#ifdef _WIN32
#pragma warning(disable:4164 4003)
#endif 
# 1 "main.cudafe1.gpu"
# 28 "src/cuda_wo_loop/computeFH.cu"
struct kValues;
# 214 "/usr/lib/gcc/i486-linux-gnu/4.3.2/include/stddef.h" 3
typedef unsigned size_t;
#include "crt/host_runtime.h"
# 145 "/usr/include/bits/types.h" 3
typedef long __clock_t;
# 61 "/usr/include/time.h" 3
typedef __clock_t clock_t;
# 28 "src/cuda_wo_loop/computeFH.cu"
struct kValues {
# 29 "src/cuda_wo_loop/computeFH.cu"
float Kx;
# 30 "src/cuda_wo_loop/computeFH.cu"
float Ky;
# 31 "src/cuda_wo_loop/computeFH.cu"
float Kz;
# 32 "src/cuda_wo_loop/computeFH.cu"
float RhoPhiR;
# 33 "src/cuda_wo_loop/computeFH.cu"
float RhoPhiI;};
void *memcpy(void*, const void*, size_t); void *memset(void*, int, size_t);
#include "main.cudafe2.stub.h"
# 36 "src/cuda_wo_loop/computeFH.cu"
__loc_sc__(__constant__,,) struct kValues __shadow_var(c,c)[512];

#include "main.cudafe2.stub.c"
