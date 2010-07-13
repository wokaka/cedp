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
__global__ void ComputePhiMag_GPU(float * phiR, float * phiI, float * phiMag, int numK)
{
int indexK = ((blockIdx.x*512)+threadIdx.x);
if ((indexK<numK))
{
float real = phiR[indexK];
float imag = phiI[indexK];
phiMag[indexK]=((real*real)+(imag*imag));
}
}

__global__ void ComputeQ_GPU(int numK, int kGlobalIndex, float * x, float * y, float * z, float * Qr, float * Qi)
{
float sX;
float sY;
float sZ;
float sQr;
float sQi;
/* Determine the element of the X arrays computed by this thread */
int xIndex = ((blockIdx.x*256)+threadIdx.x);
/* Read block's X values from global mem to shared mem */
int kIndex = 0;
sX=x[xIndex];
sY=y[xIndex];
sZ=z[xIndex];
sQr=Qr[xIndex];
sQi=Qi[xIndex];
/* Loop over all elements of K in constant mem to compute a partial value */
/* for X. */
if ((numK%2))
{
float expArg = (6.283185307179586*(((ck[0].Kx*sX)+(ck[0].Ky*sY))+(ck[0].Kz*sZ)));
sQr+=(ck[0].PhiMag*cos(expArg));
sQi+=(ck[0].PhiMag*sin(expArg));
kIndex ++ ;
kGlobalIndex ++ ;
}
for (; (kIndex<1024)&&(kGlobalIndex<numK); ((kIndex+=2), (kGlobalIndex+=2)))
{
float expArg = (6.283185307179586*(((ck[kIndex].Kx*sX)+(ck[kIndex].Ky*sY))+(ck[kIndex].Kz*sZ)));
int kIndex1;
float expArg1;
sQr+=(ck[kIndex].PhiMag*cos(expArg));
sQi+=(ck[kIndex].PhiMag*sin(expArg));
kIndex1=(kIndex+1);
expArg1=(6.283185307179586*(((ck[kIndex1].Kx*sX)+(ck[kIndex1].Ky*sY))+(ck[kIndex1].Kz*sZ)));
sQr+=(ck[kIndex1].PhiMag*cos(expArg1));
sQi+=(ck[kIndex1].PhiMag*sin(expArg1));
}
Qr[xIndex]=sQr;
Qi[xIndex]=sQi;
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
ComputePhiMag_GPU<<<DimPhiMagGrid,DimPhiMagBlock>>>(phiR_d, phiI_d, phiMag_d, numK);
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
/* printf("Launch GPU kernel: %d x (%d, %d) x (%d, %d); %d\n", */
/* QGrids, DimQGrid.x, DimQGrid.y, DimQBlock.x, DimQBlock.y, */
/* KERNEL_Q_K_ELEMS_PER_GRID); */
for (QGrid=0; QGrid<QGrids; QGrid ++ )
{
/* Put the tile of K values into constant mem */
int QGridBase = (QGrid*1024);
kValues * kValsTile = (kVals+QGridBase);
int numElems = ((1024<(numK-QGridBase)) ? 1024 : (numK-QGridBase));
cudaMemcpyToSymbol(ck, kValsTile, (numElems*sizeof (kValues)), 0);
ComputeQ_GPU<<<DimQGrid, DimQBlock>>>(numK, QGridBase, x_d, y_d, z_d, Qr_d, Qi_d);
}
}

void createDataStructsCPU(int numK, int numX, float *  * phiMag, float *  * Qr, float *  * Qi)
{
( * phiMag)=((float * )memalign(16, (numK*sizeof (float))));
( * Qr)=((float * )memalign(16, (numX*sizeof (float))));
( * Qi)=((float * )memalign(16, (numX*sizeof (float))));
}

