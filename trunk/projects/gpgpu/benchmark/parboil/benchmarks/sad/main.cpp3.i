# 1 "main.cudafe2.gpu"
# 1 "/afs/crhc.illinois.edu/project/depend/yim6/clairvoyant/fi/server/src-server/ControlServer/instr/parboil/benchmarks/sad//"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "main.cudafe2.gpu"
# 14 "src/cuda_fi/gpufi.h"
struct _gpufi_fault_;
# 46 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_kernel_;
# 54 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_variable_;
# 60 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_;
# 76 "src/cuda_fi/gpufi.h"
struct _gpufi_current_;
# 98 "src/cuda_fi/gpufi.h"
struct _gpufi_data_;
# 40 "src/cuda_fi/sad4.h"
struct vec8b;
# 214 "/usr/lib/gcc/i486-linux-gnu/4.3.2/include/stddef.h" 3
typedef unsigned size_t;

# 1 "/usr/local/cuda/bin/../include/crt/device_runtime.h" 1 3
# 42 "/usr/local/cuda/bin/../include/crt/device_runtime.h" 3
# 1 "/usr/local/cuda/bin/../include/host_defines.h" 1 3
# 43 "/usr/local/cuda/bin/../include/crt/device_runtime.h" 2 3
# 55 "/usr/local/cuda/bin/../include/crt/device_runtime.h" 3
typedef const void *__texture_type__;

typedef const void *__surface_type__;
# 279 "/usr/local/cuda/bin/../include/crt/device_runtime.h" 3
# 1 "/usr/local/cuda/bin/../include/builtin_types.h" 1 3
# 42 "/usr/local/cuda/bin/../include/builtin_types.h" 3
# 1 "/usr/local/cuda/bin/../include/device_types.h" 1 3
# 46 "/usr/local/cuda/bin/../include/device_types.h" 3
enum cudaRoundMode
{
  cudaRoundNearest,
  cudaRoundZero,
  cudaRoundPosInf,
  cudaRoundMinInf
};
# 43 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/driver_types.h" 1 3
# 91 "/usr/local/cuda/bin/../include/driver_types.h" 3
enum cudaError
{
  cudaSuccess = 0,
  cudaErrorMissingConfiguration = 1,
  cudaErrorMemoryAllocation = 2,
  cudaErrorInitializationError = 3,
  cudaErrorLaunchFailure = 4,
  cudaErrorPriorLaunchFailure = 5,
  cudaErrorLaunchTimeout = 6,
  cudaErrorLaunchOutOfResources = 7,
  cudaErrorInvalidDeviceFunction = 8,
  cudaErrorInvalidConfiguration = 9,
  cudaErrorInvalidDevice = 10,
  cudaErrorInvalidValue = 11,
  cudaErrorInvalidPitchValue = 12,
  cudaErrorInvalidSymbol = 13,
  cudaErrorMapBufferObjectFailed = 14,
  cudaErrorUnmapBufferObjectFailed = 15,
  cudaErrorInvalidHostPointer = 16,
  cudaErrorInvalidDevicePointer = 17,
  cudaErrorInvalidTexture = 18,
  cudaErrorInvalidTextureBinding = 19,
  cudaErrorInvalidChannelDescriptor = 20,
  cudaErrorInvalidMemcpyDirection = 21,
  cudaErrorAddressOfConstant = 22,
  cudaErrorTextureFetchFailed = 23,
  cudaErrorTextureNotBound = 24,
  cudaErrorSynchronizationError = 25,
  cudaErrorInvalidFilterSetting = 26,
  cudaErrorInvalidNormSetting = 27,
  cudaErrorMixedDeviceExecution = 28,
  cudaErrorCudartUnloading = 29,
  cudaErrorUnknown = 30,
  cudaErrorNotYetImplemented = 31,
  cudaErrorMemoryValueTooLarge = 32,
  cudaErrorInvalidResourceHandle = 33,
  cudaErrorNotReady = 34,
  cudaErrorInsufficientDriver = 35,
  cudaErrorSetOnActiveProcess = 36,
  cudaErrorNoDevice = 38,
  cudaErrorStartupFailure = 0x7f,
  cudaErrorApiFailureBase = 10000
};





enum cudaChannelFormatKind
{
  cudaChannelFormatKindSigned = 0,
  cudaChannelFormatKindUnsigned = 1,
  cudaChannelFormatKindFloat = 2,
  cudaChannelFormatKindNone = 3
};





struct cudaChannelFormatDesc
{
  int x;
  int y;
  int z;
  int w;
  enum cudaChannelFormatKind f;
};





struct cudaArray;





enum cudaMemcpyKind
{
  cudaMemcpyHostToHost = 0,
  cudaMemcpyHostToDevice = 1,
  cudaMemcpyDeviceToHost = 2,
  cudaMemcpyDeviceToDevice = 3
};





struct cudaPitchedPtr
{
  void *ptr;
  size_t pitch;
  size_t xsize;
  size_t ysize;
};





struct cudaExtent
{
  size_t width;
  size_t height;
  size_t depth;
};





struct cudaPos
{
  size_t x;
  size_t y;
  size_t z;
};





struct cudaMemcpy3DParms
{
  struct cudaArray *srcArray;
  struct cudaPos srcPos;
  struct cudaPitchedPtr srcPtr;

  struct cudaArray *dstArray;
  struct cudaPos dstPos;
  struct cudaPitchedPtr dstPtr;

  struct cudaExtent extent;
  enum cudaMemcpyKind kind;
};





struct cudaFuncAttributes
{
   size_t sharedSizeBytes;
   size_t constSizeBytes;
   size_t localSizeBytes;
   int maxThreadsPerBlock;
   int numRegs;
   int __cudaReserved[8];
};





enum cudaComputeMode
{
  cudaComputeModeDefault = 0,
  cudaComputeModeExclusive = 1,
  cudaComputeModeProhibited = 2
};






struct cudaDeviceProp
{
  char name[256];
  size_t totalGlobalMem;
  size_t sharedMemPerBlock;
  int regsPerBlock;
  int warpSize;
  size_t memPitch;
  int maxThreadsPerBlock;
  int maxThreadsDim[3];
  int maxGridSize[3];
  int clockRate;
  size_t totalConstMem;
  int major;
  int minor;
  size_t textureAlignment;
  int deviceOverlap;
  int multiProcessorCount;
  int kernelExecTimeoutEnabled;
  int integrated;
  int canMapHostMemory;
  int computeMode;
  int __cudaReserved[36];
};
# 319 "/usr/local/cuda/bin/../include/driver_types.h" 3
typedef enum cudaError cudaError_t;





typedef int cudaStream_t;





typedef int cudaEvent_t;
# 44 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/texture_types.h" 1 3
# 54 "/usr/local/cuda/bin/../include/texture_types.h" 3
enum cudaTextureAddressMode
{
  cudaAddressModeWrap,
  cudaAddressModeClamp
};


enum cudaTextureFilterMode
{
  cudaFilterModePoint,
  cudaFilterModeLinear
};


enum cudaTextureReadMode
{
  cudaReadModeElementType,
  cudaReadModeNormalizedFloat
};


struct textureReference
{
  int normalized;
  enum cudaTextureFilterMode filterMode;
  enum cudaTextureAddressMode addressMode[3];
  struct cudaChannelFormatDesc channelDesc;
  int __cudaReserved[16];
};
# 45 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 1 "/usr/local/cuda/bin/../include/vector_types.h" 1 3
# 45 "/usr/local/cuda/bin/../include/vector_types.h" 3
# 1 "/usr/local/cuda/bin/../include/host_defines.h" 1 3
# 46 "/usr/local/cuda/bin/../include/vector_types.h" 2 3
# 82 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct char1
{
  signed char x;
 
};


struct uchar1
{
  unsigned char x;
 
};


struct __attribute__((__aligned__(2))) char2
{
  signed char x, y;
 
};


struct __attribute__((__aligned__(2))) uchar2
{
  unsigned char x, y;
 
};


struct char3
{
  signed char x, y, z;
 
};


struct uchar3
{
  unsigned char x, y, z;
 
};


struct __attribute__((__aligned__(4))) char4
{
  signed char x, y, z, w;
 
};


struct __attribute__((__aligned__(4))) uchar4
{
  unsigned char x, y, z, w;
 
};


struct short1
{
  short x;
 
};


struct ushort1
{
  unsigned short x;
 
};


struct __attribute__((__aligned__(4))) short2
{
  short x, y;
 
};


struct __attribute__((__aligned__(4))) ushort2
{
  unsigned short x, y;
 
};


struct short3
{
  short x, y, z;
 
};


struct ushort3
{
  unsigned short x, y, z;
 
};


struct __attribute__((__aligned__(8))) short4 { short x, y, z, w; };


struct __attribute__((__aligned__(8))) ushort4 { unsigned short x, y, z, w; };


struct int1
{
  int x;
 
};


struct uint1
{
  unsigned int x;
 
};


struct __attribute__((__aligned__(8))) int2 { int x, y; };


struct __attribute__((__aligned__(8))) uint2 { unsigned int x, y; };


struct int3
{
  int x, y, z;
 
};


struct uint3
{
  unsigned int x, y, z;
 
};


struct __attribute__((__aligned__(16))) int4
{
  int x, y, z, w;
 
};


struct __attribute__((__aligned__(16))) uint4
{
  unsigned int x, y, z, w;
 
};


struct long1
{
  long int x;
 
};


struct ulong1
{
  unsigned long x;
 
};
# 258 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct __attribute__((__aligned__(2*sizeof(long int)))) long2
{
  long int x, y;
 
};


struct __attribute__((__aligned__(2*sizeof(unsigned long int)))) ulong2
{
  unsigned long int x, y;
 
};






struct long3
{
  long int x, y, z;
 
};


struct ulong3
{
  unsigned long int x, y, z;
 
};


struct __attribute__((__aligned__(16))) long4
{
  long int x, y, z, w;
 
};


struct __attribute__((__aligned__(16))) ulong4
{
  unsigned long int x, y, z, w;
 
};




struct float1
{
  float x;
 
};


struct __attribute__((__aligned__(8))) float2 { float x, y; };


struct float3
{
  float x, y, z;
 
};


struct __attribute__((__aligned__(16))) float4
{
  float x, y, z, w;
 
};


struct longlong1
{
  long long int x;
 
};


struct ulonglong1
{
  unsigned long long int x;
 
};


struct __attribute__((__aligned__(16))) longlong2
{
  long long int x, y;
 
};


struct __attribute__((__aligned__(16))) ulonglong2
{
  unsigned long long int x, y;
 
};


struct double1
{
  double x;
 
};


struct __attribute__((__aligned__(16))) double2
{
  double x, y;
 
};
# 378 "/usr/local/cuda/bin/../include/vector_types.h" 3
typedef struct char1 char1;

typedef struct uchar1 uchar1;

typedef struct char2 char2;

typedef struct uchar2 uchar2;

typedef struct char3 char3;

typedef struct uchar3 uchar3;

typedef struct char4 char4;

typedef struct uchar4 uchar4;

typedef struct short1 short1;

typedef struct ushort1 ushort1;

typedef struct short2 short2;

typedef struct ushort2 ushort2;

typedef struct short3 short3;

typedef struct ushort3 ushort3;

typedef struct short4 short4;

typedef struct ushort4 ushort4;

typedef struct int1 int1;

typedef struct uint1 uint1;

typedef struct int2 int2;

typedef struct uint2 uint2;

typedef struct int3 int3;

typedef struct uint3 uint3;

typedef struct int4 int4;

typedef struct uint4 uint4;

typedef struct long1 long1;

typedef struct ulong1 ulong1;

typedef struct long2 long2;

typedef struct ulong2 ulong2;

typedef struct long3 long3;

typedef struct ulong3 ulong3;

typedef struct long4 long4;

typedef struct ulong4 ulong4;

typedef struct float1 float1;

typedef struct float2 float2;

typedef struct float3 float3;

typedef struct float4 float4;

typedef struct longlong1 longlong1;

typedef struct ulonglong1 ulonglong1;

typedef struct longlong2 longlong2;

typedef struct ulonglong2 ulonglong2;

typedef struct double1 double1;

typedef struct double2 double2;
# 469 "/usr/local/cuda/bin/../include/vector_types.h" 3
struct dim3
{
    unsigned int x, y, z;





};


typedef struct dim3 dim3;
# 45 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 280 "/usr/local/cuda/bin/../include/crt/device_runtime.h" 2 3
# 1 "/usr/local/cuda/bin/../include/device_launch_parameters.h" 1 3
# 53 "/usr/local/cuda/bin/../include/device_launch_parameters.h" 3
uint3 extern const threadIdx;

uint3 extern const blockIdx;

dim3 extern const blockDim;

dim3 extern const gridDim;

int extern const warpSize;
# 281 "/usr/local/cuda/bin/../include/crt/device_runtime.h" 2 3
# 1 "/usr/local/cuda/bin/../include/crt/storage_class.h" 1 3
# 281 "/usr/local/cuda/bin/../include/crt/device_runtime.h" 2 3
# 217 "/usr/lib/gcc/i486-linux-gnu/4.3.2/include/stddef.h" 2 3
# 145 "/usr/include/bits/types.h" 3
typedef long __clock_t;
# 61 "/usr/include/time.h" 3
typedef __clock_t clock_t;
# 153 "/usr/include/sys/types.h" 3
typedef unsigned uint;
# 14 "src/cuda_fi/gpufi.h"
struct _gpufi_fault_ {
# 15 "src/cuda_fi/gpufi.h"
int kernel;
# 17 "src/cuda_fi/gpufi.h"
int instance;
# 18 "src/cuda_fi/gpufi.h"
int varid;
# 19 "src/cuda_fi/gpufi.h"
int call;
# 21 "src/cuda_fi/gpufi.h"
int mask_type;
# 24 "src/cuda_fi/gpufi.h"
unsigned mask;
# 25 "src/cuda_fi/gpufi.h"
int injected;
# 26 "src/cuda_fi/gpufi.h"
int disabled;
# 27 "src/cuda_fi/gpufi.h"
int mode;};
# 46 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_kernel_ {
# 47 "src/cuda_fi/gpufi.h"
char state;
# 48 "src/cuda_fi/gpufi.h"
int id;
# 49 "src/cuda_fi/gpufi.h"
int instance;
# 50 "src/cuda_fi/gpufi.h"
char name[32];};
# 54 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_variable_ {
# 55 "src/cuda_fi/gpufi.h"
int call_count;
# 56 "src/cuda_fi/gpufi.h"
int loop_id;
# 57 "src/cuda_fi/gpufi.h"
int type;};
# 60 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_ {
# 62 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_kernel_ kernel[10];
# 63 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_variable_ variable[10][128];
# 66 "src/cuda_fi/gpufi.h"
char kernel_bitmap[10];
# 67 "src/cuda_fi/gpufi.h"
int kernel_instance[10];
# 69 "src/cuda_fi/gpufi.h"
char variable_bitmap[128];
# 70 "src/cuda_fi/gpufi.h"
char variable_name[128][32];};
# 76 "src/cuda_fi/gpufi.h"
struct _gpufi_current_ {
# 77 "src/cuda_fi/gpufi.h"
int mode;
# 78 "src/cuda_fi/gpufi.h"
int kernel;
# 79 "src/cuda_fi/gpufi.h"
int instance;
# 80 "src/cuda_fi/gpufi.h"
int loop;
# 81 "src/cuda_fi/gpufi.h"
int loop_count;
# 82 "src/cuda_fi/gpufi.h"
int iteration;
# 84 "src/cuda_fi/gpufi.h"
int profile_index;
# 85 "src/cuda_fi/gpufi.h"
int profile_mode;
# 93 "src/cuda_fi/gpufi.h"
int blid;
# 94 "src/cuda_fi/gpufi.h"
int thid;};
# 98 "src/cuda_fi/gpufi.h"
struct _gpufi_data_ {
# 99 "src/cuda_fi/gpufi.h"
struct _gpufi_fault_ fault;
# 103 "src/cuda_fi/gpufi.h"
struct _gpufi_fault_ debug;
# 104 "src/cuda_fi/gpufi.h"
struct _gpufi_current_ current;
# 105 "src/cuda_fi/gpufi.h"
struct _gpufi_profile_ profile;
# 106 "src/cuda_fi/gpufi.h"
int sdc;};
# 40 "src/cuda_fi/sad4.h"
struct vec8b {
# 41 "src/cuda_fi/sad4.h"
int fst;
# 42 "src/cuda_fi/sad4.h"
int snd;};
# 140 "src/cuda_fi/gpufi_kernel.cu"
static int _Z10GPUFI_EXITP12_gpufi_data_i(struct _gpufi_data_ *, int);
# 182 "src/cuda_fi/gpufi_kernel.cu"
static void _Z12GPUFI_KERNELP12_gpufi_data_iiPc(struct _gpufi_data_ *, int, int, char *);
# 222 "src/cuda_fi/gpufi_kernel.cu"
static void _Z17GPUFI_KERNEL_LOOPP12_gpufi_data_i(struct _gpufi_data_ *, int);
# 242 "src/cuda_fi/gpufi_kernel.cu"
static void _Z22GPUFI_KERNEL_ITERATIONP12_gpufi_data_(struct _gpufi_data_ *);
# 273 "src/cuda_fi/gpufi_kernel.cu"
static void _Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(struct _gpufi_data_ *, int, char *, int *, int);
# 324 "src/cuda_fi/gpufi_kernel.cu"
static void _Z27GPUFI_KERNEL_VARIABLE_FORCEP12_gpufi_data_iPcPi(struct _gpufi_data_ *, int, char *, int *);
# 352 "src/cuda_fi/gpufi_kernel.cu"
static void _Z28GPUFI_KERNEL_VARIABLE_STREAMP12_gpufi_data_iPcPiii(struct _gpufi_data_ *, int, char *, int *, int, int);
# 26 "src/cuda_fi/largerBlocks.cu"
__attribute__((__global__)) __attribute__((__used__)) extern void _Z17larger_sad_calc_8PtiiP12_gpufi_data_(unsigned short *const, const int, const int, struct _gpufi_data_ *const);
# 165 "src/cuda_fi/largerBlocks.cu"
__attribute__((__global__)) __attribute__((__used__)) extern void _Z18larger_sad_calc_16PtiiP12_gpufi_data_(unsigned short *const, const int, const int, struct _gpufi_data_ *const);
# 59 "src/cuda_fi/sad4.cu"
__attribute__((__global__)) __attribute__((__used__)) extern void _Z11mb_sad_calcPtS_iiP12_gpufi_data_(unsigned short *const, unsigned short *const, const int, const int, struct _gpufi_data_ *const);
# 10 "src/cuda_fi/gpufi_kernel.cu"
static __attribute__((__used__)) __attribute__((__device__)) struct _gpufi_data_ *gpufi_dev;
# 36 "src/cuda_fi/sad4.cu"
static __attribute__((__used__)) __attribute__((__shared__)) unsigned short frame_loc [16];
# 38 "src/cuda_fi/sad4.cu"
static __attribute__((__used__)) __attribute__((__texture__)) __texture_type__ ref;
# 43 "src/cuda_fi/sad4.cu"
extern __attribute__((__shared__)) unsigned short sad_loc [];
# 44 "src/cuda_fi/sad4.cu"
extern __attribute__((__shared__)) struct vec8b sad_loc_8b [];
# 1 "/usr/local/cuda/bin/../include/common_functions.h" 1
# 68 "/usr/local/cuda/bin/../include/common_functions.h"
# 1 "/usr/local/cuda/bin/../include/crt/func_macro.h" 1 3
# 69 "/usr/local/cuda/bin/../include/common_functions.h" 2

static clock_t __cuda_clock(void)
{
  return clock();
}

static void *__cuda_memset(void *s, int c, size_t n)
{
  return memset(s, c, n);
}

static void *__cuda_memcpy(void *d, const void *s, size_t n)
{
  return memcpy(d, s, n);
}
# 93 "/usr/local/cuda/bin/../include/common_functions.h"
# 1 "/usr/local/cuda/bin/../include/math_functions.h" 1 3
# 912 "/usr/local/cuda/bin/../include/math_functions.h" 3
int __cuda_error_not_implememted(void);
# 972 "/usr/local/cuda/bin/../include/math_functions.h" 3
static int __cuda_abs(int a)
{
  return abs(a);
}

static float __cuda_fabsf(float a)
{
  return fabsf(a);
}

static long long int __cuda_llabs(long long int a)
{



  return llabs(a);

}

static float __cuda_exp2f(float a)
{
  return exp2f(a);
}

# 1 "/usr/local/cuda/bin/../include/device_functions.h" 1 3
# 442 "/usr/local/cuda/bin/../include/device_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_constants.h" 1 3
# 443 "/usr/local/cuda/bin/../include/device_functions.h" 2 3



static float __frcp_rn (float x)
{
  unsigned int expo;
  unsigned f, y;
  unsigned int argi;
  float t;

  argi = __float_as_int(x);
  expo = (argi >> 23);
  expo = expo & 0xff;
  f = expo - 1;
  if (f <= 0xFD) {
    y = (argi & 0x00ffffff) | 0x00800000;
    expo = (2 * 127) - expo - 2;
    t = 1.0f / x;
    argi = __float_as_int(t);
    argi = (argi & 0x00ffffff) | 0x00800000;
    if ((int)expo >= 0) {

      f = __umul24(y, argi);

      if ((int)f > 0) {
        t = __int_as_float(__float_as_int(t)-1);
        f -= y;
      }

      expo = f + y;

      f = (unsigned)(-(int)f);
      if (expo < f) {
        t = __int_as_float(__float_as_int(t)+1);
      }
      return t;
    }
  }
  return 1.0f / x;
}

static float __frcp_rz (float x)
{
  unsigned int expo;
  unsigned f, y;
  unsigned int argi;
  float t;

  argi = __float_as_int(x);
  expo = (argi >> 23);
  expo = expo & 0xff;
  f = expo - 1;
  if (f <= 0xFD) {
    y = (argi & 0x00ffffff) | 0x00800000;
    expo = (2 * 127) - expo - 2;
    t = 1.0f / x;
    argi = __float_as_int(t);
    argi = (argi & 0x00ffffff) | 0x00800000;
    if ((int)expo >= 0) {
      f = __umul24(y, argi);
      if ((int)f > 0) {
        t = __int_as_float(__float_as_int(t)-1);
      }
      return t;
    }
  }
  return 1.0f / x;
}

static float __frcp_rd (float x)
{
  unsigned int expo;
  unsigned f, y;
  unsigned int argi;
  float t;

  argi = __float_as_int(x);
  expo = (argi >> 23);
  expo = expo & 0xff;
  f = expo - 1;
  if (f <= 0xFD) {
    y = (argi & 0x00ffffff) | 0x00800000;
    expo = (2 * 127) - expo - 2;
    t = 1.0f / x;
    argi = __float_as_int(t);
    argi = (argi & 0x00ffffff) | 0x00800000;
    if ((int)expo >= 0) {
      f = __umul24(y, argi);
      if (((int)f > 0) && (x > 0.0f)) {
        t = __int_as_float(__float_as_int(t)-1);
      }
      if (((int)f < 0) && (x < 0.0f)) {
        t = __int_as_float(__float_as_int(t)+1);
      }
      return t;
    }
  }
  return 1.0f / x;
}

static float __frcp_ru (float x)
{
  unsigned int expo;
  unsigned f, y;
  unsigned int argi;
  float t;

  argi = __float_as_int(x);
  expo = (argi >> 23);
  expo = expo & 0xff;
  f = expo - 1;
  if (f <= 0xFD) {
    y = (argi & 0x00ffffff) | 0x00800000;
    expo = (2 * 127) - expo - 2;
    t = 1.0f / x;
    argi = __float_as_int(t);
    argi = (argi & 0x00ffffff) | 0x00800000;
    if ((int)expo >= 0) {
      f = __umul24(y, argi);
      if (((int)f > 0) && (x < 0.0f)) {
        t = __int_as_float(__float_as_int(t)-1);
      }
      if (((int)f < 0) && (x > 0.0f)) {
        t = __int_as_float(__float_as_int(t)+1);
      }
      return t;
    }
  }
  return 1.0f / x;
}

static float __fsqrt_rn (float radicand)
{
  unsigned int expo, argi;
  unsigned int s, f, x;

  argi = __float_as_int(radicand);
  expo = argi >> 23;
  expo = expo & 0xff;
  f = expo - 1;

  if ((argi <= 0x80000000) && (f <= 0xFD)) {
    x = (argi << 8) | 0x80000000;
    x = x >> (expo & 1);
    argi = (((__float_as_int(rsqrtf(__int_as_float(
              __float_as_int(radicand)|1)))&0x00ffffff)|0x00800000)<<7);

    s = __umulhi(argi,argi);
    f = 0x30000000 - __umulhi(x,s);
    argi = __umulhi(f,argi);

    argi = __umulhi(x,argi);
    argi = argi >> 3;
    x = (x << 16) - (argi * argi);

    f = x - (2 * argi + 1);
    if ((int)f < 0) f = (unsigned)(-(int)f);
    if ((int)x < 0) x = (unsigned)(-(int)x);
    if (f < x) argi ++;
    argi = argi + (((expo + 125) & ~0x1) << 22);
    return __int_as_float(argi);
  }
  return sqrtf(radicand);
}

static float __fsqrt_rz (float radicand)
{
  unsigned int expo, argi;
  unsigned int s, f, x;

  argi = __float_as_int(radicand);
  expo = argi >> 23;
  expo = expo & 0xff;
  f = expo - 1;

  if ((argi <= 0x80000000) && (f <= 0xFD)) {
    x = (argi << 8) | 0x80000000;
    x = x >> (expo & 1);
    argi = (((__float_as_int(rsqrtf(__int_as_float(
              __float_as_int(radicand)|1)))&0x00ffffff)|0x00800000)<<7);

    s = __umulhi(argi,argi);
    f = 0x30000000 - __umulhi(x,s);
    argi = __umulhi(f,argi);

    argi = __umulhi(x,argi);

    argi = (argi + 4) >> 3;
    x = (x << 16) - (argi * argi);
    if ((int)x < 0) argi--;
    argi = argi + (((expo + 125) & ~0x1) << 22);
    return __int_as_float(argi);
  }
  return sqrtf(radicand);
}

static float __fsqrt_ru (float radicand)
{
  unsigned int expo, argi;
  unsigned int s, f, x;

  argi = __float_as_int(radicand);
  expo = argi >> 23;
  expo = expo & 0xff;
  f = expo - 1;

  if ((argi <= 0x80000000) && (f <= 0xFD)) {
    x = (argi << 8) | 0x80000000;
    x = x >> (expo & 1);
    argi = (((__float_as_int(rsqrtf(__int_as_float(
              __float_as_int(radicand)|1)))&0x00ffffff)|0x00800000)<<7);

    s = __umulhi(argi,argi);
    f = 0x30000000 - __umulhi(x,s);
    argi = __umulhi(f,argi);

    argi = __umulhi(x,argi);
    argi = (argi + 4) >> 3;
    x = (x << 16) - (argi * argi);
    if ((int)x > 0) argi++;
    argi = argi + (((expo + 125) & ~0x1) << 22);
    return __int_as_float(argi);
  }
  return sqrtf(radicand);
}

static float __fsqrt_rd (float radicand)
{
  unsigned int expo, argi;
  unsigned int s, f, x;

  argi = __float_as_int(radicand);
  expo = argi >> 23;
  expo = expo & 0xff;
  f = expo - 1;

  if ((argi <= 0x80000000) && (f <= 0xFD)) {
    x = (argi << 8) | 0x80000000;
    x = x >> (expo & 1);
    argi = (((__float_as_int(rsqrtf(__int_as_float(
              __float_as_int(radicand)|1)))&0x00ffffff)|0x00800000)<<7);

    s = __umulhi(argi,argi);
    f = 0x30000000 - __umulhi(x,s);
    argi = __umulhi(f,argi);

    argi = __umulhi(x,argi);

    argi = (argi + 4) >> 3;
    x = (x << 16) - (argi * argi);
    if ((int)x < 0) argi--;
    argi = argi + (((expo + 125) & ~0x1) << 22);
    return __int_as_float(argi);
  }
  return sqrtf(radicand);
}

static float __fdiv_rn (float dividend, float divisor)
{
  unsigned long long prod;
  unsigned r, f, x, y, expox, expoy, sign;
  unsigned expo_res;
  unsigned resi, cvtxi, cvtyi;
  float t;

  cvtxi = __float_as_int(dividend);
  cvtyi = __float_as_int(divisor);
  expox = (cvtxi >> 23) & 0xff;
  expoy = (cvtyi >> 23) & 0xff;
  sign = ((cvtxi ^ cvtyi) & 0x80000000);

  if (((expox - 1) <= 0xFD) && ((expoy - 1) <= 0xFD)) {
    expo_res = expox - expoy + 127 - 1;

    y = (cvtyi << 8) | 0x80000000;
    x = (cvtxi & 0x00ffffff) | 0x00800000;
    t =__int_as_float((cvtyi & 0x00ffffff) | 0x3f800001);
    r = ((__float_as_int(1.0f / t) & 0x00ffffff) | 0x00800000) << 7;

    f = (unsigned)-(int)__umulhi (y, r << 1);
    r = __umulhi (f, r << 1);

    prod = ((unsigned long long)x) * (r << 1);

    if (((int)((prod >> 32) << 8)) > 0) {
      expo_res--;
      prod = prod + prod;
    }

    r = (unsigned)(prod >> 32);
    y = y >> 8;

    if (expo_res <= 0xFD) {
      int rem0, rem1, inc;

      prod = ((unsigned long long)y) * r;
      x = x << (23 + ((prod >> 32) >> 15));
      rem1 = x - (unsigned)(prod & 0xffffffff);
      rem0 = rem1 - y;
      inc = abs(rem0) < abs(rem1);

      resi = sign | ((expo_res << 23) + r + inc);
      return __int_as_float(resi);
    } else if ((int)expo_res >= 254) {

      resi = sign | 0x7f800000;
      return __int_as_float(resi);
    } else {

      int rem0, rem1, inc;
      prod = ((unsigned long long)y) * r;
      x = x << (23 + ((prod >> 32) >> 15));
      rem1 = x - (unsigned)(prod & 0xffffffff);
      rem0 = rem1 - y;
      inc = abs(rem0) < abs(rem1);
      resi = ((expo_res << 23) + r + inc);
      if (resi != 0x00800000) resi = 0;
      return __int_as_float(sign | resi);
    }
  }
  if (__cuda_fabsf(divisor) > 8.507059173e37f) {
    divisor *= 0.25f;
    dividend *= 0.25f;
  }
  return __fdividef (dividend, divisor);
}

static float __fdiv_rz (float dividend, float divisor)
{
  unsigned long long prod;
  unsigned r, f, x, y, expox, expoy, sign;
  unsigned expo_res;
  unsigned resi, cvtxi, cvtyi;
  float t;

  cvtxi = __float_as_int(dividend);
  cvtyi = __float_as_int(divisor);
  expox = (cvtxi >> 23) & 0xff;
  expoy = (cvtyi >> 23) & 0xff;
  sign = ((cvtxi ^ cvtyi) & 0x80000000);

  if (((expox - 1) <= 0xFD) && ((expoy - 1) <= 0xFD)) {
    expo_res = expox - expoy + 127 - 1;

    y = (cvtyi << 8) | 0x80000000;
    x = (cvtxi & 0x00ffffff) | 0x00800000;
    t =__int_as_float((cvtyi & 0x00ffffff) | 0x3f800001);
    r = ((__float_as_int(1.0f / t) & 0x00ffffff) | 0x00800000) << 7;

    f = (unsigned)-(int)__umulhi (y, r << 1);
    r = __umulhi (f, r << 1);

    prod = ((unsigned long long)x) * (r << 1);

    if (((int)((prod >> 32) << 8)) > 0) {
      expo_res--;
      prod = prod + prod;
    }

    prod += 0x0000000080000000ULL;
    r = (unsigned)(prod >> 32);
    y = y >> 8;
    if (expo_res <= 0xFD) {

      int rem1;
      prod = ((unsigned long long)y) * r;
      x = x << (23 + ((prod >> 32) >> 15));
      rem1 = x - (unsigned)(prod & 0xffffffff);
      if (rem1 < 0) r--;
      resi = (expo_res << 23) + r;
      if (resi == 0x7f800000) resi = 0x7f7fffff;
      return __int_as_float(sign | resi);
    } else if ((int)expo_res >= 254) {

      resi = 0x7f7fffff;
      return __int_as_float(sign |resi);
    } else {

      int rem1;
      prod = ((unsigned long long)y) * r;
      x = x << (23 + ((prod >> 32) >> 15));
      rem1 = x - (unsigned)(prod & 0xffffffff);
      if (rem1 < 0) r--;
      resi = ((expo_res << 23) + r);
      if (resi != 0x00800000) resi = 0;
      return __int_as_float(sign | resi);
    }
  }
  if (__cuda_fabsf(divisor) > 8.507059173e37f) {
    divisor *= 0.25f;
    dividend *= 0.25f;
  }
  return __fdividef (dividend, divisor);
}

static float __fdiv_ru (float dividend, float divisor)
{
  unsigned long long prod;
  unsigned r, f, x, y, expox, expoy, sign;
  unsigned expo_res;
  unsigned resi, cvtxi, cvtyi;
  float t;

  cvtxi = __float_as_int(dividend);
  cvtyi = __float_as_int(divisor);
  expox = (cvtxi >> 23) & 0xff;
  expoy = (cvtyi >> 23) & 0xff;
  sign = ((cvtxi ^ cvtyi) & 0x80000000);

  if (((expox - 1) <= 0xFD) && ((expoy - 1) <= 0xFD)) {
    expo_res = expox - expoy + 127 - 1;

    y = (cvtyi << 8) | 0x80000000;
    x = (cvtxi & 0x00ffffff) | 0x00800000;
    t =__int_as_float((cvtyi & 0x00ffffff) | 0x3f800001);
    r = ((__float_as_int(1.0f / t) & 0x00ffffff) | 0x00800000) << 7;

    f = (unsigned)-(int)__umulhi (y, r << 1);
    r = __umulhi (f, r << 1);

    prod = ((unsigned long long)x) * (r << 1);

    if (((int)((prod >> 32) << 8)) > 0) {
      expo_res--;
      prod = prod + prod;
    }

    prod += 0x0000000080000000ULL;
    r = (unsigned)(prod >> 32);
    y = y >> 8;
    if (expo_res <= 0xFD) {

      int rem1;
      prod = ((unsigned long long)y) * r;
      x = x << (23 + ((prod >> 32) >> 15));
      rem1 = x - (unsigned)(prod & 0xffffffff);
      if ((rem1 < 0) && (sign)) r--;
      if ((rem1 > 0) && (!sign)) r++;
      resi = (expo_res << 23) + r;
      if ((resi == 0x7f800000) && (sign)) resi = 0x7f7fffff;
      return __int_as_float(sign | resi);
    } else if ((int)expo_res >= 254) {

      resi = sign ? 0x7f7fffff : 0x7f800000;
      return __int_as_float(sign | resi);
    } else {

      int rem1;
      prod = ((unsigned long long)y) * r;
      x = x << (23 + ((prod >> 32) >> 15));
      rem1 = x - (unsigned)(prod & 0xffffffff);
      if ((rem1 < 0) && (sign)) r--;
      if ((rem1 > 0) && (!sign)) r++;
      resi = ((expo_res << 23) + r);
      if (resi != 0x00800000) resi = 0;
      return __int_as_float(sign | resi);
    }
  }
  if (__cuda_fabsf(divisor) > 8.507059173e37f) {
    divisor *= 0.25f;
    dividend *= 0.25f;
  }
  return __fdividef (dividend, divisor);
}

static float __fdiv_rd (float dividend, float divisor)
{
  unsigned long long prod;
  unsigned r, f, x, y, expox, expoy, sign;
  unsigned expo_res;
  unsigned resi, cvtxi, cvtyi;
  float t;

  cvtxi = __float_as_int(dividend);
  cvtyi = __float_as_int(divisor);
  expox = (cvtxi >> 23) & 0xff;
  expoy = (cvtyi >> 23) & 0xff;
  sign = ((cvtxi ^ cvtyi) & 0x80000000);

  if (((expox - 1) <= 0xFD) && ((expoy - 1) <= 0xFD)) {
    expo_res = expox - expoy + 127 - 1;

    y = (cvtyi << 8) | 0x80000000;
    x = (cvtxi & 0x00ffffff) | 0x00800000;
    t =__int_as_float((cvtyi & 0x00ffffff) | 0x3f800001);
    r = ((__float_as_int(1.0f / t) & 0x00ffffff) | 0x00800000) << 7;

    f = (unsigned)-(int)__umulhi (y, r << 1);
    r = __umulhi (f, r << 1);

    prod = ((unsigned long long)x) * (r << 1);

    if (((int)((prod >> 32) << 8)) > 0) {
      expo_res--;
      prod = prod + prod;
    }

    prod += 0x0000000080000000ULL;
    r = (unsigned)(prod >> 32);
    y = y >> 8;
    if (expo_res <= 0xFD) {

      int rem1;
      prod = ((unsigned long long)y) * r;
      x = x << (23 + ((prod >> 32) >> 15));
      rem1 = x - (unsigned)(prod & 0xffffffff);
      if ((rem1 < 0) && (!sign)) r--;
      if ((rem1 > 0) && (sign)) r++;
      resi = (expo_res << 23) + r;
      if ((resi == 0x7f800000) && (!sign)) resi = 0x7f7fffff;
      return __int_as_float(sign | resi);
    } else if ((int)expo_res >= 254) {

      resi = sign ? 0x7f800000 : 0x7f7fffff;
      return __int_as_float(sign |resi);
    } else {

      int rem1;
      prod = ((unsigned long long)y) * r;
      x = x << (23 + ((prod >> 32) >> 15));
      rem1 = x - (unsigned)(prod & 0xffffffff);
      if ((rem1 < 0) && (!sign)) r--;
      if ((rem1 > 0) && (sign)) r++;
      resi = ((expo_res << 23) + r);
      if (resi != 0x00800000) resi = 0;
      return __int_as_float(sign | resi);
    }
  }
  if (__cuda_fabsf(divisor) > 8.507059173e37f) {
    divisor *= 0.25f;
    dividend *= 0.25f;
  }
  return __fdividef (dividend, divisor);
}

static float __fadd_ru (float a, float b)
{
  unsigned int expo_x, expo_y;
  unsigned int xxi, yyi, temp;

  xxi = __float_as_int(a);
  yyi = __float_as_int(b);


  expo_y = yyi << 1;
  if (expo_y > (xxi << 1)) {
    expo_y = xxi;
    xxi = yyi;
    yyi = expo_y;
  }

  temp = 0xff;
  expo_x = temp & (xxi >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yyi >> 23);
  expo_y = expo_y - 1;

  if ((expo_x <= 0xFD) &&
      (expo_y <= 0xFD)) {

    expo_y = expo_x - expo_y;
    if (expo_y > 25) {
      expo_y = 31;
    }
    temp = xxi ^ yyi;
    xxi = xxi & ~0x7f000000;
    xxi = xxi | 0x00800000;
    yyi = yyi & ~0xff000000;
    yyi = yyi | 0x00800000;

    if ((int)temp < 0) {

      temp = 32 - expo_y;
      temp = (expo_y) ? (yyi << temp) : 0;
      temp = (unsigned int)(-((int)temp));
      xxi = xxi - (yyi >> expo_y) - (temp ? 1 : 0);
      if (xxi & 0x00800000) {
        if (expo_x <= 0xFD) {
          xxi = (xxi + (expo_x << 23));
          xxi += (temp && !(xxi & 0x80000000));
          return __int_as_float(xxi);
        }
      } else {
        if ((temp | (xxi << 1)) == 0) {

          xxi = 0;
          return __int_as_float(xxi);
        }

        yyi = xxi & 0x80000000;
        do {
          xxi = (xxi << 1) | (temp >> 31);
          temp <<= 1;
          expo_x--;
        } while (!(xxi & 0x00800000));
        xxi = xxi | yyi;
      }
    } else {

      temp = 32 - expo_y;
      temp = (expo_y) ? (yyi << temp) : 0;
      xxi = xxi + (yyi >> expo_y);
      if (!(xxi & 0x01000000)) {
        if (expo_x <= 0xFD) {
          xxi = xxi + (expo_x << 23);
          xxi += (temp && !(xxi & 0x80000000));
          return __int_as_float(xxi);
        }
      } else {

        temp = (xxi << 31) | (temp >> 1);
        xxi = ((xxi & 0x80000000) | (xxi >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
    if (expo_x <= 0xFD) {
      xxi += (temp && !(xxi & 0x80000000));
      xxi = xxi + (expo_x << 23);
      return __int_as_float(xxi);
    }
    if ((int)expo_x >= 254) {

      temp = xxi & 0x80000000;
      xxi = (temp ? 0xff7fffff : 0x7F800000);
      return __int_as_float(xxi);
    }

    yyi = xxi & 0x80000000;
    xxi = xxi & ~0xff000000;
    expo_x = (unsigned int)(-((int)expo_x));
    xxi = (xxi >> expo_x);
    if ((expo_x > 25) || (xxi != 0x00800000)) xxi = 0;
    return __int_as_float(yyi | xxi);
  } else {
    return a + b;
  }
}

static float __fadd_rd (float a, float b)
{
  unsigned int expo_x, expo_y;
  unsigned int xxi, yyi, temp;

  xxi = __float_as_int(a);
  yyi = __float_as_int(b);


  expo_y = yyi << 1;
  if (expo_y > (xxi << 1)) {
    expo_y = xxi;
    xxi = yyi;
    yyi = expo_y;
  }

  temp = 0xff;
  expo_x = temp & (xxi >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yyi >> 23);
  expo_y = expo_y - 1;

  if ((expo_x <= 0xFD) &&
      (expo_y <= 0xFD)) {

    expo_y = expo_x - expo_y;
    if (expo_y > 25) {
      expo_y = 31;
    }
    temp = xxi ^ yyi;
    xxi = xxi & ~0x7f000000;
    xxi = xxi | 0x00800000;
    yyi = yyi & ~0xff000000;
    yyi = yyi | 0x00800000;

    if ((int)temp < 0) {

      temp = 32 - expo_y;
      temp = (expo_y) ? (yyi << temp) : 0;
      temp = (unsigned int)(-((int)temp));
      xxi = xxi - (yyi >> expo_y) - (temp ? 1 : 0);
      if (xxi & 0x00800000) {
        if (expo_x <= 0xFD) {
          xxi = xxi & ~0x00800000;
          xxi = (xxi + (expo_x << 23)) + 0x00800000;
          xxi += (temp && (xxi & 0x80000000));
          return __int_as_float(xxi);
        }
      } else {
        if ((temp | (xxi << 1)) == 0) {

          xxi = 0x80000000;
          return __int_as_float(xxi);
        }

        yyi = xxi & 0x80000000;
        do {
          xxi = (xxi << 1) | (temp >> 31);
          temp <<= 1;
          expo_x--;
        } while (!(xxi & 0x00800000));
        xxi = xxi | yyi;
      }
    } else {

      temp = 32 - expo_y;
      temp = (expo_y) ? (yyi << temp) : 0;
      xxi = xxi + (yyi >> expo_y);
      if (!(xxi & 0x01000000)) {
        if (expo_x <= 0xFD) {
          expo_y = xxi & 1;
          xxi = xxi + (expo_x << 23);
          xxi += (temp && (xxi & 0x80000000));
          return __int_as_float(xxi);
        }
      } else {

        temp = (xxi << 31) | (temp >> 1);
        xxi = ((xxi & 0x80000000) | (xxi >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
    if (expo_x <= 0xFD) {
      xxi += (temp && (xxi & 0x80000000));
      xxi = xxi + (expo_x << 23);
      return __int_as_float(xxi);
    }
    if ((int)expo_x >= 254) {

      temp = xxi & 0x80000000;
      xxi = (temp ? 0xFF800000 : 0x7f7fffff);
      return __int_as_float(xxi);
    }

    yyi = xxi & 0x80000000;
    xxi = xxi & ~0xff000000;
    expo_x = (unsigned int)(-((int)expo_x));
    xxi = (xxi >> expo_x);
    if ((expo_x > 25) || (xxi != 0x00800000)) xxi = 0;
    return __int_as_float(yyi | xxi);
  } else {
    a = a + b;
    xxi = xxi ^ yyi;
    if ((a == 0.0f) && ((int)xxi < 0)) a = __int_as_float(0x80000000);
    return a;
  }
}

static float __fmul_ru (float a, float b)
{
  unsigned long long product;
  unsigned int expo_x, expo_y;
  unsigned int xxi, yyi;

  xxi = __float_as_int(a);
  yyi = __float_as_int(b);

  expo_y = 0xFF;
  expo_x = expo_y & (xxi >> 23);
  expo_x = expo_x - 1;
  expo_y = expo_y & (yyi >> 23);
  expo_y = expo_y - 1;

  if ((expo_x <= 0xFD) &&
      (expo_y <= 0xFD)) {
    expo_x = expo_x + expo_y;
    expo_y = xxi ^ yyi;
    xxi = xxi & 0x00ffffff;
    yyi = yyi << 8;
    xxi = xxi | 0x00800000;
    yyi = yyi | 0x80000000;

    product = ((unsigned long long)xxi) * yyi;
    expo_x = expo_x - 127 + 2;
    expo_y = expo_y & 0x80000000;
    xxi = (unsigned int)(product >> 32);
    yyi = (unsigned int)(product & 0xffffffff);

    if (xxi < 0x00800000) {
      xxi = (xxi << 1) | (yyi >> 31);
      yyi = (yyi << 1);
      expo_x--;
    }
    if (expo_x <= 0xFD) {
      xxi = xxi | expo_y;
      xxi = xxi + (expo_x << 23);

      xxi += (yyi && !expo_y);
      return __int_as_float(xxi);
    } else if ((int)expo_x >= 254) {

      xxi = (expo_y ? 0xff7fffff : 0x7F800000);
      return __int_as_float(xxi);
    } else {

      expo_x = ((unsigned int)-((int)expo_x));
      xxi += (yyi && !expo_y);
      xxi = (xxi >> expo_x);
      if ((expo_x > 25) || (xxi != 0x00800000)) xxi = 0;
      return __int_as_float(expo_y | xxi);
    }
  } else {
    return a * b;
  }
}

static float __fmul_rd (float a, float b)
{
  unsigned long long product;
  unsigned int expo_x, expo_y;
  unsigned int xxi, yyi;

  xxi = __float_as_int(a);
  yyi = __float_as_int(b);

  expo_y = 0xFF;
  expo_x = expo_y & (xxi >> 23);
  expo_x = expo_x - 1;
  expo_y = expo_y & (yyi >> 23);
  expo_y = expo_y - 1;

  if ((expo_x <= 0xFD) &&
      (expo_y <= 0xFD)) {
    expo_x = expo_x + expo_y;
    expo_y = xxi ^ yyi;
    xxi = xxi & 0x00ffffff;
    yyi = yyi << 8;
    xxi = xxi | 0x00800000;
    yyi = yyi | 0x80000000;

    product = ((unsigned long long)xxi) * yyi;
    expo_x = expo_x - 127 + 2;
    expo_y = expo_y & 0x80000000;
    xxi = (unsigned int)(product >> 32);
    yyi = (unsigned int)(product & 0xffffffff);

    if (xxi < 0x00800000) {
      xxi = (xxi << 1) | (yyi >> 31);
      yyi = (yyi << 1);
      expo_x--;
    }
    if (expo_x <= 0xFD) {
      xxi = xxi | expo_y;
      xxi = xxi + (expo_x << 23);

      xxi += (yyi && expo_y);
      return __int_as_float(xxi);
    } else if ((int)expo_x >= 254) {

      xxi = expo_y | (expo_y ?0x7F800000 : 0x7f7fffff);
      return __int_as_float(xxi);
    } else {

      expo_x = ((unsigned int)-((int)expo_x));
      xxi += (yyi && expo_y);
      xxi = (xxi >> expo_x);
      if ((expo_x > 25) || (xxi != 0x00800000)) xxi = 0;
      return __int_as_float(expo_y | xxi);
    }
  } else {
    return a * b;
  }
}

static float __fmaf_rn (float a, float b, float c)
{
  unsigned long long product;
  unsigned int xx, yy, zz, ww;
  unsigned int temp, s, u;
  unsigned int expo_x, expo_y, expo_z;

  xx = __float_as_int(a);
  yy = __float_as_int(b);
  zz = __float_as_int(c);


  if ((xx << 1) < 0x01000000) xx &= 0x80000000;
  if ((yy << 1) < 0x01000000) yy &= 0x80000000;
  if ((zz << 1) < 0x01000000) zz &= 0x80000000;

  temp = 0xff;
  expo_x = temp & (xx >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yy >> 23);
  expo_y = expo_y - 1;
  expo_z = temp & (zz >> 23);
  expo_z = expo_z - 1;

  if (!((expo_x <= 0xFD) &&
        (expo_y <= 0xFD) &&
        (expo_z <= 0xFD))) {




    if ((yy << 1) > 0xff000000) {
      return rsqrtf(b);
    }
    if ((zz << 1) > 0xff000000) {
      return rsqrtf(c);
    }
    if ((xx << 1) > 0xff000000) {
      return rsqrtf(a);
    }
# 1356 "/usr/local/cuda/bin/../include/device_functions.h" 3
    if ((((xx << 1) == 0) && ((yy << 1) == 0xff000000)) ||
        (((yy << 1) == 0) && ((xx << 1) == 0xff000000))) {
      return rsqrtf(__int_as_float(0xffc00000));
    }
    if ((zz << 1) == 0xff000000) {
      if (((yy << 1) == 0xff000000) || ((xx << 1) == 0xff000000)) {
        if ((int)(xx ^ yy ^ zz) < 0) {
          return rsqrtf(__int_as_float(0xffc00000));
        }
      }
    }




    if ((xx << 1) == 0xff000000) {
      xx = xx ^ (yy & 0x80000000);
      return __int_as_float(xx);
    }
    if ((yy << 1) == 0xff000000) {
      yy = yy ^ (xx & 0x80000000);
      return __int_as_float(yy);
    }
    if ((zz << 1) == 0xff000000) {
      return __int_as_float(zz);
    }





    if (zz == 0x80000000) {
      if (((xx << 1) == 0) || ((yy << 1) == 0)) {
        if ((int)(xx ^ yy) < 0) {
          return __int_as_float(zz);
        }
      }
    }



    if (((zz << 1) == 0) &&
        (((xx << 1) == 0) || ((yy << 1) == 0))) {
      zz &= 0x7fffffff;
      return __int_as_float(zz);
    }



    if (((xx << 1) == 0) || ((yy << 1) == 0)) {
      return __int_as_float(zz);
    }

    if (expo_x == (unsigned)-1) {
      temp = xx & 0x80000000;
      xx = xx << 8;
      while (!(xx & 0x80000000)) {
        xx <<= 1;
        expo_x--;
      }
      expo_x++;
      xx = (xx >> 8) | temp;
    }

    if (expo_y == (unsigned)-1) {
      temp = yy & 0x80000000;
      yy = yy << 8;
      while (!(yy & 0x80000000)) {
        yy <<= 1;
        expo_y--;
      }
      expo_y++;
      yy = (yy >> 8) | temp;
    }

    if ((expo_z == (unsigned)-1) && ((zz << 1) != 0)) {
      temp = zz & 0x80000000;
      zz = zz << 8;
      while (!(zz & 0x80000000)) {
        zz <<= 1;
        expo_z--;
      }
      expo_z++;
      zz = (zz >> 8) | temp;
    }
  }

  expo_x = expo_x + expo_y;
  expo_y = xx ^ yy;
  xx = xx & 0x00ffffff;
  yy = yy << 8;
  xx = xx | 0x00800000;
  yy = yy | 0x80000000;

  product = ((unsigned long long)xx) * yy;
  xx = (unsigned)(product >> 32);
  yy = (unsigned)(product & 0xffffffff);

  expo_x = expo_x - 127 + 2;
  expo_y = expo_y & 0x80000000;

  if (xx < 0x00800000) {
    xx = (xx << 1) | (yy >> 31);
    yy = (yy << 1);
    expo_x--;
  }
  temp = 0;

  if ((zz << 1) != 0) {
    s = zz & 0x80000000;
    zz &= 0x00ffffff;
    zz |= 0x00800000;
    ww = 0;

    if ((int)expo_z > (int)expo_x) {
      temp = expo_z;
      expo_z = expo_x;
      expo_x = temp;
      temp = zz;
      zz = xx;
      xx = temp;
      temp = ww;
      ww = yy;
      yy = temp;
      temp = expo_y;
      expo_y = s;
      s = temp;
    }


    expo_z = expo_x - expo_z;
    u = expo_y ^ s;
    if (expo_z <= 49) {

      temp = 0;
      while (expo_z >= 32) {
        temp = ww | (temp != 0);
        ww = zz;
        zz = 0;
        expo_z -= 32;
      }
      if (expo_z) {
        temp = ((temp >> expo_z) | (ww << (32 - expo_z)) |
                ((temp << (32 - expo_z)) != 0));
        ww = (ww >> expo_z) | (zz << (32 - expo_z));
        zz = (zz >> expo_z);
      }

    } else {
      temp = 1;
      ww = 0;
      zz = 0;
    }
    if ((int)u < 0) {

      temp = (unsigned)(-(int)temp);
      s = (temp != 0);
      u = yy - s;
      s = u > yy;
      yy = u - ww;
      s += yy > u;
      xx = (xx - zz) - s;
      if (!(xx | yy | temp)) {

        return __int_as_float(xx);
      }
      if ((int)xx < 0) {


        temp = ~temp;
        yy = ~yy;
        xx = ~xx;
        if (++temp == 0) {
          if (++yy == 0) {
            ++xx;
          }
        }
        expo_y ^= 0x80000000;
      }

      while (!(xx & 0x00800000)) {
        xx = (xx << 1) | (yy >> 31);
        yy = (yy << 1);
        expo_x--;
      }
    } else {

      yy = yy + ww;
      s = yy < ww;
      xx = xx + zz + s;
      if (xx & 0x01000000) {
        temp = temp | (yy << 31);
        yy = (yy >> 1) | (xx << 31);
        xx = ((xx & 0x80000000) | (xx >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
  }
  temp = yy | (temp != 0);
  if (expo_x <= 0xFD) {

    xx |= expo_y;
    s = xx & 1;
    xx += (temp == 0x80000000) ? s : (temp >> 31);
    xx = xx + (expo_x << 23);
    return __int_as_float(xx);
  } else if ((int)expo_x >= 126) {

    xx = expo_y | 0x7f800000;
    return __int_as_float(xx);
  }

  expo_x = (unsigned int)(-(int)expo_x);

  xx += (temp >= 0x80000000);
  if (xx >= 0x01000000) {
    xx = xx >> 1;
    expo_x--;
  }
  if (expo_x > 0) xx = 0;
  xx = expo_y | xx;
  return __int_as_float(xx);
}

static float __fmaf_rz (float a, float b, float c)
{
  unsigned long long product;
  unsigned int xx, yy, zz, ww;
  unsigned int temp, s, u;
  unsigned int expo_x, expo_y, expo_z;

  xx = __float_as_int(a);
  yy = __float_as_int(b);
  zz = __float_as_int(c);


  if ((xx << 1) < 0x01000000) xx &= 0x80000000;
  if ((yy << 1) < 0x01000000) yy &= 0x80000000;
  if ((zz << 1) < 0x01000000) zz &= 0x80000000;

  temp = 0xff;
  expo_x = temp & (xx >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yy >> 23);
  expo_y = expo_y - 1;
  expo_z = temp & (zz >> 23);
  expo_z = expo_z - 1;

  if (!((expo_x <= 0xFD) &&
        (expo_y <= 0xFD) &&
        (expo_z <= 0xFD))) {




    if ((yy << 1) > 0xff000000) {
      return rsqrtf(b);
    }
    if ((zz << 1) > 0xff000000) {
      return rsqrtf(c);
    }
    if ((xx << 1) > 0xff000000) {
      return rsqrtf(a);
    }
# 1631 "/usr/local/cuda/bin/../include/device_functions.h" 3
    if ((((xx << 1) == 0) && ((yy << 1) == 0xff000000)) ||
        (((yy << 1) == 0) && ((xx << 1) == 0xff000000))) {
      return rsqrtf(__int_as_float(0xffc00000));
    }
    if ((zz << 1) == 0xff000000) {
      if (((yy << 1) == 0xff000000) || ((xx << 1) == 0xff000000)) {
        if ((int)(xx ^ yy ^ zz) < 0) {
          return rsqrtf(__int_as_float(0xffc00000));
        }
      }
    }




    if ((xx << 1) == 0xff000000) {
      xx = xx ^ (yy & 0x80000000);
      return __int_as_float(xx);
    }
    if ((yy << 1) == 0xff000000) {
      yy = yy ^ (xx & 0x80000000);
      return __int_as_float(yy);
    }
    if ((zz << 1) == 0xff000000) {
      return __int_as_float(zz);
    }





    if (zz == 0x80000000) {
      if (((xx << 1) == 0) || ((yy << 1) == 0)) {
        if ((int)(xx ^ yy) < 0) {
          return __int_as_float(zz);
        }
      }
    }



    if (((zz << 1) == 0) &&
        (((xx << 1) == 0) || ((yy << 1) == 0))) {
      zz &= 0x7fffffff;
      return __int_as_float(zz);
    }



    if (((xx << 1) == 0) || ((yy << 1) == 0)) {
      return __int_as_float(zz);
    }

    if (expo_x == (unsigned)-1) {
      temp = xx & 0x80000000;
      xx = xx << 8;
      while (!(xx & 0x80000000)) {
        xx <<= 1;
        expo_x--;
      }
      expo_x++;
      xx = (xx >> 8) | temp;
    }

    if (expo_y == (unsigned)-1) {
      temp = yy & 0x80000000;
      yy = yy << 8;
      while (!(yy & 0x80000000)) {
        yy <<= 1;
        expo_y--;
      }
      expo_y++;
      yy = (yy >> 8) | temp;
    }

    if ((expo_z == (unsigned)-1) && ((zz << 1) != 0)) {
      temp = zz & 0x80000000;
      zz = zz << 8;
      while (!(zz & 0x80000000)) {
        zz <<= 1;
        expo_z--;
      }
      expo_z++;
      zz = (zz >> 8) | temp;
    }
  }

  expo_x = expo_x + expo_y;
  expo_y = xx ^ yy;
  xx = xx & 0x00ffffff;
  yy = yy << 8;
  xx = xx | 0x00800000;
  yy = yy | 0x80000000;

  product = ((unsigned long long)xx) * yy;
  xx = (unsigned)(product >> 32);
  yy = (unsigned)(product & 0xffffffff);

  expo_x = expo_x - 127 + 2;
  expo_y = expo_y & 0x80000000;

  if (xx < 0x00800000) {
    xx = (xx << 1) | (yy >> 31);
    yy = (yy << 1);
    expo_x--;
  }
  temp = 0;

  if ((zz << 1) != 0) {
    s = zz & 0x80000000;
    zz &= 0x00ffffff;
    zz |= 0x00800000;
    ww = 0;

    if ((int)expo_z > (int)expo_x) {
      temp = expo_z;
      expo_z = expo_x;
      expo_x = temp;
      temp = zz;
      zz = xx;
      xx = temp;
      temp = ww;
      ww = yy;
      yy = temp;
      temp = expo_y;
      expo_y = s;
      s = temp;
    }


    expo_z = expo_x - expo_z;
    u = expo_y ^ s;
    if (expo_z <= 49) {

      temp = 0;
      while (expo_z >= 32) {
        temp = ww | (temp != 0);
        ww = zz;
        zz = 0;
        expo_z -= 32;
      }
      if (expo_z) {
        temp = ((temp >> expo_z) | (ww << (32 - expo_z)) |
                ((temp << (32 - expo_z)) != 0));
        ww = (ww >> expo_z) | (zz << (32 - expo_z));
        zz = (zz >> expo_z);
      }

    } else {
      temp = 1;
      ww = 0;
      zz = 0;
    }
    if ((int)u < 0) {

      temp = (unsigned)(-(int)temp);
      s = (temp != 0);
      u = yy - s;
      s = u > yy;
      yy = u - ww;
      s += yy > u;
      xx = (xx - zz) - s;
      if (!(xx | yy | temp)) {

        return __int_as_float(xx);
      }
      if ((int)xx < 0) {


        temp = ~temp;
        yy = ~yy;
        xx = ~xx;
        if (++temp == 0) {
          if (++yy == 0) {
            ++xx;
          }
        }
        expo_y ^= 0x80000000;
      }

      while (!(xx & 0x00800000)) {
        xx = (xx << 1) | (yy >> 31);
        yy = (yy << 1);
        expo_x--;
      }
    } else {

      yy = yy + ww;
      s = yy < ww;
      xx = xx + zz + s;
      if (xx & 0x01000000) {
        temp = temp | (yy << 31);
        yy = (yy >> 1) | (xx << 31);
        xx = ((xx & 0x80000000) | (xx >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
  }
  temp = yy | (temp != 0);
  if (expo_x <= 0xFD) {

    xx |= expo_y;
    xx = xx + (expo_x << 23);
    return __int_as_float(xx);
  } else if ((int)expo_x >= 126) {

    xx = expo_y | 0x7f7fffff;
    return __int_as_float(xx);
  }

  return __int_as_float(expo_y);
}

static float __fmaf_ru (float a, float b, float c)
{
  unsigned long long product;
  unsigned int xx, yy, zz, ww;
  unsigned int temp, s, u;
  unsigned int expo_x, expo_y, expo_z;

  xx = __float_as_int(a);
  yy = __float_as_int(b);
  zz = __float_as_int(c);


  if ((xx << 1) < 0x01000000) xx &= 0x80000000;
  if ((yy << 1) < 0x01000000) yy &= 0x80000000;
  if ((zz << 1) < 0x01000000) zz &= 0x80000000;

  temp = 0xff;
  expo_x = temp & (xx >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yy >> 23);
  expo_y = expo_y - 1;
  expo_z = temp & (zz >> 23);
  expo_z = expo_z - 1;

  if (!((expo_x <= 0xFD) &&
        (expo_y <= 0xFD) &&
        (expo_z <= 0xFD))) {




    if ((yy << 1) > 0xff000000) {
      return rsqrtf(b);
    }
    if ((zz << 1) > 0xff000000) {
      return rsqrtf(c);
    }
    if ((xx << 1) > 0xff000000) {
      return rsqrtf(a);
    }
# 1895 "/usr/local/cuda/bin/../include/device_functions.h" 3
    if ((((xx << 1) == 0) && ((yy << 1) == 0xff000000)) ||
        (((yy << 1) == 0) && ((xx << 1) == 0xff000000))) {
      return rsqrtf(__int_as_float(0xffc00000));
    }
    if ((zz << 1) == 0xff000000) {
      if (((yy << 1) == 0xff000000) || ((xx << 1) == 0xff000000)) {
        if ((int)(xx ^ yy ^ zz) < 0) {
          return rsqrtf(__int_as_float(0xffc00000));
        }
      }
    }




    if ((xx << 1) == 0xff000000) {
      xx = xx ^ (yy & 0x80000000);
      return __int_as_float(xx);
    }
    if ((yy << 1) == 0xff000000) {
      yy = yy ^ (xx & 0x80000000);
      return __int_as_float(yy);
    }
    if ((zz << 1) == 0xff000000) {
      return __int_as_float(zz);
    }





    if (zz == 0x80000000) {
      if (((xx << 1) == 0) || ((yy << 1) == 0)) {
        if ((int)(xx ^ yy) < 0) {
          return __int_as_float(zz);
        }
      }
    }



    if (((zz << 1) == 0) &&
        (((xx << 1) == 0) || ((yy << 1) == 0))) {
      zz &= 0x7fffffff;
      return __int_as_float(zz);
    }



    if (((xx << 1) == 0) || ((yy << 1) == 0)) {
      return __int_as_float(zz);
    }

    if (expo_x == (unsigned)-1) {
      temp = xx & 0x80000000;
      xx = xx << 8;
      while (!(xx & 0x80000000)) {
        xx <<= 1;
        expo_x--;
      }
      expo_x++;
      xx = (xx >> 8) | temp;
    }

    if (expo_y == (unsigned)-1) {
      temp = yy & 0x80000000;
      yy = yy << 8;
      while (!(yy & 0x80000000)) {
        yy <<= 1;
        expo_y--;
      }
      expo_y++;
      yy = (yy >> 8) | temp;
    }

    if ((expo_z == (unsigned)-1) && ((zz << 1) != 0)) {
      temp = zz & 0x80000000;
      zz = zz << 8;
      while (!(zz & 0x80000000)) {
        zz <<= 1;
        expo_z--;
      }
      expo_z++;
      zz = (zz >> 8) | temp;
    }
  }

  expo_x = expo_x + expo_y;
  expo_y = xx ^ yy;
  xx = xx & 0x00ffffff;
  yy = yy << 8;
  xx = xx | 0x00800000;
  yy = yy | 0x80000000;

  product = ((unsigned long long)xx) * yy;
  xx = (unsigned)(product >> 32);
  yy = (unsigned)(product & 0xffffffff);

  expo_x = expo_x - 127 + 2;
  expo_y = expo_y & 0x80000000;

  if (xx < 0x00800000) {
    xx = (xx << 1) | (yy >> 31);
    yy = (yy << 1);
    expo_x--;
  }
  temp = 0;

  if ((zz << 1) != 0) {
    s = zz & 0x80000000;
    zz &= 0x00ffffff;
    zz |= 0x00800000;
    ww = 0;

    if ((int)expo_z > (int)expo_x) {
      temp = expo_z;
      expo_z = expo_x;
      expo_x = temp;
      temp = zz;
      zz = xx;
      xx = temp;
      temp = ww;
      ww = yy;
      yy = temp;
      temp = expo_y;
      expo_y = s;
      s = temp;
    }


    expo_z = expo_x - expo_z;
    u = expo_y ^ s;
    if (expo_z <= 49) {

      temp = 0;
      while (expo_z >= 32) {
        temp = ww | (temp != 0);
        ww = zz;
        zz = 0;
        expo_z -= 32;
      }
      if (expo_z) {
        temp = ((temp >> expo_z) | (ww << (32 - expo_z)) |
                ((temp << (32 - expo_z)) != 0));
        ww = (ww >> expo_z) | (zz << (32 - expo_z));
        zz = (zz >> expo_z);
      }

    } else {
      temp = 1;
      ww = 0;
      zz = 0;
    }
    if ((int)u < 0) {

      temp = (unsigned)(-(int)temp);
      s = (temp != 0);
      u = yy - s;
      s = u > yy;
      yy = u - ww;
      s += yy > u;
      xx = (xx - zz) - s;
      if (!(xx | yy | temp)) {

        return __int_as_float(xx);
      }
      if ((int)xx < 0) {


        temp = ~temp;
        yy = ~yy;
        xx = ~xx;
        if (++temp == 0) {
          if (++yy == 0) {
            ++xx;
          }
        }
        expo_y ^= 0x80000000;
      }

      while (!(xx & 0x00800000)) {
        xx = (xx << 1) | (yy >> 31);
        yy = (yy << 1);
        expo_x--;
      }
    } else {

      yy = yy + ww;
      s = yy < ww;
      xx = xx + zz + s;
      if (xx & 0x01000000) {
        temp = temp | (yy << 31);
        yy = (yy >> 1) | (xx << 31);
        xx = ((xx & 0x80000000) | (xx >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
  }
  temp = yy | (temp != 0);
  if (expo_x <= 0xFD) {

    xx |= expo_y;
    xx += (temp && !expo_y);
    xx = xx + (expo_x << 23);
    return __int_as_float(xx);
  } else if ((int)expo_x >= 126) {

    xx = expo_y | (expo_y ? 0x7f7fffff : 0x7F800000);
    return __int_as_float(xx);
  }

  expo_x = ((unsigned int)-((int)expo_x));
  xx += (temp && !expo_y);
  xx = (xx >> expo_x);
  if ((expo_x > 25) || (xx != 0x00800000)) xx = 0;
  return __int_as_float(expo_y | xx);
}

static float __fmaf_rd (float a, float b, float c)
{
  unsigned long long product;
  unsigned int xx, yy, zz, ww;
  unsigned int temp, s, u;
  unsigned int expo_x, expo_y, expo_z;

  xx = __float_as_int(a);
  yy = __float_as_int(b);
  zz = __float_as_int(c);


  if ((xx << 1) < 0x01000000) xx &= 0x80000000;
  if ((yy << 1) < 0x01000000) yy &= 0x80000000;
  if ((zz << 1) < 0x01000000) zz &= 0x80000000;

  temp = 0xff;
  expo_x = temp & (xx >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yy >> 23);
  expo_y = expo_y - 1;
  expo_z = temp & (zz >> 23);
  expo_z = expo_z - 1;

  if (!((expo_x <= 0xFD) &&
        (expo_y <= 0xFD) &&
        (expo_z <= 0xFD))) {




    if ((yy << 1) > 0xff000000) {
      return rsqrtf(b);
    }
    if ((zz << 1) > 0xff000000) {
      return rsqrtf(c);
    }
    if ((xx << 1) > 0xff000000) {
      return rsqrtf(a);
    }
# 2164 "/usr/local/cuda/bin/../include/device_functions.h" 3
    if ((((xx << 1) == 0) && ((yy << 1) == 0xff000000)) ||
        (((yy << 1) == 0) && ((xx << 1) == 0xff000000))) {
      return rsqrtf(__int_as_float(0xffc00000));
    }
    if ((zz << 1) == 0xff000000) {
      if (((yy << 1) == 0xff000000) || ((xx << 1) == 0xff000000)) {
        if ((int)(xx ^ yy ^ zz) < 0) {
          return rsqrtf(__int_as_float(0xffc00000));
        }
      }
    }




    if ((xx << 1) == 0xff000000) {
      xx = xx ^ (yy & 0x80000000);
      return __int_as_float(xx);
    }
    if ((yy << 1) == 0xff000000) {
      yy = yy ^ (xx & 0x80000000);
      return __int_as_float(yy);
    }
    if ((zz << 1) == 0xff000000) {
      return __int_as_float(zz);
    }





    if (zz == 0x80000000) {
      if (((xx << 1) == 0) || ((yy << 1) == 0)) {
        if ((int)(xx ^ yy) < 0) {
          return __int_as_float(zz);
        }
      }
    }



    if (((zz << 1) == 0) &&
        (((xx << 1) == 0) || ((yy << 1) == 0))) {
      zz = (xx ^ yy ^ zz) & 0x80000000;
      return __int_as_float(zz);
    }



    if (((xx << 1) == 0) || ((yy << 1) == 0)) {
      return __int_as_float(zz);
    }

    if (expo_x == (unsigned)-1) {
      temp = xx & 0x80000000;
      xx = xx << 8;
      while (!(xx & 0x80000000)) {
        xx <<= 1;
        expo_x--;
      }
      expo_x++;
      xx = (xx >> 8) | temp;
    }

    if (expo_y == (unsigned)-1) {
      temp = yy & 0x80000000;
      yy = yy << 8;
      while (!(yy & 0x80000000)) {
        yy <<= 1;
        expo_y--;
      }
      expo_y++;
      yy = (yy >> 8) | temp;
    }

    if ((expo_z == (unsigned)-1) && ((zz << 1) != 0)) {
      temp = zz & 0x80000000;
      zz = zz << 8;
      while (!(zz & 0x80000000)) {
        zz <<= 1;
        expo_z--;
      }
      expo_z++;
      zz = (zz >> 8) | temp;
    }
  }

  expo_x = expo_x + expo_y;
  expo_y = xx ^ yy;
  xx = xx & 0x00ffffff;
  yy = yy << 8;
  xx = xx | 0x00800000;
  yy = yy | 0x80000000;

  product = ((unsigned long long)xx) * yy;
  xx = (unsigned)(product >> 32);
  yy = (unsigned)(product & 0xffffffff);

  expo_x = expo_x - 127 + 2;
  expo_y = expo_y & 0x80000000;

  if (xx < 0x00800000) {
    xx = (xx << 1) | (yy >> 31);
    yy = (yy << 1);
    expo_x--;
  }
  temp = 0;

  if ((zz << 1) != 0) {
    s = zz & 0x80000000;
    zz &= 0x00ffffff;
    zz |= 0x00800000;
    ww = 0;

    if ((int)expo_z > (int)expo_x) {
      temp = expo_z;
      expo_z = expo_x;
      expo_x = temp;
      temp = zz;
      zz = xx;
      xx = temp;
      temp = ww;
      ww = yy;
      yy = temp;
      temp = expo_y;
      expo_y = s;
      s = temp;
    }


    expo_z = expo_x - expo_z;
    u = expo_y ^ s;
    if (expo_z <= 49) {

      temp = 0;
      while (expo_z >= 32) {
        temp = ww | (temp != 0);
        ww = zz;
        zz = 0;
        expo_z -= 32;
      }
      if (expo_z) {
        temp = ((temp >> expo_z) | (ww << (32 - expo_z)) |
                ((temp << (32 - expo_z)) != 0));
        ww = (ww >> expo_z) | (zz << (32 - expo_z));
        zz = (zz >> expo_z);
      }

    } else {
      temp = 1;
      ww = 0;
      zz = 0;
    }
    if ((int)u < 0) {

      temp = (unsigned)(-(int)temp);
      s = (temp != 0);
      u = yy - s;
      s = u > yy;
      yy = u - ww;
      s += yy > u;
      xx = (xx - zz) - s;
      if (!(xx | yy | temp)) {

        return __int_as_float(0x80000000);
      }
      if ((int)xx < 0) {


        temp = ~temp;
        yy = ~yy;
        xx = ~xx;
        if (++temp == 0) {
          if (++yy == 0) {
            ++xx;
          }
        }
        expo_y ^= 0x80000000;
      }

      while (!(xx & 0x00800000)) {
        xx = (xx << 1) | (yy >> 31);
        yy = (yy << 1);
        expo_x--;
      }
    } else {

      yy = yy + ww;
      s = yy < ww;
      xx = xx + zz + s;
      if (xx & 0x01000000) {
        temp = temp | (yy << 31);
        yy = (yy >> 1) | (xx << 31);
        xx = ((xx & 0x80000000) | (xx >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
  }
  temp = yy | (temp != 0);
  if (expo_x <= 0xFD) {

    xx |= expo_y;
    xx += (temp && expo_y);
    xx = xx + (expo_x << 23);
    return __int_as_float(xx);
  } else if ((int)expo_x >= 126) {

    xx = expo_y | (expo_y ? 0x7f800000 : 0x7F7FFFFF);
    return __int_as_float(xx);
  }

  expo_x = ((unsigned int)-((int)expo_x));
  xx += (temp && expo_y);
  xx = (xx >> expo_x);
  if ((expo_x > 25) || (xx != 0x00800000)) xx = 0;
  return __int_as_float(expo_y | xx);
}
# 4398 "/usr/local/cuda/bin/../include/device_functions.h" 3
static float __sinf(float a)
{





  return sinf(a);
}

static float __cosf(float a)
{





  return cosf(a);
}

static float __log2f(float a)
{
  return log2f(a);
}







static float __internal_accurate_fdividef(float a, float b)
{
  return a / b;
}

static float __tanf(float a)
{



  return __fdividef (__sinf(a), __cosf(a));

}

static void __sincosf(float a, float *sptr, float *cptr)
{



  *sptr = __sinf(a);
  *cptr = __cosf(a);

}

static float __expf(float a)
{



  return __cuda_exp2f(a * 1.442695041f);

}

static float __exp10f(float a)
{



  return __cuda_exp2f(a * 3.321928094f);

}

static float __log10f(float a)
{



  return 0.301029996f * __log2f(a);

}

static float __logf(float a)
{



  return 0.693147181f * __log2f(a);

}

static float __powf(float a, float b)
{



  return __cuda_exp2f(b * __log2f(a));

}

static float fdividef(float a, float b)
{





  return __internal_accurate_fdividef(a, b);

}

static int __clz(int a)
{
  return (a)?(158-(__float_as_int(__uint2float_rz((unsigned int)a))>>23)):32;
}

static int __clzll(long long int a)
{
  int ahi = ((int)((unsigned long long)a >> 32));
  int alo = ((int)((unsigned long long)a & 0xffffffffULL));
  int res;
  if (ahi) {
    res = 0;
  } else {
    res = 32;
    ahi = alo;
  }
  res = res + __clz(ahi);
  return res;
}

static int __popc(unsigned int a)
{
  a = a - ((a >> 1) & 0x55555555);
  a = (a & 0x33333333) + ((a >> 2) & 0x33333333);
  a = (a + (a >> 4)) & 0x0f0f0f0f;
  a = ((__umul24(a, 0x808080) << 1) + a) >> 24;
  return a;
}

static int __popcll(unsigned long long int a)
{
  unsigned int ahi = ((unsigned int)(a >> 32));
  unsigned int alo = ((unsigned int)(a & 0xffffffffULL));
  alo = alo - ((alo >> 1) & 0x55555555);
  alo = (alo & 0x33333333) + ((alo >> 2) & 0x33333333);
  ahi = ahi - ((ahi >> 1) & 0x55555555);
  ahi = (ahi & 0x33333333) + ((ahi >> 2) & 0x33333333);
  alo = alo + ahi;
  alo = (alo & 0x0f0f0f0f) + ((alo >> 4) & 0x0f0f0f0f);
  alo = ((__umul24(alo, 0x808080) << 1) + alo) >> 24;
  return alo;
}

static unsigned int __brev(unsigned int a)
{
  a = ((a >> 1) & 0x55555555) + ((a & 0x55555555) << 1);
  a = ((a >> 2) & 0x33333333) + ((a & 0x33333333) << 2);
  a = ((a >> 4) & 0x0F0F0F0F) + ((a & 0x0F0F0F0F) << 4);
  a = ((a >> 8) & 0x00FF00FF) + ((a & 0x00FF00FF) << 8);
  a = ( a >> 16 ) + ( a << 16);
  return a;
}

static unsigned long long int __brevll(unsigned long long int a)
{
  unsigned int hi = (unsigned int)(a >> 32);
  unsigned int lo = (unsigned int)(a & 0xffffffffULL);
  unsigned int t;
  t = __brev(lo);
  lo = __brev(hi);
  return ((unsigned long long int)t << 32) + (unsigned long long int)lo;
}

static int __ffs(int a)
{
  return 32 - __clz (a & -a);
}

static int __ffsll(long long int a)
{
  return 64 - __clzll (a & -a);
}
# 4590 "/usr/local/cuda/bin/../include/device_functions.h" 3
static double fdivide(double a, double b)
{
  return (double)fdividef((float)a, (float)b);
}
# 4667 "/usr/local/cuda/bin/../include/device_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h" 1 3
# 4668 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h" 1 3
# 4669 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/sm_13_double_functions.h" 1 3
# 600 "/usr/local/cuda/bin/../include/sm_13_double_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/common_types.h" 1 3
# 37 "/usr/local/cuda/bin/../include/common_types.h" 3
union __cudart_FloatUintCvt {
    float f;
    unsigned int i;
};

union __cudart_FloatIntCvt {
    float f;
    int i;
};

union __cudart_DoubleUlonglongCvt {
    double d;
    unsigned long long int i;
};

union __cudart_DoubleLonglongCvt {
    double d;
    long long int i;
};

union __cudart_DoubleInthiloCvt {
    double d;
    signed int i[2];
};

struct __cudart_UintUint {
    unsigned int lo;
    unsigned int hi;
};
# 601 "/usr/local/cuda/bin/../include/sm_13_double_functions.h" 2 3

static double __internal_fma_kernel(double x, double y, double z, enum cudaRoundMode rndMode)
{



  struct __cudart_UintUint xx, yy, zz, ww;
  unsigned int s, t, u, prod0, prod1, prod2, prod3, expo_x, expo_y, expo_z;

  xx.hi = __double2hiint(x);
  xx.lo = __double2loint(x);
  yy.hi = __double2hiint(y);
  yy.lo = __double2loint(y);
  zz.hi = __double2hiint(z);
  zz.lo = __double2loint(z);

  expo_z = 0x7FF;
  t = xx.hi >> 20;
  expo_x = expo_z & t;
  expo_x = expo_x - 1;
  t = yy.hi >> 20;
  expo_y = expo_z & t;
  expo_y = expo_y - 1;
  t = zz.hi >> 20;
  expo_z = expo_z & t;
  expo_z = expo_z - 1;

  if (!((expo_x <= 0x7FD) &&
        (expo_y <= 0x7FD) &&
        (expo_z <= 0x7FD))) {





    if (((yy.hi << 1) | (yy.lo != 0)) > 0xffe00000) {
      yy.hi |= 0x00080000;
      return __hiloint2double(yy.hi, yy.lo);
    }
    if (((zz.hi << 1) | (zz.lo != 0)) > 0xffe00000) {
      zz.hi |= 0x00080000;
      return __hiloint2double(zz.hi, zz.lo);
    }
    if (((xx.hi << 1) | (xx.lo != 0)) > 0xffe00000) {
      xx.hi |= 0x00080000;
      return __hiloint2double(xx.hi, xx.lo);
    }
# 660 "/usr/local/cuda/bin/../include/sm_13_double_functions.h" 3
    if (((((xx.hi << 1) | xx.lo) == 0) &&
         (((yy.hi << 1) | (yy.lo != 0)) == 0xffe00000)) ||
        ((((yy.hi << 1) | yy.lo) == 0) &&
         (((xx.hi << 1) | (xx.lo != 0)) == 0xffe00000))) {
      xx.hi = 0xfff80000;
      xx.lo = 0x00000000;
      return __hiloint2double(xx.hi, xx.lo);
    }
    if (((zz.hi << 1) | (zz.lo != 0)) == 0xffe00000) {
      if ((((yy.hi << 1) | (yy.lo != 0)) == 0xffe00000) ||
          (((xx.hi << 1) | (xx.lo != 0)) == 0xffe00000)) {
        if ((int)(xx.hi ^ yy.hi ^ zz.hi) < 0) {
          xx.hi = 0xfff80000;
          xx.lo = 0x00000000;
          return __hiloint2double(xx.hi, xx.lo);
        }
      }
    }




    if (((xx.hi << 1) | (xx.lo != 0)) == 0xffe00000) {
      xx.hi = xx.hi ^ (yy.hi & 0x80000000);
      return __hiloint2double(xx.hi, xx.lo);
    }
    if (((yy.hi << 1) | (yy.lo != 0)) == 0xffe00000) {
      yy.hi = yy.hi ^ (xx.hi & 0x80000000);
      return __hiloint2double(yy.hi, yy.lo);
    }
    if (((zz.hi << 1) | (zz.lo != 0)) == 0xffe00000) {
      return __hiloint2double(zz.hi, zz.lo);
    }





    if ((zz.hi == 0x80000000) && (zz.lo == 0)) {
      if ((((xx.hi << 1) | xx.lo) == 0) ||
          (((yy.hi << 1) | yy.lo) == 0)) {
        if ((int)(xx.hi ^ yy.hi) < 0) {
          return __hiloint2double(zz.hi, zz.lo);
        }
      }
    }



    if ((((zz.hi << 1) | zz.lo) == 0) &&
        ((((xx.hi << 1) | xx.lo) == 0) ||
         (((yy.hi << 1) | yy.lo) == 0))) {
      if (rndMode == cudaRoundMinInf) {
        return __hiloint2double((xx.hi ^ yy.hi ^ zz.hi) & 0x80000000, zz.lo);
      } else {
        zz.hi &= 0x7fffffff;
        return __hiloint2double(zz.hi, zz.lo);
      }
    }




    if ((((xx.hi << 1) | xx.lo) == 0) ||
        (((yy.hi << 1) | yy.lo) == 0)) {
      return __hiloint2double(zz.hi, zz.lo);
    }

    if (expo_x == 0xffffffff) {
      expo_x++;
      t = xx.hi & 0x80000000;
      s = xx.lo >> 21;
      xx.lo = xx.lo << 11;
      xx.hi = xx.hi << 11;
      xx.hi = xx.hi | s;
      if (!xx.hi) {
        xx.hi = xx.lo;
        xx.lo = 0;
        expo_x -= 32;
      }
      while ((int)xx.hi > 0) {
        s = xx.lo >> 31;
        xx.lo = xx.lo + xx.lo;
        xx.hi = xx.hi + xx.hi;
        xx.hi = xx.hi | s;
        expo_x--;
      }
      xx.lo = (xx.lo >> 11);
      xx.lo |= (xx.hi << 21);
      xx.hi = (xx.hi >> 11) | t;
    }
    if (expo_y == 0xffffffff) {
      expo_y++;
      t = yy.hi & 0x80000000;
      s = yy.lo >> 21;
      yy.lo = yy.lo << 11;
      yy.hi = yy.hi << 11;
      yy.hi = yy.hi | s;
      if (!yy.hi) {
        yy.hi = yy.lo;
        yy.lo = 0;
        expo_y -= 32;
      }
      while ((int)yy.hi > 0) {
        s = yy.lo >> 31;
        yy.lo = yy.lo + yy.lo;
        yy.hi = yy.hi + yy.hi;
        yy.hi = yy.hi | s;
        expo_y--;
      }
      yy.lo = (yy.lo >> 11);
      yy.lo |= (yy.hi << 21);
      yy.hi = (yy.hi >> 11) | t;
    }
    if (expo_z == 0xffffffff) {
      expo_z++;
      t = zz.hi & 0x80000000;
      s = zz.lo >> 21;
      zz.lo = zz.lo << 11;
      zz.hi = zz.hi << 11;
      zz.hi = zz.hi | s;
      if (!zz.hi) {
        zz.hi = zz.lo;
        zz.lo = 0;
        expo_z -= 32;
      }
      while ((int)zz.hi > 0) {
        s = zz.lo >> 31;
        zz.lo = zz.lo + zz.lo;
        zz.hi = zz.hi + zz.hi;
        zz.hi = zz.hi | s;
        expo_z--;
      }
      zz.lo = (zz.lo >> 11);
      zz.lo |= (zz.hi << 21);
      zz.hi = (zz.hi >> 11) | t;
    }
  }

  expo_x = expo_x + expo_y;
  expo_y = xx.hi ^ yy.hi;
  t = xx.lo >> 21;
  xx.lo = xx.lo << 11;
  xx.hi = xx.hi << 11;
  xx.hi = xx.hi | t;
  yy.hi = yy.hi & 0x000fffff;
  xx.hi = xx.hi | 0x80000000;
  yy.hi = yy.hi | 0x00100000;

  prod0 = xx.lo * yy.lo;
  prod1 = __umulhi (xx.lo, yy.lo);
  prod2 = xx.hi * yy.lo;
  prod3 = xx.lo * yy.hi;
  prod1 += prod2;
  t = prod1 < prod2;
  prod1 += prod3;
  t += prod1 < prod3;
  prod2 = __umulhi (xx.hi, yy.lo);
  prod3 = __umulhi (xx.lo, yy.hi);
  prod2 += prod3;
  s = prod2 < prod3;
  prod3 = xx.hi * yy.hi;
  prod2 += prod3;
  s += prod2 < prod3;
  prod2 += t;
  s += prod2 < t;
  prod3 = __umulhi (xx.hi, yy.hi) + s;

  yy.lo = prod0;
  yy.hi = prod1;
  xx.lo = prod2;
  xx.hi = prod3;
  expo_x = expo_x - (1023 - 2);
  expo_y = expo_y & 0x80000000;

  if (xx.hi < 0x00100000) {
    s = xx.lo >> 31;
    s = (xx.hi << 1) + s;
    xx.hi = s;
    s = yy.hi >> 31;
    s = (xx.lo << 1) + s;
    xx.lo = s;
    s = yy.lo >> 31;
    s = (yy.hi << 1) + s;
    yy.hi = s;
    s = yy.lo << 1;
    yy.lo = s;
    expo_x--;
  }

  t = 0;
  if (((zz.hi << 1) | zz.lo) != 0) {

    s = zz.hi & 0x80000000;

    zz.hi &= 0x000fffff;
    zz.hi |= 0x00100000;
    ww.hi = 0;
    ww.lo = 0;


    if ((int)expo_z > (int)expo_x) {
      t = expo_z;
      expo_z = expo_x;
      expo_x = t;
      t = zz.hi;
      zz.hi = xx.hi;
      xx.hi = t;
      t = zz.lo;
      zz.lo = xx.lo;
      xx.lo = t;
      t = ww.hi;
      ww.hi = yy.hi;
      yy.hi = t;
      t = ww.lo;
      ww.lo = yy.lo;
      yy.lo = t;
      t = expo_y;
      expo_y = s;
      s = t;
    }



    expo_z = expo_x - expo_z;
    u = expo_y ^ s;
    if (expo_z <= 107) {

      t = 0;
      while (expo_z >= 32) {
        t = ww.lo | (t != 0);
        ww.lo = ww.hi;
        ww.hi = zz.lo;
        zz.lo = zz.hi;
        zz.hi = 0;
        expo_z -= 32;
      }
      if (expo_z) {
        t = (t >> expo_z) | (ww.lo << (32 - expo_z)) |
                ((t << (32 - expo_z)) != 0);
        ww.lo = (ww.lo >> expo_z) | (ww.hi << (32 - expo_z));
        ww.hi = (ww.hi >> expo_z) | (zz.lo << (32 - expo_z));
        zz.lo = (zz.lo >> expo_z) | (zz.hi << (32 - expo_z));
        zz.hi = (zz.hi >> expo_z);
      }
    } else {
      t = 1;
      ww.lo = 0;
      ww.hi = 0;
      zz.lo = 0;
      zz.hi = 0;
    }
    if ((int)u < 0) {

      t = (unsigned)(-(int)t);
      s = (t != 0);
      u = yy.lo - s;
      s = u > yy.lo;
      yy.lo = u - ww.lo;
      s += yy.lo > u;
      u = yy.hi - s;
      s = u > yy.hi;
      yy.hi = u - ww.hi;
      s += yy.hi > u;
      u = xx.lo - s;
      s = u > xx.lo;
      xx.lo = u - zz.lo;
      s += xx.lo > u;
      xx.hi = (xx.hi - zz.hi) - s;
      if (!(xx.hi | xx.lo | yy.hi | yy.lo | t)) {

        if (rndMode == cudaRoundMinInf) {
          return __hiloint2double(0x80000000, xx.lo);
        } else {
          return __hiloint2double(xx.hi, xx.lo);
        }
      }
      if ((int)xx.hi < 0) {



        t = ~t;
        yy.lo = ~yy.lo;
        yy.hi = ~yy.hi;
        xx.lo = ~xx.lo;
        xx.hi = ~xx.hi;
        if (++t == 0) {
          if (++yy.lo == 0) {
            if (++yy.hi == 0) {
              if (++xx.lo == 0) {
              ++xx.hi;
              }
            }
          }
        }
        expo_y ^= 0x80000000;
      }


      while (!(xx.hi & 0x00100000)) {
        xx.hi = (xx.hi << 1) | (xx.lo >> 31);
        xx.lo = (xx.lo << 1) | (yy.hi >> 31);
        yy.hi = (yy.hi << 1) | (yy.lo >> 31);
        yy.lo = (yy.lo << 1);
        expo_x--;
      }
    } else {

      yy.lo = yy.lo + ww.lo;
      s = yy.lo < ww.lo;
      yy.hi = yy.hi + s;
      u = yy.hi < s;
      yy.hi = yy.hi + ww.hi;
      u += yy.hi < ww.hi;
      xx.lo = xx.lo + u;
      s = xx.lo < u;
      xx.lo = xx.lo + zz.lo;
      s += xx.lo < zz.lo;
      xx.hi = xx.hi + zz.hi + s;
      if (xx.hi & 0x00200000) {
        t = t | (yy.lo << 31);
        yy.lo = (yy.lo >> 1) | (yy.hi << 31);
        yy.hi = (yy.hi >> 1) | (xx.lo << 31);
        xx.lo = (xx.lo >> 1) | (xx.hi << 31);
        xx.hi = ((xx.hi & 0x80000000) | (xx.hi >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
  }
  t = yy.lo | (t != 0);
  t = yy.hi | (t != 0);

  xx.hi |= expo_y;
  if (expo_x <= 0x7FD) {

    xx.hi = xx.hi & ~0x00100000;
    s = xx.lo & 1;
    u = xx.lo;
    if (rndMode == cudaRoundNearest) {
      xx.lo += (t == 0x80000000) ? s : (t >> 31);
    } else if (((rndMode == cudaRoundPosInf) && t && (!expo_y)) ||
               ((rndMode == cudaRoundMinInf) && t && expo_y)) {
      xx.lo += 1;
    }
    xx.hi += (u > xx.lo);
    xx.hi += ((expo_x + 1) << 20);
    return __hiloint2double(xx.hi, xx.lo);
  } else if ((int)expo_x >= 2046) {

    if ((rndMode == cudaRoundNearest) ||
        ((rndMode == cudaRoundPosInf) && (!expo_y)) ||
        ((rndMode == cudaRoundMinInf) && expo_y)) {
      xx.hi = (xx.hi & 0x80000000) | 0x7ff00000;
      xx.lo = 0;
    } else {
      xx.hi = (xx.hi & 0x80000000) | 0x7fefffff;
      xx.lo = 0xffffffff;
    }
    return __hiloint2double(xx.hi, xx.lo);
  }

  expo_x = (unsigned)(-(int)expo_x);
  if (expo_x > 54) {

    if (((rndMode == cudaRoundPosInf) && (!expo_y)) ||
        ((rndMode == cudaRoundMinInf) && expo_y)) {
      return __hiloint2double(xx.hi & 0x80000000, 1);
    } else {
      return __hiloint2double(xx.hi & 0x80000000, 0);
    }
  }
  yy.hi = xx.hi & 0x80000000;
  xx.hi = xx.hi & ~0xffe00000;
  if (expo_x >= 32) {
    t = xx.lo | (t != 0);
    xx.lo = xx.hi;
    xx.hi = 0;
    expo_x -= 32;
  }
  if (expo_x) {
    t = (t >> expo_x) | (xx.lo << (32 - expo_x)) | (t != 0);
    xx.lo = (xx.lo >> expo_x) | (xx.hi << (32 - expo_x));
    xx.hi = (xx.hi >> expo_x);
  }
  expo_x = xx.lo & 1;
  u = xx.lo;
  if (rndMode == cudaRoundNearest) {
    xx.lo += (t == 0x80000000) ? expo_x : (t >> 31);
  } else if (((rndMode == cudaRoundPosInf) && t && (!expo_y)) ||
             ((rndMode == cudaRoundMinInf) && t && expo_y)) {
    xx.lo += 1;
  }
  xx.hi += (u > xx.lo);
  xx.hi |= yy.hi;
  return __hiloint2double(xx.hi, xx.lo);
}

static double __fma_rn(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundNearest);
}

static double __fma_rd(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundMinInf);
}

static double __fma_ru(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundPosInf);
}

static double __fma_rz(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundZero);
}

static double __dadd_rz(double a, double b)
{
  return __fma_rz(a, 1.0, b);
}

static double __dadd_ru(double a, double b)
{
  return __fma_ru(a, 1.0, b);
}

static double __dadd_rd(double a, double b)
{
  return __fma_rd(a, 1.0, b);
}

static double __dmul_rz(double a, double b)
{
  return __fma_rz(a, b, __hiloint2double(0x80000000, 0x00000000));
}

static double __dmul_ru(double a, double b)
{
  return __fma_ru(a, b, __hiloint2double(0x80000000, 0x00000000));
}

static double __dmul_rd(double a, double b)
{
  return __fma_rd(a, b, 0.0);
}

static double __dadd_rn(double a, double b)
{
  return __fma_rn(a, 1.0, b);
}

static double __dmul_rn(double a, double b)
{
  return __fma_rn(a, b, __hiloint2double(0x80000000, 0x00000000));
}
# 4670 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/texture_fetch_functions.h" 1 3
# 1882 "/usr/local/cuda/bin/../include/texture_fetch_functions.h" 3
extern uint4 __utexfetchi1D(const void*, int4);
extern int4 __itexfetchi1D(const void*, int4);
extern float4 __ftexfetchi1D(const void*, int4);
extern uint4 __utexfetch1D(const void*, float4);
extern int4 __itexfetch1D(const void*, float4);
extern float4 __ftexfetch1D(const void*, float4);
extern uint4 __utexfetch2D(const void*, float4);
extern int4 __itexfetch2D(const void*, float4);
extern float4 __ftexfetch2D(const void*, float4);
extern uint4 __utexfetch3D(const void*, float4);
extern int4 __itexfetch3D(const void*, float4);
extern float4 __ftexfetch3D(const void*, float4);
# 4671 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 997 "/usr/local/cuda/bin/../include/math_functions.h" 2 3


static int __cuda___signbitf(float a)
{
  return (int)((unsigned int)__float_as_int(a) >> 31);
}




static float __cuda_copysignf(float a, float b)
{
  return __int_as_float((__float_as_int(b) & 0x80000000) |
                        (__float_as_int(a) & ~0x80000000));
}
# 1235 "/usr/local/cuda/bin/../include/math_functions.h" 3
static long int __cuda_labs(long int a)
{
  return labs(a);
}

static float __cuda_ceilf(float a)
{
  return ceilf(a);
}

static float __cuda_floorf(float a)
{
  return floorf(a);
}

static float __cuda_sqrtf(float a)
{
  return sqrtf(a);
}

static float __cuda_rsqrtf(float a)
{
  return rsqrtf(a);
}

static float __cuda_truncf(float a)
{
  return truncf(a);
}

static int __cuda_max(int a, int b)
{
  return max(a, b);
}

static int __cuda_min(int a, int b)
{
  return min(a, b);
}

static unsigned int __cuda_umax(unsigned int a, unsigned int b)
{
  return umax(a, b);
}

static unsigned int __cuda_umin(unsigned int a, unsigned int b)
{
  return umin(a, b);
}

static long long int __cuda_llmax(long long int a, long long int b)
{
  return llmax(a, b);
}

static long long int __cuda_llmin(long long int a, long long int b)
{
  return llmin(a, b);
}

static unsigned long long int __cuda_ullmax(unsigned long long int a, unsigned long long int b)
{
  return ullmax(a, b);
}

static unsigned long long int __cuda_ullmin(unsigned long long int a, unsigned long long int b)
{
  return ullmin(a, b);
}

static long long int __cuda_llrintf(float a)
{



  return __float2ll_rn(a);

}

static long int __cuda_lrintf(float a)
{






  return (long int)__float2int_rn(a);


}

static float __cuda_nearbyintf(float a)
{



  return roundf(a);



}

static float __cuda_fmaxf(float a, float b)
{



  return fmaxf(a, b);



}

static float __cuda_fminf(float a, float b)
{



  return fminf(a, b);



}






static int __cuda___finitef(float a)
{
  return __cuda_fabsf(a) < __int_as_float(0x7f800000);
}
# 1379 "/usr/local/cuda/bin/../include/math_functions.h" 3
static int __cuda___isinff(float a)
{
  return __cuda_fabsf(a) == __int_as_float(0x7f800000);
}

static int __cuda___isnanf(float a)
{
  return !(__cuda_fabsf(a) <= __int_as_float(0x7f800000));
}

static float __cuda_nextafterf(float a, float b)
{
  unsigned int ia;
  unsigned int ib;
  ia = __float_as_int(a);
  ib = __float_as_int(b);

  if ((ia << 1) < 0x01000000) ia &= 0x80000000;
  if ((ib << 1) < 0x01000000) ib &= 0x80000000;

  if (__cuda___isnanf(a) || __cuda___isnanf(b)) return a + b;
  if (__int_as_float (ia | ib) == 0.0f) return __int_as_float(ib);

  if (__int_as_float(ia) == 0.0f) {
    return __cuda_copysignf(1.175494351e-38f, b);
  }





  if ((a < b) && (a < 0.0f)) ia--;
  if ((a < b) && (a > 0.0f)) ia++;
  if ((a > b) && (a < 0.0f)) ia++;
  if ((a > b) && (a > 0.0f)) ia--;
  a = __int_as_float(ia);

  if (__cuda_fabsf(a) < 1.175494351e-38f) {
    a = __int_as_float(ia & 0x80000000);
  }

  return a;
}

static float __cuda_nanf(const char *tagp)
{

  return __int_as_float(0x7fffffff);
}

static float __internal_fmad(float a, float b, float c)
{



  return a * b + c;

}


static float __internal_atanhf_kernel(float a_1, float a_2)
{
  float a, a2, t;

  a = a_1 + a_2;
  a2 = a * a;
  t = 1.566305595598990E-001f/64.0f;
  t = __internal_fmad (t, a2, 1.995081856004762E-001f/16.0f);
  t = __internal_fmad (t, a2, 3.333382699617026E-001f/4.0f);
  t = t * a2;
  t = __internal_fmad (t, a, a_2);
  t = t + a_1;
  return t;
}




static float __internal_atanf_kernel(float a)
{
  float t4, t0, t1;

  t4 = a * a;
  t0 = -5.674867153f;
  t0 = __internal_fmad (t4, -0.823362947f, t0);
  t0 = __internal_fmad (t0, t4, -6.565555096f);
  t0 = t0 * t4;
  t0 = t0 * a;
  t1 = t4 + 11.33538818f;
  t1 = __internal_fmad (t1, t4, 28.84246826f);
  t1 = __internal_fmad (t1, t4, 19.69667053f);
  t1 = 1.0f / t1;
  a = __internal_fmad (t0, t1, a);
  return a;
}


static float __internal_tan_kernel(float a)
{
  float a2, s, t;

  a2 = a * a;
  t = __internal_fmad (4.114678393115178E-003f, a2, -8.231194034909670E-001f);
  s = a2 - 2.469348886157666E+000f;
  s = 1.0f / s;
  t = t * s;
  t = t * a2;
  t = __internal_fmad (t, a, a);
  return t;
}

static float __internal_accurate_logf(float a)
{
  float t;
  float z;
  float m;
  int ia;
  ia = __float_as_int(a);

  if ((a > 0.0f) && (a < __int_as_float(0x7f800000))) {
    int e = -127;
# 1509 "/usr/local/cuda/bin/../include/math_functions.h" 3
    m = __int_as_float((ia & 0x807fffff) | 0x3f800000);
    e += ((unsigned)ia >> 23);
    if (m > 1.414213562f) {
      m = m * 0.5f;
      e = e + 1;
    }
    t = m - 1.0f;
    z = m + 1.0f;
    z = __fdividef (t, z);
    z = -t * z;
    z = __internal_atanhf_kernel(t, z);
    z = __internal_fmad ((float)e, 0.693147181f, z);
    return z;
  } else {

    return __logf(a);
  }
}

static float2 __internal_log_ep(float a)
{
  float2 res;
  int expo;
  float m;
  float log_hi, log_lo;
  float t_hi, t_lo;
  float f, g, u, v, q;



  float r, s, e;

  expo = (__float_as_int(a) >> 23) & 0xff;
# 1550 "/usr/local/cuda/bin/../include/math_functions.h" 3
  expo -= 127;
  m = __int_as_float((__float_as_int(a) & 0x807fffff) | 0x3f800000);
  if (m > 1.414213562f) {
    m = m * 0.5f;
    expo = expo + 1;
  }






  f = m - 1.0f;
  g = m + 1.0f;
  g = 1.0f / g;
  u = 2.0f * f * g;
  v = u * u;
  q = 1.49356810919559350E-001f/64.0f;
  q = __internal_fmad (q, v, 1.99887797540072460E-001f/16.0f);
  q = __internal_fmad (q, v, 3.33333880955515580E-001f/4.0f);
  q = q * v;
  q = q * u;
  log_hi = __int_as_float(__float_as_int(u) & 0xfffff000);
  v = __int_as_float(__float_as_int(f) & 0xfffff000);
  u = 2.0f * (f - log_hi);
  f = f - v;
  u = __internal_fmad (-log_hi, v, u);
  u = __internal_fmad (-log_hi, f, u);
  u = g * u;



  r = log_hi + u;
  s = u - (r - log_hi);
  log_hi = r;
  log_lo = s;

  r = log_hi + q;
  s = ((log_hi - r) + q) + log_lo;
  log_hi = e = r + s;
  log_lo = (r - e) + s;


  t_hi = expo * 0.6931457519f;
  t_lo = expo * 1.4286067653e-6f;


  r = t_hi + log_hi;
  s = (((t_hi - r) + log_hi) + log_lo) + t_lo;
  res.y = e = r + s;
  res.x = (r - e) + s;
  return res;
}

static float __internal_accurate_log2f(float a)
{
  return 1.442695041f * __internal_accurate_logf(a);
}




static float2 __internal_dsmul (float2 x, float2 y)
{
    float2 z;



    float up, vp, u1, u2, v1, v2, mh, ml;

    up = x.y * 4097.0f;
    u1 = (x.y - up) + up;
    u2 = x.y - u1;
    vp = y.y * 4097.0f;
    v1 = (y.y - vp) + vp;
    v2 = y.y - v1;
    mh = __fmul_rn(x.y,y.y);
    ml = (((u1 * v1 - mh) + u1 * v2) + u2 * v1) + u2 * v2;
    ml = (__fmul_rn(x.y,y.x) + __fmul_rn(x.x,y.y)) + ml;
    z.y = up = mh + ml;
    z.x = (mh - up) + ml;
    return z;
}


static __attribute__((__constant__)) unsigned int __cudart_i2opi_f [] = {
  0x3c439041,
  0xdb629599,
  0xf534ddc0,
  0xfc2757d1,
  0x4e441529,
  0xa2f9836e,
};


static float __internal_trig_reduction_kernel(float a, int *quadrant)
{
  float j;
  int q;
  if (__cuda_fabsf(a) > 48039.0f) {

    unsigned int ia = __float_as_int(a);
    unsigned int s = ia & 0x80000000;
    unsigned int result[7];
    unsigned int phi, plo;
    unsigned int hi, lo;
    unsigned int e;
    int idx;
    e = ((ia >> 23) & 0xff) - 128;
    ia = (ia << 8) | 0x80000000;

    idx = 4 - (e >> 5);
    hi = 0;

#pragma unroll 1

    for (q = 0; q < 6; q++) {
      plo = __cudart_i2opi_f[q] * ia;
      phi = __umulhi (__cudart_i2opi_f[q], ia);
      lo = hi + plo;
      hi = phi + (lo < plo);
      result[q] = lo;
    }
    result[q] = hi;
    e = e & 31;



    hi = result[idx+2];
    lo = result[idx+1];
    if (e) {
      q = 32 - e;
      hi = (hi << e) + (lo >> q);
      lo = (lo << e) + (result[idx] >> q);
    }
    q = hi >> 30;

    hi = (hi << 2) + (lo >> 30);
    lo = (lo << 2);
    e = (hi + (lo > 0)) > 0x80000000;
    q += e;
    if (s) q = -q;
    if (e) {
      unsigned int t;
      hi = ~hi;
      lo = -(int)lo;
      t = (lo == 0);
      hi += t;
      s = s ^ 0x80000000;
    }
    *quadrant = q;

    e = 0;
    while ((int)hi > 0) {
      hi = (hi << 1) + (lo >> 31);
      lo = (lo << 1);
      e--;
    }
    lo = hi * 0xc90fdaa2;
    hi = __umulhi(hi, 0xc90fdaa2);
    if ((int)hi > 0) {
      hi = (hi << 1) + (lo >> 31);
      lo = (lo << 1);
      e--;
    }
    hi = hi + (lo > 0);
    ia = s | (((e + 126) << 23) + (hi >> 8) + ((hi << 24) >= 0x80000000));
    return __int_as_float(ia);
  }
  q = __float2int_rn (a * 0.636619772f);
  j = (float)q;
  a = __internal_fmad (-j, 1.5703125000000000e+000f, a);




  a = __internal_fmad (-j, 4.8351287841796875e-004f, a);
  a = __internal_fmad (-j, 3.1385570764541626e-007f, a);

  a = __internal_fmad (-j, 6.0771005065061922e-011f, a);
  *quadrant = q;
  return a;
}
# 1743 "/usr/local/cuda/bin/../include/math_functions.h" 3
static float __internal_expf_kernel(float a, float scale)
{
  float j, z;

  j = __cuda_truncf(a * 1.442695041f);
  z = __internal_fmad (j, -0.6931457519f, a);
  z = __internal_fmad (j, -1.4286067653e-6f, z);
  z = z * 1.442695041f;
  z = __cuda_exp2f(z) * __cuda_exp2f(j + scale);
  return z;
}

static float __internal_accurate_expf(float a)
{
  float z;

  z = __internal_expf_kernel(a, 0.0f);
  if (a < -105.0f) z = 0.0f;
  if (a > 105.0f) z = __int_as_float(0x7f800000);
  return z;
}

static float __internal_accurate_exp10f(float a)
{
  float j, z;

  j = __cuda_truncf(a * 3.321928094f);
  z = __internal_fmad (j, -3.0102920532226563e-001f, a);
  z = __internal_fmad (j, -7.9034171557301747e-007f, z);
  z = z * 3.321928094f;
  z = __cuda_exp2f(z) * __cuda_exp2f(j);
  if (a < -46.0f) z = 0.0f;
  if (a > 46.0f) z = __int_as_float(0x7f800000);
  return z;
}

static float __internal_lgammaf_pos(float a)
{
  float sum;
  float s, t;

  if (a == __int_as_float(0x7f800000)) {
    return a;
  }
  if (a >= 3.0f) {
    if (a >= 7.8f) {



      s = 1.0f / a;
      t = s * s;
      sum = 0.77783067e-3f;
      sum = __internal_fmad (sum, t, -0.2777655457e-2f);
      sum = __internal_fmad (sum, t, 0.83333273853e-1f);
      sum = __internal_fmad (sum, s, 0.918938533204672f);
      s = 0.5f * __internal_accurate_logf(a);
      t = a - 0.5f;
      s = s * t;
      t = s - a;
      s = __fadd_rn(s, sum);
      t = t + s;
      return t;
    } else {
      a = a - 3.0f;
      s = -7.488903254816711E+002f;
      s = __internal_fmad (s, a, -1.234974215949363E+004f);
      s = __internal_fmad (s, a, -4.106137688064877E+004f);
      s = __internal_fmad (s, a, -4.831066242492429E+004f);
      s = __internal_fmad (s, a, -1.430333998207429E+005f);
      t = a - 2.592509840117874E+002f;
      t = __internal_fmad (t, a, -1.077717972228532E+004f);
      t = __internal_fmad (t, a, -9.268505031444956E+004f);
      t = __internal_fmad (t, a, -2.063535768623558E+005f);
      t = __fdividef (s, t);
      t = t + a;
      return t;
    }
  } else if (a >= 1.5f) {
    a = a - 2.0f;
    t = 4.959849168282574E-005f;
    t = __internal_fmad (t, a, -2.208948403848352E-004f);
    t = __internal_fmad (t, a, 5.413142447864599E-004f);
    t = __internal_fmad (t, a, -1.204516976842832E-003f);
    t = __internal_fmad (t, a, 2.884251838546602E-003f);
    t = __internal_fmad (t, a, -7.382757963931180E-003f);
    t = __internal_fmad (t, a, 2.058131963026755E-002f);
    t = __internal_fmad (t, a, -6.735248600734503E-002f);
    t = __internal_fmad (t, a, 3.224670187176319E-001f);
    t = __internal_fmad (t, a, 4.227843368636472E-001f);
    t = t * a;
    return t;
  } else if (a >= 0.7f) {
    a = 1.0f - a;
    t = 4.588266515364258E-002f;
    t = __internal_fmad (t, a, 1.037396712740616E-001f);
    t = __internal_fmad (t, a, 1.228036339653591E-001f);
    t = __internal_fmad (t, a, 1.275242157462838E-001f);
    t = __internal_fmad (t, a, 1.432166835245778E-001f);
    t = __internal_fmad (t, a, 1.693435824224152E-001f);
    t = __internal_fmad (t, a, 2.074079329483975E-001f);
    t = __internal_fmad (t, a, 2.705875136435339E-001f);
    t = __internal_fmad (t, a, 4.006854436743395E-001f);
    t = __internal_fmad (t, a, 8.224669796332661E-001f);
    t = __internal_fmad (t, a, 5.772156651487230E-001f);
    t = t * a;
    return t;
  } else {
    t = 3.587515669447039E-003f;
    t = __internal_fmad (t, a, -5.471285428060787E-003f);
    t = __internal_fmad (t, a, -4.462712795343244E-002f);
    t = __internal_fmad (t, a, 1.673177015593242E-001f);
    t = __internal_fmad (t, a, -4.213597883575600E-002f);
    t = __internal_fmad (t, a, -6.558672843439567E-001f);
    t = __internal_fmad (t, a, 5.772153712885004E-001f);
    t = t * a;
    t = __internal_fmad (t, a, a);
    return -__internal_accurate_logf(t);
  }
}


static float __internal_sin_kernel(float x)
{
  float x2, z;

  x2 = x * x;
  z = -1.95152959e-4f;
  z = __internal_fmad (z, x2, 8.33216087e-3f);
  z = __internal_fmad (z, x2, -1.66666546e-1f);
  z = z * x2;
  z = __internal_fmad (z, x, x);
  return z;
}


static float __internal_cos_kernel(float x)
{
  float x2, z;

  x2 = x * x;
  z = 2.44331571e-5f;
  z = __internal_fmad (z, x2, -1.38873163e-3f);
  z = __internal_fmad (z, x2, 4.16666457e-2f);
  z = __internal_fmad (z, x2, -5.00000000e-1f);
  z = __internal_fmad (z, x2, 1.00000000e+0f);
  return z;
}

static float __internal_accurate_sinf(float a)
{
  float z;
  int i;

  if ((__cuda___isinff(a)) || (a == 0.0f)) {
    return __fmul_rn (a, 0.0f);
  }
  z = __internal_trig_reduction_kernel(a, &i);

  if (i & 1) {
    z = __internal_cos_kernel(z);
  } else {
    z = __internal_sin_kernel(z);
  }
  if (i & 2) {
    z = -z;
  }
  return z;
}







static float __cuda_rintf(float a)
{



  return __cuda_nearbyintf(a);

}

static float __cuda_sinf(float a)
{





  return __internal_accurate_sinf(a);

}

static float __cuda_cosf(float a)
{





  float z;
  int i;

  if (__cuda___isinff(a)) {
    return __fadd_rn (a, -a);
  }
  z = __internal_trig_reduction_kernel(a, &i);

  i++;
  if (i & 1) {
    z = __internal_cos_kernel(z);
  } else {
    z = __internal_sin_kernel(z);
  }
  if (i & 2) {
    z = -z;
  }
  return z;

}

static float __cuda_tanf(float a)
{





  float z;
  int i;

  if (__cuda___isinff(a)) {
    return __fadd_rn (a, -a);
  }
  z = __internal_trig_reduction_kernel(a, &i);

  z = __internal_tan_kernel(z);
  if (i & 1) {
    z = - (1.0f / z);
  }
  return z;

}

static float __cuda_log2f(float a)
{





  return __internal_accurate_log2f(a);

}

static float __cuda_expf(float a)
{





  return __internal_accurate_expf(a);

}

static float __cuda_exp10f(float a)
{





  return __internal_accurate_exp10f(a);

}

static float __cuda_coshf(float a)
{
  float z;

  a = __cuda_fabsf(a);
  z = __internal_expf_kernel(a, -2.0f);
  z = __internal_fmad (2.0f, z, __fdividef (0.125f, z));
  if (a >= 90.0f) {
    z = __int_as_float(0x7f800000);
  }
  return z;
}

static float __cuda_sinhf(float a)
{
  float s, z;

  s = a;
  a = __cuda_fabsf(a);
  if (a < 1.0f) {
    float a2 = a * a;

    z = 2.816951222e-6f;
    z = __internal_fmad (z, a2, 1.983615978e-4f);
    z = __internal_fmad (z, a2, 8.333350058e-3f);
    z = __internal_fmad (z, a2, 1.666666650e-1f);
    z = z * a2;
    z = __internal_fmad (z, a, a);
  } else {
    z = __internal_expf_kernel(a, -2.0f);
    z = __internal_fmad (2.0f, z, -__fdividef (0.125f, z));
    if (a >= 90.0f) {
      z = __int_as_float(0x7f800000);
    }
  }
  return __cuda_copysignf(z, s);
}

static float __cuda_tanhf(float a)
{
  float s, t;

  t = __cuda_fabsf(a);
  if (t < 0.55f) {
    float z, z2;
    z = t;
    z2 = z * z;
    t = 1.643758066599993e-2f;
    t = __internal_fmad (t, z2, -5.267181327760551e-2f);
    t = __internal_fmad (t, z2, 1.332072505223051e-1f);
    t = __internal_fmad (t, z2, -3.333294663641083e-1f);
    t = t * z2;
    s = __internal_fmad (t, z, z);
  } else {
    s = 1.0f - __fdividef(2.0f,(__internal_expf_kernel(2.0f * t, 0.0f)+1.0f));
    if (t >= 88.0f) {
      s = 1.0f;
    }
  }
  return __cuda_copysignf(s, a);
}

static float __cuda_atan2f(float a, float b)
{



  float t0, t1, t3, fa, fb;



  fb = __cuda_fabsf(b);
  fa = __cuda_fabsf(a);

  if (fa == 0.0f && fb == 0.0f) {
    t3 = __cuda___signbitf(b) ? 3.141592654f : 0;
  } else if ((fa == __int_as_float(0x7f800000)) && (fb == __int_as_float(0x7f800000))) {
    t3 = __cuda___signbitf(b) ? 2.356194490f : 0.785398163f;
  } else {

    if (fb < fa) {
      t0 = fa;
      t1 = fb;
    } else {
      t0 = fb;
      t1 = fa;
    }
    t3 = __internal_accurate_fdividef(t1, t0);
    t3 = __internal_atanf_kernel(t3);

    if (fa > fb) t3 = 1.570796327f - t3;
    if (b < 0.0f) t3 = 3.141592654f - t3;
  }
  t3 = __cuda_copysignf(t3, a);

  return t3;

}

static float __cuda_atanf(float a)
{
  float t0, t1;


  t0 = __cuda_fabsf(a);
  t1 = t0;
  if (t0 > 1.0f) {
    t1 = 1.0f / t1;
  }

  t1 = __internal_atanf_kernel(t1);

  if (t0 > 1.0f) {
    t1 = 1.570796327f - t1;
  }
  return __cuda_copysignf(t1, a);
}


static float __internal_asinf_kernel(float a)
{
  float t2, t3, t4;

  t2 = a * a;
  t3 = -0.501162291f;
  t3 = __internal_fmad (t3, t2, 0.915201485f);
  t3 = t3 * t2;
  t3 = t3 * a;
  t4 = t2 - 5.478654385f;
  t4 = __internal_fmad (t4, t2, 5.491230488f);
  t4 = 1.0f / t4;
  a = __internal_fmad (t3, t4, a);
  return a;
}

static float __cuda_asinf(float a)
{
  float t0, t1, t2;

  t0 = __cuda_fabsf(a);
  t2 = 1.0f - t0;
  t2 = 0.5f * t2;
  t2 = __cuda_sqrtf(t2);
  t1 = t0 > 0.575f ? t2 : t0;
  t1 = __internal_asinf_kernel(t1);
  t2 = __internal_fmad (-2.0f, t1, 1.570796327f);
  if (t0 > 0.575f) {
    t1 = t2;
  }
  return __cuda_copysignf(t1, a);
}

static float __cuda_acosf(float a)
{
  float t0, t1, t2;

  t0 = __cuda_fabsf(a);
  t2 = 1.0f - t0;
  t2 = 0.5f * t2;
  t2 = __cuda_sqrtf(t2);
  t1 = t0 > 0.575f ? t2 : t0;
  t1 = __internal_asinf_kernel(t1);
  t1 = t0 > 0.575f ? 2.0f * t1 : 1.570796327f - t1;
  if (__cuda___signbitf(a)) {
    t1 = 3.141592654f - t1;
  }
  return t1;
}

static float __cuda_logf(float a)
{





  return __internal_accurate_logf(a);

}

static float __cuda_log10f(float a)
{





  return 0.434294482f * __internal_accurate_logf(a);

}

static float __cuda_log1pf(float a)
{



  float t;




  if (a >= -0.394f && a <= 0.65f) {

    t = a + 2.0f;
    t = __fdividef (a, t);
    t = -a * t;
    t = __internal_atanhf_kernel (a, t);
  } else {
    t = __internal_accurate_logf (1.0f + a);
  }
  return t;

}

static float __cuda_acoshf(float a)
{



  float t;

  t = a - 1.0f;
  if (__cuda_fabsf(t) > 8388608.0f) {

    return 0.693147181f + __internal_accurate_logf(a);
  } else {
    t = t + __cuda_sqrtf(__internal_fmad (a, t, t));
    return __cuda_log1pf(t);
  }

}

static float __cuda_asinhf(float a)
{



  float fa, oofa, t;

  fa = __cuda_fabsf(a);
  if (fa > 8.507059173e37f) {
    t = 0.693147181f + __logf(fa);
  } else {
    oofa = 1.0f / fa;
    t =fa+__fdividef (fa,(oofa+__cuda_sqrtf(__internal_fmad(oofa,oofa,1.0f))));
    t = __cuda_log1pf(t);
  }
  return __cuda_copysignf(t, a);

}

static float __cuda_atanhf(float a)
{



  float fa, t;

  fa = __cuda_fabsf(a);
  t = __fdividef ((2.0f * fa), (1.0f - fa));
  t = 0.5f * __cuda_log1pf(t);
  return __cuda_copysignf(t, a);

}

static float __cuda_expm1f(float a)
{
  float t, z, j, u;

  t = __cuda_rintf (a * 1.442695041f);
  z = __internal_fmad (-t, 0.6931457519f, a);
  z = __internal_fmad (-t, 1.4286067653e-6f, z);

  if (__cuda_fabsf(a) < 0.41f) {
    z = a;
    t = 0.0f;
  }

  j = t;
  if (t == 128.0f) j = j - 1.0f;

  u = 1.38795078474044430E-003f;
  u = __internal_fmad (u, z, 8.38241261853264930E-003f);
  u = __internal_fmad (u, z, 4.16678317762833940E-002f);
  u = __internal_fmad (u, z, 1.66663978874356580E-001f);
  u = __internal_fmad (u, z, 4.99999940395997040E-001f);
  u = u * z;
  u = __internal_fmad (u, z, z);
  if (a == 0.0f) u = a;

  z = __cuda_exp2f (j);
  a = z - 1.0f;
  if (a != 0.0f) u = __internal_fmad (u, z, a);
  if (t == 128.0f) u = u + u;

  if (j > 128.0f) u = __int_as_float(0x7f800000);
  if (j < -25.0f) u = -1.0f;
  return u;
}

static float __cuda_hypotf(float a, float b)
{



  float v, w, t;

  a = __cuda_fabsf(a);
  b = __cuda_fabsf(b);

  if (a > b) {
    v = a;
    w = b;
  } else {
    v = b;
    w = a;
  }
  t = __internal_accurate_fdividef(w, v);
  t = __internal_fmad (t, t, 1.0f);
  t = v * __cuda_sqrtf(t);
  if (v == 0.0f) {
    t = v + w;
  }
  if ((v == __int_as_float(0x7f800000)) || (w == __int_as_float(0x7f800000))) {
    t = __int_as_float(0x7f800000);
  }
  return t;

}

static float __cuda_cbrtf(float a)
{



  float s, t;

  s = __cuda_fabsf(a);
  if ((a == 0.0f) || (s == __int_as_float(0x7f800000))) {
    return a + a;
  }
  t = __cuda_exp2f(0.333333333f * __log2f(s));
  t = t-(t-(__fdividef(s,(t*t))))*0.333333333f;

  if (__cuda___signbitf(a)) {
    t = -t;
  }



  return t;

}

static float __cuda_erff(float a)
{
  float t, r, q;

  t = __cuda_fabsf(a);
  if (t < 1.0f) {
    t = t * t;
    r = -5.58510127926029810E-004f;
    r = __internal_fmad (r, t, 4.90688891415893070E-003f);
    r = __internal_fmad (r, t, -2.67027980930150640E-002f);
    r = __internal_fmad (r, t, 1.12799056505903940E-001f);
    r = __internal_fmad (r, t, -3.76122956138427440E-001f);
    r = __internal_fmad (r, t, 1.12837911712623450E+000f);
    a = a * r;
  } else if (t <= __int_as_float(0x7f800000)) {



    q = __internal_fmad (t, 0.3275911f, 1.0f);
    q = 1.0f / q;
    r = 1.061405429f;
    r = __internal_fmad (r, q, -1.453152027f);
    r = __internal_fmad (r, q, 1.421413741f);
    r = __internal_fmad (r, q, -0.284496736f);
    r = __internal_fmad (r, q, 0.254829592f);
    r = r * q;
    q = __internal_expf_kernel(-a * a, 0.0f);
    r = __internal_fmad (-q, r, 1.0f);
    if (t >= 5.5f) {
      r = 1.0f;
    }
    a = __int_as_float (__float_as_int(r) | (__float_as_int(a) & 0x80000000));
  }
  return a;
}

static float __cuda_erfinvf (float a)
{
  float fa, t;

  fa = fabsf(a);
  if (fa >= 1.0f) {
    t = __cuda_rsqrtf (__int_as_float (0xffc00000));
    if (fa == 1.0f) {
      t = a * __int_as_float(0x7f800000);
    }
  } else if (fa > 0.9375f) {




    float p, q;

    t = __cuda_log1pf(-fa);
    t = __cuda_rsqrtf(-t);
    p = -1.64441567910e-1f;
    p = __internal_fmad (p, t, 6.80544246825e-1f);
    p = __internal_fmad (p, t, -1.12808139162e+0f);
    p = __internal_fmad (p, t, 6.90969348887e-1f);
    p = __internal_fmad (p, t, 1.38271964963e+0f);
    p = __internal_fmad (p, t, 1.55047000312e-1f);
    q = t + 1.38522814199e+0f;
    q = __internal_fmad (q, t, 1.55024849822e-1f);
    q = q * t;
    t = __fdividef (p, q);
    if (a < 0.0f) t = -t;
  } else if (fa > 0.75f) {




    float p, q;

    t = __internal_fmad (a, a, -0.87890625f);
    p = -7.1986748896e+0f;
    p = __internal_fmad (p, t, +1.3411974175e+1f);
    p = __internal_fmad (p, t, -5.1381573203e+0f);
    p = __internal_fmad (p, t, 4.9633374831e-1f);
    q = t -1.1436535838e+1f;
    q = __internal_fmad (q, t, 1.3568885572e+1f);
    q = __internal_fmad (q, t, -4.1747509256e+0f);
    q = __internal_fmad (q, t, 3.5327242323e-1f);
    p = __fdividef (p, q);
    t = a * p;
  } else {
    float a2;

    a2 = a * a;
    t = 6.1046168794766742E-001f;
    t = __internal_fmad (t, a2, -8.9504882462753121E-001f);
    t = __internal_fmad (t, a2, 7.0224162369928511E-001f);
    t = __internal_fmad (t, a2, -1.9993784895823222E-001f);
    t = __internal_fmad (t, a2, 1.1920613463949599E-001f);
    t = __internal_fmad (t, a2, 8.0131492246997685E-002f);
    t = __internal_fmad (t, a2, 1.2793154958377403E-001f);
    t = __internal_fmad (t, a2, 2.3200529172828793E-001f);
    t = __internal_fmad (t, a2, 8.8622695604694379E-001f);
    t = t * a;
  }
  return t;
}

static float __cuda_erfcf(float a)
{



  if (a <= 0.813f) {
    return 1.0f - __cuda_erff(a);
  } else if (a > 10.055f) {
    return 0.0f;
  } else {
    float p;
    float q;
    float h;
    float l;




    p = 1.9997798317768276E-006f;
    p = __internal_fmad (p, a, 5.6410849770777538E-001f);
    p = __internal_fmad (p, a, 2.4579440583231387E+000f);
    p = __internal_fmad (p, a, 4.9763988947448308E+000f);
    p = __internal_fmad (p, a, 4.5767235962336885E+000f);
    q = a + 4.3540863476555538E+000f;
    q = __internal_fmad (q, a, 9.3453217404616584E+000f);
    q = __internal_fmad (q, a, 1.0132282183545772E+001f);
    q = __internal_fmad (q, a, 4.5781789912165518E+000f);

    h = 1.0f / q;
    q = __internal_fmad (-q * h, h, 2.0f * h);
    p = p * q;

    h = __int_as_float(__float_as_int(a) & 0xfffff000);
    l = __fadd_rn (a, -h);
    q = __fmul_rn (-h, h);
    q = __internal_expf_kernel(q, 0.0f);
    a = a + h;
    l = l * a;
    h = __internal_expf_kernel(-l, 0.0f);
    q = q * h;
    p = p * q;
    return p;
  }
}

static float __cuda_erfcinvf (float a)
{
  float t;
  if (a <= 0.0f) {
    t = __int_as_float(0x7fffffff);
    if (a == 0.0f) {
      t = (1.0f - a) * __int_as_float(0x7f800000);
    }
  }
  else if (a >= 0.0625f) {
    t = __cuda_erfinvf (1.0f - a);
  }
  else {
    float p, q;
    t = __cuda_logf(a);
    t = __cuda_rsqrtf(-t);
    p = -1.64441567910e-1f;
    p = __internal_fmad (p, t, 6.80544246825e-1f);
    p = __internal_fmad (p, t, -1.12808139162e+0f);
    p = __internal_fmad (p, t, 6.90969348887e-1f);
    p = __internal_fmad (p, t, 1.38271964963e+0f);
    p = __internal_fmad (p, t, 1.55047000312e-1f);
    q = t + 1.38522814199e+0f;
    q = __internal_fmad (q, t, 1.55024849822e-1f);
    q = q * t;
    t = __fdividef (p, q);
  }
  return t;
}

static float __cuda_lgammaf(float a)
{
  float t;
  float i;
  int quot;
  t = __internal_lgammaf_pos(__cuda_fabsf(a));
  if (a >= 0.0f) return t;
  a = __cuda_fabsf(a);
  i = __cuda_floorf(a);
  if (a == i) return __int_as_float(0x7f800000);
  if (a < 1e-19f) return -__internal_accurate_logf(a);
  i = __cuda_rintf (2.0f * a);
  quot = (int)i;
  i = __internal_fmad (-i, 0.5f, a);
  i = i * 3.141592654f;
  if (quot & 1) {
    i = __internal_cos_kernel(i);
  } else {
    i = __internal_sin_kernel(i);
  }
  i = __cuda_fabsf(i);
  t = 1.144729886f - __internal_accurate_logf(i * a) - t;
  return t;
}

static float __cuda_ldexpf(float a, int b)
{



  float fa = __cuda_fabsf(a);

  if ((fa == 0.0f) || (fa == __int_as_float(0x7f800000)) || (b == 0)) {
    if (!(fa > 0.0f)) a = a + a;
    return a;
  } else if (__cuda_abs(b) < 126) {
    return a * __cuda_exp2f((float)b);
  } else if (__cuda_abs(b) < 252) {
    int bhalf = b / 2;
    return a * __cuda_exp2f((float)bhalf) * __cuda_exp2f((float)(b - bhalf));
  } else {
    int bquarter = b / 4;
    float t = __cuda_exp2f((float)bquarter);
    return a * t * t * t * __cuda_exp2f((float)(b - 3 * bquarter));
  }

}

static float __cuda_scalbnf(float a, int b)
{




  return __cuda_ldexpf(a, b);

}

static float __cuda_scalblnf(float a, long int b)
{



  int t;
  if (b > 2147483647L) {
    t = 2147483647;
  } else if (b < (-2147483647 - 1)) {
    t = (-2147483647 - 1);
  } else {
    t = (int)b;
  }
  return __cuda_scalbnf(a, t);

}

static float __cuda_frexpf(float a, int *b)
{
  float fa = __cuda_fabsf(a);
  unsigned int expo;
  unsigned int denorm;

  if (fa < 1.175494351e-38f) {
    a *= 16777216.0f;
    denorm = 24;
  } else {
    denorm = 0;
  }
  expo = ((__float_as_int(a) >> 23) & 0xff);
  if ((fa == 0.0f) || (expo == 0xff)) {
    expo = 0;
    a = a + a;
  } else {
    expo = expo - denorm - 126;
    a = __int_as_float(((__float_as_int(a) & 0x807fffff) | 0x3f000000));
  }
  *b = expo;
  return a;
}

static float __cuda_modff(float a, float *b)
{



  float t;
  if (__cuda___finitef(a)) {
    t = __cuda_truncf(a);
    *b = t;
    t = a - t;
    return __cuda_copysignf(t, a);
  } else if (__cuda___isinff(a)) {
    t = 0.0f;
    *b = a;
    return __cuda_copysignf(t, a);
  } else {
    *b = a;
    return a;
  }

}

static float __cuda_fmodf(float a, float b)
{



  float orig_a = a;
  float orig_b = b;
  a = __cuda_fabsf(a);
  b = __cuda_fabsf(b);
  if (!((a <= __int_as_float(0x7f800000)) && (b <= __int_as_float(0x7f800000)))) {
    return orig_a + orig_b;
  }
  if ((a == __int_as_float(0x7f800000)) || (b == 0.0f)) {
    return __cuda_rsqrtf (__int_as_float (0xffc00000));
  } else if (a >= b) {
# 2701 "/usr/local/cuda/bin/../include/math_functions.h" 3
    float scaled_b = __int_as_float ((__float_as_int(b) & 0x007fffff) |
                                     (__float_as_int(a) & 0x7f800000));
    if (scaled_b > a) {
      scaled_b *= 0.5f;
    }

    while (scaled_b >= b) {
      if (a >= scaled_b) {
        a -= scaled_b;
      }
      scaled_b *= 0.5f;
    }
    return __cuda_copysignf(a, orig_a);
  } else {
    if (!(a > 0.0f)) orig_a = orig_a + orig_a;
    return orig_a;
  }

}

static float __cuda_remainderf(float a, float b)
{

  float twoa = 0.0f;
  unsigned int quot0 = 0;
  float orig_a = a;
  float orig_b = b;

  a = __cuda_fabsf(a);
  b = __cuda_fabsf(b);
  if (!((a <= __int_as_float(0x7f800000)) && (b <= __int_as_float(0x7f800000)))) {
    return orig_a + orig_b;
  }
  if ((a == __int_as_float(0x7f800000)) || (b == 0.0f)) {
    return __cuda_rsqrtf (__int_as_float (0xffc00000));
  } else if (a >= b) {
# 2748 "/usr/local/cuda/bin/../include/math_functions.h" 3
    float scaled_b = __int_as_float ((__float_as_int(b) & 0x007fffff) |
                                     (__float_as_int(a) & 0x7f800000));
    if (scaled_b > a) {
      scaled_b *= 0.5f;
    }

    if (a == scaled_b) {
      return __int_as_float(__float_as_int(orig_a) & 0x80000000);
    }

    while (scaled_b >= b) {
      quot0 = 0;
      if (a >= scaled_b) {
        twoa = __internal_fmad (a, 2.0f, -scaled_b) - scaled_b;
        a = a - scaled_b;
        quot0 = 1;
      }
      scaled_b *= 0.5f;
    }
  }
# 2776 "/usr/local/cuda/bin/../include/math_functions.h" 3
  if (a >= 1.175494351e-38f) {
    twoa = 2.0f * a;
    if ((twoa > b) || ((twoa == b) && quot0)) {
      a -= b;
      a = __int_as_float(__float_as_int(a) | 0x80000000);
    }
  } else {

    if ((twoa > b) || ((twoa == b) && quot0)) {
      a = 0.5f * __internal_fmad(b, -2.0f, twoa);
      a = __int_as_float(__float_as_int(a) | 0x80000000);
    }
  }

  a = __int_as_float((__float_as_int(orig_a) & 0x80000000)^
                     __float_as_int(a));
  return a;
}

static float __cuda_remquof(float a, float b, int* quo)
{
  float twoa = 0.0f;
  unsigned int quot = 0;
  unsigned int sign;
  float orig_a = a;
  float orig_b = b;


  sign = 0 - (__cuda___signbitf(a) != __cuda___signbitf(b));
  a = __cuda_fabsf(a);
  b = __cuda_fabsf(b);
  if (!((a <= __int_as_float(0x7f800000)) && (b <= __int_as_float(0x7f800000)))) {
    *quo = quot;
    return orig_a + orig_b;
  }
  if ((a == __int_as_float(0x7f800000)) || (b == 0.0f)) {
    *quo = quot;
    return __cuda_rsqrtf (__int_as_float (0xffc00000));
  } else if (a >= b) {
# 2827 "/usr/local/cuda/bin/../include/math_functions.h" 3
    float scaled_b = __int_as_float ((__float_as_int(b) & 0x007fffff) |
                                     (__float_as_int(a) & 0x7f800000));
    if (scaled_b > a) {
      scaled_b *= 0.5f;
    }

    if (a == scaled_b) {
      if (__float_as_int(b) > 0x7e800000) {
          a *= 0.25f;
          b *= 0.25f;
      }
      a = __fdividef(a,b) + 0.5f;
      quot = (a < 8.0f) ? (int)a : 0;
      quot = quot ^ sign;
      quot = quot - sign;
      *quo = quot;
      return __int_as_float(__float_as_int(orig_a) & 0x80000000);
    }

    while (scaled_b >= b) {
      quot <<= 1;
      if (a >= scaled_b) {
        twoa = (2.0f * a - scaled_b) - scaled_b;
        a -= scaled_b;
        quot += 1;
      }
      scaled_b *= 0.5f;
    }
  }
# 2865 "/usr/local/cuda/bin/../include/math_functions.h" 3
  if (a >= 1.175494351e-38f) {
    twoa = 2.0f * a;
    if ((twoa > b) || ((twoa == b) && (quot & 1))) {
      quot++;
      a -= b;
      a = __cuda_copysignf (a, -1.0f);
    }
  } else {

    if ((twoa > b) || ((twoa == b) && (quot & 1))) {
      quot++;
      a = 0.5f * (twoa - 2.0f * b);
      a = __cuda_copysignf (a, -1.0f);
    }
  }

  a = __int_as_float((__float_as_int(orig_a) & 0x80000000)^
                     __float_as_int(a));
  quot = quot & (~((~0)<<3));
  quot = quot ^ sign;
  quot = quot - sign;
  *quo = quot;
  return a;
}

static float __cuda_fmaf(float a, float b, float c)
{
  return __fmaf_rn(a, b, c);
}

static float __internal_accurate_powf(float a, float b)
{
  float2 loga, prod;



  float t;



  loga = __internal_log_ep(a);


  if (__cuda_fabsf(b) > 1.0e34f) b *= 1.220703125e-4f;
  prod.y = b;
  prod.x = 0.0f;
  prod = __internal_dsmul (prod, loga);


  if (__float_as_int(prod.y) == 0x42b17218) {
    prod.y = __int_as_float(__float_as_int(prod.y) - 1);
    prod.x = prod.x + __int_as_float(0x37000000);
  }


  t = __cuda_expf(prod.y);

  if (t != __int_as_float(0x7f800000)) {



    t = __internal_fmad (t, prod.x, t);
  }
  return t;
}

static float __cuda_powif(float a, int b)
{
  unsigned int e = __cuda_abs(b);
  float r = 1.0f;

  while (1) {
    if ((e & 1) != 0) {
      r = r * a;
    }
    e = e >> 1;
    if (e == 0) {
      return b < 0 ? 1.0f / r : r;
    }
    a = a * a;
  }
}

static double __cuda_powi(double a, int b)
{
  unsigned int e = __cuda_abs(b);
  double r = 1.0;

  while (1) {
    if ((e & 1) != 0) {
      r = r * a;
    }
    e = e >> 1;
    if (e == 0) {
      return b < 0 ? 1.0 / r : r;
    }
    a = a * a;
  }
}

static float __cuda_powf(float a, float b)
{





  int bIsOddInteger;
  float t;
  if (a == 1.0f || b == 0.0f) {
    return 1.0f;
  }
  if (__cuda___isnanf(a) || __cuda___isnanf(b)) {
    return a + b;
  }
  if (a == __int_as_float(0x7f800000)) {
    return __cuda___signbitf(b) ? 0.0f : __int_as_float(0x7f800000);
  }
  if (__cuda___isinff(b)) {
    if (a == -1.0f) {
      return 1.0f;
    }
    t = (__cuda_fabsf(a) > 1.0f) ? __int_as_float(0x7f800000) : 0.0f;
    if (b < 0.0f) {
      t = 1.0f / t;
    }
    return t;
  }
  bIsOddInteger = (b - (2.0f * floorf(0.5f * b))) == 1.0f;
  if (a == 0.0f) {
    t = bIsOddInteger ? a : 0.0f;
    if (b < 0.0f) {
      t = 1.0f / t;
    }
    return t;
  }
  if (a == -__int_as_float(0x7f800000)) {
    t = - ((b < 0.0f) ? (1.0f / a) : a);
    if (bIsOddInteger) {
      t = __int_as_float(__float_as_int(t) ^ 0x80000000);
    }
    return t;
  }
  if ((a < 0.0f) && (b != __cuda_truncf(b))) {
    return __cuda_rsqrtf(__int_as_float(0xffc00000));
  }
  t = __cuda_fabsf(a);
  t = __internal_accurate_powf(t, b);
  if ((a < 0.0f) && bIsOddInteger) {
    t = __int_as_float(__float_as_int(t) ^ 0x80000000);
  }
  return t;

}


static float __internal_tgammaf_kernel(float a)
{
  float t;
  t = -1.05767296987211380E-003f;
  t = __internal_fmad (t, a, 7.09279059435508670E-003f);
  t = __internal_fmad (t, a, -9.65347121958557050E-003f);
  t = __internal_fmad (t, a, -4.21736613253687960E-002f);
  t = __internal_fmad (t, a, 1.66542401247154280E-001f);
  t = __internal_fmad (t, a, -4.20043267827838460E-002f);
  t = __internal_fmad (t, a, -6.55878234051332940E-001f);
  t = __internal_fmad (t, a, 5.77215696929794240E-001f);
  t = __internal_fmad (t, a, 1.00000000000000000E+000f);
  return t;
}





static float __cuda_tgammaf(float a)
{
  float s, xx, x=a;
  if (x >= 0.0f) {
    if (x > 36.0f) x = 36.0f;
    s = 1.0f;
    xx = x;
    if (x > 34.03f) {
      xx -= 1.0f;
    }
    while (xx > 1.5f) {
      xx = xx - 1.0f;
      s = s * xx;
    }
    if (x >= 0.5f) {
      xx = xx - 1.0f;
    }
    xx = __internal_tgammaf_kernel(xx);
    if (x < 0.5f) {
      xx = xx * x;
    }
    s = __fdividef(s, xx);
    if (x > 34.03f) {

      xx = x - 1.0f;
      s = s * xx;
    }
    return s;
  } else {
    if (x == __cuda_floorf(x)) {
      x = __int_as_float(0x7fffffff);



    }
    if (x < -41.1f) x = -41.1f;
    xx = x;
    if (x < -34.03f) {
      xx += 6.0f;
    }
    s = xx;
    while (xx < -0.5f) {
      xx = xx + 1.0f;
      s = s * xx;
    }
    xx = __internal_tgammaf_kernel(xx);
    s = s * xx;
    s = 1.0f / s;
    if (x < -34.03f) {
      xx = x;
      xx *= (x + 1.0f);
      xx *= (x + 2.0f);
      xx *= (x + 3.0f);
      xx *= (x + 4.0f);
      xx *= (x + 5.0f);
      xx = 1.0f / xx;
      s = s * xx;
      if ((a < -42.0f) && !(((int)a)&1)) {
        s = __int_as_float(0x80000000);
      }
    }
    return s;
  }
}

static float __cuda_roundf(float a)
{



  float fa = __cuda_fabsf(a);
  float u = __cuda_copysignf (0.5f, a);
  u = __cuda_truncf (a + u);
  if (fa > 8388608.0f) u = a;
  if (fa < 0.5f) u = __cuda_truncf (a);
  return u;

}

static long long int __internal_llroundf_kernel(float a)
{
  unsigned long long int res, t = 0LL;
  int shift;
  unsigned int ia = __float_as_int(a);

  if ((ia << 1) > 0xff000000) return 0x8000000000000000LL;
  if ((int)ia >= 0x5f000000) return 0x7fffffffffffffffLL;
  if (ia >= 0xdf000000) return 0x8000000000000000LL;
  shift = 189 - ((ia >> 23) & 0xff);
  res = ((long long int)(((ia << 8) | 0x80000000) >> 1)) << 32;
  if (shift >= 64) {
    t = res;
    res = 0;
  } else if (shift) {
    t = res << (64 - shift);
    res = res >> shift;
  }
  if (t >= 0x8000000000000000LL) {
    res++;
  }
  if ((int)ia < 0) res = (unsigned long long int)(-(long long int)res);
  return (long long int)res;
}

static long long int __cuda_llroundf(float a)
{



  return __internal_llroundf_kernel(a);

}

static long int __cuda_lroundf(float a)
{
# 3166 "/usr/local/cuda/bin/../include/math_functions.h" 3
  return (long int)(__cuda_roundf(a));


}

static float __cuda_fdimf(float a, float b)
{
  float t;
  t = a - b;
  if (a <= b) {
    t = 0.0f;
  }
  return t;
}

static int __cuda_ilogbf(float a)
{
  unsigned int i;
  int expo;
  a = __cuda_fabsf(a);
  if (a <= 1.175494351e-38f) {

    if (a == 0.0f) {
      expo = -((int)((unsigned int)-1 >> 1))-1;
    } else {
      expo = -126;
      i = __float_as_int(a);
      i = i << 8;
      while ((int)i >= 0) {
        expo--;
        i = i + i;
      }
    }
  } else {
    i = __float_as_int(a);
    expo = ((int)((i >> 23) & 0xff)) - 127;
    if ((i == 0x7f800000)) {
      expo = ((int)((unsigned int)-1 >> 1));
    }
    if ((i > 0x7f800000)) {
      expo = -((int)((unsigned int)-1 >> 1))-1;
    }
  }
  return expo;
}

static float __cuda_logbf(float a)
{



  unsigned int i;
  int expo;
  float res;



  a = __cuda_fabsf(a);
  if (a <= 1.175494351e-38f) {

    if (a == 0.0f) {
      res = -__int_as_float(0x7f800000);
    } else {
      expo = -126;
      i = __float_as_int(a);
      i = i << 8;
      while ((int)i >= 0) {
        expo--;
        i = i + i;
      }
      res = (float)expo;
    }
  } else {
    i = __float_as_int(a);
    expo = ((int)((i >> 23) & 0xff)) - 127;
    res = (float)expo;
    if ((i >= 0x7f800000)) {

      res = a + a;
    }
  }
  return res;

}

static void __cuda_sincosf(float a, float *sptr, float *cptr)
{





  float t, u, s, c;
  int quadrant;
  t = __cuda_fabsf(a);
  if ((t == __int_as_float(0x7f800000)) || (t == 0.0f)) {
    s = __fmul_rn (a, 0.0f);
    c = 1.0f + s;
    *sptr = s;
    *cptr = c;
    return;
  }
  t = __internal_trig_reduction_kernel(a, &quadrant);
  u = __internal_cos_kernel(t);
  t = __internal_sin_kernel(t);
  if (quadrant & 1) {
    s = u;
    c = t;
  } else {
    s = t;
    c = u;
  }
  if (quadrant & 2) {
    s = -s;
  }
  quadrant++;
  if (quadrant & 2) {
    c = -c;
  }
  *sptr = s;
  *cptr = c;

}
# 3863 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx1.h" 1 3
# 45 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx1.h" 3
static double __cuda_fabs(double a)
{
  return (float)__cuda_fabsf((float)a);
}

static double __cuda_fmax(double a, double b)
{
  return (float)__cuda_fmaxf((float)a, (float)b);
}

static double __cuda_fmin(double a, double b)
{
  return (float)__cuda_fminf((float)a, (float)b);
}

static int __cuda___finite(double a)
{
  return __cuda___finitef((float)a);
}

static int __cuda___isinf(double a)
{
  return __cuda___isinff((float)a);
}

static int __cuda___isnan(double a)
{
  return __cuda___isnanf((float)a);
}

static int __cuda___signbit(double a)
{
  return __cuda___signbitf((float)a);
}

static double __cuda_sqrt(double a)
{
  return (double)__cuda_sqrtf((float)a);
}

static double __cuda_rsqrt(double a)
{
  return (double)__cuda_rsqrtf((float)a);
}

static double __cuda_ceil(double a)
{
  return (double)__cuda_ceilf((float)a);
}

static double __cuda_trunc(double a)
{
  return (double)__cuda_truncf((float)a);
}

static double __cuda_floor(double a)
{
  return (double)__cuda_floorf((float)a);
}

static double __cuda_copysign(double a, double b)
{
  return (double)__cuda_copysignf((float)a, (float)b);
}

static double __cuda_sin(double a)
{
  return (double)__cuda_sinf((float)a);
}

static double __cuda_cos(double a)
{
  return (double)__cuda_cosf((float)a);
}

static void __cuda_sincos(double a, double *sptr, double *cptr)
{
  float fs, fc;

  __cuda_sincosf((float)a, &fs, &fc);

  *sptr = (double)fs;
  *cptr = (double)fc;
}

static double __cuda_tan(double a)
{
  return (double)__cuda_tanf((float)a);
}

static double __cuda_exp(double a)
{
  return (double)__cuda_expf((float)a);
}

static double __cuda_exp2(double a)
{
  return (double)__cuda_exp2f((float)a);
}

static double __cuda_exp10(double a)
{
  return (double)__cuda_exp10f((float)a);
}

static double __cuda_expm1(double a)
{
  return (double)__cuda_expm1f((float)a);
}

static double __cuda_cosh(double a)
{
  return (double)__cuda_coshf((float)a);
}

static double __cuda_sinh(double a)
{
  return (double)__cuda_sinhf((float)a);
}

static double __cuda_tanh(double a)
{
  return (double)__cuda_tanhf((float)a);
}

static double __cuda_asin(double a)
{
  return (double)__cuda_asinf((float)a);
}

static double __cuda_acos(double a)
{
  return (double)__cuda_acosf((float)a);
}

static double __cuda_atan(double a)
{
  return (double)__cuda_atanf((float)a);
}

static double __cuda_atan2(double a, double b)
{
  return (double)__cuda_atan2f((float)a, (float)b);
}

static double __cuda_log(double a)
{
  return (double)__cuda_logf((float)a);
}

static double __cuda_log2(double a)
{
  return (double)__cuda_log2f((float)a);
}

static double __cuda_log10(double a)
{
  return (double)__cuda_log10f((float)a);
}

static double __cuda_log1p(double a)
{
  return (double)__cuda_log1pf((float)a);
}

static double __cuda_acosh(double a)
{
  return (double)__cuda_acoshf((float)a);
}

static double __cuda_asinh(double a)
{
  return (double)__cuda_asinhf((float)a);
}

static double __cuda_atanh(double a)
{
  return (double)__cuda_atanhf((float)a);
}

static double __cuda_hypot(double a, double b)
{
  return (double)__cuda_hypotf((float)a, (float)b);
}

static double __cuda_cbrt(double a)
{
  return (double)__cuda_cbrtf((float)a);
}

static double __cuda_erf(double a)
{
  return (double)__cuda_erff((float)a);
}

static double __cuda_erfinv(double a)
{
  return (double)__cuda_erfinvf((float)a);
}

static double __cuda_erfc(double a)
{
  return (double)__cuda_erfcf((float)a);
}

static double __cuda_erfcinv(double a)
{
  return (double)__cuda_erfcinvf((float)a);
}

static double __cuda_lgamma(double a)
{
  return (double)__cuda_lgammaf((float)a);
}

static double __cuda_tgamma(double a)
{
  return (double)__cuda_tgammaf((float)a);
}

static double __cuda_ldexp(double a, int b)
{
  return (double)__cuda_ldexpf((float)a, b);
}

static double __cuda_scalbn(double a, int b)
{
  return (double)__cuda_scalbnf((float)a, b);
}

static double __cuda_scalbln(double a, long b)
{
  return (double)__cuda_scalblnf((float)a, b);
}

static double __cuda_frexp(double a, int *b)
{
  return (double)__cuda_frexpf((float)a, b);
}

static double __cuda_modf(double a, double *b)
{
  float fb;
  float fa = __cuda_modff((float)a, &fb);

  *b = (double)fb;

  return (double)fa;
}

static double __cuda_fmod(double a, double b)
{
  return (double)__cuda_fmodf((float)a, (float)b);
}

static double __cuda_remainder(double a, double b)
{
  return (double)__cuda_remainderf((float)a, (float)b);
}

static double __cuda_remquo(double a, double b, int *c)
{
  return (double)__cuda_remquof((float)a, (float)b, c);
}

static double __cuda_nextafter(double a, double b)
{
  return (double)__cuda_nextafterf((float)a, (float)b);
}

static double __cuda_nan(const char *tagp)
{
  return (double)__cuda_nanf(tagp);
}

static double __cuda_pow(double a, double b)
{
  return (double)__cuda_powf((float)a, (float)b);
}

static double __cuda_round(double a)
{
  return (double)__cuda_roundf((float)a);
}

static long __cuda_lround(double a)
{
  return __cuda_lroundf((float)a);
}

static long long __cuda_llround(double a)
{
  return __cuda_llroundf((float)a);
}

static double __cuda_rint(double a)
{
  return (double)__cuda_rintf((float)a);
}

static long __cuda_lrint(double a)
{
  return __cuda_lrintf((float)a);
}

static long long __cuda_llrint(double a)
{
  return __cuda_llrintf((float)a);
}

static double __cuda_nearbyint(double a)
{
  return (double)__cuda_nearbyintf((float)a);
}

static double __cuda_fdim(double a, double b)
{
  return (double)__cuda_fdimf((float)a, (float)b);
}

static int __cuda_ilogb(double a)
{
  return __cuda_ilogbf((float)a);
}

static double __cuda_logb(double a)
{
  return (double)__cuda_logbf((float)a);
}

static double __cuda_fma(double a, double b, double c)
{
  return (double)__cuda_fmaf((float)a, (float)b, (float)c);
}
# 3864 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 94 "/usr/local/cuda/bin/../include/common_functions.h" 2
# 46 "src/cuda_fi/sad4.cu" 2
# 140 "src/cuda_fi/gpufi_kernel.cu"
static int _Z10GPUFI_EXITP12_gpufi_data_i(
# 140 "src/cuda_fi/gpufi_kernel.cu"
struct _gpufi_data_ *gpufi_dev,
# 140 "src/cuda_fi/gpufi_kernel.cu"
int errno)
# 141 "src/cuda_fi/gpufi_kernel.cu"
{
# 142 "src/cuda_fi/gpufi_kernel.cu"
(gpufi_dev->sdc) = 1;
# 146 "src/cuda_fi/gpufi_kernel.cu"
return 0;
# 147 "src/cuda_fi/gpufi_kernel.cu"
}
# 182 "src/cuda_fi/gpufi_kernel.cu"
static void _Z12GPUFI_KERNELP12_gpufi_data_iiPc(
# 182 "src/cuda_fi/gpufi_kernel.cu"
struct _gpufi_data_ *gpufi_dev,
# 182 "src/cuda_fi/gpufi_kernel.cu"
int begin,
# 182 "src/cuda_fi/gpufi_kernel.cu"
int type,
# 182 "src/cuda_fi/gpufi_kernel.cu"
char *name)
# 183 "src/cuda_fi/gpufi_kernel.cu"
{
# 184 "src/cuda_fi/gpufi_kernel.cu"
if ((((blockIdx.x)) != ((unsigned)(((gpufi_dev->current).blid)))) || (((threadIdx.x)) != ((unsigned)(((gpufi_dev->current).thid)))))
# 184 "src/cuda_fi/gpufi_kernel.cu"
{
# 185 "src/cuda_fi/gpufi_kernel.cu"
return;
# 185 "src/cuda_fi/gpufi_kernel.cu"
}
# 187 "src/cuda_fi/gpufi_kernel.cu"
if (begin == 0)
# 187 "src/cuda_fi/gpufi_kernel.cu"
{
# 189 "src/cuda_fi/gpufi_kernel.cu"
if (((int)(((char *)(&(gpufi_dev->profile).kernel_bitmap))[type])) == 0)
# 189 "src/cuda_fi/gpufi_kernel.cu"
{
# 190 "src/cuda_fi/gpufi_kernel.cu"
(((char *)(&(gpufi_dev->profile).kernel_bitmap))[type]) = ((char)1);
# 190 "src/cuda_fi/gpufi_kernel.cu"
}
# 191 "src/cuda_fi/gpufi_kernel.cu"
(((int *)(&(gpufi_dev->profile).kernel_instance))[type])++;
# 194 "src/cuda_fi/gpufi_kernel.cu"
((gpufi_dev->current).kernel) = type;
# 195 "src/cuda_fi/gpufi_kernel.cu"
((gpufi_dev->current).instance) = ((((int *)(&(gpufi_dev->profile).kernel_instance))[type]) - 1);
# 196 "src/cuda_fi/gpufi_kernel.cu"
((gpufi_dev->current).loop) = (-1);
# 199 "src/cuda_fi/gpufi_kernel.cu"
((gpufi_dev->current).profile_index)++;
# 201 "src/cuda_fi/gpufi_kernel.cu"
((((struct _gpufi_profile_kernel_ *)(&(gpufi_dev->profile).kernel))[((gpufi_dev->current).profile_index)]).state) = ((char)1);
# 202 "src/cuda_fi/gpufi_kernel.cu"
((((struct _gpufi_profile_kernel_ *)(&(gpufi_dev->profile).kernel))[((gpufi_dev->current).profile_index)]).id) = (((gpufi_dev->current).kernel));
# 203 "src/cuda_fi/gpufi_kernel.cu"
((((struct _gpufi_profile_kernel_ *)(&(gpufi_dev->profile).kernel))[((gpufi_dev->current).profile_index)]).instance) = (((gpufi_dev->current).instance));
# 204 "src/cuda_fi/gpufi_kernel.cu"
}
# 205 "src/cuda_fi/gpufi_kernel.cu"
}
# 222 "src/cuda_fi/gpufi_kernel.cu"
static void _Z17GPUFI_KERNEL_LOOPP12_gpufi_data_i(
# 222 "src/cuda_fi/gpufi_kernel.cu"
struct _gpufi_data_ *gpufi_dev,
# 222 "src/cuda_fi/gpufi_kernel.cu"
int begin)
# 223 "src/cuda_fi/gpufi_kernel.cu"
{
# 224 "src/cuda_fi/gpufi_kernel.cu"
if ((((blockIdx.x)) != ((unsigned)(((gpufi_dev->current).blid)))) || (((threadIdx.x)) != ((unsigned)(((gpufi_dev->current).thid)))))
# 224 "src/cuda_fi/gpufi_kernel.cu"
{
# 225 "src/cuda_fi/gpufi_kernel.cu"
return;
# 225 "src/cuda_fi/gpufi_kernel.cu"
}
# 239 "src/cuda_fi/gpufi_kernel.cu"
}
# 242 "src/cuda_fi/gpufi_kernel.cu"
static void _Z22GPUFI_KERNEL_ITERATIONP12_gpufi_data_(
# 242 "src/cuda_fi/gpufi_kernel.cu"
struct _gpufi_data_ *gpufi_dev)
# 243 "src/cuda_fi/gpufi_kernel.cu"
{
# 244 "src/cuda_fi/gpufi_kernel.cu"
if ((((blockIdx.x)) != ((unsigned)(((gpufi_dev->current).blid)))) || (((threadIdx.x)) != ((unsigned)(((gpufi_dev->current).thid)))))
# 244 "src/cuda_fi/gpufi_kernel.cu"
{
# 245 "src/cuda_fi/gpufi_kernel.cu"
return;
# 245 "src/cuda_fi/gpufi_kernel.cu"
}
# 254 "src/cuda_fi/gpufi_kernel.cu"
}
# 273 "src/cuda_fi/gpufi_kernel.cu"
static void _Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(
# 273 "src/cuda_fi/gpufi_kernel.cu"
struct _gpufi_data_ *gpufi_dev,
# 273 "src/cuda_fi/gpufi_kernel.cu"
int varid,
# 273 "src/cuda_fi/gpufi_kernel.cu"
char *name,
# 273 "src/cuda_fi/gpufi_kernel.cu"
int *variable,
# 273 "src/cuda_fi/gpufi_kernel.cu"
int var_type)
# 274 "src/cuda_fi/gpufi_kernel.cu"
{
# 275 "src/cuda_fi/gpufi_kernel.cu"
if ((((blockIdx.x)) != ((unsigned)(((gpufi_dev->current).blid)))) || (((threadIdx.x)) != ((unsigned)(((gpufi_dev->current).thid)))))
# 275 "src/cuda_fi/gpufi_kernel.cu"
{
# 276 "src/cuda_fi/gpufi_kernel.cu"
return;
# 276 "src/cuda_fi/gpufi_kernel.cu"
}
# 278 "src/cuda_fi/gpufi_kernel.cu"
if (((gpufi_dev->fault).disabled))
# 278 "src/cuda_fi/gpufi_kernel.cu"
{
# 279 "src/cuda_fi/gpufi_kernel.cu"
return;
# 279 "src/cuda_fi/gpufi_kernel.cu"
}
# 281 "src/cuda_fi/gpufi_kernel.cu"
if ((((varid == (((gpufi_dev->fault).varid))) && ((((((struct _gpufi_profile_kernel_ *)(&(gpufi_dev->profile).kernel))[((gpufi_dev->current).profile_index)]).id)) == (((gpufi_dev->fault).kernel)))) && ((((((struct _gpufi_profile_kernel_ *)(&(gpufi_dev->profile).kernel))[((gpufi_dev->current).profile_index)]).instance)) == (((gpufi_dev->fault).instance)))) && ((((((struct _gpufi_profile_variable_ *)(((struct _gpufi_profile_variable_ (*)[128])(&(gpufi_dev->profile).variable)) + (((gpufi_dev->current).profile_index))))[varid]).call_count)) == (((gpufi_dev->fault).call))))
# 281 "src/cuda_fi/gpufi_kernel.cu"
{
# 282 "src/cuda_fi/gpufi_kernel.cu"
auto int temp;
# 283 "src/cuda_fi/gpufi_kernel.cu"
((gpufi_dev->fault).disabled) = 1;
# 284 "src/cuda_fi/gpufi_kernel.cu"
((gpufi_dev->fault).injected)++;
# 285 "src/cuda_fi/gpufi_kernel.cu"
if (var_type == 10)
# 285 "src/cuda_fi/gpufi_kernel.cu"
{
# 286 "src/cuda_fi/gpufi_kernel.cu"
(*variable) ^= (((gpufi_dev->fault).mask));
# 287 "src/cuda_fi/gpufi_kernel.cu"
}
# 287 "src/cuda_fi/gpufi_kernel.cu"
else
# 287 "src/cuda_fi/gpufi_kernel.cu"
{
# 288 "src/cuda_fi/gpufi_kernel.cu"
if (((var_type == 40) || (var_type == 30)) || (var_type == 50))
# 290 "src/cuda_fi/gpufi_kernel.cu"
{
# 291 "src/cuda_fi/gpufi_kernel.cu"
temp = ((*variable));
# 292 "src/cuda_fi/gpufi_kernel.cu"
temp ^= (((gpufi_dev->fault).mask));
# 293 "src/cuda_fi/gpufi_kernel.cu"
(*variable) = temp;
# 294 "src/cuda_fi/gpufi_kernel.cu"
}
# 294 "src/cuda_fi/gpufi_kernel.cu"
else
# 294 "src/cuda_fi/gpufi_kernel.cu"
{
# 295 "src/cuda_fi/gpufi_kernel.cu"
if (var_type == 20)
# 295 "src/cuda_fi/gpufi_kernel.cu"
{
# 296 "src/cuda_fi/gpufi_kernel.cu"
(*variable) = (__float2int_rz(((float)(__int_as_float(((int)(((unsigned)(__float_as_int(((float)((*variable)))))) ^ (((gpufi_dev->fault).mask)))))))));
# 297 "src/cuda_fi/gpufi_kernel.cu"
}
# 298 "src/cuda_fi/gpufi_kernel.cu"
else
# 298 "src/cuda_fi/gpufi_kernel.cu"
{
# 299 "src/cuda_fi/gpufi_kernel.cu"
temp = ((*variable));
# 300 "src/cuda_fi/gpufi_kernel.cu"
temp ^= (((gpufi_dev->fault).mask));
# 301 "src/cuda_fi/gpufi_kernel.cu"
(*variable) = temp;
# 303 "src/cuda_fi/gpufi_kernel.cu"
}
# 303 "src/cuda_fi/gpufi_kernel.cu"
}
# 303 "src/cuda_fi/gpufi_kernel.cu"
}
# 310 "src/cuda_fi/gpufi_kernel.cu"
}
# 321 "src/cuda_fi/gpufi_kernel.cu"
}
# 324 "src/cuda_fi/gpufi_kernel.cu"
static void _Z27GPUFI_KERNEL_VARIABLE_FORCEP12_gpufi_data_iPcPi(
# 324 "src/cuda_fi/gpufi_kernel.cu"
struct _gpufi_data_ *gpufi_dev,
# 324 "src/cuda_fi/gpufi_kernel.cu"
int varid,
# 324 "src/cuda_fi/gpufi_kernel.cu"
char *name,
# 324 "src/cuda_fi/gpufi_kernel.cu"
int *variable)
# 325 "src/cuda_fi/gpufi_kernel.cu"
{
# 325 "src/cuda_fi/gpufi_kernel.cu"
# 349 "src/cuda_fi/gpufi_kernel.cu"
}
# 352 "src/cuda_fi/gpufi_kernel.cu"
static void _Z28GPUFI_KERNEL_VARIABLE_STREAMP12_gpufi_data_iPcPiii(
# 352 "src/cuda_fi/gpufi_kernel.cu"
struct _gpufi_data_ *gpufi_dev,
# 352 "src/cuda_fi/gpufi_kernel.cu"
int varid,
# 352 "src/cuda_fi/gpufi_kernel.cu"
char *name,
# 352 "src/cuda_fi/gpufi_kernel.cu"
int *variable,
# 352 "src/cuda_fi/gpufi_kernel.cu"
int length,
# 352 "src/cuda_fi/gpufi_kernel.cu"
int count)
# 353 "src/cuda_fi/gpufi_kernel.cu"
{
# 353 "src/cuda_fi/gpufi_kernel.cu"
# 392 "src/cuda_fi/gpufi_kernel.cu"
}
# 26 "src/cuda_fi/largerBlocks.cu"
__attribute__((__global__)) __attribute__((__used__)) void _Z17larger_sad_calc_8PtiiP12_gpufi_data_(
# 26 "src/cuda_fi/largerBlocks.cu"
__attribute__((__shared__)) unsigned short *const __val_paramblk_sad,
# 26 "src/cuda_fi/largerBlocks.cu"
__attribute__((__shared__)) const int __val_parammb_width,
# 26 "src/cuda_fi/largerBlocks.cu"
__attribute__((__shared__)) const int __val_parammb_height,
# 26 "src/cuda_fi/largerBlocks.cu"
__attribute__((__shared__)) struct _gpufi_data_ *const gpufi_dev){unsigned short *blk_sad = __val_paramblk_sad;int mb_width = __val_parammb_width;int mb_height = __val_parammb_height;
# 26 "src/cuda_fi/largerBlocks.cu"
{
# 27 "src/cuda_fi/largerBlocks.cu"
{
# 38 "src/cuda_fi/largerBlocks.cu"
auto int tx;
# 42 "src/cuda_fi/largerBlocks.cu"
auto int ty;
# 47 "src/cuda_fi/largerBlocks.cu"
auto int mb_x;
# 51 "src/cuda_fi/largerBlocks.cu"
auto int mb_y;
# 56 "src/cuda_fi/largerBlocks.cu"
auto int macroblocks;
# 60 "src/cuda_fi/largerBlocks.cu"
auto int macroblock_index;
# 64 "src/cuda_fi/largerBlocks.cu"
auto int search_pos;
# 68 "src/cuda_fi/largerBlocks.cu"
auto unsigned short *bi;
# 72 "src/cuda_fi/largerBlocks.cu"
auto unsigned short *bo_6;
# 72 "src/cuda_fi/largerBlocks.cu"
auto unsigned short *bo_5;
# 72 "src/cuda_fi/largerBlocks.cu"
auto unsigned short *bo_4;
# 28 "src/cuda_fi/largerBlocks.cu"
_Z12GPUFI_KERNELP12_gpufi_data_iiPc(gpufi_dev, 0, 0, "larger_sad_calc_8");
# 29 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 0, "blk_sad", ((int *)(&blk_sad)), 50);
# 32 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 1, "mb_width", (&mb_width), 10);
# 35 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 2, "mb_height", (&mb_height), 10);
# 38 "src/cuda_fi/largerBlocks.cu"
tx = ((int)(((threadIdx.y)) & 1U));
# 39 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 6, "tx", (&tx), 10);
# 42 "src/cuda_fi/largerBlocks.cu"
ty = ((int)(((threadIdx.y)) >> 1));
# 43 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 7, "ty", (&ty), 10);
# 47 "src/cuda_fi/largerBlocks.cu"
mb_x = ((int)((blockIdx.x)));
# 48 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 8, "mb_x", (&mb_x), 10);
# 51 "src/cuda_fi/largerBlocks.cu"
mb_y = ((int)((blockIdx.y)));
# 52 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 9, "mb_y", (&mb_y), 10);
# 56 "src/cuda_fi/largerBlocks.cu"
macroblocks = (__mul24(mb_width, mb_height));
# 57 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 10, "macroblocks", (&macroblocks), 10);
# 60 "src/cuda_fi/largerBlocks.cu"
macroblock_index = (((__mul24(mb_y, mb_width)) + mb_x) * 1096);
# 61 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 11, "macroblock_index", (&macroblock_index), 10);
# 65 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 12, "search_pos", (&search_pos), 10);
# 69 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 13, "bi", ((int *)(&bi)), 50);
# 73 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 14, "bo_6", ((int *)(&bo_6)), 50);
# 76 "src/cuda_fi/largerBlocks.cu"
bi = ((blk_sad + (((__mul24(macroblocks, 25)) + ((ty * 8) + (tx * 2))) * 1096)) + (macroblock_index * 16));
# 77 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 15, "bi", ((int *)(&bi)), 50);
# 82 "src/cuda_fi/largerBlocks.cu"
bo_6 = ((blk_sad + ((((macroblocks << 4) + macroblocks) + ((ty * 4) + (tx * 2))) * 1096)) + (macroblock_index * 8));
# 83 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 16, "bo_6", ((int *)(&bo_6)), 50);
# 88 "src/cuda_fi/largerBlocks.cu"
if (ty < 100)
# 89 "src/cuda_fi/largerBlocks.cu"
{
# 92 "src/cuda_fi/largerBlocks.cu"
bo_5 = ((blk_sad + ((((macroblocks << 3) + macroblocks) + ((ty * 4) + tx)) * 1096)) + (macroblock_index * 8));
# 93 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 17, "bo_5", ((int *)(&bo_5)), 50);
# 98 "src/cuda_fi/largerBlocks.cu"
bo_4 = ((blk_sad + ((((macroblocks << 2) + macroblocks) + ((ty * 2) + tx)) * 1096)) + (macroblock_index * 4));
# 99 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 18, "bo_4", ((int *)(&bo_4)), 50);
# 102 "src/cuda_fi/largerBlocks.cu"
}
# 104 "src/cuda_fi/largerBlocks.cu"
_Z17GPUFI_KERNEL_LOOPP12_gpufi_data_i(gpufi_dev, 0);
# 107 "src/cuda_fi/largerBlocks.cu"
for (search_pos = ((int)((threadIdx.x))); (search_pos < 545); search_pos += 32)
# 108 "src/cuda_fi/largerBlocks.cu"
{
# 118 "src/cuda_fi/largerBlocks.cu"
auto uint i00;
# 122 "src/cuda_fi/largerBlocks.cu"
auto uint i01;
# 126 "src/cuda_fi/largerBlocks.cu"
auto uint i10;
# 130 "src/cuda_fi/largerBlocks.cu"
auto uint i11;
# 115 "src/cuda_fi/largerBlocks.cu"
_Z22GPUFI_KERNEL_ITERATIONP12_gpufi_data_(gpufi_dev);
# 118 "src/cuda_fi/largerBlocks.cu"
i00 = (((uint *)bi)[search_pos]);
# 119 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 21, "i00", ((int *)(&i00)), 0);
# 122 "src/cuda_fi/largerBlocks.cu"
i01 = (((uint *)bi)[(search_pos + 548)]);
# 123 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 22, "i01", ((int *)(&i01)), 0);
# 126 "src/cuda_fi/largerBlocks.cu"
i10 = (((uint *)bi)[(search_pos + 2192)]);
# 127 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 23, "i10", ((int *)(&i10)), 0);
# 130 "src/cuda_fi/largerBlocks.cu"
i11 = (((uint *)bi)[(search_pos + 2740)]);
# 131 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 24, "i11", ((int *)(&i11)), 0);
# 134 "src/cuda_fi/largerBlocks.cu"
(((uint *)bo_6)[search_pos]) = (i00 + i10);
# 135 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 25, "((uint * )bo_6)[search_pos]", ((int *)(((uint *)bo_6) + search_pos)), 0);
# 138 "src/cuda_fi/largerBlocks.cu"
(((uint *)bo_6)[search_pos + 548]) = (i01 + i11);
# 139 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 26, "((uint * )bo_6)[(search_pos+(1096/2))]", ((int *)(((uint *)bo_6) + (search_pos + 548))), 0);
# 142 "src/cuda_fi/largerBlocks.cu"
(((uint *)bo_5)[search_pos]) = (i00 + i01);
# 143 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 27, "((uint * )bo_5)[search_pos]", ((int *)(((uint *)bo_5) + search_pos)), 0);
# 146 "src/cuda_fi/largerBlocks.cu"
(((uint *)bo_5)[search_pos + 1096]) = (i10 + i11);
# 147 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 28, "((uint * )bo_5)[(search_pos+((2*1096)/2))]", ((int *)(((uint *)bo_5) + (search_pos + 1096))), 0);
# 150 "src/cuda_fi/largerBlocks.cu"
(((uint *)bo_4)[search_pos]) = ((i00 + i01) + (i10 + i11));
# 151 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 29, "((uint * )bo_4)[search_pos]", ((int *)(((uint *)bo_4) + search_pos)), 0);
# 154 "src/cuda_fi/largerBlocks.cu"
}
# 156 "src/cuda_fi/largerBlocks.cu"
_Z17GPUFI_KERNEL_LOOPP12_gpufi_data_i(gpufi_dev, 1);
# 159 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 20, "search_pos", (&search_pos), 10);
# 162 "src/cuda_fi/largerBlocks.cu"
_Z12GPUFI_KERNELP12_gpufi_data_iiPc(gpufi_dev, 1, 0, "larger_sad_calc_8");
# 163 "src/cuda_fi/largerBlocks.cu"
}
# 163 "src/cuda_fi/largerBlocks.cu"
}}
# 165 "src/cuda_fi/largerBlocks.cu"
__attribute__((__global__)) __attribute__((__used__)) void _Z18larger_sad_calc_16PtiiP12_gpufi_data_(
# 165 "src/cuda_fi/largerBlocks.cu"
__attribute__((__shared__)) unsigned short *const __val_paramblk_sad,
# 165 "src/cuda_fi/largerBlocks.cu"
__attribute__((__shared__)) const int __val_parammb_width,
# 165 "src/cuda_fi/largerBlocks.cu"
__attribute__((__shared__)) const int __val_parammb_height,
# 165 "src/cuda_fi/largerBlocks.cu"
__attribute__((__shared__)) struct _gpufi_data_ *const gpufi_dev){unsigned short *blk_sad = __val_paramblk_sad;int mb_width = __val_parammb_width;int mb_height = __val_parammb_height;
# 165 "src/cuda_fi/largerBlocks.cu"
{
# 166 "src/cuda_fi/largerBlocks.cu"
{
# 178 "src/cuda_fi/largerBlocks.cu"
auto int mb_x;
# 182 "src/cuda_fi/largerBlocks.cu"
auto int mb_y;
# 187 "src/cuda_fi/largerBlocks.cu"
auto int macroblocks;
# 191 "src/cuda_fi/largerBlocks.cu"
auto int macroblock_index;
# 195 "src/cuda_fi/largerBlocks.cu"
auto int search_pos;
# 199 "src/cuda_fi/largerBlocks.cu"
auto unsigned short *bi;
# 203 "src/cuda_fi/largerBlocks.cu"
auto unsigned short *bo_3;
# 203 "src/cuda_fi/largerBlocks.cu"
auto unsigned short *bo_2;
# 203 "src/cuda_fi/largerBlocks.cu"
auto unsigned short *bo_1;
# 167 "src/cuda_fi/largerBlocks.cu"
_Z12GPUFI_KERNELP12_gpufi_data_iiPc(gpufi_dev, 0, 1, "larger_sad_calc_16");
# 168 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 3, "blk_sad", ((int *)(&blk_sad)), 50);
# 171 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 4, "mb_width", (&mb_width), 10);
# 174 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 5, "mb_height", (&mb_height), 10);
# 178 "src/cuda_fi/largerBlocks.cu"
mb_x = ((int)((blockIdx.x)));
# 179 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 30, "mb_x", (&mb_x), 10);
# 182 "src/cuda_fi/largerBlocks.cu"
mb_y = ((int)((blockIdx.y)));
# 183 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 31, "mb_y", (&mb_y), 10);
# 187 "src/cuda_fi/largerBlocks.cu"
macroblocks = ((__mul24(mb_width, mb_height)) * 1096);
# 188 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 32, "macroblocks", (&macroblocks), 10);
# 191 "src/cuda_fi/largerBlocks.cu"
macroblock_index = (((__mul24(mb_y, mb_width)) + mb_x) * 1096);
# 192 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 33, "macroblock_index", (&macroblock_index), 10);
# 196 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 34, "search_pos", (&search_pos), 10);
# 200 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 35, "bi", ((int *)(&bi)), 50);
# 204 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 36, "bo_3", ((int *)(&bo_3)), 50);
# 209 "src/cuda_fi/largerBlocks.cu"
bi = ((blk_sad + ((macroblocks + macroblock_index) << 2)) + macroblocks);
# 210 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 37, "bi", ((int *)(&bi)), 50);
# 217 "src/cuda_fi/largerBlocks.cu"
bo_3 = ((blk_sad + ((macroblocks + macroblock_index) << 1)) + macroblocks);
# 218 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 38, "bo_3", ((int *)(&bo_3)), 50);
# 223 "src/cuda_fi/largerBlocks.cu"
bo_2 = ((blk_sad + macroblocks) + (macroblock_index * 2));
# 224 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 39, "bo_2", ((int *)(&bo_2)), 50);
# 229 "src/cuda_fi/largerBlocks.cu"
bo_1 = (blk_sad + macroblock_index);
# 230 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 40, "bo_1", ((int *)(&bo_1)), 50);
# 234 "src/cuda_fi/largerBlocks.cu"
_Z17GPUFI_KERNEL_LOOPP12_gpufi_data_i(gpufi_dev, 0);
# 237 "src/cuda_fi/largerBlocks.cu"
for (search_pos = ((int)((threadIdx.x))); (search_pos < 545); search_pos += 32)
# 238 "src/cuda_fi/largerBlocks.cu"
{
# 248 "src/cuda_fi/largerBlocks.cu"
auto uint i00;
# 252 "src/cuda_fi/largerBlocks.cu"
auto uint i01;
# 256 "src/cuda_fi/largerBlocks.cu"
auto uint i10;
# 260 "src/cuda_fi/largerBlocks.cu"
auto uint i11;
# 245 "src/cuda_fi/largerBlocks.cu"
_Z22GPUFI_KERNEL_ITERATIONP12_gpufi_data_(gpufi_dev);
# 248 "src/cuda_fi/largerBlocks.cu"
i00 = (((uint *)bi)[search_pos]);
# 249 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 43, "i00", ((int *)(&i00)), 0);
# 252 "src/cuda_fi/largerBlocks.cu"
i01 = (((uint *)bi)[(search_pos + 548)]);
# 253 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 44, "i01", ((int *)(&i01)), 0);
# 256 "src/cuda_fi/largerBlocks.cu"
i10 = (((uint *)bi)[(search_pos + 1096)]);
# 257 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 45, "i10", ((int *)(&i10)), 0);
# 260 "src/cuda_fi/largerBlocks.cu"
i11 = (((uint *)bi)[(search_pos + 1644)]);
# 261 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 46, "i11", ((int *)(&i11)), 0);
# 264 "src/cuda_fi/largerBlocks.cu"
(((uint *)bo_3)[search_pos]) = (i00 + i10);
# 265 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 47, "((uint * )bo_3)[search_pos]", ((int *)(((uint *)bo_3) + search_pos)), 0);
# 268 "src/cuda_fi/largerBlocks.cu"
(((uint *)bo_3)[search_pos + 548]) = (i01 + i11);
# 269 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 48, "((uint * )bo_3)[(search_pos+(1096/2))]", ((int *)(((uint *)bo_3) + (search_pos + 548))), 0);
# 272 "src/cuda_fi/largerBlocks.cu"
(((uint *)bo_2)[search_pos]) = (i00 + i01);
# 273 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 49, "((uint * )bo_2)[search_pos]", ((int *)(((uint *)bo_2) + search_pos)), 0);
# 276 "src/cuda_fi/largerBlocks.cu"
(((uint *)bo_2)[search_pos + 548]) = (i10 + i11);
# 277 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 50, "((uint * )bo_2)[(search_pos+(1096/2))]", ((int *)(((uint *)bo_2) + (search_pos + 548))), 0);
# 280 "src/cuda_fi/largerBlocks.cu"
(((uint *)bo_1)[search_pos]) = ((i00 + i01) + (i10 + i11));
# 281 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 51, "((uint * )bo_1)[search_pos]", ((int *)(((uint *)bo_1) + search_pos)), 0);
# 284 "src/cuda_fi/largerBlocks.cu"
}
# 286 "src/cuda_fi/largerBlocks.cu"
_Z17GPUFI_KERNEL_LOOPP12_gpufi_data_i(gpufi_dev, 1);
# 289 "src/cuda_fi/largerBlocks.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 42, "search_pos", (&search_pos), 10);
# 292 "src/cuda_fi/largerBlocks.cu"
_Z12GPUFI_KERNELP12_gpufi_data_iiPc(gpufi_dev, 1, 1, "larger_sad_calc_16");
# 293 "src/cuda_fi/largerBlocks.cu"
}
# 293 "src/cuda_fi/largerBlocks.cu"
}}
# 59 "src/cuda_fi/sad4.cu"
__attribute__((__global__)) __attribute__((__used__)) void _Z11mb_sad_calcPtS_iiP12_gpufi_data_(
# 59 "src/cuda_fi/sad4.cu"
__attribute__((__shared__)) unsigned short *const __val_paramblk_sad,
# 59 "src/cuda_fi/sad4.cu"
__attribute__((__shared__)) unsigned short *const __val_paramframe,
# 59 "src/cuda_fi/sad4.cu"
__attribute__((__shared__)) const int __val_parammb_width,
# 59 "src/cuda_fi/sad4.cu"
__attribute__((__shared__)) const int __val_parammb_height,
# 59 "src/cuda_fi/sad4.cu"
__attribute__((__shared__)) struct _gpufi_data_ *const gpufi_dev){unsigned short *blk_sad = __val_paramblk_sad;unsigned short *frame = __val_paramframe;int mb_width = __val_parammb_width;int mb_height = __val_parammb_height;
# 59 "src/cuda_fi/sad4.cu"
{
# 60 "src/cuda_fi/sad4.cu"
{
# 74 "src/cuda_fi/sad4.cu"
auto int txy_tmp;
# 78 "src/cuda_fi/sad4.cu"
auto int ty;
# 82 "src/cuda_fi/sad4.cu"
auto int tx;
# 86 "src/cuda_fi/sad4.cu"
auto int bx;
# 90 "src/cuda_fi/sad4.cu"
auto int by;
# 95 "src/cuda_fi/sad4.cu"
auto int mb_x;
# 99 "src/cuda_fi/sad4.cu"
auto int mb_y;
# 103 "src/cuda_fi/sad4.cu"
auto int block_x;
# 107 "src/cuda_fi/sad4.cu"
auto int block_y;
# 61 "src/cuda_fi/sad4.cu"
_Z12GPUFI_KERNELP12_gpufi_data_iiPc(gpufi_dev, 0, 0, "mb_sad_calc");
# 62 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 0, "blk_sad", ((int *)(&blk_sad)), 50);
# 65 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 1, "frame", ((int *)(&frame)), 50);
# 68 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 2, "mb_width", (&mb_width), 10);
# 71 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 3, "mb_height", (&mb_height), 10);
# 74 "src/cuda_fi/sad4.cu"
txy_tmp = ((int)(((threadIdx.x)) / 61U));
# 75 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 4, "txy_tmp", (&txy_tmp), 10);
# 78 "src/cuda_fi/sad4.cu"
ty = (txy_tmp / 1);
# 79 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 5, "ty", (&ty), 10);
# 82 "src/cuda_fi/sad4.cu"
tx = ((int)(((unsigned)txy_tmp) - (__umul24(((unsigned)ty), 1U))));
# 83 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 6, "tx", (&tx), 10);
# 86 "src/cuda_fi/sad4.cu"
bx = ((int)((blockIdx.x)));
# 87 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 7, "bx", (&bx), 10);
# 90 "src/cuda_fi/sad4.cu"
by = ((int)((blockIdx.y)));
# 91 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 8, "by", (&by), 10);
# 95 "src/cuda_fi/sad4.cu"
mb_x = ((int)((((unsigned)tx) + (__umul24(((unsigned)bx), 1U))) >> 2));
# 96 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 9, "mb_x", (&mb_x), 10);
# 99 "src/cuda_fi/sad4.cu"
mb_y = ((int)((((unsigned)ty) + (__umul24(((unsigned)by), 1U))) >> 2));
# 100 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 10, "mb_y", (&mb_y), 10);
# 103 "src/cuda_fi/sad4.cu"
block_x = ((int)((((unsigned)tx) + (__umul24(((unsigned)bx), 1U))) & 3U));
# 104 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 11, "block_x", (&block_x), 10);
# 107 "src/cuda_fi/sad4.cu"
block_y = ((int)((((unsigned)ty) + (__umul24(((unsigned)by), 1U))) & 3U));
# 108 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 12, "block_y", (&block_y), 10);
# 115 "src/cuda_fi/sad4.cu"
if ((((threadIdx.x)) >> 4) < 1U)
# 116 "src/cuda_fi/sad4.cu"
{
# 117 "src/cuda_fi/sad4.cu"
auto int ty;
# 121 "src/cuda_fi/sad4.cu"
auto int tx;
# 125 "src/cuda_fi/sad4.cu"
auto int tgroup;
# 130 "src/cuda_fi/sad4.cu"
auto int img_width;
# 135 "src/cuda_fi/sad4.cu"
auto int frame_x;
# 139 "src/cuda_fi/sad4.cu"
auto int frame_y;
# 144 "src/cuda_fi/sad4.cu"
auto int cur_o;
# 117 "src/cuda_fi/sad4.cu"
ty = ((int)((((threadIdx.x)) >> 4) / 1U));
# 118 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 13, "ty", (&ty), 10);
# 121 "src/cuda_fi/sad4.cu"
tx = ((int)((((threadIdx.x)) >> 4) - (__umul24(((unsigned)ty), 1U))));
# 122 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 14, "tx", (&tx), 10);
# 125 "src/cuda_fi/sad4.cu"
tgroup = ((int)(((threadIdx.x)) & 15U));
# 126 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 15, "tgroup", (&tgroup), 10);
# 130 "src/cuda_fi/sad4.cu"
img_width = (mb_width * 16);
# 131 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 16, "img_width", (&img_width), 10);
# 135 "src/cuda_fi/sad4.cu"
frame_x = ((int)((((unsigned)tx) + (__umul24(((unsigned)bx), 1U))) << 2));
# 136 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 17, "frame_x", (&frame_x), 10);
# 139 "src/cuda_fi/sad4.cu"
frame_y = ((int)((((unsigned)ty) + (__umul24(((unsigned)by), 1U))) << 2));
# 140 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 18, "frame_y", (&frame_y), 10);
# 144 "src/cuda_fi/sad4.cu"
cur_o = ((frame_y * img_width) + frame_x);
# 145 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 19, "cur_o", (&cur_o), 10);
# 149 "src/cuda_fi/sad4.cu"
if (((frame_x >> 4) < mb_width) && ((frame_y >> 4) < mb_height))
# 150 "src/cuda_fi/sad4.cu"
{
# 152 "src/cuda_fi/sad4.cu"
(frame_loc[(((__umul24(((unsigned)ty), 1U)) + ((unsigned)tx)) << 4) + ((unsigned)tgroup)]) = (frame[((cur_o + ((tgroup >> 2) * img_width)) + (tgroup & 3))]);
# 153 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 20, "frame_loc[(((__umul24(ty, 1)+tx)<<4)+tgroup)]", ((int *)(frame_loc + ((((__umul24(((unsigned)ty), 1U)) + ((unsigned)tx)) << 4) + ((unsigned)tgroup)))), 0);
# 156 "src/cuda_fi/sad4.cu"
}
# 157 "src/cuda_fi/sad4.cu"
}
# 158 "src/cuda_fi/sad4.cu"
__syncthreads();
# 160 "src/cuda_fi/sad4.cu"
if ((mb_x < mb_width) && (mb_y < mb_height))
# 161 "src/cuda_fi/sad4.cu"
{
# 163 "src/cuda_fi/sad4.cu"
auto int frame_x;
# 167 "src/cuda_fi/sad4.cu"
auto int frame_y;
# 172 "src/cuda_fi/sad4.cu"
auto int ref_x;
# 176 "src/cuda_fi/sad4.cu"
auto int ref_y;
# 181 "src/cuda_fi/sad4.cu"
auto int cur_o;
# 185 "src/cuda_fi/sad4.cu"
auto int search_pos;
# 189 "src/cuda_fi/sad4.cu"
auto int search_pos_base;
# 193 "src/cuda_fi/sad4.cu"
auto int search_pos_end;
# 197 "src/cuda_fi/sad4.cu"
auto int sotmp;
# 201 "src/cuda_fi/sad4.cu"
auto int local_search_off_x;
# 205 "src/cuda_fi/sad4.cu"
auto int search_off_y;
# 163 "src/cuda_fi/sad4.cu"
frame_x = (((mb_x << 2) + block_x) << 2);
# 164 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 21, "frame_x", (&frame_x), 10);
# 167 "src/cuda_fi/sad4.cu"
frame_y = (((mb_y << 2) + block_y) << 2);
# 168 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 22, "frame_y", (&frame_y), 10);
# 172 "src/cuda_fi/sad4.cu"
ref_x = (frame_x - 16);
# 173 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 23, "ref_x", (&ref_x), 10);
# 176 "src/cuda_fi/sad4.cu"
ref_y = (frame_y - 16);
# 177 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 24, "ref_y", (&ref_y), 10);
# 181 "src/cuda_fi/sad4.cu"
cur_o = ((ty * 1) + tx);
# 182 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 25, "cur_o", (&cur_o), 10);
# 186 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 26, "search_pos", (&search_pos), 10);
# 189 "src/cuda_fi/sad4.cu"
search_pos_base = ((int)((((threadIdx.x)) % 61U) * 18U));
# 190 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 27, "search_pos_base", (&search_pos_base), 10);
# 193 "src/cuda_fi/sad4.cu"
search_pos_end = (search_pos_base + 18);
# 194 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 28, "search_pos_end", (&search_pos_end), 10);
# 197 "src/cuda_fi/sad4.cu"
sotmp = (search_pos_base / 33);
# 198 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 29, "sotmp", (&sotmp), 10);
# 201 "src/cuda_fi/sad4.cu"
local_search_off_x = (search_pos_base - ((sotmp << 5) + sotmp));
# 202 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 30, "local_search_off_x", (&local_search_off_x), 10);
# 205 "src/cuda_fi/sad4.cu"
search_off_y = (ref_y + sotmp);
# 206 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 31, "search_off_y", (&search_off_y), 10);
# 210 "src/cuda_fi/sad4.cu"
if (search_pos_end > 1089)
# 211 "src/cuda_fi/sad4.cu"
{
# 212 "src/cuda_fi/sad4.cu"
search_pos_end = 1089;
# 213 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 32, "search_pos_end", (&search_pos_end), 10);
# 216 "src/cuda_fi/sad4.cu"
}
# 219 "src/cuda_fi/sad4.cu"
_Z17GPUFI_KERNEL_LOOPP12_gpufi_data_i(gpufi_dev, 0);
# 222 "src/cuda_fi/sad4.cu"
for (search_pos = search_pos_base; (search_pos < search_pos_end); search_pos += 3)
# 223 "src/cuda_fi/sad4.cu"
{
# 232 "src/cuda_fi/sad4.cu"
auto unsigned short sad1;
# 232 "src/cuda_fi/sad4.cu"
auto unsigned short sad2;
# 232 "src/cuda_fi/sad4.cu"
auto unsigned short sad3;
# 236 "src/cuda_fi/sad4.cu"
auto int search_off_x;
# 241 "src/cuda_fi/sad4.cu"
auto int y;
# 229 "src/cuda_fi/sad4.cu"
_Z22GPUFI_KERNEL_ITERATIONP12_gpufi_data_(gpufi_dev);
# 232 "src/cuda_fi/sad4.cu"
sad1 = ((unsigned short)0U);
# 232 "src/cuda_fi/sad4.cu"
sad2 = ((unsigned short)0U);
# 232 "src/cuda_fi/sad4.cu"
sad3 = ((unsigned short)0U);
# 233 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 35, "sad1", ((int *)(&sad1)), 0);
# 236 "src/cuda_fi/sad4.cu"
search_off_x = (ref_x + local_search_off_x);
# 237 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 36, "search_off_x", (&search_off_x), 10);
# 242 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 37, "y", (&y), 10);
# 275 "src/cuda_fi/sad4.cu"
{
# 275 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T219;
# 276 "src/cuda_fi/sad4.cu"
auto float __T220;
# 277 "src/cuda_fi/sad4.cu"
auto float __T221;
# 278 "src/cuda_fi/sad4.cu"
auto float4 __T222;
# 279 "src/cuda_fi/sad4.cu"
auto uint4 __T223;
# 280 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T224;
# 281 "src/cuda_fi/sad4.cu"
auto float __T225;
# 282 "src/cuda_fi/sad4.cu"
auto float __T226;
# 283 "src/cuda_fi/sad4.cu"
auto float4 __T227;
# 284 "src/cuda_fi/sad4.cu"
auto uint4 __T228;
# 285 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T229;
# 286 "src/cuda_fi/sad4.cu"
auto float __T230;
# 287 "src/cuda_fi/sad4.cu"
auto float __T231;
# 288 "src/cuda_fi/sad4.cu"
auto float4 __T232;
# 289 "src/cuda_fi/sad4.cu"
auto uint4 __T233;
# 290 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T234;
# 291 "src/cuda_fi/sad4.cu"
auto float __T235;
# 292 "src/cuda_fi/sad4.cu"
auto float __T236;
# 293 "src/cuda_fi/sad4.cu"
auto float4 __T237;
# 294 "src/cuda_fi/sad4.cu"
auto uint4 __T238;
# 295 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T239;
# 296 "src/cuda_fi/sad4.cu"
auto float __T240;
# 297 "src/cuda_fi/sad4.cu"
auto float __T241;
# 298 "src/cuda_fi/sad4.cu"
auto float4 __T242;
# 299 "src/cuda_fi/sad4.cu"
auto uint4 __T243;
# 300 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T244;
# 301 "src/cuda_fi/sad4.cu"
auto float __T245;
# 302 "src/cuda_fi/sad4.cu"
auto float __T246;
# 303 "src/cuda_fi/sad4.cu"
auto float4 __T247;
# 304 "src/cuda_fi/sad4.cu"
auto uint4 __T248;
# 305 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T249;
# 306 "src/cuda_fi/sad4.cu"
auto float __T250;
# 307 "src/cuda_fi/sad4.cu"
auto float __T251;
# 308 "src/cuda_fi/sad4.cu"
auto float4 __T252;
# 309 "src/cuda_fi/sad4.cu"
auto uint4 __T253;
# 310 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T254;
# 311 "src/cuda_fi/sad4.cu"
auto float __T255;
# 312 "src/cuda_fi/sad4.cu"
auto float __T256;
# 313 "src/cuda_fi/sad4.cu"
auto float4 __T257;
# 314 "src/cuda_fi/sad4.cu"
auto uint4 __T258;
# 315 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T259;
# 316 "src/cuda_fi/sad4.cu"
auto float __T260;
# 317 "src/cuda_fi/sad4.cu"
auto float __T261;
# 318 "src/cuda_fi/sad4.cu"
auto float4 __T262;
# 319 "src/cuda_fi/sad4.cu"
auto uint4 __T263;
# 320 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T264;
# 321 "src/cuda_fi/sad4.cu"
auto float __T265;
# 322 "src/cuda_fi/sad4.cu"
auto float __T266;
# 323 "src/cuda_fi/sad4.cu"
auto float4 __T267;
# 324 "src/cuda_fi/sad4.cu"
auto uint4 __T268;
# 325 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T269;
# 326 "src/cuda_fi/sad4.cu"
auto float __T270;
# 327 "src/cuda_fi/sad4.cu"
auto float __T271;
# 328 "src/cuda_fi/sad4.cu"
auto float4 __T272;
# 329 "src/cuda_fi/sad4.cu"
auto uint4 __T273;
# 330 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T274;
# 331 "src/cuda_fi/sad4.cu"
auto float __T275;
# 332 "src/cuda_fi/sad4.cu"
auto float __T276;
# 333 "src/cuda_fi/sad4.cu"
auto float4 __T277;
# 334 "src/cuda_fi/sad4.cu"
auto uint4 __T278;
# 335 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T279;
# 336 "src/cuda_fi/sad4.cu"
auto float __T280;
# 337 "src/cuda_fi/sad4.cu"
auto float __T281;
# 338 "src/cuda_fi/sad4.cu"
auto float4 __T282;
# 339 "src/cuda_fi/sad4.cu"
auto uint4 __T283;
# 340 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T284;
# 341 "src/cuda_fi/sad4.cu"
auto float __T285;
# 342 "src/cuda_fi/sad4.cu"
auto float __T286;
# 343 "src/cuda_fi/sad4.cu"
auto float4 __T287;
# 344 "src/cuda_fi/sad4.cu"
auto uint4 __T288;
# 345 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T289;
# 346 "src/cuda_fi/sad4.cu"
auto float __T290;
# 347 "src/cuda_fi/sad4.cu"
auto float __T291;
# 348 "src/cuda_fi/sad4.cu"
auto float4 __T292;
# 349 "src/cuda_fi/sad4.cu"
auto uint4 __T293;
# 350 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T294;
# 351 "src/cuda_fi/sad4.cu"
auto float __T295;
# 352 "src/cuda_fi/sad4.cu"
auto float __T296;
# 353 "src/cuda_fi/sad4.cu"
auto float4 __T297;
# 354 "src/cuda_fi/sad4.cu"
auto uint4 __T298;
# 355 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T299;
# 356 "src/cuda_fi/sad4.cu"
auto float __T2100;
# 357 "src/cuda_fi/sad4.cu"
auto float __T2101;
# 358 "src/cuda_fi/sad4.cu"
auto float4 __T2102;
# 359 "src/cuda_fi/sad4.cu"
auto uint4 __T2103;
# 360 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T2104;
# 361 "src/cuda_fi/sad4.cu"
auto float __T2105;
# 362 "src/cuda_fi/sad4.cu"
auto float __T2106;
# 363 "src/cuda_fi/sad4.cu"
auto float4 __T2107;
# 364 "src/cuda_fi/sad4.cu"
auto uint4 __T2108;
# 365 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T2109;
# 366 "src/cuda_fi/sad4.cu"
auto float __T2110;
# 367 "src/cuda_fi/sad4.cu"
auto float __T2111;
# 368 "src/cuda_fi/sad4.cu"
auto float4 __T2112;
# 369 "src/cuda_fi/sad4.cu"
auto uint4 __T2113;
# 370 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T2114;
# 371 "src/cuda_fi/sad4.cu"
auto float __T2115;
# 372 "src/cuda_fi/sad4.cu"
auto float __T2116;
# 373 "src/cuda_fi/sad4.cu"
auto float4 __T2117;
# 374 "src/cuda_fi/sad4.cu"
auto uint4 __T2118;
# 375 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T2119;
# 376 "src/cuda_fi/sad4.cu"
auto float __T2120;
# 377 "src/cuda_fi/sad4.cu"
auto float __T2121;
# 378 "src/cuda_fi/sad4.cu"
auto float4 __T2122;
# 379 "src/cuda_fi/sad4.cu"
auto uint4 __T2123;
# 380 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T2124;
# 381 "src/cuda_fi/sad4.cu"
auto float __T2125;
# 382 "src/cuda_fi/sad4.cu"
auto float __T2126;
# 383 "src/cuda_fi/sad4.cu"
auto float4 __T2127;
# 384 "src/cuda_fi/sad4.cu"
auto uint4 __T2128;
# 385 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T2129;
# 386 "src/cuda_fi/sad4.cu"
auto float __T2130;
# 387 "src/cuda_fi/sad4.cu"
auto float __T2131;
# 388 "src/cuda_fi/sad4.cu"
auto float4 __T2132;
# 389 "src/cuda_fi/sad4.cu"
auto uint4 __T2133;
# 390 "src/cuda_fi/sad4.cu"
auto __texture_type__ __T2134;
# 391 "src/cuda_fi/sad4.cu"
auto float __T2135;
# 392 "src/cuda_fi/sad4.cu"
auto float __T2136;
# 393 "src/cuda_fi/sad4.cu"
auto float4 __T2137;
# 394 "src/cuda_fi/sad4.cu"
auto uint4 __T2138;
# 277 "src/cuda_fi/sad4.cu"
auto int t;
# 278 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 38, "t", (&t), 10);
# 281 "src/cuda_fi/sad4.cu"
y = 0;
# 282 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 39, "y", (&y), 10);
# 285 "src/cuda_fi/sad4.cu"
t = ((int)((((__T219 = ref) , (__T220 = ((float)search_off_x))) , (__T221 = ((float)(search_off_y + y)))) , ((__T223 = (__utexfetch2D(__T219, ((((((__T222.x) = __T220) , ((__T222.y) = __T221)) , ((__T222.z) = (0.0F))) , ((__T222.w) = (0.0F))) , __T222)))) , ((unsigned short)((__T223.x))))));
# 286 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 40, "t", (&t), 10);
# 289 "src/cuda_fi/sad4.cu"
sad1 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 0)])))));
# 290 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 41, "sad1", ((int *)(&sad1)), 0);
# 293 "src/cuda_fi/sad4.cu"
t = ((int)((((__T224 = ref) , (__T225 = ((float)(search_off_x + 1)))) , (__T226 = ((float)(search_off_y + y)))) , ((__T228 = (__utexfetch2D(__T224, ((((((__T227.x) = __T225) , ((__T227.y) = __T226)) , ((__T227.z) = (0.0F))) , ((__T227.w) = (0.0F))) , __T227)))) , ((unsigned short)((__T228.x))))));
# 294 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 42, "t", (&t), 10);
# 297 "src/cuda_fi/sad4.cu"
sad1 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 1)])))));
# 298 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 43, "sad1", ((int *)(&sad1)), 0);
# 301 "src/cuda_fi/sad4.cu"
sad2 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 0)])))));
# 302 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 44, "sad2", ((int *)(&sad2)), 0);
# 305 "src/cuda_fi/sad4.cu"
t = ((int)((((__T229 = ref) , (__T230 = ((float)(search_off_x + 2)))) , (__T231 = ((float)(search_off_y + y)))) , ((__T233 = (__utexfetch2D(__T229, ((((((__T232.x) = __T230) , ((__T232.y) = __T231)) , ((__T232.z) = (0.0F))) , ((__T232.w) = (0.0F))) , __T232)))) , ((unsigned short)((__T233.x))))));
# 306 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 45, "t", (&t), 10);
# 309 "src/cuda_fi/sad4.cu"
sad1 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 2)])))));
# 310 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 46, "sad1", ((int *)(&sad1)), 0);
# 313 "src/cuda_fi/sad4.cu"
sad2 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 1)])))));
# 314 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 47, "sad2", ((int *)(&sad2)), 0);
# 317 "src/cuda_fi/sad4.cu"
sad3 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 0)])))));
# 318 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 48, "sad3", ((int *)(&sad3)), 0);
# 321 "src/cuda_fi/sad4.cu"
t = ((int)((((__T234 = ref) , (__T235 = ((float)(search_off_x + 3)))) , (__T236 = ((float)(search_off_y + y)))) , ((__T238 = (__utexfetch2D(__T234, ((((((__T237.x) = __T235) , ((__T237.y) = __T236)) , ((__T237.z) = (0.0F))) , ((__T237.w) = (0.0F))) , __T237)))) , ((unsigned short)((__T238.x))))));
# 322 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 49, "t", (&t), 10);
# 325 "src/cuda_fi/sad4.cu"
sad1 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 3)])))));
# 326 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 50, "sad1", ((int *)(&sad1)), 0);
# 329 "src/cuda_fi/sad4.cu"
sad2 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 2)])))));
# 330 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 51, "sad2", ((int *)(&sad2)), 0);
# 333 "src/cuda_fi/sad4.cu"
sad3 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 1)])))));
# 334 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 52, "sad3", ((int *)(&sad3)), 0);
# 337 "src/cuda_fi/sad4.cu"
t = ((int)((((__T239 = ref) , (__T240 = ((float)(search_off_x + 4)))) , (__T241 = ((float)(search_off_y + y)))) , ((__T243 = (__utexfetch2D(__T239, ((((((__T242.x) = __T240) , ((__T242.y) = __T241)) , ((__T242.z) = (0.0F))) , ((__T242.w) = (0.0F))) , __T242)))) , ((unsigned short)((__T243.x))))));
# 338 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 53, "t", (&t), 10);
# 341 "src/cuda_fi/sad4.cu"
sad2 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 3)])))));
# 342 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 54, "sad2", ((int *)(&sad2)), 0);
# 345 "src/cuda_fi/sad4.cu"
sad3 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 2)])))));
# 346 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 55, "sad3", ((int *)(&sad3)), 0);
# 349 "src/cuda_fi/sad4.cu"
t = ((int)((((__T244 = ref) , (__T245 = ((float)(search_off_x + 5)))) , (__T246 = ((float)(search_off_y + y)))) , ((__T248 = (__utexfetch2D(__T244, ((((((__T247.x) = __T245) , ((__T247.y) = __T246)) , ((__T247.z) = (0.0F))) , ((__T247.w) = (0.0F))) , __T247)))) , ((unsigned short)((__T248.x))))));
# 350 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 56, "t", (&t), 10);
# 353 "src/cuda_fi/sad4.cu"
sad3 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 3)])))));
# 354 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 57, "sad3", ((int *)(&sad3)), 0);
# 358 "src/cuda_fi/sad4.cu"
y = 1;
# 359 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 58, "y", (&y), 10);
# 362 "src/cuda_fi/sad4.cu"
t = ((int)((((__T249 = ref) , (__T250 = ((float)search_off_x))) , (__T251 = ((float)(search_off_y + y)))) , ((__T253 = (__utexfetch2D(__T249, ((((((__T252.x) = __T250) , ((__T252.y) = __T251)) , ((__T252.z) = (0.0F))) , ((__T252.w) = (0.0F))) , __T252)))) , ((unsigned short)((__T253.x))))));
# 363 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 59, "t", (&t), 10);
# 366 "src/cuda_fi/sad4.cu"
sad1 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 0)])))));
# 367 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 60, "sad1", ((int *)(&sad1)), 0);
# 370 "src/cuda_fi/sad4.cu"
t = ((int)((((__T254 = ref) , (__T255 = ((float)(search_off_x + 1)))) , (__T256 = ((float)(search_off_y + y)))) , ((__T258 = (__utexfetch2D(__T254, ((((((__T257.x) = __T255) , ((__T257.y) = __T256)) , ((__T257.z) = (0.0F))) , ((__T257.w) = (0.0F))) , __T257)))) , ((unsigned short)((__T258.x))))));
# 371 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 61, "t", (&t), 10);
# 374 "src/cuda_fi/sad4.cu"
sad1 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 1)])))));
# 375 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 62, "sad1", ((int *)(&sad1)), 0);
# 378 "src/cuda_fi/sad4.cu"
sad2 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 0)])))));
# 379 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 63, "sad2", ((int *)(&sad2)), 0);
# 382 "src/cuda_fi/sad4.cu"
t = ((int)((((__T259 = ref) , (__T260 = ((float)(search_off_x + 2)))) , (__T261 = ((float)(search_off_y + y)))) , ((__T263 = (__utexfetch2D(__T259, ((((((__T262.x) = __T260) , ((__T262.y) = __T261)) , ((__T262.z) = (0.0F))) , ((__T262.w) = (0.0F))) , __T262)))) , ((unsigned short)((__T263.x))))));
# 383 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 64, "t", (&t), 10);
# 386 "src/cuda_fi/sad4.cu"
sad1 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 2)])))));
# 387 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 65, "sad1", ((int *)(&sad1)), 0);
# 390 "src/cuda_fi/sad4.cu"
sad2 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 1)])))));
# 391 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 66, "sad2", ((int *)(&sad2)), 0);
# 394 "src/cuda_fi/sad4.cu"
sad3 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 0)])))));
# 395 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 67, "sad3", ((int *)(&sad3)), 0);
# 398 "src/cuda_fi/sad4.cu"
t = ((int)((((__T264 = ref) , (__T265 = ((float)(search_off_x + 3)))) , (__T266 = ((float)(search_off_y + y)))) , ((__T268 = (__utexfetch2D(__T264, ((((((__T267.x) = __T265) , ((__T267.y) = __T266)) , ((__T267.z) = (0.0F))) , ((__T267.w) = (0.0F))) , __T267)))) , ((unsigned short)((__T268.x))))));
# 399 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 68, "t", (&t), 10);
# 402 "src/cuda_fi/sad4.cu"
sad1 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 3)])))));
# 403 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 69, "sad1", ((int *)(&sad1)), 0);
# 406 "src/cuda_fi/sad4.cu"
sad2 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 2)])))));
# 407 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 70, "sad2", ((int *)(&sad2)), 0);
# 410 "src/cuda_fi/sad4.cu"
sad3 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 1)])))));
# 411 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 71, "sad3", ((int *)(&sad3)), 0);
# 414 "src/cuda_fi/sad4.cu"
t = ((int)((((__T269 = ref) , (__T270 = ((float)(search_off_x + 4)))) , (__T271 = ((float)(search_off_y + y)))) , ((__T273 = (__utexfetch2D(__T269, ((((((__T272.x) = __T270) , ((__T272.y) = __T271)) , ((__T272.z) = (0.0F))) , ((__T272.w) = (0.0F))) , __T272)))) , ((unsigned short)((__T273.x))))));
# 415 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 72, "t", (&t), 10);
# 418 "src/cuda_fi/sad4.cu"
sad2 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 3)])))));
# 419 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 73, "sad2", ((int *)(&sad2)), 0);
# 422 "src/cuda_fi/sad4.cu"
sad3 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 2)])))));
# 423 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 74, "sad3", ((int *)(&sad3)), 0);
# 426 "src/cuda_fi/sad4.cu"
t = ((int)((((__T274 = ref) , (__T275 = ((float)(search_off_x + 5)))) , (__T276 = ((float)(search_off_y + y)))) , ((__T278 = (__utexfetch2D(__T274, ((((((__T277.x) = __T275) , ((__T277.y) = __T276)) , ((__T277.z) = (0.0F))) , ((__T277.w) = (0.0F))) , __T277)))) , ((unsigned short)((__T278.x))))));
# 427 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 75, "t", (&t), 10);
# 430 "src/cuda_fi/sad4.cu"
sad3 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 3)])))));
# 431 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 76, "sad3", ((int *)(&sad3)), 0);
# 435 "src/cuda_fi/sad4.cu"
y = 2;
# 436 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 77, "y", (&y), 10);
# 439 "src/cuda_fi/sad4.cu"
t = ((int)((((__T279 = ref) , (__T280 = ((float)search_off_x))) , (__T281 = ((float)(search_off_y + y)))) , ((__T283 = (__utexfetch2D(__T279, ((((((__T282.x) = __T280) , ((__T282.y) = __T281)) , ((__T282.z) = (0.0F))) , ((__T282.w) = (0.0F))) , __T282)))) , ((unsigned short)((__T283.x))))));
# 440 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 78, "t", (&t), 10);
# 443 "src/cuda_fi/sad4.cu"
sad1 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 0)])))));
# 444 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 79, "sad1", ((int *)(&sad1)), 0);
# 447 "src/cuda_fi/sad4.cu"
t = ((int)((((__T284 = ref) , (__T285 = ((float)(search_off_x + 1)))) , (__T286 = ((float)(search_off_y + y)))) , ((__T288 = (__utexfetch2D(__T284, ((((((__T287.x) = __T285) , ((__T287.y) = __T286)) , ((__T287.z) = (0.0F))) , ((__T287.w) = (0.0F))) , __T287)))) , ((unsigned short)((__T288.x))))));
# 448 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 80, "t", (&t), 10);
# 451 "src/cuda_fi/sad4.cu"
sad1 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 1)])))));
# 452 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 81, "sad1", ((int *)(&sad1)), 0);
# 455 "src/cuda_fi/sad4.cu"
sad2 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 0)])))));
# 456 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 82, "sad2", ((int *)(&sad2)), 0);
# 459 "src/cuda_fi/sad4.cu"
t = ((int)((((__T289 = ref) , (__T290 = ((float)(search_off_x + 2)))) , (__T291 = ((float)(search_off_y + y)))) , ((__T293 = (__utexfetch2D(__T289, ((((((__T292.x) = __T290) , ((__T292.y) = __T291)) , ((__T292.z) = (0.0F))) , ((__T292.w) = (0.0F))) , __T292)))) , ((unsigned short)((__T293.x))))));
# 460 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 83, "t", (&t), 10);
# 463 "src/cuda_fi/sad4.cu"
sad1 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 2)])))));
# 464 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 84, "sad1", ((int *)(&sad1)), 0);
# 467 "src/cuda_fi/sad4.cu"
sad2 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 1)])))));
# 468 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 85, "sad2", ((int *)(&sad2)), 0);
# 471 "src/cuda_fi/sad4.cu"
sad3 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 0)])))));
# 472 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 86, "sad3", ((int *)(&sad3)), 0);
# 475 "src/cuda_fi/sad4.cu"
t = ((int)((((__T294 = ref) , (__T295 = ((float)(search_off_x + 3)))) , (__T296 = ((float)(search_off_y + y)))) , ((__T298 = (__utexfetch2D(__T294, ((((((__T297.x) = __T295) , ((__T297.y) = __T296)) , ((__T297.z) = (0.0F))) , ((__T297.w) = (0.0F))) , __T297)))) , ((unsigned short)((__T298.x))))));
# 476 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 87, "t", (&t), 10);
# 479 "src/cuda_fi/sad4.cu"
sad1 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 3)])))));
# 480 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 88, "sad1", ((int *)(&sad1)), 0);
# 483 "src/cuda_fi/sad4.cu"
sad2 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 2)])))));
# 484 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 89, "sad2", ((int *)(&sad2)), 0);
# 487 "src/cuda_fi/sad4.cu"
sad3 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 1)])))));
# 488 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 90, "sad3", ((int *)(&sad3)), 0);
# 491 "src/cuda_fi/sad4.cu"
t = ((int)((((__T299 = ref) , (__T2100 = ((float)(search_off_x + 4)))) , (__T2101 = ((float)(search_off_y + y)))) , ((__T2103 = (__utexfetch2D(__T299, ((((((__T2102.x) = __T2100) , ((__T2102.y) = __T2101)) , ((__T2102.z) = (0.0F))) , ((__T2102.w) = (0.0F))) , __T2102)))) , ((unsigned short)((__T2103.x))))));
# 492 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 91, "t", (&t), 10);
# 495 "src/cuda_fi/sad4.cu"
sad2 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 3)])))));
# 496 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 92, "sad2", ((int *)(&sad2)), 0);
# 499 "src/cuda_fi/sad4.cu"
sad3 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 2)])))));
# 500 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 93, "sad3", ((int *)(&sad3)), 0);
# 503 "src/cuda_fi/sad4.cu"
t = ((int)((((__T2104 = ref) , (__T2105 = ((float)(search_off_x + 5)))) , (__T2106 = ((float)(search_off_y + y)))) , ((__T2108 = (__utexfetch2D(__T2104, ((((((__T2107.x) = __T2105) , ((__T2107.y) = __T2106)) , ((__T2107.z) = (0.0F))) , ((__T2107.w) = (0.0F))) , __T2107)))) , ((unsigned short)((__T2108.x))))));
# 504 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 94, "t", (&t), 10);
# 507 "src/cuda_fi/sad4.cu"
sad3 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 3)])))));
# 508 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 95, "sad3", ((int *)(&sad3)), 0);
# 512 "src/cuda_fi/sad4.cu"
y = 3;
# 513 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 96, "y", (&y), 10);
# 516 "src/cuda_fi/sad4.cu"
t = ((int)((((__T2109 = ref) , (__T2110 = ((float)search_off_x))) , (__T2111 = ((float)(search_off_y + y)))) , ((__T2113 = (__utexfetch2D(__T2109, ((((((__T2112.x) = __T2110) , ((__T2112.y) = __T2111)) , ((__T2112.z) = (0.0F))) , ((__T2112.w) = (0.0F))) , __T2112)))) , ((unsigned short)((__T2113.x))))));
# 517 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 97, "t", (&t), 10);
# 520 "src/cuda_fi/sad4.cu"
sad1 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 0)])))));
# 521 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 98, "sad1", ((int *)(&sad1)), 0);
# 524 "src/cuda_fi/sad4.cu"
t = ((int)((((__T2114 = ref) , (__T2115 = ((float)(search_off_x + 1)))) , (__T2116 = ((float)(search_off_y + y)))) , ((__T2118 = (__utexfetch2D(__T2114, ((((((__T2117.x) = __T2115) , ((__T2117.y) = __T2116)) , ((__T2117.z) = (0.0F))) , ((__T2117.w) = (0.0F))) , __T2117)))) , ((unsigned short)((__T2118.x))))));
# 525 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 99, "t", (&t), 10);
# 528 "src/cuda_fi/sad4.cu"
sad1 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 1)])))));
# 529 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 100, "sad1", ((int *)(&sad1)), 0);
# 532 "src/cuda_fi/sad4.cu"
sad2 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 0)])))));
# 533 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 101, "sad2", ((int *)(&sad2)), 0);
# 536 "src/cuda_fi/sad4.cu"
t = ((int)((((__T2119 = ref) , (__T2120 = ((float)(search_off_x + 2)))) , (__T2121 = ((float)(search_off_y + y)))) , ((__T2123 = (__utexfetch2D(__T2119, ((((((__T2122.x) = __T2120) , ((__T2122.y) = __T2121)) , ((__T2122.z) = (0.0F))) , ((__T2122.w) = (0.0F))) , __T2122)))) , ((unsigned short)((__T2123.x))))));
# 537 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 102, "t", (&t), 10);
# 540 "src/cuda_fi/sad4.cu"
sad1 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 2)])))));
# 541 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 103, "sad1", ((int *)(&sad1)), 0);
# 544 "src/cuda_fi/sad4.cu"
sad2 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 1)])))));
# 545 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 104, "sad2", ((int *)(&sad2)), 0);
# 548 "src/cuda_fi/sad4.cu"
sad3 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 0)])))));
# 549 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 105, "sad3", ((int *)(&sad3)), 0);
# 552 "src/cuda_fi/sad4.cu"
t = ((int)((((__T2124 = ref) , (__T2125 = ((float)(search_off_x + 3)))) , (__T2126 = ((float)(search_off_y + y)))) , ((__T2128 = (__utexfetch2D(__T2124, ((((((__T2127.x) = __T2125) , ((__T2127.y) = __T2126)) , ((__T2127.z) = (0.0F))) , ((__T2127.w) = (0.0F))) , __T2127)))) , ((unsigned short)((__T2128.x))))));
# 553 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 106, "t", (&t), 10);
# 556 "src/cuda_fi/sad4.cu"
sad1 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 3)])))));
# 557 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 107, "sad1", ((int *)(&sad1)), 0);
# 560 "src/cuda_fi/sad4.cu"
sad2 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 2)])))));
# 561 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 108, "sad2", ((int *)(&sad2)), 0);
# 564 "src/cuda_fi/sad4.cu"
sad3 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 1)])))));
# 565 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 109, "sad3", ((int *)(&sad3)), 0);
# 568 "src/cuda_fi/sad4.cu"
t = ((int)((((__T2129 = ref) , (__T2130 = ((float)(search_off_x + 4)))) , (__T2131 = ((float)(search_off_y + y)))) , ((__T2133 = (__utexfetch2D(__T2129, ((((((__T2132.x) = __T2130) , ((__T2132.y) = __T2131)) , ((__T2132.z) = (0.0F))) , ((__T2132.w) = (0.0F))) , __T2132)))) , ((unsigned short)((__T2133.x))))));
# 569 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 110, "t", (&t), 10);
# 572 "src/cuda_fi/sad4.cu"
sad2 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 3)])))));
# 573 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 111, "sad2", ((int *)(&sad2)), 0);
# 576 "src/cuda_fi/sad4.cu"
sad3 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 2)])))));
# 577 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 112, "sad3", ((int *)(&sad3)), 0);
# 580 "src/cuda_fi/sad4.cu"
t = ((int)((((__T2134 = ref) , (__T2135 = ((float)(search_off_x + 5)))) , (__T2136 = ((float)(search_off_y + y)))) , ((__T2138 = (__utexfetch2D(__T2134, ((((((__T2137.x) = __T2135) , ((__T2137.y) = __T2136)) , ((__T2137.z) = (0.0F))) , ((__T2137.w) = (0.0F))) , __T2137)))) , ((unsigned short)((__T2138.x))))));
# 581 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 113, "t", (&t), 10);
# 584 "src/cuda_fi/sad4.cu"
sad3 += (__cuda_abs((t - ((int)(frame_loc[(((cur_o << 4) + (y << 2)) + 3)])))));
# 585 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 114, "sad3", ((int *)(&sad3)), 0);
# 588 "src/cuda_fi/sad4.cu"
}
# 590 "src/cuda_fi/sad4.cu"
(sad_loc[(((__umul24(((unsigned)ty), 1U)) + ((unsigned)tx)) * 1096U) + ((unsigned)search_pos)]) = sad1;
# 591 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 115, "sad_loc[(((__umul24(ty, 1)+tx)*1096)+search_pos)]", ((int *)(sad_loc + ((((__umul24(((unsigned)ty), 1U)) + ((unsigned)tx)) * 1096U) + ((unsigned)search_pos)))), 0);
# 594 "src/cuda_fi/sad4.cu"
(sad_loc[(((__umul24(((unsigned)ty), 1U)) + ((unsigned)tx)) * 1096U) + ((unsigned)(search_pos + 1))]) = sad2;
# 595 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 116, "sad_loc[(((__umul24(ty, 1)+tx)*1096)+(search_pos+1))]", ((int *)(sad_loc + ((((__umul24(((unsigned)ty), 1U)) + ((unsigned)tx)) * 1096U) + ((unsigned)(search_pos + 1))))), 0);
# 598 "src/cuda_fi/sad4.cu"
(sad_loc[(((__umul24(((unsigned)ty), 1U)) + ((unsigned)tx)) * 1096U) + ((unsigned)(search_pos + 2))]) = sad3;
# 599 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 117, "sad_loc[(((__umul24(ty, 1)+tx)*1096)+(search_pos+2))]", ((int *)(sad_loc + ((((__umul24(((unsigned)ty), 1U)) + ((unsigned)tx)) * 1096U) + ((unsigned)(search_pos + 2))))), 0);
# 602 "src/cuda_fi/sad4.cu"
local_search_off_x += 3;
# 603 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 118, "local_search_off_x", (&local_search_off_x), 10);
# 606 "src/cuda_fi/sad4.cu"
if (local_search_off_x >= 33)
# 607 "src/cuda_fi/sad4.cu"
{
# 608 "src/cuda_fi/sad4.cu"
local_search_off_x -= 33;
# 609 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 119, "local_search_off_x", (&local_search_off_x), 10);
# 612 "src/cuda_fi/sad4.cu"
search_off_y++;
# 613 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 120, "search_off_y", (&search_off_y), 10);
# 616 "src/cuda_fi/sad4.cu"
}
# 617 "src/cuda_fi/sad4.cu"
}
# 619 "src/cuda_fi/sad4.cu"
_Z17GPUFI_KERNEL_LOOPP12_gpufi_data_i(gpufi_dev, 1);
# 622 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 34, "search_pos", (&search_pos), 10);
# 625 "src/cuda_fi/sad4.cu"
}
# 626 "src/cuda_fi/sad4.cu"
__syncthreads();
# 631 "src/cuda_fi/sad4.cu"
if ((((threadIdx.x)) >> 5) < 1U)
# 632 "src/cuda_fi/sad4.cu"
{
# 633 "src/cuda_fi/sad4.cu"
auto int tgroup;
# 637 "src/cuda_fi/sad4.cu"
auto int ty;
# 641 "src/cuda_fi/sad4.cu"
auto int tx;
# 645 "src/cuda_fi/sad4.cu"
auto int index;
# 650 "src/cuda_fi/sad4.cu"
auto int mb_x;
# 654 "src/cuda_fi/sad4.cu"
auto int mb_y;
# 658 "src/cuda_fi/sad4.cu"
auto int block_x;
# 662 "src/cuda_fi/sad4.cu"
auto int block_y;
# 633 "src/cuda_fi/sad4.cu"
tgroup = ((int)(((threadIdx.x)) & 31U));
# 634 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 121, "tgroup", (&tgroup), 10);
# 637 "src/cuda_fi/sad4.cu"
ty = ((int)((((threadIdx.x)) >> 5) / 1U));
# 638 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 122, "ty", (&ty), 10);
# 641 "src/cuda_fi/sad4.cu"
tx = ((int)((((threadIdx.x)) >> 5) - (__umul24(((unsigned)ty), 1U))));
# 642 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 123, "tx", (&tx), 10);
# 646 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 124, "index", (&index), 10);
# 650 "src/cuda_fi/sad4.cu"
mb_x = ((int)((((unsigned)tx) + (__umul24(((unsigned)bx), 1U))) >> 2));
# 651 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 125, "mb_x", (&mb_x), 10);
# 654 "src/cuda_fi/sad4.cu"
mb_y = ((int)((((unsigned)ty) + (__umul24(((unsigned)by), 1U))) >> 2));
# 655 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 126, "mb_y", (&mb_y), 10);
# 658 "src/cuda_fi/sad4.cu"
block_x = ((int)((((unsigned)tx) + (__umul24(((unsigned)bx), 1U))) & 3U));
# 659 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 127, "block_x", (&block_x), 10);
# 662 "src/cuda_fi/sad4.cu"
block_y = ((int)((((unsigned)ty) + (__umul24(((unsigned)by), 1U))) & 3U));
# 663 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 128, "block_y", (&block_y), 10);
# 666 "src/cuda_fi/sad4.cu"
if ((mb_x < mb_width) && (mb_y < mb_height))
# 667 "src/cuda_fi/sad4.cu"
{
# 672 "src/cuda_fi/sad4.cu"
blk_sad += ((((__umul24((__umul24(((unsigned)mb_width), ((unsigned)mb_height))), 25U)) + (((__umul24(((unsigned)mb_y), ((unsigned)mb_width))) + ((unsigned)mb_x)) * 16U)) + ((unsigned)((4 * block_y) + block_x))) * 1096U);
# 673 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 129, "blk_sad", ((int *)(&blk_sad)), 50);
# 678 "src/cuda_fi/sad4.cu"
_Z17GPUFI_KERNEL_LOOPP12_gpufi_data_i(gpufi_dev, 0);
# 681 "src/cuda_fi/sad4.cu"
for (index = tgroup; (index < 274); index += 32)
# 682 "src/cuda_fi/sad4.cu"
{
# 684 "src/cuda_fi/sad4.cu"
_Z22GPUFI_KERNEL_ITERATIONP12_gpufi_data_(gpufi_dev);
# 687 "src/cuda_fi/sad4.cu"
(((struct vec8b *)blk_sad)[index]) = (sad_loc_8b[((((__umul24(((unsigned)ty), 1U)) + ((unsigned)tx)) * 274U) + ((unsigned)index))]);
# 688 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 132, "((struct vec8b * )blk_sad)[index]", ((int *)(((struct vec8b *)blk_sad) + index)), 0);
# 691 "src/cuda_fi/sad4.cu"
}
# 693 "src/cuda_fi/sad4.cu"
_Z17GPUFI_KERNEL_LOOPP12_gpufi_data_i(gpufi_dev, 1);
# 696 "src/cuda_fi/sad4.cu"
_Z21GPUFI_KERNEL_VARIABLEP12_gpufi_data_iPcPii(gpufi_dev, 131, "index", (&index), 10);
# 699 "src/cuda_fi/sad4.cu"
}
# 700 "src/cuda_fi/sad4.cu"
}
# 701 "src/cuda_fi/sad4.cu"
_Z12GPUFI_KERNELP12_gpufi_data_iiPc(gpufi_dev, 1, 0, "mb_sad_calc");
# 702 "src/cuda_fi/sad4.cu"
}
# 702 "src/cuda_fi/sad4.cu"
}}
