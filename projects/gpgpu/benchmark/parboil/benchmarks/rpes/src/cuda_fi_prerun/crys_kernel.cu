/* Instrumented by FaultInjector */
#include "gpufi.h"

/* #if 0
 */
#include "gpufi.h"

__global__ void ComputeX(uint4 * , float * , int );
__device__ float product1D(float , float , float , float , float );
__device__ float dist2(float3 , float3 );
__device__ float dist2(float4 , float4 );
__device__ float3 ReducePair(float4 , float4 , float2 , float2 , float );
__device__ float ComputeI(float , float , float , float , float , float , float , float );
__device__ float Root(float X);
/* & */
/* & */
/* & */
/* & */
/* & */
__device__ void GetBases(int , int , int , int * , int * , int * , int * , int * );
/* & */
/* & */
/* & */
/* & */
__device__ void GetAtoms(int , int * , int * , int * , int * );
/* & */
/* & */
/* & */
/* & */
__device__ void GetOffsets(int , int * , int * , int * , int * );
/* & */
/* & */
/* & */
/* & */
__device__ void GetNs(int , int , int , int , int , int * , int * , int * , int * );
/* & */
/* & */
/* & */
/* & */
__device__ void KahanSum(float * , float , float * , float * , float * );
texture<float4, 1, cudaReadModeElementType> texCoors;
texture<float2, 1, cudaReadModeElementType> texSprms;
texture<float , 1, cudaReadModeElementType> texWghts;
__global__ void ComputeX(uint4 * d_Work, float * d_Output, int Offset,  struct _gpufi_data_ *gpufi_dev)
{
    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_BEGIN, 0, "ComputeX");
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 0, "d_Work", (int*)&d_Work, GPUFI_DATATYPE_UNKNOWN_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 1, "d_Output", (int*)&d_Output, GPUFI_DATATYPE_FLOAT_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 2, "Offset", (int*)&Offset, GPUFI_DATATYPE_INTEGER);


    __shared__ float Data[64];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 8, "Data", (int*)&Data, GPUFI_DATATYPE_FLOAT);


    __shared__ uint4 s_Work;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 9, "s_Work", (int*)&s_Work, GPUFI_DATATYPE_UNKNOWN);


    int blid = blockIdx.x;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 10, "blid", (int*)&blid, GPUFI_DATATYPE_INTEGER);


    int thid = threadIdx.x;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 11, "thid", (int*)&thid, GPUFI_DATATYPE_INTEGER);


    int myWorkIndex = (((Offset+blid)<<6)+thid);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 12, "myWorkIndex", (int*)&myWorkIndex, GPUFI_DATATYPE_INTEGER);


    uint4 myWork;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 13, "myWork", (int*)&myWork, GPUFI_DATATYPE_UNKNOWN);


    int localthid, a1, a2, a3, a4;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 14, "localthid", (int*)&localthid, GPUFI_DATATYPE_INTEGER);


    float Result = 0.0;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 15, "Result", (int*)&Result, GPUFI_DATATYPE_FLOAT);


    int Maxthid;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 16, "Maxthid", (int*)&Maxthid, GPUFI_DATATYPE_INTEGER);


    unsigned int s;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 17, "s", (int*)&s, GPUFI_DATATYPE_INTEGER);


    if (( ! thid))
    {
        s_Work=d_Work[(Offset+blid)];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 18, "s_Work", (int*)&s_Work, GPUFI_DATATYPE_UNKNOWN);


    }
    __syncthreads();
    myWork=s_Work;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 19, "myWork", (int*)&myWork, GPUFI_DATATYPE_UNKNOWN);


    GetBases(myWork.x, myWorkIndex, myWork.w, ( & localthid), ( & a1), ( & a2), ( & a3), ( & a4));
    Maxthid=__mul24(a1, __mul24(a2, __mul24(a3, a4)));
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 20, "Maxthid", (int*)&Maxthid, GPUFI_DATATYPE_INTEGER);


    if ((localthid<Maxthid))
    {
        int n1, n2, n3, n4;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 21, "n1", (int*)&n1, GPUFI_DATATYPE_INTEGER);


        int off1, off2, off3, off4;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 22, "off1", (int*)&off1, GPUFI_DATATYPE_INTEGER);


        int atom1, atom2, atom3, atom4;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 23, "atom1", (int*)&atom1, GPUFI_DATATYPE_INTEGER);


        float4 Atom1;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 24, "Atom1", (int*)&Atom1, GPUFI_DATATYPE_UNKNOWN);


        float4 Atom2;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 25, "Atom2", (int*)&Atom2, GPUFI_DATATYPE_UNKNOWN);


        float4 Atom3;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 26, "Atom3", (int*)&Atom3, GPUFI_DATATYPE_UNKNOWN);


        float4 Atom4;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 27, "Atom4", (int*)&Atom4, GPUFI_DATATYPE_UNKNOWN);


        float2 Param1;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 28, "Param1", (int*)&Param1, GPUFI_DATATYPE_UNKNOWN);


        float2 Param2;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 29, "Param2", (int*)&Param2, GPUFI_DATATYPE_UNKNOWN);


        float2 Param3;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 30, "Param3", (int*)&Param3, GPUFI_DATATYPE_UNKNOWN);


        float2 Param4;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 31, "Param4", (int*)&Param4, GPUFI_DATATYPE_UNKNOWN);


        float R12;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 32, "R12", (int*)&R12, GPUFI_DATATYPE_FLOAT);


        float R34;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 33, "R34", (int*)&R34, GPUFI_DATATYPE_FLOAT);


        float sum12;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 34, "sum12", (int*)&sum12, GPUFI_DATATYPE_FLOAT);


        float sum34;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 35, "sum34", (int*)&sum34, GPUFI_DATATYPE_FLOAT);


        float prod12;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 36, "prod12", (int*)&prod12, GPUFI_DATATYPE_FLOAT);


        float prod34;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 37, "prod34", (int*)&prod34, GPUFI_DATATYPE_FLOAT);


        float preexp;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 38, "preexp", (int*)&preexp, GPUFI_DATATYPE_FLOAT);


        float preintegral;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 39, "preintegral", (int*)&preintegral, GPUFI_DATATYPE_FLOAT);


        GetAtoms(myWork.y, ( & atom1), ( & atom2), ( & atom3), ( & atom4));
        GetNs(localthid, a1, a2, a3, a4, ( & n1), ( & n2), ( & n3), ( & n4));
        GetOffsets(myWork.z, ( & off1), ( & off2), ( & off3), ( & off4));
        n1+=off1;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 40, "n1", (int*)&n1, GPUFI_DATATYPE_INTEGER);


        n2+=off2;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 41, "n2", (int*)&n2, GPUFI_DATATYPE_INTEGER);


        n3+=off3;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 42, "n3", (int*)&n3, GPUFI_DATATYPE_INTEGER);


        n4+=off4;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 43, "n4", (int*)&n4, GPUFI_DATATYPE_INTEGER);


        Atom1=tex1D(texCoors, ((float)atom1));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 44, "Atom1", (int*)&Atom1, GPUFI_DATATYPE_UNKNOWN);


        Atom2=tex1D(texCoors, ((float)atom2));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 45, "Atom2", (int*)&Atom2, GPUFI_DATATYPE_UNKNOWN);


        Atom3=tex1D(texCoors, ((float)atom3));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 46, "Atom3", (int*)&Atom3, GPUFI_DATATYPE_UNKNOWN);


        Atom4=tex1D(texCoors, ((float)atom4));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 47, "Atom4", (int*)&Atom4, GPUFI_DATATYPE_UNKNOWN);


        Param1=tex1D(texSprms, ((float)n1));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 48, "Param1", (int*)&Param1, GPUFI_DATATYPE_UNKNOWN);


        Param2=tex1D(texSprms, ((float)n2));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 49, "Param2", (int*)&Param2, GPUFI_DATATYPE_UNKNOWN);


        Param3=tex1D(texSprms, ((float)n3));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 50, "Param3", (int*)&Param3, GPUFI_DATATYPE_UNKNOWN);


        Param4=tex1D(texSprms, ((float)n4));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 51, "Param4", (int*)&Param4, GPUFI_DATATYPE_UNKNOWN);


        R12=dist2(Atom1, Atom2);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 52, "R12", (int*)&R12, GPUFI_DATATYPE_FLOAT);


        R34=dist2(Atom3, Atom4);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 53, "R34", (int*)&R34, GPUFI_DATATYPE_FLOAT);


        sum12=(Param1.x+Param2.x);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 54, "sum12", (int*)&sum12, GPUFI_DATATYPE_FLOAT);


        sum34=(Param3.x+Param4.x);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 55, "sum34", (int*)&sum34, GPUFI_DATATYPE_FLOAT);


        prod12=(Param1.x*Param2.x);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 56, "prod12", (int*)&prod12, GPUFI_DATATYPE_FLOAT);


        prod34=(Param3.x*Param4.x);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 57, "prod34", (int*)&prod34, GPUFI_DATATYPE_FLOAT);


        preexp=((__fdividef(prod12, sum12)*R12)+(__fdividef(prod34, sum34)*R34));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 58, "preexp", (int*)&preexp, GPUFI_DATATYPE_FLOAT);


        preintegral=(__fdividef(((((Param1.y*Param2.y)*Param3.y)*Param4.y)*__expf(( - preexp))), (sum12*sum34))*(1/sqrtf((sum12+sum34))));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 59, "preintegral", (int*)&preintegral, GPUFI_DATATYPE_FLOAT);


        if (((preintegral*preintegral)>1.0E-23))
        {
            float3 Atomp = ReducePair(Atom1, Atom2, Param1, Param2, sum12);
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 60, "Atomp", (int*)&Atomp, GPUFI_DATATYPE_UNKNOWN);


            float3 Atomq = ReducePair(Atom3, Atom4, Param3, Param4, sum34);
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 61, "Atomq", (int*)&Atomq, GPUFI_DATATYPE_UNKNOWN);


            float rpq2 = dist2(Atomp, Atomq);
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 62, "rpq2", (int*)&rpq2, GPUFI_DATATYPE_FLOAT);


            float rho = __fdividef((sum12*sum34), (sum12+sum34));
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 63, "rho", (int*)&rho, GPUFI_DATATYPE_FLOAT);


            float weight = Root((rpq2*rho));
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 64, "weight", (int*)&weight, GPUFI_DATATYPE_FLOAT);


            Result=((34.98683666*preintegral)*weight);
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 65, "Result", (int*)&Result, GPUFI_DATATYPE_FLOAT);


        }
    }
    Data[thid]=Result;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 66, "Data[thid]", (int*)&Data[thid], GPUFI_DATATYPE_FLOAT);


    __syncthreads();
    /* Fault Injector Instrumentation Begin */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_BEGIN);
    /* Fault Injector Instrumentation End */

    for (s=(blockDim.x>>1); s>0; s=(s>>1))
    {
        /* Fault Injector Instrumentation Begin */
        GPUFI_KERNEL_ITERATION(gpufi_dev);
        /* Fault Injector Instrumentation End */

        if ((thid<s))
        {
            Data[thid]+=Data[(thid+s)];
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 69, "Data[thid]", (int*)&Data[thid], GPUFI_DATATYPE_FLOAT);


        }
        __syncthreads();
    }
    /* Automatically inserted by Cetus_Cuda */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_END);
    /* Fault Injector Instrumentation End *//* End of Cetus_Cuda code */

    GPUFI_KERNEL_VARIABLE(gpufi_dev, 68, "s", (int*)&s, GPUFI_DATATYPE_INTEGER);


    if (( ! thid))
    {
        d_Output[(Offset+blid)]=Data[0];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 70, "d_Output[(Offset+blid)]", (int*)&d_Output[(Offset+blid)], GPUFI_DATATYPE_FLOAT);


    }
    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_END, 0, "ComputeX");
}

__global__ void DoReduction(float * d_ReductionSum, float * d_Output, uint2 * d_FinalReduce, int block_size, int Offset,  struct _gpufi_data_ *gpufi_dev)
{
    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_BEGIN, 1, "DoReduction");
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 3, "d_ReductionSum", (int*)&d_ReductionSum, GPUFI_DATATYPE_FLOAT_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 4, "d_Output", (int*)&d_Output, GPUFI_DATATYPE_FLOAT_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 5, "d_FinalReduce", (int*)&d_FinalReduce, GPUFI_DATATYPE_UNKNOWN_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 6, "block_size", (int*)&block_size, GPUFI_DATATYPE_INTEGER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 7, "Offset", (int*)&Offset, GPUFI_DATATYPE_INTEGER);


    int firstElement;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 71, "firstElement", (int*)&firstElement, GPUFI_DATATYPE_INTEGER);


    int offset;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 72, "offset", (int*)&offset, GPUFI_DATATYPE_INTEGER);


    __shared__ float Result[64];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 73, "Result", (int*)&Result, GPUFI_DATATYPE_FLOAT);


    int blid = blockIdx.x;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 74, "blid", (int*)&blid, GPUFI_DATATYPE_INTEGER);


    int thid = threadIdx.x;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 75, "thid", (int*)&thid, GPUFI_DATATYPE_INTEGER);


    uint2 myWork = d_FinalReduce[(blid+Offset)];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 76, "myWork", (int*)&myWork, GPUFI_DATATYPE_UNKNOWN);


    unsigned int s;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 77, "s", (int*)&s, GPUFI_DATATYPE_INTEGER);


    firstElement=myWork.x;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 78, "firstElement", (int*)&firstElement, GPUFI_DATATYPE_INTEGER);


    offset=myWork.y;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 79, "offset", (int*)&offset, GPUFI_DATATYPE_INTEGER);


    if ((thid<offset))
    {
        Result[thid]=d_Output[(firstElement+thid)];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 80, "Result[thid]", (int*)&Result[thid], GPUFI_DATATYPE_FLOAT);


    }
    else
    {
        Result[thid]=0.0;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 81, "Result[thid]", (int*)&Result[thid], GPUFI_DATATYPE_FLOAT);


    }
    __syncthreads();
    /* Fault Injector Instrumentation Begin */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_BEGIN);
    /* Fault Injector Instrumentation End */

    for (s=(blockDim.x>>1); s>0; s=(s>>1))
    {
        /* Fault Injector Instrumentation Begin */
        GPUFI_KERNEL_ITERATION(gpufi_dev);
        /* Fault Injector Instrumentation End */

        if ((thid<s))
        {
            Result[thid]+=Result[(thid+s)];
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 84, "Result[thid]", (int*)&Result[thid], GPUFI_DATATYPE_FLOAT);


        }
        __syncthreads();
    }
    /* Automatically inserted by Cetus_Cuda */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_END);
    /* Fault Injector Instrumentation End *//* End of Cetus_Cuda code */

    GPUFI_KERNEL_VARIABLE(gpufi_dev, 83, "s", (int*)&s, GPUFI_DATATYPE_INTEGER);


    if (( ! thid))
    {
        d_ReductionSum[(blid+Offset)]=Result[0];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 85, "d_ReductionSum[(blid+Offset)]", (int*)&d_ReductionSum[(blid+Offset)], GPUFI_DATATYPE_FLOAT);


    }
    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_END, 1, "DoReduction");
}

__device__ float product1D(float alpha_a, float coor_a, float alpha_b, float coor_b, float sum_ab)
{
    return __fdividef(((alpha_a*coor_a)+(alpha_b*coor_b)), sum_ab);
}

__device__ float dist2(float3 Atom1, float3 Atom2)
{
    float dx = (Atom1.x-Atom2.x);
    float dy = (Atom1.y-Atom2.y);
    float dz = (Atom1.z-Atom2.z);
    return (((dx*dx)+(dy*dy))+(dz*dz));
}

__device__ float dist2(float4 Atom1, float4 Atom2)
{
    float dx = (Atom1.x-Atom2.x);
    float dy = (Atom1.y-Atom2.y);
    float dz = (Atom1.z-Atom2.z);
    return (((dx*dx)+(dy*dy))+(dz*dz));
}

__device__ float3 ReducePair(float4 Atom1, float4 Atom2, float2 Param1, float2 Param2, float sum_12)
{
    float3 Atomp;
    Atomp.x=product1D(Param1.x, Atom1.x, Param2.x, Atom2.x, sum_12);
    Atomp.y=product1D(Param1.x, Atom1.y, Param2.x, Atom2.y, sum_12);
    Atomp.z=product1D(Param1.x, Atom1.z, Param2.x, Atom2.z, sum_12);
    return Atomp;
}

__device__ float Root(float X)
{
    float rPIE4;
    float WW1 = 0.0;
    float F1, E, Y, inv;
    rPIE4=1.273239545;
    if ((X<3.0E-7))
    {
        WW1=(1.0-(0.333333333*X));
    }
    else
    {
        if ((X<1.0))
        {
            F1=((((((((((((((((((( - 8.36313918003957E-8)*X)+1.21222603512827E-6)*X)-1.15662609053481E-5)*X)+9.25197374512647E-5)*X)-6.40994113129432E-4)*X)+0.00378787044215009)*X)-0.0185185172458485)*X)+0.0714285713298222)*X)-0.199999999997023)*X)+0.333333333333318);
            WW1=(((X+X)*F1)+__expf(( - X)));
        }
        else
        {
            if ((X<3.0))
            {
                Y=(X-2.0);
                F1=((((((((((((((((((((((( - 1.61702782425558E-10)*Y)+1.96215250865776E-9)*Y)-2.14234468198419E-8)*Y)+2.17216556336318E-7)*Y)-1.98850171329371E-6)*Y)+1.62429321438911E-5)*Y)-1.16740298039895E-4)*Y)+7.24888732052332E-4)*Y)-0.00379490003707156)*Y)+0.0161723488664661)*Y)-0.0529428148329736)*Y)+0.115702180856167);
                WW1=(((X+X)*F1)+__expf(( - X)));
            }
            else
            {
                if ((X<5.0))
                {
                    Y=(X-4.0);
                    F1=((((((((((((((((((((((( - 2.62453564772299E-11)*Y)+3.24031041623823E-10)*Y)-3.614965656163E-9)*Y)+3.760256799971E-8)*Y)-3.553558319675E-7)*Y)+3.022556449731E-6)*Y)-2.290098979647E-5)*Y)+1.526537461148E-4)*Y)-8.81947375894379E-4)*Y)+0.00433207949514611)*Y)-0.0175257821619926)*Y)+0.0528406320615584);
                    WW1=(((X+X)*F1)+__expf(( - X)));
                }
                else
                {
                    if ((X<10.0))
                    {
                        E=__expf(( - X));
                        inv=(1/X);
                        WW1=((((((((((((((0.46897511375022*inv)-0.69955602298985)*inv)+0.53689283271887)*inv)-0.32883030418398)*inv)+0.24645596956002)*inv)-0.49984072848436)*inv)-3.1501078774085E-6)*E)+(1/sqrtf((rPIE4*X))));
                    }
                    else
                    {
                        if ((X<15.0))
                        {
                            E=__expf(( - X));
                            inv=(1/X);
                            WW1=((((((((( - 0.18784686463512)*inv)+0.22991849164985)*inv)-0.49893752514047)*inv)-2.1916512131607E-5)*E)+(1/sqrtf((rPIE4*X))));
                        }
                        else
                        {
                            if ((X<33.0))
                            {
                                E=__expf(( - X));
                                inv=(1/X);
                                WW1=((((((0.1962326414943*inv)-0.4969524146449)*inv)-6.0156581186481E-5)*E)+(1/sqrtf((rPIE4*X))));
                            }
                            else
                            {
                                WW1=(1/sqrtf((rPIE4*X)));
                            }
                        }
                    }
                }
            }
        }
    }
    return WW1;
}

/* & */
/* & */
/* & */
/* & */
/* & */
__device__ void GetBases(int Work, int thid, int Shift, int * localthid, int * a1, int * a2, int * a3, int * a4)
{
    ( * a1)=((Work&((unsigned int)61440))>>12);
    ( * a2)=((Work&((unsigned int)3840))>>8);
    ( * a3)=((Work&((unsigned int)240))>>4);
    ( * a4)=(Work&((unsigned int)15));
    ( * localthid)=(thid-(Shift<<6));
}

/* & */
/* & */
/* & */
/* & */
__device__ void GetNs(int localthid, int a1, int a2, int a3, int a4, int * n1, int * n2, int * n3, int * n4)
{
    int prod = __mul24(a2, __mul24(a3, a4));
    int res = localthid;
    ( * n1)=__fdividef(res, prod);
    res-=__mul24(( * n1), prod);
    prod=__mul24(a3, a4);
    ( * n2)=__fdividef(res, prod);
    res-=__mul24(( * n2), prod);
    prod=a4;
    ( * n3)=__fdividef(res, prod);
    res-=__mul24(( * n3), prod);
    ( * n4)=res;
}

/* & */
/* & */
/* & */
/* & */
__device__ void GetAtoms(int Work, int * atom1, int * atom2, int * atom3, int * atom4)
{
    ( * atom1)=((Work&((unsigned int)4.27819008E9))>>24);
    ( * atom2)=((Work&((unsigned int)16711680))>>16);
    ( * atom3)=((Work&((unsigned int)65280))>>8);
    ( * atom4)=(Work&((unsigned int)255));
}

/* & */
/* & */
/* & */
/* & */
__device__ void GetOffsets(int Work, int * off1, int * off2, int * off3, int * off4)
{
    ( * off1)=((Work&((unsigned int)4.27819008E9))>>24);
    ( * off2)=((Work&((unsigned int)16711680))>>16);
    ( * off3)=((Work&((unsigned int)65280))>>8);
    ( * off4)=(Work&((unsigned int)255));
}
