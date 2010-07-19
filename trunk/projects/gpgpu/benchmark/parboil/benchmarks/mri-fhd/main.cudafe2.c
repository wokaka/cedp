#ifdef _WIN32
#pragma warning(disable:4164 4003)
#endif 
# 1 "main.cudafe1.gpu"
# 6 "src/cuda_fi/gpufi.h"
struct _gpufi_fault_;
# 24 "src/cuda_fi/gpufi.h"
struct _gpufi_current_;
# 29 "src/cuda_fi/gpufi.h"
struct _gpufi_data_;
# 22 "src/cuda_fi/computeFH.cu"
struct kValues;
# 214 "/usr/lib/gcc/i486-linux-gnu/4.3.2/include/stddef.h" 3
typedef unsigned size_t;
#include "crt/host_runtime.h"
# 145 "/usr/include/bits/types.h" 3
typedef long __clock_t;
# 61 "/usr/include/time.h" 3
typedef __clock_t clock_t;
# 6 "src/cuda_fi/gpufi.h"
struct _gpufi_fault_ {
# 7 "src/cuda_fi/gpufi.h"
int kernel;
# 8 "src/cuda_fi/gpufi.h"
int instance;
# 9 "src/cuda_fi/gpufi.h"
int varid;
# 10 "src/cuda_fi/gpufi.h"
int call;
# 12 "src/cuda_fi/gpufi.h"
unsigned mask;
# 17 "src/cuda_fi/gpufi.h"
int injected;
# 18 "src/cuda_fi/gpufi.h"
int disabled;
# 20 "src/cuda_fi/gpufi.h"
int blid;
# 21 "src/cuda_fi/gpufi.h"
int thid;};
# 24 "src/cuda_fi/gpufi.h"
struct _gpufi_current_ {
# 25 "src/cuda_fi/gpufi.h"
int instance;
# 26 "src/cuda_fi/gpufi.h"
int count;};
# 29 "src/cuda_fi/gpufi.h"
struct _gpufi_data_ {
# 30 "src/cuda_fi/gpufi.h"
struct _gpufi_fault_ fault;
# 31 "src/cuda_fi/gpufi.h"
struct _gpufi_current_ current;
# 32 "src/cuda_fi/gpufi.h"
int sdc;};
# 22 "src/cuda_fi/computeFH.cu"
struct kValues {
# 24 "src/cuda_fi/computeFH.cu"
float Kx;
# 25 "src/cuda_fi/computeFH.cu"
float Ky;
# 26 "src/cuda_fi/computeFH.cu"
float Kz;
# 27 "src/cuda_fi/computeFH.cu"
float RhoPhiR;
# 28 "src/cuda_fi/computeFH.cu"
float RhoPhiI;};
void *memcpy(void*, const void*, size_t); void *memset(void*, int, size_t);
#include "main.cudafe2.stub.h"
# 10 "src/cuda_fi/gpufi_kernel.cu"
__loc_sc__(__device__,,) struct _gpufi_data_ *__shadow_var(gpufi_dev,gpufi_dev);
# 31 "src/cuda_fi/computeFH.cu"
__loc_sc__(__constant__,,) struct kValues __shadow_var(c,c)[512];

#include "main.cudafe2.stub.c"
