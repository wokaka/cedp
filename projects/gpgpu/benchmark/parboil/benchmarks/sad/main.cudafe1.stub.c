#if defined(__cplusplus)
extern "C" {
#endif
#include "main.fatbin.c"
#include "crt/host_runtime.h"
#if defined(__device_emulation) && defined(__cplusplus)
namespace __cuda_emu {struct __T20 {unsigned short *__par0;int __par1;int __par2;struct _gpufi_data_ *__par3;int __dummy_field;};
}
#endif
struct __T20 {unsigned short *__par0;int __par1;int __par2;struct _gpufi_data_ *__par3;int __dummy_field;};
#if defined(__device_emulation) && defined(__cplusplus)
namespace __cuda_emu {struct __T21 {unsigned short *__par0;int __par1;int __par2;struct _gpufi_data_ *__par3;int __dummy_field;};
}
#endif
struct __T21 {unsigned short *__par0;int __par1;int __par2;struct _gpufi_data_ *__par3;int __dummy_field;};
#if defined(__device_emulation) && defined(__cplusplus)
namespace __cuda_emu {struct __T22 {unsigned short *__par0;unsigned short *__par1;int __par2;int __par3;struct _gpufi_data_ *__par4;int __dummy_field;};
}
#endif
struct __T22 {unsigned short *__par0;unsigned short *__par1;int __par2;int __par3;struct _gpufi_data_ *__par4;int __dummy_field;};
static void __sti____cudaRegisterAll_12_main_cpp1_ii_46b07679(void) __attribute__((__constructor__));
void __device_stub__Z17larger_sad_calc_8PtiiP12_gpufi_data_(unsigned short *__par0, int __par1, int __par2, struct _gpufi_data_ *__par3){auto struct __T20 *__T26;
__cudaInitArgBlock(__T26);__cudaSetupArg(__par0, __T26);__cudaSetupArg(__par1, __T26);__cudaSetupArg(__par2, __T26);__cudaSetupArg(__par3, __T26);__cudaLaunch(((char *)__device_stub_name(__device_stub__Z17larger_sad_calc_8PtiiP12_gpufi_data_,((void ( *)(unsigned short *, int, int, struct _gpufi_data_ *))larger_sad_calc_8__entry))));}
#if defined(__cplusplus)
}
void larger_sad_calc_8__entry( unsigned short *__cuda_0,int __cuda_1,int __cuda_2,struct _gpufi_data_ *__cuda_3)
{__device_stub__Z17larger_sad_calc_8PtiiP12_gpufi_data_( __cuda_0,__cuda_1,__cuda_2,__cuda_3);}
extern "C"{
#endif
void __device_stub__Z18larger_sad_calc_16PtiiP12_gpufi_data_(unsigned short *__par0, int __par1, int __par2, struct _gpufi_data_ *__par3){auto struct __T21 *__T27;
__cudaInitArgBlock(__T27);__cudaSetupArg(__par0, __T27);__cudaSetupArg(__par1, __T27);__cudaSetupArg(__par2, __T27);__cudaSetupArg(__par3, __T27);__cudaLaunch(((char *)__device_stub_name(__device_stub__Z18larger_sad_calc_16PtiiP12_gpufi_data_,((void ( *)(unsigned short *, int, int, struct _gpufi_data_ *))larger_sad_calc_16__entry))));}
#if defined(__cplusplus)
}
void larger_sad_calc_16__entry( unsigned short *__cuda_0,int __cuda_1,int __cuda_2,struct _gpufi_data_ *__cuda_3)
{__device_stub__Z18larger_sad_calc_16PtiiP12_gpufi_data_( __cuda_0,__cuda_1,__cuda_2,__cuda_3);}
extern "C"{
#endif
void __device_stub__Z11mb_sad_calcPtS_iiP12_gpufi_data_(unsigned short *__par0, unsigned short *__par1, int __par2, int __par3, struct _gpufi_data_ *__par4){auto struct __T22 *__T28;
__cudaInitArgBlock(__T28);__cudaSetupArg(__par0, __T28);__cudaSetupArg(__par1, __T28);__cudaSetupArg(__par2, __T28);__cudaSetupArg(__par3, __T28);__cudaSetupArg(__par4, __T28);__cudaLaunch(((char *)__device_stub_name(__device_stub__Z11mb_sad_calcPtS_iiP12_gpufi_data_,((void ( *)(unsigned short *, unsigned short *, int, int, struct _gpufi_data_ *))mb_sad_calc__entry))));}
#if defined(__cplusplus)
}
void mb_sad_calc__entry( unsigned short *__cuda_0,unsigned short *__cuda_1,int __cuda_2,int __cuda_3,struct _gpufi_data_ *__cuda_4)
{__device_stub__Z11mb_sad_calcPtS_iiP12_gpufi_data_( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4);}
extern "C"{
#endif
#if defined(__device_emulation)
#if defined(__cplusplus)
namespace __cuda_emu {
#endif
static void __device_wrapper__Z17larger_sad_calc_8PtiiP12_gpufi_data_(char *__T217){_Z17larger_sad_calc_8PtiiP12_gpufi_data_((((*((struct __T20 *)__T217)).__par0)), (((*((struct __T20 *)__T217)).__par1)), (((*((struct __T20 *)__T217)).__par2)), (((*((struct __T20 *)__T217)).__par3)));}
#if defined(__cplusplus)
}
#endif
#endif
#if defined(__device_emulation)
#if defined(__cplusplus)
namespace __cuda_emu {
#endif
static void __device_wrapper__Z18larger_sad_calc_16PtiiP12_gpufi_data_(char *__T218){_Z18larger_sad_calc_16PtiiP12_gpufi_data_((((*((struct __T21 *)__T218)).__par0)), (((*((struct __T21 *)__T218)).__par1)), (((*((struct __T21 *)__T218)).__par2)), (((*((struct __T21 *)__T218)).__par3)));}
#if defined(__cplusplus)
}
#endif
#endif
#if defined(__device_emulation)
#if defined(__cplusplus)
namespace __cuda_emu {
#endif
static void __device_wrapper__Z11mb_sad_calcPtS_iiP12_gpufi_data_(char *__T2139){_Z11mb_sad_calcPtS_iiP12_gpufi_data_((((*((struct __T22 *)__T2139)).__par0)), (((*((struct __T22 *)__T2139)).__par1)), (((*((struct __T22 *)__T2139)).__par2)), (((*((struct __T22 *)__T2139)).__par3)), (((*((struct __T22 *)__T2139)).__par4)));}
#if defined(__cplusplus)
}
#endif
#endif
static void __sti____cudaRegisterAll_12_main_cpp1_ii_46b07679(void){__cudaRegisterBinary();__cudaRegisterEntry(__device_stub_name(__device_stub__Z11mb_sad_calcPtS_iiP12_gpufi_data_,((void ( *)(unsigned short *, unsigned short *, int, int, struct _gpufi_data_ *))mb_sad_calc__entry)), _Z11mb_sad_calcPtS_iiP12_gpufi_data_, (-1));__cudaRegisterEntry(__device_stub_name(__device_stub__Z18larger_sad_calc_16PtiiP12_gpufi_data_,((void ( *)(unsigned short *, int, int, struct _gpufi_data_ *))larger_sad_calc_16__entry)), _Z18larger_sad_calc_16PtiiP12_gpufi_data_, (-1));__cudaRegisterEntry(__device_stub_name(__device_stub__Z17larger_sad_calc_8PtiiP12_gpufi_data_,((void ( *)(unsigned short *, int, int, struct _gpufi_data_ *))larger_sad_calc_8__entry)), _Z17larger_sad_calc_8PtiiP12_gpufi_data_, (-1));__cudaRegisterVariable(__shadow_var(gpufi_dev,gpufi_dev), 0, 4, 0, 0);__cudaRegisterSharedVariable(frame_loc, 32, 2, 0);__cudaRegisterGlobalTexture(__text_var(ref,ref), 2, 0, 0);__cudaRegisterUnsizedShared(sad_loc);__cudaRegisterUnsizedShared(sad_loc_8b);}
#if defined(__cplusplus)
}
#endif
