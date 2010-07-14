#ifndef __GPU_FI_H__
#define __GPU_FI_H__

#define GPUFI_CHECK(gpufi,n1,n2) { if(n1 != n2) GPUFI_EXIT(gpufi,0);}

struct _gpufi_fault_ {
    int kernel;     
    int instance;
    int varid;
    int call;

    unsigned int mask;  
//    int mask_type;
//#define MASK_XOR    0    
//    int mask_length;    // 4 Bytes

    int injected;
    int disabled;

    int blid;
    int thid;
};

struct _gpufi_current_ {
    int instance;
    int count;
};

struct _gpufi_data_ {
  struct _gpufi_fault_ fault;
  struct _gpufi_current_ current;
  int sdc;
};

#define GPUFI_DATATYPE_UNKNOWN 0
#define GPUFI_DATATYPE_INTEGER 10
#define GPUFI_DATATYPE_FLOAT 20
#define GPUFI_DATATYPE_INTEGER_POINTER 30
#define GPUFI_DATATYPE_FLOAT_POINTER 40
#define GPUFI_DATATYPE_UNKNOWN_POINTER 50

__device__ void GPUFI_KERNEL_DEC(struct _gpufi_data_ *, int *count);
__device__ void GPUFI_KERNEL_SET(struct _gpufi_data_ *, int *count, int value);
__device__ void GPUFI_KERNEL(struct _gpufi_data_ *, int begin, int type, char *);
__device__ void GPUFI_KERNEL_LOOP(struct _gpufi_data_ *, int);
__device__ void GPUFI_KERNEL_ITERATION(struct _gpufi_data_ *);
__device__ void GPUFI_KERNEL_VARIABLE(struct _gpufi_data_ *, int varid, char *name, int *variable, int var_type);
__device__ void GPUFI_KERNEL_VARIABLE_STREAM(struct _gpufi_data_ *gpufi_dev, int varid, char *name, int *variable, int length, int count);
__device__ void GPUFI_DEBUG_LOC(struct _gpufi_data_ *gpufi_dev);
__device__ int GPUFI_EXIT(struct _gpufi_data_ *gpufi_dev, int errno);
int GPUFI_INIT(int, int);
int GPUFI_HALT(char *fname);
__device__ void CudaStrcpy(char *dst, char *src, int max);

extern struct _gpufi_data_ gpufi_host;

#define GPUFI_KERNEL_BEGIN 0
#define GPUFI_KERNEL_END 1
#define GPUFI_LOOP_BEGIN 0
#define GPUFI_LOOP_END 1

//extern __device__ struct _gpufi_data_ *gpufi_dev;

#ifndef CUDA_ERRCK
#define CUDA_ERRCK							\
  {cudaError_t err;							\
    if ((err = cudaGetLastError()) != cudaSuccess) {			\
      fprintf(stderr, "CUDA error on line %d: %s\n", __LINE__, cudaGetErrorString(err)); \
      exit(-1);								\
    }									\
  }
#endif

#include "gpufi_kernel.cu"

#endif
