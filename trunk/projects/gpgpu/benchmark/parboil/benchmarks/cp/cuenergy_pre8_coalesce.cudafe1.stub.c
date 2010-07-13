#include "cuenergy_pre8_coalesce.fatbin.c"
#include "crt/host_runtime.h"
struct __T20 {int __par0;float __par1;float *__par2;int __dummy_field;__pad__(volatile char __dummy[4];)};
extern void __device_stub__Z7cenergyifPf(int, float, float *);
static void __sti____cudaRegisterAll_30_cuenergy_pre8_coalesce_cpp1_ii_8fc8a9e8(void) __attribute__((__constructor__));
void __device_stub__Z7cenergyifPf(int __par0, float __par1, float *__par2){ struct __T20 *__T21;
__cudaInitArgBlock(__T21);__cudaSetupArg(__par0, __T21);__cudaSetupArg(__par1, __T21);__cudaSetupArg(__par2, __T21);__cudaLaunch(((char *)((void ( *)(int, float, float *))cenergy)));}
void cenergy( int __cuda_0,float __cuda_1,float *__cuda_2)
# 30 "src/cuda/cuenergy_pre8_coalesce.cu"
{__device_stub__Z7cenergyifPf( __cuda_0,__cuda_1,__cuda_2);
# 83 "src/cuda/cuenergy_pre8_coalesce.cu"
}
# 1 "cuenergy_pre8_coalesce.cudafe1.stub.c"
static void __sti____cudaRegisterAll_30_cuenergy_pre8_coalesce_cpp1_ii_8fc8a9e8(void) {  __cudaRegisterBinary(); __cudaRegisterEntry(((void ( *)(int, float, float *))cenergy), _Z7cenergyifPf, (-1)); __cudaRegisterVariable(__shadow_var(atominfo,atominfo), 0, 64000, 1, 0);  }
