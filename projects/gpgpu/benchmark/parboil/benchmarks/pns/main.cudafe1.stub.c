#if defined(__cplusplus)
extern "C" {
#endif
#include "main.fatbin.c"
#include "crt/host_runtime.h"
#if defined(__device_emulation) && defined(__cplusplus)
namespace __cuda_emu {struct __T20 {int *__par0;float *__par1;int *__par2;int __par3;int __par4;int __par5;struct _gpufi_data_ *__par6;int __dummy_field;};
}
#endif
struct __T20 {int *__par0;float *__par1;int *__par2;int __par3;int __par4;int __par5;struct _gpufi_data_ *__par6;int __dummy_field;};
static void __sti____cudaRegisterAll_12_main_cpp1_ii_46b07679(void) __attribute__((__constructor__));
void __device_stub__Z14PetrinetKernelPiPfS_iiiP12_gpufi_data_(int *__par0, float *__par1, int *__par2, int __par3, int __par4, int __par5, struct _gpufi_data_ *__par6){auto struct __T20 *__T24;
__cudaInitArgBlock(__T24);__cudaSetupArg(__par0, __T24);__cudaSetupArg(__par1, __T24);__cudaSetupArg(__par2, __T24);__cudaSetupArg(__par3, __T24);__cudaSetupArg(__par4, __T24);__cudaSetupArg(__par5, __T24);__cudaSetupArg(__par6, __T24);__cudaLaunch(((char *)__device_stub_name(__device_stub__Z14PetrinetKernelPiPfS_iiiP12_gpufi_data_,((void ( *)(int *, float *, int *, int, int, int, struct _gpufi_data_ *))PetrinetKernel__entry))));}
#if defined(__cplusplus)
}
void PetrinetKernel__entry( int *__cuda_0,float *__cuda_1,int *__cuda_2,int __cuda_3,int __cuda_4,int __cuda_5,struct _gpufi_data_ *__cuda_6)
{__device_stub__Z14PetrinetKernelPiPfS_iiiP12_gpufi_data_( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6);}
extern "C"{
#endif
#if defined(__device_emulation)
#if defined(__cplusplus)
namespace __cuda_emu {
#endif
static void __device_wrapper__Z14PetrinetKernelPiPfS_iiiP12_gpufi_data_(char *__T214){_Z14PetrinetKernelPiPfS_iiiP12_gpufi_data_((((*((struct __T20 *)__T214)).__par0)), (((*((struct __T20 *)__T214)).__par1)), (((*((struct __T20 *)__T214)).__par2)), (((*((struct __T20 *)__T214)).__par3)), (((*((struct __T20 *)__T214)).__par4)), (((*((struct __T20 *)__T214)).__par5)), (((*((struct __T20 *)__T214)).__par6)));}
#if defined(__cplusplus)
}
#endif
#endif
static void __sti____cudaRegisterAll_12_main_cpp1_ii_46b07679(void){__cudaRegisterBinary();__cudaRegisterEntry(__device_stub_name(__device_stub__Z14PetrinetKernelPiPfS_iiiP12_gpufi_data_,((void ( *)(int *, float *, int *, int, int, int, struct _gpufi_data_ *))PetrinetKernel__entry)), _Z14PetrinetKernelPiPfS_iiiP12_gpufi_data_, (-1));__cudaRegisterVariable(__shadow_var(gpufi_dev,gpufi_dev), 0, 4, 0, 0);__cudaRegisterSharedVariable(mt, 2496, 4, 0);}
#if defined(__cplusplus)
}
#endif
