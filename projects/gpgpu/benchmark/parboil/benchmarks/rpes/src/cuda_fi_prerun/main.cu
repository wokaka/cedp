/* Instrumented by FaultInjector */
#include "gpufi.h"

#include <stdio.h>

#include <string.h>

#include "parboil.h"

#include "shell.h"

#include "crys_kernel.cu"

#include "gpufi.h"

uint4 * d_Block_Work;
uint2 * d_FinalReduce;
float * d_Output, * d_ReductionSum;
struct cudaArray * d_Coors, * d_Sprms, * d_Wghts;
float4 * Coors;
float2 * Sprms;
uint4 * Block_Work;
int totNumBlocks;
int MaxBlocks;
struct Atom * ComputeAtom, * BasisAtom;
struct Shell * ComputeShell;
float Coor[64];
float Alpha[64];
float Coeff[64];
float Wghts[2];
float * ReductionSum;
int totReductionElements;
uint2 * FinalReduce;
struct double3
{
    double x, y, z;
};

void AllocateDataOnDevice(int , int , int , int , int , int );
void RunKernel(int , struct pb_TimerSet * , struct pb_Parameters * );
void CalcOnHost(int );
/* & */
struct Atom * ReadBasisAtoms(int * , struct pb_Parameters * );
/* & */
int TotalNumOfShells(char * , int , int * );
void PopulateShells(char * , int );
void PopulateHostData(int , int , int );
int NumOfIntegrals(int );
void DistributeBlockWork(int );
void FreeAllData(struct pb_TimerSet * );
void PopulateWeights(  );
double root1(double X);
int main(int argc, char * argv[])
{
    struct pb_TimerSet timers;
    struct pb_Parameters * params;
    int numBasisAtoms;
    int totNumAtoms;
    int totNumShells;
    int totBasisShells = 0;
    int i, j;
    int numIntegrals;
    int d_output_mem;
    int d_work_mem;
    int reduction_mem;
    int final_mem;
    int d_total_mem;
    pb_InitializeTimerSet(( & timers));
    GPUFI_INIT(2, 86);


    params=pb_ReadParameters(( & argc), argv);
    totNumBlocks=0;
    MaxBlocks=0;
    pb_SwitchToTimer(( & timers), pb_TimerID_IO);
    BasisAtom=ReadBasisAtoms(( & numBasisAtoms), params);
    pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
    totNumShells=TotalNumOfShells(params->inpFiles[0], numBasisAtoms, ( & totNumAtoms));
    totReductionElements=((((totNumShells*(totNumShells+1))*(totNumShells+2))*(totNumShells+3))/24);
    ComputeAtom=((struct Atom * )malloc((totNumAtoms*sizeof (struct Atom))));
    ComputeShell=((struct Shell * )malloc((totNumShells*sizeof (struct Shell))));
    pb_SwitchToTimer(( & timers), pb_TimerID_IO);
    PopulateShells(params->inpFiles[0], numBasisAtoms);
    pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
    /* 	all shells are ready now
     */
    /* 	prepare host data
     */
    for (i=0; i<numBasisAtoms; i ++ )
    {
        for (j=0; j<BasisAtom[i].numShells; j ++ )
        {
            totBasisShells+=BasisAtom[i].AtomShell[j].numPrimitives;
        }
    }
    Coors=((float4 * )malloc((totNumAtoms*sizeof (float4))));
    Sprms=((float2 * )malloc((totBasisShells*sizeof (float2))));
    PopulateHostData(totNumAtoms, totNumShells, numBasisAtoms);
    /* 	distribute the work now
     */
    FinalReduce=((uint2 * )malloc((totReductionElements*sizeof (uint2))));
    numIntegrals=NumOfIntegrals(totNumShells);
    pb_SwitchToTimer(( & timers), pb_TimerID_IO);
    printf("Total # of integrals to compute: %d\n", numIntegrals);
    printf("Total # of blocks allocated: %d\n", totNumBlocks);
    printf("Final array size: %d\n", totReductionElements);
    pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
    Block_Work=((uint4 * )malloc((totNumBlocks*sizeof (uint4))));
    DistributeBlockWork(totNumShells);
    d_output_mem=(totNumBlocks*sizeof (float));
    d_work_mem=(totNumBlocks*sizeof (uint4));
    reduction_mem=(totReductionElements*sizeof (float));
    final_mem=(totReductionElements*sizeof (uint2));
    ReductionSum=((float * )malloc(reduction_mem));
    /* 	prepare device data
     */
    pb_SwitchToTimer(( & timers), pb_TimerID_COPY);
    AllocateDataOnDevice(d_output_mem, d_work_mem, reduction_mem, final_mem, totNumAtoms, totBasisShells);
    pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
    d_total_mem=(((d_output_mem+d_work_mem)+reduction_mem)+final_mem);
    printf("%.2lf MB allocated\n", (((double)d_total_mem)/1048576));
    printf("maxblocks = %d\n", MaxBlocks);
    /* 	okay, now ready to do something useful
     */
    RunKernel(numIntegrals, ( & timers), params);
    /* 	loading data back to the host
     */
    pb_SwitchToTimer(( & timers), pb_TimerID_COPY);
    cudaMemcpy(ReductionSum, d_ReductionSum, reduction_mem, cudaMemcpyDeviceToHost);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 146);
            exit(( - 1));
        }
    }
    pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
    FreeAllData(( & timers));
    if (params->outFile)
    {
        FILE * file;
        pb_SwitchToTimer(( & timers), pb_TimerID_IO);
        file=fopen(params->outFile, "w");
        printf("totReductionElements %d\n", totReductionElements);
        /* only printing the first 20000
         */
        for (i=0; i<(reduction_mem/sizeof (float)); i ++ )
        {
            fprintf(file, "%d\t%e\n", i, ReductionSum[i]);
        }
        fclose(file);
    }
    pb_SwitchToTimer(( & timers), pb_TimerID_NONE);
    pb_PrintTimerSet(( & timers));
    pb_FreeParameters(params);
    GPUFI_HALT("fi_profile.txt");
    return 0;
    GPUFI_HALT("fi_profile.txt");
}

void RunKernel(int numIntegrals, struct pb_TimerSet * timers, struct pb_Parameters * params)
{
    int runs = ((int)ceil(((1.0*totNumBlocks)/65535)));
    int RemainingBlocks;
    int StartBlock = 0;
    int run;
    int RemainReduction;
    int Offset = 0;
    printf("%d computation cycles will be performed...\n", runs);
    RemainingBlocks=totNumBlocks;
    for (run=0; run<runs; run ++ )
    {
        int numBlocks = min(65535, RemainingBlocks);
        struct dim3 grid;
        struct dim3 block;
        grid.x=numBlocks;
        grid.y=1;
        grid.z=1;
        block.x=64;
        block.y=1;
        block.z=1;
        pb_SwitchToTimer(timers, pb_TimerID_GPU);
        /* Fault Injection Instrumentation Begin */
        cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));
        CUDA_ERRCK
        cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);
        CUDA_ERRCK
        /* Fault Injection Instrumentation End */

        ComputeX<<<grid, block>>> (d_Block_Work, d_Output, StartBlock, gpufi_dev);
        /* Fault Injection Instrumentation Begin */
        cudaMemcpy(&gpufi_host, gpufi_dev, sizeof(struct _gpufi_data_), cudaMemcpyDeviceToHost);
        CUDA_ERRCK
        cudaFree(gpufi_dev);
        CUDA_ERRCK
        /* Fault Injection Instrumentation End */

        {
            cudaError_t err;
            if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 192);
                exit(( - 1));
            }
        }
        if (params->synchronizeGpu)
        {
            cudaThreadSynchronize();
        }
        pb_SwitchToTimer(timers, pb_TimerID_COMPUTE);
        RemainingBlocks-=65535;
        StartBlock+=numBlocks;
    }
    runs=((int)ceil(((1.0*totReductionElements)/65535)));
    printf("done.\n\n%d reduction cycles will be performed...\n", runs);
    RemainReduction=totReductionElements;
    for (run=0; run<runs; run ++ )
    {
        int numBlocks = min(65535, RemainReduction);
        struct dim3 grid;
        struct dim3 block;
        grid.x=numBlocks;
        grid.y=1;
        grid.z=1;
        block.x=MaxBlocks;
        block.y=1;
        block.z=1;
        pb_SwitchToTimer(timers, pb_TimerID_GPU);
        /* Fault Injection Instrumentation Begin */
        cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));
        CUDA_ERRCK
        cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);
        CUDA_ERRCK
        /* Fault Injection Instrumentation End */

        DoReduction<<<grid, block>>> (d_ReductionSum, d_Output, d_FinalReduce, MaxBlocks, Offset, gpufi_dev);
        /* Fault Injection Instrumentation Begin */
        cudaMemcpy(&gpufi_host, gpufi_dev, sizeof(struct _gpufi_data_), cudaMemcpyDeviceToHost);
        CUDA_ERRCK
        cudaFree(gpufi_dev);
        CUDA_ERRCK
        /* Fault Injection Instrumentation End */

        {
            cudaError_t err;
            if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 219);
                exit(( - 1));
            }
        }
        if (params->synchronizeGpu)
        {
            cudaThreadSynchronize();
        }
        pb_SwitchToTimer(timers, pb_TimerID_COMPUTE);
        RemainReduction-=65535;
        Offset+=numBlocks;
    }
}

void AllocateDataOnDevice(int d_output_mem, int d_work_mem, int reduction_mem, int final_mem, int numCoors, int numSprms)
{
    cudaMalloc(((void *  * )( & d_ReductionSum)), reduction_mem);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 233);
            exit(( - 1));
        }
    }
    cudaMalloc(((void *  * )( & d_Output)), d_output_mem);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 235);
            exit(( - 1));
        }
    }
    cudaMalloc(((void *  * )( & d_Block_Work)), d_work_mem);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 237);
            exit(( - 1));
        }
    }
    cudaMalloc(((void *  * )( & d_FinalReduce)), final_mem);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 239);
            exit(( - 1));
        }
    }
    cudaMallocArray(( & d_Coors), ( & texCoors.channelDesc), numCoors, 1);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 242);
            exit(( - 1));
        }
    }
    cudaMallocArray(( & d_Sprms), ( & texSprms.channelDesc), numSprms, 1);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 245);
            exit(( - 1));
        }
    }
    cudaMallocArray(( & d_Wghts), ( & texWghts.channelDesc), (1<<2), 2);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 248);
            exit(( - 1));
        }
    }
    cudaMemcpy(d_Block_Work, Block_Work, d_work_mem, cudaMemcpyHostToDevice);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 252);
            exit(( - 1));
        }
    }
    cudaMemcpy(d_FinalReduce, FinalReduce, final_mem, cudaMemcpyHostToDevice);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 255);
            exit(( - 1));
        }
    }
    cudaMemcpyToArray(d_Coors, 0, 0, ((void * )Coors), (numCoors*sizeof (float4)), cudaMemcpyHostToDevice);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 260);
            exit(( - 1));
        }
    }
    cudaMemcpyToArray(d_Sprms, 0, 0, ((void * )Sprms), (numSprms*sizeof (float2)), cudaMemcpyHostToDevice);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 264);
            exit(( - 1));
        }
    }
    cudaMemcpyToArray(d_Wghts, 0, 0, ((void * )Wghts), (2*sizeof (float)), cudaMemcpyHostToDevice);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 268);
            exit(( - 1));
        }
    }
    texWghts.filterMode=cudaFilterModeLinear;
    cudaBindTextureToArray(texCoors, d_Coors, texCoors.channelDesc);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 273);
            exit(( - 1));
        }
    }
    cudaBindTextureToArray(texSprms, d_Sprms, texSprms.channelDesc);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 275);
            exit(( - 1));
        }
    }
    cudaBindTextureToArray(texWghts, d_Wghts, texWghts.channelDesc);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 277);
            exit(( - 1));
        }
    }
}

void FreeAllData(struct pb_TimerSet * timers)
{
    pb_SwitchToTimer(timers, pb_TimerID_COPY);
    cudaFree(((void * )d_FinalReduce));
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 284);
            exit(( - 1));
        }
    }
    cudaFree(((void * )d_Block_Work));
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 286);
            exit(( - 1));
        }
    }
    cudaFree(((void * )d_Output));
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 288);
            exit(( - 1));
        }
    }
    cudaFree(((void * )d_ReductionSum));
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 290);
            exit(( - 1));
        }
    }
    cudaFreeArray(d_Coors);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 292);
            exit(( - 1));
        }
    }
    cudaFreeArray(d_Wghts);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 294);
            exit(( - 1));
        }
    }
    cudaFreeArray(d_Sprms);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 296);
            exit(( - 1));
        }
    }
    pb_SwitchToTimer(timers, pb_TimerID_COMPUTE);
    free(((void * )Block_Work));
    free(((void * )FinalReduce));
    free(((void * )ComputeAtom));
    free(((void * )BasisAtom));
    free(((void * )ComputeShell));
}

/* & */
struct Atom * ReadBasisAtoms(int * numBasisAtoms, struct pb_Parameters * params)
{
    FILE * basis = fopen(params->inpFiles[1], "r");
    int numAtoms = 0, numShells = 0;
    struct Atom * BasisAtom;
    int atom, shell;
    if (( ! basis))
    {
        printf("Unable to open file %s\n", params->inpFiles[1]);
        exit(0);
    }
    fscanf(basis, "%*s %*s %d", ( & numAtoms));
    fscanf(basis, "%*s %*s %d", ( & numShells));
    printf("\n>>>>>>> STARTED BASIS SET OUTPUT <<<<<<<\n");
    printf("\n# OF KNOWN ATOMS:  %d\n", numAtoms);
    printf("# OF KNOWN SHELLS: %d\n\n", numShells);
    ( * numBasisAtoms)=numAtoms;
    BasisAtom=((struct Atom * )malloc((numAtoms*sizeof (struct Atom))));
    for (atom=0; atom<numAtoms; atom ++ )
    {
        char type[4];
        char buff[4];
        fscanf(basis, "%*s %s", type);
        fscanf(basis, "%*s %d", ( & numShells));
        BasisAtom[atom].numShells=numShells;
        strcpy(BasisAtom[atom].Type, type);
        printf("\nAtom %s (%d shells)\n", BasisAtom[atom].Type, BasisAtom[atom].numShells);
        for (shell=0; shell<numShells; shell ++ )
        {
            int numPrimitives = 0;
            int prim;
            fscanf(basis, "%*s %*d %*s %d", ( & numPrimitives));
            BasisAtom[atom].AtomShell[shell].numPrimitives=numPrimitives;
            sprintf(buff, "%d", (shell+1));
            strcpy(BasisAtom[atom].AtomShell[shell].Type, type);
            strcpy((BasisAtom[atom].AtomShell[shell].Type+1), buff);
            printf("\tShell %s: %d primitives\n", BasisAtom[atom].AtomShell[shell].Type, BasisAtom[atom].AtomShell[shell].numPrimitives);
            for (prim=0; prim<numPrimitives; prim ++ )
            {
                fscanf(basis, "%*s %*s %*s %f %f", ( & BasisAtom[atom].AtomShell[shell].Alpha[prim]), ( & BasisAtom[atom].AtomShell[shell].Coeff[prim]));
                printf("\t\tprimitive %d: %10.2f    %5.2f\n", (prim+1), BasisAtom[atom].AtomShell[shell].Alpha[prim], BasisAtom[atom].AtomShell[shell].Coeff[prim]);
            }
            printf("\n");
        }
    }
    printf(">>>>>>>> DONE BASIS SET OUTPUT <<<<<<<<\n\n\n");
    fclose(basis);
    return BasisAtom;
}

/* & */
int TotalNumOfShells(char * fname, int numBasisAtoms, int * totNumAtoms)
{
    FILE * inp = fopen(fname, "r");
    int numShells = 0;
    int atom, batom;
    if (( ! inp))
    {
        printf("Unable to open %s\n", fname);
        exit(0);
    }
    fscanf(inp, "%*s %d", totNumAtoms);
    for (atom=0; atom<( * totNumAtoms); atom ++ )
    {
        char type[8];
        int notfound = 1;
        fscanf(inp, "%s %*s %*s %*s", type);
        for (batom=0; batom<numBasisAtoms; batom ++ )
        {
            if (( ! strcmp(BasisAtom[batom].Type, type)))
            {
                numShells+=BasisAtom[batom].numShells;
                notfound=0;
                break;
            }
        }
        if (notfound)
        {
            printf("Unable to find atom \'%s\' in the basis set\n", type);
            exit(0);
        }
    }
    fclose(inp);
    return numShells;
}

void PopulateShells(char * fname, int numBasisAtoms)
{
    FILE * inp = fopen(fname, "r");
    int numAtoms = 0, currentShell = 0;
    int atom, batom, shell, prim;
    if (( ! inp))
    {
        printf("Unable to open %s\n", fname);
        exit(0);
    }
    fscanf(inp, "%*s %d", ( & numAtoms));
    for (atom=0; atom<numAtoms; atom ++ )
    {
        int currentInList = 0;
        fscanf(inp, "%s %f %f %f", ( & ComputeAtom[atom].Type), ( & ComputeAtom[atom].X), ( & ComputeAtom[atom].Y), ( & ComputeAtom[atom].Z));
        for (batom=0; batom<numBasisAtoms; batom ++ )
        {
            /* 	this part populates inList
             */
            if (( ! strcmp(BasisAtom[batom].Type, ComputeAtom[atom].Type)))
            {
                for (shell=0; shell<BasisAtom[batom].numShells; shell ++ )
                {
                    ComputeShell[currentShell]=BasisAtom[batom].AtomShell[shell];
                    ComputeShell[currentShell].myAtom=atom;
                    /* 	this part populates inList
                     */
                    for (prim=0; prim<BasisAtom[batom].AtomShell[shell].numPrimitives; prim ++ )
                    {
                        ComputeShell[currentShell].inList[prim]=(currentInList ++ );
                    }
                    currentShell ++ ;
                }
                break;
            }
            else
            {
                for (shell=0; shell<BasisAtom[batom].numShells; shell ++ )
                {
                    currentInList+=BasisAtom[batom].AtomShell[shell].numPrimitives;
                }
            }
        }
    }
    fclose(inp);
}

void PopulateHostData(int totNumAtoms, int totNumShells, int numBasisAtoms)
{
    int atom;
    int currentPos = 0, batom, shell, prim;
    PopulateWeights();
    for (atom=0; atom<totNumAtoms; atom ++ )
    {
        Coors[atom].x=ComputeAtom[atom].X;
        Coors[atom].y=ComputeAtom[atom].Y;
        Coors[atom].z=ComputeAtom[atom].Z;
    }
    for (batom=0; batom<numBasisAtoms; batom ++ )
    {
        for (shell=0; shell<BasisAtom[batom].numShells; shell ++ )
        {
            for (prim=0; prim<BasisAtom[batom].AtomShell[shell].numPrimitives; prim ++ )
            {
                Sprms[currentPos].x=BasisAtom[batom].AtomShell[shell].Alpha[prim];
                Sprms[currentPos].y=BasisAtom[batom].AtomShell[shell].Coeff[prim];
                currentPos ++ ;
            }
        }
    }
}

int NumOfIntegrals(int totNumShells)
{
    int numIntegrals = 0;
    int firstRedElement = 0;
    int redElement = 0;
    int shell1, shell2, shell3, shell4;
    for (shell1=0; shell1<totNumShells; shell1 ++ )
    {
        for (shell2=shell1; shell2<totNumShells; shell2 ++ )
        {
            for (shell3=shell2; shell3<totNumShells; shell3 ++ )
            {
                for (shell4=shell3; shell4<totNumShells; shell4 ++ )
                {
                    int integrals = (((ComputeShell[shell1].numPrimitives*ComputeShell[shell2].numPrimitives)*ComputeShell[shell3].numPrimitives)*ComputeShell[shell4].numPrimitives);
                    int blocks;
                    numIntegrals+=integrals;
                    blocks=((int)ceil(((1.0*integrals)/64)));
                    totNumBlocks+=blocks;
                    if ((blocks>MaxBlocks))
                    {
                        MaxBlocks=blocks;
                    }
                    FinalReduce[redElement].x=firstRedElement;
                    FinalReduce[redElement].y=blocks;
                    firstRedElement+=blocks;
                    redElement ++ ;
                }
            }
        }
    }
    return numIntegrals;
}

void DistributeBlockWork(int totNumShells)
{
    int numElements = 0;
    int StartBlock = 0;
    int block;
    int shell1, shell2, shell3, shell4, basic;
    for (shell1=0; shell1<totNumShells; shell1 ++ )
    {
        for (shell2=shell1; shell2<totNumShells; shell2 ++ )
        {
            for (shell3=shell2; shell3<totNumShells; shell3 ++ )
            {
                for (shell4=shell3; shell4<totNumShells; shell4 ++ )
                {
                    int integrals = (((ComputeShell[shell1].numPrimitives*ComputeShell[shell2].numPrimitives)*ComputeShell[shell3].numPrimitives)*ComputeShell[shell4].numPrimitives);
                    int blocks = ((int)ceil(((1.0*integrals)/64)));
                    StartBlock=numElements;
                    for (block=0; block<blocks; block ++ )
                    {
                        int a4 = ComputeShell[shell4].numPrimitives;
                        int a3 = ComputeShell[shell3].numPrimitives;
                        int a2 = ComputeShell[shell2].numPrimitives;
                        int a1 = ComputeShell[shell1].numPrimitives;
                        int offset4 = ComputeShell[shell4].inList[0];
                        int offset3 = ComputeShell[shell3].inList[0];
                        int offset2 = ComputeShell[shell2].inList[0];
                        int offset1 = ComputeShell[shell1].inList[0];
                        Block_Work[numElements].y=((((ComputeShell[shell1].myAtom<<24)|(ComputeShell[shell2].myAtom<<16))|(ComputeShell[shell3].myAtom<<8))|ComputeShell[shell4].myAtom);
                        Block_Work[numElements].z=((((offset1<<24)|(offset2<<16))|(offset3<<8))|offset4);
                        Block_Work[numElements].x=((((a1<<12)|(a2<<8))|(a3<<4))|a4);
                        Block_Work[numElements].w=StartBlock;
                        numElements ++ ;
                    }
                }
            }
        }
    }
}

double root1(double X)
{
    double PIE4;
    double WW1 = 0.0;
    double F1, E, Y, inv;
    PIE4=0.785398163397448;
    if ((X<3.0E-7))
    {
        WW1=(1.0-(0.333333333*X));
    }
    else
    {
        if ((X<1.0))
        {
            F1=((((((((((((((((((( - 8.36313918003957E-8)*X)+1.21222603512827E-6)*X)-1.15662609053481E-5)*X)+9.25197374512647E-5)*X)-6.40994113129432E-4)*X)+0.00378787044215009)*X)-0.0185185172458485)*X)+0.0714285713298222)*X)-0.199999999997023)*X)+0.333333333333318);
            WW1=(((X+X)*F1)+exp(( - X)));
        }
        else
        {
            if ((X<3.0))
            {
                Y=(X-2.0);
                F1=((((((((((((((((((((((( - 1.61702782425558E-10)*Y)+1.96215250865776E-9)*Y)-2.14234468198419E-8)*Y)+2.17216556336318E-7)*Y)-1.98850171329371E-6)*Y)+1.62429321438911E-5)*Y)-1.16740298039895E-4)*Y)+7.24888732052332E-4)*Y)-0.00379490003707156)*Y)+0.0161723488664661)*Y)-0.0529428148329736)*Y)+0.115702180856167);
                WW1=(((X+X)*F1)+exp(( - X)));
            }
            else
            {
                if ((X<5.0))
                {
                    Y=(X-4.0);
                    F1=((((((((((((((((((((((( - 2.62453564772299E-11)*Y)+3.24031041623823E-10)*Y)-3.614965656163E-9)*Y)+3.760256799971E-8)*Y)-3.553558319675E-7)*Y)+3.022556449731E-6)*Y)-2.290098979647E-5)*Y)+1.526537461148E-4)*Y)-8.81947375894379E-4)*Y)+0.00433207949514611)*Y)-0.0175257821619926)*Y)+0.0528406320615584);
                    WW1=(((X+X)*F1)+exp(( - X)));
                }
                else
                {
                    if ((X<10.0))
                    {
                        E=exp(( - X));
                        inv=(1/X);
                        WW1=((((((((((((((0.46897511375022*inv)-0.69955602298985)*inv)+0.53689283271887)*inv)-0.32883030418398)*inv)+0.24645596956002)*inv)-0.49984072848436)*inv)-3.1501078774085E-6)*E)+sqrt((PIE4*inv)));
                    }
                    else
                    {
                        if ((X<15.0))
                        {
                            E=exp(( - X));
                            inv=(1/X);
                            WW1=((((((((( - 0.18784686463512)*inv)+0.22991849164985)*inv)-0.49893752514047)*inv)-2.1916512131607E-5)*E)+sqrt((PIE4*inv)));
                        }
                        else
                        {
                            if ((X<33.0))
                            {
                                E=exp(( - X));
                                inv=(1/X);
                                WW1=((((((0.1962326414943*inv)-0.4969524146449)*inv)-6.0156581186481E-5)*E)+sqrt((PIE4*inv)));
                            }
                            else
                            {
                                inv=(1/X);
                                WW1=sqrt((PIE4*inv));
                            }
                        }
                    }
                }
            }
        }
    }
    return WW1;
}

void PopulateWeights(  )
{
    int i;
    for (i=0; i<2; i ++ )
    {
        float X = ((float)(((1.0*i)*10)/(2-1)));
        Wghts[i]=root1(X);
    }
}
