/* Automatically inserted by Cetus_Cuda */
#include "gpufi.h"
/* End of Cetus_Cuda code */

/*
**************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 **************************************************************************
*/
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <math.h> 
#include "parboil.h" 
#include "rand_gen.cu" 
#include "petri_kernel.cu" 
#include "gpufi.h" 
static int N, s, t, N2, NSQUARE2;
uint32 host_mt[624];
void * AllocateDeviceMemory(int size);
void CopyFromDeviceMemory(void * h_p, void * d_p, int size);
void CopyFromHostMemory(void * d_p, void * h_p, int size);
void FreeDeviceMemory(void * mem);
void PetrinetOnDevice(struct pb_TimerSet * timers, struct pb_Parameters * params);
void compute_statistics(  );
float results[4];
float * h_vars;
int * h_maxs;
int main(int argc, char *  * argv)
{
struct pb_TimerSet timers;
struct pb_Parameters * params;
/*
Automatically inserted by Cetus_Cuda
*/
GPUFI_FETCH_COMMAND();
/*
End of Cetus_Cuda code
*/
pb_InitializeTimerSet(( & timers));
params=pb_ReadParameters(( & argc), argv);
if ((argc<4))
{
printf("Usage: petri n s t\n""n: the place-transition grid is 2nX2n\n""s: the maximum steps in a trajectory\n""t: number of trajectories\n");
/*
Automatically inserted by Cetus_Cuda
*/
GPUFI_END("fi_profile.txt");
/*
End of Cetus_Cuda code
*/
return ( - 1);
}
pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
N=atoi(argv[1]);
if ((N<1))
{
/*
Automatically inserted by Cetus_Cuda
*/
GPUFI_END("fi_profile.txt");
/*
End of Cetus_Cuda code
*/
return ( - 1);
}
s=atoi(argv[2]);
if ((s<1))
{
/*
Automatically inserted by Cetus_Cuda
*/
GPUFI_END("fi_profile.txt");
/*
End of Cetus_Cuda code
*/
return ( - 1);
}
t=atoi(argv[3]);
if ((t<1))
{
/*
Automatically inserted by Cetus_Cuda
*/
GPUFI_END("fi_profile.txt");
/*
End of Cetus_Cuda code
*/
return ( - 1);
}
N2=(N+N);
NSQUARE2=(N*N2);
h_vars=((float * )malloc((t*sizeof (float))));
h_maxs=((int * )malloc((t*sizeof (int))));
/* compute the simulation on the GPU */
PetrinetOnDevice(( & timers), params);
pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
compute_statistics();
free(h_vars);
free(h_maxs);
pb_SwitchToTimer(( & timers), pb_TimerID_IO);
printf("petri N=%d s=%d t=%d\n", N, s, t);
printf("mean_vars: %f    var_vars: %f\n", results[0], results[1]);
printf("mean_maxs: %f    var_maxs: %f\n", results[2], results[3]);
if (params->outFile)
{
FILE * out;
out=fopen(params->outFile, "w");
fprintf(out, "%f %f %f %f\n", results[0], results[1], results[2], results[3]);
fclose(out);
}
pb_SwitchToTimer(( & timers), pb_TimerID_NONE);
pb_PrintTimerSet(( & timers));
pb_FreeParameters(params);
/*
Automatically inserted by Cetus_Cuda
*/
GPUFI_END("fi_profile.txt");
/*
End of Cetus_Cuda code
*/
return 0;
}

void compute_statistics(  )
{
float sum = 0;
float sum_vars = 0;
float sum_max = 0;
float sum_max_vars = 0;
int i;
for (i=0; i<t; i ++ )
{
sum+=h_vars[i];
sum_vars+=(h_vars[i]*h_vars[i]);
sum_max+=h_maxs[i];
sum_max_vars+=(h_maxs[i]*h_maxs[i]);
}
results[0]=(sum/t);
results[1]=((sum_vars/t)-(results[0]*results[0]));
results[2]=(sum_max/t);
results[3]=((sum_max_vars/t)-(results[2]*results[2]));
}

void PetrinetOnDevice(struct pb_TimerSet * timers, struct pb_Parameters * params)
{
/* Allocate memory */
int i;
int unit_size = (((NSQUARE2*(sizeof (int)+sizeof (char)))+sizeof (float))+sizeof (int));
int block_num = (750000000/unit_size);
int * p_hmaxs;
float * p_hvars;
int * g_places;
float * g_vars;
int * g_maxs;
dim3 grid;
dim3 threads;
dim3 grid1;
pb_SwitchToTimer(timers, pb_TimerID_COPY);
g_places=((int * )AllocateDeviceMemory((((unit_size-sizeof (float))-sizeof (int))*block_num)));
{
cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
g_vars=((float * )AllocateDeviceMemory((block_num*sizeof (float))));
{
cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
g_maxs=((int * )AllocateDeviceMemory((block_num*sizeof (int))));
{
cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
/* Setup the execution configuration */
grid.x=block_num;
/* number of blocks */
grid.y=1;
grid.z=1;
grid.x=256;
/* each block has 256 threads */
grid.y=1;
grid.z=1;
p_hmaxs=h_maxs;
p_hvars=h_vars;
/* Launch the device computation threads! */
for (i=0; i<(t-block_num); i+=block_num)
{
if (params->synchronizeGpu)
{
cudaThreadSynchronize();
}
pb_SwitchToTimer(timers, pb_TimerID_GPU);
/* Automatically inserted by Cetus_Cuda */
cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));
CUDA_ERRCK
cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);
CUDA_ERRCK
/* End of Cetus_Cuda code */

PetrinetKernel<<<grid, threads>>> (g_places, g_vars, g_maxs, N, s, (5489*(i+1)), gpufi_dev);
/* Automatically inserted by Cetus_Cuda */
cudaMemcpy(&gpufi_host, gpufi_dev, sizeof(struct _gpufi_data_), cudaMemcpyDeviceToHost);
CUDA_ERRCK
cudaFree(gpufi_dev);
CUDA_ERRCK
/* End of Cetus_Cuda code */

{
cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
if (params->synchronizeGpu)
{
cudaThreadSynchronize();
}
pb_SwitchToTimer(timers, pb_TimerID_COPY);
CopyFromDeviceMemory(p_hmaxs, g_maxs, (block_num*sizeof (int)));
{
cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
CopyFromDeviceMemory(p_hvars, g_vars, (block_num*sizeof (float)));
{
cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
if (params->synchronizeGpu)
{
cudaThreadSynchronize();
}
pb_SwitchToTimer(timers, pb_TimerID_COMPUTE);
p_hmaxs+=block_num;
p_hvars+=block_num;
}
grid1.x=(t-i);
grid1.y=1;
grid1.z=1;
pb_SwitchToTimer(timers, pb_TimerID_GPU);
/* Automatically inserted by Cetus_Cuda */
cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));
CUDA_ERRCK
cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);
CUDA_ERRCK
/* End of Cetus_Cuda code */

PetrinetKernel<<<grid1, threads>>> (g_places, g_vars, g_maxs, N, s, time(NULL), gpufi_dev);
/* Automatically inserted by Cetus_Cuda */
cudaMemcpy(&gpufi_host, gpufi_dev, sizeof(struct _gpufi_data_), cudaMemcpyDeviceToHost);
CUDA_ERRCK
cudaFree(gpufi_dev);
CUDA_ERRCK
/* End of Cetus_Cuda code */

{
cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
/* Read result from the device */
if (params->synchronizeGpu)
{
cudaThreadSynchronize();
}
pb_SwitchToTimer(timers, pb_TimerID_COPY);
CopyFromDeviceMemory(p_hmaxs, g_maxs, ((t-i)*sizeof (int)));
{
cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
CopyFromDeviceMemory(p_hvars, g_vars, ((t-i)*sizeof (float)));
{
cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
/* Free device matrices */
FreeDeviceMemory(g_places);
{
cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
FreeDeviceMemory(g_vars);
{
cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
FreeDeviceMemory(g_maxs);
{
cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
}

/* Allocate a device matrix of same size as M. */
void * AllocateDeviceMemory(int size)
{
int * mem;
cudaMalloc(((void *  * )( & mem)), size);
return mem;
}

/* Copy device memory to host memory */
void CopyFromDeviceMemory(void * h_p, void * d_p, int size)
{
cudaMemcpy(h_p, d_p, size, cudaMemcpyDeviceToHost);
}

/* Copy device memory from host memory */
void CopyFromHostMemory(void * d_p, void * h_p, int size)
{
cudaMemcpy(d_p, h_p, size, cudaMemcpyHostToDevice);
}

/* Free a device matrix. */
void FreeDeviceMemory(void * mem)
{
if ((mem!=NULL))
{
cudaFree(mem);
}
}

