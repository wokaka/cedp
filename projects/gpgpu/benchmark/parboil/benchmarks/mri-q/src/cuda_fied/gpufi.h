#ifndef __GPU_FI_H__
#define __GPU_FI_H__

#define GPUFI   1

#define MAX_VARIABLE_NAME 256

struct _gpufi_fault_ {
    int kernel;         // invocation index
                        // if it is 0, it means 'ready to inject'
    int instance;
    int varid;
    int call;

    int mask_type;
#define MASK_XOR    0    
//    int mask_length;    // 4 Bytes
    unsigned int mask;  
    int injected;
    int disabled;
    int mode;
};

//__device__ extern int gpufi_mode;

#define GPUFI_PROFILE 1
#define GPUFI_FI 0

#define MAX_KERNEL	32
#define MAX_VARIABLE	1024
#define MAX_NAME    	32

#define MAX_INSTANCE	10
#define MAX_LOOP	10
#define MAX_ITERATION	1000

struct _gpufi_profile_kernel_ {
    char state;
    int id;
    int instance;
    char name[MAX_NAME];
};

struct _gpufi_profile_variable_ {
    int call_count;
    int loop_id;
    char name[MAX_NAME];
};

struct _gpufi_profile_ {
    /* profiled data */
    struct _gpufi_profile_kernel_ kernel[MAX_KERNEL];
    struct _gpufi_profile_variable_ variable[MAX_KERNEL][MAX_VARIABLE];

    /* in order to maintain current */
    char kernel_bitmap[MAX_KERNEL];
    int kernel_instance[MAX_KERNEL];
};

int gpufi_profile_variable_count = 0;
int gpufi_profile_kernel_count = 0;

struct _gpufi_current_ {
    int mode;
    int kernel;
    int instance;
    int loop;
    int loop_count;
    int iteration;

    int profile_index;

    int blid;
    int thid;
};

//__device__ extern struct _gpufi_current_ gpufi_current;
struct _gpufi_data_ {
  struct _gpufi_fault_ fault;
#if DEBUG_INJECT_LOC
  struct _gpufi_fault_ injected;
#endif
  struct _gpufi_fault_ debug;
  struct _gpufi_current_ current;
  struct _gpufi_profile_ profile;
};

__device__ void GPUFI_KERNEL_DEC(struct _gpufi_data_ *, int *count);
__device__ void GPUFI_KERNEL_SET(struct _gpufi_data_ *, int *count, int value);
__device__ void GPUFI_KERNEL(struct _gpufi_data_ *, int begin, int type, char *);
__device__ void GPUFI_KERNEL_LOOP(struct _gpufi_data_ *, int);
__device__ void GPUFI_KERNEL_ITERATION(struct _gpufi_data_ *);
__device__ void GPUFI_KERNEL_VARIABLE(struct _gpufi_data_ *, int varid, char *name, int *variable);
__device__ void GPUFI_KERNEL_VARIABLE_STREAM(struct _gpufi_data_ *gpufi_dev, int varid, char *name, int *variable, int length, int count);
__device__ void GPUFI_DEBUG_LOC(struct _gpufi_data_ *gpufi_dev);
__device__ int GPUFI_EXIT(int errno);
int GPUFI_INIT(struct _gpufi_data_ *gpufi_dev, int, int);
int GPUFI_HALT(char *fname);
__device__ void CudaStrcpy(char *dst, char *src);

extern struct _gpufi_data_ gpufi_host;

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

