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
void createDataStructs(int numK, int numX, float * realRhoPhi, float * imagRhoPhi, float * outR, float * outI)
{
realRhoPhi=((float * )calloc(numK, sizeof (float)));
imagRhoPhi=((float * )calloc(numK, sizeof (float)));
outR=((float * )calloc(numX, sizeof (float)));
outI=((float * )calloc(numX, sizeof (float)));
}

__global__ void ComputeRhoPhiGPU(int numK, float * phiR, float * phiI, float * dR, float * dI, float * realRhoPhi, float * imagRhoPhi)
{
int indexK = ((blockIdx.x*512)+threadIdx.x);
if ((indexK<numK))
{
float rPhiR = phiR[indexK];
float rPhiI = phiI[indexK];
float rDR = dR[indexK];
float rDI = dI[indexK];
realRhoPhi[indexK]=((rPhiR*rDR)+(rPhiI*rDI));
imagRhoPhi[indexK]=((rPhiR*rDI)-(rPhiI*rDR));
}
}

__global__ void ComputeFH_GPU(int numK, int kGlobalIndex, float * x, float * y, float * z, float * outR, float * outI)
{
float sX;
float sY;
float sZ;
float sOutR;
float sOutI;
/* Determine the element of the X arrays computed by this thread */
int xIndex = ((blockIdx.x*256)+threadIdx.x);
int kIndex = 0;
int kCnt;
sX=x[xIndex];
sY=y[xIndex];
sZ=z[xIndex];
sOutR=outR[xIndex];
sOutI=outI[xIndex];
/* Loop over all elements of K in constant mem to compute a partial value */
/* for X. */
kCnt=(numK-kGlobalIndex);
if ((kCnt<512))
{
#pragma loop name ComputeFH_GPU#0 
for (kIndex=0; (kIndex<(kCnt%4))&&(kGlobalIndex<numK); ((kIndex ++ ), (kGlobalIndex ++ )))
{
float expArg = (6.283185307179586*(((c[kIndex].Kx*sX)+(c[kIndex].Ky*sY))+(c[kIndex].Kz*sZ)));
float cosArg = cos(expArg);
float sinArg = sin(expArg);
sOutR+=((c[kIndex].RhoPhiR*cosArg)-(c[kIndex].RhoPhiI*sinArg));
sOutI+=((c[kIndex].RhoPhiI*cosArg)+(c[kIndex].RhoPhiR*sinArg));
}
}
#pragma loop name ComputeFH_GPU#1 
for (; (kIndex<512)&&(kGlobalIndex<numK); ((kIndex+=4), (kGlobalIndex+=4)))
{
float expArg = (6.283185307179586*(((c[kIndex].Kx*sX)+(c[kIndex].Ky*sY))+(c[kIndex].Kz*sZ)));
float cosArg = cos(expArg);
float sinArg = sin(expArg);
int kIndex1;
float expArg1;
float cosArg1;
float sinArg1;
int kIndex2;
float expArg2;
float cosArg2;
float sinArg2;
int kIndex3;
float expArg3;
float cosArg3;
float sinArg3;
sOutR+=((c[kIndex].RhoPhiR*cosArg)-(c[kIndex].RhoPhiI*sinArg));
sOutI+=((c[kIndex].RhoPhiI*cosArg)+(c[kIndex].RhoPhiR*sinArg));
kIndex1=(kIndex+1);
expArg1=(6.283185307179586*(((c[kIndex1].Kx*sX)+(c[kIndex1].Ky*sY))+(c[kIndex1].Kz*sZ)));
cosArg1=cos(expArg1);
sinArg1=sin(expArg1);
sOutR+=((c[kIndex1].RhoPhiR*cosArg1)-(c[kIndex1].RhoPhiI*sinArg1));
sOutI+=((c[kIndex1].RhoPhiI*cosArg1)+(c[kIndex1].RhoPhiR*sinArg1));
kIndex2=(kIndex+2);
expArg2=(6.283185307179586*(((c[kIndex2].Kx*sX)+(c[kIndex2].Ky*sY))+(c[kIndex2].Kz*sZ)));
cosArg2=cos(expArg2);
sinArg2=sin(expArg2);
sOutR+=((c[kIndex2].RhoPhiR*cosArg2)-(c[kIndex2].RhoPhiI*sinArg2));
sOutI+=((c[kIndex2].RhoPhiI*cosArg2)+(c[kIndex2].RhoPhiR*sinArg2));
kIndex3=(kIndex+3);
expArg3=(6.283185307179586*(((c[kIndex3].Kx*sX)+(c[kIndex3].Ky*sY))+(c[kIndex3].Kz*sZ)));
cosArg3=cos(expArg3);
sinArg3=sin(expArg3);
sOutR+=((c[kIndex3].RhoPhiR*cosArg3)-(c[kIndex3].RhoPhiI*sinArg3));
sOutI+=((c[kIndex3].RhoPhiI*cosArg3)+(c[kIndex3].RhoPhiR*sinArg3));
}
outR[xIndex]=sOutR;
outI[xIndex]=sOutI;
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
DimPhoPhiGrid.x=rhoPhiBlocks;
DimPhoPhiGrid.y=1;
DimPhoPhiGrid.z=1;
/* printf("Launch RhoPhi Kernel on GPU: Blocks (%d, %d), Threads Per Block %d\n", */
/*       rhoPhiBlocks, 1, KERNEL_RHO_PHI_THREADS_PER_BLOCK); */
ComputeRhoPhiGPU<<<DimRhoPhiGrid, DimRhoPhiBlock>>>(numK, phiR_d, phiI_d, dR_d, dI_d, realRhoPhi_d, imagRhoPhi_d);
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
/* printf("Launch GPU Kernel: Grids %d, Blocks Per Grid (%d, %d), Threads Per Block (%d, %d), K Elems Per Thread %d\n", */
/*       FHGrids, DimFHGrid.x, DimFHGrid.y, DimFHBlock.x, DimFHBlock.y, KERNEL_FH_K_ELEMS_PER_GRID); */
#pragma loop name computeFH_GPU#0 
for (FHGrid=0; FHGrid<FHGrids; FHGrid ++ )
{
/* Put the tile of K values into constant mem */
int FHGridBase = (FHGrid*512);
kValues * kValsTile = (kVals+FHGridBase);
int numElems = ((512<(numK-FHGridBase)) ? 512 : (numK-FHGridBase));
cudaMemcpyToSymbol(c, kValsTile, (numElems*sizeof (kValues)), 0);
{
cudaError_t err;
if (((err=cudaGetLastError())!=cudaSuccess))
{
fprintf(stderr, "CUDA error on line %d: %s\n", 201, cudaGetErrorString(err));
exit(( - 1));
}
}
;
ComputeFH_GPU<<<DimFHGrid, DimFHBlock>>>(numK, FHGridBase, x_d, y_d, z_d, outR_d, outI_d);
{
cudaError_t err;
if (((err=cudaGetLastError())!=cudaSuccess))
{
fprintf(stderr, "CUDA error on line %d: %s\n", 205, cudaGetErrorString(err));
exit(( - 1));
}
}
;
}
}

