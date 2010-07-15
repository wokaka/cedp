#if defined(__cplusplus)
extern "C" {
#endif
#include "main.fatbin.c"
#include "crt/host_runtime.h"
#if defined(__device_emulation) && defined(__cplusplus)
namespace __cuda_emu {struct __T20 {hist_t *__par0;float *__par1;float *__par2;float *__par3;int __par4;int __par5;int __dummy_field;};
}
#endif
struct __T20 {hist_t *__par0;float *__par1;float *__par2;float *__par3;int __par4;int __par5;int __dummy_field;};
static void __sti____cudaRegisterAll_12_main_cpp1_ii_839760fd(void) __attribute__((__constructor__));
void __device_stub__Z9gen_histsPmPfS0_S0_ii(hist_t *__par0, float *__par1, float *__par2, float *__par3, int __par4, int __par5){auto struct __T20 *__T23;
__cudaInitArgBlock(__T23);__cudaSetupArg(__par0, __T23);__cudaSetupArg(__par1, __T23);__cudaSetupArg(__par2, __T23);__cudaSetupArg(__par3, __T23);__cudaSetupArg(__par4, __T23);__cudaSetupArg(__par5, __T23);__cudaLaunch(((char *)__device_stub_name(__device_stub__Z9gen_histsPmPfS0_S0_ii,((void ( *)(hist_t *, float *, float *, float *, int, int))gen_hists__entry))));}
#if defined(__cplusplus)
}
void gen_hists__entry( hist_t *__cuda_0,float *__cuda_1,float *__cuda_2,float *__cuda_3,int __cuda_4,int __cuda_5)
{__device_stub__Z9gen_histsPmPfS0_S0_ii( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5);}
extern "C"{
#endif
#if defined(__device_emulation)
#if defined(__cplusplus)
namespace __cuda_emu {
#endif
static void __device_wrapper__Z9gen_histsPmPfS0_S0_ii(char *__T25){_Z9gen_histsPmPfS0_S0_ii((((*((struct __T20 *)__T25)).__par0)), (((*((struct __T20 *)__T25)).__par1)), (((*((struct __T20 *)__T25)).__par2)), (((*((struct __T20 *)__T25)).__par3)), (((*((struct __T20 *)__T25)).__par4)), (((*((struct __T20 *)__T25)).__par5)));}
#if defined(__cplusplus)
}
#endif
#endif
static void __sti____cudaRegisterAll_12_main_cpp1_ii_839760fd(void){__cudaRegisterBinary();__cudaRegisterEntry(__device_stub_name(__device_stub__Z9gen_histsPmPfS0_S0_ii,((void ( *)(hist_t *, float *, float *, float *, int, int))gen_hists__entry)), _Z9gen_histsPmPfS0_S0_ii, (-1));__cudaRegisterVariable(__shadow_var(dev_binb,dev_binb), 0, 84, 1, 0);}
#if defined(__cplusplus)
}
#endif
