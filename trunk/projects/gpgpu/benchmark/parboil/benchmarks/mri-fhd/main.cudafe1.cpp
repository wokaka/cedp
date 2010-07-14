# 1 "src/cuda_wo_loop/main.cu"
# 233 "/usr/include/c++/4.3/i486-linux-gnu/bits/c++config.h" 3
namespace std __attribute__((visibility("default"))) { 
# 245 "/usr/include/c++/4.3/i486-linux-gnu/bits/c++config.h" 3
}
# 46 "/usr/local/cuda/bin/../include/device_types.h"
#if 0
# 46
enum cudaRoundMode { 

cudaRoundNearest, 
cudaRoundZero, 
cudaRoundPosInf, 
cudaRoundMinInf
}; 
#endif
# 152 "/usr/lib/gcc/i486-linux-gnu/4.3.2/include/stddef.h" 3
typedef int ptrdiff_t; 
# 214 "/usr/lib/gcc/i486-linux-gnu/4.3.2/include/stddef.h" 3
typedef unsigned size_t; 
#include "crt/host_runtime.h"
# 91 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 91
enum cudaError { 

cudaSuccess, 
cudaErrorMissingConfiguration, 
cudaErrorMemoryAllocation, 
cudaErrorInitializationError, 
cudaErrorLaunchFailure, 
cudaErrorPriorLaunchFailure, 
cudaErrorLaunchTimeout, 
cudaErrorLaunchOutOfResources, 
cudaErrorInvalidDeviceFunction, 
cudaErrorInvalidConfiguration, 
cudaErrorInvalidDevice, 
cudaErrorInvalidValue, 
cudaErrorInvalidPitchValue, 
cudaErrorInvalidSymbol, 
cudaErrorMapBufferObjectFailed, 
cudaErrorUnmapBufferObjectFailed, 
cudaErrorInvalidHostPointer, 
cudaErrorInvalidDevicePointer, 
cudaErrorInvalidTexture, 
cudaErrorInvalidTextureBinding, 
cudaErrorInvalidChannelDescriptor, 
cudaErrorInvalidMemcpyDirection, 
cudaErrorAddressOfConstant, 
cudaErrorTextureFetchFailed, 
cudaErrorTextureNotBound, 
cudaErrorSynchronizationError, 
cudaErrorInvalidFilterSetting, 
cudaErrorInvalidNormSetting, 
cudaErrorMixedDeviceExecution, 
cudaErrorCudartUnloading, 
cudaErrorUnknown, 
cudaErrorNotYetImplemented, 
cudaErrorMemoryValueTooLarge, 
cudaErrorInvalidResourceHandle, 
cudaErrorNotReady, 
cudaErrorInsufficientDriver, 
cudaErrorSetOnActiveProcess, 
cudaErrorNoDevice = 38, 
cudaErrorStartupFailure = 127, 
cudaErrorApiFailureBase = 10000
}; 
#endif
# 139 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 139
enum cudaChannelFormatKind { 

cudaChannelFormatKindSigned, 
cudaChannelFormatKindUnsigned, 
cudaChannelFormatKindFloat, 
cudaChannelFormatKindNone
}; 
#endif
# 151 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 151
struct cudaChannelFormatDesc { 

int x; 
int y; 
int z; 
int w; 
cudaChannelFormatKind f; 
}; 
#endif
# 164 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
struct cudaArray; 
#endif
# 170 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 170
enum cudaMemcpyKind { 

cudaMemcpyHostToHost, 
cudaMemcpyHostToDevice, 
cudaMemcpyDeviceToHost, 
cudaMemcpyDeviceToDevice
}; 
#endif
# 182 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 182
struct cudaPitchedPtr { 

void *ptr; 
size_t pitch; 
size_t xsize; 
size_t ysize; 
}; 
#endif
# 194 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 194
struct cudaExtent { 

size_t width; 
size_t height; 
size_t depth; 
}; 
#endif
# 205 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 205
struct cudaPos { 

size_t x; 
size_t y; 
size_t z; 
}; 
#endif
# 216 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 216
struct cudaMemcpy3DParms { 

cudaArray *srcArray; 
cudaPos srcPos; 
cudaPitchedPtr srcPtr; 

cudaArray *dstArray; 
cudaPos dstPos; 
cudaPitchedPtr dstPtr; 

cudaExtent extent; 
cudaMemcpyKind kind; 
}; 
#endif
# 234 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 234
struct cudaFuncAttributes { 

size_t sharedSizeBytes; 
size_t constSizeBytes; 
size_t localSizeBytes; 
int maxThreadsPerBlock; 
int numRegs; 
int __cudaReserved[8]; 
}; 
#endif
# 248 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 248
enum cudaComputeMode { 

cudaComputeModeDefault, 
cudaComputeModeExclusive, 
cudaComputeModeProhibited
}; 
#endif
# 260 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 260
struct cudaDeviceProp { 

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
#endif
# 319 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
typedef cudaError 
# 319
cudaError_t; 
#endif
# 325 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
typedef int 
# 325
cudaStream_t; 
#endif
# 331 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
typedef int 
# 331
cudaEvent_t; 
#endif
# 54 "/usr/local/cuda/bin/../include/texture_types.h"
#if 0
# 54
enum cudaTextureAddressMode { 

cudaAddressModeWrap, 
cudaAddressModeClamp
}; 
#endif
# 61 "/usr/local/cuda/bin/../include/texture_types.h"
#if 0
# 61
enum cudaTextureFilterMode { 

cudaFilterModePoint, 
cudaFilterModeLinear
}; 
#endif
# 68 "/usr/local/cuda/bin/../include/texture_types.h"
#if 0
# 68
enum cudaTextureReadMode { 

cudaReadModeElementType, 
cudaReadModeNormalizedFloat
}; 
#endif
# 75 "/usr/local/cuda/bin/../include/texture_types.h"
#if 0
# 75
struct textureReference { 

int normalized; 
cudaTextureFilterMode filterMode; 
cudaTextureAddressMode addressMode[3]; 
cudaChannelFormatDesc channelDesc; 
int __cudaReserved[16]; 
}; 
#endif
# 82 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 82
struct char1 { 

signed char x; 

}; 
#endif
# 89 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 89
struct uchar1 { 

unsigned char x; 

}; 
#endif
# 96 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 96
struct __attribute__((__aligned__(2))) char2 { 

signed char x; signed char y; 

}; 
#endif
# 103 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 103
struct __attribute__((__aligned__(2))) uchar2 { 

unsigned char x; unsigned char y; 

}; 
#endif
# 110 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 110
struct char3 { 

signed char x; signed char y; signed char z; 

}; 
#endif
# 117 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 117
struct uchar3 { 

unsigned char x; unsigned char y; unsigned char z; 

}; 
#endif
# 124 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 124
struct __attribute__((__aligned__(4))) char4 { 

signed char x; signed char y; signed char z; signed char w; 

}; 
#endif
# 131 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 131
struct __attribute__((__aligned__(4))) uchar4 { 

unsigned char x; unsigned char y; unsigned char z; unsigned char w; 

}; 
#endif
# 138 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 138
struct short1 { 

short x; 

}; 
#endif
# 145 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 145
struct ushort1 { 

unsigned short x; 

}; 
#endif
# 152 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 152
struct __attribute__((__aligned__(4))) short2 { 

short x; short y; 

}; 
#endif
# 159 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 159
struct __attribute__((__aligned__(4))) ushort2 { 

unsigned short x; unsigned short y; 

}; 
#endif
# 166 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 166
struct short3 { 

short x; short y; short z; 

}; 
#endif
# 173 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 173
struct ushort3 { 

unsigned short x; unsigned short y; unsigned short z; 

}; 
#endif
# 180 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 180
struct __attribute__((__aligned__(8))) short4 { short x; short y; short z; short w; }; 
#endif
# 183 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 183
struct __attribute__((__aligned__(8))) ushort4 { unsigned short x; unsigned short y; unsigned short z; unsigned short w; }; 
#endif
# 186 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 186
struct int1 { 

int x; 

}; 
#endif
# 193 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 193
struct uint1 { 

unsigned x; 

}; 
#endif
# 200 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 200
struct __attribute__((__aligned__(8))) int2 { int x; int y; }; 
#endif
# 203 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 203
struct __attribute__((__aligned__(8))) uint2 { unsigned x; unsigned y; }; 
#endif
# 206 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 206
struct int3 { 

int x; int y; int z; 

}; 
#endif
# 213 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 213
struct uint3 { 

unsigned x; unsigned y; unsigned z; 

}; 
#endif
# 220 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 220
struct __attribute__((__aligned__(16))) int4 { 

int x; int y; int z; int w; 

}; 
#endif
# 227 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 227
struct __attribute__((__aligned__(16))) uint4 { 

unsigned x; unsigned y; unsigned z; unsigned w; 

}; 
#endif
# 234 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 234
struct long1 { 

long x; 

}; 
#endif
# 241 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 241
struct ulong1 { 

unsigned long x; 

}; 
#endif
# 258 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 258
struct __attribute__((__aligned__(8))) long2 { 

long x; long y; 

}; 
#endif
# 265 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 265
struct __attribute__((__aligned__(8))) ulong2 { 

unsigned long x; unsigned long y; 

}; 
#endif
# 276 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 276
struct long3 { 

long x; long y; long z; 

}; 
#endif
# 283 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 283
struct ulong3 { 

unsigned long x; unsigned long y; unsigned long z; 

}; 
#endif
# 290 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 290
struct __attribute__((__aligned__(16))) long4 { 

long x; long y; long z; long w; 

}; 
#endif
# 297 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 297
struct __attribute__((__aligned__(16))) ulong4 { 

unsigned long x; unsigned long y; unsigned long z; unsigned long w; 

}; 
#endif
# 306 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 306
struct float1 { 

float x; 

}; 
#endif
# 313 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 313
struct __attribute__((__aligned__(8))) float2 { float x; float y; }; 
#endif
# 316 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 316
struct float3 { 

float x; float y; float z; 

}; 
#endif
# 323 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 323
struct __attribute__((__aligned__(16))) float4 { 

float x; float y; float z; float w; 

}; 
#endif
# 330 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 330
struct longlong1 { 

long long x; 

}; 
#endif
# 337 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 337
struct ulonglong1 { 

unsigned long long x; 

}; 
#endif
# 344 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 344
struct __attribute__((__aligned__(16))) longlong2 { 

long long x; long long y; 

}; 
#endif
# 351 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 351
struct __attribute__((__aligned__(16))) ulonglong2 { 

unsigned long long x; unsigned long long y; 

}; 
#endif
# 358 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 358
struct double1 { 

double x; 

}; 
#endif
# 365 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 365
struct __attribute__((__aligned__(16))) double2 { 

double x; double y; 

}; 
#endif
# 378 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef char1 
# 378
char1; 
#endif
# 380 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef uchar1 
# 380
uchar1; 
#endif
# 382 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef char2 
# 382
char2; 
#endif
# 384 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef uchar2 
# 384
uchar2; 
#endif
# 386 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef char3 
# 386
char3; 
#endif
# 388 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef uchar3 
# 388
uchar3; 
#endif
# 390 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef char4 
# 390
char4; 
#endif
# 392 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef uchar4 
# 392
uchar4; 
#endif
# 394 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef short1 
# 394
short1; 
#endif
# 396 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ushort1 
# 396
ushort1; 
#endif
# 398 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef short2 
# 398
short2; 
#endif
# 400 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ushort2 
# 400
ushort2; 
#endif
# 402 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef short3 
# 402
short3; 
#endif
# 404 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ushort3 
# 404
ushort3; 
#endif
# 406 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef short4 
# 406
short4; 
#endif
# 408 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ushort4 
# 408
ushort4; 
#endif
# 410 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef int1 
# 410
int1; 
#endif
# 412 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef uint1 
# 412
uint1; 
#endif
# 414 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef int2 
# 414
int2; 
#endif
# 416 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef uint2 
# 416
uint2; 
#endif
# 418 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef int3 
# 418
int3; 
#endif
# 420 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef uint3 
# 420
uint3; 
#endif
# 422 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef int4 
# 422
int4; 
#endif
# 424 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef uint4 
# 424
uint4; 
#endif
# 426 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef long1 
# 426
long1; 
#endif
# 428 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ulong1 
# 428
ulong1; 
#endif
# 430 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef long2 
# 430
long2; 
#endif
# 432 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ulong2 
# 432
ulong2; 
#endif
# 434 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef long3 
# 434
long3; 
#endif
# 436 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ulong3 
# 436
ulong3; 
#endif
# 438 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef long4 
# 438
long4; 
#endif
# 440 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ulong4 
# 440
ulong4; 
#endif
# 442 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef float1 
# 442
float1; 
#endif
# 444 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef float2 
# 444
float2; 
#endif
# 446 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef float3 
# 446
float3; 
#endif
# 448 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef float4 
# 448
float4; 
#endif
# 450 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef longlong1 
# 450
longlong1; 
#endif
# 452 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ulonglong1 
# 452
ulonglong1; 
#endif
# 454 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef longlong2 
# 454
longlong2; 
#endif
# 456 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ulonglong2 
# 456
ulonglong2; 
#endif
# 458 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef double1 
# 458
double1; 
#endif
# 460 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef double2 
# 460
double2; 
#endif
# 469 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 469
struct dim3 { 

unsigned x; unsigned y; unsigned z; 
# 477
}; 
#endif
# 480 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef dim3 
# 480
dim3; 
#endif
# 89 "/usr/local/cuda/bin/../include/cuda_runtime_api.h"
extern "C" cudaError_t cudaMalloc3D(cudaPitchedPtr *, cudaExtent); 
extern "C" cudaError_t cudaMalloc3DArray(cudaArray **, const cudaChannelFormatDesc *, cudaExtent); 
extern "C" cudaError_t cudaMemset3D(cudaPitchedPtr, int, cudaExtent); 
extern "C" cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms *); 
extern "C" cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms *, cudaStream_t); 
# 102
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
# 121
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
# 138
extern "C" cudaError_t cudaMemcpyAsync(void *, const void *, size_t, cudaMemcpyKind, cudaStream_t); 
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind, cudaStream_t); 
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t); 
extern "C" cudaError_t cudaMemcpy2DAsync(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t); 
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t); 
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t); 
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char *, const void *, size_t, size_t, cudaMemcpyKind, cudaStream_t); 
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void *, const char *, size_t, size_t, cudaMemcpyKind, cudaStream_t); 
# 153
extern "C" cudaError_t cudaMemset(void *, int, size_t); 
extern "C" cudaError_t cudaMemset2D(void *, size_t, int, size_t, size_t); 
# 162
extern "C" cudaError_t cudaGetSymbolAddress(void **, const char *); 
extern "C" cudaError_t cudaGetSymbolSize(size_t *, const char *); 
# 171
extern "C" cudaError_t cudaGetDeviceCount(int *); 
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp *, int); 
extern "C" cudaError_t cudaChooseDevice(int *, const cudaDeviceProp *); 
extern "C" cudaError_t cudaSetDevice(int); 
extern "C" cudaError_t cudaGetDevice(int *); 
extern "C" cudaError_t cudaSetValidDevices(int *, int); 
extern "C" cudaError_t cudaSetDeviceFlags(int); 
# 185
extern "C" cudaError_t cudaBindTexture(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U)); 
extern "C" cudaError_t cudaBindTexture2D(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t, size_t, size_t); 
extern "C" cudaError_t cudaBindTextureToArray(const textureReference *, const cudaArray *, const cudaChannelFormatDesc *); 
extern "C" cudaError_t cudaUnbindTexture(const textureReference *); 
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t *, const textureReference *); 
extern "C" cudaError_t cudaGetTextureReference(const textureReference **, const char *); 
# 198
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc *, const cudaArray *); 
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int, int, int, int, cudaChannelFormatKind); 
# 207
extern "C" cudaError_t cudaGetLastError(); 
extern "C" const char *cudaGetErrorString(cudaError_t); 
# 216
extern "C" cudaError_t cudaConfigureCall(dim3, dim3, size_t = (0), cudaStream_t = (0)); 
extern "C" cudaError_t cudaSetupArgument(const void *, size_t, size_t); 
extern "C" cudaError_t cudaLaunch(const char *); 
extern "C" cudaError_t cudaFuncGetAttributes(cudaFuncAttributes *, const char *); 
# 227
extern "C" cudaError_t cudaStreamCreate(cudaStream_t *); 
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t); 
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t); 
extern "C" cudaError_t cudaStreamQuery(cudaStream_t); 
# 238
extern "C" cudaError_t cudaEventCreate(cudaEvent_t *); 
extern "C" cudaError_t cudaEventCreateWithFlags(cudaEvent_t *, int); 
extern "C" cudaError_t cudaEventRecord(cudaEvent_t, cudaStream_t); 
extern "C" cudaError_t cudaEventQuery(cudaEvent_t); 
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t); 
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t); 
extern "C" cudaError_t cudaEventElapsedTime(float *, cudaEvent_t, cudaEvent_t); 
# 252
extern "C" cudaError_t cudaSetDoubleForDevice(double *); 
extern "C" cudaError_t cudaSetDoubleForHost(double *); 
# 261
extern "C" cudaError_t cudaThreadExit(); 
extern "C" cudaError_t cudaThreadSynchronize(); 
# 270
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
# 56
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
# 134
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
# 162
extern "C" { struct itimerspec { 

timespec it_interval; 
timespec it_value; 
}; }


struct sigevent; 
# 175
extern "C" { typedef __pid_t pid_t; }
# 184
extern "C"  __attribute__((__weak__)) clock_t clock() throw(); 


extern "C" time_t time(time_t *) throw(); 


extern "C" double difftime(time_t, time_t) throw() __attribute__((__const__)); 



extern "C" time_t mktime(tm *) throw(); 
# 200
extern "C" size_t strftime(char *__restrict__, size_t, const char *__restrict__, const tm *__restrict__) throw(); 
# 208
extern "C" char *strptime(const char *__restrict__, const char *__restrict__, tm *) throw(); 
# 40 "/usr/include/xlocale.h" 3
extern "C" { typedef 
# 28
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
# 232
extern "C" tm *gmtime(const time_t *) throw(); 



extern "C" tm *localtime(const time_t *) throw(); 
# 242
extern "C" tm *gmtime_r(const time_t *__restrict__, tm *__restrict__) throw(); 




extern "C" tm *localtime_r(const time_t *__restrict__, tm *__restrict__) throw(); 
# 254
extern "C" char *asctime(const tm *) throw(); 


extern "C" char *ctime(const time_t *) throw(); 
# 265
extern "C" char *asctime_r(const tm *__restrict__, char *__restrict__) throw(); 



extern "C" char *ctime_r(const time_t *__restrict__, char *__restrict__) throw(); 
# 275
extern "C" { extern char *__tzname[2]; } 
extern "C" { extern int __daylight; } 
extern "C" { extern long __timezone; } 




extern "C" { extern char *tzname[2]; } 



extern "C" void tzset() throw(); 



extern "C" { extern int daylight; } 
extern "C" { extern long timezone; } 
# 297
extern "C" int stime(const time_t *) throw(); 
# 312
extern "C" time_t timegm(tm *) throw(); 


extern "C" time_t timelocal(tm *) throw(); 


extern "C" int dysize(int) throw() __attribute__((__const__)); 
# 327
extern "C" int nanosleep(const timespec *, timespec *); 




extern "C" int clock_getres(clockid_t, timespec *) throw(); 


extern "C" int clock_gettime(clockid_t, timespec *) throw(); 


extern "C" int clock_settime(clockid_t, const timespec *) throw(); 
# 346
extern "C" int clock_nanosleep(clockid_t, int, const timespec *, timespec *); 




extern "C" int clock_getcpuclockid(pid_t, clockid_t *) throw(); 




extern "C" int timer_create(clockid_t, sigevent *__restrict__, timer_t *__restrict__) throw(); 




extern "C" int timer_delete(timer_t) throw(); 


extern "C" int timer_settime(timer_t, int, const itimerspec *__restrict__, itimerspec *__restrict__) throw(); 




extern "C" int timer_gettime(timer_t, itimerspec *) throw(); 



extern "C" int timer_getoverrun(timer_t) throw(); 
# 389
extern "C" { extern int getdate_err; } 
# 398
extern "C" tm *getdate(const char *); 
# 412
extern "C" int getdate_r(const char *__restrict__, tm *__restrict__); 
# 38 "/usr/include/string.h" 3
extern "C"  __attribute__((__weak__)) void *memcpy(void *__restrict__, const void *__restrict__, size_t) throw(); 




extern "C" void *memmove(void *, const void *, size_t) throw(); 
# 51
extern "C" void *memccpy(void *__restrict__, const void *__restrict__, int, size_t) throw(); 
# 59
extern "C"  __attribute__((__weak__)) void *memset(void *, int, size_t) throw(); 


extern "C" int memcmp(const void *, const void *, size_t) throw() __attribute__((__pure__)); 



extern "C" void *memchr(const void *, int, size_t) throw() __attribute__((__pure__)); 
# 73
extern "C" void *rawmemchr(const void *, int) throw() __attribute__((__pure__)); 



extern "C" void *memrchr(const void *, int, size_t) throw() __attribute__((__pure__)); 
# 84
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
# 130
extern "C" char *strdup(const char *) throw() __attribute__((__malloc__)); 
# 138
extern "C" char *strndup(const char *, size_t) throw() __attribute__((__malloc__)); 
# 167 "/usr/include/string.h" 3
extern "C" char *strchr(const char *, int) throw() __attribute__((__pure__)); 


extern "C" char *strrchr(const char *, int) throw() __attribute__((__pure__)); 
# 177
extern "C" char *strchrnul(const char *, int) throw() __attribute__((__pure__)); 
# 184
extern "C" size_t strcspn(const char *, const char *) throw() __attribute__((__pure__)); 



extern "C" size_t strspn(const char *, const char *) throw() __attribute__((__pure__)); 


extern "C" char *strpbrk(const char *, const char *) throw() __attribute__((__pure__)); 


extern "C" char *strstr(const char *, const char *) throw() __attribute__((__pure__)); 




extern "C" char *strtok(char *__restrict__, const char *__restrict__) throw(); 
# 205
extern "C" char *__strtok_r(char *__restrict__, const char *__restrict__, char **__restrict__) throw(); 




extern "C" char *strtok_r(char *__restrict__, const char *__restrict__, char **__restrict__) throw(); 
# 217
extern "C" char *strcasestr(const char *, const char *) throw() __attribute__((__pure__)); 
# 225
extern "C" void *memmem(const void *, size_t, const void *, size_t) throw() __attribute__((__pure__)); 
# 231
extern "C" void *__mempcpy(void *__restrict__, const void *__restrict__, size_t) throw(); 


extern "C" void *mempcpy(void *__restrict__, const void *__restrict__, size_t) throw(); 
# 242
extern "C" size_t strlen(const char *) throw() __attribute__((__pure__)); 
# 249
extern "C" size_t strnlen(const char *, size_t) throw() __attribute__((__pure__)); 
# 256
extern "C" char *strerror(int) throw(); 
# 281 "/usr/include/string.h" 3
extern "C" char *strerror_r(int, char *, size_t) throw(); 
# 288
extern "C" char *strerror_l(int, __locale_t) throw(); 
# 294
extern "C" void __bzero(void *, size_t) throw(); 



extern "C" void bcopy(const void *, void *, size_t) throw(); 



extern "C" void bzero(void *, size_t) throw(); 


extern "C" int bcmp(const void *, const void *, size_t) throw() __attribute__((__pure__)); 



extern "C" char *index(const char *, int) throw() __attribute__((__pure__)); 



extern "C" char *rindex(const char *, int) throw() __attribute__((__pure__)); 




extern "C" int ffs(int) throw() __attribute__((__const__)); 




extern "C" int ffsl(long) throw() __attribute__((__const__)); 

extern "C" int ffsll(long long) throw() __attribute__((__const__)); 
# 331
extern "C" int strcasecmp(const char *, const char *) throw() __attribute__((__pure__)); 



extern "C" int strncasecmp(const char *, const char *, size_t) throw() __attribute__((__pure__)); 
# 342
extern "C" int strcasecmp_l(const char *, const char *, __locale_t) throw() __attribute__((__pure__)); 



extern "C" int strncasecmp_l(const char *, const char *, size_t, __locale_t) throw() __attribute__((__pure__)); 
# 354
extern "C" char *strsep(char **__restrict__, const char *__restrict__) throw(); 
# 361
extern "C" int strverscmp(const char *, const char *) throw() __attribute__((__pure__)); 



extern "C" char *strsignal(int) throw(); 


extern "C" char *__stpcpy(char *__restrict__, const char *__restrict__) throw(); 

extern "C" char *stpcpy(char *__restrict__, const char *__restrict__) throw(); 




extern "C" char *__stpncpy(char *__restrict__, const char *__restrict__, size_t) throw(); 


extern "C" char *stpncpy(char *__restrict__, const char *__restrict__, size_t) throw(); 




extern "C" char *strfry(char *) throw(); 


extern "C" void *memfrob(void *, size_t) throw(); 
# 393
extern "C" char *basename(const char *) throw(); 
# 56 "/usr/local/cuda/bin/../include/common_functions.h"
extern "C"  __attribute__((__weak__)) clock_t clock() throw(); 


extern "C"  __attribute__((__weak__)) void *memset(void *, int, size_t) throw(); 


extern "C"  __attribute__((__weak__)) void *memcpy(void *, const void *, size_t) throw(); 
# 65 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C"  __attribute__((__weak__)) int abs(int) throw() __attribute__((__const__)); 

extern "C"  __attribute__((__weak__)) long labs(long) throw() __attribute__((__const__)); 

extern "C"  __attribute__((__weak__)) long long llabs(long long) throw() __attribute__((__const__)); 

extern "C"  __attribute__((__weak__)) double fabs(double) throw() __attribute__((__const__)); 

extern "C"  __attribute__((__weak__)) float fabsf(float) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) int min(int, int); 

extern "C"  __attribute__((__weak__)) unsigned umin(unsigned, unsigned); 

extern "C"  __attribute__((__weak__)) long long llmin(long long, long long); 

extern "C"  __attribute__((__weak__)) unsigned long long ullmin(unsigned long long, unsigned long long); 

extern "C"  __attribute__((__weak__)) float fminf(float, float) throw(); 

extern "C"  __attribute__((__weak__)) double fmin(double, double) throw(); 


extern "C"  __attribute__((__weak__)) int max(int, int); 

extern "C"  __attribute__((__weak__)) unsigned umax(unsigned, unsigned); 

extern "C"  __attribute__((__weak__)) long long llmax(long long, long long); 

extern "C"  __attribute__((__weak__)) unsigned long long ullmax(unsigned long long, unsigned long long); 

extern "C"  __attribute__((__weak__)) float fmaxf(float, float) throw(); 

extern "C"  __attribute__((__weak__)) double fmax(double, double) throw(); 


extern "C"  __attribute__((__weak__)) double sin(double) throw(); 

extern "C"  __attribute__((__weak__)) float sinf(float) throw(); 


extern "C"  __attribute__((__weak__)) double cos(double) throw(); 

extern "C"  __attribute__((__weak__)) float cosf(float) throw(); 


extern "C"  __attribute__((__weak__)) void sincos(double, double *, double *) throw(); 

extern "C"  __attribute__((__weak__)) void sincosf(float, float *, float *) throw(); 


extern "C"  __attribute__((__weak__)) double tan(double) throw(); 

extern "C"  __attribute__((__weak__)) float tanf(float) throw(); 


extern "C"  __attribute__((__weak__)) double sqrt(double) throw(); 

extern "C"  __attribute__((__weak__)) float sqrtf(float) throw(); 


extern "C"  __attribute__((__weak__)) double rsqrt(double); 

extern "C"  __attribute__((__weak__)) float rsqrtf(float); 


extern "C"  __attribute__((__weak__)) double exp2(double) throw(); 

extern "C"  __attribute__((__weak__)) float exp2f(float) throw(); 


extern "C"  __attribute__((__weak__)) double exp10(double) throw(); 

extern "C"  __attribute__((__weak__)) float exp10f(float) throw(); 


extern "C"  __attribute__((__weak__)) double expm1(double) throw(); 

extern "C"  __attribute__((__weak__)) float expm1f(float) throw(); 


extern "C"  __attribute__((__weak__)) double log2(double) throw(); 

extern "C"  __attribute__((__weak__)) float log2f(float) throw(); 


extern "C"  __attribute__((__weak__)) double log10(double) throw(); 

extern "C"  __attribute__((__weak__)) float log10f(float) throw(); 


extern "C"  __attribute__((__weak__)) double log(double) throw(); 

extern "C"  __attribute__((__weak__)) float logf(float) throw(); 


extern "C"  __attribute__((__weak__)) double log1p(double) throw(); 

extern "C"  __attribute__((__weak__)) float log1pf(float) throw(); 


extern "C"  __attribute__((__weak__)) double floor(double) throw() __attribute__((__const__)); 

extern "C"  __attribute__((__weak__)) float floorf(float) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) double exp(double) throw(); 

extern "C"  __attribute__((__weak__)) float expf(float) throw(); 


extern "C"  __attribute__((__weak__)) double cosh(double) throw(); 

extern "C"  __attribute__((__weak__)) float coshf(float) throw(); 


extern "C"  __attribute__((__weak__)) double sinh(double) throw(); 

extern "C"  __attribute__((__weak__)) float sinhf(float) throw(); 


extern "C"  __attribute__((__weak__)) double tanh(double) throw(); 

extern "C"  __attribute__((__weak__)) float tanhf(float) throw(); 


extern "C"  __attribute__((__weak__)) double acosh(double) throw(); 

extern "C"  __attribute__((__weak__)) float acoshf(float) throw(); 


extern "C"  __attribute__((__weak__)) double asinh(double) throw(); 

extern "C"  __attribute__((__weak__)) float asinhf(float) throw(); 


extern "C"  __attribute__((__weak__)) double atanh(double) throw(); 

extern "C"  __attribute__((__weak__)) float atanhf(float) throw(); 


extern "C"  __attribute__((__weak__)) double ldexp(double, int) throw(); 

extern "C"  __attribute__((__weak__)) float ldexpf(float, int) throw(); 


extern "C"  __attribute__((__weak__)) double logb(double) throw(); 

extern "C"  __attribute__((__weak__)) float logbf(float) throw(); 


extern "C"  __attribute__((__weak__)) int ilogb(double) throw(); 

extern "C"  __attribute__((__weak__)) int ilogbf(float) throw(); 


extern "C"  __attribute__((__weak__)) double scalbn(double, int) throw(); 

extern "C"  __attribute__((__weak__)) float scalbnf(float, int) throw(); 


extern "C"  __attribute__((__weak__)) double scalbln(double, long) throw(); 

extern "C"  __attribute__((__weak__)) float scalblnf(float, long) throw(); 


extern "C"  __attribute__((__weak__)) double frexp(double, int *) throw(); 

extern "C"  __attribute__((__weak__)) float frexpf(float, int *) throw(); 


extern "C"  __attribute__((__weak__)) double round(double) throw() __attribute__((__const__)); 

extern "C"  __attribute__((__weak__)) float roundf(float) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) long lround(double) throw(); 

extern "C"  __attribute__((__weak__)) long lroundf(float) throw(); 


extern "C"  __attribute__((__weak__)) long long llround(double) throw(); 

extern "C"  __attribute__((__weak__)) long long llroundf(float) throw(); 


extern "C"  __attribute__((__weak__)) double rint(double) throw(); 

extern "C"  __attribute__((__weak__)) float rintf(float) throw(); 


extern "C"  __attribute__((__weak__)) long lrint(double) throw(); 

extern "C"  __attribute__((__weak__)) long lrintf(float) throw(); 


extern "C"  __attribute__((__weak__)) long long llrint(double) throw(); 

extern "C"  __attribute__((__weak__)) long long llrintf(float) throw(); 


extern "C"  __attribute__((__weak__)) double nearbyint(double) throw(); 

extern "C"  __attribute__((__weak__)) float nearbyintf(float) throw(); 


extern "C"  __attribute__((__weak__)) double ceil(double) throw() __attribute__((__const__)); 

extern "C"  __attribute__((__weak__)) float ceilf(float) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) double trunc(double) throw() __attribute__((__const__)); 

extern "C"  __attribute__((__weak__)) float truncf(float) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) double fdim(double, double) throw(); 

extern "C"  __attribute__((__weak__)) float fdimf(float, float) throw(); 


extern "C"  __attribute__((__weak__)) double atan2(double, double) throw(); 

extern "C"  __attribute__((__weak__)) float atan2f(float, float) throw(); 


extern "C"  __attribute__((__weak__)) double atan(double) throw(); 

extern "C"  __attribute__((__weak__)) float atanf(float) throw(); 


extern "C"  __attribute__((__weak__)) double asin(double) throw(); 

extern "C"  __attribute__((__weak__)) float asinf(float) throw(); 


extern "C"  __attribute__((__weak__)) double acos(double) throw(); 

extern "C"  __attribute__((__weak__)) float acosf(float) throw(); 


extern "C"  __attribute__((__weak__)) double hypot(double, double) throw(); 

extern "C"  __attribute__((__weak__)) float hypotf(float, float) throw(); 


extern "C"  __attribute__((__weak__)) double cbrt(double) throw(); 

extern "C"  __attribute__((__weak__)) float cbrtf(float) throw(); 


extern "C"  __attribute__((__weak__)) double pow(double, double) throw(); 

extern "C"  __attribute__((__weak__)) float powf(float, float) throw(); 


extern "C"  __attribute__((__weak__)) double modf(double, double *) throw(); 

extern "C"  __attribute__((__weak__)) float modff(float, float *) throw(); 


extern "C"  __attribute__((__weak__)) double fmod(double, double) throw(); 

extern "C"  __attribute__((__weak__)) float fmodf(float, float) throw(); 


extern "C"  __attribute__((__weak__)) double remainder(double, double) throw(); 

extern "C"  __attribute__((__weak__)) float remainderf(float, float) throw(); 


extern "C"  __attribute__((__weak__)) double remquo(double, double, int *) throw(); 

extern "C"  __attribute__((__weak__)) float remquof(float, float, int *) throw(); 


extern "C"  __attribute__((__weak__)) double erf(double) throw(); 

extern "C"  __attribute__((__weak__)) float erff(float) throw(); 


extern "C"  __attribute__((__weak__)) double erfinv(double) throw(); 

extern "C"  __attribute__((__weak__)) float erfinvf(float) throw(); 


extern "C"  __attribute__((__weak__)) double erfc(double) throw(); 

extern "C"  __attribute__((__weak__)) float erfcf(float) throw(); 


extern "C"  __attribute__((__weak__)) double erfcinv(double) throw(); 

extern "C"  __attribute__((__weak__)) float erfcinvf(float) throw(); 


extern "C"  __attribute__((__weak__)) double lgamma(double) throw(); 

extern "C"  __attribute__((__weak__)) float lgammaf(float) throw(); 


extern "C"  __attribute__((__weak__)) double tgamma(double) throw(); 

extern "C"  __attribute__((__weak__)) float tgammaf(float) throw(); 


extern "C"  __attribute__((__weak__)) double copysign(double, double) throw() __attribute__((__const__)); 

extern "C"  __attribute__((__weak__)) float copysignf(float, float) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) double nextafter(double, double) throw() __attribute__((__const__)); 

extern "C"  __attribute__((__weak__)) float nextafterf(float, float) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) double nan(const char *) throw() __attribute__((__const__)); 

extern "C"  __attribute__((__weak__)) float nanf(const char *) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) int __isinf(double) throw() __attribute__((__const__)); 

extern "C"  __attribute__((__weak__)) int __isinff(float) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) int __isnan(double) throw() __attribute__((__const__)); 

extern "C"  __attribute__((__weak__)) int __isnanf(float) throw() __attribute__((__const__)); 
# 408 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C"  __attribute__((__weak__)) int __finite(double) throw() __attribute__((__const__)); 

extern "C"  __attribute__((__weak__)) int __finitef(float) throw() __attribute__((__const__)); 

extern "C" { extern inline  __attribute__((__weak__)) int __signbit(double) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); } 




extern "C" { extern inline  __attribute__((__weak__)) int __signbitf(float) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); } 


extern "C"  __attribute__((__weak__)) double fma(double, double, double) throw(); 

extern "C"  __attribute__((__weak__)) float fmaf(float, float, float) throw(); 
# 38 "/usr/include/bits/mathdef.h" 3
extern "C" { typedef long double float_t; }

extern "C" { typedef long double double_t; }
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C"  __attribute__((__weak__)) double acos(double) throw(); extern "C" double __acos(double) throw(); 

extern "C"  __attribute__((__weak__)) double asin(double) throw(); extern "C" double __asin(double) throw(); 

extern "C"  __attribute__((__weak__)) double atan(double) throw(); extern "C" double __atan(double) throw(); 

extern "C"  __attribute__((__weak__)) double atan2(double, double) throw(); extern "C" double __atan2(double, double) throw(); 


extern "C"  __attribute__((__weak__)) double cos(double) throw(); extern "C" double __cos(double) throw(); 

extern "C"  __attribute__((__weak__)) double sin(double) throw(); extern "C" double __sin(double) throw(); 

extern "C"  __attribute__((__weak__)) double tan(double) throw(); extern "C" double __tan(double) throw(); 




extern "C"  __attribute__((__weak__)) double cosh(double) throw(); extern "C" double __cosh(double) throw(); 

extern "C"  __attribute__((__weak__)) double sinh(double) throw(); extern "C" double __sinh(double) throw(); 

extern "C"  __attribute__((__weak__)) double tanh(double) throw(); extern "C" double __tanh(double) throw(); 




extern "C"  __attribute__((__weak__)) void sincos(double, double *, double *) throw(); extern "C" void __sincos(double, double *, double *) throw(); 
# 89
extern "C"  __attribute__((__weak__)) double acosh(double) throw(); extern "C" double __acosh(double) throw(); 

extern "C"  __attribute__((__weak__)) double asinh(double) throw(); extern "C" double __asinh(double) throw(); 

extern "C"  __attribute__((__weak__)) double atanh(double) throw(); extern "C" double __atanh(double) throw(); 
# 101
extern "C"  __attribute__((__weak__)) double exp(double) throw(); extern "C" double __exp(double) throw(); 


extern "C"  __attribute__((__weak__)) double frexp(double, int *) throw(); extern "C" double __frexp(double, int *) throw(); 


extern "C"  __attribute__((__weak__)) double ldexp(double, int) throw(); extern "C" double __ldexp(double, int) throw(); 


extern "C"  __attribute__((__weak__)) double log(double) throw(); extern "C" double __log(double) throw(); 


extern "C"  __attribute__((__weak__)) double log10(double) throw(); extern "C" double __log10(double) throw(); 


extern "C"  __attribute__((__weak__)) double modf(double, double *) throw(); extern "C" double __modf(double, double *) throw(); 




extern "C"  __attribute__((__weak__)) double exp10(double) throw(); extern "C" double __exp10(double) throw(); 

extern "C" double pow10(double) throw(); extern "C" double __pow10(double) throw(); 
# 129
extern "C"  __attribute__((__weak__)) double expm1(double) throw(); extern "C" double __expm1(double) throw(); 


extern "C"  __attribute__((__weak__)) double log1p(double) throw(); extern "C" double __log1p(double) throw(); 


extern "C"  __attribute__((__weak__)) double logb(double) throw(); extern "C" double __logb(double) throw(); 
# 142
extern "C"  __attribute__((__weak__)) double exp2(double) throw(); extern "C" double __exp2(double) throw(); 


extern "C"  __attribute__((__weak__)) double log2(double) throw(); extern "C" double __log2(double) throw(); 
# 154
extern "C"  __attribute__((__weak__)) double pow(double, double) throw(); extern "C" double __pow(double, double) throw(); 


extern "C"  __attribute__((__weak__)) double sqrt(double) throw(); extern "C" double __sqrt(double) throw(); 
# 163
extern "C"  __attribute__((__weak__)) double hypot(double, double) throw(); extern "C" double __hypot(double, double) throw(); 
# 170
extern "C"  __attribute__((__weak__)) double cbrt(double) throw(); extern "C" double __cbrt(double) throw(); 
# 179
extern "C"  __attribute__((__weak__)) double ceil(double) throw() __attribute__((__const__)); extern "C" double __ceil(double) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) double fabs(double) throw() __attribute__((__const__)); extern "C" double __fabs(double) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) double floor(double) throw() __attribute__((__const__)); extern "C" double __floor(double) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) double fmod(double, double) throw(); extern "C" double __fmod(double, double) throw(); 




extern "C"  __attribute__((__weak__)) int __isinf(double) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) int __finite(double) throw() __attribute__((__const__)); 
# 202
extern "C" int isinf(double) throw() __attribute__((__const__)); 


extern "C" int finite(double) throw() __attribute__((__const__)); 


extern "C" double drem(double, double) throw(); extern "C" double __drem(double, double) throw(); 



extern "C" double significand(double) throw(); extern "C" double __significand(double) throw(); 
# 218
extern "C"  __attribute__((__weak__)) double copysign(double, double) throw() __attribute__((__const__)); extern "C" double __copysign(double, double) throw() __attribute__((__const__)); 
# 225
extern "C"  __attribute__((__weak__)) double nan(const char *) throw() __attribute__((__const__)); extern "C" double __nan(const char *) throw() __attribute__((__const__)); 
# 231
extern "C"  __attribute__((__weak__)) int __isnan(double) throw() __attribute__((__const__)); 



extern "C" int isnan(double) throw() __attribute__((__const__)); 


extern "C" double j0(double) throw(); extern "C" double __j0(double) throw(); 
extern "C" double j1(double) throw(); extern "C" double __j1(double) throw(); 
extern "C" double jn(int, double) throw(); extern "C" double __jn(int, double) throw(); 
extern "C" double y0(double) throw(); extern "C" double __y0(double) throw(); 
extern "C" double y1(double) throw(); extern "C" double __y1(double) throw(); 
extern "C" double yn(int, double) throw(); extern "C" double __yn(int, double) throw(); 
# 250
extern "C"  __attribute__((__weak__)) double erf(double) throw(); extern "C" double __erf(double) throw(); 
extern "C"  __attribute__((__weak__)) double erfc(double) throw(); extern "C" double __erfc(double) throw(); 
extern "C"  __attribute__((__weak__)) double lgamma(double) throw(); extern "C" double __lgamma(double) throw(); 
# 259
extern "C"  __attribute__((__weak__)) double tgamma(double) throw(); extern "C" double __tgamma(double) throw(); 
# 265
extern "C" double gamma(double) throw(); extern "C" double __gamma(double) throw(); 
# 272
extern "C" double lgamma_r(double, int *) throw(); extern "C" double __lgamma_r(double, int *) throw(); 
# 280
extern "C"  __attribute__((__weak__)) double rint(double) throw(); extern "C" double __rint(double) throw(); 


extern "C"  __attribute__((__weak__)) double nextafter(double, double) throw() __attribute__((__const__)); extern "C" double __nextafter(double, double) throw() __attribute__((__const__)); 

extern "C" double nexttoward(double, long double) throw() __attribute__((__const__)); extern "C" double __nexttoward(double, long double) throw() __attribute__((__const__)); 



extern "C"  __attribute__((__weak__)) double remainder(double, double) throw(); extern "C" double __remainder(double, double) throw(); 



extern "C"  __attribute__((__weak__)) double scalbn(double, int) throw(); extern "C" double __scalbn(double, int) throw(); 



extern "C"  __attribute__((__weak__)) int ilogb(double) throw(); extern "C" int __ilogb(double) throw(); 




extern "C"  __attribute__((__weak__)) double scalbln(double, long) throw(); extern "C" double __scalbln(double, long) throw(); 



extern "C"  __attribute__((__weak__)) double nearbyint(double) throw(); extern "C" double __nearbyint(double) throw(); 



extern "C"  __attribute__((__weak__)) double round(double) throw() __attribute__((__const__)); extern "C" double __round(double) throw() __attribute__((__const__)); 



extern "C"  __attribute__((__weak__)) double trunc(double) throw() __attribute__((__const__)); extern "C" double __trunc(double) throw() __attribute__((__const__)); 




extern "C"  __attribute__((__weak__)) double remquo(double, double, int *) throw(); extern "C" double __remquo(double, double, int *) throw(); 
# 326
extern "C"  __attribute__((__weak__)) long lrint(double) throw(); extern "C" long __lrint(double) throw(); 
extern "C"  __attribute__((__weak__)) long long llrint(double) throw(); extern "C" long long __llrint(double) throw(); 



extern "C"  __attribute__((__weak__)) long lround(double) throw(); extern "C" long __lround(double) throw(); 
extern "C"  __attribute__((__weak__)) long long llround(double) throw(); extern "C" long long __llround(double) throw(); 



extern "C"  __attribute__((__weak__)) double fdim(double, double) throw(); extern "C" double __fdim(double, double) throw(); 


extern "C"  __attribute__((__weak__)) double fmax(double, double) throw(); extern "C" double __fmax(double, double) throw(); 


extern "C"  __attribute__((__weak__)) double fmin(double, double) throw(); extern "C" double __fmin(double, double) throw(); 



extern "C" int __fpclassify(double) throw() __attribute__((__const__)); 



extern "C" { extern inline  __attribute__((__weak__)) int __signbit(double) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); } 




extern "C"  __attribute__((__weak__)) double fma(double, double, double) throw(); extern "C" double __fma(double, double, double) throw(); 
# 364
extern "C" double scalb(double, double) throw(); extern "C" double __scalb(double, double) throw(); 
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C"  __attribute__((__weak__)) float acosf(float) throw(); extern "C" float __acosf(float) throw(); 

extern "C"  __attribute__((__weak__)) float asinf(float) throw(); extern "C" float __asinf(float) throw(); 

extern "C"  __attribute__((__weak__)) float atanf(float) throw(); extern "C" float __atanf(float) throw(); 

extern "C"  __attribute__((__weak__)) float atan2f(float, float) throw(); extern "C" float __atan2f(float, float) throw(); 


extern "C"  __attribute__((__weak__)) float cosf(float) throw(); 

extern "C"  __attribute__((__weak__)) float sinf(float) throw(); 

extern "C"  __attribute__((__weak__)) float tanf(float) throw(); 




extern "C"  __attribute__((__weak__)) float coshf(float) throw(); extern "C" float __coshf(float) throw(); 

extern "C"  __attribute__((__weak__)) float sinhf(float) throw(); extern "C" float __sinhf(float) throw(); 

extern "C"  __attribute__((__weak__)) float tanhf(float) throw(); extern "C" float __tanhf(float) throw(); 




extern "C"  __attribute__((__weak__)) void sincosf(float, float *, float *) throw(); 
# 89
extern "C"  __attribute__((__weak__)) float acoshf(float) throw(); extern "C" float __acoshf(float) throw(); 

extern "C"  __attribute__((__weak__)) float asinhf(float) throw(); extern "C" float __asinhf(float) throw(); 

extern "C"  __attribute__((__weak__)) float atanhf(float) throw(); extern "C" float __atanhf(float) throw(); 
# 101
extern "C"  __attribute__((__weak__)) float expf(float) throw(); 


extern "C"  __attribute__((__weak__)) float frexpf(float, int *) throw(); extern "C" float __frexpf(float, int *) throw(); 


extern "C"  __attribute__((__weak__)) float ldexpf(float, int) throw(); extern "C" float __ldexpf(float, int) throw(); 


extern "C"  __attribute__((__weak__)) float logf(float) throw(); 


extern "C"  __attribute__((__weak__)) float log10f(float) throw(); 


extern "C"  __attribute__((__weak__)) float modff(float, float *) throw(); extern "C" float __modff(float, float *) throw(); 




extern "C"  __attribute__((__weak__)) float exp10f(float) throw(); 

extern "C" float pow10f(float) throw(); extern "C" float __pow10f(float) throw(); 
# 129
extern "C"  __attribute__((__weak__)) float expm1f(float) throw(); extern "C" float __expm1f(float) throw(); 


extern "C"  __attribute__((__weak__)) float log1pf(float) throw(); extern "C" float __log1pf(float) throw(); 


extern "C"  __attribute__((__weak__)) float logbf(float) throw(); extern "C" float __logbf(float) throw(); 
# 142
extern "C"  __attribute__((__weak__)) float exp2f(float) throw(); extern "C" float __exp2f(float) throw(); 


extern "C"  __attribute__((__weak__)) float log2f(float) throw(); 
# 154
extern "C"  __attribute__((__weak__)) float powf(float, float) throw(); 


extern "C"  __attribute__((__weak__)) float sqrtf(float) throw(); extern "C" float __sqrtf(float) throw(); 
# 163
extern "C"  __attribute__((__weak__)) float hypotf(float, float) throw(); extern "C" float __hypotf(float, float) throw(); 
# 170
extern "C"  __attribute__((__weak__)) float cbrtf(float) throw(); extern "C" float __cbrtf(float) throw(); 
# 179
extern "C"  __attribute__((__weak__)) float ceilf(float) throw() __attribute__((__const__)); extern "C" float __ceilf(float) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) float fabsf(float) throw() __attribute__((__const__)); extern "C" float __fabsf(float) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) float floorf(float) throw() __attribute__((__const__)); extern "C" float __floorf(float) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) float fmodf(float, float) throw(); extern "C" float __fmodf(float, float) throw(); 




extern "C"  __attribute__((__weak__)) int __isinff(float) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) int __finitef(float) throw() __attribute__((__const__)); 
# 202
extern "C" int isinff(float) throw() __attribute__((__const__)); 


extern "C" int finitef(float) throw() __attribute__((__const__)); 


extern "C" float dremf(float, float) throw(); extern "C" float __dremf(float, float) throw(); 



extern "C" float significandf(float) throw(); extern "C" float __significandf(float) throw(); 
# 218
extern "C"  __attribute__((__weak__)) float copysignf(float, float) throw() __attribute__((__const__)); extern "C" float __copysignf(float, float) throw() __attribute__((__const__)); 
# 225
extern "C"  __attribute__((__weak__)) float nanf(const char *) throw() __attribute__((__const__)); extern "C" float __nanf(const char *) throw() __attribute__((__const__)); 
# 231
extern "C"  __attribute__((__weak__)) int __isnanf(float) throw() __attribute__((__const__)); 



extern "C" int isnanf(float) throw() __attribute__((__const__)); 


extern "C" float j0f(float) throw(); extern "C" float __j0f(float) throw(); 
extern "C" float j1f(float) throw(); extern "C" float __j1f(float) throw(); 
extern "C" float jnf(int, float) throw(); extern "C" float __jnf(int, float) throw(); 
extern "C" float y0f(float) throw(); extern "C" float __y0f(float) throw(); 
extern "C" float y1f(float) throw(); extern "C" float __y1f(float) throw(); 
extern "C" float ynf(int, float) throw(); extern "C" float __ynf(int, float) throw(); 
# 250
extern "C"  __attribute__((__weak__)) float erff(float) throw(); extern "C" float __erff(float) throw(); 
extern "C"  __attribute__((__weak__)) float erfcf(float) throw(); extern "C" float __erfcf(float) throw(); 
extern "C"  __attribute__((__weak__)) float lgammaf(float) throw(); extern "C" float __lgammaf(float) throw(); 
# 259
extern "C"  __attribute__((__weak__)) float tgammaf(float) throw(); extern "C" float __tgammaf(float) throw(); 
# 265
extern "C" float gammaf(float) throw(); extern "C" float __gammaf(float) throw(); 
# 272
extern "C" float lgammaf_r(float, int *) throw(); extern "C" float __lgammaf_r(float, int *) throw(); 
# 280
extern "C"  __attribute__((__weak__)) float rintf(float) throw(); extern "C" float __rintf(float) throw(); 


extern "C"  __attribute__((__weak__)) float nextafterf(float, float) throw() __attribute__((__const__)); extern "C" float __nextafterf(float, float) throw() __attribute__((__const__)); 

extern "C" float nexttowardf(float, long double) throw() __attribute__((__const__)); extern "C" float __nexttowardf(float, long double) throw() __attribute__((__const__)); 



extern "C"  __attribute__((__weak__)) float remainderf(float, float) throw(); extern "C" float __remainderf(float, float) throw(); 



extern "C"  __attribute__((__weak__)) float scalbnf(float, int) throw(); extern "C" float __scalbnf(float, int) throw(); 



extern "C"  __attribute__((__weak__)) int ilogbf(float) throw(); extern "C" int __ilogbf(float) throw(); 




extern "C"  __attribute__((__weak__)) float scalblnf(float, long) throw(); extern "C" float __scalblnf(float, long) throw(); 



extern "C"  __attribute__((__weak__)) float nearbyintf(float) throw(); extern "C" float __nearbyintf(float) throw(); 



extern "C"  __attribute__((__weak__)) float roundf(float) throw() __attribute__((__const__)); extern "C" float __roundf(float) throw() __attribute__((__const__)); 



extern "C"  __attribute__((__weak__)) float truncf(float) throw() __attribute__((__const__)); extern "C" float __truncf(float) throw() __attribute__((__const__)); 




extern "C"  __attribute__((__weak__)) float remquof(float, float, int *) throw(); extern "C" float __remquof(float, float, int *) throw(); 
# 326
extern "C"  __attribute__((__weak__)) long lrintf(float) throw(); extern "C" long __lrintf(float) throw(); 
extern "C"  __attribute__((__weak__)) long long llrintf(float) throw(); extern "C" long long __llrintf(float) throw(); 



extern "C"  __attribute__((__weak__)) long lroundf(float) throw(); extern "C" long __lroundf(float) throw(); 
extern "C"  __attribute__((__weak__)) long long llroundf(float) throw(); extern "C" long long __llroundf(float) throw(); 



extern "C"  __attribute__((__weak__)) float fdimf(float, float) throw(); extern "C" float __fdimf(float, float) throw(); 


extern "C"  __attribute__((__weak__)) float fmaxf(float, float) throw(); extern "C" float __fmaxf(float, float) throw(); 


extern "C"  __attribute__((__weak__)) float fminf(float, float) throw(); extern "C" float __fminf(float, float) throw(); 



extern "C" int __fpclassifyf(float) throw() __attribute__((__const__)); 



extern "C" { extern inline  __attribute__((__weak__)) int __signbitf(float) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); } 




extern "C"  __attribute__((__weak__)) float fmaf(float, float, float) throw(); extern "C" float __fmaf(float, float, float) throw(); 
# 364
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
# 89
extern "C" long double acoshl(long double) throw(); extern "C" long double __acoshl(long double) throw(); 

extern "C" long double asinhl(long double) throw(); extern "C" long double __asinhl(long double) throw(); 

extern "C" long double atanhl(long double) throw(); extern "C" long double __atanhl(long double) throw(); 
# 101
extern "C" long double expl(long double) throw(); extern "C" long double __expl(long double) throw(); 


extern "C" long double frexpl(long double, int *) throw(); extern "C" long double __frexpl(long double, int *) throw(); 


extern "C" long double ldexpl(long double, int) throw(); extern "C" long double __ldexpl(long double, int) throw(); 


extern "C" long double logl(long double) throw(); extern "C" long double __logl(long double) throw(); 


extern "C" long double log10l(long double) throw(); extern "C" long double __log10l(long double) throw(); 


extern "C" long double modfl(long double, long double *) throw(); extern "C" long double __modfl(long double, long double *) throw(); 




extern "C" long double exp10l(long double) throw(); extern "C" long double __exp10l(long double) throw(); 

extern "C" long double pow10l(long double) throw(); extern "C" long double __pow10l(long double) throw(); 
# 129
extern "C" long double expm1l(long double) throw(); extern "C" long double __expm1l(long double) throw(); 


extern "C" long double log1pl(long double) throw(); extern "C" long double __log1pl(long double) throw(); 


extern "C" long double logbl(long double) throw(); extern "C" long double __logbl(long double) throw(); 
# 142
extern "C" long double exp2l(long double) throw(); extern "C" long double __exp2l(long double) throw(); 


extern "C" long double log2l(long double) throw(); extern "C" long double __log2l(long double) throw(); 
# 154
extern "C" long double powl(long double, long double) throw(); extern "C" long double __powl(long double, long double) throw(); 


extern "C" long double sqrtl(long double) throw(); extern "C" long double __sqrtl(long double) throw(); 
# 163
extern "C" long double hypotl(long double, long double) throw(); extern "C" long double __hypotl(long double, long double) throw(); 
# 170
extern "C" long double cbrtl(long double) throw(); extern "C" long double __cbrtl(long double) throw(); 
# 179
extern "C" long double ceill(long double) throw() __attribute__((__const__)); extern "C" long double __ceill(long double) throw() __attribute__((__const__)); 


extern "C" long double fabsl(long double) throw() __attribute__((__const__)); extern "C" long double __fabsl(long double) throw() __attribute__((__const__)); 


extern "C" long double floorl(long double) throw() __attribute__((__const__)); extern "C" long double __floorl(long double) throw() __attribute__((__const__)); 


extern "C" long double fmodl(long double, long double) throw(); extern "C" long double __fmodl(long double, long double) throw(); 




extern "C"  __attribute__((__weak__)) int __isinfl(long double) throw() __attribute__((__const__)); 


extern "C"  __attribute__((__weak__)) int __finitel(long double) throw() __attribute__((__const__)); 
# 202
extern "C" int isinfl(long double) throw() __attribute__((__const__)); 


extern "C" int finitel(long double) throw() __attribute__((__const__)); 


extern "C" long double dreml(long double, long double) throw(); extern "C" long double __dreml(long double, long double) throw(); 



extern "C" long double significandl(long double) throw(); extern "C" long double __significandl(long double) throw(); 
# 218
extern "C" long double copysignl(long double, long double) throw() __attribute__((__const__)); extern "C" long double __copysignl(long double, long double) throw() __attribute__((__const__)); 
# 225
extern "C" long double nanl(const char *) throw() __attribute__((__const__)); extern "C" long double __nanl(const char *) throw() __attribute__((__const__)); 
# 231
extern "C"  __attribute__((__weak__)) int __isnanl(long double) throw() __attribute__((__const__)); 



extern "C" int isnanl(long double) throw() __attribute__((__const__)); 


extern "C" long double j0l(long double) throw(); extern "C" long double __j0l(long double) throw(); 
extern "C" long double j1l(long double) throw(); extern "C" long double __j1l(long double) throw(); 
extern "C" long double jnl(int, long double) throw(); extern "C" long double __jnl(int, long double) throw(); 
extern "C" long double y0l(long double) throw(); extern "C" long double __y0l(long double) throw(); 
extern "C" long double y1l(long double) throw(); extern "C" long double __y1l(long double) throw(); 
extern "C" long double ynl(int, long double) throw(); extern "C" long double __ynl(int, long double) throw(); 
# 250
extern "C" long double erfl(long double) throw(); extern "C" long double __erfl(long double) throw(); 
extern "C" long double erfcl(long double) throw(); extern "C" long double __erfcl(long double) throw(); 
extern "C" long double lgammal(long double) throw(); extern "C" long double __lgammal(long double) throw(); 
# 259
extern "C" long double tgammal(long double) throw(); extern "C" long double __tgammal(long double) throw(); 
# 265
extern "C" long double gammal(long double) throw(); extern "C" long double __gammal(long double) throw(); 
# 272
extern "C" long double lgammal_r(long double, int *) throw(); extern "C" long double __lgammal_r(long double, int *) throw(); 
# 280
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
# 326
extern "C" long lrintl(long double) throw(); extern "C" long __lrintl(long double) throw(); 
extern "C" long long llrintl(long double) throw(); extern "C" long long __llrintl(long double) throw(); 



extern "C" long lroundl(long double) throw(); extern "C" long __lroundl(long double) throw(); 
extern "C" long long llroundl(long double) throw(); extern "C" long long __llroundl(long double) throw(); 



extern "C" long double fdiml(long double, long double) throw(); extern "C" long double __fdiml(long double, long double) throw(); 


extern "C" long double fmaxl(long double, long double) throw(); extern "C" long double __fmaxl(long double, long double) throw(); 


extern "C" long double fminl(long double, long double) throw(); extern "C" long double __fminl(long double, long double) throw(); 



extern "C" int __fpclassifyl(long double) throw() __attribute__((__const__)); 



extern "C" { extern inline  __attribute__((__weak__)) int __signbitl(long double) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); } 




extern "C" long double fmal(long double, long double, long double) throw(); extern "C" long double __fmal(long double, long double, long double) throw(); 
# 364
extern "C" long double scalbl(long double, long double) throw(); extern "C" long double __scalbl(long double, long double) throw(); 
# 157 "/usr/include/math.h" 3
extern "C" { extern int signgam; } 
# 199
enum __cuda_FP_NAN { 
FP_NAN, 

FP_INFINITE, 

FP_ZERO, 

FP_SUBNORMAL, 

FP_NORMAL

}; 
# 291 "/usr/include/math.h" 3
extern "C" { typedef 
# 285
enum { 
_IEEE_ = (-1), 
_SVID_, 
_XOPEN_, 
_POSIX_, 
_ISOC_
} _LIB_VERSION_TYPE; }




extern "C" { extern _LIB_VERSION_TYPE _LIB_VERSION; } 
# 307
extern "C" { struct __exception { 




int type; 
char *name; 
double arg1; 
double arg2; 
double retval; 
}; }


extern "C" int matherr(__exception *) throw(); 
# 36 "/usr/include/bits/mathinline.h" 3
extern "C" { inline  __attribute__((__weak__)) __attribute__((__gnu_inline__)) __attribute__((__const__)) int __signbitf(float __x) throw() 
{ 
auto union { float __f; int __i; } __u = {__f: __x}; 
return (__u.__i) < 0; 
} } 

extern "C" { inline  __attribute__((__weak__)) __attribute__((__gnu_inline__)) __attribute__((__const__)) int __signbit(double __x) throw() 
{ 
auto union { double __d; int __i[2]; } __u = {__d: __x}; 
return ((__u.__i)[1]) < 0; 
} } 

extern "C" { inline  __attribute__((__weak__)) __attribute__((__gnu_inline__)) __attribute__((__const__)) int __signbitl(long double __x) throw() 
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
# 84
} __wait_terminated; 

struct { 

unsigned __w_stopval:8; 
unsigned __w_stopsig:8; 
unsigned:16; 
# 97
} __wait_stopped; 
}; }
# 102 "/usr/include/stdlib.h" 3
extern "C" { typedef 
# 99
struct div_t { 
int quot; 
int rem; 
} div_t; }
# 110
extern "C" { typedef 
# 107
struct ldiv_t { 
long quot; 
long rem; 
} ldiv_t; }
# 122
extern "C" { typedef 
# 119
struct lldiv_t { 
long long quot; 
long long rem; 
} lldiv_t; }
# 140
extern "C" size_t __ctype_get_mb_cur_max() throw(); 




extern "C" { extern inline double atof(const char *) throw() __attribute__((__pure__)) __attribute__((__gnu_inline__)); } 


extern "C" { extern inline int atoi(const char *) throw() __attribute__((__pure__)) __attribute__((__gnu_inline__)); } 


extern "C" { extern inline long atol(const char *) throw() __attribute__((__pure__)) __attribute__((__gnu_inline__)); } 
# 158
extern "C" { extern inline long long atoll(const char *) throw() __attribute__((__pure__)) __attribute__((__gnu_inline__)); } 
# 165
extern "C" double strtod(const char *__restrict__, char **__restrict__) throw(); 
# 173
extern "C" float strtof(const char *__restrict__, char **__restrict__) throw(); 


extern "C" long double strtold(const char *__restrict__, char **__restrict__) throw(); 
# 184
extern "C" long strtol(const char *__restrict__, char **__restrict__, int) throw(); 



extern "C" unsigned long strtoul(const char *__restrict__, char **__restrict__, int) throw(); 
# 196
extern "C" long long strtoq(const char *__restrict__, char **__restrict__, int) throw(); 




extern "C" unsigned long long strtouq(const char *__restrict__, char **__restrict__, int) throw(); 
# 210
extern "C" long long strtoll(const char *__restrict__, char **__restrict__, int) throw(); 




extern "C" unsigned long long strtoull(const char *__restrict__, char **__restrict__, int) throw(); 
# 240 "/usr/include/stdlib.h" 3
extern "C" long strtol_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw(); 



extern "C" unsigned long strtoul_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw(); 
# 250
extern "C" long long strtoll_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw(); 
# 256
extern "C" unsigned long long strtoull_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw(); 




extern "C" double strtod_l(const char *__restrict__, char **__restrict__, __locale_t) throw(); 



extern "C" float strtof_l(const char *__restrict__, char **__restrict__, __locale_t) throw(); 



extern "C" long double strtold_l(const char *__restrict__, char **__restrict__, __locale_t) throw(); 
# 279
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
# 298
extern "C" { inline __attribute__((__pure__)) __attribute__((__gnu_inline__)) long long atoll(const char *__nptr) throw() 
{ 
return strtoll(__nptr, (char **)__null, 10); 
} } 
# 311
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
# 57
extern "C" { typedef __ino64_t ino64_t; }




extern "C" { typedef __dev_t dev_t; }




extern "C" { typedef __gid_t gid_t; }




extern "C" { typedef __mode_t mode_t; }




extern "C" { typedef __nlink_t nlink_t; }




extern "C" { typedef __uid_t uid_t; }
# 88
extern "C" { typedef __off_t off_t; }
# 95
extern "C" { typedef __off64_t off64_t; }
# 105 "/usr/include/sys/types.h" 3
extern "C" { typedef __id_t id_t; }




extern "C" { typedef __ssize_t ssize_t; }
# 116
extern "C" { typedef __daddr_t daddr_t; }
extern "C" { typedef __caddr_t caddr_t; }
# 123
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
# 32
extern "C" { typedef 
# 30
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
# 78
extern "C" { typedef 
# 68
struct fd_set { 



__fd_mask fds_bits[((1024) / ((8) * sizeof(__fd_mask)))]; 
# 78
} fd_set; }
# 85
extern "C" { typedef __fd_mask fd_mask; }
# 109
extern "C" int select(int, fd_set *__restrict__, fd_set *__restrict__, fd_set *__restrict__, timeval *__restrict__); 
# 121
extern "C" int pselect(int, fd_set *__restrict__, fd_set *__restrict__, fd_set *__restrict__, const timespec *__restrict__, const __sigset_t *__restrict__); 
# 31 "/usr/include/sys/sysmacros.h" 3
extern "C" { extern inline unsigned gnu_dev_major(unsigned long long) throw() __attribute__((__gnu_inline__)); } 


extern "C" { extern inline unsigned gnu_dev_minor(unsigned long long) throw() __attribute__((__gnu_inline__)); } 


extern "C" { extern inline unsigned long long gnu_dev_makedev(unsigned, unsigned) throw() __attribute__((__gnu_inline__)); } 
# 43
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
# 235
extern "C" { typedef __blkcnt_t blkcnt_t; }



extern "C" { typedef __fsblkcnt_t fsblkcnt_t; }



extern "C" { typedef __fsfilcnt_t fsfilcnt_t; }
# 262 "/usr/include/sys/types.h" 3
extern "C" { typedef __blkcnt64_t blkcnt64_t; }
extern "C" { typedef __fsblkcnt64_t fsblkcnt64_t; }
extern "C" { typedef __fsfilcnt64_t fsfilcnt64_t; }
# 50 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef unsigned long pthread_t; }
# 57
extern "C" { typedef 
# 54
union pthread_attr_t { 
char __size[36]; 
long __align; 
} pthread_attr_t; }
# 70 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef 
# 67
struct __pthread_internal_slist { 

__pthread_internal_slist *__next; 
} __pthread_slist_t; }
# 104
extern "C" { typedef 
# 77
union pthread_mutex_t { 
struct __pthread_mutex_s { 

int __lock; 
unsigned __count; 
int __owner; 
# 88
int __kind; 
# 94
unsigned __nusers; 

union { 
int __spins; 
__pthread_slist_t __list; 
}; 

} __data; 
char __size[24]; 
long __align; 
} pthread_mutex_t; }
# 110
extern "C" { typedef 
# 107
union pthread_mutexattr_t { 
char __size[4]; 
int __align; 
} pthread_mutexattr_t; }
# 130
extern "C" { typedef 
# 116
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
# 136
extern "C" { typedef 
# 133
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
# 195
extern "C" { typedef 
# 192
union pthread_rwlockattr_t { 
char __size[8]; 
long __align; 
} pthread_rwlockattr_t; }
# 201
extern "C" { typedef volatile int pthread_spinlock_t; }
# 210
extern "C" { typedef 
# 207
union pthread_barrier_t { 
char __size[20]; 
long __align; 
} pthread_barrier_t; }
# 216
extern "C" { typedef 
# 213
union pthread_barrierattr_t { 
char __size[4]; 
int __align; 
} pthread_barrierattr_t; }
# 327 "/usr/include/stdlib.h" 3
extern "C" long random() throw(); 


extern "C" void srandom(unsigned) throw(); 
# 336
extern "C" char *initstate(unsigned, char *, size_t) throw(); 




extern "C" char *setstate(char *) throw(); 
# 349
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
# 380
extern "C" int rand() throw(); 

extern "C" void srand(unsigned) throw(); 




extern "C" int rand_r(unsigned *) throw(); 
# 395
extern "C" double drand48() throw(); 
extern "C" double erand48(unsigned short [3]) throw(); 


extern "C" long lrand48() throw(); 
extern "C" long nrand48(unsigned short [3]) throw(); 



extern "C" long mrand48() throw(); 
extern "C" long jrand48(unsigned short [3]) throw(); 



extern "C" void srand48(long) throw(); 
extern "C" unsigned short *seed48(unsigned short [3]) throw(); 

extern "C" void lcong48(unsigned short [7]) throw(); 
# 418
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
# 444
extern "C" int mrand48_r(drand48_data *__restrict__, long *__restrict__) throw(); 


extern "C" int jrand48_r(unsigned short [3], drand48_data *__restrict__, long *__restrict__) throw(); 
# 453
extern "C" int srand48_r(long, drand48_data *) throw(); 


extern "C" int seed48_r(unsigned short [3], drand48_data *) throw(); 


extern "C" int lcong48_r(unsigned short [7], drand48_data *) throw(); 
# 471
extern "C" void *malloc(size_t) throw() __attribute__((__malloc__)); 

extern "C" void *calloc(size_t, size_t) throw() __attribute__((__malloc__)); 
# 485
extern "C" void *realloc(void *, size_t) throw(); 


extern "C" void free(void *) throw(); 




extern "C" void cfree(void *) throw(); 
# 33 "/usr/include/alloca.h" 3
extern "C" void *alloca(size_t) throw(); 
# 502 "/usr/include/stdlib.h" 3
extern "C" void *valloc(size_t) throw() __attribute__((__malloc__)); 




extern "C" int posix_memalign(void **, size_t, size_t) throw(); 
# 513
extern "C" void abort() throw() __attribute__((__noreturn__)); 



extern "C" int atexit(void (*)(void)) throw(); 
# 523
extern "C" int on_exit(void (*)(int, void *), void *) throw(); 
# 531
extern "C" void exit(int) throw() __attribute__((__noreturn__)); 
# 538
extern "C" void _Exit(int) throw() __attribute__((__noreturn__)); 
# 545
extern "C" char *getenv(const char *) throw(); 




extern "C" char *__secure_getenv(const char *) throw(); 
# 557
extern "C" int putenv(char *) throw(); 
# 563
extern "C" int setenv(const char *, const char *, int) throw(); 



extern "C" int unsetenv(const char *) throw(); 
# 574
extern "C" int clearenv() throw(); 
# 583
extern "C" char *mktemp(char *) throw(); 
# 594
extern "C" int mkstemp(char *); 
# 604 "/usr/include/stdlib.h" 3
extern "C" int mkstemp64(char *); 
# 614
extern "C" char *mkdtemp(char *) throw(); 
# 625
extern "C" int mkostemp(char *, int); 
# 635 "/usr/include/stdlib.h" 3
extern "C" int mkostemp64(char *, int); 
# 645
extern "C" int system(const char *); 
# 652
extern "C" char *canonicalize_file_name(const char *) throw(); 
# 662
extern "C" char *realpath(const char *__restrict__, char *__restrict__) throw(); 
# 670
extern "C" { typedef int (*__compar_fn_t)(const void *, const void *); }


extern "C" { typedef __compar_fn_t comparison_fn_t; }
# 680
extern "C" void *bsearch(const void *, const void *, size_t, size_t, __compar_fn_t); 
# 686
extern "C" void qsort(void *, size_t, size_t, __compar_fn_t); 




extern "C"  __attribute__((__weak__)) int abs(int) throw() __attribute__((__const__)); 
extern "C"  __attribute__((__weak__)) long labs(long) throw() __attribute__((__const__)); 



extern "C"  __attribute__((__weak__)) long long llabs(long long) throw() __attribute__((__const__)); 
# 705
extern "C" div_t div(int, int) throw() __attribute__((__const__)); 

extern "C" ldiv_t ldiv(long, long) throw() __attribute__((__const__)); 
# 713
extern "C" lldiv_t lldiv(long long, long long) throw() __attribute__((__const__)); 
# 727
extern "C" char *ecvt(double, int, int *__restrict__, int *__restrict__) throw(); 
# 733
extern "C" char *fcvt(double, int, int *__restrict__, int *__restrict__) throw(); 
# 739
extern "C" char *gcvt(double, int, char *) throw(); 
# 745
extern "C" char *qecvt(long double, int, int *__restrict__, int *__restrict__) throw(); 


extern "C" char *qfcvt(long double, int, int *__restrict__, int *__restrict__) throw(); 


extern "C" char *qgcvt(long double, int, char *) throw(); 
# 757
extern "C" int ecvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw(); 


extern "C" int fcvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw(); 



extern "C" int qecvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw(); 



extern "C" int qfcvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw(); 
# 779
extern "C" int mblen(const char *, size_t) throw(); 


extern "C" int mbtowc(wchar_t *__restrict__, const char *__restrict__, size_t) throw(); 



extern "C" int wctomb(char *, wchar_t) throw(); 



extern "C" size_t mbstowcs(wchar_t *__restrict__, const char *__restrict__, size_t) throw(); 


extern "C" size_t wcstombs(char *__restrict__, const wchar_t *__restrict__, size_t) throw(); 
# 804
extern "C" int rpmatch(const char *) throw(); 
# 815
extern "C" int getsubopt(char **__restrict__, char *const *__restrict__, char **__restrict__) throw(); 
# 824
extern "C" void setkey(const char *) throw(); 
# 832
extern "C" int posix_openpt(int); 
# 840
extern "C" int grantpt(int) throw(); 



extern "C" int unlockpt(int) throw(); 




extern "C" char *ptsname(int) throw(); 
# 856
extern "C" int ptsname_r(int, char *, size_t) throw(); 



extern "C" int getpt(); 
# 867
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


template<> struct __truth_type< true>  { 
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
struct __are_same< _Tp, _Tp>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 


template<class _Tp> 
struct __is_void { 

enum __cuda___value { __value}; 
typedef __false_type __type; 
}; 


template<> struct __is_void< void>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 




template<class _Tp> 
struct __is_integer { 

enum __cuda___value { __value}; 
typedef __false_type __type; 
}; 
# 147
template<> struct __is_integer< bool>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< char>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< signed char>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< unsigned char>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 



template<> struct __is_integer< wchar_t>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 



template<> struct __is_integer< short>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< unsigned short>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< int>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< unsigned>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< long>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< unsigned long>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< long long>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_integer< unsigned long long>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 




template<class _Tp> 
struct __is_floating { 

enum __cuda___value { __value}; 
typedef __false_type __type; 
}; 



template<> struct __is_floating< float>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_floating< double>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_floating< long double>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 




template<class _Tp> 
struct __is_pointer { 

enum __cuda___value { __value}; 
typedef __false_type __type; 
}; 

template<class _Tp> 
struct __is_pointer< _Tp *>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 




template<class _Tp> 
struct __is_normal_iterator { 

enum __cuda___value { __value}; 
typedef __false_type __type; 
}; 

template<class _Iterator, class _Container> 
struct __is_normal_iterator< __gnu_cxx::__normal_iterator< _Iterator, _Container> >  { 


enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 




template<class _Tp> 
struct __is_arithmetic : public __traitor< __is_integer< _Tp> , __is_floating< _Tp> >  { 

}; 




template<class _Tp> 
struct __is_fundamental : public __traitor< __is_void< _Tp> , __is_arithmetic< _Tp> >  { 

}; 




template<class _Tp> 
struct __is_scalar : public __traitor< __is_arithmetic< _Tp> , __is_pointer< _Tp> >  { 

}; 




template<class _Tp> 
struct __is_char { 

enum __cuda___value { __value}; 
typedef __false_type __type; 
}; 


template<> struct __is_char< char>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 



template<> struct __is_char< wchar_t>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 


template<class _Tp> 
struct __is_byte { 

enum __cuda___value { __value}; 
typedef __false_type __type; 
}; 


template<> struct __is_byte< char>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_byte< signed char>  { 

enum __cuda___value { __value = 1}; 
typedef __true_type __type; 
}; 


template<> struct __is_byte< unsigned char>  { 

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
struct __enable_if< true, _Tp>  { 
typedef _Tp __type; }; 



template<bool _Cond, class _Iftrue, class _Iffalse> 
struct __conditional_type { 
typedef _Iftrue __type; }; 

template<class _Iftrue, class _Iffalse> 
struct __conditional_type< false, _Iftrue, _Iffalse>  { 
typedef _Iffalse __type; }; 



template<class _Tp> 
struct __add_unsigned { 


private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp>  __if_type; 


public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type; 
}; 


template<> struct __add_unsigned< char>  { 
typedef unsigned char __type; }; 


template<> struct __add_unsigned< signed char>  { 
typedef unsigned char __type; }; 


template<> struct __add_unsigned< short>  { 
typedef unsigned short __type; }; 


template<> struct __add_unsigned< int>  { 
typedef unsigned __type; }; 


template<> struct __add_unsigned< long>  { 
typedef unsigned long __type; }; 


template<> struct __add_unsigned< long long>  { 
typedef unsigned long long __type; }; 



template<> struct __add_unsigned< bool> ; 


template<> struct __add_unsigned< wchar_t> ; 



template<class _Tp> 
struct __remove_unsigned { 


private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp>  __if_type; 


public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type; 
}; 


template<> struct __remove_unsigned< char>  { 
typedef signed char __type; }; 


template<> struct __remove_unsigned< unsigned char>  { 
typedef signed char __type; }; 


template<> struct __remove_unsigned< unsigned short>  { 
typedef short __type; }; 


template<> struct __remove_unsigned< unsigned>  { 
typedef int __type; }; 


template<> struct __remove_unsigned< unsigned long>  { 
typedef long __type; }; 


template<> struct __remove_unsigned< unsigned long long>  { 
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
struct __promote< _Tp, false>  { 
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
# 483
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
# 171
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
extern "C" { extern inline  __attribute__((__weak__)) int __signbitl(long double) throw() __attribute__((__gnu_inline__)) __attribute__((__const__)); } 

extern "C"  __attribute__((__weak__)) int __isinfl(long double) throw() __attribute__((__const__)); 

extern "C"  __attribute__((__weak__)) int __isnanl(long double) throw() __attribute__((__const__)); 
# 456 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C"  __attribute__((__weak__)) int __finitel(long double) throw() __attribute__((__const__)); 
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
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
# 53 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
#if 0
extern "C" { extern const uint3 
# 53
threadIdx; } 
#endif
# 55 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
#if 0
extern "C" { extern const uint3 
# 55
blockIdx; } 
#endif
# 57 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
#if 0
extern "C" { extern const dim3 
# 57
blockDim; } 
#endif
# 59 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
#if 0
extern "C" { extern const dim3 
# 59
gridDim; } 
#endif
# 61 "/usr/local/cuda/bin/../include/device_launch_parameters.h"
#if 0
extern "C" { extern const int 
# 61
warpSize; } 
#endif
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
# 172
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
# 226
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
# 304
template<class T> inline cudaError_t 
cudaGetSymbolAddress(void **
devPtr, const T &
symbol) 

{ 
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol)); 
} 
# 319
static inline cudaError_t cudaGetSymbolSize(size_t *
size, char *
symbol) 

{ 
return cudaGetSymbolSize(size, (const char *)symbol); 
} 
# 348
template<class T> inline cudaError_t 
cudaGetSymbolSize(size_t *
size, const T &
symbol) 

{ 
return cudaGetSymbolSize(size, (const char *)(&symbol)); 
} 
# 404
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t 
cudaBindTexture(size_t *
offset, const texture< T, dim, readMode>  &
tex, const void *
devPtr, const cudaChannelFormatDesc &
desc, size_t 
size = (((2147483647) * 2U) + 1U)) 

{ 
return cudaBindTexture(offset, &tex, devPtr, (&desc), size); 
} 
# 448
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t 
cudaBindTexture(size_t *
offset, const texture< T, dim, readMode>  &
tex, const void *
devPtr, size_t 
size = (((2147483647) * 2U) + 1U)) 

{ 
return cudaBindTexture(offset, tex, devPtr, (tex.channelDesc), size); 
} 
# 503
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t 
cudaBindTexture2D(size_t *
offset, const texture< T, dim, readMode>  &
tex, const void *
devPtr, const cudaChannelFormatDesc &
desc, size_t 
width, size_t 
height, size_t 
pitch) 

{ 
return cudaBindTexture2D(offset, &tex, devPtr, (&desc), width, height, pitch); 
} 
# 545
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t 
cudaBindTextureToArray(const texture< T, dim, readMode>  &
tex, const cudaArray *
array, const cudaChannelFormatDesc &
desc) 

{ 
return cudaBindTextureToArray(&tex, array, (&desc)); 
} 
# 582
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t 
cudaBindTextureToArray(const texture< T, dim, readMode>  &
tex, const cudaArray *
array) 

{ 
auto cudaChannelFormatDesc desc; 
auto cudaError_t err = cudaGetChannelDesc(&desc, array); 

return (err == (cudaSuccess)) ? (cudaBindTextureToArray(tex, array, desc)) : err; 
} 
# 620
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t 
cudaUnbindTexture(const texture< T, dim, readMode>  &
tex) 

{ 
return cudaUnbindTexture(&tex); 
} 
# 659
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t 
cudaGetTextureAlignmentOffset(size_t *
offset, const texture< T, dim, readMode>  &
tex) 

{ 
return cudaGetTextureAlignmentOffset(offset, &tex); 
} 
# 708
template<class T> inline cudaError_t 
cudaLaunch(T *
entry) 

{ 
return cudaLaunch((const char *)entry); 
} 
# 744
template<class T> inline cudaError_t 
cudaFuncGetAttributes(cudaFuncAttributes *
attr, T *
entry) 

{ 
return cudaFuncGetAttributes(attr, (const char *)entry); 
} 
# 45 "/usr/include/stdio.h" 3
struct _IO_FILE; 



extern "C" { typedef _IO_FILE FILE; }
# 65 "/usr/include/stdio.h" 3
extern "C" { typedef _IO_FILE __FILE; }
# 90 "/usr/include/wchar.h" 3
extern "C" { typedef 
# 79
struct __mbstate_t { 
int __count; 

union { 

unsigned __wch; 



char __wchb[4]; 
} __value; 
} __mbstate_t; }
# 26 "/usr/include/_G_config.h" 3
extern "C" { typedef 
# 23
struct _G_fpos_t { 
__off_t __pos; 
__mbstate_t __state; 
} _G_fpos_t; }




extern "C" { typedef 
# 28
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
# 180
extern "C" { typedef void _IO_lock_t; }
# 186
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
# 344
struct _IO_FILE_plus; 

extern "C" { extern _IO_FILE_plus _IO_2_1_stdin_; } 
extern "C" { extern _IO_FILE_plus _IO_2_1_stdout_; } 
extern "C" { extern _IO_FILE_plus _IO_2_1_stderr_; } 
# 364 "/usr/include/libio.h" 3
extern "C" { typedef __ssize_t __io_read_fn(void *, char *, size_t); }
# 372
extern "C" { typedef __ssize_t __io_write_fn(void *, const char *, size_t); }
# 381
extern "C" { typedef int __io_seek_fn(void *, __off64_t *, int); }


extern "C" { typedef int __io_close_fn(void *); }




extern "C" { typedef __io_read_fn cookie_read_function_t; }
extern "C" { typedef __io_write_fn cookie_write_function_t; }
extern "C" { typedef __io_seek_fn cookie_seek_function_t; }
extern "C" { typedef __io_close_fn cookie_close_function_t; }
# 401
extern "C" { typedef 
# 396
struct _IO_cookie_io_functions_t { 
__io_read_fn *read; 
__io_write_fn *write; 
__io_seek_fn *seek; 
__io_close_fn *close; 
} _IO_cookie_io_functions_t; }
extern "C" { typedef _IO_cookie_io_functions_t cookie_io_functions_t; }

struct _IO_cookie_file; 


extern "C" void _IO_cookie_init(_IO_cookie_file *, int, void *, _IO_cookie_io_functions_t); 
# 416
extern "C" int __underflow(_IO_FILE *); 
extern "C" int __uflow(_IO_FILE *); 
extern "C" int __overflow(_IO_FILE *, int); 
# 458 "/usr/include/libio.h" 3
extern "C" int _IO_getc(_IO_FILE *); 
extern "C" int _IO_putc(int, _IO_FILE *); 
extern "C" int _IO_feof(_IO_FILE *) throw(); 
extern "C" int _IO_ferror(_IO_FILE *) throw(); 

extern "C" int _IO_peekc_locked(_IO_FILE *); 
# 469
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
# 91
extern "C" { typedef _G_fpos_t fpos_t; }
# 97
extern "C" { typedef _G_fpos64_t fpos64_t; }
# 145 "/usr/include/stdio.h" 3
extern "C" { extern _IO_FILE *stdin; } 
extern "C" { extern _IO_FILE *stdout; } 
extern "C" { extern _IO_FILE *stderr; } 
# 155
extern "C" int remove(const char *) throw(); 

extern "C" int rename(const char *, const char *) throw(); 




extern "C" int renameat(int, const char *, int, const char *) throw(); 
# 172
extern "C" FILE *tmpfile(); 
# 182 "/usr/include/stdio.h" 3
extern "C" FILE *tmpfile64(); 



extern "C" char *tmpnam(char *) throw(); 
# 192
extern "C" char *tmpnam_r(char *) throw(); 
# 204
extern "C" char *tempnam(const char *, const char *) throw() __attribute__((__malloc__)); 
# 214
extern "C" int fclose(FILE *); 




extern "C" int fflush(FILE *); 
# 229
extern "C" int fflush_unlocked(FILE *); 
# 239
extern "C" int fcloseall(); 
# 249
extern "C" FILE *fopen(const char *__restrict__, const char *__restrict__); 
# 255
extern "C" FILE *freopen(const char *__restrict__, const char *__restrict__, FILE *__restrict__); 
# 274 "/usr/include/stdio.h" 3
extern "C" FILE *fopen64(const char *__restrict__, const char *__restrict__); 

extern "C" FILE *freopen64(const char *__restrict__, const char *__restrict__, FILE *__restrict__); 
# 283
extern "C" FILE *fdopen(int, const char *) throw(); 
# 289
extern "C" FILE *fopencookie(void *__restrict__, const char *__restrict__, _IO_cookie_io_functions_t) throw(); 




extern "C" FILE *fmemopen(void *, size_t, const char *) throw(); 
# 300
extern "C" FILE *open_memstream(char **, size_t *) throw(); 
# 307
extern "C" void setbuf(FILE *__restrict__, char *__restrict__) throw(); 



extern "C" int setvbuf(FILE *__restrict__, char *__restrict__, int, size_t) throw(); 
# 318
extern "C" void setbuffer(FILE *__restrict__, char *__restrict__, size_t) throw(); 



extern "C" void setlinebuf(FILE *) throw(); 
# 331
extern "C" int fprintf(FILE *__restrict__, const char *__restrict__, ...); 
# 337
extern "C" int printf(const char *__restrict__, ...); 

extern "C" int sprintf(char *__restrict__, const char *__restrict__, ...) throw(); 
# 346
extern "C" int vfprintf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list); 
# 352
extern "C" { extern inline int vprintf(const char *__restrict__, __gnuc_va_list) __attribute__((__gnu_inline__)); } 

extern "C" int vsprintf(char *__restrict__, const char *__restrict__, __gnuc_va_list) throw(); 
# 361
extern "C" int snprintf(char *__restrict__, size_t, const char *__restrict__, ...) throw(); 



extern "C" int vsnprintf(char *__restrict__, size_t, const char *__restrict__, __gnuc_va_list) throw(); 
# 374
extern "C" int vasprintf(char **__restrict__, const char *__restrict__, __gnuc_va_list) throw(); 


extern "C" int __asprintf(char **__restrict__, const char *__restrict__, ...) throw(); 


extern "C" int asprintf(char **__restrict__, const char *__restrict__, ...) throw(); 
# 390
extern "C" int vdprintf(int, const char *__restrict__, __gnuc_va_list); 


extern "C" int dprintf(int, const char *__restrict__, ...); 
# 403
extern "C" int fscanf(FILE *__restrict__, const char *__restrict__, ...); 
# 409
extern "C" int scanf(const char *__restrict__, ...); 

extern "C" int sscanf(const char *__restrict__, const char *__restrict__, ...) throw(); 
# 449 "/usr/include/stdio.h" 3
extern "C" int vfscanf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list); 
# 457
extern "C" int vscanf(const char *__restrict__, __gnuc_va_list); 



extern "C" int vsscanf(const char *__restrict__, const char *__restrict__, __gnuc_va_list) throw(); 
# 509 "/usr/include/stdio.h" 3
extern "C" int fgetc(FILE *); 
extern "C" int getc(FILE *); 
# 516
extern "C" { extern inline int getchar() __attribute__((__gnu_inline__)); } 
# 528
extern "C" { extern inline int getc_unlocked(FILE *) __attribute__((__gnu_inline__)); } 
extern "C" { extern inline int getchar_unlocked() __attribute__((__gnu_inline__)); } 
# 539
extern "C" { extern inline int fgetc_unlocked(FILE *) __attribute__((__gnu_inline__)); } 
# 551
extern "C" int fputc(int, FILE *); 
extern "C" int putc(int, FILE *); 
# 558
extern "C" { extern inline int putchar(int) __attribute__((__gnu_inline__)); } 
# 572
extern "C" { extern inline int fputc_unlocked(int, FILE *) __attribute__((__gnu_inline__)); } 
# 580
extern "C" { extern inline int putc_unlocked(int, FILE *) __attribute__((__gnu_inline__)); } 
extern "C" { extern inline int putchar_unlocked(int) __attribute__((__gnu_inline__)); } 
# 588
extern "C" int getw(FILE *); 


extern "C" int putw(int, FILE *); 
# 600
extern "C" char *fgets(char *__restrict__, int, FILE *__restrict__); 
# 608
extern "C" char *gets(char *); 
# 618
extern "C" char *fgets_unlocked(char *__restrict__, int, FILE *__restrict__); 
# 634
extern "C" __ssize_t __getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__); 


extern "C" __ssize_t getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__); 
# 647
extern "C" { extern inline __ssize_t getline(char **__restrict__, size_t *__restrict__, FILE *__restrict__) __attribute__((__gnu_inline__)); } 
# 658
extern "C" int fputs(const char *__restrict__, FILE *__restrict__); 
# 664
extern "C" int puts(const char *); 
# 671
extern "C" int ungetc(int, FILE *); 
# 678
extern "C" size_t fread(void *__restrict__, size_t, size_t, FILE *__restrict__); 
# 684
extern "C" size_t fwrite(const void *__restrict__, size_t, size_t, FILE *__restrict__); 
# 695
extern "C" int fputs_unlocked(const char *__restrict__, FILE *__restrict__); 
# 706
extern "C" size_t fread_unlocked(void *__restrict__, size_t, size_t, FILE *__restrict__); 

extern "C" size_t fwrite_unlocked(const void *__restrict__, size_t, size_t, FILE *__restrict__); 
# 718
extern "C" int fseek(FILE *, long, int); 




extern "C" long ftell(FILE *); 




extern "C" void rewind(FILE *); 
# 742
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
# 815
extern "C" void perror(const char *); 
# 27 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern int sys_nerr; } 
extern "C" { extern const char *const sys_errlist[]; } 


extern "C" { extern int _sys_nerr; } 
extern "C" { extern const char *const _sys_errlist[]; } 
# 827 "/usr/include/stdio.h" 3
extern "C" int fileno(FILE *) throw(); 




extern "C" int fileno_unlocked(FILE *) throw(); 
# 842
extern "C" FILE *popen(const char *, const char *); 
# 848
extern "C" int pclose(FILE *); 
# 854
extern "C" char *ctermid(char *) throw(); 
# 860
extern "C" char *cuserid(char *); 




struct obstack; 


extern "C" int obstack_printf(obstack *__restrict__, const char *__restrict__, ...) throw(); 


extern "C" int obstack_vprintf(obstack *__restrict__, const char *__restrict__, __gnuc_va_list) throw(); 
# 882
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
# 54
extern "C" { inline __attribute__((__gnu_inline__)) int fgetc_unlocked(FILE *__fp) 
{ 
return (__builtin_expect((__fp->_IO_read_ptr) >= (__fp->_IO_read_end), 0)) ? __uflow(__fp) : (*((unsigned char *)((__fp->_IO_read_ptr)++))); 
} } 
# 64
extern "C" { inline __attribute__((__gnu_inline__)) int getc_unlocked(FILE *__fp) 
{ 
return (__builtin_expect((__fp->_IO_read_ptr) >= (__fp->_IO_read_end), 0)) ? __uflow(__fp) : (*((unsigned char *)((__fp->_IO_read_ptr)++))); 
} } 



extern "C" { inline __attribute__((__gnu_inline__)) int getchar_unlocked() 
{ 
return (__builtin_expect((stdin->_IO_read_ptr) >= (stdin->_IO_read_end), 0)) ? __uflow(stdin) : (*((unsigned char *)((stdin->_IO_read_ptr)++))); 
} } 
# 80
extern "C" { inline __attribute__((__gnu_inline__)) int putchar(int __c) 
{ 
return _IO_putc(__c, stdout); 
} } 
# 89
extern "C" { inline __attribute__((__gnu_inline__)) int fputc_unlocked(int __c, FILE *__stream) 
{ 
return (__builtin_expect((__stream->_IO_write_ptr) >= (__stream->_IO_write_end), 0)) ? __overflow(__stream, (unsigned char)__c) : ((unsigned char)((*((__stream->_IO_write_ptr)++)) = __c)); 
} } 
# 99
extern "C" { inline __attribute__((__gnu_inline__)) int putc_unlocked(int __c, FILE *__stream) 
{ 
return (__builtin_expect((__stream->_IO_write_ptr) >= (__stream->_IO_write_end), 0)) ? __overflow(__stream, (unsigned char)__c) : ((unsigned char)((*((__stream->_IO_write_ptr)++)) = __c)); 
} } 



extern "C" { inline __attribute__((__gnu_inline__)) int putchar_unlocked(int __c) 
{ 
return (__builtin_expect((stdout->_IO_write_ptr) >= (stdout->_IO_write_end), 0)) ? __overflow(stdout, (unsigned char)__c) : ((unsigned char)((*((stdout->_IO_write_ptr)++)) = __c)); 
} } 
# 116
extern "C" { inline __attribute__((__gnu_inline__)) __ssize_t getline(char **__lineptr, size_t *__n, FILE *__stream) 
{ 
return __getdelim(__lineptr, __n, '\n', __stream); 
} } 
# 126
extern "C" { inline __attribute__((__gnu_inline__)) int feof_unlocked(FILE *__stream) throw() 
{ 
return ((__stream->_flags) & 16) != 0; 
} } 



extern "C" { inline __attribute__((__gnu_inline__)) int ferror_unlocked(FILE *__stream) throw() 
{ 
return ((__stream->_flags) & 32) != 0; 
} } 
# 57 "/usr/include/sys/time.h" 3
extern "C" { struct timezone { 

int tz_minuteswest; 
int tz_dsttime; 
}; }

extern "C" { typedef struct timezone *__restrict__ __timezone_ptr_t; }
# 73
extern "C" int gettimeofday(timeval *__restrict__, __timezone_ptr_t) throw(); 
# 79
extern "C" int settimeofday(const timeval *, const struct timezone *) throw(); 
# 87
extern "C" int adjtime(const timeval *, timeval *) throw(); 
# 93
enum __itimer_which { 


ITIMER_REAL, 


ITIMER_VIRTUAL, 



ITIMER_PROF

}; 



extern "C" { struct itimerval { 


timeval it_interval; 

timeval it_value; 
}; }
# 122
extern "C" { typedef int __itimer_which_t; }




extern "C" int getitimer(__itimer_which_t, itimerval *) throw(); 
# 133
extern "C" int setitimer(__itimer_which_t, const itimerval *__restrict__, itimerval *__restrict__) throw(); 
# 140
extern "C" int utimes(const char *, const timeval [2]) throw(); 




extern "C" int lutimes(const char *, const timeval [2]) throw(); 



extern "C" int futimes(int, const timeval [2]) throw(); 
# 156
extern "C" int futimesat(int, const char *, const timeval [2]) throw(); 
# 238 "/usr/include/unistd.h" 3
extern "C" { typedef __intptr_t intptr_t; }
# 245
extern "C" { typedef __socklen_t socklen_t; }
# 258
extern "C" int access(const char *, int) throw(); 




extern "C" int euidaccess(const char *, int) throw(); 



extern "C" int eaccess(const char *, int) throw(); 
# 275
extern "C" int faccessat(int, const char *, int, int) throw(); 
# 301
extern "C" __off_t lseek(int, __off_t, int) throw(); 
# 312 "/usr/include/unistd.h" 3
extern "C" __off64_t lseek64(int, __off64_t, int) throw(); 
# 320
extern "C" int close(int); 
# 327
extern "C" ssize_t read(int, void *, size_t); 
# 333
extern "C" ssize_t write(int, const void *, size_t); 
# 343
extern "C" ssize_t pread(int, void *, size_t, __off_t); 
# 351
extern "C" ssize_t pwrite(int, const void *, size_t, __off_t); 
# 371 "/usr/include/unistd.h" 3
extern "C" ssize_t pread64(int, void *, size_t, __off64_t); 



extern "C" ssize_t pwrite64(int, const void *, size_t, __off64_t); 
# 384
extern "C" int pipe(int [2]) throw(); 
# 393
extern "C" unsigned alarm(unsigned) throw(); 
# 405
extern "C" unsigned sleep(unsigned); 
# 412
extern "C" __useconds_t ualarm(__useconds_t, __useconds_t) throw(); 
# 420
extern "C" int usleep(__useconds_t); 
# 429
extern "C" int pause(); 



extern "C" int chown(const char *, __uid_t, __gid_t) throw(); 




extern "C" int fchown(int, __uid_t, __gid_t) throw(); 




extern "C" int lchown(const char *, __uid_t, __gid_t) throw(); 
# 451
extern "C" int fchownat(int, const char *, __uid_t, __gid_t, int) throw(); 
# 457
extern "C" int chdir(const char *) throw(); 



extern "C" int fchdir(int) throw(); 
# 471
extern "C" char *getcwd(char *, size_t) throw(); 
# 477
extern "C" char *get_current_dir_name() throw(); 
# 484
extern "C" char *getwd(char *) throw() __attribute__((__deprecated__)); 
# 490
extern "C" int dup(int) throw(); 


extern "C" int dup2(int, int) throw(); 


extern "C" { extern char **__environ; } 

extern "C" { extern char **environ; } 
# 504
extern "C" int execve(const char *, char *const [], char *const []) throw(); 
# 510
extern "C" int fexecve(int, char *const [], char *const []) throw(); 
# 516
extern "C" int execv(const char *, char *const []) throw(); 




extern "C" int execle(const char *, const char *, ...) throw(); 




extern "C" int execl(const char *, const char *, ...) throw(); 




extern "C" int execvp(const char *, char *const []) throw(); 
# 537
extern "C" int execlp(const char *, const char *, ...) throw(); 
# 543
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
# 600
extern "C" int setpgid(__pid_t, __pid_t) throw(); 
# 617
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
# 667
extern "C" int setuid(__uid_t) throw(); 




extern "C" int setreuid(__uid_t, __uid_t) throw(); 




extern "C" int seteuid(__uid_t) throw(); 
# 684
extern "C" int setgid(__gid_t) throw(); 




extern "C" int setregid(__gid_t, __gid_t) throw(); 




extern "C" int setegid(__gid_t) throw(); 
# 700
extern "C" int getresuid(__uid_t *, __uid_t *, __uid_t *) throw(); 




extern "C" int getresgid(__gid_t *, __gid_t *, __gid_t *) throw(); 




extern "C" int setresuid(__uid_t, __uid_t, __uid_t) throw(); 




extern "C" int setresgid(__gid_t, __gid_t, __gid_t) throw(); 
# 723
extern "C" __pid_t fork() throw(); 
# 730
extern "C" __pid_t vfork() throw(); 
# 736
extern "C" char *ttyname(int) throw(); 



extern "C" int ttyname_r(int, char *, size_t) throw(); 




extern "C" int isatty(int) throw(); 
# 751
extern "C" int ttyslot() throw(); 




extern "C" int link(const char *, const char *) throw(); 
# 762
extern "C" int linkat(int, const char *, int, const char *, int) throw(); 
# 769
extern "C" int symlink(const char *, const char *) throw(); 
# 775
extern "C" ssize_t readlink(const char *__restrict__, char *__restrict__, size_t) throw(); 
# 782
extern "C" int symlinkat(const char *, int, const char *) throw(); 



extern "C" ssize_t readlinkat(int, const char *__restrict__, char *__restrict__, size_t) throw(); 
# 792
extern "C" int unlink(const char *) throw(); 



extern "C" int unlinkat(int, const char *, int) throw(); 




extern "C" int rmdir(const char *) throw(); 



extern "C" __pid_t tcgetpgrp(int) throw(); 


extern "C" int tcsetpgrp(int, __pid_t) throw(); 
# 815
extern "C" char *getlogin(); 
# 823
extern "C" int getlogin_r(char *, size_t); 




extern "C" int setlogin(const char *) throw(); 
# 59 "/usr/include/getopt.h" 3
extern "C" { extern char *optarg; } 
# 73
extern "C" { extern int optind; } 




extern "C" { extern int opterr; } 



extern "C" { extern int optopt; } 
# 152 "/usr/include/getopt.h" 3
extern "C" int getopt(int, char *const *, const char *) throw(); 
# 845 "/usr/include/unistd.h" 3
extern "C" int gethostname(char *, size_t) throw(); 
# 852
extern "C" int sethostname(const char *, size_t) throw(); 




extern "C" int sethostid(long) throw(); 
# 863
extern "C" int getdomainname(char *, size_t) throw(); 

extern "C" int setdomainname(const char *, size_t) throw(); 
# 872
extern "C" int vhangup() throw(); 


extern "C" int revoke(const char *) throw(); 
# 883
extern "C" int profil(unsigned short *, size_t, size_t, unsigned) throw(); 
# 891
extern "C" int acct(const char *) throw(); 



extern "C" char *getusershell() throw(); 
extern "C" void endusershell() throw(); 
extern "C" void setusershell() throw(); 
# 903
extern "C" int daemon(int, int) throw(); 
# 910
extern "C" int chroot(const char *) throw(); 



extern "C" char *getpass(const char *); 
# 923
extern "C" int fsync(int); 
# 930
extern "C" long gethostid(); 


extern "C" void sync() throw(); 




extern "C" int getpagesize() throw() __attribute__((__const__)); 




extern "C" int getdtablesize() throw(); 




extern "C" int truncate(const char *, __off_t) throw(); 
# 960 "/usr/include/unistd.h" 3
extern "C" int truncate64(const char *, __off64_t) throw(); 
# 970
extern "C" int ftruncate(int, __off_t) throw(); 
# 980 "/usr/include/unistd.h" 3
extern "C" int ftruncate64(int, __off64_t) throw(); 
# 990
extern "C" int brk(void *) throw(); 
# 996
extern "C" void *sbrk(intptr_t) throw(); 
# 1011
extern "C" long syscall(long, ...) throw(); 
# 1034
extern "C" int lockf(int, int, __off_t); 
# 1044 "/usr/include/unistd.h" 3
extern "C" int lockf64(int, int, __off64_t); 
# 1065 "/usr/include/unistd.h" 3
extern "C" int fdatasync(int); 
# 1073
extern "C" char *crypt(const char *, const char *) throw(); 




extern "C" void encrypt(char *, int) throw(); 
# 1085
extern "C" void swab(const void *__restrict__, void *__restrict__, ssize_t) throw(); 
# 1094
extern "C" char *ctermid(char *) throw(); 
# 12 "/afs/crhc.illinois.edu/project/depend/yim6/clairvoyant/fi/cedp/cedp/projects/gpgpu/benchmark/parboil/common/include/parboil.h"
extern "C" { struct pb_Parameters { 
char *outFile; 


char **inpFiles; 



int synchronizeGpu; 
# 27
}; }
# 39
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
# 76
extern "C" void pb_ResetTimer(pb_Timer *); 
# 84
extern "C" void pb_StartTimer(pb_Timer *); 
# 91
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
# 124
extern "C" void pb_SwitchToTimer(pb_TimerSet *, pb_TimerID); 



extern "C" void pb_PrintTimerSet(pb_TimerSet *); 
# 9 "src/cuda_wo_loop/file.h"
extern void inputData(char *, int *, int *, float **, float **, float **, float **, float **, float **, float **, float **, float **, float **); 
# 15
extern void outputData(char *, float *, float *, int); 
# 28 "src/cuda_wo_loop/computeFH.cu"
struct kValues { 
float Kx; 
float Ky; 
float Kz; 
float RhoPhiR; 
float RhoPhiI; 
}; 

__loc_sc__(__constant__,,) kValues __shadow_var(,c)[512]; 

void createDataStructs(int numK, int numX, float *&
realRhoPhi, float *&imagRhoPhi, float *&
outR, float *&outI) 
{ 
realRhoPhi = (float *)calloc(numK, sizeof(float)); 
imagRhoPhi = (float *)calloc(numK, sizeof(float)); 
outR = (float *)calloc(numX, sizeof(float)); 
outI = (float *)calloc(numX, sizeof(float)); 
} 


void ComputeRhoPhiGPU__entry(int numK, float *
phiR, float *phiI, float *
dR, float *dI, float *
realRhoPhi, float *imagRhoPhi);
#if 0
 
# 53
{ 
auto int indexK = (blockIdx.x * (512) + threadIdx.x); 
if (indexK < numK) { 
auto float rPhiR = (phiR[indexK]); 
auto float rPhiI = (phiI[indexK]); 
auto float rDR = (dR[indexK]); 
auto float rDI = (dI[indexK]); 
(realRhoPhi[indexK]) = rPhiR * rDR + rPhiI * rDI; 
(imagRhoPhi[indexK]) = rPhiR * rDI - rPhiI * rDR; 
}  
} 
#endif
# 66 "src/cuda_wo_loop/computeFH.cu"
void ComputeFH_GPU__entry(int numK, int kGlobalIndex, float *
x, float *y, float *z, float *
outR, float *outI);
#if 0
 
# 69
{ 
auto float sX; 
auto float sY; 
auto float sZ; 
auto float sOutR; 
auto float sOutI; 


auto int xIndex = (blockIdx.x * (256) + threadIdx.x); 

sX = x[xIndex]; 
sY = y[xIndex]; 
sZ = z[xIndex]; 
sOutR = outR[xIndex]; 
sOutI = outI[xIndex]; 



auto int kIndex = 0; 
auto int kCnt = (numK - kGlobalIndex); 
if (kCnt < 512) { 
# 102 "src/cuda_wo_loop/computeFH.cu"
}  
# 141 "src/cuda_wo_loop/computeFH.cu"
(outR[xIndex]) = sOutR; 
(outI[xIndex]) = sOutI; 
} 
#endif
# 145 "src/cuda_wo_loop/computeFH.cu"
void computeRhoPhi_GPU(int numK, float *
phiR_d, float *phiI_d, float *dR_d, float *dI_d, float *
realRhoPhi_d, float *imagRhoPhi_d) 
{ 
auto int rhoPhiBlocks = (numK / 512); 

if (numK % 512) { 
rhoPhiBlocks++; }  

auto dim3 DimRhoPhiBlock(512, 1); 
auto dim3 DimRhoPhiGrid(rhoPhiBlocks, 1); 



cudaConfigureCall(DimRhoPhiGrid, DimRhoPhiBlock) ? ((void)0) : ComputeRhoPhiGPU__entry(numK, phiR_d, phiI_d, dR_d, dI_d, realRhoPhi_d, imagRhoPhi_d); 

} 

void computeFH_GPU(int numK, int numX, float *
x_d, float *y_d, float *z_d, kValues *
kVals, float *
outR_d, float *outI_d) 
{ 
auto int FHGrids = (numK / 512); 
if (numK % 512) { 
FHGrids++; }  
auto int FHBlocks = (numX / 256); 
if (numX % 256) { 
FHBlocks++; }  
auto dim3 DimFHBlock(256, 1); 
auto dim3 DimFHGrid(FHBlocks, 1); 




for (int FHGrid = 0; FHGrid < FHGrids; FHGrid++) { 

auto int FHGridBase = (FHGrid * 512); 

auto kValues *kValsTile = (kVals + FHGridBase); 
auto int numElems = ((512 < (numK - FHGridBase)) ? 512 : (numK - FHGridBase)); 
cudaMemcpyToSymbol(__shadow_var(,c), kValsTile, numElems * sizeof(kValues), 0); 
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 187, cudaGetErrorString(err)); exit(-1); }  } ; 

cudaConfigureCall(DimFHGrid, DimFHBlock) ? ((void)0) : ComputeFH_GPU__entry(numK, FHGridBase, x_d, y_d, z_d, outR_d, outI_d); 

{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 191, cudaGetErrorString(err)); exit(-1); }  } ; 
}  
} 
# 38 "src/cuda_wo_loop/main.cu"
static void setupMemoryGPU(int num, int size, float *&dev_ptr, float *&host_ptr) 
{ 
cudaMalloc((void **)(&dev_ptr), num * size); 
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 41, cudaGetErrorString(err)); exit(-1); }  } ; 
cudaMemcpy(dev_ptr, host_ptr, num * size, cudaMemcpyHostToDevice); 
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 43, cudaGetErrorString(err)); exit(-1); }  } ; 
} 


static void cleanupMemoryGPU(int num, int size, float *&dev_ptr, float *host_ptr) 
{ 
cudaMemcpy(host_ptr, dev_ptr, num * size, cudaMemcpyDeviceToHost); 
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 50, cudaGetErrorString(err)); exit(-1); }  } ; 
cudaFree(dev_ptr); 
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 52, cudaGetErrorString(err)); exit(-1); }  } ; 
} 


int main(int argc, char *argv[]) 
{ 
auto int numX; auto int numK; 
auto int original_numK; 
auto float *kx; auto float *ky; auto float *kz; 
auto float *x; auto float *y; auto float *z; 
auto float *phiR; auto float *phiI; 
auto float *dR; auto float *dI; 
auto float *realRhoPhi; auto float *imagRhoPhi; 
auto float *outI; auto float *outR; 
auto kValues *kVals; 



auto pb_Parameters *params; 
auto pb_TimerSet timers; 

pb_InitializeTimerSet(&timers); 


params = pb_ReadParameters(&argc, argv); 
if ((((params->inpFiles)[0]) == (__null)) || (((params->inpFiles)[1]) != (__null))) 
{ 
fprintf(stderr, "Expecting one input filename\n"); 
exit(-1); 
}  


pb_SwitchToTimer(&timers, pb_TimerID_IO); 
inputData((params->inpFiles)[0], &original_numK, &numX, &kx, &ky, &kz, &x, &y, &z, &phiR, &phiI, &dR, &dI); 
# 94
if (argc < 2) { 
numK = original_numK; } else 

{ 
auto int inputK; 
auto char *end; 
inputK = strtol(argv[1], &end, 10); 
if (end == (argv[1])) 
{ 
fprintf(stderr, "Expecting an integer parameter\n"); 
exit(-1); 
}  

numK = (inputK < original_numK) ? inputK : original_numK; 
}  

printf("%d pixels in output; %d samples in trajectory; using %d samples\n", numX, original_numK, numK); 


pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE); 


createDataStructs(numK, numX, realRhoPhi, imagRhoPhi, outR, outI); 
kVals = (kValues *)calloc(numK, sizeof(kValues)); 


{ 

auto float *phiR_d; auto float *phiI_d; 
auto float *dR_d; auto float *dI_d; 
auto float *realRhoPhi_d; auto float *imagRhoPhi_d; 

pb_SwitchToTimer(&timers, pb_TimerID_COPY); 
setupMemoryGPU(numK, sizeof(float), phiR_d, phiR); 
setupMemoryGPU(numK, sizeof(float), phiI_d, phiI); 
setupMemoryGPU(numK, sizeof(float), dR_d, dR); 
setupMemoryGPU(numK, sizeof(float), dI_d, dI); 
cudaMalloc((void **)(&realRhoPhi_d), numK * sizeof(float)); 
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 132, cudaGetErrorString(err)); exit(-1); }  } ; 
cudaMalloc((void **)(&imagRhoPhi_d), numK * sizeof(float)); 
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 134, cudaGetErrorString(err)); exit(-1); }  } ; 

if (params->synchronizeGpu) { cudaThreadSynchronize(); }  
pb_SwitchToTimer(&timers, pb_TimerID_GPU); 


computeRhoPhi_GPU(numK, phiR_d, phiI_d, dR_d, dI_d, realRhoPhi_d, imagRhoPhi_d); 


if (params->synchronizeGpu) { cudaThreadSynchronize(); }  
pb_SwitchToTimer(&timers, pb_TimerID_COPY); 

cleanupMemoryGPU(numK, sizeof(float), realRhoPhi_d, realRhoPhi); 
cleanupMemoryGPU(numK, sizeof(float), imagRhoPhi_d, imagRhoPhi); 
cudaFree(phiR_d); 
cudaFree(phiI_d); 
cudaFree(dR_d); 
cudaFree(dI_d); 
} 

pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE); 


for (int k = 0; k < numK; k++) { 
((kVals[k]).Kx) = kx[k]; 
((kVals[k]).Ky) = ky[k]; 
((kVals[k]).Kz) = kz[k]; 
((kVals[k]).RhoPhiR) = realRhoPhi[k]; 
((kVals[k]).RhoPhiI) = imagRhoPhi[k]; 
}  

pb_SwitchToTimer(&timers, pb_TimerID_COPY); 


{ 
auto float *x_d; auto float *y_d; auto float *z_d; 
auto float *outI_d; auto float *outR_d; 


setupMemoryGPU(numX, sizeof(float), x_d, x); 
setupMemoryGPU(numX, sizeof(float), y_d, y); 
setupMemoryGPU(numX, sizeof(float), z_d, z); 



cudaMalloc((void **)(&outR_d), numX * sizeof(float)); 
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 180, cudaGetErrorString(err)); exit(-1); }  } ; 
cudaMemset(outR_d, 0, numX * sizeof(float)); 
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 182, cudaGetErrorString(err)); exit(-1); }  } ; 
cudaMalloc((void **)(&outI_d), numX * sizeof(float)); 
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 184, cudaGetErrorString(err)); exit(-1); }  } ; 
cudaMemset(outI_d, 0, numX * sizeof(float)); 
{ auto cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { fprintf(stderr, "CUDA error on line %d: %s\n", 186, cudaGetErrorString(err)); exit(-1); }  } ; 

if (params->synchronizeGpu) { cudaThreadSynchronize(); }  
pb_SwitchToTimer(&timers, pb_TimerID_GPU); 


computeFH_GPU(numK, numX, x_d, y_d, z_d, kVals, outR_d, outI_d); 

if (params->synchronizeGpu) { cudaThreadSynchronize(); }  
pb_SwitchToTimer(&timers, pb_TimerID_COPY); 


cleanupMemoryGPU(numX, sizeof(float), outR_d, outR); 
cleanupMemoryGPU(numX, sizeof(float), outI_d, outI); 

cudaFree(x_d); 
cudaFree(y_d); 
cudaFree(z_d); 
} 

pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE); 

if (params->outFile) 
{ 

pb_SwitchToTimer(&timers, pb_TimerID_IO); 
outputData(params->outFile, outR, outI, numX); 
pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE); 
}  

free(kx); 
free(ky); 
free(kz); 
free(x); 
free(y); 
free(z); 
free(phiR); 
free(phiI); 
free(dR); 
free(dI); 
free(realRhoPhi); 
free(imagRhoPhi); 
free(kVals); 
free(outR); 
free(outI); 

pb_SwitchToTimer(&timers, pb_TimerID_NONE); 
pb_PrintTimerSet(&timers); 
pb_FreeParameters(params); 

return 0; 
} 

#include "main.cudafe1.stub.c"
