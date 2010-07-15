#ifdef _WIN32
#pragma warning(disable:4164 4003)
#endif 
# 1 "main.cudafe1.gpu"
# 214 "/usr/lib/gcc/i486-linux-gnu/4.3.2/include/stddef.h" 3
typedef unsigned size_t;
#include "crt/host_runtime.h"
# 145 "/usr/include/bits/types.h" 3
typedef long __clock_t;
# 61 "/usr/include/time.h" 3
typedef __clock_t clock_t;
# 23 "src/cuda/model.h"
typedef unsigned long hist_t;
void *memcpy(void*, const void*, size_t); void *memset(void*, int, size_t);
#include "main.cudafe2.stub.h"
# 29 "src/cuda/scan_largearray_kernel.cu"
__loc_sc__(__constant__,,) float __shadow_var(dev_binb,dev_binb)[21];

#include "main.cudafe2.stub.c"
