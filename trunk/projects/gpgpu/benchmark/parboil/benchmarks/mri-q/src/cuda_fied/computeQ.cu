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

struct kValues
{
    float Kx;
    float Ky;
    float Kz;
    float PhiMag;
};

/*
Values in the k-space coordinate system are stored in constant memory
 * on the GPU
*/
__constant__ kValues ck[1024];
__global__ void ComputePhiMag_GPU(float * phiR, float * phiI, float * phiMag, int numK,  struct _gpufi_data_ *gpufi_dev)
{
    // [ED]
    int numK_dup = numK;


    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_BEGIN, 0, "ComputePhiMag_GPU");
    int indexK = ((blockIdx.x*512)+threadIdx.x);
    // [ED]
    int indexK_dup = ((blockIdx.x*512)+threadIdx.x);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 0, "indexK", (int*)&indexK);


    // [ED]
    if(indexK != indexK_dup)
        GPUFI_EXIT(0);


    // [ED]
    if(numK != numK_dup)
        GPUFI_EXIT(0);


    if ((indexK<numK))
    {
        float real = phiR[indexK];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 1, "real", (int*)&real);


        float imag = phiI[indexK];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 2, "imag", (int*)&imag);


        phiMag[indexK]=((real*real)+(imag*imag));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 3, "phiMag[indexK]", (int*)&phiMag[indexK]);


    }
    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_END, 0, "ComputePhiMag_GPU");
}

__global__ void ComputeQ_GPU(int numK, int kGlobalIndex, float * x, float * y, float * z, float * Qr, float * Qi,  struct _gpufi_data_ *gpufi_dev)
{
    // [ED]
    int kGlobalIndex_dup = kGlobalIndex;


    // [ED]
    int numK_dup = numK;


    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_BEGIN, 1, "ComputeQ_GPU");
    float sX;
    float sY;
    float sZ;
    float sQr;
    float sQi;
    /* Determine the element of the X arrays computed by this thread
     */
    int xIndex = ((blockIdx.x*256)+threadIdx.x);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 4, "xIndex", (int*)&xIndex);


    /* Read block's X values from global mem to shared mem
     */
    int kIndex = 0;
    // [ED]
    int kIndex_dup = 0;


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 5, "kIndex", (int*)&kIndex);


    sX=x[xIndex];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 6, "sX", (int*)&sX);


    sY=y[xIndex];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 7, "sY", (int*)&sY);


    sZ=z[xIndex];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 8, "sZ", (int*)&sZ);


    sQr=Qr[xIndex];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 9, "sQr", (int*)&sQr);


    sQi=Qi[xIndex];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 10, "sQi", (int*)&sQi);


    /* Loop over all elements of K in constant mem to compute a partial value
     */
    /* for X.
     */
    // [ED]
    if(numK != numK_dup)
        GPUFI_EXIT(0);


    if ((numK%2))
    {
        float expArg = (6.283185307179586*(((ck[0].Kx*sX)+(ck[0].Ky*sY))+(ck[0].Kz*sZ)));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 11, "expArg", (int*)&expArg);


        sQr+=(ck[0].PhiMag*cos(expArg));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 12, "sQr", (int*)&sQr);


        sQi+=(ck[0].PhiMag*sin(expArg));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 13, "sQi", (int*)&sQi);


        kIndex ++ ;
        kGlobalIndex ++ ;
    }
    /* Fault Injector Instrumentation Begin */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_BEGIN);
    /* Fault Injector Instrumentation End */

    // [ED]
    if(kGlobalIndex != kGlobalIndex_dup)
        GPUFI_EXIT(0);


    // [ED]
    if(kIndex != kIndex_dup)
        GPUFI_EXIT(0);


    // [ED]
    if(numK != numK_dup)
        GPUFI_EXIT(0);


    for (; (kIndex<1024)&&(kGlobalIndex<numK); ((kIndex+=2), (kGlobalIndex+=2)))
    {
        /* Fault Injector Instrumentation Begin */
        GPUFI_KERNEL_ITERATION(gpufi_dev);
        /* Fault Injector Instrumentation End */

        float expArg = (6.283185307179586*(((ck[kIndex].Kx*sX)+(ck[kIndex].Ky*sY))+(ck[kIndex].Kz*sZ)));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 14, "expArg", (int*)&expArg);


        int kIndex1;
        float expArg1;
        sQr+=(ck[kIndex].PhiMag*cos(expArg));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 15, "sQr", (int*)&sQr);


        sQi+=(ck[kIndex].PhiMag*sin(expArg));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 16, "sQi", (int*)&sQi);


        kIndex1=(kIndex+1);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 17, "kIndex1", (int*)&kIndex1);


        expArg1=(6.283185307179586*(((ck[kIndex1].Kx*sX)+(ck[kIndex1].Ky*sY))+(ck[kIndex1].Kz*sZ)));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 18, "expArg1", (int*)&expArg1);


        sQr+=(ck[kIndex1].PhiMag*cos(expArg1));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 19, "sQr", (int*)&sQr);


        sQi+=(ck[kIndex1].PhiMag*sin(expArg1));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 20, "sQi", (int*)&sQi);


    }
    /* Automatically inserted by Cetus_Cuda */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_END);
    /* Fault Injector Instrumentation End *//* End of Cetus_Cuda code */

    Qr[xIndex]=sQr;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 21, "Qr[xIndex]", (int*)&Qr[xIndex]);


    Qi[xIndex]=sQi;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 22, "Qi[xIndex]", (int*)&Qi[xIndex]);


    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_END, 1, "ComputeQ_GPU");
}

void computePhiMag_GPU(int numK, float * phiR_d, float * phiI_d, float * phiMag_d)
{
    int phiMagBlocks = (numK/512);
    dim3 DimPhiMagBlock;
    dim3 DimPhiMagGrid;
    if ((numK%512))
    {
        phiMagBlocks ++ ;
    }
    DimPhiMagBlock.x=512;
    DimPhiMagBlock.y=1;
    DimPhiMagBlock.z=1;
    DimPhiMagGrid.x=phiMagBlocks;
    DimPhiMagGrid.y=1;
    DimPhiMagGrid.z=1;
    /* Fault Injection Instrumentation Begin */
    cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));
    CUDA_ERRCK
    cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);
    CUDA_ERRCK
    /* Fault Injection Instrumentation End */

    ComputePhiMag_GPU<<<DimPhiMagGrid, DimPhiMagBlock>>> (phiR_d, phiI_d, phiMag_d, numK, gpufi_dev);
    /* Fault Injection Instrumentation Begin */
    cudaMemcpy(&gpufi_host, gpufi_dev, sizeof(struct _gpufi_data_), cudaMemcpyDeviceToHost);
    CUDA_ERRCK
    cudaFree(gpufi_dev);
    CUDA_ERRCK
    /* Fault Injection Instrumentation End */

}

void computeQ_GPU(int numK, int numX, float * x_d, float * y_d, float * z_d, kValues * kVals, float * Qr_d, float * Qi_d)
{
    int QGrids = (numK/1024);
    int QBlocks;
    dim3 DimQBlock;
    dim3 DimQGrid;
    int QGrid;
    if ((numK%1024))
    {
        QGrids ++ ;
    }
    QBlocks=(numX/256);
    if ((numX%256))
    {
        QBlocks ++ ;
    }
    DimQBlock.x=256;
    DimQBlock.y=1;
    DimQBlock.z=1;
    DimQGrid.x=QBlocks;
    DimQGrid.y=1;
    DimQGrid.z=1;
    /* printf("Launch GPU kernel: %d x (%d, %d) x (%d, %d); %d\n",
     */
    /* QGrids, DimQGrid.x, DimQGrid.y, DimQBlock.x, DimQBlock.y,
     */
    /* KERNEL_Q_K_ELEMS_PER_GRID);
     */
    for (QGrid=0; QGrid<QGrids; QGrid ++ )
    {
        /* Put the tile of K values into constant mem
         */
        int QGridBase = (QGrid*1024);
        kValues * kValsTile = (kVals+QGridBase);
        int numElems = ((1024<(numK-QGridBase)) ? 1024 : (numK-QGridBase));
        cudaMemcpyToSymbol(ck, kValsTile, (numElems*sizeof (kValues)), 0);
        /* Fault Injection Instrumentation Begin */
        cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));
        CUDA_ERRCK
        cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);
        CUDA_ERRCK
        /* Fault Injection Instrumentation End */

        ComputeQ_GPU<<<DimQGrid, DimQBlock>>> (numK, QGridBase, x_d, y_d, z_d, Qr_d, Qi_d, gpufi_dev);
        /* Fault Injection Instrumentation Begin */
        cudaMemcpy(&gpufi_host, gpufi_dev, sizeof(struct _gpufi_data_), cudaMemcpyDeviceToHost);
        CUDA_ERRCK
        cudaFree(gpufi_dev);
        CUDA_ERRCK
        /* Fault Injection Instrumentation End */

    }
}

void createDataStructsCPU(int numK, int numX, float *  * phiMag, float *  * Qr, float *  * Qi)
{
    ( * phiMag)=((float * )memalign(16, (numK*sizeof (float))));
    ( * Qr)=((float * )memalign(16, (numX*sizeof (float))));
    ( * Qi)=((float * )memalign(16, (numX*sizeof (float))));
}
