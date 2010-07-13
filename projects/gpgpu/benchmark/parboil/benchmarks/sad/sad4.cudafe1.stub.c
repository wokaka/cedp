#if defined(__cplusplus)
extern "C" {
#endif
#include "sad4.fatbin.c"
#include "crt/host_runtime.h"
#if defined(__device_emulation) && defined(__cplusplus)
namespace __cuda_emu {struct __T20 {unsigned short *__par0;unsigned short *__par1;int __par2;int __par3;int __dummy_field;};
}
#endif
struct __T20 {unsigned short *__par0;unsigned short *__par1;int __par2;int __par3;int __dummy_field;};
static void __sti____cudaRegisterAll_12_sad4_cpp1_ii_ref(void) __attribute__((__constructor__));
void __device_stub__Z11mb_sad_calcPtS_ii(unsigned short *__par0, unsigned short *__par1, int __par2, int __par3){auto struct __T20 *__T23;
__cudaInitArgBlock(__T23);__cudaSetupArg(__par0, __T23);__cudaSetupArg(__par1, __T23);__cudaSetupArg(__par2, __T23);__cudaSetupArg(__par3, __T23);__cudaLaunch(((char *)__device_stub_name(__device_stub__Z11mb_sad_calcPtS_ii,((void ( *)(unsigned short *, unsigned short *, int, int))mb_sad_calc__entry))));}
#if defined(__cplusplus)
}
void mb_sad_calc__entry( unsigned short *__cuda_0,unsigned short *__cuda_1,int __cuda_2,int __cuda_3)
{__device_stub__Z11mb_sad_calcPtS_ii( __cuda_0,__cuda_1,__cuda_2,__cuda_3);}
extern "C"{
#endif
#if defined(__device_emulation)
#if defined(__cplusplus)
namespace __cuda_emu {
#endif
static void __device_wrapper__Z11mb_sad_calcPtS_ii(char *__T234){_Z11mb_sad_calcPtS_ii((((*((struct __T20 *)__T234)).__par0)), (((*((struct __T20 *)__T234)).__par1)), (((*((struct __T20 *)__T234)).__par2)), (((*((struct __T20 *)__T234)).__par3)));}
#if defined(__cplusplus)
}
#endif
#endif
static void __sti____cudaRegisterAll_12_sad4_cpp1_ii_ref(void){__cudaRegisterBinary();__cudaRegisterEntry(__device_stub_name(__device_stub__Z11mb_sad_calcPtS_ii,((void ( *)(unsigned short *, unsigned short *, int, int))mb_sad_calc__entry)), _Z11mb_sad_calcPtS_ii, (-1));__cudaRegisterSharedVariable(frame_loc, 32, 2, 0);__cudaRegisterGlobalTexture(__text_var(ref,ref), 2, 0, 0);__cudaRegisterUnsizedShared(sad_loc);__cudaRegisterUnsizedShared(sad_loc_8b);}
#if defined(__cplusplus)
}
#endif
