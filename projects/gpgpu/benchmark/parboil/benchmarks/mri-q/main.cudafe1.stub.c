#if defined(__cplusplus)
extern "C" {
#endif
#include "main.fatbin.c"
#include "crt/host_runtime.h"
#if defined(__device_emulation) && defined(__cplusplus)
namespace __cuda_emu {struct __T20 {float *__par0;float *__par1;float *__par2;int __par3;int __dummy_field;};
}
#endif
struct __T20 {float *__par0;float *__par1;float *__par2;int __par3;int __dummy_field;};
#if defined(__device_emulation) && defined(__cplusplus)
namespace __cuda_emu {struct __T21 {int __par0;int __par1;float *__par2;float *__par3;float *__par4;float *__par5;float *__par6;int __dummy_field;};
}
#endif
struct __T21 {int __par0;int __par1;float *__par2;float *__par3;float *__par4;float *__par5;float *__par6;int __dummy_field;};
static void __sti____cudaRegisterAll_12_main_cpp1_ii_46b07679(void) __attribute__((__constructor__));
void __device_stub__Z17ComputePhiMag_GPUPfS_S_i(float *__par0, float *__par1, float *__par2, int __par3){auto struct __T20 *__T24;
__cudaInitArgBlock(__T24);__cudaSetupArg(__par0, __T24);__cudaSetupArg(__par1, __T24);__cudaSetupArg(__par2, __T24);__cudaSetupArg(__par3, __T24);__cudaLaunch(((char *)__device_stub_name(__device_stub__Z17ComputePhiMag_GPUPfS_S_i,((void ( *)(float *, float *, float *, int))ComputePhiMag_GPU__entry))));}
#if defined(__cplusplus)
}
void ComputePhiMag_GPU__entry( float *__cuda_0,float *__cuda_1,float *__cuda_2,int __cuda_3)
{__device_stub__Z17ComputePhiMag_GPUPfS_S_i( __cuda_0,__cuda_1,__cuda_2,__cuda_3);}
extern "C"{
#endif
void __device_stub__Z12ComputeQ_GPUiiPfS_S_S_S_(int __par0, int __par1, float *__par2, float *__par3, float *__par4, float *__par5, float *__par6){auto struct __T21 *__T25;
__cudaInitArgBlock(__T25);__cudaSetupArg(__par0, __T25);__cudaSetupArg(__par1, __T25);__cudaSetupArg(__par2, __T25);__cudaSetupArg(__par3, __T25);__cudaSetupArg(__par4, __T25);__cudaSetupArg(__par5, __T25);__cudaSetupArg(__par6, __T25);__cudaLaunch(((char *)__device_stub_name(__device_stub__Z12ComputeQ_GPUiiPfS_S_S_S_,((void ( *)(int, int, float *, float *, float *, float *, float *))ComputeQ_GPU__entry))));}
#if defined(__cplusplus)
}
void ComputeQ_GPU__entry( int __cuda_0,int __cuda_1,float *__cuda_2,float *__cuda_3,float *__cuda_4,float *__cuda_5,float *__cuda_6)
{__device_stub__Z12ComputeQ_GPUiiPfS_S_S_S_( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6);}
extern "C"{
#endif
#if defined(__device_emulation)
#if defined(__cplusplus)
namespace __cuda_emu {
#endif
static void __device_wrapper__Z17ComputePhiMag_GPUPfS_S_i(char *__T26){_Z17ComputePhiMag_GPUPfS_S_i((((*((struct __T20 *)__T26)).__par0)), (((*((struct __T20 *)__T26)).__par1)), (((*((struct __T20 *)__T26)).__par2)), (((*((struct __T20 *)__T26)).__par3)));}
#if defined(__cplusplus)
}
#endif
#endif
#if defined(__device_emulation)
#if defined(__cplusplus)
namespace __cuda_emu {
#endif
static void __device_wrapper__Z12ComputeQ_GPUiiPfS_S_S_S_(char *__T27){_Z12ComputeQ_GPUiiPfS_S_S_S_((((*((struct __T21 *)__T27)).__par0)), (((*((struct __T21 *)__T27)).__par1)), (((*((struct __T21 *)__T27)).__par2)), (((*((struct __T21 *)__T27)).__par3)), (((*((struct __T21 *)__T27)).__par4)), (((*((struct __T21 *)__T27)).__par5)), (((*((struct __T21 *)__T27)).__par6)));}
#if defined(__cplusplus)
}
#endif
#endif
static void __sti____cudaRegisterAll_12_main_cpp1_ii_46b07679(void){__cudaRegisterBinary();__cudaRegisterEntry(__device_stub_name(__device_stub__Z12ComputeQ_GPUiiPfS_S_S_S_,((void ( *)(int, int, float *, float *, float *, float *, float *))ComputeQ_GPU__entry)), _Z12ComputeQ_GPUiiPfS_S_S_S_, (-1));__cudaRegisterEntry(__device_stub_name(__device_stub__Z17ComputePhiMag_GPUPfS_S_i,((void ( *)(float *, float *, float *, int))ComputePhiMag_GPU__entry)), _Z17ComputePhiMag_GPUPfS_S_i, (-1));__cudaRegisterVariable(__shadow_var(gpufi_dev,gpufi_dev), 0, 4, 0, 0);__cudaRegisterVariable(__shadow_var(ck,ck), 0, 16384, 1, 0);}
#if defined(__cplusplus)
}
#endif
