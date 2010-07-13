/* Instrumented by FaultInjector */
#include "gpufi.h"

/*
**************************************************************************
 
 *cr
 
 *cr            (C) Copyright 2007 The Board of Trustees of the
 
 *cr                        University of Illinois
 
 *cr                         All Rights Reserved
 
 *cr
 
 **************************************************************************
*/
#include "gpufi.h"

/* Adjustable parameters */
struct kValues
{
    float Kx;
    float Ky;
    float Kz;
    float RhoPhiR;
    float RhoPhiI;
};

__constant__ __device__ struct kValues c[512];
/* & */
/* & */
/* & */
/* & */
void createDataStructs(int numK, int numX, float *  * realRhoPhi, float *  * imagRhoPhi, float *  * outR, float *  * outI)
{
    ( * realRhoPhi)=((float * )calloc(numK, sizeof (float)));
    ( * imagRhoPhi)=((float * )calloc(numK, sizeof (float)));
    ( * outR)=((float * )calloc(numX, sizeof (float)));
    ( * outI)=((float * )calloc(numX, sizeof (float)));
}

__global__ void ComputeRhoPhiGPU(int numK, float * phiR, float * phiI, float * dR, float * dI, float * realRhoPhi, float * imagRhoPhi,  struct _gpufi_data_ *gpufi_dev)
{
    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_BEGIN, 0, "ComputeRhoPhiGPU");
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 0, "numK", (int*)&numK, GPUFI_DATATYPE_INTEGER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 1, "phiR", (int*)&phiR, GPUFI_DATATYPE_FLOAT_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 2, "phiI", (int*)&phiI, GPUFI_DATATYPE_FLOAT_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 3, "dR", (int*)&dR, GPUFI_DATATYPE_FLOAT_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 4, "dI", (int*)&dI, GPUFI_DATATYPE_FLOAT_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 5, "realRhoPhi", (int*)&realRhoPhi, GPUFI_DATATYPE_FLOAT_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 6, "imagRhoPhi", (int*)&imagRhoPhi, GPUFI_DATATYPE_FLOAT_POINTER);


    int indexK = ((blockIdx.x*512)+threadIdx.x);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 14, "indexK", (int*)&indexK, GPUFI_DATATYPE_INTEGER);


    if ((indexK<numK))
    {
        float rPhiR = phiR[indexK];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 15, "rPhiR", (int*)&rPhiR, GPUFI_DATATYPE_FLOAT);


        float rPhiI = phiI[indexK];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 16, "rPhiI", (int*)&rPhiI, GPUFI_DATATYPE_FLOAT);


        float rDR = dR[indexK];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 17, "rDR", (int*)&rDR, GPUFI_DATATYPE_FLOAT);


        float rDI = dI[indexK];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 18, "rDI", (int*)&rDI, GPUFI_DATATYPE_FLOAT);


        realRhoPhi[indexK]=((rPhiR*rDR)+(rPhiI*rDI));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 19, "realRhoPhi[indexK]", (int*)&realRhoPhi[indexK], GPUFI_DATATYPE_FLOAT);


        imagRhoPhi[indexK]=((rPhiR*rDI)-(rPhiI*rDR));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 20, "imagRhoPhi[indexK]", (int*)&imagRhoPhi[indexK], GPUFI_DATATYPE_FLOAT);


    }
    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_END, 0, "ComputeRhoPhiGPU");
}

__global__ void ComputeFH_GPU(int numK, int kGlobalIndex, float * x, float * y, float * z, float * outR, float * outI,  struct _gpufi_data_ *gpufi_dev)
{
    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_BEGIN, 1, "ComputeFH_GPU");
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 10, "y", (int*)&y, GPUFI_DATATYPE_FLOAT_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 11, "z", (int*)&z, GPUFI_DATATYPE_FLOAT_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 12, "outR", (int*)&outR, GPUFI_DATATYPE_FLOAT_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 13, "outI", (int*)&outI, GPUFI_DATATYPE_FLOAT_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 7, "numK", (int*)&numK, GPUFI_DATATYPE_INTEGER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 8, "kGlobalIndex", (int*)&kGlobalIndex, GPUFI_DATATYPE_INTEGER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 9, "x", (int*)&x, GPUFI_DATATYPE_FLOAT_POINTER);


    float sX;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 21, "sX", (int*)&sX, GPUFI_DATATYPE_FLOAT);


    float sY;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 22, "sY", (int*)&sY, GPUFI_DATATYPE_FLOAT);


    float sZ;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 23, "sZ", (int*)&sZ, GPUFI_DATATYPE_FLOAT);


    float sOutR;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 24, "sOutR", (int*)&sOutR, GPUFI_DATATYPE_FLOAT);


    float sOutI;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 25, "sOutI", (int*)&sOutI, GPUFI_DATATYPE_FLOAT);


    /* Determine the element of the X arrays computed by this thread
     */
    int xIndex = ((blockIdx.x*256)+threadIdx.x);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 26, "xIndex", (int*)&xIndex, GPUFI_DATATYPE_INTEGER);


    float * test = NULL;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 27, "test", (int*)&test, GPUFI_DATATYPE_FLOAT_POINTER);


    int kIndex = 0;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 28, "kIndex", (int*)&kIndex, GPUFI_DATATYPE_INTEGER);


    int kCnt;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 29, "kCnt", (int*)&kCnt, GPUFI_DATATYPE_INTEGER);


    test=( & sOutR);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 30, "test", (int*)&test, GPUFI_DATATYPE_FLOAT_POINTER);


    sX=x[xIndex];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 31, "sX", (int*)&sX, GPUFI_DATATYPE_FLOAT);


    sY=y[xIndex];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 32, "sY", (int*)&sY, GPUFI_DATATYPE_FLOAT);


    sZ=z[xIndex];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 33, "sZ", (int*)&sZ, GPUFI_DATATYPE_FLOAT);


    sOutR=outR[xIndex];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 34, "sOutR", (int*)&sOutR, GPUFI_DATATYPE_FLOAT);


    sOutI=outI[xIndex];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 35, "sOutI", (int*)&sOutI, GPUFI_DATATYPE_FLOAT);


    /* Loop over all elements of K in constant mem to compute a partial value
     */
    /* for X.
     */
    kCnt=(numK-kGlobalIndex);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 36, "kCnt", (int*)&kCnt, GPUFI_DATATYPE_INTEGER);


    if ((kCnt<512))
    {
        /* Fault Injector Instrumentation Begin */
        GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_BEGIN);
        /* Fault Injector Instrumentation End */

        for (kIndex=0; (kIndex<(kCnt%4))&&(kGlobalIndex<numK); ((kIndex ++ ), (kGlobalIndex ++ )))
        {
            /* Fault Injector Instrumentation Begin */
            GPUFI_KERNEL_ITERATION(gpufi_dev);
            /* Fault Injector Instrumentation End */

            float expArg = (6.283185307179586*(((c[kIndex].Kx*sX)+(c[kIndex].Ky*sY))+(c[kIndex].Kz*sZ)));
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 40, "expArg", (int*)&expArg, GPUFI_DATATYPE_FLOAT);


            float cosArg = cos(expArg);
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 41, "cosArg", (int*)&cosArg, GPUFI_DATATYPE_FLOAT);


            float sinArg = sin(expArg);
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 42, "sinArg", (int*)&sinArg, GPUFI_DATATYPE_FLOAT);


            sOutR+=((c[kIndex].RhoPhiR*cosArg)-(c[kIndex].RhoPhiI*sinArg));
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 43, "sOutR", (int*)&sOutR, GPUFI_DATATYPE_FLOAT);


            sOutI+=((c[kIndex].RhoPhiI*cosArg)+(c[kIndex].RhoPhiR*sinArg));
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 44, "sOutI", (int*)&sOutI, GPUFI_DATATYPE_FLOAT);


        }
        /* Automatically inserted by Cetus_Cuda */
        GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_END);
        /* Fault Injector Instrumentation End *//* End of Cetus_Cuda code */

        GPUFI_KERNEL_VARIABLE(gpufi_dev, 38, "kIndex", (int*)&kIndex, GPUFI_DATATYPE_INTEGER);


        GPUFI_KERNEL_VARIABLE(gpufi_dev, 39, "kGlobalIndex", (int*)&kGlobalIndex, GPUFI_DATATYPE_INTEGER);


    }
    /* Fault Injector Instrumentation Begin */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_BEGIN);
    /* Fault Injector Instrumentation End */

    for (; (kIndex<512)&&(kGlobalIndex<numK); ((kIndex+=4), (kGlobalIndex+=4)))
    {
        /* Fault Injector Instrumentation Begin */
        GPUFI_KERNEL_ITERATION(gpufi_dev);
        /* Fault Injector Instrumentation End */

        float expArg = (6.283185307179586*(((c[kIndex].Kx*sX)+(c[kIndex].Ky*sY))+(c[kIndex].Kz*sZ)));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 47, "expArg", (int*)&expArg, GPUFI_DATATYPE_FLOAT);


        float cosArg = cos(expArg);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 48, "cosArg", (int*)&cosArg, GPUFI_DATATYPE_FLOAT);


        float sinArg = sin(expArg);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 49, "sinArg", (int*)&sinArg, GPUFI_DATATYPE_FLOAT);


        int kIndex1;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 50, "kIndex1", (int*)&kIndex1, GPUFI_DATATYPE_INTEGER);


        float expArg1;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 51, "expArg1", (int*)&expArg1, GPUFI_DATATYPE_FLOAT);


        float cosArg1;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 52, "cosArg1", (int*)&cosArg1, GPUFI_DATATYPE_FLOAT);


        float sinArg1;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 53, "sinArg1", (int*)&sinArg1, GPUFI_DATATYPE_FLOAT);


        int kIndex2;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 54, "kIndex2", (int*)&kIndex2, GPUFI_DATATYPE_INTEGER);


        float expArg2;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 55, "expArg2", (int*)&expArg2, GPUFI_DATATYPE_FLOAT);


        float cosArg2;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 56, "cosArg2", (int*)&cosArg2, GPUFI_DATATYPE_FLOAT);


        float sinArg2;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 57, "sinArg2", (int*)&sinArg2, GPUFI_DATATYPE_FLOAT);


        int kIndex3;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 58, "kIndex3", (int*)&kIndex3, GPUFI_DATATYPE_INTEGER);


        float expArg3;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 59, "expArg3", (int*)&expArg3, GPUFI_DATATYPE_FLOAT);


        float cosArg3;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 60, "cosArg3", (int*)&cosArg3, GPUFI_DATATYPE_FLOAT);


        float sinArg3;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 61, "sinArg3", (int*)&sinArg3, GPUFI_DATATYPE_FLOAT);


        sOutR+=((c[kIndex].RhoPhiR*cosArg)-(c[kIndex].RhoPhiI*sinArg));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 62, "sOutR", (int*)&sOutR, GPUFI_DATATYPE_FLOAT);


        sOutI+=((c[kIndex].RhoPhiI*cosArg)+(c[kIndex].RhoPhiR*sinArg));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 63, "sOutI", (int*)&sOutI, GPUFI_DATATYPE_FLOAT);


        kIndex1=(kIndex+1);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 64, "kIndex1", (int*)&kIndex1, GPUFI_DATATYPE_INTEGER);


        expArg1=(6.283185307179586*(((c[kIndex1].Kx*sX)+(c[kIndex1].Ky*sY))+(c[kIndex1].Kz*sZ)));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 65, "expArg1", (int*)&expArg1, GPUFI_DATATYPE_FLOAT);


        cosArg1=cos(expArg1);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 66, "cosArg1", (int*)&cosArg1, GPUFI_DATATYPE_FLOAT);


        sinArg1=sin(expArg1);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 67, "sinArg1", (int*)&sinArg1, GPUFI_DATATYPE_FLOAT);


        sOutR+=((c[kIndex1].RhoPhiR*cosArg1)-(c[kIndex1].RhoPhiI*sinArg1));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 68, "sOutR", (int*)&sOutR, GPUFI_DATATYPE_FLOAT);


        sOutI+=((c[kIndex1].RhoPhiI*cosArg1)+(c[kIndex1].RhoPhiR*sinArg1));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 69, "sOutI", (int*)&sOutI, GPUFI_DATATYPE_FLOAT);


        kIndex2=(kIndex+2);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 70, "kIndex2", (int*)&kIndex2, GPUFI_DATATYPE_INTEGER);


        expArg2=(6.283185307179586*(((c[kIndex2].Kx*sX)+(c[kIndex2].Ky*sY))+(c[kIndex2].Kz*sZ)));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 71, "expArg2", (int*)&expArg2, GPUFI_DATATYPE_FLOAT);


        cosArg2=cos(expArg2);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 72, "cosArg2", (int*)&cosArg2, GPUFI_DATATYPE_FLOAT);


        sinArg2=sin(expArg2);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 73, "sinArg2", (int*)&sinArg2, GPUFI_DATATYPE_FLOAT);


        sOutR+=((c[kIndex2].RhoPhiR*cosArg2)-(c[kIndex2].RhoPhiI*sinArg2));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 74, "sOutR", (int*)&sOutR, GPUFI_DATATYPE_FLOAT);


        sOutI+=((c[kIndex2].RhoPhiI*cosArg2)+(c[kIndex2].RhoPhiR*sinArg2));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 75, "sOutI", (int*)&sOutI, GPUFI_DATATYPE_FLOAT);


        kIndex3=(kIndex+3);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 76, "kIndex3", (int*)&kIndex3, GPUFI_DATATYPE_INTEGER);


        expArg3=(6.283185307179586*(((c[kIndex3].Kx*sX)+(c[kIndex3].Ky*sY))+(c[kIndex3].Kz*sZ)));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 77, "expArg3", (int*)&expArg3, GPUFI_DATATYPE_FLOAT);


        cosArg3=cos(expArg3);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 78, "cosArg3", (int*)&cosArg3, GPUFI_DATATYPE_FLOAT);


        sinArg3=sin(expArg3);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 79, "sinArg3", (int*)&sinArg3, GPUFI_DATATYPE_FLOAT);


        sOutR+=((c[kIndex3].RhoPhiR*cosArg3)-(c[kIndex3].RhoPhiI*sinArg3));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 80, "sOutR", (int*)&sOutR, GPUFI_DATATYPE_FLOAT);


        sOutI+=((c[kIndex3].RhoPhiI*cosArg3)+(c[kIndex3].RhoPhiR*sinArg3));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 81, "sOutI", (int*)&sOutI, GPUFI_DATATYPE_FLOAT);


    }
    /* Automatically inserted by Cetus_Cuda */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_END);
    /* Fault Injector Instrumentation End *//* End of Cetus_Cuda code */

    GPUFI_KERNEL_VARIABLE(gpufi_dev, 45, "kIndex", (int*)&kIndex, GPUFI_DATATYPE_INTEGER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 46, "kGlobalIndex", (int*)&kGlobalIndex, GPUFI_DATATYPE_INTEGER);


    outR[xIndex]=sOutR;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 82, "outR[xIndex]", (int*)&outR[xIndex], GPUFI_DATATYPE_FLOAT);


    outI[xIndex]=sOutI;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 83, "outI[xIndex]", (int*)&outI[xIndex], GPUFI_DATATYPE_FLOAT);


    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_END, 1, "ComputeFH_GPU");
}

void computeRhoPhi_GPU(int numK, float * phiR_d, float * phiI_d, float * dR_d, float * dI_d, float * realRhoPhi_d, float * imagRhoPhi_d)
{
    int rhoPhiBlocks = (numK/512);
    dim3 DimRhoPhiBlock;
    dim3 DimRhoPhiGrid;
    if ((numK%512))
    {
        rhoPhiBlocks ++ ;
    }
    DimRhoPhiBlock.x=512;
    DimRhoPhiBlock.y=1;
    DimRhoPhiBlock.z=1;
    DimRhoPhiGrid.x=rhoPhiBlocks;
    DimRhoPhiGrid.y=1;
    DimRhoPhiGrid.z=1;
    /* printf("Launch RhoPhi Kernel on GPU: Blocks (%d, %d), Threads Per Block %d\n",
     */
    /*       rhoPhiBlocks, 1, KERNEL_RHO_PHI_THREADS_PER_BLOCK);
     */
    /* Fault Injection Instrumentation Begin */
    cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));
    CUDA_ERRCK
    cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);
    CUDA_ERRCK
    /* Fault Injection Instrumentation End */

    ComputeRhoPhiGPU<<<DimRhoPhiGrid, DimRhoPhiBlock>>> (numK, phiR_d, phiI_d, dR_d, dI_d, realRhoPhi_d, imagRhoPhi_d, gpufi_dev);
    /* Fault Injection Instrumentation Begin */
    cudaMemcpy(&gpufi_host, gpufi_dev, sizeof(struct _gpufi_data_), cudaMemcpyDeviceToHost);
    CUDA_ERRCK
    cudaFree(gpufi_dev);
    CUDA_ERRCK
    /* Fault Injection Instrumentation End */

}

void computeFH_GPU(int numK, int numX, float * x_d, float * y_d, float * z_d, struct kValues * kVals, float * outR_d, float * outI_d)
{
    int FHGrids = (numK/512);
    int FHBlocks;
    dim3 DimFHBlock;
    dim3 DimFHGrid;
    int FHGrid;
    if ((numK%512))
    {
        FHGrids ++ ;
    }
    FHBlocks=(numX/256);
    if ((numX%256))
    {
        FHBlocks ++ ;
    }
    DimFHBlock.x=256;
    DimFHBlock.y=1;
    DimFHBlock.z=1;
    DimFHGrid.x=FHBlocks;
    DimFHGrid.y=1;
    DimFHGrid.z=1;
    /* printf("Launch GPU Kernel: Grids %d, Blocks Per Grid (%d, %d), Threads Per Block (%d, %d), K Elems Per Thread %d\n",
     */
    /*       FHGrids, DimFHGrid.x, DimFHGrid.y, DimFHBlock.x, DimFHBlock.y, KERNEL_FH_K_ELEMS_PER_GRID);
     */
    for (FHGrid=0; FHGrid<FHGrids; FHGrid ++ )
    {
        /* Put the tile of K values into constant mem
         */
        int FHGridBase = (FHGrid*512);
        kValues * kValsTile = (kVals+FHGridBase);
        int numElems = ((512<(numK-FHGridBase)) ? 512 : (numK-FHGridBase));
        cudaMemcpyToSymbol(c, kValsTile, (numElems*sizeof (kValues)), 0);
        {
            cudaError_t err;
            if (((err=cudaGetLastError())!=cudaSuccess))
            {
                fprintf(stderr, "CUDA error on line %d: %s\n", 202, cudaGetErrorString(err));
                exit(( - 1));
            }
        }
        ;
        /* Fault Injection Instrumentation Begin */
        cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));
        CUDA_ERRCK
        cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);
        CUDA_ERRCK
        /* Fault Injection Instrumentation End */

        ComputeFH_GPU<<<DimFHGrid, DimFHBlock>>> (numK, FHGridBase, x_d, y_d, z_d, outR_d, outI_d, gpufi_dev);
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
            fprintf(stderr, "CUDA error on line %d: %s\n", 206, cudaGetErrorString(err));
                exit(( - 1));
            }
        }
        ;
    }
}
