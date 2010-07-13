#ifdef _WIN32
#pragma warning(disable:4164 4003)
#endif 
# 1 "main.cudafe1.gpu"
# 100 "src/cuda_ed5/gpufi.h"
struct _gpufi_data_;
# 12 "src/cuda_ed5/computeQ.cu"
struct kValues;
# 214 "/usr/lib/gcc/i486-linux-gnu/4.3.2/include/stddef.h" 3
typedef unsigned size_t;
#include "crt/host_runtime.h"
# 145 "/usr/include/bits/types.h" 3
typedef long __clock_t;
# 61 "/usr/include/time.h" 3
typedef __clock_t clock_t;
# 12 "src/cuda_ed5/computeQ.cu"
struct kValues {
# 14 "src/cuda_ed5/computeQ.cu"
float Kx;
# 15 "src/cuda_ed5/computeQ.cu"
float Ky;
# 16 "src/cuda_ed5/computeQ.cu"
float Kz;
# 17 "src/cuda_ed5/computeQ.cu"
float PhiMag;};
void *memcpy(void*, const void*, size_t); void *memset(void*, int, size_t);
#include "main.cudafe2.stub.h"
# 10 "src/cuda_ed5/gpufi_kernel.cu"
__loc_sc__(__device__,,) struct _gpufi_data_ *__shadow_var(gpufi_dev,gpufi_dev);
# 24 "src/cuda_ed5/computeQ.cu"
__loc_sc__(__constant__,,) struct kValues __shadow_var(ck,ck)[1024];

#include "main.cudafe2.stub.c"
