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

__global__ void ComputeRhoPhiGPU(int numK, float * phiR, float * phiI, float * dR, float * dI, float * realRhoPhi, float * imagRhoPhi,  struct _gpufi_data_ *gpufi_dev)
{

/* Automatically inserted by Cetus_Cuda */
GPUFI_KERNEL_KERNEL(gpufi_dev, 1);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1001, "A", (int*)&numK);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1002, "", (int*)&phiR);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1002, "", (int*)phiR, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1003, "", (int*)&phiI);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1003, "", (int*)phiI, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1004, "", (int*)&dR);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1004, "", (int*)dR, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1005, "", (int*)&dI);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1005, "", (int*)dI, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1006, "", (int*)&realRhoPhi);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1006, "", (int*)realRhoPhi, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1007, "", (int*)&imagRhoPhi);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1007, "", (int*)imagRhoPhi, 1 /* Array size */, 1 /* Number of faults */);
/* End of Cetus_Cuda code */

int indexK = ((blockIdx.x*512)+threadIdx.x);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1008, "", (int*)&indexK);


if ((indexK<numK))
{
float rPhiR = phiR[indexK];
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1009, "", (int*)&rPhiR);


float rPhiI = phiI[indexK];
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1010, "", (int*)&rPhiI);


float rDR = dR[indexK];
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1011, "", (int*)&rDR);


float rDI = dI[indexK];
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1012, "", (int*)&rDI);


realRhoPhi[indexK]=((rPhiR*rDR)+(rPhiI*rDI));
imagRhoPhi[indexK]=((rPhiR*rDI)-(rPhiI*rDR));
}
}

__global__ void ComputeFH_GPU(int numK, int kGlobalIndex, float * x, float * y, float * z, float * outR, float * outI,  struct _gpufi_data_ *gpufi_dev)
{

/* Automatically inserted by Cetus_Cuda */
GPUFI_KERNEL_KERNEL(gpufi_dev, 2);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1013, "", (int*)&numK);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1014, "", (int*)&kGlobalIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1015, "", (int*)&x);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1015, "", (int*)x, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1016, "", (int*)&y);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1016, "", (int*)y, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1017, "", (int*)&z);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1017, "", (int*)z, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1018, "", (int*)&outR);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1018, "", (int*)outR, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1019, "", (int*)&outI);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1019, "", (int*)outI, 1 /* Array size */, 1 /* Number of faults */);
/* End of Cetus_Cuda code */

float sX;
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1020, "", (int*)&sX);


float sY;
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1021, "", (int*)&sY);


float sZ;
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1022, "", (int*)&sZ);


float sOutR;
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1023, "", (int*)&sOutR);


float sOutI;
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1024, "", (int*)&sOutI);


/* Determine the element of the X arrays computed by this thread */
int xIndex = ((blockIdx.x*256)+threadIdx.x);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1025, "", (int*)&xIndex);


float * test = NULL;
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1026, "", (int*)&test);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1026, "", (int*)test, 1 /* Array size */, 1 /* Number of faults */);


int kIndex = 0;
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1027, "", (int*)&kIndex);


int kCnt;
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1028, "", (int*)&kCnt);


test=( & sOutR);
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
/* Automatically inserted by Cetus_Cuda */
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1013, "", (int*)&numK);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1014, "", (int*)&kGlobalIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1015, "", (int*)&x);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1015, "", (int*)x, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1016, "", (int*)&y);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1016, "", (int*)y, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1017, "", (int*)&z);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1017, "", (int*)z, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1018, "", (int*)&outR);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1018, "", (int*)outR, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1019, "", (int*)&outI);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1019, "", (int*)outI, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1020, "", (int*)&sX);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1021, "", (int*)&sY);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1022, "", (int*)&sZ);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1023, "", (int*)&sOutR);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1024, "", (int*)&sOutI);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1025, "", (int*)&xIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1026, "", (int*)&test);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1026, "", (int*)test, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1027, "", (int*)&kIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1028, "", (int*)&kCnt);
GPUFI_KERNEL_LOOP(gpufi_dev);
/* End of Cetus_Cuda code */

for (kIndex=0; (kIndex<(kCnt%4))&&(kGlobalIndex<numK); ((kIndex ++ ), (kGlobalIndex ++ )))
{
/* Automatically inserted by Cetus_Cuda */
GPUFI_KERNEL_ITERATION(gpufi_dev);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1013, "", (int*)&numK);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1014, "", (int*)&kGlobalIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1015, "", (int*)&x);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1015, "", (int*)x, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1016, "", (int*)&y);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1016, "", (int*)y, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1017, "", (int*)&z);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1017, "", (int*)z, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1018, "", (int*)&outR);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1018, "", (int*)outR, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1019, "", (int*)&outI);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1019, "", (int*)outI, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1020, "", (int*)&sX);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1021, "", (int*)&sY);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1022, "", (int*)&sZ);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1023, "", (int*)&sOutR);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1024, "", (int*)&sOutI);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1025, "", (int*)&xIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1026, "", (int*)&test);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1026, "", (int*)test, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1027, "", (int*)&kIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1028, "", (int*)&kCnt);
/* End of Cetus_Cuda code */

float expArg = (6.283185307179586*(((c[kIndex].Kx*sX)+(c[kIndex].Ky*sY))+(c[kIndex].Kz*sZ)));
float cosArg = cos(expArg);
float sinArg = sin(expArg);
sOutR+=((c[kIndex].RhoPhiR*cosArg)-(c[kIndex].RhoPhiI*sinArg));
sOutI+=((c[kIndex].RhoPhiI*cosArg)+(c[kIndex].RhoPhiR*sinArg));
}
/* Automatically inserted by Cetus_Cuda */
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1013, "", (int*)&numK);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1014, "", (int*)&kGlobalIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1015, "", (int*)&x);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1015, "", (int*)x, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1016, "", (int*)&y);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1016, "", (int*)y, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1017, "", (int*)&z);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1017, "", (int*)z, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1018, "", (int*)&outR);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1018, "", (int*)outR, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1019, "", (int*)&outI);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1019, "", (int*)outI, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1020, "", (int*)&sX);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1021, "", (int*)&sY);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1022, "", (int*)&sZ);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1023, "", (int*)&sOutR);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1024, "", (int*)&sOutI);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1025, "", (int*)&xIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1026, "", (int*)&test);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1026, "", (int*)test, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1027, "", (int*)&kIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1028, "", (int*)&kCnt);
/* End of Cetus_Cuda code */

}
/* Automatically inserted by Cetus_Cuda */
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1013, "", (int*)&numK);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1014, "", (int*)&kGlobalIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1015, "", (int*)&x);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1015, "", (int*)x, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1016, "", (int*)&y);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1016, "", (int*)y, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1017, "", (int*)&z);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1017, "", (int*)z, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1018, "", (int*)&outR);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1018, "", (int*)outR, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1019, "", (int*)&outI);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1019, "", (int*)outI, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1020, "", (int*)&sX);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1021, "", (int*)&sY);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1022, "", (int*)&sZ);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1023, "", (int*)&sOutR);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1024, "", (int*)&sOutI);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1025, "", (int*)&xIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1026, "", (int*)&test);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1026, "", (int*)test, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1027, "", (int*)&kIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1028, "", (int*)&kCnt);
GPUFI_KERNEL_LOOP(gpufi_dev);
/* End of Cetus_Cuda code */

for (; (kIndex<512)&&(kGlobalIndex<numK); ((kIndex+=4), (kGlobalIndex+=4)))
{
/* Automatically inserted by Cetus_Cuda */
GPUFI_KERNEL_ITERATION(gpufi_dev);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1013, "", (int*)&numK);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1014, "", (int*)&kGlobalIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1015, "", (int*)&x);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1015, "", (int*)x, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1016, "", (int*)&y);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1016, "", (int*)y, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1017, "", (int*)&z);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1017, "", (int*)z, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1018, "", (int*)&outR);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1018, "", (int*)outR, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1019, "", (int*)&outI);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1019, "", (int*)outI, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1020, "", (int*)&sX);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1021, "", (int*)&sY);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1022, "", (int*)&sZ);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1023, "", (int*)&sOutR);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1024, "", (int*)&sOutI);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1025, "", (int*)&xIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1026, "", (int*)&test);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1026, "", (int*)test, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1027, "", (int*)&kIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1028, "", (int*)&kCnt);
/* End of Cetus_Cuda code */

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
/* Automatically inserted by Cetus_Cuda */
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1013, "", (int*)&numK);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1014, "", (int*)&kGlobalIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1015, "", (int*)&x);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1015, "", (int*)x, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1016, "", (int*)&y);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1016, "", (int*)y, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1017, "", (int*)&z);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1017, "", (int*)z, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1018, "", (int*)&outR);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1018, "", (int*)outR, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1019, "", (int*)&outI);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1019, "", (int*)outI, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1020, "", (int*)&sX);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1021, "", (int*)&sY);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1022, "", (int*)&sZ);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1023, "", (int*)&sOutR);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1024, "", (int*)&sOutI);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1025, "", (int*)&xIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1026, "", (int*)&test);
GPUFI_KERNEL_VARIABLE_STREAM(gpufi_dev, 1026, "", (int*)test, 1 /* Array size */, 1 /* Number of faults */);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1027, "", (int*)&kIndex);
GPUFI_KERNEL_VARIABLE(gpufi_dev, 1028, "", (int*)&kCnt);
/* End of Cetus_Cuda code */

outR[xIndex]=sOutR;
outI[xIndex]=sOutI;
}

void computeRhoPhi_GPU(int numK, float * phiR_d, float * phiI_d, float * dR_d, float * dI_d, float * realRhoPhi_d, float * imagRhoPhi_d)
{
int rhoPhiBlocks = (numK/512);
dim3 DimRhoPhiBlock;
dim3 DimPhoPhiGrid;
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
/* Automatically inserted by Cetus_Cuda */
cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));
CUDA_ERRCK
cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);
CUDA_ERRCK
/* End of Cetus_Cuda code */

ComputeRhoPhiGPU<<<DimRhoPhiGrid, DimRhoPhiBlock>>> (numK, phiR_d, phiI_d, dR_d, dI_d, realRhoPhi_d, imagRhoPhi_d, gpufi_dev);
/* Automatically inserted by Cetus_Cuda */
cudaMemcpy(&gpufi_host, gpufi_dev, sizeof(struct _gpufi_data_), cudaMemcpyDeviceToHost);
CUDA_ERRCK
cudaFree(gpufi_dev);
CUDA_ERRCK
/* End of Cetus_Cuda code */

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
fprintf(stderr, "CUDA error on line %d: %s\n", 203, cudaGetErrorString(err));
exit(( - 1));
}
}
;
/* Automatically inserted by Cetus_Cuda */
cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));
CUDA_ERRCK
cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);
CUDA_ERRCK
/* End of Cetus_Cuda code */

ComputeFH_GPU<<<DimFHGrid, DimFHBlock>>> (numK, FHGridBase, x_d, y_d, z_d, outR_d, outI_d, gpufi_dev);
/* Automatically inserted by Cetus_Cuda */
cudaMemcpy(&gpufi_host, gpufi_dev, sizeof(struct _gpufi_data_), cudaMemcpyDeviceToHost);
CUDA_ERRCK
cudaFree(gpufi_dev);
CUDA_ERRCK
/* End of Cetus_Cuda code */

{
cudaError_t err;
if (((err=cudaGetLastError())!=cudaSuccess))
{
fprintf(stderr, "CUDA error on line %d: %s\n", 207, cudaGetErrorString(err));
exit(( - 1));
}
}
;
}
}

