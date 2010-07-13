# 1 "main.cudafe1.cpp"
# 1 "/afs/crhc.illinois.edu/project/depend/yim6/clairvoyant/fi/server/src-server/ControlServer/instr/parboil/benchmarks/pns//"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "main.cudafe1.cpp"
# 1 "src/cuda_fi_prerun/main.cu"
# 233 "/usr/include/c++/4.3/i486-linux-gnu/bits/c++config.h" 3
namespace std __attribute__((visibility("default"))) {
# 245 "/usr/include/c++/4.3/i486-linux-gnu/bits/c++config.h" 3
}
# 46 "/usr/local/cuda/bin/../include/device_types.h"
# 152 "/usr/lib/gcc/i486-linux-gnu/4.3.2/include/stddef.h" 3
typedef int ptrdiff_t;
# 214 "/usr/lib/gcc/i486-linux-gnu/4.3.2/include/stddef.h" 3
typedef unsigned size_t;
# 1 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 1 3
# 107 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 3
# 1 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 1 3
# 53 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 3
# 1 "/usr/local/cuda/bin/../include/host_defines.h" 1 3
# 54 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 2 3
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

    dim3(unsigned int x = 1, unsigned int y = 1, unsigned int z = 1) : x(x), y(y), z(z) {}
    dim3(uint3 v) : x(v.x), y(v.y), z(v.z) {}
    operator uint3(void) { uint3 t; t.x = x; t.y = y; t.z = z; return t; }

};


typedef struct dim3 dim3;
# 45 "/usr/local/cuda/bin/../include/builtin_types.h" 2 3
# 55 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 2 3
# 80 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 3
extern "C" {
# 89 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 3
extern cudaError_t cudaMalloc3D(struct cudaPitchedPtr* pitchedDevPtr, struct cudaExtent extent);
extern cudaError_t cudaMalloc3DArray(struct cudaArray** arrayPtr, const struct cudaChannelFormatDesc* desc, struct cudaExtent extent);
extern cudaError_t cudaMemset3D(struct cudaPitchedPtr pitchedDevPtr, int value, struct cudaExtent extent);
extern cudaError_t cudaMemcpy3D(const struct cudaMemcpy3DParms *p);
extern cudaError_t cudaMemcpy3DAsync(const struct cudaMemcpy3DParms *p, cudaStream_t stream);
# 102 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 3
extern cudaError_t cudaMalloc(void **devPtr, size_t size);
extern cudaError_t cudaMallocHost(void **ptr, size_t size);
extern cudaError_t cudaMallocPitch(void **devPtr, size_t *pitch, size_t width, size_t height);
extern cudaError_t cudaMallocArray(struct cudaArray **array, const struct cudaChannelFormatDesc *desc, size_t width, size_t height );
extern cudaError_t cudaFree(void *devPtr);
extern cudaError_t cudaFreeHost(void *ptr);
extern cudaError_t cudaFreeArray(struct cudaArray *array);

extern cudaError_t cudaHostAlloc(void **pHost, size_t bytes, unsigned int flags);
extern cudaError_t cudaHostGetDevicePointer(void **pDevice, void *pHost, unsigned int flags);
extern cudaError_t cudaHostGetFlags(unsigned int *pFlags, void *pHost);
# 121 "/usr/local/cuda/bin/../include/cuda_runtime_api.h" 3
extern cudaError_t cudaMemcpy(void *dst, const void *src, size_t count, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpyToArray(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t count, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpyFromArray(void *dst, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t count, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpyArrayToArray(struct cudaArray *dst, size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray *src, size_t wOffsetSrc, size_t hOffsetSrc, size_t count, enum cudaMemcpyKind kind );
extern cudaError_t cudaMemcpy2D(void *dst, size_t dpitch, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpy2DToArray(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpy2DFromArray(void *dst, size_t dpitch, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, size_t height, enum cudaMemcpyKind kind);
extern cudaError_t cudaMemcpy2DArrayToArray(struct cudaArray *dst, size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray *src, size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, enum cudaMemcpyKind kind );
extern cudaError_t cudaMemcpyToSymbol(const char *symbol, const void *src, size_t count, size_t offset , enum cudaMemcpyKind kind );
extern cudaError_t cudaMemcpyFromSymbol(void *dst, const char *symbol, size_t count, size_t offset , enum cudaMemcpyKind kind );







extern cudaError_t cudaMemcpyAsync(void *dst, const void *src, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpyToArrayAsync(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpyFromArrayAsync(void *dst, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpy2DAsync(void *dst, size_t dpitch, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpy2DToArrayAsync(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpy2DFromArrayAsync(void *dst, size_t dpitch, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpyToSymbolAsync(const char *symbol, const void *src, size_t count, size_t offset, enum cudaMemcpyKind kind, cudaStream_t stream);
extern cudaError_t cudaMemcpyFromSymbolAsync(void *dst, const char *symbol, size_t count, size_t offset, enum cudaMemcpyKind kind, cudaStream_t stream);







extern cudaError_t cudaMemset(void *devPtr, int value, size_t count);
extern cudaError_t cudaMemset2D(void *devPtr, size_t pitch, int value, size_t width, size_t height);







extern cudaError_t cudaGetSymbolAddress(void **devPtr, const char *symbol);
extern cudaError_t cudaGetSymbolSize(size_t *size, const char *symbol);







extern cudaError_t cudaGetDeviceCount(int *count);
extern cudaError_t cudaGetDeviceProperties(struct cudaDeviceProp *prop, int device);
extern cudaError_t cudaChooseDevice(int *device, const struct cudaDeviceProp *prop);
extern cudaError_t cudaSetDevice(int device);
extern cudaError_t cudaGetDevice(int *device);
extern cudaError_t cudaSetValidDevices(int *device_arr, int len);
extern cudaError_t cudaSetDeviceFlags( int flags );







extern cudaError_t cudaBindTexture(size_t *offset, const struct textureReference *texref, const void *devPtr, const struct cudaChannelFormatDesc *desc, size_t size );
extern cudaError_t cudaBindTexture2D(size_t *offset,const struct textureReference *texref,const void *devPtr, const struct cudaChannelFormatDesc *desc,size_t width, size_t height, size_t pitch);
extern cudaError_t cudaBindTextureToArray(const struct textureReference *texref, const struct cudaArray *array, const struct cudaChannelFormatDesc *desc);
extern cudaError_t cudaUnbindTexture(const struct textureReference *texref);
extern cudaError_t cudaGetTextureAlignmentOffset(size_t *offset, const struct textureReference *texref);
extern cudaError_t cudaGetTextureReference(const struct textureReference **texref, const char *symbol);







extern cudaError_t cudaGetChannelDesc(struct cudaChannelFormatDesc *desc, const struct cudaArray *array);
extern struct cudaChannelFormatDesc cudaCreateChannelDesc(int x, int y, int z, int w, enum cudaChannelFormatKind f);







extern cudaError_t cudaGetLastError(void);
extern const char* cudaGetErrorString(cudaError_t error);







extern cudaError_t cudaConfigureCall(dim3 gridDim, dim3 blockDim, size_t sharedMem , cudaStream_t stream );
extern cudaError_t cudaSetupArgument(const void *arg, size_t size, size_t offset);
extern cudaError_t cudaLaunch(const char *entry);
extern cudaError_t cudaFuncGetAttributes(struct cudaFuncAttributes *attr, const char *func);







extern cudaError_t cudaStreamCreate(cudaStream_t *pStream);
extern cudaError_t cudaStreamDestroy(cudaStream_t stream);
extern cudaError_t cudaStreamSynchronize(cudaStream_t stream);
extern cudaError_t cudaStreamQuery(cudaStream_t stream);







extern cudaError_t cudaEventCreate(cudaEvent_t *event);
extern cudaError_t cudaEventCreateWithFlags(cudaEvent_t *event, int flags);
extern cudaError_t cudaEventRecord(cudaEvent_t event, cudaStream_t stream);
extern cudaError_t cudaEventQuery(cudaEvent_t event);
extern cudaError_t cudaEventSynchronize(cudaEvent_t event);
extern cudaError_t cudaEventDestroy(cudaEvent_t event);
extern cudaError_t cudaEventElapsedTime(float *ms, cudaEvent_t start, cudaEvent_t end);







extern cudaError_t cudaSetDoubleForDevice(double *d);
extern cudaError_t cudaSetDoubleForHost(double *d);







extern cudaError_t cudaThreadExit(void);
extern cudaError_t cudaThreadSynchronize(void);







extern cudaError_t cudaDriverGetVersion(int *driverVersion);
extern cudaError_t cudaRuntimeGetVersion(int *runtimeVersion);


}
# 108 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2 3
# 1 "/usr/local/cuda/bin/../include/crt/storage_class.h" 1 3
# 109 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2 3
# 216 "/usr/lib/gcc/i486-linux-gnu/4.3.2/include/stddef.h" 2 3
# 91 "/usr/local/cuda/bin/../include/driver_types.h"
# 139 "/usr/local/cuda/bin/../include/driver_types.h"
# 151 "/usr/local/cuda/bin/../include/driver_types.h"
# 164 "/usr/local/cuda/bin/../include/driver_types.h"
# 170 "/usr/local/cuda/bin/../include/driver_types.h"
# 182 "/usr/local/cuda/bin/../include/driver_types.h"
# 194 "/usr/local/cuda/bin/../include/driver_types.h"
# 205 "/usr/local/cuda/bin/../include/driver_types.h"
# 216 "/usr/local/cuda/bin/../include/driver_types.h"
# 234 "/usr/local/cuda/bin/../include/driver_types.h"
# 248 "/usr/local/cuda/bin/../include/driver_types.h"
# 260 "/usr/local/cuda/bin/../include/driver_types.h"
# 319 "/usr/local/cuda/bin/../include/driver_types.h"
# 325 "/usr/local/cuda/bin/../include/driver_types.h"
# 331 "/usr/local/cuda/bin/../include/driver_types.h"
# 54 "/usr/local/cuda/bin/../include/texture_types.h"
# 61 "/usr/local/cuda/bin/../include/texture_types.h"
# 68 "/usr/local/cuda/bin/../include/texture_types.h"
# 75 "/usr/local/cuda/bin/../include/texture_types.h"
# 82 "/usr/local/cuda/bin/../include/vector_types.h"
# 89 "/usr/local/cuda/bin/../include/vector_types.h"
# 96 "/usr/local/cuda/bin/../include/vector_types.h"
# 103 "/usr/local/cuda/bin/../include/vector_types.h"
# 110 "/usr/local/cuda/bin/../include/vector_types.h"
# 117 "/usr/local/cuda/bin/../include/vector_types.h"
# 124 "/usr/local/cuda/bin/../include/vector_types.h"
# 131 "/usr/local/cuda/bin/../include/vector_types.h"
# 138 "/usr/local/cuda/bin/../include/vector_types.h"
# 145 "/usr/local/cuda/bin/../include/vector_types.h"
# 152 "/usr/local/cuda/bin/../include/vector_types.h"
# 159 "/usr/local/cuda/bin/../include/vector_types.h"
# 166 "/usr/local/cuda/bin/../include/vector_types.h"
# 173 "/usr/local/cuda/bin/../include/vector_types.h"
# 180 "/usr/local/cuda/bin/../include/vector_types.h"
# 183 "/usr/local/cuda/bin/../include/vector_types.h"
# 186 "/usr/local/cuda/bin/../include/vector_types.h"
# 193 "/usr/local/cuda/bin/../include/vector_types.h"
# 200 "/usr/local/cuda/bin/../include/vector_types.h"
# 203 "/usr/local/cuda/bin/../include/vector_types.h"
# 206 "/usr/local/cuda/bin/../include/vector_types.h"
# 213 "/usr/local/cuda/bin/../include/vector_types.h"
# 220 "/usr/local/cuda/bin/../include/vector_types.h"
# 227 "/usr/local/cuda/bin/../include/vector_types.h"
# 234 "/usr/local/cuda/bin/../include/vector_types.h"
# 241 "/usr/local/cuda/bin/../include/vector_types.h"
# 258 "/usr/local/cuda/bin/../include/vector_types.h"
# 265 "/usr/local/cuda/bin/../include/vector_types.h"
# 276 "/usr/local/cuda/bin/../include/vector_types.h"
# 283 "/usr/local/cuda/bin/../include/vector_types.h"
# 290 "/usr/local/cuda/bin/../include/vector_types.h"
# 297 "/usr/local/cuda/bin/../include/vector_types.h"
# 306 "/usr/local/cuda/bin/../include/vector_types.h"
# 313 "/usr/local/cuda/bin/../include/vector_types.h"
# 316 "/usr/local/cuda/bin/../include/vector_types.h"
# 323 "/usr/local/cuda/bin/../include/vector_types.h"
# 330 "/usr/local/cuda/bin/../include/vector_types.h"
# 337 "/usr/local/cuda/bin/../include/vector_types.h"
# 344 "/usr/local/cuda/bin/../include/vector_types.h"
# 351 "/usr/local/cuda/bin/../include/vector_types.h"
# 358 "/usr/local/cuda/bin/../include/vector_types.h"
# 365 "/usr/local/cuda/bin/../include/vector_types.h"
# 378 "/usr/local/cuda/bin/../include/vector_types.h"
# 380 "/usr/local/cuda/bin/../include/vector_types.h"
# 382 "/usr/local/cuda/bin/../include/vector_types.h"
# 384 "/usr/local/cuda/bin/../include/vector_types.h"
# 386 "/usr/local/cuda/bin/../include/vector_types.h"
# 388 "/usr/local/cuda/bin/../include/vector_types.h"
# 390 "/usr/local/cuda/bin/../include/vector_types.h"
# 392 "/usr/local/cuda/bin/../include/vector_types.h"
# 394 "/usr/local/cuda/bin/../include/vector_types.h"
# 396 "/usr/local/cuda/bin/../include/vector_types.h"
# 398 "/usr/local/cuda/bin/../include/vector_types.h"
# 400 "/usr/local/cuda/bin/../include/vector_types.h"
# 402 "/usr/local/cuda/bin/../include/vector_types.h"
# 404 "/usr/local/cuda/bin/../include/vector_types.h"
# 406 "/usr/local/cuda/bin/../include/vector_types.h"
# 408 "/usr/local/cuda/bin/../include/vector_types.h"
# 410 "/usr/local/cuda/bin/../include/vector_types.h"
# 412 "/usr/local/cuda/bin/../include/vector_types.h"
# 414 "/usr/local/cuda/bin/../include/vector_types.h"
# 416 "/usr/local/cuda/bin/../include/vector_types.h"
# 418 "/usr/local/cuda/bin/../include/vector_types.h"
# 420 "/usr/local/cuda/bin/../include/vector_types.h"
# 422 "/usr/local/cuda/bin/../include/vector_types.h"
# 424 "/usr/local/cuda/bin/../include/vector_types.h"
# 426 "/usr/local/cuda/bin/../include/vector_types.h"
# 428 "/usr/local/cuda/bin/../include/vector_types.h"
# 430 "/usr/local/cuda/bin/../include/vector_types.h"
# 432 "/usr/local/cuda/bin/../include/vector_types.h"
# 434 "/usr/local/cuda/bin/../include/vector_types.h"
# 436 "/usr/local/cuda/bin/../include/vector_types.h"
# 438 "/usr/local/cuda/bin/../include/vector_types.h"
# 440 "/usr/local/cuda/bin/../include/vector_types.h"
# 442 "/usr/local/cuda/bin/../include/vector_types.h"
# 444 "/usr/local/cuda/bin/../include/vector_types.h"
# 446 "/usr/local/cuda/bin/../include/vector_types.h"
# 448 "/usr/local/cuda/bin/../include/vector_types.h"
# 450 "/usr/local/cuda/bin/../include/vector_types.h"
# 452 "/usr/local/cuda/bin/../include/vector_types.h"
# 454 "/usr/local/cuda/bin/../include/vector_types.h"
# 456 "/usr/local/cuda/bin/../include/vector_types.h"
# 458 "/usr/local/cuda/bin/../include/vector_types.h"
# 460 "/usr/local/cuda/bin/../include/vector_types.h"
# 469 "/usr/local/cuda/bin/../include/vector_types.h"
# 480 "/usr/local/cuda/bin/../include/vector_types.h"
# 89 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3D(cudaPitchedPtr *, cudaExtent);
extern "C" cudaError_t cudaMalloc3DArray(cudaArray **, const cudaChannelFormatDesc *, cudaExtent);
extern "C" cudaError_t cudaMemset3D(cudaPitchedPtr, int, cudaExtent);
extern "C" cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms *);
extern "C" cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms *, cudaStream_t);
# 102 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc(void **, size_t);
extern "C" cudaError_t cudaMallocHost(void **, size_t);
extern "C" cudaError_t cudaMallocPitch(void **, size_t *, size_t, size_t);
extern "C" cudaError_t cudaMallocArray(cudaArray **, const cudaChannelFormatDesc *, size_t, size_t = (1));
extern "C" cudaError_t cudaFree(void *);
extern "C" cudaError_t cudaFreeHost(void *);
extern "C" cudaError_t cudaFreeArray(cudaArray *);

extern "C" cudaError_t cudaHostAlloc(void **, size_t, unsigned);
extern "C" cudaError_t cudaHostGetDevicePointer(void **, void *, unsigned);
extern "C" cudaError_t cudaHostGetFlags(unsigned *, void *);
# 121 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpy(void *, const void *, size_t, cudaMemcpyKind);
extern "C" cudaError_t cudaMemcpyToArray(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind);
extern "C" cudaError_t cudaMemcpyFromArray(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind);
extern "C" cudaError_t cudaMemcpyArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
extern "C" cudaError_t cudaMemcpy2D(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
extern "C" cudaError_t cudaMemcpy2DToArray(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind);
extern "C" cudaError_t cudaMemcpy2DFromArray(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind);
extern "C" cudaError_t cudaMemcpy2DArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice);
extern "C" cudaError_t cudaMemcpyToSymbol(const char *, const void *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyHostToDevice);
extern "C" cudaError_t cudaMemcpyFromSymbol(void *, const char *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyDeviceToHost);
# 138 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemcpyAsync(void *, const void *, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpy2DAsync(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char *, const void *, size_t, size_t, cudaMemcpyKind, cudaStream_t);
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void *, const char *, size_t, size_t, cudaMemcpyKind, cudaStream_t);
# 153 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMemset(void *, int, size_t);
extern "C" cudaError_t cudaMemset2D(void *, size_t, int, size_t, size_t);
# 162 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetSymbolAddress(void **, const char *);
extern "C" cudaError_t cudaGetSymbolSize(size_t *, const char *);
# 171 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetDeviceCount(int *);
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp *, int);
extern "C" cudaError_t cudaChooseDevice(int *, const cudaDeviceProp *);
extern "C" cudaError_t cudaSetDevice(int);
extern "C" cudaError_t cudaGetDevice(int *);
extern "C" cudaError_t cudaSetValidDevices(int *, int);
extern "C" cudaError_t cudaSetDeviceFlags(int);
# 185 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaBindTexture(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U));
extern "C" cudaError_t cudaBindTexture2D(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t, size_t, size_t);
extern "C" cudaError_t cudaBindTextureToArray(const textureReference *, const cudaArray *, const cudaChannelFormatDesc *);
extern "C" cudaError_t cudaUnbindTexture(const textureReference *);
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t *, const textureReference *);
extern "C" cudaError_t cudaGetTextureReference(const textureReference **, const char *);
# 198 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc *, const cudaArray *);
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int, int, int, int, cudaChannelFormatKind);
# 207 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaGetLastError();
extern "C" const char *cudaGetErrorString(cudaError_t);
# 216 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaConfigureCall(dim3, dim3, size_t = (0), cudaStream_t = (0));
extern "C" cudaError_t cudaSetupArgument(const void *, size_t, size_t);
extern "C" cudaError_t cudaLaunch(const char *);
extern "C" cudaError_t cudaFuncGetAttributes(cudaFuncAttributes *, const char *);
# 227 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaStreamCreate(cudaStream_t *);
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t);
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t);
extern "C" cudaError_t cudaStreamQuery(cudaStream_t);
# 238 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaEventCreate(cudaEvent_t *);
extern "C" cudaError_t cudaEventCreateWithFlags(cudaEvent_t *, int);
extern "C" cudaError_t cudaEventRecord(cudaEvent_t, cudaStream_t);
extern "C" cudaError_t cudaEventQuery(cudaEvent_t);
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t);
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t);
extern "C" cudaError_t cudaEventElapsedTime(float *, cudaEvent_t, cudaEvent_t);
# 252 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaSetDoubleForDevice(double *);
extern "C" cudaError_t cudaSetDoubleForHost(double *);
# 261 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaThreadExit();
extern "C" cudaError_t cudaThreadSynchronize();
# 270 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaDriverGetVersion(int *);
extern "C" cudaError_t cudaRuntimeGetVersion(int *);
# 93 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<class T> inline cudaChannelFormatDesc cudaCreateChannelDesc()
{
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char> ()
{
auto int e = (((int)sizeof(char)) * 8);




return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);

}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> ()
{
auto int e = (((int)sizeof(signed char)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> ()
{
auto int e = (((int)sizeof(unsigned char)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> ()
{
auto int e = (((int)sizeof(signed char)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> ()
{
auto int e = (((int)sizeof(unsigned char)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> ()
{
auto int e = (((int)sizeof(signed char)) * 8);

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> ()
{
auto int e = (((int)sizeof(unsigned char)) * 8);

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> ()
{
auto int e = (((int)sizeof(signed char)) * 8);

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> ()
{
auto int e = (((int)sizeof(unsigned char)) * 8);

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short> ()
{
auto int e = (((int)sizeof(short)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> ()
{
auto int e = (((int)sizeof(unsigned short)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> ()
{
auto int e = (((int)sizeof(short)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> ()
{
auto int e = (((int)sizeof(unsigned short)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> ()
{
auto int e = (((int)sizeof(short)) * 8);

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> ()
{
auto int e = (((int)sizeof(unsigned short)) * 8);

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> ()
{
auto int e = (((int)sizeof(short)) * 8);

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> ()
{
auto int e = (((int)sizeof(unsigned short)) * 8);

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int> ()
{
auto int e = (((int)sizeof(int)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> ()
{
auto int e = (((int)sizeof(unsigned)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> ()
{
auto int e = (((int)sizeof(int)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> ()
{
auto int e = (((int)sizeof(unsigned)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> ()
{
auto int e = (((int)sizeof(int)) * 8);

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> ()
{
auto int e = (((int)sizeof(unsigned)) * 8);

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> ()
{
auto int e = (((int)sizeof(int)) * 8);

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> ()
{
auto int e = (((int)sizeof(unsigned)) * 8);

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
}



template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< long> ()
{
auto int e = (((int)sizeof(long)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned long> ()
{
auto int e = (((int)sizeof(unsigned long)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< long1> ()
{
auto int e = (((int)sizeof(long)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong1> ()
{
auto int e = (((int)sizeof(unsigned long)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< long2> ()
{
auto int e = (((int)sizeof(long)) * 8);

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong2> ()
{
auto int e = (((int)sizeof(unsigned long)) * 8);

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< long4> ()
{
auto int e = (((int)sizeof(long)) * 8);

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong4> ()
{
auto int e = (((int)sizeof(unsigned long)) * 8);

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned);
}



template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float> ()
{
auto int e = (((int)sizeof(float)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> ()
{
auto int e = (((int)sizeof(float)) * 8);

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> ()
{
auto int e = (((int)sizeof(float)) * 8);

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat);
}

template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> ()
{
auto int e = (((int)sizeof(float)) * 8);

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat);
}
# 54 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz)
{
auto cudaPitchedPtr s;

(s.ptr) = d;
(s.pitch) = p;
(s.xsize) = xsz;
(s.ysize) = ysz;

return s;
}

static inline cudaPos make_cudaPos(size_t x, size_t y, size_t z)
{
auto cudaPos p;

(p.x) = x;
(p.y) = y;
(p.z) = z;

return p;
}

static inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d)
{
auto cudaExtent e;

(e.width) = w;
(e.height) = h;
(e.depth) = d;

return e;
}
# 54 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char1 make_char1(signed char x)
{
auto char1 t; (t.x) = x; return t;
}

static inline uchar1 make_uchar1(unsigned char x)
{
auto uchar1 t; (t.x) = x; return t;
}

static inline char2 make_char2(signed char x, signed char y)
{
auto char2 t; (t.x) = x; (t.y) = y; return t;
}

static inline uchar2 make_uchar2(unsigned char x, unsigned char y)
{
auto uchar2 t; (t.x) = x; (t.y) = y; return t;
}

static inline char3 make_char3(signed char x, signed char y, signed char z)
{
auto char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
}

static inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z)
{
auto uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
}

static inline char4 make_char4(signed char x, signed char y, signed char z, signed char w)
{
auto char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
}

static inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w)
{
auto uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
}

static inline short1 make_short1(short x)
{
auto short1 t; (t.x) = x; return t;
}

static inline ushort1 make_ushort1(unsigned short x)
{
auto ushort1 t; (t.x) = x; return t;
}

static inline short2 make_short2(short x, short y)
{
auto short2 t; (t.x) = x; (t.y) = y; return t;
}

static inline ushort2 make_ushort2(unsigned short x, unsigned short y)
{
auto ushort2 t; (t.x) = x; (t.y) = y; return t;
}

static inline short3 make_short3(short x, short y, short z)
{
auto short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
}

static inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z)
{
auto ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
}

static inline short4 make_short4(short x, short y, short z, short w)
{
auto short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
}

static inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w)
{
auto ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
}

static inline int1 make_int1(int x)
{
auto int1 t; (t.x) = x; return t;
}

static inline uint1 make_uint1(unsigned x)
{
auto uint1 t; (t.x) = x; return t;
}

static inline int2 make_int2(int x, int y)
{
auto int2 t; (t.x) = x; (t.y) = y; return t;
}

static inline uint2 make_uint2(unsigned x, unsigned y)
{
auto uint2 t; (t.x) = x; (t.y) = y; return t;
}

static inline int3 make_int3(int x, int y, int z)
{
auto int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
}

static inline uint3 make_uint3(unsigned x, unsigned y, unsigned z)
{
auto uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
}

static inline int4 make_int4(int x, int y, int z, int w)
{
auto int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
}

static inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w)
{
auto uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
}

static inline long1 make_long1(long x)
{
auto long1 t; (t.x) = x; return t;
}

static inline ulong1 make_ulong1(unsigned long x)
{
auto ulong1 t; (t.x) = x; return t;
}

static inline long2 make_long2(long x, long y)
{
auto long2 t; (t.x) = x; (t.y) = y; return t;
}

static inline ulong2 make_ulong2(unsigned long x, unsigned long y)
{
auto ulong2 t; (t.x) = x; (t.y) = y; return t;
}



static inline long3 make_long3(long x, long y, long z)
{
auto long3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
}

static inline ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z)
{
auto ulong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
}

static inline long4 make_long4(long x, long y, long z, long w)
{
auto long4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
}

static inline ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z, unsigned long w)
{
auto ulong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
}



static inline float1 make_float1(float x)
{
auto float1 t; (t.x) = x; return t;
}

static inline float2 make_float2(float x, float y)
{
auto float2 t; (t.x) = x; (t.y) = y; return t;
}

static inline float3 make_float3(float x, float y, float z)
{
auto float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t;
}

static inline float4 make_float4(float x, float y, float z, float w)
{
auto float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t;
}

static inline longlong1 make_longlong1(long long x)
{
auto longlong1 t; (t.x) = x; return t;
}

static inline ulonglong1 make_ulonglong1(unsigned long long x)
{
auto ulonglong1 t; (t.x) = x; return t;
}

static inline longlong2 make_longlong2(long long x, long long y)
{
auto longlong2 t; (t.x) = x; (t.y) = y; return t;
}

static inline ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y)
{
auto ulonglong2 t; (t.x) = x; (t.y) = y; return t;
}

static inline double1 make_double1(double x)
{
auto double1 t; (t.x) = x; return t;
}

static inline double2 make_double2(double x, double y)
{
auto double2 t; (t.x) = x; (t.y) = y; return t;
}
# 31 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned char __u_char; }
extern "C" { typedef unsigned short __u_short; }
extern "C" { typedef unsigned __u_int; }
extern "C" { typedef unsigned long __u_long; }


extern "C" { typedef signed char __int8_t; }
extern "C" { typedef unsigned char __uint8_t; }
extern "C" { typedef signed short __int16_t; }
extern "C" { typedef unsigned short __uint16_t; }
extern "C" { typedef signed int __int32_t; }
extern "C" { typedef unsigned __uint32_t; }




extern "C" { typedef signed long long __int64_t; }
extern "C" { typedef unsigned long long __uint64_t; }
# 56 "/usr/include/bits/types.h" 3
extern "C" { typedef long long __quad_t; }
extern "C" { typedef unsigned long long __u_quad_t; }
# 134 "/usr/include/bits/types.h" 3
extern "C" { typedef __u_quad_t __dev_t; }
extern "C" { typedef unsigned __uid_t; }
extern "C" { typedef unsigned __gid_t; }
extern "C" { typedef unsigned long __ino_t; }
extern "C" { typedef __u_quad_t __ino64_t; }
extern "C" { typedef unsigned __mode_t; }
extern "C" { typedef unsigned __nlink_t; }
extern "C" { typedef long __off_t; }
extern "C" { typedef __quad_t __off64_t; }
extern "C" { typedef int __pid_t; }
extern "C" { typedef struct __fsid_t { int __val[2]; } __fsid_t; }
extern "C" { typedef long __clock_t; }
extern "C" { typedef unsigned long __rlim_t; }
extern "C" { typedef __u_quad_t __rlim64_t; }
extern "C" { typedef unsigned __id_t; }
extern "C" { typedef long __time_t; }
extern "C" { typedef unsigned __useconds_t; }
extern "C" { typedef long __suseconds_t; }

extern "C" { typedef int __daddr_t; }
extern "C" { typedef long __swblk_t; }
extern "C" { typedef int __key_t; }


extern "C" { typedef int __clockid_t; }


extern "C" { typedef void *__timer_t; }


extern "C" { typedef long __blksize_t; }




extern "C" { typedef long __blkcnt_t; }
extern "C" { typedef __quad_t __blkcnt64_t; }


extern "C" { typedef unsigned long __fsblkcnt_t; }
extern "C" { typedef __u_quad_t __fsblkcnt64_t; }


extern "C" { typedef unsigned long __fsfilcnt_t; }
extern "C" { typedef __u_quad_t __fsfilcnt64_t; }

extern "C" { typedef int __ssize_t; }



extern "C" { typedef __off64_t __loff_t; }
extern "C" { typedef __quad_t *__qaddr_t; }
extern "C" { typedef char *__caddr_t; }


extern "C" { typedef int __intptr_t; }


extern "C" { typedef unsigned __socklen_t; }
# 61 "/usr/include/time.h" 3
extern "C" { typedef __clock_t clock_t; }
# 77 "/usr/include/time.h" 3
extern "C" { typedef __time_t time_t; }
# 93 "/usr/include/time.h" 3
extern "C" { typedef __clockid_t clockid_t; }
# 105 "/usr/include/time.h" 3
extern "C" { typedef __timer_t timer_t; }
# 121 "/usr/include/time.h" 3
extern "C" { struct timespec {

__time_t tv_sec;
long tv_nsec;
}; }
# 134 "/usr/include/time.h" 3
extern "C" { struct tm {

int tm_sec;
int tm_min;
int tm_hour;
int tm_mday;
int tm_mon;
int tm_year;
int tm_wday;
int tm_yday;
int tm_isdst;


long tm_gmtoff;
const char *tm_zone;




}; }
# 162 "/usr/include/time.h" 3
extern "C" { struct itimerspec {

timespec it_interval;
timespec it_value;
}; }


struct sigevent;
# 175 "/usr/include/time.h" 3
extern "C" { typedef __pid_t pid_t; }
# 184 "/usr/include/time.h" 3
extern "C" __attribute__((__weak__)) clock_t clock() throw();


extern "C" time_t time(time_t *) throw();


extern "C" double difftime(time_t, time_t) throw() __attribute__((__const__));



extern "C" time_t mktime(tm *) throw();
# 200 "/usr/include/time.h" 3
extern "C" size_t strftime(char *__restrict__, size_t, const char *__restrict__, const tm *__restrict__) throw();
# 208 "/usr/include/time.h" 3
extern "C" char *strptime(const char *__restrict__, const char *__restrict__, tm *) throw();
# 40 "/usr/include/xlocale.h" 3
extern "C" { typedef
# 28 "/usr/include/xlocale.h" 3
struct __locale_struct {


struct locale_data *__locales[13];


const unsigned short *__ctype_b;
const int *__ctype_tolower;
const int *__ctype_toupper;


const char *__names[13];
} *__locale_t; }
# 218 "/usr/include/time.h" 3
extern "C" size_t strftime_l(char *__restrict__, size_t, const char *__restrict__, const tm *__restrict__, __locale_t) throw();




extern "C" char *strptime_l(const char *__restrict__, const char *__restrict__, tm *, __locale_t) throw();
# 232 "/usr/include/time.h" 3
extern "C" tm *gmtime(const time_t *) throw();



extern "C" tm *localtime(const time_t *) throw();
# 242 "/usr/include/time.h" 3
extern "C" tm *gmtime_r(const time_t *__restrict__, tm *__restrict__) throw();




extern "C" tm *localtime_r(const time_t *__restrict__, tm *__restrict__) throw();
# 254 "/usr/include/time.h" 3
extern "C" char *asctime(const tm *) throw();


extern "C" char *ctime(const time_t *) throw();
# 265 "/usr/include/time.h" 3
extern "C" char *asctime_r(const tm *__restrict__, char *__restrict__) throw();



extern "C" char *ctime_r(const time_t *__restrict__, char *__restrict__) throw();
# 275 "/usr/include/time.h" 3
extern "C" { extern char *__tzname[2]; }
extern "C" { extern int __daylight; }
extern "C" { extern long __timezone; }




extern "C" { extern char *tzname[2]; }



extern "C" void tzset() throw();



extern "C" { extern int daylight; }
extern "C" { extern long timezone; }
# 297 "/usr/include/time.h" 3
extern "C" int stime(const time_t *) throw();
# 312 "/usr/include/time.h" 3
extern "C" time_t timegm(tm *) throw();


extern "C" time_t timelocal(tm *) throw();


extern "C" int dysize(int) throw() __attribute__((__const__));
# 327 "/usr/include/time.h" 3
extern "C" int nanosleep(const timespec *, timespec *);




extern "C" int clock_getres(clockid_t, timespec *) throw();


extern "C" int clock_gettime(clockid_t, timespec *) throw();


extern "C" int clock_settime(clockid_t, const timespec *) throw();
# 346 "/usr/include/time.h" 3
extern "C" int clock_nanosleep(clockid_t, int, const timespec *, timespec *);




extern "C" int clock_getcpuclockid(pid_t, clockid_t *) throw();




extern "C" int timer_create(clockid_t, sigevent *__restrict__, timer_t *__restrict__) throw();




extern "C" int timer_delete(timer_t) throw();


extern "C" int timer_settime(timer_t, int, const itimerspec *__restrict__, itimerspec *__restrict__) throw();




extern "C" int timer_gettime(timer_t, itimerspec *) throw();



extern "C" int timer_getoverrun(timer_t) throw();
# 389 "/usr/include/time.h" 3
extern "C" { extern int getdate_err; }
# 398 "/usr/include/time.h" 3
extern "C" tm *getdate(const char *);
# 412 "/usr/include/time.h" 3
extern "C" int getdate_r(const char *__restrict__, tm *__restrict__);
# 38 "/usr/include/string.h" 3
extern "C" __attribute__((__weak__)) void *memcpy(void *__restrict__, const void *__restrict__, size_t) throw();




extern "C" void *memmove(void *, const void *, size_t) throw();
# 51 "/usr/include/string.h" 3
extern "C" void *memccpy(void *__restrict__, const void *__restrict__, int, size_t) throw();
# 59 "/usr/include/string.h" 3
extern "C" __attribute__((__weak__)) void *memset(void *, int, size_t) throw();


extern "C" int memcmp(const void *, const void *, size_t) throw() __attribute__((__pure__));



extern "C" void *memchr(const void *, int, size_t) throw() __attribute__((__pure__));
# 73 "/usr/include/string.h" 3
extern "C" void *rawmemchr(const void *, int) throw() __attribute__((__pure__));



extern "C" void *memrchr(const void *, int, size_t) throw() __attribute__((__pure__));
# 84 "/usr/include/string.h" 3
extern "C" char *strcpy(char *__restrict__, const char *__restrict__) throw();


extern "C" char *strncpy(char *__restrict__, const char *__restrict__, size_t) throw();




extern "C" char *strcat(char *__restrict__, const char *__restrict__) throw();


extern "C" char *strncat(char *__restrict__, const char *__restrict__, size_t) throw();



extern "C" int strcmp(const char *, const char *) throw() __attribute__((__pure__));


extern "C" int strncmp(const char *, const char *, size_t) throw() __attribute__((__pure__));



extern "C" int strcoll(const char *, const char *) throw() __attribute__((__pure__));


extern "C" size_t strxfrm(char *__restrict__, const char *__restrict__, size_t) throw();
# 121 "/usr/include/string.h" 3
extern "C" int strcoll_l(const char *, const char *, __locale_t) throw() __attribute__((__pure__));


extern "C" size_t strxfrm_l(char *, const char *, size_t, __locale_t) throw();
# 130 "/usr/include/string.h" 3
extern "C" char *strdup(const char *) throw() __attribute__((__malloc__));
# 138 "/usr/include/string.h" 3
extern "C" char *strndup(const char *, size_t) throw() __attribute__((__malloc__));
# 167 "/usr/include/string.h" 3
extern "C" char *strchr(const char *, int) throw() __attribute__((__pure__));


extern "C" char *strrchr(const char *, int) throw() __attribute__((__pure__));
# 177 "/usr/include/string.h" 3
extern "C" char *strchrnul(const char *, int) throw() __attribute__((__pure__));
# 184 "/usr/include/string.h" 3
extern "C" size_t strcspn(const char *, const char *) throw() __attribute__((__pure__));



extern "C" size_t strspn(const char *, const char *) throw() __attribute__((__pure__));


extern "C" char *strpbrk(const char *, const char *) throw() __attribute__((__pure__));


extern "C" char *strstr(const char *, const char *) throw() __attribute__((__pure__));




extern "C" char *strtok(char *__restrict__, const char *__restrict__) throw();
# 205 "/usr/include/string.h" 3
extern "C" char *__strtok_r(char *__restrict__, const char *__restrict__, char **__restrict__) throw();




extern "C" char *strtok_r(char *__restrict__, const char *__restrict__, char **__restrict__) throw();
# 217 "/usr/include/string.h" 3
extern "C" char *strcasestr(const char *, const char *) throw() __attribute__((__pure__));
# 225 "/usr/include/string.h" 3
extern "C" void *memmem(const void *, size_t, const void *, size_t) throw() __attribute__((__pure__));
# 231 "/usr/include/string.h" 3
extern "C" void *__mempcpy(void *__restrict__, const void *__restrict__, size_t) throw();


extern "C" void *mempcpy(void *__restrict__, const void *__restrict__, size_t) throw();
# 242 "/usr/include/string.h" 3
extern "C" size_t strlen(const char *) throw() __attribute__((__pure__));
# 249 "/usr/include/string.h" 3
extern "C" size_t strnlen(const char *, size_t) throw() __attribute__((__pure__));
# 256 "/usr/include/string.h" 3
extern "C" char *strerror(int) throw();
# 281 "/usr/include/string.h" 3
extern "C" char *strerror_r(int, char *, size_t) throw();
# 288 "/usr/include/string.h" 3
extern "C" char *strerror_l(int, __locale_t) throw();
# 294 "/usr/include/string.h" 3
extern "C" void __bzero(void *, size_t) throw();



extern "C" void bcopy(const void *, void *, size_t) throw();



extern "C" void bzero(void *, size_t) throw();


extern "C" int bcmp(const void *, const void *, size_t) throw() __attribute__((__pure__));



extern "C" char *index(const char *, int) throw() __attribute__((__pure__));



extern "C" char *rindex(const char *, int) throw() __attribute__((__pure__));




extern "C" int ffs(int) throw() __attribute__((__const__));




extern "C" int ffsl(long) throw() __attribute__((__const__));

extern "C" int ffsll(long long) throw() __attribute__((__const__));
# 331 "/usr/include/string.h" 3
extern "C" int strcasecmp(const char *, const char *) throw() __attribute__((__pure__));



extern "C" int strncasecmp(const char *, const char *, size_t) throw() __attribute__((__pure__));
# 342 "/usr/include/string.h" 3
extern "C" int strcasecmp_l(const char *, const char *, __locale_t) throw() __attribute__((__pure__));



extern "C" int strncasecmp_l(const char *, const char *, size_t, __locale_t) throw() __attribute__((__pure__));
# 354 "/usr/include/string.h" 3
extern "C" char *strsep(char **__restrict__, const char *__restrict__) throw();
# 361 "/usr/include/string.h" 3
extern "C" int strverscmp(const char *, const char *) throw() __attribute__((__pure__));



extern "C" char *strsignal(int) throw();


extern "C" char *__stpcpy(char *__restrict__, const char *__restrict__) throw();

extern "C" char *stpcpy(char *__restrict__, const char *__restrict__) throw();




extern "C" char *__stpncpy(char *__restrict__, const char *__restrict__, size_t) throw();


extern "C" char *stpncpy(char *__restrict__, const char *__restrict__, size_t) throw();




extern "C" char *strfry(char *) throw();


extern "C" void *memfrob(void *, size_t) throw();
# 393 "/usr/include/string.h" 3
extern "C" char *basename(const char *) throw();
# 56 "/usr/local/cuda/bin/../include/common_functions.h"
extern "C" __attribute__((__weak__)) clock_t clock() throw();


extern "C" __attribute__((__weak__)) void *memset(void *, int, size_t) throw();


extern "C" __attribute__((__weak__)) void *memcpy(void *, const void *, size_t) throw();
# 65 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int abs(int) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) long labs(long) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) long long llabs(long long) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) double fabs(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float fabsf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) int min(int, int);

extern "C" __attribute__((__weak__)) unsigned umin(unsigned, unsigned);

extern "C" __attribute__((__weak__)) long long llmin(long long, long long);

extern "C" __attribute__((__weak__)) unsigned long long ullmin(unsigned long long, unsigned long long);

extern "C" __attribute__((__weak__)) float fminf(float, float) throw();

extern "C" __attribute__((__weak__)) double fmin(double, double) throw();


extern "C" __attribute__((__weak__)) int max(int, int);

extern "C" __attribute__((__weak__)) unsigned umax(unsigned, unsigned);

extern "C" __attribute__((__weak__)) long long llmax(long long, long long);

extern "C" __attribute__((__weak__)) unsigned long long ullmax(unsigned long long, unsigned long long);

extern "C" __attribute__((__weak__)) float fmaxf(float, float) throw();

extern "C" __attribute__((__weak__)) double fmax(double, double) throw();


extern "C" __attribute__((__weak__)) double sin(double) throw();

extern "C" __attribute__((__weak__)) float sinf(float) throw();


extern "C" __attribute__((__weak__)) double cos(double) throw();

extern "C" __attribute__((__weak__)) float cosf(float) throw();


extern "C" __attribute__((__weak__)) void sincos(double, double *, double *) throw();

extern "C" __attribute__((__weak__)) void sincosf(float, float *, float *) throw();


extern "C" __attribute__((__weak__)) double tan(double) throw();

extern "C" __attribute__((__weak__)) float tanf(float) throw();


extern "C" __attribute__((__weak__)) double sqrt(double) throw();

extern "C" __attribute__((__weak__)) float sqrtf(float) throw();


extern "C" __attribute__((__weak__)) double rsqrt(double);

extern "C" __attribute__((__weak__)) float rsqrtf(float);


extern "C" __attribute__((__weak__)) double exp2(double) throw();

extern "C" __attribute__((__weak__)) float exp2f(float) throw();


extern "C" __attribute__((__weak__)) double exp10(double) throw();

extern "C" __attribute__((__weak__)) float exp10f(float) throw();


extern "C" __attribute__((__weak__)) double expm1(double) throw();

extern "C" __attribute__((__weak__)) float expm1f(float) throw();


extern "C" __attribute__((__weak__)) double log2(double) throw();

extern "C" __attribute__((__weak__)) float log2f(float) throw();


extern "C" __attribute__((__weak__)) double log10(double) throw();

extern "C" __attribute__((__weak__)) float log10f(float) throw();


extern "C" __attribute__((__weak__)) double log(double) throw();

extern "C" __attribute__((__weak__)) float logf(float) throw();


extern "C" __attribute__((__weak__)) double log1p(double) throw();

extern "C" __attribute__((__weak__)) float log1pf(float) throw();


extern "C" __attribute__((__weak__)) double floor(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float floorf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double exp(double) throw();

extern "C" __attribute__((__weak__)) float expf(float) throw();


extern "C" __attribute__((__weak__)) double cosh(double) throw();

extern "C" __attribute__((__weak__)) float coshf(float) throw();


extern "C" __attribute__((__weak__)) double sinh(double) throw();

extern "C" __attribute__((__weak__)) float sinhf(float) throw();


extern "C" __attribute__((__weak__)) double tanh(double) throw();

extern "C" __attribute__((__weak__)) float tanhf(float) throw();


extern "C" __attribute__((__weak__)) double acosh(double) throw();

extern "C" __attribute__((__weak__)) float acoshf(float) throw();


extern "C" __attribute__((__weak__)) double asinh(double) throw();

extern "C" __attribute__((__weak__)) float asinhf(float) throw();


extern "C" __attribute__((__weak__)) double atanh(double) throw();

extern "C" __attribute__((__weak__)) float atanhf(float) throw();


extern "C" __attribute__((__weak__)) double ldexp(double, int) throw();

extern "C" __attribute__((__weak__)) float ldexpf(float, int) throw();


extern "C" __attribute__((__weak__)) double logb(double) throw();

extern "C" __attribute__((__weak__)) float logbf(float) throw();


extern "C" __attribute__((__weak__)) int ilogb(double) throw();

extern "C" __attribute__((__weak__)) int ilogbf(float) throw();


extern "C" __attribute__((__weak__)) double scalbn(double, int) throw();

extern "C" __attribute__((__weak__)) float scalbnf(float, int) throw();


extern "C" __attribute__((__weak__)) double scalbln(double, long) throw();

extern "C" __attribute__((__weak__)) float scalblnf(float, long) throw();


extern "C" __attribute__((__weak__)) double frexp(double, int *) throw();

extern "C" __attribute__((__weak__)) float frexpf(float, int *) throw();


extern "C" __attribute__((__weak__)) double round(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float roundf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) long lround(double) throw();

extern "C" __attribute__((__weak__)) long lroundf(float) throw();


extern "C" __attribute__((__weak__)) long long llround(double) throw();

extern "C" __attribute__((__weak__)) long long llroundf(float) throw();


extern "C" __attribute__((__weak__)) double rint(double) throw();

extern "C" __attribute__((__weak__)) float rintf(float) throw();


extern "C" __attribute__((__weak__)) long lrint(double) throw();

extern "C" __attribute__((__weak__)) long lrintf(float) throw();


extern "C" __attribute__((__weak__)) long long llrint(double) throw();

extern "C" __attribute__((__weak__)) long long llrintf(float) throw();


extern "C" __attribute__((__weak__)) double nearbyint(double) throw();

extern "C" __attribute__((__weak__)) float nearbyintf(float) throw();


extern "C" __attribute__((__weak__)) double ceil(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float ceilf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double trunc(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float truncf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double fdim(double, double) throw();

extern "C" __attribute__((__weak__)) float fdimf(float, float) throw();


extern "C" __attribute__((__weak__)) double atan2(double, double) throw();

extern "C" __attribute__((__weak__)) float atan2f(float, float) throw();


extern "C" __attribute__((__weak__)) double atan(double) throw();

extern "C" __attribute__((__weak__)) float atanf(float) throw();


extern "C" __attribute__((__weak__)) double asin(double) throw();

extern "C" __attribute__((__weak__)) float asinf(float) throw();


extern "C" __attribute__((__weak__)) double acos(double) throw();

extern "C" __attribute__((__weak__)) float acosf(float) throw();


extern "C" __attribute__((__weak__)) double hypot(double, double) throw();

extern "C" __attribute__((__weak__)) float hypotf(float, float) throw();


extern "C" __attribute__((__weak__)) double cbrt(double) throw();

extern "C" __attribute__((__weak__)) float cbrtf(float) throw();


extern "C" __attribute__((__weak__)) double pow(double, double) throw();

extern "C" __attribute__((__weak__)) float powf(float, float) throw();


extern "C" __attribute__((__weak__)) double modf(double, double *) throw();

extern "C" __attribute__((__weak__)) float modff(float, float *) throw();


extern "C" __attribute__((__weak__)) double fmod(double, double) throw();

extern "C" __attribute__((__weak__)) float fmodf(float, float) throw();


extern "C" __attribute__((__weak__)) double remainder(double, double) throw();

extern "C" __attribute__((__weak__)) float remainderf(float, float) throw();


extern "C" __attribute__((__weak__)) double remquo(double, double, int *) throw();

extern "C" __attribute__((__weak__)) float remquof(float, float, int *) throw();


extern "C" __attribute__((__weak__)) double erf(double) throw();

extern "C" __attribute__((__weak__)) float erff(float) throw();


extern "C" __attribute__((__weak__)) double erfinv(double) throw();

extern "C" __attribute__((__weak__)) float erfinvf(float) throw();


extern "C" __attribute__((__weak__)) double erfc(double) throw();

extern "C" __attribute__((__weak__)) float erfcf(float) throw();


extern "C" __attribute__((__weak__)) double erfcinv(double) throw();

extern "C" __attribute__((__weak__)) float erfcinvf(float) throw();


extern "C" __attribute__((__weak__)) double lgamma(double) throw();

extern "C" __attribute__((__weak__)) float lgammaf(float) throw();


extern "C" __attribute__((__weak__)) double tgamma(double) throw();

extern "C" __attribute__((__weak__)) float tgammaf(float) throw();


extern "C" __attribute__((__weak__)) double copysign(double, double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float copysignf(float, float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double nextafter(double, double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float nextafterf(float, float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double nan(const char *) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) float nanf(const char *) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) int __isinf(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) int __isinff(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) int __isnan(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) int __isnanf(float) throw() __attribute__((__const__));
# 408 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finite(double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) int __finitef(float) throw() __attribute__((__const__));

extern "C" { extern inline __attribute__((__weak__)) int __signbit(double) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); }




extern "C" { extern inline __attribute__((__weak__)) int __signbitf(float) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); }


extern "C" __attribute__((__weak__)) double fma(double, double, double) throw();

extern "C" __attribute__((__weak__)) float fmaf(float, float, float) throw();
# 38 "/usr/include/bits/mathdef.h" 3
extern "C" { typedef long double float_t; }

extern "C" { typedef long double double_t; }
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double acos(double) throw(); extern "C" double __acos(double) throw();

extern "C" __attribute__((__weak__)) double asin(double) throw(); extern "C" double __asin(double) throw();

extern "C" __attribute__((__weak__)) double atan(double) throw(); extern "C" double __atan(double) throw();

extern "C" __attribute__((__weak__)) double atan2(double, double) throw(); extern "C" double __atan2(double, double) throw();


extern "C" __attribute__((__weak__)) double cos(double) throw(); extern "C" double __cos(double) throw();

extern "C" __attribute__((__weak__)) double sin(double) throw(); extern "C" double __sin(double) throw();

extern "C" __attribute__((__weak__)) double tan(double) throw(); extern "C" double __tan(double) throw();




extern "C" __attribute__((__weak__)) double cosh(double) throw(); extern "C" double __cosh(double) throw();

extern "C" __attribute__((__weak__)) double sinh(double) throw(); extern "C" double __sinh(double) throw();

extern "C" __attribute__((__weak__)) double tanh(double) throw(); extern "C" double __tanh(double) throw();




extern "C" __attribute__((__weak__)) void sincos(double, double *, double *) throw(); extern "C" void __sincos(double, double *, double *) throw();
# 89 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double acosh(double) throw(); extern "C" double __acosh(double) throw();

extern "C" __attribute__((__weak__)) double asinh(double) throw(); extern "C" double __asinh(double) throw();

extern "C" __attribute__((__weak__)) double atanh(double) throw(); extern "C" double __atanh(double) throw();
# 101 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double exp(double) throw(); extern "C" double __exp(double) throw();


extern "C" __attribute__((__weak__)) double frexp(double, int *) throw(); extern "C" double __frexp(double, int *) throw();


extern "C" __attribute__((__weak__)) double ldexp(double, int) throw(); extern "C" double __ldexp(double, int) throw();


extern "C" __attribute__((__weak__)) double log(double) throw(); extern "C" double __log(double) throw();


extern "C" __attribute__((__weak__)) double log10(double) throw(); extern "C" double __log10(double) throw();


extern "C" __attribute__((__weak__)) double modf(double, double *) throw(); extern "C" double __modf(double, double *) throw();




extern "C" __attribute__((__weak__)) double exp10(double) throw(); extern "C" double __exp10(double) throw();

extern "C" double pow10(double) throw(); extern "C" double __pow10(double) throw();
# 129 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double expm1(double) throw(); extern "C" double __expm1(double) throw();


extern "C" __attribute__((__weak__)) double log1p(double) throw(); extern "C" double __log1p(double) throw();


extern "C" __attribute__((__weak__)) double logb(double) throw(); extern "C" double __logb(double) throw();
# 142 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double exp2(double) throw(); extern "C" double __exp2(double) throw();


extern "C" __attribute__((__weak__)) double log2(double) throw(); extern "C" double __log2(double) throw();
# 154 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double pow(double, double) throw(); extern "C" double __pow(double, double) throw();


extern "C" __attribute__((__weak__)) double sqrt(double) throw(); extern "C" double __sqrt(double) throw();
# 163 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double hypot(double, double) throw(); extern "C" double __hypot(double, double) throw();
# 170 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double cbrt(double) throw(); extern "C" double __cbrt(double) throw();
# 179 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double ceil(double) throw() __attribute__((__const__)); extern "C" double __ceil(double) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double fabs(double) throw() __attribute__((__const__)); extern "C" double __fabs(double) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double floor(double) throw() __attribute__((__const__)); extern "C" double __floor(double) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) double fmod(double, double) throw(); extern "C" double __fmod(double, double) throw();




extern "C" __attribute__((__weak__)) int __isinf(double) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) int __finite(double) throw() __attribute__((__const__));
# 202 "/usr/include/bits/mathcalls.h" 3
extern "C" int isinf(double) throw() __attribute__((__const__));


extern "C" int finite(double) throw() __attribute__((__const__));


extern "C" double drem(double, double) throw(); extern "C" double __drem(double, double) throw();



extern "C" double significand(double) throw(); extern "C" double __significand(double) throw();
# 218 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double copysign(double, double) throw() __attribute__((__const__)); extern "C" double __copysign(double, double) throw() __attribute__((__const__));
# 225 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double nan(const char *) throw() __attribute__((__const__)); extern "C" double __nan(const char *) throw() __attribute__((__const__));
# 231 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __isnan(double) throw() __attribute__((__const__));



extern "C" int isnan(double) throw() __attribute__((__const__));


extern "C" double j0(double) throw(); extern "C" double __j0(double) throw();
extern "C" double j1(double) throw(); extern "C" double __j1(double) throw();
extern "C" double jn(int, double) throw(); extern "C" double __jn(int, double) throw();
extern "C" double y0(double) throw(); extern "C" double __y0(double) throw();
extern "C" double y1(double) throw(); extern "C" double __y1(double) throw();
extern "C" double yn(int, double) throw(); extern "C" double __yn(int, double) throw();
# 250 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double erf(double) throw(); extern "C" double __erf(double) throw();
extern "C" __attribute__((__weak__)) double erfc(double) throw(); extern "C" double __erfc(double) throw();
extern "C" __attribute__((__weak__)) double lgamma(double) throw(); extern "C" double __lgamma(double) throw();
# 259 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double tgamma(double) throw(); extern "C" double __tgamma(double) throw();
# 265 "/usr/include/bits/mathcalls.h" 3
extern "C" double gamma(double) throw(); extern "C" double __gamma(double) throw();
# 272 "/usr/include/bits/mathcalls.h" 3
extern "C" double lgamma_r(double, int *) throw(); extern "C" double __lgamma_r(double, int *) throw();
# 280 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) double rint(double) throw(); extern "C" double __rint(double) throw();


extern "C" __attribute__((__weak__)) double nextafter(double, double) throw() __attribute__((__const__)); extern "C" double __nextafter(double, double) throw() __attribute__((__const__));

extern "C" double nexttoward(double, long double) throw() __attribute__((__const__)); extern "C" double __nexttoward(double, long double) throw() __attribute__((__const__));



extern "C" __attribute__((__weak__)) double remainder(double, double) throw(); extern "C" double __remainder(double, double) throw();



extern "C" __attribute__((__weak__)) double scalbn(double, int) throw(); extern "C" double __scalbn(double, int) throw();



extern "C" __attribute__((__weak__)) int ilogb(double) throw(); extern "C" int __ilogb(double) throw();




extern "C" __attribute__((__weak__)) double scalbln(double, long) throw(); extern "C" double __scalbln(double, long) throw();



extern "C" __attribute__((__weak__)) double nearbyint(double) throw(); extern "C" double __nearbyint(double) throw();



extern "C" __attribute__((__weak__)) double round(double) throw() __attribute__((__const__)); extern "C" double __round(double) throw() __attribute__((__const__));



extern "C" __attribute__((__weak__)) double trunc(double) throw() __attribute__((__const__)); extern "C" double __trunc(double) throw() __attribute__((__const__));




extern "C" __attribute__((__weak__)) double remquo(double, double, int *) throw(); extern "C" double __remquo(double, double, int *) throw();
# 326 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long lrint(double) throw(); extern "C" long __lrint(double) throw();
extern "C" __attribute__((__weak__)) long long llrint(double) throw(); extern "C" long long __llrint(double) throw();



extern "C" __attribute__((__weak__)) long lround(double) throw(); extern "C" long __lround(double) throw();
extern "C" __attribute__((__weak__)) long long llround(double) throw(); extern "C" long long __llround(double) throw();



extern "C" __attribute__((__weak__)) double fdim(double, double) throw(); extern "C" double __fdim(double, double) throw();


extern "C" __attribute__((__weak__)) double fmax(double, double) throw(); extern "C" double __fmax(double, double) throw();


extern "C" __attribute__((__weak__)) double fmin(double, double) throw(); extern "C" double __fmin(double, double) throw();



extern "C" int __fpclassify(double) throw() __attribute__((__const__));



extern "C" { extern inline __attribute__((__weak__)) int __signbit(double) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); }




extern "C" __attribute__((__weak__)) double fma(double, double, double) throw(); extern "C" double __fma(double, double, double) throw();
# 364 "/usr/include/bits/mathcalls.h" 3
extern "C" double scalb(double, double) throw(); extern "C" double __scalb(double, double) throw();
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float acosf(float) throw(); extern "C" float __acosf(float) throw();

extern "C" __attribute__((__weak__)) float asinf(float) throw(); extern "C" float __asinf(float) throw();

extern "C" __attribute__((__weak__)) float atanf(float) throw(); extern "C" float __atanf(float) throw();

extern "C" __attribute__((__weak__)) float atan2f(float, float) throw(); extern "C" float __atan2f(float, float) throw();


extern "C" __attribute__((__weak__)) float cosf(float) throw();

extern "C" __attribute__((__weak__)) float sinf(float) throw();

extern "C" __attribute__((__weak__)) float tanf(float) throw();




extern "C" __attribute__((__weak__)) float coshf(float) throw(); extern "C" float __coshf(float) throw();

extern "C" __attribute__((__weak__)) float sinhf(float) throw(); extern "C" float __sinhf(float) throw();

extern "C" __attribute__((__weak__)) float tanhf(float) throw(); extern "C" float __tanhf(float) throw();




extern "C" __attribute__((__weak__)) void sincosf(float, float *, float *) throw();
# 89 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float acoshf(float) throw(); extern "C" float __acoshf(float) throw();

extern "C" __attribute__((__weak__)) float asinhf(float) throw(); extern "C" float __asinhf(float) throw();

extern "C" __attribute__((__weak__)) float atanhf(float) throw(); extern "C" float __atanhf(float) throw();
# 101 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float expf(float) throw();


extern "C" __attribute__((__weak__)) float frexpf(float, int *) throw(); extern "C" float __frexpf(float, int *) throw();


extern "C" __attribute__((__weak__)) float ldexpf(float, int) throw(); extern "C" float __ldexpf(float, int) throw();


extern "C" __attribute__((__weak__)) float logf(float) throw();


extern "C" __attribute__((__weak__)) float log10f(float) throw();


extern "C" __attribute__((__weak__)) float modff(float, float *) throw(); extern "C" float __modff(float, float *) throw();




extern "C" __attribute__((__weak__)) float exp10f(float) throw();

extern "C" float pow10f(float) throw(); extern "C" float __pow10f(float) throw();
# 129 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float expm1f(float) throw(); extern "C" float __expm1f(float) throw();


extern "C" __attribute__((__weak__)) float log1pf(float) throw(); extern "C" float __log1pf(float) throw();


extern "C" __attribute__((__weak__)) float logbf(float) throw(); extern "C" float __logbf(float) throw();
# 142 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float exp2f(float) throw(); extern "C" float __exp2f(float) throw();


extern "C" __attribute__((__weak__)) float log2f(float) throw();
# 154 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float powf(float, float) throw();


extern "C" __attribute__((__weak__)) float sqrtf(float) throw(); extern "C" float __sqrtf(float) throw();
# 163 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float hypotf(float, float) throw(); extern "C" float __hypotf(float, float) throw();
# 170 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float cbrtf(float) throw(); extern "C" float __cbrtf(float) throw();
# 179 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float ceilf(float) throw() __attribute__((__const__)); extern "C" float __ceilf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) float fabsf(float) throw() __attribute__((__const__)); extern "C" float __fabsf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) float floorf(float) throw() __attribute__((__const__)); extern "C" float __floorf(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) float fmodf(float, float) throw(); extern "C" float __fmodf(float, float) throw();




extern "C" __attribute__((__weak__)) int __isinff(float) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) int __finitef(float) throw() __attribute__((__const__));
# 202 "/usr/include/bits/mathcalls.h" 3
extern "C" int isinff(float) throw() __attribute__((__const__));


extern "C" int finitef(float) throw() __attribute__((__const__));


extern "C" float dremf(float, float) throw(); extern "C" float __dremf(float, float) throw();



extern "C" float significandf(float) throw(); extern "C" float __significandf(float) throw();
# 218 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float copysignf(float, float) throw() __attribute__((__const__)); extern "C" float __copysignf(float, float) throw() __attribute__((__const__));
# 225 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float nanf(const char *) throw() __attribute__((__const__)); extern "C" float __nanf(const char *) throw() __attribute__((__const__));
# 231 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __isnanf(float) throw() __attribute__((__const__));



extern "C" int isnanf(float) throw() __attribute__((__const__));


extern "C" float j0f(float) throw(); extern "C" float __j0f(float) throw();
extern "C" float j1f(float) throw(); extern "C" float __j1f(float) throw();
extern "C" float jnf(int, float) throw(); extern "C" float __jnf(int, float) throw();
extern "C" float y0f(float) throw(); extern "C" float __y0f(float) throw();
extern "C" float y1f(float) throw(); extern "C" float __y1f(float) throw();
extern "C" float ynf(int, float) throw(); extern "C" float __ynf(int, float) throw();
# 250 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float erff(float) throw(); extern "C" float __erff(float) throw();
extern "C" __attribute__((__weak__)) float erfcf(float) throw(); extern "C" float __erfcf(float) throw();
extern "C" __attribute__((__weak__)) float lgammaf(float) throw(); extern "C" float __lgammaf(float) throw();
# 259 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float tgammaf(float) throw(); extern "C" float __tgammaf(float) throw();
# 265 "/usr/include/bits/mathcalls.h" 3
extern "C" float gammaf(float) throw(); extern "C" float __gammaf(float) throw();
# 272 "/usr/include/bits/mathcalls.h" 3
extern "C" float lgammaf_r(float, int *) throw(); extern "C" float __lgammaf_r(float, int *) throw();
# 280 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) float rintf(float) throw(); extern "C" float __rintf(float) throw();


extern "C" __attribute__((__weak__)) float nextafterf(float, float) throw() __attribute__((__const__)); extern "C" float __nextafterf(float, float) throw() __attribute__((__const__));

extern "C" float nexttowardf(float, long double) throw() __attribute__((__const__)); extern "C" float __nexttowardf(float, long double) throw() __attribute__((__const__));



extern "C" __attribute__((__weak__)) float remainderf(float, float) throw(); extern "C" float __remainderf(float, float) throw();



extern "C" __attribute__((__weak__)) float scalbnf(float, int) throw(); extern "C" float __scalbnf(float, int) throw();



extern "C" __attribute__((__weak__)) int ilogbf(float) throw(); extern "C" int __ilogbf(float) throw();




extern "C" __attribute__((__weak__)) float scalblnf(float, long) throw(); extern "C" float __scalblnf(float, long) throw();



extern "C" __attribute__((__weak__)) float nearbyintf(float) throw(); extern "C" float __nearbyintf(float) throw();



extern "C" __attribute__((__weak__)) float roundf(float) throw() __attribute__((__const__)); extern "C" float __roundf(float) throw() __attribute__((__const__));



extern "C" __attribute__((__weak__)) float truncf(float) throw() __attribute__((__const__)); extern "C" float __truncf(float) throw() __attribute__((__const__));




extern "C" __attribute__((__weak__)) float remquof(float, float, int *) throw(); extern "C" float __remquof(float, float, int *) throw();
# 326 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) long lrintf(float) throw(); extern "C" long __lrintf(float) throw();
extern "C" __attribute__((__weak__)) long long llrintf(float) throw(); extern "C" long long __llrintf(float) throw();



extern "C" __attribute__((__weak__)) long lroundf(float) throw(); extern "C" long __lroundf(float) throw();
extern "C" __attribute__((__weak__)) long long llroundf(float) throw(); extern "C" long long __llroundf(float) throw();



extern "C" __attribute__((__weak__)) float fdimf(float, float) throw(); extern "C" float __fdimf(float, float) throw();


extern "C" __attribute__((__weak__)) float fmaxf(float, float) throw(); extern "C" float __fmaxf(float, float) throw();


extern "C" __attribute__((__weak__)) float fminf(float, float) throw(); extern "C" float __fminf(float, float) throw();



extern "C" int __fpclassifyf(float) throw() __attribute__((__const__));



extern "C" { extern inline __attribute__((__weak__)) int __signbitf(float) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); }




extern "C" __attribute__((__weak__)) float fmaf(float, float, float) throw(); extern "C" float __fmaf(float, float, float) throw();
# 364 "/usr/include/bits/mathcalls.h" 3
extern "C" float scalbf(float, float) throw(); extern "C" float __scalbf(float, float) throw();
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" long double acosl(long double) throw(); extern "C" long double __acosl(long double) throw();

extern "C" long double asinl(long double) throw(); extern "C" long double __asinl(long double) throw();

extern "C" long double atanl(long double) throw(); extern "C" long double __atanl(long double) throw();

extern "C" long double atan2l(long double, long double) throw(); extern "C" long double __atan2l(long double, long double) throw();


extern "C" long double cosl(long double) throw(); extern "C" long double __cosl(long double) throw();

extern "C" long double sinl(long double) throw(); extern "C" long double __sinl(long double) throw();

extern "C" long double tanl(long double) throw(); extern "C" long double __tanl(long double) throw();




extern "C" long double coshl(long double) throw(); extern "C" long double __coshl(long double) throw();

extern "C" long double sinhl(long double) throw(); extern "C" long double __sinhl(long double) throw();

extern "C" long double tanhl(long double) throw(); extern "C" long double __tanhl(long double) throw();




extern "C" void sincosl(long double, long double *, long double *) throw(); extern "C" void __sincosl(long double, long double *, long double *) throw();
# 89 "/usr/include/bits/mathcalls.h" 3
extern "C" long double acoshl(long double) throw(); extern "C" long double __acoshl(long double) throw();

extern "C" long double asinhl(long double) throw(); extern "C" long double __asinhl(long double) throw();

extern "C" long double atanhl(long double) throw(); extern "C" long double __atanhl(long double) throw();
# 101 "/usr/include/bits/mathcalls.h" 3
extern "C" long double expl(long double) throw(); extern "C" long double __expl(long double) throw();


extern "C" long double frexpl(long double, int *) throw(); extern "C" long double __frexpl(long double, int *) throw();


extern "C" long double ldexpl(long double, int) throw(); extern "C" long double __ldexpl(long double, int) throw();


extern "C" long double logl(long double) throw(); extern "C" long double __logl(long double) throw();


extern "C" long double log10l(long double) throw(); extern "C" long double __log10l(long double) throw();


extern "C" long double modfl(long double, long double *) throw(); extern "C" long double __modfl(long double, long double *) throw();




extern "C" long double exp10l(long double) throw(); extern "C" long double __exp10l(long double) throw();

extern "C" long double pow10l(long double) throw(); extern "C" long double __pow10l(long double) throw();
# 129 "/usr/include/bits/mathcalls.h" 3
extern "C" long double expm1l(long double) throw(); extern "C" long double __expm1l(long double) throw();


extern "C" long double log1pl(long double) throw(); extern "C" long double __log1pl(long double) throw();


extern "C" long double logbl(long double) throw(); extern "C" long double __logbl(long double) throw();
# 142 "/usr/include/bits/mathcalls.h" 3
extern "C" long double exp2l(long double) throw(); extern "C" long double __exp2l(long double) throw();


extern "C" long double log2l(long double) throw(); extern "C" long double __log2l(long double) throw();
# 154 "/usr/include/bits/mathcalls.h" 3
extern "C" long double powl(long double, long double) throw(); extern "C" long double __powl(long double, long double) throw();


extern "C" long double sqrtl(long double) throw(); extern "C" long double __sqrtl(long double) throw();
# 163 "/usr/include/bits/mathcalls.h" 3
extern "C" long double hypotl(long double, long double) throw(); extern "C" long double __hypotl(long double, long double) throw();
# 170 "/usr/include/bits/mathcalls.h" 3
extern "C" long double cbrtl(long double) throw(); extern "C" long double __cbrtl(long double) throw();
# 179 "/usr/include/bits/mathcalls.h" 3
extern "C" long double ceill(long double) throw() __attribute__((__const__)); extern "C" long double __ceill(long double) throw() __attribute__((__const__));


extern "C" long double fabsl(long double) throw() __attribute__((__const__)); extern "C" long double __fabsl(long double) throw() __attribute__((__const__));


extern "C" long double floorl(long double) throw() __attribute__((__const__)); extern "C" long double __floorl(long double) throw() __attribute__((__const__));


extern "C" long double fmodl(long double, long double) throw(); extern "C" long double __fmodl(long double, long double) throw();




extern "C" __attribute__((__weak__)) int __isinfl(long double) throw() __attribute__((__const__));


extern "C" __attribute__((__weak__)) int __finitel(long double) throw() __attribute__((__const__));
# 202 "/usr/include/bits/mathcalls.h" 3
extern "C" int isinfl(long double) throw() __attribute__((__const__));


extern "C" int finitel(long double) throw() __attribute__((__const__));


extern "C" long double dreml(long double, long double) throw(); extern "C" long double __dreml(long double, long double) throw();



extern "C" long double significandl(long double) throw(); extern "C" long double __significandl(long double) throw();
# 218 "/usr/include/bits/mathcalls.h" 3
extern "C" long double copysignl(long double, long double) throw() __attribute__((__const__)); extern "C" long double __copysignl(long double, long double) throw() __attribute__((__const__));
# 225 "/usr/include/bits/mathcalls.h" 3
extern "C" long double nanl(const char *) throw() __attribute__((__const__)); extern "C" long double __nanl(const char *) throw() __attribute__((__const__));
# 231 "/usr/include/bits/mathcalls.h" 3
extern "C" __attribute__((__weak__)) int __isnanl(long double) throw() __attribute__((__const__));



extern "C" int isnanl(long double) throw() __attribute__((__const__));


extern "C" long double j0l(long double) throw(); extern "C" long double __j0l(long double) throw();
extern "C" long double j1l(long double) throw(); extern "C" long double __j1l(long double) throw();
extern "C" long double jnl(int, long double) throw(); extern "C" long double __jnl(int, long double) throw();
extern "C" long double y0l(long double) throw(); extern "C" long double __y0l(long double) throw();
extern "C" long double y1l(long double) throw(); extern "C" long double __y1l(long double) throw();
extern "C" long double ynl(int, long double) throw(); extern "C" long double __ynl(int, long double) throw();
# 250 "/usr/include/bits/mathcalls.h" 3
extern "C" long double erfl(long double) throw(); extern "C" long double __erfl(long double) throw();
extern "C" long double erfcl(long double) throw(); extern "C" long double __erfcl(long double) throw();
extern "C" long double lgammal(long double) throw(); extern "C" long double __lgammal(long double) throw();
# 259 "/usr/include/bits/mathcalls.h" 3
extern "C" long double tgammal(long double) throw(); extern "C" long double __tgammal(long double) throw();
# 265 "/usr/include/bits/mathcalls.h" 3
extern "C" long double gammal(long double) throw(); extern "C" long double __gammal(long double) throw();
# 272 "/usr/include/bits/mathcalls.h" 3
extern "C" long double lgammal_r(long double, int *) throw(); extern "C" long double __lgammal_r(long double, int *) throw();
# 280 "/usr/include/bits/mathcalls.h" 3
extern "C" long double rintl(long double) throw(); extern "C" long double __rintl(long double) throw();


extern "C" long double nextafterl(long double, long double) throw() __attribute__((__const__)); extern "C" long double __nextafterl(long double, long double) throw() __attribute__((__const__));

extern "C" long double nexttowardl(long double, long double) throw() __attribute__((__const__)); extern "C" long double __nexttowardl(long double, long double) throw() __attribute__((__const__));



extern "C" long double remainderl(long double, long double) throw(); extern "C" long double __remainderl(long double, long double) throw();



extern "C" long double scalbnl(long double, int) throw(); extern "C" long double __scalbnl(long double, int) throw();



extern "C" int ilogbl(long double) throw(); extern "C" int __ilogbl(long double) throw();




extern "C" long double scalblnl(long double, long) throw(); extern "C" long double __scalblnl(long double, long) throw();



extern "C" long double nearbyintl(long double) throw(); extern "C" long double __nearbyintl(long double) throw();



extern "C" long double roundl(long double) throw() __attribute__((__const__)); extern "C" long double __roundl(long double) throw() __attribute__((__const__));



extern "C" long double truncl(long double) throw() __attribute__((__const__)); extern "C" long double __truncl(long double) throw() __attribute__((__const__));




extern "C" long double remquol(long double, long double, int *) throw(); extern "C" long double __remquol(long double, long double, int *) throw();
# 326 "/usr/include/bits/mathcalls.h" 3
extern "C" long lrintl(long double) throw(); extern "C" long __lrintl(long double) throw();
extern "C" long long llrintl(long double) throw(); extern "C" long long __llrintl(long double) throw();



extern "C" long lroundl(long double) throw(); extern "C" long __lroundl(long double) throw();
extern "C" long long llroundl(long double) throw(); extern "C" long long __llroundl(long double) throw();



extern "C" long double fdiml(long double, long double) throw(); extern "C" long double __fdiml(long double, long double) throw();


extern "C" long double fmaxl(long double, long double) throw(); extern "C" long double __fmaxl(long double, long double) throw();


extern "C" long double fminl(long double, long double) throw(); extern "C" long double __fminl(long double, long double) throw();



extern "C" int __fpclassifyl(long double) throw() __attribute__((__const__));



extern "C" { extern inline __attribute__((__weak__)) int __signbitl(long double) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); }




extern "C" long double fmal(long double, long double, long double) throw(); extern "C" long double __fmal(long double, long double, long double) throw();
# 364 "/usr/include/bits/mathcalls.h" 3
extern "C" long double scalbl(long double, long double) throw(); extern "C" long double __scalbl(long double, long double) throw();
# 157 "/usr/include/math.h" 3
extern "C" { extern int signgam; }
# 199 "/usr/include/math.h" 3
enum __cuda_FP_NAN {
FP_NAN,

FP_INFINITE,

FP_ZERO,

FP_SUBNORMAL,

FP_NORMAL

};
# 291 "/usr/include/math.h" 3
extern "C" { typedef
# 285 "/usr/include/math.h" 3
enum {
_IEEE_ = (-1),
_SVID_,
_XOPEN_,
_POSIX_,
_ISOC_
} _LIB_VERSION_TYPE; }




extern "C" { extern _LIB_VERSION_TYPE _LIB_VERSION; }
# 307 "/usr/include/math.h" 3
extern "C" { struct __exception {




int type;
char *name;
double arg1;
double arg2;
double retval;
}; }


extern "C" int matherr(__exception *) throw();
# 36 "/usr/include/bits/mathinline.h" 3
extern "C" { inline __attribute__((__weak__)) __attribute__((__gnu_inline__)) __attribute__((__const__)) int __signbitf(float __x) throw()
{
auto union { float __f; int __i; } __u = {__f: __x};
return (__u.__i) < 0;
} }

extern "C" { inline __attribute__((__weak__)) __attribute__((__gnu_inline__)) __attribute__((__const__)) int __signbit(double __x) throw()
{
auto union { double __d; int __i[2]; } __u = {__d: __x};
return ((__u.__i)[1]) < 0;
} }

extern "C" { inline __attribute__((__weak__)) __attribute__((__gnu_inline__)) __attribute__((__const__)) int __signbitl(long double __x) throw()
{
auto union { long double __l; int __i[3]; } __u = {__l: __x};
return (((__u.__i)[2]) & 32768) != 0;
} }
# 67 "/usr/include/bits/waitstatus.h" 3
extern "C" { union wait {

int w_status;

struct {

unsigned __w_termsig:7;
unsigned __w_coredump:1;
unsigned __w_retcode:8;
unsigned:16;
# 84 "/usr/include/bits/waitstatus.h" 3
} __wait_terminated;

struct {

unsigned __w_stopval:8;
unsigned __w_stopsig:8;
unsigned:16;
# 97 "/usr/include/bits/waitstatus.h" 3
} __wait_stopped;
}; }
# 102 "/usr/include/stdlib.h" 3
extern "C" { typedef
# 99 "/usr/include/stdlib.h" 3
struct div_t {
int quot;
int rem;
} div_t; }
# 110 "/usr/include/stdlib.h" 3
extern "C" { typedef
# 107 "/usr/include/stdlib.h" 3
struct ldiv_t {
long quot;
long rem;
} ldiv_t; }
# 122 "/usr/include/stdlib.h" 3
extern "C" { typedef
# 119 "/usr/include/stdlib.h" 3
struct lldiv_t {
long long quot;
long long rem;
} lldiv_t; }
# 140 "/usr/include/stdlib.h" 3
extern "C" size_t __ctype_get_mb_cur_max() throw();




extern "C" { extern inline double atof(const char *) throw() __attribute__((__pure__)) __attribute__((__gnu_inline__)); }


extern "C" { extern inline int atoi(const char *) throw() __attribute__((__pure__)) __attribute__((__gnu_inline__)); }


extern "C" { extern inline long atol(const char *) throw() __attribute__((__pure__)) __attribute__((__gnu_inline__)); }
# 158 "/usr/include/stdlib.h" 3
extern "C" { extern inline long long atoll(const char *) throw() __attribute__((__pure__)) __attribute__((__gnu_inline__)); }
# 165 "/usr/include/stdlib.h" 3
extern "C" double strtod(const char *__restrict__, char **__restrict__) throw();
# 173 "/usr/include/stdlib.h" 3
extern "C" float strtof(const char *__restrict__, char **__restrict__) throw();


extern "C" long double strtold(const char *__restrict__, char **__restrict__) throw();
# 184 "/usr/include/stdlib.h" 3
extern "C" long strtol(const char *__restrict__, char **__restrict__, int) throw();



extern "C" unsigned long strtoul(const char *__restrict__, char **__restrict__, int) throw();
# 196 "/usr/include/stdlib.h" 3
extern "C" long long strtoq(const char *__restrict__, char **__restrict__, int) throw();




extern "C" unsigned long long strtouq(const char *__restrict__, char **__restrict__, int) throw();
# 210 "/usr/include/stdlib.h" 3
extern "C" long long strtoll(const char *__restrict__, char **__restrict__, int) throw();




extern "C" unsigned long long strtoull(const char *__restrict__, char **__restrict__, int) throw();
# 240 "/usr/include/stdlib.h" 3
extern "C" long strtol_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw();



extern "C" unsigned long strtoul_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw();
# 250 "/usr/include/stdlib.h" 3
extern "C" long long strtoll_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw();
# 256 "/usr/include/stdlib.h" 3
extern "C" unsigned long long strtoull_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw();




extern "C" double strtod_l(const char *__restrict__, char **__restrict__, __locale_t) throw();



extern "C" float strtof_l(const char *__restrict__, char **__restrict__, __locale_t) throw();



extern "C" long double strtold_l(const char *__restrict__, char **__restrict__, __locale_t) throw();
# 279 "/usr/include/stdlib.h" 3
extern "C" { inline __attribute__((__pure__)) __attribute__((__gnu_inline__)) double atof(const char *__nptr) throw()
{
return strtod(__nptr, (char **)__null);
} }

extern "C" { inline __attribute__((__pure__)) __attribute__((__gnu_inline__)) int atoi(const char *__nptr) throw()
{
return (int)strtol(__nptr, (char **)__null, 10);
} }

extern "C" { inline __attribute__((__pure__)) __attribute__((__gnu_inline__)) long atol(const char *__nptr) throw()
{
return strtol(__nptr, (char **)__null, 10);
} }
# 298 "/usr/include/stdlib.h" 3
extern "C" { inline __attribute__((__pure__)) __attribute__((__gnu_inline__)) long long atoll(const char *__nptr) throw()
{
return strtoll(__nptr, (char **)__null, 10);
} }
# 311 "/usr/include/stdlib.h" 3
extern "C" char *l64a(long) throw();


extern "C" long a64l(const char *) throw() __attribute__((__pure__));
# 35 "/usr/include/sys/types.h" 3
extern "C" { typedef __u_char u_char; }
extern "C" { typedef __u_short u_short; }
extern "C" { typedef __u_int u_int; }
extern "C" { typedef __u_long u_long; }
extern "C" { typedef __quad_t quad_t; }
extern "C" { typedef __u_quad_t u_quad_t; }
extern "C" { typedef __fsid_t fsid_t; }




extern "C" { typedef __loff_t loff_t; }



extern "C" { typedef __ino_t ino_t; }
# 57 "/usr/include/sys/types.h" 3
extern "C" { typedef __ino64_t ino64_t; }




extern "C" { typedef __dev_t dev_t; }




extern "C" { typedef __gid_t gid_t; }




extern "C" { typedef __mode_t mode_t; }




extern "C" { typedef __nlink_t nlink_t; }




extern "C" { typedef __uid_t uid_t; }
# 88 "/usr/include/sys/types.h" 3
extern "C" { typedef __off_t off_t; }
# 95 "/usr/include/sys/types.h" 3
extern "C" { typedef __off64_t off64_t; }
# 105 "/usr/include/sys/types.h" 3
extern "C" { typedef __id_t id_t; }




extern "C" { typedef __ssize_t ssize_t; }
# 116 "/usr/include/sys/types.h" 3
extern "C" { typedef __daddr_t daddr_t; }
extern "C" { typedef __caddr_t caddr_t; }
# 123 "/usr/include/sys/types.h" 3
extern "C" { typedef __key_t key_t; }
# 137 "/usr/include/sys/types.h" 3
extern "C" { typedef __useconds_t useconds_t; }



extern "C" { typedef __suseconds_t suseconds_t; }
# 151 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned long ulong; }
extern "C" { typedef unsigned short ushort; }
extern "C" { typedef unsigned uint; }
# 195 "/usr/include/sys/types.h" 3
extern "C" { typedef signed char int8_t; }
extern "C" { typedef short int16_t; }
extern "C" { typedef int int32_t; }
extern "C" { typedef long long int64_t; }


extern "C" { typedef unsigned char u_int8_t; }
extern "C" { typedef unsigned short u_int16_t; }
extern "C" { typedef unsigned u_int32_t; }
extern "C" { typedef unsigned long long u_int64_t; }

extern "C" { typedef int register_t; }
# 24 "/usr/include/bits/sigset.h" 3
extern "C" { typedef int __sig_atomic_t; }
# 32 "/usr/include/bits/sigset.h" 3
extern "C" { typedef
# 30 "/usr/include/bits/sigset.h" 3
struct __sigset_t {
unsigned long __val[((1024) / ((8) * sizeof(unsigned long)))];
} __sigset_t; }
# 38 "/usr/include/sys/select.h" 3
extern "C" { typedef __sigset_t sigset_t; }
# 69 "/usr/include/bits/time.h" 3
extern "C" { struct timeval {

__time_t tv_sec;
__suseconds_t tv_usec;
}; }
# 55 "/usr/include/sys/select.h" 3
extern "C" { typedef long __fd_mask; }
# 78 "/usr/include/sys/select.h" 3
extern "C" { typedef
# 68 "/usr/include/sys/select.h" 3
struct fd_set {



__fd_mask fds_bits[((1024) / ((8) * sizeof(__fd_mask)))];
# 78 "/usr/include/sys/select.h" 3
} fd_set; }
# 85 "/usr/include/sys/select.h" 3
extern "C" { typedef __fd_mask fd_mask; }
# 109 "/usr/include/sys/select.h" 3
extern "C" int select(int, fd_set *__restrict__, fd_set *__restrict__, fd_set *__restrict__, timeval *__restrict__);
# 121 "/usr/include/sys/select.h" 3
extern "C" int pselect(int, fd_set *__restrict__, fd_set *__restrict__, fd_set *__restrict__, const timespec *__restrict__, const __sigset_t *__restrict__);
# 31 "/usr/include/sys/sysmacros.h" 3
extern "C" { extern inline unsigned gnu_dev_major(unsigned long long) throw() __attribute__((__gnu_inline__)); }


extern "C" { extern inline unsigned gnu_dev_minor(unsigned long long) throw() __attribute__((__gnu_inline__)); }


extern "C" { extern inline unsigned long long gnu_dev_makedev(unsigned, unsigned) throw() __attribute__((__gnu_inline__)); }
# 43 "/usr/include/sys/sysmacros.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) unsigned gnu_dev_major(unsigned long long __dev) throw()
{
return ((__dev >> 8) & (4095)) | (((unsigned)(__dev >> 32)) & (~4095));
} }


extern "C" { inline __attribute__((__gnu_inline__)) unsigned gnu_dev_minor(unsigned long long __dev) throw()
{
return (__dev & (255)) | (((unsigned)(__dev >> 12)) & (~255));
} }


extern "C" { inline __attribute__((__gnu_inline__)) unsigned long long gnu_dev_makedev(unsigned __major, unsigned __minor) throw()
{
return (((__minor & (255)) | ((__major & (4095)) << 8)) | (((unsigned long long)(__minor & (~255))) << 12)) | (((unsigned long long)(__major & (~4095))) << 32);


} }
# 228 "/usr/include/sys/types.h" 3
extern "C" { typedef __blksize_t blksize_t; }
# 235 "/usr/include/sys/types.h" 3
extern "C" { typedef __blkcnt_t blkcnt_t; }



extern "C" { typedef __fsblkcnt_t fsblkcnt_t; }



extern "C" { typedef __fsfilcnt_t fsfilcnt_t; }
# 262 "/usr/include/sys/types.h" 3
extern "C" { typedef __blkcnt64_t blkcnt64_t; }
extern "C" { typedef __fsblkcnt64_t fsblkcnt64_t; }
extern "C" { typedef __fsfilcnt64_t fsfilcnt64_t; }
# 50 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef unsigned long pthread_t; }
# 57 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 54 "/usr/include/bits/pthreadtypes.h" 3
union pthread_attr_t {
char __size[36];
long __align;
} pthread_attr_t; }
# 70 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 67 "/usr/include/bits/pthreadtypes.h" 3
struct __pthread_internal_slist {

__pthread_internal_slist *__next;
} __pthread_slist_t; }
# 104 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 77 "/usr/include/bits/pthreadtypes.h" 3
union pthread_mutex_t {
struct __pthread_mutex_s {

int __lock;
unsigned __count;
int __owner;
# 88 "/usr/include/bits/pthreadtypes.h" 3
int __kind;
# 94 "/usr/include/bits/pthreadtypes.h" 3
unsigned __nusers;

union {
int __spins;
__pthread_slist_t __list;
};

} __data;
char __size[24];
long __align;
} pthread_mutex_t; }
# 110 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 107 "/usr/include/bits/pthreadtypes.h" 3
union pthread_mutexattr_t {
char __size[4];
int __align;
} pthread_mutexattr_t; }
# 130 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 116 "/usr/include/bits/pthreadtypes.h" 3
union pthread_cond_t {

struct {
int __lock;
unsigned __futex;
unsigned long long __total_seq;
unsigned long long __wakeup_seq;
unsigned long long __woken_seq;
void *__mutex;
unsigned __nwaiters;
unsigned __broadcast_seq;
} __data;
char __size[48];
long long __align;
} pthread_cond_t; }
# 136 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 133 "/usr/include/bits/pthreadtypes.h" 3
union pthread_condattr_t {
char __size[4];
int __align;
} pthread_condattr_t; }



extern "C" { typedef unsigned pthread_key_t; }



extern "C" { typedef int pthread_once_t; }
# 189 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 151 "/usr/include/bits/pthreadtypes.h" 3
union pthread_rwlock_t {
# 171 "/usr/include/bits/pthreadtypes.h" 3
struct {
int __lock;
unsigned __nr_readers;
unsigned __readers_wakeup;
unsigned __writer_wakeup;
unsigned __nr_readers_queued;
unsigned __nr_writers_queued;


unsigned char __flags;
unsigned char __shared;
unsigned char __pad1;
unsigned char __pad2;
int __writer;
} __data;

char __size[32];
long __align;
} pthread_rwlock_t; }
# 195 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 192 "/usr/include/bits/pthreadtypes.h" 3
union pthread_rwlockattr_t {
char __size[8];
long __align;
} pthread_rwlockattr_t; }
# 201 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef volatile int pthread_spinlock_t; }
# 210 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 207 "/usr/include/bits/pthreadtypes.h" 3
union pthread_barrier_t {
char __size[20];
long __align;
} pthread_barrier_t; }
# 216 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef
# 213 "/usr/include/bits/pthreadtypes.h" 3
union pthread_barrierattr_t {
char __size[4];
int __align;
} pthread_barrierattr_t; }
# 327 "/usr/include/stdlib.h" 3
extern "C" long random() throw();


extern "C" void srandom(unsigned) throw();
# 336 "/usr/include/stdlib.h" 3
extern "C" char *initstate(unsigned, char *, size_t) throw();




extern "C" char *setstate(char *) throw();
# 349 "/usr/include/stdlib.h" 3
extern "C" { struct random_data {

int32_t *fptr;
int32_t *rptr;
int32_t *state;
int rand_type;
int rand_deg;
int rand_sep;
int32_t *end_ptr;
}; }

extern "C" int random_r(random_data *__restrict__, int32_t *__restrict__) throw();


extern "C" int srandom_r(unsigned, random_data *) throw();


extern "C" int initstate_r(unsigned, char *__restrict__, size_t, random_data *__restrict__) throw();




extern "C" int setstate_r(char *__restrict__, random_data *__restrict__) throw();
# 380 "/usr/include/stdlib.h" 3
extern "C" int rand() throw();

extern "C" void srand(unsigned) throw();




extern "C" int rand_r(unsigned *) throw();
# 395 "/usr/include/stdlib.h" 3
extern "C" double drand48() throw();
extern "C" double erand48(unsigned short [3]) throw();


extern "C" long lrand48() throw();
extern "C" long nrand48(unsigned short [3]) throw();



extern "C" long mrand48() throw();
extern "C" long jrand48(unsigned short [3]) throw();



extern "C" void srand48(long) throw();
extern "C" unsigned short *seed48(unsigned short [3]) throw();

extern "C" void lcong48(unsigned short [7]) throw();
# 418 "/usr/include/stdlib.h" 3
extern "C" { struct drand48_data {

unsigned short __x[3];
unsigned short __old_x[3];
unsigned short __c;
unsigned short __init;
unsigned long long __a;
}; }


extern "C" int drand48_r(drand48_data *__restrict__, double *__restrict__) throw();

extern "C" int erand48_r(unsigned short [3], drand48_data *__restrict__, double *__restrict__) throw();




extern "C" int lrand48_r(drand48_data *__restrict__, long *__restrict__) throw();


extern "C" int nrand48_r(unsigned short [3], drand48_data *__restrict__, long *__restrict__) throw();
# 444 "/usr/include/stdlib.h" 3
extern "C" int mrand48_r(drand48_data *__restrict__, long *__restrict__) throw();


extern "C" int jrand48_r(unsigned short [3], drand48_data *__restrict__, long *__restrict__) throw();
# 453 "/usr/include/stdlib.h" 3
extern "C" int srand48_r(long, drand48_data *) throw();


extern "C" int seed48_r(unsigned short [3], drand48_data *) throw();


extern "C" int lcong48_r(unsigned short [7], drand48_data *) throw();
# 471 "/usr/include/stdlib.h" 3
extern "C" void *malloc(size_t) throw() __attribute__((__malloc__));

extern "C" void *calloc(size_t, size_t) throw() __attribute__((__malloc__));
# 485 "/usr/include/stdlib.h" 3
extern "C" void *realloc(void *, size_t) throw();


extern "C" void free(void *) throw();




extern "C" void cfree(void *) throw();
# 33 "/usr/include/alloca.h" 3
extern "C" void *alloca(size_t) throw();
# 502 "/usr/include/stdlib.h" 3
extern "C" void *valloc(size_t) throw() __attribute__((__malloc__));




extern "C" int posix_memalign(void **, size_t, size_t) throw();
# 513 "/usr/include/stdlib.h" 3
extern "C" void abort() throw() __attribute__((__noreturn__));



extern "C" int atexit(void (*)(void)) throw();
# 523 "/usr/include/stdlib.h" 3
extern "C" int on_exit(void (*)(int, void *), void *) throw();
# 531 "/usr/include/stdlib.h" 3
extern "C" void exit(int) throw() __attribute__((__noreturn__));
# 538 "/usr/include/stdlib.h" 3
extern "C" void _Exit(int) throw() __attribute__((__noreturn__));
# 545 "/usr/include/stdlib.h" 3
extern "C" char *getenv(const char *) throw();




extern "C" char *__secure_getenv(const char *) throw();
# 557 "/usr/include/stdlib.h" 3
extern "C" int putenv(char *) throw();
# 563 "/usr/include/stdlib.h" 3
extern "C" int setenv(const char *, const char *, int) throw();



extern "C" int unsetenv(const char *) throw();
# 574 "/usr/include/stdlib.h" 3
extern "C" int clearenv() throw();
# 583 "/usr/include/stdlib.h" 3
extern "C" char *mktemp(char *) throw();
# 594 "/usr/include/stdlib.h" 3
extern "C" int mkstemp(char *);
# 604 "/usr/include/stdlib.h" 3
extern "C" int mkstemp64(char *);
# 614 "/usr/include/stdlib.h" 3
extern "C" char *mkdtemp(char *) throw();
# 625 "/usr/include/stdlib.h" 3
extern "C" int mkostemp(char *, int);
# 635 "/usr/include/stdlib.h" 3
extern "C" int mkostemp64(char *, int);
# 645 "/usr/include/stdlib.h" 3
extern "C" int system(const char *);
# 652 "/usr/include/stdlib.h" 3
extern "C" char *canonicalize_file_name(const char *) throw();
# 662 "/usr/include/stdlib.h" 3
extern "C" char *realpath(const char *__restrict__, char *__restrict__) throw();
# 670 "/usr/include/stdlib.h" 3
extern "C" { typedef int (*__compar_fn_t)(const void *, const void *); }


extern "C" { typedef __compar_fn_t comparison_fn_t; }
# 680 "/usr/include/stdlib.h" 3
extern "C" void *bsearch(const void *, const void *, size_t, size_t, __compar_fn_t);
# 686 "/usr/include/stdlib.h" 3
extern "C" void qsort(void *, size_t, size_t, __compar_fn_t);




extern "C" __attribute__((__weak__)) int abs(int) throw() __attribute__((__const__));
extern "C" __attribute__((__weak__)) long labs(long) throw() __attribute__((__const__));



extern "C" __attribute__((__weak__)) long long llabs(long long) throw() __attribute__((__const__));
# 705 "/usr/include/stdlib.h" 3
extern "C" div_t div(int, int) throw() __attribute__((__const__));

extern "C" ldiv_t ldiv(long, long) throw() __attribute__((__const__));
# 713 "/usr/include/stdlib.h" 3
extern "C" lldiv_t lldiv(long long, long long) throw() __attribute__((__const__));
# 727 "/usr/include/stdlib.h" 3
extern "C" char *ecvt(double, int, int *__restrict__, int *__restrict__) throw();
# 733 "/usr/include/stdlib.h" 3
extern "C" char *fcvt(double, int, int *__restrict__, int *__restrict__) throw();
# 739 "/usr/include/stdlib.h" 3
extern "C" char *gcvt(double, int, char *) throw();
# 745 "/usr/include/stdlib.h" 3
extern "C" char *qecvt(long double, int, int *__restrict__, int *__restrict__) throw();


extern "C" char *qfcvt(long double, int, int *__restrict__, int *__restrict__) throw();


extern "C" char *qgcvt(long double, int, char *) throw();
# 757 "/usr/include/stdlib.h" 3
extern "C" int ecvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw();


extern "C" int fcvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw();



extern "C" int qecvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw();



extern "C" int qfcvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw();
# 779 "/usr/include/stdlib.h" 3
extern "C" int mblen(const char *, size_t) throw();


extern "C" int mbtowc(wchar_t *__restrict__, const char *__restrict__, size_t) throw();



extern "C" int wctomb(char *, wchar_t) throw();



extern "C" size_t mbstowcs(wchar_t *__restrict__, const char *__restrict__, size_t) throw();


extern "C" size_t wcstombs(char *__restrict__, const wchar_t *__restrict__, size_t) throw();
# 804 "/usr/include/stdlib.h" 3
extern "C" int rpmatch(const char *) throw();
# 815 "/usr/include/stdlib.h" 3
extern "C" int getsubopt(char **__restrict__, char *const *__restrict__, char **__restrict__) throw();
# 824 "/usr/include/stdlib.h" 3
extern "C" void setkey(const char *) throw();
# 832 "/usr/include/stdlib.h" 3
extern "C" int posix_openpt(int);
# 840 "/usr/include/stdlib.h" 3
extern "C" int grantpt(int) throw();



extern "C" int unlockpt(int) throw();




extern "C" char *ptsname(int) throw();
# 856 "/usr/include/stdlib.h" 3
extern "C" int ptsname_r(int, char *, size_t) throw();



extern "C" int getpt();
# 867 "/usr/include/stdlib.h" 3
extern "C" int getloadavg(double [], int) throw();
# 74 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {

template<class _Iterator, class _Container> class __normal_iterator;


}

namespace std __attribute__((visibility("default"))) {

struct __true_type { };
struct __false_type { };

template<bool __T0>
struct __truth_type {
typedef __false_type __type; };


template<> struct __truth_type< true> {
typedef __true_type __type; };



template<class _Sp, class _Tp>
struct __traitor {

enum __cuda___value { __value = (((bool)_Sp::__value) || ((bool)_Tp::__value))};
typedef typename __truth_type< (((bool)_Sp::__value) || ((bool)_Tp::__value))> ::__type __type;
};


template<class , class >
struct __are_same {

enum __cuda___value { __value};
typedef __false_type __type;
};

template<class _Tp>
struct __are_same< _Tp, _Tp> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<class _Tp>
struct __is_void {

enum __cuda___value { __value};
typedef __false_type __type;
};


template<> struct __is_void< void> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};




template<class _Tp>
struct __is_integer {

enum __cuda___value { __value};
typedef __false_type __type;
};
# 147 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
template<> struct __is_integer< bool> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< char> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< signed char> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< unsigned char> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};



template<> struct __is_integer< wchar_t> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};



template<> struct __is_integer< short> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< unsigned short> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< int> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< unsigned> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< long> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< unsigned long> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< long long> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_integer< unsigned long long> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};




template<class _Tp>
struct __is_floating {

enum __cuda___value { __value};
typedef __false_type __type;
};



template<> struct __is_floating< float> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_floating< double> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_floating< long double> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};




template<class _Tp>
struct __is_pointer {

enum __cuda___value { __value};
typedef __false_type __type;
};

template<class _Tp>
struct __is_pointer< _Tp *> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};




template<class _Tp>
struct __is_normal_iterator {

enum __cuda___value { __value};
typedef __false_type __type;
};

template<class _Iterator, class _Container>
struct __is_normal_iterator< __gnu_cxx::__normal_iterator< _Iterator, _Container> > {


enum __cuda___value { __value = 1};
typedef __true_type __type;
};




template<class _Tp>
struct __is_arithmetic : public __traitor< __is_integer< _Tp> , __is_floating< _Tp> > {

};




template<class _Tp>
struct __is_fundamental : public __traitor< __is_void< _Tp> , __is_arithmetic< _Tp> > {

};




template<class _Tp>
struct __is_scalar : public __traitor< __is_arithmetic< _Tp> , __is_pointer< _Tp> > {

};




template<class _Tp>
struct __is_char {

enum __cuda___value { __value};
typedef __false_type __type;
};


template<> struct __is_char< char> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};



template<> struct __is_char< wchar_t> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<class _Tp>
struct __is_byte {

enum __cuda___value { __value};
typedef __false_type __type;
};


template<> struct __is_byte< char> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_byte< signed char> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};


template<> struct __is_byte< unsigned char> {

enum __cuda___value { __value = 1};
typedef __true_type __type;
};




template<class _Tp>
struct __is_move_iterator {

enum __cuda___value { __value};
typedef __false_type __type;
};
# 406 "/usr/include/c++/4.3/bits/cpp_type_traits.h" 3
}
# 43 "/usr/include/c++/4.3/ext/type_traits.h" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {


template<bool __T1, class >
struct __enable_if {
};

template<class _Tp>
struct __enable_if< true, _Tp> {
typedef _Tp __type; };



template<bool _Cond, class _Iftrue, class _Iffalse>
struct __conditional_type {
typedef _Iftrue __type; };

template<class _Iftrue, class _Iffalse>
struct __conditional_type< false, _Iftrue, _Iffalse> {
typedef _Iffalse __type; };



template<class _Tp>
struct __add_unsigned {


private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp> __if_type;


public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type;
};


template<> struct __add_unsigned< char> {
typedef unsigned char __type; };


template<> struct __add_unsigned< signed char> {
typedef unsigned char __type; };


template<> struct __add_unsigned< short> {
typedef unsigned short __type; };


template<> struct __add_unsigned< int> {
typedef unsigned __type; };


template<> struct __add_unsigned< long> {
typedef unsigned long __type; };


template<> struct __add_unsigned< long long> {
typedef unsigned long long __type; };



template<> struct __add_unsigned< bool> ;


template<> struct __add_unsigned< wchar_t> ;



template<class _Tp>
struct __remove_unsigned {


private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp> __if_type;


public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type;
};


template<> struct __remove_unsigned< char> {
typedef signed char __type; };


template<> struct __remove_unsigned< unsigned char> {
typedef signed char __type; };


template<> struct __remove_unsigned< unsigned short> {
typedef short __type; };


template<> struct __remove_unsigned< unsigned> {
typedef int __type; };


template<> struct __remove_unsigned< unsigned long> {
typedef long __type; };


template<> struct __remove_unsigned< unsigned long long> {
typedef long long __type; };



template<> struct __remove_unsigned< bool> ;


template<> struct __remove_unsigned< wchar_t> ;



template < typename _Type >
    inline bool
    __is_null_pointer ( _Type * __ptr )
    { return __ptr == 0; }

template < typename _Type >
    inline bool
    __is_null_pointer ( _Type )
    { return false; }



template<class _Tp, bool __T2 = std::__is_integer< _Tp> ::__value>
struct __promote {
typedef double __type; };

template<class _Tp>
struct __promote< _Tp, false> {
typedef _Tp __type; };

template<class _Tp, class _Up>
struct __promote_2 {


private: typedef typename __promote< _Tp, std::__is_integer< _Tp> ::__value> ::__type __type1;
typedef typename __promote< _Up, std::__is_integer< _Up> ::__value> ::__type __type2;


public: typedef __typeof__((__type1() + __type2())) __type;
};

template<class _Tp, class _Up, class _Vp>
struct __promote_3 {


private: typedef typename __promote< _Tp, std::__is_integer< _Tp> ::__value> ::__type __type1;
typedef typename __promote< _Up, std::__is_integer< _Up> ::__value> ::__type __type2;
typedef typename __promote< _Vp, std::__is_integer< _Vp> ::__value> ::__type __type3;


public: typedef __typeof__(((__type1() + __type2()) + __type3())) __type;
};

template<class _Tp, class _Up, class _Vp, class _Wp>
struct __promote_4 {


private: typedef typename __promote< _Tp, std::__is_integer< _Tp> ::__value> ::__type __type1;
typedef typename __promote< _Up, std::__is_integer< _Up> ::__value> ::__type __type2;
typedef typename __promote< _Vp, std::__is_integer< _Vp> ::__value> ::__type __type3;
typedef typename __promote< _Wp, std::__is_integer< _Wp> ::__value> ::__type __type4;


public: typedef __typeof__((((__type1() + __type2()) + __type3()) + __type4())) __type;
};

}
# 82 "/usr/include/c++/4.3/cmath" 3
namespace std __attribute__((visibility("default"))) {



template < typename _Tp >
    _Tp __cmath_power ( _Tp, unsigned int );

template < typename _Tp >
    inline _Tp
    __pow_helper ( _Tp __x, int __n )
    {
      return __n < 0
        ? _Tp ( 1 ) / __cmath_power ( __x, - __n )
        : __cmath_power ( __x, __n );
    }


inline double abs(double __x)
{ return __builtin_fabs(__x); }


inline float abs(float __x)
{ return __builtin_fabsf(__x); }


inline long double abs(long double __x)
{ return __builtin_fabsl(__x); }

using ::acos;


inline float acos(float __x)
{ return __builtin_acosf(__x); }


inline long double acos(long double __x)
{ return __builtin_acosl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    acos ( _Tp __x )
    { return __builtin_acos ( __x ); }

using ::asin;


inline float asin(float __x)
{ return __builtin_asinf(__x); }


inline long double asin(long double __x)
{ return __builtin_asinl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    asin ( _Tp __x )
    { return __builtin_asin ( __x ); }

using ::atan;


inline float atan(float __x)
{ return __builtin_atanf(__x); }


inline long double atan(long double __x)
{ return __builtin_atanl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    atan ( _Tp __x )
    { return __builtin_atan ( __x ); }

using ::atan2;


inline float atan2(float __y, float __x)
{ return __builtin_atan2f(__y, __x); }


inline long double atan2(long double __y, long double __x)
{ return __builtin_atan2l(__y, __x); }

template < typename _Tp, typename _Up >
    inline
    typename __gnu_cxx :: __promote_2 <
    typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value
        && __is_arithmetic < _Up > :: __value,
        _Tp > :: __type, _Up > :: __type
    atan2 ( _Tp __y, _Up __x )
    {
      typedef typename __gnu_cxx :: __promote_2 < _Tp, _Up > :: __type __type;
      return atan2 ( __type ( __y ), __type ( __x ) );
    }

using ::ceil;


inline float ceil(float __x)
{ return __builtin_ceilf(__x); }


inline long double ceil(long double __x)
{ return __builtin_ceill(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    ceil ( _Tp __x )
    { return __builtin_ceil ( __x ); }

using ::cos;


inline float cos(float __x)
{ return __builtin_cosf(__x); }


inline long double cos(long double __x)
{ return __builtin_cosl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    cos ( _Tp __x )
    { return __builtin_cos ( __x ); }

using ::cosh;


inline float cosh(float __x)
{ return __builtin_coshf(__x); }


inline long double cosh(long double __x)
{ return __builtin_coshl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    cosh ( _Tp __x )
    { return __builtin_cosh ( __x ); }

using ::exp;


inline float exp(float __x)
{ return __builtin_expf(__x); }


inline long double exp(long double __x)
{ return __builtin_expl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    exp ( _Tp __x )
    { return __builtin_exp ( __x ); }

using ::fabs;


inline float fabs(float __x)
{ return __builtin_fabsf(__x); }


inline long double fabs(long double __x)
{ return __builtin_fabsl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    fabs ( _Tp __x )
    { return __builtin_fabs ( __x ); }

using ::floor;


inline float floor(float __x)
{ return __builtin_floorf(__x); }


inline long double floor(long double __x)
{ return __builtin_floorl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    floor ( _Tp __x )
    { return __builtin_floor ( __x ); }

using ::fmod;


inline float fmod(float __x, float __y)
{ return __builtin_fmodf(__x, __y); }


inline long double fmod(long double __x, long double __y)
{ return __builtin_fmodl(__x, __y); }

using ::frexp;


inline float frexp(float __x, int *__exp)
{ return __builtin_frexpf(__x, __exp); }


inline long double frexp(long double __x, int *__exp)
{ return __builtin_frexpl(__x, __exp); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    frexp ( _Tp __x, int * __exp )
    { return __builtin_frexp ( __x, __exp ); }

using ::ldexp;


inline float ldexp(float __x, int __exp)
{ return __builtin_ldexpf(__x, __exp); }


inline long double ldexp(long double __x, int __exp)
{ return __builtin_ldexpl(__x, __exp); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
  ldexp ( _Tp __x, int __exp )
  { return __builtin_ldexp ( __x, __exp ); }

using ::log;


inline float log(float __x)
{ return __builtin_logf(__x); }


inline long double log(long double __x)
{ return __builtin_logl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    log ( _Tp __x )
    { return __builtin_log ( __x ); }

using ::log10;


inline float log10(float __x)
{ return __builtin_log10f(__x); }


inline long double log10(long double __x)
{ return __builtin_log10l(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    log10 ( _Tp __x )
    { return __builtin_log10 ( __x ); }

using ::modf;


inline float modf(float __x, float *__iptr)
{ return __builtin_modff(__x, __iptr); }


inline long double modf(long double __x, long double *__iptr)
{ return __builtin_modfl(__x, __iptr); }

using ::pow;


inline float pow(float __x, float __y)
{ return __builtin_powf(__x, __y); }


inline long double pow(long double __x, long double __y)
{ return __builtin_powl(__x, __y); }



inline double pow(double __x, int __i)
{ return __builtin_powi(__x, __i); }


inline float pow(float __x, int __n)
{ return __builtin_powif(__x, __n); }


inline long double pow(long double __x, int __n)
{ return __builtin_powil(__x, __n); }

template < typename _Tp, typename _Up >
    inline
    typename __gnu_cxx :: __promote_2 <
    typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value
        && __is_arithmetic < _Up > :: __value,
        _Tp > :: __type, _Up > :: __type
    pow ( _Tp __x, _Up __y )
    {
      typedef typename __gnu_cxx :: __promote_2 < _Tp, _Up > :: __type __type;
      return pow ( __type ( __x ), __type ( __y ) );
    }

using ::sin;


inline float sin(float __x)
{ return __builtin_sinf(__x); }


inline long double sin(long double __x)
{ return __builtin_sinl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sin ( _Tp __x )
    { return __builtin_sin ( __x ); }

using ::sinh;


inline float sinh(float __x)
{ return __builtin_sinhf(__x); }


inline long double sinh(long double __x)
{ return __builtin_sinhl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sinh ( _Tp __x )
    { return __builtin_sinh ( __x ); }

using ::sqrt;


inline float sqrt(float __x)
{ return __builtin_sqrtf(__x); }


inline long double sqrt(long double __x)
{ return __builtin_sqrtl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sqrt ( _Tp __x )
    { return __builtin_sqrt ( __x ); }

using ::tan;


inline float tan(float __x)
{ return __builtin_tanf(__x); }


inline long double tan(long double __x)
{ return __builtin_tanl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    tan ( _Tp __x )
    { return __builtin_tan ( __x ); }

using ::tanh;


inline float tanh(float __x)
{ return __builtin_tanhf(__x); }


inline long double tanh(long double __x)
{ return __builtin_tanhl(__x); }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    tanh ( _Tp __x )
    { return __builtin_tanh ( __x ); }

}
# 483 "/usr/include/c++/4.3/cmath" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {

template < typename _Tp >
    inline int
    __capture_fpclassify ( _Tp __f ) { return ( sizeof ( __f ) == sizeof ( float ) ? __fpclassifyf ( __f ) : sizeof ( __f ) == sizeof ( double ) ? __fpclassify ( __f ) : __fpclassifyl ( __f ) ); }

}
# 505 "/usr/include/c++/4.3/cmath" 3
namespace std __attribute__((visibility("default"))) {

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    fpclassify ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return :: __gnu_cxx :: __capture_fpclassify ( __type ( __f ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isfinite ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isfinite ( __type ( __f ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isinf ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isinf ( __type ( __f ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isnan ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isnan ( __type ( __f ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isnormal ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isnormal ( __type ( __f ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    signbit ( _Tp __f )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_signbit ( __type ( __f ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isgreater ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isgreater ( __type ( __f1 ), __type ( __f2 ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isgreaterequal ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isgreaterequal ( __type ( __f1 ), __type ( __f2 ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isless ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isless ( __type ( __f1 ), __type ( __f2 ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    islessequal ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_islessequal ( __type ( __f1 ), __type ( __f2 ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    islessgreater ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_islessgreater ( __type ( __f1 ), __type ( __f2 ) );
    }

template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_arithmetic < _Tp > :: __value,
        int > :: __type
    isunordered ( _Tp __f1, _Tp __f2 )
    {
      typedef typename __gnu_cxx :: __promote < _Tp > :: __type __type;
      return __builtin_isunordered ( __type ( __f1 ), __type ( __f2 ) );
    }

}
# 40 "/usr/include/c++/4.3/bits/cmath.tcc" 3
namespace std __attribute__((visibility("default"))) {

template < typename _Tp >
    inline _Tp
    __cmath_power ( _Tp __x, unsigned int __n )
    {
      _Tp __y = __n % 2 ? __x : _Tp ( 1 );

      while ( __n >>= 1 )
        {
          __x = __x * __x;
          if ( __n % 2 )
            __y = __y * __x;
        }

      return __y;
    }

}
# 53 "/usr/include/c++/4.3/cstddef" 3
namespace std __attribute__((visibility("default"))) {

using ::ptrdiff_t;
using ::size_t;

}
# 105 "/usr/include/c++/4.3/cstdlib" 3
namespace std __attribute__((visibility("default"))) {

using ::div_t;
using ::ldiv_t;

using ::abort;
using ::abs;
using ::atexit;
using ::atof;
using ::atoi;
using ::atol;
using ::bsearch;
using ::calloc;
using ::div;
using ::exit;
using ::free;
using ::getenv;
using ::labs;
using ::ldiv;
using ::malloc;

using ::mblen;
using ::mbstowcs;
using ::mbtowc;

using ::qsort;
using ::rand;
using ::realloc;
using ::srand;
using ::strtod;
using ::strtol;
using ::strtoul;
using ::system;

using ::wcstombs;
using ::wctomb;



inline long abs(long __i) { return labs(__i); }


inline ldiv_t div(long __i, long __j) { return ldiv(__i, __j); }

}
# 162 "/usr/include/c++/4.3/cstdlib" 3
namespace __gnu_cxx __attribute__((visibility("default"))) {


using ::lldiv_t;
# 171 "/usr/include/c++/4.3/cstdlib" 3
using ::_Exit;



inline long long abs(long long __x) { return (__x >= (0)) ? __x : (-__x); }


using ::llabs;


inline lldiv_t div(long long __n, long long __d)
{ auto lldiv_t __q; (__q.quot) = __n / __d; (__q.rem) = __n % __d; return __q; }

using ::lldiv;
# 195 "/usr/include/c++/4.3/cstdlib" 3
using ::atoll;
using ::strtoll;
using ::strtoull;

using ::strtof;
using ::strtold;

}

namespace std __attribute__((visibility("default"))) {


using __gnu_cxx::lldiv_t;

using __gnu_cxx::_Exit;
using __gnu_cxx::abs;

using __gnu_cxx::llabs;
using __gnu_cxx::div;
using __gnu_cxx::lldiv;

using __gnu_cxx::atoll;
using __gnu_cxx::strtof;
using __gnu_cxx::strtoll;
using __gnu_cxx::strtoull;
using __gnu_cxx::strtold;

}
# 442 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" { extern inline __attribute__((__weak__)) int __signbitl(long double) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); }

extern "C" __attribute__((__weak__)) int __isinfl(long double) throw() __attribute__((__const__));

extern "C" __attribute__((__weak__)) int __isnanl(long double) throw() __attribute__((__const__));
# 456 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C" __attribute__((__weak__)) int __finitel(long double) throw() __attribute__((__const__));
# 481 "/usr/local/cuda/bin/../include/math_functions.h"
namespace __gnu_cxx {

extern inline long long abs(long long) __attribute__((visibility("default")));
}

namespace std {

template<class T> extern inline T __pow_helper(T, int);
template<class T> extern inline T __cmath_power(T, unsigned);
}

using std::abs;
using std::fabs;
using std::ceil;
using std::floor;
using std::sqrt;
using std::pow;
using std::log;
using std::log10;
using std::fmod;
using std::modf;
using std::exp;
using std::frexp;
using std::ldexp;
using std::asin;
using std::sin;
using std::sinh;
using std::acos;
using std::cos;
using std::cosh;
using std::atan;
using std::atan2;
using std::tan;
using std::tanh;
# 568 "/usr/local/cuda/bin/../include/math_functions.h"
namespace std {


extern inline long abs(long) __attribute__((visibility("default")));
extern inline float abs(float) __attribute__((visibility("default")));
extern inline double abs(double) __attribute__((visibility("default")));
extern inline float fabs(float) __attribute__((visibility("default")));
extern inline float ceil(float) __attribute__((visibility("default")));
extern inline float floor(float) __attribute__((visibility("default")));
extern inline float sqrt(float) __attribute__((visibility("default")));
extern inline float pow(float, float) __attribute__((visibility("default")));
extern inline float pow(float, int) __attribute__((visibility("default")));
extern inline double pow(double, int) __attribute__((visibility("default")));
extern inline float log(float) __attribute__((visibility("default")));
extern inline float log10(float) __attribute__((visibility("default")));
extern inline float fmod(float, float) __attribute__((visibility("default")));
extern inline float modf(float, float *) __attribute__((visibility("default")));
extern inline float exp(float) __attribute__((visibility("default")));
extern inline float frexp(float, int *) __attribute__((visibility("default")));
extern inline float ldexp(float, int) __attribute__((visibility("default")));
extern inline float asin(float) __attribute__((visibility("default")));
extern inline float sin(float) __attribute__((visibility("default")));
extern inline float sinh(float) __attribute__((visibility("default")));
extern inline float acos(float) __attribute__((visibility("default")));
extern inline float cos(float) __attribute__((visibility("default")));
extern inline float cosh(float) __attribute__((visibility("default")));
extern inline float atan(float) __attribute__((visibility("default")));
extern inline float atan2(float, float) __attribute__((visibility("default")));
extern inline float tan(float) __attribute__((visibility("default")));
extern inline float tanh(float) __attribute__((visibility("default")));


}


static inline float logb(float a)
{
return logbf(a);
}

static inline int ilogb(float a)
{
return ilogbf(a);
}

static inline float scalbn(float a, int b)
{
return scalbnf(a, b);
}

static inline float scalbln(float a, long b)
{
return scalblnf(a, b);
}

static inline float exp2(float a)
{
return exp2f(a);
}

static inline float exp10(float a)
{
return exp10f(a);
}

static inline float expm1(float a)
{
return expm1f(a);
}

static inline float log2(float a)
{
return log2f(a);
}

static inline float log1p(float a)
{
return log1pf(a);
}

static inline float rsqrt(float a)
{
return rsqrtf(a);
}

static inline float acosh(float a)
{
return acoshf(a);
}

static inline float asinh(float a)
{
return asinhf(a);
}

static inline float atanh(float a)
{
return atanhf(a);
}

static inline float hypot(float a, float b)
{
return hypotf(a, b);
}

static inline float cbrt(float a)
{
return cbrtf(a);
}

static inline void sincos(float a, float *sptr, float *cptr)
{
sincosf(a, sptr, cptr);
}

static inline float erf(float a)
{
return erff(a);
}

static inline float erfinv(float a)
{
return erfinvf(a);
}

static inline float erfc(float a)
{
return erfcf(a);
}

static inline float erfcinv(float a)
{
return erfcinvf(a);
}

static inline float lgamma(float a)
{
return lgammaf(a);
}

static inline float tgamma(float a)
{
return tgammaf(a);
}

static inline float copysign(float a, float b)
{
return copysignf(a, b);
}

static inline double copysign(double a, float b)
{
return copysign(a, (double)b);
}

static inline float copysign(float a, double b)
{
return copysignf(a, (float)b);
}

static inline float nextafter(float a, float b)
{
return nextafterf(a, b);
}

static inline float remainder(float a, float b)
{
return remainderf(a, b);
}

static inline float remquo(float a, float b, int *quo)
{
return remquof(a, b, quo);
}

static inline float round(float a)
{
return roundf(a);
}

static inline long lround(float a)
{
return lroundf(a);
}

static inline long long llround(float a)
{
return llroundf(a);
}

static inline float trunc(float a)
{
return truncf(a);
}

static inline float rint(float a)
{
return rintf(a);
}

static inline long lrint(float a)
{
return lrintf(a);
}

static inline long long llrint(float a)
{
return llrintf(a);
}

static inline float nearbyint(float a)
{
return nearbyintf(a);
}

static inline float fdim(float a, float b)
{
return fdimf(a, b);
}

static inline float fma(float a, float b, float c)
{
return fmaf(a, b, c);
}

static inline unsigned min(unsigned a, unsigned b)
{
return umin(a, b);
}

static inline unsigned min(int a, unsigned b)
{
return umin((unsigned)a, b);
}

static inline unsigned min(unsigned a, int b)
{
return umin(a, (unsigned)b);
}

static inline long long min(long long a, long long b)
{
return llmin(a, b);
}

static inline unsigned long long min(unsigned long long a, unsigned long long b)
{
return ullmin(a, b);
}

static inline unsigned long long min(long long a, unsigned long long b)
{
return ullmin((unsigned long long)a, b);
}

static inline unsigned long long min(unsigned long long a, long long b)
{
return ullmin(a, (unsigned long long)b);
}

static inline float min(float a, float b)
{
return fminf(a, b);
}

static inline double min(double a, double b)
{
return fmin(a, b);
}

static inline double min(float a, double b)
{
return fmin((double)a, b);
}

static inline double min(double a, float b)
{
return fmin(a, (double)b);
}

static inline unsigned max(unsigned a, unsigned b)
{
return umax(a, b);
}

static inline unsigned max(int a, unsigned b)
{
return umax((unsigned)a, b);
}

static inline unsigned max(unsigned a, int b)
{
return umax(a, (unsigned)b);
}

static inline long long max(long long a, long long b)
{
return llmax(a, b);
}

static inline unsigned long long max(unsigned long long a, unsigned long long b)
{
return ullmax(a, b);
}

static inline unsigned long long max(long long a, unsigned long long b)
{
return ullmax((unsigned long long)a, b);
}

static inline unsigned long long max(unsigned long long a, long long b)
{
return ullmax(a, (unsigned long long)b);
}

static inline float max(float a, float b)
{
return fmaxf(a, b);
}

static inline double max(double a, double b)
{
return fmax(a, b);
}

static inline double max(float a, double b)
{
return fmax((double)a, b);
}

static inline double max(double a, float b)
{
return fmax(a, (double)b);
}
# 59 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
template<class T, int dim = 1, cudaTextureReadMode mode = cudaReadModeElementType>
struct texture : public textureReference {

texture(int norm = 0, cudaTextureFilterMode
fMode = cudaFilterModePoint, cudaTextureAddressMode
aMode = cudaAddressModeClamp)
{
(this->normalized) = norm;
(this->filterMode) = fMode;
((this->addressMode)[0]) = aMode;
((this->addressMode)[1]) = aMode;
((this->addressMode)[2]) = aMode;
(this->channelDesc) = cudaCreateChannelDesc< T> ();
}

texture(int norm, cudaTextureFilterMode
fMode, cudaTextureAddressMode
aMode, cudaChannelFormatDesc
desc)
{
(this->normalized) = norm;
(this->filterMode) = fMode;
((this->addressMode)[0]) = aMode;
((this->addressMode)[1]) = aMode;
((this->addressMode)[2]) = aMode;
(this->channelDesc) = desc;
}
};
# 53 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 55 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 57 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 59 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 61 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
# 101 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaSetupArgument(T
arg, size_t
offset)

{
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset);
}

template<class T> inline cudaError_t
cudaHostAlloc(T **
ptr, size_t
size, unsigned
flags)

{
return cudaHostAlloc((void **)((void *)ptr), size, flags);
}

template<class T> inline cudaError_t
cudaHostGetDevicePointer(T **
pDevice, void *
pHost, unsigned
flags)

{
return cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags);
}

template<class T> inline cudaError_t
cudaMalloc(T **
devPtr, size_t
size)

{
return cudaMalloc((void **)((void *)devPtr), size);
}

template<class T> inline cudaError_t
cudaMallocHost(T **
ptr, size_t
size)

{
return cudaMallocHost((void **)((void *)ptr), size);
}

template<class T> inline cudaError_t
cudaMallocPitch(T **
devPtr, size_t *
pitch, size_t
width, size_t
height)

{
return cudaMallocPitch((void **)((void *)devPtr), pitch, width, height);
}
# 172 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyToSymbol(char *
symbol, const void *
src, size_t
count, size_t
offset = (0), cudaMemcpyKind
kind = cudaMemcpyHostToDevice)

{
return cudaMemcpyToSymbol((const char *)symbol, src, count, offset, kind);
}

template<class T> inline cudaError_t
cudaMemcpyToSymbol(const T &
symbol, const void *
src, size_t
count, size_t
offset = (0), cudaMemcpyKind
kind = cudaMemcpyHostToDevice)

{
return cudaMemcpyToSymbol((const char *)(&symbol), src, count, offset, kind);
}

static inline cudaError_t cudaMemcpyToSymbolAsync(char *
symbol, const void *
src, size_t
count, size_t
offset, cudaMemcpyKind
kind, cudaStream_t
stream)

{
return cudaMemcpyToSymbolAsync((const char *)symbol, src, count, offset, kind, stream);
}

template<class T> inline cudaError_t
cudaMemcpyToSymbolAsync(const T &
symbol, const void *
src, size_t
count, size_t
offset, cudaMemcpyKind
kind, cudaStream_t
stream)

{
return cudaMemcpyToSymbolAsync((const char *)(&symbol), src, count, offset, kind, stream);
}
# 226 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaMemcpyFromSymbol(void *
dst, char *
symbol, size_t
count, size_t
offset = (0), cudaMemcpyKind
kind = cudaMemcpyDeviceToHost)

{
return cudaMemcpyFromSymbol(dst, (const char *)symbol, count, offset, kind);
}

template<class T> inline cudaError_t
cudaMemcpyFromSymbol(void *
dst, const T &
symbol, size_t
count, size_t
offset = (0), cudaMemcpyKind
kind = cudaMemcpyDeviceToHost)

{
return cudaMemcpyFromSymbol(dst, (const char *)(&symbol), count, offset, kind);
}

static inline cudaError_t cudaMemcpyFromSymbolAsync(void *
dst, char *
symbol, size_t
count, size_t
offset, cudaMemcpyKind
kind, cudaStream_t
stream)

{
return cudaMemcpyFromSymbolAsync(dst, (const char *)symbol, count, offset, kind, stream);
}

template<class T> inline cudaError_t
cudaMemcpyFromSymbolAsync(void *
dst, const T &
symbol, size_t
count, size_t
offset, cudaMemcpyKind
kind, cudaStream_t
stream)

{
return cudaMemcpyFromSymbolAsync(dst, (const char *)(&symbol), count, offset, kind, stream);
}

static inline cudaError_t cudaGetSymbolAddress(void **
devPtr, char *
symbol)

{
return cudaGetSymbolAddress(devPtr, (const char *)symbol);
}
# 304 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaGetSymbolAddress(void **
devPtr, const T &
symbol)

{
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol));
}
# 319 "/usr/local/cuda/bin/../include/cuda_runtime.h"
static inline cudaError_t cudaGetSymbolSize(size_t *
size, char *
symbol)

{
return cudaGetSymbolSize(size, (const char *)symbol);
}
# 348 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaGetSymbolSize(size_t *
size, const T &
symbol)

{
return cudaGetSymbolSize(size, (const char *)(&symbol));
}
# 404 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaBindTexture(size_t *
offset, const texture< T, dim, readMode> &
tex, const void *
devPtr, const cudaChannelFormatDesc &
desc, size_t
size = (((2147483647) * 2U) + 1U))

{
return cudaBindTexture(offset, &tex, devPtr, (&desc), size);
}
# 448 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaBindTexture(size_t *
offset, const texture< T, dim, readMode> &
tex, const void *
devPtr, size_t
size = (((2147483647) * 2U) + 1U))

{
return cudaBindTexture(offset, tex, devPtr, (tex.channelDesc), size);
}
# 503 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaBindTexture2D(size_t *
offset, const texture< T, dim, readMode> &
tex, const void *
devPtr, const cudaChannelFormatDesc &
desc, size_t
width, size_t
height, size_t
pitch)

{
return cudaBindTexture2D(offset, &tex, devPtr, (&desc), width, height, pitch);
}
# 545 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaBindTextureToArray(const texture< T, dim, readMode> &
tex, const cudaArray *
array, const cudaChannelFormatDesc &
desc)

{
return cudaBindTextureToArray(&tex, array, (&desc));
}
# 582 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaBindTextureToArray(const texture< T, dim, readMode> &
tex, const cudaArray *
array)

{
auto cudaChannelFormatDesc desc;
auto cudaError_t err = cudaGetChannelDesc(&desc, array);

return (err == (cudaSuccess)) ? (cudaBindTextureToArray(tex, array, desc)) : err;
}
# 620 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaUnbindTexture(const texture< T, dim, readMode> &
tex)

{
return cudaUnbindTexture(&tex);
}
# 659 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t
cudaGetTextureAlignmentOffset(size_t *
offset, const texture< T, dim, readMode> &
tex)

{
return cudaGetTextureAlignmentOffset(offset, &tex);
}
# 708 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaLaunch(T *
entry)

{
return cudaLaunch((const char *)entry);
}
# 744 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t
cudaFuncGetAttributes(cudaFuncAttributes *
attr, T *
entry)

{
return cudaFuncGetAttributes(attr, (const char *)entry);
}
# 14 "src/cuda_fi_prerun/gpufi.h"
struct _gpufi_fault_ {
int kernel;

int instance;
int varid;
int call;

int mask_type;


unsigned mask;
int injected;
int disabled;
int mode;
};
# 46 "src/cuda_fi_prerun/gpufi.h"
struct _gpufi_profile_kernel_ {
char state;
int id;
int instance;
char name[32];
};


struct _gpufi_profile_variable_ {
int call_count;
int loop_id;
int type;
};

struct _gpufi_profile_ {

_gpufi_profile_kernel_ kernel[10];
_gpufi_profile_variable_ variable[10][512];


char kernel_bitmap[10];
int kernel_instance[10];

char variable_bitmap[512];
char variable_name[512][32];
};

int gpufi_profile_variable_count = 0;
int gpufi_profile_kernel_count = 0;

struct _gpufi_current_ {
int mode;
int kernel;
int instance;
int loop;
int loop_count;
int iteration;

int profile_index;
int profile_mode;
# 93 "src/cuda_fi_prerun/gpufi.h"
int blid;
int thid;
};


struct _gpufi_data_ {
_gpufi_fault_ fault;



_gpufi_fault_ debug;
_gpufi_current_ current;
_gpufi_profile_ profile;
};
# 124 "src/cuda_fi_prerun/gpufi.h"
extern int GPUFI_INIT(int, int);
extern int GPUFI_HALT(char *);


extern _gpufi_data_ gpufi_host;
# 45 "/usr/include/stdio.h" 3
struct _IO_FILE;



extern "C" { typedef _IO_FILE FILE; }
# 65 "/usr/include/stdio.h" 3
extern "C" { typedef _IO_FILE __FILE; }
# 90 "/usr/include/wchar.h" 3
extern "C" { typedef
# 79 "/usr/include/wchar.h" 3
struct __mbstate_t {
int __count;

union {

unsigned __wch;



char __wchb[4];
} __value;
} __mbstate_t; }
# 26 "/usr/include/_G_config.h" 3
extern "C" { typedef
# 23 "/usr/include/_G_config.h" 3
struct _G_fpos_t {
__off_t __pos;
__mbstate_t __state;
} _G_fpos_t; }




extern "C" { typedef
# 28 "/usr/include/_G_config.h" 3
struct _G_fpos64_t {
__off64_t __pos;
__mbstate_t __state;
} _G_fpos64_t; }
# 53 "/usr/include/_G_config.h" 3
extern "C" { typedef short _G_int16_t; }
extern "C" { typedef int _G_int32_t; }
extern "C" { typedef unsigned short _G_uint16_t; }
extern "C" { typedef unsigned _G_uint32_t; }
# 43 "/usr/lib/gcc/i486-linux-gnu/4.3.2/include/stdarg.h" 3
extern "C" { typedef __builtin_va_list __gnuc_va_list; }
# 170 "/usr/include/libio.h" 3
struct _IO_jump_t; struct _IO_FILE;
# 180 "/usr/include/libio.h" 3
extern "C" { typedef void _IO_lock_t; }
# 186 "/usr/include/libio.h" 3
extern "C" { struct _IO_marker {
_IO_marker *_next;
_IO_FILE *_sbuf;



int _pos;
# 203 "/usr/include/libio.h" 3
}; }


enum __codecvt_result {

__codecvt_ok,
__codecvt_partial,
__codecvt_error,
__codecvt_noconv
};
# 271 "/usr/include/libio.h" 3
extern "C" { struct _IO_FILE {
int _flags;




char *_IO_read_ptr;
char *_IO_read_end;
char *_IO_read_base;
char *_IO_write_base;
char *_IO_write_ptr;
char *_IO_write_end;
char *_IO_buf_base;
char *_IO_buf_end;

char *_IO_save_base;
char *_IO_backup_base;
char *_IO_save_end;

_IO_marker *_markers;

_IO_FILE *_chain;

int _fileno;



int _flags2;

__off_t _old_offset;



unsigned short _cur_column;
signed char _vtable_offset;
char _shortbuf[1];



_IO_lock_t *_lock;
# 319 "/usr/include/libio.h" 3
__off64_t _offset;
# 328 "/usr/include/libio.h" 3
void *__pad1;
void *__pad2;
void *__pad3;
void *__pad4;
size_t __pad5;

int _mode;

char _unused2[((((15) * sizeof(int)) - ((4) * sizeof(void *))) - sizeof(size_t))];

}; }
# 344 "/usr/include/libio.h" 3
struct _IO_FILE_plus;

extern "C" { extern _IO_FILE_plus _IO_2_1_stdin_; }
extern "C" { extern _IO_FILE_plus _IO_2_1_stdout_; }
extern "C" { extern _IO_FILE_plus _IO_2_1_stderr_; }
# 364 "/usr/include/libio.h" 3
extern "C" { typedef __ssize_t __io_read_fn(void *, char *, size_t); }
# 372 "/usr/include/libio.h" 3
extern "C" { typedef __ssize_t __io_write_fn(void *, const char *, size_t); }
# 381 "/usr/include/libio.h" 3
extern "C" { typedef int __io_seek_fn(void *, __off64_t *, int); }


extern "C" { typedef int __io_close_fn(void *); }




extern "C" { typedef __io_read_fn cookie_read_function_t; }
extern "C" { typedef __io_write_fn cookie_write_function_t; }
extern "C" { typedef __io_seek_fn cookie_seek_function_t; }
extern "C" { typedef __io_close_fn cookie_close_function_t; }
# 401 "/usr/include/libio.h" 3
extern "C" { typedef
# 396 "/usr/include/libio.h" 3
struct _IO_cookie_io_functions_t {
__io_read_fn *read;
__io_write_fn *write;
__io_seek_fn *seek;
__io_close_fn *close;
} _IO_cookie_io_functions_t; }
extern "C" { typedef _IO_cookie_io_functions_t cookie_io_functions_t; }

struct _IO_cookie_file;


extern "C" void _IO_cookie_init(_IO_cookie_file *, int, void *, _IO_cookie_io_functions_t);
# 416 "/usr/include/libio.h" 3
extern "C" int __underflow(_IO_FILE *);
extern "C" int __uflow(_IO_FILE *);
extern "C" int __overflow(_IO_FILE *, int);
# 458 "/usr/include/libio.h" 3
extern "C" int _IO_getc(_IO_FILE *);
extern "C" int _IO_putc(int, _IO_FILE *);
extern "C" int _IO_feof(_IO_FILE *) throw();
extern "C" int _IO_ferror(_IO_FILE *) throw();

extern "C" int _IO_peekc_locked(_IO_FILE *);
# 469 "/usr/include/libio.h" 3
extern "C" void _IO_flockfile(_IO_FILE *) throw();
extern "C" void _IO_funlockfile(_IO_FILE *) throw();
extern "C" int _IO_ftrylockfile(_IO_FILE *) throw();
# 488 "/usr/include/libio.h" 3
extern "C" int _IO_vfscanf(_IO_FILE *__restrict__, const char *__restrict__, __gnuc_va_list, int *__restrict__);

extern "C" int _IO_vfprintf(_IO_FILE *__restrict__, const char *__restrict__, __gnuc_va_list);

extern "C" __ssize_t _IO_padn(_IO_FILE *, int, __ssize_t);
extern "C" size_t _IO_sgetn(_IO_FILE *, void *, size_t);

extern "C" __off64_t _IO_seekoff(_IO_FILE *, __off64_t, int, int);
extern "C" __off64_t _IO_seekpos(_IO_FILE *, __off64_t, int);

extern "C" void _IO_free_backup_area(_IO_FILE *) throw();
# 80 "/usr/include/stdio.h" 3
extern "C" { typedef __gnuc_va_list va_list; }
# 91 "/usr/include/stdio.h" 3
extern "C" { typedef _G_fpos_t fpos_t; }
# 97 "/usr/include/stdio.h" 3
extern "C" { typedef _G_fpos64_t fpos64_t; }
# 145 "/usr/include/stdio.h" 3
extern "C" { extern _IO_FILE *stdin; }
extern "C" { extern _IO_FILE *stdout; }
extern "C" { extern _IO_FILE *stderr; }
# 155 "/usr/include/stdio.h" 3
extern "C" int remove(const char *) throw();

extern "C" int rename(const char *, const char *) throw();




extern "C" int renameat(int, const char *, int, const char *) throw();
# 172 "/usr/include/stdio.h" 3
extern "C" FILE *tmpfile();
# 182 "/usr/include/stdio.h" 3
extern "C" FILE *tmpfile64();



extern "C" char *tmpnam(char *) throw();
# 192 "/usr/include/stdio.h" 3
extern "C" char *tmpnam_r(char *) throw();
# 204 "/usr/include/stdio.h" 3
extern "C" char *tempnam(const char *, const char *) throw() __attribute__((__malloc__));
# 214 "/usr/include/stdio.h" 3
extern "C" int fclose(FILE *);




extern "C" int fflush(FILE *);
# 229 "/usr/include/stdio.h" 3
extern "C" int fflush_unlocked(FILE *);
# 239 "/usr/include/stdio.h" 3
extern "C" int fcloseall();
# 249 "/usr/include/stdio.h" 3
extern "C" FILE *fopen(const char *__restrict__, const char *__restrict__);
# 255 "/usr/include/stdio.h" 3
extern "C" FILE *freopen(const char *__restrict__, const char *__restrict__, FILE *__restrict__);
# 274 "/usr/include/stdio.h" 3
extern "C" FILE *fopen64(const char *__restrict__, const char *__restrict__);

extern "C" FILE *freopen64(const char *__restrict__, const char *__restrict__, FILE *__restrict__);
# 283 "/usr/include/stdio.h" 3
extern "C" FILE *fdopen(int, const char *) throw();
# 289 "/usr/include/stdio.h" 3
extern "C" FILE *fopencookie(void *__restrict__, const char *__restrict__, _IO_cookie_io_functions_t) throw();




extern "C" FILE *fmemopen(void *, size_t, const char *) throw();
# 300 "/usr/include/stdio.h" 3
extern "C" FILE *open_memstream(char **, size_t *) throw();
# 307 "/usr/include/stdio.h" 3
extern "C" void setbuf(FILE *__restrict__, char *__restrict__) throw();



extern "C" int setvbuf(FILE *__restrict__, char *__restrict__, int, size_t) throw();
# 318 "/usr/include/stdio.h" 3
extern "C" void setbuffer(FILE *__restrict__, char *__restrict__, size_t) throw();



extern "C" void setlinebuf(FILE *) throw();
# 331 "/usr/include/stdio.h" 3
extern "C" int fprintf(FILE *__restrict__, const char *__restrict__, ...);
# 337 "/usr/include/stdio.h" 3
extern "C" int printf(const char *__restrict__, ...);

extern "C" int sprintf(char *__restrict__, const char *__restrict__, ...) throw();
# 346 "/usr/include/stdio.h" 3
extern "C" int vfprintf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list);
# 352 "/usr/include/stdio.h" 3
extern "C" { extern inline int vprintf(const char *__restrict__, __gnuc_va_list) __attribute__((__gnu_inline__)); }

extern "C" int vsprintf(char *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 361 "/usr/include/stdio.h" 3
extern "C" int snprintf(char *__restrict__, size_t, const char *__restrict__, ...) throw();



extern "C" int vsnprintf(char *__restrict__, size_t, const char *__restrict__, __gnuc_va_list) throw();
# 374 "/usr/include/stdio.h" 3
extern "C" int vasprintf(char **__restrict__, const char *__restrict__, __gnuc_va_list) throw();


extern "C" int __asprintf(char **__restrict__, const char *__restrict__, ...) throw();


extern "C" int asprintf(char **__restrict__, const char *__restrict__, ...) throw();
# 390 "/usr/include/stdio.h" 3
extern "C" int vdprintf(int, const char *__restrict__, __gnuc_va_list);


extern "C" int dprintf(int, const char *__restrict__, ...);
# 403 "/usr/include/stdio.h" 3
extern "C" int fscanf(FILE *__restrict__, const char *__restrict__, ...);
# 409 "/usr/include/stdio.h" 3
extern "C" int scanf(const char *__restrict__, ...);

extern "C" int sscanf(const char *__restrict__, const char *__restrict__, ...) throw();
# 449 "/usr/include/stdio.h" 3
extern "C" int vfscanf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list);
# 457 "/usr/include/stdio.h" 3
extern "C" int vscanf(const char *__restrict__, __gnuc_va_list);



extern "C" int vsscanf(const char *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 509 "/usr/include/stdio.h" 3
extern "C" int fgetc(FILE *);
extern "C" int getc(FILE *);
# 516 "/usr/include/stdio.h" 3
extern "C" { extern inline int getchar() __attribute__((__gnu_inline__)); }
# 528 "/usr/include/stdio.h" 3
extern "C" { extern inline int getc_unlocked(FILE *) __attribute__((__gnu_inline__)); }
extern "C" { extern inline int getchar_unlocked() __attribute__((__gnu_inline__)); }
# 539 "/usr/include/stdio.h" 3
extern "C" { extern inline int fgetc_unlocked(FILE *) __attribute__((__gnu_inline__)); }
# 551 "/usr/include/stdio.h" 3
extern "C" int fputc(int, FILE *);
extern "C" int putc(int, FILE *);
# 558 "/usr/include/stdio.h" 3
extern "C" { extern inline int putchar(int) __attribute__((__gnu_inline__)); }
# 572 "/usr/include/stdio.h" 3
extern "C" { extern inline int fputc_unlocked(int, FILE *) __attribute__((__gnu_inline__)); }
# 580 "/usr/include/stdio.h" 3
extern "C" { extern inline int putc_unlocked(int, FILE *) __attribute__((__gnu_inline__)); }
extern "C" { extern inline int putchar_unlocked(int) __attribute__((__gnu_inline__)); }
# 588 "/usr/include/stdio.h" 3
extern "C" int getw(FILE *);


extern "C" int putw(int, FILE *);
# 600 "/usr/include/stdio.h" 3
extern "C" char *fgets(char *__restrict__, int, FILE *__restrict__);
# 608 "/usr/include/stdio.h" 3
extern "C" char *gets(char *);
# 618 "/usr/include/stdio.h" 3
extern "C" char *fgets_unlocked(char *__restrict__, int, FILE *__restrict__);
# 634 "/usr/include/stdio.h" 3
extern "C" __ssize_t __getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__);


extern "C" __ssize_t getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__);
# 647 "/usr/include/stdio.h" 3
extern "C" { extern inline __ssize_t getline(char **__restrict__, size_t *__restrict__, FILE *__restrict__) __attribute__((__gnu_inline__)); }
# 658 "/usr/include/stdio.h" 3
extern "C" int fputs(const char *__restrict__, FILE *__restrict__);
# 664 "/usr/include/stdio.h" 3
extern "C" int puts(const char *);
# 671 "/usr/include/stdio.h" 3
extern "C" int ungetc(int, FILE *);
# 678 "/usr/include/stdio.h" 3
extern "C" size_t fread(void *__restrict__, size_t, size_t, FILE *__restrict__);
# 684 "/usr/include/stdio.h" 3
extern "C" size_t fwrite(const void *__restrict__, size_t, size_t, FILE *__restrict__);
# 695 "/usr/include/stdio.h" 3
extern "C" int fputs_unlocked(const char *__restrict__, FILE *__restrict__);
# 706 "/usr/include/stdio.h" 3
extern "C" size_t fread_unlocked(void *__restrict__, size_t, size_t, FILE *__restrict__);

extern "C" size_t fwrite_unlocked(const void *__restrict__, size_t, size_t, FILE *__restrict__);
# 718 "/usr/include/stdio.h" 3
extern "C" int fseek(FILE *, long, int);




extern "C" long ftell(FILE *);




extern "C" void rewind(FILE *);
# 742 "/usr/include/stdio.h" 3
extern "C" int fseeko(FILE *, __off_t, int);




extern "C" __off_t ftello(FILE *);
# 767 "/usr/include/stdio.h" 3
extern "C" int fgetpos(FILE *__restrict__, fpos_t *__restrict__);




extern "C" int fsetpos(FILE *, const fpos_t *);
# 787 "/usr/include/stdio.h" 3
extern "C" int fseeko64(FILE *, __off64_t, int);
extern "C" __off64_t ftello64(FILE *);
extern "C" int fgetpos64(FILE *__restrict__, fpos64_t *__restrict__);
extern "C" int fsetpos64(FILE *, const fpos64_t *);




extern "C" void clearerr(FILE *) throw();

extern "C" int feof(FILE *) throw();

extern "C" int ferror(FILE *) throw();




extern "C" void clearerr_unlocked(FILE *) throw();
extern "C" { extern inline int feof_unlocked(FILE *) throw() __attribute__((__gnu_inline__)); }
extern "C" { extern inline int ferror_unlocked(FILE *) throw() __attribute__((__gnu_inline__)); }
# 815 "/usr/include/stdio.h" 3
extern "C" void perror(const char *);
# 27 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern int sys_nerr; }
extern "C" { extern const char *const sys_errlist[]; }


extern "C" { extern int _sys_nerr; }
extern "C" { extern const char *const _sys_errlist[]; }
# 827 "/usr/include/stdio.h" 3
extern "C" int fileno(FILE *) throw();




extern "C" int fileno_unlocked(FILE *) throw();
# 842 "/usr/include/stdio.h" 3
extern "C" FILE *popen(const char *, const char *);
# 848 "/usr/include/stdio.h" 3
extern "C" int pclose(FILE *);
# 854 "/usr/include/stdio.h" 3
extern "C" char *ctermid(char *) throw();
# 860 "/usr/include/stdio.h" 3
extern "C" char *cuserid(char *);




struct obstack;


extern "C" int obstack_printf(obstack *__restrict__, const char *__restrict__, ...) throw();


extern "C" int obstack_vprintf(obstack *__restrict__, const char *__restrict__, __gnuc_va_list) throw();
# 882 "/usr/include/stdio.h" 3
extern "C" void flockfile(FILE *) throw();



extern "C" int ftrylockfile(FILE *) throw();


extern "C" void funlockfile(FILE *) throw();
# 37 "/usr/include/bits/stdio.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) int vprintf(const char *__restrict__ __fmt, __gnuc_va_list __arg)
{
return vfprintf(stdout, __fmt, __arg);
} }




extern "C" { inline __attribute__((__gnu_inline__)) int getchar()
{
return _IO_getc(stdin);
} }
# 54 "/usr/include/bits/stdio.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) int fgetc_unlocked(FILE *__fp)
{
return (__builtin_expect((__fp->_IO_read_ptr) >= (__fp->_IO_read_end), 0)) ? __uflow(__fp) : (*((unsigned char *)((__fp->_IO_read_ptr)++)));
} }
# 64 "/usr/include/bits/stdio.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) int getc_unlocked(FILE *__fp)
{
return (__builtin_expect((__fp->_IO_read_ptr) >= (__fp->_IO_read_end), 0)) ? __uflow(__fp) : (*((unsigned char *)((__fp->_IO_read_ptr)++)));
} }



extern "C" { inline __attribute__((__gnu_inline__)) int getchar_unlocked()
{
return (__builtin_expect((stdin->_IO_read_ptr) >= (stdin->_IO_read_end), 0)) ? __uflow(stdin) : (*((unsigned char *)((stdin->_IO_read_ptr)++)));
} }
# 80 "/usr/include/bits/stdio.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) int putchar(int __c)
{
return _IO_putc(__c, stdout);
} }
# 89 "/usr/include/bits/stdio.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) int fputc_unlocked(int __c, FILE *__stream)
{
return (__builtin_expect((__stream->_IO_write_ptr) >= (__stream->_IO_write_end), 0)) ? __overflow(__stream, (unsigned char)__c) : ((unsigned char)((*((__stream->_IO_write_ptr)++)) = __c));
} }
# 99 "/usr/include/bits/stdio.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) int putc_unlocked(int __c, FILE *__stream)
{
return (__builtin_expect((__stream->_IO_write_ptr) >= (__stream->_IO_write_end), 0)) ? __overflow(__stream, (unsigned char)__c) : ((unsigned char)((*((__stream->_IO_write_ptr)++)) = __c));
} }



extern "C" { inline __attribute__((__gnu_inline__)) int putchar_unlocked(int __c)
{
return (__builtin_expect((stdout->_IO_write_ptr) >= (stdout->_IO_write_end), 0)) ? __overflow(stdout, (unsigned char)__c) : ((unsigned char)((*((stdout->_IO_write_ptr)++)) = __c));
} }
# 116 "/usr/include/bits/stdio.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) __ssize_t getline(char **__lineptr, size_t *__n, FILE *__stream)
{
return __getdelim(__lineptr, __n, '\n', __stream);
} }
# 126 "/usr/include/bits/stdio.h" 3
extern "C" { inline __attribute__((__gnu_inline__)) int feof_unlocked(FILE *__stream) throw()
{
return ((__stream->_flags) & 16) != 0;
} }



extern "C" { inline __attribute__((__gnu_inline__)) int ferror_unlocked(FILE *__stream) throw()
{
return ((__stream->_flags) & 32) != 0;
} }
# 9 "src/cuda_fi_prerun/gpufi_kernel.cu"
_gpufi_data_ gpufi_host = {{0}};
static _gpufi_data_ *gpufi_dev__cuda_shadow_variable__;
# 18 "src/cuda_fi_prerun/gpufi_kernel.cu"
int variable_count;
int kernel_count;
# 25 "src/cuda_fi_prerun/gpufi_kernel.cu"
int GPUFI_INIT(int kernel_cnt, int variable_cnt)
{
auto FILE *fp;
auto char cmd[32];
auto int i;

kernel_count = kernel_cnt + 1;
variable_count = variable_cnt;

memset(&gpufi_host, 0, sizeof(_gpufi_data_));

fp = fopen("fi_cmd.txt", "rt");

if (!(fp)) {
printf("file open error\n");
system("pwd");
return -1;
}

fscanf(fp, "%s", cmd);
printf("%s ", cmd);
if (!(strcmp(cmd, "profile"))) {
((gpufi_host.current).blid) = 0;
((gpufi_host.current).thid) = 0;

((gpufi_host.fault).mode) = 1;
((gpufi_host.current).profile_index) = (-1);
fscanf(fp, "%s", cmd);
printf("%s ", cmd);
if (!(strcmp(cmd, "none"))) {
((gpufi_host.current).profile_mode) = 0;
} else {
if (!(strcmp(cmd, "value"))) {
fscanf(fp, "%s", cmd);
printf("%s ", cmd);
if (!(strcmp(cmd, "loop"))) {
((gpufi_host.current).profile_mode) = 1; } else {
if (!(strcmp(cmd, "kernel"))) {
((gpufi_host.current).profile_mode) = 2; } else {
if (!(strcmp(cmd, "thread"))) {
((gpufi_host.current).profile_mode) = 3;
fscanf(fp, "%d", &((gpufi_host.current).blid));
printf(" %d ", (gpufi_host.current).blid);
} else {
if (!(strcmp(cmd, "block"))) {
((gpufi_host.current).profile_mode) = 4;
} } } }
} }
printf(" (%d)\n", (gpufi_host.current).profile_mode);
}

fclose(fp);

return 0;
}
# 93 "src/cuda_fi_prerun/gpufi_kernel.cu"
char *gpufi_type_name[6] = {((char *)("unknown")), ((char *)("int")), ((char *)("fp")), ((char *)("int_pt")), ((char *)("fp_pt")), ((char *)("unknown_pt"))};

int GPUFI_HALT(char *fname)
{
auto FILE *fp;
auto int i; auto int j; auto int k; auto int m;

if (((gpufi_host.fault).mode) == 1) {


fp = fopen(fname, "wt");
if (!(fp)) {
printf("can\'t write to an output file, %s\n", fname);
return -1;
}

for (i = 0; i < 10; i++) {
if (((((gpufi_host.profile).kernel)[i]).state) == 1) {
fprintf(fp, "kernel\t%d\t%s\t%d\n", (((gpufi_host.profile).kernel)[i]).id, (((gpufi_host.profile).kernel)[i]).name, (((gpufi_host.profile).kernel)[i]).instance); } else {




break; }

for (j = 0; j < variable_count; j++) {
if ((((((gpufi_host.profile).variable)[i])[j]).call_count) != 0) {
fprintf(fp, "variable\t%d\t%s\t%d\t%d\t%s\t", j, (((gpufi_host.profile).variable_bitmap)[j]) ? (((gpufi_host.profile).variable_name)[j]) : (""), ((((gpufi_host.profile).variable)[i])[j]).call_count, ((((gpufi_host.profile).variable)[i])[j]).loop_id, (gpufi_type_name)[((((gpufi_host.profile).variable)[i])[j]).type]);
# 127 "src/cuda_fi_prerun/gpufi_kernel.cu"
fprintf(fp, "\n");
}
}
fprintf(fp, "\n");
}

fclose(fp);
}

return 0;
}
# 238 "/usr/include/unistd.h" 3
extern "C" { typedef __intptr_t intptr_t; }
# 245 "/usr/include/unistd.h" 3
extern "C" { typedef __socklen_t socklen_t; }
# 258 "/usr/include/unistd.h" 3
extern "C" int access(const char *, int) throw();




extern "C" int euidaccess(const char *, int) throw();



extern "C" int eaccess(const char *, int) throw();
# 275 "/usr/include/unistd.h" 3
extern "C" int faccessat(int, const char *, int, int) throw();
# 301 "/usr/include/unistd.h" 3
extern "C" __off_t lseek(int, __off_t, int) throw();
# 312 "/usr/include/unistd.h" 3
extern "C" __off64_t lseek64(int, __off64_t, int) throw();
# 320 "/usr/include/unistd.h" 3
extern "C" int close(int);
# 327 "/usr/include/unistd.h" 3
extern "C" ssize_t read(int, void *, size_t);
# 333 "/usr/include/unistd.h" 3
extern "C" ssize_t write(int, const void *, size_t);
# 343 "/usr/include/unistd.h" 3
extern "C" ssize_t pread(int, void *, size_t, __off_t);
# 351 "/usr/include/unistd.h" 3
extern "C" ssize_t pwrite(int, const void *, size_t, __off_t);
# 371 "/usr/include/unistd.h" 3
extern "C" ssize_t pread64(int, void *, size_t, __off64_t);



extern "C" ssize_t pwrite64(int, const void *, size_t, __off64_t);
# 384 "/usr/include/unistd.h" 3
extern "C" int pipe(int [2]) throw();
# 393 "/usr/include/unistd.h" 3
extern "C" unsigned alarm(unsigned) throw();
# 405 "/usr/include/unistd.h" 3
extern "C" unsigned sleep(unsigned);
# 412 "/usr/include/unistd.h" 3
extern "C" __useconds_t ualarm(__useconds_t, __useconds_t) throw();
# 420 "/usr/include/unistd.h" 3
extern "C" int usleep(__useconds_t);
# 429 "/usr/include/unistd.h" 3
extern "C" int pause();



extern "C" int chown(const char *, __uid_t, __gid_t) throw();




extern "C" int fchown(int, __uid_t, __gid_t) throw();




extern "C" int lchown(const char *, __uid_t, __gid_t) throw();
# 451 "/usr/include/unistd.h" 3
extern "C" int fchownat(int, const char *, __uid_t, __gid_t, int) throw();
# 457 "/usr/include/unistd.h" 3
extern "C" int chdir(const char *) throw();



extern "C" int fchdir(int) throw();
# 471 "/usr/include/unistd.h" 3
extern "C" char *getcwd(char *, size_t) throw();
# 477 "/usr/include/unistd.h" 3
extern "C" char *get_current_dir_name() throw();
# 484 "/usr/include/unistd.h" 3
extern "C" char *getwd(char *) throw() __attribute__((__deprecated__));
# 490 "/usr/include/unistd.h" 3
extern "C" int dup(int) throw();


extern "C" int dup2(int, int) throw();


extern "C" { extern char **__environ; }

extern "C" { extern char **environ; }
# 504 "/usr/include/unistd.h" 3
extern "C" int execve(const char *, char *const [], char *const []) throw();
# 510 "/usr/include/unistd.h" 3
extern "C" int fexecve(int, char *const [], char *const []) throw();
# 516 "/usr/include/unistd.h" 3
extern "C" int execv(const char *, char *const []) throw();




extern "C" int execle(const char *, const char *, ...) throw();




extern "C" int execl(const char *, const char *, ...) throw();




extern "C" int execvp(const char *, char *const []) throw();
# 537 "/usr/include/unistd.h" 3
extern "C" int execlp(const char *, const char *, ...) throw();
# 543 "/usr/include/unistd.h" 3
extern "C" int nice(int) throw();




extern "C" void _exit(int) __attribute__((__noreturn__));
# 27 "/usr/include/bits/confname.h" 3
enum __cuda__PC_LINK_MAX {
_PC_LINK_MAX,

_PC_MAX_CANON,

_PC_MAX_INPUT,

_PC_NAME_MAX,

_PC_PATH_MAX,

_PC_PIPE_BUF,

_PC_CHOWN_RESTRICTED,

_PC_NO_TRUNC,

_PC_VDISABLE,

_PC_SYNC_IO,

_PC_ASYNC_IO,

_PC_PRIO_IO,

_PC_SOCK_MAXBUF,

_PC_FILESIZEBITS,

_PC_REC_INCR_XFER_SIZE,

_PC_REC_MAX_XFER_SIZE,

_PC_REC_MIN_XFER_SIZE,

_PC_REC_XFER_ALIGN,

_PC_ALLOC_SIZE_MIN,

_PC_SYMLINK_MAX,

_PC_2_SYMLINKS

};



enum __cuda__SC_ARG_MAX {
_SC_ARG_MAX,

_SC_CHILD_MAX,

_SC_CLK_TCK,

_SC_NGROUPS_MAX,

_SC_OPEN_MAX,

_SC_STREAM_MAX,

_SC_TZNAME_MAX,

_SC_JOB_CONTROL,

_SC_SAVED_IDS,

_SC_REALTIME_SIGNALS,

_SC_PRIORITY_SCHEDULING,

_SC_TIMERS,

_SC_ASYNCHRONOUS_IO,

_SC_PRIORITIZED_IO,

_SC_SYNCHRONIZED_IO,

_SC_FSYNC,

_SC_MAPPED_FILES,

_SC_MEMLOCK,

_SC_MEMLOCK_RANGE,

_SC_MEMORY_PROTECTION,

_SC_MESSAGE_PASSING,

_SC_SEMAPHORES,

_SC_SHARED_MEMORY_OBJECTS,

_SC_AIO_LISTIO_MAX,

_SC_AIO_MAX,

_SC_AIO_PRIO_DELTA_MAX,

_SC_DELAYTIMER_MAX,

_SC_MQ_OPEN_MAX,

_SC_MQ_PRIO_MAX,

_SC_VERSION,

_SC_PAGESIZE,


_SC_RTSIG_MAX,

_SC_SEM_NSEMS_MAX,

_SC_SEM_VALUE_MAX,

_SC_SIGQUEUE_MAX,

_SC_TIMER_MAX,




_SC_BC_BASE_MAX,

_SC_BC_DIM_MAX,

_SC_BC_SCALE_MAX,

_SC_BC_STRING_MAX,

_SC_COLL_WEIGHTS_MAX,

_SC_EQUIV_CLASS_MAX,

_SC_EXPR_NEST_MAX,

_SC_LINE_MAX,

_SC_RE_DUP_MAX,

_SC_CHARCLASS_NAME_MAX,


_SC_2_VERSION,

_SC_2_C_BIND,

_SC_2_C_DEV,

_SC_2_FORT_DEV,

_SC_2_FORT_RUN,

_SC_2_SW_DEV,

_SC_2_LOCALEDEF,


_SC_PII,

_SC_PII_XTI,

_SC_PII_SOCKET,

_SC_PII_INTERNET,

_SC_PII_OSI,

_SC_POLL,

_SC_SELECT,

_SC_UIO_MAXIOV,

_SC_IOV_MAX = 60,

_SC_PII_INTERNET_STREAM,

_SC_PII_INTERNET_DGRAM,

_SC_PII_OSI_COTS,

_SC_PII_OSI_CLTS,

_SC_PII_OSI_M,

_SC_T_IOV_MAX,



_SC_THREADS,

_SC_THREAD_SAFE_FUNCTIONS,

_SC_GETGR_R_SIZE_MAX,

_SC_GETPW_R_SIZE_MAX,

_SC_LOGIN_NAME_MAX,

_SC_TTY_NAME_MAX,

_SC_THREAD_DESTRUCTOR_ITERATIONS,

_SC_THREAD_KEYS_MAX,

_SC_THREAD_STACK_MIN,

_SC_THREAD_THREADS_MAX,

_SC_THREAD_ATTR_STACKADDR,

_SC_THREAD_ATTR_STACKSIZE,

_SC_THREAD_PRIORITY_SCHEDULING,

_SC_THREAD_PRIO_INHERIT,

_SC_THREAD_PRIO_PROTECT,

_SC_THREAD_PROCESS_SHARED,


_SC_NPROCESSORS_CONF,

_SC_NPROCESSORS_ONLN,

_SC_PHYS_PAGES,

_SC_AVPHYS_PAGES,

_SC_ATEXIT_MAX,

_SC_PASS_MAX,


_SC_XOPEN_VERSION,

_SC_XOPEN_XCU_VERSION,

_SC_XOPEN_UNIX,

_SC_XOPEN_CRYPT,

_SC_XOPEN_ENH_I18N,

_SC_XOPEN_SHM,


_SC_2_CHAR_TERM,

_SC_2_C_VERSION,

_SC_2_UPE,


_SC_XOPEN_XPG2,

_SC_XOPEN_XPG3,

_SC_XOPEN_XPG4,


_SC_CHAR_BIT,

_SC_CHAR_MAX,

_SC_CHAR_MIN,

_SC_INT_MAX,

_SC_INT_MIN,

_SC_LONG_BIT,

_SC_WORD_BIT,

_SC_MB_LEN_MAX,

_SC_NZERO,

_SC_SSIZE_MAX,

_SC_SCHAR_MAX,

_SC_SCHAR_MIN,

_SC_SHRT_MAX,

_SC_SHRT_MIN,

_SC_UCHAR_MAX,

_SC_UINT_MAX,

_SC_ULONG_MAX,

_SC_USHRT_MAX,


_SC_NL_ARGMAX,

_SC_NL_LANGMAX,

_SC_NL_MSGMAX,

_SC_NL_NMAX,

_SC_NL_SETMAX,

_SC_NL_TEXTMAX,


_SC_XBS5_ILP32_OFF32,

_SC_XBS5_ILP32_OFFBIG,

_SC_XBS5_LP64_OFF64,

_SC_XBS5_LPBIG_OFFBIG,


_SC_XOPEN_LEGACY,

_SC_XOPEN_REALTIME,

_SC_XOPEN_REALTIME_THREADS,


_SC_ADVISORY_INFO,

_SC_BARRIERS,

_SC_BASE,

_SC_C_LANG_SUPPORT,

_SC_C_LANG_SUPPORT_R,

_SC_CLOCK_SELECTION,

_SC_CPUTIME,

_SC_THREAD_CPUTIME,

_SC_DEVICE_IO,

_SC_DEVICE_SPECIFIC,

_SC_DEVICE_SPECIFIC_R,

_SC_FD_MGMT,

_SC_FIFO,

_SC_PIPE,

_SC_FILE_ATTRIBUTES,

_SC_FILE_LOCKING,

_SC_FILE_SYSTEM,

_SC_MONOTONIC_CLOCK,

_SC_MULTI_PROCESS,

_SC_SINGLE_PROCESS,

_SC_NETWORKING,

_SC_READER_WRITER_LOCKS,

_SC_SPIN_LOCKS,

_SC_REGEXP,

_SC_REGEX_VERSION,

_SC_SHELL,

_SC_SIGNALS,

_SC_SPAWN,

_SC_SPORADIC_SERVER,

_SC_THREAD_SPORADIC_SERVER,

_SC_SYSTEM_DATABASE,

_SC_SYSTEM_DATABASE_R,

_SC_TIMEOUTS,

_SC_TYPED_MEMORY_OBJECTS,

_SC_USER_GROUPS,

_SC_USER_GROUPS_R,

_SC_2_PBS,

_SC_2_PBS_ACCOUNTING,

_SC_2_PBS_LOCATE,

_SC_2_PBS_MESSAGE,

_SC_2_PBS_TRACK,

_SC_SYMLOOP_MAX,

_SC_STREAMS,

_SC_2_PBS_CHECKPOINT,


_SC_V6_ILP32_OFF32,

_SC_V6_ILP32_OFFBIG,

_SC_V6_LP64_OFF64,

_SC_V6_LPBIG_OFFBIG,


_SC_HOST_NAME_MAX,

_SC_TRACE,

_SC_TRACE_EVENT_FILTER,

_SC_TRACE_INHERIT,

_SC_TRACE_LOG,


_SC_LEVEL1_ICACHE_SIZE,

_SC_LEVEL1_ICACHE_ASSOC,

_SC_LEVEL1_ICACHE_LINESIZE,

_SC_LEVEL1_DCACHE_SIZE,

_SC_LEVEL1_DCACHE_ASSOC,

_SC_LEVEL1_DCACHE_LINESIZE,

_SC_LEVEL2_CACHE_SIZE,

_SC_LEVEL2_CACHE_ASSOC,

_SC_LEVEL2_CACHE_LINESIZE,

_SC_LEVEL3_CACHE_SIZE,

_SC_LEVEL3_CACHE_ASSOC,

_SC_LEVEL3_CACHE_LINESIZE,

_SC_LEVEL4_CACHE_SIZE,

_SC_LEVEL4_CACHE_ASSOC,

_SC_LEVEL4_CACHE_LINESIZE,



_SC_IPV6 = 235,

_SC_RAW_SOCKETS

};



enum __cuda__CS_PATH {
_CS_PATH,


_CS_V6_WIDTH_RESTRICTED_ENVS,



_CS_GNU_LIBC_VERSION,

_CS_GNU_LIBPTHREAD_VERSION,


_CS_LFS_CFLAGS = 1000,

_CS_LFS_LDFLAGS,

_CS_LFS_LIBS,

_CS_LFS_LINTFLAGS,

_CS_LFS64_CFLAGS,

_CS_LFS64_LDFLAGS,

_CS_LFS64_LIBS,

_CS_LFS64_LINTFLAGS,


_CS_XBS5_ILP32_OFF32_CFLAGS = 1100,

_CS_XBS5_ILP32_OFF32_LDFLAGS,

_CS_XBS5_ILP32_OFF32_LIBS,

_CS_XBS5_ILP32_OFF32_LINTFLAGS,

_CS_XBS5_ILP32_OFFBIG_CFLAGS,

_CS_XBS5_ILP32_OFFBIG_LDFLAGS,

_CS_XBS5_ILP32_OFFBIG_LIBS,

_CS_XBS5_ILP32_OFFBIG_LINTFLAGS,

_CS_XBS5_LP64_OFF64_CFLAGS,

_CS_XBS5_LP64_OFF64_LDFLAGS,

_CS_XBS5_LP64_OFF64_LIBS,

_CS_XBS5_LP64_OFF64_LINTFLAGS,

_CS_XBS5_LPBIG_OFFBIG_CFLAGS,

_CS_XBS5_LPBIG_OFFBIG_LDFLAGS,

_CS_XBS5_LPBIG_OFFBIG_LIBS,

_CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,


_CS_POSIX_V6_ILP32_OFF32_CFLAGS,

_CS_POSIX_V6_ILP32_OFF32_LDFLAGS,

_CS_POSIX_V6_ILP32_OFF32_LIBS,

_CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,

_CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,

_CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,

_CS_POSIX_V6_ILP32_OFFBIG_LIBS,

_CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,

_CS_POSIX_V6_LP64_OFF64_CFLAGS,

_CS_POSIX_V6_LP64_OFF64_LDFLAGS,

_CS_POSIX_V6_LP64_OFF64_LIBS,

_CS_POSIX_V6_LP64_OFF64_LINTFLAGS,

_CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,

_CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,

_CS_POSIX_V6_LPBIG_OFFBIG_LIBS,

_CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS

};
# 557 "/usr/include/unistd.h" 3
extern "C" long pathconf(const char *, int) throw();



extern "C" long fpathconf(int, int) throw();


extern "C" long sysconf(int) throw();



extern "C" size_t confstr(int, char *, size_t) throw();




extern "C" __pid_t getpid() throw();


extern "C" __pid_t getppid() throw();




extern "C" __pid_t getpgrp() throw();
# 591 "/usr/include/unistd.h" 3
extern "C" __pid_t __getpgid(__pid_t) throw();

extern "C" __pid_t getpgid(__pid_t) throw();
# 600 "/usr/include/unistd.h" 3
extern "C" int setpgid(__pid_t, __pid_t) throw();
# 617 "/usr/include/unistd.h" 3
extern "C" int setpgrp() throw();
# 634 "/usr/include/unistd.h" 3
extern "C" __pid_t setsid() throw();



extern "C" __pid_t getsid(__pid_t) throw();



extern "C" __uid_t getuid() throw();


extern "C" __uid_t geteuid() throw();


extern "C" __gid_t getgid() throw();


extern "C" __gid_t getegid() throw();




extern "C" int getgroups(int, __gid_t []) throw();



extern "C" int group_member(__gid_t) throw();
# 667 "/usr/include/unistd.h" 3
extern "C" int setuid(__uid_t) throw();




extern "C" int setreuid(__uid_t, __uid_t) throw();




extern "C" int seteuid(__uid_t) throw();
# 684 "/usr/include/unistd.h" 3
extern "C" int setgid(__gid_t) throw();




extern "C" int setregid(__gid_t, __gid_t) throw();




extern "C" int setegid(__gid_t) throw();
# 700 "/usr/include/unistd.h" 3
extern "C" int getresuid(__uid_t *, __uid_t *, __uid_t *) throw();




extern "C" int getresgid(__gid_t *, __gid_t *, __gid_t *) throw();




extern "C" int setresuid(__uid_t, __uid_t, __uid_t) throw();




extern "C" int setresgid(__gid_t, __gid_t, __gid_t) throw();
# 723 "/usr/include/unistd.h" 3
extern "C" __pid_t fork() throw();
# 730 "/usr/include/unistd.h" 3
extern "C" __pid_t vfork() throw();
# 736 "/usr/include/unistd.h" 3
extern "C" char *ttyname(int) throw();



extern "C" int ttyname_r(int, char *, size_t) throw();




extern "C" int isatty(int) throw();
# 751 "/usr/include/unistd.h" 3
extern "C" int ttyslot() throw();




extern "C" int link(const char *, const char *) throw();
# 762 "/usr/include/unistd.h" 3
extern "C" int linkat(int, const char *, int, const char *, int) throw();
# 769 "/usr/include/unistd.h" 3
extern "C" int symlink(const char *, const char *) throw();
# 775 "/usr/include/unistd.h" 3
extern "C" ssize_t readlink(const char *__restrict__, char *__restrict__, size_t) throw();
# 782 "/usr/include/unistd.h" 3
extern "C" int symlinkat(const char *, int, const char *) throw();



extern "C" ssize_t readlinkat(int, const char *__restrict__, char *__restrict__, size_t) throw();
# 792 "/usr/include/unistd.h" 3
extern "C" int unlink(const char *) throw();



extern "C" int unlinkat(int, const char *, int) throw();




extern "C" int rmdir(const char *) throw();



extern "C" __pid_t tcgetpgrp(int) throw();


extern "C" int tcsetpgrp(int, __pid_t) throw();
# 815 "/usr/include/unistd.h" 3
extern "C" char *getlogin();
# 823 "/usr/include/unistd.h" 3
extern "C" int getlogin_r(char *, size_t);




extern "C" int setlogin(const char *) throw();
# 59 "/usr/include/getopt.h" 3
extern "C" { extern char *optarg; }
# 73 "/usr/include/getopt.h" 3
extern "C" { extern int optind; }




extern "C" { extern int opterr; }



extern "C" { extern int optopt; }
# 152 "/usr/include/getopt.h" 3
extern "C" int getopt(int, char *const *, const char *) throw();
# 845 "/usr/include/unistd.h" 3
extern "C" int gethostname(char *, size_t) throw();
# 852 "/usr/include/unistd.h" 3
extern "C" int sethostname(const char *, size_t) throw();




extern "C" int sethostid(long) throw();
# 863 "/usr/include/unistd.h" 3
extern "C" int getdomainname(char *, size_t) throw();

extern "C" int setdomainname(const char *, size_t) throw();
# 872 "/usr/include/unistd.h" 3
extern "C" int vhangup() throw();


extern "C" int revoke(const char *) throw();
# 883 "/usr/include/unistd.h" 3
extern "C" int profil(unsigned short *, size_t, size_t, unsigned) throw();
# 891 "/usr/include/unistd.h" 3
extern "C" int acct(const char *) throw();



extern "C" char *getusershell() throw();
extern "C" void endusershell() throw();
extern "C" void setusershell() throw();
# 903 "/usr/include/unistd.h" 3
extern "C" int daemon(int, int) throw();
# 910 "/usr/include/unistd.h" 3
extern "C" int chroot(const char *) throw();



extern "C" char *getpass(const char *);
# 923 "/usr/include/unistd.h" 3
extern "C" int fsync(int);
# 930 "/usr/include/unistd.h" 3
extern "C" long gethostid();


extern "C" void sync() throw();




extern "C" int getpagesize() throw() __attribute__((__const__));




extern "C" int getdtablesize() throw();




extern "C" int truncate(const char *, __off_t) throw();
# 960 "/usr/include/unistd.h" 3
extern "C" int truncate64(const char *, __off64_t) throw();
# 970 "/usr/include/unistd.h" 3
extern "C" int ftruncate(int, __off_t) throw();
# 980 "/usr/include/unistd.h" 3
extern "C" int ftruncate64(int, __off64_t) throw();
# 990 "/usr/include/unistd.h" 3
extern "C" int brk(void *) throw();
# 996 "/usr/include/unistd.h" 3
extern "C" void *sbrk(intptr_t) throw();
# 1011 "/usr/include/unistd.h" 3
extern "C" long syscall(long, ...) throw();
# 1034 "/usr/include/unistd.h" 3
extern "C" int lockf(int, int, __off_t);
# 1044 "/usr/include/unistd.h" 3
extern "C" int lockf64(int, int, __off64_t);
# 1065 "/usr/include/unistd.h" 3
extern "C" int fdatasync(int);
# 1073 "/usr/include/unistd.h" 3
extern "C" char *crypt(const char *, const char *) throw();




extern "C" void encrypt(char *, int) throw();
# 1085 "/usr/include/unistd.h" 3
extern "C" void swab(const void *__restrict__, void *__restrict__, ssize_t) throw();
# 1094 "/usr/include/unistd.h" 3
extern "C" char *ctermid(char *) throw();
# 12 "src/cuda_fi_prerun/parboil.h"
extern "C" { struct pb_Parameters {
char *outFile;


char **inpFiles;



int synchronizeGpu;
# 27 "src/cuda_fi_prerun/parboil.h"
}; }
# 39 "src/cuda_fi_prerun/parboil.h"
extern "C" pb_Parameters *pb_ReadParameters(int *, char **);




extern "C" void pb_FreeParameters(pb_Parameters *);




extern "C" int pb_Parameters_CountInputs(pb_Parameters *);



extern "C" { typedef unsigned long long pb_Timestamp; }




enum pb_TimerState {
pb_Timer_STOPPED,
pb_Timer_RUNNING
};

extern "C" { struct pb_Timer {
pb_TimerState state;
pb_Timestamp elapsed;
pb_Timestamp init;


}; }
# 76 "src/cuda_fi_prerun/parboil.h"
extern "C" void pb_ResetTimer(pb_Timer *);
# 84 "src/cuda_fi_prerun/parboil.h"
extern "C" void pb_StartTimer(pb_Timer *);
# 91 "src/cuda_fi_prerun/parboil.h"
extern "C" void pb_StopTimer(pb_Timer *);



extern "C" double pb_GetElapsedTime(pb_Timer *);


enum pb_TimerID {
pb_TimerID_NONE,
pb_TimerID_IO,
pb_TimerID_GPU,
pb_TimerID_COPY,

pb_TimerID_COMPUTE,


pb_TimerID_LAST
};


extern "C" { struct pb_TimerSet {
pb_TimerID current;
pb_Timer timers[pb_TimerID_LAST];
}; }



extern "C" void pb_InitializeTimerSet(pb_TimerSet *);
# 124 "src/cuda_fi_prerun/parboil.h"
extern "C" void pb_SwitchToTimer(pb_TimerSet *, pb_TimerID);



extern "C" void pb_PrintTimerSet(pb_TimerSet *);
# 71 "/usr/include/assert.h" 3
extern "C" void __assert_fail(const char *, const char *, unsigned, const char *) throw() __attribute__((__noreturn__));




extern "C" void __assert_perror_fail(int, const char *, unsigned, const char *) throw() __attribute__((__noreturn__));
# 84 "/usr/include/assert.h" 3
extern "C" void __assert(const char *, const char *, int) throw() __attribute__((__noreturn__));
# 18 "src/cuda_fi_prerun/randomc.h"
typedef signed int int32;
typedef unsigned uint32;
# 38 "src/cuda_fi_prerun/randomc.h"
# 13 "src/cuda_fi_prerun/petri.h"
extern void PetrinetKernel__entry(int *, int, int, int);
# 202 "src/cuda_fi_prerun/petri_kernel.cu"
void PetrinetKernel__entry(int *g_s, float *g_v, int *g_m, int n, int s, int seed, _gpufi_data_ *gpufi_dev);
# 29 "src/cuda_fi_prerun/main.cu"
static int N; static int s; static int t; static int N2; static int NSQUARE2;
uint32 host_mt[624];
extern void *AllocateDeviceMemory(int);
extern void CopyFromDeviceMemory(void *, void *, int);
extern void CopyFromHostMemory(void *, void *, int);
extern void FreeDeviceMemory(void *);
extern void PetrinetOnDevice(pb_TimerSet *, pb_Parameters *);
extern void compute_statistics();
float results[4];
float *h_vars;
int *h_maxs;
int main(int argc, char **argv)
{
auto pb_TimerSet timers;
auto pb_Parameters *params;
pb_InitializeTimerSet(&timers);
GPUFI_INIT(1, 8);


params = pb_ReadParameters(&argc, argv);
if (argc < 4)
{
printf("Usage: petri n s t\nn: the place-transition grid is 2nX2n\ns: the maximum steps in a trajectory\nt: number of trajectories\n");
GPUFI_HALT((char *)("fi_profile.txt"));
return -1;
}
pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);
N = atoi(argv[1]);
if (N < 1)
{
GPUFI_HALT((char *)("fi_profile.txt"));
return -1;
}
s = atoi(argv[2]);
if (s < 1)
{
GPUFI_HALT((char *)("fi_profile.txt"));
return -1;
}
t = atoi(argv[3]);
if (t < 1)
{
GPUFI_HALT((char *)("fi_profile.txt"));
return -1;
}
N2 = N + N;
NSQUARE2 = N * N2;
h_vars = (float *)malloc(t * sizeof(float));
h_maxs = (int *)malloc(t * sizeof(int));
# 80 "src/cuda_fi_prerun/main.cu"
PetrinetOnDevice(&timers, params);
pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);
compute_statistics();
free(h_vars);
free(h_maxs);
pb_SwitchToTimer(&timers, pb_TimerID_IO);
printf("petri N=%d s=%d t=%d\n", N, s, t);
printf("mean_vars: %f    var_vars: %f\n", (results)[0], (results)[1]);
printf("mean_maxs: %f    var_maxs: %f\n", (results)[2], (results)[3]);
if (params->outFile)
{
auto FILE *out;
out = fopen(params->outFile, "w");
fprintf(out, "%f %f %f %f\n", (results)[0], (results)[1], (results)[2], (results)[3]);
fclose(out);
}
pb_SwitchToTimer(&timers, pb_TimerID_NONE);
pb_PrintTimerSet(&timers);
pb_FreeParameters(params);
GPUFI_HALT((char *)("fi_profile.txt"));
return 0;
GPUFI_HALT((char *)("fi_profile.txt"));
}

void compute_statistics()
{
auto float sum = (0);
auto float sum_vars = (0);
auto float sum_max = (0);
auto float sum_max_vars = (0);
auto int i;
for (i = 0; i < t; i++)
{
sum += h_vars[i];
sum_vars += h_vars[i] * h_vars[i];
sum_max += h_maxs[i];
sum_max_vars += h_maxs[i] * h_maxs[i];
}
((results)[0]) = sum / t;
((results)[1]) = sum_vars / t - (results)[0] * (results)[0];
((results)[2]) = sum_max / t;
((results)[3]) = sum_max_vars / t - (results)[2] * (results)[2];
}

void PetrinetOnDevice(pb_TimerSet *timers, pb_Parameters *params)
{
# 128 "src/cuda_fi_prerun/main.cu"
auto int i;
auto int unit_size = ((NSQUARE2 * (sizeof(int) + sizeof(char)) + sizeof(float)) + sizeof(int));
auto int block_num = (750000000 / unit_size);
auto int *p_hmaxs;
auto float *p_hvars;
auto int *g_places;
auto float *g_vars;
auto int *g_maxs;
auto dim3 grid;
auto dim3 threads;
auto dim3 grid1;
pb_SwitchToTimer(timers, pb_TimerID_COPY);
g_places = (int *)AllocateDeviceMemory(((unit_size - sizeof(float)) - sizeof(int)) * block_num);
{
auto cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
g_vars = (float *)AllocateDeviceMemory(block_num * sizeof(float));
{
auto cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
g_maxs = (int *)AllocateDeviceMemory(block_num * sizeof(int));
{
auto cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
# 166 "src/cuda_fi_prerun/main.cu"
(grid.x) = block_num;
# 169 "src/cuda_fi_prerun/main.cu"
(grid.y) = (1);
(grid.z) = (1);
(grid.x) = (256);
# 174 "src/cuda_fi_prerun/main.cu"
(grid.y) = (1);
(grid.z) = (1);
p_hmaxs = h_maxs;
p_hvars = h_vars;
# 180 "src/cuda_fi_prerun/main.cu"
for (i = 0; i < (t - block_num); i += block_num)
{
if (params->synchronizeGpu)
{
cudaThreadSynchronize();
}
pb_SwitchToTimer(timers, pb_TimerID_GPU);

cudaMalloc((void **)(&gpufi_dev__cuda_shadow_variable__), sizeof(_gpufi_data_));
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 189, cudaGetErrorString(err)); exit(-1); } }
cudaMemcpy(gpufi_dev__cuda_shadow_variable__, &gpufi_host, sizeof(_gpufi_data_), cudaMemcpyHostToDevice);
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 191, cudaGetErrorString(err)); exit(-1); } }


cudaConfigureCall(grid, threads) ? ((void)0) : (PetrinetKernel__entry)(g_places, g_vars, g_maxs, N, s, 5489 * (i + 1), gpufi_dev__cuda_shadow_variable__);

cudaMemcpy(&gpufi_host, gpufi_dev__cuda_shadow_variable__, sizeof(_gpufi_data_), cudaMemcpyDeviceToHost);
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 197, cudaGetErrorString(err)); exit(-1); } }
cudaFree(gpufi_dev__cuda_shadow_variable__);
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 199, cudaGetErrorString(err)); exit(-1); } }


{
auto cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
if (params->synchronizeGpu)
{
cudaThreadSynchronize();
}
pb_SwitchToTimer(timers, pb_TimerID_COPY);
CopyFromDeviceMemory(p_hmaxs, g_maxs, block_num * sizeof(int));
{
auto cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
CopyFromDeviceMemory(p_hvars, g_vars, block_num * sizeof(float));
{
auto cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
if (params->synchronizeGpu)
{
cudaThreadSynchronize();
}
pb_SwitchToTimer(timers, pb_TimerID_COMPUTE);
p_hmaxs += block_num;
p_hvars += block_num;
}
(grid1.x) = t - i;
(grid1.y) = (1);
(grid1.z) = (1);
pb_SwitchToTimer(timers, pb_TimerID_GPU);

cudaMalloc((void **)(&gpufi_dev__cuda_shadow_variable__), sizeof(_gpufi_data_));
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 244, cudaGetErrorString(err)); exit(-1); } }
cudaMemcpy(gpufi_dev__cuda_shadow_variable__, &gpufi_host, sizeof(_gpufi_data_), cudaMemcpyHostToDevice);
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 246, cudaGetErrorString(err)); exit(-1); } }


cudaConfigureCall(grid1, threads) ? ((void)0) : (PetrinetKernel__entry)(g_places, g_vars, g_maxs, N, s, time(__null), gpufi_dev__cuda_shadow_variable__);

cudaMemcpy(&gpufi_host, gpufi_dev__cuda_shadow_variable__, sizeof(_gpufi_data_), cudaMemcpyDeviceToHost);
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 252, cudaGetErrorString(err)); exit(-1); } }
cudaFree(gpufi_dev__cuda_shadow_variable__);
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 254, cudaGetErrorString(err)); exit(-1); } }


{
auto cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
# 266 "src/cuda_fi_prerun/main.cu"
if (params->synchronizeGpu)
{
cudaThreadSynchronize();
}
pb_SwitchToTimer(timers, pb_TimerID_COPY);
CopyFromDeviceMemory(p_hmaxs, g_maxs, (t - i) * sizeof(int));
{
auto cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
CopyFromDeviceMemory(p_hvars, g_vars, (t - i) * sizeof(float));
{
auto cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
# 289 "src/cuda_fi_prerun/main.cu"
FreeDeviceMemory(g_places);
{
auto cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
FreeDeviceMemory(g_vars);
{
auto cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
FreeDeviceMemory(g_maxs);
{
auto cudaError_t err = cudaGetLastError();
if (err)
{
fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
}
}
}
# 317 "src/cuda_fi_prerun/main.cu"
void *AllocateDeviceMemory(int size)
{
auto int *mem;
printf("cudaMalloc(%d)\n", size);
cudaMalloc((void **)(&mem), size);
return mem;
}
# 327 "src/cuda_fi_prerun/main.cu"
void CopyFromDeviceMemory(void *h_p, void *d_p, int size)
{
cudaMemcpy(h_p, d_p, size, cudaMemcpyDeviceToHost);
}
# 334 "src/cuda_fi_prerun/main.cu"
void CopyFromHostMemory(void *d_p, void *h_p, int size)
{
cudaMemcpy(d_p, h_p, size, cudaMemcpyHostToDevice);
}
# 341 "src/cuda_fi_prerun/main.cu"
void FreeDeviceMemory(void *mem)
{
if (mem != (__null))
{
cudaFree(mem);
}
}

# 1 "main.cudafe1.stub.c" 1 3

extern "C" {

# 1 "main.fatbin.c" 1 3
# 1 "/usr/local/cuda/bin/../include/__cudaFatFormat.h" 1 3
# 83 "/usr/local/cuda/bin/../include/__cudaFatFormat.h" 3
extern "C" {
# 97 "/usr/local/cuda/bin/../include/__cudaFatFormat.h" 3
typedef struct {
    char* gpuProfileName;
    char* cubin;
} __cudaFatCubinEntry;
# 113 "/usr/local/cuda/bin/../include/__cudaFatFormat.h" 3
typedef struct {
    char* gpuProfileName;
    char* ptx;
} __cudaFatPtxEntry;
# 125 "/usr/local/cuda/bin/../include/__cudaFatFormat.h" 3
typedef struct __cudaFatDebugEntryRec {
    char* gpuProfileName;
    char* debug;
    struct __cudaFatDebugEntryRec *next;
    unsigned int size;
} __cudaFatDebugEntry;


typedef enum {
      __cudaFatDontSearchFlag = (1 << 0),
      __cudaFatDontCacheFlag = (1 << 1),
      __cudaFatSassDebugFlag = (1 << 2)
} __cudaFatCudaBinaryFlag;
# 146 "/usr/local/cuda/bin/../include/__cudaFatFormat.h" 3
typedef struct {
    char* name;
} __cudaFatSymbol;
# 160 "/usr/local/cuda/bin/../include/__cudaFatFormat.h" 3
typedef struct __cudaFatCudaBinaryRec {
    unsigned long magic;
    unsigned long version;
    unsigned long gpuInfoVersion;
    char* key;
    char* ident;
    char* usageMode;
    __cudaFatPtxEntry *ptx;
    __cudaFatCubinEntry *cubin;
    __cudaFatDebugEntry *debug;
    void* debugInfo;
    unsigned int flags;
    __cudaFatSymbol *exported;
    __cudaFatSymbol *imported;
    struct __cudaFatCudaBinaryRec *dependends;
    unsigned int characteristic;
} __cudaFatCudaBinary;
# 196 "/usr/local/cuda/bin/../include/__cudaFatFormat.h" 3
    typedef enum {
        __cudaFatAvoidPTX,
        __cudaFatPreferBestCode
    } __cudaFatCompilationPolicy;
# 219 "/usr/local/cuda/bin/../include/__cudaFatFormat.h" 3
void fatGetCubinForGpuWithPolicy( __cudaFatCudaBinary *binary, __cudaFatCompilationPolicy policy, char* gpuName, char* *cubin, char* *dbgInfoFile );
# 230 "/usr/local/cuda/bin/../include/__cudaFatFormat.h" 3
void fatFreeCubin( char* cubin, char* dbgInfoFile );


}
# 2 "main.fatbin.c" 2 3




extern "C" {


static const unsigned long long __deviceText_$compute_11$[] = {
0x6f69737265762e09ull,0x2e090a342e31206eull,0x7320746567726174ull,0x616d202c31315f6dull,
0x6f745f3436665f70ull,0x2f2f090a3233665full,0x656c69706d6f6320ull,0x2f20687469772064ull,
0x61636f6c2f727375ull,0x6f2f616475632f6cull,0x696c2f34366e6570ull,0x2f090a65622f2f62ull,
0x6e65706f766e202full,0x6220332e32206363ull,0x206e6f20746c6975ull,0x2d37302d39303032ull,
0x2d2f2f090a0a3230ull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x43202f2f090a2d2dull,0x676e696c69706d6full,0x70632e6e69616d20ull,0x742f2820692e3370ull,
0x23494263632f706dull,0x296b4b423048462eull,0x2d2d2d2d2f2f090aull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x0a2d2d2d2d2d2d2dull,0x2d2d2d2d2f2f090aull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x0a2d2d2d2d2d2d2dull,0x6974704f202f2f09ull,0x2f2f090a3a736e6full,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x202f2f090a2d2d2dull,
0x3a74656772615420ull,0x415349202c787470ull,0x202c31315f6d733aull,0x6c3a6e6169646e45ull,
0x50202c656c747469ull,0x53207265746e696full,0x090a32333a657a69ull,0x09334f2d20202f2full,
0x7a696d6974704f28ull,0x656c206e6f697461ull,0x2f2f090a296c6576ull,0x44280930672d2020ull,
0x76656c2067756265ull,0x202f2f090a296c65ull,0x65522809326d2d20ull,0x7664612074726f70ull,
0x29736569726f7369ull,0x2d2d2d2d2f2f090aull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,0x2d2d2d2d2d2d2d2dull,
0x0a2d2d2d2d2d2d2dull,0x09656c69662e090aull,0x6d6d6f633c220931ull,0x656e696c2d646e61ull,
0x6c69662e090a223eull,0x69616d2209320965ull,0x6566616475632e6eull,0x090a227570672e32ull,
0x093309656c69662eull,0x6475632f63727322ull,0x6572705f69665f61ull,0x667570672f6e7572ull,
0x662e090a22682e69ull,0x2f22093409656c69ull,0x2f62696c2f727375ull,0x363834692f636367ull,
0x672d78756e696c2dull,0x322e332e342f756eull,0x6564756c636e692full,0x2e6665646474732full,
0x6c69662e090a2268ull,0x73752f2209350965ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,
0x6c636e692f2e2e2full,0x2f7472632f656475ull,0x725f656369766564ull,0x682e656d69746e75ull,
0x656c69662e090a22ull,0x7273752f22093609ull,0x632f6c61636f6c2full,0x2f6e69622f616475ull,
0x756c636e692f2e2eull,0x5f74736f682f6564ull,0x2e73656e69666564ull,0x6c69662e090a2268ull,
0x73752f2209370965ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,0x6c636e692f2e2e2full,
0x6c6975622f656475ull,0x657079745f6e6974ull,0x662e090a22682e73ull,0x2f22093809656c69ull,
0x61636f6c2f727375ull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x65642f6564756c63ull,
0x7079745f65636976ull,0x2e090a22682e7365ull,0x22093909656c6966ull,0x636f6c2f7273752full,
0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,0x642f6564756c636eull,0x79745f7265766972ull,
0x090a22682e736570ull,0x303109656c69662eull,0x6c2f7273752f2209ull,0x6475632f6c61636full,
0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x657275747865742full,0x682e73657079745full,
0x656c69662e090a22ull,0x73752f2209313109ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,
0x6c636e692f2e2e2full,0x746365762f656475ull,0x73657079745f726full,0x69662e090a22682eull,
0x2f2209323109656cull,0x61636f6c2f727375ull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,
0x65642f6564756c63ull,0x75616c5f65636976ull,0x617261705f68636eull,0x682e73726574656dull,
0x656c69662e090a22ull,0x73752f2209333109ull,0x2f6c61636f6c2f72ull,0x6e69622f61647563ull,
0x6c636e692f2e2e2full,0x2f7472632f656475ull,0x5f656761726f7473ull,0x22682e7373616c63ull,
0x09656c69662e090aull,0x7273752f22093431ull,0x6564756c636e692full,0x79742f737469622full,
0x090a22682e736570ull,0x353109656c69662eull,0x692f7273752f2209ull,0x742f6564756c636eull,
0x090a22682e656d69ull,0x363109656c69662eull,0x75632f6372732209ull,0x72705f69665f6164ull,
0x6e61722f6e757265ull,0x0a22682e636d6f64ull,0x3109656c69662e09ull,0x2f7273752f220937ull,
0x75632f6c61636f6cull,0x2e2f6e69622f6164ull,0x64756c636e692f2eull,0x5f31315f6d732f65ull,
0x665f63696d6f7461ull,0x736e6f6974636e75ull,0x69662e090a22682eull,0x732209383109656cull,
0x5f616475632f6372ull,0x75726572705f6966ull,0x5f69667570672f6eull,0x632e6c656e72656bull,
0x6c69662e090a2275ull,0x7273220939310965ull,0x665f616475632f63ull,0x6e75726572705f69ull,
0x65675f646e61722full,0x2e090a2275632e6eull,0x09303209656c6966ull,0x6475632f63727322ull,
0x6572705f69665f61ull,0x727465702f6e7572ull,0x6c656e72656b5f69ull,0x662e090a2275632eull,
0x2209313209656c69ull,0x636f6c2f7273752full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,
0x632f6564756c636eull,0x75665f6e6f6d6d6full,0x2e736e6f6974636eull,0x6c69662e090a2268ull,
0x752f220932320965ull,0x6c61636f6c2f7273ull,0x69622f616475632full,0x636e692f2e2e2f6eull,
0x7472632f6564756cull,0x616d5f636e75662full,0x090a22682e6f7263ull,0x333209656c69662eull,
0x6c2f7273752f2209ull,0x6475632f6c61636full,0x2e2e2f6e69622f61ull,0x6564756c636e692full,
0x75665f6874616d2full,0x2e736e6f6974636eull,0x6c69662e090a2268ull,0x752f220934320965ull,
0x6c61636f6c2f7273ull,0x69622f616475632full,0x636e692f2e2e2f6eull,0x7665642f6564756cull,
0x636e75665f656369ull,0x22682e736e6f6974ull,0x09656c69662e090aull,0x7273752f22093532ull,
0x632f6c61636f6c2full,0x2f6e69622f616475ull,0x756c636e692f2e2eull,0x5f6874616d2f6564ull,
0x746e6174736e6f63ull,0x662e090a22682e73ull,0x2209363209656c69ull,0x636f6c2f7273752full,
0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,0x732f6564756c636eull,0x6f74615f32315f6dull,
0x636e75665f63696dull,0x22682e736e6f6974ull,0x09656c69662e090aull,0x7273752f22093732ull,
0x632f6c61636f6c2full,0x2f6e69622f616475ull,0x756c636e692f2e2eull,0x33315f6d732f6564ull,
0x5f656c62756f645full,0x6e6f6974636e7566ull,0x662e090a22682e73ull,0x2209383209656c69ull,
0x636f6c2f7273752full,0x2f616475632f6c61ull,0x692f2e2e2f6e6962ull,0x632f6564756c636eull,
0x79745f6e6f6d6d6full,0x090a22682e736570ull,0x393209656c69662eull,0x6c2f7273752f2209ull,
0x6475632f6c61636full,0x2e2e2f6e69622f61ull,0x6564756c636e692full,0x657275747865742full,
0x665f68637465665full,0x736e6f6974636e75ull,0x69662e090a22682eull,0x2f2209303309656cull,
0x61636f6c2f727375ull,0x622f616475632f6cull,0x6e692f2e2e2f6e69ull,0x616d2f6564756c63ull,
0x74636e75665f6874ull,0x6c62645f736e6f69ull,0x22682e317874705full,0x626f6c672e090a0aull,
0x203233752e206c61ull,0x65645f6966757067ull,0x6168732e090a3b76ull,0x696c612e20646572ull,
0x38622e2034206e67ull,0x363934325b746d20ull,0x6e6f632e090a3b5dull,0x67696c612e207473ull,
0x2038622e2031206eull,0x6174736e6f635f5full,0x35315b363834746eull,0x3578307b203d205dull,
0x302c353678302c30ull,0x323778302c343778ull,0x78302c393678302cull,0x2c353678302c6536ull,
0x3478302c34377830ull,0x302c353678302c62ull,0x653678302c323778ull,0x78302c353678302cull,
0x3b7d3078302c6336ull,0x74736e6f632e090aull,0x206e67696c612e20ull,0x5f5f2038622e2031ull,
0x746e6174736e6f63ull,0x3d205d395b333934ull,0x302c653478307b20ull,0x313578302c333578ull,
0x78302c353578302cull,0x2c323578302c3134ull,0x3378302c35347830ull,0x0a3b7d3078302c32ull,
0x2074736e6f632e09ull,0x31206e67696c612eull,0x635f5f2038622e20ull,0x34746e6174736e6full,
0x203d205d395b3439ull,0x78302c373678307bull,0x2c303778302c6635ull,0x3678302c63367830ull,
0x302c333678302c31ull,0x333778302c353678ull,0x090a3b7d3078302cull,0x2e2074736e6f632eull,
0x2031206e67696c61ull,0x6f635f5f2038622eull,0x3834746e6174736eull,0x7b203d205d345b37ull,
0x3578302c37367830ull,0x302c333778302c66ull,0x632e090a3b7d3078ull,0x6c612e2074736e6full,
0x622e2031206e6769ull,0x736e6f635f5f2038ull,0x5b383834746e6174ull,0x78307b203d205d34ull,
0x2c663578302c3736ull,0x3078302c36377830ull,0x6e6f632e090a3b7dull,0x67696c612e207473ull,
0x2038622e2031206eull,0x6174736e6f635f5full,0x5d345b393834746eull,0x373678307b203d20ull,
0x78302c663578302cull,0x3b7d3078302c6436ull,0x74736e6f632e090aull,0x206e67696c612e20ull,
0x5f5f2038622e2031ull,0x746e6174736e6f63ull,0x3d205d325b303934ull,0x302c653678307b20ull,
0x632e090a3b7d3078ull,0x6c612e2074736e6full,0x622e2031206e6769ull,0x736e6f635f5f2038ull,
0x5b313934746e6174ull,0x78307b203d205d32ull,0x3b7d3078302c3337ull,0x74736e6f632e090aull,
0x206e67696c612e20ull,0x5f5f2038622e2031ull,0x746e6174736e6f63ull,0x3d205d355b323934ull,
0x302c333778307b20ull,0x353678302c353678ull,0x78302c343678302cull,0x652e090a0a3b7d30ull,
0x315a5f207972746eull,0x656e697274655034ull,0x506c656e72654b74ull,0x6969695f53665069ull,
0x667570675f323150ull,0x205f617461645f69ull,0x7261702e09090a28ull,0x203233752e206d61ull,
0x6170616475635f5full,0x5034315a5f5f6d72ull,0x4b74656e69727465ull,0x5069506c656e7265ull,
0x31506969695f5366ull,0x5f69667570675f32ull,0x5f5f5f5f61746164ull,0x617261705f6c6176ull,
0x09090a2c735f676dull,0x2e206d617261702eull,0x75635f5f20323375ull,0x5f5f6d7261706164ull,
0x697274655034315aull,0x656e72654b74656eull,0x695f53665069506cull,0x70675f3231506969ull,
0x617461645f696675ull,0x5f6c61765f5f5f5full,0x765f676d61726170ull,0x7261702e09090a2cull,
0x203233752e206d61ull,0x6170616475635f5full,0x5034315a5f5f6d72ull,0x4b74656e69727465ull,
0x5069506c656e7265ull,0x31506969695f5366ull,0x5f69667570675f32ull,0x5f5f5f5f61746164ull,
0x617261705f6c6176ull,0x09090a2c6d5f676dull,0x2e206d617261702eull,0x75635f5f20323373ull,
0x5f5f6d7261706164ull,0x697274655034315aull,0x656e72654b74656eull,0x695f53665069506cull,
0x70675f3231506969ull,0x617461645f696675ull,0x5f6c61765f5f5f5full,0x0a2c6e6d61726170ull,
0x6d617261702e0909ull,0x5f5f203233732e20ull,0x6d72617061647563ull,0x74655034315a5f5full,
0x72654b74656e6972ull,0x53665069506c656eull,0x5f3231506969695full,0x61645f6966757067ull,
0x61765f5f5f5f6174ull,0x736d617261705f6cull,0x7261702e09090a2cull,0x203233732e206d61ull,
0x6170616475635f5full,0x5034315a5f5f6d72ull,0x4b74656e69727465ull,0x5069506c656e7265ull,
0x31506969695f5366ull,0x5f69667570675f32ull,0x5f5f5f5f61746164ull,0x617261705f6c6176ull,
0x090a2c646565736dull,0x206d617261702e09ull,0x635f5f203233752eull,0x5f6d726170616475ull,
0x7274655034315a5full,0x6e72654b74656e69ull,0x5f53665069506c65ull,0x675f323150696969ull,
0x7461645f69667570ull,0x69667570675f5f61ull,0x7b090a297665645full,0x2e206765722e090aull,
0x3c68722520363175ull,0x722e090a3b3e3333ull,0x203233752e206765ull,0x2e090a3b31767225ull,
0x3233752e20676572ull,0x3e3730373c722520ull,0x206765722e090a3bull,0x3c6625203233662eull,
0x722e090a3b3e3931ull,0x646572702e206765ull,0x3e3431313c702520ull,0x09636f6c2e090a3bull,
0x3009323032093032ull,0x5f5f3142424c240aull,0x697274655034315aull,0x656e72654b74656eull,
0x695f53665069506cull,0x70675f3231506969ull,0x617461645f696675ull,0x636f6c2e090a3a5full,
0x0934303209303209ull,0x61702e646c090a30ull,0x203233752e6d6172ull,0x5f5b202c31722509ull,
0x726170616475635full,0x655034315a5f5f6dull,0x654b74656e697274ull,0x665069506c656e72ull,
0x3231506969695f53ull,0x645f69667570675full,0x7570675f5f617461ull,0x3b5d7665645f6966ull,
0x6f6c672e646c090aull,0x203233752e6c6162ull,0x255b202c32722509ull,0x3b5d3430312b3172ull,
0x33752e747663090aull,0x2509203631752e32ull,0x61746325202c3372ull,0x73090a3b782e6469ull,
0x752e656e2e707465ull,0x2c31702509203233ull,0x7225202c32722520ull,0x2e747663090a3b33ull,
0x203631752e323375ull,0x7425202c34722509ull,0x40090a3b782e6469ull,0x2061726220317025ull,
0x39395f305f4c2409ull,0x646c090a3b363835ull,0x2e6c61626f6c672eull,0x3572250920323375ull,
0x312b3172255b202cull,0x6573090a3b5d3830ull,0x33752e71652e7074ull,0x202c327025092032ull,
0x347225202c357225ull,0x2032702540090a3bull,0x5f4c240920617262ull,0x3b30333339395f30ull,
0x39395f305f4c240aull,0x6f6d090a3a363835ull,0x2509203233732e76ull,0x090a3b31202c3672ull,
0x20696e752e617262ull,0x39395f305f4c2409ull,0x5f4c240a3b343730ull,0x3a30333339395f30ull,
0x33732e766f6d090aull,0x202c367225092032ull,0x5f305f4c240a3b30ull,0x090a3a3437303939ull,
0x203233752e766f6dull,0x3b30202c37722509ull,0x6e2e70746573090aull,0x2509203233732e65ull,
0x2c367225202c3370ull,0x40090a3b37722520ull,0x2061726220337025ull,0x315f305f744c2409ull,
0x090a3b3037393531ull,0x61626f6c672e646cull,0x2509203233732e6cull,0x3172255b202c3872ull,
0x6d090a3b5d32332bull,0x09203233752e766full,0x0a3b31202c397225ull,0x656e2e7074657309ull,
0x702509203233732eull,0x202c387225202c34ull,0x2540090a3b397225ull,0x0920617262203470ull,
0x31315f305f744c24ull,0x61090a3b30373935ull,0x09203233752e6464ull,0x7225202c30317225ull,
0x3633353536202c31ull,0x6c672e646c090a3bull,0x2038732e6c61626full,0x5b202c3131722509ull,
0x35332d2b30317225ull,0x6f6d090a3b5d3434ull,0x2509203233752e76ull,0x0a3b30202c323172ull,
0x656e2e7074657309ull,0x702509203233732eull,0x2c31317225202c35ull,0x090a3b3231722520ull,
0x6172622035702540ull,0x5f305f744c240920ull,0x0a3b323834363131ull,0x383109636f6c2e09ull,
0x090a300931373209ull,0x203631732e766f6dull,0x31202c3168722509ull,0x6c672e7473090a3bull,
0x2038732e6c61626full,0x2d2b303172255b09ull,0x25202c5d34343533ull,0x744c240a3b316872ull,
0x38343631315f305full,0x636f6c2e090a3a32ull,0x0932373209383109ull,0x6c672e646c090a30ull,
0x3233732e6c61626full,0x202c333172250920ull,0x332d2b303172255bull,0x61090a3b5d323335ull,
0x09203233732e6464ull,0x7225202c34317225ull,0x090a3b31202c3331ull,0x61626f6c672e7473ull,
0x5b09203233732e6cull,0x35332d2b30317225ull,0x317225202c5d3233ull,0x636f6c2e090a3b34ull,
0x0935373209383109ull,0x732e766f6d090a30ull,0x3531722509203233ull,0x7473090a3b30202cull,
0x2e6c61626f6c672eull,0x72255b0920323373ull,0x25202c5d36372b31ull,0x6c2e090a3b353172ull,
0x373209383109636full,0x2e646c090a300936ull,0x732e6c61626f6c67ull,0x3631722509203233ull,
0x2b303172255b202cull,0x0a3b5d323335332dull,0x3233732e62757309ull,0x202c373172250920ull,
0x3b31202c36317225ull,0x6f6c672e7473090aull,0x203233732e6c6162ull,0x30382b3172255b09ull,
0x3b37317225202c5dull,0x3109636f6c2e090aull,0x0a30093737320938ull,0x3233732e766f6d09ull,
0x202c383172250920ull,0x2e7473090a3b312dull,0x732e6c61626f6c67ull,0x3172255b09203233ull,
0x7225202c5d34382bull,0x6f6c2e090a3b3831ull,0x3038320938310963ull,0x672e646c090a3009ull,
0x33732e6c61626f6cull,0x2c39317225092032ull,0x36392b3172255b20ull,0x2e646461090a3b5dull,
0x3272250920323373ull,0x2c39317225202c30ull,0x2e7473090a3b3120ull,0x732e6c61626f6c67ull,
0x3172255b09203233ull,0x7225202c5d36392bull,0x766f6d090a3b3032ull,0x722509203233752eull,
0x090a3b39202c3132ull,0x2e74672e70746573ull,0x3670250920323373ull,0x202c30327225202cull,
0x40090a3b31327225ull,0x2061726220367025ull,0x315f305f744c2409ull,0x090a3b3439393631ull,
0x09383109636f6c2eull,0x6d090a3009333832ull,0x09203631732e766full,0x3b31202c32687225ull,
0x6f6c2e6c756d090aull,0x722509203233752eull,0x30327225202c3232ull,0x61090a3b3434202cull,
0x09203233752e6464ull,0x7225202c33327225ull,0x3b32327225202c31ull,0x6f6c672e7473090aull,
0x092038732e6c6162ull,0x31312b333272255bull,0x32687225202c5d32ull,0x09636f6c2e090a3bull,
0x3009343832093831ull,0x6f6c672e646c090aull,0x203233732e6c6162ull,0x5b202c3432722509ull,
0x3b5d36372b317225ull,0x6f6c672e646c090aull,0x203233752e6c6162ull,0x5b202c3532722509ull,
0x3b5d36392b317225ull,0x6f6c2e6c756d090aull,0x722509203233752eull,0x35327225202c3632ull,
0x61090a3b3434202cull,0x09203233752e6464ull,0x7225202c37327225ull,0x3b36327225202c31ull,
0x6f6c672e7473090aull,0x203233732e6c6162ull,0x312b373272255b09ull,0x327225202c5d3631ull,
0x636f6c2e090a3b34ull,0x0935383209383109ull,0x6c672e646c090a30ull,0x3233752e6c61626full,
0x202c383272250920ull,0x5d36392b3172255bull,0x6c2e6c756d090a3bull,0x2509203233752e6full,
0x327225202c393272ull,0x090a3b3434202c38ull,0x203233752e646461ull,0x25202c3033722509ull,
0x39327225202c3172ull,0x752e646461090a3bull,0x3133722509203233ull,0x202c30337225202cull,
0x6c2e090a3b343231ull,0x383109383109636full,0x766f6d090a300931ull,0x722509203233732eull,
0x0a3b3038202c3233ull,0x3233732e766f6d09ull,0x202c333372250920ull,0x2e766f6d090a3b30ull,
0x3372250920323375ull,0x6e6f635f5f202c34ull,0x363834746e617473ull,0x395f305f4c240a3bull,
0x2f200a3a32343839ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,0x3120656e696c2079ull,
0x636f6c2e090a3238ull,0x0932383109383109ull,0x752e646461090a30ull,0x3533722509203233ull,
0x202c33337225202cull,0x73090a3b31337225ull,0x6c61626f6c672e74ull,0x72255b092038732eull,
0x25202c5d302b3533ull,0x6c2e090a3b323372ull,0x383109383109636full,0x646461090a300931ull,
0x722509203233732eull,0x33337225202c3333ull,0x6461090a3b31202cull,0x2509203233752e64ull,
0x337225202c363372ull,0x3b34337225202c33ull,0x6e6f632e646c090aull,0x25092038732e7473ull,
0x72255b202c323372ull,0x090a3b5d302b3633ull,0x203233752e766f6dull,0x30202c3733722509ull,
0x2e70746573090a3bull,0x09203233732e7165ull,0x337225202c377025ull,0x3b37337225202c32ull,
0x622037702540090aull,0x305f4c2409206172ull,0x3b3031363030315full,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3238312065ull,
0x6562616c20646165ull,0x305f4c242064656cull,0x090a32343839395full,0x203233752e646461ull,
0x25202c3833722509ull,0x3b3133202c343372ull,0x6c2e70746573090aull,0x2509203233732e74ull,
0x36337225202c3870ull,0x0a3b38337225202cull,0x7262203870254009ull,0x5f305f4c24092061ull,
0x240a3b3234383939ull,0x363030315f305f4cull,0x6f6c2e090a3a3031ull,0x3338310938310963ull,
0x2e766f6d090a3009ull,0x6872250920363173ull,0x61090a3b30202c33ull,0x09203233752e6464ull,
0x7225202c39337225ull,0x31337225202c3333ull,0x6c672e7473090a3bull,0x2038732e6c61626full,
0x302b393372255b09ull,0x3b33687225202c5dull,0x3109636f6c2e090aull,0x0a30093638320938ull,
0x626f6c672e646c09ull,0x09203233732e6c61ull,0x255b202c30347225ull,0x0a3b5d30382b3172ull,
0x626f6c672e646c09ull,0x09203233752e6c61ull,0x255b202c31347225ull,0x0a3b5d36392b3172ull,
0x2e6f6c2e6c756d09ull,0x3472250920323375ull,0x2c31347225202c32ull,0x6461090a3b343420ull,
0x2509203233752e64ull,0x317225202c333472ull,0x0a3b32347225202cull,0x626f6c672e747309ull,
0x09203233732e6c61ull,0x32312b333472255bull,0x30347225202c5d30ull,0x5f305f744c240a3bull,
0x0a3a343939363131ull,0x626f6c672e646c09ull,0x09203233752e6c61ull,0x72255b202c327225ull,
0x0a3b5d3430312b31ull,0x656e2e7074657309ull,0x702509203233752eull,0x202c327225202c31ull,
0x744c240a3b337225ull,0x37393531315f305full,0x305f744c240a3a30ull,0x090a3a363638345full,
0x09303209636f6c2eull,0x40090a3009353032ull,0x2061726220317025ull,0x30315f305f4c2409ull,
0x6c090a3b38373331ull,0x6c61626f6c672e64ull,0x722509203233752eull,0x3172255b202c3434ull,
0x090a3b5d3830312bull,0x2e71652e70746573ull,0x3970250920323375ull,0x202c34347225202cull,
0x2540090a3b347225ull,0x0920617262203970ull,0x3130315f305f4c24ull,0x5f4c240a3b323231ull,
0x3837333130315f30ull,0x732e766f6d090a3aull,0x3534722509203233ull,0x7262090a3b31202cull,
0x240920696e752e61ull,0x383030315f305f4cull,0x305f4c240a3b3636ull,0x3a3232313130315full,
0x33732e766f6d090aull,0x2c35347225092032ull,0x305f4c240a3b3020ull,0x3a3636383030315full,
0x33752e766f6d090aull,0x2c36347225092032ull,0x746573090a3b3020ull,0x3233732e656e2e70ull,
0x202c303170250920ull,0x7225202c35347225ull,0x702540090a3b3634ull,0x0920617262203031ull,
0x31315f305f744c24ull,0x6c090a3b38313038ull,0x6c61626f6c672e64ull,0x722509203233732eull,
0x3172255b202c3734ull,0x6d090a3b5d32332bull,0x09203233752e766full,0x3b31202c38347225ull,
0x6e2e70746573090aull,0x2509203233732e65ull,0x347225202c313170ull,0x3b38347225202c37ull,
0x203131702540090aull,0x744c240920617262ull,0x31303831315f305full,0x672e646c090a3b38ull,
0x33732e6c61626f6cull,0x2c30327225092032ull,0x36392b3172255b20ull,0x2e766f6d090a3b5dull,
0x3472250920323375ull,0x73090a3b39202c39ull,0x732e74672e707465ull,0x3231702509203233ull,
0x202c30327225202cull,0x40090a3b39347225ull,0x6172622032317025ull,0x5f305f744c240920ull,
0x0a3b383130383131ull,0x373109636f6c2e09ull,0x090a300933303109ull,0x752e6f6c2e6c756dull,
0x3035722509203233ull,0x202c30327225202cull,0x61090a3b34343136ull,0x09203233752e6464ull,
0x7225202c31357225ull,0x3b30357225202c31ull,0x33752e646461090aull,0x2c32357225092032ull,
0x35202c3135722520ull,0x766f6d090a3b3235ull,0x722509203233732eull,0x090a3b31202c3335ull,
0x6f6c672e6d6f7461ull,0x2e6464612e6c6162ull,0x7672250920323373ull,0x323572255b202c31ull,
0x3b33357225202c5dull,0x33752e646461090aull,0x2c30317225092032ull,0x3536202c31722520ull,
0x646c090a3b363335ull,0x2e6c61626f6c672eull,0x3435722509203873ull,0x2b303172255b202cull,
0x0a3b5d323934332dull,0x3233752e766f6d09ull,0x202c353572250920ull,0x70746573090a3b30ull,
0x203233732e656e2eull,0x25202c3331702509ull,0x357225202c343572ull,0x31702540090a3b35ull,
0x2409206172622033ull,0x3831315f305f744cull,0x6c2e090a3b303335ull,0x363309383109636full,
0x766f6d090a300936ull,0x722509203631732eull,0x090a3b31202c3468ull,0x61626f6c672e7473ull,
0x255b092038732e6cull,0x3934332d2b303172ull,0x34687225202c5d32ull,0x09636f6c2e090a3bull,
0x3009313831093831ull,0x33732e766f6d090aull,0x2c36357225092032ull,0x6d090a3b33303120ull,
0x09203233732e766full,0x3b30202c37357225ull,0x33752e766f6d090aull,0x2c38357225092032ull,
0x74736e6f635f5f20ull,0x0a3b373834746e61ull,0x3130315f305f4c24ull,0x2f2f200a3a343336ull,
0x4c203e706f6f6c3cull,0x79646f6220706f6full,0x383120656e696c20ull,0x09636f6c2e090a32ull,
0x3009323831093831ull,0x33752e646461090aull,0x2c39357225092032ull,0x25202c3735722520ull,
0x2e7473090a3b3172ull,0x732e6c61626f6c67ull,0x393572255b092038ull,0x2c5d36353532362bull,
0x090a3b3635722520ull,0x09383109636f6c2eull,0x61090a3009313831ull,0x09203233732e6464ull,
0x7225202c37357225ull,0x090a3b31202c3735ull,0x203233752e646461ull,0x25202c3036722509ull,
0x357225202c373572ull,0x632e646c090a3b38ull,0x2038732e74736e6full,0x5b202c3635722509ull,
0x3b5d302b30367225ull,0x33752e766f6d090aull,0x2c31367225092032ull,0x746573090a3b3020ull,
0x3233732e71652e70ull,0x202c343170250920ull,0x7225202c36357225ull,0x702540090a3b3136ull,
0x0920617262203431ull,0x3230315f305f4c24ull,0x2f2f200a3b323034ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x383120656e696c20ull,0x2064616568202c32ull,
0x2064656c6562616cull,0x3130315f305f4c24ull,0x646461090a343336ull,0x722509203233752eull,
0x38357225202c3236ull,0x73090a3b3133202cull,0x732e746c2e707465ull,0x3531702509203233ull,
0x202c30367225202cull,0x40090a3b32367225ull,0x6172622035317025ull,0x315f305f4c240920ull,
0x240a3b3433363130ull,0x343230315f305f4cull,0x6f6c2e090a3a3230ull,0x3338310938310963ull,
0x2e766f6d090a3009ull,0x6872250920363173ull,0x61090a3b30202c35ull,0x09203233752e6464ull,
0x7225202c33367225ull,0x3b317225202c3735ull,0x33752e747663090aull,0x2509203631752e32ull,
0x687225202c343672ull,0x672e7473090a3b35ull,0x38732e6c61626f6cull,0x2b333672255b0920ull,
0x202c5d3635353236ull,0x4c240a3b34367225ull,0x353831315f305f74ull,0x6f6c2e090a3a3033ull,
0x3936330938310963ull,0x672e646c090a3009ull,0x33732e6c61626f6cull,0x2c35367225092032ull,
0x34382b3172255b20ull,0x672e646c090a3b5dull,0x33752e6c61626f6cull,0x2c36367225092032ull,
0x36392b3172255b20ull,0x2e6c756d090a3b5dull,0x09203233752e6f6cull,0x7225202c37367225ull,
0x34343136202c3636ull,0x752e646461090a3bull,0x3836722509203233ull,0x25202c317225202cull,
0x7473090a3b373672ull,0x2e6c61626f6c672eull,0x72255b0920323373ull,0x2c5d3635352b3836ull,
0x090a3b3536722520ull,0x09383109636f6c2eull,0x6d090a3009303733ull,0x09203233732e766full,
0x3b33202c39367225ull,0x6f6c672e646c090aull,0x203233752e6c6162ull,0x5b202c3037722509ull,
0x3b5d36392b317225ull,0x6f6c2e6c756d090aull,0x722509203233752eull,0x30377225202c3137ull,
0x0a3b34343136202cull,0x3233752e64646109ull,0x202c323772250920ull,0x377225202c317225ull,
0x672e7473090a3b31ull,0x33732e6c61626f6cull,0x323772255b092032ull,0x25202c5d3036352bull,
0x646c090a3b393672ull,0x2e6c61626f6c672eull,0x3272250920323375ull,0x312b3172255b202cull,
0x6573090a3b5d3430ull,0x33752e656e2e7074ull,0x202c317025092032ull,0x337225202c327225ull,
0x5f305f744c240a3bull,0x0a3a383130383131ull,0x31315f305f744c24ull,0x4c240a3a36303537ull,
0x343533345f305f74ull,0x09636f6c2e090a3aull,0x3009383032093032ull,0x622031702540090aull,
0x305f4c2409206172ull,0x3b3037313330315full,0x6f6c672e646c090aull,0x203233752e6c6162ull,
0x5b202c3337722509ull,0x5d3830312b317225ull,0x2e70746573090a3bull,0x09203233752e7165ull,
0x7225202c36317025ull,0x3b347225202c3337ull,0x203631702540090aull,0x5f4c240920617262ull,
0x3431393230315f30ull,0x315f305f4c240a3bull,0x090a3a3037313330ull,0x203233732e766f6dull,
0x31202c3437722509ull,0x752e617262090a3bull,0x305f4c240920696eull,0x3b3835363230315full,
0x30315f305f4c240aull,0x6d090a3a34313932ull,0x09203233732e766full,0x3b30202c34377225ull,
0x30315f305f4c240aull,0x6d090a3a38353632ull,0x09203233752e766full,0x3b30202c35377225ull,
0x6e2e70746573090aull,0x2509203233732e65ull,0x377225202c373170ull,0x3b35377225202c34ull,
0x203731702540090aull,0x744c240920617262ull,0x35353931315f305full,0x672e646c090a3b34ull,
0x33732e6c61626f6cull,0x2c36377225092032ull,0x32332b3172255b20ull,0x2e766f6d090a3b5dull,
0x3772250920323375ull,0x73090a3b31202c37ull,0x732e656e2e707465ull,0x3831702509203233ull,
0x202c36377225202cull,0x40090a3b37377225ull,0x6172622038317025ull,0x5f305f744c240920ull,
0x0a3b343535393131ull,0x626f6c672e646c09ull,0x09203233732e6c61ull,0x255b202c30327225ull,
0x0a3b5d36392b3172ull,0x3233752e766f6d09ull,0x202c383772250920ull,0x70746573090a3b39ull,
0x203233732e74672eull,0x25202c3931702509ull,0x377225202c303272ull,0x31702540090a3b38ull,
0x2409206172622039ull,0x3931315f305f744cull,0x6c2e090a3b343535ull,0x303109373109636full,
0x6c756d090a300933ull,0x203233752e6f6c2eull,0x25202c3937722509ull,0x343136202c303272ull,
0x2e646461090a3b34ull,0x3872250920323375ull,0x202c317225202c30ull,0x61090a3b39377225ull,
0x09203233752e6464ull,0x7225202c31387225ull,0x3b343635202c3038ull,0x33732e766f6d090aull,
0x2c32387225092032ull,0x6f7461090a3b3120ull,0x6c61626f6c672e6dull,0x3233732e6464612eull,
0x202c317672250920ull,0x202c5d313872255bull,0x61090a3b32387225ull,0x09203233752e6464ull,
0x7225202c30317225ull,0x3633353536202c31ull,0x6c672e646c090a3bull,0x2038732e6c61626full,
0x5b202c3338722509ull,0x34332d2b30317225ull,0x6f6d090a3b5d3139ull,0x2509203233752e76ull,
0x0a3b30202c343872ull,0x656e2e7074657309ull,0x702509203233732eull,0x33387225202c3032ull,
0x0a3b34387225202cull,0x6220303270254009ull,0x5f744c2409206172ull,0x3636303032315f30ull,
0x09636f6c2e090a3bull,0x3009363633093831ull,0x31732e766f6d090aull,0x2c36687225092036ull,
0x2e7473090a3b3120ull,0x732e6c61626f6c67ull,0x303172255b092038ull,0x2c5d313934332d2bull,
0x090a3b3668722520ull,0x09383109636f6c2eull,0x6d090a3009313831ull,0x09203233732e766full,
0x3031202c35387225ull,0x2e766f6d090a3b33ull,0x3572250920323373ull,0x6d090a3b30202c37ull,
0x09203233752e766full,0x5f5f202c36387225ull,0x746e6174736e6f63ull,0x5f4c240a3b383834ull,
0x3632343330315f30ull,0x6f6c3c2f2f200a3aull,0x706f6f4c203e706full,0x696c2079646f6220ull,
0x090a32383120656eull,0x09383109636f6c2eull,0x61090a3009323831ull,0x09203233752e6464ull,
0x7225202c37387225ull,0x3b317225202c3735ull,0x6f6c672e7473090aull,0x092038732e6c6162ull,
0x32362b373872255bull,0x7225202c5d383835ull,0x6f6c2e090a3b3538ull,0x3138310938310963ull,
0x2e646461090a3009ull,0x3572250920323373ull,0x2c37357225202c37ull,0x646461090a3b3120ull,
0x722509203233752eull,0x37357225202c3838ull,0x0a3b36387225202cull,0x736e6f632e646c09ull,
0x7225092038732e74ull,0x3872255b202c3538ull,0x6d090a3b5d302b38ull,0x09203233752e766full,
0x3b30202c39387225ull,0x652e70746573090aull,0x2509203233732e71ull,0x387225202c313270ull,
0x3b39387225202c35ull,0x203132702540090aull,0x5f4c240920617262ull,0x3439313430315f30ull,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c32383120656eull,0x62616c2064616568ull,0x5f4c242064656c65ull,0x3632343330315f30ull,
0x33752e646461090aull,0x2c30397225092032ull,0x33202c3638722520ull,0x70746573090a3b31ull,
0x203233732e746c2eull,0x25202c3232702509ull,0x397225202c383872ull,0x32702540090a3b30ull,
0x2409206172622032ull,0x343330315f305f4cull,0x305f4c240a3b3632ull,0x3a3439313430315full,
0x3109636f6c2e090aull,0x0a30093338310938ull,0x3631732e766f6d09ull,0x202c376872250920ull,
0x2e646461090a3b30ull,0x3972250920323375ull,0x2c37357225202c31ull,0x63090a3b31722520ull,
0x752e3233752e7476ull,0x3239722509203631ull,0x0a3b37687225202cull,0x626f6c672e747309ull,
0x5b092038732e6c61ull,0x3532362b31397225ull,0x397225202c5d3838ull,0x305f744c240a3b32ull,
0x3a3636303032315full,0x3109636f6c2e090aull,0x0a30093936330938ull,0x626f6c672e646c09ull,
0x09203233732e6c61ull,0x255b202c33397225ull,0x0a3b5d34382b3172ull,0x626f6c672e646c09ull,
0x09203233752e6c61ull,0x255b202c34397225ull,0x0a3b5d36392b3172ull,0x2e6f6c2e6c756d09ull,
0x3972250920323375ull,0x2c34397225202c35ull,0x090a3b3434313620ull,0x203233752e646461ull,
0x25202c3639722509ull,0x35397225202c3172ull,0x6c672e7473090a3bull,0x3233732e6c61626full,
0x2b363972255b0920ull,0x7225202c5d383635ull,0x6f6c2e090a3b3339ull,0x3037330938310963ull,
0x2e766f6d090a3009ull,0x3972250920323373ull,0x6c090a3b34202c37ull,0x6c61626f6c672e64ull,
0x722509203233752eull,0x3172255b202c3839ull,0x6d090a3b5d36392bull,0x33752e6f6c2e6c75ull,
0x2c39397225092032ull,0x36202c3839722520ull,0x6461090a3b343431ull,0x2509203233752e64ull,
0x7225202c30303172ull,0x3b39397225202c31ull,0x6f6c672e7473090aull,0x203233732e6c6162ull,
0x2b30303172255b09ull,0x7225202c5d323735ull,0x2e646c090a3b3739ull,0x752e6c61626f6c67ull,
0x2c32722509203233ull,0x30312b3172255b20ull,0x746573090a3b5d34ull,0x3233752e656e2e70ull,
0x25202c3170250920ull,0x3b337225202c3272ull,0x315f305f744c240aull,0x240a3a3435353931ull,
0x3931315f305f744cull,0x744c240a3a323430ull,0x3a323438335f305full,0x3209636f6c2e090aull,
0x0a30093131320930ull,0x7262203170254009ull,0x5f305f4c24092061ull,0x0a3b323639343031ull,
0x626f6c672e646c09ull,0x09203233752e6c61ull,0x5b202c3130317225ull,0x5d3830312b317225ull,
0x2e70746573090a3bull,0x09203233752e7165ull,0x7225202c33327025ull,0x347225202c313031ull,
0x3332702540090a3bull,0x4c24092061726220ull,0x30373430315f305full,0x5f305f4c240a3b36ull,
0x0a3a323639343031ull,0x3233732e766f6d09ull,0x2c32303172250920ull,0x617262090a3b3120ull,
0x4c240920696e752eull,0x35343430315f305full,0x5f305f4c240a3b30ull,0x0a3a363037343031ull,
0x3233732e766f6d09ull,0x2c32303172250920ull,0x305f4c240a3b3020ull,0x3a3035343430315full,
0x33752e766f6d090aull,0x3330317225092032ull,0x6573090a3b30202cull,0x33732e656e2e7074ull,
0x2c34327025092032ull,0x202c323031722520ull,0x090a3b3330317225ull,0x7262203432702540ull,
0x305f744c24092061ull,0x3b3039303132315full,0x6f6c672e646c090aull,0x203233732e6c6162ull,
0x202c343031722509ull,0x5d32332b3172255bull,0x752e766f6d090a3bull,0x3031722509203233ull,
0x73090a3b31202c35ull,0x732e656e2e707465ull,0x3532702509203233ull,0x2c3430317225202cull,
0x0a3b353031722520ull,0x6220353270254009ull,0x5f744c2409206172ull,0x3039303132315f30ull,
0x6c672e646c090a3bull,0x3233732e6c61626full,0x202c303272250920ull,0x5d36392b3172255bull,
0x752e766f6d090a3bull,0x3031722509203233ull,0x73090a3b39202c36ull,0x732e74672e707465ull,
0x3632702509203233ull,0x202c30327225202cull,0x090a3b3630317225ull,0x7262203632702540ull,
0x305f744c24092061ull,0x3b3039303132315full,0x3109636f6c2e090aull,0x0a30093330310937ull,
0x2e6f6c2e6c756d09ull,0x3172250920323375ull,0x30327225202c3730ull,0x0a3b34343136202cull,
0x3233752e64646109ull,0x2c38303172250920ull,0x7225202c31722520ull,0x6461090a3b373031ull,
0x2509203233752e64ull,0x7225202c39303172ull,0x363735202c383031ull,0x732e766f6d090a3bull,
0x3131722509203233ull,0x61090a3b31202c30ull,0x626f6c672e6d6f74ull,0x732e6464612e6c61ull,
0x3176722509203233ull,0x39303172255b202cull,0x3031317225202c5dull,0x752e646461090a3bull,
0x3031722509203233ull,0x36202c317225202cull,0x6c090a3b36333535ull,0x6c61626f6c672e64ull,
0x317225092038732eull,0x3172255b202c3131ull,0x5d303934332d2b30ull,0x752e766f6d090a3bull,
0x3131722509203233ull,0x73090a3b30202c32ull,0x732e656e2e707465ull,0x3732702509203233ull,
0x2c3131317225202cull,0x0a3b323131722520ull,0x6220373270254009ull,0x5f744c2409206172ull,
0x3230363132315f30ull,0x09636f6c2e090a3bull,0x3009363633093831ull,0x31732e766f6d090aull,
0x2c38687225092036ull,0x2e7473090a3b3120ull,0x732e6c61626f6c67ull,0x303172255b092038ull,
0x2c5d303934332d2bull,0x090a3b3868722520ull,0x09383109636f6c2eull,0x6d090a3009313831ull,
0x09203233732e766full,0x31202c3331317225ull,0x766f6d090a3b3330ull,0x722509203233732eull,
0x090a3b30202c3735ull,0x203233752e766f6dull,0x202c343131722509ull,0x6174736e6f635f5full,
0x240a3b393834746eull,0x323530315f305f4cull,0x3c2f2f200a3a3831ull,0x6f4c203e706f6f6cull,
0x2079646f6220706full,0x32383120656e696cull,0x3109636f6c2e090aull,0x0a30093238310938ull,
0x3233752e64646109ull,0x2c35313172250920ull,0x25202c3735722520ull,0x2e7473090a3b3172ull,
0x732e6c61626f6c67ull,0x313172255b092038ull,0x5d30323632362b35ull,0x3b3331317225202cull,
0x3109636f6c2e090aull,0x0a30093138310938ull,0x3233732e64646109ull,0x202c373572250920ull,
0x3b31202c37357225ull,0x33752e646461090aull,0x3631317225092032ull,0x202c37357225202cull,
0x090a3b3431317225ull,0x74736e6f632e646cull,0x317225092038732eull,0x3172255b202c3331ull,
0x090a3b5d302b3631ull,0x203233752e766f6dull,0x202c373131722509ull,0x70746573090a3b30ull,
0x203233732e71652eull,0x25202c3832702509ull,0x7225202c33313172ull,0x2540090a3b373131ull,
0x2061726220383270ull,0x30315f305f4c2409ull,0x2f200a3b36383935ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,0x64616568202c3238ull,
0x64656c6562616c20ull,0x30315f305f4c2420ull,0x6461090a38313235ull,0x2509203233752e64ull,
0x7225202c38313172ull,0x3b3133202c343131ull,0x6c2e70746573090aull,0x2509203233732e74ull,
0x317225202c393270ull,0x31317225202c3631ull,0x32702540090a3b38ull,0x2409206172622039ull,
0x323530315f305f4cull,0x305f4c240a3b3831ull,0x3a3638393530315full,0x3109636f6c2e090aull,
0x0a30093338310938ull,0x3631732e766f6d09ull,0x202c396872250920ull,0x2e646461090a3b30ull,
0x3172250920323375ull,0x37357225202c3931ull,0x090a3b317225202cull,0x2e3233752e747663ull,
0x3172250920363175ull,0x39687225202c3032ull,0x6c672e7473090a3bull,0x2038732e6c61626full,
0x2b39313172255b09ull,0x202c5d3032363236ull,0x240a3b3032317225ull,0x3132315f305f744cull,
0x6c2e090a3a323036ull,0x363309383109636full,0x2e646c090a300939ull,0x732e6c61626f6c67ull,
0x3231722509203233ull,0x2b3172255b202c31ull,0x646c090a3b5d3438ull,0x2e6c61626f6c672eull,
0x3172250920323375ull,0x3172255b202c3232ull,0x6d090a3b5d36392bull,0x33752e6f6c2e6c75ull,
0x3332317225092032ull,0x2c3232317225202cull,0x090a3b3434313620ull,0x203233752e646461ull,
0x202c343231722509ull,0x317225202c317225ull,0x2e7473090a3b3332ull,0x732e6c61626f6c67ull,
0x3172255b09203233ull,0x2c5d3038352b3432ull,0x0a3b313231722520ull,0x383109636f6c2e09ull,
0x090a300930373309ull,0x203233732e766f6dull,0x202c353231722509ull,0x672e646c090a3b33ull,
0x33752e6c61626f6cull,0x3632317225092032ull,0x392b3172255b202cull,0x6c756d090a3b5d36ull,
0x203233752e6f6c2eull,0x202c373231722509ull,0x36202c3632317225ull,0x6461090a3b343431ull,
0x2509203233752e64ull,0x7225202c38323172ull,0x3732317225202c31ull,0x6c672e7473090a3bull,
0x3233732e6c61626full,0x38323172255b0920ull,0x25202c5d3438352bull,0x6c090a3b35323172ull,
0x6c61626f6c672e64ull,0x722509203233752eull,0x2b3172255b202c32ull,0x73090a3b5d343031ull,
0x752e656e2e707465ull,0x2c31702509203233ull,0x7225202c32722520ull,0x305f744c240a3b33ull,
0x3a3039303132315full,0x315f305f744c240aull,0x240a3a3837353032ull,0x3333335f305f744cull,
0x636f6c2e090a3a30ull,0x0934313209303209ull,0x2031702540090a30ull,0x5f4c240920617262ull,
0x3435373630315f30ull,0x6c672e646c090a3bull,0x3233752e6c61626full,0x2c39323172250920ull,
0x30312b3172255b20ull,0x746573090a3b5d38ull,0x3233752e71652e70ull,0x202c303370250920ull,
0x25202c3932317225ull,0x702540090a3b3472ull,0x0920617262203033ull,0x3630315f305f4c24ull,
0x5f4c240a3b383934ull,0x3435373630315f30ull,0x732e766f6d090a3aull,0x3331722509203233ull,
0x62090a3b31202c30ull,0x0920696e752e6172ull,0x3630315f305f4c24ull,0x5f4c240a3b323432ull,
0x3839343630315f30ull,0x732e766f6d090a3aull,0x3331722509203233ull,0x4c240a3b30202c30ull,
0x34323630315f305full,0x2e766f6d090a3a32ull,0x3172250920323375ull,0x090a3b30202c3133ull,
0x2e656e2e70746573ull,0x3370250920323373ull,0x3033317225202c31ull,0x3b3133317225202cull,
0x203133702540090aull,0x744c240920617262ull,0x32363232315f305full,0x672e646c090a3b36ull,
0x33732e6c61626f6cull,0x3233317225092032ull,0x332b3172255b202cull,0x766f6d090a3b5d32ull,
0x722509203233752eull,0x0a3b31202c333331ull,0x656e2e7074657309ull,0x702509203233732eull,
0x33317225202c3233ull,0x3333317225202c32ull,0x3233702540090a3bull,0x4c24092061726220ull,
0x363232315f305f74ull,0x2e646c090a3b3632ull,0x732e6c61626f6c67ull,0x3032722509203233ull,
0x392b3172255b202cull,0x766f6d090a3b5d36ull,0x722509203233752eull,0x0a3b39202c343331ull,
0x74672e7074657309ull,0x702509203233732eull,0x30327225202c3333ull,0x3b3433317225202cull,
0x203333702540090aull,0x744c240920617262ull,0x32363232315f305full,0x636f6c2e090a3b36ull,
0x0933303109373109ull,0x6c2e6c756d090a30ull,0x2509203233752e6full,0x7225202c35333172ull,
0x34343136202c3032ull,0x752e646461090a3bull,0x3331722509203233ull,0x202c317225202c36ull,
0x090a3b3533317225ull,0x203233752e646461ull,0x202c373331722509ull,0x35202c3633317225ull,
0x766f6d090a3b3838ull,0x722509203233732eull,0x0a3b31202c383331ull,0x6c672e6d6f746109ull,
0x6464612e6c61626full,0x722509203233732eull,0x3172255b202c3176ull,0x317225202c5d3733ull,
0x646461090a3b3833ull,0x722509203233752eull,0x2c317225202c3031ull,0x0a3b363335353620ull,
0x626f6c672e646c09ull,0x25092038732e6c61ull,0x255b202c39333172ull,0x3834332d2b303172ull,
0x766f6d090a3b5d39ull,0x722509203233752eull,0x0a3b30202c303431ull,0x656e2e7074657309ull,
0x702509203233732eull,0x33317225202c3433ull,0x3034317225202c39ull,0x3433702540090a3bull,
0x4c24092061726220ull,0x313332315f305f74ull,0x6f6c2e090a3b3833ull,0x3636330938310963ull,
0x2e766f6d090a3009ull,0x6872250920363173ull,0x090a3b31202c3031ull,0x61626f6c672e7473ull,
0x255b092038732e6cull,0x3834332d2b303172ull,0x31687225202c5d39ull,0x636f6c2e090a3b30ull,
0x0931383109383109ull,0x732e766f6d090a30ull,0x3431722509203233ull,0x0a3b303131202c31ull,
0x3233732e766f6d09ull,0x202c373572250920ull,0x2e766f6d090a3b30ull,0x3172250920323375ull,
0x6f635f5f202c3234ull,0x3934746e6174736eull,0x5f305f4c240a3b30ull,0x0a3a303130373031ull,
0x706f6f6c3c2f2f20ull,0x6220706f6f4c203eull,0x656e696c2079646full,0x6c2e090a32383120ull,
0x383109383109636full,0x646461090a300932ull,0x722509203233752eull,0x357225202c333431ull,
0x0a3b317225202c37ull,0x626f6c672e747309ull,0x5b092038732e6c61ull,0x32362b3334317225ull,
0x7225202c5d323536ull,0x6c2e090a3b313431ull,0x383109383109636full,0x646461090a300931ull,
0x722509203233732eull,0x37357225202c3735ull,0x6461090a3b31202cull,0x2509203233752e64ull,
0x7225202c34343172ull,0x34317225202c3735ull,0x632e646c090a3b32ull,0x2038732e74736e6full,
0x202c313431722509ull,0x302b34343172255bull,0x2e766f6d090a3b5dull,0x3172250920323375ull,
0x090a3b30202c3534ull,0x2e71652e70746573ull,0x3370250920323373ull,0x3134317225202c35ull,
0x3b3534317225202cull,0x203533702540090aull,0x5f4c240920617262ull,0x3837373730315f30ull,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c32383120656eull,0x62616c2064616568ull,0x5f4c242064656c65ull,0x3031303730315f30ull,
0x33752e646461090aull,0x3634317225092032ull,0x2c3234317225202cull,0x6573090a3b313320ull,
0x33732e746c2e7074ull,0x2c36337025092032ull,0x202c343431722520ull,0x090a3b3634317225ull,
0x7262203633702540ull,0x5f305f4c24092061ull,0x0a3b303130373031ull,0x3730315f305f4c24ull,
0x6c2e090a3a383737ull,0x383109383109636full,0x766f6d090a300933ull,0x722509203631732eull,
0x0a3b30202c313168ull,0x3233752e64646109ull,0x2c37343172250920ull,0x25202c3735722520ull,
0x747663090a3b3172ull,0x3631752e3233752eull,0x2c38343172250920ull,0x0a3b313168722520ull,
0x626f6c672e747309ull,0x5b092038732e6c61ull,0x32362b3734317225ull,0x7225202c5d323536ull,
0x744c240a3b383431ull,0x33313332315f305full,0x636f6c2e090a3a38ull,0x0939363309383109ull,
0x6c672e646c090a30ull,0x3233732e6c61626full,0x2c39343172250920ull,0x34382b3172255b20ull,
0x672e646c090a3b5dull,0x33752e6c61626f6cull,0x3035317225092032ull,0x392b3172255b202cull,
0x6c756d090a3b5d36ull,0x203233752e6f6c2eull,0x202c313531722509ull,0x36202c3035317225ull,
0x6461090a3b343431ull,0x2509203233752e64ull,0x7225202c32353172ull,0x3135317225202c31ull,
0x6c672e7473090a3bull,0x3233732e6c61626full,0x32353172255b0920ull,0x25202c5d3239352bull,
0x2e090a3b39343172ull,0x3309383109636f6cull,0x6f6d090a30093037ull,0x2509203233732e76ull,
0x3b31202c33353172ull,0x6f6c672e646c090aull,0x203233752e6c6162ull,0x202c343531722509ull,
0x5d36392b3172255bull,0x6c2e6c756d090a3bull,0x2509203233752e6full,0x7225202c35353172ull,
0x343136202c343531ull,0x2e646461090a3b34ull,0x3172250920323375ull,0x2c317225202c3635ull,
0x0a3b353531722520ull,0x626f6c672e747309ull,0x09203233732e6c61ull,0x352b36353172255bull,
0x317225202c5d3639ull,0x2e646c090a3b3335ull,0x752e6c61626f6c67ull,0x2c32722509203233ull,
0x30312b3172255b20ull,0x746573090a3b5d34ull,0x3233752e656e2e70ull,0x25202c3170250920ull,
0x3b337225202c3272ull,0x315f305f744c240aull,0x240a3a3632363232ull,0x3232315f305f744cull,
0x744c240a3a343131ull,0x3a383138325f305full,0x3209636f6c2e090aull,0x0a30093731320930ull,
0x7262203170254009ull,0x5f305f4c24092061ull,0x0a3b363435383031ull,0x626f6c672e646c09ull,
0x09203233752e6c61ull,0x5b202c3735317225ull,0x5d3830312b317225ull,0x2e70746573090a3bull,
0x09203233752e7165ull,0x7225202c37337025ull,0x347225202c373531ull,0x3733702540090a3bull,
0x4c24092061726220ull,0x39323830315f305full,0x5f305f4c240a3b30ull,0x0a3a363435383031ull,
0x3233732e766f6d09ull,0x2c38353172250920ull,0x617262090a3b3120ull,0x4c240920696e752eull,
0x33303830315f305full,0x5f305f4c240a3b34ull,0x0a3a303932383031ull,0x3233732e766f6d09ull,
0x2c38353172250920ull,0x305f4c240a3b3020ull,0x3a3433303830315full,0x33752e766f6d090aull,
0x3935317225092032ull,0x6573090a3b30202cull,0x33732e656e2e7074ull,0x2c38337025092032ull,
0x202c383531722520ull,0x090a3b3935317225ull,0x7262203833702540ull,0x305f744c24092061ull,
0x3b3236313432315full,0x6f6c672e646c090aull,0x203233732e6c6162ull,0x202c303631722509ull,
0x5d32332b3172255bull,0x752e766f6d090a3bull,0x3631722509203233ull,0x73090a3b31202c31ull,
0x732e656e2e707465ull,0x3933702509203233ull,0x2c3036317225202cull,0x0a3b313631722520ull,
0x6220393370254009ull,0x5f744c2409206172ull,0x3236313432315f30ull,0x6c672e646c090a3bull,
0x3233732e6c61626full,0x202c303272250920ull,0x5d36392b3172255bull,0x752e766f6d090a3bull,
0x3631722509203233ull,0x73090a3b39202c32ull,0x732e74672e707465ull,0x3034702509203233ull,
0x202c30327225202cull,0x090a3b3236317225ull,0x7262203034702540ull,0x305f744c24092061ull,
0x3b3236313432315full,0x3109636f6c2e090aull,0x0a30093330310937ull,0x2e6f6c2e6c756d09ull,
0x3172250920323375ull,0x30327225202c3336ull,0x0a3b34343136202cull,0x3233752e64646109ull,
0x2c34363172250920ull,0x7225202c31722520ull,0x6461090a3b333631ull,0x2509203233752e64ull,
0x7225202c35363172ull,0x303036202c343631ull,0x732e766f6d090a3bull,0x3631722509203233ull,
0x61090a3b31202c36ull,0x626f6c672e6d6f74ull,0x732e6464612e6c61ull,0x3176722509203233ull,
0x35363172255b202cull,0x3636317225202c5dull,0x752e646461090a3bull,0x3031722509203233ull,
0x36202c317225202cull,0x6c090a3b36333535ull,0x6c61626f6c672e64ull,0x317225092038732eull,
0x3172255b202c3736ull,0x5d383834332d2b30ull,0x752e766f6d090a3bull,0x3631722509203233ull,
0x73090a3b30202c38ull,0x732e656e2e707465ull,0x3134702509203233ull,0x2c3736317225202cull,
0x0a3b383631722520ull,0x6220313470254009ull,0x5f744c2409206172ull,0x3437363432315f30ull,
0x09636f6c2e090a3bull,0x3009363633093831ull,0x31732e766f6d090aull,0x3231687225092036ull,
0x7473090a3b31202cull,0x2e6c61626f6c672eull,0x3172255b09203873ull,0x5d383834332d2b30ull,
0x3b3231687225202cull,0x3109636f6c2e090aull,0x0a30093138310938ull,0x3233732e766f6d09ull,
0x2c39363172250920ull,0x6d090a3b35313120ull,0x09203233732e766full,0x3b30202c37357225ull,
0x33752e766f6d090aull,0x3037317225092032ull,0x736e6f635f5f202cull,0x3b313934746e6174ull,
0x30315f305f4c240aull,0x2f200a3a32303838ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,
0x3120656e696c2079ull,0x636f6c2e090a3238ull,0x0932383109383109ull,0x752e646461090a30ull,
0x3731722509203233ull,0x2c37357225202c31ull,0x73090a3b31722520ull,0x6c61626f6c672e74ull,
0x72255b092038732eull,0x383632362b313731ull,0x36317225202c5d34ull,0x636f6c2e090a3b39ull,
0x0931383109383109ull,0x732e646461090a30ull,0x3735722509203233ull,0x202c37357225202cull,
0x2e646461090a3b31ull,0x3172250920323375ull,0x37357225202c3237ull,0x3b3037317225202cull,
0x6e6f632e646c090aull,0x25092038732e7473ull,0x255b202c39363172ull,0x3b5d302b32373172ull,
0x33752e766f6d090aull,0x3337317225092032ull,0x6573090a3b30202cull,0x33732e71652e7074ull,
0x2c32347025092032ull,0x202c393631722520ull,0x090a3b3337317225ull,0x7262203234702540ull,
0x5f305f4c24092061ull,0x0a3b303735393031ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,
0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c32383120ull,0x6c6562616c206461ull,
0x5f305f4c24206465ull,0x090a323038383031ull,0x203233752e646461ull,0x202c343731722509ull,
0x33202c3037317225ull,0x70746573090a3b31ull,0x203233732e746c2eull,0x25202c3334702509ull,
0x7225202c32373172ull,0x2540090a3b343731ull,0x2061726220333470ull,0x30315f305f4c2409ull,
0x4c240a3b32303838ull,0x37353930315f305full,0x636f6c2e090a3a30ull,0x0933383109383109ull,
0x732e766f6d090a30ull,0x3168722509203631ull,0x61090a3b30202c33ull,0x09203233752e6464ull,
0x25202c3537317225ull,0x317225202c373572ull,0x752e747663090a3bull,0x09203631752e3233ull,
0x25202c3637317225ull,0x73090a3b33316872ull,0x6c61626f6c672e74ull,0x72255b092038732eull,
0x383632362b353731ull,0x37317225202c5d34ull,0x305f744c240a3b36ull,0x3a3437363432315full,
0x3109636f6c2e090aull,0x0a30093936330938ull,0x626f6c672e646c09ull,0x09203233732e6c61ull,
0x5b202c3737317225ull,0x3b5d34382b317225ull,0x6f6c672e646c090aull,0x203233752e6c6162ull,
0x202c383731722509ull,0x5d36392b3172255bull,0x6c2e6c756d090a3bull,0x2509203233752e6full,
0x7225202c39373172ull,0x343136202c383731ull,0x2e646461090a3b34ull,0x3172250920323375ull,
0x2c317225202c3038ull,0x0a3b393731722520ull,0x626f6c672e747309ull,0x09203233732e6c61ull,
0x362b30383172255bull,0x317225202c5d3430ull,0x6f6c2e090a3b3737ull,0x3037330938310963ull,
0x2e766f6d090a3009ull,0x3172250920323373ull,0x090a3b31202c3138ull,0x61626f6c672e646cull,
0x2509203233752e6cull,0x255b202c32383172ull,0x0a3b5d36392b3172ull,0x2e6f6c2e6c756d09ull,
0x3172250920323375ull,0x38317225202c3338ull,0x3b34343136202c32ull,0x33752e646461090aull,
0x3438317225092032ull,0x25202c317225202cull,0x73090a3b33383172ull,0x6c61626f6c672e74ull,
0x255b09203233732eull,0x3830362b34383172ull,0x3138317225202c5dull,0x6c672e646c090a3bull,
0x3233752e6c61626full,0x5b202c3272250920ull,0x5d3430312b317225ull,0x2e70746573090a3bull,
0x09203233752e656eull,0x327225202c317025ull,0x240a3b337225202cull,0x3432315f305f744cull,
0x744c240a3a323631ull,0x35363332315f305full,0x305f744c240a3a30ull,0x090a3a363033325full,
0x09303209636f6c2eull,0x40090a3009303232ull,0x2061726220317025ull,0x31315f305f4c2409ull,
0x6c090a3b38333330ull,0x6c61626f6c672e64ull,0x722509203233752eull,0x72255b202c353831ull,
0x0a3b5d3830312b31ull,0x71652e7074657309ull,0x702509203233752eull,0x38317225202c3434ull,
0x0a3b347225202c35ull,0x6220343470254009ull,0x305f4c2409206172ull,0x3b3238303031315full,
0x31315f305f4c240aull,0x6d090a3a38333330ull,0x09203233732e766full,0x31202c3638317225ull,
0x752e617262090a3bull,0x305f4c240920696eull,0x3b3632383930315full,0x31315f305f4c240aull,
0x6d090a3a32383030ull,0x09203233732e766full,0x30202c3638317225ull,0x315f305f4c240a3bull,
0x090a3a3632383930ull,0x203233752e766f6dull,0x202c373831722509ull,0x70746573090a3b30ull,
0x203233732e656e2eull,0x25202c3534702509ull,0x7225202c36383172ull,0x2540090a3b373831ull,
0x2061726220353470ull,0x315f305f744c2409ull,0x090a3b3839363532ull,0x61626f6c672e646cull,
0x2509203233732e6cull,0x255b202c38383172ull,0x0a3b5d32332b3172ull,0x3233752e766f6d09ull,
0x2c39383172250920ull,0x746573090a3b3120ull,0x3233732e656e2e70ull,0x202c363470250920ull,
0x25202c3838317225ull,0x40090a3b39383172ull,0x6172622036347025ull,0x5f305f744c240920ull,
0x0a3b383936353231ull,0x626f6c672e646c09ull,0x09203233732e6c61ull,0x255b202c30327225ull,
0x0a3b5d36392b3172ull,0x3233752e766f6d09ull,0x2c30393172250920ull,0x746573090a3b3920ull,
0x3233732e74672e70ull,0x202c373470250920ull,0x7225202c30327225ull,0x2540090a3b303931ull,
0x2061726220373470ull,0x315f305f744c2409ull,0x090a3b3839363532ull,0x09373109636f6c2eull,
0x6d090a3009333031ull,0x33752e6f6c2e6c75ull,0x3139317225092032ull,0x202c30327225202cull,
0x61090a3b34343136ull,0x09203233752e6464ull,0x25202c3239317225ull,0x39317225202c3172ull,
0x2e646461090a3b31ull,0x3172250920323375ull,0x39317225202c3339ull,0x0a3b323136202c32ull,
0x3233732e766f6d09ull,0x2c34393172250920ull,0x6f7461090a3b3120ull,0x6c61626f6c672e6dull,
0x3233732e6464612eull,0x202c317672250920ull,0x2c5d33393172255bull,0x0a3b343931722520ull,
0x3233752e64646109ull,0x202c303172250920ull,0x353536202c317225ull,0x2e646c090a3b3633ull,
0x732e6c61626f6c67ull,0x3539317225092038ull,0x2b303172255b202cull,0x0a3b5d373834332dull,
0x3233752e766f6d09ull,0x2c36393172250920ull,0x746573090a3b3020ull,0x3233732e656e2e70ull,
0x202c383470250920ull,0x25202c3539317225ull,0x40090a3b36393172ull,0x6172622038347025ull,
0x5f305f744c240920ull,0x0a3b303132363231ull,0x383109636f6c2e09ull,0x090a300936363309ull,
0x203631732e766f6dull,0x202c343168722509ull,0x672e7473090a3b31ull,0x38732e6c61626f6cull,
0x2b303172255b0920ull,0x202c5d373834332dull,0x090a3b3431687225ull,0x09383109636f6c2eull,
0x6d090a3009313831ull,0x09203233732e766full,0x31202c3739317225ull,0x766f6d090a3b3531ull,
0x722509203233732eull,0x090a3b30202c3735ull,0x203233752e766f6dull,0x202c383931722509ull,
0x6174736e6f635f5full,0x240a3b323934746eull,0x353031315f305f4cull,0x3c2f2f200a3a3439ull,
0x6f4c203e706f6f6cull,0x2079646f6220706full,0x32383120656e696cull,0x3109636f6c2e090aull,
0x0a30093238310938ull,0x3233752e64646109ull,0x2c39393172250920ull,0x25202c3735722520ull,
0x2e7473090a3b3172ull,0x732e6c61626f6c67ull,0x393172255b092038ull,0x5d36313732362b39ull,
0x3b3739317225202cull,0x3109636f6c2e090aull,0x0a30093138310938ull,0x3233732e64646109ull,
0x202c373572250920ull,0x3b31202c37357225ull,0x33752e646461090aull,0x3030327225092032ull,
0x202c37357225202cull,0x090a3b3839317225ull,0x74736e6f632e646cull,0x317225092038732eull,
0x3272255b202c3739ull,0x090a3b5d302b3030ull,0x203233752e766f6dull,0x202c313032722509ull,
0x70746573090a3b30ull,0x203233732e71652eull,0x25202c3934702509ull,0x7225202c37393172ull,
0x2540090a3b313032ull,0x2061726220393470ull,0x31315f305f4c2409ull,0x2f200a3b32363331ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3120656e696c2079ull,
0x64616568202c3238ull,0x64656c6562616c20ull,0x31315f305f4c2420ull,0x6461090a34393530ull,
0x2509203233752e64ull,0x7225202c32303272ull,0x3b3133202c383931ull,0x6c2e70746573090aull,
0x2509203233732e74ull,0x327225202c303570ull,0x30327225202c3030ull,0x35702540090a3b32ull,
0x2409206172622030ull,0x353031315f305f4cull,0x305f4c240a3b3439ull,0x3a3236333131315full,
0x3109636f6c2e090aull,0x0a30093338310938ull,0x3631732e766f6d09ull,0x2c35316872250920ull,
0x646461090a3b3020ull,0x722509203233752eull,0x357225202c333032ull,0x0a3b317225202c37ull,
0x3233752e74766309ull,0x722509203631752eull,0x687225202c343032ull,0x2e7473090a3b3531ull,
0x732e6c61626f6c67ull,0x303272255b092038ull,0x5d36313732362b33ull,0x3b3430327225202cull,
0x315f305f744c240aull,0x090a3a3031323632ull,0x09383109636f6c2eull,0x6c090a3009393633ull,
0x6c61626f6c672e64ull,0x722509203233732eull,0x72255b202c353032ull,0x090a3b5d34382b31ull,
0x61626f6c672e646cull,0x2509203233752e6cull,0x255b202c36303272ull,0x0a3b5d36392b3172ull,
0x2e6f6c2e6c756d09ull,0x3272250920323375ull,0x30327225202c3730ull,0x3b34343136202c36ull,
0x33752e646461090aull,0x3830327225092032ull,0x25202c317225202cull,0x73090a3b37303272ull,
0x6c61626f6c672e74ull,0x255b09203233732eull,0x3631362b38303272ull,0x3530327225202c5dull,
0x09636f6c2e090a3bull,0x3009303733093831ull,0x33732e766f6d090aull,0x3930327225092032ull,
0x646c090a3b31202cull,0x2e6c61626f6c672eull,0x3272250920323375ull,0x3172255b202c3031ull,
0x6d090a3b5d36392bull,0x33752e6f6c2e6c75ull,0x3131327225092032ull,0x2c3031327225202cull,
0x090a3b3434313620ull,0x203233752e646461ull,0x202c323132722509ull,0x327225202c317225ull,
0x2e7473090a3b3131ull,0x732e6c61626f6c67ull,0x3272255b09203233ull,0x2c5d3032362b3231ull,
0x0a3b393032722520ull,0x626f6c672e646c09ull,0x09203233752e6c61ull,0x72255b202c327225ull,
0x0a3b5d3430312b31ull,0x656e2e7074657309ull,0x702509203233752eull,0x202c327225202c31ull,
0x744c240a3b337225ull,0x39363532315f305full,0x305f744c240a3a38ull,0x3a3638313532315full,
0x315f305f744c240aull,0x6c2e090a3a343937ull,0x323209303209636full,0x702540090a300938ull,
0x2409206172622031ull,0x313231315f305f4cull,0x2e646c090a3b3033ull,0x752e6c61626f6c67ull,
0x3132722509203233ull,0x2b3172255b202c33ull,0x73090a3b5d383031ull,0x752e71652e707465ull,
0x3135702509203233ull,0x2c3331327225202cull,0x40090a3b34722520ull,0x6172622031357025ull,
0x315f305f4c240920ull,0x240a3b3437383131ull,0x313231315f305f4cull,0x766f6d090a3a3033ull,
0x722509203233732eull,0x0a3b31202c343132ull,0x696e752e61726209ull,0x315f305f4c240920ull,
0x240a3b3831363131ull,0x383131315f305f4cull,0x766f6d090a3a3437ull,0x722509203233732eull,
0x0a3b30202c343132ull,0x3131315f305f4c24ull,0x6f6d090a3a383136ull,0x2509203233752e76ull,
0x3b30202c35313272ull,0x6e2e70746573090aull,0x2509203233732e65ull,0x327225202c323570ull,
0x31327225202c3431ull,0x35702540090a3b35ull,0x2409206172622032ull,0x3732315f305f744cull,
0x646c090a3b343332ull,0x2e6c61626f6c672eull,0x3272250920323373ull,0x3172255b202c3631ull,
0x6d090a3b5d32332bull,0x09203233752e766full,0x31202c3731327225ull,0x2e70746573090a3bull,
0x09203233732e656eull,0x7225202c33357025ull,0x327225202c363132ull,0x702540090a3b3731ull,
0x0920617262203335ull,0x32315f305f744c24ull,0x6c090a3b34333237ull,0x6c61626f6c672e64ull,
0x722509203233732eull,0x3172255b202c3032ull,0x6d090a3b5d36392bull,0x09203233752e766full,
0x39202c3831327225ull,0x2e70746573090a3bull,0x09203233732e7467ull,0x7225202c34357025ull,
0x31327225202c3032ull,0x35702540090a3b38ull,0x2409206172622034ull,0x3732315f305f744cull,
0x6c2e090a3b343332ull,0x303109373109636full,0x6c756d090a300933ull,0x203233752e6f6c2eull,
0x202c393132722509ull,0x3136202c30327225ull,0x646461090a3b3434ull,0x722509203233752eull,
0x317225202c303232ull,0x3b3931327225202cull,0x33752e646461090aull,0x3132327225092032ull,
0x2c3032327225202cull,0x6d090a3b34323620ull,0x09203233732e766full,0x31202c3232327225ull,
0x2e6d6f7461090a3bull,0x612e6c61626f6c67ull,0x09203233732e6464ull,0x255b202c31767225ull,
0x25202c5d31323272ull,0x61090a3b32323272ull,0x09203233752e6464ull,0x7225202c30317225ull,
0x3633353536202c31ull,0x6c672e646c090a3bull,0x2038732e6c61626full,0x202c333232722509ull,
0x332d2b303172255bull,0x6d090a3b5d363834ull,0x09203233752e766full,0x30202c3432327225ull,
0x2e70746573090a3bull,0x09203233732e656eull,0x7225202c35357025ull,0x327225202c333232ull,
0x702540090a3b3432ull,0x0920617262203535ull,0x32315f305f744c24ull,0x2e090a3b36343737ull,
0x3309383109636f6cull,0x6f6d090a30093636ull,0x2509203631732e76ull,0x3b31202c36316872ull,
0x6f6c672e7473090aull,0x092038732e6c6162ull,0x332d2b303172255bull,0x7225202c5d363834ull,
0x6c2e090a3b363168ull,0x383109383109636full,0x766f6d090a300931ull,0x722509203233732eull,
0x3b3837202c353232ull,0x33732e766f6d090aull,0x2c37357225092032ull,0x766f6d090a3b3020ull,
0x722509203233752eull,0x635f5f202c363232ull,0x34746e6174736e6full,0x305f4c240a3b3339ull,
0x3a3638333231315full,0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,0x6e696c2079646f62ull,
0x2e090a3238312065ull,0x3109383109636f6cull,0x6461090a30093238ull,0x2509203233752e64ull,
0x7225202c37323272ull,0x3b317225202c3735ull,0x6f6c672e7473090aull,0x092038732e6c6162ull,
0x362b37323272255bull,0x25202c5d38343732ull,0x2e090a3b35323272ull,0x3109383109636f6cull,
0x6461090a30093138ull,0x2509203233732e64ull,0x357225202c373572ull,0x61090a3b31202c37ull,
0x09203233752e6464ull,0x25202c3832327225ull,0x327225202c373572ull,0x2e646c090a3b3632ull,
0x38732e74736e6f63ull,0x2c35323272250920ull,0x2b38323272255b20ull,0x766f6d090a3b5d30ull,
0x722509203233752eull,0x0a3b30202c393232ull,0x71652e7074657309ull,0x702509203233732eull,
0x32327225202c3635ull,0x3932327225202c35ull,0x3635702540090a3bull,0x4c24092061726220ull,
0x35313331315f305full,0x6c3c2f2f200a3b34ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c32383120656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x38333231315f305full,0x752e646461090a36ull,0x3332722509203233ull,0x3632327225202c30ull,
0x73090a3b3133202cull,0x732e746c2e707465ull,0x3735702509203233ull,0x2c3832327225202cull,
0x0a3b303332722520ull,0x6220373570254009ull,0x305f4c2409206172ull,0x3b3638333231315full,
0x31315f305f4c240aull,0x2e090a3a34353133ull,0x3109383109636f6cull,0x6f6d090a30093338ull,
0x2509203631732e76ull,0x3b30202c37316872ull,0x33752e646461090aull,0x3133327225092032ull,
0x202c37357225202cull,0x7663090a3b317225ull,0x31752e3233752e74ull,0x3233327225092036ull,
0x3b3731687225202cull,0x6f6c672e7473090aull,0x092038732e6c6162ull,0x362b31333272255bull,
0x25202c5d38343732ull,0x4c240a3b32333272ull,0x373732315f305f74ull,0x6f6c2e090a3a3634ull,
0x3936330938310963ull,0x672e646c090a3009ull,0x33732e6c61626f6cull,0x3333327225092032ull,
0x382b3172255b202cull,0x2e646c090a3b5d34ull,0x752e6c61626f6c67ull,0x3332722509203233ull,
0x2b3172255b202c34ull,0x756d090a3b5d3639ull,0x3233752e6f6c2e6cull,0x2c35333272250920ull,
0x202c343332722520ull,0x61090a3b34343136ull,0x09203233752e6464ull,0x25202c3633327225ull,
0x33327225202c3172ull,0x672e7473090a3b35ull,0x33732e6c61626f6cull,0x333272255b092032ull,
0x202c5d3832362b36ull,0x090a3b3333327225ull,0x09383109636f6c2eull,0x6d090a3009303733ull,
0x09203233732e766full,0x31202c3733327225ull,0x6c672e646c090a3bull,0x3233752e6c61626full,
0x2c38333272250920ull,0x36392b3172255b20ull,0x2e6c756d090a3b5dull,0x09203233752e6f6cull,
0x25202c3933327225ull,0x3136202c38333272ull,0x646461090a3b3434ull,0x722509203233752eull,
0x317225202c303432ull,0x3b3933327225202cull,0x6f6c672e7473090aull,0x203233732e6c6162ull,
0x2b30343272255b09ull,0x7225202c5d323336ull,0x646c090a3b373332ull,0x2e6c61626f6c672eull,
0x3272250920323375ull,0x312b3172255b202cull,0x6573090a3b5d3430ull,0x33752e656e2e7074ull,
0x202c317025092032ull,0x337225202c327225ull,0x5f305f744c240a3bull,0x0a3a343332373231ull,
0x32315f305f744c24ull,0x4c240a3a32323736ull,0x323832315f305f74ull,0x09636f6c2e090a3aull,
0x3009323332093032ull,0x622031702540090aull,0x305f4c2409206172ull,0x3b3232393331315full,
0x6f6c672e646c090aull,0x203233752e6c6162ull,0x202c313432722509ull,0x3830312b3172255bull,
0x70746573090a3b5dull,0x203233752e71652eull,0x25202c3835702509ull,0x7225202c31343272ull,
0x35702540090a3b34ull,0x2409206172622038ull,0x363331315f305f4cull,0x305f4c240a3b3636ull,
0x3a3232393331315full,0x33732e766f6d090aull,0x3234327225092032ull,0x7262090a3b31202cull,
0x240920696e752e61ull,0x343331315f305f4cull,0x305f4c240a3b3031ull,0x3a3636363331315full,
0x33732e766f6d090aull,0x3234327225092032ull,0x5f4c240a3b30202cull,0x3031343331315f30ull,
0x752e766f6d090a3aull,0x3432722509203233ull,0x73090a3b30202c33ull,0x732e656e2e707465ull,
0x3935702509203233ull,0x2c3234327225202cull,0x0a3b333432722520ull,0x6220393570254009ull,
0x5f744c2409206172ull,0x3037373832315f30ull,0x6c672e646c090a3bull,0x3233732e6c61626full,
0x2c34343272250920ull,0x32332b3172255b20ull,0x2e766f6d090a3b5dull,0x3272250920323375ull,
0x090a3b31202c3534ull,0x2e656e2e70746573ull,0x3670250920323373ull,0x3434327225202c30ull,
0x3b3534327225202cull,0x203036702540090aull,0x744c240920617262ull,0x37373832315f305full,
0x672e646c090a3b30ull,0x33732e6c61626f6cull,0x2c30327225092032ull,0x36392b3172255b20ull,
0x2e766f6d090a3b5dull,0x3272250920323375ull,0x090a3b39202c3634ull,0x2e74672e70746573ull,
0x3670250920323373ull,0x2c30327225202c31ull,0x0a3b363432722520ull,0x6220313670254009ull,
0x5f744c2409206172ull,0x3037373832315f30ull,0x09636f6c2e090a3bull,0x3009333031093731ull,
0x6f6c2e6c756d090aull,0x722509203233752eull,0x327225202c373432ull,0x3b34343136202c30ull,
0x33752e646461090aull,0x3834327225092032ull,0x25202c317225202cull,0x61090a3b37343272ull,
0x09203233752e6464ull,0x25202c3934327225ull,0x3336202c38343272ull,0x2e766f6d090a3b36ull,
0x3272250920323373ull,0x090a3b31202c3035ull,0x6f6c672e6d6f7461ull,0x2e6464612e6c6162ull,
0x7672250920323373ull,0x343272255b202c31ull,0x35327225202c5d39ull,0x2e646461090a3b30ull,
0x3172250920323375ull,0x202c317225202c30ull,0x090a3b3633353536ull,0x61626f6c672e646cull,
0x7225092038732e6cull,0x72255b202c313532ull,0x353834332d2b3031ull,0x2e766f6d090a3b5dull,
0x3272250920323375ull,0x090a3b30202c3235ull,0x2e656e2e70746573ull,0x3670250920323373ull,
0x3135327225202c32ull,0x3b3235327225202cull,0x203236702540090aull,0x744c240920617262ull,
0x38323932315f305full,0x636f6c2e090a3b32ull,0x0936363309383109ull,0x732e766f6d090a30ull,
0x3168722509203631ull,0x73090a3b31202c38ull,0x6c61626f6c672e74ull,0x72255b092038732eull,
0x353834332d2b3031ull,0x3831687225202c5dull,0x09636f6c2e090a3bull,0x3009313831093831ull,
0x33732e766f6d090aull,0x3335327225092032ull,0x090a3b333031202cull,0x203233732e766f6dull,
0x30202c3735722509ull,0x752e766f6d090a3bull,0x3532722509203233ull,0x6e6f635f5f202c34ull,
0x343934746e617473ull,0x315f305f4c240a3bull,0x200a3a3837313431ull,0x3e706f6f6c3c2f2full,
0x6f6220706f6f4c20ull,0x20656e696c207964ull,0x6f6c2e090a323831ull,0x3238310938310963ull,
0x2e646461090a3009ull,0x3272250920323375ull,0x37357225202c3535ull,0x090a3b317225202cull,
0x61626f6c672e7473ull,0x255b092038732e6cull,0x3732362b35353272ull,0x327225202c5d3038ull,
0x6f6c2e090a3b3335ull,0x3138310938310963ull,0x2e646461090a3009ull,0x3572250920323373ull,
0x2c37357225202c37ull,0x646461090a3b3120ull,0x722509203233752eull,0x357225202c363532ull,
0x3435327225202c37ull,0x6f632e646c090a3bull,0x092038732e74736eull,0x5b202c3335327225ull,
0x5d302b3635327225ull,0x752e766f6d090a3bull,0x3532722509203233ull,0x73090a3b30202c37ull,
0x732e71652e707465ull,0x3336702509203233ull,0x2c3335327225202cull,0x0a3b373532722520ull,
0x6220333670254009ull,0x305f4c2409206172ull,0x3b3634393431315full,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3238312065ull,
0x6562616c20646165ull,0x305f4c242064656cull,0x0a3837313431315full,0x3233752e64646109ull,
0x2c38353272250920ull,0x202c343532722520ull,0x746573090a3b3133ull,0x3233732e746c2e70ull,
0x202c343670250920ull,0x25202c3635327225ull,0x40090a3b38353272ull,0x6172622034367025ull,
0x315f305f4c240920ull,0x240a3b3837313431ull,0x393431315f305f4cull,0x6f6c2e090a3a3634ull,
0x3338310938310963ull,0x2e766f6d090a3009ull,0x6872250920363173ull,0x090a3b30202c3931ull,
0x203233752e646461ull,0x202c393532722509ull,0x7225202c37357225ull,0x2e747663090a3b31ull,
0x203631752e323375ull,0x202c303632722509ull,0x090a3b3931687225ull,0x61626f6c672e7473ull,
0x255b092038732e6cull,0x3732362b39353272ull,0x327225202c5d3038ull,0x5f744c240a3b3036ull,
0x3238323932315f30ull,0x09636f6c2e090a3aull,0x3009393633093831ull,0x6f6c672e646c090aull,
0x203233732e6c6162ull,0x202c313632722509ull,0x5d34382b3172255bull,0x6c672e646c090a3bull,
0x3233752e6c61626full,0x2c32363272250920ull,0x36392b3172255b20ull,0x2e6c756d090a3b5dull,
0x09203233752e6f6cull,0x25202c3336327225ull,0x3136202c32363272ull,0x646461090a3b3434ull,
0x722509203233752eull,0x317225202c343632ull,0x3b3336327225202cull,0x6f6c672e7473090aull,
0x203233732e6c6162ull,0x2b34363272255b09ull,0x7225202c5d303436ull,0x6c2e090a3b313632ull,
0x373309383109636full,0x766f6d090a300930ull,0x722509203233732eull,0x0a3b33202c353632ull,
0x626f6c672e646c09ull,0x09203233752e6c61ull,0x5b202c3636327225ull,0x3b5d36392b317225ull,
0x6f6c2e6c756d090aull,0x722509203233752eull,0x327225202c373632ull,0x34343136202c3636ull,
0x752e646461090a3bull,0x3632722509203233ull,0x202c317225202c38ull,0x090a3b3736327225ull,
0x61626f6c672e7473ull,0x5b09203233732e6cull,0x34362b3836327225ull,0x36327225202c5d34ull,
0x305f744c240a3b35ull,0x3a3037373832315full,0x315f305f744c240aull,0x240a3a3835323832ull,
0x3037375f305f744cull,0x09636f6c2e090a3aull,0x3009373332093032ull,0x7261702e646c090aull,
0x09203233732e6d61ull,0x5b202c3936327225ull,0x6170616475635f5full,0x5034315a5f5f6d72ull,
0x4b74656e69727465ull,0x5069506c656e7265ull,0x31506969695f5366ull,0x5f69667570675f32ull,
0x5f5f5f5f61746164ull,0x617261705f6c6176ull,0x756d090a3b5d6e6dull,0x3233732e6f6c2e6cull,
0x2c30373272250920ull,0x202c393632722520ull,0x090a3b3936327225ull,0x732e6f6c2e6c756dull,
0x3732722509203233ull,0x3037327225202c31ull,0x6873090a3b32202cull,0x2509203233732e72ull,
0x7225202c32373272ull,0x3b3031202c313732ull,0x33752e766f6d090aull,0x3337327225092032ull,
0x6573090a3b30202cull,0x33732e656c2e7074ull,0x2c35367025092032ull,0x202c323732722520ull,
0x090a3b3337327225ull,0x7262203536702540ull,0x305f744c24092061ull,0x3b3031323835315full,
0x33732e766f6d090aull,0x3437327225092032ull,0x3b3237327225202cull,0x2e34326c756d090aull,
0x09203233752e6f6cull,0x25202c3537327225ull,0x090a3b34202c3472ull,0x203233732e726873ull,
0x202c363732722509ull,0x32202c3137327225ull,0x732e646461090a3bull,0x3732722509203233ull,
0x3137327225202c37ull,0x3b3637327225202cull,0x6f6c2e6c756d090aull,0x722509203233752eull,
0x327225202c383732ull,0x3b337225202c3737ull,0x6f6c2e6c756d090aull,0x722509203233752eull,
0x327225202c393732ull,0x090a3b34202c3837ull,0x6d617261702e646cull,0x722509203233752eull,
0x5f5f5b202c303832ull,0x6d72617061647563ull,0x74655034315a5f5full,0x72654b74656e6972ull,
0x53665069506c656eull,0x5f3231506969695full,0x61645f6966757067ull,0x61765f5f5f5f6174ull,
0x676d617261705f6cull,0x6461090a3b5d735full,0x2509203233752e64ull,0x7225202c31383272ull,
0x327225202c303832ull,0x766f6d090a3b3937ull,0x722509203233732eull,0x0a3b30202c323832ull,
0x3233732e766f6d09ull,0x2c33383272250920ull,0x0a3b343732722520ull,0x33315f305f744c24ull,
0x2f200a3a36303330ull,0x203e706f6f6c3c2full,0x646f6220706f6f4cull,0x3220656e696c2079ull,
0x7473656e202c3733ull,0x7470656420676e69ull,0x7365202c31203a68ull,0x20646574616d6974ull,
0x6f69746172657469ull,0x6e6b6e75203a736eull,0x6f6c2e090a6e776full,0x0932380930320963ull,
0x732e766f6d090a30ull,0x3832722509203233ull,0x3334383631202c34ull,0x6873090a3b393030ull,
0x2509203233622e6cull,0x7225202c35383272ull,0x0a3b38202c323832ull,0x2e6f6c2e6c756d09ull,
0x3272250920323375ull,0x38327225202c3638ull,0x61090a3b34202c35ull,0x09203233752e6464ull,
0x25202c3738327225ull,0x7225202c35373272ull,0x6461090a3b363832ull,0x2509203233752e64ull,
0x7225202c38383272ull,0x327225202c313832ull,0x2e7473090a3b3738ull,0x732e6c61626f6c67ull,
0x3272255b09203233ull,0x25202c5d302b3838ull,0x61090a3b34383272ull,0x09203233732e6464ull,
0x25202c3238327225ull,0x3b31202c32383272ull,0x6e2e70746573090aull,0x2509203233732e65ull,
0x327225202c363670ull,0x38327225202c3237ull,0x36702540090a3b32ull,0x2409206172622036ull,
0x3033315f305f744cull,0x7262090a3b363033ull,0x240920696e752e61ull,0x3932315f305f744cull,
0x744c240a3b343937ull,0x31323835315f305full,0x326c756d090a3a30ull,0x3233752e6f6c2e34ull,
0x2c35373272250920ull,0x3b34202c34722520ull,0x33732e726873090aull,0x3637327225092032ull,
0x2c3137327225202cull,0x5f744c240a3b3220ull,0x3439373932315f30ull,0x622e6c6873090a3aull,
0x3832722509203233ull,0x3237327225202c39ull,0x7573090a3b38202cull,0x2509203233732e62ull,
0x7225202c30393272ull,0x327225202c363732ull,0x746573090a3b3938ull,0x3233752e65672e70ull,
0x202c373670250920ull,0x327225202c347225ull,0x702540090a3b3039ull,0x0920617262203736ull,
0x33315f305f744c24ull,0x2e090a3b38313830ull,0x3809303209636f6cull,0x766f6d090a300936ull,
0x722509203233732eull,0x383631202c313932ull,0x090a3b3930303334ull,0x6d617261702e646cull,
0x722509203233752eull,0x5f5f5b202c323932ull,0x6d72617061647563ull,0x74655034315a5f5full,
0x72654b74656e6972ull,0x53665069506c656eull,0x5f3231506969695full,0x61645f6966757067ull,
0x61765f5f5f5f6174ull,0x676d617261705f6cull,0x6461090a3b5d735full,0x2509203233732e64ull,
0x7225202c33393272ull,0x327225202c313732ull,0x6c756d090a3b3637ull,0x203233752e6f6c2eull,
0x202c343932722509ull,0x327225202c337225ull,0x6c756d090a3b3339ull,0x203233752e6f6c2eull,
0x202c353932722509ull,0x34202c3439327225ull,0x752e646461090a3bull,0x3932722509203233ull,
0x3239327225202c36ull,0x3b3539327225202cull,0x33752e646461090aull,0x3739327225092032ull,
0x2c3938327225202cull,0x6d090a3b34722520ull,0x33752e6f6c2e6c75ull,0x3839327225092032ull,
0x2c3739327225202cull,0x646461090a3b3420ull,0x722509203233752eull,0x327225202c393932ull,
0x39327225202c3639ull,0x672e7473090a3b38ull,0x33732e6c61626f6cull,0x393272255b092032ull,
0x7225202c5d302b39ull,0x744c240a3b313932ull,0x31383033315f305full,0x636f6c2e090a3a38ull,
0x3009383809303209ull,0x33752e766f6d090aull,0x3030337225092032ull,0x6573090a3b30202cull,
0x33752e71652e7074ull,0x2c38367025092032ull,0x7225202c34722520ull,0x2140090a3b303033ull,
0x6172622038367025ull,0x5f305f744c240920ull,0x0a3b303333313331ull,0x393109636f6c2e09ull,
0x6d090a3009323609ull,0x09203233752e766full,0x6d202c3130337225ull,0x702e646c090a3b74ull,
0x3233732e6d617261ull,0x2c32303372250920ull,0x616475635f5f5b20ull,0x315a5f5f6d726170ull,
0x656e697274655034ull,0x506c656e72654b74ull,0x6969695f53665069ull,0x667570675f323150ull,
0x5f5f617461645f69ull,0x61705f6c61765f5full,0x5d646565736d6172ull,0x752e646461090a3bull,
0x3033722509203233ull,0x3230337225202c33ull,0x090a3b337225202cull,0x65726168732e7473ull,
0x5b09203233752e64ull,0x25202c5d302b746dull,0x61090a3b33303372ull,0x09203233752e6464ull,
0x25202c3430337225ull,0x3b34202c31303372ull,0x33752e646461090aull,0x3530337225092032ull,
0x2c3130337225202cull,0x090a3b3639343220ull,0x203233732e766f6dull,0x202c363033722509ull,
0x305f744c240a3b31ull,0x3a3435333233315full,0x6f6f6c3c2f2f200aull,0x20706f6f4c203e70ull,
0x6e696c2079646f62ull,0x656e202c32362065ull,0x656420676e697473ull,0x202c31203a687470ull,
0x6f69746172657469ull,0x0a333236203a736eull,0x393109636f6c2e09ull,0x6c090a3009353609ull,
0x6465726168732e64ull,0x722509203233752eull,0x72255b202c373033ull,0x3b5d342d2b343033ull,
0x33752e726873090aull,0x3830337225092032ull,0x2c3730337225202cull,0x6f78090a3b303320ull,
0x2509203233622e72ull,0x7225202c39303372ull,0x337225202c373033ull,0x6c756d090a3b3830ull,
0x203233752e6f6c2eull,0x202c303133722509ull,0x31202c3930337225ull,0x3532333334323138ull,
0x2e646461090a3b33ull,0x3372250920323375ull,0x30337225202c3131ull,0x3031337225202c36ull,
0x68732e7473090a3bull,0x3233752e64657261ull,0x34303372255b0920ull,0x337225202c5d302bull,
0x646461090a3b3131ull,0x722509203233732eull,0x337225202c363033ull,0x090a3b31202c3630ull,
0x203233752e646461ull,0x202c343033722509ull,0x34202c3430337225ull,0x2e70746573090a3bull,
0x09203233752e656eull,0x7225202c39367025ull,0x337225202c343033ull,0x702540090a3b3530ull,
0x0920617262203936ull,0x33315f305f744c24ull,0x4c240a3b34353332ull,0x333133315f305f74ull,
0x766f6d090a3a3033ull,0x722509203233752eull,0x3b746d202c313033ull,0x3109636f6c2e090aull,
0x090a300938360939ull,0x636e79732e726162ull,0x6c2e090a3b300920ull,0x333209303209636full,
0x2e646c090a300938ull,0x33732e6d61726170ull,0x3231337225092032ull,0x6475635f5f5b202cull,
0x5a5f5f6d72617061ull,0x6e69727465503431ull,0x6c656e72654b7465ull,0x69695f5366506950ull,
0x7570675f32315069ull,0x5f617461645f6966ull,0x705f6c61765f5f5full,0x0a3b5d736d617261ull,
0x3233752e766f6d09ull,0x2c33313372250920ull,0x746573090a3b3020ull,0x3233732e656c2e70ull,
0x202c303770250920ull,0x25202c3231337225ull,0x40090a3b33313372ull,0x6172622030377025ull,
0x5f305f744c240920ull,0x0a3b363634383531ull,0x3233732e64646109ull,0x2c37373272250920ull,
0x202c313732722520ull,0x090a3b3637327225ull,0x752e6f6c2e6c756dull,0x3732722509203233ull,
0x3737327225202c38ull,0x090a3b337225202cull,0x752e6f6c2e6c756dull,0x3732722509203233ull,
0x3837327225202c39ull,0x646c090a3b34202cull,0x752e6d617261702eull,0x3133722509203233ull,
0x75635f5f5b202c34ull,0x5f5f6d7261706164ull,0x697274655034315aull,0x656e72654b74656eull,
0x695f53665069506cull,0x70675f3231506969ull,0x617461645f696675ull,0x5f6c61765f5f5f5full,
0x735f676d61726170ull,0x2e646461090a3b5dull,0x3272250920323375ull,0x31337225202c3138ull,
0x3937327225202c34ull,0x732e646461090a3bull,0x3133722509203233ull,0x3936327225202c35ull,
0x3b3936327225202cull,0x6f6c2e6c756d090aull,0x722509203233732eull,0x337225202c363133ull,
0x36327225202c3531ull,0x2e646461090a3b39ull,0x3372250920323373ull,0x31337225202c3731ull,
0x0a3b313133202c32ull,0x3233732e766f6d09ull,0x2c38313372250920ull,0x3837313435312d20ull,
0x6d090a3b31333133ull,0x09203233732e766full,0x30202c3931337225ull,0x2e70746573090a3bull,
0x09203233732e746cull,0x7225202c31377025ull,0x337225202c373133ull,0x736261090a3b3931ull,
0x722509203233732eull,0x337225202c303233ull,0x6c756d090a3b3731ull,0x203233752e69682eull,
0x202c313233722509ull,0x25202c3032337225ull,0x73090a3b38313372ull,0x09203233752e6275ull,
0x25202c3232337225ull,0x7225202c30323372ull,0x6873090a3b313233ull,0x2509203233752e72ull,
0x7225202c33323372ull,0x0a3b31202c323233ull,0x3233752e64646109ull,0x2c34323372250920ull,
0x202c333233722520ull,0x090a3b3132337225ull,0x203233732e726873ull,0x202c353233722509ull,
0x38202c3432337225ull,0x3137702540090a3bull,0x3233732e62757320ull,0x2c35323372250920ull,
0x202c393133722520ull,0x090a3b3532337225ull,0x203233732e766f6dull,0x202c363233722509ull,
0x090a3b3532337225ull,0x203233752e766f6dull,0x202c373233722509ull,0x6573090a3b363232ull,
0x33752e656c2e7074ull,0x2c32377025092032ull,0x7225202c34722520ull,0x6461090a3b373233ull,
0x2509203233732e64ull,0x7225202c38323372ull,0x0a3b343534202c34ull,0x3233752e766f6d09ull,
0x2c39323372250920ull,0x73090a3b36353220ull,0x752e746c2e707465ull,0x3337702509203233ull,
0x25202c347225202cull,0x6d090a3b39323372ull,0x09203233752e766full,0x31202c3033337225ull,
0x746573090a3b3131ull,0x3233752e656c2e70ull,0x202c343770250920ull,0x337225202c347225ull,
0x766f6d090a3b3033ull,0x722509203233752eull,0x323131202c313333ull,0x2e70746573090a3bull,
0x09203233752e746cull,0x7225202c35377025ull,0x3133337225202c34ull,0x752e646461090a3bull,
0x3333722509203233ull,0x3537327225202c32ull,0x3b3130337225202cull,0x33732e766f6d090aull,
0x3333337225092032ull,0x090a3b323236202cull,0x2e656c2e70746573ull,0x3770250920323373ull,
0x3832337225202c36ull,0x3b3333337225202cull,0x33732e766f6d090aull,0x3433337225092032ull,
0x6f6d090a3b30202cull,0x2509203233732e76ull,0x7225202c35333372ull,0x744c240a3b363233ull,
0x37333333315f305full,0x6c3c2f2f200a3a38ull,0x6f6f4c203e706f6full,0x6c2079646f622070ull,
0x2c38333220656e69ull,0x676e697473656e20ull,0x203a687470656420ull,0x6d69747365202c31ull,
0x6574692064657461ull,0x3a736e6f69746172ull,0x6e776f6e6b6e7520ull,0x3209636f6c2e090aull,
0x090a300938390930ull,0x6220323770252140ull,0x5f744c2409206172ull,0x3433363333315f30ull,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c38333220656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x37333333315f305full,
0x09636f6c2e090a38ull,0x0a30093338093931ull,0x726168732e646c09ull,0x09203233752e6465ull,
0x5b202c3633337225ull,0x5d302b3233337225ull,0x622e646e61090a3bull,0x3333722509203233ull,
0x3633337225202c37ull,0x34373431322d202cull,0x090a3b3834363338ull,0x65726168732e646cull,
0x2509203233752e64ull,0x255b202c38333372ull,0x3b5d342b32333372ull,0x33622e646e61090aull,
0x3933337225092032ull,0x2c3833337225202cull,0x3338343734313220ull,0x726f090a3b373436ull,
0x722509203233622eull,0x337225202c303433ull,0x33337225202c3733ull,0x636f6c2e090a3b39ull,
0x3009343809393109ull,0x6168732e646c090aull,0x203233752e646572ull,0x202c313433722509ull,
0x312b32333372255bull,0x73090a3b5d383835ull,0x09203233752e7268ull,0x25202c3234337225ull,
0x3b31202c30343372ull,0x33622e726f78090aull,0x3334337225092032ull,0x2c3134337225202cull,
0x0a3b323433722520ull,0x3233622e726f7809ull,0x2c34343372250920ull,0x202c333433722520ull,
0x333834373237312dull,0x6e61090a3b313836ull,0x2509203233622e64ull,0x7225202c35343372ull,
0x0a3b31202c303433ull,0x3233732e67656e09ull,0x2c36343372250920ull,0x0a3b353433722520ull,
0x33752e74636c7309ull,0x2509203233732e32ull,0x7225202c37343372ull,0x337225202c333433ull,
0x34337225202c3434ull,0x2e766f6d090a3b36ull,0x3372250920323373ull,0x34337225202c3834ull,
0x305f744c240a3b37ull,0x3a3433363333315full,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3833322065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x3837333333315f30ull,0x3109636f6c2e090aull,0x090a300936380939ull,
0x636e79732e726162ull,0x2140090a3b300920ull,0x6172622032377025ull,0x5f305f744c240920ull,
0x0a3b363431343331ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c38333220ull,0x6c6562616c206461ull,0x305f744c24206465ull,
0x0a3837333333315full,0x393109636f6c2e09ull,0x6d090a3009393809ull,0x09203233732e766full,
0x25202c3934337225ull,0x73090a3b38343372ull,0x6465726168732e74ull,0x255b09203233752eull,
0x2c5d302b32333372ull,0x0a3b393433722520ull,0x33315f305f744c24ull,0x2f200a3a36343134ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,
0x64616568202c3833ull,0x64656c6562616c20ull,0x315f305f744c2420ull,0x2e090a3837333333ull,
0x3909393109636f6cull,0x726162090a300931ull,0x300920636e79732eull,0x3770252140090a3bull,
0x2409206172622032ull,0x3433315f305f744cull,0x2f2f200a3b383536ull,0x50203e706f6f6c3cull,
0x6c20666f20747261ull,0x79646f6220706f6full,0x333220656e696c20ull,0x2064616568202c38ull,
0x2064656c6562616cull,0x33315f305f744c24ull,0x6c2e090a38373333ull,0x373909393109636full,
0x732e646c090a3009ull,0x33752e6465726168ull,0x3035337225092032ull,0x32333372255b202cull,
0x090a3b5d3830392bull,0x203233622e646e61ull,0x202c313533722509ull,0x2d202c3035337225ull,
0x3633383437343132ull,0x2e646c090a3b3834ull,0x752e646572616873ull,0x3533722509203233ull,
0x333372255b202c32ull,0x0a3b5d3231392b32ull,0x3233622e646e6109ull,0x2c33353372250920ull,
0x202c323533722520ull,0x3633383437343132ull,0x2e726f090a3b3734ull,0x3372250920323362ull,
0x35337225202c3034ull,0x3335337225202c31ull,0x09636f6c2e090a3bull,0x0a30093839093931ull,
0x726168732e646c09ull,0x09203233752e6465ull,0x5b202c3435337225ull,0x5d302b3233337225ull,
0x752e726873090a3bull,0x3533722509203233ull,0x3034337225202c35ull,0x6f78090a3b31202cull,
0x2509203233622e72ull,0x7225202c36353372ull,0x337225202c343533ull,0x726f78090a3b3535ull,
0x722509203233622eull,0x337225202c373533ull,0x3237312d202c3635ull,0x3b31383633383437ull,
0x33622e646e61090aull,0x3835337225092032ull,0x2c3034337225202cull,0x67656e090a3b3120ull,
0x722509203233732eull,0x337225202c393533ull,0x636c73090a3b3835ull,0x33732e3233752e74ull,
0x3036337225092032ull,0x2c3635337225202cull,0x202c373533722520ull,0x090a3b3935337225ull,
0x203233732e766f6dull,0x202c383433722509ull,0x240a3b3036337225ull,0x3433315f305f744cull,
0x2f2f200a3a383536ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x333220656e696c20ull,0x2064616568202c38ull,0x2064656c6562616cull,0x33315f305f744c24ull,
0x6c2e090a38373333ull,0x303109393109636full,0x726162090a300930ull,0x300920636e79732eull,
0x3770252140090a3bull,0x2409206172622032ull,0x3533315f305f744cull,0x2f2f200a3b303731ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x333220656e696c20ull,
0x2064616568202c38ull,0x2064656c6562616cull,0x33315f305f744c24ull,0x6c2e090a38373333ull,
0x303109393109636full,0x766f6d090a300933ull,0x722509203233732eull,0x337225202c313633ull,
0x2e7473090a3b3834ull,0x752e646572616873ull,0x3372255b09203233ull,0x2c5d3830392b3233ull,
0x0a3b313633722520ull,0x33315f305f744c24ull,0x2f200a3a30373135ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3833ull,
0x64656c6562616c20ull,0x315f305f744c2420ull,0x2e090a3837333333ull,0x3109393109636f6cull,
0x6162090a30093530ull,0x0920636e79732e72ull,0x70252140090a3b30ull,0x0920617262203637ull,
0x33315f305f744c24ull,0x2f200a3b32383635ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3833ull,0x64656c6562616c20ull,
0x315f305f744c2420ull,0x2e090a3837333333ull,0x3109393109636f6cull,0x646c090a30093131ull,
0x2e6465726168732eull,0x3372250920323375ull,0x3372255b202c3236ull,0x5d363138312b3233ull,
0x622e646e61090a3bull,0x3633722509203233ull,0x3236337225202c33ull,0x34373431322d202cull,
0x090a3b3834363338ull,0x65726168732e646cull,0x2509203233752e64ull,0x255b202c34363372ull,
0x3238312b32333372ull,0x646e61090a3b5d30ull,0x722509203233622eull,0x337225202c353633ull,
0x37343132202c3436ull,0x0a3b373436333834ull,0x203233622e726f09ull,0x202c303433722509ull,
0x25202c3336337225ull,0x2e090a3b35363372ull,0x3109393109636f6cull,0x646c090a30093231ull,
0x2e6465726168732eull,0x3372250920323375ull,0x3372255b202c3636ull,0x3b5d3830392b3233ull,
0x33752e726873090aull,0x3736337225092032ull,0x2c3034337225202cull,0x726f78090a3b3120ull,
0x722509203233622eull,0x337225202c383633ull,0x36337225202c3636ull,0x2e726f78090a3b37ull,
0x3372250920323362ull,0x36337225202c3936ull,0x373237312d202c38ull,0x0a3b313836333834ull,
0x3233622e646e6109ull,0x2c30373372250920ull,0x202c303433722520ull,0x2e67656e090a3b31ull,
0x3372250920323373ull,0x37337225202c3137ull,0x74636c73090a3b30ull,0x3233732e3233752eull,
0x2c32373372250920ull,0x202c383633722520ull,0x25202c3936337225ull,0x6d090a3b31373372ull,
0x09203233732e766full,0x25202c3834337225ull,0x4c240a3b32373372ull,0x363533315f305f74ull,
0x3c2f2f200a3a3238ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x38333220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3333315f305f744cull,
0x6f6c2e090a383733ull,0x3431310939310963ull,0x2e726162090a3009ull,0x3b300920636e7973ull,
0x363770252140090aull,0x4c24092061726220ull,0x313633315f305f74ull,0x3c2f2f200a3b3439ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x38333220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3333315f305f744cull,0x6f6c2e090a383733ull,
0x3731310939310963ull,0x2e766f6d090a3009ull,0x3372250920323373ull,0x34337225202c3337ull,
0x732e7473090a3b38ull,0x33752e6465726168ull,0x333372255b092032ull,0x2c5d363138312b32ull,
0x0a3b333733722520ull,0x33315f305f744c24ull,0x2f200a3a34393136ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3833ull,
0x64656c6562616c20ull,0x315f305f744c2420ull,0x2e090a3837333333ull,0x3109393109636f6cull,
0x6162090a30093931ull,0x0920636e79732e72ull,0x70252140090a3b30ull,0x0920617262203836ull,
0x33315f305f744c24ull,0x2f200a3b32363936ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3833ull,0x64656c6562616c20ull,
0x315f305f744c2420ull,0x2e090a3837333333ull,0x3109393109636f6cull,0x646c090a30093432ull,
0x2e6465726168732eull,0x3372250920323375ull,0x2b746d5b202c3437ull,0x646e61090a3b5d30ull,
0x722509203233622eull,0x337225202c353733ull,0x37343132202c3437ull,0x0a3b373436333834ull,
0x726168732e646c09ull,0x09203233752e6465ull,0x5b202c3637337225ull,0x5d323934322b746dull,
0x622e646e61090a3bull,0x3733722509203233ull,0x3637337225202c37ull,0x34373431322d202cull,
0x090a3b3834363338ull,0x09203233622e726full,0x25202c3837337225ull,0x7225202c35373372ull,
0x6f6d090a3b373733ull,0x2509203233732e76ull,0x7225202c30343372ull,0x6c2e090a3b383733ull,
0x323109393109636full,0x726873090a300935ull,0x722509203233752eull,0x337225202c393733ull,
0x090a3b31202c3837ull,0x65726168732e646cull,0x2509203233752e64ull,0x6d5b202c30383372ull,
0x3b5d343835312b74ull,0x33622e726f78090aull,0x3138337225092032ull,0x2c3937337225202cull,
0x0a3b303833722520ull,0x3233622e726f7809ull,0x2c32383372250920ull,0x202c313833722520ull,
0x333834373237312dull,0x6e61090a3b313836ull,0x2509203233622e64ull,0x7225202c33383372ull,
0x0a3b31202c383733ull,0x3233732e67656e09ull,0x2c34383372250920ull,0x0a3b333833722520ull,
0x33752e74636c7309ull,0x2509203233732e32ull,0x7225202c35383372ull,0x337225202c313833ull,
0x38337225202c3238ull,0x732e7473090a3b34ull,0x33752e6465726168ull,0x322b746d5b092032ull,
0x7225202c5d323934ull,0x7262090a3b353833ull,0x240920696e752e61ull,0x3633315f305f744cull,
0x744c240a3b363037ull,0x36393633315f305full,0x6c3c2f2f200a3a32ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c38333220656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x333333315f305f74ull,0x2e766f6d090a3837ull,0x3372250920323373ull,
0x34337225202c3034ull,0x305f744c240a3b38ull,0x3a3630373633315full,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3833322065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x3837333333315f30ull,0x3109636f6c2e090aull,
0x0a30093732310939ull,0x6e79732e72616209ull,0x2e090a3b30092063ull,0x3109393109636f6cull,
0x6873090a30093333ull,0x2509203233752e72ull,0x7225202c36383372ull,0x3b3131202c303433ull,
0x33622e726f78090aull,0x3738337225092032ull,0x2c3638337225202cull,0x0a3b303433722520ull,
0x3233622e6c687309ull,0x2c38383372250920ull,0x202c373833722520ull,0x2e646e61090a3b37ull,
0x3372250920323362ull,0x38337225202c3938ull,0x383536312d202c38ull,0x0a3b363536383330ull,
0x3233622e726f7809ull,0x2c30393372250920ull,0x202c373833722520ull,0x090a3b3938337225ull,
0x203233622e6c6873ull,0x202c313933722509ull,0x31202c3039337225ull,0x2e646e61090a3b35ull,
0x3372250920323362ull,0x39337225202c3239ull,0x323237322d202c31ull,0x090a3b3434353633ull,
0x203233622e726f78ull,0x202c333933722509ull,0x25202c3039337225ull,0x73090a3b32393372ull,
0x09203233752e7268ull,0x25202c3439337225ull,0x3831202c33393372ull,0x622e726f78090a3bull,
0x3933722509203233ull,0x3339337225202c35ull,0x3b3439337225202cull,0x33732e766f6d090aull,
0x3834337225092032ull,0x3b3539337225202cull,0x3209636f6c2e090aull,0x0a30093330310930ull,
0x726168732e646c09ull,0x09203233752e6465ull,0x5b202c3639337225ull,0x5d302b3233337225ull,
0x752e6d6572090a3bull,0x3933722509203233ull,0x3639337225202c37ull,0x3b3631337225202cull,
0x3209636f6c2e090aull,0x0a30093430310930ull,0x2033377025214009ull,0x744c240920617262ull,
0x37343733315f305full,0x6c3c2f2f200a3b34ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c38333220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x333333315f305f74ull,0x636f6c2e090a3837ull,0x3009383209303209ull,0x33732e766964090aull,
0x3839337225092032ull,0x2c3739337225202cull,0x0a3b393632722520ull,0x3233732e62757309ull,
0x2c39393372250920ull,0x202c353133722520ull,0x2e766f6d090a3b31ull,0x3472250920323373ull,
0x090a3b30202c3030ull,0x2e71652e70746573ull,0x3770250920323373ull,0x3839337225202c37ull,
0x3b3030347225202cull,0x33732e627573090aull,0x3130347225092032ull,0x2c3839337225202cull,
0x6c6573090a3b3120ull,0x2509203233732e70ull,0x7225202c32303472ull,0x347225202c393933ull,
0x37377025202c3130ull,0x732e766f6d090a3bull,0x3034722509203233ull,0x3230347225202c33ull,
0x732e6d6572090a3bull,0x3034722509203233ull,0x3739337225202c34ull,0x3b3936327225202cull,
0x33622e646e61090aull,0x3530347225092032ull,0x2c3839337225202cull,0x766f6d090a3b3120ull,
0x722509203233752eull,0x0a3b30202c363034ull,0x71652e7074657309ull,0x702509203233732eull,
0x30347225202c3837ull,0x3630347225202c35ull,0x3837702540090a3bull,0x4c24092061726220ull,
0x393733315f305f74ull,0x3c2f2f200a3b3638ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x38333220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3333315f305f744cull,0x6f6c2e090a383733ull,0x0939320930320963ull,0x732e646461090a30ull,
0x3034722509203233ull,0x3430347225202c37ull,0x6f6d090a3b31202cull,0x2509203233732e76ull,
0x3b30202c38303472ull,0x33732e627573090aull,0x3930347225092032ull,0x2c3936327225202cull,
0x746573090a3b3120ull,0x3233732e656e2e70ull,0x202c393770250920ull,0x25202c3430347225ull,
0x73090a3b39303472ull,0x203233732e706c65ull,0x202c303134722509ull,0x25202c3730347225ull,
0x7025202c38303472ull,0x617262090a3b3937ull,0x4c240920696e752eull,0x373733315f305f74ull,
0x5f744c240a3b3033ull,0x3638393733315f30ull,0x6f6c3c2f2f200a3aull,0x74726150203e706full,
0x706f6f6c20666f20ull,0x696c2079646f6220ull,0x202c38333220656eull,0x62616c2064616568ull,
0x744c242064656c65ull,0x37333333315f305full,0x732e766f6d090a38ull,0x3134722509203233ull,
0x3430347225202c30ull,0x5f305f744c240a3bull,0x0a3a303337373331ull,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c38333220ull,
0x6c6562616c206461ull,0x305f744c24206465ull,0x0a3837333333315full,0x3233732e766f6d09ull,
0x2c31313472250920ull,0x0a3b303134722520ull,0x303209636f6c2e09ull,0x61090a3009303309ull,
0x09203233732e6464ull,0x25202c3231347225ull,0x3b31202c38393372ull,0x33732e766f6d090aull,
0x3331347225092032ull,0x6573090a3b30202cull,0x33732e656e2e7074ull,0x2c30387025092032ull,
0x202c393933722520ull,0x090a3b3839337225ull,0x3233732e706c6573ull,0x2c34313472250920ull,
0x202c323134722520ull,0x25202c3331347225ull,0x6f6d090a3b303870ull,0x2509203233732e76ull,
0x7225202c35313472ull,0x6c2e090a3b343134ull,0x313309303209636full,0x2e6c756d090a3009ull,
0x09203233732e6f6cull,0x25202c3631347225ull,0x7225202c32303472ull,0x6461090a3b393632ull,
0x2509203233732e64ull,0x7225202c37313472ull,0x347225202c303134ull,0x646461090a3b3631ull,
0x722509203233752eull,0x327225202c383134ull,0x31347225202c3138ull,0x672e646c090a3b37ull,
0x38732e6c61626f6cull,0x2c39313472250920ull,0x2b38313472255b20ull,0x766f6d090a3b5d30ull,
0x722509203233732eull,0x347225202c303234ull,0x6f6c2e090a3b3931ull,0x0932330930320963ull,
0x6c2e6c756d090a30ull,0x2509203233732e6full,0x7225202c31323472ull,0x327225202c383933ull,
0x646461090a3b3936ull,0x722509203233732eull,0x347225202c323234ull,0x30347225202c3132ull,
0x2e646461090a3b34ull,0x3472250920323375ull,0x32347225202c3332ull,0x3138327225202c32ull,
0x6c672e646c090a3bull,0x2038732e6c61626full,0x202c343234722509ull,0x302b33323472255bull,
0x2e766f6d090a3b5dull,0x3472250920323373ull,0x32347225202c3532ull,0x2e766f6d090a3b34ull,
0x3472250920323373ull,0x090a3b30202c3632ull,0x752e74672e746573ull,0x09203233732e3233ull,
0x25202c3732347225ull,0x7225202c34323472ull,0x656e090a3b363234ull,0x2509203233732e67ull,
0x7225202c38323472ull,0x6f6d090a3b373234ull,0x2509203233732e76ull,0x3b30202c39323472ull,
0x74672e746573090aull,0x3233732e3233752eull,0x2c30333472250920ull,0x202c393134722520ull,
0x090a3b3932347225ull,0x203233732e67656eull,0x202c313334722509ull,0x090a3b3033347225ull,
0x203233622e646e61ull,0x202c323334722509ull,0x25202c3832347225ull,0x6d090a3b31333472ull,
0x09203233752e766full,0x30202c3333347225ull,0x2e70746573090a3bull,0x09203233732e7165ull,
0x7225202c31387025ull,0x347225202c323334ull,0x702540090a3b3333ull,0x0920617262203138ull,
0x33315f305f744c24ull,0x2f200a3b38393438ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3833ull,0x64656c6562616c20ull,
0x315f305f744c2420ull,0x2e090a3837333333ull,0x3309303209636f6cull,0x646461090a300936ull,
0x722509203233732eull,0x337225202c343334ull,0x090a3b37202c3433ull,0x203233732e726873ull,
0x202c353334722509ull,0x32202c3631337225ull,0x6c2e6c756d090a3bull,0x2509203233752e6full,
0x7225202c36333472ull,0x0a3b34202c353334ull,0x3233752e64646109ull,0x2c37333472250920ull,
0x202c313832722520ull,0x090a3b3633347225ull,0x752e6f6c2e6c756dull,0x3334722509203233ull,
0x3232347225202c38ull,0x6461090a3b34202cull,0x2509203233752e64ull,0x7225202c39333472ull,
0x347225202c373334ull,0x2e7473090a3b3833ull,0x732e6c61626f6c67ull,0x3472255b09203233ull,
0x25202c5d302b3933ull,0x6d090a3b34333472ull,0x09203233732e766full,0x31202c3034347225ull,
0x752e617262090a3bull,0x5f744c240920696eull,0x3831323733315f30ull,0x5f305f744c240a3bull,
0x0a3a383934383331ull,0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,
0x656e696c2079646full,0x6568202c38333220ull,0x6c6562616c206461ull,0x305f744c24206465ull,
0x0a3837333333315full,0x3233732e766f6d09ull,0x2c30343472250920ull,0x617262090a3b3020ull,
0x4c240920696e752eull,0x323733315f305f74ull,0x5f744c240a3b3831ull,0x3437343733315f30ull,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c38333220656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x37333333315f305full,
0x732e766f6d090a38ull,0x3434722509203233ull,0x4c240a3b30202c30ull,0x323733315f305f74ull,
0x3c2f2f200a3a3831ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x38333220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3333315f305f744cull,
0x6f6c2e090a383733ull,0x0939330930320963ull,0x732e726162090a30ull,0x0a3b300920636e79ull,
0x3233732e766f6d09ull,0x2c31343472250920ull,0x746573090a3b3020ull,0x3233732e656e2e70ull,
0x202c323870250920ull,0x25202c3034347225ull,0x40090a3b31343472ull,0x7262203238702521ull,
0x305f744c24092061ull,0x3b3435373833315full,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3833322065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x3837333333315f30ull,0x3209636f6c2e090aull,0x090a300936340930ull,
0x203233732e646461ull,0x202c323434722509ull,0x37202c3433337225ull,0x622e646e61090a3bull,
0x3434722509203233ull,0x3234347225202c33ull,0x6964090a3b31202cull,0x2509203233732e76ull,
0x7225202c34343472ull,0x327225202c373933ull,0x646e61090a3b3936ull,0x722509203233622eull,
0x347225202c353434ull,0x090a3b31202c3434ull,0x2e71652e70746573ull,0x3870250920323373ull,
0x3334347225202c33ull,0x3b3534347225202cull,0x203338702540090aull,0x744c240920617262ull,
0x30393234345f305full,0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,
0x696c2079646f6220ull,0x202c38333220656eull,0x62616c2064616568ull,0x744c242064656c65ull,
0x37333333315f305full,0x732e726873090a38ull,0x3434722509203233ull,0x3631337225202c36ull,
0x756d090a3b32202cull,0x3233752e6f6c2e6cull,0x2c37343472250920ull,0x202c363434722520ull,
0x2e646461090a3b34ull,0x3472250920323375ull,0x34347225202c3834ull,0x3138327225202c37ull,
0x732e766f6d090a3bull,0x3434722509203233ull,0x3131347225202c39ull,0x732e766f6d090a3bull,
0x3534722509203233ull,0x3330347225202c30ull,0x6c2e6c756d090a3bull,0x2509203233732e6full,
0x7225202c31353472ull,0x327225202c303534ull,0x646461090a3b3936ull,0x722509203233732eull,
0x347225202c323534ull,0x35347225202c3934ull,0x2e6c756d090a3b31ull,0x09203233752e6f6cull,
0x25202c3335347225ull,0x3b34202c32353472ull,0x33752e646461090aull,0x3435347225092032ull,
0x2c3834347225202cull,0x0a3b333534722520ull,0x626f6c672e646c09ull,0x09203233732e6c61ull,
0x5b202c3535347225ull,0x5d302b3435347225ull,0x2e70746573090a3bull,0x09203233732e7165ull,
0x7225202c34387025ull,0x347225202c353534ull,0x702540090a3b3234ull,0x0920617262203438ull,
0x35315f305f744c24ull,0x2f200a3b38373938ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,
0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3833ull,0x64656c6562616c20ull,
0x315f305f744c2420ull,0x6d090a3837333333ull,0x09203233732e766full,0x25202c3635347225ull,
0x6d090a3b35313472ull,0x33732e6f6c2e6c75ull,0x3735347225092032ull,0x2c3635347225202cull,
0x0a3b393632722520ull,0x3233732e64646109ull,0x2c38353472250920ull,0x202c373534722520ull,
0x090a3b3936327225ull,0x752e6f6c2e6c756dull,0x3534722509203233ull,0x3835347225202c39ull,
0x7573090a3b34202cull,0x2509203233752e62ull,0x7225202c30363472ull,0x0a3b34202c393534ull,
0x3233732e64646109ull,0x2c31363472250920ull,0x202c373534722520ull,0x090a3b3934347225ull,
0x752e6f6c2e6c756dull,0x3634722509203233ull,0x3136347225202c32ull,0x7573090a3b34202cull,
0x2509203233752e62ull,0x7225202c33363472ull,0x0a3b34202c323634ull,0x3233732e766f6d09ull,
0x2c34363472250920ull,0x746573090a3b3020ull,0x3233732e71652e70ull,0x202c353870250920ull,
0x25202c3934347225ull,0x73090a3b34363472ull,0x203233752e706c65ull,0x202c353634722509ull,
0x25202c3036347225ull,0x7025202c33363472ull,0x646461090a3b3538ull,0x722509203233752eull,
0x347225202c363634ull,0x34347225202c3536ull,0x672e646c090a3b38ull,0x33732e6c61626f6cull,
0x3736347225092032ull,0x36363472255b202cull,0x6573090a3b5d302bull,0x33732e71652e7074ull,
0x2c36387025092032ull,0x202c373634722520ull,0x090a3b3234347225ull,0x7262203638702540ull,
0x305f744c24092061ull,0x3b3837393835315full,0x345f305f744c240aull,0x2f200a3a30393234ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,
0x64616568202c3833ull,0x64656c6562616c20ull,0x315f305f744c2420ull,0x6d090a3837333333ull,
0x09203233732e766full,0x31202c3836347225ull,0x752e617262090a3bull,0x5f744c240920696eull,
0x3b36323835345f30ull,0x315f305f744c240aull,0x240a3a3837393835ull,0x3534345f305f744cull,
0x3c2f2f200a3a3634ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x38333220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3333315f305f744cull,
0x766f6d090a383733ull,0x722509203233732eull,0x0a3b30202c383634ull,0x35345f305f744c24ull,
0x2f2f200a3a363238ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x333220656e696c20ull,0x2064616568202c38ull,0x2064656c6562616cull,0x33315f305f744c24ull,
0x6f6d090a38373333ull,0x2509203233732e76ull,0x3b30202c39363472ull,0x6e2e70746573090aull,
0x2509203233732e65ull,0x347225202c323870ull,0x36347225202c3836ull,0x305f744c240a3b39ull,
0x3a3435373833315full,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3833322065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x3837333333315f30ull,0x323870252140090aull,0x4c24092061726220ull,0x323933315f305f74ull,
0x3c2f2f200a3b3636ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x38333220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3333315f305f744cull,
0x6f6c2e090a383733ull,0x0934350930320963ull,0x732e766f6d090a30ull,0x3734722509203233ull,
0x3032347225202c30ull,0x732e627573090a3bull,0x3734722509203233ull,0x3037347225202c31ull,
0x6f6d090a3b31202cull,0x2509203233732e76ull,0x7225202c32373472ull,0x6f6d090a3b313134ull,
0x2509203233732e76ull,0x7225202c33373472ull,0x756d090a3b333034ull,0x3233732e6f6c2e6cull,
0x2c34373472250920ull,0x202c333734722520ull,0x090a3b3936327225ull,0x203233732e646461ull,
0x202c353734722509ull,0x25202c3237347225ull,0x61090a3b34373472ull,0x09203233752e6464ull,
0x25202c3637347225ull,0x7225202c31383272ull,0x7473090a3b353734ull,0x2e6c61626f6c672eull,
0x3472255b09203873ull,0x25202c5d302b3637ull,0x2e090a3b31373472ull,0x3509303209636f6cull,
0x766f6d090a300937ull,0x722509203233732eull,0x347225202c373734ull,0x627573090a3b3532ull,
0x722509203233732eull,0x347225202c383734ull,0x090a3b31202c3737ull,0x203233732e766964ull,
0x202c393734722509ull,0x25202c3739337225ull,0x6d090a3b39363272ull,0x33732e6f6c2e6c75ull,
0x3038347225092032ull,0x2c3936327225202cull,0x0a3b393734722520ull,0x3233732e6d657209ull,
0x2c31383472250920ull,0x202c373933722520ull,0x090a3b3936327225ull,0x203233732e646461ull,
0x202c323834722509ull,0x25202c3038347225ull,0x61090a3b31383472ull,0x09203233752e6464ull,
0x25202c3338347225ull,0x7225202c31383272ull,0x7473090a3b323834ull,0x2e6c61626f6c672eull,
0x3472255b09203873ull,0x25202c5d302b3338ull,0x4c240a3b38373472ull,0x323933315f305f74ull,
0x3c2f2f200a3a3636ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x38333220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3333315f305f744cull,
0x6f6c2e090a383733ull,0x0931360930320963ull,0x732e726162090a30ull,0x0a3b300920636e79ull,
0x2032387025214009ull,0x744c240920617262ull,0x37373933315f305full,0x6c3c2f2f200a3b38ull,
0x726150203e706f6full,0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c38333220656e69ull,
0x616c206461656820ull,0x4c242064656c6562ull,0x333333315f305f74ull,0x636f6c2e090a3837ull,
0x3009343609303209ull,0x33732e766f6d090aull,0x3438347225092032ull,0x3b3531347225202cull,
0x6f6c2e6c756d090aull,0x722509203233732eull,0x347225202c353834ull,0x36327225202c3438ull,
0x2e766f6d090a3b39ull,0x3472250920323373ull,0x31347225202c3638ull,0x2e646461090a3b31ull,
0x3472250920323373ull,0x38347225202c3738ull,0x3538347225202c36ull,0x752e646461090a3bull,
0x3834722509203233ull,0x3738347225202c38ull,0x3b3138327225202cull,0x6f6c672e646c090aull,
0x092038732e6c6162ull,0x5b202c3032687225ull,0x5d302b3838347225ull,0x732e646461090a3bull,
0x3268722509203631ull,0x3032687225202c31ull,0x7473090a3b31202cull,0x2e6c61626f6c672eull,
0x3472255b09203873ull,0x25202c5d302b3838ull,0x2e090a3b31326872ull,0x3609303209636f6cull,
0x6d6572090a300937ull,0x722509203233732eull,0x337225202c343034ull,0x36327225202c3739ull,
0x2e627573090a3b39ull,0x3472250920323373ull,0x36327225202c3938ull,0x64090a3b31202c39ull,
0x09203233732e7669ull,0x25202c3839337225ull,0x7225202c37393372ull,0x6573090a3b393632ull,
0x33732e656e2e7074ull,0x2c37387025092032ull,0x202c393834722520ull,0x090a3b3430347225ull,
0x732e6f6c2e6c756dull,0x3934722509203233ull,0x3839337225202c30ull,0x3b3936327225202cull,
0x33732e646461090aull,0x3232347225092032ull,0x2c3039347225202cull,0x0a3b343034722520ull,
0x3233752e64646109ull,0x2c31393472250920ull,0x202c323234722520ull,0x706c6573090a3b31ull,
0x722509203233752eull,0x347225202c323934ull,0x39347225202c3139ull,0x3b37387025202c30ull,
0x33752e646461090aull,0x3339347225092032ull,0x2c3239347225202cull,0x0a3b313832722520ull,
0x626f6c672e646c09ull,0x25092038732e6c61ull,0x255b202c32326872ull,0x3b5d302b33393472ull,
0x31732e646461090aull,0x3332687225092036ull,0x2c3232687225202cull,0x2e7473090a3b3120ull,
0x732e6c61626f6c67ull,0x393472255b092038ull,0x7225202c5d302b33ull,0x744c240a3b333268ull,
0x37373933315f305full,0x6c3c2f2f200a3a38ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c38333220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x333333315f305f74ull,0x636f6c2e090a3837ull,0x3009313709303209ull,0x79732e726162090aull,
0x090a3b300920636eull,0x09303209636f6c2eull,0x6c090a3009373031ull,0x6465726168732e64ull,
0x722509203233752eull,0x72255b202c343934ull,0x343230312b323333ull,0x2e6d6572090a3b5dull,
0x3372250920323375ull,0x39347225202c3739ull,0x3631337225202c34ull,0x09636f6c2e090a3bull,
0x3009383031093032ull,0x333770252140090aull,0x4c24092061726220ull,0x353034315f305f74ull,
0x3c2f2f200a3b3634ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x38333220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3333315f305f744cull,
0x6f6c2e090a383733ull,0x0938320930320963ull,0x732e766964090a30ull,0x3934722509203233ull,
0x3739337225202c35ull,0x3b3936327225202cull,0x33732e627573090aull,0x3939337225092032ull,
0x2c3531337225202cull,0x766f6d090a3b3120ull,0x722509203233732eull,0x0a3b30202c363934ull,
0x71652e7074657309ull,0x702509203233732eull,0x39347225202c3737ull,0x3639347225202c35ull,
0x732e627573090a3bull,0x3034722509203233ull,0x3539347225202c31ull,0x6573090a3b31202cull,
0x09203233732e706cull,0x25202c3230347225ull,0x7225202c39393372ull,0x377025202c313034ull,
0x2e766f6d090a3b37ull,0x3472250920323373ull,0x30347225202c3330ull,0x2e6d6572090a3b32ull,
0x3472250920323373ull,0x39337225202c3739ull,0x3936327225202c37ull,0x622e646e61090a3bull,
0x3934722509203233ull,0x3539347225202c38ull,0x6f6d090a3b31202cull,0x2509203233752e76ull,
0x3b30202c39393472ull,0x652e70746573090aull,0x2509203233732e71ull,0x347225202c383870ull,
0x39347225202c3839ull,0x38702540090a3b39ull,0x2409206172622038ull,0x3134315f305f744cull,
0x2f2f200a3b383530ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x333220656e696c20ull,0x2064616568202c38ull,0x2064656c6562616cull,0x33315f305f744c24ull,
0x6c2e090a38373333ull,0x393209303209636full,0x2e646461090a3009ull,0x3572250920323373ull,
0x39347225202c3030ull,0x6d090a3b31202c37ull,0x09203233732e766full,0x30202c3130357225ull,
0x732e627573090a3bull,0x3035722509203233ull,0x3936327225202c32ull,0x6573090a3b31202cull,
0x33732e656e2e7074ull,0x2c39387025092032ull,0x202c373934722520ull,0x090a3b3230357225ull,
0x3233732e706c6573ull,0x2c33303572250920ull,0x202c303035722520ull,0x25202c3130357225ull,
0x7262090a3b393870ull,0x240920696e752e61ull,0x3034315f305f744cull,0x744c240a3b323038ull,
0x35303134315f305full,0x6c3c2f2f200a3a38ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c38333220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x333333315f305f74ull,0x2e766f6d090a3837ull,0x3572250920323373ull,0x39347225202c3330ull,
0x305f744c240a3b37ull,0x3a3230383034315full,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3833322065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x3837333333315f30ull,0x33732e766f6d090aull,0x3131347225092032ull,
0x3b3330357225202cull,0x3209636f6c2e090aull,0x090a300930330930ull,0x203233732e646461ull,
0x202c343035722509ull,0x31202c3539347225ull,0x732e766f6d090a3bull,0x3035722509203233ull,
0x73090a3b30202c35ull,0x732e656e2e707465ull,0x3039702509203233ull,0x2c3539347225202cull,
0x0a3b393933722520ull,0x33732e706c657309ull,0x3630357225092032ull,0x2c3430357225202cull,
0x202c353035722520ull,0x6d090a3b30397025ull,0x09203233732e766full,0x25202c3531347225ull,
0x2e090a3b36303572ull,0x3309303209636f6cull,0x6c756d090a300931ull,0x203233732e6f6c2eull,
0x202c373035722509ull,0x25202c3230347225ull,0x61090a3b39363272ull,0x09203233732e6464ull,
0x25202c3830357225ull,0x7225202c33303572ull,0x6461090a3b373035ull,0x2509203233752e64ull,
0x7225202c39303572ull,0x357225202c313832ull,0x2e646c090a3b3830ull,0x732e6c61626f6c67ull,
0x3931347225092038ull,0x39303572255b202cull,0x6f6d090a3b5d302bull,0x2509203233732e76ull,
0x7225202c30323472ull,0x6c2e090a3b393134ull,0x323309303209636full,0x2e6c756d090a3009ull,
0x09203233732e6f6cull,0x25202c3031357225ull,0x7225202c35393472ull,0x6461090a3b393632ull,
0x2509203233732e64ull,0x7225202c31313572ull,0x347225202c303135ull,0x646461090a3b3739ull,
0x722509203233752eull,0x357225202c323135ull,0x38327225202c3131ull,0x672e646c090a3b31ull,
0x38732e6c61626f6cull,0x2c34323472250920ull,0x2b32313572255b20ull,0x766f6d090a3b5d30ull,
0x722509203233732eull,0x347225202c353234ull,0x766f6d090a3b3432ull,0x722509203233732eull,
0x0a3b30202c333135ull,0x2e74672e74657309ull,0x203233732e323375ull,0x202c343135722509ull,
0x25202c3432347225ull,0x6e090a3b33313572ull,0x09203233732e6765ull,0x25202c3531357225ull,
0x6d090a3b34313572ull,0x09203233732e766full,0x30202c3631357225ull,0x672e746573090a3bull,
0x33732e3233752e74ull,0x3731357225092032ull,0x2c3931347225202cull,0x0a3b363135722520ull,
0x3233732e67656e09ull,0x2c38313572250920ull,0x0a3b373135722520ull,0x3233622e646e6109ull,
0x2c39313572250920ull,0x202c353135722520ull,0x090a3b3831357225ull,0x203233752e766f6dull,
0x202c303235722509ull,0x70746573090a3b30ull,0x203233732e71652eull,0x25202c3139702509ull,
0x7225202c39313572ull,0x2540090a3b303235ull,0x2061726220313970ull,0x315f305f744c2409ull,
0x200a3b3037353134ull,0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,
0x20656e696c207964ull,0x616568202c383332ull,0x656c6562616c2064ull,0x5f305f744c242064ull,
0x090a383733333331ull,0x09303209636f6c2eull,0x6461090a30093633ull,0x2509203233732e64ull,
0x7225202c31323572ull,0x3b3131202c343333ull,0x33732e726873090aull,0x3232357225092032ull,
0x2c3631337225202cull,0x6c756d090a3b3220ull,0x203233752e6f6c2eull,0x202c333235722509ull,
0x34202c3232357225ull,0x752e646461090a3bull,0x3235722509203233ull,0x3138327225202c34ull,
0x3b3332357225202cull,0x6f6c2e6c756d090aull,0x722509203233752eull,0x357225202c353235ull,
0x090a3b34202c3131ull,0x203233752e646461ull,0x202c363235722509ull,0x25202c3432357225ull,
0x73090a3b35323572ull,0x6c61626f6c672e74ull,0x255b09203233732eull,0x2c5d302b36323572ull,
0x0a3b313235722520ull,0x3233732e766f6d09ull,0x2c30343472250920ull,0x617262090a3b3120ull,
0x4c240920696e752eull,0x323034315f305f74ull,0x5f744c240a3b3039ull,0x3037353134315f30ull,
0x6f6c3c2f2f200a3aull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c38333220656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x37333333315f305full,
0x732e766f6d090a38ull,0x3434722509203233ull,0x62090a3b30202c30ull,0x0920696e752e6172ull,
0x34315f305f744c24ull,0x4c240a3b30393230ull,0x353034315f305f74ull,0x3c2f2f200a3a3634ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x38333220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3333315f305f744cull,0x766f6d090a383733ull,
0x722509203233732eull,0x0a3b30202c303434ull,0x34315f305f744c24ull,0x2f200a3a30393230ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,
0x64616568202c3833ull,0x64656c6562616c20ull,0x315f305f744c2420ull,0x2e090a3837333333ull,
0x3309303209636f6cull,0x726162090a300939ull,0x300920636e79732eull,0x732e766f6d090a3bull,
0x3235722509203233ull,0x73090a3b30202c37ull,0x732e656e2e707465ull,0x3238702509203233ull,
0x2c3034347225202cull,0x0a3b373235722520ull,0x2032387025214009ull,0x744c240920617262ull,
0x32383134315f305full,0x6c3c2f2f200a3b36ull,0x726150203e706f6full,0x6f6f6c20666f2074ull,
0x6c2079646f622070ull,0x2c38333220656e69ull,0x616c206461656820ull,0x4c242064656c6562ull,
0x333333315f305f74ull,0x636f6c2e090a3837ull,0x3009363409303209ull,0x33732e646461090aull,
0x3832357225092032ull,0x2c3433337225202cull,0x6e61090a3b313120ull,0x2509203233622e64ull,
0x7225202c39323572ull,0x0a3b31202c383235ull,0x3233732e76696409ull,0x2c30333572250920ull,
0x202c373933722520ull,0x090a3b3936327225ull,0x203233622e646e61ull,0x202c313335722509ull,
0x31202c3033357225ull,0x2e70746573090a3bull,0x09203233732e7165ull,0x7225202c32397025ull,
0x357225202c393235ull,0x702540090a3b3133ull,0x0920617262203239ull,0x31355f305f744c24ull,
0x2f2f200a3b383534ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x333220656e696c20ull,0x2064616568202c38ull,0x2064656c6562616cull,0x33315f305f744c24ull,
0x6873090a38373333ull,0x2509203233732e72ull,0x7225202c36343472ull,0x0a3b32202c363133ull,
0x2e6f6c2e6c756d09ull,0x3472250920323375ull,0x34347225202c3734ull,0x61090a3b34202c36ull,
0x09203233752e6464ull,0x25202c3834347225ull,0x7225202c37343472ull,0x6f6d090a3b313832ull,
0x2509203233732e76ull,0x7225202c39343472ull,0x6f6d090a3b313134ull,0x2509203233732e76ull,
0x7225202c32333572ull,0x756d090a3b333034ull,0x3233732e6f6c2e6cull,0x2c33333572250920ull,
0x202c323335722520ull,0x090a3b3936327225ull,0x203233732e646461ull,0x202c343335722509ull,
0x25202c3934347225ull,0x6d090a3b33333572ull,0x33752e6f6c2e6c75ull,0x3533357225092032ull,
0x2c3433357225202cull,0x646461090a3b3420ull,0x722509203233752eull,0x347225202c363335ull,
0x33357225202c3834ull,0x672e646c090a3b35ull,0x33732e6c61626f6cull,0x3733357225092032ull,
0x36333572255b202cull,0x6573090a3b5d302bull,0x33732e71652e7074ull,0x2c33397025092032ull,
0x202c373335722520ull,0x090a3b3832357225ull,0x7262203339702540ull,0x305f744c24092061ull,
0x3b3634373935315full,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,
0x6e696c2079646f62ull,0x68202c3833322065ull,0x6562616c20646165ull,0x5f744c242064656cull,
0x3837333333315f30ull,0x33732e766f6d090aull,0x3833357225092032ull,0x3b3531347225202cull,
0x6f6c2e6c756d090aull,0x722509203233732eull,0x357225202c393335ull,0x36327225202c3833ull,
0x2e646461090a3b39ull,0x3572250920323373ull,0x33357225202c3034ull,0x3936327225202c39ull,
0x6c2e6c756d090a3bull,0x2509203233752e6full,0x7225202c31343572ull,0x0a3b34202c303435ull,
0x3233752e62757309ull,0x2c32343572250920ull,0x202c313435722520ull,0x2e646461090a3b34ull,
0x3572250920323373ull,0x33357225202c3334ull,0x3934347225202c39ull,0x6c2e6c756d090a3bull,
0x2509203233752e6full,0x7225202c34343572ull,0x0a3b34202c333435ull,0x3233752e62757309ull,
0x2c35343572250920ull,0x202c343435722520ull,0x2e766f6d090a3b34ull,0x3572250920323373ull,
0x090a3b30202c3634ull,0x2e71652e70746573ull,0x3970250920323373ull,0x3934347225202c34ull,
0x3b3634357225202cull,0x752e706c6573090aull,0x3435722509203233ull,0x3234357225202c37ull,
0x2c3534357225202cull,0x090a3b3439702520ull,0x203233752e646461ull,0x202c383435722509ull,
0x25202c3734357225ull,0x6c090a3b38343472ull,0x6c61626f6c672e64ull,0x722509203233732eull,
0x72255b202c393435ull,0x0a3b5d302b383435ull,0x71652e7074657309ull,0x702509203233732eull,
0x34357225202c3539ull,0x3832357225202c39ull,0x3539702540090a3bull,0x4c24092061726220ull,
0x373935315f305f74ull,0x5f744c240a3b3634ull,0x3a38353431355f30ull,0x6f6f6c3c2f2f200aull,
0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3833322065ull,
0x6562616c20646165ull,0x5f744c242064656cull,0x3837333333315f30ull,0x33732e766f6d090aull,
0x3035357225092032ull,0x7262090a3b31202cull,0x240920696e752e61ull,0x3932355f305f744cull,
0x5f744c240a3b3439ull,0x3634373935315f30ull,0x5f305f744c240a3aull,0x200a3a3431373135ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c383332ull,0x656c6562616c2064ull,0x5f305f744c242064ull,0x090a383733333331ull,
0x203233732e766f6dull,0x202c303535722509ull,0x305f744c240a3b30ull,0x0a3a34393932355full,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c38333220ull,0x6c6562616c206461ull,0x305f744c24206465ull,0x0a3837333333315full,
0x3233732e766f6d09ull,0x2c31353572250920ull,0x746573090a3b3020ull,0x3233732e656e2e70ull,
0x202c323870250920ull,0x25202c3035357225ull,0x4c240a3b31353572ull,0x383134315f305f74ull,
0x3c2f2f200a3a3632ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x38333220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3333315f305f744cull,
0x252140090a383733ull,0x2061726220323870ull,0x315f305f744c2409ull,0x200a3b3833333234ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c383332ull,0x656c6562616c2064ull,0x5f305f744c242064ull,0x090a383733333331ull,
0x09303209636f6c2eull,0x6f6d090a30093435ull,0x2509203233732e76ull,0x7225202c32353572ull,
0x7573090a3b303234ull,0x2509203233732e62ull,0x7225202c33353572ull,0x0a3b31202c323535ull,
0x3233732e766f6d09ull,0x2c34353572250920ull,0x0a3b313134722520ull,0x3233732e766f6d09ull,
0x2c35353572250920ull,0x0a3b333034722520ull,0x2e6f6c2e6c756d09ull,0x3572250920323373ull,
0x35357225202c3635ull,0x3936327225202c35ull,0x732e646461090a3bull,0x3535722509203233ull,
0x3435357225202c37ull,0x3b3635357225202cull,0x33752e646461090aull,0x3835357225092032ull,
0x2c3138327225202cull,0x0a3b373535722520ull,0x626f6c672e747309ull,0x5b092038732e6c61ull,
0x5d302b3835357225ull,0x3b3335357225202cull,0x3209636f6c2e090aull,0x090a300937350930ull,
0x203233732e766f6dull,0x202c393535722509ull,0x090a3b3532347225ull,0x203233732e627573ull,
0x202c303635722509ull,0x31202c3935357225ull,0x732e766964090a3bull,0x3635722509203233ull,
0x3739337225202c31ull,0x3b3936327225202cull,0x6f6c2e6c756d090aull,0x722509203233732eull,
0x327225202c323635ull,0x36357225202c3936ull,0x2e6d6572090a3b31ull,0x3572250920323373ull,
0x39337225202c3336ull,0x3936327225202c37ull,0x732e646461090a3bull,0x3635722509203233ull,
0x3236357225202c34ull,0x3b3336357225202cull,0x33752e646461090aull,0x3536357225092032ull,
0x2c3138327225202cull,0x0a3b343635722520ull,0x626f6c672e747309ull,0x5b092038732e6c61ull,
0x5d302b3536357225ull,0x3b3036357225202cull,0x315f305f744c240aull,0x200a3a3833333234ull,
0x3e706f6f6c3c2f2full,0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,
0x616568202c383332ull,0x656c6562616c2064ull,0x5f305f744c242064ull,0x090a383733333331ull,
0x09303209636f6c2eull,0x6162090a30093136ull,0x0920636e79732e72ull,0x70252140090a3b30ull,
0x0920617262203238ull,0x34315f305f744c24ull,0x2f200a3b30353832ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3833ull,
0x64656c6562616c20ull,0x315f305f744c2420ull,0x2e090a3837333333ull,0x3609303209636f6cull,
0x766f6d090a300934ull,0x722509203233732eull,0x347225202c363635ull,0x6c756d090a3b3531ull,
0x203233732e6f6c2eull,0x202c373635722509ull,0x25202c3636357225ull,0x6d090a3b39363272ull,
0x09203233732e766full,0x25202c3836357225ull,0x61090a3b31313472ull,0x09203233732e6464ull,
0x25202c3936357225ull,0x7225202c38363572ull,0x6461090a3b373635ull,0x2509203233752e64ull,
0x7225202c38383472ull,0x327225202c393635ull,0x2e646c090a3b3138ull,0x732e6c61626f6c67ull,
0x3432687225092038ull,0x38383472255b202cull,0x6461090a3b5d302bull,0x2509203631732e64ull,
0x7225202c35326872ull,0x0a3b31202c343268ull,0x626f6c672e747309ull,0x5b092038732e6c61ull,
0x5d302b3838347225ull,0x3b3532687225202cull,0x3209636f6c2e090aull,0x090a300937360930ull,
0x203233732e6d6572ull,0x202c373934722509ull,0x25202c3739337225ull,0x73090a3b39363272ull,
0x09203233732e6275ull,0x25202c3938347225ull,0x3b31202c39363272ull,0x33732e766964090aull,
0x3539347225092032ull,0x2c3739337225202cull,0x0a3b393632722520ull,0x656e2e7074657309ull,
0x702509203233732eull,0x39347225202c3639ull,0x3938347225202c37ull,0x6c2e6c756d090a3bull,
0x2509203233732e6full,0x7225202c30373572ull,0x327225202c353934ull,0x646461090a3b3936ull,
0x722509203233732eull,0x357225202c313135ull,0x39347225202c3037ull,0x2e646461090a3b37ull,
0x3472250920323375ull,0x31357225202c3139ull,0x73090a3b31202c31ull,0x203233752e706c65ull,
0x202c323934722509ull,0x25202c3139347225ull,0x7025202c30373572ull,0x646461090a3b3639ull,
0x722509203233752eull,0x347225202c333934ull,0x38327225202c3239ull,0x672e646c090a3b31ull,
0x38732e6c61626f6cull,0x2c36326872250920ull,0x2b33393472255b20ull,0x646461090a3b5d30ull,
0x722509203631732eull,0x687225202c373268ull,0x090a3b31202c3632ull,0x61626f6c672e7473ull,
0x255b092038732e6cull,0x2c5d302b33393472ull,0x0a3b373268722520ull,0x34315f305f744c24ull,
0x2f200a3a30353832ull,0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,
0x3220656e696c2079ull,0x64616568202c3833ull,0x64656c6562616c20ull,0x315f305f744c2420ull,
0x2e090a3837333333ull,0x3709303209636f6cull,0x726162090a300931ull,0x300920636e79732eull,
0x09636f6c2e090a3bull,0x3009383031093032ull,0x343770252140090aull,0x4c24092061726220ull,
0x333334315f305f74ull,0x3c2f2f200a3b3236ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,
0x2079646f6220706full,0x38333220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,
0x3333315f305f744cull,0x6f6c2e090a383733ull,0x3331310930320963ull,0x732e646c090a3009ull,
0x33752e6465726168ull,0x3137357225092032ull,0x32333372255b202cull,0x0a3b5d383430322bull,
0x3233752e6d657209ull,0x2c37393372250920ull,0x202c313735722520ull,0x240a3b3631337225ull,
0x3334315f305f744cull,0x2f2f200a3a323633ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x333220656e696c20ull,0x2064616568202c38ull,0x2064656c6562616cull,
0x33315f305f744c24ull,0x6c2e090a38373333ull,0x313109303209636full,0x252140090a300935ull,
0x2061726220353770ull,0x315f305f744c2409ull,0x200a3b3033313434ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c383332ull,
0x656c6562616c2064ull,0x5f305f744c242064ull,0x090a383733333331ull,0x09303209636f6c2eull,
0x6964090a30093832ull,0x2509203233732e76ull,0x7225202c32373572ull,0x327225202c373933ull,
0x627573090a3b3936ull,0x722509203233732eull,0x337225202c393933ull,0x090a3b31202c3531ull,
0x203233732e766f6dull,0x202c333735722509ull,0x70746573090a3b30ull,0x203233732e71652eull,
0x25202c3737702509ull,0x7225202c32373572ull,0x7573090a3b333735ull,0x2509203233732e62ull,
0x7225202c31303472ull,0x0a3b31202c323735ull,0x33732e706c657309ull,0x3230347225092032ull,
0x2c3939337225202cull,0x202c313034722520ull,0x6d090a3b37377025ull,0x09203233732e766full,
0x25202c3330347225ull,0x72090a3b32303472ull,0x09203233732e6d65ull,0x25202c3437357225ull,
0x7225202c37393372ull,0x6e61090a3b393632ull,0x2509203233622e64ull,0x7225202c35373572ull,
0x0a3b31202c323735ull,0x3233752e766f6d09ull,0x2c36373572250920ull,0x746573090a3b3020ull,
0x3233732e71652e70ull,0x202c373970250920ull,0x25202c3537357225ull,0x40090a3b36373572ull,
0x6172622037397025ull,0x5f305f744c240920ull,0x0a3b323436343431ull,0x706f6f6c3c2f2f20ull,
0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,0x6568202c38333220ull,
0x6c6562616c206461ull,0x305f744c24206465ull,0x0a3837333333315full,0x303209636f6c2e09ull,
0x61090a3009393209ull,0x09203233732e6464ull,0x25202c3737357225ull,0x3b31202c34373572ull,
0x33732e766f6d090aull,0x3837357225092032ull,0x7573090a3b30202cull,0x2509203233732e62ull,
0x7225202c39373572ull,0x0a3b31202c393632ull,0x656e2e7074657309ull,0x702509203233732eull,
0x37357225202c3839ull,0x3937357225202c34ull,0x2e706c6573090a3bull,0x3572250920323373ull,
0x37357225202c3038ull,0x3837357225202c37ull,0x0a3b38397025202cull,0x696e752e61726209ull,
0x5f305f744c240920ull,0x0a3b363833343431ull,0x34315f305f744c24ull,0x2f200a3a32343634ull,
0x203e706f6f6c3c2full,0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,
0x64616568202c3833ull,0x64656c6562616c20ull,0x315f305f744c2420ull,0x6d090a3837333333ull,
0x09203233732e766full,0x25202c3038357225ull,0x4c240a3b34373572ull,0x333434315f305f74ull,
0x3c2f2f200a3a3638ull,0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,
0x38333220656e696cull,0x6c2064616568202cull,0x242064656c656261ull,0x3333315f305f744cull,
0x766f6d090a383733ull,0x722509203233732eull,0x357225202c313134ull,0x6f6c2e090a3b3038ull,
0x0930330930320963ull,0x732e646461090a30ull,0x3835722509203233ull,0x3237357225202c31ull,
0x6f6d090a3b31202cull,0x2509203233732e76ull,0x3b30202c32383572ull,0x6e2e70746573090aull,
0x2509203233732e65ull,0x357225202c393970ull,0x39337225202c3237ull,0x706c6573090a3b39ull,
0x722509203233732eull,0x357225202c333835ull,0x38357225202c3138ull,0x3b39397025202c32ull,
0x33732e766f6d090aull,0x3531347225092032ull,0x3b3338357225202cull,0x3209636f6c2e090aull,
0x090a300931330930ull,0x732e6f6c2e6c756dull,0x3835722509203233ull,0x3230347225202c34ull,
0x3b3936327225202cull,0x33732e646461090aull,0x3538357225092032ull,0x2c3038357225202cull,
0x0a3b343835722520ull,0x3233752e64646109ull,0x2c36383572250920ull,0x202c313832722520ull,
0x090a3b3538357225ull,0x61626f6c672e646cull,0x7225092038732e6cull,0x72255b202c393134ull,
0x0a3b5d302b363835ull,0x3233732e766f6d09ull,0x2c30323472250920ull,0x0a3b393134722520ull,
0x303209636f6c2e09ull,0x6d090a3009323309ull,0x33732e6f6c2e6c75ull,0x3738357225092032ull,
0x2c3237357225202cull,0x0a3b393632722520ull,0x3233732e64646109ull,0x2c38383572250920ull,
0x202c373835722520ull,0x090a3b3437357225ull,0x203233752e646461ull,0x202c393835722509ull,
0x25202c3838357225ull,0x6c090a3b31383272ull,0x6c61626f6c672e64ull,0x347225092038732eull,
0x3572255b202c3432ull,0x090a3b5d302b3938ull,0x203233732e766f6dull,0x202c353234722509ull,
0x090a3b3432347225ull,0x203233732e766f6dull,0x202c303935722509ull,0x2e746573090a3b30ull,
0x732e3233752e7467ull,0x3935722509203233ull,0x3432347225202c31ull,0x3b3039357225202cull,
0x33732e67656e090aull,0x3239357225092032ull,0x3b3139357225202cull,0x33732e766f6d090aull,
0x3339357225092032ull,0x6573090a3b30202cull,0x3233752e74672e74ull,0x722509203233732eull,
0x347225202c343935ull,0x39357225202c3931ull,0x2e67656e090a3b33ull,0x3572250920323373ull,
0x39357225202c3539ull,0x2e646e61090a3b34ull,0x3572250920323362ull,0x39357225202c3639ull,
0x3539357225202c32ull,0x752e766f6d090a3bull,0x3935722509203233ull,0x73090a3b30202c37ull,
0x732e71652e707465ull,0x3031702509203233ull,0x3639357225202c30ull,0x3b3739357225202cull,
0x303031702540090aull,0x4c24092061726220ull,0x313534315f305f74ull,0x3c2f2f200a3b3435ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x38333220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3333315f305f744cull,0x6f6c2e090a383733ull,
0x0936330930320963ull,0x732e646461090a30ull,0x3935722509203233ull,0x3433337225202c38ull,
0x73090a3b3331202cull,0x09203233732e7268ull,0x25202c3939357225ull,0x3b32202c36313372ull,
0x6f6c2e6c756d090aull,0x722509203233752eull,0x357225202c303036ull,0x090a3b34202c3939ull,
0x203233752e646461ull,0x202c313036722509ull,0x25202c3138327225ull,0x6d090a3b30303672ull,
0x33752e6f6c2e6c75ull,0x3230367225092032ull,0x2c3838357225202cull,0x646461090a3b3420ull,
0x722509203233752eull,0x367225202c333036ull,0x30367225202c3130ull,0x672e7473090a3b32ull,
0x33732e6c61626f6cull,0x303672255b092032ull,0x7225202c5d302b33ull,0x6f6d090a3b383935ull,
0x2509203233732e76ull,0x3b31202c30343472ull,0x6e752e617262090aull,0x305f744c24092069ull,
0x3b3437383334315full,0x315f305f744c240aull,0x200a3a3435313534ull,0x3e706f6f6c3c2f2full,
0x666f207472615020ull,0x6f6220706f6f6c20ull,0x20656e696c207964ull,0x616568202c383332ull,
0x656c6562616c2064ull,0x5f305f744c242064ull,0x090a383733333331ull,0x203233732e766f6dull,
0x202c303434722509ull,0x2e617262090a3b30ull,0x744c240920696e75ull,0x37383334315f305full,
0x305f744c240a3b34ull,0x3a3033313434315full,0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,
0x20706f6f6c20666full,0x6e696c2079646f62ull,0x68202c3833322065ull,0x6562616c20646165ull,
0x5f744c242064656cull,0x3837333333315f30ull,0x33732e766f6d090aull,0x3034347225092032ull,
0x744c240a3b30202cull,0x37383334315f305full,0x6c3c2f2f200a3a34ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c38333220656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x333333315f305f74ull,0x636f6c2e090a3837ull,0x3009393309303209ull,
0x79732e726162090aull,0x090a3b300920636eull,0x203233732e766f6dull,0x202c343036722509ull,
0x70746573090a3b30ull,0x203233732e656e2eull,0x25202c3238702509ull,0x7225202c30343472ull,
0x2140090a3b343036ull,0x6172622032387025ull,0x5f305f744c240920ull,0x0a3b303134353431ull,
0x706f6f6c3c2f2f20ull,0x6f2074726150203eull,0x6220706f6f6c2066ull,0x656e696c2079646full,
0x6568202c38333220ull,0x6c6562616c206461ull,0x305f744c24206465ull,0x0a3837333333315full,
0x303209636f6c2e09ull,0x61090a3009363409ull,0x09203233732e6464ull,0x25202c3530367225ull,
0x3331202c34333372ull,0x622e646e61090a3bull,0x3036722509203233ull,0x3530367225202c36ull,
0x6964090a3b31202cull,0x2509203233732e76ull,0x7225202c37303672ull,0x327225202c373933ull,
0x646e61090a3b3936ull,0x722509203233622eull,0x367225202c383036ull,0x090a3b31202c3730ull,
0x2e71652e70746573ull,0x3170250920323373ull,0x30367225202c3130ull,0x3830367225202c36ull,
0x3031702540090a3bull,0x2409206172622031ull,0x3139355f305f744cull,0x3c2f2f200a3b3833ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x38333220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3333315f305f744cull,0x726873090a383733ull,
0x722509203233732eull,0x337225202c363434ull,0x090a3b32202c3631ull,0x752e6f6c2e6c756dull,
0x3434722509203233ull,0x3634347225202c37ull,0x6461090a3b34202cull,0x2509203233752e64ull,
0x7225202c38343472ull,0x327225202c373434ull,0x766f6d090a3b3138ull,0x722509203233732eull,
0x347225202c393434ull,0x766f6d090a3b3131ull,0x722509203233732eull,0x347225202c393036ull,
0x6c756d090a3b3330ull,0x203233732e6f6c2eull,0x202c303136722509ull,0x25202c3930367225ull,
0x61090a3b39363272ull,0x09203233732e6464ull,0x25202c3131367225ull,0x7225202c39343472ull,
0x756d090a3b303136ull,0x3233752e6f6c2e6cull,0x2c32313672250920ull,0x202c313136722520ull,
0x2e646461090a3b34ull,0x3672250920323375ull,0x34347225202c3331ull,0x3231367225202c38ull,
0x6c672e646c090a3bull,0x3233732e6c61626full,0x2c34313672250920ull,0x2b33313672255b20ull,
0x746573090a3b5d30ull,0x3233732e71652e70ull,0x2c32303170250920ull,0x202c343136722520ull,
0x090a3b3530367225ull,0x6220323031702540ull,0x5f744c2409206172ull,0x3431353036315f30ull,
0x6f6c3c2f2f200a3bull,0x74726150203e706full,0x706f6f6c20666f20ull,0x696c2079646f6220ull,
0x202c38333220656eull,0x62616c2064616568ull,0x744c242064656c65ull,0x37333333315f305full,
0x732e766f6d090a38ull,0x3136722509203233ull,0x3531347225202c35ull,0x6c2e6c756d090a3bull,
0x2509203233732e6full,0x7225202c36313672ull,0x327225202c353136ull,0x646461090a3b3936ull,
0x722509203233732eull,0x367225202c373136ull,0x36327225202c3631ull,0x2e6c756d090a3b39ull,
0x09203233752e6f6cull,0x25202c3831367225ull,0x3b34202c37313672ull,0x33752e627573090aull,
0x3931367225092032ull,0x2c3831367225202cull,0x646461090a3b3420ull,0x722509203233732eull,
0x367225202c303236ull,0x34347225202c3631ull,0x2e6c756d090a3b39ull,0x09203233752e6f6cull,
0x25202c3132367225ull,0x3b34202c30323672ull,0x33752e627573090aull,0x3232367225092032ull,
0x2c3132367225202cull,0x766f6d090a3b3420ull,0x722509203233732eull,0x0a3b30202c333236ull,
0x71652e7074657309ull,0x702509203233732eull,0x347225202c333031ull,0x32367225202c3934ull,
0x706c6573090a3b33ull,0x722509203233752eull,0x367225202c343236ull,0x32367225202c3931ull,
0x3330317025202c32ull,0x752e646461090a3bull,0x3236722509203233ull,0x3432367225202c35ull,
0x3b3834347225202cull,0x6f6c672e646c090aull,0x203233732e6c6162ull,0x202c363236722509ull,
0x302b35323672255bull,0x70746573090a3b5dull,0x203233732e71652eull,0x202c343031702509ull,
0x25202c3632367225ull,0x40090a3b35303672ull,0x7262203430317025ull,0x305f744c24092061ull,
0x3b3431353036315full,0x355f305f744c240aull,0x2f200a3a38333139ull,0x203e706f6f6c3c2full,
0x20666f2074726150ull,0x646f6220706f6f6cull,0x3220656e696c2079ull,0x64616568202c3833ull,
0x64656c6562616c20ull,0x315f305f744c2420ull,0x6d090a3837333333ull,0x09203233732e766full,
0x31202c3732367225ull,0x752e617262090a3bull,0x5f744c240920696eull,0x3b34373630365f30ull,
0x315f305f744c240aull,0x240a3a3431353036ull,0x3339355f305f744cull,0x3c2f2f200a3a3439ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x38333220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3333315f305f744cull,0x766f6d090a383733ull,
0x722509203233732eull,0x0a3b30202c373236ull,0x30365f305f744c24ull,0x2f2f200a3a343736ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x333220656e696c20ull,
0x2064616568202c38ull,0x2064656c6562616cull,0x33315f305f744c24ull,0x6f6d090a38373333ull,
0x2509203233732e76ull,0x3b30202c38323672ull,0x6e2e70746573090aull,0x2509203233732e65ull,
0x367225202c323870ull,0x32367225202c3732ull,0x305f744c240a3b38ull,0x3a3031343534315full,
0x6f6f6c3c2f2f200aull,0x2074726150203e70ull,0x20706f6f6c20666full,0x6e696c2079646f62ull,
0x68202c3833322065ull,0x6562616c20646165ull,0x5f744c242064656cull,0x3837333333315f30ull,
0x323870252140090aull,0x4c24092061726220ull,0x393534315f305f74ull,0x3c2f2f200a3b3232ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x38333220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3333315f305f744cull,0x6f6c2e090a383733ull,
0x0934350930320963ull,0x732e766f6d090a30ull,0x3236722509203233ull,0x3032347225202c39ull,
0x732e627573090a3bull,0x3336722509203233ull,0x3932367225202c30ull,0x6f6d090a3b31202cull,
0x2509203233732e76ull,0x7225202c31333672ull,0x6f6d090a3b313134ull,0x2509203233732e76ull,
0x7225202c32333672ull,0x756d090a3b333034ull,0x3233732e6f6c2e6cull,0x2c33333672250920ull,
0x202c323336722520ull,0x090a3b3936327225ull,0x203233732e646461ull,0x202c343336722509ull,
0x25202c3133367225ull,0x61090a3b33333672ull,0x09203233752e6464ull,0x25202c3533367225ull,
0x7225202c31383272ull,0x7473090a3b343336ull,0x2e6c61626f6c672eull,0x3672255b09203873ull,
0x25202c5d302b3533ull,0x2e090a3b30333672ull,0x3509303209636f6cull,0x766f6d090a300937ull,
0x722509203233732eull,0x347225202c363336ull,0x627573090a3b3532ull,0x722509203233732eull,
0x367225202c373336ull,0x090a3b31202c3633ull,0x203233732e766964ull,0x202c383336722509ull,
0x25202c3739337225ull,0x6d090a3b39363272ull,0x33732e6f6c2e6c75ull,0x3933367225092032ull,
0x2c3936327225202cull,0x0a3b383336722520ull,0x3233732e6d657209ull,0x2c30343672250920ull,
0x202c373933722520ull,0x090a3b3936327225ull,0x203233732e646461ull,0x202c313436722509ull,
0x25202c3933367225ull,0x61090a3b30343672ull,0x09203233752e6464ull,0x25202c3234367225ull,
0x7225202c31383272ull,0x7473090a3b313436ull,0x2e6c61626f6c672eull,0x3672255b09203873ull,
0x25202c5d302b3234ull,0x4c240a3b37333672ull,0x393534315f305f74ull,0x3c2f2f200a3a3232ull,
0x6150203e706f6f6cull,0x6f6c20666f207472ull,0x2079646f6220706full,0x38333220656e696cull,
0x6c2064616568202cull,0x242064656c656261ull,0x3333315f305f744cull,0x6f6c2e090a383733ull,
0x0931360930320963ull,0x732e726162090a30ull,0x0a3b300920636e79ull,0x2032387025214009ull,
0x744c240920617262ull,0x33343634315f305full,0x6c3c2f2f200a3b34ull,0x726150203e706f6full,
0x6f6f6c20666f2074ull,0x6c2079646f622070ull,0x2c38333220656e69ull,0x616c206461656820ull,
0x4c242064656c6562ull,0x333333315f305f74ull,0x636f6c2e090a3837ull,0x3009343609303209ull,
0x33732e766f6d090aull,0x3334367225092032ull,0x3b3531347225202cull,0x6f6c2e6c756d090aull,
0x722509203233732eull,0x367225202c343436ull,0x36327225202c3334ull,0x2e766f6d090a3b39ull,
0x3672250920323373ull,0x31347225202c3534ull,0x2e646461090a3b31ull,0x3672250920323373ull,
0x34367225202c3634ull,0x3434367225202c35ull,0x752e646461090a3bull,0x3834722509203233ull,
0x3634367225202c38ull,0x3b3138327225202cull,0x6f6c672e646c090aull,0x092038732e6c6162ull,
0x5b202c3832687225ull,0x5d302b3838347225ull,0x732e646461090a3bull,0x3268722509203631ull,
0x3832687225202c39ull,0x7473090a3b31202cull,0x2e6c61626f6c672eull,0x3472255b09203873ull,
0x25202c5d302b3838ull,0x2e090a3b39326872ull,0x3609303209636f6cull,0x6d6572090a300937ull,
0x722509203233732eull,0x337225202c343735ull,0x36327225202c3739ull,0x2e627573090a3b39ull,
0x3472250920323373ull,0x36327225202c3938ull,0x64090a3b31202c39ull,0x09203233732e7669ull,
0x25202c3237357225ull,0x7225202c37393372ull,0x6573090a3b393632ull,0x33732e656e2e7074ull,
0x3530317025092032ull,0x2c3437357225202cull,0x0a3b393834722520ull,0x2e6f6c2e6c756d09ull,
0x3672250920323373ull,0x37357225202c3734ull,0x3936327225202c32ull,0x732e646461090a3bull,
0x3835722509203233ull,0x3734367225202c38ull,0x3b3437357225202cull,0x33752e646461090aull,
0x3139347225092032ull,0x2c3838357225202cull,0x6c6573090a3b3120ull,0x2509203233752e70ull,
0x7225202c32393472ull,0x367225202c313934ull,0x30317025202c3734ull,0x2e646461090a3b35ull,
0x3472250920323375ull,0x39347225202c3339ull,0x3138327225202c32ull,0x6c672e646c090a3bull,
0x2038732e6c61626full,0x202c303368722509ull,0x302b33393472255bull,0x2e646461090a3b5dull,
0x6872250920363173ull,0x33687225202c3133ull,0x73090a3b31202c30ull,0x6c61626f6c672e74ull,
0x72255b092038732eull,0x202c5d302b333934ull,0x240a3b3133687225ull,0x3634315f305f744cull,
0x2f2f200a3a343334ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,
0x333220656e696c20ull,0x2064616568202c38ull,0x2064656c6562616cull,0x33315f305f744c24ull,
0x6c2e090a38373333ull,0x313709303209636full,0x2e726162090a3009ull,0x3b300920636e7973ull,
0x3209636f6c2e090aull,0x0a30093531310930ull,0x3233732e64646109ull,0x2c34333372250920ull,
0x202c343333722520ull,0x6573090a3b323133ull,0x33732e74672e7074ull,0x3630317025092032ull,
0x2c3231337225202cull,0x0a3b343333722520ull,0x2036303170254009ull,0x744c240920617262ull,
0x37333333315f305full,0x2e617262090a3b38ull,0x744c240920696e75ull,0x36383233315f305full,
0x305f744c240a3b36ull,0x3a3636343835315full,0x33752e646461090aull,0x3233337225092032ull,
0x2c3537327225202cull,0x0a3b313033722520ull,0x33315f305f744c24ull,0x2e090a3a36363832ull,
0x3209303209636f6cull,0x7573090a30093933ull,0x2509203233732e62ull,0x7225202c38343672ull,
0x0a3b31202c323732ull,0x3233752e766f6d09ull,0x2c39343672250920ull,0x746573090a3b3020ull,
0x3233732e746c2e70ull,0x2c37303170250920ull,0x202c383436722520ull,0x090a3b3934367225ull,
0x203233732e766f6dull,0x202c303536722509ull,0x2e766f6d090a3b30ull,0x3166250920323366ull,
0x303030306630202cull,0x2020203b30303030ull,0x0a30202f2f092020ull,0x2037303170254009ull,
0x744c240920617262ull,0x32303136315f305full,0x2e766f6d090a3b36ull,0x3672250920323373ull,
0x37327225202c3135ull,0x2e646461090a3b32ull,0x3272250920323373ull,0x37327225202c3737ull,
0x3637327225202c31ull,0x6c2e6c756d090a3bull,0x2509203233752e6full,0x7225202c38373272ull,
0x337225202c373732ull,0x6c2e6c756d090a3bull,0x2509203233752e6full,0x7225202c39373272ull,
0x0a3b34202c383732ull,0x617261702e646c09ull,0x2509203233752e6dull,0x5f5b202c32353672ull,
0x726170616475635full,0x655034315a5f5f6dull,0x654b74656e697274ull,0x665069506c656e72ull,
0x3231506969695f53ull,0x645f69667570675full,0x765f5f5f5f617461ull,0x6d617261705f6c61ull,
0x61090a3b5d735f67ull,0x09203233752e6464ull,0x25202c3138327225ull,0x7225202c32353672ull,
0x6f6d090a3b393732ull,0x2509203233732e76ull,0x3b30202c33353672ull,0x33732e766f6d090aull,
0x3435367225092032ull,0x3b3135367225202cull,0x315f305f744c240aull,0x200a3a3431373734ull,
0x3e706f6f6c3c2f2full,0x6f6220706f6f4c20ull,0x20656e696c207964ull,0x73656e202c393332ull,
0x70656420676e6974ull,0x65202c31203a6874ull,0x646574616d697473ull,0x6974617265746920ull,
0x6b6e75203a736e6full,0x6c2e090a6e776f6eull,0x333109303209636full,0x6c6873090a300935ull,
0x722509203233622eull,0x367225202c353536ull,0x090a3b38202c3335ull,0x752e6f6c2e6c756dull,
0x3536722509203233ull,0x3535367225202c36ull,0x6461090a3b34202cull,0x2509203233752e64ull,
0x7225202c37353672ull,0x367225202c353732ull,0x646461090a3b3635ull,0x722509203233752eull,
0x327225202c383536ull,0x35367225202c3138ull,0x672e646c090a3b37ull,0x33732e6c61626f6cull,
0x3935367225092032ull,0x38353672255b202cull,0x6c2e090a3b5d302bull,0x333109303209636full,
0x646e61090a300937ull,0x722509203233622eull,0x367225202c303636ull,0x3b353532202c3935ull,
0x6f6c2e6c756d090aull,0x722509203233732eull,0x367225202c313636ull,0x36367225202c3036ull,
0x2e747663090a3b30ull,0x732e3233662e6e72ull,0x2c32662509203233ull,0x0a3b313636722520ull,
0x3233662e64646109ull,0x25202c3166250920ull,0x3b316625202c3266ull,0x3209636f6c2e090aull,
0x0a30093833310930ull,0x3233732e78616d09ull,0x2c30353672250920ull,0x202c303636722520ull,
0x090a3b3035367225ull,0x09303209636f6c2eull,0x73090a3009303431ull,0x09203233732e7268ull,
0x25202c3236367225ull,0x3b38202c39353672ull,0x33622e646e61090aull,0x3336367225092032ull,
0x2c3236367225202cull,0x6d090a3b35353220ull,0x33732e6f6c2e6c75ull,0x3436367225092032ull,
0x2c3336367225202cull,0x0a3b333636722520ull,0x2e6e722e74766309ull,0x203233732e323366ull,
0x7225202c33662509ull,0x6461090a3b343636ull,0x2509203233662e64ull,0x2c336625202c3166ull,
0x2e090a3b31662520ull,0x3109303209636f6cull,0x616d090a30093134ull,0x2509203233732e78ull,
0x7225202c30353672ull,0x367225202c333636ull,0x6f6c2e090a3b3035ull,0x3334310930320963ull,
0x2e726873090a3009ull,0x3672250920323373ull,0x35367225202c3536ull,0x090a3b3631202c39ull,
0x203233622e646e61ull,0x202c363636722509ull,0x32202c3536367225ull,0x6c756d090a3b3535ull,
0x203233732e6f6c2eull,0x202c373636722509ull,0x25202c3636367225ull,0x63090a3b36363672ull,
0x33662e6e722e7476ull,0x2509203233732e32ull,0x36367225202c3466ull,0x2e646461090a3b37ull,
0x3166250920323366ull,0x25202c346625202cull,0x6f6c2e090a3b3166ull,0x3434310930320963ull,
0x2e78616d090a3009ull,0x3672250920323373ull,0x36367225202c3035ull,0x3035367225202c36ull,
0x09636f6c2e090a3bull,0x3009363431093032ull,0x33732e726873090aull,0x3836367225092032ull,
0x2c3935367225202cull,0x6e61090a3b343220ull,0x2509203233622e64ull,0x7225202c39363672ull,
0x353532202c383636ull,0x6c2e6c756d090a3bull,0x2509203233732e6full,0x7225202c30373672ull,
0x367225202c393636ull,0x747663090a3b3936ull,0x2e3233662e6e722eull,0x3566250920323373ull,
0x3b3037367225202cull,0x33662e646461090aull,0x202c316625092032ull,0x316625202c356625ull,
0x09636f6c2e090a3bull,0x3009373431093032ull,0x33732e78616d090aull,0x3035367225092032ull,
0x2c3936367225202cull,0x0a3b303536722520ull,0x3233732e64646109ull,0x2c33353672250920ull,
0x202c333536722520ull,0x70746573090a3b31ull,0x203233732e656e2eull,0x202c383031702509ull,
0x25202c3237327225ull,0x40090a3b33353672ull,0x7262203830317025ull,0x305f744c24092061ull,
0x3b3431373734315full,0x6e752e617262090aull,0x305f744c24092069ull,0x3b3230323734315full,
0x315f305f744c240aull,0x240a3a3632303136ull,0x3734315f305f744cull,0x6e61090a3a323032ull,
0x2509203233622e64ull,0x7225202c31373672ull,0x353532202c363732ull,0x752e627573090a3bull,
0x3736722509203233ull,0x3137367225202c32ull,0x6573090a3b31202cull,0x33752e74672e7074ull,
0x3930317025092032ull,0x25202c347225202cull,0x40090a3b32373672ull,0x7262203930317025ull,
0x305f744c24092061ull,0x3b3632323834315full,0x3209636f6c2e090aull,0x0a30093635310930ull,
0x617261702e646c09ull,0x2509203233752e6dull,0x5f5b202c33373672ull,0x726170616475635full,
0x655034315a5f5f6dull,0x654b74656e697274ull,0x665069506c656e72ull,0x3231506969695f53ull,
0x645f69667570675full,0x765f5f5f5f617461ull,0x6d617261705f6c61ull,0x61090a3b5d735f67ull,
0x09203233732e6464ull,0x25202c3437367225ull,0x7225202c31373272ull,0x756d090a3b363732ull,
0x3233752e6f6c2e6cull,0x2c35373672250920ull,0x7225202c33722520ull,0x756d090a3b343736ull,
0x3233752e6f6c2e6cull,0x2c36373672250920ull,0x202c353736722520ull,0x2e646461090a3b34ull,
0x3672250920323375ull,0x37367225202c3737ull,0x3637367225202c33ull,0x6c2e6c756d090a3bull,
0x2509203233732e6full,0x7225202c38373672ull,0x363532202c323732ull,0x752e646461090a3bull,
0x3736722509203233ull,0x202c347225202c39ull,0x090a3b3837367225ull,0x752e6f6c2e6c756dull,
0x3836722509203233ull,0x3937367225202c30ull,0x6461090a3b34202cull,0x2509203233752e64ull,
0x7225202c31383672ull,0x367225202c373736ull,0x2e646c090a3b3038ull,0x732e6c61626f6c67ull,
0x3836722509203233ull,0x383672255b202c32ull,0x2e090a3b5d302b31ull,0x3109303209636f6cull,
0x6e61090a30093835ull,0x2509203233622e64ull,0x7225202c33383672ull,0x353532202c323836ull,
0x6c2e6c756d090a3bull,0x2509203233732e6full,0x7225202c34383672ull,0x367225202c333836ull,
0x747663090a3b3338ull,0x2e3233662e6e722eull,0x3666250920323373ull,0x3b3438367225202cull,
0x33662e646461090aull,0x202c316625092032ull,0x316625202c366625ull,0x09636f6c2e090a3bull,
0x3009393531093032ull,0x33732e78616d090aull,0x3035367225092032ull,0x2c3338367225202cull,
0x0a3b303536722520ull,0x303209636f6c2e09ull,0x090a300931363109ull,0x203233732e726873ull,
0x202c353836722509ull,0x38202c3238367225ull,0x622e646e61090a3bull,0x3836722509203233ull,
0x3538367225202c36ull,0x090a3b353532202cull,0x732e6f6c2e6c756dull,0x3836722509203233ull,
0x3638367225202c37ull,0x3b3638367225202cull,0x6e722e747663090aull,0x3233732e3233662eull,
0x25202c3766250920ull,0x61090a3b37383672ull,0x09203233662e6464ull,0x376625202c316625ull,
0x090a3b316625202cull,0x09303209636f6c2eull,0x6d090a3009323631ull,0x09203233732e7861ull,
0x25202c3035367225ull,0x7225202c36383672ull,0x6c2e090a3b303536ull,0x363109303209636full,
0x726873090a300934ull,0x722509203233732eull,0x367225202c383836ull,0x0a3b3631202c3238ull,
0x3233622e646e6109ull,0x2c39383672250920ull,0x202c383836722520ull,0x756d090a3b353532ull,
0x3233732e6f6c2e6cull,0x2c30393672250920ull,0x202c393836722520ull,0x090a3b3938367225ull,
0x662e6e722e747663ull,0x09203233732e3233ull,0x367225202c386625ull,0x646461090a3b3039ull,
0x662509203233662eull,0x202c386625202c31ull,0x6c2e090a3b316625ull,0x363109303209636full,
0x78616d090a300935ull,0x722509203233732eull,0x367225202c303536ull,0x35367225202c3938ull,
0x636f6c2e090a3b30ull,0x0937363109303209ull,0x732e726873090a30ull,0x3936722509203233ull,
0x3238367225202c31ull,0x61090a3b3432202cull,0x09203233622e646eull,0x25202c3239367225ull,
0x3532202c31393672ull,0x2e6c756d090a3b35ull,0x09203233732e6f6cull,0x25202c3339367225ull,
0x7225202c32393672ull,0x7663090a3b323936ull,0x3233662e6e722e74ull,0x662509203233732eull,
0x3339367225202c39ull,0x662e646461090a3bull,0x2c31662509203233ull,0x6625202c39662520ull,
0x636f6c2e090a3b31ull,0x0938363109303209ull,0x732e78616d090a30ull,0x3536722509203233ull,
0x3239367225202c30ull,0x3b3035367225202cull,0x315f305f744c240aull,0x090a3a3632323834ull,
0x09303209636f6c2eull,0x73090a3009303731ull,0x6465726168732e74ull,0x255b09203233662eull,
0x2c5d302b32333372ull,0x2e090a3b31662520ull,0x3109303209636f6cull,0x7473090a30093137ull,
0x2e6465726168732eull,0x72255b0920323375ull,0x343230312b323333ull,0x3035367225202c5dull,
0x09636f6c2e090a3bull,0x3009323731093032ull,0x79732e726162090aull,0x090a3b300920636eull,
0x203233732e766f6dull,0x202c333536722509ull,0x744c240a3b383231ull,0x35323934315f305full,
0x6c3c2f2f200a3a30ull,0x6f6f4c203e706f6full,0x6c2079646f622070ull,0x2c32373120656e69ull,
0x676e697473656e20ull,0x203a687470656420ull,0x6d69747365202c31ull,0x6574692064657461ull,
0x3a736e6f69746172ull,0x6e776f6e6b6e7520ull,0x6c2e70746573090aull,0x2509203233752e65ull,
0x7225202c30313170ull,0x347225202c333536ull,0x3131702540090a3bull,0x2409206172622030ull,
0x3035315f305f744cull,0x2f2f200a3b383130ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x373120656e696c20ull,0x2064616568202c32ull,0x2064656c6562616cull,
0x34315f305f744c24ull,0x6c2e090a30353239ull,0x373109303209636full,0x646461090a300937ull,
0x722509203233752eull,0x367225202c343936ull,0x3b347225202c3335ull,0x6f6c2e6c756d090aull,
0x722509203233752eull,0x367225202c353936ull,0x090a3b34202c3439ull,0x203233752e646461ull,
0x202c363936722509ull,0x25202c3539367225ull,0x6c090a3b31303372ull,0x6465726168732e64ull,
0x662509203233662eull,0x3672255b202c3031ull,0x090a3b5d302b3639ull,0x65726168732e646cull,
0x2509203233662e64ull,0x72255b202c313166ull,0x0a3b5d302b323333ull,0x3233662e64646109ull,
0x202c323166250920ull,0x6625202c30316625ull,0x2e7473090a3b3131ull,0x662e646572616873ull,
0x3372255b09203233ull,0x25202c5d302b3233ull,0x646c090a3b323166ull,0x2e6465726168732eull,
0x3672250920323375ull,0x3672255b202c3739ull,0x5d343230312b3639ull,0x68732e646c090a3bull,
0x3233752e64657261ull,0x2c38393672250920ull,0x2b32333372255b20ull,0x090a3b5d34323031ull,
0x2e65672e70746573ull,0x3170250920323375ull,0x39367225202c3131ull,0x3739367225202c38ull,
0x3131702540090a3bull,0x2409206172622031ull,0x3035315f305f744cull,0x2f2f200a3b383130ull,
0x50203e706f6f6c3cull,0x6c20666f20747261ull,0x79646f6220706f6full,0x373120656e696c20ull,
0x2064616568202c32ull,0x2064656c6562616cull,0x34315f305f744c24ull,0x6c2e090a30353239ull,
0x383109303209636full,0x2e7473090a300930ull,0x752e646572616873ull,0x3372255b09203233ull,
0x5d343230312b3233ull,0x3b3739367225202cull,0x315f305f744c240aull,0x240a3a3831303035ull,
0x3934315f305f744cull,0x2f2f200a3a363035ull,0x50203e706f6f6c3cull,0x6c20666f20747261ull,
0x79646f6220706f6full,0x373120656e696c20ull,0x2064616568202c32ull,0x2064656c6562616cull,
0x34315f305f744c24ull,0x6c2e090a30353239ull,0x383109303209636full,0x726162090a300933ull,
0x300920636e79732eull,0x09636f6c2e090a3bull,0x3009333731093032ull,0x33732e726873090aull,
0x3335367225092032ull,0x2c3335367225202cull,0x766f6d090a3b3120ull,0x722509203233752eull,
0x0a3b30202c393936ull,0x74672e7074657309ull,0x702509203233732eull,0x367225202c323131ull,
0x39367225202c3335ull,0x31702540090a3b39ull,0x0920617262203231ull,0x34315f305f744c24ull,
0x40090a3b30353239ull,0x7262203836702521ull,0x305f744c24092061ull,0x3b3638373035315full,
0x3209636f6c2e090aull,0x0a30093738310930ull,0x6c2e34326c756d09ull,0x2509203233752e6full,
0x7225202c30303772ull,0x6c090a3b34202c33ull,0x6465726168732e64ull,0x662509203233662eull,
0x2b746d5b202c3331ull,0x747663090a3b5d30ull,0x2e3233662e6e722eull,0x3166250920323373ull,
0x3137327225202c34ull,0x662e766964090a3bull,0x203233662e6c6c75ull,0x25202c3531662509ull,
0x316625202c333166ull,0x2e766f6d090a3b34ull,0x3166250920323366ull,0x3866626630202c36ull,
0x20203b3030303030ull,0x312d202f2f092020ull,0x33662e646461090aull,0x2c37316625092032ull,
0x25202c3531662520ull,0x646c090a3b363166ull,0x752e6d617261702eull,0x3037722509203233ull,
0x75635f5f5b202c31ull,0x5f5f6d7261706164ull,0x697274655034315aull,0x656e72654b74656eull,
0x695f53665069506cull,0x70675f3231506969ull,0x617461645f696675ull,0x5f6c61765f5f5f5full,
0x765f676d61726170ull,0x2e646461090a3b5dull,0x3772250920323375ull,0x30377225202c3230ull,
0x3030377225202c31ull,0x6c672e7473090a3bull,0x3233662e6c61626full,0x32303772255b0920ull,
0x316625202c5d302bull,0x636f6c2e090a3b37ull,0x0930393109303209ull,0x68732e646c090a30ull,
0x3233732e64657261ull,0x2c33303772250920ull,0x3230312b746d5b20ull,0x2e646c090a3b5d34ull,
0x33752e6d61726170ull,0x3430377225092032ull,0x6475635f5f5b202cull,0x5a5f5f6d72617061ull,
0x6e69727465503431ull,0x6c656e72654b7465ull,0x69695f5366506950ull,0x7570675f32315069ull,
0x5f617461645f6966ull,0x705f6c61765f5f5full,0x5d6d5f676d617261ull,0x752e646461090a3bull,
0x3037722509203233ull,0x3430377225202c35ull,0x3b3030377225202cull,0x6f6c672e7473090aull,
0x203233732e6c6162ull,0x2b35303772255b09ull,0x30377225202c5d30ull,0x305f744c240a3b33ull,
0x3a3638373035315full,0x3209636f6c2e090aull,0x0a30093134320930ull,0x240a3b7469786509ull,
0x5f5f646e6557444cull,0x697274655034315aull,0x656e72654b74656eull,0x695f53665069506cull,
0x70675f3231506969ull,0x617461645f696675ull,0x2f2f207d090a3a5full,0x74655034315a5f20ull,
0x72654b74656e6972ull,0x53665069506c656eull,0x5f3231506969695full,0x61645f6966757067ull,
0x0000000a0a5f6174ull
};


}



extern "C" {


static const unsigned long long __deviceText_$sm_11$[] = {
0x6365746968637261ull,0x6d737b2065727574ull,0x6962610a7d31315full,0x206e6f6973726576ull,
0x6f6d0a7d317b2020ull,0x202020656d616e64ull,0x696275637b202020ull,0x636f6c65720a7d6eull,
0x6d616e09090a7b20ull,0x67203d2020202065ull,0x7665645f69667570ull,0x616e67657309090aull,
0x6c6572203d20656dull,0x67657309090a636full,0x31203d20206d756eull,0x7366666f09090a34ull,
0x0a30203d20207465ull,0x2073657479620909ull,0x0a7d0a34203d2020ull,0x7b207374736e6f63ull,
0x20656d616e09090aull,0x635f5f203d202020ull,0x34746e6174736e6full,0x67657309090a3738ull,
0x63203d20656d616eull,0x7309090a74736e6full,0x3d20206d756e6765ull,0x66666f09090a3020ull,
0x33203d2020746573ull,0x6574796209090a33ull,0x0a34203d20202073ull,0x090a7b206d656d09ull,
0x3533373030783009ull,0x0a7d090a20373666ull,0x7374736e6f630a7dull,0x6d616e09090a7b20ull,
0x5f203d2020202065ull,0x6e6174736e6f635full,0x7309090a36383474ull,0x3d20656d616e6765ull,
0x090a74736e6f6320ull,0x206d756e67657309ull,0x6f09090a30203d20ull,0x3d20207465736666ull,
0x74796209090a3020ull,0x31203d2020207365ull,0x7b206d656d090a35ull,0x373237783009090aull,
0x7830203035353634ull,0x3936653635363437ull,0x3632376536783020ull,0x3030783020623435ull,
0x0a20353663363030ull,0x6e6f630a7d0a7d09ull,0x09090a7b20737473ull,0x20202020656d616eull,
0x736e6f635f5f203dull,0x0a343934746e6174ull,0x6d616e6765730909ull,0x736e6f63203d2065ull,
0x6e67657309090a74ull,0x0a30203d20206d75ull,0x74657366666f0909ull,0x090a3432203d2020ull,
0x2020736574796209ull,0x656d090a39203d20ull,0x783009090a7b206dull,0x3736663530376336ull,
0x3635363337783020ull,0x3030783020313633ull,0x0a20303030303030ull,0x6e6f630a7d0a7d09ull,
0x09090a7b20737473ull,0x20202020656d616eull,0x736e6f635f5f203dull,0x0a333934746e6174ull,
0x6d616e6765730909ull,0x736e6f63203d2065ull,0x6e67657309090a74ull,0x0a30203d20206d75ull,
0x74657366666f0909ull,0x090a3531203d2020ull,0x2020736574796209ull,0x656d090a39203d20ull,
0x783009090a7b206dull,0x6534333531353535ull,0x3535343233783020ull,0x3030783020313432ull,
0x0a20303030303030ull,0x6e6f630a7d0a7d09ull,0x09090a7b20737473ull,0x20202020656d616eull,
0x736e6f635f5f203dull,0x0a323934746e6174ull,0x6d616e6765730909ull,0x736e6f63203d2065ull,
0x6e67657309090a74ull,0x0a30203d20206d75ull,0x74657366666f0909ull,0x090a3934203d2020ull,
0x2020736574796209ull,0x656d090a35203d20ull,0x783009090a7b206dull,0x3337353635363436ull,
0x3030303030783020ull,0x0a7d090a20303030ull,0x7374736e6f630a7dull,0x6d616e09090a7b20ull,
0x5f203d2020202065ull,0x6e6174736e6f635full,0x7309090a31393474ull,0x3d20656d616e6765ull,
0x090a74736e6f6320ull,0x206d756e67657309ull,0x6f09090a30203d20ull,0x3d20207465736666ull,
0x796209090a373420ull,0x203d202020736574ull,0x7b206d656d090a32ull,0x303030783009090aull,
0x090a203337303030ull,0x736e6f630a7d0a7dull,0x6e09090a7b207374ull,0x3d20202020656d61ull,
0x74736e6f635f5f20ull,0x090a303934746e61ull,0x656d616e67657309ull,0x74736e6f63203d20ull,
0x756e67657309090aull,0x090a30203d20206dull,0x2074657366666f09ull,0x09090a3534203d20ull,
0x2020207365747962ull,0x6d656d090a32203dull,0x30783009090a7b20ull,0x2065363030303030ull,
0x6f630a7d0a7d090aull,0x090a7b207374736eull,0x202020656d616e09ull,0x6e6f635f5f203d20ull,
0x393834746e617473ull,0x616e67657309090aull,0x6e6f63203d20656dull,0x67657309090a7473ull,
0x30203d20206d756eull,0x657366666f09090aull,0x0a3134203d202074ull,0x2073657479620909ull,
0x6d090a34203d2020ull,0x3009090a7b206d65ull,0x3666356436303078ull,0x0a7d0a7d090a2037ull,
0x7b207374736e6f63ull,0x20656d616e09090aull,0x635f5f203d202020ull,0x34746e6174736e6full,
0x67657309090a3838ull,0x63203d20656d616eull,0x7309090a74736e6full,0x3d20206d756e6765ull,
0x66666f09090a3020ull,0x33203d2020746573ull,0x6574796209090a37ull,0x0a34203d20202073ull,
0x090a7b206d656d09ull,0x3536373030783009ull,0x0a7d090a20373666ull,0x7b2065646f630a7dull,
0x3d20656d616e090aull,0x74655034315a5f20ull,0x72654b74656e6972ull,0x53665069506c656eull,
0x5f3231506969695full,0x61645f6966757067ull,0x656d6c090a5f6174ull,0x73090a30203d206dull,
0x3532203d206d656dull,0x20676572090a3034ull,0x62090a3033203d20ull,0x0a31203d20207261ull,
0x7b2074736e6f6309ull,0x6e6765730909090aull,0x6f63203d20656d61ull,0x730909090a74736eull,
0x3d20206d756e6765ull,0x666f0909090a3120ull,0x203d202074657366ull,0x7479620909090a30ull,
0x31203d2020207365ull,0x6d656d09090a3631ull,0x78300909090a7b20ull,0x3130303030303030ull,
0x3030303030783020ull,0x3030783020393030ull,0x3020663130303030ull,0x3430303030303078ull,
0x78300909090a2030ull,0x3434303030303030ull,0x3030303030783020ull,0x3030783020383430ull,
0x3020633430303030ull,0x3430303030303078ull,0x78300909090a2065ull,0x3035303030303030ull,
0x3030303030783020ull,0x3030783020653230ull,0x3020373330303030ull,0x6539303030303078ull,
0x78300909090a2063ull,0x3265303030303030ull,0x3030303030783020ull,0x3030783020303031ull,
0x3020663630303030ull,0x3730303030303078ull,0x78300909090a2030ull,0x6536323030303030ull,
0x3030303038783020ull,0x6637783020303030ull,0x3020666666666666ull,0x6430623830393978ull,
0x78300909090a2066ull,0x3038363563326439ull,0x3036636665783020ull,0x6666783020303030ull,
0x3020636666666666ull,0x6666666666666678ull,0x78300909090a2066ull,0x6666303030303030ull,
0x3030386537783020ull,0x6662783020303030ull,0x3020303030303038ull,0x3232666666666678ull,
0x78300909090a2038ull,0x3030303030386533ull,0x7d090a7d09090a20ull,0x646f636e6962090aull,
0x783009090a7b2065ull,0x3930346638323132ull,0x3030303030783020ull,0x3064783020373030ull,
0x3020393034306530ull,0x3837303063303878ull,0x61783009090a2030ull,0x2031316334303030ull,
0x3730303234307830ull,0x3030337830203038ull,0x7830203930343034ull,0x3064373431303436ull,
0x3061783009090a20ull,0x3020646635303030ull,0x6337343130633078ull,0x3030306178302038ull,
0x3078302033303066ull,0x2030303030303030ull,0x303061783009090aull,0x7830203135303030ull,
0x3038373030303430ull,0x6330303031783020ull,0x3030783020333030ull,0x0a20303832313030ull,
0x6332313278300909ull,0x3078302031303466ull,0x2037303030303030ull,0x3030653030647830ull,
0x6330387830203130ull,0x090a203038373030ull,0x3034313033783009ull,0x3436783020646631ull,
0x3020386437383030ull,0x3030653030303178ull,0x3030303078302033ull,0x09090a2030383231ull,
0x3038313030317830ull,0x3030307830203130ull,0x7830203330303030ull,0x3330306630303031ull,
0x3030303030783020ull,0x3009090a20303837ull,0x3038663030303178ull,0x3330343078302031ull,
0x3378302030383763ull,0x2064663130633730ull,0x3734313063367830ull,0x783009090a206164ull,
0x3330306236303061ull,0x3030303030783020ull,0x3031783020303030ull,0x3020333030623630ull,
0x3832313030303078ull,0x32783009090a2030ull,0x2031303466303231ull,0x3030303030307830ull,
0x3030647830203330ull,0x7830203130303065ull,0x3038373030633038ull,0x3033783009090a20ull,
0x3020646631303038ull,0x6437343134633678ull,0x3630303178302038ull,0x3078302033303062ull,
0x2030383231303030ull,0x303132783009090aull,0x7830203130346630ull,0x3330303130303030ull,
0x3838323032783020ull,0x6630783020393030ull,0x0a20333266666666ull,0x6530306478300909ull,
0x3878302039303430ull,0x2030383730303230ull,0x3930303030617830ull,0x3063307830206466ull,
0x090a203863373831ull,0x3030303132783009ull,0x3430783020643030ull,0x3020303035633634ull,
0x3130303030303178ull,0x3034303278302031ull,0x09090a2030303538ull,0x3630653030647830ull,
0x3230617830203930ull,0x7830203030353030ull,0x3930303834333032ull,0x6666666630783020ull,
0x3009090a20333266ull,0x3034306530306478ull,0x3063303878302031ull,0x3278302030383730ull,
0x2031303038313030ull,0x3030303030307830ull,0x783009090a203330ull,0x3130343065303064ull,
0x3030633061783020ull,0x3132783020303837ull,0x3020643034666330ull,0x3030303030303078ull,
0x31783009090a2037ull,0x2031303038303030ull,0x3030303030307830ull,0x3030647830203330ull,
0x7830203130363065ull,0x3038373030633061ull,0x3064783009090a20ull,0x3020313034306530ull,
0x3837303063303878ull,0x3031313278302030ull,0x3078302039303466ull,0x2037303030303030ull,
0x333032783009090aull,0x7830203130303866ull,0x6666666666666630ull,0x3065303064783020ull,
0x3061783020313034ull,0x0a20303837303063ull,0x3431313278300909ull,0x3078302039303466ull,
0x2037303030303030ull,0x3038663330317830ull,0x6666307830203130ull,0x090a206666666666ull,
0x3065303064783009ull,0x3061783020313034ull,0x3020303837303063ull,0x3034663032313278ull,
0x3030303078302064ull,0x09090a2037303030ull,0x3630653030647830ull,0x6330387830203130ull,
0x7830203038373030ull,0x3930303831303032ull,0x3030303030783020ull,0x3009090a20333030ull,
0x6635303138303378ull,0x3134633678302064ull,0x6478302038633730ull,0x2039303630653030ull,
0x3730306330617830ull,0x783009090a203038ull,0x3330303836303031ull,0x3030303030783020ull,
0x3031783020303832ull,0x3020313030386332ull,0x3030303030303078ull,0x34783009090a2033ull,
0x2064303830313030ull,0x3730303030307830ull,0x3030367830203038ull,0x7830206430613030ull,
0x3038376330303030ull,0x3033783009090a20ull,0x3020643036303031ull,0x3837303031346378ull,
0x3030303678302030ull,0x3078302039303830ull,0x2030383763303030ull,0x303032783009090aull,
0x7830206430346430ull,0x3038373830323430ull,0x3031303031783020ull,0x3030783020313130ull,
0x0a20333030303030ull,0x3033303278300909ull,0x3078302064303638ull,0x2037303030303030ull,
0x3630653030647830ull,0x3230617830203930ull,0x090a203038373030ull,0x6630323132783009ull,
0x3030783020353134ull,0x3020373030303030ull,0x3061306530306478ull,0x3063303878302039ull,
0x09090a2030383730ull,0x3466633031327830ull,0x3030307830206430ull,0x7830203730303030ull,
0x6430363065303064ull,0x3030633038783020ull,0x3009090a20303837ull,0x3232303430303478ull,
0x3030303078302031ull,0x3678302030383730ull,0x2031323030353030ull,0x3730323030307830ull,
0x783009090a203038ull,0x3132303130313033ull,0x3030313463783020ull,0x3036783020303837ull,
0x3020393030303430ull,0x3837303230303078ull,0x32783009090a2030ull,0x2039303464303030ull,
0x3738303234307830ull,0x3330327830203038ull,0x7830203930343834ull,0x3730303030303030ull,
0x3064783009090a20ull,0x3020643034306530ull,0x3837303063306178ull,0x6530306478302030ull,
0x3878302039306130ull,0x2030383730306330ull,0x303034783009090aull,0x7830206430323034ull,
0x3038373030303030ull,0x3035303036783020ull,0x3030783020643030ull,0x0a20303837633030ull,
0x3031303378300909ull,0x6378302064303630ull,0x2030383730303134ull,0x3030343030367830ull,
0x3030307830203130ull,0x090a203038376330ull,0x6430303032783009ull,0x3430783020313034ull,
0x3020303837303032ull,0x3138663030303178ull,0x3330343078302035ull,0x09090a2030383763ull,
0x3038303130317830ull,0x3030307830203930ull,0x7830203730303030ull,0x6430303863333032ull,
0x3030303030783020ull,0x3009090a20373030ull,0x3261303030303278ull,0x3030343078302031ull,
0x3278302030383763ull,0x2035316138313030ull,0x3030303030307830ull,0x783009090a203330ull,
0x3530613030303030ull,0x3030303063783020ull,0x3431783020303837ull,0x3020353030303030ull,
0x3837303030303278ull,0x31783009090a2030ull,0x2031303830303030ull,0x3763333030307830ull,
0x3030617830203038ull,0x7830203930323030ull,0x3063373831306330ull,0x3064783009090a20ull,
0x3020313030316530ull,0x3837303032306178ull,0x3030303278302030ull,0x3078302031306130ull,
0x2030383730663134ull,0x303031783009090aull,0x7830203330303935ull,0x3030313030303030ull,
0x3032383033783020ull,0x6336783020646631ull,0x0a20386337343034ull,0x3430303178300909ull,
0x3078302033303065ull,0x2030383230303030ull,0x6130303030327830ull,0x3034307830203930ull,
0x090a203038376330ull,0x3030303031783009ull,0x3030783020313030ull,0x3020333030303030ull,
0x3034306530306478ull,0x3032306178302031ull,0x09090a2030383730ull,0x3466303231327830ull,
0x3030307830203130ull,0x7830203730303030ull,0x3130303065303064ull,0x3030633038783020ull,
0x3009090a20303837ull,0x3034663031313278ull,0x3030303078302039ull,0x6478302037303030ull,
0x2039303430653030ull,0x3730306330387830ull,0x783009090a203038ull,0x6430303863323031ull,
0x3030303030783020ull,0x3034783020333030ull,0x3020353130303730ull,0x3837303030303078ull,
0x36783009090a2030ull,0x2035313230363030ull,0x3734313030307830ull,0x3130337830203038ull,
0x7830203531613030ull,0x3038373030313463ull,0x3036783009090a20ull,0x3020313030303630ull,
0x3837343130303078ull,0x3030303278302030ull,0x3078302031303464ull,0x2030383730303234ull,
0x333032783009090aull,0x7830203130303838ull,0x3730303030303030ull,0x3065303064783020ull,
0x3061783020393030ull,0x0a20303837303063ull,0x3832313278300909ull,0x3078302031303466ull,
0x2037303030303030ull,0x3030653030647830ull,0x6330387830203130ull,0x090a203038373030ull,
0x3034303033783009ull,0x3436783020646631ull,0x3020386337343130ull,0x3030303030306678ull,
0x3030306578302031ull,0x09090a2032303030ull,0x3035373030617830ull,0x3030307830203330ull,
0x7830203030303030ull,0x3330303237303031ull,0x3030303030783020ull,0x3009090a20303832ull,
0x3034666332313278ull,0x3030303078302031ull,0x6478302037303030ull,0x2031303030653030ull,
0x3730306330387830ull,0x783009090a203038ull,0x6466313034313033ull,0x3830303436783020ull,
0x3031783020386437ull,0x3020333030343730ull,0x3832313030303078ull,0x31783009090a2030ull,
0x2031303038313030ull,0x3030303030307830ull,0x3030317830203330ull,0x7830203330303537ull,
0x3038373030303030ull,0x3031783009090a20ull,0x3020313038663030ull,0x3837633330343078ull,
0x6337303378302030ull,0x3678302064663130ull,0x2061643734313063ull,0x303061783009090aull,
0x7830203330303362ull,0x3030303030303030ull,0x3362303031783020ull,0x3030783020333030ull,
0x0a20303832313030ull,0x3032313278300909ull,0x3078302031303466ull,0x2033303030303030ull,
0x3030653030647830ull,0x6330387830203130ull,0x090a203038373030ull,0x3030383033783009ull,
0x6336783020646631ull,0x3020386437343134ull,0x3030336230303178ull,0x3030303078302033ull,
0x09090a2030383231ull,0x3466303231327830ull,0x3030307830203130ull,0x7830203730303030ull,
0x3130303065303064ull,0x3030633038783020ull,0x3009090a20303837ull,0x6631303138303378ull,
0x3134633678302064ull,0x3178302038643730ull,0x2033303033623030ull,0x3231303030307830ull,
0x783009090a203038ull,0x3930303063303033ull,0x3030313463783020ull,0x3033783020303837ull,
0x3020313030306230ull,0x3837303031346378ull,0x32783009090a2030ull,0x2030303438303030ull,
0x3466303031327830ull,0x3030317830203030ull,0x7830206430303831ull,0x3330303030303030ull,
0x3032783009090a20ull,0x3020393030383832ull,0x3230303030303078ull,0x3030313278302033ull,
0x3078302031303466ull,0x2033303031303030ull,0x303064783009090aull,0x7830206430343065ull,
0x3038373030653063ull,0x3863313032783020ull,0x6630783020393030ull,0x0a20373266666666ull,
0x6530306478300909ull,0x3878302039303430ull,0x2030383730303230ull,0x3930303030617830ull,
0x3063307830206466ull,0x090a203863373831ull,0x3061303031783009ull,0x3030783020333030ull,
0x3020303832303030ull,0x3030386331303278ull,0x6666663078302039ull,0x09090a2037326666ull,
0x3030313030317830ull,0x3030307830203130ull,0x7830203330303030ull,0x3130343065303064ull,
0x3030323061783020ull,0x3009090a20303837ull,0x3038663030303178ull,0x3330343078302064ull,
0x3178302030383763ull,0x2039303038373230ull,0x3030303030307830ull,0x783009090a203730ull,
0x3130346430303032ull,0x6330323430783020ull,0x3032783020303837ull,0x3020643036383130ull,
0x3030303030303078ull,0x30783009090a2033ull,0x2035303630303030ull,0x3730303030637830ull,
0x3130327830203038ull,0x7830203531303863ull,0x3734663030303030ull,0x3431783009090a20ull,
0x3020353032343030ull,0x3837303030303278ull,0x3030303178302030ull,0x3078302031303830ull,
0x2030383763333030ull,0x303061783009090aull,0x7830203930323030ull,0x3063373831306330ull,
0x3065303064783020ull,0x3061783020313061ull,0x0a20303837303032ull,0x3132303278300909ull,
0x3078302031303638ull,0x2033303030303030ull,0x3063393030317830ull,0x3030307830203330ull,
0x090a203030313030ull,0x3033383033783009ull,0x6336783020646631ull,0x3020386337343034ull,
0x3030303930303178ull,0x3030303078302033ull,0x09090a2030383230ull,0x3464303030327830ull,
0x3234307830203930ull,0x7830203038376330ull,0x3130303030303031ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3034386331303278ull,0x3030303078302039ull,0x6478302037346630ull,
0x2031303430653030ull,0x3730303230617830ull,0x783009090a203038ull,0x6430346630323132ull,
0x3030303030783020ull,0x3064783020373030ull,0x3020313036306530ull,0x3837303063303878ull,
0x32783009090a2030ull,0x2039303466343131ull,0x3030303030307830ull,0x3030647830203730ull,
0x7830203930343065ull,0x3038373030633038ull,0x3033783009090a20ull,0x3020353130306330ull,
0x3837303031346378ull,0x6230303378302030ull,0x6378302031303030ull,0x2030383730303134ull,
0x303032783009090aull,0x7830203030613830ull,0x3030346630303132ull,0x3863323032783020ull,
0x3030783020313030ull,0x0a20333230303030ull,0x6530306478300909ull,0x6178302039303030ull,
0x2030383730306330ull,0x3630653030647830ull,0x6330387830203130ull,0x090a203038373030ull,
0x3063303033783009ull,0x3463783020393030ull,0x3020303837303031ull,0x3030306230303378ull,
0x3031346378302031ull,0x09090a2030383730ull,0x3438303030327830ull,0x3031327830203030ull,
0x7830203830346630ull,0x3130303833303031ull,0x3030303030783020ull,0x3009090a20333030ull,
0x3034383033303278ull,0x3030303078302039ull,0x6478302033323030ull,0x2031303430653030ull,
0x3730306330617830ull,0x783009090a203038ull,0x3130346638323132ull,0x3030303030783020ull,
0x3064783020373030ull,0x3020313030306530ull,0x3837303063303878ull,0x33783009090a2030ull,
0x2064663130343030ull,0x3734313034367830ull,0x3030667830203863ull,0x7830203130303030ull,
0x3230303030303065ull,0x3061783009090a20ull,0x3020333030646230ull,0x3030303030303078ull,
0x6230303178302030ull,0x3078302033303061ull,0x2030383230303030ull,0x323132783009090aull,
0x7830203130346663ull,0x3730303030303030ull,0x3065303064783020ull,0x3038783020313030ull,
0x0a20303837303063ull,0x3431303378300909ull,0x3678302064663130ull,0x2038643738303034ull,
0x3063623030317830ull,0x3030307830203330ull,0x090a203038323130ull,0x3831303031783009ull,
0x3030783020313030ull,0x3020333030303030ull,0x3030646230303178ull,0x3030303078302033ull,
0x09090a2030383730ull,0x3866303030317830ull,0x3034307830203130ull,0x7830203038376333ull,
0x6466313063373033ull,0x3431306336783020ull,0x3009090a20616437ull,0x3030626630306178ull,
0x3030303078302033ull,0x3178302030303030ull,0x2033303062663030ull,0x3231303030307830ull,
0x783009090a203038ull,0x3130346630323132ull,0x3030303030783020ull,0x3064783020333030ull,
0x3020313030306530ull,0x3837303063303878ull,0x33783009090a2030ull,0x2064663130303830ull,
0x3734313463367830ull,0x3030317830203864ull,0x7830203330306266ull,0x3038323130303030ull,
0x3132783009090a20ull,0x3020313034663032ull,0x3030303030303078ull,0x6530306478302037ull,
0x3878302031303030ull,0x2030383730306330ull,0x383033783009090aull,0x7830206466313031ull,
0x3864373031346336ull,0x6266303031783020ull,0x3030783020333030ull,0x0a20303832313030ull,
0x6330303378300909ull,0x6378302039303030ull,0x2030383730303134ull,0x3030623030337830ull,
0x3134637830203130ull,0x090a203038373030ull,0x3830303032783009ull,0x3132783020303034ull,
0x3020303034663030ull,0x3030383130303178ull,0x3030303078302064ull,0x09090a2033303030ull,
0x3038343330327830ull,0x3030307830203930ull,0x7830203332303030ull,0x3130346630303132ull,
0x3130303030783020ull,0x3009090a20333030ull,0x3034306530306478ull,0x3065306378302064ull,
0x3278302030383730ull,0x2039303038643130ull,0x6666666666307830ull,0x783009090a203732ull,
0x3930343065303064ull,0x3030323038783020ull,0x3061783020303837ull,0x3020646639303030ull,
0x6337383130633078ull,0x31783009090a2038ull,0x2033303038653030ull,0x3230303030307830ull,
0x3130327830203038ull,0x7830203930303864ull,0x3732666666666630ull,0x3031783009090a20ull,
0x3020313030303130ull,0x3030303030303078ull,0x6530306478302033ull,0x6178302031303430ull,
0x2030383730303230ull,0x303031783009090aull,0x7830206430386630ull,0x3038376333303430ull,
0x3837323031783020ull,0x3030783020393030ull,0x0a20373030303030ull,0x3030303278300909ull,
0x3078302031303464ull,0x2030383763303234ull,0x3638313030327830ull,0x3030307830206430ull,
0x090a203330303030ull,0x3030303030783009ull,0x3063783020353036ull,0x3020303837303030ull,
0x3130386333303278ull,0x3030303078302035ull,0x09090a2037346630ull,0x6134303034317830ull,
0x3030327830203530ull,0x7830203038373030ull,0x3130383030303031ull,0x6333303030783020ull,
0x3009090a20303837ull,0x3032303030306178ull,0x3130633078302039ull,0x6478302030633738ull,
0x2031306130653030ull,0x3730303230617830ull,0x783009090a203038ull,0x3130363835323032ull,
0x3030303030783020ull,0x3031783020333030ull,0x3020333030346530ull,0x3031303030303078ull,
0x33783009090a2030ull,0x2064663130343830ull,0x3734303463367830ull,0x3030317830203863ull,
0x7830203330303864ull,0x3038323030303030ull,0x3032783009090a20ull,0x3020393034643030ull,
0x3837633032343078ull,0x3030303178302030ull,0x3078302031303030ull,0x2033303030303030ull,
0x333032783009090aull,0x7830203930343863ull,0x3734663030303030ull,0x3065303064783020ull,
0x3061783020313034ull,0x0a20303837303032ull,0x3032313278300909ull,0x3078302064303466ull,
0x2037303030303030ull,0x3630653030647830ull,0x6330387830203130ull,0x090a203038373030ull,
0x6634313132783009ull,0x3030783020393034ull,0x3020373030303030ull,0x3034306530306478ull,
0x3063303878302039ull,0x09090a2030383730ull,0x3030633030337830ull,0x3134637830203531ull,
0x7830203038373030ull,0x3130303062303033ull,0x3030313463783020ull,0x3009090a20303837ull,
0x3061383030303278ull,0x3030313278302030ull,0x3278302030303466ull,0x2031303038383330ull,
0x3030303030307830ull,0x783009090a203332ull,0x3930303065303064ull,0x3030633061783020ull,
0x3064783020303837ull,0x3020313036306530ull,0x3837303063303878ull,0x33783009090a2030ull,
0x2039303030633030ull,0x3730303134637830ull,0x3030337830203038ull,0x7830203130303062ull,
0x3038373030313463ull,0x3032783009090a20ull,0x3020303034383030ull,0x3034663030313278ull,
0x3430303178302038ull,0x3078302031303038ull,0x2033303030303030ull,0x333032783009090aull,
0x7830203930343863ull,0x3332303030303030ull,0x3065303064783020ull,0x3061783020313034ull,
0x0a20303837303063ull,0x3832313278300909ull,0x3078302031303466ull,0x2037303030303030ull,
0x3030653030647830ull,0x6330387830203130ull,0x090a203038373030ull,0x3034303033783009ull,
0x3436783020646631ull,0x3020386337343130ull,0x3030303030306678ull,0x3030306578302031ull,
0x09090a2032303030ull,0x3035303130617830ull,0x3030307830203330ull,0x7830203030303030ull,
0x3330303230313031ull,0x3030303030783020ull,0x3009090a20303832ull,0x3034666332313278ull,
0x3030303078302031ull,0x6478302037303030ull,0x2031303030653030ull,0x3730306330387830ull,
0x783009090a203038ull,0x6466313034313033ull,0x3830303436783020ull,0x3031783020386437ull,
0x3020333030343031ull,0x3832313030303078ull,0x31783009090a2030ull,0x2031303038313030ull,
0x3030303030307830ull,0x3130317830203330ull,0x7830203330303530ull,0x3038373030303030ull,
0x3031783009090a20ull,0x3020313038663030ull,0x3837633330343078ull,0x6337303378302030ull,
0x3678302064663130ull,0x2061643734313063ull,0x313061783009090aull,0x7830203330303334ull,
0x3030303030303030ull,0x3334313031783020ull,0x3030783020333030ull,0x0a20303832313030ull,
0x3032313278300909ull,0x3078302031303466ull,0x2033303030303030ull,0x3030653030647830ull,
0x6330387830203130ull,0x090a203038373030ull,0x3030383033783009ull,0x6336783020646631ull,
0x3020386437343134ull,0x3030333431303178ull,0x3030303078302033ull,0x09090a2030383231ull,
0x3466303231327830ull,0x3030307830203130ull,0x7830203730303030ull,0x3130303065303064ull,
0x3030633038783020ull,0x3009090a20303837ull,0x6631303138303378ull,0x3134633678302064ull,
0x3178302038643730ull,0x2033303033343130ull,0x3231303030307830ull,0x783009090a203038ull,
0x3930303063303033ull,0x3030313463783020ull,0x3033783020303837ull,0x3020313030306230ull,
0x3837303031346378ull,0x32783009090a2030ull,0x2030303438303030ull,0x3466303031327830ull,
0x3030317830203030ull,0x7830206430303831ull,0x3330303030303030ull,0x3032783009090a20ull,
0x3020393030383030ull,0x3230303030303078ull,0x3030313278302037ull,0x3078302031303466ull,
0x2033303031303030ull,0x303064783009090aull,0x7830206430343065ull,0x3038373030653063ull,
0x3865313032783020ull,0x6630783020393030ull,0x0a20373266666666ull,0x6530306478300909ull,
0x3878302039303430ull,0x2030383730303230ull,0x3930303030617830ull,0x3063307830206466ull,
0x090a203863373831ull,0x3033313031783009ull,0x3030783020333030ull,0x3020303832303030ull,
0x3030386531303278ull,0x6666663078302039ull,0x09090a2037326666ull,0x3030313030317830ull,
0x3030307830203130ull,0x7830203330303030ull,0x3130343065303064ull,0x3030323061783020ull,
0x3009090a20303837ull,0x3038663030303178ull,0x3330343078302064ull,0x3178302030383763ull,
0x2039303038373230ull,0x3030303030307830ull,0x783009090a203730ull,0x3130346430303032ull,
0x6330323430783020ull,0x3032783020303837ull,0x3020643036383130ull,0x3030303030303078ull,
0x30783009090a2033ull,0x2035303630303030ull,0x3730303030637830ull,0x3130327830203038ull,
0x7830203531303863ull,0x6234663030303030ull,0x3431783009090a20ull,0x3020353032353030ull,
0x3837303030303278ull,0x3030303178302030ull,0x3078302031303830ull,0x2030383763333030ull,
0x303061783009090aull,0x7830203930323030ull,0x3063373831306330ull,0x3065303064783020ull,
0x3061783020313061ull,0x0a20303837303032ull,0x3932303278300909ull,0x3078302031303638ull,
0x2033303030303030ull,0x3063323130317830ull,0x3030307830203330ull,0x090a203030313030ull,
0x3035383033783009ull,0x6336783020646631ull,0x3020386337343034ull,0x3030303231303178ull,
0x3030303078302033ull,0x09090a2030383230ull,0x3464303030327830ull,0x3234307830203930ull,
0x7830203038376330ull,0x3130303030303031ull,0x3030303030783020ull,0x3009090a20333030ull,
0x3034386331303278ull,0x3030303078302039ull,0x6478302062346630ull,0x2031303430653030ull,
0x3730303230617830ull,0x783009090a203038ull,0x6430346630323132ull,0x3030303030783020ull,
0x3064783020373030ull,0x3020313036306530ull,0x3837303063303878ull,0x32783009090a2030ull,
0x2039303466343131ull,0x3030303030307830ull,0x3030647830203730ull,0x7830203930343065ull,
0x3038373030633038ull,0x3033783009090a20ull,0x3020353130306330ull,0x3837303031346378ull,
0x6230303378302030ull,0x6378302031303030ull,0x2030383730303134ull,0x303032783009090aull,
0x7830203030613830ull,0x3030346630303132ull,0x3834303032783020ull,0x3030783020313030ull,
0x0a20373230303030ull,0x6530306478300909ull,0x6178302039303030ull,0x2030383730306330ull,
0x3630653030647830ull,0x6330387830203130ull,0x090a203038373030ull,0x3063303033783009ull,
0x3463783020393030ull,0x3020303837303031ull,0x3030306230303378ull,0x3031346378302031ull,
0x09090a2030383730ull,0x3438303030327830ull,0x3031327830203030ull,0x7830203830346630ull,
0x3130303833303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x3034383830303278ull,
0x3030303078302039ull,0x6478302037323030ull,0x2031303430653030ull,0x3730306330617830ull,
0x783009090a203038ull,0x3130346638323132ull,0x3030303030783020ull,0x3064783020373030ull,
0x3020313030306530ull,0x3837303063303878ull,0x33783009090a2030ull,0x2064663130343030ull,
0x3734313034367830ull,0x3030667830203863ull,0x7830203130303030ull,0x3230303030303065ull,
0x3061783009090a20ull,0x3020333030643431ull,0x3030303030303078ull,0x3431303178302030ull,
0x3078302033303061ull,0x2030383230303030ull,0x323132783009090aull,0x7830203130346663ull,
0x3730303030303030ull,0x3065303064783020ull,0x3038783020313030ull,0x0a20303837303063ull,
0x3431303378300909ull,0x3678302064663130ull,0x2038643738303034ull,0x3063343130317830ull,
0x3030307830203330ull,0x090a203038323130ull,0x3831303031783009ull,0x3030783020313030ull,
0x3020333030303030ull,0x3030643431303178ull,0x3030303078302033ull,0x09090a2030383730ull,
0x3866303030317830ull,0x3034307830203130ull,0x7830203038376333ull,0x6466313063373033ull,
0x3431306336783020ull,0x3009090a20616437ull,0x3030623831306178ull,0x3030303078302033ull,
0x3178302030303030ull,0x2033303062383130ull,0x3231303030307830ull,0x783009090a203038ull,
0x3130346630323132ull,0x3030303030783020ull,0x3064783020333030ull,0x3020313030306530ull,
0x3837303063303878ull,0x33783009090a2030ull,0x2064663130303830ull,0x3734313463367830ull,
0x3130317830203864ull,0x7830203330306238ull,0x3038323130303030ull,0x3132783009090a20ull,
0x3020313034663032ull,0x3030303030303078ull,0x6530306478302037ull,0x3878302031303030ull,
0x2030383730306330ull,0x383033783009090aull,0x7830206466313031ull,0x3864373031346336ull,
0x6238313031783020ull,0x3030783020333030ull,0x0a20303832313030ull,0x6330303378300909ull,
0x6378302039303030ull,0x2030383730303134ull,0x3030623030337830ull,0x3134637830203130ull,
0x090a203038373030ull,0x3830303032783009ull,0x3132783020303034ull,0x3020303034663030ull,
0x3030383130303178ull,0x3030303078302064ull,0x09090a2033303030ull,0x3038633030327830ull,
0x3030307830203930ull,0x7830203732303030ull,0x3130346630303132ull,0x3130303030783020ull,
0x3009090a20333030ull,0x3034306530306478ull,0x3065306378302064ull,0x3278302030383730ull,
0x2039303038663130ull,0x6666666666307830ull,0x783009090a203732ull,0x3930343065303064ull,
0x3030323038783020ull,0x3061783020303837ull,0x3020646639303030ull,0x6337383130633078ull,
0x31783009090a2038ull,0x2033303038373130ull,0x3230303030307830ull,0x3130327830203038ull,
0x7830203930303866ull,0x3732666666666630ull,0x3031783009090a20ull,0x3020313030303130ull,
0x3030303030303078ull,0x6530306478302033ull,0x6178302031303430ull,0x2030383730303230ull,
0x303031783009090aull,0x7830206430386630ull,0x3038376333303430ull,0x3865323031783020ull,
0x3030783020393030ull,0x0a20373030303030ull,0x3030303278300909ull,0x3078302031303464ull,
0x2030383763303234ull,0x3638313030327830ull,0x3030307830206430ull,0x090a203330303030ull,
0x3030303030783009ull,0x3063783020353036ull,0x3020303837303030ull,0x3130386333303278ull,
0x3030303078302035ull,0x09090a2062346630ull,0x6135303034317830ull,0x3030327830203530ull,
0x7830203038373030ull,0x3130383030303031ull,0x6333303030783020ull,0x3009090a20303837ull,
0x3032303030306178ull,0x3130633078302039ull,0x6478302030633738ull,0x2031306130653030ull,
0x3730303230617830ull,0x783009090a203038ull,0x3130363864323032ull,0x3030303030783020ull,
0x3031783020333030ull,0x3020333030343731ull,0x3031303030303078ull,0x33783009090a2030ull,
0x2064663130363830ull,0x3734303463367830ull,0x3130317830203863ull,0x7830203330303836ull,
0x3038323030303030ull,0x3032783009090a20ull,0x3020393034643030ull,0x3837633032343078ull,
0x3030303178302030ull,0x3078302031303030ull,0x2033303030303030ull,0x333032783009090aull,
0x7830203930343863ull,0x6234663030303030ull,0x3065303064783020ull,0x3061783020313034ull,
0x0a20303837303032ull,0x3032313278300909ull,0x3078302064303466ull,0x2037303030303030ull,
0x3630653030647830ull,0x6330387830203130ull,0x090a203038373030ull,0x6634313132783009ull,
0x3030783020393034ull,0x3020373030303030ull,0x3034306530306478ull,0x3063303878302039ull,
0x09090a2030383730ull,0x3030633030337830ull,0x3134637830203531ull,0x7830203038373030ull,
0x3130303062303033ull,0x3030313463783020ull,0x3009090a20303837ull,0x3061383030303278ull,
0x3030313278302030ull,0x3278302030303466ull,0x2031303038303130ull,0x3030303030307830ull,
0x783009090a203732ull,0x3930303065303064ull,0x3030633061783020ull,0x3064783020303837ull,
0x3020313036306530ull,0x3837303063303878ull,0x33783009090a2030ull,0x2039303030633030ull,
0x3730303134637830ull,0x3030337830203038ull,0x7830203130303062ull,0x3038373030313463ull,
0x3032783009090a20ull,0x3020303034383030ull,0x3034663030313278ull,0x3130303178302038ull,
0x3078302031303038ull,0x2033303030303030ull,0x313032783009090aull,0x7830203930343834ull,
0x3732303030303030ull,0x3065303064783020ull,0x3061783020313034ull,0x0a20303837303063ull,
0x3832313278300909ull,0x3078302031303466ull,0x2037303030303030ull,0x3030653030647830ull,
0x6330387830203130ull,0x090a203038373030ull,0x3034303033783009ull,0x3436783020646631ull,
0x3020386337343130ull,0x3030303030306678ull,0x3030306578302031ull,0x09090a2032303030ull,
0x3035393130617830ull,0x3030307830203330ull,0x7830203030303030ull,0x3330303239313031ull,
0x3030303030783020ull,0x3009090a20303832ull,0x3034666332313278ull,0x3030303078302031ull,
0x6478302037303030ull,0x2031303030653030ull,0x3730306330387830ull,0x783009090a203038ull,
0x6466313034313033ull,0x3830303436783020ull,0x3031783020386437ull,0x3020333030343931ull,
0x3832313030303078ull,0x31783009090a2030ull,0x2031303038313030ull,0x3030303030307830ull,
0x3130317830203330ull,0x7830203330303539ull,0x3038373030303030ull,0x3031783009090a20ull,
0x3020313038663030ull,0x3837633330343078ull,0x6337303378302030ull,0x3678302064663130ull,
0x2061643734313063ull,0x313061783009090aull,0x7830203330303364ull,0x3030303030303030ull,
0x3364313031783020ull,0x3030783020333030ull,0x0a20303832313030ull,0x3032313278300909ull,
0x3078302031303466ull,0x2033303030303030ull,0x3030653030647830ull,0x6330387830203130ull,
0x090a203038373030ull,0x3030383033783009ull,0x6336783020646631ull,0x3020386437343134ull,
0x3030336431303178ull,0x3030303078302033ull,0x09090a2030383231ull,0x3466303231327830ull,
0x3030307830203130ull,0x7830203730303030ull,0x3130303065303064ull,0x3030633038783020ull,
0x3009090a20303837ull,0x6631303138303378ull,0x3134633678302064ull,0x3178302038643730ull,
0x2033303033643130ull,0x3231303030307830ull,0x783009090a203038ull,0x3930303063303033ull,
0x3030313463783020ull,0x3033783020303837ull,0x3020313030306230ull,0x3837303031346378ull,
0x32783009090a2030ull,0x2030303438303030ull,0x3466303031327830ull,0x3030317830203030ull,
0x7830206430303831ull,0x3330303030303030ull,0x3032783009090a20ull,0x3020393030383831ull,
0x3230303030303078ull,0x3030313278302037ull,0x3078302031303466ull,0x2033303031303030ull,
0x303064783009090aull,0x7830206430343065ull,0x3038373030653063ull,0x3830323032783020ull,
0x6630783020393030ull,0x0a20373266666666ull,0x6530306478300909ull,0x3878302039303430ull,
0x2030383730303230ull,0x3930303030617830ull,0x3063307830206466ull,0x090a203863373831ull,
0x3063313031783009ull,0x3030783020333030ull,0x3020303832303030ull,0x3030383032303278ull,
0x6666663078302039ull,0x09090a2037326666ull,0x3030313030317830ull,0x3030307830203130ull,
0x7830203330303030ull,0x3130343065303064ull,0x3030323061783020ull,0x3009090a20303837ull,
0x3038663030303178ull,0x3330343078302064ull,0x3178302030383763ull,0x2039303038333330ull,
0x3030303030307830ull,0x783009090a203730ull,0x3130346430303032ull,0x6330323430783020ull,
0x3032783020303837ull,0x3020643036383130ull,0x3030303030303078ull,0x30783009090a2033ull,
0x2035303630303030ull,0x3730303030637830ull,0x3130327830203038ull,0x7830203531303863ull,
0x6634663030303030ull,0x3431783009090a20ull,0x3020353065353030ull,0x3837303030303278ull,
0x3030303178302030ull,0x3078302031303830ull,0x2030383763333030ull,0x303061783009090aull,
0x7830203930323030ull,0x3063373831306330ull,0x3065303064783020ull,0x3061783020313061ull,
0x0a20303837303032ull,0x6632303278300909ull,0x3078302031303638ull,0x2033303030303030ull,
0x3063623130317830ull,0x3030307830203330ull,0x090a203030313030ull,0x3037383033783009ull,
0x6336783020646631ull,0x3020386337343034ull,0x3030306231303178ull,0x3030303078302033ull,
0x09090a2030383230ull,0x3464303030327830ull,0x3234307830203930ull,0x7830203038376330ull,
0x3130303030303031ull,0x3030303030783020ull,0x3009090a20333030ull,0x3034386331303278ull,
0x3030303078302039ull,0x6478302066346630ull,0x2031303430653030ull,0x3730303230617830ull,
0x783009090a203038ull,0x6430346630323132ull,0x3030303030783020ull,0x3064783020373030ull,
0x3020313036306530ull,0x3837303063303878ull,0x32783009090a2030ull,0x2039303466343131ull,
0x3030303030307830ull,0x3030647830203730ull,0x7830203930343065ull,0x3038373030633038ull,
0x3033783009090a20ull,0x3020353130306330ull,0x3837303031346378ull,0x6230303378302030ull,
0x6378302031303030ull,0x2030383730303134ull,0x303032783009090aull,0x7830203030613830ull,
0x3030346630303132ull,0x3863313032783020ull,0x3030783020313030ull,0x0a20373230303030ull,
0x6530306478300909ull,0x6178302039303030ull,0x2030383730306330ull,0x3630653030647830ull,
0x6330387830203130ull,0x090a203038373030ull,0x3063303033783009ull,0x3463783020393030ull,
0x3020303837303031ull,0x3030306230303378ull,0x3031346378302031ull,0x09090a2030383730ull,
0x3438303030327830ull,0x3031327830203030ull,0x7830203830346630ull,0x3130303831303031ull,
0x3030303030783020ull,0x3009090a20333030ull,0x3034383032303278ull,0x3030303078302039ull,
0x6478302037323030ull,0x2031303430653030ull,0x3730306330617830ull,0x783009090a203038ull,
0x3130346638323132ull,0x3030303030783020ull,0x3064783020373030ull,0x3020313030306530ull,
0x3837303063303878ull,0x33783009090a2030ull,0x2064663130343030ull,0x3734313034367830ull,
0x3030667830203863ull,0x7830203130303030ull,0x3230303030303065ull,0x3061783009090a20ull,
0x3020333030646431ull,0x3030303030303078ull,0x6431303178302030ull,0x3078302033303061ull,
0x2030383230303030ull,0x323132783009090aull,0x7830203130346663ull,0x3730303030303030ull,
0x3065303064783020ull,0x3038783020313030ull,0x0a20303837303063ull,0x3431303378300909ull,
0x3678302064663130ull,0x2038643738303034ull,0x3063643130317830ull,0x3030307830203330ull,
0x090a203038323130ull,0x3831303031783009ull,0x3030783020313030ull,0x3020333030303030ull,
0x3030646431303178ull,0x3030303078302033ull,0x09090a2030383730ull,0x3866303030317830ull,
0x3034307830203130ull,0x7830203038376333ull,0x6466313063373033ull,0x3431306336783020ull,
0x3009090a20616437ull,0x3030623132306178ull,0x3030303078302033ull,0x3178302030303030ull,
0x2033303062313230ull,0x3231303030307830ull,0x783009090a203038ull,0x3130346630323132ull,
0x3030303030783020ull,0x3064783020333030ull,0x3020313030306530ull,0x3837303063303878ull,
0x33783009090a2030ull,0x2064663130303830ull,0x3734313463367830ull,0x3230317830203864ull,
0x7830203330306231ull,0x3038323130303030ull,0x3132783009090a20ull,0x3020313034663032ull,
0x3030303030303078ull,0x6530306478302037ull,0x3878302031303030ull,0x2030383730306330ull,
0x383033783009090aull,0x7830206466313031ull,0x3864373031346336ull,0x6231323031783020ull,
0x3030783020333030ull,0x0a20303832313030ull,0x6330303378300909ull,0x6378302039303030ull,
0x2030383730303134ull,0x3030623030337830ull,0x3134637830203130ull,0x090a203038373030ull,
0x3830303032783009ull,0x3132783020303034ull,0x3020303034663030ull,0x3030383130303178ull,
0x3030303078302064ull,0x09090a2033303030ull,0x3038343230327830ull,0x3030307830203930ull,
0x7830203732303030ull,0x3130346630303132ull,0x3130303030783020ull,0x3009090a20333030ull,
0x3034306530306478ull,0x3065306378302064ull,0x3278302030383730ull,0x2039303038313230ull,
0x6666666666307830ull,0x783009090a203732ull,0x3930343065303064ull,0x3030323038783020ull,
0x3061783020303837ull,0x3020646639303030ull,0x6337383130633078ull,0x31783009090a2038ull,
0x2033303038303230ull,0x3230303030307830ull,0x3230327830203038ull,0x7830203930303831ull,
0x3732666666666630ull,0x3031783009090a20ull,0x3020313030303130ull,0x3030303030303078ull,
0x6530306478302033ull,0x6178302031303430ull,0x2030383730303230ull,0x303031783009090aull,
0x7830206430386630ull,0x3038376333303430ull,0x3833333031783020ull,0x3030783020393030ull,
0x0a20373030303030ull,0x3030303278300909ull,0x3078302031303464ull,0x2030383763303234ull,
0x3638313030327830ull,0x3030307830206430ull,0x090a203330303030ull,0x3030303030783009ull,
0x3063783020353036ull,0x3020303837303030ull,0x3130386333303278ull,0x3030303078302035ull,
0x09090a2066346630ull,0x3236303034317830ull,0x3030327830203530ull,0x7830203038373030ull,
0x3130383030303031ull,0x6333303030783020ull,0x3009090a20303837ull,0x3032303030306178ull,
0x3130633078302039ull,0x6478302030633738ull,0x2031306130653030ull,0x3730303230617830ull,
0x783009090a203038ull,0x3130363831333032ull,0x3030303030783020ull,0x3031783020333030ull,
0x3020333030343032ull,0x3031303030303078ull,0x33783009090a2030ull,0x2064663130383830ull,
0x3734303463367830ull,0x3130317830203863ull,0x7830203330303866ull,0x3038323030303030ull,
0x3032783009090a20ull,0x3020393034643030ull,0x3837633032343078ull,0x3030303178302030ull,
0x3078302031303030ull,0x2033303030303030ull,0x333032783009090aull,0x7830203930343863ull,
0x6634663030303030ull,0x3065303064783020ull,0x3061783020313034ull,0x0a20303837303032ull,
0x3032313278300909ull,0x3078302064303466ull,0x2037303030303030ull,0x3630653030647830ull,
0x6330387830203130ull,0x090a203038373030ull,0x6634313132783009ull,0x3030783020393034ull,
0x3020373030303030ull,0x3034306530306478ull,0x3063303878302039ull,0x09090a2030383730ull,
0x3030633030337830ull,0x3134637830203531ull,0x7830203038373030ull,0x3130303062303033ull,
0x3030313463783020ull,0x3009090a20303837ull,0x3061383030303278ull,0x3030313278302030ull,
0x3278302030303466ull,0x2031303038383230ull,0x3030303030307830ull,0x783009090a203732ull,
0x3930303065303064ull,0x3030633061783020ull,0x3064783020303837ull,0x3020313036306530ull,
0x3837303063303878ull,0x33783009090a2030ull,0x2039303030633030ull,0x3730303134637830ull,
0x3030337830203038ull,0x7830203130303062ull,0x3038373030313463ull,0x3032783009090a20ull,
0x3020303034383030ull,0x3034663030313278ull,0x3130303178302038ull,0x3078302031303038ull,
0x2033303030303030ull,0x323032783009090aull,0x7830203930343863ull,0x3732303030303030ull,
0x3065303064783020ull,0x3061783020313034ull,0x0a20303837303063ull,0x3832313278300909ull,
0x3078302031303466ull,0x2037303030303030ull,0x3030653030647830ull,0x6330387830203130ull,
0x090a203038373030ull,0x3034303033783009ull,0x3436783020646631ull,0x3020386337343130ull,
0x3030303030306678ull,0x3030306578302031ull,0x09090a2032303030ull,0x3035323230617830ull,
0x3030307830203330ull,0x7830203030303030ull,0x3330303232323031ull,0x3030303030783020ull,
0x3009090a20303832ull,0x3034666332313278ull,0x3030303078302031ull,0x6478302037303030ull,
0x2031303030653030ull,0x3730306330387830ull,0x783009090a203038ull,0x6466313034313033ull,
0x3830303436783020ull,0x3031783020386437ull,0x3020333030343232ull,0x3832313030303078ull,
0x31783009090a2030ull,0x2031303038313030ull,0x3030303030307830ull,0x3230317830203330ull,
0x7830203330303532ull,0x3038373030303030ull,0x3031783009090a20ull,0x3020313038663030ull,
0x3837633330343078ull,0x6337303378302030ull,0x3678302064663130ull,0x2061643734313063ull,
0x323061783009090aull,0x7830203330303336ull,0x3030303030303030ull,0x3336323031783020ull,
0x3030783020333030ull,0x0a20303832313030ull,0x3032313278300909ull,0x3078302031303466ull,
0x2033303030303030ull,0x3030653030647830ull,0x6330387830203130ull,0x090a203038373030ull,
0x3030383033783009ull,0x6336783020646631ull,0x3020386437343134ull,0x3030333632303178ull,
0x3030303078302033ull,0x09090a2030383231ull,0x3466303231327830ull,0x3030307830203130ull,
0x7830203730303030ull,0x3130303065303064ull,0x3030633038783020ull,0x3009090a20303837ull,
0x6631303138303378ull,0x3134633678302064ull,0x3178302038643730ull,0x2033303033363230ull,
0x3231303030307830ull,0x783009090a203038ull,0x3930303063303033ull,0x3030313463783020ull,
0x3033783020303837ull,0x3020313030306230ull,0x3837303031346378ull,0x32783009090a2030ull,
0x2030303438303030ull,0x3466303031327830ull,0x3030317830203030ull,0x7830206430303831ull,
0x3330303030303030ull,0x3032783009090a20ull,0x3020393030383033ull,0x3230303030303078ull,
0x3030313278302037ull,0x3078302031303466ull,0x2033303031303030ull,0x303064783009090aull,
0x7830206430343065ull,0x3038373030653063ull,0x3832323032783020ull,0x6630783020393030ull,
0x0a20373266666666ull,0x6530306478300909ull,0x3878302039303430ull,0x2030383730303230ull,
0x3930303030617830ull,0x3063307830206466ull,0x090a203863373831ull,0x3035323031783009ull,
0x3030783020333030ull,0x3020303832303030ull,0x3030383232303278ull,0x6666663078302039ull,
0x09090a2037326666ull,0x3030313030317830ull,0x3030307830203130ull,0x7830203330303030ull,
0x3130343065303064ull,0x3030323061783020ull,0x3009090a20303837ull,0x3038663030303178ull,
0x3330343078302064ull,0x3178302030383763ull,0x2039303038653030ull,0x3030303030307830ull,
0x783009090a203730ull,0x3130346430303032ull,0x6330323430783020ull,0x3032783020303837ull,
0x3020643036383130ull,0x3030303030303078ull,0x30783009090a2033ull,0x2035303630303030ull,
0x3730303030637830ull,0x3130327830203038ull,0x7830203531303863ull,0x3335663030303030ull,
0x3431783009090a20ull,0x3020353065313030ull,0x3837303030303278ull,0x3030303178302030ull,
0x3078302031303830ull,0x2030383763333030ull,0x303061783009090aull,0x7830203930323030ull,
0x3063373831306330ull,0x3065303064783020ull,0x3061783020313061ull,0x0a20303837303032ull,
0x6630303278300909ull,0x3078302031303638ull,0x2033303030303030ull,0x3063343230317830ull,
0x3030307830203330ull,0x090a203030313030ull,0x3039383033783009ull,0x6336783020646631ull,
0x3020386337343034ull,0x3030303432303178ull,0x3030303078302033ull,0x09090a2030383230ull,
0x3464303030327830ull,0x3234307830203930ull,0x7830203038376330ull,0x3130303030303031ull,
0x3030303030783020ull,0x3009090a20333030ull,0x3034386331303278ull,0x3030303078302039ull,
0x6478302033356630ull,0x2031303430653030ull,0x3730303230617830ull,0x783009090a203038ull,
0x6430346630323132ull,0x3030303030783020ull,0x3064783020373030ull,0x3020313036306530ull,
0x3837303063303878ull,0x32783009090a2030ull,0x2039303466343131ull,0x3030303030307830ull,
0x3030647830203730ull,0x7830203930343065ull,0x3038373030633038ull,0x3033783009090a20ull,
0x3020353130306330ull,0x3837303031346378ull,0x6230303378302030ull,0x6378302031303030ull,
0x2030383730303134ull,0x303032783009090aull,0x7830203030613830ull,0x3030346630303132ull,
0x3834333032783020ull,0x3030783020313030ull,0x0a20373230303030ull,0x6530306478300909ull,
0x6178302039303030ull,0x2030383730306330ull,0x3630653030647830ull,0x6330387830203130ull,
0x090a203038373030ull,0x3063303033783009ull,0x3463783020393030ull,0x3020303837303031ull,
0x3030306230303378ull,0x3031346378302031ull,0x09090a2030383730ull,0x3438303030327830ull,
0x3031327830203030ull,0x7830203830346630ull,0x3130303831303031ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3034383833303278ull,0x3030303078302039ull,0x6478302037323030ull,
0x2031303430653030ull,0x3730306330617830ull,0x783009090a203038ull,0x3130346638323132ull,
0x3030303030783020ull,0x3064783020373030ull,0x3020313030306530ull,0x3837303063303878ull,
0x33783009090a2030ull,0x2064663130343030ull,0x3734313034367830ull,0x3030667830203863ull,
0x7830203130303030ull,0x3230303030303065ull,0x3061783009090a20ull,0x3020333030643632ull,
0x3030303030303078ull,0x3632303178302030ull,0x3078302033303061ull,0x2030383230303030ull,
0x323132783009090aull,0x7830203130346663ull,0x3730303030303030ull,0x3065303064783020ull,
0x3038783020313030ull,0x0a20303837303063ull,0x3431303378300909ull,0x3678302064663130ull,
0x2038633738303034ull,0x3063363230317830ull,0x3030307830203330ull,0x090a203038323030ull,
0x3831303031783009ull,0x3030783020313030ull,0x3020333030303030ull,0x3030643632303178ull,
0x3030303078302033ull,0x09090a2030383730ull,0x3866303030317830ull,0x3034307830203130ull,
0x7830203038376333ull,0x6466313063373033ull,0x3431306336783020ull,0x3009090a20616337ull,
0x3030386132306178ull,0x3030303078302033ull,0x3178302030303030ull,0x2033303038613230ull,
0x3230303030307830ull,0x783009090a203038ull,0x3130346630323132ull,0x3030303030783020ull,
0x3064783020333030ull,0x3020313030306530ull,0x3837303063303878ull,0x33783009090a2030ull,
0x2064663130303830ull,0x3734313463367830ull,0x3230317830203863ull,0x7830203330303861ull,
0x3038323030303030ull,0x3132783009090a20ull,0x3020313034663032ull,0x3030303030303078ull,
0x6530306478302037ull,0x3878302031303030ull,0x2030383730306330ull,0x383033783009090aull,
0x7830206466313031ull,0x3863373031346336ull,0x3861323031783020ull,0x3030783020333030ull,
0x0a20303832303030ull,0x6330303378300909ull,0x6378302039303030ull,0x2030383730303134ull,
0x3030623030337830ull,0x3134637830203130ull,0x090a203038373030ull,0x3830303032783009ull,
0x3132783020303034ull,0x3020303034663030ull,0x3030383130303178ull,0x3030303078302064ull,
0x09090a2033303030ull,0x3038633330327830ull,0x3030307830203930ull,0x7830203732303030ull,
0x3130346630303132ull,0x3130303030783020ull,0x3009090a20333030ull,0x3034306530306478ull,
0x3065306378302064ull,0x3278302030383730ull,0x2039303038333230ull,0x6666666666307830ull,
0x783009090a203732ull,0x3930343065303064ull,0x3030323038783020ull,0x3061783020303837ull,
0x3020646639303030ull,0x6337383130633078ull,0x31783009090a2038ull,0x2033303038393230ull,
0x3230303030307830ull,0x3230327830203038ull,0x7830203930303833ull,0x3732666666666630ull,
0x3031783009090a20ull,0x3020313030303130ull,0x3030303030303078ull,0x6530306478302033ull,
0x6178302031303430ull,0x2030383730303230ull,0x303031783009090aull,0x7830206430386630ull,
0x3038376333303430ull,0x3837323031783020ull,0x3030783020393030ull,0x0a20373030303030ull,
0x3030303278300909ull,0x3078302031303464ull,0x2030383763303234ull,0x3638313030327830ull,
0x3030307830206430ull,0x090a203330303030ull,0x3030303030783009ull,0x3063783020353036ull,
0x3020303837303030ull,0x3130386333303278ull,0x3030303078302035ull,0x09090a2033356630ull,
0x3033303034317830ull,0x3030327830203530ull,0x7830203038373030ull,0x3130383030303031ull,
0x6333303030783020ull,0x3009090a20303837ull,0x3032303030306178ull,0x3130633078302039ull,
0x6478302030633738ull,0x2031306130653030ull,0x3730303230617830ull,0x783009090a203038ull,
0x3130363838313032ull,0x3030303030783020ull,0x3031783020333030ull,0x3020333030343932ull,
0x3031303030303078ull,0x33783009090a2030ull,0x2064663130613830ull,0x3734303463367830ull,
0x3230317830203863ull,0x7830203330303838ull,0x3038323030303030ull,0x3032783009090a20ull,
0x3020393034643030ull,0x3837633032343078ull,0x3030303178302030ull,0x3078302031303030ull,
0x2033303030303030ull,0x333032783009090aull,0x7830203930343863ull,0x3335663030303030ull,
0x3065303064783020ull,0x3061783020313034ull,0x0a20303837303032ull,0x3032313278300909ull,
0x3078302064303466ull,0x2037303030303030ull,0x3630653030647830ull,0x6330387830203130ull,
0x090a203038373030ull,0x6634313132783009ull,0x3030783020393034ull,0x3020373030303030ull,
0x3034306530306478ull,0x3063303878302039ull,0x09090a2030383730ull,0x3030633030337830ull,
0x3134637830203531ull,0x7830203038373030ull,0x3130303062303033ull,0x3030313463783020ull,
0x3009090a20303837ull,0x3061383030303278ull,0x3030313278302030ull,0x3278302030303466ull,
0x2031303038303030ull,0x3030303030307830ull,0x783009090a206232ull,0x3930303065303064ull,
0x3030633061783020ull,0x3064783020303837ull,0x3020313036306530ull,0x3837303063303878ull,
0x33783009090a2030ull,0x2039303030633030ull,0x3730303134637830ull,0x3030337830203038ull,
0x7830203130303062ull,0x3038373030313463ull,0x3032783009090a20ull,0x3020303034383030ull,
0x3034663030313278ull,0x3330303178302038ull,0x3078302031303038ull,0x2033303030303030ull,
0x303032783009090aull,0x7830203930343834ull,0x6232303030303030ull,0x3065303064783020ull,
0x3061783020313034ull,0x0a20303837303063ull,0x3030303178300909ull,0x3478302031306530ull,
0x2032383763303034ull,0x3030313030347830ull,0x3030307830203930ull,0x090a203038373030ull,
0x3030303036783009ull,0x3030783020393032ull,0x3020303837383030ull,0x3034303031303378ull,
0x3031346378302039ull,0x09090a2030383730ull,0x3030303030367830ull,0x3030307830203130ull,
0x7830203038373830ull,0x6434303031303033ull,0x3030313463783020ull,0x3009090a20303837ull,
0x3436326130303378ull,0x3031636578302039ull,0x3378302030383730ull,0x2064663532633730ull,
0x3763303063367830ull,0x783009090a203863ull,0x3330303463323031ull,0x3030303030783020ull,
0x3033783020303832ull,0x3020313436323230ull,0x3837303031636578ull,0x32783009090a2030ull,
0x2031303032303030ull,0x3763343034307830ull,0x3030347830203038ull,0x7830203930303039ull,
0x3038373030303030ull,0x3036783009090a20ull,0x3020393032303830ull,0x3837383030303078ull,
0x3031303378302030ull,0x6378302039303430ull,0x2030383730303134ull,0x303036783009090aull,
0x7830203130303038ull,0x3038373830303030ull,0x3032303033783020ull,0x3463783020313030ull,
0x0a20303837303031ull,0x3230303378300909ull,0x6378302035343832ull,0x2030383730303134ull,
0x3866303030317830ull,0x3034307830203930ull,0x090a203038376333ull,0x6330303032783009ull,
0x3430783020313038ull,0x3020303837303032ull,0x3034306130303378ull,0x3031346378302064ull,
0x09090a2030383730ull,0x3232303030327830ull,0x3034307830203531ull,0x7830203038376330ull,
0x3930343831303032ull,0x3030303030783020ull,0x3009090a20333030ull,0x3030383130303178ull,
0x3031303078302064ull,0x3278302033313031ull,0x2035313030303030ull,0x3734313034307830ull,
0x783009090a203038ull,0x6466353232303033ull,0x3431306336783020ull,0x3064783020386337ull,
0x3020643061306530ull,0x3837303063306178ull,0x31783009090a2030ull,0x2033303062623230ull,
0x3230303030307830ull,0x3230317830203038ull,0x7830203330303663ull,0x3038373030303030ull,
0x3033783009090a20ull,0x3020353438323230ull,0x3837303031346378ull,0x3230303378302030ull,
0x6578302031343632ull,0x2030383730303163ull,0x303033783009090aull,0x7830203930343238ull,
0x3038373030313463ull,0x3030303033783020ull,0x3430783020313034ull,0x0a20303837303430ull,
0x3030303378300909ull,0x3678302064663932ull,0x2038633738313034ull,0x3036643230617830ull,
0x3030307830203330ull,0x090a203030303030ull,0x3664323031783009ull,0x3030783020333030ull,
0x3020303832303030ull,0x3036323030303278ull,0x3430343078302031ull,0x09090a2030383730ull,
0x3031313030347830ull,0x3030307830206430ull,0x7830203038373030ull,0x6430323130303036ull,
0x6330303030783020ull,0x3009090a20303837ull,0x3036303031303378ull,0x3031346378302064ull,
0x3678302030383730ull,0x2031303031303030ull,0x3763303030307830ull,0x783009090a203038ull,
0x3930343030303032ull,0x3035303430783020ull,0x3033783020303837ull,0x3020313030303230ull,
0x3837303031346378ull,0x33783009090a2030ull,0x2039303430323030ull,0x3730303134637830ull,
0x3031327830203038ull,0x7830203030386530ull,0x3830303832303032ull,0x3031783009090a20ull,
0x3020313030383130ull,0x3130313031303078ull,0x6530306478302033ull,0x6178302031303430ull,
0x2030383730306330ull,0x373033783009090aull,0x7830203130383263ull,0x3263373830303436ull,
0x3030303061783020ull,0x6330783020646631ull,0x0a20386537343130ull,0x3030303078300909ull,
0x3278302039333030ull,0x2030383732303030ull,0x3030663230617830ull,0x3030307830203330ull,
0x090a203030303030ull,0x3066323031783009ull,0x3030783020333030ull,0x3020303031303030ull,
0x3032643030303278ull,0x3132343078302031ull,0x09090a2030383730ull,0x3631303030307830ull,
0x3234657830203130ull,0x7830203038373030ull,0x6430303830333031ull,0x3030303030783020ull,
0x3009090a20333030ull,0x3130383130303178ull,0x3030303078302035ull,0x3078302033303030ull,
0x2035303630303030ull,0x3730303030637830ull,0x783009090a203038ull,0x3130303030303430ull,
0x3030303034783020ull,0x3032783020303837ull,0x3020313030386333ull,0x6666666666663078ull,
0x30783009090a2066ull,0x2039303030303030ull,0x3730303030637830ull,0x3138337830203038ull,
0x7830203130306365ull,0x3038373030333465ull,0x3031783009090a20ull,0x3020393030383532ull,
0x3938373063363078ull,0x3030386478302037ull,0x3078302031303063ull,0x2030383738303234ull,
0x303034783009090aull,0x7830203132303035ull,0x3038373030303030ull,0x3034303036783020ull,
0x3030783020313232ull,0x0a20303837303230ull,0x3031303378300909ull,0x6378302031323031ull,
0x2030383730303134ull,0x3030343030367830ull,0x3030307830203130ull,0x090a203038373032ull,
0x3834303032783009ull,0x3030783020643036ull,0x3020333030303030ull,0x3030303030303278ull,
0x3130343078302031ull,0x09090a2030383734ull,0x3730623830337830ull,0x3434367830206466ull,
0x7830203863373431ull,0x3130303030303430ull,0x3030323465783020ull,0x3009090a20303837ull,
0x3161383130303278ull,0x3030303078302035ull,0x3178302033303030ull,0x2033303066643230ull,
0x3230303030307830ull,0x783009090a203038ull,0x3130303030303066ull,0x3030303065783020ull,
0x3638783020323030ull,0x3020333065666631ull,0x3030303030303078ull,0x33783009090a2030ull,
0x2064663164633730ull,0x3763303263367830ull,0x3530317830203863ull,0x7830203330303033ull,
0x3038323030303030ull,0x3031783009090a20ull,0x3020393065303030ull,0x3837633030343478ull,
0x3030303278302030ull,0x3078302031303632ull,0x2030383730343034ull,0x303032783009090aull,
0x7830203531656330ull,0x3038373830323430ull,0x3039303034783020ull,0x3034783020633030ull,
0x0a20303234313530ull,0x3830303678300909ull,0x3078302064303230ull,0x2030383763303030ull,
0x3631343030367830ull,0x3030307830203132ull,0x090a203038373032ull,0x3030313033783009ull,
0x3463783020643036ull,0x3020303837303031ull,0x3230313031303378ull,0x3031346378302031ull,
0x09090a2030383730ull,0x3861363030327830ull,0x3030307830206432ull,0x7830206631303030ull,
0x3130303038303036ull,0x6330303030783020ull,0x3009090a20303837ull,0x3032616332303278ull,
0x3030303078302064ull,0x3678302033303030ull,0x2039353431343030ull,0x3730323030307830ull,
0x783009090a203038ull,0x6466373130393033ull,0x6330346336783020ull,0x3033783020386437ull,
0x3020313030303230ull,0x3837303031346378ull,0x30783009090a2030ull,0x2035303630303030ull,
0x3730303030637830ull,0x3830337830203038ull,0x7830206466393263ull,0x3863376330343436ull,
0x3031783009090a20ull,0x3020643538663030ull,0x3837633330343078ull,0x3030303278302030ull,
0x3078302064333863ull,0x2030383730303234ull,0x383033783009090aull,0x7830206466393264ull,
0x3865373430343436ull,0x3030303030783020ull,0x3032783020643230ull,0x0a20303837323030ull,
0x6538303378300909ull,0x3678302064663932ull,0x2038653763303434ull,0x3030303030307830ull,
0x3030327830203133ull,0x090a203038373230ull,0x3266383033783009ull,0x3436783020646639ull,
0x3020386537343034ull,0x3330303030303078ull,0x3030303278302035ull,0x09090a2030383732ull,
0x3038313330617830ull,0x3030307830203330ull,0x7830203030303030ull,0x3330303831333031ull,
0x3030303030783020ull,0x3009090a20303031ull,0x3030633139346478ull,0x3036343078302031ull,
0x6478302030383730ull,0x2039303263323934ull,0x3730303634307830ull,0x783009090a203038ull,
0x3130303032303064ull,0x3430303430783020ull,0x3464783020303837ull,0x3020393038366330ull,
0x3837303030303278ull,0x33783009090a2030ull,0x2039303030313030ull,0x3730303134657830ull,
0x3038647830203038ull,0x7830203930306332ull,0x3038373830323430ull,0x3064783009090a20ull,
0x3020313030303038ull,0x3837303034343078ull,0x3339306478302030ull,0x3078302035353430ull,
0x2030383738303434ull,0x303061783009090aull,0x7830206466313030ull,0x3865373431306332ull,
0x3030303031783020ull,0x3430783020353534ull,0x0a20303033653330ull,0x3030306678300909ull,
0x6578302031303030ull,0x2032303030303030ull,0x6566663136387830ull,0x3030307830203330ull,
0x090a203030303030ull,0x3030303430783009ull,0x3465783020313030ull,0x3020303836343532ull,
0x3065666631363878ull,0x3030303078302033ull,0x09090a2030303030ull,0x3038323330617830ull,
0x3030307830203330ull,0x7830203030303030ull,0x3330303832333031ull,0x3030303030783020ull,
0x3009090a20303031ull,0x3038313730346478ull,0x3030303278302039ull,0x6478302030383730ull,
0x2031303063313938ull,0x3730303634307830ull,0x783009090a203038ull,0x3930326332393864ull,
0x3030363430783020ull,0x3064783020303837ull,0x3020313030303230ull,0x3837343030343078ull,
0x33783009090a2030ull,0x2039303030313030ull,0x3730303134657830ull,0x3034647830203038ull,
0x7830203930306332ull,0x3038373830323430ull,0x3064783009090a20ull,0x3020313030303038ull,
0x3837303034343078ull,0x3339306478302030ull,0x3078302035353430ull,0x2030383738303434ull,
0x303061783009090aull,0x7830206466313030ull,0x3865373431306332ull,0x3030303031783020ull,
0x3430783020353534ull,0x0a20303033653330ull,0x3030306678300909ull,0x6578302031303030ull,
0x2032303030303030ull,0x6566663136387830ull,0x3030307830203330ull,0x090a203030303030ull,
0x6331303430783009ull,0x3465783020313036ull,0x3020303836343532ull,0x3065666631363878ull,
0x3030303078302033ull,0x09090a2030303030ull,0x3039333330617830ull,0x3030307830203330ull,
0x7830203030303030ull,0x3330303933333031ull,0x3130303030783020ull,0x3009090a20303031ull,
0x3030336530346478ull,0x3030303278302039ull,0x6478302030383730ull,0x2031303063313938ull,
0x3730303634307830ull,0x783009090a203038ull,0x3930326332393864ull,0x3030363430783020ull,
0x3064783020303837ull,0x3020313030303230ull,0x3837343030343078ull,0x64783009090a2030ull,
0x2039303831373034ull,0x3730303030327830ull,0x3030337830203038ull,0x7830203930303031ull,
0x3038373030313465ull,0x3864783009090a20ull,0x3020393030633230ull,0x3837383032343078ull,
0x3038306478302030ull,0x3078302031303030ull,0x2030383730303434ull,0x393064783009090aull,
0x7830203535343033ull,0x3038373830343430ull,0x3030303061783020ull,0x6332783020646631ull,
0x0a20386537343130ull,0x3030303178300909ull,0x3078302035353430ull,0x2030303365333034ull,
0x3030303030667830ull,0x3030657830203130ull,0x090a203230303030ull,0x6666313638783009ull,
0x3030783020333065ull,0x3020303030303030ull,0x3063383330343078ull,0x3532346578302031ull,
0x09090a2030383635ull,0x6566663136387830ull,0x3030307830203330ull,0x7830203030303030ull,
0x3330306334333061ull,0x3030303030783020ull,0x3009090a20303030ull,0x3063313030303078ull,
0x3030306178302031ull,0x3178302030653730ull,0x2033303063343330ull,0x3132303030307830ull,
0x783009090a203030ull,0x3930306433313064ull,0x3030303032783020ull,0x3064783020303837ull,
0x3020313036643239ull,0x3837303036343078ull,0x64783009090a2030ull,0x2039303063313938ull,
0x3730303634307830ull,0x3030647830203038ull,0x7830203535303032ull,0x3038373430303430ull,
0x3064783009090a20ull,0x3020393038626330ull,0x3837303030303278ull,0x3130303378302030ull,
0x6578302031306132ull,0x2030383730303134ull,0x303864783009090aull,0x7830206430306330ull,
0x3038373830323430ull,0x3230383064783020ull,0x3430783020393061ull,0x0a20303837303034ull,
0x3339306478300909ull,0x3078302031303630ull,0x2030383738303434ull,0x3530303030617830ull,
0x3063327830206466ull,0x090a203865373431ull,0x3030303031783009ull,0x3430783020313036ull,
0x3020303033653330ull,0x3034663430303078ull,0x3032346578302031ull,0x09090a2030383730ull,
0x3030303030667830ull,0x3030657830203130ull,0x7830203230303030ull,0x3330656666313638ull,
0x3030303030783020ull,0x3009090a20303030ull,0x3030653030353178ull,0x3030303178302030ull,
0x3278302038306361ull,0x2033303030633530ull,0x3730303030307830ull,0x783009090a203038ull,
0x3930613262303033ull,0x3030313465783020ull,0x3064783020303837ull,0x3020393034303531ull,
0x3837383030343078ull,0x33783009090a2030ull,0x2064303430373030ull,0x3730303134637830ull,
0x3930647830203038ull,0x7830206430363034ull,0x3038373030343430ull,0x3064783009090a20ull,
0x3020393034303330ull,0x3837383030343078ull,0x6630303378302030ull,0x6378302064303430ull,
0x2030383730303134ull,0x393064783009090aull,0x7830206430363035ull,0x3038373030343430ull,
0x3033303064783020ull,0x3430783020393034ull,0x0a20303837383030ull,0x3231303378300909ull,
0x6578302064303430ull,0x2030383730303134ull,0x3430333030647830ull,0x3034307830203535ull,
0x090a203038373830ull,0x6438333061783009ull,0x3030783020333030ull,0x3020303030303030ull,
0x3630303030303178ull,0x3330343078302031ull,0x09090a2030383763ull,0x3631303030307830ull,
0x3030617830203130ull,0x7830203065373030ull,0x3330306338333031ull,0x3230303030783020ull,
0x3009090a20303031ull,0x3065653030313178ull,0x3030303178302038ull,0x3278302030303062ull,
0x2033303066643530ull,0x3730303030307830ull,0x783009090a203038ull,0x3830303830303031ull,
0x6530303131783020ull,0x3031783020303265ull,0x3020313030333030ull,0x3837633330343078ull,
0x32783009090a2030ull,0x2033303030303630ull,0x3730303030307830ull,0x3330327830203038ull,
0x7830203132613866ull,0x6666666666666630ull,0x3032783009090a20ull,0x3020353034386633ull,
0x6666666666663078ull,0x6337303378302066ull,0x3678302064663530ull,0x2038653738303063ull,
0x303031783009090aull,0x7830203530303130ull,0x3038326533303430ull,0x3830303031783020ull,
0x3031783020383130ull,0x0a20633032383030ull,0x3038306478300909ull,0x3078302064663530ull,
0x2038653730303434ull,0x6563303031327830ull,0x3634307830206431ull,0x090a203038366535ull,
0x3030303132783009ull,0x3430783020313063ull,0x3020303836323034ull,0x3163303730303378ull,
0x3130633678302064ull,0x09090a2030383636ull,0x3030373030647830ull,0x3034307830206431ull,
0x7830203038363230ull,0x6431633030303031ull,0x6533303430783020ull,0x3009090a20303031ull,
0x3065303030303178ull,0x3030343478302031ull,0x3478302030383763ull,0x2034326330313030ull,
0x3230343030347830ull,0x783009090a203832ull,0x3532653030303036ull,0x3432303030783020ull,
0x3036783020303837ull,0x3020393230303530ull,0x3837383230303078ull,0x33783009090a2030ull,
0x2035323231303130ull,0x3730303134637830ull,0x3130337830203038ull,0x7830203932343130ull,
0x3038373030313463ull,0x3036783009090a20ull,0x3020643063303030ull,0x3837343230303078ull,
0x3430303678302030ull,0x3078302035323030ull,0x2030383738323030ull,0x303032783009090aull,
0x7830203030653833ull,0x6330323936303032ull,0x3132303033783020ull,0x6336783020393130ull,
0x0a20303837343130ull,0x3130303278300909ull,0x3078302031323438ull,0x2033303030303030ull,
0x6531303030327830ull,0x3034307830203130ull,0x090a203038373030ull,0x3065303064783009ull,
0x3038783020313030ull,0x3020303837303032ull,0x3065313030303278ull,0x3030343078302039ull,
0x09090a2030383763ull,0x3430653030647830ull,0x3230387830203930ull,0x7830203038373030ull,
0x3931303136303064ull,0x3030303430783020ull,0x3009090a20303837ull,0x3238303030306178ull,
0x3130633078302039ull,0x6178302030383738ull,0x2035323030303030ull,0x3738313063307830ull,
0x783009090a203038ull,0x6466353163373033ull,0x3031306336783020ull,0x3033783020386537ull,
0x3020646633316337ull,0x6532323130633678ull,0x31783009090a2038ull,0x2033303061383330ull,
0x3132303030307830ull,0x3930647830203030ull,0x7830203130633236ull,0x3038373030343430ull,
0x3033783009090a20ull,0x3020393036303230ull,0x3837303031346378ull,0x3030303278302030ull,
0x3278302030306539ull,0x2038303038323030ull,0x303032783009090aull,0x7830203130656137ull,
0x3330303030303030ull,0x3065303064783020ull,0x3061783020313034ull,0x0a20303837303063ull,
0x3130303178300909ull,0x3078302031303038ull,0x2033303030303030ull,0x3064383330317830ull,
0x3030307830203330ull,0x090a203038373030ull,0x6630303031783009ull,0x3430783020313038ull,
0x3020303837633330ull,0x3030643833303178ull,0x3030303078302033ull,0x09090a2030383730ull,
0x3866303030317830ull,0x3034307830203130ull,0x7830203038376333ull,0x3130303030303066ull,
0x3030303065783020ull,0x3009090a20323030ull,0x3065666631363878ull,0x3030303078302033ull,
0x6178302030303030ull,0x2033303061623330ull,0x3030303030307830ull,0x783009090a203030ull,
0x3130303063373033ull,0x3431306336783020ull,0x3061783020306537ull,0x3020646631303030ull,
0x6637343130633078ull,0x31783009090a2038ull,0x2033303061623330ull,0x3132303030307830ull,
0x3031317830203030ull,0x7830203830656530ull,0x3030306230303031ull,0x3032783009090a20ull,
0x3020333030666435ull,0x3837303030303078ull,0x3730303278302030ull,0x3078302039306561ull,
0x2033303030303030ull,0x383064783009090aull,0x7830206430343030ull,0x3038373030343430ull,
0x3030383064783020ull,0x3430783020313030ull,0x0a20303837303034ull,0x6233306178300909ull,
0x3078302033303039ull,0x2030303030303030ull,0x3730303030337830ull,0x3063367830206466ull,
0x090a203865373830ull,0x3662333031783009ull,0x3030783020333030ull,0x3020303832323030ull,
0x3065303030303178ull,0x3030343478302031ull,0x09090a2030383763ull,0x3430313030347830ull,
0x3030307830206430ull,0x7830203038373030ull,0x6430363030303036ull,0x6330303030783020ull,
0x3009090a20303837ull,0x3036303031303378ull,0x3031346378302064ull,0x3678302030383730ull,
0x2064303430303030ull,0x3763303030307830ull,0x783009090a203038ull,0x3130633236393064ull,
0x3030343430783020ull,0x3032783020303837ull,0x3020303236383730ull,0x3030386630303278ull,
0x33783009090a2063ull,0x2031303031323030ull,0x3730303134637830ull,0x3030327830203038ull,
0x7830203130363030ull,0x3038373030303430ull,0x3064783009090a20ull,0x3020313030306530ull,
0x3837303063303878ull,0x3230303378302030ull,0x3678302064663130ull,0x2038653738303063ull,
0x333031783009090aull,0x7830203330303862ull,0x3038323230303030ull,0x3030303031783020ull,
0x3434783020313065ull,0x0a20303837633030ull,0x3130303478300909ull,0x3078302031323831ull,
0x2030383730303030ull,0x6131303030367830ull,0x3030307830203132ull,0x090a203038373032ull,
0x3130313033783009ull,0x3463783020313230ull,0x3020303837303031ull,0x3238313030303678ull,
0x3230303078302031ull,0x09090a2030383730ull,0x6538383030327830ull,0x3031327830203030ull,
0x7830203032656538ull,0x3130303032303033ull,0x3030313463783020ull,0x3009090a20303837ull,
0x3230313230303378ull,0x3031346378302031ull,0x3278302030383730ull,0x2031303038633330ull,
0x6666666666307830ull,0x783009090a206666ull,0x6466663063373033ull,0x3830306336783020ull,
0x3132783020386537ull,0x3020313030313030ull,0x3832613534343078ull,0x32783009090a2030ull,
0x2031303030303030ull,0x3763303034307830ull,0x3030647830203038ull,0x7830203130303065ull,
0x3038373030633038ull,0x3033783009090a20ull,0x3020646631303230ull,0x6537383030633678ull,
0x6233303178302038ull,0x3078302033303038ull,0x2030383232303030ull,0x303031783009090aull,
0x7830203130303831ull,0x3330303030303030ull,0x3962333031783020ull,0x3030783020333030ull,
0x0a20303837303030ull,0x3030303178300909ull,0x3078302031303866ull,0x2030383763333034ull,
0x3130633730337830ull,0x3063367830206466ull,0x090a206166373431ull,0x3030303066783009ull,
0x3065783020313030ull,0x3020323030303030ull,0x3030316433306178ull,0x3030303078302033ull,
0x09090a2030303030ull,0x3031643330317830ull,0x3030307830203330ull,0x7830203030313330ull,
0x3830656530303131ull,0x6230303031783020ull,0x3009090a20303030ull,0x3030666435303278ull,
0x3030303078302033ull,0x3178302030383730ull,0x2063303038303030ull,0x6565303031317830ull,
0x783009090a203032ull,0x3130303330303031ull,0x6333303430783020ull,0x3032783020303837ull,
0x3020333030303036ull,0x3837303030303078ull,0x31783009090a2030ull,0x2039306530303030ull,
0x3763303034347830ull,0x3330327830203038ull,0x7830203132323966ull,0x6666666666666630ull,
0x3034783009090a20ull,0x3020343634303530ull,0x3638303730303478ull,0x3430303678302038ull,
0x3078302035363630ull,0x2030383734363030ull,0x303036783009090aull,0x7830203936613036ull,
0x3038373836303030ull,0x3330313033783020ull,0x3463783020353632ull,0x0a20303837303031ull,
0x3031303378300909ull,0x6378302039363433ull,0x2030383730303134ull,0x3430343030367830ull,
0x3030307830203536ull,0x090a203038373436ull,0x3036303036783009ull,0x3030783020393038ull,
0x3020303837383630ull,0x3032623730303278ull,0x3030303278302063ull,0x09090a2034363438ull,
0x3439663330327830ull,0x6666307830203130ull,0x7830206666666666ull,0x6330653933303032ull,
0x3230303031783020ull,0x3009090a20303130ull,0x3036306530306478ull,0x3032306178302039ull,
0x3278302030383730ull,0x2039306531303030ull,0x3734363034307830ull,0x783009090a203038ull,
0x3130343065303064ull,0x3030323061783020ull,0x3066783020303837ull,0x3020313030303030ull,
0x3030303030306578ull,0x38783009090a2032ull,0x2033306566663136ull,0x3030303030307830ull,
0x3330617830203030ull,0x7830203330303066ull,0x3030303030303030ull,0x3031783009090a20ull,
0x3020333030306633ull,0x3031333030303078ull,0x3030303178302030ull,0x3178302030303062ull,
0x2038306565303031ull,0x353032783009090aull,0x7830203330306664ull,0x3038373030303030ull,
0x3830303031783020ull,0x3131783020633030ull,0x0a20303265653030ull,0x3030303178300909ull,
0x3078302031303033ull,0x2030383763333034ull,0x3030303630327830ull,0x3030307830203330ull,
0x090a203038373030ull,0x3030303031783009ull,0x3434783020393065ull,0x3020303837633030ull,
0x3261303630303478ull,0x3030303078302031ull,0x09090a2030383730ull,0x3830373030367830ull,
0x3030307830203132ull,0x7830203038373032ull,0x3132303130313033ull,0x3030313463783020ull,
0x3009090a20303837ull,0x3238303630303678ull,0x3230303078302031ull,0x3278302030383730ull,
0x2064303030303030ull,0x3730323034307830ull,0x783009090a203038ull,0x3136656566333132ull,
0x6666666630783020ull,0x3032783020666666ull,0x3020643036383130ull,0x3030303030303078ull,
0x33783009090a2033ull,0x2064663133303030ull,0x3734313063367830ull,0x3030317830203865ull,
0x7830206430303130ull,0x3030356533303430ull,0x3034783009090a20ull,0x3020313038313530ull,
0x3837303030303078ull,0x3430303678302030ull,0x3078302031306131ull,0x2030383730303030ull,
0x313033783009090aull,0x7830203130303030ull,0x3038373030313463ull,0x3134303036783020ull,
0x3030783020313038ull,0x0a20303837303030ull,0x3730303278300909ull,0x3278302030303038ull,
0x2038303038663030ull,0x3430653030647830ull,0x3230387830203130ull,0x090a203038373030ull,
0x3031303032783009ull,0x3030783020313030ull,0x3020333030303030ull,0x3034306530306478ull,
0x3032306178302031ull,0x09090a2030383730ull,0x6531303030327830ull,0x3034307830203930ull,
0x7830203038376330ull,0x3130343065303064ull,0x3030323038783020ull,0x3009090a20303837ull,
0x3030303130303278ull,0x3030303078302031ull,0x6478302033303030ull,0x2031303430653030ull,
0x3730303230617830ull,0x783009090a203038ull,0x3130303030303066ull,0x3030303065783020ull,
0x3638783020323030ull,0x3020333065666631ull,0x3030303030303078ull,0x64783009090a2030ull,
0x2039303030383034ull,0x3730303030327830ull,0x3039317830203038ull,0x7830203030306530ull,
0x3830636130303031ull,0x3032783009090a20ull,0x3020333030306335ull,0x3837303030303078ull,
0x3234306178302030ull,0x3078302033303038ull,0x2030303030303030ull,0x303031783009090aull,
0x7830203136303030ull,0x3038376333303430ull,0x3130303030783020ull,0x3061783020313036ull,
0x0a20306537303030ull,0x3234303178300909ull,0x3078302033303037ull,0x2030303132303030ull,
0x6565303031317830ull,0x3030317830203830ull,0x090a203030306230ull,0x6664353032783009ull,
0x3030783020333030ull,0x3020303837303030ull,0x3030383030303178ull,0x3030313178302038ull,
0x09090a2030326565ull,0x3033303030317830ull,0x3034307830203130ull,0x7830203038376333ull,
0x3330303030363032ull,0x3030303030783020ull,0x3009090a20303837ull,0x3261386633303278ull,
0x6666663078302031ull,0x3278302066666666ull,0x2035303438663330ull,0x6666666666307830ull,
0x783009090a206666ull,0x6466353063373033ull,0x3830306336783020ull,0x3031783020386537ull,
0x3020353030313030ull,0x3832653330343078ull,0x31783009090a2030ull,0x2038313038303030ull,
0x3238303030317830ull,0x3830647830206330ull,0x7830206466353030ull,0x3865373030343430ull,
0x3132783009090a20ull,0x3020643165633030ull,0x3836653536343078ull,0x3030313278302030ull,
0x3078302031306330ull,0x2030383632303434ull,0x303033783009090aull,0x7830206431633037ull,
0x3038363631306336ull,0x3037303064783020ull,0x3430783020643130ull,0x0a20303836323030ull,
0x3030303178300909ull,0x3078302064316330ull,0x2030303165333034ull,0x6530303030317830ull,
0x3034347830203130ull,0x090a203038376330ull,0x3031303034783009ull,0x3034783020343263ull,
0x3020383232303430ull,0x3265303030303678ull,0x3230303078302035ull,0x09090a2030383734ull,
0x3030353030367830ull,0x3030307830203932ull,0x7830203038373832ull,0x3532323130313033ull,
0x3030313463783020ull,0x3009090a20303837ull,0x3234313031303378ull,0x3031346378302039ull,
0x3678302030383730ull,0x2064306330303030ull,0x3734323030307830ull,0x783009090a203038ull,
0x3532303034303036ull,0x3832303030783020ull,0x3032783020303837ull,0x3020303065383330ull,
0x3032393630303278ull,0x33783009090a2063ull,0x2039313430383030ull,0x3734313063367830ull,
0x3030327830203038ull,0x7830203132343831ull,0x3330303030303030ull,0x3032783009090a20ull,
0x3020313065313030ull,0x3837303030343078ull,0x6530306478302030ull,0x3878302031303030ull,
0x2030383730303230ull,0x303032783009090aull,0x7830203930653130ull,0x3038376330303430ull,
0x3065303064783020ull,0x3038783020393034ull,0x0a20303837303032ull,0x3630306478300909ull,
0x3078302039313031ull,0x2030383730303034ull,0x3830303030617830ull,0x3063307830203932ull,
0x090a203038373831ull,0x3030303061783009ull,0x6330783020353230ull,0x3020303837383130ull,
0x6635316337303378ull,0x3130633678302064ull,0x09090a2038653730ull,0x3331633730337830ull,
0x3063367830206466ull,0x7830203865323231ull,0x3330303532343031ull,0x3230303030783020ull,
0x3009090a20303031ull,0x3063323639306478ull,0x3034343078302031ull,0x3378302030383730ull,
0x2039303630323030ull,0x3730303134637830ull,0x783009090a203038ull,0x3030653930303032ull,
0x3832303032783020ull,0x3032783020383030ull,0x3020313065616230ull,0x3030303030303078ull,
0x64783009090a2033ull,0x2031303430653030ull,0x3730306330617830ull,0x3030317830203038ull,
0x7830203130303831ull,0x3330303030303030ull,0x3031783009090a20ull,0x3020333030383234ull,
0x3837303030303078ull,0x3030303178302030ull,0x3078302031303866ull,0x2030383763333034ull,
0x343031783009090aull,0x7830203330303832ull,0x3038373030303030ull,0x6630303031783020ull,
0x3430783020313038ull,0x0a20303837633330ull,0x3030306678300909ull,0x6578302031303030ull,
0x2032303030303030ull,0x6566663136387830ull,0x3030307830203330ull,0x090a203030303030ull,
0x3535343061783009ull,0x3030783020333030ull,0x3020303030303030ull,0x3030306337303378ull,
0x3130633678302031ull,0x09090a2030653734ull,0x3130303030617830ull,0x3063307830206466ull,
0x7830203866373431ull,0x3330303535343031ull,0x3230303030783020ull,0x3009090a20303031ull,
0x3065653030313178ull,0x3030303178302038ull,0x3278302030303062ull,0x2033303066643530ull,
0x3730303030307830ull,0x783009090a203038ull,0x3930656162303032ull,0x3030303030783020ull,
0x3064783020333030ull,0x3020643034303038ull,0x3837303034343078ull,0x64783009090a2030ull,
0x2031303030303830ull,0x3730303434307830ull,0x3430617830203038ull,0x7830203330303435ull,
0x3030303030303030ull,0x3033783009090a20ull,0x3020646637303030ull,0x6537383030633678ull,
0x3534303178302038ull,0x3078302033303031ull,0x2030383232303030ull,0x303031783009090aull,
0x7830203130653030ull,0x3038376330303434ull,0x3031303034783020ull,0x3030783020643034ull,
0x0a20303837303030ull,0x3030303678300909ull,0x3078302064303630ull,0x2030383763303030ull,
0x3630303130337830ull,0x3134637830206430ull,0x090a203038373030ull,0x3030303036783009ull,
0x3030783020643034ull,0x3020303837633030ull,0x3063323639306478ull,0x3034343078302031ull,
0x09090a2030383730ull,0x3638373030327830ull,0x3030327830203032ull,0x7830206330303866ull,
0x3130303132303033ull,0x3030313463783020ull,0x3009090a20303837ull,0x3036303030303278ull,
0x3030343078302031ull,0x6478302030383730ull,0x2031303030653030ull,0x3730306330387830ull,
0x783009090a203038ull,0x6466313032303033ull,0x3830306336783020ull,0x3031783020386537ull,
0x3020333030333534ull,0x3832323030303078ull,0x31783009090a2030ull,0x2031306530303030ull,
0x3763303034347830ull,0x3030347830203038ull,0x7830203132383131ull,0x3038373030303030ull,
0x3036783009090a20ull,0x3020313261313030ull,0x3837303230303078ull,0x3031303378302030ull,
0x6378302031323031ull,0x2030383730303134ull,0x303036783009090aull,0x7830203132383130ull,
0x3038373032303030ull,0x3838303032783020ull,0x3132783020303065ull,0x0a20303265653830ull,
0x3230303378300909ull,0x6378302031303030ull,0x2030383730303134ull,0x3031323030337830ull,
0x3134637830203132ull,0x090a203038373030ull,0x3863333032783009ull,0x6630783020313030ull,
0x3020666666666666ull,0x6666306337303378ull,0x3030633678302064ull,0x09090a2038653738ull,
0x3031303031327830ull,0x3434307830203130ull,0x7830203038326135ull,0x3130303030303032ull,
0x6330303430783020ull,0x3009090a20303837ull,0x3030306530306478ull,0x3063303878302031ull,
0x3378302030383730ull,0x2064663130323030ull,0x3738303063367830ull,0x783009090a203865ull,
0x3330303335343031ull,0x3230303030783020ull,0x3031783020303832ull,0x3020313030383130ull,
0x3030303030303078ull,0x31783009090a2033ull,0x2033303034353430ull,0x3730303030307830ull,
0x3030317830203038ull,0x7830203130386630ull,0x3038376333303430ull,0x3033783009090a20ull,
0x3020646631306337ull,0x6637343130633678ull,0x3030306678302061ull,0x6578302031303030ull,
0x2032303030303030ull,0x343061783009090aull,0x7830203330306336ull,0x3030303030303030ull,
0x6336343031783020ull,0x3030783020333030ull,0x0a20303031333030ull,0x3030313178300909ull,
0x3178302038306565ull,0x2030303062303030ull,0x3066643530327830ull,0x3030307830203330ull,
0x090a203038373030ull,0x3830303031783009ull,0x3131783020633030ull,0x3020303265653030ull,
0x3030333030303178ull,0x3330343078302031ull,0x09090a2030383763ull,0x3030303630327830ull,
0x3030307830203330ull,0x7830203038373030ull,0x3930653030303031ull,0x6330303434783020ull,
0x3009090a20303837ull,0x3232396633303278ull,0x6666663078302031ull,0x3478302066666666ull,
0x2034363430353030ull,0x3830373030347830ull,0x783009090a203836ull,0x3536363034303036ull,
0x3436303030783020ull,0x3036783020303837ull,0x3020393661303630ull,0x3837383630303078ull,
0x33783009090a2030ull,0x2035363233303130ull,0x3730303134637830ull,0x3130337830203038ull,
0x7830203936343330ull,0x3038373030313463ull,0x3036783009090a20ull,0x3020353634303430ull,
0x3837343630303078ull,0x3630303678302030ull,0x3078302039303830ull,0x2030383738363030ull,
0x303032783009090aull,0x7830206330326237ull,0x3436343830303032ull,0x3966333032783020ull,
0x6630783020313034ull,0x0a20666666666666ull,0x3330303278300909ull,0x3178302063306539ull,
0x2030313032303030ull,0x3630653030647830ull,0x3230617830203930ull,0x090a203038373030ull,
0x3130303032783009ull,0x3430783020393065ull,0x3020303837343630ull,0x3034306530306478ull,
0x3032306178302031ull,0x09090a2030383730ull,0x3030303030667830ull,0x3030657830203130ull,
0x7830203230303030ull,0x3330656666313638ull,0x3030303030783020ull,0x3009090a20303030ull,
0x3030623834306178ull,0x3030303078302033ull,0x3178302030303030ull,0x2033303062383430ull,
0x3133303030307830ull,0x783009090a203030ull,0x3830656530303131ull,0x6230303031783020ull,
0x3032783020303030ull,0x3020333030666435ull,0x3837303030303078ull,0x31783009090a2030ull,
0x2038303038303030ull,0x6565303031317830ull,0x3030317830203032ull,0x7830203130303330ull,
0x3038376333303430ull,0x3032783009090a20ull,0x3020333030303036ull,0x3837303030303078ull,
0x3030303178302030ull,0x3478302064306530ull,0x2030383763303034ull,0x303034783009090aull,
0x7830203132653034ull,0x3038373030303030ull,0x3035303036783020ull,0x3030783020313263ull,
0x0a20303837303230ull,0x3031303378300909ull,0x6378302031323031ull,0x2030383730303134ull,
0x6330343030367830ull,0x3030307830203132ull,0x090a203038373032ull,0x3030303032783009ull,
0x3430783020393030ull,0x3020303837303230ull,0x3665656633313278ull,0x6666663078302035ull,
0x09090a2066666666ull,0x3438313030327830ull,0x3030307830203930ull,0x7830203330303030ull,
0x6466313039313033ull,0x3431306336783020ull,0x3009090a20386537ull,0x3030313030303178ull,
0x3330343078302039ull,0x3478302030303565ull,0x2031303831373030ull,0x3730303030307830ull,
0x783009090a203038ull,0x3130613136303036ull,0x3030303030783020ull,0x3033783020303837ull,
0x3020313030303031ull,0x3837303031346378ull,0x36783009090a2030ull,0x2031303831363030ull,
0x3730303030307830ull,0x3030327830203038ull,0x7830203030303837ull,0x6330303866303032ull,
0x3064783009090a20ull,0x3020313036306530ull,0x3837303032303878ull,0x3130303278302030ull,
0x3078302031303030ull,0x2033303030303030ull,0x303064783009090aull,0x7830203130363065ull,
0x3038373030323061ull,0x3130303032783020ull,0x3430783020393065ull,0x0a20303837383030ull,
0x6530306478300909ull,0x3878302031303430ull,0x2030383730303230ull,0x3030313030327830ull,
0x3030307830203130ull,0x090a203330303030ull,0x3065303064783009ull,0x3061783020313034ull,
0x3020303837303032ull,0x3030303030306678ull,0x3030306578302031ull,0x09090a2032303030ull,
0x6566663136387830ull,0x3030307830203330ull,0x7830203030303030ull,0x3330303439343061ull,
0x3030303030783020ull,0x3009090a20303030ull,0x3038313030303078ull,0x3030306178302031ull,
0x3178302030653730ull,0x2033303034393430ull,0x3132303030307830ull,0x783009090a203030ull,
0x3930303030313464ull,0x3030303032783020ull,0x3931783020303837ull,0x3020303030653030ull,
0x3063613030303178ull,0x32783009090a2038ull,0x2033303030633530ull,0x3730303030307830ull,
0x3030317830203038ull,0x7830203136303030ull,0x3038376333303430ull,0x3066783009090a20ull,
0x3020313030303030ull,0x3030303030306578ull,0x6334306178302032ull,0x3078302033303037ull,
0x2030303030303030ull,0x303030783009090aull,0x7830203130613130ull,0x3065373030303061ull,
0x3663343031783020ull,0x3030783020333030ull,0x0a20303031323030ull,0x3030313178300909ull,
0x3178302038306565ull,0x2030303062303030ull,0x3066643530327830ull,0x3030307830203330ull,
0x090a203038373030ull,0x3830303031783009ull,0x3131783020383030ull,0x3020303265653030ull,
0x3030333030303178ull,0x3330343078302031ull,0x09090a2030383763ull,0x3030303630327830ull,
0x3030307830203330ull,0x7830203038373030ull,0x3132613866333032ull,0x6666666630783020ull,
0x3009090a20666666ull,0x3034386633303278ull,0x6666663078302035ull,0x3378302066666666ull,
0x2064663530633730ull,0x3738303063367830ull,0x783009090a203865ull,0x3530303130303031ull,
0x6533303430783020ull,0x3031783020303832ull,0x3020383130383030ull,0x3032383030303178ull,
0x64783009090a2063ull,0x2064663530303830ull,0x3730303434307830ull,0x3031327830203865ull,
0x7830206431656330ull,0x3038366535363430ull,0x3132783009090a20ull,0x3020313063303030ull,
0x3836323034343078ull,0x3730303378302030ull,0x3678302064316330ull,0x2030383636313063ull,
0x303064783009090aull,0x7830206431303037ull,0x3038363230303430ull,0x3030303031783020ull,
0x3430783020643163ull,0x0a20303031653330ull,0x3030303178300909ull,0x3478302031306530ull,
0x2030383763303034ull,0x6330313030347830ull,0x3030347830203432ull,0x090a203832323034ull,
0x3030303036783009ull,0x3030783020353265ull,0x3020303837343230ull,0x3230303530303678ull,
0x3230303078302039ull,0x09090a2030383738ull,0x3231303130337830ull,0x3134637830203532ull,
0x7830203038373030ull,0x3932343130313033ull,0x3030313463783020ull,0x3009090a20303837ull,
0x3063303030303678ull,0x3230303078302064ull,0x3678302030383734ull,0x2035323030343030ull,
0x3738323030307830ull,0x783009090a203038ull,0x3030653833303032ull,0x3936303032783020ull,
0x3033783020633032ull,0x3020393134303830ull,0x3837343130633678ull,0x32783009090a2030ull,
0x2031323438313030ull,0x3030303030307830ull,0x3030327830203330ull,0x7830203130653130ull,
0x3038373030303430ull,0x3064783009090a20ull,0x3020313030306530ull,0x3837303032303878ull,
0x3030303278302030ull,0x3078302039306531ull,0x2030383763303034ull,0x303064783009090aull,
0x7830203930343065ull,0x3038373030323038ull,0x3136303064783020ull,0x3430783020393130ull,
0x0a20303837303030ull,0x3030306178300909ull,0x3078302039323830ull,0x2030383738313063ull,
0x3030303030617830ull,0x3063307830203532ull,0x090a203038373831ull,0x3163373033783009ull,
0x6336783020646635ull,0x3020386537303130ull,0x6633316337303378ull,0x3130633678302064ull,
0x09090a2038653232ull,0x3034633430317830ull,0x3030307830203330ull,0x7830203030313230ull,
0x3130633236393064ull,0x3030343430783020ull,0x3009090a20303837ull,0x3036303230303378ull,
0x3031346378302039ull,0x3278302030383730ull,0x2030306539303030ull,0x3038323030327830ull,
0x783009090a203830ull,0x3130656164303032ull,0x3030303030783020ull,0x3064783020333030ull,
0x3020313034306530ull,0x3837303063306178ull,0x31783009090a2030ull,0x2031303038313030ull,
0x3030303030307830ull,0x3430317830203330ull,0x7830203330303763ull,0x3038373030303030ull,
0x3031783009090a20ull,0x3020313038663030ull,0x3837633330343078ull,0x6334303178302030ull,
0x3078302033303037ull,0x2030383730303030ull,0x303031783009090aull,0x7830203130386630ull,
0x3038376333303430ull,0x3030303066783020ull,0x3065783020313030ull,0x0a20323030303030ull,
0x6631363878300909ull,0x3078302033306566ull,0x2030303030303030ull,0x3034663430617830ull,
0x3030307830203330ull,0x090a203030303030ull,0x3063373033783009ull,0x6336783020313030ull,
0x3020306537343130ull,0x6631303030306178ull,0x3130633078302064ull,0x09090a2038663734ull,
0x3034663430317830ull,0x3030307830203330ull,0x7830203030313230ull,0x3830656530303131ull,
0x6230303031783020ull,0x3009090a20303030ull,0x3030666435303278ull,0x3030303078302033ull,
0x3278302030383730ull,0x2039306561643030ull,0x3030303030307830ull,0x783009090a203330ull,
0x6430343030383064ull,0x3030343430783020ull,0x3064783020303837ull,0x3020313030303038ull,
0x3837303034343078ull,0x61783009090a2030ull,0x2033303033663430ull,0x3030303030307830ull,
0x3030337830203030ull,0x7830206466373030ull,0x3865373830306336ull,0x3031783009090a20ull,
0x3020333030306634ull,0x3832323030303078ull,0x3030303178302030ull,0x3478302031306530ull,
0x2030383763303034ull,0x303034783009090aull,0x7830206430343031ull,0x3038373030303030ull,
0x3030303036783020ull,0x3030783020643036ull,0x0a20303837633030ull,0x3031303378300909ull,
0x6378302064303630ull,0x2030383730303134ull,0x3430303030367830ull,0x3030307830206430ull,
0x090a203038376330ull,0x3236393064783009ull,0x3430783020313063ull,0x3020303837303034ull,
0x3236383730303278ull,0x6630303278302030ull,0x09090a2063303038ull,0x3031323030337830ull,
0x3134637830203130ull,0x7830203038373030ull,0x3130363030303032ull,0x3030303430783020ull,
0x3009090a20303837ull,0x3030306530306478ull,0x3063303878302031ull,0x3378302030383730ull,
0x2064663130323030ull,0x3738303063367830ull,0x783009090a203865ull,0x3330303266343031ull,
0x3230303030783020ull,0x3031783020303832ull,0x3020313065303030ull,0x3837633030343478ull,
0x34783009090a2030ull,0x2031323831313030ull,0x3730303030307830ull,0x3030367830203038ull,
0x7830203132613130ull,0x3038373032303030ull,0x3033783009090a20ull,0x3020313230313031ull,
0x3837303031346378ull,0x3030303678302030ull,0x3078302031323831ull,0x2030383730323030ull,
0x303032783009090aull,0x7830203030653838ull,0x3032656538303132ull,0x3032303033783020ull,
0x3463783020313030ull,0x0a20303837303031ull,0x3230303378300909ull,0x6378302031323031ull,
0x2030383730303134ull,0x3038633330327830ull,0x6666307830203130ull,0x090a206666666666ull,
0x3063373033783009ull,0x6336783020646666ull,0x3020386537383030ull,0x3030313030313278ull,
0x3534343078302031ull,0x09090a2030383261ull,0x3030303030327830ull,0x3034307830203130ull,
0x7830203038376330ull,0x3130303065303064ull,0x3030633038783020ull,0x3009090a20303837ull,
0x6631303230303378ull,0x3030633678302064ull,0x3178302038653738ull,0x2033303032663430ull,
0x3232303030307830ull,0x783009090a203038ull,0x3130303831303031ull,0x3030303030783020ull,
0x3031783020333030ull,0x3020333030336634ull,0x3837303030303078ull,0x31783009090a2030ull,
0x2031303866303030ull,0x3763333034307830ull,0x3730337830203038ull,0x7830206466313063ull,
0x6166373431306336ull,0x3066783009090a20ull,0x3020313030303030ull,0x3030303030306578ull,
0x3035306178302032ull,0x3078302033303062ull,0x2030303030303030ull,0x353031783009090aull,
0x7830203330306230ull,0x3030313330303030ull,0x6530303131783020ull,0x3031783020383065ull,
0x0a20303030623030ull,0x6435303278300909ull,0x3078302033303066ull,0x2030383730303030ull,
0x3038303030317830ull,0x3031317830206330ull,0x090a203032656530ull,0x3330303031783009ull,
0x3430783020313030ull,0x3020303837633330ull,0x3030303036303278ull,0x3030303078302033ull,
0x09090a2030383730ull,0x6530303030317830ull,0x3034347830203930ull,0x7830203038376330ull,
0x3132323966333032ull,0x6666666630783020ull,0x3009090a20666666ull,0x3634303530303478ull,
0x3730303478302034ull,0x3678302038363830ull,0x2035363630343030ull,0x3734363030307830ull,
0x783009090a203038ull,0x3936613036303036ull,0x3836303030783020ull,0x3033783020303837ull,
0x3020353632333031ull,0x3837303031346378ull,0x33783009090a2030ull,0x2039363433303130ull,
0x3730303134637830ull,0x3030367830203038ull,0x7830203536343034ull,0x3038373436303030ull,
0x3036783009090a20ull,0x3020393038303630ull,0x3837383630303078ull,0x3730303278302030ull,
0x3278302063303262ull,0x2034363438303030ull,0x333032783009090aull,0x7830203130343966ull,
0x6666666666666630ull,0x3933303032783020ull,0x3031783020633065ull,0x0a20303130323030ull,
0x6530306478300909ull,0x6178302039303630ull,0x2030383730303230ull,0x6531303030327830ull,
0x3034307830203930ull,0x090a203038373436ull,0x3065303064783009ull,0x3061783020313034ull,
0x3020303837303032ull,0x3030303030306678ull,0x3030306578302031ull,0x09090a2032303030ull,
0x6566663136387830ull,0x3030307830203330ull,0x7830203030303030ull,0x3330306132353061ull,
0x3030303030783020ull,0x3009090a20303030ull,0x3030613235303178ull,0x3030303078302033ull,
0x3178302030303133ull,0x2030303062303030ull,0x6565303031317830ull,0x783009090a203830ull,
0x3330306664353032ull,0x3030303030783020ull,0x3031783020303837ull,0x3020633030383030ull,
0x3265653030313178ull,0x31783009090a2030ull,0x2031303033303030ull,0x3763333034307830ull,
0x3630327830203038ull,0x7830203330303030ull,0x3038373030303030ull,0x3031783009090a20ull,
0x3020393065303030ull,0x3837633030343478ull,0x3630303478302030ull,0x3078302031326130ull,
0x2030383730303030ull,0x303036783009090aull,0x7830203132383037ull,0x3038373032303030ull,
0x3130313033783020ull,0x3463783020313230ull,0x0a20303837303031ull,0x3630303678300909ull,
0x3078302031323830ull,0x2030383730323030ull,0x3030303030327830ull,0x3034307830206430ull,
0x090a203038373032ull,0x6566333132783009ull,0x6630783020313665ull,0x3020666666666666ull,
0x3036383130303278ull,0x3030303078302064ull,0x09090a2033303030ull,0x3130383130337830ull,
0x3063367830206466ull,0x7830203865373431ull,0x6430303130303031ull,0x6533303430783020ull,
0x3009090a20303035ull,0x3038313530303478ull,0x3030303078302031ull,0x3678302030383730ull,
0x2031306131343030ull,0x3730303030307830ull,0x783009090a203038ull,0x3130303030313033ull,
0x3030313463783020ull,0x3036783020303837ull,0x3020313038313430ull,0x3837303030303078ull,
0x32783009090a2030ull,0x2030303038373030ull,0x3038663030327830ull,0x3030647830203830ull,
0x7830203130343065ull,0x3038373030323038ull,0x3032783009090a20ull,0x3020313030303130ull,
0x3030303030303078ull,0x6530306478302033ull,0x6178302031303430ull,0x2030383730303230ull,
0x303032783009090aull,0x7830203930653130ull,0x3038376330303430ull,0x3065303064783020ull,
0x3038783020313034ull,0x0a20303837303032ull,0x3130303278300909ull,0x3078302031303030ull,
0x2033303030303030ull,0x3430653030647830ull,0x3230617830203130ull,0x090a203038373030ull,
0x3030303066783009ull,0x3065783020313030ull,0x3020323030303030ull,0x3065666631363878ull,
0x3030303078302033ull,0x09090a2030303030ull,0x6561383330327830ull,0x3030307830206435ull,
0x7830203331303030ull,0x6466316437313033ull,0x3031326336783020ull,0x3009090a20386537ull,
0x3030633033303178ull,0x3030303078302033ull,0x3178302030383232ull,0x2033303032333530ull,
0x3730303030307830ull,0x783009090a203038ull,0x3130326163323032ull,0x3030303030783020ull,
0x3030783020333030ull,0x3020353030303030ull,0x3837303030306378ull,0x32783009090a2030ull,
0x2064663532303031ull,0x3763353434307830ull,0x3030317830203863ull,0x7830203130386630ull,
0x3038376333303430ull,0x3031783009090a20ull,0x3020353138663030ull,0x3837633330343078ull,
0x3635303178302030ull,0x3078302033303037ull,0x2030383930303030ull,0x303032783009090aull,
0x7830203530363230ull,0x3038373034303430ull,0x3039303034783020ull,0x3030783020393034ull,
0x0a20303837303030ull,0x3830303678300909ull,0x3078302039303630ull,0x2030383738303030ull,
0x3430303130337830ull,0x3134637830203930ull,0x090a203038373030ull,0x3038303036783009ull,
0x3030783020353034ull,0x3020303837383030ull,0x3032303230303378ull,0x3031346378302035ull,
0x09090a2030383730ull,0x3866303030317830ull,0x3034307830203931ull,0x7830203038376333ull,
0x6431386330303032ull,0x3430323430783020ull,0x3009090a20303837ull,0x3063306130303378ull,
0x3031346378302035ull,0x3278302030383730ull,0x2034303261313030ull,0x6538313030327830ull,
0x783009090a203430ull,0x3530323065303064ull,0x3030633038783020ull,0x3064783020303837ull,
0x3020643032303839ull,0x3837303034343078ull,0x33783009090a2030ull,0x2039303230383030ull,
0x3730303163657830ull,0x3130337830203038ull,0x7830203932323030ull,0x3038373030316365ull,
0x3034783009090a20ull,0x3020353263303730ull,0x3837303030303078ull,0x3030303378302030ull,
0x3878302031323630ull,0x2030383730303063ull,0x393064783009090aull,0x7830203930343038ull,
0x3038373030343430ull,0x3036303036783020ull,0x3030783020353265ull,0x0a20303837343230ull,
0x3831303378300909ull,0x6578302031303230ull,0x2030383730303163ull,0x3431383930647830ull,
0x3434307830203530ull,0x090a203038373030ull,0x3035303034783009ull,0x3030783020393238ull,
0x3020303837303030ull,0x3030303839306478ull,0x3034343078302031ull,0x09090a2030383730ull,
0x3231303130337830ull,0x3134637830203532ull,0x7830203038373030ull,0x6432613034303036ull,
0x3832303030783020ull,0x3009090a20303837ull,0x3234303330303478ull,0x3030303078302039ull,
0x3678302030383730ull,0x2064306330363030ull,0x3734323030307830ull,0x783009090a203038ull,
0x6432363130313033ull,0x3030313463783020ull,0x3036783020303837ull,0x3020393236303230ull,
0x3837383230303078ull,0x34783009090a2030ull,0x2035323030313030ull,0x3730303030307830ull,
0x3030617830203038ull,0x7830206430363030ull,0x3038373431303434ull,0x3036783009090a20ull,
0x3020643238303430ull,0x3837633230303078ull,0x3031303378302030ull,0x6378302039323431ull,
0x2030383730303134ull,0x303036783009090aull,0x7830203532323030ull,0x3038373432303030ull,
0x3030303062783020ull,0x3030783020313336ull,0x0a20303837343130ull,0x3030306178300909ull,
0x3478302064323631ull,0x2030383734313034ull,0x3430323030367830ull,0x3030307830203531ull,
0x090a203038373832ull,0x3130313033783009ull,0x3463783020643032ull,0x3020303837303031ull,
0x3234303830303378ull,0x3030633878302035ull,0x09090a2030383730ull,0x3631303030627830ull,
0x3030307830203132ull,0x7830203038373033ull,0x3531613030303061ull,0x3431303434783020ull,
0x3009090a20303837ull,0x3030303030303678ull,0x3030303078302039ull,0x3278302030383763ull,
0x2039316338313030ull,0x3030303030307830ull,0x783009090a203330ull,0x3532323039303033ull,
0x3030306338783020ull,0x3062783020303837ull,0x3020643061303030ull,0x3837303230303078ull,
0x61783009090a2030ull,0x2035303430303030ull,0x3734313034347830ull,0x3030337830203038ull,
0x7830206466353236ull,0x3863373431306336ull,0x3033783009090a20ull,0x3020313030303930ull,
0x3837303030633878ull,0x3030306278302030ull,0x3078302035313230ull,0x2030383763303030ull,
0x353031783009090aull,0x7830203330306533ull,0x3038323030303030ull,0x3238393064783020ull,
0x3430783020353030ull,0x0a20303837303034ull,0x6633303278300909ull,0x3078302035303238ull,
0x2066666666666666ull,0x3932313030337830ull,0x3034367830206466ull,0x090a203863373031ull,
0x6139353061783009ull,0x3030783020333030ull,0x3020303030303030ull,0x3030613935303178ull,
0x3030303078302033ull,0x09090a2030383230ull,0x3632303030327830ull,0x3034307830203530ull,
0x7830203038373034ull,0x3930303133303034ull,0x3030303030783020ull,0x3009090a20303837ull,
0x3032313230303678ull,0x3030303078302039ull,0x3378302030383738ull,0x2039303430303130ull,
0x3730303134637830ull,0x783009090a203038ull,0x6430343238303033ull,0x3030313463783020ull,
0x3036783020303837ull,0x3020353030313230ull,0x3837383030303078ull,0x32783009090a2030ull,
0x2039303832303030ull,0x3763303034307830ull,0x3030337830203038ull,0x7830203530323032ull,
0x3038373030313463ull,0x3033783009090a20ull,0x3020393034303230ull,0x3837303031346378ull,
0x3130313278302030ull,0x3278302034303865ull,0x2034303238323030ull,0x303064783009090aull,
0x7830203530323065ull,0x3038373030633038ull,0x3038393064783020ull,0x3430783020643032ull,
0x0a20303837303034ull,0x3830303378300909ull,0x6578302064313230ull,0x2030383730303163ull,
0x3230303130337830ull,0x3163657830203132ull,0x090a203038373030ull,0x3037303034783009ull,
0x3030783020393063ull,0x3020303837303030ull,0x3136303030303378ull,0x3030633878302039ull,
0x09090a2030383730ull,0x6530383930647830ull,0x3434307830203130ull,0x7830203038373030ull,
0x6431653036303036ull,0x3830303030783020ull,0x3009090a20303837ull,0x3032303831303378ull,
0x3031636578302035ull,0x6478302030383730ull,0x2039303031383930ull,0x3730303434307830ull,
0x783009090a203038ull,0x3132303031303034ull,0x3030303030783020ull,0x3064783020303837ull,
0x3020353032303839ull,0x3837303034343078ull,0x33783009090a2030ull,0x2064316530303130ull,
0x3730303134637830ull,0x3030367830203038ull,0x7830203532323030ull,0x3038373032303030ull,
0x3034783009090a20ull,0x3020313238303530ull,0x3837303030303078ull,0x3630303678302030ull,
0x3078302064306330ull,0x2030383763313030ull,0x313033783009090aull,0x7830203532323130ull,
0x3038373030313463ull,0x3034303036783020ull,0x3030783020313261ull,0x0a20303837303230ull,
0x3330303478300909ull,0x3078302064313430ull,0x2030383730303030ull,0x3630303030617830ull,
0x3034347830206430ull,0x090a203038373431ull,0x3030303036783009ull,0x3030783020353230ull,
0x3020303837343230ull,0x3230313031303378ull,0x3031346378302031ull,0x09090a2030383730ull,
0x3630323030367830ull,0x3030307830206431ull,0x7830203038376331ull,0x3932363030303062ull,
0x3431303030783020ull,0x3009090a20303837ull,0x3232313030306178ull,0x3130343478302035ull,
0x3678302030383734ull,0x2035313830343030ull,0x3730323030307830ull,0x783009090a203038ull,
0x6430653030313033ull,0x3030313463783020ull,0x3033783020303837ull,0x3020643130303630ull,
0x3837303030633878ull,0x62783009090a2030ull,0x2039313231303030ull,0x3738323030307830ull,
0x3030617830203038ull,0x7830203531613030ull,0x3038373431303434ull,0x3036783009090a20ull,
0x3020313034303230ull,0x3837633030303078ull,0x3730303378302030ull,0x3878302064313430ull,
0x2030383730303063ull,0x303062783009090aull,0x7830206430613030ull,0x3038373831303030ull,
0x3030303061783020ull,0x3434783020393030ull,0x0a20303837343130ull,0x3730303378300909ull,
0x3878302031303230ull,0x2030383730303063ull,0x3430303030627830ull,0x3030307830203531ull,
0x090a203038376330ull,0x3030303430783009ull,0x3465783020313030ull,0x3020323837343132ull,
0x3030303230343078ull,0x3032346578302031ull,0x09090a2030383730ull,0x6566663136387830ull,
0x3030307830203330ull,0x7830203030303030ull,0x3530303830303031ull,0x3030303030783020ull,
0x3009090a20623030ull,0x6633303431303378ull,0x3030343678302064ull,0x6178302038633763ull,
0x2033303062613530ull,0x3030303030307830ull,0x783009090a203030ull,0x3330306261353031ull,
0x3030303030783020ull,0x3032783020303832ull,0x3020313032303030ull,0x3837303530343078ull,
0x30783009090a2030ull,0x2039303030323030ull,0x3730303030637830ull,0x3035317830203038ull,
0x7830203030306530ull,0x3030363730303962ull,0x3430783009090a20ull,0x3020313030303030ull,
0x3837303032346578ull,0x3830386478302030ull,0x3278302039303835ull,0x2030383730303030ull,
0x303464783009090aull,0x7830206430303038ull,0x3038373030303032ull,0x3030303831783020ull,
0x3434783020313030ull,0x0a20303837633030ull,0x3030633378300909ull,0x3678302064663163ull,
0x2038633738313234ull,0x3030303038317830ull,0x3034347830203130ull,0x090a203038376330ull,
0x3032303430783009ull,0x3465783020313030ull,0x3020303035303032ull,0x3030303030306678ull,
0x3030306578302031ull,0x09090a2032303030ull,0x6566663136387830ull,0x3030307830203330ull,
0x7830203030303030ull,0x3530323031303033ull,0x3030316365783020ull,0x3009090a20303837ull,
0x6633306337303378ull,0x3130633678302064ull,0x3178302038633730ull,0x2033303065393530ull,
0x3230303030307830ull,0x783009090a203038ull,0x3130633130303030ull,0x3030303061783020ull,
0x3033783020306537ull,0x3020333030303030ull,0x3031323030303078ull,0x61783009090a2030ull,
0x2039303632303030ull,0x3734313034347830ull,0x3930627830203038ull,0x7830206466353039ull,
0x3863373031353036ull,0x3033783009090a20ull,0x3020353038303230ull,0x3837303031346378ull,
0x3030303178302030ull,0x3478302031303631ull,0x2030383763303034ull,0x393063783009090aull,
0x7830203130303063ull,0x3038363030343030ull,0x3063393063783020ull,0x3030783020393034ull,
0x0a20303836303034ull,0x3030303978300909ull,0x3078302039303430ull,0x2030383730303030ull,
0x3030323031657830ull,0x3430307830203930ull,0x090a203038373836ull,0x6330303032783009ull,
0x3430783020313061ull,0x3020303837343032ull,0x3038353830306478ull,0x3030303278302035ull,
0x09090a2030383730ull,0x3030653030647830ull,0x6330617830203930ull,0x7830203038373030ull,
0x3430636531303132ull,0x6530303531783020ull,0x3009090a20303030ull,0x3032306530306478ull,
0x3063306178302031ull,0x3378302030383730ull,0x2033303030303030ull,0x3730303030307830ull,
0x783009090a203038ull,0x6430343030303061ull,0x3430303434783020ull,0x3039783020303837ull,
0x3020313236303030ull,0x3837303030303078ull,0x61783009090a2030ull,0x2064303030303030ull,
0x3734363034347830ull,0x3330327830203038ull,0x7830203132303965ull,0x6666666666666630ull,
0x3063783009090a20ull,0x3020643036303830ull,0x6537633030303078ull,0x3030306178302030ull,
0x3878302064303630ull,0x2030383734363034ull,0x303034783009090aull,0x7830203136633035ull,
0x3038373030303030ull,0x3034303036783020ull,0x3030783020313665ull,0x0a20303837303630ull,
0x3031303378300909ull,0x6378302031363033ull,0x2030383730303134ull,0x6330343030367830ull,
0x3030307830203136ull,0x090a203038373036ull,0x3030343032783009ull,0x3430783020313630ull,
0x3020303837303630ull,0x3630333030306178ull,0x3630343478302031ull,0x09090a2030383734ull,
0x3033383030637830ull,0x3030307830203132ull,0x7830203065376330ull,0x3132303130303061ull,
0x3436303438783020ull,0x3009090a20303837ull,0x3036303030303278ull,0x3230343078302064ull,
0x3478302030383730ull,0x2031326330353030ull,0x3730303030307830ull,0x783009090a203038ull,
0x3132653034303036ull,0x3032303030783020ull,0x3033783020303837ull,0x3020313230313031ull,
0x3837303031346378ull,0x36783009090a2030ull,0x2031326330343030ull,0x3730323030307830ull,
0x3030337830203038ull,0x7830203132303130ull,0x3038373030303430ull,0x3033783009090a20ull,
0x3020313234303830ull,0x3837633030343678ull,0x3030303378302030ull,0x3078302064303031ull,
0x2030383763303034ull,0x303034783009090aull,0x7830203132633035ull,0x3038373030303030ull,
0x3034303036783020ull,0x3030783020313265ull,0x0a20303837303230ull,0x3031303378300909ull,
0x6378302031323031ull,0x2030383730303134ull,0x6330343030367830ull,0x3030307830206430ull,
0x090a203038373032ull,0x3030303033783009ull,0x3430783020313036ull,0x3020303837303030ull,
0x6635306337303378ull,0x3130343678302064ull,0x09090a2038653734ull,0x3030323030647830ull,
0x3034307830203130ull,0x7830203030356532ull,0x3330303030303033ull,0x3230303030783020ull,
0x3009090a20303837ull,0x3030303030306678ull,0x3030306578302031ull,0x6178302030303030ull,
0x2064303430303030ull,0x3734313134307830ull,0x783009090a203038ull,0x3132363030303061ull,
0x3430303434783020ull,0x3061783020303837ull,0x3020353630303030ull,0x3837343131343078ull,
0x39783009090a2030ull,0x2064363031303030ull,0x3730303030307830ull,0x3030617830203038ull,
0x7830203132323330ull,0x3038373436303434ull,0x3032783009090a20ull,0x3020643636626533ull,
0x6666666666663078ull,0x6231306378302066ull,0x3078302031323031ull,0x2030653763303030ull,
0x303061783009090aull,0x7830203132303130ull,0x3038373436303438ull,0x3031313034783020ull,
0x3030783020393663ull,0x0a20303837303030ull,0x3031303678300909ull,0x3078302039366530ull,
0x2030383738363030ull,0x3433303130337830ull,0x3134637830203936ull,0x090a203038373030ull,
0x3030313036783009ull,0x3030783020393663ull,0x3020303837383630ull,0x3632333034303278ull,
0x3630343078302039ull,0x09090a2030383738ull,0x3433303030617830ull,0x3034347830203936ull,
0x7830203038373436ull,0x6436343362313063ull,0x6330303030783020ull,0x3009090a20306537ull,
0x3636333030306178ull,0x3630343878302064ull,0x3278302030383734ull,0x2031323031303030ull,
0x3763363034307830ull,0x783009090a203038ull,0x6436323236303034ull,0x3030303030783020ull,
0x3036783020303837ull,0x3020643630323730ull,0x3837633630303078ull,0x33783009090a2030ull,
0x2064363633303130ull,0x3730303134637830ull,0x3030367830203038ull,0x7830206436303236ull,
0x3038376336303030ull,0x3033783009090a20ull,0x3020353636333030ull,0x3837343630343078ull,
0x3931303378302030ull,0x3678302064303630ull,0x2030383763303034ull,0x303064783009090aull,
0x7830203130343030ull,0x3038373830303430ull,0x3066313033783020ull,0x3465783020313030ull,
0x0a20303837303031ull,0x3030303378300909ull,0x3078302031323630ull,0x2030383730323034ull,
0x3030303030617830ull,0x3063327830206430ull,0x090a203038373431ull,0x3038303064783009ull,
0x3430783020643036ull,0x3020303837383030ull,0x6635306337303378ull,0x3130633678302064ull,
0x09090a2038653734ull,0x3030303030327830ull,0x3034307830203130ull,0x7830203038376330ull,
0x3130303032303064ull,0x6532303430783020ull,0x3009090a20303035ull,0x3030303030303378ull,
0x3030303078302033ull,0x6678302030383732ull,0x2031303030303030ull,0x3030303030657830ull,
0x783009090a203030ull,0x3536303130303061ull,0x3431313430783020ull,0x3061783020303837ull,
0x3020393632333030ull,0x3837343030343478ull,0x61783009090a2030ull,0x2064363030303030ull,
0x3734313134307830ull,0x3030397830203038ull,0x7830203137343330ull,0x3038373030303030ull,
0x3061783009090a20ull,0x3020393636333030ull,0x3837343630343478ull,0x6533303278302030ull,
0x3078302031373862ull,0x2066666666666666ull,0x313063783009090aull,0x7830203936343363ull,
0x3065376330303030ull,0x3330303061783020ull,0x3438783020393634ull,0x0a20303837343630ull,
0x3533303478300909ull,0x3078302035373436ull,0x2030383730303030ull,0x3636343330367830ull,
0x3030307830203537ull,0x090a203038373437ull,0x3330313033783009ull,0x3463783020353761ull,
0x3020303837303031ull,0x3734363433303678ull,0x3730303078302035ull,0x09090a2030383734ull,
0x3633303430327830ull,0x3034307830203537ull,0x7830203038373437ull,0x3537613330303061ull,
0x3436303434783020ull,0x3009090a20303837ull,0x3761336331306378ull,0x3030303078302031ull,
0x6178302030653763ull,0x2031373833303030ull,0x3734363034387830ull,0x783009090a203038ull,
0x3936343330303032ull,0x3037303430783020ull,0x3034783020303837ull,0x3020313761363233ull,
0x3837303030303078ull,0x36783009090a2030ull,0x2031373836333330ull,0x3730373030307830ull,
0x3130337830203038ull,0x7830203137383330ull,0x3038373030313463ull,0x3036783009090a20ull,
0x3020313738363233ull,0x3837303730303078ull,0x3030303378302030ull,0x3078302031373833ull,
0x2030383763363034ull,0x313033783009090aull,0x7830203137323363ull,0x3038376330303436ull,
0x3330303033783020ull,0x3430783020393638ull,0x0a20303837383630ull,0x3233303478300909ull,
0x3078302031376136ull,0x2030383730303030ull,0x3836333330367830ull,0x3030307830203137ull,
0x090a203038373037ull,0x3330313033783009ull,0x3463783020313738ull,0x3020303837303031ull,
0x3638363233303678ull,0x3730303078302035ull,0x09090a2030383730ull,0x3030663130337830ull,
0x3134657830203130ull,0x7830203038373030ull,0x3936323330303033ull,0x6336303430783020ull,
0x3009090a20303837ull,0x3630303030306178ull,0x3130633278302035ull,0x6478302030383734ull,
0x2035363233613130ull,0x3738303034307830ull,0x783009090a203038ull,0x6466313163373033ull,
0x3431306336783020ull,0x3032783020386537ull,0x3020313030303030ull,0x3837343630343078ull,
0x64783009090a2030ull,0x2031303030383030ull,0x3565323034307830ull,0x3030337830203030ull,
0x7830203330303030ull,0x3038373230303030ull,0x3066783009090a20ull,0x3020313030303030ull,
0x3030303030306578ull,0x0a7d0a7d090a2031ull,0x0000000000000000ull
};


}


static __cudaFatPtxEntry __ptxEntries [] = {{(char*)"compute_11",(char*)__deviceText_$compute_11$},{0,0}};
static __cudaFatCubinEntry __cubinEntries[] = {{(char*)"sm_11",(char*)__deviceText_$sm_11$},{0,0}};
static __cudaFatDebugEntry __debugEntries0 = {0, 0, 0, 0} ;



static __cudaFatCudaBinary __fatDeviceText __attribute__ ((section (".nvFatBinSegment")))= {0x1ee55a01,0x00000003,0x8ecc680c,(char*)"81c96ccf2944c37a",(char*)"src/cuda_fi_prerun/main.cu",(char*)" ",__ptxEntries,__cubinEntries,&__debugEntries0,0,0,0,0,0,0xa359ea02};
# 5 "main.cudafe1.stub.c" 2 3
# 1 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 1 3
# 112 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 3
# 1 "/usr/local/cuda/bin/../include/host_defines.h" 1 3
# 113 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2 3
# 139 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 3
extern "C" {


extern void** __cudaRegisterFatBinary(
  void *fatCubin
);

extern void __cudaUnregisterFatBinary(
  void **fatCubinHandle
);

extern void __cudaRegisterVar(
        void **fatCubinHandle,
        char *hostVar,
        char *deviceAddress,
  const char *deviceName,
        int ext,
        int size,
        int constant,
        int global
);

extern void __cudaRegisterTexture(
        void **fatCubinHandle,
  const struct textureReference *hostVar,
  const void **deviceAddress,
  const char *deviceName,
        int dim,
        int norm,
        int ext
);

extern void __cudaRegisterSurface(
        void **fatCubinHandle,
  const struct surfaceReference *hostVar,
  const void **deviceAddress,
  const char *deviceName,
        int dim,
        int ext
);

extern void __cudaRegisterShared(
  void **fatCubinHandle,
  void **devicePtr
);

extern void __cudaRegisterSharedVar(
  void **fatCubinHandle,
  void **devicePtr,
  size_t size,
  size_t alignment,
  int storage
);

extern void __cudaRegisterFunction(
        void **fatCubinHandle,
  const char *hostFun,
        char *deviceFun,
  const char *deviceName,
        int thread_limit,
        uint3 *tid,
        uint3 *bid,
        dim3 *bDim,
        dim3 *gDim,
        int *wSize
);


}




extern int atexit(void(*)(void)) throw();







static void **__cudaFatCubinHandle;

static void __cudaUnregisterBinaryUtil(void)
{
  __cudaUnregisterFatBinary(__cudaFatCubinHandle);
}
# 274 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 3
# 1 "/usr/local/cuda/bin/../include/common_functions.h" 1 3
# 68 "/usr/local/cuda/bin/../include/common_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/crt/func_macro.h" 1 3
# 69 "/usr/local/cuda/bin/../include/common_functions.h" 2 3

static __attribute__((__unused__)) clock_t __cuda_clock(void)
{
  return clock();
}

static __attribute__((__unused__)) void *__cuda_memset(void *s, int c, size_t n)
{
  return memset(s, c, n);
}

static __attribute__((__unused__)) void *__cuda_memcpy(void *d, const void *s, size_t n)
{
  return memcpy(d, s, n);
}
# 93 "/usr/local/cuda/bin/../include/common_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_functions.h" 1 3
# 912 "/usr/local/cuda/bin/../include/math_functions.h" 3
int __cuda_error_not_implememted(void);
# 972 "/usr/local/cuda/bin/../include/math_functions.h" 3
static __attribute__((__unused__)) int __cuda_abs(int a)
{
  return abs(a);
}

static __attribute__((__unused__)) float __cuda_fabsf(float a)
{
  return fabsf(a);
}

static __attribute__((__unused__)) long long int __cuda_llabs(long long int a)
{

  return ::llabs(a);



}

static __attribute__((__unused__)) float __cuda_exp2f(float a)
{
  return exp2f(a);
}

# 1 "/usr/local/cuda/bin/../include/device_functions.h" 1 3
# 442 "/usr/local/cuda/bin/../include/device_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_constants.h" 1 3
# 443 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 2384 "/usr/local/cuda/bin/../include/device_functions.h" 3
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
# 2385 "/usr/local/cuda/bin/../include/device_functions.h" 2 3

static const unsigned char __internal_rcpTab[128] =
{
  0xff, 0xfd, 0xfb, 0xf9, 0xf7, 0xf5, 0xf4, 0xf2,
  0xf0, 0xee, 0xed, 0xeb, 0xe9, 0xe8, 0xe6, 0xe4,
  0xe3, 0xe1, 0xe0, 0xde, 0xdd, 0xdb, 0xda, 0xd8,
  0xd7, 0xd5, 0xd4, 0xd3, 0xd1, 0xd0, 0xcf, 0xcd,
  0xcc, 0xcb, 0xca, 0xc8, 0xc7, 0xc6, 0xc5, 0xc4,
  0xc2, 0xc1, 0xc0, 0xbf, 0xbe, 0xbd, 0xbc, 0xbb,
  0xba, 0xb9, 0xb8, 0xb7, 0xb6, 0xb5, 0xb4, 0xb3,
  0xb2, 0xb1, 0xb0, 0xaf, 0xae, 0xad, 0xac, 0xab,
  0xaa, 0xa9, 0xa8, 0xa8, 0xa7, 0xa6, 0xa5, 0xa4,
  0xa3, 0xa3, 0xa2, 0xa1, 0xa0, 0x9f, 0x9f, 0x9e,
  0x9d, 0x9c, 0x9c, 0x9b, 0x9a, 0x99, 0x99, 0x98,
  0x97, 0x97, 0x96, 0x95, 0x95, 0x94, 0x93, 0x93,
  0x92, 0x91, 0x91, 0x90, 0x8f, 0x8f, 0x8e, 0x8e,
  0x8d, 0x8c, 0x8c, 0x8b, 0x8b, 0x8a, 0x89, 0x89,
  0x88, 0x88, 0x87, 0x87, 0x86, 0x85, 0x85, 0x84,
  0x84, 0x83, 0x83, 0x82, 0x82, 0x81, 0x81, 0x80
};

static const unsigned int __internal_invSqrtCubeTab[96] =
{
  0xfa0bf8fe, 0xee6b28fa, 0xe5f024f7, 0xdaf268f3,
  0xd2f000f0, 0xc890c0ec, 0xc10378e9, 0xb9a758e6,
  0xb4da40e4, 0xadcea0e1, 0xa6f278de, 0xa279c0dc,
  0x9beb48d9, 0x97a5c4d7, 0x916340d4, 0x8d4fc8d2,
  0x895000d0, 0x8563b8ce, 0x818ac0cc, 0x7dc4e8ca,
  0x7a1200c8, 0x7671d8c6, 0x72e440c4, 0x6f6908c2,
  0x6db240c1, 0x6a523cbf, 0x670424bd, 0x6563c0bc,
  0x623028ba, 0x609ce8b9, 0x5d8364b7, 0x5bfd18b6,
  0x58fd40b4, 0x5783a8b3, 0x560e48b2, 0x533000b0,
  0x51c70caf, 0x506238ae, 0x4da4c0ac, 0x4c4c10ab,
  0x4af768aa, 0x49a6b8a9, 0x485a00a8, 0x471134a7,
  0x45cc58a6, 0x434e40a4, 0x4214f8a3, 0x40df88a2,
  0x3fade0a1, 0x3e8000a0, 0x3d55dc9f, 0x3c2f789e,
  0x3c2f789e, 0x3b0cc49d, 0x39edc09c, 0x38d2609b,
  0x37baa89a, 0x36a68899, 0x35960098, 0x34890497,
  0x34890497, 0x337f9896, 0x3279ac95, 0x31774094,
  0x30784893, 0x30784893, 0x2f7cc892, 0x2e84b091,
  0x2d900090, 0x2d900090, 0x2c9eac8f, 0x2bb0b88e,
  0x2bb0b88e, 0x2ac6148d, 0x29dec08c, 0x29dec08c,
  0x28fab08b, 0x2819e88a, 0x2819e88a, 0x273c5889,
  0x273c5889, 0x26620088, 0x258ad487, 0x258ad487,
  0x24b6d886, 0x24b6d886, 0x23e5fc85, 0x23184084,
  0x23184084, 0x224d9883, 0x224d9883, 0x21860882,
  0x21860882, 0x20c18081, 0x20c18081, 0x20000080
};

static __attribute__((__unused__)) float __internal_frcp_kernel (float x,enum cudaRoundMode mode)
{
  unsigned long long prod;
  volatile union __cudart_FloatUintCvt arg;
  unsigned int expo;
  unsigned int sign;
  unsigned f, y;

  arg.f = x;
  sign = arg.i & 0x80000000;
  expo = (arg.i >> 23);
  expo = expo & 0xff;
  f = expo - 1;

  if (f <= 0xFD) {
    y = (arg.i << 8);
    y = y | 0x80000000;

    arg.i = __internal_rcpTab[(y >> 24) - 128];

    f = arg.i * arg.i;
    f = f << 16;
    prod = ((unsigned long long)y) * f;
    arg.i = (arg.i << 24) - (unsigned)(prod >> 32);

    f = arg.i + arg.i;
    prod = ((unsigned long long)y) * f;
    f = (unsigned)(-(int)(prod >> 32));
    prod = ((unsigned long long)arg.i) * f;
    y = y >> 8;

    expo = (2 * 127) - expo - 2;
    arg.i = (unsigned)(prod >> 32);
    if (mode == cudaRoundNearest) {
      arg.i = arg.i >> 6;
    } else {
      arg.i = (arg.i + 32) >> 6;
    }
    if ((int)expo >= 0) {
      f = y * arg.i;
      arg.i = ((expo << 23) + arg.i) | sign;
    } else {

      expo = -(int)expo;
      arg.i = arg.i >> expo;
      f = y * arg.i;
      arg.i = arg.i | sign;
    }
    if (mode == cudaRoundNearest) {
      expo = f + y;
      if ((int)f < 0) f = (unsigned)(-(int)f);
      if ((int)expo < 0) expo = (unsigned)(-(int)expo);
      if (expo < f) arg.i++;
    } else if (mode == cudaRoundZero) {
      if ((int)f > 0) arg.i = arg.i - 1;
    } else if (mode == cudaRoundPosInf) {
      if (((int)f > 0) && sign) arg.i = arg.i - 1;
      if (((int)f < 0) && !sign) arg.i = arg.i + 1;
    } else {
      if (((int)f > 0) && !sign) arg.i = arg.i - 1;
      if (((int)f < 0) && sign) arg.i = arg.i + 1;
    }
    return arg.f;
  } else {

    if (!(arg.i << 1)) {
      arg.i = 0x7F800000 | arg.i;
      return arg.f;
    }

    if ((arg.i << 1) == 0xff000000) {
      arg.i &= 0x80000000;
      return arg.f;
    }

    if ((arg.i << 1) > 0xff000000) {
      arg.i |= 0x00400000;
      return arg.f;
    }

    f = 0;
    arg.i <<= 8;
    do {
      f++;
      arg.i <<= 1;
    } while ((int)arg.i > 0);
    arg.i >>= 8;
    arg.i |= sign;
    arg.f = __internal_frcp_kernel (arg.f, mode);
    expo = ((arg.i << 1) >> 24);
    if ((expo + f) < 255) {
      arg.i = (arg.i + (f << 23));
      return arg.f;
    }
    if (mode == cudaRoundNearest) {
      arg.i = (arg.i & 0x80000000) | 0x7f800000;
    } else if (mode == cudaRoundZero) {
      arg.i = (arg.i & 0x80000000) | 0x7f7fffff;
    } else if (mode == cudaRoundPosInf) {
      arg.i = (arg.i & 0x80000000) | ((sign) ? 0x7f7fffff : 0x7f800000);
    } else {
      arg.i = (arg.i & 0x80000000) | ((sign) ? 0x7f800000 : 0x7f7fffff);
    }
    return arg.f;
  }
}

static __attribute__((__unused__)) float __internal_fsqrt_kernel (float radicand, enum cudaRoundMode mode)

{
  unsigned long long prod;
  volatile union __cudart_FloatUintCvt arg;
  unsigned int expo;
  unsigned int s, f, x;

  arg.f = radicand;
  expo = arg.i >> 23;
  expo = expo & 0xff;
  f = expo - 1;

  if ((arg.i <= 0x80000000) && (f <= 0xFD)) {

    x = (arg.i << 8) | 0x80000000;
    x = x >> (expo & 1);

    arg.i = f = __internal_invSqrtCubeTab[((unsigned)x >> 25) - 32];

    prod = ((unsigned long long)x) * f;
    arg.i = ((arg.i * 3) << 22) - (unsigned)(prod >> 32);

    prod = ((unsigned long long)arg.i) * arg.i;
    s = (unsigned)(prod >> 32);
    prod = ((unsigned long long)x) * s;
    f = 0x30000000 - (unsigned)(prod >> 32);
    prod = ((unsigned long long)f) * arg.i;
    arg.i = (unsigned)(prod >> 32);

    prod = ((unsigned long long)x) * arg.i;
    arg.i = (unsigned)(prod >> 32);
    if (mode == cudaRoundNearest) {
      arg.i = arg.i >> 3;
    } else {
      arg.i = (arg.i + 4) >> 3;
    }
    x = (x << 16) - (arg.i * arg.i);

    if (mode == cudaRoundNearest) {
      f = x - (2 * arg.i + 1);
      if ((int)f < 0) f = (unsigned)(-(int)f);
      if ((int)x < 0) x = (unsigned)(-(int)x);
      if (f < x) arg.i ++;
    } else if ((mode == cudaRoundZero) || (mode == cudaRoundMinInf)) {
      if ((int)x < 0) arg.i--;
    } else if (mode == cudaRoundPosInf) {
      if ((int)x > 0) arg.i++;
    }
    arg.i = arg.i + (((expo + 125) & ~0x1) << 22);
    return arg.f;
  } else {

    if (!(arg.i << 1) || (arg.i == 0x7F800000)) {
      return arg.f;
    }

    if ((arg.i << 1) > 0xFF000000) {
      arg.i |= 0x00400000;
      return arg.f;
    }

    if (arg.i & 0x80000000) {
      arg.i = 0xFFC00000;
      return arg.f;
    }

    x = 0;
    arg.i <<= 8;
    do {
      x++;
      arg.i <<= 1;
    } while ((int)arg.i > 0);
    arg.i >>= 8;
    arg.i += (x & 1) << 23;
    x += (x & 1);
    arg.f = __internal_fsqrt_kernel (arg.f, mode);
    arg.i -= ((x >> 1) << 23);
    return arg.f;
  }
}

static __attribute__((__unused__)) float __internal_fdiv_kernel (float dividend, float divisor, enum cudaRoundMode mode)

{
  unsigned long long prod;
  unsigned r, f, x, y, expox, expoy, sign;
  volatile union __cudart_FloatUintCvt cvtx, cvty, res;

  cvtx.f = dividend;
  cvty.f = divisor;
  expox = ((cvtx.i >> 23) & 0xff) - 1;
  expoy = ((cvty.i >> 23) & 0xff) - 1;
  sign = ((cvtx.i ^ cvty.i) & 0x80000000);

  if ((expox <= 0xFD) && (expoy <= 0xFD)) {
divide:
    expox = expox - expoy + 127 - 1;
    expoy = expox;

    y = (cvty.i << 8) | 0x80000000;
    x = (cvtx.i & 0x00ffffff) | 0x00800000;

    r = __internal_rcpTab[(y >> 24) - 128];

    f = r * r;
    prod = ((unsigned long long)y) * (f << 16);
    r = (r << 24) - (unsigned)(prod >> 32);

    prod = ((unsigned long long)y) * (r << 1);
    f = (unsigned)-(int)(prod >> 32);
    prod = ((unsigned long long)f) * (r << 1);
    r = (unsigned)(prod >> 32);

    prod = ((unsigned long long)x) * (r << 1);

    if (((int)((prod >> 32) << 8)) > 0) {
      expox--;
      prod = prod + prod;
    }
    if (mode == cudaRoundNearest) {

      r = (unsigned)(prod >> 32);
      y = y >> 8;

      if (expox <= 0xFD) {
        int rem0, rem1, inc;

        prod = ((unsigned long long)y) * r;
        x = x << (23 + ((prod >> 32) >> 15));
        rem1 = x - (unsigned)(prod & 0xffffffff);
        rem0 = rem1 - y;
        inc = abs(rem0) < abs(rem1);

        res.i = sign | ((expox << 23) + r + inc);
        return res.f;
      } else if ((int)expox >= 254) {

        res.i = sign | 0x7f800000;
        return res.f;
      } else {

        int shift = -(int)expox;
        if (shift > 23) {

          r = (shift < 25) && ((x != y) || (r > 0x00ff0000));
          res.i = sign | r;
          return res.f;
        }
        if (x == y) {

          shift = -(int)expoy;
          r = 0x00800000 >> shift;
          res.i = sign | r;
          return res.f;
        }
        {
          unsigned long long tempx;
          long long remlo, remhi;

          r = r >> shift;
          prod = ((unsigned long long)y) * r;
          tempx = ((unsigned long long)x) << (23 - shift);
          remlo = 2 * tempx - 2 * prod - y;
          remhi = remlo + 2 * tempx;
          if (remlo < 0) remlo = -remlo;
          if (remhi < 0) remhi = -remhi;
          if (remhi < remlo) tempx = 2 * tempx;
          remlo = tempx - prod;
          remhi = remlo - y;
          if (remlo < 0) remlo = -remlo;
          if (remhi < 0) remhi = -remhi;
          if ((remhi < remlo) || ((remhi == remlo) && (r & 1))) r++;
          res.i = sign | r;
          return res.f;
        }
      }
    } else if (mode == cudaRoundZero) {

      prod += 0x0000000080000000ULL;
      r = (unsigned)(prod >> 32);
      y = y >> 8;

      if (expox <= 0xFD) {
        int rem1;
        prod = ((unsigned long long)y) * r;
        x = x << (23 + ((prod >> 32) >> 15));
        rem1 = x - (unsigned)(prod & 0xffffffff);
        if (rem1 < 0) r--;
        r = (expox << 23) + r;
        if (r == 0x7f800000) r = 0x7f7fffff;
        res.i = sign | r;
        return res.f;
      } else if ((int)expox >= 254) {

        res.i = sign | 0x7f7fffff;
        return res.f;
      } else {

        int shift = -(int)expox;
        if ((x == y) && (shift < 31)) {
          shift = -(int)expoy;
          r = 0x00800000 >> shift;
          res.i = sign | r;
          return res.f;
        }
        if (shift > 23) {
          r = 0;
          res.i = sign | r;
          return res.f;
        }
        {
          unsigned long long tempx;
          long long remlo, remhi;

          r = r >> shift;
          prod = ((unsigned long long)y) * r;
          tempx = ((unsigned long long)x) << (23 - shift);
          remlo = 2 * tempx - 2 * prod - y;
          remhi = remlo + 2 * tempx;
          if (remlo < 0) remlo = -remlo;
          if (remhi < 0) remhi = -remhi;
          if (remhi < remlo) tempx = 2 * tempx;
          remlo = tempx - prod;
          if ((remlo < 0) & (r != 0)) r--;
          res.i = sign | r;
          return res.f;
        }
      }
    } else if (mode == cudaRoundPosInf) {

      prod += 0x0000000080000000ULL;
      r = (unsigned)(prod >> 32);
      y = y >> 8;

      if (expox <= 0xFD) {
        int rem1;
        prod = ((unsigned long long)y) * r;
        x = x << (23 + ((prod >> 32) >> 15));
        rem1 = x - (unsigned)(prod & 0xffffffff);
        if ((rem1 < 0) && (sign)) r--;
        if ((rem1 > 0) && (!sign)) r++;
        r = (expox << 23) + r;
        if ((r == 0x7f800000) && (sign)) r = 0x7f7fffff;
        res.i = sign | r;
        return res.f;
      } else if ((int)expox >= 254) {

        r = sign ? 0x7f7fffff : 0x7f800000;
        res.i = sign | r;
        return res.f;
      } else {

        int shift = -(int)expox;
        if ((x == y) && (shift <= 24)) {
          shift = -(int)expoy;
          r = 0x00800000 >> shift;
          if (r == 0) r = !sign;
          res.i = sign | r;
          return res.f;
        }
        if (shift > 23) {
          r = !sign;
          res.i = sign | r;
          return res.f;
        }
        {
          unsigned long long tempx;
          long long remlo, remhi;

          r = r >> shift;
          prod = ((unsigned long long)y) * r;
          tempx = ((unsigned long long)x) << (23 - shift);
          remlo = 2 * tempx - 2 * prod - y;
          remhi = remlo + 2 * tempx;
          if (remlo < 0) remlo = -remlo;
          if (remhi < 0) remhi = -remhi;
          if (remhi < remlo) tempx = 2 * tempx;
          remlo = tempx - prod;
          if ((remlo < 0) && (r != 0) && (sign)) r--;
          if ((remlo > 0) && (!sign)) r++;
          res.i = sign | r;
          return res.f;
        }
      }
    } else if (mode == cudaRoundMinInf) {

      prod += 0x0000000080000000ULL;
      r = (unsigned)(prod >> 32);
      y = y >> 8;

      if (expox <= 0xFD) {
        int rem1;
        prod = ((unsigned long long)y) * r;
        x = x << (23 + ((prod >> 32) >> 15));
        rem1 = x - (unsigned)(prod & 0xffffffff);
        if ((rem1 < 0) && (!sign)) r--;
        if ((rem1 > 0) && (sign)) r++;
        r = (expox << 23) + r;
        if ((r == 0x7f800000) && (!sign)) r = 0x7f7fffff;
        res.i = sign | r;
        return res.f;
      } else if ((int)expox >= 254) {

        r = sign ? 0x7f800000 : 0x7f7fffff;
        res.i = sign | r;
        return res.f;
      } else {

        int shift = -(int)expox;
        if ((x == y) && (shift <= 24)) {
          shift = -(int)expoy;
          r = 0x00800000 >> shift;
          if (r == 0) r = !!sign;
          res.i = sign | r;
          return res.f;
        }
        if (shift > 23) {
          r = !!sign;
          res.i = sign | r;
          return res.f;
        }
        {
          unsigned long long tempx;
          long long remlo, remhi;

          r = r >> shift;
          prod = ((unsigned long long)y) * r;
          tempx = ((unsigned long long)x) << (23 - shift);
          remlo = 2 * tempx - 2 * prod - y;
          remhi = remlo + 2 * tempx;
          if (remlo < 0) remlo = -remlo;
          if (remhi < 0) remhi = -remhi;
          if (remhi < remlo) tempx = 2 * tempx;
          remlo = tempx - prod;
          if ((remlo < 0) && (r != 0) && (!sign)) r--;
          if ((remlo > 0) && (sign)) r++;
          res.i = sign | r;
          return res.f;
        }
      }
    }
  }
  {
    int xzero, yzero, xinf, yinf, xnan, ynan;

    xnan = (cvtx.i << 1) > 0xff000000;
    ynan = (cvty.i << 1) > 0xff000000;

    if (xnan) {
      res.i = cvtx.i | 0x00400000;
      return res.f;
    }
    if (ynan) {
      res.i = cvty.i | 0x00400000;
      return res.f;
    }
    xzero = (cvtx.i << 1) == 0x00000000;
    yzero = (cvty.i << 1) == 0x00000000;
    xinf = (cvtx.i << 1) == 0xff000000;
    yinf = (cvty.i << 1) == 0xff000000;

    if ((xzero & yzero) | (xinf & yinf)) {
      res.i = 0xffc00000;
      return res.f;
    }

    if (xzero | yinf) {
      res.i = sign;
      return res.f;
    }

    if (yzero | xinf) {
      res.i = sign | 0x7f800000;
      return res.f;
    }

    if ((int)expox < 0) {
      cvtx.i = cvtx.i << 9;
      while ((int)cvtx.i >= 0) {
        expox--;
        cvtx.i = cvtx.i + cvtx.i;
      }
      cvtx.i = cvtx.i >> 8;
    }
    if ((int)expoy < 0) {
      cvty.i = cvty.i << 9;
      while ((int)cvty.i >= 0) {
        expoy--;
        cvty.i = cvty.i + cvty.i;
      }
      cvty.i = cvty.i >> 8;
    }
    goto divide;
  }
}

static __attribute__((__unused__)) float __internal_fmul_kernel (float a, float b, enum cudaRoundMode mode)

{
  unsigned long long product;
  volatile union __cudart_FloatUintCvt xx, yy;
  unsigned expo_x, expo_y;

  xx.f = a;
  yy.f = b;

  expo_y = 0xFF;
  expo_x = expo_y & (xx.i >> 23);
  expo_x = expo_x - 1;
  expo_y = expo_y & (yy.i >> 23);
  expo_y = expo_y - 1;

  if ((expo_x <= 0xFD) &&
      (expo_y <= 0xFD)) {
multiply:
    expo_x = expo_x + expo_y;
    expo_y = xx.i ^ yy.i;
    xx.i = xx.i & 0x00ffffff;
    yy.i = yy.i << 8;
    xx.i = xx.i | 0x00800000;
    yy.i = yy.i | 0x80000000;

    product = ((unsigned long long)xx.i) * yy.i;
    expo_x = expo_x - 127 + 2;
    expo_y = expo_y & 0x80000000;
    xx.i = (unsigned int)(product >> 32);
    yy.i = (unsigned int)(product & 0xffffffff);

    if (xx.i < 0x00800000) {
      xx.i = (xx.i << 1) | (yy.i >> 31);
      yy.i = (yy.i << 1);
      expo_x--;
    }
    if (expo_x <= 0xFD) {
      xx.i = xx.i | expo_y;
      xx.i = xx.i + (expo_x << 23);

      if (mode == cudaRoundNearest) {
        if (yy.i < 0x80000000) return xx.f;
        xx.i += ((yy.i == 0x80000000) ? (xx.i & 1) : (yy.i >> 31));
      } else if (mode == cudaRoundZero) {
      } else if (mode == cudaRoundPosInf) {
        xx.i += (yy.i && !expo_y);
      } else if (mode == cudaRoundMinInf) {
        xx.i += (yy.i && expo_y);
      }
      return xx.f;
    } else if ((int)expo_x >= 254) {

      if (mode == cudaRoundNearest) {
         xx.i = expo_y | 0x7F800000;
      } else if (mode == cudaRoundZero) {
         xx.i = expo_y | 0x7F7FFFFF;
      } else if (mode == cudaRoundPosInf) {
         xx.i = (expo_y ? 0xff7fffff : 0x7F800000);
      } else {
         xx.i = (expo_y ? 0xFF800000 : 0x7f7fffff);
      }
      return xx.f;
    } else {

      expo_x = ((unsigned int)-((int)expo_x));
      if (mode == cudaRoundNearest) {
        if (expo_x > 25) {

          xx.i = expo_y;
          return xx.f;
        } else {
          yy.i = (xx.i << (32 - expo_x)) | ((yy.i) ? 1 : 0);
          xx.i = expo_y + (xx.i >> expo_x);
          xx.i += ((yy.i == 0x80000000) ? (xx.i & 1) : (yy.i >> 31));
          return xx.f;
        }
      } else if (mode == cudaRoundZero) {
        if (expo_x > 25) expo_x = 25;
        xx.i = expo_y + (xx.i >> expo_x);
        return xx.f;
      } else if (mode == cudaRoundPosInf) {
        if (expo_x > 25) expo_x = 25;
        yy.i = (xx.i << (32 - expo_x)) | ((yy.i) ? 1 : 0);
        xx.i = expo_y + (xx.i >> expo_x);
        xx.i += (yy.i && !expo_y);
        return xx.f;
      } else {
        if (expo_x > 25) expo_x = 25;
        yy.i = (xx.i << (32 - expo_x)) | ((yy.i) ? 1 : 0);
        xx.i = expo_y + (xx.i >> expo_x);
        xx.i += (yy.i && expo_y);
        return xx.f;
      }
    }
  } else {
    product = xx.i ^ yy.i;
    product = product & 0x80000000;
    if (!(xx.i & 0x7fffffff)) {
      if (expo_y != 254) {
        xx.i = (unsigned int)product;
        return xx.f;
      }
      expo_y = yy.i << 1;
      if (expo_y == 0xFF000000) {
        xx.i = expo_y | 0x00C00000;
      } else {
        xx.i = yy.i | 0x00400000;
      }
      return xx.f;
    }
    if (!(yy.i & 0x7fffffff)) {
      if (expo_x != 254) {
        xx.i = (unsigned int)product;
        return xx.f;
      }
      expo_x = xx.i << 1;
      if (expo_x == 0xFF000000) {
        xx.i = expo_x | 0x00C00000;
      } else {
        xx.i = xx.i | 0x00400000;
      }
      return xx.f;
    }
    if ((expo_y != 254) && (expo_x != 254)) {
      expo_y++;
      expo_x++;
      if (expo_x == 0) {
        expo_y |= xx.i & 0x80000000;




        xx.i = xx.i << 8;
        while (!(xx.i & 0x80000000)) {
          xx.i <<= 1;
          expo_x--;
        }
        xx.i = (xx.i >> 8) | (expo_y & 0x80000000);
        expo_y &= ~0x80000000;
        expo_y--;
        goto multiply;
      }
      if (expo_y == 0) {
        expo_x |= yy.i & 0x80000000;
        yy.i = yy.i << 8;
        while (!(yy.i & 0x80000000)) {
          yy.i <<= 1;
          expo_y--;
        }
        yy.i = (yy.i >> 8) | (expo_x & 0x80000000);
        expo_x &= ~0x80000000;
        expo_x--;
        goto multiply;
      }
    }
    expo_x = xx.i << 1;
    expo_y = yy.i << 1;

    if (expo_x > 0xFF000000) {

      xx.i = xx.i | 0x00400000;
      return xx.f;
    }

    if (expo_y > 0xFF000000) {

      xx.i = yy.i | 0x00400000;
      return xx.f;
    }
    xx.i = (unsigned int)product | 0x7f800000;
    return xx.f;
  }
}

static __attribute__((__unused__)) float __internal_fmaf_kernel (float a, float b, float c, enum cudaRoundMode mode)

{
  unsigned long long product;
  unsigned int xx, yy, zz, ww;
  unsigned int temp, s, u;
  unsigned int expo_x, expo_y, expo_z;
  volatile union __cudart_FloatUintCvt cvt;

  cvt.f = a;
  xx = cvt.i;
  cvt.f = b;
  yy = cvt.i;
  cvt.f = c;
  zz = cvt.i;

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
      return b + b;
    }
    if ((zz << 1) > 0xff000000) {
      return c + c;
    }
    if ((xx << 1) > 0xff000000) {
      return a + a;
    }
# 3164 "/usr/local/cuda/bin/../include/device_functions.h" 3
    if ((((xx << 1) == 0) && ((yy << 1) == 0xff000000)) ||
        (((yy << 1) == 0) && ((xx << 1) == 0xff000000))) {
      cvt.i = 0xffc00000;
      return cvt.f;
    }
    if ((zz << 1) == 0xff000000) {
      if (((yy << 1) == 0xff000000) || ((xx << 1) == 0xff000000)) {
        if ((int)(xx ^ yy ^ zz) < 0) {
          cvt.i = 0xffc00000;
          return cvt.f;
        }
      }
    }




    if ((xx << 1) == 0xff000000) {
      xx = xx ^ (yy & 0x80000000);
      cvt.i = xx;
      return cvt.f;
    }
    if ((yy << 1) == 0xff000000) {
      yy = yy ^ (xx & 0x80000000);
      cvt.i = yy;
      return cvt.f;
    }
    if ((zz << 1) == 0xff000000) {
      cvt.i = zz;
      return cvt.f;
    }





    if (zz == 0x80000000) {
      if (((xx << 1) == 0) || ((yy << 1) == 0)) {
        if ((int)(xx ^ yy) < 0) {
          cvt.i = zz;
          return cvt.f;
        }
      }
    }



    if (((zz << 1) == 0) &&
        (((xx << 1) == 0) || ((yy << 1) == 0))) {
      if (mode == cudaRoundMinInf) {
        zz = 0x80000000 & (xx ^ yy ^ zz);
      } else {
        zz &= 0x7fffffff;
      }
      cvt.i = zz;
      return cvt.f;
    }



    if (((xx << 1) == 0) || ((yy << 1) == 0)) {
      cvt.i = zz;
      return cvt.f;
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

        if (mode == cudaRoundMinInf) {
          xx = 0x80000000;
        }
        cvt.i = xx;
        return cvt.f;
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
    if (mode == cudaRoundNearest) {
      s = xx & 1;
      xx += (temp == 0x80000000) ? s : (temp >> 31);
    } else if (mode == cudaRoundPosInf) {
      xx += temp && !expo_y;
    } else if (mode == cudaRoundMinInf) {
      xx += temp && expo_y;
    }
    xx = xx + (expo_x << 23);
    cvt.i = xx;
    return cvt.f;
  } else if ((int)expo_x >= 126) {

    if (mode == cudaRoundNearest) {
      xx = expo_y | 0x7f800000;
    } else if (mode == cudaRoundZero) {
      xx = expo_y | 0x7F7FFFFF;
    } else if (mode == cudaRoundPosInf) {
      xx = expo_y ? 0xFF7FFFFF : 0x7f800000;
    } else if (mode == cudaRoundMinInf) {
      xx = expo_y ? 0xff800000 : 0x7f7fffff;
    }
    cvt.i = xx;
    return cvt.f;
  }

  expo_x = (unsigned int)(-(int)expo_x);
  if (expo_x > 25) {

    xx = 0;
    if (mode == cudaRoundPosInf) {
      xx += !expo_y;
    } else if (mode == cudaRoundMinInf) {
      xx += !!expo_y;
    }
    cvt.i = expo_y | xx;
    return cvt.f;
  }
  temp = (xx << (32 - expo_x)) | ((temp) ? 1 : 0);
  xx = xx >> expo_x;
  if (mode == cudaRoundNearest) {
    xx = xx + ((temp == 0x80000000) ? (xx & 1) : (temp >> 31));
  } else if (mode == cudaRoundPosInf) {
    xx = xx + (!expo_y && temp);
  } else if (mode == cudaRoundMinInf) {
    xx = xx + (expo_y && temp);
  }
  xx = expo_y + xx;
  cvt.i = xx;
  return cvt.f;
}

static __attribute__((__unused__)) float __internal_fadd_kernel (float a, float b, enum cudaRoundMode mode)

{
  volatile union __cudart_FloatUintCvt xx, yy;
  unsigned int expo_x;
  unsigned int expo_y;
  unsigned int temp;

  xx.f = a;
  yy.f = b;


  expo_y = yy.i << 1;
  if (expo_y > (xx.i << 1)) {
    expo_y = xx.i;
    xx.i = yy.i;
    yy.i = expo_y;
  }

  temp = 0xff;
  expo_x = temp & (xx.i >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yy.i >> 23);
  expo_y = expo_y - 1;

  if ((expo_x <= 0xFD) &&
      (expo_y <= 0xFD)) {
add:
    expo_y = expo_x - expo_y;
    if (expo_y > 25) {
      expo_y = 31;
    }
    temp = xx.i ^ yy.i;
    xx.i = xx.i & ~0x7f000000;
    xx.i = xx.i | 0x00800000;
    yy.i = yy.i & ~0xff000000;
    yy.i = yy.i | 0x00800000;

    if ((int)temp < 0) {

      temp = 32 - expo_y;
      temp = (expo_y) ? (yy.i << temp) : 0;
      temp = (unsigned)(-((int)temp));
      xx.i = xx.i - (yy.i >> expo_y) - (temp ? 1 : 0);
      if (xx.i & 0x00800000) {
        if (expo_x <= 0xFD) {
          xx.i = xx.i + (expo_x << 23);
          if (mode == cudaRoundNearest) {
            if (temp < 0x80000000) return xx.f;
            xx.i += ((temp == 0x80000000) ? (xx.i & 1) : (temp >> 31));
          } else if (mode == cudaRoundZero) {
          } else if (mode == cudaRoundPosInf) {
            xx.i += (temp && !(xx.i & 0x80000000));
          } else if (mode == cudaRoundMinInf) {
            xx.i += (temp && (xx.i & 0x80000000));
          }
          return xx.f;
        }
      } else {
        if ((temp | (xx.i << 1)) == 0) {

          if (mode == cudaRoundMinInf) {
            xx.i = 0x80000000;
          } else {
            xx.i = 0;
          }
          return xx.f;
        }

        yy.i = xx.i & 0x80000000;
        do {
          xx.i = (xx.i << 1) | (temp >> 31);
          temp <<= 1;
          expo_x--;
        } while (!(xx.i & 0x00800000));
        xx.i = xx.i | yy.i;
      }
    } else {

      temp = 32 - expo_y;
      temp = (expo_y) ? (yy.i << temp) : 0;
      xx.i = xx.i + (yy.i >> expo_y);
      if (!(xx.i & 0x01000000)) {
        if (expo_x <= 0xFD) {
          xx.i = xx.i + (expo_x << 23);
          if (mode == cudaRoundNearest) {
            if (temp < 0x80000000) return xx.f;
            xx.i += ((temp == 0x80000000) ? (xx.i & 1) : (temp >> 31));
          } else if (mode == cudaRoundZero) {
          } else if (mode == cudaRoundPosInf) {
            xx.i += (temp && !(xx.i & 0x80000000));
          } else if (mode == cudaRoundMinInf) {
            xx.i += (temp && (xx.i & 0x80000000));
          }
          return xx.f;
        }
      } else {

        temp = (xx.i << 31) | (temp >> 1);
        xx.i = ((xx.i & 0x80000000) | (xx.i >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
    if (expo_x <= 0xFD) {
      xx.i = xx.i + (expo_x << 23);
      if (mode == cudaRoundNearest) {
        if (temp < 0x80000000) return xx.f;
        xx.i += ((temp == 0x80000000) ? (xx.i & 1) : (temp >> 31));
      } else if (mode == cudaRoundZero) {
      } else if (mode == cudaRoundPosInf) {
        xx.i += (temp && !(xx.i & 0x80000000));
      } else if (mode == cudaRoundMinInf) {
        xx.i += (temp && (xx.i & 0x80000000));
      }
      return xx.f;
    }
    if ((int)expo_x >= 254) {

      temp = xx.i & 0x80000000;
      if (mode == cudaRoundNearest) {
        xx.i = (temp) | 0x7f800000;
      } else if (mode == cudaRoundZero) {
        xx.i = (temp) | 0x7f7fffff;
      } else if (mode == cudaRoundMinInf) {
        xx.i = (temp ? 0xFF800000 : 0x7f7fffff);
      } else if (mode == cudaRoundPosInf) {
        xx.i = (temp ? 0xff7fffff : 0x7F800000);
      }
      return xx.f;
    }

    expo_y = expo_x + 32;
    yy.i = xx.i & 0x80000000;
    xx.i = xx.i & ~0xff000000;
    expo_x = (unsigned)(-((int)expo_x));
    temp = xx.i << expo_y | ((temp) ? 1 : 0);
    xx.i = yy.i | (xx.i >> expo_x);
    if (mode == cudaRoundNearest) {
      xx.i += (temp == 0x80000000) ? (xx.i & 1) : (temp >> 31);
    } else if (mode == cudaRoundZero) {
    } else if (mode == cudaRoundPosInf) {
      xx.i += (temp && !yy.i);
    } else if (mode == cudaRoundMinInf) {
      xx.i += (temp && yy.i);
    }
    return xx.f;
  } else {

    if (!(yy.i << 1)) {
      if (mode == cudaRoundMinInf) {
        if (!(xx.i << 1)) {
          xx.i = xx.i | yy.i;
        }
      } else {
        if (xx.i == 0x80000000) {
          xx.i = yy.i;
        }
      }
      if ((xx.i << 1) > 0xff000000) {
        xx.i |= 0x00400000;
      }
      return xx.f;
    }
    if ((expo_y != 254) && (expo_x != 254)) {

      if (expo_x == (unsigned int) -1) {
        temp = xx.i & 0x80000000;
        xx.i = xx.i << 8;
        while (!(xx.i & 0x80000000)) {
          xx.i <<= 1;
          expo_x--;
        }
        expo_x++;
        xx.i = (xx.i >> 8) | temp;
      }
      if (expo_y == (unsigned int) -1) {
        temp = yy.i & 0x80000000;
        yy.i = yy.i << 8;
        while (!(yy.i & 0x80000000)) {
          yy.i <<= 1;
          expo_y--;
        }
        expo_y++;
        yy.i = (yy.i >> 8) | temp;
      }
      goto add;
    }
    expo_x = xx.i << 1;
    expo_y = yy.i << 1;

    if (expo_x > 0xff000000) {

      xx.i = xx.i | 0x00400000;
      return xx.f;
    }

    if (expo_y > 0xff000000) {

      xx.i = yy.i | 0x00400000;
      return xx.f;
    }
    if ((expo_x == 0xff000000) && (expo_y == 0xff000000)) {




      expo_x = xx.i ^ yy.i;
      xx.i = xx.i | ((expo_x) ? 0xffc00000 : 0);
      return xx.f;
    }

    if (expo_y == 0xff000000) {
      xx.i = yy.i;
    }
    return xx.f;
  }
}

static __attribute__((__unused__)) float __frcp_rn (float a)
{
  return __internal_frcp_kernel (a, cudaRoundNearest);
}

static __attribute__((__unused__)) float __frcp_rz (float a)
{
  return __internal_frcp_kernel (a, cudaRoundZero);
}

static __attribute__((__unused__)) float __frcp_rd (float a)
{
  return __internal_frcp_kernel (a, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __frcp_ru (float a)
{
  return __internal_frcp_kernel (a, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fsqrt_rn (float a)
{
  return __internal_fsqrt_kernel (a, cudaRoundNearest);
}

static __attribute__((__unused__)) float __fsqrt_rz (float a)
{
  return __internal_fsqrt_kernel (a, cudaRoundZero);
}

static __attribute__((__unused__)) float __fsqrt_rd (float a)
{
  return __internal_fsqrt_kernel (a, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __fsqrt_ru (float a)
{
  return __internal_fsqrt_kernel (a, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fdiv_rn (float a, float b)
{
  return __internal_fdiv_kernel (a, b, cudaRoundNearest);
}

static __attribute__((__unused__)) float __fdiv_rz (float a, float b)
{
  return __internal_fdiv_kernel (a, b, cudaRoundZero);
}

static __attribute__((__unused__)) float __fdiv_rd (float a, float b)
{
  return __internal_fdiv_kernel (a, b, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __fdiv_ru (float a, float b)
{
  return __internal_fdiv_kernel (a, b, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fadd_rd (float a, float b)
{
  return __internal_fadd_kernel (a, b, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __fadd_ru (float a, float b)
{
  return __internal_fadd_kernel (a, b, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fmul_rd (float a, float b)
{
  return __internal_fmul_kernel (a, b, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __fmul_ru (float a, float b)
{
  return __internal_fmul_kernel (a, b, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fmaf_rn (float a, float b, float c)
{
  return __internal_fmaf_kernel (a, b, c, cudaRoundNearest);
}

static __attribute__((__unused__)) float __fmaf_rz (float a, float b, float c)
{
  return __internal_fmaf_kernel (a, b, c, cudaRoundZero);
}

static __attribute__((__unused__)) float __fmaf_ru (float a, float b, float c)
{
  return __internal_fmaf_kernel (a, b, c, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __fmaf_rd (float a, float b, float c)
{
  return __internal_fmaf_kernel (a, b, c, cudaRoundMinInf);
}

static __attribute__((__unused__)) int __cuda___isnan(double a);
static __attribute__((__unused__)) int __cuda___isnanf(float a);
static __attribute__((__unused__)) int __double2int_rz(double);
static __attribute__((__unused__)) unsigned int __double2uint_rz(double);
static __attribute__((__unused__)) long long int __double2ll_rz(double);
static __attribute__((__unused__)) unsigned long long int __double2ull_rz(double);
# 3771 "/usr/local/cuda/bin/../include/device_functions.h" 3
static __attribute__((__unused__)) int __mulhi(int a, int b)
{
  long long int c = (long long int)a * (long long int)b;

  return (int)(c >> 32);
}

static __attribute__((__unused__)) unsigned int __umulhi(unsigned int a, unsigned int b)
{
  unsigned long long int c = (unsigned long long int)a * (unsigned long long int)b;

  return (unsigned int)(c >> 32);
}

static __attribute__((__unused__)) unsigned long long int __umul64hi(unsigned long long int a, unsigned long long int b)
{
  unsigned int a_lo = (unsigned int)a;
  unsigned long long int a_hi = a >> 32;
  unsigned int b_lo = (unsigned int)b;
  unsigned long long int b_hi = b >> 32;
  unsigned long long int m1 = a_lo * b_hi;
  unsigned long long int m2 = a_hi * b_lo;
  unsigned int carry;

  carry = (0ULL + __umulhi(a_lo, b_lo) + (unsigned int)m1 + (unsigned int)m2) >> 32;

  return a_hi * b_hi + (m1 >> 32) + (m2 >> 32) + carry;
}

static __attribute__((__unused__)) long long int __mul64hi(long long int a, long long int b)
{
  long long int res;
  res = __umul64hi(a, b);
  if (a < 0LL) res = res - b;
  if (b < 0LL) res = res - a;
  return res;
}

static __attribute__((__unused__)) float __saturatef(float a)
{
  if (__cuda___isnanf(a)) return 0.0f;
  return a >= 1.0f ? 1.0f : a <= 0.0f ? 0.0f : a;
}

static __attribute__((__unused__)) unsigned int __sad(int a, int b, unsigned int c)
{
  long long int diff = (long long int)a - (long long int)b;

  return (unsigned int)(__cuda_llabs(diff) + (long long int)c);
}

static __attribute__((__unused__)) unsigned int __usad(unsigned int a, unsigned int b, unsigned int c)
{
  long long int diff = (long long int)a - (long long int)b;

  return (unsigned int)(__cuda_llabs(diff) + (long long int)c);
}

static __attribute__((__unused__)) int __mul24(int a, int b)
{

  a &= 0xffffff;
  a = (a & 0x800000) != 0 ? a | ~0xffffff : a;
  b &= 0xffffff;
  b = (b & 0x800000) != 0 ? b | ~0xffffff : b;


  return a * b;
}

static __attribute__((__unused__)) unsigned int __umul24(unsigned int a, unsigned int b)
{

  a &= 0xffffff;
  b &= 0xffffff;


  return a * b;
}

static __attribute__((__unused__)) float __int_as_float(int a)
{
  volatile union __cudart_FloatIntCvt u;

  u.i = a;
  return u.f;
}

static __attribute__((__unused__)) int __float_as_int(float a)
{
  volatile union __cudart_FloatIntCvt u;

  u.f = a;
  return u.i;
}

static __attribute__((__unused__)) long long int __internal_float2ll_kernel(float a, long long int max, long long int min, long long int nan, enum cudaRoundMode rndMode)
{
  unsigned long long int res, t = 0ULL;
  int shift;
  unsigned int ia;

  if (sizeof(a) == sizeof(double) && __cuda___isnan((double)a)) return nan; if (sizeof(a) == sizeof(float) && __cuda___isnanf((float)a)) return nan; if (a >= max) return max; if (a <= min) return min;
  ia = __float_as_int(a);
  shift = 189 - ((ia >> 23) & 0xff);
  res = (unsigned long long int)(((ia << 8) | 0x80000000) >> 1) << 32;
  if (shift >= 64) {
    t = res;
    res = 0;
  } else if (shift) {
    t = res << (64 - shift);
    res = res >> shift;
  }
  if (rndMode == cudaRoundNearest && (long long int)t < 0LL) {
    res += t == 0x8000000000000000ULL ? res & 1ULL : 1ULL;
  }
  else if (rndMode == cudaRoundMinInf && t != 0ULL && ia > 0x80000000) {
    res++;
  }
  else if (rndMode == cudaRoundPosInf && t != 0ULL && (int)ia > 0) {
    res++;
  }
  if ((int)ia < 0) res = (unsigned long long int)-(long long int)res;
  return (long long int)res;
}

static __attribute__((__unused__)) int __internal_float2int(float a, enum cudaRoundMode rndMode)
{
  return (int)__internal_float2ll_kernel(a, 2147483647LL, -2147483648LL, 0LL, rndMode);
}

static __attribute__((__unused__)) int __float2int_rz(float a)
{



  return __internal_float2int(a, cudaRoundZero);

}

static __attribute__((__unused__)) int __float2int_ru(float a)
{
  return __internal_float2int(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) int __float2int_rd(float a)
{
  return __internal_float2int(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) int __float2int_rn(float a)
{
  return __internal_float2int(a, cudaRoundNearest);
}

static __attribute__((__unused__)) long long int __internal_float2ll(float a, enum cudaRoundMode rndMode)
{
  return __internal_float2ll_kernel(a, 9223372036854775807LL, -9223372036854775807LL -1LL, -9223372036854775807LL -1LL, rndMode);
}

static __attribute__((__unused__)) long long int __float2ll_rz(float a)
{



  return __internal_float2ll(a, cudaRoundZero);

}

static __attribute__((__unused__)) long long int __float2ll_ru(float a)
{
  return __internal_float2ll(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) long long int __float2ll_rd(float a)
{
  return __internal_float2ll(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) long long int __float2ll_rn(float a)
{
  return __internal_float2ll(a, cudaRoundNearest);
}

static __attribute__((__unused__)) unsigned long long int __internal_float2ull_kernel(float a, unsigned long long int max, unsigned long long int nan, enum cudaRoundMode rndMode)
{
  unsigned long long int res, t = 0ULL;
  int shift;
  unsigned int ia;

  if (sizeof(a) == sizeof(double) && __cuda___isnan((double)a)) return nan; if (sizeof(a) == sizeof(float) && __cuda___isnanf((float)a)) return nan; if (a >= max) return max; if (a <= 0LL) return 0LL;
  ia = __float_as_int(a);
  shift = 190 - ((ia >> 23) & 0xff);
  res = (unsigned long long int)((ia << 8) | 0x80000000) << 32;
  if (shift >= 64) {
    t = res >> (int)(shift > 64);
    res = 0;
  } else if (shift) {
    t = res << (64 - shift);
    res = res >> shift;
  }
  if (rndMode == cudaRoundNearest && (long long int)t < 0LL) {
    res += t == 0x8000000000000000ULL ? res & 1ULL : 1ULL;
  }
  else if (rndMode == cudaRoundPosInf && t != 0ULL) {
    res++;
  }
  return res;
}

static __attribute__((__unused__)) unsigned int __internal_float2uint(float a, enum cudaRoundMode rndMode)
{
  return (unsigned int)__internal_float2ull_kernel(a, 4294967295U, 0U, rndMode);
}

static __attribute__((__unused__)) unsigned int __float2uint_rz(float a)
{



  return __internal_float2uint(a, cudaRoundZero);

}

static __attribute__((__unused__)) unsigned int __float2uint_ru(float a)
{
  return __internal_float2uint(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) unsigned int __float2uint_rd(float a)
{
  return __internal_float2uint(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) unsigned int __float2uint_rn(float a)
{
  return __internal_float2uint(a, cudaRoundNearest);
}

static __attribute__((__unused__)) unsigned long long int __internal_float2ull(float a, enum cudaRoundMode rndMode)
{
  return __internal_float2ull_kernel(a, 18446744073709551615ULL, 9223372036854775808ULL, rndMode);
}

static __attribute__((__unused__)) unsigned long long int __float2ull_rz(float a)
{



  return __internal_float2ull(a, cudaRoundZero);

}

static __attribute__((__unused__)) unsigned long long int __float2ull_ru(float a)
{
  return __internal_float2ull(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) unsigned long long int __float2ull_rd(float a)
{
  return __internal_float2ull(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) unsigned long long int __float2ull_rn(float a)
{
  return __internal_float2ull(a, cudaRoundNearest);
}

static __attribute__((__unused__)) int __internal_normalize64(unsigned long long int *a)
{
  int lz = 0;

  if ((*a & 0xffffffff00000000ULL) == 0ULL) {
    *a <<= 32;
    lz += 32;
  }
  if ((*a & 0xffff000000000000ULL) == 0ULL) {
    *a <<= 16;
    lz += 16;
  }
  if ((*a & 0xff00000000000000ULL) == 0ULL) {
    *a <<= 8;
    lz += 8;
  }
  if ((*a & 0xf000000000000000ULL) == 0ULL) {
    *a <<= 4;
    lz += 4;
  }
  if ((*a & 0xC000000000000000ULL) == 0ULL) {
    *a <<= 2;
    lz += 2;
  }
  if ((*a & 0x8000000000000000ULL) == 0ULL) {
    *a <<= 1;
    lz += 1;
  }
  return lz;
}

static __attribute__((__unused__)) int __internal_normalize(unsigned int *a)
{
  unsigned long long int t = (unsigned long long int)*a;
  int lz = __internal_normalize64(&t);

  *a = (unsigned int)(t >> 32);

  return lz - 32;
}

static __attribute__((__unused__)) float __internal_int2float_kernel(int a, enum cudaRoundMode rndMode)
{
  volatile union __cudart_FloatUintCvt res;
  int shift;
  unsigned int t;
  res.i = a;
  if (a == 0) return res.f;
  if (a < 0) res.i = (unsigned int)-a;
  shift = __internal_normalize((unsigned int*)&res.i);
  t = res.i << 24;
  res.i = (res.i >> 8);
  res.i += (127 + 30 - shift) << 23;
  if (a < 0) res.i |= 0x80000000;
  if ((rndMode == cudaRoundNearest) && (t >= 0x80000000)) {
    res.i += (t == 0x80000000) ? (res.i & 1) : (t >> 31);
  }
  else if ((rndMode == cudaRoundMinInf) && t && (a < 0)) {
    res.i++;
  }
  else if ((rndMode == cudaRoundPosInf) && t && (a > 0)) {
    res.i++;
  }
  return res.f;
}

static __attribute__((__unused__)) float __int2float_rz(int a)
{
  return __internal_int2float_kernel(a, cudaRoundZero);
}

static __attribute__((__unused__)) float __int2float_ru(int a)
{
  return __internal_int2float_kernel(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __int2float_rd(int a)
{
  return __internal_int2float_kernel(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __int2float_rn(int a)
{



  return __internal_int2float_kernel(a, cudaRoundNearest);

}

static __attribute__((__unused__)) float __internal_uint2float_kernel(unsigned int a, enum cudaRoundMode rndMode)
{
  volatile union __cudart_FloatUintCvt res;
  int shift;
  unsigned int t;
  res.i = a;
  if (a == 0) return res.f;
  shift = __internal_normalize((unsigned int*)&res.i);
  t = res.i << 24;
  res.i = (res.i >> 8);
  res.i += (127 + 30 - shift) << 23;
  if (rndMode == cudaRoundNearest) {
    res.i += (t == 0x80000000) ? (res.i & 1) : (t >> 31);
  }
  else if ((rndMode == cudaRoundPosInf) && t) {
    res.i++;
  }
  return res.f;
}

static __attribute__((__unused__)) float __uint2float_rz(unsigned int a)
{
  return __internal_uint2float_kernel(a, cudaRoundZero);
}

static __attribute__((__unused__)) float __uint2float_ru(unsigned int a)
{
  return __internal_uint2float_kernel(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) float __uint2float_rd(unsigned int a)
{
  return __internal_uint2float_kernel(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) float __uint2float_rn(unsigned int a)
{



  return __internal_uint2float_kernel(a, cudaRoundNearest);

}

static __attribute__((__unused__)) float __ll2float_rn(long long int a)
{
  return (float)a;
}

static __attribute__((__unused__)) float __internal_ull2float_kernel(unsigned long long int a, enum cudaRoundMode rndMode)
{
  unsigned long long int temp;
  unsigned int res, t;
  int shift;
  if (a == 0ULL) return 0.0f;
  temp = a;
  shift = __internal_normalize64(&temp);
  temp = (temp >> 8) | ((temp & 0xffULL) ? 1ULL : 0ULL);
  res = (unsigned int)(temp >> 32);
  t = (unsigned int)temp;
  res += (127 + 62 - shift) << 23;
  if (rndMode == cudaRoundNearest) {
    res += (t == 0x80000000) ? (res & 1) : (t >> 31);
  } else if (rndMode == cudaRoundPosInf) {
    res += (t != 0);
  }
  return __int_as_float(res);
}

static __attribute__((__unused__)) float __ull2float_rn(unsigned long long int a)
{



  return __internal_ull2float_kernel(a, cudaRoundNearest);

}

static __attribute__((__unused__)) unsigned short __float2half_rn(float f)
{
  unsigned int x = __float_as_int (f);
  unsigned int u = (x & 0x7fffffff), remainder, shift, lsb, lsb_s1, lsb_m1;
  unsigned int sign, exponent, mantissa;


  if (u > 0x7f800000) {
    return 0x7fff;
  }

  sign = ((x >> 16) & 0x8000);


  if (u > 0x477fefff) {
    return sign | 0x7c00;
  }
  if (u < 0x33000001) {
    return sign | 0x0000;
  }

  exponent = ((u >> 23) & 0xff);
  mantissa = (u & 0x7fffff);

  if (exponent > 0x70) {
    shift = 13;
    exponent -= 0x70;
  } else {
    shift = 0x7e - exponent;
    exponent = 0;
    mantissa |= 0x800000;
  }
  lsb = (1 << shift);
  lsb_s1 = (lsb >> 1);
  lsb_m1 = (lsb - 1);


  remainder = (mantissa & lsb_m1);
  mantissa >>= shift;
  if (remainder > lsb_s1 || (remainder == lsb_s1 && (mantissa & 0x1))) {
    ++mantissa;
    if (!(mantissa & 0x3ff)) {
      ++exponent;
      mantissa = 0;
    }
  }

  return sign | (exponent << 10) | mantissa;
}

static __attribute__((__unused__)) float __half2float(unsigned short h)
{
  unsigned int sign = ((h >> 15) & 1);
  unsigned int exponent = ((h >> 10) & 0x1f);
  unsigned int mantissa = ((h & 0x3ff) << 13);

  if (exponent == 0x1f) {
    mantissa = (mantissa
                ? (sign = 0, 0x7fffff)
                : 0);
    exponent = 0xff;
  } else if (!exponent) {
    if (mantissa) {
      unsigned int msb;
      exponent = 0x71;
      do {
        msb = (mantissa & 0x400000);
        mantissa <<= 1;
        --exponent;
      } while (!msb);
      mantissa &= 0x7fffff;
    }
  } else {
    exponent += 0x70;
  }

  return __int_as_float ((sign << 31) | (exponent << 23) | mantissa);
}

static __attribute__((__unused__)) float __fadd_rz(float a, float b)
{
  return __internal_fadd_kernel(a, b, cudaRoundZero);
}

static __attribute__((__unused__)) float __fmul_rz(float a, float b)
{
  return __internal_fmul_kernel(a, b, cudaRoundZero);
}

static __attribute__((__unused__)) float __fadd_rn(float a, float b)
{
  return __internal_fadd_kernel(a, b, cudaRoundNearest);
}

static __attribute__((__unused__)) float __fmul_rn(float a, float b)
{
  return __internal_fmul_kernel(a, b, cudaRoundNearest);
}

static __attribute__((__unused__)) void __brkpt(int c)
{

}
# 4318 "/usr/local/cuda/bin/../include/device_functions.h" 3
extern int __cudaSynchronizeThreads(void**, void*);



static __attribute__((__unused__)) inline __attribute__((always_inline)) void __syncthreads(void)
{
  volatile int _ = 0;
  L: if (__cudaSynchronizeThreads((void**)&&L, (void*)&_)) goto L;
}
# 4337 "/usr/local/cuda/bin/../include/device_functions.h" 3
static __attribute__((__unused__)) void __prof_trigger(int a)
{
}

static __attribute__((__unused__)) void __threadfence(void)
{
  __syncthreads();
}

static __attribute__((__unused__)) void __threadfence_block(void)
{
  __syncthreads();
}



static __attribute__((__unused__)) void __trap(void)
{
  __builtin_trap();
}
# 4375 "/usr/local/cuda/bin/../include/device_functions.h" 3
static __attribute__((__unused__)) float __fdividef(float a, float b)
{



  volatile float aa = a;
  volatile float bb = b;

  if (__cuda_fabsf(bb) > 8.507059173e37f) {
    if (__cuda_fabsf(aa) <= 3.402823466e38f) {
      return ((aa / bb) / 3.402823466e38f) / 3.402823466e38f;
    } else {
      bb = 1.0f / bb;
      bb = bb / 3.402823466e38f;
      return aa * bb;
    }
  } else {
    return aa / bb;
  }

}


static __attribute__((__unused__)) float __sinf(float a)
{

  if ((__float_as_int(a) << 1) == 0xff000000) {
    return __fadd_rn (a, -a);
  }

  return sinf(a);
}

static __attribute__((__unused__)) float __cosf(float a)
{

  if ((__float_as_int(a) << 1) == 0xff000000) {
    return __fadd_rn (a, -a);
  }

  return cosf(a);
}

static __attribute__((__unused__)) float __log2f(float a)
{
  return log2f(a);
}







static __attribute__((__unused__)) float __internal_accurate_fdividef(float a, float b)
{
  return a / b;
}

static __attribute__((__unused__)) float __tanf(float a)
{



  return __fdividef (__sinf(a), __cosf(a));

}

static __attribute__((__unused__)) void __sincosf(float a, float *sptr, float *cptr)
{



  *sptr = __sinf(a);
  *cptr = __cosf(a);

}

static __attribute__((__unused__)) float __expf(float a)
{



  return __cuda_exp2f(a * 1.442695041f);

}

static __attribute__((__unused__)) float __exp10f(float a)
{



  return __cuda_exp2f(a * 3.321928094f);

}

static __attribute__((__unused__)) float __log10f(float a)
{



  return 0.301029996f * __log2f(a);

}

static __attribute__((__unused__)) float __logf(float a)
{



  return 0.693147181f * __log2f(a);

}

static __attribute__((__unused__)) float __powf(float a, float b)
{



  return __cuda_exp2f(b * __log2f(a));

}

static __attribute__((__unused__)) float fdividef(float a, float b)
{





  return __internal_accurate_fdividef(a, b);

}

static __attribute__((__unused__)) int __clz(int a)
{
  return (a)?(158-(__float_as_int(__uint2float_rz((unsigned int)a))>>23)):32;
}

static __attribute__((__unused__)) int __clzll(long long int a)
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

static __attribute__((__unused__)) int __popc(unsigned int a)
{
  a = a - ((a >> 1) & 0x55555555);
  a = (a & 0x33333333) + ((a >> 2) & 0x33333333);
  a = (a + (a >> 4)) & 0x0f0f0f0f;
  a = ((__umul24(a, 0x808080) << 1) + a) >> 24;
  return a;
}

static __attribute__((__unused__)) int __popcll(unsigned long long int a)
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

static __attribute__((__unused__)) unsigned int __brev(unsigned int a)
{
  a = ((a >> 1) & 0x55555555) + ((a & 0x55555555) << 1);
  a = ((a >> 2) & 0x33333333) + ((a & 0x33333333) << 2);
  a = ((a >> 4) & 0x0F0F0F0F) + ((a & 0x0F0F0F0F) << 4);
  a = ((a >> 8) & 0x00FF00FF) + ((a & 0x00FF00FF) << 8);
  a = ( a >> 16 ) + ( a << 16);
  return a;
}

static __attribute__((__unused__)) unsigned long long int __brevll(unsigned long long int a)
{
  unsigned int hi = (unsigned int)(a >> 32);
  unsigned int lo = (unsigned int)(a & 0xffffffffULL);
  unsigned int t;
  t = __brev(lo);
  lo = __brev(hi);
  return ((unsigned long long int)t << 32) + (unsigned long long int)lo;
}

static __attribute__((__unused__)) int __ffs(int a)
{
  return 32 - __clz (a & -a);
}

static __attribute__((__unused__)) int __ffsll(long long int a)
{
  return 64 - __clzll (a & -a);
}
# 4590 "/usr/local/cuda/bin/../include/device_functions.h" 3
static __attribute__((__unused__)) double fdivide(double a, double b)
{
  return (double)fdividef((float)a, (float)b);
}



static __attribute__((__unused__)) int __double2int_rz(double a)
{
  return __float2int_rz((float)a);
}

static __attribute__((__unused__)) unsigned int __double2uint_rz(double a)
{
  return __float2uint_rz((float)a);
}

static __attribute__((__unused__)) long long int __double2ll_rz(double a)
{
  return __float2ll_rz((float)a);
}

static __attribute__((__unused__)) unsigned long long int __double2ull_rz(double a)
{
  return __float2ull_rz((float)a);
}
# 4667 "/usr/local/cuda/bin/../include/device_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h" 1 3
# 257 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h" 3
extern void __cudaMutexOperation(int lock);






static __attribute__((__unused__)) int __iAtomicAdd(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old + val; __cudaMutexOperation(0);



  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicAdd(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old + val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicExch(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicExch(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) float __fAtomicExch(float *address, float val)
{
  float old;

  __cudaMutexOperation(1); old = *address; *address = val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicMin(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old < val ? old : val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicMin(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old < val ? old : val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicMax(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old > val ? old : val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicMax(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old > val ? old : val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicInc(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = (old >= val) ? 0 : old + 1; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicDec(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = ((old == 0) | (old > val)) ? val : (old - 1); __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicAnd(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old & val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicAnd(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old & val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicOr(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old | val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicOr(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old | val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicXor(int *address, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old ^ val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicXor(unsigned int *address, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old ^ val; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) int __iAtomicCAS(int *address, int compare, int val)
{
  int old;

  __cudaMutexOperation(1); old = *address; *address = old == compare ? val : old; __cudaMutexOperation(0);




  return old;
}

static __attribute__((__unused__)) unsigned int __uAtomicCAS(unsigned int *address, unsigned int compare, unsigned int val)
{
  unsigned int old;

  __cudaMutexOperation(1); old = *address; *address = old == compare ? val : old; __cudaMutexOperation(0);




  return old;
}
# 4668 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h" 1 3
# 118 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h" 3
extern void __cudaMutexOperation(int lock);






static __attribute__((__unused__)) unsigned long long int __ullAtomicAdd(unsigned long long int *address, unsigned long long int val)
{
  unsigned long long int old;

  __cudaMutexOperation(1); old = *address; *address = old + val; __cudaMutexOperation(0);



  return old;
}

static __attribute__((__unused__)) unsigned long long int __ullAtomicExch(unsigned long long int *address, unsigned long long int val)
{
  unsigned long long int old;

  __cudaMutexOperation(1); old = *address; *address = val; __cudaMutexOperation(0);



  return old;
}

static __attribute__((__unused__)) unsigned long long int __ullAtomicCAS(unsigned long long int *address, unsigned long long int compare, unsigned long long int val)
{
  unsigned long long int old;

  __cudaMutexOperation(1); old = *address; *address = old == compare ? val : old; __cudaMutexOperation(0);



  return old;
}





static __attribute__((__unused__)) int __any(int cond)
{
  return cond;
}

static __attribute__((__unused__)) int __all(int cond)
{
  return cond;
}
# 4669 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/sm_13_double_functions.h" 1 3
# 267 "/usr/local/cuda/bin/../include/sm_13_double_functions.h" 3
static __attribute__((__unused__)) double __longlong_as_double(long long int a)
{
  volatile union __cudart_DoubleLonglongCvt u;
  u.i = a;
  return u.d;
}

static __attribute__((__unused__)) long long int __double_as_longlong(double a)
{
  volatile union __cudart_DoubleLonglongCvt u;
  u.d = a;
  return u.i;
}

static __attribute__((__unused__)) float __internal_double2float_kernel(double a)
{
  volatile union __cudart_DoubleUlonglongCvt xx;
  volatile union __cudart_FloatUintCvt res;

  int shift;
  xx.d = a;
  if (xx.i == 0) return 0.0f;
  res.i = (((unsigned int) (xx.i >> 32)) & 0x80000000);
  if ((xx.i & 0x7ff0000000000000ULL) == 0x7ff0000000000000ULL) {
    if ((xx.i & 0x7fffffffffffffffULL) > 0x7ff0000000000000ULL) {

      res.i = ((unsigned int)((xx.i >> 32) & 0x80000000) |
               (255U << 23) | 0x00400000 |
               (unsigned int)((xx.i >> (53 - 24)) & 0x007fffff));
    } else {

      res.i |= 0x7f800000;
    }
    return res.f;
  }
  shift = ((int) ((xx.i >> 52) & 0x7ff)) - 1023;

  xx.i = (xx.i & 0x000fffffffffffffULL);
  if (shift >= 128) {
    res.i |= 0x7f7fffff;
    return res.f;
  }
  if (shift <= -127) {
    if (shift < -180) {

      xx.i = 0;
    } else {
      xx.i |= 0x0010000000000000ULL;
      xx.i >>= -126 - shift;
    }
  } else {
    res.i |= (unsigned int) (127 + shift) << 23;
  }
  res.i |= ((unsigned int) (xx.i >> 29)) & 0x007fffff;
  xx.i &= 0x1fffffff;
  return res.f;
}

static __attribute__((__unused__)) double __internal_ll2double_kernel(long long int a, enum cudaRoundMode rndMode)
{
  volatile union __cudart_DoubleUlonglongCvt res;
  int shift;
  unsigned int t;
  res.i = a;
  if (a == 0) return res.d;
  if (a < 0) res.i = (unsigned long long int)-a;
  shift = __internal_normalize64((unsigned long long int*)&res.i);
  t = ((unsigned int) res.i) << 21;
  res.i >>= 11;
  res.i += ((unsigned long long int)(1023 + 62 - shift)) << 52;
  if (a < 0) res.i |= 0x8000000000000000ULL;
  if ((rndMode == cudaRoundNearest) && (t >= 0x80000000)) {
    res.i += (t == 0x80000000) ? (res.i & 1) : 1;
  }
  else if ((rndMode == cudaRoundMinInf) && t && (a < 0)) {
    res.i++;
  }
  else if ((rndMode == cudaRoundPosInf) && t && (a > 0)) {
    res.i++;
  }
  return res.d;
}

static __attribute__((__unused__)) double __internal_ull2double_kernel(unsigned long long int a, enum cudaRoundMode rndMode)
{
  volatile union __cudart_DoubleUlonglongCvt res;
  int shift;
  unsigned int t;
  res.i = a;
  if (a == 0) return res.d;
  shift = __internal_normalize64((unsigned long long int *)&res.i);
  t = ((unsigned int) res.i) << 21;
  res.i >>= 11;
  res.i += ((unsigned long long int)(1023 + 62 - shift)) << 52;
  if ((rndMode == cudaRoundNearest) && (t >= 0x80000000)) {
    res.i += (t == 0x80000000) ? (res.i & 1) : 1;
  }
  else if ((rndMode == cudaRoundPosInf) && t) {
    res.i++;
  }
  return res.d;
}

static __attribute__((__unused__)) long long int __internal_double2ll_kernel(double a, long long int max, long long int min, long long int nan, enum cudaRoundMode rndMode)
{
  volatile union __cudart_DoubleUlonglongCvt xx, res;
  unsigned long long int t = 0;
  int shift;

  xx.d = a;
  if (sizeof(a) == sizeof(double) && __cuda___isnan((double)a)) return nan; if (sizeof(a) == sizeof(float) && __cuda___isnanf((float)a)) return nan; if (a >= max) return max; if (a <= min) return min;
  shift = (int) (1023 + 62 - ((xx.i >> 52) & 0x7ff));
  res.i = ((xx.i << 11) | 0x8000000000000000ULL) >> 1;
  if (shift >= 64) {
    t = res.i;
    res.i = 0;
  } else if (shift) {
    t = res.i << (64 - shift);
    res.i = res.i >> shift;
  }
  if ((rndMode == cudaRoundNearest) && (t >= 0x8000000000000000ULL)) {
    res.i += (t == 0x8000000000000000ULL) ? (res.i & 1) : 1;
  }
  else if ((rndMode == cudaRoundMinInf) && t &&
          (xx.i > 0x8000000000000000ULL)) {
    res.i++;
  }
  else if ((rndMode == cudaRoundPosInf) && t && ((long long int)xx.i > 0)) {
    res.i++;
  }
  if ((long long int)xx.i < 0) {
    res.i = (unsigned long long int)(-(long long int)res.i);
  }
  return res.i;
}

static __attribute__((__unused__)) unsigned long long int __internal_double2ull_kernel(double a, unsigned long long int max, unsigned long long int nan, enum cudaRoundMode rndMode)
{
  volatile union __cudart_DoubleUlonglongCvt xx, res;
  unsigned long long int t = 0;
  int shift;

  xx.d = a;
  if (sizeof(a) == sizeof(double) && __cuda___isnan((double)a)) return nan; if (sizeof(a) == sizeof(float) && __cuda___isnanf((float)a)) return nan; if (a >= max) return max; if (a <= 0LL) return 0LL;

  if (a == 0.0) return 0LL;
  shift = (int) (1023 + 63 - ((xx.i >> 52) & 0x7ff));
  res.i = ((xx.i << 11) | 0x8000000000000000ULL);
  if (shift >= 64) {
    t = res.i >> (int)(shift > 64);
    res.i = 0;
  } else if (shift) {
    t = res.i << (64 - shift);
    res.i = res.i >> shift;
  }
  if ((rndMode == cudaRoundNearest) && (t >= 0x8000000000000000ULL)) {
    res.i += (t == 0x8000000000000000ULL) ? (res.i & 1) : 1;
  }
  else if ((rndMode == cudaRoundPosInf) && t) {
    res.i++;
  }
  return res.i;
}

static __attribute__((__unused__)) int __double2hiint(double a)
{
  volatile union __cudart_DoubleInthiloCvt cvt;

  cvt.d = a;
  return cvt.i[1];
}

static __attribute__((__unused__)) int __double2loint(double a)
{
  volatile union __cudart_DoubleInthiloCvt cvt;

  cvt.d = a;
  return cvt.i[0];
}

static __attribute__((__unused__)) double __hiloint2double(int a, int b)
{
  volatile union __cudart_DoubleInthiloCvt cvt;

  cvt.i[0] = b;
  cvt.i[1] = a;
  return cvt.d;
}

static __attribute__((__unused__)) float __double2float_rn(double a)
{
  return (float)a;
}

static __attribute__((__unused__)) float __double2float_rz(double a)
{
  return __internal_double2float_kernel(a);
}

static __attribute__((__unused__)) int __internal_double2int(double a, enum cudaRoundMode rndMode)
{
  return (int)__internal_double2ll_kernel(a, 2147483647LL, -2147483648LL, -2147483648LL, rndMode);
}

static __attribute__((__unused__)) int __double2int_rn(double a)
{
  return __internal_double2int(a, cudaRoundNearest);
}

static __attribute__((__unused__)) int __double2int_ru(double a)
{
  return __internal_double2int(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) int __double2int_rd(double a)
{
  return __internal_double2int(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) unsigned int __internal_double2uint(double a, enum cudaRoundMode rndMode)
{
  return (unsigned int)__internal_double2ull_kernel(a, 4294967295ULL, 2147483648ULL, rndMode);
}

static __attribute__((__unused__)) unsigned int __double2uint_rn(double a)
{
  return __internal_double2uint(a, cudaRoundNearest);
}

static __attribute__((__unused__)) unsigned int __double2uint_ru(double a)
{
  return __internal_double2uint(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) unsigned int __double2uint_rd(double a)
{
  return __internal_double2uint(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) long long int __internal_double2ll(double a, enum cudaRoundMode rndMode)
{
  return __internal_double2ll_kernel(a, 9223372036854775807LL, -9223372036854775807LL -1LL, -9223372036854775807LL -1LL, rndMode);
}

static __attribute__((__unused__)) long long int __double2ll_rn(double a)
{
  return __internal_double2ll(a, cudaRoundNearest);
}

static __attribute__((__unused__)) long long int __double2ll_ru(double a)
{
  return __internal_double2ll(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) long long int __double2ll_rd(double a)
{
  return __internal_double2ll(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) unsigned long long int __internal_double2ull(double a, enum cudaRoundMode rndMode)
{
  return __internal_double2ull_kernel(a, 18446744073709551615ULL, 9223372036854775808ULL, rndMode);
}

static __attribute__((__unused__)) unsigned long long int __double2ull_rn(double a)
{
  return __internal_double2ull(a, cudaRoundNearest);
}

static __attribute__((__unused__)) unsigned long long int __double2ull_ru(double a)
{
  return __internal_double2ull(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) unsigned long long int __double2ull_rd(double a)
{
  return __internal_double2ull(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) double __int2double_rn(int a)
{
  return (double)a;
}

static __attribute__((__unused__)) double __uint2double_rn(unsigned int a)
{
  return (double)a;
}

static __attribute__((__unused__)) double __ll2double_rn(long long int a)
{
  return (double)a;
}

static __attribute__((__unused__)) double __ll2double_rz(long long int a)
{
  return __internal_ll2double_kernel(a, cudaRoundZero);
}

static __attribute__((__unused__)) double __ll2double_rd(long long int a)
{
  return __internal_ll2double_kernel(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) double __ll2double_ru(long long int a)
{
  return __internal_ll2double_kernel(a, cudaRoundPosInf);
}

static __attribute__((__unused__)) double __ull2double_rn(unsigned long long int a)
{
  return __internal_ull2double_kernel(a, cudaRoundNearest);
}

static __attribute__((__unused__)) double __ull2double_rz(unsigned long long int a)
{
  return __internal_ull2double_kernel(a, cudaRoundZero);
}

static __attribute__((__unused__)) double __ull2double_rd(unsigned long long int a)
{
  return __internal_ull2double_kernel(a, cudaRoundMinInf);
}

static __attribute__((__unused__)) double __ull2double_ru(unsigned long long int a)
{
  return __internal_ull2double_kernel(a, cudaRoundPosInf);
}







static __attribute__((__unused__)) double __internal_fma_kernel(double x, double y, double z, enum cudaRoundMode rndMode)
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

static __attribute__((__unused__)) double __fma_rn(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundNearest);
}

static __attribute__((__unused__)) double __fma_rd(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundMinInf);
}

static __attribute__((__unused__)) double __fma_ru(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundPosInf);
}

static __attribute__((__unused__)) double __fma_rz(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundZero);
}

static __attribute__((__unused__)) double __dadd_rz(double a, double b)
{
  return __fma_rz(a, 1.0, b);
}

static __attribute__((__unused__)) double __dadd_ru(double a, double b)
{
  return __fma_ru(a, 1.0, b);
}

static __attribute__((__unused__)) double __dadd_rd(double a, double b)
{
  return __fma_rd(a, 1.0, b);
}

static __attribute__((__unused__)) double __dmul_rz(double a, double b)
{
  return __fma_rz(a, b, __hiloint2double(0x80000000, 0x00000000));
}

static __attribute__((__unused__)) double __dmul_ru(double a, double b)
{
  return __fma_ru(a, b, __hiloint2double(0x80000000, 0x00000000));
}

static __attribute__((__unused__)) double __dmul_rd(double a, double b)
{
  return __fma_rd(a, b, 0.0);
}

static __attribute__((__unused__)) double __dadd_rn(double a, double b)
{
  return __fma_rn(a, 1.0, b);
}

static __attribute__((__unused__)) double __dmul_rn(double a, double b)
{
  return __fma_rn(a, b, __hiloint2double(0x80000000, 0x00000000));
}
# 4670 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 1 "/usr/local/cuda/bin/../include/texture_fetch_functions.h" 1 3
# 1910 "/usr/local/cuda/bin/../include/texture_fetch_functions.h" 3
extern void __cudaTextureFetch(const void *tex, void *index, int integer, void *val);

static __attribute__((__unused__)) int4 __itexfetchi(const void *tex, int4 index)
{
  int4 val;

  __cudaTextureFetch(tex, (void*)&index, 1, (void*)&val);

  return val;
}

static __attribute__((__unused__)) uint4 __utexfetchi(const void *tex, int4 index)
{
  uint4 val;

  __cudaTextureFetch(tex, (void*)&index, 1, (void*)&val);

  return val;
}

static __attribute__((__unused__)) float4 __ftexfetchi(const void *tex, int4 index)
{
  float4 val;

  __cudaTextureFetch(tex, (void*)&index, 1, (void*)&val);

  return val;
}

static __attribute__((__unused__)) int4 __itexfetch(const void *tex, float4 index, int dim)
{
  int4 val;

  __cudaTextureFetch(tex, (void*)&index, 0, (void*)&val);

  return val;
}

static __attribute__((__unused__)) uint4 __utexfetch(const void *tex, float4 index, int dim)
{
  uint4 val;

  __cudaTextureFetch(tex, (void*)&index, 0, (void*)&val);

  return val;
}

static __attribute__((__unused__)) float4 __ftexfetch(const void *tex, float4 index, int dim)
{
  float4 val;

  __cudaTextureFetch(tex, (void*)&index, 0, (void*)&val);

  return val;
}
# 4671 "/usr/local/cuda/bin/../include/device_functions.h" 2 3
# 997 "/usr/local/cuda/bin/../include/math_functions.h" 2 3


static __attribute__((__unused__)) int __cuda___signbitf(float a)
{
  return (int)((unsigned int)__float_as_int(a) >> 31);
}




static __attribute__((__unused__)) float __cuda_copysignf(float a, float b)
{
  return __int_as_float((__float_as_int(b) & 0x80000000) |
                        (__float_as_int(a) & ~0x80000000));
}
# 1021 "/usr/local/cuda/bin/../include/math_functions.h" 3


extern __attribute__((__weak__)) int min(int a, int b); int min(int a, int b)
{
  return a < b ? a : b;
}

extern __attribute__((__weak__)) unsigned int umin(unsigned int a, unsigned int b); unsigned int umin(unsigned int a, unsigned int b)
{
  return a < b ? a : b;
}

extern __attribute__((__weak__)) long long int llmin(long long int a, long long int b); long long int llmin(long long int a, long long int b)
{
  return a < b ? a : b;
}

extern __attribute__((__weak__)) unsigned long long int ullmin(unsigned long long int a, unsigned long long int b); unsigned long long int ullmin(unsigned long long int a, unsigned long long int b)
{
  return a < b ? a : b;
}

extern __attribute__((__weak__)) int max(int a, int b); int max(int a, int b)
{
  return a > b ? a : b;
}

extern __attribute__((__weak__)) unsigned int umax(unsigned int a, unsigned int b); unsigned int umax(unsigned int a, unsigned int b)
{
  return a > b ? a : b;
}

extern __attribute__((__weak__)) long long int llmax(long long int a, long long int b); long long int llmax(long long int a, long long int b)
{
  return a > b ? a : b;
}

extern __attribute__((__weak__)) unsigned long long int ullmax(unsigned long long int a, unsigned long long int b); unsigned long long int ullmax(unsigned long long int a, unsigned long long int b)
{
  return a > b ? a : b;
}


# 1135 "/usr/local/cuda/bin/../include/math_functions.h" 3
static __attribute__((__unused__)) float __internal_nearbyintf(float a)
{
  float fa = fabsf(a);

  if (fa >= 8388608.0f) {
    return a;
  } else {
    volatile float u = 8388608.0f + fa;

    u = u - 8388608.0f;
    return copysignf(u, a);
  }
}

static __attribute__((__unused__)) float __internal_fminf(float a, float b)
{
  volatile union {
    float f;
    unsigned int i;
  } cvta, cvtb;
  int nana, nanb;

  cvta.f = a;
  cvtb.f = b;
  nana = ((cvta.i << 1) > 0xff000000);
  nanb = ((cvtb.i << 1) > 0xff000000);
  if (nana && nanb) return a + b;
  if (nana) return b;
  if (nanb) return a;
  if ((cvta.i | cvtb.i) == 0x80000000) {
    return __int_as_float(0x80000000);
  }
  return a < b ? a : b;
}

static __attribute__((__unused__)) float __internal_fmaxf(float a, float b)
{
  volatile union {
    float f;
    unsigned int i;
  } cvta, cvtb;
  int nana, nanb;

  cvta.f = a;
  cvtb.f = b;
  nana = ((cvta.i << 1) > 0xff000000);
  nanb = ((cvtb.i << 1) > 0xff000000);
  if (nana && nanb) return a + b;
  if (nana) return b;
  if (nanb) return a;
  if ((cvta.f == 0.0f) && (cvtb.f == 0.0f)) {
    cvta.i &= cvtb.i;
    return cvta.f;
  }
  return a > b ? a : b;
}
# 1235 "/usr/local/cuda/bin/../include/math_functions.h" 3
static __attribute__((__unused__)) long int __cuda_labs(long int a)
{
  return labs(a);
}

static __attribute__((__unused__)) float __cuda_ceilf(float a)
{
  return ceilf(a);
}

static __attribute__((__unused__)) float __cuda_floorf(float a)
{
  return floorf(a);
}

static __attribute__((__unused__)) float __cuda_sqrtf(float a)
{
  return sqrtf(a);
}

static __attribute__((__unused__)) float __cuda_rsqrtf(float a)
{
  return rsqrtf(a);
}

static __attribute__((__unused__)) float __cuda_truncf(float a)
{
  return truncf(a);
}

static __attribute__((__unused__)) int __cuda_max(int a, int b)
{
  return max(a, b);
}

static __attribute__((__unused__)) int __cuda_min(int a, int b)
{
  return min(a, b);
}

static __attribute__((__unused__)) unsigned int __cuda_umax(unsigned int a, unsigned int b)
{
  return umax(a, b);
}

static __attribute__((__unused__)) unsigned int __cuda_umin(unsigned int a, unsigned int b)
{
  return umin(a, b);
}

static __attribute__((__unused__)) long long int __cuda_llmax(long long int a, long long int b)
{
  return llmax(a, b);
}

static __attribute__((__unused__)) long long int __cuda_llmin(long long int a, long long int b)
{
  return llmin(a, b);
}

static __attribute__((__unused__)) unsigned long long int __cuda_ullmax(unsigned long long int a, unsigned long long int b)
{
  return ullmax(a, b);
}

static __attribute__((__unused__)) unsigned long long int __cuda_ullmin(unsigned long long int a, unsigned long long int b)
{
  return ullmin(a, b);
}

static __attribute__((__unused__)) long long int __cuda_llrintf(float a)
{



  return __float2ll_rn(a);

}

static __attribute__((__unused__)) long int __cuda_lrintf(float a)
{






  return (long int)__float2int_rn(a);


}

static __attribute__((__unused__)) float __cuda_nearbyintf(float a)
{





  return __internal_nearbyintf(a);

}

static __attribute__((__unused__)) float __cuda_fmaxf(float a, float b)
{





  return __internal_fmaxf(a, b);

}

static __attribute__((__unused__)) float __cuda_fminf(float a, float b)
{





  return __internal_fminf(a, b);

}






static __attribute__((__unused__)) int __cuda___finitef(float a)
{
  return __cuda_fabsf(a) < __int_as_float(0x7f800000);
}
# 1379 "/usr/local/cuda/bin/../include/math_functions.h" 3
static __attribute__((__unused__)) int __cuda___isinff(float a)
{
  return __cuda_fabsf(a) == __int_as_float(0x7f800000);
}

static __attribute__((__unused__)) int __cuda___isnanf(float a)
{
  return !(__cuda_fabsf(a) <= __int_as_float(0x7f800000));
}

static __attribute__((__unused__)) float __cuda_nextafterf(float a, float b)
{
  unsigned int ia;
  unsigned int ib;
  ia = __float_as_int(a);
  ib = __float_as_int(b);




  if (__cuda___isnanf(a) || __cuda___isnanf(b)) return a + b;
  if (__int_as_float (ia | ib) == 0.0f) return __int_as_float(ib);





  if (__int_as_float(ia) == 0.0f) {
    return __cuda_copysignf(__int_as_float(0x00000001), b);
  }

  if ((a < b) && (a < 0.0f)) ia--;
  if ((a < b) && (a > 0.0f)) ia++;
  if ((a > b) && (a < 0.0f)) ia++;
  if ((a > b) && (a > 0.0f)) ia--;
  a = __int_as_float(ia);





  return a;
}

static __attribute__((__unused__)) float __cuda_nanf(const char *tagp)
{

  return __int_as_float(0x7fffffff);
}

static __attribute__((__unused__)) float __internal_fmad(float a, float b, float c)
{

  return __fmaf_rn (a, b, c);



}


static __attribute__((__unused__)) float __internal_atanhf_kernel(float a_1, float a_2)
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




static __attribute__((__unused__)) float __internal_atanf_kernel(float a)
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


static __attribute__((__unused__)) float __internal_tan_kernel(float a)
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

static __attribute__((__unused__)) float __internal_accurate_logf(float a)
{
  float t;
  float z;
  float m;
  int ia;
  ia = __float_as_int(a);

  if ((a > 0.0f) && (a < __int_as_float(0x7f800000))) {
    int e = -127;


    if ((unsigned)ia < (unsigned)0x00800000) {
      a = a * 16777216.0f;
      e -= 24;
      ia = __float_as_int(a);
    }


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

static __attribute__((__unused__)) float2 __internal_log_ep(float a)
{
  float2 res;
  int expo;
  float m;
  float log_hi, log_lo;
  float t_hi, t_lo;
  float f, g, u, v, q;

  volatile float r, s, e;



  expo = (__float_as_int(a) >> 23) & 0xff;


  if (expo == 0) {
    a *= 16777216.0f;
    expo = (__float_as_int(a) >> 23) & 0xff;
    expo -= 24;
  }

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

static __attribute__((__unused__)) float __internal_accurate_log2f(float a)
{
  return 1.442695041f * __internal_accurate_logf(a);
}




static __attribute__((__unused__)) float2 __internal_dsmul (float2 x, float2 y)
{
    float2 z;

    volatile float up, vp, u1, u2, v1, v2, mh, ml;



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


static unsigned int __cudart_i2opi_f [] = {
  0x3c439041,
  0xdb629599,
  0xf534ddc0,
  0xfc2757d1,
  0x4e441529,
  0xa2f9836e,
};


static __attribute__((__unused__)) float __internal_trig_reduction_kernel(float a, int *quadrant)
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


  a = __fmaf_rn (-j, 4.8382673412561417e-004f, a);




  a = __internal_fmad (-j, 6.0771005065061922e-011f, a);
  *quadrant = q;
  return a;
}
# 1743 "/usr/local/cuda/bin/../include/math_functions.h" 3
static __attribute__((__unused__)) float __internal_expf_kernel(float a, float scale)
{
  float j, z;

  j = __cuda_truncf(a * 1.442695041f);
  z = __internal_fmad (j, -0.6931457519f, a);
  z = __internal_fmad (j, -1.4286067653e-6f, z);
  z = z * 1.442695041f;
  z = __cuda_exp2f(z) * __cuda_exp2f(j + scale);
  return z;
}

static __attribute__((__unused__)) float __internal_accurate_expf(float a)
{
  float z;

  z = __internal_expf_kernel(a, 0.0f);
  if (a < -105.0f) z = 0.0f;
  if (a > 105.0f) z = __int_as_float(0x7f800000);
  return z;
}

static __attribute__((__unused__)) float __internal_accurate_exp10f(float a)
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

static __attribute__((__unused__)) float __internal_lgammaf_pos(float a)
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


static __attribute__((__unused__)) float __internal_sin_kernel(float x)
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


static __attribute__((__unused__)) float __internal_cos_kernel(float x)
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

static __attribute__((__unused__)) float __internal_accurate_sinf(float a)
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







static __attribute__((__unused__)) float __cuda_rintf(float a)
{



  return __cuda_nearbyintf(a);

}

static __attribute__((__unused__)) float __cuda_sinf(float a)
{





  return __internal_accurate_sinf(a);

}

static __attribute__((__unused__)) float __cuda_cosf(float a)
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

static __attribute__((__unused__)) float __cuda_tanf(float a)
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

static __attribute__((__unused__)) float __cuda_log2f(float a)
{





  return __internal_accurate_log2f(a);

}

static __attribute__((__unused__)) float __cuda_expf(float a)
{





  return __internal_accurate_expf(a);

}

static __attribute__((__unused__)) float __cuda_exp10f(float a)
{





  return __internal_accurate_exp10f(a);

}

static __attribute__((__unused__)) float __cuda_coshf(float a)
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

static __attribute__((__unused__)) float __cuda_sinhf(float a)
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

static __attribute__((__unused__)) float __cuda_tanhf(float a)
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

static __attribute__((__unused__)) float __cuda_atan2f(float a, float b)
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

static __attribute__((__unused__)) float __cuda_atanf(float a)
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


static __attribute__((__unused__)) float __internal_asinf_kernel(float a)
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

static __attribute__((__unused__)) float __cuda_asinf(float a)
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

static __attribute__((__unused__)) float __cuda_acosf(float a)
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

static __attribute__((__unused__)) float __cuda_logf(float a)
{





  return __internal_accurate_logf(a);

}

static __attribute__((__unused__)) float __cuda_log10f(float a)
{





  return 0.434294482f * __internal_accurate_logf(a);

}

static __attribute__((__unused__)) float __cuda_log1pf(float a)
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

static __attribute__((__unused__)) float __cuda_acoshf(float a)
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

static __attribute__((__unused__)) float __cuda_asinhf(float a)
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

static __attribute__((__unused__)) float __cuda_atanhf(float a)
{



  float fa, t;

  fa = __cuda_fabsf(a);
  t = __fdividef ((2.0f * fa), (1.0f - fa));
  t = 0.5f * __cuda_log1pf(t);
  return __cuda_copysignf(t, a);

}

static __attribute__((__unused__)) float __cuda_expm1f(float a)
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

static __attribute__((__unused__)) float __cuda_hypotf(float a, float b)
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

static __attribute__((__unused__)) float __cuda_cbrtf(float a)
{



  float s, t;

  s = __cuda_fabsf(a);
  if ((a == 0.0f) || (s == __int_as_float(0x7f800000))) {
    return a + a;
  }
  t = __cuda_exp2f(0.333333333f * __log2f(s));
  t = t-(t-(__fdividef(s,(t*t))))*0.333333333f;





  t = __cuda_copysignf(t, a);

  return t;

}

static __attribute__((__unused__)) float __cuda_erff(float a)
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

static __attribute__((__unused__)) float __cuda_erfinvf (float a)
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

static __attribute__((__unused__)) float __cuda_erfcf(float a)
{

    if (__cuda___isnanf(a)) return a + a;

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

static __attribute__((__unused__)) float __cuda_erfcinvf (float a)
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

static __attribute__((__unused__)) float __cuda_lgammaf(float a)
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

static __attribute__((__unused__)) float __cuda_ldexpf(float a, int b)
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

static __attribute__((__unused__)) float __cuda_scalbnf(float a, int b)
{




  return __cuda_ldexpf(a, b);

}

static __attribute__((__unused__)) float __cuda_scalblnf(float a, long int b)
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

static __attribute__((__unused__)) float __cuda_frexpf(float a, int *b)
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

static __attribute__((__unused__)) float __cuda_modff(float a, float *b)
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

static __attribute__((__unused__)) float __cuda_fmodf(float a, float b)
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


    int expoa = (a < 1.175494351e-38f) ?
        ((int)__log2f(a)) : (((__float_as_int(a) >> 23) & 0xff) - 127);
    int expob = (b < 1.175494351e-38f) ?
        ((int)__log2f(b)) : (((__float_as_int(b) >> 23) & 0xff) - 127);
    int scale = expoa - expob;
    float scaled_b = __cuda_ldexpf(b, scale);
    if (scaled_b <= 0.5f * a) {
      scaled_b *= 2.0f;
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

static __attribute__((__unused__)) float __cuda_remainderf(float a, float b)
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

    int expoa = (a < 1.175494351e-38f) ?
        ((int)__log2f(a)) : (((__float_as_int(a) >> 23) & 0xff) - 127);
    int expob = (b < 1.175494351e-38f) ?
        ((int)__log2f(b)) : (((__float_as_int(b) >> 23) & 0xff) - 127);
    int scale = expoa - expob;
    float scaled_b = __cuda_ldexpf(b, scale);
    if (scaled_b <= 0.5f * a) {
      scaled_b *= 2.0f;
    }
# 2758 "/usr/local/cuda/bin/../include/math_functions.h" 3
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


  twoa = 2.0f * a;
  if ((twoa > b) || ((twoa == b) && quot0)) {
    a -= b;
    a = __int_as_float(__float_as_int(a) | 0x80000000);
  }
# 2790 "/usr/local/cuda/bin/../include/math_functions.h" 3
  a = __int_as_float((__float_as_int(orig_a) & 0x80000000)^
                     __float_as_int(a));
  return a;
}

static __attribute__((__unused__)) float __cuda_remquof(float a, float b, int* quo)
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


    int expoa = (a < 1.175494351e-38f) ?
        ((int)__log2f(a)) : (((__float_as_int(a) >> 23) & 0xff) - 127);
    int expob = (b < 1.175494351e-38f) ?
        ((int)__log2f(b)) : (((__float_as_int(b) >> 23) & 0xff) - 127);
    int scale = expoa - expob;
    float scaled_b = __cuda_ldexpf(b, scale);
    if (scaled_b <= 0.5f * a) {
      scaled_b *= 2.0f;
    }
# 2846 "/usr/local/cuda/bin/../include/math_functions.h" 3
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


  twoa = 2.0f * a;
  if ((twoa > b) || ((twoa == b) && (quot & 1))) {
    quot++;
    a -= b;
    a = __cuda_copysignf (a, -1.0f);
  }
# 2881 "/usr/local/cuda/bin/../include/math_functions.h" 3
  a = __int_as_float((__float_as_int(orig_a) & 0x80000000)^
                     __float_as_int(a));
  quot = quot & (~((~0)<<3));
  quot = quot ^ sign;
  quot = quot - sign;
  *quo = quot;
  return a;
}

static __attribute__((__unused__)) float __cuda_fmaf(float a, float b, float c)
{
  return __fmaf_rn(a, b, c);
}

static __attribute__((__unused__)) float __internal_accurate_powf(float a, float b)
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

static __attribute__((__unused__)) float __cuda_powif(float a, int b)
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

static __attribute__((__unused__)) double __cuda_powi(double a, int b)
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

static __attribute__((__unused__)) float __cuda_powf(float a, float b)
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


static __attribute__((__unused__)) float __internal_tgammaf_kernel(float a)
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





static __attribute__((__unused__)) float __cuda_tgammaf(float a)
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

      return x;

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

static __attribute__((__unused__)) float __cuda_roundf(float a)
{



  float fa = __cuda_fabsf(a);
  float u = __cuda_copysignf (0.5f, a);
  u = __cuda_truncf (a + u);
  if (fa > 8388608.0f) u = a;
  if (fa < 0.5f) u = __cuda_truncf (a);
  return u;

}

static __attribute__((__unused__)) long long int __internal_llroundf_kernel(float a)
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

static __attribute__((__unused__)) long long int __cuda_llroundf(float a)
{



  return __internal_llroundf_kernel(a);

}

static __attribute__((__unused__)) long int __cuda_lroundf(float a)
{







  if (__cuda___isnanf(a)) return 0L;
  if (a >= 2147483648.0f) return 2147483647L;
  if (a <= -2147483648.0f) return (-2147483647L - 1L);

  return (long int)(__cuda_roundf(a));


}

static __attribute__((__unused__)) float __cuda_fdimf(float a, float b)
{
  float t;
  t = a - b;
  if (a <= b) {
    t = 0.0f;
  }
  return t;
}

static __attribute__((__unused__)) int __cuda_ilogbf(float a)
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

static __attribute__((__unused__)) float __cuda_logbf(float a)
{



  unsigned int i;
  int expo;
  float res;

  if (__cuda___isnanf(a)) return a + a;

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

static __attribute__((__unused__)) void __cuda_sincosf(float a, float *sptr, float *cptr)
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
# 3298 "/usr/local/cuda/bin/../include/math_functions.h" 3


extern __attribute__((__weak__)) double rsqrt(double a); double rsqrt(double a)
{
  return 1.0 / sqrt(a);
}

extern __attribute__((__weak__)) float rsqrtf(float a); float rsqrtf(float a)
{
  return (float)rsqrt((double)a);
}


# 3863 "/usr/local/cuda/bin/../include/math_functions.h" 3
# 1 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx1.h" 1 3
# 45 "/usr/local/cuda/bin/../include/math_functions_dbl_ptx1.h" 3
static __attribute__((__unused__)) double __cuda_fabs(double a)
{
  return (float)__cuda_fabsf((float)a);
}

static __attribute__((__unused__)) double __cuda_fmax(double a, double b)
{
  return (float)__cuda_fmaxf((float)a, (float)b);
}

static __attribute__((__unused__)) double __cuda_fmin(double a, double b)
{
  return (float)__cuda_fminf((float)a, (float)b);
}

static __attribute__((__unused__)) int __cuda___finite(double a)
{
  return __cuda___finitef((float)a);
}

static __attribute__((__unused__)) int __cuda___isinf(double a)
{
  return __cuda___isinff((float)a);
}

static __attribute__((__unused__)) int __cuda___isnan(double a)
{
  return __cuda___isnanf((float)a);
}

static __attribute__((__unused__)) int __cuda___signbit(double a)
{
  return __cuda___signbitf((float)a);
}

static __attribute__((__unused__)) double __cuda_sqrt(double a)
{
  return (double)__cuda_sqrtf((float)a);
}

static __attribute__((__unused__)) double __cuda_rsqrt(double a)
{
  return (double)__cuda_rsqrtf((float)a);
}

static __attribute__((__unused__)) double __cuda_ceil(double a)
{
  return (double)__cuda_ceilf((float)a);
}

static __attribute__((__unused__)) double __cuda_trunc(double a)
{
  return (double)__cuda_truncf((float)a);
}

static __attribute__((__unused__)) double __cuda_floor(double a)
{
  return (double)__cuda_floorf((float)a);
}

static __attribute__((__unused__)) double __cuda_copysign(double a, double b)
{
  return (double)__cuda_copysignf((float)a, (float)b);
}

static __attribute__((__unused__)) double __cuda_sin(double a)
{
  return (double)__cuda_sinf((float)a);
}

static __attribute__((__unused__)) double __cuda_cos(double a)
{
  return (double)__cuda_cosf((float)a);
}

static __attribute__((__unused__)) void __cuda_sincos(double a, double *sptr, double *cptr)
{
  float fs, fc;

  __cuda_sincosf((float)a, &fs, &fc);

  *sptr = (double)fs;
  *cptr = (double)fc;
}

static __attribute__((__unused__)) double __cuda_tan(double a)
{
  return (double)__cuda_tanf((float)a);
}

static __attribute__((__unused__)) double __cuda_exp(double a)
{
  return (double)__cuda_expf((float)a);
}

static __attribute__((__unused__)) double __cuda_exp2(double a)
{
  return (double)__cuda_exp2f((float)a);
}

static __attribute__((__unused__)) double __cuda_exp10(double a)
{
  return (double)__cuda_exp10f((float)a);
}

static __attribute__((__unused__)) double __cuda_expm1(double a)
{
  return (double)__cuda_expm1f((float)a);
}

static __attribute__((__unused__)) double __cuda_cosh(double a)
{
  return (double)__cuda_coshf((float)a);
}

static __attribute__((__unused__)) double __cuda_sinh(double a)
{
  return (double)__cuda_sinhf((float)a);
}

static __attribute__((__unused__)) double __cuda_tanh(double a)
{
  return (double)__cuda_tanhf((float)a);
}

static __attribute__((__unused__)) double __cuda_asin(double a)
{
  return (double)__cuda_asinf((float)a);
}

static __attribute__((__unused__)) double __cuda_acos(double a)
{
  return (double)__cuda_acosf((float)a);
}

static __attribute__((__unused__)) double __cuda_atan(double a)
{
  return (double)__cuda_atanf((float)a);
}

static __attribute__((__unused__)) double __cuda_atan2(double a, double b)
{
  return (double)__cuda_atan2f((float)a, (float)b);
}

static __attribute__((__unused__)) double __cuda_log(double a)
{
  return (double)__cuda_logf((float)a);
}

static __attribute__((__unused__)) double __cuda_log2(double a)
{
  return (double)__cuda_log2f((float)a);
}

static __attribute__((__unused__)) double __cuda_log10(double a)
{
  return (double)__cuda_log10f((float)a);
}

static __attribute__((__unused__)) double __cuda_log1p(double a)
{
  return (double)__cuda_log1pf((float)a);
}

static __attribute__((__unused__)) double __cuda_acosh(double a)
{
  return (double)__cuda_acoshf((float)a);
}

static __attribute__((__unused__)) double __cuda_asinh(double a)
{
  return (double)__cuda_asinhf((float)a);
}

static __attribute__((__unused__)) double __cuda_atanh(double a)
{
  return (double)__cuda_atanhf((float)a);
}

static __attribute__((__unused__)) double __cuda_hypot(double a, double b)
{
  return (double)__cuda_hypotf((float)a, (float)b);
}

static __attribute__((__unused__)) double __cuda_cbrt(double a)
{
  return (double)__cuda_cbrtf((float)a);
}

static __attribute__((__unused__)) double __cuda_erf(double a)
{
  return (double)__cuda_erff((float)a);
}

static __attribute__((__unused__)) double __cuda_erfinv(double a)
{
  return (double)__cuda_erfinvf((float)a);
}

static __attribute__((__unused__)) double __cuda_erfc(double a)
{
  return (double)__cuda_erfcf((float)a);
}

static __attribute__((__unused__)) double __cuda_erfcinv(double a)
{
  return (double)__cuda_erfcinvf((float)a);
}

static __attribute__((__unused__)) double __cuda_lgamma(double a)
{
  return (double)__cuda_lgammaf((float)a);
}

static __attribute__((__unused__)) double __cuda_tgamma(double a)
{
  return (double)__cuda_tgammaf((float)a);
}

static __attribute__((__unused__)) double __cuda_ldexp(double a, int b)
{
  return (double)__cuda_ldexpf((float)a, b);
}

static __attribute__((__unused__)) double __cuda_scalbn(double a, int b)
{
  return (double)__cuda_scalbnf((float)a, b);
}

static __attribute__((__unused__)) double __cuda_scalbln(double a, long b)
{
  return (double)__cuda_scalblnf((float)a, b);
}

static __attribute__((__unused__)) double __cuda_frexp(double a, int *b)
{
  return (double)__cuda_frexpf((float)a, b);
}

static __attribute__((__unused__)) double __cuda_modf(double a, double *b)
{
  float fb;
  float fa = __cuda_modff((float)a, &fb);

  *b = (double)fb;

  return (double)fa;
}

static __attribute__((__unused__)) double __cuda_fmod(double a, double b)
{
  return (double)__cuda_fmodf((float)a, (float)b);
}

static __attribute__((__unused__)) double __cuda_remainder(double a, double b)
{
  return (double)__cuda_remainderf((float)a, (float)b);
}

static __attribute__((__unused__)) double __cuda_remquo(double a, double b, int *c)
{
  return (double)__cuda_remquof((float)a, (float)b, c);
}

static __attribute__((__unused__)) double __cuda_nextafter(double a, double b)
{
  return (double)__cuda_nextafterf((float)a, (float)b);
}

static __attribute__((__unused__)) double __cuda_nan(const char *tagp)
{
  return (double)__cuda_nanf(tagp);
}

static __attribute__((__unused__)) double __cuda_pow(double a, double b)
{
  return (double)__cuda_powf((float)a, (float)b);
}

static __attribute__((__unused__)) double __cuda_round(double a)
{
  return (double)__cuda_roundf((float)a);
}

static __attribute__((__unused__)) long __cuda_lround(double a)
{
  return __cuda_lroundf((float)a);
}

static __attribute__((__unused__)) long long __cuda_llround(double a)
{
  return __cuda_llroundf((float)a);
}

static __attribute__((__unused__)) double __cuda_rint(double a)
{
  return (double)__cuda_rintf((float)a);
}

static __attribute__((__unused__)) long __cuda_lrint(double a)
{
  return __cuda_lrintf((float)a);
}

static __attribute__((__unused__)) long long __cuda_llrint(double a)
{
  return __cuda_llrintf((float)a);
}

static __attribute__((__unused__)) double __cuda_nearbyint(double a)
{
  return (double)__cuda_nearbyintf((float)a);
}

static __attribute__((__unused__)) double __cuda_fdim(double a, double b)
{
  return (double)__cuda_fdimf((float)a, (float)b);
}

static __attribute__((__unused__)) int __cuda_ilogb(double a)
{
  return __cuda_ilogbf((float)a);
}

static __attribute__((__unused__)) double __cuda_logb(double a)
{
  return (double)__cuda_logbf((float)a);
}

static __attribute__((__unused__)) double __cuda_fma(double a, double b, double c)
{
  return (double)__cuda_fmaf((float)a, (float)b, (float)c);
}
# 3864 "/usr/local/cuda/bin/../include/math_functions.h" 2 3
# 94 "/usr/local/cuda/bin/../include/common_functions.h" 2 3
# 275 "/usr/local/cuda/bin/../include/crt/host_runtime.h" 2 3
# 6 "main.cudafe1.stub.c" 2 3




struct __T20 {int *__par0;float *__par1;int *__par2;int __par3;int __par4;int __par5;struct _gpufi_data_ *__par6;int __dummy_field;};
static void __sti____cudaRegisterAll_12_main_cpp1_ii_46b07679(void) __attribute__((__constructor__));
void __device_stub__Z14PetrinetKernelPiPfS_iiiP12_gpufi_data_(int *__par0, float *__par1, int *__par2, int __par3, int __par4, int __par5, struct _gpufi_data_ *__par6){auto struct __T20 *__T24;
*(void**)(void*)&__T24 = (void*)0;if (cudaSetupArgument((void*)(char*)&__par0, sizeof(__par0), (size_t)&__T24->__par0) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par1, sizeof(__par1), (size_t)&__T24->__par1) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par2, sizeof(__par2), (size_t)&__T24->__par2) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par3, sizeof(__par3), (size_t)&__T24->__par3) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par4, sizeof(__par4), (size_t)&__T24->__par4) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par5, sizeof(__par5), (size_t)&__T24->__par5) != cudaSuccess) return;if (cudaSetupArgument((void*)(char*)&__par6, sizeof(__par6), (size_t)&__T24->__par6) != cudaSuccess) return;{ volatile static char *__f; __f = ((char *)((void ( *)(int *, float *, int *, int, int, int, struct _gpufi_data_ *))PetrinetKernel__entry)); (void)cudaLaunch(((char *)((void ( *)(int *, float *, int *, int, int, int, struct _gpufi_data_ *))PetrinetKernel__entry))); };}

}
void PetrinetKernel__entry( int *__cuda_0,float *__cuda_1,int *__cuda_2,int __cuda_3,int __cuda_4,int __cuda_5,struct _gpufi_data_ *__cuda_6)
{__device_stub__Z14PetrinetKernelPiPfS_iiiP12_gpufi_data_( __cuda_0,__cuda_1,__cuda_2,__cuda_3,__cuda_4,__cuda_5,__cuda_6);}
extern "C"{
# 29 "main.cudafe1.stub.c" 3
static void __sti____cudaRegisterAll_12_main_cpp1_ii_46b07679(void){__cudaFatCubinHandle = __cudaRegisterFatBinary((void*)(&__fatDeviceText)); atexit(__cudaUnregisterBinaryUtil);__cudaRegisterFunction(__cudaFatCubinHandle, (const char*)((void ( *)(int *, float *, int *, int, int, int, struct _gpufi_data_ *))PetrinetKernel__entry), (char*)"_Z14PetrinetKernelPiPfS_iiiP12_gpufi_data_", "_Z14PetrinetKernelPiPfS_iiiP12_gpufi_data_", (-1), (uint3*)0, (uint3*)0, (dim3*)0, (dim3*)0, (int*)0);__cudaRegisterVar(__cudaFatCubinHandle, (char*)&gpufi_dev__cuda_shadow_variable__, (char*)"gpufi_dev", "gpufi_dev", 0, 4, 0, 0);__cudaRegisterSharedVar(__cudaFatCubinHandle, (void**)"mt", 2496, 4, 0);}

}
# 349 "src/cuda_fi_prerun/main.cu" 2
