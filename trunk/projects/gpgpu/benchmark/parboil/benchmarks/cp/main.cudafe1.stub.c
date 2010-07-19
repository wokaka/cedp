#if defined(__cplusplus)
extern "C" {
#endif
#include "main.fatbin.c"
#include "crt/host_runtime.h"
#if defined(__device_emulation) && defined(__cplusplus)
namespace __cuda_emu {struct __T20 {int __par0;float __par1;float *__par2;struct _gpufi_data_ *__par3;int __dummy_field;};
}
#endif
struct __T20 {int __par0;float __par1;float *__par2;struct _gpufi_data_ *__par3;int __dummy_field;};
static void __sti____cudaRegisterAll_12_main_cpp1_ii_571f98e8(void) __attribute__((__constructor__));
void __device_stub__Z7cenergyifPfP12_gpufi_data_(int __par0, float __par1, float *__par2, struct _gpufi_data_ *__par3){auto struct __T20 *__T23;
__cudaInitArgBlock(__T23);__cudaSetupArg(__par0, __T23);__cudaSetupArg(__par1, __T23);__cudaSetupArg(__par2, __T23);__cudaSetupArg(__par3, __T23);__cudaLaunch(((char *)__device_stub_name(__device_stub__Z7cenergyifPfP12_gpufi_data_,((void ( *)(int, float, float *, struct _gpufi_data_ *))cenergy__entry))));}
#if defined(__cplusplus)
}
void cenergy__entry( int __cuda_0,float __cuda_1,float *__cuda_2,struct _gpufi_data_ *__cuda_3)
{__device_stub__Z7cenergyifPfP12_gpufi_data_( __cuda_0,__cuda_1,__cuda_2,__cuda_3);}
extern "C"{
#endif
#if defined(__device_emulation)
#if defined(__cplusplus)
namespace __cuda_emu {
#endif
static void __device_wrapper__Z7cenergyifPfP12_gpufi_data_(char *__T24){_Z7cenergyifPfP12_gpufi_data_((((*((struct __T20 *)__T24)).__par0)), (((*((struct __T20 *)__T24)).__par1)), (((*((struct __T20 *)__T24)).__par2)), (((*((struct __T20 *)__T24)).__par3)));}
#if defined(__cplusplus)
}
#endif
#endif
static void __sti____cudaRegisterAll_12_main_cpp1_ii_571f98e8(void){__cudaRegisterBinary();__cudaRegisterEntry(__device_stub_name(__device_stub__Z7cenergyifPfP12_gpufi_data_,((void ( *)(int, float, float *, struct _gpufi_data_ *))cenergy__entry)), _Z7cenergyifPfP12_gpufi_data_, (-1));__cudaRegisterVariable(__shadow_var(gpufi_dev,gpufi_dev), 0, 4, 0, 0);__cudaRegisterVariable(__shadow_var(atominfo,atominfo), 0, 64000, 1, 0);}
#if defined(__cplusplus)
}
#endif
