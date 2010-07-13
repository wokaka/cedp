#ifdef _WIN32
#pragma warning(disable:4164 4003)
#endif 
# 1 "sad4.cudafe1.gpu"
# 37 "src/cuda/sad4.h"
struct vec8b;
# 214 "/usr/lib/gcc/i486-linux-gnu/4.3.2/include/stddef.h" 3
typedef unsigned size_t;
#include "crt/host_runtime.h"
# 145 "/usr/include/bits/types.h" 3
typedef long __clock_t;
# 61 "/usr/include/time.h" 3
typedef __clock_t clock_t;
# 37 "src/cuda/sad4.h"
struct vec8b {
# 38 "src/cuda/sad4.h"
int fst;
# 39 "src/cuda/sad4.h"
int snd;} __attribute__((__aligned__(8)));
# 42 "src/cuda/sad4.h"
typedef struct vec8b vec8b;
void *memcpy(void*, const void*, size_t); void *memset(void*, int, size_t);
# 43 "src/cuda/sad4.cu"
__loc_sc__(__text__,,) __texture_type__ __text_var(ref,ref);
#include "sad4.cudafe2.stub.h"

#include "sad4.cudafe2.stub.c"
