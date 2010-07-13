#if defined(__cplusplus)
extern "C" {
#endif
#include "main.fatbin.c"
#include "crt/host_runtime.h"
#if defined(__device_emulation) && defined(__cplusplus)
namespace __cuda_emu {struct __T20 {int __par0;float *__par1;float *__par2;float *__par3;float *__par4;float *__par5;float *__par6;struct _gpufi_data_ *__par7;int __dummy_field;};
}
#endif
struct __T20 {int __par0;float *__par1;float *__par2;float *__par3;float *__par4;float *__par5;float *__par6;struct _gpufi_data_ *__par7;int __dummy_field;};
#if defined(__device_emulation) && defined(__cplusplus)
namespace __cuda_emu {struct __T21 {int __par0;int __par1;float *__par2;float *__par3;float *__par4;float *__par5;float *__par6;struct _gpufi_data_ *__par7;int __dummy_field;};
}
#endif
struct __T21 {int __par0;int __par1;float *__par2;float *__par3;float *__par4;float *__par5;float *__par6;struct _gpufi_data_ *__par7;int __dummy_field;};
static void __sti____cudaRegisterAll_12_main_cpp1_ii_46b07679(void) __attribute__((__constructor__));
void __device_stub__Z16ComputeRhoPhiGPUiPfS_S_S_S_S_P12_gpufi_data_(int __par0, float *__par1, float *__par2, float *__par3, float *__par4, float *__par5, float *__par6, struct _gpufi_data_ *__par7){auto struct __T20 *__T25;
__cudaInitArgBlock(__T25);__cudaSetupArg(__par0, __T25);__cudaSetupArg(__par1, __T25);__cudaSetupArg(__par2, __T25);__cudaSetupArg(__par3, __T25);__cudaSetupArg(__par4, __T25);__cudaSetupArg(__par5, __T25);__cudaSetupArg(__par6, __T25);__cudaSetupArg(__par7, __T25);__cudaLaunch(((char *)__device_stub_name(__device_stub__Z16ComputeRhoPhiGPUiPfS_S_S_S_S_P12_gpufi_data_,((void ( *)(int, float *, float *, float *, float *, float *, float *, struct _gpufi_data_ *))ComputeRhoPhiGPU__entry))));}
#if defined(__cplusplus)
}
void ComputeRhoPhiGPU__entry( int __cuda_0,float *__cuda_1,float *__cuda_2,float *__cuda_3,float *__cuda_4,float *__cuda_5,float *__cuda_6,struct _gpufi_data_ *__cuda_7)
{__device_stub__Z16ComputeRhoPhiGPUiPfS_S_S_S_S_P12_gpufi_data_( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7);}
extern "C"{
#endif
void __device_stub__Z13ComputeFH_GPUiiPfS_S_S_S_P12_gpufi_data_(int __par0, int __par1, float *__par2, float *__par3, float *__par4, float *__par5, float *__par6, struct _gpufi_data_ *__par7){auto struct __T21 *__T26;
__cudaInitArgBlock(__T26);__cudaSetupArg(__par0, __T26);__cudaSetupArg(__par1, __T26);__cudaSetupArg(__par2, __T26);__cudaSetupArg(__par3, __T26);__cudaSetupArg(__par4, __T26);__cudaSetupArg(__par5, __T26);__cudaSetupArg(__par6, __T26);__cudaSetupArg(__par7, __T26);__cudaLaunch(((char *)__device_stub_name(__device_stub__Z13ComputeFH_GPUiiPfS_S_S_S_P12_gpufi_data_,((void ( *)(int, int, float *, float *, float *, float *, float *, struct _gpufi_data_ *))ComputeFH_GPU__entry))));}
#if defined(__cplusplus)
}
void ComputeFH_GPU__entry( int __cuda_0,int __cuda_1,float *__cuda_2,float *__cuda_3,float *__cuda_4,float *__cuda_5,float *__cuda_6,struct _gpufi_data_ *__cuda_7)
{__device_stub__Z13ComputeFH_GPUiiPfS_S_S_S_P12_gpufi_data_( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6,__cuda_7);}
extern "C"{
#endif
#if defined(__device_emulation)
#if defined(__cplusplus)
namespace __cuda_emu {
#endif
static void __device_wrapper__Z16ComputeRhoPhiGPUiPfS_S_S_S_S_P12_gpufi_data_(char *__T27){_Z16ComputeRhoPhiGPUiPfS_S_S_S_S_P12_gpufi_data_((((*((struct __T20 *)__T27)).__par0)), (((*((struct __T20 *)__T27)).__par1)), (((*((struct __T20 *)__T27)).__par2)), (((*((struct __T20 *)__T27)).__par3)), (((*((struct __T20 *)__T27)).__par4)), (((*((struct __T20 *)__T27)).__par5)), (((*((struct __T20 *)__T27)).__par6)), (((*((struct __T20 *)__T27)).__par7)));}
#if defined(__cplusplus)
}
#endif
#endif
#if defined(__device_emulation)
#if defined(__cplusplus)
namespace __cuda_emu {
#endif
static void __device_wrapper__Z13ComputeFH_GPUiiPfS_S_S_S_P12_gpufi_data_(char *__T218){_Z13ComputeFH_GPUiiPfS_S_S_S_P12_gpufi_data_((((*((struct __T21 *)__T218)).__par0)), (((*((struct __T21 *)__T218)).__par1)), (((*((struct __T21 *)__T218)).__par2)), (((*((struct __T21 *)__T218)).__par3)), (((*((struct __T21 *)__T218)).__par4)), (((*((struct __T21 *)__T218)).__par5)), (((*((struct __T21 *)__T218)).__par6)), (((*((struct __T21 *)__T218)).__par7)));}
#if defined(__cplusplus)
}
#endif
#endif
static void __sti____cudaRegisterAll_12_main_cpp1_ii_46b07679(void){__cudaRegisterBinary();__cudaRegisterEntry(__device_stub_name(__device_stub__Z13ComputeFH_GPUiiPfS_S_S_S_P12_gpufi_data_,((void ( *)(int, int, float *, float *, float *, float *, float *, struct _gpufi_data_ *))ComputeFH_GPU__entry)), _Z13ComputeFH_GPUiiPfS_S_S_S_P12_gpufi_data_, (-1));__cudaRegisterEntry(__device_stub_name(__device_stub__Z16ComputeRhoPhiGPUiPfS_S_S_S_S_P12_gpufi_data_,((void ( *)(int, float *, float *, float *, float *, float *, float *, struct _gpufi_data_ *))ComputeRhoPhiGPU__entry)), _Z16ComputeRhoPhiGPUiPfS_S_S_S_S_P12_gpufi_data_, (-1));__cudaRegisterVariable(__shadow_var(gpufi_dev,gpufi_dev), 0, 4, 0, 0);__cudaRegisterVariable(__shadow_var(c,c), 0, 10240, 1, 0);}
#if defined(__cplusplus)
}
#endif
