#if defined(__cplusplus)
extern "C" {
#endif
#include "largerBlocks.fatbin.c"
#include "crt/host_runtime.h"
#if defined(__device_emulation) && defined(__cplusplus)
namespace __cuda_emu {struct __T20 {unsigned short *__par0;int __par1;int __par2;int __dummy_field;};
}
#endif
struct __T20 {unsigned short *__par0;int __par1;int __par2;int __dummy_field;};
#if defined(__device_emulation) && defined(__cplusplus)
namespace __cuda_emu {struct __T21 {unsigned short *__par0;int __par1;int __par2;int __dummy_field;};
}
#endif
struct __T21 {unsigned short *__par0;int __par1;int __par2;int __dummy_field;};
static void __sti____cudaRegisterAll_20_largerBlocks_cpp1_ii_cabe4276(void) __attribute__((__constructor__));
void __device_stub__Z17larger_sad_calc_8Ptii(unsigned short *__par0, int __par1, int __par2){auto struct __T20 *__T24;
__cudaInitArgBlock(__T24);__cudaSetupArg(__par0, __T24);__cudaSetupArg(__par1, __T24);__cudaSetupArg(__par2, __T24);__cudaLaunch(((char *)__device_stub_name(__device_stub__Z17larger_sad_calc_8Ptii,((void ( *)(unsigned short *, int, int))larger_sad_calc_8__entry))));}
#if defined(__cplusplus)
}
void larger_sad_calc_8__entry( unsigned short *__cuda_0,int __cuda_1,int __cuda_2)
{__device_stub__Z17larger_sad_calc_8Ptii( __cuda_0,__cuda_1,__cuda_2);}
extern "C"{
#endif
void __device_stub__Z18larger_sad_calc_16Ptii(unsigned short *__par0, int __par1, int __par2){auto struct __T21 *__T25;
__cudaInitArgBlock(__T25);__cudaSetupArg(__par0, __T25);__cudaSetupArg(__par1, __T25);__cudaSetupArg(__par2, __T25);__cudaLaunch(((char *)__device_stub_name(__device_stub__Z18larger_sad_calc_16Ptii,((void ( *)(unsigned short *, int, int))larger_sad_calc_16__entry))));}
#if defined(__cplusplus)
}
void larger_sad_calc_16__entry( unsigned short *__cuda_0,int __cuda_1,int __cuda_2)
{__device_stub__Z18larger_sad_calc_16Ptii( __cuda_0,__cuda_1,__cuda_2);}
extern "C"{
#endif
#if defined(__device_emulation)
#if defined(__cplusplus)
namespace __cuda_emu {
#endif
static void __device_wrapper__Z17larger_sad_calc_8Ptii(char *__T26){_Z17larger_sad_calc_8Ptii((((*((struct __T20 *)__T26)).__par0)), (((*((struct __T20 *)__T26)).__par1)), (((*((struct __T20 *)__T26)).__par2)));}
#if defined(__cplusplus)
}
#endif
#endif
#if defined(__device_emulation)
#if defined(__cplusplus)
namespace __cuda_emu {
#endif
static void __device_wrapper__Z18larger_sad_calc_16Ptii(char *__T27){_Z18larger_sad_calc_16Ptii((((*((struct __T21 *)__T27)).__par0)), (((*((struct __T21 *)__T27)).__par1)), (((*((struct __T21 *)__T27)).__par2)));}
#if defined(__cplusplus)
}
#endif
#endif
static void __sti____cudaRegisterAll_20_largerBlocks_cpp1_ii_cabe4276(void){__cudaRegisterBinary();__cudaRegisterEntry(__device_stub_name(__device_stub__Z18larger_sad_calc_16Ptii,((void ( *)(unsigned short *, int, int))larger_sad_calc_16__entry)), _Z18larger_sad_calc_16Ptii, (-1));__cudaRegisterEntry(__device_stub_name(__device_stub__Z17larger_sad_calc_8Ptii,((void ( *)(unsigned short *, int, int))larger_sad_calc_8__entry)), _Z17larger_sad_calc_8Ptii, (-1));}
#if defined(__cplusplus)
}
#endif
