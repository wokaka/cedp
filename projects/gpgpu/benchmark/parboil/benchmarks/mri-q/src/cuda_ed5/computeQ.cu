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
__constant__ __device__ kValues ck[1024];
//__constant__ __device__ kValues *ck_dup = ck;

#define GPUFI_CHECK(n1,n2) { if(n1 != n2) GPUFI_EXIT(0);}

__global__ void ComputePhiMag_GPU(float * phiR, float * phiI, float * phiMag, int numK)
{
		int numK_dup = numK;
		//ed
		float *phiR_dup = phiR;
		float *phiI_dup = phiI;
		float *phiMag_dup = phiMag;
		
    int indexK = ((blockIdx.x*512)+threadIdx.x);
    int indexK_dup = ((blockIdx.x*512)+threadIdx.x);
    
    GPUFI_CHECK(indexK,indexK_dup);
    GPUFI_CHECK(numK,numK_dup);
    if ((indexK<numK))
    {
        // [ED]
        if(phiR != phiR_dup) GPUFI_EXIT(0);
		    GPUFI_CHECK(indexK,indexK_dup);
        float real = phiR[indexK];
        float real_dup = phiR[indexK];
        
        // [ED]
        if(phiI != phiI_dup) GPUFI_EXIT(0);
		    GPUFI_CHECK(indexK,indexK_dup);
        float imag = phiI[indexK];
        float imag_dup = phiI[indexK];
        
        // [ED]
        if(phiMag != phiMag_dup) GPUFI_EXIT(0);
		    GPUFI_CHECK(indexK,indexK_dup);
		    GPUFI_CHECK(real,real_dup);
		    GPUFI_CHECK(imag,imag_dup);
        phiMag[indexK]=((real*real)+(imag*imag));
		    GPUFI_CHECK(phiMag[indexK],((real*real)+(imag*imag)));
    }
}

__global__ void ComputeQ_GPU(int numK, int kGlobalIndex, float * x, float * y, float * z, float * Qr, float * Qi)
{
		int numK_dup = numK;
		int kGlobalIndex_dup = kGlobalIndex;
		// ed
		float *x_dup = x;
		float *y_dup = y;
		float *z_dup = z;
		float *Qr_dup = Qr;
		float *Qi_dup = Qi;
		
    float sX;
    float sY;
    float sZ;
    float sQr;
    float sQi;
    /* Determine the element of the X arrays computed by this thread
     */
    // [ED]
    //if(x != x_dup)
    //    GPUFI_EXIT(0);


    int xIndex = ((blockIdx.x*256)+threadIdx.x);
    int xIndex_dup = ((blockIdx.x*256)+threadIdx.x);
    /* Read block's X values from global mem to shared mem
     */
    int kIndex = 0;
    int kIndex_dup = 0;

    // [ED]
    if(x != x_dup) GPUFI_EXIT(0);
    GPUFI_CHECK(xIndex,xIndex_dup);
    sX=x[xIndex];
    float sX_dup = x[xIndex];

    // [ED]
    if(y != y_dup) GPUFI_EXIT(0);
    GPUFI_CHECK(xIndex,xIndex_dup);
    sY=y[xIndex];
    float sY_dup = y[xIndex];
    
    // [ED]
    if(z != z_dup) GPUFI_EXIT(0);
    GPUFI_CHECK(xIndex,xIndex_dup);
    sZ=z[xIndex];
    float sZ_dup = z[xIndex];
    
    // [ED]
    if(Qr != Qr_dup) GPUFI_EXIT(0);
    GPUFI_CHECK(xIndex,xIndex_dup);
    sQr=Qr[xIndex];
    float sQr_dup = Qr[xIndex];
    
    // [ED]
    if(Qi != Qi_dup) GPUFI_EXIT(0);
    GPUFI_CHECK(xIndex,xIndex_dup);
    sQi=Qi[xIndex];
    float sQi_dup = Qi[xIndex];
    
    /* Loop over all elements of K in constant mem to compute a partial value
     */
    /* for X.
     */
    GPUFI_CHECK(numK,numK_dup);
    if ((numK%2))
    {
		    // [ED]
		    //if(ck != ck_dup) GPUFI_EXIT(0);
		    GPUFI_CHECK(sX,sX_dup);
		    GPUFI_CHECK(sY,sY_dup);
		    GPUFI_CHECK(sZ,sZ_dup);
        float expArg = (6.283185307179586*(((ck[0].Kx*sX)+(ck[0].Ky*sY))+(ck[0].Kz*sZ)));
        float expArg_dup = (6.283185307179586*(((ck[0].Kx*sX)+(ck[0].Ky*sY))+(ck[0].Kz*sZ)));
		    //if(ck != ck_dup) GPUFI_EXIT(0);
		    GPUFI_CHECK(expArg,expArg_dup);
        sQr+=(ck[0].PhiMag*cos(expArg));
		    //if(ck != ck_dup) GPUFI_EXIT(0);
		    GPUFI_CHECK(expArg,expArg_dup);
        sQi+=(ck[0].PhiMag*sin(expArg));
		    GPUFI_CHECK(kIndex,kIndex_dup);
        kIndex ++ ;
        kIndex_dup++;
		    GPUFI_CHECK(kGlobalIndex,kGlobalIndex_dup);
        kGlobalIndex ++ ;
        kGlobalIndex_dup ++ ;
    }
    for (; (kIndex<1024&&kIndex==kIndex_dup)&&(kGlobalIndex<numK&&kGlobalIndex==kGlobalIndex_dup&&numK==numK_dup); ((kIndex+=2), (kGlobalIndex+=2), kIndex_dup+=2, kGlobalIndex_dup+=2))
    {
        
		    //if(ck != ck_dup) GPUFI_EXIT(0);
		    GPUFI_CHECK(kIndex,kIndex_dup);
		    GPUFI_CHECK(sX,sX_dup);
		    GPUFI_CHECK(sY,sY_dup);
		    GPUFI_CHECK(sZ,sZ_dup);
        float expArg = (6.283185307179586*(((ck[kIndex].Kx*sX)+(ck[kIndex].Ky*sY))+(ck[kIndex].Kz*sZ)));
        float expArg_dup = (6.283185307179586*(((ck[kIndex].Kx*sX)+(ck[kIndex].Ky*sY))+(ck[kIndex].Kz*sZ)));
        int kIndex1;
        int kIndex1_dup;
        float expArg1;
        float expArg1_dup;
		    //if(ck != ck_dup) GPUFI_EXIT(0);
		    GPUFI_CHECK(kIndex,kIndex_dup);
		    GPUFI_CHECK(expArg,expArg_dup);
        sQr+=(ck[kIndex].PhiMag*cos(expArg));
        sQr_dup+=(ck[kIndex].PhiMag*cos(expArg));
		    //if(ck != ck_dup) GPUFI_EXIT(0);
		    GPUFI_CHECK(kIndex,kIndex_dup);
		    GPUFI_CHECK(expArg,expArg_dup);
        sQi+=(ck[kIndex].PhiMag*sin(expArg));
		    GPUFI_CHECK(expArg,expArg_dup);
        sQi_dup+=(ck[kIndex].PhiMag*sin(expArg));
		    GPUFI_CHECK(kIndex,kIndex_dup);
        kIndex1_dup=(kIndex+1);
        kIndex1=(kIndex+1);
		    //if(ck != ck_dup) GPUFI_EXIT(0);
		    GPUFI_CHECK(kIndex1,kIndex1_dup);
		    GPUFI_CHECK(sX,sX_dup);
		    GPUFI_CHECK(sY,sY_dup);
		    GPUFI_CHECK(sZ,sZ_dup);
        expArg1=(6.283185307179586*(((ck[kIndex1].Kx*sX)+(ck[kIndex1].Ky*sY))+(ck[kIndex1].Kz*sZ)));
        expArg1_dup=(6.283185307179586*(((ck[kIndex1].Kx*sX)+(ck[kIndex1].Ky*sY))+(ck[kIndex1].Kz*sZ)));
		    //if(ck != ck_dup) GPUFI_EXIT(0);
		    GPUFI_CHECK(kIndex1,kIndex1_dup);
		    GPUFI_CHECK(expArg,expArg_dup);
        sQr+=(ck[kIndex1].PhiMag*cos(expArg1));
		    GPUFI_CHECK(expArg,expArg_dup);
        sQr_dup+=(ck[kIndex1].PhiMag*cos(expArg1));
		    //if(ck != ck_dup) GPUFI_EXIT(0);
		    GPUFI_CHECK(kIndex1,kIndex1_dup);
		    GPUFI_CHECK(expArg,expArg_dup);
        sQi+=(ck[kIndex1].PhiMag*sin(expArg1));
		    GPUFI_CHECK(expArg,expArg_dup);
        sQi_dup+=(ck[kIndex1].PhiMag*sin(expArg1));
    }
    // [ED]
    if(Qr != Qr_dup) GPUFI_EXIT(0);
    GPUFI_CHECK(xIndex,xIndex_dup);
    Qr[xIndex]=sQr;
    GPUFI_CHECK(Qr[xIndex],sQr);

    // [ED]
    if(Qi != Qi_dup) GPUFI_EXIT(0);
    GPUFI_CHECK(xIndex,xIndex_dup);
    Qi[xIndex]=sQi;
    GPUFI_CHECK(Qi[xIndex],sQi);
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
    ComputePhiMag_GPU<<<DimPhiMagGrid, DimPhiMagBlock>>> (phiR_d, phiI_d, phiMag_d, numK);
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
        ComputeQ_GPU<<<DimQGrid, DimQBlock>>> (numK, QGridBase, x_d, y_d, z_d, Qr_d, Qi_d);
    }
}

void createDataStructsCPU(int numK, int numX, float *  * phiMag, float *  * Qr, float *  * Qi)
{
    ( * phiMag)=((float * )memalign(16, (numK*sizeof (float))));
    ( * Qr)=((float * )memalign(16, (numX*sizeof (float))));
    ( * Qi)=((float * )memalign(16, (numX*sizeof (float))));
}
