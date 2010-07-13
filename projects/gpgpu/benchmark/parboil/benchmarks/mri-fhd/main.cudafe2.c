#ifdef _WIN32
#pragma warning(disable:4164 4003)
#endif 
# 1 "main.cudafe1.gpu"
# 14 "src/cuda_fi/gpufi.h"
struct _gpufi_fault_;
# 46 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_kernel_;
# 54 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_variable_;
# 60 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_;
# 76 "src/cuda_fi/gpufi.h"
struct _gpufi_current_;
# 98 "src/cuda_fi/gpufi.h"
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
# 14 "src/cuda_fi/gpufi.h"
struct _gpufi_fault_ {
# 15 "src/cuda_fi/gpufi.h"
int kernel;
# 17 "src/cuda_fi/gpufi.h"
int instance;
# 18 "src/cuda_fi/gpufi.h"
int varid;
# 19 "src/cuda_fi/gpufi.h"
int call;
# 21 "src/cuda_fi/gpufi.h"
int mask_type;
# 24 "src/cuda_fi/gpufi.h"
unsigned mask;
# 25 "src/cuda_fi/gpufi.h"
int injected;
# 26 "src/cuda_fi/gpufi.h"
int disabled;
# 27 "src/cuda_fi/gpufi.h"
int mode;};
# 46 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_kernel_ {
# 47 "src/cuda_fi/gpufi.h"
char state;
# 48 "src/cuda_fi/gpufi.h"
int id;
# 49 "src/cuda_fi/gpufi.h"
int instance;
# 50 "src/cuda_fi/gpufi.h"
char name[32];};
# 54 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_variable_ {
# 55 "src/cuda_fi/gpufi.h"
int call_count;
# 56 "src/cuda_fi/gpufi.h"
int loop_id;
# 57 "src/cuda_fi/gpufi.h"
int type;};
# 60 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_ {
# 62 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_kernel_ kernel[10];
# 63 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_variable_ variable[10][128];
# 66 "src/cuda_fi/gpufi.h"
char kernel_bitmap[10];
# 67 "src/cuda_fi/gpufi.h"
int kernel_instance[10];
# 69 "src/cuda_fi/gpufi.h"
char variable_bitmap[128];
# 70 "src/cuda_fi/gpufi.h"
char variable_name[128][32];};
# 76 "src/cuda_fi/gpufi.h"
struct _gpufi_current_ {
# 77 "src/cuda_fi/gpufi.h"
int mode;
# 78 "src/cuda_fi/gpufi.h"
int kernel;
# 79 "src/cuda_fi/gpufi.h"
int instance;
# 80 "src/cuda_fi/gpufi.h"
int loop;
# 81 "src/cuda_fi/gpufi.h"
int loop_count;
# 82 "src/cuda_fi/gpufi.h"
int iteration;
# 84 "src/cuda_fi/gpufi.h"
int profile_index;
# 85 "src/cuda_fi/gpufi.h"
int profile_mode;
# 93 "src/cuda_fi/gpufi.h"
int blid;
# 94 "src/cuda_fi/gpufi.h"
int thid;};
# 98 "src/cuda_fi/gpufi.h"
struct _gpufi_data_ {
# 99 "src/cuda_fi/gpufi.h"
struct _gpufi_fault_ fault;
# 103 "src/cuda_fi/gpufi.h"
struct _gpufi_fault_ debug;
# 104 "src/cuda_fi/gpufi.h"
struct _gpufi_current_ current;
# 105 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_ profile;
# 106 "src/cuda_fi/gpufi.h"
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
