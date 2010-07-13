#if defined(__cplusplus)
extern "C" {
#endif
#include "main.fatbin.c"
#include "crt/host_runtime.h"
#if defined(__device_emulation) && defined(__cplusplus)
namespace __cuda_emu {struct __T20 {uint4 *__par0;float *__par1;int __par2;int __dummy_field;};
}
#endif
struct __T20 {uint4 *__par0;float *__par1;int __par2;int __dummy_field;};
#if defined(__device_emulation) && defined(__cplusplus)
namespace __cuda_emu {struct __T21 {float *__par0;float *__par1;uint2 *__par2;int __par3;int __par4;int __dummy_field;};
}
#endif
struct __T21 {float *__par0;float *__par1;uint2 *__par2;int __par3;int __par4;int __dummy_field;};
static void __sti____cudaRegisterAll_12_main_cpp1_ii_texCoors(void) __attribute__((__constructor__));
void __device_stub__Z8ComputeXP5uint4Pfi(uint4 *__par0, float *__par1, int __par2){auto struct __T20 *__T24;
__cudaInitArgBlock(__T24);__cudaSetupArg(__par0, __T24);__cudaSetupArg(__par1, __T24);__cudaSetupArg(__par2, __T24);__cudaLaunch(((char *)__device_stub_name(__device_stub__Z8ComputeXP5uint4Pfi,((void ( *)(uint4 *, float *, int))ComputeX__entry))));}
#if defined(__cplusplus)
}
void ComputeX__entry( uint4 *__cuda_0,float *__cuda_1,int __cuda_2)
{__device_stub__Z8ComputeXP5uint4Pfi( __cuda_0,__cuda_1,__cuda_2);}
extern "C"{
#endif
void __device_stub__Z11DoReductionPfS_P5uint2ii(float *__par0, float *__par1, uint2 *__par2, int __par3, int __par4){auto struct __T21 *__T25;
__cudaInitArgBlock(__T25);__cudaSetupArg(__par0, __T25);__cudaSetupArg(__par1, __T25);__cudaSetupArg(__par2, __T25);__cudaSetupArg(__par3, __T25);__cudaSetupArg(__par4, __T25);__cudaLaunch(((char *)__device_stub_name(__device_stub__Z11DoReductionPfS_P5uint2ii,((void ( *)(float *, float *, uint2 *, int, int))DoReduction__entry))));}
#if defined(__cplusplus)
}
void DoReduction__entry( float *__cuda_0,float *__cuda_1,uint2 *__cuda_2,int __cuda_3,int __cuda_4)
{__device_stub__Z11DoReductionPfS_P5uint2ii( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4);}
extern "C"{
#endif
#if defined(__device_emulation)
#if defined(__cplusplus)
namespace __cuda_emu {
#endif
static void __device_wrapper__Z8ComputeXP5uint4Pfi(char *__T275){_Z8ComputeXP5uint4Pfi((((*((struct __T20 *)__T275)).__par0)), (((*((struct __T20 *)__T275)).__par1)), (((*((struct __T20 *)__T275)).__par2)));}
#if defined(__cplusplus)
}
#endif
#endif
#if defined(__device_emulation)
#if defined(__cplusplus)
namespace __cuda_emu {
#endif
static void __device_wrapper__Z11DoReductionPfS_P5uint2ii(char *__T276){_Z11DoReductionPfS_P5uint2ii((((*((struct __T21 *)__T276)).__par0)), (((*((struct __T21 *)__T276)).__par1)), (((*((struct __T21 *)__T276)).__par2)), (((*((struct __T21 *)__T276)).__par3)), (((*((struct __T21 *)__T276)).__par4)));}
#if defined(__cplusplus)
}
#endif
#endif
static void __sti____cudaRegisterAll_12_main_cpp1_ii_texCoors(void){__cudaRegisterBinary();__cudaRegisterEntry(__device_stub_name(__device_stub__Z11DoReductionPfS_P5uint2ii,((void ( *)(float *, float *, uint2 *, int, int))DoReduction__entry)), _Z11DoReductionPfS_P5uint2ii, (-1));__cudaRegisterEntry(__device_stub_name(__device_stub__Z8ComputeXP5uint4Pfi,((void ( *)(uint4 *, float *, int))ComputeX__entry)), _Z8ComputeXP5uint4Pfi, (-1));__cudaRegisterGlobalTexture(__text_var(texCoors,texCoors), 1, 0, 0);__cudaRegisterGlobalTexture(__text_var(texSprms,texSprms), 1, 0, 0);__cudaRegisterGlobalTexture(__text_var(texWghts,texWghts), 1, 0, 0);}
#if defined(__cplusplus)
}
#endif
