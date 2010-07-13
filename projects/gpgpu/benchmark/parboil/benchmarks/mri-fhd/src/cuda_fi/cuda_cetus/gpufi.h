#undef NULL
typedef int dim3;
typedef struct kValues kValues;
typedef struct cudaError_t cudaError_t;

#if _POSIX_VERSION < 200112L
#undef _POSIX_VERSION
#define _POSIX_VERSION 200112L
#endif

