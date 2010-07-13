# 1 "src/cuda/cuenergy_pre8_coalesce.cu"
# 46 "/usr/local/cuda/bin/../include/device_types.h"
#if 0
# 46
enum cudaRoundMode { 
# 48
cudaRoundNearest, 
# 49
cudaRoundZero, 
# 50
cudaRoundPosInf, 
# 51
cudaRoundMinInf
# 52
}; 
#endif
# 152 "/usr/lib/gcc/x86_64-linux-gnu/4.2.4/include/stddef.h" 3
typedef long ptrdiff_t; 
# 214 "/usr/lib/gcc/x86_64-linux-gnu/4.2.4/include/stddef.h" 3
typedef unsigned long size_t; 
#include "crt/host_runtime.h"
# 94 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 94
enum cudaError { 
# 96
cudaSuccess, 
# 97
cudaErrorMissingConfiguration, 
# 98
cudaErrorMemoryAllocation, 
# 99
cudaErrorInitializationError, 
# 100
cudaErrorLaunchFailure, 
# 101
cudaErrorPriorLaunchFailure, 
# 102
cudaErrorLaunchTimeout, 
# 103
cudaErrorLaunchOutOfResources, 
# 104
cudaErrorInvalidDeviceFunction, 
# 105
cudaErrorInvalidConfiguration, 
# 106
cudaErrorInvalidDevice, 
# 107
cudaErrorInvalidValue, 
# 108
cudaErrorInvalidPitchValue, 
# 109
cudaErrorInvalidSymbol, 
# 110
cudaErrorMapBufferObjectFailed, 
# 111
cudaErrorUnmapBufferObjectFailed, 
# 112
cudaErrorInvalidHostPointer, 
# 113
cudaErrorInvalidDevicePointer, 
# 114
cudaErrorInvalidTexture, 
# 115
cudaErrorInvalidTextureBinding, 
# 116
cudaErrorInvalidChannelDescriptor, 
# 117
cudaErrorInvalidMemcpyDirection, 
# 118
cudaErrorAddressOfConstant, 
# 124
cudaErrorTextureFetchFailed, 
# 125
cudaErrorTextureNotBound, 
# 126
cudaErrorSynchronizationError, 
# 127
cudaErrorInvalidFilterSetting, 
# 128
cudaErrorInvalidNormSetting, 
# 129
cudaErrorMixedDeviceExecution, 
# 130
cudaErrorCudartUnloading, 
# 131
cudaErrorUnknown, 
# 132
cudaErrorNotYetImplemented, 
# 133
cudaErrorMemoryValueTooLarge, 
# 134
cudaErrorInvalidResourceHandle, 
# 135
cudaErrorNotReady, 
# 136
cudaErrorInsufficientDriver, 
# 137
cudaErrorSetOnActiveProcess, 
# 138
cudaErrorInvalidSurface, 
# 139
cudaErrorNoDevice, 
# 140
cudaErrorECCUncorrectable, 
# 141
cudaErrorSharedObjectSymbolNotFound, 
# 142
cudaErrorSharedObjectInitFailed, 
# 143
cudaErrorUnsupportedLimit, 
# 144
cudaErrorDuplicateVariableName, 
# 145
cudaErrorDuplicateTextureName, 
# 146
cudaErrorDuplicateSurfaceName, 
# 147
cudaErrorDevicesUnavailable, 
# 148
cudaErrorStartupFailure = 127, 
# 149
cudaErrorApiFailureBase = 10000
# 150
}; 
#endif
# 156 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 156
enum cudaChannelFormatKind { 
# 158
cudaChannelFormatKindSigned, 
# 159
cudaChannelFormatKindUnsigned, 
# 160
cudaChannelFormatKindFloat, 
# 161
cudaChannelFormatKindNone
# 162
}; 
#endif
# 168 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 168
struct cudaChannelFormatDesc { 
# 170
int x; 
# 171
int y; 
# 172
int z; 
# 173
int w; 
# 174
cudaChannelFormatKind f; 
# 175
}; 
#endif
# 181 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
struct cudaArray; 
#endif
# 187 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 187
enum cudaMemcpyKind { 
# 189
cudaMemcpyHostToHost, 
# 190
cudaMemcpyHostToDevice, 
# 191
cudaMemcpyDeviceToHost, 
# 192
cudaMemcpyDeviceToDevice
# 193
}; 
#endif
# 200 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 200
struct cudaPitchedPtr { 
# 202
void *ptr; 
# 203
size_t pitch; 
# 204
size_t xsize; 
# 205
size_t ysize; 
# 206
}; 
#endif
# 213 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 213
struct cudaExtent { 
# 215
size_t width; 
# 216
size_t height; 
# 217
size_t depth; 
# 218
}; 
#endif
# 225 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 225
struct cudaPos { 
# 227
size_t x; 
# 228
size_t y; 
# 229
size_t z; 
# 230
}; 
#endif
# 236 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 236
struct cudaMemcpy3DParms { 
# 238
cudaArray *srcArray; 
# 239
cudaPos srcPos; 
# 240
cudaPitchedPtr srcPtr; 
# 242
cudaArray *dstArray; 
# 243
cudaPos dstPos; 
# 244
cudaPitchedPtr dstPtr; 
# 246
cudaExtent extent; 
# 247
cudaMemcpyKind kind; 
# 248
}; 
#endif
# 254 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
struct cudaGraphicsResource; 
#endif
# 260 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 260
enum cudaGraphicsRegisterFlags { 
# 262
cudaGraphicsRegisterFlagsNone
# 263
}; 
#endif
# 269 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 269
enum cudaGraphicsMapFlags { 
# 271
cudaGraphicsMapFlagsNone, 
# 272
cudaGraphicsMapFlagsReadOnly, 
# 273
cudaGraphicsMapFlagsWriteDiscard
# 274
}; 
#endif
# 280 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 280
enum cudaGraphicsCubeFace { 
# 281
cudaGraphicsCubeFacePositiveX, 
# 282
cudaGraphicsCubeFaceNegativeX, 
# 283
cudaGraphicsCubeFacePositiveY, 
# 284
cudaGraphicsCubeFaceNegativeY, 
# 285
cudaGraphicsCubeFacePositiveZ, 
# 286
cudaGraphicsCubeFaceNegativeZ
# 287
}; 
#endif
# 293 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 293
struct cudaFuncAttributes { 
# 295
size_t sharedSizeBytes; 
# 296
size_t constSizeBytes; 
# 297
size_t localSizeBytes; 
# 298
int maxThreadsPerBlock; 
# 299
int numRegs; 
# 305
int ptxVersion; 
# 311
int binaryVersion; 
# 312
int __cudaReserved[6]; 
# 313
}; 
#endif
# 319 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 319
enum cudaFuncCache { 
# 321
cudaFuncCachePreferNone, 
# 322
cudaFuncCachePreferShared, 
# 323
cudaFuncCachePreferL1
# 324
}; 
#endif
# 330 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 330
enum cudaComputeMode { 
# 332
cudaComputeModeDefault, 
# 333
cudaComputeModeExclusive, 
# 334
cudaComputeModeProhibited
# 335
}; 
#endif
# 341 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 341
enum cudaLimit { 
# 343
cudaLimitStackSize, 
# 344
cudaLimitPrintfFifoSize
# 345
}; 
#endif
# 351 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
# 351
struct cudaDeviceProp { 
# 353
char name[256]; 
# 354
size_t totalGlobalMem; 
# 355
size_t sharedMemPerBlock; 
# 356
int regsPerBlock; 
# 357
int warpSize; 
# 358
size_t memPitch; 
# 359
int maxThreadsPerBlock; 
# 360
int maxThreadsDim[3]; 
# 361
int maxGridSize[3]; 
# 362
int clockRate; 
# 363
size_t totalConstMem; 
# 364
int major; 
# 365
int minor; 
# 366
size_t textureAlignment; 
# 367
int deviceOverlap; 
# 368
int multiProcessorCount; 
# 369
int kernelExecTimeoutEnabled; 
# 370
int integrated; 
# 371
int canMapHostMemory; 
# 372
int computeMode; 
# 373
int maxTexture1D; 
# 374
int maxTexture2D[2]; 
# 375
int maxTexture3D[3]; 
# 376
int maxTexture2DArray[3]; 
# 377
size_t surfaceAlignment; 
# 378
int concurrentKernels; 
# 379
int ECCEnabled; 
# 380
int pciBusID; 
# 381
int pciDeviceID; 
# 382
int __cudaReserved[22]; 
# 383
}; 
#endif
# 426 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
typedef cudaError 
# 426
cudaError_t; 
#endif
# 432 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
typedef struct CUstream_st *
# 432
cudaStream_t; 
#endif
# 438 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
typedef struct CUevent_st *
# 438
cudaEvent_t; 
#endif
# 444 "/usr/local/cuda/bin/../include/driver_types.h"
#if 0
typedef struct CUuuid_st 
# 444
cudaUUID_t; 
#endif
# 54 "/usr/local/cuda/bin/../include/surface_types.h"
#if 0
# 54
enum cudaSurfaceBoundaryMode { 
# 56
cudaBoundaryModeZero, 
# 57
cudaBoundaryModeClamp, 
# 58
cudaBoundaryModeTrap
# 59
}; 
#endif
# 62 "/usr/local/cuda/bin/../include/surface_types.h"
#if 0
# 62
enum cudaSurfaceFormatMode { 
# 64
cudaFormatModeForced, 
# 65
cudaFormatModeAuto
# 66
}; 
#endif
# 69 "/usr/local/cuda/bin/../include/surface_types.h"
#if 0
# 69
struct surfaceReference { 
# 71
cudaChannelFormatDesc channelDesc; 
# 72
}; 
#endif
# 54 "/usr/local/cuda/bin/../include/texture_types.h"
#if 0
# 54
enum cudaTextureAddressMode { 
# 56
cudaAddressModeWrap, 
# 57
cudaAddressModeClamp, 
# 58
cudaAddressModeMirror
# 59
}; 
#endif
# 62 "/usr/local/cuda/bin/../include/texture_types.h"
#if 0
# 62
enum cudaTextureFilterMode { 
# 64
cudaFilterModePoint, 
# 65
cudaFilterModeLinear
# 66
}; 
#endif
# 69 "/usr/local/cuda/bin/../include/texture_types.h"
#if 0
# 69
enum cudaTextureReadMode { 
# 71
cudaReadModeElementType, 
# 72
cudaReadModeNormalizedFloat
# 73
}; 
#endif
# 76 "/usr/local/cuda/bin/../include/texture_types.h"
#if 0
# 76
struct textureReference { 
# 78
int normalized; 
# 79
cudaTextureFilterMode filterMode; 
# 80
cudaTextureAddressMode addressMode[3]; 
# 81
cudaChannelFormatDesc channelDesc; 
# 82
int __cudaReserved[16]; 
# 83
}; 
#endif
# 75 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 75
struct char1 { 
# 77
signed char x; 
# 78
}; 
#endif
# 81 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 81
struct uchar1 { 
# 83
unsigned char x; 
# 84
}; 
#endif
# 87 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 87
struct __attribute__((__aligned__(2))) char2 { 
# 89
signed char x, y; 
# 90
}; 
#endif
# 93 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 93
struct __attribute__((__aligned__(2))) uchar2 { 
# 95
unsigned char x, y; 
# 96
}; 
#endif
# 99 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 99
struct char3 { 
# 101
signed char x, y, z; 
# 102
}; 
#endif
# 105 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 105
struct uchar3 { 
# 107
unsigned char x, y, z; 
# 108
}; 
#endif
# 111 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 111
struct __attribute__((__aligned__(4))) char4 { 
# 113
signed char x, y, z, w; 
# 114
}; 
#endif
# 117 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 117
struct __attribute__((__aligned__(4))) uchar4 { 
# 119
unsigned char x, y, z, w; 
# 120
}; 
#endif
# 123 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 123
struct short1 { 
# 125
short x; 
# 126
}; 
#endif
# 129 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 129
struct ushort1 { 
# 131
unsigned short x; 
# 132
}; 
#endif
# 135 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 135
struct __attribute__((__aligned__(4))) short2 { 
# 137
short x, y; 
# 138
}; 
#endif
# 141 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 141
struct __attribute__((__aligned__(4))) ushort2 { 
# 143
unsigned short x, y; 
# 144
}; 
#endif
# 147 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 147
struct short3 { 
# 149
short x, y, z; 
# 150
}; 
#endif
# 153 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 153
struct ushort3 { 
# 155
unsigned short x, y, z; 
# 156
}; 
#endif
# 159 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 159
struct __attribute__((__aligned__(8))) short4 { short x; short y; short z; short w; }; 
#endif
# 162 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 162
struct __attribute__((__aligned__(8))) ushort4 { unsigned short x; unsigned short y; unsigned short z; unsigned short w; }; 
#endif
# 165 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 165
struct int1 { 
# 167
int x; 
# 168
}; 
#endif
# 171 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 171
struct uint1 { 
# 173
unsigned x; 
# 174
}; 
#endif
# 177 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 177
struct __attribute__((__aligned__(8))) int2 { int x; int y; }; 
#endif
# 180 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 180
struct __attribute__((__aligned__(8))) uint2 { unsigned x; unsigned y; }; 
#endif
# 183 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 183
struct int3 { 
# 185
int x, y, z; 
# 186
}; 
#endif
# 189 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 189
struct uint3 { 
# 191
unsigned x, y, z; 
# 192
}; 
#endif
# 195 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 195
struct __attribute__((__aligned__(16))) int4 { 
# 197
int x, y, z, w; 
# 198
}; 
#endif
# 201 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 201
struct __attribute__((__aligned__(16))) uint4 { 
# 203
unsigned x, y, z, w; 
# 204
}; 
#endif
# 207 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 207
struct long1 { 
# 209
long x; 
# 210
}; 
#endif
# 213 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 213
struct ulong1 { 
# 215
unsigned long x; 
# 216
}; 
#endif
# 229 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 229
struct __attribute__((__aligned__(16))) long2 { 
# 231
long x, y; 
# 232
}; 
#endif
# 235 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 235
struct __attribute__((__aligned__(16))) ulong2 { 
# 237
unsigned long x, y; 
# 238
}; 
#endif
# 243 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 243
struct long3 { 
# 245
long x, y, z; 
# 246
}; 
#endif
# 249 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 249
struct ulong3 { 
# 251
unsigned long x, y, z; 
# 252
}; 
#endif
# 255 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 255
struct __attribute__((__aligned__(16))) long4 { 
# 257
long x, y, z, w; 
# 258
}; 
#endif
# 261 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 261
struct __attribute__((__aligned__(16))) ulong4 { 
# 263
unsigned long x, y, z, w; 
# 264
}; 
#endif
# 267 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 267
struct float1 { 
# 269
float x; 
# 270
}; 
#endif
# 273 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 273
struct __attribute__((__aligned__(8))) float2 { float x; float y; }; 
#endif
# 276 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 276
struct float3 { 
# 278
float x, y, z; 
# 279
}; 
#endif
# 282 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 282
struct __attribute__((__aligned__(16))) float4 { 
# 284
float x, y, z, w; 
# 285
}; 
#endif
# 288 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 288
struct longlong1 { 
# 290
long long x; 
# 291
}; 
#endif
# 294 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 294
struct ulonglong1 { 
# 296
unsigned long long x; 
# 297
}; 
#endif
# 300 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 300
struct __attribute__((__aligned__(16))) longlong2 { 
# 302
long long x, y; 
# 303
}; 
#endif
# 306 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 306
struct __attribute__((__aligned__(16))) ulonglong2 { 
# 308
unsigned long long x, y; 
# 309
}; 
#endif
# 312 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 312
struct longlong3 { 
# 314
long long x, y, z; 
# 315
}; 
#endif
# 318 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 318
struct ulonglong3 { 
# 320
unsigned long long x, y, z; 
# 321
}; 
#endif
# 324 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 324
struct __attribute__((__aligned__(16))) longlong4 { 
# 326
long long x, y, z, w; 
# 327
}; 
#endif
# 330 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 330
struct __attribute__((__aligned__(16))) ulonglong4 { 
# 332
unsigned long long x, y, z, w; 
# 333
}; 
#endif
# 336 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 336
struct double1 { 
# 338
double x; 
# 339
}; 
#endif
# 342 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 342
struct __attribute__((__aligned__(16))) double2 { 
# 344
double x, y; 
# 345
}; 
#endif
# 348 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 348
struct double3 { 
# 350
double x, y, z; 
# 351
}; 
#endif
# 354 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 354
struct __attribute__((__aligned__(16))) double4 { 
# 356
double x, y, z, w; 
# 357
}; 
#endif
# 366 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef char1 
# 366
char1; 
#endif
# 368 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef uchar1 
# 368
uchar1; 
#endif
# 370 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef char2 
# 370
char2; 
#endif
# 372 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef uchar2 
# 372
uchar2; 
#endif
# 374 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef char3 
# 374
char3; 
#endif
# 376 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef uchar3 
# 376
uchar3; 
#endif
# 378 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef char4 
# 378
char4; 
#endif
# 380 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef uchar4 
# 380
uchar4; 
#endif
# 382 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef short1 
# 382
short1; 
#endif
# 384 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ushort1 
# 384
ushort1; 
#endif
# 386 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef short2 
# 386
short2; 
#endif
# 388 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ushort2 
# 388
ushort2; 
#endif
# 390 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef short3 
# 390
short3; 
#endif
# 392 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ushort3 
# 392
ushort3; 
#endif
# 394 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef short4 
# 394
short4; 
#endif
# 396 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ushort4 
# 396
ushort4; 
#endif
# 398 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef int1 
# 398
int1; 
#endif
# 400 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef uint1 
# 400
uint1; 
#endif
# 402 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef int2 
# 402
int2; 
#endif
# 404 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef uint2 
# 404
uint2; 
#endif
# 406 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef int3 
# 406
int3; 
#endif
# 408 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef uint3 
# 408
uint3; 
#endif
# 410 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef int4 
# 410
int4; 
#endif
# 412 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef uint4 
# 412
uint4; 
#endif
# 414 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef long1 
# 414
long1; 
#endif
# 416 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ulong1 
# 416
ulong1; 
#endif
# 418 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef long2 
# 418
long2; 
#endif
# 420 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ulong2 
# 420
ulong2; 
#endif
# 422 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef long3 
# 422
long3; 
#endif
# 424 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ulong3 
# 424
ulong3; 
#endif
# 426 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef long4 
# 426
long4; 
#endif
# 428 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ulong4 
# 428
ulong4; 
#endif
# 430 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef float1 
# 430
float1; 
#endif
# 432 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef float2 
# 432
float2; 
#endif
# 434 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef float3 
# 434
float3; 
#endif
# 436 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef float4 
# 436
float4; 
#endif
# 438 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef longlong1 
# 438
longlong1; 
#endif
# 440 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ulonglong1 
# 440
ulonglong1; 
#endif
# 442 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef longlong2 
# 442
longlong2; 
#endif
# 444 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ulonglong2 
# 444
ulonglong2; 
#endif
# 446 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef longlong3 
# 446
longlong3; 
#endif
# 448 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ulonglong3 
# 448
ulonglong3; 
#endif
# 450 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef longlong4 
# 450
longlong4; 
#endif
# 452 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef ulonglong4 
# 452
ulonglong4; 
#endif
# 454 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef double1 
# 454
double1; 
#endif
# 456 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef double2 
# 456
double2; 
#endif
# 458 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef double3 
# 458
double3; 
#endif
# 460 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
typedef double4 
# 460
double4; 
#endif
# 469 "/usr/local/cuda/bin/../include/vector_types.h"
#if 0
# 469
struct dim3 { 
# 471
unsigned x, y, z; 
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
# 90
extern "C" cudaError_t cudaMalloc3DArray(cudaArray **, const cudaChannelFormatDesc *, cudaExtent, unsigned = (0)); 
# 91
extern "C" cudaError_t cudaMemset3D(cudaPitchedPtr, int, cudaExtent); 
# 92
extern "C" cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms *); 
# 93
extern "C" cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms *, cudaStream_t = 0); 
# 101
extern "C" cudaError_t cudaMalloc(void **, size_t); 
# 102
extern "C" cudaError_t cudaMallocHost(void **, size_t); 
# 103
extern "C" cudaError_t cudaMallocPitch(void **, size_t *, size_t, size_t); 
# 104
extern "C" cudaError_t cudaMallocArray(cudaArray **, const cudaChannelFormatDesc *, size_t, size_t = (0), unsigned = (0)); 
# 105
extern "C" cudaError_t cudaFree(void *); 
# 106
extern "C" cudaError_t cudaFreeHost(void *); 
# 107
extern "C" cudaError_t cudaFreeArray(cudaArray *); 
# 109
extern "C" cudaError_t cudaHostAlloc(void **, size_t, unsigned); 
# 110
extern "C" cudaError_t cudaHostGetDevicePointer(void **, void *, unsigned); 
# 111
extern "C" cudaError_t cudaHostGetFlags(unsigned *, void *); 
# 119
extern "C" cudaError_t cudaMemGetInfo(size_t *, size_t *); 
# 120
extern "C" cudaError_t cudaMemcpy(void *, const void *, size_t, cudaMemcpyKind); 
# 121
extern "C" cudaError_t cudaMemcpyToArray(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind); 
# 122
extern "C" cudaError_t cudaMemcpyFromArray(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind); 
# 123
extern "C" cudaError_t cudaMemcpyArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice); 
# 124
extern "C" cudaError_t cudaMemcpy2D(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind); 
# 125
extern "C" cudaError_t cudaMemcpy2DToArray(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind); 
# 126
extern "C" cudaError_t cudaMemcpy2DFromArray(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind); 
# 127
extern "C" cudaError_t cudaMemcpy2DArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice); 
# 128
extern "C" cudaError_t cudaMemcpyToSymbol(const char *, const void *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyHostToDevice); 
# 129
extern "C" cudaError_t cudaMemcpyFromSymbol(void *, const char *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyDeviceToHost); 
# 137
extern "C" cudaError_t cudaMemcpyAsync(void *, const void *, size_t, cudaMemcpyKind, cudaStream_t = 0); 
# 138
extern "C" cudaError_t cudaMemcpyToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind, cudaStream_t = 0); 
# 139
extern "C" cudaError_t cudaMemcpyFromArrayAsync(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0); 
# 140
extern "C" cudaError_t cudaMemcpy2DAsync(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0); 
# 141
extern "C" cudaError_t cudaMemcpy2DToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0); 
# 142
extern "C" cudaError_t cudaMemcpy2DFromArrayAsync(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0); 
# 143
extern "C" cudaError_t cudaMemcpyToSymbolAsync(const char *, const void *, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0); 
# 144
extern "C" cudaError_t cudaMemcpyFromSymbolAsync(void *, const char *, size_t, size_t, cudaMemcpyKind, cudaStream_t = 0); 
# 152
extern "C" cudaError_t cudaMemset(void *, int, size_t); 
# 153
extern "C" cudaError_t cudaMemset2D(void *, size_t, int, size_t, size_t); 
# 161
extern "C" cudaError_t cudaGetSymbolAddress(void **, const char *); 
# 162
extern "C" cudaError_t cudaGetSymbolSize(size_t *, const char *); 
# 170
extern "C" cudaError_t cudaGetDeviceCount(int *); 
# 171
extern "C" cudaError_t cudaGetDeviceProperties(cudaDeviceProp *, int); 
# 172
extern "C" cudaError_t cudaChooseDevice(int *, const cudaDeviceProp *); 
# 173
extern "C" cudaError_t cudaSetDevice(int); 
# 174
extern "C" cudaError_t cudaGetDevice(int *); 
# 175
extern "C" cudaError_t cudaSetValidDevices(int *, int); 
# 176
extern "C" cudaError_t cudaSetDeviceFlags(int); 
# 184
extern "C" cudaError_t cudaBindTexture(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t = (((2147483647) * 2U) + 1U)); 
# 185
extern "C" cudaError_t cudaBindTexture2D(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t, size_t, size_t); 
# 186
extern "C" cudaError_t cudaBindTextureToArray(const textureReference *, const cudaArray *, const cudaChannelFormatDesc *); 
# 187
extern "C" cudaError_t cudaUnbindTexture(const textureReference *); 
# 188
extern "C" cudaError_t cudaGetTextureAlignmentOffset(size_t *, const textureReference *); 
# 189
extern "C" cudaError_t cudaGetTextureReference(const textureReference **, const char *); 
# 197
extern "C" cudaError_t cudaBindSurfaceToArray(const surfaceReference *, const cudaArray *, const cudaChannelFormatDesc *); 
# 198
extern "C" cudaError_t cudaGetSurfaceAlignmentOffset(size_t *, const surfaceReference *); 
# 199
extern "C" cudaError_t cudaGetSurfaceReference(const surfaceReference **, const char *); 
# 207
extern "C" cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc *, const cudaArray *); 
# 208
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc(int, int, int, int, cudaChannelFormatKind); 
# 216
extern "C" cudaError_t cudaGetLastError(); 
# 217
extern "C" cudaError_t cudaPeekAtLastError(); 
# 218
extern "C" const char *cudaGetErrorString(cudaError_t); 
# 226
extern "C" cudaError_t cudaConfigureCall(dim3, dim3, size_t = (0), cudaStream_t = 0); 
# 227
extern "C" cudaError_t cudaSetupArgument(const void *, size_t, size_t); 
# 228
extern "C" cudaError_t cudaFuncSetCacheConfig(const char *, cudaFuncCache); 
# 229
extern "C" cudaError_t cudaLaunch(const char *); 
# 230
extern "C" cudaError_t cudaFuncGetAttributes(cudaFuncAttributes *, const char *); 
# 238
extern "C" cudaError_t cudaStreamCreate(cudaStream_t *); 
# 239
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t); 
# 240
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t); 
# 241
extern "C" cudaError_t cudaStreamQuery(cudaStream_t); 
# 249
extern "C" cudaError_t cudaEventCreate(cudaEvent_t *); 
# 250
extern "C" cudaError_t cudaEventCreateWithFlags(cudaEvent_t *, int); 
# 251
extern "C" cudaError_t cudaEventRecord(cudaEvent_t, cudaStream_t = 0); 
# 252
extern "C" cudaError_t cudaEventQuery(cudaEvent_t); 
# 253
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t); 
# 254
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t); 
# 255
extern "C" cudaError_t cudaEventElapsedTime(float *, cudaEvent_t, cudaEvent_t); 
# 263
extern "C" cudaError_t cudaSetDoubleForDevice(double *); 
# 264
extern "C" cudaError_t cudaSetDoubleForHost(double *); 
# 272
extern "C" cudaError_t cudaThreadExit(); 
# 273
extern "C" cudaError_t cudaThreadSynchronize(); 
# 274
extern "C" cudaError_t cudaThreadSetLimit(cudaLimit, size_t); 
# 275
extern "C" cudaError_t cudaThreadGetLimit(size_t *, cudaLimit); 
# 283
extern "C" cudaError_t cudaDriverGetVersion(int *); 
# 284
extern "C" cudaError_t cudaRuntimeGetVersion(int *); 
# 285
extern "C" cudaError_t cudaGetExportTable(const void **, const cudaUUID_t *); 
# 294
extern "C" cudaError_t cudaGraphicsUnregisterResource(cudaGraphicsResource *); 
# 295
extern "C" cudaError_t cudaGraphicsResourceSetMapFlags(cudaGraphicsResource *, unsigned); 
# 296
extern "C" cudaError_t cudaGraphicsMapResources(int, cudaGraphicsResource **, cudaStream_t = 0); 
# 297
extern "C" cudaError_t cudaGraphicsUnmapResources(int, cudaGraphicsResource **, cudaStream_t = 0); 
# 298
extern "C" cudaError_t cudaGraphicsResourceGetMappedPointer(void **, size_t *, cudaGraphicsResource *); 
# 299
extern "C" cudaError_t cudaGraphicsSubResourceGetMappedArray(cudaArray **, cudaGraphicsResource *, unsigned, unsigned); 
# 93 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<class T> inline cudaChannelFormatDesc cudaCreateChannelDesc() 
# 94
{ 
# 95
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone); 
# 96
} 
# 98
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf() 
# 99
{ 
# 100
int e = (((int)sizeof(unsigned short)) * 8); 
# 102
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
# 103
} 
# 105
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf1() 
# 106
{ 
# 107
int e = (((int)sizeof(unsigned short)) * 8); 
# 109
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
# 110
} 
# 112
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf2() 
# 113
{ 
# 114
int e = (((int)sizeof(unsigned short)) * 8); 
# 116
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat); 
# 117
} 
# 119
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf4() 
# 120
{ 
# 121
int e = (((int)sizeof(unsigned short)) * 8); 
# 123
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat); 
# 124
} 
# 126
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char> () 
# 127
{ 
# 128
int e = (((int)sizeof(char)) * 8); 
# 133
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 135
} 
# 137
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> () 
# 138
{ 
# 139
int e = (((int)sizeof(signed char)) * 8); 
# 141
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 142
} 
# 144
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> () 
# 145
{ 
# 146
int e = (((int)sizeof(unsigned char)) * 8); 
# 148
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 149
} 
# 151
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> () 
# 152
{ 
# 153
int e = (((int)sizeof(signed char)) * 8); 
# 155
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 156
} 
# 158
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> () 
# 159
{ 
# 160
int e = (((int)sizeof(unsigned char)) * 8); 
# 162
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 163
} 
# 165
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> () 
# 166
{ 
# 167
int e = (((int)sizeof(signed char)) * 8); 
# 169
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
# 170
} 
# 172
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> () 
# 173
{ 
# 174
int e = (((int)sizeof(unsigned char)) * 8); 
# 176
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
# 177
} 
# 179
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> () 
# 180
{ 
# 181
int e = (((int)sizeof(signed char)) * 8); 
# 183
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
# 184
} 
# 186
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> () 
# 187
{ 
# 188
int e = (((int)sizeof(unsigned char)) * 8); 
# 190
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
# 191
} 
# 193
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short> () 
# 194
{ 
# 195
int e = (((int)sizeof(short)) * 8); 
# 197
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 198
} 
# 200
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> () 
# 201
{ 
# 202
int e = (((int)sizeof(unsigned short)) * 8); 
# 204
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 205
} 
# 207
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> () 
# 208
{ 
# 209
int e = (((int)sizeof(short)) * 8); 
# 211
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 212
} 
# 214
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> () 
# 215
{ 
# 216
int e = (((int)sizeof(unsigned short)) * 8); 
# 218
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 219
} 
# 221
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> () 
# 222
{ 
# 223
int e = (((int)sizeof(short)) * 8); 
# 225
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
# 226
} 
# 228
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> () 
# 229
{ 
# 230
int e = (((int)sizeof(unsigned short)) * 8); 
# 232
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
# 233
} 
# 235
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> () 
# 236
{ 
# 237
int e = (((int)sizeof(short)) * 8); 
# 239
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
# 240
} 
# 242
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> () 
# 243
{ 
# 244
int e = (((int)sizeof(unsigned short)) * 8); 
# 246
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
# 247
} 
# 249
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int> () 
# 250
{ 
# 251
int e = (((int)sizeof(int)) * 8); 
# 253
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 254
} 
# 256
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> () 
# 257
{ 
# 258
int e = (((int)sizeof(unsigned)) * 8); 
# 260
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 261
} 
# 263
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> () 
# 264
{ 
# 265
int e = (((int)sizeof(int)) * 8); 
# 267
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 268
} 
# 270
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> () 
# 271
{ 
# 272
int e = (((int)sizeof(unsigned)) * 8); 
# 274
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 275
} 
# 277
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> () 
# 278
{ 
# 279
int e = (((int)sizeof(int)) * 8); 
# 281
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
# 282
} 
# 284
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> () 
# 285
{ 
# 286
int e = (((int)sizeof(unsigned)) * 8); 
# 288
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
# 289
} 
# 291
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> () 
# 292
{ 
# 293
int e = (((int)sizeof(int)) * 8); 
# 295
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
# 296
} 
# 298
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> () 
# 299
{ 
# 300
int e = (((int)sizeof(unsigned)) * 8); 
# 302
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
# 303
} 
# 365 "/usr/local/cuda/bin/../include/channel_descriptor.h"
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float> () 
# 366
{ 
# 367
int e = (((int)sizeof(float)) * 8); 
# 369
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
# 370
} 
# 372
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> () 
# 373
{ 
# 374
int e = (((int)sizeof(float)) * 8); 
# 376
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
# 377
} 
# 379
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> () 
# 380
{ 
# 381
int e = (((int)sizeof(float)) * 8); 
# 383
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat); 
# 384
} 
# 386
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> () 
# 387
{ 
# 388
int e = (((int)sizeof(float)) * 8); 
# 390
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat); 
# 391
} 
# 55 "/usr/local/cuda/bin/../include/driver_functions.h"
static inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz) 
# 56
{ 
# 57
cudaPitchedPtr s; 
# 59
(s.ptr) = d; 
# 60
(s.pitch) = p; 
# 61
(s.xsize) = xsz; 
# 62
(s.ysize) = ysz; 
# 64
return s; 
# 65
} 
# 67
static inline cudaPos make_cudaPos(size_t x, size_t y, size_t z) 
# 68
{ 
# 69
cudaPos p; 
# 71
(p.x) = x; 
# 72
(p.y) = y; 
# 73
(p.z) = z; 
# 75
return p; 
# 76
} 
# 78
static inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d) 
# 79
{ 
# 80
cudaExtent e; 
# 82
(e.width) = w; 
# 83
(e.height) = h; 
# 84
(e.depth) = d; 
# 86
return e; 
# 87
} 
# 55 "/usr/local/cuda/bin/../include/vector_functions.h"
static inline char1 make_char1(signed char x) 
# 56
{ 
# 57
char1 t; (t.x) = x; return t; 
# 58
} 
# 60
static inline uchar1 make_uchar1(unsigned char x) 
# 61
{ 
# 62
uchar1 t; (t.x) = x; return t; 
# 63
} 
# 65
static inline char2 make_char2(signed char x, signed char y) 
# 66
{ 
# 67
char2 t; (t.x) = x; (t.y) = y; return t; 
# 68
} 
# 70
static inline uchar2 make_uchar2(unsigned char x, unsigned char y) 
# 71
{ 
# 72
uchar2 t; (t.x) = x; (t.y) = y; return t; 
# 73
} 
# 75
static inline char3 make_char3(signed char x, signed char y, signed char z) 
# 76
{ 
# 77
char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 78
} 
# 80
static inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z) 
# 81
{ 
# 82
uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 83
} 
# 85
static inline char4 make_char4(signed char x, signed char y, signed char z, signed char w) 
# 86
{ 
# 87
char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 88
} 
# 90
static inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w) 
# 91
{ 
# 92
uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 93
} 
# 95
static inline short1 make_short1(short x) 
# 96
{ 
# 97
short1 t; (t.x) = x; return t; 
# 98
} 
# 100
static inline ushort1 make_ushort1(unsigned short x) 
# 101
{ 
# 102
ushort1 t; (t.x) = x; return t; 
# 103
} 
# 105
static inline short2 make_short2(short x, short y) 
# 106
{ 
# 107
short2 t; (t.x) = x; (t.y) = y; return t; 
# 108
} 
# 110
static inline ushort2 make_ushort2(unsigned short x, unsigned short y) 
# 111
{ 
# 112
ushort2 t; (t.x) = x; (t.y) = y; return t; 
# 113
} 
# 115
static inline short3 make_short3(short x, short y, short z) 
# 116
{ 
# 117
short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 118
} 
# 120
static inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z) 
# 121
{ 
# 122
ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 123
} 
# 125
static inline short4 make_short4(short x, short y, short z, short w) 
# 126
{ 
# 127
short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 128
} 
# 130
static inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w) 
# 131
{ 
# 132
ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 133
} 
# 135
static inline int1 make_int1(int x) 
# 136
{ 
# 137
int1 t; (t.x) = x; return t; 
# 138
} 
# 140
static inline uint1 make_uint1(unsigned x) 
# 141
{ 
# 142
uint1 t; (t.x) = x; return t; 
# 143
} 
# 145
static inline int2 make_int2(int x, int y) 
# 146
{ 
# 147
int2 t; (t.x) = x; (t.y) = y; return t; 
# 148
} 
# 150
static inline uint2 make_uint2(unsigned x, unsigned y) 
# 151
{ 
# 152
uint2 t; (t.x) = x; (t.y) = y; return t; 
# 153
} 
# 155
static inline int3 make_int3(int x, int y, int z) 
# 156
{ 
# 157
int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 158
} 
# 160
static inline uint3 make_uint3(unsigned x, unsigned y, unsigned z) 
# 161
{ 
# 162
uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 163
} 
# 165
static inline int4 make_int4(int x, int y, int z, int w) 
# 166
{ 
# 167
int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 168
} 
# 170
static inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w) 
# 171
{ 
# 172
uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 173
} 
# 175
static inline long1 make_long1(long x) 
# 176
{ 
# 177
long1 t; (t.x) = x; return t; 
# 178
} 
# 180
static inline ulong1 make_ulong1(unsigned long x) 
# 181
{ 
# 182
ulong1 t; (t.x) = x; return t; 
# 183
} 
# 185
static inline long2 make_long2(long x, long y) 
# 186
{ 
# 187
long2 t; (t.x) = x; (t.y) = y; return t; 
# 188
} 
# 190
static inline ulong2 make_ulong2(unsigned long x, unsigned long y) 
# 191
{ 
# 192
ulong2 t; (t.x) = x; (t.y) = y; return t; 
# 193
} 
# 195
static inline long3 make_long3(long x, long y, long z) 
# 196
{ 
# 197
long3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 198
} 
# 200
static inline ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z) 
# 201
{ 
# 202
ulong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 203
} 
# 205
static inline long4 make_long4(long x, long y, long z, long w) 
# 206
{ 
# 207
long4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 208
} 
# 210
static inline ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z, unsigned long w) 
# 211
{ 
# 212
ulong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 213
} 
# 215
static inline float1 make_float1(float x) 
# 216
{ 
# 217
float1 t; (t.x) = x; return t; 
# 218
} 
# 220
static inline float2 make_float2(float x, float y) 
# 221
{ 
# 222
float2 t; (t.x) = x; (t.y) = y; return t; 
# 223
} 
# 225
static inline float3 make_float3(float x, float y, float z) 
# 226
{ 
# 227
float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 228
} 
# 230
static inline float4 make_float4(float x, float y, float z, float w) 
# 231
{ 
# 232
float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 233
} 
# 235
static inline longlong1 make_longlong1(long long x) 
# 236
{ 
# 237
longlong1 t; (t.x) = x; return t; 
# 238
} 
# 240
static inline ulonglong1 make_ulonglong1(unsigned long long x) 
# 241
{ 
# 242
ulonglong1 t; (t.x) = x; return t; 
# 243
} 
# 245
static inline longlong2 make_longlong2(long long x, long long y) 
# 246
{ 
# 247
longlong2 t; (t.x) = x; (t.y) = y; return t; 
# 248
} 
# 250
static inline ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y) 
# 251
{ 
# 252
ulonglong2 t; (t.x) = x; (t.y) = y; return t; 
# 253
} 
# 255
static inline longlong3 make_longlong3(long long x, long long y, long long z) 
# 256
{ 
# 257
longlong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 258
} 
# 260
static inline ulonglong3 make_ulonglong3(unsigned long long x, unsigned long long y, unsigned long long z) 
# 261
{ 
# 262
ulonglong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 263
} 
# 265
static inline longlong4 make_longlong4(long long x, long long y, long long z, long long w) 
# 266
{ 
# 267
longlong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 268
} 
# 270
static inline ulonglong4 make_ulonglong4(unsigned long long x, unsigned long long y, unsigned long long z, unsigned long long w) 
# 271
{ 
# 272
ulonglong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 273
} 
# 275
static inline double1 make_double1(double x) 
# 276
{ 
# 277
double1 t; (t.x) = x; return t; 
# 278
} 
# 280
static inline double2 make_double2(double x, double y) 
# 281
{ 
# 282
double2 t; (t.x) = x; (t.y) = y; return t; 
# 283
} 
# 285
static inline double3 make_double3(double x, double y, double z) 
# 286
{ 
# 287
double3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 288
} 
# 290
static inline double4 make_double4(double x, double y, double z, double w) 
# 291
{ 
# 292
double4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 293
} 
# 38 "/usr/include/string.h" 3
extern "C"  __attribute__((weak)) void *memcpy(void *__restrict__, const void *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 43
extern "C" void *memmove(void *, const void *, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 51
extern "C" void *memccpy(void *__restrict__, const void *__restrict__, int, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 59
extern "C"  __attribute__((weak)) void *memset(void *, int, size_t) throw() __attribute__((nonnull(1))); 
# 62
extern "C" int memcmp(const void *, const void *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 66
extern "C" void *memchr(const void *, int, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))); 
# 73
extern "C" void *rawmemchr(const void *, int) throw() __attribute__((__pure__)) __attribute__((nonnull(1))); 
# 77
extern "C" void *memrchr(const void *, int, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))); 
# 84
extern "C" char *strcpy(char *__restrict__, const char *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 87
extern "C" char *strncpy(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 92
extern "C" char *strcat(char *__restrict__, const char *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 95
extern "C" char *strncat(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 99
extern "C" int strcmp(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 102
extern "C" int strncmp(const char *, const char *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 106
extern "C" int strcoll(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 109
extern "C" size_t strxfrm(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((nonnull(2))); 
# 40 "/usr/include/xlocale.h" 3
extern "C" { typedef 
# 28
struct __locale_struct { 
# 31
struct locale_data *__locales[13]; 
# 34
const unsigned short *__ctype_b; 
# 35
const int *__ctype_tolower; 
# 36
const int *__ctype_toupper; 
# 39
const char *__names[13]; 
# 40
} *__locale_t; }
# 121 "/usr/include/string.h" 3
extern "C" int strcoll_l(const char *, const char *, __locale_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(3))); 
# 124
extern "C" size_t strxfrm_l(char *, const char *, size_t, __locale_t) throw() __attribute__((nonnull(2))) __attribute__((nonnull(4))); 
# 130
extern "C" char *strdup(const char *) throw() __attribute__((__malloc__)) __attribute__((nonnull(1))); 
# 138
extern "C" char *strndup(const char *, size_t) throw() __attribute__((__malloc__)) __attribute__((nonnull(1))); 
# 167 "/usr/include/string.h" 3
extern "C" char *strchr(const char *, int) throw() __attribute__((__pure__)) __attribute__((nonnull(1))); 
# 170
extern "C" char *strrchr(const char *, int) throw() __attribute__((__pure__)) __attribute__((nonnull(1))); 
# 177
extern "C" char *strchrnul(const char *, int) throw() __attribute__((__pure__)) __attribute__((nonnull(1))); 
# 184
extern "C" size_t strcspn(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 188
extern "C" size_t strspn(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 191
extern "C" char *strpbrk(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 194
extern "C" char *strstr(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 199
extern "C" char *strtok(char *__restrict__, const char *__restrict__) throw() __attribute__((nonnull(2))); 
# 205
extern "C" char *__strtok_r(char *__restrict__, const char *__restrict__, char **__restrict__) throw() __attribute__((nonnull(2))) __attribute__((nonnull(3))); 
# 210
extern "C" char *strtok_r(char *__restrict__, const char *__restrict__, char **__restrict__) throw() __attribute__((nonnull(2))) __attribute__((nonnull(3))); 
# 217
extern "C" char *strcasestr(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 225
extern "C" void *memmem(const void *, size_t, const void *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(3))); 
# 231
extern "C" void *__mempcpy(void *__restrict__, const void *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 234
extern "C" void *mempcpy(void *__restrict__, const void *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 242
extern "C" size_t strlen(const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))); 
# 249
extern "C" size_t strnlen(const char *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))); 
# 256
extern "C" char *strerror(int) throw(); 
# 281 "/usr/include/string.h" 3
extern "C" char *strerror_r(int, char *, size_t) throw() __attribute__((nonnull(2))); 
# 288
extern "C" char *strerror_l(int, __locale_t) throw(); 
# 294
extern "C" void __bzero(void *, size_t) throw() __attribute__((nonnull(1))); 
# 298
extern "C" void bcopy(const void *, void *, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 302
extern "C" void bzero(void *, size_t) throw() __attribute__((nonnull(1))); 
# 305
extern "C" int bcmp(const void *, const void *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 309
extern "C" char *index(const char *, int) throw() __attribute__((__pure__)) __attribute__((nonnull(1))); 
# 313
extern "C" char *rindex(const char *, int) throw() __attribute__((__pure__)) __attribute__((nonnull(1))); 
# 318
extern "C" int ffs(int) throw() __attribute__((__const__)); 
# 323
extern "C" int ffsl(long) throw() __attribute__((__const__)); 
# 325
extern "C" int ffsll(long long) throw() __attribute__((__const__)); 
# 331
extern "C" int strcasecmp(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 335
extern "C" int strncasecmp(const char *, const char *, size_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 342
extern "C" int strcasecmp_l(const char *, const char *, __locale_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(3))); 
# 346
extern "C" int strncasecmp_l(const char *, const char *, size_t, __locale_t) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(4))); 
# 354
extern "C" char *strsep(char **__restrict__, const char *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 361
extern "C" int strverscmp(const char *, const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 365
extern "C" char *strsignal(int) throw(); 
# 368
extern "C" char *__stpcpy(char *__restrict__, const char *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 370
extern "C" char *stpcpy(char *__restrict__, const char *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 375
extern "C" char *__stpncpy(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 378
extern "C" char *stpncpy(char *__restrict__, const char *__restrict__, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 383
extern "C" char *strfry(char *) throw() __attribute__((nonnull(1))); 
# 386
extern "C" void *memfrob(void *, size_t) throw() __attribute__((nonnull(1))); 
# 393
extern "C" char *basename(const char *) throw() __attribute__((nonnull(1))); 
# 31 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned char __u_char; }
# 32
extern "C" { typedef unsigned short __u_short; }
# 33
extern "C" { typedef unsigned __u_int; }
# 34
extern "C" { typedef unsigned long __u_long; }
# 37
extern "C" { typedef signed char __int8_t; }
# 38
extern "C" { typedef unsigned char __uint8_t; }
# 39
extern "C" { typedef signed short __int16_t; }
# 40
extern "C" { typedef unsigned short __uint16_t; }
# 41
extern "C" { typedef signed int __int32_t; }
# 42
extern "C" { typedef unsigned __uint32_t; }
# 44
extern "C" { typedef signed long __int64_t; }
# 45
extern "C" { typedef unsigned long __uint64_t; }
# 53
extern "C" { typedef long __quad_t; }
# 54
extern "C" { typedef unsigned long __u_quad_t; }
# 134 "/usr/include/bits/types.h" 3
extern "C" { typedef unsigned long __dev_t; }
# 135
extern "C" { typedef unsigned __uid_t; }
# 136
extern "C" { typedef unsigned __gid_t; }
# 137
extern "C" { typedef unsigned long __ino_t; }
# 138
extern "C" { typedef unsigned long __ino64_t; }
# 139
extern "C" { typedef unsigned __mode_t; }
# 140
extern "C" { typedef unsigned long __nlink_t; }
# 141
extern "C" { typedef long __off_t; }
# 142
extern "C" { typedef long __off64_t; }
# 143
extern "C" { typedef int __pid_t; }
# 144
extern "C" { typedef struct { int __val[2]; } __fsid_t; }
# 145
extern "C" { typedef long __clock_t; }
# 146
extern "C" { typedef unsigned long __rlim_t; }
# 147
extern "C" { typedef unsigned long __rlim64_t; }
# 148
extern "C" { typedef unsigned __id_t; }
# 149
extern "C" { typedef long __time_t; }
# 150
extern "C" { typedef unsigned __useconds_t; }
# 151
extern "C" { typedef long __suseconds_t; }
# 153
extern "C" { typedef int __daddr_t; }
# 154
extern "C" { typedef long __swblk_t; }
# 155
extern "C" { typedef int __key_t; }
# 158
extern "C" { typedef int __clockid_t; }
# 161
extern "C" { typedef void *__timer_t; }
# 164
extern "C" { typedef long __blksize_t; }
# 169
extern "C" { typedef long __blkcnt_t; }
# 170
extern "C" { typedef long __blkcnt64_t; }
# 173
extern "C" { typedef unsigned long __fsblkcnt_t; }
# 174
extern "C" { typedef unsigned long __fsblkcnt64_t; }
# 177
extern "C" { typedef unsigned long __fsfilcnt_t; }
# 178
extern "C" { typedef unsigned long __fsfilcnt64_t; }
# 180
extern "C" { typedef long __ssize_t; }
# 184
extern "C" { typedef __off64_t __loff_t; }
# 185
extern "C" { typedef __quad_t *__qaddr_t; }
# 186
extern "C" { typedef char *__caddr_t; }
# 189
extern "C" { typedef long __intptr_t; }
# 192
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
# 123
__time_t tv_sec; 
# 124
long tv_nsec; 
# 125
}; }
# 134
extern "C" { struct tm { 
# 136
int tm_sec; 
# 137
int tm_min; 
# 138
int tm_hour; 
# 139
int tm_mday; 
# 140
int tm_mon; 
# 141
int tm_year; 
# 142
int tm_wday; 
# 143
int tm_yday; 
# 144
int tm_isdst; 
# 147
long tm_gmtoff; 
# 148
const char *tm_zone; 
# 153
}; }
# 162
extern "C" { struct itimerspec { 
# 164
timespec it_interval; 
# 165
timespec it_value; 
# 166
}; }
# 169
struct sigevent; 
# 175
extern "C" { typedef __pid_t pid_t; }
# 184
extern "C"  __attribute__((weak)) clock_t clock() throw(); 
# 187
extern "C" time_t time(time_t *) throw(); 
# 190
extern "C" double difftime(time_t, time_t) throw() __attribute__((__const__)); 
# 194
extern "C" time_t mktime(tm *) throw(); 
# 200
extern "C" size_t strftime(char *__restrict__, size_t, const char *__restrict__, const tm *__restrict__) throw(); 
# 208
extern "C" char *strptime(const char *__restrict__, const char *__restrict__, tm *) throw(); 
# 218 "/usr/include/time.h" 3
extern "C" size_t strftime_l(char *__restrict__, size_t, const char *__restrict__, const tm *__restrict__, __locale_t) throw(); 
# 223
extern "C" char *strptime_l(const char *__restrict__, const char *__restrict__, tm *, __locale_t) throw(); 
# 232
extern "C" tm *gmtime(const time_t *) throw(); 
# 236
extern "C" tm *localtime(const time_t *) throw(); 
# 242
extern "C" tm *gmtime_r(const time_t *__restrict__, tm *__restrict__) throw(); 
# 247
extern "C" tm *localtime_r(const time_t *__restrict__, tm *__restrict__) throw(); 
# 254
extern "C" char *asctime(const tm *) throw(); 
# 257
extern "C" char *ctime(const time_t *) throw(); 
# 265
extern "C" char *asctime_r(const tm *__restrict__, char *__restrict__) throw(); 
# 269
extern "C" char *ctime_r(const time_t *__restrict__, char *__restrict__) throw(); 
# 275
extern "C" { extern char *__tzname[2]; } 
# 276
extern "C" { extern int __daylight; } 
# 277
extern "C" { extern long __timezone; } 
# 282
extern "C" { extern char *tzname[2]; } 
# 286
extern "C" void tzset() throw(); 
# 290
extern "C" { extern int daylight; } 
# 291
extern "C" { extern long timezone; } 
# 297
extern "C" int stime(const time_t *) throw(); 
# 312
extern "C" time_t timegm(tm *) throw(); 
# 315
extern "C" time_t timelocal(tm *) throw(); 
# 318
extern "C" int dysize(int) throw() __attribute__((__const__)); 
# 327
extern "C" int nanosleep(const timespec *, timespec *); 
# 332
extern "C" int clock_getres(clockid_t, timespec *) throw(); 
# 335
extern "C" int clock_gettime(clockid_t, timespec *) throw(); 
# 338
extern "C" int clock_settime(clockid_t, const timespec *) throw(); 
# 346
extern "C" int clock_nanosleep(clockid_t, int, const timespec *, timespec *); 
# 351
extern "C" int clock_getcpuclockid(pid_t, clockid_t *) throw(); 
# 356
extern "C" int timer_create(clockid_t, sigevent *__restrict__, timer_t *__restrict__) throw(); 
# 361
extern "C" int timer_delete(timer_t) throw(); 
# 364
extern "C" int timer_settime(timer_t, int, const itimerspec *__restrict__, itimerspec *__restrict__) throw(); 
# 369
extern "C" int timer_gettime(timer_t, itimerspec *) throw(); 
# 373
extern "C" int timer_getoverrun(timer_t) throw(); 
# 389
extern "C" { extern int getdate_err; } 
# 398
extern "C" tm *getdate(const char *); 
# 412
extern "C" int getdate_r(const char *__restrict__, tm *__restrict__); 
# 57 "/usr/local/cuda/bin/../include/common_functions.h"
extern "C"  __attribute__((weak)) clock_t clock() throw(); 
# 59
extern "C"  __attribute__((weak)) void *memset(void *, int, size_t) throw() __attribute__((nonnull(1))); 
# 61
extern "C"  __attribute__((weak)) void *memcpy(void *, const void *, size_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 66 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C"  __attribute__((weak)) int abs(int) throw() __attribute__((__const__)); 
# 68
extern "C"  __attribute__((weak)) long labs(long) throw() __attribute__((__const__)); 
# 70
extern "C"  __attribute__((weak)) long long llabs(long long) throw() __attribute__((__const__)); 
# 72
extern "C"  __attribute__((weak)) double fabs(double) throw() __attribute__((__const__)); 
# 74
extern "C"  __attribute__((weak)) float fabsf(float) throw() __attribute__((__const__)); 
# 77
extern "C"  __attribute__((weak)) int min(int, int); 
# 79
extern "C"  __attribute__((weak)) unsigned umin(unsigned, unsigned); 
# 81
extern "C"  __attribute__((weak)) long long llmin(long long, long long); 
# 83
extern "C"  __attribute__((weak)) unsigned long long ullmin(unsigned long long, unsigned long long); 
# 85
extern "C"  __attribute__((weak)) float fminf(float, float) throw(); 
# 87
extern "C"  __attribute__((weak)) double fmin(double, double) throw(); 
# 90
extern "C"  __attribute__((weak)) int max(int, int); 
# 92
extern "C"  __attribute__((weak)) unsigned umax(unsigned, unsigned); 
# 94
extern "C"  __attribute__((weak)) long long llmax(long long, long long); 
# 96
extern "C"  __attribute__((weak)) unsigned long long ullmax(unsigned long long, unsigned long long); 
# 98
extern "C"  __attribute__((weak)) float fmaxf(float, float) throw(); 
# 100
extern "C"  __attribute__((weak)) double fmax(double, double) throw(); 
# 103
extern "C"  __attribute__((weak)) double sin(double) throw(); 
# 105
extern "C"  __attribute__((weak)) float sinf(float) throw(); 
# 108
extern "C"  __attribute__((weak)) double cos(double) throw(); 
# 110
extern "C"  __attribute__((weak)) float cosf(float) throw(); 
# 113
extern "C"  __attribute__((weak)) void sincos(double, double *, double *) throw(); 
# 115
extern "C"  __attribute__((weak)) void sincosf(float, float *, float *) throw(); 
# 118
extern "C"  __attribute__((weak)) double tan(double) throw(); 
# 120
extern "C"  __attribute__((weak)) float tanf(float) throw(); 
# 123
extern "C"  __attribute__((weak)) double sqrt(double) throw(); 
# 125
extern "C"  __attribute__((weak)) float sqrtf(float) throw(); 
# 128
extern "C"  __attribute__((weak)) double rsqrt(double); 
# 130
extern "C"  __attribute__((weak)) float rsqrtf(float); 
# 133
extern "C"  __attribute__((weak)) double exp2(double) throw(); 
# 135
extern "C"  __attribute__((weak)) float exp2f(float) throw(); 
# 138
extern "C"  __attribute__((weak)) double exp10(double) throw(); 
# 140
extern "C"  __attribute__((weak)) float exp10f(float) throw(); 
# 143
extern "C"  __attribute__((weak)) double expm1(double) throw(); 
# 145
extern "C"  __attribute__((weak)) float expm1f(float) throw(); 
# 148
extern "C"  __attribute__((weak)) double log2(double) throw(); 
# 150
extern "C"  __attribute__((weak)) float log2f(float) throw(); 
# 153
extern "C"  __attribute__((weak)) double log10(double) throw(); 
# 155
extern "C"  __attribute__((weak)) float log10f(float) throw(); 
# 158
extern "C"  __attribute__((weak)) double log(double) throw(); 
# 160
extern "C"  __attribute__((weak)) float logf(float) throw(); 
# 163
extern "C"  __attribute__((weak)) double log1p(double) throw(); 
# 165
extern "C"  __attribute__((weak)) float log1pf(float) throw(); 
# 168
extern "C"  __attribute__((weak)) double floor(double) throw() __attribute__((__const__)); 
# 170
extern "C"  __attribute__((weak)) float floorf(float) throw() __attribute__((__const__)); 
# 173
extern "C"  __attribute__((weak)) double exp(double) throw(); 
# 175
extern "C"  __attribute__((weak)) float expf(float) throw(); 
# 178
extern "C"  __attribute__((weak)) double cosh(double) throw(); 
# 180
extern "C"  __attribute__((weak)) float coshf(float) throw(); 
# 183
extern "C"  __attribute__((weak)) double sinh(double) throw(); 
# 185
extern "C"  __attribute__((weak)) float sinhf(float) throw(); 
# 188
extern "C"  __attribute__((weak)) double tanh(double) throw(); 
# 190
extern "C"  __attribute__((weak)) float tanhf(float) throw(); 
# 193
extern "C"  __attribute__((weak)) double acosh(double) throw(); 
# 195
extern "C"  __attribute__((weak)) float acoshf(float) throw(); 
# 198
extern "C"  __attribute__((weak)) double asinh(double) throw(); 
# 200
extern "C"  __attribute__((weak)) float asinhf(float) throw(); 
# 203
extern "C"  __attribute__((weak)) double atanh(double) throw(); 
# 205
extern "C"  __attribute__((weak)) float atanhf(float) throw(); 
# 208
extern "C"  __attribute__((weak)) double ldexp(double, int) throw(); 
# 210
extern "C"  __attribute__((weak)) float ldexpf(float, int) throw(); 
# 213
extern "C"  __attribute__((weak)) double logb(double) throw(); 
# 215
extern "C"  __attribute__((weak)) float logbf(float) throw(); 
# 218
extern "C"  __attribute__((weak)) int ilogb(double) throw(); 
# 220
extern "C"  __attribute__((weak)) int ilogbf(float) throw(); 
# 223
extern "C"  __attribute__((weak)) double scalbn(double, int) throw(); 
# 225
extern "C"  __attribute__((weak)) float scalbnf(float, int) throw(); 
# 228
extern "C"  __attribute__((weak)) double scalbln(double, long) throw(); 
# 230
extern "C"  __attribute__((weak)) float scalblnf(float, long) throw(); 
# 233
extern "C"  __attribute__((weak)) double frexp(double, int *) throw(); 
# 235
extern "C"  __attribute__((weak)) float frexpf(float, int *) throw(); 
# 238
extern "C"  __attribute__((weak)) double round(double) throw() __attribute__((__const__)); 
# 240
extern "C"  __attribute__((weak)) float roundf(float) throw() __attribute__((__const__)); 
# 243
extern "C"  __attribute__((weak)) long lround(double) throw(); 
# 245
extern "C"  __attribute__((weak)) long lroundf(float) throw(); 
# 248
extern "C"  __attribute__((weak)) long long llround(double) throw(); 
# 250
extern "C"  __attribute__((weak)) long long llroundf(float) throw(); 
# 253
extern "C"  __attribute__((weak)) double rint(double) throw(); 
# 255
extern "C"  __attribute__((weak)) float rintf(float) throw(); 
# 258
extern "C"  __attribute__((weak)) long lrint(double) throw(); 
# 260
extern "C"  __attribute__((weak)) long lrintf(float) throw(); 
# 263
extern "C"  __attribute__((weak)) long long llrint(double) throw(); 
# 265
extern "C"  __attribute__((weak)) long long llrintf(float) throw(); 
# 268
extern "C"  __attribute__((weak)) double nearbyint(double) throw(); 
# 270
extern "C"  __attribute__((weak)) float nearbyintf(float) throw(); 
# 273
extern "C"  __attribute__((weak)) double ceil(double) throw() __attribute__((__const__)); 
# 275
extern "C"  __attribute__((weak)) float ceilf(float) throw() __attribute__((__const__)); 
# 278
extern "C"  __attribute__((weak)) double trunc(double) throw() __attribute__((__const__)); 
# 280
extern "C"  __attribute__((weak)) float truncf(float) throw() __attribute__((__const__)); 
# 283
extern "C"  __attribute__((weak)) double fdim(double, double) throw(); 
# 285
extern "C"  __attribute__((weak)) float fdimf(float, float) throw(); 
# 288
extern "C"  __attribute__((weak)) double atan2(double, double) throw(); 
# 290
extern "C"  __attribute__((weak)) float atan2f(float, float) throw(); 
# 293
extern "C"  __attribute__((weak)) double atan(double) throw(); 
# 295
extern "C"  __attribute__((weak)) float atanf(float) throw(); 
# 298
extern "C"  __attribute__((weak)) double asin(double) throw(); 
# 300
extern "C"  __attribute__((weak)) float asinf(float) throw(); 
# 303
extern "C"  __attribute__((weak)) double acos(double) throw(); 
# 305
extern "C"  __attribute__((weak)) float acosf(float) throw(); 
# 308
extern "C"  __attribute__((weak)) double hypot(double, double) throw(); 
# 310
extern "C"  __attribute__((weak)) float hypotf(float, float) throw(); 
# 313
extern "C"  __attribute__((weak)) double cbrt(double) throw(); 
# 315
extern "C"  __attribute__((weak)) float cbrtf(float) throw(); 
# 318
extern "C"  __attribute__((weak)) double rcbrt(double); 
# 320
extern "C"  __attribute__((weak)) float rcbrtf(float); 
# 323
extern "C"  __attribute__((weak)) double sinpi(double); 
# 325
extern "C"  __attribute__((weak)) float sinpif(float); 
# 328
extern "C"  __attribute__((weak)) double pow(double, double) throw(); 
# 330
extern "C"  __attribute__((weak)) float powf(float, float) throw(); 
# 333
extern "C"  __attribute__((weak)) double modf(double, double *) throw(); 
# 335
extern "C"  __attribute__((weak)) float modff(float, float *) throw(); 
# 338
extern "C"  __attribute__((weak)) double fmod(double, double) throw(); 
# 340
extern "C"  __attribute__((weak)) float fmodf(float, float) throw(); 
# 343
extern "C"  __attribute__((weak)) double remainder(double, double) throw(); 
# 345
extern "C"  __attribute__((weak)) float remainderf(float, float) throw(); 
# 348
extern "C"  __attribute__((weak)) double remquo(double, double, int *) throw(); 
# 350
extern "C"  __attribute__((weak)) float remquof(float, float, int *) throw(); 
# 353
extern "C"  __attribute__((weak)) double erf(double) throw(); 
# 355
extern "C"  __attribute__((weak)) float erff(float) throw(); 
# 358
extern "C"  __attribute__((weak)) double erfinv(double); 
# 360
extern "C"  __attribute__((weak)) float erfinvf(float); 
# 363
extern "C"  __attribute__((weak)) double erfc(double) throw(); 
# 365
extern "C"  __attribute__((weak)) float erfcf(float) throw(); 
# 368
extern "C"  __attribute__((weak)) double erfcinv(double); 
# 370
extern "C"  __attribute__((weak)) float erfcinvf(float); 
# 373
extern "C"  __attribute__((weak)) double lgamma(double) throw(); 
# 375
extern "C"  __attribute__((weak)) float lgammaf(float) throw(); 
# 378
extern "C"  __attribute__((weak)) double tgamma(double) throw(); 
# 380
extern "C"  __attribute__((weak)) float tgammaf(float) throw(); 
# 383
extern "C"  __attribute__((weak)) double copysign(double, double) throw() __attribute__((__const__)); 
# 385
extern "C"  __attribute__((weak)) float copysignf(float, float) throw() __attribute__((__const__)); 
# 388
extern "C"  __attribute__((weak)) double nextafter(double, double) throw() __attribute__((__const__)); 
# 390
extern "C"  __attribute__((weak)) float nextafterf(float, float) throw() __attribute__((__const__)); 
# 393
extern "C"  __attribute__((weak)) double nan(const char *) throw() __attribute__((__const__)); 
# 395
extern "C"  __attribute__((weak)) float nanf(const char *) throw() __attribute__((__const__)); 
# 398
extern "C"  __attribute__((weak)) int __isinf(double) throw() __attribute__((__const__)); 
# 400
extern "C"  __attribute__((weak)) int __isinff(float) throw() __attribute__((__const__)); 
# 403
extern "C"  __attribute__((weak)) int __isnan(double) throw() __attribute__((__const__)); 
# 405
extern "C"  __attribute__((weak)) int __isnanf(float) throw() __attribute__((__const__)); 
# 419 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C"  __attribute__((weak)) int __finite(double) throw() __attribute__((__const__)); 
# 421
extern "C"  __attribute__((weak)) int __finitef(float) throw() __attribute__((__const__)); 
# 423
extern "C"  __attribute__((weak)) int __signbit(double) throw() __attribute__((__const__)); 
# 428
extern "C"  __attribute__((weak)) int __signbitf(float) throw() __attribute__((__const__)); 
# 431
extern "C"  __attribute__((weak)) double fma(double, double, double) throw(); 
# 433
extern "C"  __attribute__((weak)) float fmaf(float, float, float) throw(); 
# 441
extern "C"  __attribute__((weak)) int __signbitl(long double) throw() __attribute__((__const__)); 
# 443
extern "C"  __attribute__((weak)) int __isinfl(long double) throw() __attribute__((__const__)); 
# 445
extern "C"  __attribute__((weak)) int __isnanl(long double) throw() __attribute__((__const__)); 
# 455 "/usr/local/cuda/bin/../include/math_functions.h"
extern "C"  __attribute__((weak)) int __finitel(long double) throw() __attribute__((__const__)); 
# 31 "/usr/include/bits/mathdef.h" 3
extern "C" { typedef float float_t; }
# 32
extern "C" { typedef double double_t; }
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C"  __attribute__((weak)) double acos(double) throw(); extern "C" double __acos(double) throw(); 
# 57
extern "C"  __attribute__((weak)) double asin(double) throw(); extern "C" double __asin(double) throw(); 
# 59
extern "C"  __attribute__((weak)) double atan(double) throw(); extern "C" double __atan(double) throw(); 
# 61
extern "C"  __attribute__((weak)) double atan2(double, double) throw(); extern "C" double __atan2(double, double) throw(); 
# 64
extern "C"  __attribute__((weak)) double cos(double) throw(); extern "C" double __cos(double) throw(); 
# 66
extern "C"  __attribute__((weak)) double sin(double) throw(); extern "C" double __sin(double) throw(); 
# 68
extern "C"  __attribute__((weak)) double tan(double) throw(); extern "C" double __tan(double) throw(); 
# 73
extern "C"  __attribute__((weak)) double cosh(double) throw(); extern "C" double __cosh(double) throw(); 
# 75
extern "C"  __attribute__((weak)) double sinh(double) throw(); extern "C" double __sinh(double) throw(); 
# 77
extern "C"  __attribute__((weak)) double tanh(double) throw(); extern "C" double __tanh(double) throw(); 
# 82
extern "C"  __attribute__((weak)) void sincos(double, double *, double *) throw(); extern "C" void __sincos(double, double *, double *) throw(); 
# 89
extern "C"  __attribute__((weak)) double acosh(double) throw(); extern "C" double __acosh(double) throw(); 
# 91
extern "C"  __attribute__((weak)) double asinh(double) throw(); extern "C" double __asinh(double) throw(); 
# 93
extern "C"  __attribute__((weak)) double atanh(double) throw(); extern "C" double __atanh(double) throw(); 
# 101
extern "C"  __attribute__((weak)) double exp(double) throw(); extern "C" double __exp(double) throw(); 
# 104
extern "C"  __attribute__((weak)) double frexp(double, int *) throw(); extern "C" double __frexp(double, int *) throw(); 
# 107
extern "C"  __attribute__((weak)) double ldexp(double, int) throw(); extern "C" double __ldexp(double, int) throw(); 
# 110
extern "C"  __attribute__((weak)) double log(double) throw(); extern "C" double __log(double) throw(); 
# 113
extern "C"  __attribute__((weak)) double log10(double) throw(); extern "C" double __log10(double) throw(); 
# 116
extern "C"  __attribute__((weak)) double modf(double, double *) throw(); extern "C" double __modf(double, double *) throw(); 
# 121
extern "C"  __attribute__((weak)) double exp10(double) throw(); extern "C" double __exp10(double) throw(); 
# 123
extern "C" double pow10(double) throw(); extern "C" double __pow10(double) throw(); 
# 129
extern "C"  __attribute__((weak)) double expm1(double) throw(); extern "C" double __expm1(double) throw(); 
# 132
extern "C"  __attribute__((weak)) double log1p(double) throw(); extern "C" double __log1p(double) throw(); 
# 135
extern "C"  __attribute__((weak)) double logb(double) throw(); extern "C" double __logb(double) throw(); 
# 142
extern "C"  __attribute__((weak)) double exp2(double) throw(); extern "C" double __exp2(double) throw(); 
# 145
extern "C"  __attribute__((weak)) double log2(double) throw(); extern "C" double __log2(double) throw(); 
# 154
extern "C"  __attribute__((weak)) double pow(double, double) throw(); extern "C" double __pow(double, double) throw(); 
# 157
extern "C"  __attribute__((weak)) double sqrt(double) throw(); extern "C" double __sqrt(double) throw(); 
# 163
extern "C"  __attribute__((weak)) double hypot(double, double) throw(); extern "C" double __hypot(double, double) throw(); 
# 170
extern "C"  __attribute__((weak)) double cbrt(double) throw(); extern "C" double __cbrt(double) throw(); 
# 179
extern "C"  __attribute__((weak)) double ceil(double) throw() __attribute__((__const__)); extern "C" double __ceil(double) throw() __attribute__((__const__)); 
# 182
extern "C"  __attribute__((weak)) double fabs(double) throw() __attribute__((__const__)); extern "C" double __fabs(double) throw() __attribute__((__const__)); 
# 185
extern "C"  __attribute__((weak)) double floor(double) throw() __attribute__((__const__)); extern "C" double __floor(double) throw() __attribute__((__const__)); 
# 188
extern "C"  __attribute__((weak)) double fmod(double, double) throw(); extern "C" double __fmod(double, double) throw(); 
# 193
extern "C"  __attribute__((weak)) int __isinf(double) throw() __attribute__((__const__)); 
# 196
extern "C"  __attribute__((weak)) int __finite(double) throw() __attribute__((__const__)); 
# 202
extern "C" int isinf(double) throw() __attribute__((__const__)); 
# 205
extern "C" int finite(double) throw() __attribute__((__const__)); 
# 208
extern "C" double drem(double, double) throw(); extern "C" double __drem(double, double) throw(); 
# 212
extern "C" double significand(double) throw(); extern "C" double __significand(double) throw(); 
# 218
extern "C"  __attribute__((weak)) double copysign(double, double) throw() __attribute__((__const__)); extern "C" double __copysign(double, double) throw() __attribute__((__const__)); 
# 225
extern "C"  __attribute__((weak)) double nan(const char *) throw() __attribute__((__const__)); extern "C" double __nan(const char *) throw() __attribute__((__const__)); 
# 231
extern "C"  __attribute__((weak)) int __isnan(double) throw() __attribute__((__const__)); 
# 235
extern "C" int isnan(double) throw() __attribute__((__const__)); 
# 238
extern "C" double j0(double) throw(); extern "C" double __j0(double) throw(); 
# 239
extern "C" double j1(double) throw(); extern "C" double __j1(double) throw(); 
# 240
extern "C" double jn(int, double) throw(); extern "C" double __jn(int, double) throw(); 
# 241
extern "C" double y0(double) throw(); extern "C" double __y0(double) throw(); 
# 242
extern "C" double y1(double) throw(); extern "C" double __y1(double) throw(); 
# 243
extern "C" double yn(int, double) throw(); extern "C" double __yn(int, double) throw(); 
# 250
extern "C"  __attribute__((weak)) double erf(double) throw(); extern "C" double __erf(double) throw(); 
# 251
extern "C"  __attribute__((weak)) double erfc(double) throw(); extern "C" double __erfc(double) throw(); 
# 252
extern "C"  __attribute__((weak)) double lgamma(double) throw(); extern "C" double __lgamma(double) throw(); 
# 259
extern "C"  __attribute__((weak)) double tgamma(double) throw(); extern "C" double __tgamma(double) throw(); 
# 265
extern "C" double gamma(double) throw(); extern "C" double __gamma(double) throw(); 
# 272
extern "C" double lgamma_r(double, int *) throw(); extern "C" double __lgamma_r(double, int *) throw(); 
# 280
extern "C"  __attribute__((weak)) double rint(double) throw(); extern "C" double __rint(double) throw(); 
# 283
extern "C"  __attribute__((weak)) double nextafter(double, double) throw() __attribute__((__const__)); extern "C" double __nextafter(double, double) throw() __attribute__((__const__)); 
# 285
extern "C" double nexttoward(double, long double) throw() __attribute__((__const__)); extern "C" double __nexttoward(double, long double) throw() __attribute__((__const__)); 
# 289
extern "C"  __attribute__((weak)) double remainder(double, double) throw(); extern "C" double __remainder(double, double) throw(); 
# 293
extern "C"  __attribute__((weak)) double scalbn(double, int) throw(); extern "C" double __scalbn(double, int) throw(); 
# 297
extern "C"  __attribute__((weak)) int ilogb(double) throw(); extern "C" int __ilogb(double) throw(); 
# 302
extern "C"  __attribute__((weak)) double scalbln(double, long) throw(); extern "C" double __scalbln(double, long) throw(); 
# 306
extern "C"  __attribute__((weak)) double nearbyint(double) throw(); extern "C" double __nearbyint(double) throw(); 
# 310
extern "C"  __attribute__((weak)) double round(double) throw() __attribute__((__const__)); extern "C" double __round(double) throw() __attribute__((__const__)); 
# 314
extern "C"  __attribute__((weak)) double trunc(double) throw() __attribute__((__const__)); extern "C" double __trunc(double) throw() __attribute__((__const__)); 
# 319
extern "C"  __attribute__((weak)) double remquo(double, double, int *) throw(); extern "C" double __remquo(double, double, int *) throw(); 
# 326
extern "C"  __attribute__((weak)) long lrint(double) throw(); extern "C" long __lrint(double) throw(); 
# 327
extern "C"  __attribute__((weak)) long long llrint(double) throw(); extern "C" long long __llrint(double) throw(); 
# 331
extern "C"  __attribute__((weak)) long lround(double) throw(); extern "C" long __lround(double) throw(); 
# 332
extern "C"  __attribute__((weak)) long long llround(double) throw(); extern "C" long long __llround(double) throw(); 
# 336
extern "C"  __attribute__((weak)) double fdim(double, double) throw(); extern "C" double __fdim(double, double) throw(); 
# 339
extern "C"  __attribute__((weak)) double fmax(double, double) throw(); extern "C" double __fmax(double, double) throw(); 
# 342
extern "C"  __attribute__((weak)) double fmin(double, double) throw(); extern "C" double __fmin(double, double) throw(); 
# 346
extern "C" int __fpclassify(double) throw() __attribute__((__const__)); 
# 350
extern "C"  __attribute__((weak)) int __signbit(double) throw() __attribute__((__const__)); 
# 355
extern "C"  __attribute__((weak)) double fma(double, double, double) throw(); extern "C" double __fma(double, double, double) throw(); 
# 364
extern "C" double scalb(double, double) throw(); extern "C" double __scalb(double, double) throw(); 
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C"  __attribute__((weak)) float acosf(float) throw(); extern "C" float __acosf(float) throw(); 
# 57
extern "C"  __attribute__((weak)) float asinf(float) throw(); extern "C" float __asinf(float) throw(); 
# 59
extern "C"  __attribute__((weak)) float atanf(float) throw(); extern "C" float __atanf(float) throw(); 
# 61
extern "C"  __attribute__((weak)) float atan2f(float, float) throw(); extern "C" float __atan2f(float, float) throw(); 
# 64
extern "C"  __attribute__((weak)) float cosf(float) throw(); 
# 66
extern "C"  __attribute__((weak)) float sinf(float) throw(); 
# 68
extern "C"  __attribute__((weak)) float tanf(float) throw(); 
# 73
extern "C"  __attribute__((weak)) float coshf(float) throw(); extern "C" float __coshf(float) throw(); 
# 75
extern "C"  __attribute__((weak)) float sinhf(float) throw(); extern "C" float __sinhf(float) throw(); 
# 77
extern "C"  __attribute__((weak)) float tanhf(float) throw(); extern "C" float __tanhf(float) throw(); 
# 82
extern "C"  __attribute__((weak)) void sincosf(float, float *, float *) throw(); 
# 89
extern "C"  __attribute__((weak)) float acoshf(float) throw(); extern "C" float __acoshf(float) throw(); 
# 91
extern "C"  __attribute__((weak)) float asinhf(float) throw(); extern "C" float __asinhf(float) throw(); 
# 93
extern "C"  __attribute__((weak)) float atanhf(float) throw(); extern "C" float __atanhf(float) throw(); 
# 101
extern "C"  __attribute__((weak)) float expf(float) throw(); 
# 104
extern "C"  __attribute__((weak)) float frexpf(float, int *) throw(); extern "C" float __frexpf(float, int *) throw(); 
# 107
extern "C"  __attribute__((weak)) float ldexpf(float, int) throw(); extern "C" float __ldexpf(float, int) throw(); 
# 110
extern "C"  __attribute__((weak)) float logf(float) throw(); 
# 113
extern "C"  __attribute__((weak)) float log10f(float) throw(); 
# 116
extern "C"  __attribute__((weak)) float modff(float, float *) throw(); extern "C" float __modff(float, float *) throw(); 
# 121
extern "C"  __attribute__((weak)) float exp10f(float) throw(); 
# 123
extern "C" float pow10f(float) throw(); extern "C" float __pow10f(float) throw(); 
# 129
extern "C"  __attribute__((weak)) float expm1f(float) throw(); extern "C" float __expm1f(float) throw(); 
# 132
extern "C"  __attribute__((weak)) float log1pf(float) throw(); extern "C" float __log1pf(float) throw(); 
# 135
extern "C"  __attribute__((weak)) float logbf(float) throw(); extern "C" float __logbf(float) throw(); 
# 142
extern "C"  __attribute__((weak)) float exp2f(float) throw(); extern "C" float __exp2f(float) throw(); 
# 145
extern "C"  __attribute__((weak)) float log2f(float) throw(); 
# 154
extern "C"  __attribute__((weak)) float powf(float, float) throw(); 
# 157
extern "C"  __attribute__((weak)) float sqrtf(float) throw(); extern "C" float __sqrtf(float) throw(); 
# 163
extern "C"  __attribute__((weak)) float hypotf(float, float) throw(); extern "C" float __hypotf(float, float) throw(); 
# 170
extern "C"  __attribute__((weak)) float cbrtf(float) throw(); extern "C" float __cbrtf(float) throw(); 
# 179
extern "C"  __attribute__((weak)) float ceilf(float) throw() __attribute__((__const__)); extern "C" float __ceilf(float) throw() __attribute__((__const__)); 
# 182
extern "C"  __attribute__((weak)) float fabsf(float) throw() __attribute__((__const__)); extern "C" float __fabsf(float) throw() __attribute__((__const__)); 
# 185
extern "C"  __attribute__((weak)) float floorf(float) throw() __attribute__((__const__)); extern "C" float __floorf(float) throw() __attribute__((__const__)); 
# 188
extern "C"  __attribute__((weak)) float fmodf(float, float) throw(); extern "C" float __fmodf(float, float) throw(); 
# 193
extern "C"  __attribute__((weak)) int __isinff(float) throw() __attribute__((__const__)); 
# 196
extern "C"  __attribute__((weak)) int __finitef(float) throw() __attribute__((__const__)); 
# 202
extern "C" int isinff(float) throw() __attribute__((__const__)); 
# 205
extern "C" int finitef(float) throw() __attribute__((__const__)); 
# 208
extern "C" float dremf(float, float) throw(); extern "C" float __dremf(float, float) throw(); 
# 212
extern "C" float significandf(float) throw(); extern "C" float __significandf(float) throw(); 
# 218
extern "C"  __attribute__((weak)) float copysignf(float, float) throw() __attribute__((__const__)); extern "C" float __copysignf(float, float) throw() __attribute__((__const__)); 
# 225
extern "C"  __attribute__((weak)) float nanf(const char *) throw() __attribute__((__const__)); extern "C" float __nanf(const char *) throw() __attribute__((__const__)); 
# 231
extern "C"  __attribute__((weak)) int __isnanf(float) throw() __attribute__((__const__)); 
# 235
extern "C" int isnanf(float) throw() __attribute__((__const__)); 
# 238
extern "C" float j0f(float) throw(); extern "C" float __j0f(float) throw(); 
# 239
extern "C" float j1f(float) throw(); extern "C" float __j1f(float) throw(); 
# 240
extern "C" float jnf(int, float) throw(); extern "C" float __jnf(int, float) throw(); 
# 241
extern "C" float y0f(float) throw(); extern "C" float __y0f(float) throw(); 
# 242
extern "C" float y1f(float) throw(); extern "C" float __y1f(float) throw(); 
# 243
extern "C" float ynf(int, float) throw(); extern "C" float __ynf(int, float) throw(); 
# 250
extern "C"  __attribute__((weak)) float erff(float) throw(); extern "C" float __erff(float) throw(); 
# 251
extern "C"  __attribute__((weak)) float erfcf(float) throw(); extern "C" float __erfcf(float) throw(); 
# 252
extern "C"  __attribute__((weak)) float lgammaf(float) throw(); extern "C" float __lgammaf(float) throw(); 
# 259
extern "C"  __attribute__((weak)) float tgammaf(float) throw(); extern "C" float __tgammaf(float) throw(); 
# 265
extern "C" float gammaf(float) throw(); extern "C" float __gammaf(float) throw(); 
# 272
extern "C" float lgammaf_r(float, int *) throw(); extern "C" float __lgammaf_r(float, int *) throw(); 
# 280
extern "C"  __attribute__((weak)) float rintf(float) throw(); extern "C" float __rintf(float) throw(); 
# 283
extern "C"  __attribute__((weak)) float nextafterf(float, float) throw() __attribute__((__const__)); extern "C" float __nextafterf(float, float) throw() __attribute__((__const__)); 
# 285
extern "C" float nexttowardf(float, long double) throw() __attribute__((__const__)); extern "C" float __nexttowardf(float, long double) throw() __attribute__((__const__)); 
# 289
extern "C"  __attribute__((weak)) float remainderf(float, float) throw(); extern "C" float __remainderf(float, float) throw(); 
# 293
extern "C"  __attribute__((weak)) float scalbnf(float, int) throw(); extern "C" float __scalbnf(float, int) throw(); 
# 297
extern "C"  __attribute__((weak)) int ilogbf(float) throw(); extern "C" int __ilogbf(float) throw(); 
# 302
extern "C"  __attribute__((weak)) float scalblnf(float, long) throw(); extern "C" float __scalblnf(float, long) throw(); 
# 306
extern "C"  __attribute__((weak)) float nearbyintf(float) throw(); extern "C" float __nearbyintf(float) throw(); 
# 310
extern "C"  __attribute__((weak)) float roundf(float) throw() __attribute__((__const__)); extern "C" float __roundf(float) throw() __attribute__((__const__)); 
# 314
extern "C"  __attribute__((weak)) float truncf(float) throw() __attribute__((__const__)); extern "C" float __truncf(float) throw() __attribute__((__const__)); 
# 319
extern "C"  __attribute__((weak)) float remquof(float, float, int *) throw(); extern "C" float __remquof(float, float, int *) throw(); 
# 326
extern "C"  __attribute__((weak)) long lrintf(float) throw(); extern "C" long __lrintf(float) throw(); 
# 327
extern "C"  __attribute__((weak)) long long llrintf(float) throw(); extern "C" long long __llrintf(float) throw(); 
# 331
extern "C"  __attribute__((weak)) long lroundf(float) throw(); extern "C" long __lroundf(float) throw(); 
# 332
extern "C"  __attribute__((weak)) long long llroundf(float) throw(); extern "C" long long __llroundf(float) throw(); 
# 336
extern "C"  __attribute__((weak)) float fdimf(float, float) throw(); extern "C" float __fdimf(float, float) throw(); 
# 339
extern "C"  __attribute__((weak)) float fmaxf(float, float) throw(); extern "C" float __fmaxf(float, float) throw(); 
# 342
extern "C"  __attribute__((weak)) float fminf(float, float) throw(); extern "C" float __fminf(float, float) throw(); 
# 346
extern "C" int __fpclassifyf(float) throw() __attribute__((__const__)); 
# 350
extern "C"  __attribute__((weak)) int __signbitf(float) throw() __attribute__((__const__)); 
# 355
extern "C"  __attribute__((weak)) float fmaf(float, float, float) throw(); extern "C" float __fmaf(float, float, float) throw(); 
# 364
extern "C" float scalbf(float, float) throw(); extern "C" float __scalbf(float, float) throw(); 
# 55 "/usr/include/bits/mathcalls.h" 3
extern "C" long double acosl(long double) throw(); extern "C" long double __acosl(long double) throw(); 
# 57
extern "C" long double asinl(long double) throw(); extern "C" long double __asinl(long double) throw(); 
# 59
extern "C" long double atanl(long double) throw(); extern "C" long double __atanl(long double) throw(); 
# 61
extern "C" long double atan2l(long double, long double) throw(); extern "C" long double __atan2l(long double, long double) throw(); 
# 64
extern "C" long double cosl(long double) throw(); extern "C" long double __cosl(long double) throw(); 
# 66
extern "C" long double sinl(long double) throw(); extern "C" long double __sinl(long double) throw(); 
# 68
extern "C" long double tanl(long double) throw(); extern "C" long double __tanl(long double) throw(); 
# 73
extern "C" long double coshl(long double) throw(); extern "C" long double __coshl(long double) throw(); 
# 75
extern "C" long double sinhl(long double) throw(); extern "C" long double __sinhl(long double) throw(); 
# 77
extern "C" long double tanhl(long double) throw(); extern "C" long double __tanhl(long double) throw(); 
# 82
extern "C" void sincosl(long double, long double *, long double *) throw(); extern "C" void __sincosl(long double, long double *, long double *) throw(); 
# 89
extern "C" long double acoshl(long double) throw(); extern "C" long double __acoshl(long double) throw(); 
# 91
extern "C" long double asinhl(long double) throw(); extern "C" long double __asinhl(long double) throw(); 
# 93
extern "C" long double atanhl(long double) throw(); extern "C" long double __atanhl(long double) throw(); 
# 101
extern "C" long double expl(long double) throw(); extern "C" long double __expl(long double) throw(); 
# 104
extern "C" long double frexpl(long double, int *) throw(); extern "C" long double __frexpl(long double, int *) throw(); 
# 107
extern "C" long double ldexpl(long double, int) throw(); extern "C" long double __ldexpl(long double, int) throw(); 
# 110
extern "C" long double logl(long double) throw(); extern "C" long double __logl(long double) throw(); 
# 113
extern "C" long double log10l(long double) throw(); extern "C" long double __log10l(long double) throw(); 
# 116
extern "C" long double modfl(long double, long double *) throw(); extern "C" long double __modfl(long double, long double *) throw(); 
# 121
extern "C" long double exp10l(long double) throw(); extern "C" long double __exp10l(long double) throw(); 
# 123
extern "C" long double pow10l(long double) throw(); extern "C" long double __pow10l(long double) throw(); 
# 129
extern "C" long double expm1l(long double) throw(); extern "C" long double __expm1l(long double) throw(); 
# 132
extern "C" long double log1pl(long double) throw(); extern "C" long double __log1pl(long double) throw(); 
# 135
extern "C" long double logbl(long double) throw(); extern "C" long double __logbl(long double) throw(); 
# 142
extern "C" long double exp2l(long double) throw(); extern "C" long double __exp2l(long double) throw(); 
# 145
extern "C" long double log2l(long double) throw(); extern "C" long double __log2l(long double) throw(); 
# 154
extern "C" long double powl(long double, long double) throw(); extern "C" long double __powl(long double, long double) throw(); 
# 157
extern "C" long double sqrtl(long double) throw(); extern "C" long double __sqrtl(long double) throw(); 
# 163
extern "C" long double hypotl(long double, long double) throw(); extern "C" long double __hypotl(long double, long double) throw(); 
# 170
extern "C" long double cbrtl(long double) throw(); extern "C" long double __cbrtl(long double) throw(); 
# 179
extern "C" long double ceill(long double) throw() __attribute__((__const__)); extern "C" long double __ceill(long double) throw() __attribute__((__const__)); 
# 182
extern "C" long double fabsl(long double) throw() __attribute__((__const__)); extern "C" long double __fabsl(long double) throw() __attribute__((__const__)); 
# 185
extern "C" long double floorl(long double) throw() __attribute__((__const__)); extern "C" long double __floorl(long double) throw() __attribute__((__const__)); 
# 188
extern "C" long double fmodl(long double, long double) throw(); extern "C" long double __fmodl(long double, long double) throw(); 
# 193
extern "C"  __attribute__((weak)) int __isinfl(long double) throw() __attribute__((__const__)); 
# 196
extern "C"  __attribute__((weak)) int __finitel(long double) throw() __attribute__((__const__)); 
# 202
extern "C" int isinfl(long double) throw() __attribute__((__const__)); 
# 205
extern "C" int finitel(long double) throw() __attribute__((__const__)); 
# 208
extern "C" long double dreml(long double, long double) throw(); extern "C" long double __dreml(long double, long double) throw(); 
# 212
extern "C" long double significandl(long double) throw(); extern "C" long double __significandl(long double) throw(); 
# 218
extern "C" long double copysignl(long double, long double) throw() __attribute__((__const__)); extern "C" long double __copysignl(long double, long double) throw() __attribute__((__const__)); 
# 225
extern "C" long double nanl(const char *) throw() __attribute__((__const__)); extern "C" long double __nanl(const char *) throw() __attribute__((__const__)); 
# 231
extern "C"  __attribute__((weak)) int __isnanl(long double) throw() __attribute__((__const__)); 
# 235
extern "C" int isnanl(long double) throw() __attribute__((__const__)); 
# 238
extern "C" long double j0l(long double) throw(); extern "C" long double __j0l(long double) throw(); 
# 239
extern "C" long double j1l(long double) throw(); extern "C" long double __j1l(long double) throw(); 
# 240
extern "C" long double jnl(int, long double) throw(); extern "C" long double __jnl(int, long double) throw(); 
# 241
extern "C" long double y0l(long double) throw(); extern "C" long double __y0l(long double) throw(); 
# 242
extern "C" long double y1l(long double) throw(); extern "C" long double __y1l(long double) throw(); 
# 243
extern "C" long double ynl(int, long double) throw(); extern "C" long double __ynl(int, long double) throw(); 
# 250
extern "C" long double erfl(long double) throw(); extern "C" long double __erfl(long double) throw(); 
# 251
extern "C" long double erfcl(long double) throw(); extern "C" long double __erfcl(long double) throw(); 
# 252
extern "C" long double lgammal(long double) throw(); extern "C" long double __lgammal(long double) throw(); 
# 259
extern "C" long double tgammal(long double) throw(); extern "C" long double __tgammal(long double) throw(); 
# 265
extern "C" long double gammal(long double) throw(); extern "C" long double __gammal(long double) throw(); 
# 272
extern "C" long double lgammal_r(long double, int *) throw(); extern "C" long double __lgammal_r(long double, int *) throw(); 
# 280
extern "C" long double rintl(long double) throw(); extern "C" long double __rintl(long double) throw(); 
# 283
extern "C" long double nextafterl(long double, long double) throw() __attribute__((__const__)); extern "C" long double __nextafterl(long double, long double) throw() __attribute__((__const__)); 
# 285
extern "C" long double nexttowardl(long double, long double) throw() __attribute__((__const__)); extern "C" long double __nexttowardl(long double, long double) throw() __attribute__((__const__)); 
# 289
extern "C" long double remainderl(long double, long double) throw(); extern "C" long double __remainderl(long double, long double) throw(); 
# 293
extern "C" long double scalbnl(long double, int) throw(); extern "C" long double __scalbnl(long double, int) throw(); 
# 297
extern "C" int ilogbl(long double) throw(); extern "C" int __ilogbl(long double) throw(); 
# 302
extern "C" long double scalblnl(long double, long) throw(); extern "C" long double __scalblnl(long double, long) throw(); 
# 306
extern "C" long double nearbyintl(long double) throw(); extern "C" long double __nearbyintl(long double) throw(); 
# 310
extern "C" long double roundl(long double) throw() __attribute__((__const__)); extern "C" long double __roundl(long double) throw() __attribute__((__const__)); 
# 314
extern "C" long double truncl(long double) throw() __attribute__((__const__)); extern "C" long double __truncl(long double) throw() __attribute__((__const__)); 
# 319
extern "C" long double remquol(long double, long double, int *) throw(); extern "C" long double __remquol(long double, long double, int *) throw(); 
# 326
extern "C" long lrintl(long double) throw(); extern "C" long __lrintl(long double) throw(); 
# 327
extern "C" long long llrintl(long double) throw(); extern "C" long long __llrintl(long double) throw(); 
# 331
extern "C" long lroundl(long double) throw(); extern "C" long __lroundl(long double) throw(); 
# 332
extern "C" long long llroundl(long double) throw(); extern "C" long long __llroundl(long double) throw(); 
# 336
extern "C" long double fdiml(long double, long double) throw(); extern "C" long double __fdiml(long double, long double) throw(); 
# 339
extern "C" long double fmaxl(long double, long double) throw(); extern "C" long double __fmaxl(long double, long double) throw(); 
# 342
extern "C" long double fminl(long double, long double) throw(); extern "C" long double __fminl(long double, long double) throw(); 
# 346
extern "C" int __fpclassifyl(long double) throw() __attribute__((__const__)); 
# 350
extern "C"  __attribute__((weak)) int __signbitl(long double) throw() __attribute__((__const__)); 
# 355
extern "C" long double fmal(long double, long double, long double) throw(); extern "C" long double __fmal(long double, long double, long double) throw(); 
# 364
extern "C" long double scalbl(long double, long double) throw(); extern "C" long double __scalbl(long double, long double) throw(); 
# 157 "/usr/include/math.h" 3
extern "C" { extern int signgam; } 
# 199
enum { 
# 200
FP_NAN, 
# 202
FP_INFINITE, 
# 204
FP_ZERO, 
# 206
FP_SUBNORMAL, 
# 208
FP_NORMAL
# 210
}; 
# 291 "/usr/include/math.h" 3
extern "C" { typedef 
# 285
enum { 
# 286
_IEEE_ = (-1), 
# 287
_SVID_, 
# 288
_XOPEN_, 
# 289
_POSIX_, 
# 290
_ISOC_
# 291
} _LIB_VERSION_TYPE; }
# 296
extern "C" { extern _LIB_VERSION_TYPE _LIB_VERSION; } 
# 307
extern "C" { struct __exception { 
# 312
int type; 
# 313
char *name; 
# 314
double arg1; 
# 315
double arg2; 
# 316
double retval; 
# 317
}; }
# 320
extern "C" int matherr(__exception *) throw(); 
# 67 "/usr/include/bits/waitstatus.h" 3
extern "C" { union wait { 
# 69
int w_status; 
# 71
struct { 
# 73
unsigned __w_termsig:7; 
# 74
unsigned __w_coredump:1; 
# 75
unsigned __w_retcode:8; 
# 76
unsigned:16; 
# 84
} __wait_terminated; 
# 86
struct { 
# 88
unsigned __w_stopval:8; 
# 89
unsigned __w_stopsig:8; 
# 90
unsigned:16; 
# 97
} __wait_stopped; 
# 98
}; }
# 102 "/usr/include/stdlib.h" 3
extern "C" { typedef 
# 99
struct { 
# 100
int quot; 
# 101
int rem; 
# 102
} div_t; }
# 110
extern "C" { typedef 
# 107
struct { 
# 108
long quot; 
# 109
long rem; 
# 110
} ldiv_t; }
# 122
extern "C" { typedef 
# 119
struct { 
# 120
long long quot; 
# 121
long long rem; 
# 122
} lldiv_t; }
# 140
extern "C" size_t __ctype_get_mb_cur_max() throw(); 
# 145
extern "C" double atof(const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))); 
# 148
extern "C" int atoi(const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))); 
# 151
extern "C" long atol(const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))); 
# 158
extern "C" long long atoll(const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))); 
# 165
extern "C" double strtod(const char *__restrict__, char **__restrict__) throw() __attribute__((nonnull(1))); 
# 173
extern "C" float strtof(const char *__restrict__, char **__restrict__) throw() __attribute__((nonnull(1))); 
# 176
extern "C" long double strtold(const char *__restrict__, char **__restrict__) throw() __attribute__((nonnull(1))); 
# 184
extern "C" long strtol(const char *__restrict__, char **__restrict__, int) throw() __attribute__((nonnull(1))); 
# 188
extern "C" unsigned long strtoul(const char *__restrict__, char **__restrict__, int) throw() __attribute__((nonnull(1))); 
# 196
extern "C" long long strtoq(const char *__restrict__, char **__restrict__, int) throw() __attribute__((nonnull(1))); 
# 201
extern "C" unsigned long long strtouq(const char *__restrict__, char **__restrict__, int) throw() __attribute__((nonnull(1))); 
# 210
extern "C" long long strtoll(const char *__restrict__, char **__restrict__, int) throw() __attribute__((nonnull(1))); 
# 215
extern "C" unsigned long long strtoull(const char *__restrict__, char **__restrict__, int) throw() __attribute__((nonnull(1))); 
# 240 "/usr/include/stdlib.h" 3
extern "C" long strtol_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(4))); 
# 244
extern "C" unsigned long strtoul_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(4))); 
# 250
extern "C" long long strtoll_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(4))); 
# 256
extern "C" unsigned long long strtoull_l(const char *__restrict__, char **__restrict__, int, __locale_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(4))); 
# 261
extern "C" double strtod_l(const char *__restrict__, char **__restrict__, __locale_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(3))); 
# 265
extern "C" float strtof_l(const char *__restrict__, char **__restrict__, __locale_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(3))); 
# 269
extern "C" long double strtold_l(const char *__restrict__, char **__restrict__, __locale_t) throw() __attribute__((nonnull(1))) __attribute__((nonnull(3))); 
# 311 "/usr/include/stdlib.h" 3
extern "C" char *l64a(long) throw(); 
# 314
extern "C" long a64l(const char *) throw() __attribute__((__pure__)) __attribute__((nonnull(1))); 
# 35 "/usr/include/sys/types.h" 3
extern "C" { typedef __u_char u_char; }
# 36
extern "C" { typedef __u_short u_short; }
# 37
extern "C" { typedef __u_int u_int; }
# 38
extern "C" { typedef __u_long u_long; }
# 39
extern "C" { typedef __quad_t quad_t; }
# 40
extern "C" { typedef __u_quad_t u_quad_t; }
# 41
extern "C" { typedef __fsid_t fsid_t; }
# 46
extern "C" { typedef __loff_t loff_t; }
# 50
extern "C" { typedef __ino_t ino_t; }
# 57
extern "C" { typedef __ino64_t ino64_t; }
# 62
extern "C" { typedef __dev_t dev_t; }
# 67
extern "C" { typedef __gid_t gid_t; }
# 72
extern "C" { typedef __mode_t mode_t; }
# 77
extern "C" { typedef __nlink_t nlink_t; }
# 82
extern "C" { typedef __uid_t uid_t; }
# 88
extern "C" { typedef __off_t off_t; }
# 95
extern "C" { typedef __off64_t off64_t; }
# 105 "/usr/include/sys/types.h" 3
extern "C" { typedef __id_t id_t; }
# 110
extern "C" { typedef __ssize_t ssize_t; }
# 116
extern "C" { typedef __daddr_t daddr_t; }
# 117
extern "C" { typedef __caddr_t caddr_t; }
# 123
extern "C" { typedef __key_t key_t; }
# 137 "/usr/include/sys/types.h" 3
extern "C" { typedef __useconds_t useconds_t; }
# 141
extern "C" { typedef __suseconds_t suseconds_t; }
# 151 "/usr/include/sys/types.h" 3
extern "C" { typedef unsigned long ulong; }
# 152
extern "C" { typedef unsigned short ushort; }
# 153
extern "C" { typedef unsigned uint; }
# 195 "/usr/include/sys/types.h" 3
extern "C" { typedef signed char int8_t; }
# 196
extern "C" { typedef short int16_t; }
# 197
extern "C" { typedef int int32_t; }
# 198
extern "C" { typedef long int64_t; }
# 201
extern "C" { typedef unsigned char u_int8_t; }
# 202
extern "C" { typedef unsigned short u_int16_t; }
# 203
extern "C" { typedef unsigned u_int32_t; }
# 204
extern "C" { typedef unsigned long u_int64_t; }
# 206
extern "C" { typedef int register_t; }
# 24 "/usr/include/bits/sigset.h" 3
extern "C" { typedef int __sig_atomic_t; }
# 32
extern "C" { typedef 
# 30
struct { 
# 31
unsigned long __val[((1024) / ((8) * sizeof(unsigned long)))]; 
# 32
} __sigset_t; }
# 38 "/usr/include/sys/select.h" 3
extern "C" { typedef __sigset_t sigset_t; }
# 69 "/usr/include/bits/time.h" 3
extern "C" { struct timeval { 
# 71
__time_t tv_sec; 
# 72
__suseconds_t tv_usec; 
# 73
}; }
# 55 "/usr/include/sys/select.h" 3
extern "C" { typedef long __fd_mask; }
# 78
extern "C" { typedef 
# 68
struct { 
# 72
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
extern "C" unsigned gnu_dev_major(unsigned long long) throw(); 
# 34
extern "C" unsigned gnu_dev_minor(unsigned long long) throw(); 
# 37
extern "C" unsigned long long gnu_dev_makedev(unsigned, unsigned) throw(); 
# 228 "/usr/include/sys/types.h" 3
extern "C" { typedef __blksize_t blksize_t; }
# 235
extern "C" { typedef __blkcnt_t blkcnt_t; }
# 239
extern "C" { typedef __fsblkcnt_t fsblkcnt_t; }
# 243
extern "C" { typedef __fsfilcnt_t fsfilcnt_t; }
# 262 "/usr/include/sys/types.h" 3
extern "C" { typedef __blkcnt64_t blkcnt64_t; }
# 263
extern "C" { typedef __fsblkcnt64_t fsblkcnt64_t; }
# 264
extern "C" { typedef __fsfilcnt64_t fsfilcnt64_t; }
# 50 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef unsigned long pthread_t; }
# 57
extern "C" { typedef 
# 54
union { 
# 55
char __size[56]; 
# 56
long __align; 
# 57
} pthread_attr_t; }
# 65
extern "C" { typedef 
# 61
struct __pthread_internal_list { 
# 63
__pthread_internal_list *__prev; 
# 64
__pthread_internal_list *__next; 
# 65
} __pthread_list_t; }
# 104 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef 
# 77 "/usr/include/bits/pthreadtypes.h" 3
union { 
# 78
struct __pthread_mutex_s { 
# 80
int __lock; 
# 81
unsigned __count; 
# 82
int __owner; 
# 84
unsigned __nusers; 
# 88
int __kind; 
# 90
int __spins; 
# 91
__pthread_list_t __list; 
# 101 "/usr/include/bits/pthreadtypes.h" 3
} __data; 
# 102
char __size[40]; 
# 103
long __align; 
# 104
} pthread_mutex_t; }
# 110
extern "C" { typedef 
# 107
union { 
# 108
char __size[4]; 
# 109
int __align; 
# 110
} pthread_mutexattr_t; }
# 130
extern "C" { typedef 
# 116
union { 
# 118
struct { 
# 119
int __lock; 
# 120
unsigned __futex; 
# 121
__extension__ unsigned long long __total_seq; 
# 122
__extension__ unsigned long long __wakeup_seq; 
# 123
__extension__ unsigned long long __woken_seq; 
# 124
void *__mutex; 
# 125
unsigned __nwaiters; 
# 126
unsigned __broadcast_seq; 
# 127
} __data; 
# 128
char __size[48]; 
# 129
__extension__ long long __align; 
# 130
} pthread_cond_t; }
# 136
extern "C" { typedef 
# 133
union { 
# 134
char __size[4]; 
# 135
int __align; 
# 136
} pthread_condattr_t; }
# 140
extern "C" { typedef unsigned pthread_key_t; }
# 144
extern "C" { typedef int pthread_once_t; }
# 189 "/usr/include/bits/pthreadtypes.h" 3
extern "C" { typedef 
# 151 "/usr/include/bits/pthreadtypes.h" 3
union { 
# 154
struct { 
# 155
int __lock; 
# 156
unsigned __nr_readers; 
# 157
unsigned __readers_wakeup; 
# 158
unsigned __writer_wakeup; 
# 159
unsigned __nr_readers_queued; 
# 160
unsigned __nr_writers_queued; 
# 161
int __writer; 
# 162
int __shared; 
# 163
unsigned long __pad1; 
# 164
unsigned long __pad2; 
# 167
unsigned __flags; 
# 168
} __data; 
# 187 "/usr/include/bits/pthreadtypes.h" 3
char __size[56]; 
# 188
long __align; 
# 189
} pthread_rwlock_t; }
# 195
extern "C" { typedef 
# 192
union { 
# 193
char __size[8]; 
# 194
long __align; 
# 195
} pthread_rwlockattr_t; }
# 201
extern "C" { typedef volatile int pthread_spinlock_t; }
# 210
extern "C" { typedef 
# 207
union { 
# 208
char __size[32]; 
# 209
long __align; 
# 210
} pthread_barrier_t; }
# 216
extern "C" { typedef 
# 213
union { 
# 214
char __size[4]; 
# 215
int __align; 
# 216
} pthread_barrierattr_t; }
# 327 "/usr/include/stdlib.h" 3
extern "C" long random() throw(); 
# 330
extern "C" void srandom(unsigned) throw(); 
# 336
extern "C" char *initstate(unsigned, char *, size_t) throw() __attribute__((nonnull(2))); 
# 341
extern "C" char *setstate(char *) throw() __attribute__((nonnull(1))); 
# 349
extern "C" { struct random_data { 
# 351
int32_t *fptr; 
# 352
int32_t *rptr; 
# 353
int32_t *state; 
# 354
int rand_type; 
# 355
int rand_deg; 
# 356
int rand_sep; 
# 357
int32_t *end_ptr; 
# 358
}; }
# 360
extern "C" int random_r(random_data *__restrict__, int32_t *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 363
extern "C" int srandom_r(unsigned, random_data *) throw() __attribute__((nonnull(2))); 
# 366
extern "C" int initstate_r(unsigned, char *__restrict__, size_t, random_data *__restrict__) throw() __attribute__((nonnull(2))) __attribute__((nonnull(4))); 
# 371
extern "C" int setstate_r(char *__restrict__, random_data *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 380
extern "C" int rand() throw(); 
# 382
extern "C" void srand(unsigned) throw(); 
# 387
extern "C" int rand_r(unsigned *) throw(); 
# 395
extern "C" double drand48() throw(); 
# 396
extern "C" double erand48(unsigned short [3]) throw() __attribute__((nonnull(1))); 
# 399
extern "C" long lrand48() throw(); 
# 400
extern "C" long nrand48(unsigned short [3]) throw() __attribute__((nonnull(1))); 
# 404
extern "C" long mrand48() throw(); 
# 405
extern "C" long jrand48(unsigned short [3]) throw() __attribute__((nonnull(1))); 
# 409
extern "C" void srand48(long) throw(); 
# 410
extern "C" unsigned short *seed48(unsigned short [3]) throw() __attribute__((nonnull(1))); 
# 412
extern "C" void lcong48(unsigned short [7]) throw() __attribute__((nonnull(1))); 
# 418
extern "C" { struct drand48_data { 
# 420
unsigned short __x[3]; 
# 421
unsigned short __old_x[3]; 
# 422
unsigned short __c; 
# 423
unsigned short __init; 
# 424
unsigned long long __a; 
# 425
}; }
# 428
extern "C" int drand48_r(drand48_data *__restrict__, double *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 430
extern "C" int erand48_r(unsigned short [3], drand48_data *__restrict__, double *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 435
extern "C" int lrand48_r(drand48_data *__restrict__, long *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 438
extern "C" int nrand48_r(unsigned short [3], drand48_data *__restrict__, long *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 444
extern "C" int mrand48_r(drand48_data *__restrict__, long *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 447
extern "C" int jrand48_r(unsigned short [3], drand48_data *__restrict__, long *__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 453
extern "C" int srand48_r(long, drand48_data *) throw() __attribute__((nonnull(2))); 
# 456
extern "C" int seed48_r(unsigned short [3], drand48_data *) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 459
extern "C" int lcong48_r(unsigned short [7], drand48_data *) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))); 
# 471
extern "C" void *malloc(size_t) throw() __attribute__((__malloc__)); 
# 473
extern "C" void *calloc(size_t, size_t) throw() __attribute__((__malloc__)); 
# 485
extern "C" void *realloc(void *, size_t) throw() __attribute__((__warn_unused_result__)); 
# 488
extern "C" void free(void *) throw(); 
# 493
extern "C" void cfree(void *) throw(); 
# 33 "/usr/include/alloca.h" 3
extern "C" void *alloca(size_t) throw(); 
# 502 "/usr/include/stdlib.h" 3
extern "C" void *valloc(size_t) throw() __attribute__((__malloc__)); 
# 507
extern "C" int posix_memalign(void **, size_t, size_t) throw() __attribute__((nonnull(1))); 
# 513
extern "C" void abort() throw() __attribute__((__noreturn__)); 
# 517
extern "C" int atexit(void (*)(void)) throw() __attribute__((nonnull(1))); 
# 523
extern "C" int on_exit(void (*)(int, void *), void *) throw() __attribute__((nonnull(1))); 
# 531
extern "C" void exit(int) throw() __attribute__((__noreturn__)); 
# 538
extern "C" void _Exit(int) throw() __attribute__((__noreturn__)); 
# 545
extern "C" char *getenv(const char *) throw() __attribute__((nonnull(1))); 
# 550
extern "C" char *__secure_getenv(const char *) throw() __attribute__((nonnull(1))); 
# 557
extern "C" int putenv(char *) throw() __attribute__((nonnull(1))); 
# 563
extern "C" int setenv(const char *, const char *, int) throw() __attribute__((nonnull(2))); 
# 567
extern "C" int unsetenv(const char *) throw(); 
# 574
extern "C" int clearenv() throw(); 
# 583
extern "C" char *mktemp(char *) throw() __attribute__((nonnull(1))); 
# 594
extern "C" int mkstemp(char *) __attribute__((nonnull(1))); 
# 604 "/usr/include/stdlib.h" 3
extern "C" int mkstemp64(char *) __attribute__((nonnull(1))); 
# 614
extern "C" char *mkdtemp(char *) throw() __attribute__((nonnull(1))); 
# 625
extern "C" int mkostemp(char *, int) __attribute__((nonnull(1))); 
# 635 "/usr/include/stdlib.h" 3
extern "C" int mkostemp64(char *, int) __attribute__((nonnull(1))); 
# 645
extern "C" int system(const char *); 
# 652
extern "C" char *canonicalize_file_name(const char *) throw() __attribute__((nonnull(1))); 
# 662
extern "C" char *realpath(const char *__restrict__, char *__restrict__) throw(); 
# 670
extern "C" { typedef int (*__compar_fn_t)(const void *, const void *); }
# 673
extern "C" { typedef __compar_fn_t comparison_fn_t; }
# 680
extern "C" void *bsearch(const void *, const void *, size_t, size_t, __compar_fn_t) __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(5))); 
# 686
extern "C" void qsort(void *, size_t, size_t, __compar_fn_t) __attribute__((nonnull(1))) __attribute__((nonnull(4))); 
# 691
extern "C"  __attribute__((weak)) int abs(int) throw() __attribute__((__const__)); 
# 692
extern "C"  __attribute__((weak)) long labs(long) throw() __attribute__((__const__)); 
# 696
extern "C"  __attribute__((weak)) long long llabs(long long) throw() __attribute__((__const__)); 
# 705
extern "C" div_t div(int, int) throw() __attribute__((__const__)); 
# 707
extern "C" ldiv_t ldiv(long, long) throw() __attribute__((__const__)); 
# 713
extern "C" lldiv_t lldiv(long long, long long) throw() __attribute__((__const__)); 
# 727
extern "C" char *ecvt(double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))); 
# 733
extern "C" char *fcvt(double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))); 
# 739
extern "C" char *gcvt(double, int, char *) throw() __attribute__((nonnull(3))); 
# 745
extern "C" char *qecvt(long double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))); 
# 748
extern "C" char *qfcvt(long double, int, int *__restrict__, int *__restrict__) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))); 
# 751
extern "C" char *qgcvt(long double, int, char *) throw() __attribute__((nonnull(3))); 
# 757
extern "C" int ecvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5))); 
# 760
extern "C" int fcvt_r(double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5))); 
# 764
extern "C" int qecvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5))); 
# 768
extern "C" int qfcvt_r(long double, int, int *__restrict__, int *__restrict__, char *__restrict__, size_t) throw() __attribute__((nonnull(3))) __attribute__((nonnull(4))) __attribute__((nonnull(5))); 
# 779
extern "C" int mblen(const char *, size_t) throw(); 
# 782
extern "C" int mbtowc(wchar_t *__restrict__, const char *__restrict__, size_t) throw(); 
# 786
extern "C" int wctomb(char *, wchar_t) throw(); 
# 790
extern "C" size_t mbstowcs(wchar_t *__restrict__, const char *__restrict__, size_t) throw(); 
# 793
extern "C" size_t wcstombs(char *__restrict__, const wchar_t *__restrict__, size_t) throw(); 
# 804
extern "C" int rpmatch(const char *) throw() __attribute__((nonnull(1))); 
# 815
extern "C" int getsubopt(char **__restrict__, char *const *__restrict__, char **__restrict__) throw() __attribute__((nonnull(1))) __attribute__((nonnull(2))) __attribute__((nonnull(3))); 
# 824
extern "C" void setkey(const char *) throw() __attribute__((nonnull(1))); 
# 832
extern "C" int posix_openpt(int); 
# 840
extern "C" int grantpt(int) throw(); 
# 844
extern "C" int unlockpt(int) throw(); 
# 849
extern "C" char *ptsname(int) throw(); 
# 856
extern "C" int ptsname_r(int, char *, size_t) throw() __attribute__((nonnull(2))); 
# 860
extern "C" int getpt(); 
# 867
extern "C" int getloadavg(double [], int) throw() __attribute__((nonnull(1))); 
# 149 "/usr/include/c++/4.2/x86_64-linux-gnu/bits/c++config.h" 3
namespace std __attribute__((visibility("default"))) { 
# 161 "/usr/include/c++/4.2/x86_64-linux-gnu/bits/c++config.h" 3
}
# 74 "/usr/include/c++/4.2/bits/cpp_type_traits.h" 3
namespace __gnu_cxx __attribute__((visibility("default"))) { 
# 76
template<class _Iterator, class _Container> class __normal_iterator; 
# 79
}
# 81
namespace std __attribute__((visibility("default"))) { 
# 83
namespace __detail { 
# 87
typedef char __one; 
# 88
typedef char __two[2]; 
# 90
template<class _Tp> __one __test_type(int _Tp::*); 
# 92
template<class _Tp> __two &__test_type(...); 
# 94
}
# 97
struct __true_type { }; 
# 98
struct __false_type { }; 
# 100
template<bool __T0> 
# 101
struct __truth_type { 
# 102
typedef __false_type __type; }; 
# 105
template<> struct __truth_type< true>  { 
# 106
typedef __true_type __type; }; 
# 110
template<class _Sp, class _Tp> 
# 111
struct __traitor { 
# 113
enum { __value = (((bool)_Sp::__value) || ((bool)_Tp::__value))}; 
# 114
typedef typename __truth_type< __value> ::__type __type; 
# 115
}; 
# 118
template<class , class > 
# 119
struct __are_same { 
# 121
enum { __value}; 
# 122
typedef __false_type __type; 
# 123
}; 
# 125
template<class _Tp> 
# 126
struct __are_same< _Tp, _Tp>  { 
# 128
enum { __value = 1}; 
# 129
typedef __true_type __type; 
# 130
}; 
# 133
template<class _Tp> 
# 134
struct __is_void { 
# 136
enum { __value}; 
# 137
typedef __false_type __type; 
# 138
}; 
# 141
template<> struct __is_void< void>  { 
# 143
enum { __value = 1}; 
# 144
typedef __true_type __type; 
# 145
}; 
# 150
template<class _Tp> 
# 151
struct __is_integer { 
# 153
enum { __value}; 
# 154
typedef __false_type __type; 
# 155
}; 
# 161
template<> struct __is_integer< bool>  { 
# 163
enum { __value = 1}; 
# 164
typedef __true_type __type; 
# 165
}; 
# 168
template<> struct __is_integer< char>  { 
# 170
enum { __value = 1}; 
# 171
typedef __true_type __type; 
# 172
}; 
# 175
template<> struct __is_integer< signed char>  { 
# 177
enum { __value = 1}; 
# 178
typedef __true_type __type; 
# 179
}; 
# 182
template<> struct __is_integer< unsigned char>  { 
# 184
enum { __value = 1}; 
# 185
typedef __true_type __type; 
# 186
}; 
# 190
template<> struct __is_integer< wchar_t>  { 
# 192
enum { __value = 1}; 
# 193
typedef __true_type __type; 
# 194
}; 
# 198
template<> struct __is_integer< short>  { 
# 200
enum { __value = 1}; 
# 201
typedef __true_type __type; 
# 202
}; 
# 205
template<> struct __is_integer< unsigned short>  { 
# 207
enum { __value = 1}; 
# 208
typedef __true_type __type; 
# 209
}; 
# 212
template<> struct __is_integer< int>  { 
# 214
enum { __value = 1}; 
# 215
typedef __true_type __type; 
# 216
}; 
# 219
template<> struct __is_integer< unsigned>  { 
# 221
enum { __value = 1}; 
# 222
typedef __true_type __type; 
# 223
}; 
# 226
template<> struct __is_integer< long>  { 
# 228
enum { __value = 1}; 
# 229
typedef __true_type __type; 
# 230
}; 
# 233
template<> struct __is_integer< unsigned long>  { 
# 235
enum { __value = 1}; 
# 236
typedef __true_type __type; 
# 237
}; 
# 240
template<> struct __is_integer< long long>  { 
# 242
enum { __value = 1}; 
# 243
typedef __true_type __type; 
# 244
}; 
# 247
template<> struct __is_integer< unsigned long long>  { 
# 249
enum { __value = 1}; 
# 250
typedef __true_type __type; 
# 251
}; 
# 256
template<class _Tp> 
# 257
struct __is_floating { 
# 259
enum { __value}; 
# 260
typedef __false_type __type; 
# 261
}; 
# 265
template<> struct __is_floating< float>  { 
# 267
enum { __value = 1}; 
# 268
typedef __true_type __type; 
# 269
}; 
# 272
template<> struct __is_floating< double>  { 
# 274
enum { __value = 1}; 
# 275
typedef __true_type __type; 
# 276
}; 
# 279
template<> struct __is_floating< long double>  { 
# 281
enum { __value = 1}; 
# 282
typedef __true_type __type; 
# 283
}; 
# 288
template<class _Tp> 
# 289
struct __is_pointer { 
# 291
enum { __value}; 
# 292
typedef __false_type __type; 
# 293
}; 
# 295
template<class _Tp> 
# 296
struct __is_pointer< _Tp *>  { 
# 298
enum { __value = 1}; 
# 299
typedef __true_type __type; 
# 300
}; 
# 305
template<class _Tp> 
# 306
struct __is_normal_iterator { 
# 308
enum { __value}; 
# 309
typedef __false_type __type; 
# 310
}; 
# 312
template<class _Iterator, class _Container> 
# 313
struct __is_normal_iterator< __gnu_cxx::__normal_iterator< _Iterator, _Container> >  { 
# 316
enum { __value = 1}; 
# 317
typedef __true_type __type; 
# 318
}; 
# 323
template<class _Tp> 
# 324
struct __is_arithmetic : public __traitor< __is_integer< _Tp> , __is_floating< _Tp> >  { 
# 326
}; 
# 331
template<class _Tp> 
# 332
struct __is_fundamental : public __traitor< __is_void< _Tp> , __is_arithmetic< _Tp> >  { 
# 334
}; 
# 339
template<class _Tp> 
# 340
struct __is_scalar : public __traitor< __is_arithmetic< _Tp> , __is_pointer< _Tp> >  { 
# 342
}; 
# 345
template<class _Tp> 
# 346
struct __is_pod { 
# 349
enum { 
# 350
__value = (sizeof(__detail::__test_type< _Tp> (0)) != sizeof(__detail::__one))
# 352
}; 
# 353
}; 
# 358
template<class _Tp> 
# 359
struct __is_empty { 
# 363
private: 
# 362
template<class > 
# 363
struct __first { }; 
# 364
template<class _Up> 
# 365
struct __second : public _Up { 
# 366
}; 
# 370
public: enum { 
# 371
__value = (sizeof(__first< _Tp> ) == sizeof(__second< _Tp> ))
# 372
}; 
# 373
}; 
# 378
template<class _Tp> 
# 379
struct __is_char { 
# 381
enum { __value}; 
# 382
typedef __false_type __type; 
# 383
}; 
# 386
template<> struct __is_char< char>  { 
# 388
enum { __value = 1}; 
# 389
typedef __true_type __type; 
# 390
}; 
# 394
template<> struct __is_char< wchar_t>  { 
# 396
enum { __value = 1}; 
# 397
typedef __true_type __type; 
# 398
}; 
# 401
}
# 53 "/usr/include/c++/4.2/cstddef" 3
namespace std __attribute__((visibility("default"))) { 
# 55
using ::ptrdiff_t;
# 56
using ::size_t;
# 58
}
# 74 "/usr/include/c++/4.2/bits/stl_relops.h" 3
namespace std __attribute__((visibility("default"))) { 
# 76
namespace rel_ops { 
# 90
template < class _Tp >
      inline bool
      operator != ( const _Tp & __x, const _Tp & __y )
      { return ! ( __x == __y ); }
# 103
template < class _Tp >
      inline bool
      operator > ( const _Tp & __x, const _Tp & __y )
      { return __y < __x; }
# 116
template < class _Tp >
      inline bool
      operator <= ( const _Tp & __x, const _Tp & __y )
      { return ! ( __y < __x ); }
# 129
template < class _Tp >
      inline bool
      operator >= ( const _Tp & __x, const _Tp & __y )
      { return ! ( __x < __y ); }
# 134
}
# 136
}
# 64 "/usr/include/c++/4.2/bits/stl_pair.h" 3
namespace std __attribute__((visibility("default"))) { 
# 67
template < class _T1, class _T2 >
    struct pair
    {
      typedef _T1 first_type;
      typedef _T2 second_type;

      _T1 first;
      _T2 second;





      pair ( )
      : first ( ), second ( ) { }


      pair ( const _T1 & __a, const _T2 & __b )
      : first ( __a ), second ( __b ) { }


      template < class _U1, class _U2 >
        pair ( const pair < _U1, _U2 > & __p )
 : first ( __p . first ), second ( __p . second ) { }
    };
# 94
template < class _T1, class _T2 >
    inline bool
    operator == ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return __x . first == __y . first && __x . second == __y . second; }
# 100
template < class _T1, class _T2 >
    inline bool
    operator < ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return __x . first < __y . first
      || ( ! ( __y . first < __x . first ) && __x . second < __y . second ); }
# 107
template < class _T1, class _T2 >
    inline bool
    operator != ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return ! ( __x == __y ); }
# 113
template < class _T1, class _T2 >
    inline bool
    operator > ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return __y < __x; }
# 119
template < class _T1, class _T2 >
    inline bool
    operator <= ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return ! ( __y < __x ); }
# 125
template < class _T1, class _T2 >
    inline bool
    operator >= ( const pair < _T1, _T2 > & __x, const pair < _T1, _T2 > & __y )
    { return ! ( __x < __y ); }
# 142
template < class _T1, class _T2 >
    inline pair < _T1, _T2 >
    make_pair ( _T1 __x, _T2 __y )
    { return pair < _T1, _T2 > ( __x, __y ); }
# 147
}
# 44 "/usr/include/c++/4.2/ext/type_traits.h" 3
namespace __gnu_cxx __attribute__((visibility("default"))) { 
# 47
template<bool __T1, class > 
# 48
struct __enable_if { 
# 49
}; 
# 51
template<class _Tp> 
# 52
struct __enable_if< true, _Tp>  { 
# 53
typedef _Tp __type; }; 
# 57
template<bool _Cond, class _Iftrue, class _Iffalse> 
# 58
struct __conditional_type { 
# 59
typedef _Iftrue __type; }; 
# 61
template<class _Iftrue, class _Iffalse> 
# 62
struct __conditional_type< false, _Iftrue, _Iffalse>  { 
# 63
typedef _Iffalse __type; }; 
# 67
template<class _Tp> 
# 68
struct __add_unsigned { 
# 71
private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp>  __if_type; 
# 74
public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type; 
# 75
}; 
# 78
template<> struct __add_unsigned< char>  { 
# 79
typedef unsigned char __type; }; 
# 82
template<> struct __add_unsigned< signed char>  { 
# 83
typedef unsigned char __type; }; 
# 86
template<> struct __add_unsigned< short>  { 
# 87
typedef unsigned short __type; }; 
# 90
template<> struct __add_unsigned< int>  { 
# 91
typedef unsigned __type; }; 
# 94
template<> struct __add_unsigned< long>  { 
# 95
typedef unsigned long __type; }; 
# 98
template<> struct __add_unsigned< long long>  { 
# 99
typedef unsigned long long __type; }; 
# 103
template<> struct __add_unsigned< bool> ; 
# 106
template<> struct __add_unsigned< wchar_t> ; 
# 110
template<class _Tp> 
# 111
struct __remove_unsigned { 
# 114
private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp>  __if_type; 
# 117
public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type; 
# 118
}; 
# 121
template<> struct __remove_unsigned< char>  { 
# 122
typedef signed char __type; }; 
# 125
template<> struct __remove_unsigned< unsigned char>  { 
# 126
typedef signed char __type; }; 
# 129
template<> struct __remove_unsigned< unsigned short>  { 
# 130
typedef short __type; }; 
# 133
template<> struct __remove_unsigned< unsigned>  { 
# 134
typedef int __type; }; 
# 137
template<> struct __remove_unsigned< unsigned long>  { 
# 138
typedef long __type; }; 
# 141
template<> struct __remove_unsigned< unsigned long long>  { 
# 142
typedef long long __type; }; 
# 146
template<> struct __remove_unsigned< bool> ; 
# 149
template<> struct __remove_unsigned< wchar_t> ; 
# 151
}
# 82 "/usr/include/c++/4.2/cmath" 3
namespace std __attribute__((visibility("default"))) { 
# 86
template < typename _Tp > _Tp __cmath_power ( _Tp, unsigned int );
# 89
inline double abs(double __x) 
# 90
{ return __builtin_fabs(__x); } 
# 93
inline float abs(float __x) 
# 94
{ return __builtin_fabsf(__x); } 
# 97
inline long double abs(long double __x) 
# 98
{ return __builtin_fabsl(__x); } 
# 100
using ::acos;
# 103
inline float acos(float __x) 
# 104
{ return __builtin_acosf(__x); } 
# 107
inline long double acos(long double __x) 
# 108
{ return __builtin_acosl(__x); } 
# 110
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    acos ( _Tp __x )
    { return __builtin_acos ( __x ); }
# 116
using ::asin;
# 119
inline float asin(float __x) 
# 120
{ return __builtin_asinf(__x); } 
# 123
inline long double asin(long double __x) 
# 124
{ return __builtin_asinl(__x); } 
# 126
template < typename _Tp >
  inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
      double > :: __type
    asin ( _Tp __x )
    { return __builtin_asin ( __x ); }
# 132
using ::atan;
# 135
inline float atan(float __x) 
# 136
{ return __builtin_atanf(__x); } 
# 139
inline long double atan(long double __x) 
# 140
{ return __builtin_atanl(__x); } 
# 142
template < typename _Tp >
  inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
      double > :: __type
    atan ( _Tp __x )
    { return __builtin_atan ( __x ); }
# 148
using ::atan2;
# 151
inline float atan2(float __y, float __x) 
# 152
{ return __builtin_atan2f(__y, __x); } 
# 155
inline long double atan2(long double __y, long double __x) 
# 156
{ return __builtin_atan2l(__y, __x); } 
# 158
template < typename _Tp, typename _Up >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value
            && __is_integer < _Up > :: __value,
        double > :: __type
    atan2 ( _Tp __y, _Up __x )
    { return __builtin_atan2 ( __y, __x ); }
# 165
using ::ceil;
# 168
inline float ceil(float __x) 
# 169
{ return __builtin_ceilf(__x); } 
# 172
inline long double ceil(long double __x) 
# 173
{ return __builtin_ceill(__x); } 
# 175
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    ceil ( _Tp __x )
    { return __builtin_ceil ( __x ); }
# 181
using ::cos;
# 184
inline float cos(float __x) 
# 185
{ return __builtin_cosf(__x); } 
# 188
inline long double cos(long double __x) 
# 189
{ return __builtin_cosl(__x); } 
# 191
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    cos ( _Tp __x )
    { return __builtin_cos ( __x ); }
# 197
using ::cosh;
# 200
inline float cosh(float __x) 
# 201
{ return __builtin_coshf(__x); } 
# 204
inline long double cosh(long double __x) 
# 205
{ return __builtin_coshl(__x); } 
# 207
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    cosh ( _Tp __x )
    { return __builtin_cosh ( __x ); }
# 213
using ::exp;
# 216
inline float exp(float __x) 
# 217
{ return __builtin_expf(__x); } 
# 220
inline long double exp(long double __x) 
# 221
{ return __builtin_expl(__x); } 
# 223
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    exp ( _Tp __x )
    { return __builtin_exp ( __x ); }
# 229
using ::fabs;
# 232
inline float fabs(float __x) 
# 233
{ return __builtin_fabsf(__x); } 
# 236
inline long double fabs(long double __x) 
# 237
{ return __builtin_fabsl(__x); } 
# 239
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    fabs ( _Tp __x )
    { return __builtin_fabs ( __x ); }
# 245
using ::floor;
# 248
inline float floor(float __x) 
# 249
{ return __builtin_floorf(__x); } 
# 252
inline long double floor(long double __x) 
# 253
{ return __builtin_floorl(__x); } 
# 255
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    floor ( _Tp __x )
    { return __builtin_floor ( __x ); }
# 261
using ::fmod;
# 264
inline float fmod(float __x, float __y) 
# 265
{ return __builtin_fmodf(__x, __y); } 
# 268
inline long double fmod(long double __x, long double __y) 
# 269
{ return __builtin_fmodl(__x, __y); } 
# 271
using ::frexp;
# 274
inline float frexp(float __x, int *__exp) 
# 275
{ return __builtin_frexpf(__x, __exp); } 
# 278
inline long double frexp(long double __x, int *__exp) 
# 279
{ return __builtin_frexpl(__x, __exp); } 
# 281
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    frexp ( _Tp __x, int * __exp )
    { return __builtin_frexp ( __x, __exp ); }
# 287
using ::ldexp;
# 290
inline float ldexp(float __x, int __exp) 
# 291
{ return __builtin_ldexpf(__x, __exp); } 
# 294
inline long double ldexp(long double __x, int __exp) 
# 295
{ return __builtin_ldexpl(__x, __exp); } 
# 297
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
  ldexp ( _Tp __x, int __exp )
  { return __builtin_ldexp ( __x, __exp ); }
# 303
using ::log;
# 306
inline float log(float __x) 
# 307
{ return __builtin_logf(__x); } 
# 310
inline long double log(long double __x) 
# 311
{ return __builtin_logl(__x); } 
# 313
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    log ( _Tp __x )
    { return __builtin_log ( __x ); }
# 319
using ::log10;
# 322
inline float log10(float __x) 
# 323
{ return __builtin_log10f(__x); } 
# 326
inline long double log10(long double __x) 
# 327
{ return __builtin_log10l(__x); } 
# 329
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    log10 ( _Tp __x )
    { return __builtin_log10 ( __x ); }
# 335
using ::modf;
# 338
inline float modf(float __x, float *__iptr) 
# 339
{ return __builtin_modff(__x, __iptr); } 
# 342
inline long double modf(long double __x, long double *__iptr) 
# 343
{ return __builtin_modfl(__x, __iptr); } 
# 345
template < typename _Tp >
    inline _Tp
    __pow_helper ( _Tp __x, int __n )
    {
      return __n < 0
        ? _Tp ( 1 ) / __cmath_power ( __x, - __n )
        : __cmath_power ( __x, __n );
    }
# 354
using ::pow;
# 357
inline float pow(float __x, float __y) 
# 358
{ return __builtin_powf(__x, __y); } 
# 361
inline long double pow(long double __x, long double __y) 
# 362
{ return __builtin_powl(__x, __y); } 
# 365
inline double pow(double __x, int __i) 
# 366
{ return __builtin_powi(__x, __i); } 
# 369
inline float pow(float __x, int __n) 
# 370
{ return __builtin_powif(__x, __n); } 
# 373
inline long double pow(long double __x, int __n) 
# 374
{ return __builtin_powil(__x, __n); } 
# 376
using ::sin;
# 379
inline float sin(float __x) 
# 380
{ return __builtin_sinf(__x); } 
# 383
inline long double sin(long double __x) 
# 384
{ return __builtin_sinl(__x); } 
# 386
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sin ( _Tp __x )
    { return __builtin_sin ( __x ); }
# 392
using ::sinh;
# 395
inline float sinh(float __x) 
# 396
{ return __builtin_sinhf(__x); } 
# 399
inline long double sinh(long double __x) 
# 400
{ return __builtin_sinhl(__x); } 
# 402
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sinh ( _Tp __x )
    { return __builtin_sinh ( __x ); }
# 408
using ::sqrt;
# 411
inline float sqrt(float __x) 
# 412
{ return __builtin_sqrtf(__x); } 
# 415
inline long double sqrt(long double __x) 
# 416
{ return __builtin_sqrtl(__x); } 
# 418
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    sqrt ( _Tp __x )
    { return __builtin_sqrt ( __x ); }
# 424
using ::tan;
# 427
inline float tan(float __x) 
# 428
{ return __builtin_tanf(__x); } 
# 431
inline long double tan(long double __x) 
# 432
{ return __builtin_tanl(__x); } 
# 434
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    tan ( _Tp __x )
    { return __builtin_tan ( __x ); }
# 440
using ::tanh;
# 443
inline float tanh(float __x) 
# 444
{ return __builtin_tanhf(__x); } 
# 447
inline long double tanh(long double __x) 
# 448
{ return __builtin_tanhl(__x); } 
# 450
template < typename _Tp >
    inline typename __gnu_cxx :: __enable_if < __is_integer < _Tp > :: __value,
        double > :: __type
    tanh ( _Tp __x )
    { return __builtin_tanh ( __x ); }
# 456
}
# 464
namespace __gnu_cxx __attribute__((visibility("default"))) { 
# 466
template < typename _Tp >
    inline int
    __capture_fpclassify ( _Tp __f ) { return ( sizeof ( __f ) == sizeof ( float ) ? __fpclassifyf ( __f ) : sizeof ( __f ) == sizeof ( double ) ? __fpclassify ( __f ) : __fpclassifyl ( __f ) ); }
# 470
template < typename _Tp >
    inline int
    __capture_isfinite ( _Tp __f ) { return ( sizeof ( __f ) == sizeof ( float ) ? __finitef ( __f ) : sizeof ( __f ) == sizeof ( double ) ? __finite ( __f ) : __finitel ( __f ) ); }
# 474
template < typename _Tp >
    inline int
    __capture_isinf ( _Tp __f ) { return ( sizeof ( __f ) == sizeof ( float ) ? __isinff ( __f ) : sizeof ( __f ) == sizeof ( double ) ? __isinf ( __f ) : __isinfl ( __f ) ); }
# 478
template < typename _Tp >
    inline int
    __capture_isnan ( _Tp __f ) { return ( sizeof ( __f ) == sizeof ( float ) ? __isnanf ( __f ) : sizeof ( __f ) == sizeof ( double ) ? __isnan ( __f ) : __isnanl ( __f ) ); }
# 482
template < typename _Tp >
    inline int
    __capture_isnormal ( _Tp __f ) { return ( ( sizeof ( __f ) == sizeof ( float ) ? __fpclassifyf ( __f ) : sizeof ( __f ) == sizeof ( double ) ? __fpclassify ( __f ) : __fpclassifyl ( __f ) ) == FP_NORMAL ); }
# 486
template < typename _Tp >
    inline int
    __capture_signbit ( _Tp __f ) { return ( sizeof ( __f ) == sizeof ( float ) ? __signbitf ( __f ) : sizeof ( __f ) == sizeof ( double ) ? __signbit ( __f ) : __signbitl ( __f ) ); }
# 490
template < typename _Tp >
    inline int
    __capture_isgreater ( _Tp __f1, _Tp __f2 )
    { return __builtin_isgreater ( __f1, __f2 ); }
# 495
template < typename _Tp >
    inline int
    __capture_isgreaterequal ( _Tp __f1, _Tp __f2 )
    { return __builtin_isgreaterequal ( __f1, __f2 ); }
# 500
template < typename _Tp >
    inline int
    __capture_isless ( _Tp __f1, _Tp __f2 ) { return __builtin_isless ( __f1, __f2 ); }
# 504
template < typename _Tp >
    inline int
    __capture_islessequal ( _Tp __f1, _Tp __f2 )
    { return __builtin_islessequal ( __f1, __f2 ); }
# 509
template < typename _Tp >
    inline int
    __capture_islessgreater ( _Tp __f1, _Tp __f2 )
    { return __builtin_islessgreater ( __f1, __f2 ); }
# 514
template < typename _Tp >
    inline int
    __capture_isunordered ( _Tp __f1, _Tp __f2 )
    { return __builtin_isunordered ( __f1, __f2 ); }
# 519
}
# 535 "/usr/include/c++/4.2/cmath" 3
namespace std __attribute__((visibility("default"))) { 
# 537
template < typename _Tp >
    inline int
    fpclassify ( _Tp __f ) { return :: __gnu_cxx :: __capture_fpclassify ( __f ); }
# 541
template < typename _Tp >
    inline int
    isfinite ( _Tp __f ) { return :: __gnu_cxx :: __capture_isfinite ( __f ); }
# 545
template < typename _Tp >
    inline int
    isinf ( _Tp __f ) { return :: __gnu_cxx :: __capture_isinf ( __f ); }
# 549
template < typename _Tp >
    inline int
    isnan ( _Tp __f ) { return :: __gnu_cxx :: __capture_isnan ( __f ); }
# 553
template < typename _Tp >
    inline int
    isnormal ( _Tp __f ) { return :: __gnu_cxx :: __capture_isnormal ( __f ); }
# 557
template < typename _Tp >
    inline int
    signbit ( _Tp __f ) { return :: __gnu_cxx :: __capture_signbit ( __f ); }
# 561
template < typename _Tp >
    inline int
    isgreater ( _Tp __f1, _Tp __f2 )
    { return :: __gnu_cxx :: __capture_isgreater ( __f1, __f2 ); }
# 566
template < typename _Tp >
    inline int
    isgreaterequal ( _Tp __f1, _Tp __f2 )
    { return :: __gnu_cxx :: __capture_isgreaterequal ( __f1, __f2 ); }
# 571
template < typename _Tp >
    inline int
    isless ( _Tp __f1, _Tp __f2 )
    { return :: __gnu_cxx :: __capture_isless ( __f1, __f2 ); }
# 576
template < typename _Tp >
    inline int
    islessequal ( _Tp __f1, _Tp __f2 )
    { return :: __gnu_cxx :: __capture_islessequal ( __f1, __f2 ); }
# 581
template < typename _Tp >
    inline int
    islessgreater ( _Tp __f1, _Tp __f2 )
    { return :: __gnu_cxx :: __capture_islessgreater ( __f1, __f2 ); }
# 586
template < typename _Tp >
    inline int
    isunordered ( _Tp __f1, _Tp __f2 )
    { return :: __gnu_cxx :: __capture_isunordered ( __f1, __f2 ); }
# 591
}
# 39 "/usr/include/c++/4.2/bits/cmath.tcc" 3
namespace std __attribute__((visibility("default"))) { 
# 41
template < typename _Tp >
    inline _Tp
    __cmath_power ( _Tp __x, unsigned int __n )
    {
      _Tp __y = __n % 2 ? __x : 1;

      while ( __n >>= 1 )
        {
          __x = __x * __x;
          if ( __n % 2 )
            __y = __y * __x;
        }

      return __y;
    }
# 57
}
# 104 "/usr/include/c++/4.2/cstdlib" 3
namespace std __attribute__((visibility("default"))) { 
# 106
using ::div_t;
# 107
using ::ldiv_t;
# 109
using ::abort;
# 110
using ::abs;
# 111
using ::atexit;
# 112
using ::atof;
# 113
using ::atoi;
# 114
using ::atol;
# 115
using ::bsearch;
# 116
using ::calloc;
# 117
using ::div;
# 118
using ::exit;
# 119
using ::free;
# 120
using ::getenv;
# 121
using ::labs;
# 122
using ::ldiv;
# 123
using ::malloc;
# 125
using ::mblen;
# 126
using ::mbstowcs;
# 127
using ::mbtowc;
# 129
using ::qsort;
# 130
using ::rand;
# 131
using ::realloc;
# 132
using ::srand;
# 133
using ::strtod;
# 134
using ::strtol;
# 135
using ::strtoul;
# 136
using ::system;
# 138
using ::wcstombs;
# 139
using ::wctomb;
# 143
inline long abs(long __i) { return labs(__i); } 
# 146
inline ldiv_t div(long __i, long __j) { return ldiv(__i, __j); } 
# 148
}
# 161 "/usr/include/c++/4.2/cstdlib" 3
namespace __gnu_cxx __attribute__((visibility("default"))) { 
# 164
using ::lldiv_t;
# 170
using ::_Exit;
# 174
inline long long abs(long long __x) { return (__x >= (0)) ? __x : (-__x); } 
# 177
using ::llabs;
# 180
inline lldiv_t div(long long __n, long long __d) 
# 181
{ lldiv_t __q; (__q.quot) = (__n / __d); (__q.rem) = (__n % __d); return __q; } 
# 183
using ::lldiv;
# 194 "/usr/include/c++/4.2/cstdlib" 3
using ::atoll;
# 195
using ::strtoll;
# 196
using ::strtoull;
# 198
using ::strtof;
# 199
using ::strtold;
# 201
}
# 203
namespace std __attribute__((visibility("default"))) { 
# 206
using __gnu_cxx::lldiv_t;
# 208
using __gnu_cxx::_Exit;
# 209
using __gnu_cxx::abs;
# 211
using __gnu_cxx::llabs;
# 212
using __gnu_cxx::div;
# 213
using __gnu_cxx::lldiv;
# 215
using __gnu_cxx::atoll;
# 216
using __gnu_cxx::strtof;
# 217
using __gnu_cxx::strtoll;
# 218
using __gnu_cxx::strtoull;
# 219
using __gnu_cxx::strtold;
# 221
}
# 497 "/usr/local/cuda/bin/../include/math_functions.h"
namespace __gnu_cxx { 
# 499
extern inline long long abs(long long) __attribute__((visibility("default"))); 
# 500
}
# 502
namespace std { 
# 504
template<class T> extern inline T __pow_helper(T, int); 
# 505
template<class T> extern inline T __cmath_power(T, unsigned); 
# 506
}
# 508
using std::abs;
# 509
using std::fabs;
# 510
using std::ceil;
# 511
using std::floor;
# 512
using std::sqrt;
# 513
using std::pow;
# 514
using std::log;
# 515
using std::log10;
# 516
using std::fmod;
# 517
using std::modf;
# 518
using std::exp;
# 519
using std::frexp;
# 520
using std::ldexp;
# 521
using std::asin;
# 522
using std::sin;
# 523
using std::sinh;
# 524
using std::acos;
# 525
using std::cos;
# 526
using std::cosh;
# 527
using std::atan;
# 528
using std::atan2;
# 529
using std::tan;
# 530
using std::tanh;
# 584 "/usr/local/cuda/bin/../include/math_functions.h"
namespace std { 
# 587
extern inline long abs(long) __attribute__((visibility("default"))); 
# 588
extern inline float abs(float) __attribute__((visibility("default"))); 
# 589
extern inline double abs(double) __attribute__((visibility("default"))); 
# 590
extern inline float fabs(float) __attribute__((visibility("default"))); 
# 591
extern inline float ceil(float) __attribute__((visibility("default"))); 
# 592
extern inline float floor(float) __attribute__((visibility("default"))); 
# 593
extern inline float sqrt(float) __attribute__((visibility("default"))); 
# 594
extern inline float pow(float, float) __attribute__((visibility("default"))); 
# 595
extern inline float pow(float, int) __attribute__((visibility("default"))); 
# 596
extern inline double pow(double, int) __attribute__((visibility("default"))); 
# 597
extern inline float log(float) __attribute__((visibility("default"))); 
# 598
extern inline float log10(float) __attribute__((visibility("default"))); 
# 599
extern inline float fmod(float, float) __attribute__((visibility("default"))); 
# 600
extern inline float modf(float, float *) __attribute__((visibility("default"))); 
# 601
extern inline float exp(float) __attribute__((visibility("default"))); 
# 602
extern inline float frexp(float, int *) __attribute__((visibility("default"))); 
# 603
extern inline float ldexp(float, int) __attribute__((visibility("default"))); 
# 604
extern inline float asin(float) __attribute__((visibility("default"))); 
# 605
extern inline float sin(float) __attribute__((visibility("default"))); 
# 606
extern inline float sinh(float) __attribute__((visibility("default"))); 
# 607
extern inline float acos(float) __attribute__((visibility("default"))); 
# 608
extern inline float cos(float) __attribute__((visibility("default"))); 
# 609
extern inline float cosh(float) __attribute__((visibility("default"))); 
# 610
extern inline float atan(float) __attribute__((visibility("default"))); 
# 611
extern inline float atan2(float, float) __attribute__((visibility("default"))); 
# 612
extern inline float tan(float) __attribute__((visibility("default"))); 
# 613
extern inline float tanh(float) __attribute__((visibility("default"))); 
# 616
}
# 619
static inline float logb(float a) 
# 620
{ 
# 621
return logbf(a); 
# 622
} 
# 624
static inline int ilogb(float a) 
# 625
{ 
# 626
return ilogbf(a); 
# 627
} 
# 629
static inline float scalbn(float a, int b) 
# 630
{ 
# 631
return scalbnf(a, b); 
# 632
} 
# 634
static inline float scalbln(float a, long b) 
# 635
{ 
# 636
return scalblnf(a, b); 
# 637
} 
# 639
static inline float exp2(float a) 
# 640
{ 
# 641
return exp2f(a); 
# 642
} 
# 644
static inline float exp10(float a) 
# 645
{ 
# 646
return exp10f(a); 
# 647
} 
# 649
static inline float expm1(float a) 
# 650
{ 
# 651
return expm1f(a); 
# 652
} 
# 654
static inline float log2(float a) 
# 655
{ 
# 656
return log2f(a); 
# 657
} 
# 659
static inline float log1p(float a) 
# 660
{ 
# 661
return log1pf(a); 
# 662
} 
# 664
static inline float rsqrt(float a) 
# 665
{ 
# 666
return rsqrtf(a); 
# 667
} 
# 669
static inline float acosh(float a) 
# 670
{ 
# 671
return acoshf(a); 
# 672
} 
# 674
static inline float asinh(float a) 
# 675
{ 
# 676
return asinhf(a); 
# 677
} 
# 679
static inline float atanh(float a) 
# 680
{ 
# 681
return atanhf(a); 
# 682
} 
# 684
static inline float hypot(float a, float b) 
# 685
{ 
# 686
return hypotf(a, b); 
# 687
} 
# 689
static inline float cbrt(float a) 
# 690
{ 
# 691
return cbrtf(a); 
# 692
} 
# 694
static inline float rcbrt(float a) 
# 695
{ 
# 696
return rcbrtf(a); 
# 697
} 
# 699
static inline float sinpi(float a) 
# 700
{ 
# 701
return sinpif(a); 
# 702
} 
# 704
static inline void sincos(float a, float *sptr, float *cptr) 
# 705
{ 
# 706
sincosf(a, sptr, cptr); 
# 707
} 
# 709
static inline float erf(float a) 
# 710
{ 
# 711
return erff(a); 
# 712
} 
# 714
static inline float erfinv(float a) 
# 715
{ 
# 716
return erfinvf(a); 
# 717
} 
# 719
static inline float erfc(float a) 
# 720
{ 
# 721
return erfcf(a); 
# 722
} 
# 724
static inline float erfcinv(float a) 
# 725
{ 
# 726
return erfcinvf(a); 
# 727
} 
# 729
static inline float lgamma(float a) 
# 730
{ 
# 731
return lgammaf(a); 
# 732
} 
# 734
static inline float tgamma(float a) 
# 735
{ 
# 736
return tgammaf(a); 
# 737
} 
# 739
static inline float copysign(float a, float b) 
# 740
{ 
# 741
return copysignf(a, b); 
# 742
} 
# 744
static inline double copysign(double a, float b) 
# 745
{ 
# 746
return copysign(a, (double)b); 
# 747
} 
# 749
static inline float copysign(float a, double b) 
# 750
{ 
# 751
return copysignf(a, (float)b); 
# 752
} 
# 754
static inline float nextafter(float a, float b) 
# 755
{ 
# 756
return nextafterf(a, b); 
# 757
} 
# 759
static inline float remainder(float a, float b) 
# 760
{ 
# 761
return remainderf(a, b); 
# 762
} 
# 764
static inline float remquo(float a, float b, int *quo) 
# 765
{ 
# 766
return remquof(a, b, quo); 
# 767
} 
# 769
static inline float round(float a) 
# 770
{ 
# 771
return roundf(a); 
# 772
} 
# 774
static inline long lround(float a) 
# 775
{ 
# 776
return lroundf(a); 
# 777
} 
# 779
static inline long long llround(float a) 
# 780
{ 
# 781
return llroundf(a); 
# 782
} 
# 784
static inline float trunc(float a) 
# 785
{ 
# 786
return truncf(a); 
# 787
} 
# 789
static inline float rint(float a) 
# 790
{ 
# 791
return rintf(a); 
# 792
} 
# 794
static inline long lrint(float a) 
# 795
{ 
# 796
return lrintf(a); 
# 797
} 
# 799
static inline long long llrint(float a) 
# 800
{ 
# 801
return llrintf(a); 
# 802
} 
# 804
static inline float nearbyint(float a) 
# 805
{ 
# 806
return nearbyintf(a); 
# 807
} 
# 809
static inline float fdim(float a, float b) 
# 810
{ 
# 811
return fdimf(a, b); 
# 812
} 
# 814
static inline float fma(float a, float b, float c) 
# 815
{ 
# 816
return fmaf(a, b, c); 
# 817
} 
# 819
static inline float fmax(float a, float b) 
# 820
{ 
# 821
return fmaxf(a, b); 
# 822
} 
# 824
static inline float fmin(float a, float b) 
# 825
{ 
# 826
return fminf(a, b); 
# 827
} 
# 829
static inline unsigned min(unsigned a, unsigned b) 
# 830
{ 
# 831
return umin(a, b); 
# 832
} 
# 834
static inline unsigned min(int a, unsigned b) 
# 835
{ 
# 836
return umin((unsigned)a, b); 
# 837
} 
# 839
static inline unsigned min(unsigned a, int b) 
# 840
{ 
# 841
return umin(a, (unsigned)b); 
# 842
} 
# 844
static inline long long min(long long a, long long b) 
# 845
{ 
# 846
return llmin(a, b); 
# 847
} 
# 849
static inline unsigned long long min(unsigned long long a, unsigned long long b) 
# 850
{ 
# 851
return ullmin(a, b); 
# 852
} 
# 854
static inline unsigned long long min(long long a, unsigned long long b) 
# 855
{ 
# 856
return ullmin((unsigned long long)a, b); 
# 857
} 
# 859
static inline unsigned long long min(unsigned long long a, long long b) 
# 860
{ 
# 861
return ullmin(a, (unsigned long long)b); 
# 862
} 
# 864
static inline float min(float a, float b) 
# 865
{ 
# 866
return fminf(a, b); 
# 867
} 
# 869
static inline double min(double a, double b) 
# 870
{ 
# 871
return fmin(a, b); 
# 872
} 
# 874
static inline double min(float a, double b) 
# 875
{ 
# 876
return fmin((double)a, b); 
# 877
} 
# 879
static inline double min(double a, float b) 
# 880
{ 
# 881
return fmin(a, (double)b); 
# 882
} 
# 884
static inline unsigned max(unsigned a, unsigned b) 
# 885
{ 
# 886
return umax(a, b); 
# 887
} 
# 889
static inline unsigned max(int a, unsigned b) 
# 890
{ 
# 891
return umax((unsigned)a, b); 
# 892
} 
# 894
static inline unsigned max(unsigned a, int b) 
# 895
{ 
# 896
return umax(a, (unsigned)b); 
# 897
} 
# 899
static inline long long max(long long a, long long b) 
# 900
{ 
# 901
return llmax(a, b); 
# 902
} 
# 904
static inline unsigned long long max(unsigned long long a, unsigned long long b) 
# 905
{ 
# 906
return ullmax(a, b); 
# 907
} 
# 909
static inline unsigned long long max(long long a, unsigned long long b) 
# 910
{ 
# 911
return ullmax((unsigned long long)a, b); 
# 912
} 
# 914
static inline unsigned long long max(unsigned long long a, long long b) 
# 915
{ 
# 916
return ullmax(a, (unsigned long long)b); 
# 917
} 
# 919
static inline float max(float a, float b) 
# 920
{ 
# 921
return fmaxf(a, b); 
# 922
} 
# 924
static inline double max(double a, double b) 
# 925
{ 
# 926
return fmax(a, b); 
# 927
} 
# 929
static inline double max(float a, double b) 
# 930
{ 
# 931
return fmax((double)a, b); 
# 932
} 
# 934
static inline double max(double a, float b) 
# 935
{ 
# 936
return fmax(a, (double)b); 
# 937
} 
# 60 "/usr/local/cuda/bin/../include/cuda_surface_types.h"
template<class T, int dim = 1> 
# 61
struct surface : public surfaceReference { 
# 63
surface() 
# 64
{ 
# 65
(channelDesc) = cudaCreateChannelDesc< T> (); 
# 66
} 
# 68
surface(cudaChannelFormatDesc desc) 
# 69
{ 
# 70
(channelDesc) = desc; 
# 71
} 
# 72
}; 
# 75
template<int dim> 
# 76
struct surface< void, dim>  : public surfaceReference { 
# 78
surface() 
# 79
{ 
# 80
(channelDesc) = cudaCreateChannelDesc< void> (); 
# 81
} 
# 82
}; 
# 60 "/usr/local/cuda/bin/../include/cuda_texture_types.h"
template<class T, int dim = 1, cudaTextureReadMode mode = cudaReadModeElementType> 
# 61
struct texture : public textureReference { 
# 63
texture(int norm = 0, cudaTextureFilterMode 
# 64
fMode = cudaFilterModePoint, cudaTextureAddressMode 
# 65
aMode = cudaAddressModeClamp) 
# 66
{ 
# 67
(normalized) = norm; 
# 68
(filterMode) = fMode; 
# 69
((addressMode)[0]) = aMode; 
# 70
((addressMode)[1]) = aMode; 
# 71
((addressMode)[2]) = aMode; 
# 72
(channelDesc) = cudaCreateChannelDesc< T> (); 
# 73
} 
# 75
texture(int norm, cudaTextureFilterMode 
# 76
fMode, cudaTextureAddressMode 
# 77
aMode, cudaChannelFormatDesc 
# 78
desc) 
# 79
{ 
# 80
(normalized) = norm; 
# 81
(filterMode) = fMode; 
# 82
((addressMode)[0]) = aMode; 
# 83
((addressMode)[1]) = aMode; 
# 84
((addressMode)[2]) = aMode; 
# 85
(channelDesc) = desc; 
# 86
} 
# 87
}; 
# 329 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline int mulhi(int a, int b) 
# 330
{int volatile ___ = 1;
# 332
exit(___);}
#if 0
# 330
{ 
# 331
return __mulhi(a, b); 
# 332
} 
#endif
# 334 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned mulhi(unsigned a, unsigned b) 
# 335
{int volatile ___ = 1;
# 337
exit(___);}
#if 0
# 335
{ 
# 336
return __umulhi(a, b); 
# 337
} 
#endif
# 339 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned mulhi(int a, unsigned b) 
# 340
{int volatile ___ = 1;
# 342
exit(___);}
#if 0
# 340
{ 
# 341
return __umulhi((unsigned)a, b); 
# 342
} 
#endif
# 344 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned mulhi(unsigned a, int b) 
# 345
{int volatile ___ = 1;
# 347
exit(___);}
#if 0
# 345
{ 
# 346
return __umulhi(a, (unsigned)b); 
# 347
} 
#endif
# 349 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline long long mul64hi(long long a, long long b) 
# 350
{int volatile ___ = 1;
# 352
exit(___);}
#if 0
# 350
{ 
# 351
return __mul64hi(a, b); 
# 352
} 
#endif
# 354 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned long long mul64hi(unsigned long long a, unsigned long long b) 
# 355
{int volatile ___ = 1;
# 357
exit(___);}
#if 0
# 355
{ 
# 356
return __umul64hi(a, b); 
# 357
} 
#endif
# 359 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned long long mul64hi(long long a, unsigned long long b) 
# 360
{int volatile ___ = 1;
# 362
exit(___);}
#if 0
# 360
{ 
# 361
return __umul64hi((unsigned long long)a, b); 
# 362
} 
#endif
# 364 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned long long mul64hi(unsigned long long a, long long b) 
# 365
{int volatile ___ = 1;
# 367
exit(___);}
#if 0
# 365
{ 
# 366
return __umul64hi(a, (unsigned long long)b); 
# 367
} 
#endif
# 369 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline int float_as_int(float a) 
# 370
{int volatile ___ = 1;
# 372
exit(___);}
#if 0
# 370
{ 
# 371
return __float_as_int(a); 
# 372
} 
#endif
# 374 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline float int_as_float(int a) 
# 375
{int volatile ___ = 1;
# 377
exit(___);}
#if 0
# 375
{ 
# 376
return __int_as_float(a); 
# 377
} 
#endif
# 379 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline float saturate(float a) 
# 380
{int volatile ___ = 1;
# 382
exit(___);}
#if 0
# 380
{ 
# 381
return __saturatef(a); 
# 382
} 
#endif
# 384 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline int mul24(int a, int b) 
# 385
{int volatile ___ = 1;
# 387
exit(___);}
#if 0
# 385
{ 
# 386
return __mul24(a, b); 
# 387
} 
#endif
# 389 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned umul24(unsigned a, unsigned b) 
# 390
{int volatile ___ = 1;
# 392
exit(___);}
#if 0
# 390
{ 
# 391
return __umul24(a, b); 
# 392
} 
#endif
# 394 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline void trap() 
# 395
{int volatile ___ = 1;
# 397
exit(___);}
#if 0
# 395
{ 
# 396
__trap(); 
# 397
} 
#endif
# 399 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline void brkpt(int c) 
# 400
{int volatile ___ = 1;
# 402
exit(___);}
#if 0
# 400
{ 
# 401
__brkpt(c); 
# 402
} 
#endif
# 404 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline void syncthreads() 
# 405
{int volatile ___ = 1;
# 407
exit(___);}
#if 0
# 405
{ 
# 406
__syncthreads(); 
# 407
} 
#endif
# 409 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline void prof_trigger(int e) 
# 410
{int volatile ___ = 1;
# 427
exit(___);}
#if 0
# 410
{ 
# 411
if (e == 0) { __prof_trigger(0); } else { 
# 412
if (e == 1) { __prof_trigger(1); } else { 
# 413
if (e == 2) { __prof_trigger(2); } else { 
# 414
if (e == 3) { __prof_trigger(3); } else { 
# 415
if (e == 4) { __prof_trigger(4); } else { 
# 416
if (e == 5) { __prof_trigger(5); } else { 
# 417
if (e == 6) { __prof_trigger(6); } else { 
# 418
if (e == 7) { __prof_trigger(7); } else { 
# 419
if (e == 8) { __prof_trigger(8); } else { 
# 420
if (e == 9) { __prof_trigger(9); } else { 
# 421
if (e == 10) { __prof_trigger(10); } else { 
# 422
if (e == 11) { __prof_trigger(11); } else { 
# 423
if (e == 12) { __prof_trigger(12); } else { 
# 424
if (e == 13) { __prof_trigger(13); } else { 
# 425
if (e == 14) { __prof_trigger(14); } else { 
# 426
if (e == 15) { __prof_trigger(15); }  }  }  }  }  }  }  }  }  }  }  }  }  }  }  }  
# 427
} 
#endif
# 429 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline void threadfence(bool global) 
# 430
{int volatile ___ = 1;
# 432
exit(___);}
#if 0
# 430
{ 
# 431
global ? __threadfence() : __threadfence_block(); 
# 432
} 
#endif
# 434 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline int float2int(float a, cudaRoundMode mode) 
# 435
{int volatile ___ = 1;
# 440
exit(___);}
#if 0
# 435
{ 
# 436
return (mode == (cudaRoundNearest)) ? __float2int_rn(a) : ((mode == (cudaRoundPosInf)) ? __float2int_ru(a) : ((mode == (cudaRoundMinInf)) ? __float2int_rd(a) : __float2int_rz(a))); 
# 440
} 
#endif
# 442 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline unsigned float2uint(float a, cudaRoundMode mode) 
# 443
{int volatile ___ = 1;
# 448
exit(___);}
#if 0
# 443
{ 
# 444
return (mode == (cudaRoundNearest)) ? __float2uint_rn(a) : ((mode == (cudaRoundPosInf)) ? __float2uint_ru(a) : ((mode == (cudaRoundMinInf)) ? __float2uint_rd(a) : __float2uint_rz(a))); 
# 448
} 
#endif
# 450 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline float int2float(int a, cudaRoundMode mode) 
# 451
{int volatile ___ = 1;
# 456
exit(___);}
#if 0
# 451
{ 
# 452
return (mode == (cudaRoundZero)) ? __int2float_rz(a) : ((mode == (cudaRoundPosInf)) ? __int2float_ru(a) : ((mode == (cudaRoundMinInf)) ? __int2float_rd(a) : __int2float_rn(a))); 
# 456
} 
#endif
# 458 "/usr/local/cuda/bin/../include/device_functions.h"
static __attribute__((unused)) inline float uint2float(unsigned a, cudaRoundMode mode) 
# 459
{int volatile ___ = 1;
# 464
exit(___);}
#if 0
# 459
{ 
# 460
return (mode == (cudaRoundZero)) ? __uint2float_rz(a) : ((mode == (cudaRoundPosInf)) ? __uint2float_ru(a) : ((mode == (cudaRoundMinInf)) ? __uint2float_rd(a) : __uint2float_rn(a))); 
# 464
} 
#endif
# 102 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicAdd(int *address, int val) 
# 103
{int volatile ___ = 1;
# 105
exit(___);}
#if 0
# 103
{ 
# 104
return __iAtomicAdd(address, val); 
# 105
} 
#endif
# 107 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicAdd(unsigned *address, unsigned val) 
# 108
{int volatile ___ = 1;
# 110
exit(___);}
#if 0
# 108
{ 
# 109
return __uAtomicAdd(address, val); 
# 110
} 
#endif
# 112 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicSub(int *address, int val) 
# 113
{int volatile ___ = 1;
# 115
exit(___);}
#if 0
# 113
{ 
# 114
return __iAtomicAdd(address, (unsigned)(-((int)val))); 
# 115
} 
#endif
# 117 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicSub(unsigned *address, unsigned val) 
# 118
{int volatile ___ = 1;
# 120
exit(___);}
#if 0
# 118
{ 
# 119
return __uAtomicAdd(address, (unsigned)(-((int)val))); 
# 120
} 
#endif
# 122 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicExch(int *address, int val) 
# 123
{int volatile ___ = 1;
# 125
exit(___);}
#if 0
# 123
{ 
# 124
return __iAtomicExch(address, val); 
# 125
} 
#endif
# 127 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicExch(unsigned *address, unsigned val) 
# 128
{int volatile ___ = 1;
# 130
exit(___);}
#if 0
# 128
{ 
# 129
return __uAtomicExch(address, val); 
# 130
} 
#endif
# 132 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline float atomicExch(float *address, float val) 
# 133
{int volatile ___ = 1;
# 135
exit(___);}
#if 0
# 133
{ 
# 134
return __fAtomicExch(address, val); 
# 135
} 
#endif
# 137 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicMin(int *address, int val) 
# 138
{int volatile ___ = 1;
# 140
exit(___);}
#if 0
# 138
{ 
# 139
return __iAtomicMin(address, val); 
# 140
} 
#endif
# 142 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicMin(unsigned *address, unsigned val) 
# 143
{int volatile ___ = 1;
# 145
exit(___);}
#if 0
# 143
{ 
# 144
return __uAtomicMin(address, val); 
# 145
} 
#endif
# 147 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicMax(int *address, int val) 
# 148
{int volatile ___ = 1;
# 150
exit(___);}
#if 0
# 148
{ 
# 149
return __iAtomicMax(address, val); 
# 150
} 
#endif
# 152 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicMax(unsigned *address, unsigned val) 
# 153
{int volatile ___ = 1;
# 155
exit(___);}
#if 0
# 153
{ 
# 154
return __uAtomicMax(address, val); 
# 155
} 
#endif
# 157 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicInc(unsigned *address, unsigned val) 
# 158
{int volatile ___ = 1;
# 160
exit(___);}
#if 0
# 158
{ 
# 159
return __uAtomicInc(address, val); 
# 160
} 
#endif
# 162 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicDec(unsigned *address, unsigned val) 
# 163
{int volatile ___ = 1;
# 165
exit(___);}
#if 0
# 163
{ 
# 164
return __uAtomicDec(address, val); 
# 165
} 
#endif
# 167 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicAnd(int *address, int val) 
# 168
{int volatile ___ = 1;
# 170
exit(___);}
#if 0
# 168
{ 
# 169
return __iAtomicAnd(address, val); 
# 170
} 
#endif
# 172 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicAnd(unsigned *address, unsigned val) 
# 173
{int volatile ___ = 1;
# 175
exit(___);}
#if 0
# 173
{ 
# 174
return __uAtomicAnd(address, val); 
# 175
} 
#endif
# 177 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicOr(int *address, int val) 
# 178
{int volatile ___ = 1;
# 180
exit(___);}
#if 0
# 178
{ 
# 179
return __iAtomicOr(address, val); 
# 180
} 
#endif
# 182 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicOr(unsigned *address, unsigned val) 
# 183
{int volatile ___ = 1;
# 185
exit(___);}
#if 0
# 183
{ 
# 184
return __uAtomicOr(address, val); 
# 185
} 
#endif
# 187 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicXor(int *address, int val) 
# 188
{int volatile ___ = 1;
# 190
exit(___);}
#if 0
# 188
{ 
# 189
return __iAtomicXor(address, val); 
# 190
} 
#endif
# 192 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicXor(unsigned *address, unsigned val) 
# 193
{int volatile ___ = 1;
# 195
exit(___);}
#if 0
# 193
{ 
# 194
return __uAtomicXor(address, val); 
# 195
} 
#endif
# 197 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline int atomicCAS(int *address, int compare, int val) 
# 198
{int volatile ___ = 1;
# 200
exit(___);}
#if 0
# 198
{ 
# 199
return __iAtomicCAS(address, compare, val); 
# 200
} 
#endif
# 202 "/usr/local/cuda/bin/../include/sm_11_atomic_functions.h"
static __attribute__((unused)) inline unsigned atomicCAS(unsigned *address, unsigned compare, unsigned val) 
# 203
{int volatile ___ = 1;
# 205
exit(___);}
#if 0
# 203
{ 
# 204
return __uAtomicCAS(address, compare, val); 
# 205
} 
#endif
# 75 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
static __attribute__((unused)) inline unsigned long long atomicAdd(unsigned long long *address, unsigned long long val) 
# 76
{int volatile ___ = 1;
# 78
exit(___);}
#if 0
# 76
{ 
# 77
return __ullAtomicAdd(address, val); 
# 78
} 
#endif
# 80 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
static __attribute__((unused)) inline unsigned long long atomicExch(unsigned long long *address, unsigned long long val) 
# 81
{int volatile ___ = 1;
# 83
exit(___);}
#if 0
# 81
{ 
# 82
return __ullAtomicExch(address, val); 
# 83
} 
#endif
# 85 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
static __attribute__((unused)) inline unsigned long long atomicCAS(unsigned long long *address, unsigned long long compare, unsigned long long val) 
# 86
{int volatile ___ = 1;
# 88
exit(___);}
#if 0
# 86
{ 
# 87
return __ullAtomicCAS(address, compare, val); 
# 88
} 
#endif
# 90 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
static __attribute__((unused)) inline bool any(bool cond) 
# 91
{int volatile ___ = 1;
# 93
exit(___);}
#if 0
# 91
{ 
# 92
return (bool)__any((int)cond); 
# 93
} 
#endif
# 95 "/usr/local/cuda/bin/../include/sm_12_atomic_functions.h"
static __attribute__((unused)) inline bool all(bool cond) 
# 96
{int volatile ___ = 1;
# 98
exit(___);}
#if 0
# 96
{ 
# 97
return (bool)__all((int)cond); 
# 98
} 
#endif
# 170 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double fma(double a, double b, double c, cudaRoundMode mode) 
# 171
{int volatile ___ = 1;
# 176
exit(___);}
#if 0
# 171
{ 
# 172
return (mode == (cudaRoundZero)) ? __fma_rz(a, b, c) : ((mode == (cudaRoundPosInf)) ? __fma_ru(a, b, c) : ((mode == (cudaRoundMinInf)) ? __fma_rd(a, b, c) : __fma_rn(a, b, c))); 
# 176
} 
#endif
# 178 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double dmul(double a, double b, cudaRoundMode mode) 
# 179
{int volatile ___ = 1;
# 184
exit(___);}
#if 0
# 179
{ 
# 180
return (mode == (cudaRoundZero)) ? __dmul_rz(a, b) : ((mode == (cudaRoundPosInf)) ? __dmul_ru(a, b) : ((mode == (cudaRoundMinInf)) ? __dmul_rd(a, b) : __dmul_rn(a, b))); 
# 184
} 
#endif
# 186 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double dadd(double a, double b, cudaRoundMode mode) 
# 187
{int volatile ___ = 1;
# 192
exit(___);}
#if 0
# 187
{ 
# 188
return (mode == (cudaRoundZero)) ? __dadd_rz(a, b) : ((mode == (cudaRoundPosInf)) ? __dadd_ru(a, b) : ((mode == (cudaRoundMinInf)) ? __dadd_rd(a, b) : __dadd_rn(a, b))); 
# 192
} 
#endif
# 194 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline int double2int(double a, cudaRoundMode mode) 
# 195
{int volatile ___ = 1;
# 200
exit(___);}
#if 0
# 195
{ 
# 196
return (mode == (cudaRoundNearest)) ? __double2int_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2int_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2int_rd(a) : __double2int_rz(a))); 
# 200
} 
#endif
# 202 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline unsigned double2uint(double a, cudaRoundMode mode) 
# 203
{int volatile ___ = 1;
# 208
exit(___);}
#if 0
# 203
{ 
# 204
return (mode == (cudaRoundNearest)) ? __double2uint_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2uint_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2uint_rd(a) : __double2uint_rz(a))); 
# 208
} 
#endif
# 210 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline long long double2ll(double a, cudaRoundMode mode) 
# 211
{int volatile ___ = 1;
# 216
exit(___);}
#if 0
# 211
{ 
# 212
return (mode == (cudaRoundNearest)) ? __double2ll_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2ll_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2ll_rd(a) : __double2ll_rz(a))); 
# 216
} 
#endif
# 218 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline unsigned long long double2ull(double a, cudaRoundMode mode) 
# 219
{int volatile ___ = 1;
# 224
exit(___);}
#if 0
# 219
{ 
# 220
return (mode == (cudaRoundNearest)) ? __double2ull_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2ull_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2ull_rd(a) : __double2ull_rz(a))); 
# 224
} 
#endif
# 226 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double ll2double(long long a, cudaRoundMode mode) 
# 227
{int volatile ___ = 1;
# 232
exit(___);}
#if 0
# 227
{ 
# 228
return (mode == (cudaRoundZero)) ? __ll2double_rz(a) : ((mode == (cudaRoundPosInf)) ? __ll2double_ru(a) : ((mode == (cudaRoundMinInf)) ? __ll2double_rd(a) : __ll2double_rn(a))); 
# 232
} 
#endif
# 234 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double ull2double(unsigned long long a, cudaRoundMode mode) 
# 235
{int volatile ___ = 1;
# 240
exit(___);}
#if 0
# 235
{ 
# 236
return (mode == (cudaRoundZero)) ? __ull2double_rz(a) : ((mode == (cudaRoundPosInf)) ? __ull2double_ru(a) : ((mode == (cudaRoundMinInf)) ? __ull2double_rd(a) : __ull2double_rn(a))); 
# 240
} 
#endif
# 242 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double int2double(int a, cudaRoundMode mode) 
# 243
{int volatile ___ = 1;
# 245
exit(___);}
#if 0
# 243
{ 
# 244
return (double)a; 
# 245
} 
#endif
# 247 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double uint2double(unsigned a, cudaRoundMode mode) 
# 248
{int volatile ___ = 1;
# 250
exit(___);}
#if 0
# 248
{ 
# 249
return (double)a; 
# 250
} 
#endif
# 252 "/usr/local/cuda/bin/../include/sm_13_double_functions.h"
static __attribute__((unused)) inline double float2double(float a, cudaRoundMode mode) 
# 253
{int volatile ___ = 1;
# 255
exit(___);}
#if 0
# 253
{ 
# 254
return (double)a; 
# 255
} 
#endif
# 66 "/usr/local/cuda/bin/../include/sm_20_atomic_functions.h"
static __attribute__((unused)) inline float atomicAdd(float *address, float val) 
# 67
{int volatile ___ = 1;
# 69
exit(___);}
#if 0
# 67
{ 
# 68
return __fAtomicAdd(address, val); 
# 69
} 
#endif
# 124 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
static __attribute__((unused)) inline unsigned ballot(bool pred) 
# 125
{int volatile ___ = 1;
# 127
exit(___);}
#if 0
# 125
{ 
# 126
return __ballot((int)pred); 
# 127
} 
#endif
# 129 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
static __attribute__((unused)) inline int syncthreads_count(bool pred) 
# 130
{int volatile ___ = 1;
# 132
exit(___);}
#if 0
# 130
{ 
# 131
return __syncthreads_count((int)pred); 
# 132
} 
#endif
# 134 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
static __attribute__((unused)) inline bool syncthreads_and(bool pred) 
# 135
{int volatile ___ = 1;
# 137
exit(___);}
#if 0
# 135
{ 
# 136
return (bool)__syncthreads_and((int)pred); 
# 137
} 
#endif
# 139 "/usr/local/cuda/bin/../include/sm_20_intrinsics.h"
static __attribute__((unused)) inline bool syncthreads_or(bool pred) 
# 140
{int volatile ___ = 1;
# 142
exit(___);}
#if 0
# 140
{ 
# 141
return (bool)__syncthreads_or((int)pred); 
# 142
} 
#endif
# 97 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void 
# 98
surf1Dread(T *res, surface< void, 1>  surf, int x, int s, cudaSurfaceBoundaryMode mode) 
# 99
{int volatile ___ = 1;
# 106
exit(___);}
#if 0
# 99
{ 
# 100
(s == 1) ? ((void)((*((uchar1 *)res)) = __surf1Dreadc1(surf, x, cudaBoundaryModeTrap))) : ((s == 2) ? ((void)((*((ushort1 *)res)) = __surf1Dreads1(surf, x, cudaBoundaryModeTrap))) : ((s == 4) ? ((void)((*((uint1 *)res)) = __surf1Dreadu1(surf, x, cudaBoundaryModeTrap))) : ((s == 8) ? ((void)((*((uint2 *)res)) = __surf1Dreadu2(surf, x, cudaBoundaryModeTrap))) : ((s == 16) ? ((void)((*((uint4 *)res)) = __surf1Dreadu4(surf, x, cudaBoundaryModeTrap))) : ((void)0))))); 
# 106
} 
#endif
# 108 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline T 
# 109
surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 110
{int volatile ___ = 1;
# 116
exit(___);}
#if 0
# 110
{ 
# 111
T tmp; 
# 113
surf1Dread(&tmp, surf, x, (int)sizeof(T), mode); 
# 115
return tmp; 
# 116
} 
#endif
# 118 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void 
# 119
surf1Dread(T *res, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 120
{int volatile ___ = 1;
# 122
exit(___);}
#if 0
# 120
{ 
# 121
(*res) = surf1Dread< T> (surf, x, mode); 
# 122
} 
#endif
# 125 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 126
{int volatile ___ = 1;
# 128
exit(___);}
#if 0
# 126
{ 
# 127
return (char)(__surf1Dreadc1(surf, x, cudaBoundaryModeTrap).x); 
# 128
} 
#endif
# 131 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline signed char surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 132
{int volatile ___ = 1;
# 134
exit(___);}
#if 0
# 132
{ 
# 133
return (signed char)(__surf1Dreadc1(surf, x, cudaBoundaryModeTrap).x); 
# 134
} 
#endif
# 137 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned char surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 138
{int volatile ___ = 1;
# 140
exit(___);}
#if 0
# 138
{ 
# 139
return __surf1Dreadc1(surf, x, cudaBoundaryModeTrap).x; 
# 140
} 
#endif
# 143 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char1 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 144
{int volatile ___ = 1;
# 146
exit(___);}
#if 0
# 144
{ 
# 145
return make_char1((signed char)(__surf1Dreadc1(surf, x, cudaBoundaryModeTrap).x)); 
# 146
} 
#endif
# 149 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar1 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 150
{int volatile ___ = 1;
# 152
exit(___);}
#if 0
# 150
{ 
# 151
return __surf1Dreadc1(surf, x, cudaBoundaryModeTrap); 
# 152
} 
#endif
# 155 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char2 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 156
{int volatile ___ = 1;
# 160
exit(___);}
#if 0
# 156
{ 
# 157
uchar2 tmp = __surf1Dreadc2(surf, x, cudaBoundaryModeTrap); 
# 159
return make_char2((signed char)(tmp.x), (signed char)(tmp.y)); 
# 160
} 
#endif
# 163 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar2 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 164
{int volatile ___ = 1;
# 166
exit(___);}
#if 0
# 164
{ 
# 165
return __surf1Dreadc2(surf, x, cudaBoundaryModeTrap); 
# 166
} 
#endif
# 169 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char4 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 170
{int volatile ___ = 1;
# 174
exit(___);}
#if 0
# 170
{ 
# 171
uchar4 tmp = __surf1Dreadc4(surf, x, cudaBoundaryModeTrap); 
# 173
return make_char4((signed char)(tmp.x), (signed char)(tmp.y), (signed char)(tmp.z), (signed char)(tmp.w)); 
# 174
} 
#endif
# 177 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar4 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 178
{int volatile ___ = 1;
# 180
exit(___);}
#if 0
# 178
{ 
# 179
return __surf1Dreadc4(surf, x, cudaBoundaryModeTrap); 
# 180
} 
#endif
# 183 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 184
{int volatile ___ = 1;
# 186
exit(___);}
#if 0
# 184
{ 
# 185
return (short)(__surf1Dreads1(surf, x, cudaBoundaryModeTrap).x); 
# 186
} 
#endif
# 189 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned short surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 190
{int volatile ___ = 1;
# 192
exit(___);}
#if 0
# 190
{ 
# 191
return __surf1Dreads1(surf, x, cudaBoundaryModeTrap).x; 
# 192
} 
#endif
# 195 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short1 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 196
{int volatile ___ = 1;
# 198
exit(___);}
#if 0
# 196
{ 
# 197
return make_short1((signed short)(__surf1Dreads1(surf, x, cudaBoundaryModeTrap).x)); 
# 198
} 
#endif
# 201 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort1 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 202
{int volatile ___ = 1;
# 204
exit(___);}
#if 0
# 202
{ 
# 203
return __surf1Dreads1(surf, x, cudaBoundaryModeTrap); 
# 204
} 
#endif
# 207 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short2 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 208
{int volatile ___ = 1;
# 212
exit(___);}
#if 0
# 208
{ 
# 209
ushort2 tmp = __surf1Dreads2(surf, x, cudaBoundaryModeTrap); 
# 211
return make_short2((signed short)(tmp.x), (signed short)(tmp.y)); 
# 212
} 
#endif
# 215 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort2 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 216
{int volatile ___ = 1;
# 218
exit(___);}
#if 0
# 216
{ 
# 217
return __surf1Dreads2(surf, x, cudaBoundaryModeTrap); 
# 218
} 
#endif
# 221 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short4 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 222
{int volatile ___ = 1;
# 226
exit(___);}
#if 0
# 222
{ 
# 223
ushort4 tmp = __surf1Dreads4(surf, x, cudaBoundaryModeTrap); 
# 225
return make_short4((signed short)(tmp.x), (signed short)(tmp.y), (signed short)(tmp.z), (signed short)(tmp.w)); 
# 226
} 
#endif
# 229 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort4 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 230
{int volatile ___ = 1;
# 232
exit(___);}
#if 0
# 230
{ 
# 231
return __surf1Dreads4(surf, x, cudaBoundaryModeTrap); 
# 232
} 
#endif
# 235 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 236
{int volatile ___ = 1;
# 238
exit(___);}
#if 0
# 236
{ 
# 237
return (int)(__surf1Dreadu1(surf, x, cudaBoundaryModeTrap).x); 
# 238
} 
#endif
# 241 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 242
{int volatile ___ = 1;
# 244
exit(___);}
#if 0
# 242
{ 
# 243
return __surf1Dreadu1(surf, x, cudaBoundaryModeTrap).x; 
# 244
} 
#endif
# 247 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int1 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 248
{int volatile ___ = 1;
# 250
exit(___);}
#if 0
# 248
{ 
# 249
return make_int1((signed int)(__surf1Dreadu1(surf, x, cudaBoundaryModeTrap).x)); 
# 250
} 
#endif
# 253 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint1 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 254
{int volatile ___ = 1;
# 256
exit(___);}
#if 0
# 254
{ 
# 255
return __surf1Dreadu1(surf, x, cudaBoundaryModeTrap); 
# 256
} 
#endif
# 259 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int2 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 260
{int volatile ___ = 1;
# 264
exit(___);}
#if 0
# 260
{ 
# 261
uint2 tmp = __surf1Dreadu2(surf, x, cudaBoundaryModeTrap); 
# 263
return make_int2((int)(tmp.x), (int)(tmp.y)); 
# 264
} 
#endif
# 267 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint2 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 268
{int volatile ___ = 1;
# 270
exit(___);}
#if 0
# 268
{ 
# 269
return __surf1Dreadu2(surf, x, cudaBoundaryModeTrap); 
# 270
} 
#endif
# 273 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int4 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 274
{int volatile ___ = 1;
# 278
exit(___);}
#if 0
# 274
{ 
# 275
uint4 tmp = __surf1Dreadu4(surf, x, cudaBoundaryModeTrap); 
# 277
return make_int4((int)(tmp.x), (int)(tmp.y), (int)(tmp.z), (int)(tmp.w)); 
# 278
} 
#endif
# 281 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint4 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 282
{int volatile ___ = 1;
# 284
exit(___);}
#if 0
# 282
{ 
# 283
return __surf1Dreadu4(surf, x, cudaBoundaryModeTrap); 
# 284
} 
#endif
# 287 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline long long surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 288
{int volatile ___ = 1;
# 290
exit(___);}
#if 0
# 288
{ 
# 289
return (long long)(__surf1Dreadl1(surf, x, cudaBoundaryModeTrap).x); 
# 290
} 
#endif
# 293 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long long surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 294
{int volatile ___ = 1;
# 296
exit(___);}
#if 0
# 294
{ 
# 295
return __surf1Dreadl1(surf, x, cudaBoundaryModeTrap).x; 
# 296
} 
#endif
# 299 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline longlong1 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 300
{int volatile ___ = 1;
# 302
exit(___);}
#if 0
# 300
{ 
# 301
return make_longlong1((long long)(__surf1Dreadl1(surf, x, cudaBoundaryModeTrap).x)); 
# 302
} 
#endif
# 305 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong1 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 306
{int volatile ___ = 1;
# 308
exit(___);}
#if 0
# 306
{ 
# 307
return __surf1Dreadl1(surf, x, cudaBoundaryModeTrap); 
# 308
} 
#endif
# 311 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline longlong2 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 312
{int volatile ___ = 1;
# 316
exit(___);}
#if 0
# 312
{ 
# 313
ulonglong2 tmp = __surf1Dreadl2(surf, x, cudaBoundaryModeTrap); 
# 315
return make_longlong2((long long)(tmp.x), (long long)(tmp.y)); 
# 316
} 
#endif
# 319 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong2 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 320
{int volatile ___ = 1;
# 322
exit(___);}
#if 0
# 320
{ 
# 321
return __surf1Dreadl2(surf, x, cudaBoundaryModeTrap); 
# 322
} 
#endif
# 385 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 386
{int volatile ___ = 1;
# 388
exit(___);}
#if 0
# 386
{ 
# 387
return __int_as_float((int)(__surf1Dreadu1(surf, x, cudaBoundaryModeTrap).x)); 
# 388
} 
#endif
# 391 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float1 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 392
{int volatile ___ = 1;
# 394
exit(___);}
#if 0
# 392
{ 
# 393
return make_float1(__int_as_float((int)(__surf1Dreadu1(surf, x, cudaBoundaryModeTrap).x))); 
# 394
} 
#endif
# 397 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float2 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 398
{int volatile ___ = 1;
# 402
exit(___);}
#if 0
# 398
{ 
# 399
uint2 tmp = __surf1Dreadu2(surf, x, cudaBoundaryModeTrap); 
# 401
return make_float2(__int_as_float((int)(tmp.x)), __int_as_float((int)(tmp.y))); 
# 402
} 
#endif
# 405 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float4 surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 406
{int volatile ___ = 1;
# 410
exit(___);}
#if 0
# 406
{ 
# 407
uint4 tmp = __surf1Dreadu4(surf, x, cudaBoundaryModeTrap); 
# 409
return make_float4(__int_as_float((int)(tmp.x)), __int_as_float((int)(tmp.y)), __int_as_float((int)(tmp.z)), __int_as_float((int)(tmp.w))); 
# 410
} 
#endif
# 457 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void 
# 458
surf2Dread(T *res, surface< void, 2>  surf, int x, int y, int s, cudaSurfaceBoundaryMode mode) 
# 459
{int volatile ___ = 1;
# 466
exit(___);}
#if 0
# 459
{ 
# 460
(s == 1) ? ((void)((*((uchar1 *)res)) = __surf2Dreadc1(surf, x, y, cudaBoundaryModeTrap))) : ((s == 2) ? ((void)((*((ushort1 *)res)) = __surf2Dreads1(surf, x, y, cudaBoundaryModeTrap))) : ((s == 4) ? ((void)((*((uint1 *)res)) = __surf2Dreadu1(surf, x, y, cudaBoundaryModeTrap))) : ((s == 8) ? ((void)((*((uint2 *)res)) = __surf2Dreadu2(surf, x, y, cudaBoundaryModeTrap))) : ((s == 16) ? ((void)((*((uint4 *)res)) = __surf2Dreadu4(surf, x, y, cudaBoundaryModeTrap))) : ((void)0))))); 
# 466
} 
#endif
# 468 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline T 
# 469
surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 470
{int volatile ___ = 1;
# 476
exit(___);}
#if 0
# 470
{ 
# 471
T tmp; 
# 473
surf2Dread(&tmp, surf, x, y, (int)sizeof(T), mode); 
# 475
return tmp; 
# 476
} 
#endif
# 478 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void 
# 479
surf2Dread(T *res, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 480
{int volatile ___ = 1;
# 482
exit(___);}
#if 0
# 480
{ 
# 481
(*res) = surf2Dread< T> (surf, x, y, mode); 
# 482
} 
#endif
# 485 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 486
{int volatile ___ = 1;
# 488
exit(___);}
#if 0
# 486
{ 
# 487
return (char)(__surf2Dreadc1(surf, x, y, cudaBoundaryModeTrap).x); 
# 488
} 
#endif
# 491 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline signed char surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 492
{int volatile ___ = 1;
# 494
exit(___);}
#if 0
# 492
{ 
# 493
return (signed char)(__surf2Dreadc1(surf, x, y, cudaBoundaryModeTrap).x); 
# 494
} 
#endif
# 497 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned char surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 498
{int volatile ___ = 1;
# 500
exit(___);}
#if 0
# 498
{ 
# 499
return __surf2Dreadc1(surf, x, y, cudaBoundaryModeTrap).x; 
# 500
} 
#endif
# 503 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char1 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 504
{int volatile ___ = 1;
# 506
exit(___);}
#if 0
# 504
{ 
# 505
return make_char1((signed char)(__surf2Dreadc1(surf, x, y, cudaBoundaryModeTrap).x)); 
# 506
} 
#endif
# 509 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar1 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 510
{int volatile ___ = 1;
# 512
exit(___);}
#if 0
# 510
{ 
# 511
return __surf2Dreadc1(surf, x, y, cudaBoundaryModeTrap); 
# 512
} 
#endif
# 515 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char2 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 516
{int volatile ___ = 1;
# 520
exit(___);}
#if 0
# 516
{ 
# 517
uchar2 tmp = __surf2Dreadc2(surf, x, y, cudaBoundaryModeTrap); 
# 519
return make_char2((signed char)(tmp.x), (signed char)(tmp.y)); 
# 520
} 
#endif
# 523 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar2 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 524
{int volatile ___ = 1;
# 526
exit(___);}
#if 0
# 524
{ 
# 525
return __surf2Dreadc2(surf, x, y, cudaBoundaryModeTrap); 
# 526
} 
#endif
# 529 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline char4 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 530
{int volatile ___ = 1;
# 534
exit(___);}
#if 0
# 530
{ 
# 531
uchar4 tmp = __surf2Dreadc4(surf, x, y, cudaBoundaryModeTrap); 
# 533
return make_char4((signed char)(tmp.x), (signed char)(tmp.y), (signed char)(tmp.z), (signed char)(tmp.w)); 
# 534
} 
#endif
# 537 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uchar4 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 538
{int volatile ___ = 1;
# 540
exit(___);}
#if 0
# 538
{ 
# 539
return __surf2Dreadc4(surf, x, y, cudaBoundaryModeTrap); 
# 540
} 
#endif
# 543 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 544
{int volatile ___ = 1;
# 546
exit(___);}
#if 0
# 544
{ 
# 545
return (short)(__surf2Dreads1(surf, x, y, cudaBoundaryModeTrap).x); 
# 546
} 
#endif
# 549 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned short surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 550
{int volatile ___ = 1;
# 552
exit(___);}
#if 0
# 550
{ 
# 551
return __surf2Dreads1(surf, x, y, cudaBoundaryModeTrap).x; 
# 552
} 
#endif
# 555 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short1 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 556
{int volatile ___ = 1;
# 558
exit(___);}
#if 0
# 556
{ 
# 557
return make_short1((signed short)(__surf2Dreads1(surf, x, y, cudaBoundaryModeTrap).x)); 
# 558
} 
#endif
# 561 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort1 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 562
{int volatile ___ = 1;
# 564
exit(___);}
#if 0
# 562
{ 
# 563
return __surf2Dreads1(surf, x, y, cudaBoundaryModeTrap); 
# 564
} 
#endif
# 567 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short2 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 568
{int volatile ___ = 1;
# 572
exit(___);}
#if 0
# 568
{ 
# 569
ushort2 tmp = __surf2Dreads2(surf, x, y, cudaBoundaryModeTrap); 
# 571
return make_short2((signed short)(tmp.x), (signed short)(tmp.y)); 
# 572
} 
#endif
# 575 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort2 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 576
{int volatile ___ = 1;
# 578
exit(___);}
#if 0
# 576
{ 
# 577
return __surf2Dreads2(surf, x, y, cudaBoundaryModeTrap); 
# 578
} 
#endif
# 581 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline short4 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 582
{int volatile ___ = 1;
# 586
exit(___);}
#if 0
# 582
{ 
# 583
ushort4 tmp = __surf2Dreads4(surf, x, y, cudaBoundaryModeTrap); 
# 585
return make_short4((signed short)(tmp.x), (signed short)(tmp.y), (signed short)(tmp.z), (signed short)(tmp.w)); 
# 586
} 
#endif
# 589 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ushort4 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 590
{int volatile ___ = 1;
# 592
exit(___);}
#if 0
# 590
{ 
# 591
return __surf2Dreads4(surf, x, y, cudaBoundaryModeTrap); 
# 592
} 
#endif
# 595 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 596
{int volatile ___ = 1;
# 598
exit(___);}
#if 0
# 596
{ 
# 597
return (int)(__surf2Dreadu1(surf, x, y, cudaBoundaryModeTrap).x); 
# 598
} 
#endif
# 601 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 602
{int volatile ___ = 1;
# 604
exit(___);}
#if 0
# 602
{ 
# 603
return __surf2Dreadu1(surf, x, y, cudaBoundaryModeTrap).x; 
# 604
} 
#endif
# 607 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int1 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 608
{int volatile ___ = 1;
# 610
exit(___);}
#if 0
# 608
{ 
# 609
return make_int1((signed int)(__surf2Dreadu1(surf, x, y, cudaBoundaryModeTrap).x)); 
# 610
} 
#endif
# 613 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint1 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 614
{int volatile ___ = 1;
# 616
exit(___);}
#if 0
# 614
{ 
# 615
return __surf2Dreadu1(surf, x, y, cudaBoundaryModeTrap); 
# 616
} 
#endif
# 619 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int2 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 620
{int volatile ___ = 1;
# 624
exit(___);}
#if 0
# 620
{ 
# 621
uint2 tmp = __surf2Dreadu2(surf, x, y, cudaBoundaryModeTrap); 
# 623
return make_int2((int)(tmp.x), (int)(tmp.y)); 
# 624
} 
#endif
# 627 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint2 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 628
{int volatile ___ = 1;
# 630
exit(___);}
#if 0
# 628
{ 
# 629
return __surf2Dreadu2(surf, x, y, cudaBoundaryModeTrap); 
# 630
} 
#endif
# 633 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline int4 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 634
{int volatile ___ = 1;
# 638
exit(___);}
#if 0
# 634
{ 
# 635
uint4 tmp = __surf2Dreadu4(surf, x, y, cudaBoundaryModeTrap); 
# 637
return make_int4((int)(tmp.x), (int)(tmp.y), (int)(tmp.z), (int)(tmp.w)); 
# 638
} 
#endif
# 641 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline uint4 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 642
{int volatile ___ = 1;
# 644
exit(___);}
#if 0
# 642
{ 
# 643
return __surf2Dreadu4(surf, x, y, cudaBoundaryModeTrap); 
# 644
} 
#endif
# 647 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline long long surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 648
{int volatile ___ = 1;
# 650
exit(___);}
#if 0
# 648
{ 
# 649
return (long long)(__surf2Dreadl1(surf, x, y, cudaBoundaryModeTrap).x); 
# 650
} 
#endif
# 653 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline unsigned long long surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 654
{int volatile ___ = 1;
# 656
exit(___);}
#if 0
# 654
{ 
# 655
return __surf2Dreadl1(surf, x, y, cudaBoundaryModeTrap).x; 
# 656
} 
#endif
# 659 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline longlong1 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 660
{int volatile ___ = 1;
# 662
exit(___);}
#if 0
# 660
{ 
# 661
return make_longlong1((long long)(__surf2Dreadl1(surf, x, y, cudaBoundaryModeTrap).x)); 
# 662
} 
#endif
# 665 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong1 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 666
{int volatile ___ = 1;
# 668
exit(___);}
#if 0
# 666
{ 
# 667
return __surf2Dreadl1(surf, x, y, cudaBoundaryModeTrap); 
# 668
} 
#endif
# 671 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline longlong2 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 672
{int volatile ___ = 1;
# 676
exit(___);}
#if 0
# 672
{ 
# 673
ulonglong2 tmp = __surf2Dreadl2(surf, x, y, cudaBoundaryModeTrap); 
# 675
return make_longlong2((long long)(tmp.x), (long long)(tmp.y)); 
# 676
} 
#endif
# 679 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline ulonglong2 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 680
{int volatile ___ = 1;
# 682
exit(___);}
#if 0
# 680
{ 
# 681
return __surf2Dreadl2(surf, x, y, cudaBoundaryModeTrap); 
# 682
} 
#endif
# 745 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 746
{int volatile ___ = 1;
# 748
exit(___);}
#if 0
# 746
{ 
# 747
return __int_as_float((int)(__surf2Dreadu1(surf, x, y, cudaBoundaryModeTrap).x)); 
# 748
} 
#endif
# 751 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float1 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 752
{int volatile ___ = 1;
# 754
exit(___);}
#if 0
# 752
{ 
# 753
return make_float1(__int_as_float((int)(__surf2Dreadu1(surf, x, y, cudaBoundaryModeTrap).x))); 
# 754
} 
#endif
# 757 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float2 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 758
{int volatile ___ = 1;
# 762
exit(___);}
#if 0
# 758
{ 
# 759
uint2 tmp = __surf2Dreadu2(surf, x, y, cudaBoundaryModeTrap); 
# 761
return make_float2(__int_as_float((int)(tmp.x)), __int_as_float((int)(tmp.y))); 
# 762
} 
#endif
# 765 "/usr/local/cuda/bin/../include/surface_functions.h"
template<> __attribute__((unused)) inline float4 surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 766
{int volatile ___ = 1;
# 770
exit(___);}
#if 0
# 766
{ 
# 767
uint4 tmp = __surf2Dreadu4(surf, x, y, cudaBoundaryModeTrap); 
# 769
return make_float4(__int_as_float((int)(tmp.x)), __int_as_float((int)(tmp.y)), __int_as_float((int)(tmp.z)), __int_as_float((int)(tmp.w))); 
# 770
} 
#endif
# 817 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void 
# 818
surf1Dwrite(T val, surface< void, 1>  surf, int x, int s, cudaSurfaceBoundaryMode mode) 
# 819
{int volatile ___ = 1;
# 837
exit(___);}
#if 0
# 819
{ 
# 820
union { 
# 821
T val; 
# 822
uchar1 c1; 
# 823
ushort1 s1; 
# 824
uint1 u1; 
# 825
uint2 u2; 
# 826
uint4 u4; 
# 827
} tmp; 
# 829
(tmp.val) = val; 
# 831
(s == 1) ? ((void)__surf1Dwritec1(tmp.c1, surf, x, cudaBoundaryModeTrap)) : ((s == 2) ? ((void)__surf1Dwrites1(tmp.s1, surf, x, cudaBoundaryModeTrap)) : ((s == 4) ? ((void)__surf1Dwriteu1(tmp.u1, surf, x, cudaBoundaryModeTrap)) : ((s == 8) ? ((void)__surf1Dwriteu2(tmp.u2, surf, x, cudaBoundaryModeTrap)) : ((s == 16) ? ((void)__surf1Dwriteu4(tmp.u4, surf, x, cudaBoundaryModeTrap)) : ((void)0))))); 
# 837
} 
#endif
# 839 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void 
# 840
surf1Dwrite(T val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 841
{int volatile ___ = 1;
# 843
exit(___);}
#if 0
# 841
{ ; 
# 842
surf1Dwrite(val, surf, x, (int)sizeof(T), mode); 
# 843
} 
#endif
# 846 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(char val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 847
{int volatile ___ = 1;
# 849
exit(___);}
#if 0
# 847
{ 
# 848
__surf1Dwritec1(make_uchar1((unsigned char)val), surf, x, cudaBoundaryModeTrap); 
# 849
} 
#endif
# 851 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(signed char val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 852
{int volatile ___ = 1;
# 854
exit(___);}
#if 0
# 852
{ 
# 853
__surf1Dwritec1(make_uchar1((unsigned char)val), surf, x, cudaBoundaryModeTrap); 
# 854
} 
#endif
# 856 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(unsigned char val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 857
{int volatile ___ = 1;
# 859
exit(___);}
#if 0
# 857
{ 
# 858
__surf1Dwritec1(make_uchar1(val), surf, x, cudaBoundaryModeTrap); 
# 859
} 
#endif
# 861 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(char1 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 862
{int volatile ___ = 1;
# 864
exit(___);}
#if 0
# 862
{ 
# 863
__surf1Dwritec1(make_uchar1((unsigned char)(val.x)), surf, x, cudaBoundaryModeTrap); 
# 864
} 
#endif
# 866 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uchar1 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 867
{int volatile ___ = 1;
# 869
exit(___);}
#if 0
# 867
{ 
# 868
__surf1Dwritec1(val, surf, x, cudaBoundaryModeTrap); 
# 869
} 
#endif
# 871 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(char2 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 872
{int volatile ___ = 1;
# 874
exit(___);}
#if 0
# 872
{ 
# 873
__surf1Dwritec2(make_uchar2((unsigned char)(val.x), (unsigned char)(val.y)), surf, x, cudaBoundaryModeTrap); 
# 874
} 
#endif
# 876 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uchar2 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 877
{int volatile ___ = 1;
# 879
exit(___);}
#if 0
# 877
{ 
# 878
__surf1Dwritec2(val, surf, x, cudaBoundaryModeTrap); 
# 879
} 
#endif
# 881 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(char4 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 882
{int volatile ___ = 1;
# 884
exit(___);}
#if 0
# 882
{ 
# 883
__surf1Dwritec4(make_uchar4((unsigned char)(val.x), (unsigned char)(val.y), (unsigned char)(val.z), (unsigned char)(val.w)), surf, x, cudaBoundaryModeTrap); 
# 884
} 
#endif
# 886 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uchar4 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 887
{int volatile ___ = 1;
# 889
exit(___);}
#if 0
# 887
{ 
# 888
__surf1Dwritec4(val, surf, x, cudaBoundaryModeTrap); 
# 889
} 
#endif
# 891 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(short val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 892
{int volatile ___ = 1;
# 894
exit(___);}
#if 0
# 892
{ 
# 893
__surf1Dwrites1(make_ushort1((unsigned short)val), surf, x, cudaBoundaryModeTrap); 
# 894
} 
#endif
# 896 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(unsigned short val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 897
{int volatile ___ = 1;
# 899
exit(___);}
#if 0
# 897
{ 
# 898
__surf1Dwrites1(make_ushort1(val), surf, x, cudaBoundaryModeTrap); 
# 899
} 
#endif
# 901 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(short1 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 902
{int volatile ___ = 1;
# 904
exit(___);}
#if 0
# 902
{ 
# 903
__surf1Dwrites1(make_ushort1((unsigned short)(val.x)), surf, x, cudaBoundaryModeTrap); 
# 904
} 
#endif
# 906 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ushort1 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 907
{int volatile ___ = 1;
# 909
exit(___);}
#if 0
# 907
{ 
# 908
__surf1Dwrites1(val, surf, x, cudaBoundaryModeTrap); 
# 909
} 
#endif
# 911 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(short2 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 912
{int volatile ___ = 1;
# 914
exit(___);}
#if 0
# 912
{ 
# 913
__surf1Dwrites2(make_ushort2((unsigned short)(val.x), (unsigned short)(val.y)), surf, x, cudaBoundaryModeTrap); 
# 914
} 
#endif
# 916 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ushort2 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 917
{int volatile ___ = 1;
# 919
exit(___);}
#if 0
# 917
{ 
# 918
__surf1Dwrites2(val, surf, x, cudaBoundaryModeTrap); 
# 919
} 
#endif
# 921 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(short4 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 922
{int volatile ___ = 1;
# 924
exit(___);}
#if 0
# 922
{ 
# 923
__surf1Dwrites4(make_ushort4((unsigned short)(val.x), (unsigned short)(val.y), (unsigned short)(val.z), (unsigned short)(val.w)), surf, x, cudaBoundaryModeTrap); 
# 924
} 
#endif
# 926 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ushort4 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 927
{int volatile ___ = 1;
# 929
exit(___);}
#if 0
# 927
{ 
# 928
__surf1Dwrites4(val, surf, x, cudaBoundaryModeTrap); 
# 929
} 
#endif
# 931 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(int val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 932
{int volatile ___ = 1;
# 934
exit(___);}
#if 0
# 932
{ 
# 933
__surf1Dwriteu1(make_uint1((unsigned)val), surf, x, cudaBoundaryModeTrap); 
# 934
} 
#endif
# 936 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(unsigned val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 937
{int volatile ___ = 1;
# 939
exit(___);}
#if 0
# 937
{ 
# 938
__surf1Dwriteu1(make_uint1(val), surf, x, cudaBoundaryModeTrap); 
# 939
} 
#endif
# 941 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(int1 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 942
{int volatile ___ = 1;
# 944
exit(___);}
#if 0
# 942
{ 
# 943
__surf1Dwriteu1(make_uint1((unsigned)(val.x)), surf, x, cudaBoundaryModeTrap); 
# 944
} 
#endif
# 946 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uint1 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 947
{int volatile ___ = 1;
# 949
exit(___);}
#if 0
# 947
{ 
# 948
__surf1Dwriteu1(val, surf, x, cudaBoundaryModeTrap); 
# 949
} 
#endif
# 951 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(int2 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 952
{int volatile ___ = 1;
# 954
exit(___);}
#if 0
# 952
{ 
# 953
__surf1Dwriteu2(make_uint2((unsigned)(val.x), (unsigned)(val.y)), surf, x, cudaBoundaryModeTrap); 
# 954
} 
#endif
# 956 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uint2 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 957
{int volatile ___ = 1;
# 959
exit(___);}
#if 0
# 957
{ 
# 958
__surf1Dwriteu2(val, surf, x, cudaBoundaryModeTrap); 
# 959
} 
#endif
# 961 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(int4 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 962
{int volatile ___ = 1;
# 964
exit(___);}
#if 0
# 962
{ 
# 963
__surf1Dwriteu4(make_uint4((unsigned)(val.x), (unsigned)(val.y), (unsigned)(val.z), (unsigned)(val.w)), surf, x, cudaBoundaryModeTrap); 
# 964
} 
#endif
# 966 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(uint4 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 967
{int volatile ___ = 1;
# 969
exit(___);}
#if 0
# 967
{ 
# 968
__surf1Dwriteu4(val, surf, x, cudaBoundaryModeTrap); 
# 969
} 
#endif
# 971 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(long long val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 972
{int volatile ___ = 1;
# 974
exit(___);}
#if 0
# 972
{ 
# 973
__surf1Dwritel1(make_ulonglong1((unsigned long long)val), surf, x, cudaBoundaryModeTrap); 
# 974
} 
#endif
# 976 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(unsigned long long val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 977
{int volatile ___ = 1;
# 979
exit(___);}
#if 0
# 977
{ 
# 978
__surf1Dwritel1(make_ulonglong1(val), surf, x, cudaBoundaryModeTrap); 
# 979
} 
#endif
# 981 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(longlong1 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 982
{int volatile ___ = 1;
# 984
exit(___);}
#if 0
# 982
{ 
# 983
__surf1Dwritel1(make_ulonglong1((unsigned long long)(val.x)), surf, x, cudaBoundaryModeTrap); 
# 984
} 
#endif
# 986 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ulonglong1 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 987
{int volatile ___ = 1;
# 989
exit(___);}
#if 0
# 987
{ 
# 988
__surf1Dwritel1(val, surf, x, cudaBoundaryModeTrap); 
# 989
} 
#endif
# 991 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(longlong2 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 992
{int volatile ___ = 1;
# 994
exit(___);}
#if 0
# 992
{ 
# 993
__surf1Dwritel2(make_ulonglong2((unsigned long long)(val.x), (unsigned long long)(val.y)), surf, x, cudaBoundaryModeTrap); 
# 994
} 
#endif
# 996 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(ulonglong2 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 997
{int volatile ___ = 1;
# 999
exit(___);}
#if 0
# 997
{ 
# 998
__surf1Dwritel2(val, surf, x, cudaBoundaryModeTrap); 
# 999
} 
#endif
# 1045 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(float val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 1046
{int volatile ___ = 1;
# 1048
exit(___);}
#if 0
# 1046
{ 
# 1047
__surf1Dwriteu1(make_uint1((unsigned)__float_as_int(val)), surf, x, cudaBoundaryModeTrap); 
# 1048
} 
#endif
# 1050 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(float1 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 1051
{int volatile ___ = 1;
# 1053
exit(___);}
#if 0
# 1051
{ 
# 1052
__surf1Dwriteu1(make_uint1((unsigned)__float_as_int(val.x)), surf, x, cudaBoundaryModeTrap); 
# 1053
} 
#endif
# 1055 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(float2 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 1056
{int volatile ___ = 1;
# 1058
exit(___);}
#if 0
# 1056
{ 
# 1057
__surf1Dwriteu2(make_uint2((unsigned)__float_as_int(val.x), __float_as_int((unsigned)(val.y))), surf, x, cudaBoundaryModeTrap); 
# 1058
} 
#endif
# 1060 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf1Dwrite(float4 val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode) 
# 1061
{int volatile ___ = 1;
# 1063
exit(___);}
#if 0
# 1061
{ 
# 1062
__surf1Dwriteu4(make_uint4((unsigned)__float_as_int(val.x), (unsigned)__float_as_int(val.y), (unsigned)__float_as_int(val.z), (unsigned)__float_as_int(val.w)), surf, x, cudaBoundaryModeTrap); 
# 1063
} 
#endif
# 1110 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void 
# 1111
surf2Dwrite(T val, surface< void, 2>  surf, int x, int y, int s, cudaSurfaceBoundaryMode mode) 
# 1112
{int volatile ___ = 1;
# 1130
exit(___);}
#if 0
# 1112
{ 
# 1113
union { 
# 1114
T val; 
# 1115
uchar1 c1; 
# 1116
ushort1 s1; 
# 1117
uint1 u1; 
# 1118
uint2 u2; 
# 1119
uint4 u4; 
# 1120
} tmp; 
# 1122
(tmp.val) = val; 
# 1124
(s == 1) ? ((void)__surf2Dwritec1(tmp.c1, surf, x, y, cudaBoundaryModeTrap)) : ((s == 2) ? ((void)__surf2Dwrites1(tmp.s1, surf, x, y, cudaBoundaryModeTrap)) : ((s == 4) ? ((void)__surf2Dwriteu1(tmp.u1, surf, x, y, cudaBoundaryModeTrap)) : ((s == 8) ? ((void)__surf2Dwriteu2(tmp.u2, surf, x, y, cudaBoundaryModeTrap)) : ((s == 16) ? ((void)__surf2Dwriteu4(tmp.u4, surf, x, y, cudaBoundaryModeTrap)) : ((void)0))))); 
# 1130
} 
#endif
# 1132 "/usr/local/cuda/bin/../include/surface_functions.h"
template<class T> static __attribute__((unused)) inline void 
# 1133
surf2Dwrite(T val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1134
{int volatile ___ = 1;
# 1136
exit(___);}
#if 0
# 1134
{ ; 
# 1135
surf2Dwrite(val, surf, x, y, (int)sizeof(T), mode); 
# 1136
} 
#endif
# 1139 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(char val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1140
{int volatile ___ = 1;
# 1142
exit(___);}
#if 0
# 1140
{ 
# 1141
__surf2Dwritec1(make_uchar1((unsigned char)val), surf, x, y, cudaBoundaryModeTrap); 
# 1142
} 
#endif
# 1144 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(signed char val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1145
{int volatile ___ = 1;
# 1147
exit(___);}
#if 0
# 1145
{ 
# 1146
__surf2Dwritec1(make_uchar1((unsigned char)val), surf, x, y, cudaBoundaryModeTrap); 
# 1147
} 
#endif
# 1149 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(unsigned char val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1150
{int volatile ___ = 1;
# 1152
exit(___);}
#if 0
# 1150
{ 
# 1151
__surf2Dwritec1(make_uchar1(val), surf, x, y, cudaBoundaryModeTrap); 
# 1152
} 
#endif
# 1154 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(char1 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1155
{int volatile ___ = 1;
# 1157
exit(___);}
#if 0
# 1155
{ 
# 1156
__surf2Dwritec1(make_uchar1((unsigned char)(val.x)), surf, x, y, cudaBoundaryModeTrap); 
# 1157
} 
#endif
# 1159 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uchar1 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1160
{int volatile ___ = 1;
# 1162
exit(___);}
#if 0
# 1160
{ 
# 1161
__surf2Dwritec1(val, surf, x, y, cudaBoundaryModeTrap); 
# 1162
} 
#endif
# 1164 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(char2 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1165
{int volatile ___ = 1;
# 1167
exit(___);}
#if 0
# 1165
{ 
# 1166
__surf2Dwritec2(make_uchar2((unsigned char)(val.x), (unsigned char)(val.y)), surf, x, y, cudaBoundaryModeTrap); 
# 1167
} 
#endif
# 1169 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uchar2 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1170
{int volatile ___ = 1;
# 1172
exit(___);}
#if 0
# 1170
{ 
# 1171
__surf2Dwritec2(val, surf, x, y, cudaBoundaryModeTrap); 
# 1172
} 
#endif
# 1174 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(char4 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1175
{int volatile ___ = 1;
# 1177
exit(___);}
#if 0
# 1175
{ 
# 1176
__surf2Dwritec4(make_uchar4((unsigned char)(val.x), (unsigned char)(val.y), (unsigned char)(val.z), (unsigned char)(val.w)), surf, x, y, cudaBoundaryModeTrap); 
# 1177
} 
#endif
# 1179 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uchar4 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1180
{int volatile ___ = 1;
# 1182
exit(___);}
#if 0
# 1180
{ 
# 1181
__surf2Dwritec4(val, surf, x, y, cudaBoundaryModeTrap); 
# 1182
} 
#endif
# 1184 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(short val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1185
{int volatile ___ = 1;
# 1187
exit(___);}
#if 0
# 1185
{ 
# 1186
__surf2Dwrites1(make_ushort1((unsigned short)val), surf, x, y, cudaBoundaryModeTrap); 
# 1187
} 
#endif
# 1189 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(unsigned short val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1190
{int volatile ___ = 1;
# 1192
exit(___);}
#if 0
# 1190
{ 
# 1191
__surf2Dwrites1(make_ushort1(val), surf, x, y, cudaBoundaryModeTrap); 
# 1192
} 
#endif
# 1194 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(short1 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1195
{int volatile ___ = 1;
# 1197
exit(___);}
#if 0
# 1195
{ 
# 1196
__surf2Dwrites1(make_ushort1((unsigned short)(val.x)), surf, x, y, cudaBoundaryModeTrap); 
# 1197
} 
#endif
# 1199 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ushort1 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1200
{int volatile ___ = 1;
# 1202
exit(___);}
#if 0
# 1200
{ 
# 1201
__surf2Dwrites1(val, surf, x, y, cudaBoundaryModeTrap); 
# 1202
} 
#endif
# 1204 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(short2 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1205
{int volatile ___ = 1;
# 1207
exit(___);}
#if 0
# 1205
{ 
# 1206
__surf2Dwrites2(make_ushort2((unsigned short)(val.x), (unsigned short)(val.y)), surf, x, y, cudaBoundaryModeTrap); 
# 1207
} 
#endif
# 1209 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ushort2 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1210
{int volatile ___ = 1;
# 1212
exit(___);}
#if 0
# 1210
{ 
# 1211
__surf2Dwrites2(val, surf, x, y, cudaBoundaryModeTrap); 
# 1212
} 
#endif
# 1214 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(short4 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1215
{int volatile ___ = 1;
# 1217
exit(___);}
#if 0
# 1215
{ 
# 1216
__surf2Dwrites4(make_ushort4((unsigned short)(val.x), (unsigned short)(val.y), (unsigned short)(val.z), (unsigned short)(val.w)), surf, x, y, cudaBoundaryModeTrap); 
# 1217
} 
#endif
# 1219 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ushort4 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1220
{int volatile ___ = 1;
# 1222
exit(___);}
#if 0
# 1220
{ 
# 1221
__surf2Dwrites4(val, surf, x, y, cudaBoundaryModeTrap); 
# 1222
} 
#endif
# 1224 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(int val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1225
{int volatile ___ = 1;
# 1227
exit(___);}
#if 0
# 1225
{ 
# 1226
__surf2Dwriteu1(make_uint1((unsigned)val), surf, x, y, cudaBoundaryModeTrap); 
# 1227
} 
#endif
# 1229 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(unsigned val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1230
{int volatile ___ = 1;
# 1232
exit(___);}
#if 0
# 1230
{ 
# 1231
__surf2Dwriteu1(make_uint1(val), surf, x, y, cudaBoundaryModeTrap); 
# 1232
} 
#endif
# 1234 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(int1 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1235
{int volatile ___ = 1;
# 1237
exit(___);}
#if 0
# 1235
{ 
# 1236
__surf2Dwriteu1(make_uint1((unsigned)(val.x)), surf, x, y, cudaBoundaryModeTrap); 
# 1237
} 
#endif
# 1239 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uint1 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1240
{int volatile ___ = 1;
# 1242
exit(___);}
#if 0
# 1240
{ 
# 1241
__surf2Dwriteu1(val, surf, x, y, cudaBoundaryModeTrap); 
# 1242
} 
#endif
# 1244 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(int2 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1245
{int volatile ___ = 1;
# 1247
exit(___);}
#if 0
# 1245
{ 
# 1246
__surf2Dwriteu2(make_uint2((unsigned)(val.x), (unsigned)(val.y)), surf, x, y, cudaBoundaryModeTrap); 
# 1247
} 
#endif
# 1249 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uint2 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1250
{int volatile ___ = 1;
# 1252
exit(___);}
#if 0
# 1250
{ 
# 1251
__surf2Dwriteu2(val, surf, x, y, cudaBoundaryModeTrap); 
# 1252
} 
#endif
# 1254 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(int4 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1255
{int volatile ___ = 1;
# 1257
exit(___);}
#if 0
# 1255
{ 
# 1256
__surf2Dwriteu4(make_uint4((unsigned)(val.x), (unsigned)(val.y), (unsigned)(val.z), (unsigned)(val.w)), surf, x, y, cudaBoundaryModeTrap); 
# 1257
} 
#endif
# 1259 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(uint4 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1260
{int volatile ___ = 1;
# 1262
exit(___);}
#if 0
# 1260
{ 
# 1261
__surf2Dwriteu4(val, surf, x, y, cudaBoundaryModeTrap); 
# 1262
} 
#endif
# 1264 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(long long val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1265
{int volatile ___ = 1;
# 1267
exit(___);}
#if 0
# 1265
{ 
# 1266
__surf2Dwritel1(make_ulonglong1((unsigned long long)val), surf, x, y, cudaBoundaryModeTrap); 
# 1267
} 
#endif
# 1269 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(unsigned long long val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1270
{int volatile ___ = 1;
# 1272
exit(___);}
#if 0
# 1270
{ 
# 1271
__surf2Dwritel1(make_ulonglong1(val), surf, x, y, cudaBoundaryModeTrap); 
# 1272
} 
#endif
# 1274 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(longlong1 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1275
{int volatile ___ = 1;
# 1277
exit(___);}
#if 0
# 1275
{ 
# 1276
__surf2Dwritel1(make_ulonglong1((unsigned long long)(val.x)), surf, x, y, cudaBoundaryModeTrap); 
# 1277
} 
#endif
# 1279 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ulonglong1 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1280
{int volatile ___ = 1;
# 1282
exit(___);}
#if 0
# 1280
{ 
# 1281
__surf2Dwritel1(val, surf, x, y, cudaBoundaryModeTrap); 
# 1282
} 
#endif
# 1284 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(longlong2 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1285
{int volatile ___ = 1;
# 1287
exit(___);}
#if 0
# 1285
{ 
# 1286
__surf2Dwritel2(make_ulonglong2((unsigned long long)(val.x), (unsigned long long)(val.y)), surf, x, y, cudaBoundaryModeTrap); 
# 1287
} 
#endif
# 1289 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(ulonglong2 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1290
{int volatile ___ = 1;
# 1292
exit(___);}
#if 0
# 1290
{ 
# 1291
__surf2Dwritel2(val, surf, x, y, cudaBoundaryModeTrap); 
# 1292
} 
#endif
# 1338 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(float val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1339
{int volatile ___ = 1;
# 1341
exit(___);}
#if 0
# 1339
{ 
# 1340
__surf2Dwriteu1(make_uint1((unsigned)__float_as_int(val)), surf, x, y, cudaBoundaryModeTrap); 
# 1341
} 
#endif
# 1343 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(float1 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1344
{int volatile ___ = 1;
# 1346
exit(___);}
#if 0
# 1344
{ 
# 1345
__surf2Dwriteu1(make_uint1((unsigned)__float_as_int(val.x)), surf, x, y, cudaBoundaryModeTrap); 
# 1346
} 
#endif
# 1348 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(float2 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1349
{int volatile ___ = 1;
# 1351
exit(___);}
#if 0
# 1349
{ 
# 1350
__surf2Dwriteu2(make_uint2((unsigned)__float_as_int(val.x), __float_as_int((unsigned)(val.y))), surf, x, y, cudaBoundaryModeTrap); 
# 1351
} 
#endif
# 1353 "/usr/local/cuda/bin/../include/surface_functions.h"
static __attribute__((unused)) inline void surf2Dwrite(float4 val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode) 
# 1354
{int volatile ___ = 1;
# 1356
exit(___);}
#if 0
# 1354
{ 
# 1355
__surf2Dwriteu4(make_uint4((unsigned)__float_as_int(val.x), (unsigned)__float_as_int(val.y), (unsigned)__float_as_int(val.z), (unsigned)__float_as_int(val.w)), surf, x, y, cudaBoundaryModeTrap); 
# 1356
} 
#endif
# 61 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
template<class T, cudaTextureReadMode readMode> extern __attribute__((unused)) uint4 __utexfetchi(texture< T, 1, readMode> , int4); 
# 63
template<class T, cudaTextureReadMode readMode> extern __attribute__((unused)) int4 __itexfetchi(texture< T, 1, readMode> , int4); 
# 65
template<class T, cudaTextureReadMode readMode> extern __attribute__((unused)) float4 __ftexfetchi(texture< T, 1, readMode> , int4); 
# 68
template<class T, int dim, cudaTextureReadMode readMode> extern __attribute__((unused)) uint4 __utexfetch(texture< T, dim, readMode> , float4, int); 
# 70
template<class T, int dim, cudaTextureReadMode readMode> extern __attribute__((unused)) int4 __itexfetch(texture< T, dim, readMode> , float4, int); 
# 72
template<class T, int dim, cudaTextureReadMode readMode> extern __attribute__((unused)) float4 __ftexfetch(texture< T, dim, readMode> , float4, int); 
# 80
static __attribute__((unused)) inline char tex1Dfetch(texture< char, 1, cudaReadModeElementType>  t, int x) 
# 81
{int volatile ___ = 1;
# 89
exit(___);}
#if 0
# 81
{ 
# 85
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 88
return (char)(v.x); 
# 89
} 
#endif
# 91 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline signed char tex1Dfetch(texture< signed char, 1, cudaReadModeElementType>  t, int x) 
# 92
{int volatile ___ = 1;
# 96
exit(___);}
#if 0
# 92
{ 
# 93
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 95
return (signed char)(v.x); 
# 96
} 
#endif
# 98 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned char tex1Dfetch(texture< unsigned char, 1, cudaReadModeElementType>  t, int x) 
# 99
{int volatile ___ = 1;
# 103
exit(___);}
#if 0
# 99
{ 
# 100
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 102
return (unsigned char)(v.x); 
# 103
} 
#endif
# 105 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char1 tex1Dfetch(texture< char1, 1, cudaReadModeElementType>  t, int x) 
# 106
{int volatile ___ = 1;
# 110
exit(___);}
#if 0
# 106
{ 
# 107
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 109
return make_char1(v.x); 
# 110
} 
#endif
# 112 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar1 tex1Dfetch(texture< uchar1, 1, cudaReadModeElementType>  t, int x) 
# 113
{int volatile ___ = 1;
# 117
exit(___);}
#if 0
# 113
{ 
# 114
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 116
return make_uchar1(v.x); 
# 117
} 
#endif
# 119 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char2 tex1Dfetch(texture< char2, 1, cudaReadModeElementType>  t, int x) 
# 120
{int volatile ___ = 1;
# 124
exit(___);}
#if 0
# 120
{ 
# 121
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 123
return make_char2(v.x, v.y); 
# 124
} 
#endif
# 126 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar2 tex1Dfetch(texture< uchar2, 1, cudaReadModeElementType>  t, int x) 
# 127
{int volatile ___ = 1;
# 131
exit(___);}
#if 0
# 127
{ 
# 128
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 130
return make_uchar2(v.x, v.y); 
# 131
} 
#endif
# 133 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char4 tex1Dfetch(texture< char4, 1, cudaReadModeElementType>  t, int x) 
# 134
{int volatile ___ = 1;
# 138
exit(___);}
#if 0
# 134
{ 
# 135
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 137
return make_char4(v.x, v.y, v.z, v.w); 
# 138
} 
#endif
# 140 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar4 tex1Dfetch(texture< uchar4, 1, cudaReadModeElementType>  t, int x) 
# 141
{int volatile ___ = 1;
# 145
exit(___);}
#if 0
# 141
{ 
# 142
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 144
return make_uchar4(v.x, v.y, v.z, v.w); 
# 145
} 
#endif
# 153 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short tex1Dfetch(texture< short, 1, cudaReadModeElementType>  t, int x) 
# 154
{int volatile ___ = 1;
# 158
exit(___);}
#if 0
# 154
{ 
# 155
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 157
return (short)(v.x); 
# 158
} 
#endif
# 160 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned short tex1Dfetch(texture< unsigned short, 1, cudaReadModeElementType>  t, int x) 
# 161
{int volatile ___ = 1;
# 165
exit(___);}
#if 0
# 161
{ 
# 162
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 164
return (unsigned short)(v.x); 
# 165
} 
#endif
# 167 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short1 tex1Dfetch(texture< short1, 1, cudaReadModeElementType>  t, int x) 
# 168
{int volatile ___ = 1;
# 172
exit(___);}
#if 0
# 168
{ 
# 169
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 171
return make_short1(v.x); 
# 172
} 
#endif
# 174 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort1 tex1Dfetch(texture< ushort1, 1, cudaReadModeElementType>  t, int x) 
# 175
{int volatile ___ = 1;
# 179
exit(___);}
#if 0
# 175
{ 
# 176
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 178
return make_ushort1(v.x); 
# 179
} 
#endif
# 181 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short2 tex1Dfetch(texture< short2, 1, cudaReadModeElementType>  t, int x) 
# 182
{int volatile ___ = 1;
# 186
exit(___);}
#if 0
# 182
{ 
# 183
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 185
return make_short2(v.x, v.y); 
# 186
} 
#endif
# 188 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort2 tex1Dfetch(texture< ushort2, 1, cudaReadModeElementType>  t, int x) 
# 189
{int volatile ___ = 1;
# 193
exit(___);}
#if 0
# 189
{ 
# 190
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 192
return make_ushort2(v.x, v.y); 
# 193
} 
#endif
# 195 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short4 tex1Dfetch(texture< short4, 1, cudaReadModeElementType>  t, int x) 
# 196
{int volatile ___ = 1;
# 200
exit(___);}
#if 0
# 196
{ 
# 197
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 199
return make_short4(v.x, v.y, v.z, v.w); 
# 200
} 
#endif
# 202 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort4 tex1Dfetch(texture< ushort4, 1, cudaReadModeElementType>  t, int x) 
# 203
{int volatile ___ = 1;
# 207
exit(___);}
#if 0
# 203
{ 
# 204
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 206
return make_ushort4(v.x, v.y, v.z, v.w); 
# 207
} 
#endif
# 215 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int tex1Dfetch(texture< int, 1, cudaReadModeElementType>  t, int x) 
# 216
{int volatile ___ = 1;
# 220
exit(___);}
#if 0
# 216
{ 
# 217
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 219
return (int)(v.x); 
# 220
} 
#endif
# 222 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned tex1Dfetch(texture< unsigned, 1, cudaReadModeElementType>  t, int x) 
# 223
{int volatile ___ = 1;
# 227
exit(___);}
#if 0
# 223
{ 
# 224
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 226
return (unsigned)(v.x); 
# 227
} 
#endif
# 229 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int1 tex1Dfetch(texture< int1, 1, cudaReadModeElementType>  t, int x) 
# 230
{int volatile ___ = 1;
# 234
exit(___);}
#if 0
# 230
{ 
# 231
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 233
return make_int1(v.x); 
# 234
} 
#endif
# 236 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint1 tex1Dfetch(texture< uint1, 1, cudaReadModeElementType>  t, int x) 
# 237
{int volatile ___ = 1;
# 241
exit(___);}
#if 0
# 237
{ 
# 238
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 240
return make_uint1(v.x); 
# 241
} 
#endif
# 243 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int2 tex1Dfetch(texture< int2, 1, cudaReadModeElementType>  t, int x) 
# 244
{int volatile ___ = 1;
# 248
exit(___);}
#if 0
# 244
{ 
# 245
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 247
return make_int2(v.x, v.y); 
# 248
} 
#endif
# 250 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint2 tex1Dfetch(texture< uint2, 1, cudaReadModeElementType>  t, int x) 
# 251
{int volatile ___ = 1;
# 255
exit(___);}
#if 0
# 251
{ 
# 252
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 254
return make_uint2(v.x, v.y); 
# 255
} 
#endif
# 257 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int4 tex1Dfetch(texture< int4, 1, cudaReadModeElementType>  t, int x) 
# 258
{int volatile ___ = 1;
# 262
exit(___);}
#if 0
# 258
{ 
# 259
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 261
return make_int4(v.x, v.y, v.z, v.w); 
# 262
} 
#endif
# 264 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint4 tex1Dfetch(texture< uint4, 1, cudaReadModeElementType>  t, int x) 
# 265
{int volatile ___ = 1;
# 269
exit(___);}
#if 0
# 265
{ 
# 266
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 268
return make_uint4(v.x, v.y, v.z, v.w); 
# 269
} 
#endif
# 343 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< float, 1, cudaReadModeElementType>  t, int x) 
# 344
{int volatile ___ = 1;
# 348
exit(___);}
#if 0
# 344
{ 
# 345
float4 v = __ftexfetchi(t, make_int4(x, 0, 0, 0)); 
# 347
return v.x; 
# 348
} 
#endif
# 350 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1Dfetch(texture< float1, 1, cudaReadModeElementType>  t, int x) 
# 351
{int volatile ___ = 1;
# 355
exit(___);}
#if 0
# 351
{ 
# 352
float4 v = __ftexfetchi(t, make_int4(x, 0, 0, 0)); 
# 354
return make_float1(v.x); 
# 355
} 
#endif
# 357 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1Dfetch(texture< float2, 1, cudaReadModeElementType>  t, int x) 
# 358
{int volatile ___ = 1;
# 362
exit(___);}
#if 0
# 358
{ 
# 359
float4 v = __ftexfetchi(t, make_int4(x, 0, 0, 0)); 
# 361
return make_float2(v.x, v.y); 
# 362
} 
#endif
# 364 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1Dfetch(texture< float4, 1, cudaReadModeElementType>  t, int x) 
# 365
{int volatile ___ = 1;
# 369
exit(___);}
#if 0
# 365
{ 
# 366
float4 v = __ftexfetchi(t, make_int4(x, 0, 0, 0)); 
# 368
return make_float4(v.x, v.y, v.z, v.w); 
# 369
} 
#endif
# 377 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< char, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 378
{int volatile ___ = 1;
# 387
exit(___);}
#if 0
# 378
{ 
# 382
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 384
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 386
return w.x; 
# 387
} 
#endif
# 389 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< signed char, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 390
{int volatile ___ = 1;
# 395
exit(___);}
#if 0
# 390
{ 
# 391
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 392
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 394
return w.x; 
# 395
} 
#endif
# 397 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< unsigned char, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 398
{int volatile ___ = 1;
# 403
exit(___);}
#if 0
# 398
{ 
# 399
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 400
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 402
return w.x; 
# 403
} 
#endif
# 405 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1Dfetch(texture< char1, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 406
{int volatile ___ = 1;
# 411
exit(___);}
#if 0
# 406
{ 
# 407
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 408
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 410
return make_float1(w.x); 
# 411
} 
#endif
# 413 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1Dfetch(texture< uchar1, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 414
{int volatile ___ = 1;
# 419
exit(___);}
#if 0
# 414
{ 
# 415
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 416
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 418
return make_float1(w.x); 
# 419
} 
#endif
# 421 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1Dfetch(texture< char2, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 422
{int volatile ___ = 1;
# 427
exit(___);}
#if 0
# 422
{ 
# 423
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 424
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 426
return make_float2(w.x, w.y); 
# 427
} 
#endif
# 429 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1Dfetch(texture< uchar2, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 430
{int volatile ___ = 1;
# 435
exit(___);}
#if 0
# 430
{ 
# 431
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 432
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 434
return make_float2(w.x, w.y); 
# 435
} 
#endif
# 437 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1Dfetch(texture< char4, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 438
{int volatile ___ = 1;
# 443
exit(___);}
#if 0
# 438
{ 
# 439
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 440
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 442
return make_float4(w.x, w.y, w.z, w.w); 
# 443
} 
#endif
# 445 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1Dfetch(texture< uchar4, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 446
{int volatile ___ = 1;
# 451
exit(___);}
#if 0
# 446
{ 
# 447
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 448
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 450
return make_float4(w.x, w.y, w.z, w.w); 
# 451
} 
#endif
# 459 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< short, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 460
{int volatile ___ = 1;
# 465
exit(___);}
#if 0
# 460
{ 
# 461
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 462
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 464
return w.x; 
# 465
} 
#endif
# 467 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1Dfetch(texture< unsigned short, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 468
{int volatile ___ = 1;
# 473
exit(___);}
#if 0
# 468
{ 
# 469
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 470
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 472
return w.x; 
# 473
} 
#endif
# 475 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1Dfetch(texture< short1, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 476
{int volatile ___ = 1;
# 481
exit(___);}
#if 0
# 476
{ 
# 477
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 478
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 480
return make_float1(w.x); 
# 481
} 
#endif
# 483 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1Dfetch(texture< ushort1, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 484
{int volatile ___ = 1;
# 489
exit(___);}
#if 0
# 484
{ 
# 485
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 486
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 488
return make_float1(w.x); 
# 489
} 
#endif
# 491 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1Dfetch(texture< short2, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 492
{int volatile ___ = 1;
# 497
exit(___);}
#if 0
# 492
{ 
# 493
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 494
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 496
return make_float2(w.x, w.y); 
# 497
} 
#endif
# 499 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1Dfetch(texture< ushort2, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 500
{int volatile ___ = 1;
# 505
exit(___);}
#if 0
# 500
{ 
# 501
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 502
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 504
return make_float2(w.x, w.y); 
# 505
} 
#endif
# 507 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1Dfetch(texture< short4, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 508
{int volatile ___ = 1;
# 513
exit(___);}
#if 0
# 508
{ 
# 509
int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0)); 
# 510
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 512
return make_float4(w.x, w.y, w.z, w.w); 
# 513
} 
#endif
# 515 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1Dfetch(texture< ushort4, 1, cudaReadModeNormalizedFloat>  t, int x) 
# 516
{int volatile ___ = 1;
# 521
exit(___);}
#if 0
# 516
{ 
# 517
uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0)); 
# 518
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 520
return make_float4(w.x, w.y, w.z, w.w); 
# 521
} 
#endif
# 529 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char tex1D(texture< char, 1, cudaReadModeElementType>  t, float x) 
# 530
{int volatile ___ = 1;
# 538
exit(___);}
#if 0
# 530
{ 
# 534
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 537
return (char)(v.x); 
# 538
} 
#endif
# 540 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline signed char tex1D(texture< signed char, 1, cudaReadModeElementType>  t, float x) 
# 541
{int volatile ___ = 1;
# 545
exit(___);}
#if 0
# 541
{ 
# 542
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 544
return (signed char)(v.x); 
# 545
} 
#endif
# 547 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned char tex1D(texture< unsigned char, 1, cudaReadModeElementType>  t, float x) 
# 548
{int volatile ___ = 1;
# 552
exit(___);}
#if 0
# 548
{ 
# 549
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 551
return (unsigned char)(v.x); 
# 552
} 
#endif
# 554 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char1 tex1D(texture< char1, 1, cudaReadModeElementType>  t, float x) 
# 555
{int volatile ___ = 1;
# 559
exit(___);}
#if 0
# 555
{ 
# 556
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 558
return make_char1(v.x); 
# 559
} 
#endif
# 561 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar1 tex1D(texture< uchar1, 1, cudaReadModeElementType>  t, float x) 
# 562
{int volatile ___ = 1;
# 566
exit(___);}
#if 0
# 562
{ 
# 563
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 565
return make_uchar1(v.x); 
# 566
} 
#endif
# 568 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char2 tex1D(texture< char2, 1, cudaReadModeElementType>  t, float x) 
# 569
{int volatile ___ = 1;
# 573
exit(___);}
#if 0
# 569
{ 
# 570
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 572
return make_char2(v.x, v.y); 
# 573
} 
#endif
# 575 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar2 tex1D(texture< uchar2, 1, cudaReadModeElementType>  t, float x) 
# 576
{int volatile ___ = 1;
# 580
exit(___);}
#if 0
# 576
{ 
# 577
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 579
return make_uchar2(v.x, v.y); 
# 580
} 
#endif
# 582 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char4 tex1D(texture< char4, 1, cudaReadModeElementType>  t, float x) 
# 583
{int volatile ___ = 1;
# 587
exit(___);}
#if 0
# 583
{ 
# 584
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 586
return make_char4(v.x, v.y, v.z, v.w); 
# 587
} 
#endif
# 589 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar4 tex1D(texture< uchar4, 1, cudaReadModeElementType>  t, float x) 
# 590
{int volatile ___ = 1;
# 594
exit(___);}
#if 0
# 590
{ 
# 591
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 593
return make_uchar4(v.x, v.y, v.z, v.w); 
# 594
} 
#endif
# 602 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short tex1D(texture< short, 1, cudaReadModeElementType>  t, float x) 
# 603
{int volatile ___ = 1;
# 607
exit(___);}
#if 0
# 603
{ 
# 604
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 606
return (short)(v.x); 
# 607
} 
#endif
# 609 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned short tex1D(texture< unsigned short, 1, cudaReadModeElementType>  t, float x) 
# 610
{int volatile ___ = 1;
# 614
exit(___);}
#if 0
# 610
{ 
# 611
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 613
return (unsigned short)(v.x); 
# 614
} 
#endif
# 616 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short1 tex1D(texture< short1, 1, cudaReadModeElementType>  t, float x) 
# 617
{int volatile ___ = 1;
# 621
exit(___);}
#if 0
# 617
{ 
# 618
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 620
return make_short1(v.x); 
# 621
} 
#endif
# 623 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort1 tex1D(texture< ushort1, 1, cudaReadModeElementType>  t, float x) 
# 624
{int volatile ___ = 1;
# 628
exit(___);}
#if 0
# 624
{ 
# 625
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 627
return make_ushort1(v.x); 
# 628
} 
#endif
# 630 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short2 tex1D(texture< short2, 1, cudaReadModeElementType>  t, float x) 
# 631
{int volatile ___ = 1;
# 635
exit(___);}
#if 0
# 631
{ 
# 632
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 634
return make_short2(v.x, v.y); 
# 635
} 
#endif
# 637 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort2 tex1D(texture< ushort2, 1, cudaReadModeElementType>  t, float x) 
# 638
{int volatile ___ = 1;
# 642
exit(___);}
#if 0
# 638
{ 
# 639
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 641
return make_ushort2(v.x, v.y); 
# 642
} 
#endif
# 644 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short4 tex1D(texture< short4, 1, cudaReadModeElementType>  t, float x) 
# 645
{int volatile ___ = 1;
# 649
exit(___);}
#if 0
# 645
{ 
# 646
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 648
return make_short4(v.x, v.y, v.z, v.w); 
# 649
} 
#endif
# 651 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort4 tex1D(texture< ushort4, 1, cudaReadModeElementType>  t, float x) 
# 652
{int volatile ___ = 1;
# 656
exit(___);}
#if 0
# 652
{ 
# 653
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 655
return make_ushort4(v.x, v.y, v.z, v.w); 
# 656
} 
#endif
# 664 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int tex1D(texture< int, 1, cudaReadModeElementType>  t, float x) 
# 665
{int volatile ___ = 1;
# 669
exit(___);}
#if 0
# 665
{ 
# 666
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 668
return (int)(v.x); 
# 669
} 
#endif
# 671 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned tex1D(texture< unsigned, 1, cudaReadModeElementType>  t, float x) 
# 672
{int volatile ___ = 1;
# 676
exit(___);}
#if 0
# 672
{ 
# 673
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 675
return (unsigned)(v.x); 
# 676
} 
#endif
# 678 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int1 tex1D(texture< int1, 1, cudaReadModeElementType>  t, float x) 
# 679
{int volatile ___ = 1;
# 683
exit(___);}
#if 0
# 679
{ 
# 680
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 682
return make_int1(v.x); 
# 683
} 
#endif
# 685 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint1 tex1D(texture< uint1, 1, cudaReadModeElementType>  t, float x) 
# 686
{int volatile ___ = 1;
# 690
exit(___);}
#if 0
# 686
{ 
# 687
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 689
return make_uint1(v.x); 
# 690
} 
#endif
# 692 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int2 tex1D(texture< int2, 1, cudaReadModeElementType>  t, float x) 
# 693
{int volatile ___ = 1;
# 697
exit(___);}
#if 0
# 693
{ 
# 694
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 696
return make_int2(v.x, v.y); 
# 697
} 
#endif
# 699 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint2 tex1D(texture< uint2, 1, cudaReadModeElementType>  t, float x) 
# 700
{int volatile ___ = 1;
# 704
exit(___);}
#if 0
# 700
{ 
# 701
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 703
return make_uint2(v.x, v.y); 
# 704
} 
#endif
# 706 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int4 tex1D(texture< int4, 1, cudaReadModeElementType>  t, float x) 
# 707
{int volatile ___ = 1;
# 711
exit(___);}
#if 0
# 707
{ 
# 708
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 710
return make_int4(v.x, v.y, v.z, v.w); 
# 711
} 
#endif
# 713 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint4 tex1D(texture< uint4, 1, cudaReadModeElementType>  t, float x) 
# 714
{int volatile ___ = 1;
# 718
exit(___);}
#if 0
# 714
{ 
# 715
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 717
return make_uint4(v.x, v.y, v.z, v.w); 
# 718
} 
#endif
# 798 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< float, 1, cudaReadModeElementType>  t, float x) 
# 799
{int volatile ___ = 1;
# 803
exit(___);}
#if 0
# 799
{ 
# 800
float4 v = __ftexfetch(t, make_float4(x, 0, 0, 0)); 
# 802
return v.x; 
# 803
} 
#endif
# 805 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1D(texture< float1, 1, cudaReadModeElementType>  t, float x) 
# 806
{int volatile ___ = 1;
# 810
exit(___);}
#if 0
# 806
{ 
# 807
float4 v = __ftexfetch(t, make_float4(x, 0, 0, 0)); 
# 809
return make_float1(v.x); 
# 810
} 
#endif
# 812 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1D(texture< float2, 1, cudaReadModeElementType>  t, float x) 
# 813
{int volatile ___ = 1;
# 817
exit(___);}
#if 0
# 813
{ 
# 814
float4 v = __ftexfetch(t, make_float4(x, 0, 0, 0)); 
# 816
return make_float2(v.x, v.y); 
# 817
} 
#endif
# 819 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1D(texture< float4, 1, cudaReadModeElementType>  t, float x) 
# 820
{int volatile ___ = 1;
# 824
exit(___);}
#if 0
# 820
{ 
# 821
float4 v = __ftexfetch(t, make_float4(x, 0, 0, 0)); 
# 823
return make_float4(v.x, v.y, v.z, v.w); 
# 824
} 
#endif
# 832 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< char, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 833
{int volatile ___ = 1;
# 842
exit(___);}
#if 0
# 833
{ 
# 837
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 839
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 841
return w.x; 
# 842
} 
#endif
# 844 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< signed char, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 845
{int volatile ___ = 1;
# 850
exit(___);}
#if 0
# 845
{ 
# 846
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 847
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 849
return w.x; 
# 850
} 
#endif
# 852 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< unsigned char, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 853
{int volatile ___ = 1;
# 858
exit(___);}
#if 0
# 853
{ 
# 854
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 855
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 857
return w.x; 
# 858
} 
#endif
# 860 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1D(texture< char1, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 861
{int volatile ___ = 1;
# 866
exit(___);}
#if 0
# 861
{ 
# 862
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 863
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 865
return make_float1(w.x); 
# 866
} 
#endif
# 868 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1D(texture< uchar1, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 869
{int volatile ___ = 1;
# 874
exit(___);}
#if 0
# 869
{ 
# 870
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 871
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 873
return make_float1(w.x); 
# 874
} 
#endif
# 876 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1D(texture< char2, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 877
{int volatile ___ = 1;
# 882
exit(___);}
#if 0
# 877
{ 
# 878
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 879
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 881
return make_float2(w.x, w.y); 
# 882
} 
#endif
# 884 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1D(texture< uchar2, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 885
{int volatile ___ = 1;
# 890
exit(___);}
#if 0
# 885
{ 
# 886
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 887
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 889
return make_float2(w.x, w.y); 
# 890
} 
#endif
# 892 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1D(texture< char4, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 893
{int volatile ___ = 1;
# 898
exit(___);}
#if 0
# 893
{ 
# 894
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 895
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 897
return make_float4(w.x, w.y, w.z, w.w); 
# 898
} 
#endif
# 900 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1D(texture< uchar4, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 901
{int volatile ___ = 1;
# 906
exit(___);}
#if 0
# 901
{ 
# 902
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 903
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 905
return make_float4(w.x, w.y, w.z, w.w); 
# 906
} 
#endif
# 914 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< short, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 915
{int volatile ___ = 1;
# 920
exit(___);}
#if 0
# 915
{ 
# 916
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 917
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 919
return w.x; 
# 920
} 
#endif
# 922 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex1D(texture< unsigned short, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 923
{int volatile ___ = 1;
# 928
exit(___);}
#if 0
# 923
{ 
# 924
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 925
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 927
return w.x; 
# 928
} 
#endif
# 930 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1D(texture< short1, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 931
{int volatile ___ = 1;
# 936
exit(___);}
#if 0
# 931
{ 
# 932
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 933
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 935
return make_float1(w.x); 
# 936
} 
#endif
# 938 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex1D(texture< ushort1, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 939
{int volatile ___ = 1;
# 944
exit(___);}
#if 0
# 939
{ 
# 940
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 941
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 943
return make_float1(w.x); 
# 944
} 
#endif
# 946 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1D(texture< short2, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 947
{int volatile ___ = 1;
# 952
exit(___);}
#if 0
# 947
{ 
# 948
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 949
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 951
return make_float2(w.x, w.y); 
# 952
} 
#endif
# 954 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex1D(texture< ushort2, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 955
{int volatile ___ = 1;
# 960
exit(___);}
#if 0
# 955
{ 
# 956
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 957
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 959
return make_float2(w.x, w.y); 
# 960
} 
#endif
# 962 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1D(texture< short4, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 963
{int volatile ___ = 1;
# 968
exit(___);}
#if 0
# 963
{ 
# 964
int4 v = __itexfetch(t, make_float4(x, 0, 0, 0)); 
# 965
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 967
return make_float4(w.x, w.y, w.z, w.w); 
# 968
} 
#endif
# 970 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex1D(texture< ushort4, 1, cudaReadModeNormalizedFloat>  t, float x) 
# 971
{int volatile ___ = 1;
# 976
exit(___);}
#if 0
# 971
{ 
# 972
uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0)); 
# 973
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 975
return make_float4(w.x, w.y, w.z, w.w); 
# 976
} 
#endif
# 984 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char tex2D(texture< char, 2, cudaReadModeElementType>  t, float x, float y) 
# 985
{int volatile ___ = 1;
# 993
exit(___);}
#if 0
# 985
{ 
# 989
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 992
return (char)(v.x); 
# 993
} 
#endif
# 995 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline signed char tex2D(texture< signed char, 2, cudaReadModeElementType>  t, float x, float y) 
# 996
{int volatile ___ = 1;
# 1000
exit(___);}
#if 0
# 996
{ 
# 997
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 999
return (signed char)(v.x); 
# 1000
} 
#endif
# 1002 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned char tex2D(texture< unsigned char, 2, cudaReadModeElementType>  t, float x, float y) 
# 1003
{int volatile ___ = 1;
# 1007
exit(___);}
#if 0
# 1003
{ 
# 1004
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1006
return (unsigned char)(v.x); 
# 1007
} 
#endif
# 1009 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char1 tex2D(texture< char1, 2, cudaReadModeElementType>  t, float x, float y) 
# 1010
{int volatile ___ = 1;
# 1014
exit(___);}
#if 0
# 1010
{ 
# 1011
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1013
return make_char1(v.x); 
# 1014
} 
#endif
# 1016 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar1 tex2D(texture< uchar1, 2, cudaReadModeElementType>  t, float x, float y) 
# 1017
{int volatile ___ = 1;
# 1021
exit(___);}
#if 0
# 1017
{ 
# 1018
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1020
return make_uchar1(v.x); 
# 1021
} 
#endif
# 1023 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char2 tex2D(texture< char2, 2, cudaReadModeElementType>  t, float x, float y) 
# 1024
{int volatile ___ = 1;
# 1028
exit(___);}
#if 0
# 1024
{ 
# 1025
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1027
return make_char2(v.x, v.y); 
# 1028
} 
#endif
# 1030 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar2 tex2D(texture< uchar2, 2, cudaReadModeElementType>  t, float x, float y) 
# 1031
{int volatile ___ = 1;
# 1035
exit(___);}
#if 0
# 1031
{ 
# 1032
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1034
return make_uchar2(v.x, v.y); 
# 1035
} 
#endif
# 1037 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char4 tex2D(texture< char4, 2, cudaReadModeElementType>  t, float x, float y) 
# 1038
{int volatile ___ = 1;
# 1042
exit(___);}
#if 0
# 1038
{ 
# 1039
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1041
return make_char4(v.x, v.y, v.z, v.w); 
# 1042
} 
#endif
# 1044 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar4 tex2D(texture< uchar4, 2, cudaReadModeElementType>  t, float x, float y) 
# 1045
{int volatile ___ = 1;
# 1049
exit(___);}
#if 0
# 1045
{ 
# 1046
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1048
return make_uchar4(v.x, v.y, v.z, v.w); 
# 1049
} 
#endif
# 1057 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short tex2D(texture< short, 2, cudaReadModeElementType>  t, float x, float y) 
# 1058
{int volatile ___ = 1;
# 1062
exit(___);}
#if 0
# 1058
{ 
# 1059
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1061
return (short)(v.x); 
# 1062
} 
#endif
# 1064 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned short tex2D(texture< unsigned short, 2, cudaReadModeElementType>  t, float x, float y) 
# 1065
{int volatile ___ = 1;
# 1069
exit(___);}
#if 0
# 1065
{ 
# 1066
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1068
return (unsigned short)(v.x); 
# 1069
} 
#endif
# 1071 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short1 tex2D(texture< short1, 2, cudaReadModeElementType>  t, float x, float y) 
# 1072
{int volatile ___ = 1;
# 1076
exit(___);}
#if 0
# 1072
{ 
# 1073
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1075
return make_short1(v.x); 
# 1076
} 
#endif
# 1078 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort1 tex2D(texture< ushort1, 2, cudaReadModeElementType>  t, float x, float y) 
# 1079
{int volatile ___ = 1;
# 1083
exit(___);}
#if 0
# 1079
{ 
# 1080
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1082
return make_ushort1(v.x); 
# 1083
} 
#endif
# 1085 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short2 tex2D(texture< short2, 2, cudaReadModeElementType>  t, float x, float y) 
# 1086
{int volatile ___ = 1;
# 1090
exit(___);}
#if 0
# 1086
{ 
# 1087
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1089
return make_short2(v.x, v.y); 
# 1090
} 
#endif
# 1092 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort2 tex2D(texture< ushort2, 2, cudaReadModeElementType>  t, float x, float y) 
# 1093
{int volatile ___ = 1;
# 1097
exit(___);}
#if 0
# 1093
{ 
# 1094
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1096
return make_ushort2(v.x, v.y); 
# 1097
} 
#endif
# 1099 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short4 tex2D(texture< short4, 2, cudaReadModeElementType>  t, float x, float y) 
# 1100
{int volatile ___ = 1;
# 1104
exit(___);}
#if 0
# 1100
{ 
# 1101
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1103
return make_short4(v.x, v.y, v.z, v.w); 
# 1104
} 
#endif
# 1106 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort4 tex2D(texture< ushort4, 2, cudaReadModeElementType>  t, float x, float y) 
# 1107
{int volatile ___ = 1;
# 1111
exit(___);}
#if 0
# 1107
{ 
# 1108
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1110
return make_ushort4(v.x, v.y, v.z, v.w); 
# 1111
} 
#endif
# 1119 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int tex2D(texture< int, 2, cudaReadModeElementType>  t, float x, float y) 
# 1120
{int volatile ___ = 1;
# 1124
exit(___);}
#if 0
# 1120
{ 
# 1121
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1123
return (int)(v.x); 
# 1124
} 
#endif
# 1126 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned tex2D(texture< unsigned, 2, cudaReadModeElementType>  t, float x, float y) 
# 1127
{int volatile ___ = 1;
# 1131
exit(___);}
#if 0
# 1127
{ 
# 1128
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1130
return (unsigned)(v.x); 
# 1131
} 
#endif
# 1133 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int1 tex2D(texture< int1, 2, cudaReadModeElementType>  t, float x, float y) 
# 1134
{int volatile ___ = 1;
# 1138
exit(___);}
#if 0
# 1134
{ 
# 1135
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1137
return make_int1(v.x); 
# 1138
} 
#endif
# 1140 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint1 tex2D(texture< uint1, 2, cudaReadModeElementType>  t, float x, float y) 
# 1141
{int volatile ___ = 1;
# 1145
exit(___);}
#if 0
# 1141
{ 
# 1142
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1144
return make_uint1(v.x); 
# 1145
} 
#endif
# 1147 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int2 tex2D(texture< int2, 2, cudaReadModeElementType>  t, float x, float y) 
# 1148
{int volatile ___ = 1;
# 1152
exit(___);}
#if 0
# 1148
{ 
# 1149
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1151
return make_int2(v.x, v.y); 
# 1152
} 
#endif
# 1154 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint2 tex2D(texture< uint2, 2, cudaReadModeElementType>  t, float x, float y) 
# 1155
{int volatile ___ = 1;
# 1159
exit(___);}
#if 0
# 1155
{ 
# 1156
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1158
return make_uint2(v.x, v.y); 
# 1159
} 
#endif
# 1161 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int4 tex2D(texture< int4, 2, cudaReadModeElementType>  t, float x, float y) 
# 1162
{int volatile ___ = 1;
# 1166
exit(___);}
#if 0
# 1162
{ 
# 1163
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1165
return make_int4(v.x, v.y, v.z, v.w); 
# 1166
} 
#endif
# 1168 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint4 tex2D(texture< uint4, 2, cudaReadModeElementType>  t, float x, float y) 
# 1169
{int volatile ___ = 1;
# 1173
exit(___);}
#if 0
# 1169
{ 
# 1170
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1172
return make_uint4(v.x, v.y, v.z, v.w); 
# 1173
} 
#endif
# 1247 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< float, 2, cudaReadModeElementType>  t, float x, float y) 
# 1248
{int volatile ___ = 1;
# 1252
exit(___);}
#if 0
# 1248
{ 
# 1249
float4 v = __ftexfetch(t, make_float4(x, y, 0, 0)); 
# 1251
return v.x; 
# 1252
} 
#endif
# 1254 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex2D(texture< float1, 2, cudaReadModeElementType>  t, float x, float y) 
# 1255
{int volatile ___ = 1;
# 1259
exit(___);}
#if 0
# 1255
{ 
# 1256
float4 v = __ftexfetch(t, make_float4(x, y, 0, 0)); 
# 1258
return make_float1(v.x); 
# 1259
} 
#endif
# 1261 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex2D(texture< float2, 2, cudaReadModeElementType>  t, float x, float y) 
# 1262
{int volatile ___ = 1;
# 1266
exit(___);}
#if 0
# 1262
{ 
# 1263
float4 v = __ftexfetch(t, make_float4(x, y, 0, 0)); 
# 1265
return make_float2(v.x, v.y); 
# 1266
} 
#endif
# 1268 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex2D(texture< float4, 2, cudaReadModeElementType>  t, float x, float y) 
# 1269
{int volatile ___ = 1;
# 1273
exit(___);}
#if 0
# 1269
{ 
# 1270
float4 v = __ftexfetch(t, make_float4(x, y, 0, 0)); 
# 1272
return make_float4(v.x, v.y, v.z, v.w); 
# 1273
} 
#endif
# 1281 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< char, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1282
{int volatile ___ = 1;
# 1291
exit(___);}
#if 0
# 1282
{ 
# 1286
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1288
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1290
return w.x; 
# 1291
} 
#endif
# 1293 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< signed char, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1294
{int volatile ___ = 1;
# 1299
exit(___);}
#if 0
# 1294
{ 
# 1295
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1296
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1298
return w.x; 
# 1299
} 
#endif
# 1301 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< unsigned char, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1302
{int volatile ___ = 1;
# 1307
exit(___);}
#if 0
# 1302
{ 
# 1303
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1304
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1306
return w.x; 
# 1307
} 
#endif
# 1309 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex2D(texture< char1, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1310
{int volatile ___ = 1;
# 1315
exit(___);}
#if 0
# 1310
{ 
# 1311
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1312
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1314
return make_float1(w.x); 
# 1315
} 
#endif
# 1317 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex2D(texture< uchar1, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1318
{int volatile ___ = 1;
# 1323
exit(___);}
#if 0
# 1318
{ 
# 1319
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1320
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1322
return make_float1(w.x); 
# 1323
} 
#endif
# 1325 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex2D(texture< char2, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1326
{int volatile ___ = 1;
# 1331
exit(___);}
#if 0
# 1326
{ 
# 1327
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1328
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1330
return make_float2(w.x, w.y); 
# 1331
} 
#endif
# 1333 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex2D(texture< uchar2, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1334
{int volatile ___ = 1;
# 1339
exit(___);}
#if 0
# 1334
{ 
# 1335
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1336
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1338
return make_float2(w.x, w.y); 
# 1339
} 
#endif
# 1341 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex2D(texture< char4, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1342
{int volatile ___ = 1;
# 1347
exit(___);}
#if 0
# 1342
{ 
# 1343
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1344
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1346
return make_float4(w.x, w.y, w.z, w.w); 
# 1347
} 
#endif
# 1349 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex2D(texture< uchar4, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1350
{int volatile ___ = 1;
# 1355
exit(___);}
#if 0
# 1350
{ 
# 1351
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1352
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1354
return make_float4(w.x, w.y, w.z, w.w); 
# 1355
} 
#endif
# 1363 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< short, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1364
{int volatile ___ = 1;
# 1369
exit(___);}
#if 0
# 1364
{ 
# 1365
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1366
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1368
return w.x; 
# 1369
} 
#endif
# 1371 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex2D(texture< unsigned short, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1372
{int volatile ___ = 1;
# 1377
exit(___);}
#if 0
# 1372
{ 
# 1373
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1374
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1376
return w.x; 
# 1377
} 
#endif
# 1379 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex2D(texture< short1, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1380
{int volatile ___ = 1;
# 1385
exit(___);}
#if 0
# 1380
{ 
# 1381
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1382
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1384
return make_float1(w.x); 
# 1385
} 
#endif
# 1387 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex2D(texture< ushort1, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1388
{int volatile ___ = 1;
# 1393
exit(___);}
#if 0
# 1388
{ 
# 1389
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1390
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1392
return make_float1(w.x); 
# 1393
} 
#endif
# 1395 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex2D(texture< short2, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1396
{int volatile ___ = 1;
# 1401
exit(___);}
#if 0
# 1396
{ 
# 1397
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1398
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1400
return make_float2(w.x, w.y); 
# 1401
} 
#endif
# 1403 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex2D(texture< ushort2, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1404
{int volatile ___ = 1;
# 1409
exit(___);}
#if 0
# 1404
{ 
# 1405
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1406
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1408
return make_float2(w.x, w.y); 
# 1409
} 
#endif
# 1411 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex2D(texture< short4, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1412
{int volatile ___ = 1;
# 1417
exit(___);}
#if 0
# 1412
{ 
# 1413
int4 v = __itexfetch(t, make_float4(x, y, 0, 0)); 
# 1414
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1416
return make_float4(w.x, w.y, w.z, w.w); 
# 1417
} 
#endif
# 1419 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex2D(texture< ushort4, 2, cudaReadModeNormalizedFloat>  t, float x, float y) 
# 1420
{int volatile ___ = 1;
# 1425
exit(___);}
#if 0
# 1420
{ 
# 1421
uint4 v = __utexfetch(t, make_float4(x, y, 0, 0)); 
# 1422
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1424
return make_float4(w.x, w.y, w.z, w.w); 
# 1425
} 
#endif
# 1433 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char tex3D(texture< char, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1434
{int volatile ___ = 1;
# 1442
exit(___);}
#if 0
# 1434
{ 
# 1438
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1441
return (char)(v.x); 
# 1442
} 
#endif
# 1444 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline signed char tex3D(texture< signed char, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1445
{int volatile ___ = 1;
# 1449
exit(___);}
#if 0
# 1445
{ 
# 1446
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1448
return (signed char)(v.x); 
# 1449
} 
#endif
# 1451 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned char tex3D(texture< unsigned char, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1452
{int volatile ___ = 1;
# 1456
exit(___);}
#if 0
# 1452
{ 
# 1453
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1455
return (unsigned char)(v.x); 
# 1456
} 
#endif
# 1458 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char1 tex3D(texture< char1, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1459
{int volatile ___ = 1;
# 1463
exit(___);}
#if 0
# 1459
{ 
# 1460
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1462
return make_char1(v.x); 
# 1463
} 
#endif
# 1465 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar1 tex3D(texture< uchar1, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1466
{int volatile ___ = 1;
# 1470
exit(___);}
#if 0
# 1466
{ 
# 1467
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1469
return make_uchar1(v.x); 
# 1470
} 
#endif
# 1472 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char2 tex3D(texture< char2, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1473
{int volatile ___ = 1;
# 1477
exit(___);}
#if 0
# 1473
{ 
# 1474
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1476
return make_char2(v.x, v.y); 
# 1477
} 
#endif
# 1479 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar2 tex3D(texture< uchar2, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1480
{int volatile ___ = 1;
# 1484
exit(___);}
#if 0
# 1480
{ 
# 1481
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1483
return make_uchar2(v.x, v.y); 
# 1484
} 
#endif
# 1486 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline char4 tex3D(texture< char4, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1487
{int volatile ___ = 1;
# 1491
exit(___);}
#if 0
# 1487
{ 
# 1488
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1490
return make_char4(v.x, v.y, v.z, v.w); 
# 1491
} 
#endif
# 1493 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uchar4 tex3D(texture< uchar4, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1494
{int volatile ___ = 1;
# 1498
exit(___);}
#if 0
# 1494
{ 
# 1495
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1497
return make_uchar4(v.x, v.y, v.z, v.w); 
# 1498
} 
#endif
# 1506 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short tex3D(texture< short, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1507
{int volatile ___ = 1;
# 1511
exit(___);}
#if 0
# 1507
{ 
# 1508
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1510
return (short)(v.x); 
# 1511
} 
#endif
# 1513 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned short tex3D(texture< unsigned short, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1514
{int volatile ___ = 1;
# 1518
exit(___);}
#if 0
# 1514
{ 
# 1515
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1517
return (unsigned short)(v.x); 
# 1518
} 
#endif
# 1520 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short1 tex3D(texture< short1, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1521
{int volatile ___ = 1;
# 1525
exit(___);}
#if 0
# 1521
{ 
# 1522
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1524
return make_short1(v.x); 
# 1525
} 
#endif
# 1527 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort1 tex3D(texture< ushort1, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1528
{int volatile ___ = 1;
# 1532
exit(___);}
#if 0
# 1528
{ 
# 1529
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1531
return make_ushort1(v.x); 
# 1532
} 
#endif
# 1534 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short2 tex3D(texture< short2, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1535
{int volatile ___ = 1;
# 1539
exit(___);}
#if 0
# 1535
{ 
# 1536
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1538
return make_short2(v.x, v.y); 
# 1539
} 
#endif
# 1541 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort2 tex3D(texture< ushort2, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1542
{int volatile ___ = 1;
# 1546
exit(___);}
#if 0
# 1542
{ 
# 1543
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1545
return make_ushort2(v.x, v.y); 
# 1546
} 
#endif
# 1548 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline short4 tex3D(texture< short4, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1549
{int volatile ___ = 1;
# 1553
exit(___);}
#if 0
# 1549
{ 
# 1550
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1552
return make_short4(v.x, v.y, v.z, v.w); 
# 1553
} 
#endif
# 1555 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline ushort4 tex3D(texture< ushort4, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1556
{int volatile ___ = 1;
# 1560
exit(___);}
#if 0
# 1556
{ 
# 1557
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1559
return make_ushort4(v.x, v.y, v.z, v.w); 
# 1560
} 
#endif
# 1568 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int tex3D(texture< int, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1569
{int volatile ___ = 1;
# 1573
exit(___);}
#if 0
# 1569
{ 
# 1570
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1572
return (int)(v.x); 
# 1573
} 
#endif
# 1575 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline unsigned tex3D(texture< unsigned, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1576
{int volatile ___ = 1;
# 1580
exit(___);}
#if 0
# 1576
{ 
# 1577
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1579
return (unsigned)(v.x); 
# 1580
} 
#endif
# 1582 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int1 tex3D(texture< int1, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1583
{int volatile ___ = 1;
# 1587
exit(___);}
#if 0
# 1583
{ 
# 1584
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1586
return make_int1(v.x); 
# 1587
} 
#endif
# 1589 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint1 tex3D(texture< uint1, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1590
{int volatile ___ = 1;
# 1594
exit(___);}
#if 0
# 1590
{ 
# 1591
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1593
return make_uint1(v.x); 
# 1594
} 
#endif
# 1596 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int2 tex3D(texture< int2, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1597
{int volatile ___ = 1;
# 1601
exit(___);}
#if 0
# 1597
{ 
# 1598
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1600
return make_int2(v.x, v.y); 
# 1601
} 
#endif
# 1603 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint2 tex3D(texture< uint2, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1604
{int volatile ___ = 1;
# 1608
exit(___);}
#if 0
# 1604
{ 
# 1605
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1607
return make_uint2(v.x, v.y); 
# 1608
} 
#endif
# 1610 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline int4 tex3D(texture< int4, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1611
{int volatile ___ = 1;
# 1615
exit(___);}
#if 0
# 1611
{ 
# 1612
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1614
return make_int4(v.x, v.y, v.z, v.w); 
# 1615
} 
#endif
# 1617 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline uint4 tex3D(texture< uint4, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1618
{int volatile ___ = 1;
# 1622
exit(___);}
#if 0
# 1618
{ 
# 1619
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1621
return make_uint4(v.x, v.y, v.z, v.w); 
# 1622
} 
#endif
# 1696 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< float, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1697
{int volatile ___ = 1;
# 1701
exit(___);}
#if 0
# 1697
{ 
# 1698
float4 v = __ftexfetch(t, make_float4(x, y, z, 0)); 
# 1700
return v.x; 
# 1701
} 
#endif
# 1703 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex3D(texture< float1, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1704
{int volatile ___ = 1;
# 1708
exit(___);}
#if 0
# 1704
{ 
# 1705
float4 v = __ftexfetch(t, make_float4(x, y, z, 0)); 
# 1707
return make_float1(v.x); 
# 1708
} 
#endif
# 1710 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex3D(texture< float2, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1711
{int volatile ___ = 1;
# 1715
exit(___);}
#if 0
# 1711
{ 
# 1712
float4 v = __ftexfetch(t, make_float4(x, y, z, 0)); 
# 1714
return make_float2(v.x, v.y); 
# 1715
} 
#endif
# 1717 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex3D(texture< float4, 3, cudaReadModeElementType>  t, float x, float y, float z) 
# 1718
{int volatile ___ = 1;
# 1722
exit(___);}
#if 0
# 1718
{ 
# 1719
float4 v = __ftexfetch(t, make_float4(x, y, z, 0)); 
# 1721
return make_float4(v.x, v.y, v.z, v.w); 
# 1722
} 
#endif
# 1730 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< char, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1731
{int volatile ___ = 1;
# 1740
exit(___);}
#if 0
# 1731
{ 
# 1735
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1737
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1739
return w.x; 
# 1740
} 
#endif
# 1742 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< signed char, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1743
{int volatile ___ = 1;
# 1748
exit(___);}
#if 0
# 1743
{ 
# 1744
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1745
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1747
return w.x; 
# 1748
} 
#endif
# 1750 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< unsigned char, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1751
{int volatile ___ = 1;
# 1756
exit(___);}
#if 0
# 1751
{ 
# 1752
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1753
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1755
return w.x; 
# 1756
} 
#endif
# 1758 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex3D(texture< char1, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1759
{int volatile ___ = 1;
# 1764
exit(___);}
#if 0
# 1759
{ 
# 1760
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1761
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1763
return make_float1(w.x); 
# 1764
} 
#endif
# 1766 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex3D(texture< uchar1, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1767
{int volatile ___ = 1;
# 1772
exit(___);}
#if 0
# 1767
{ 
# 1768
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1769
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1771
return make_float1(w.x); 
# 1772
} 
#endif
# 1774 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex3D(texture< char2, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1775
{int volatile ___ = 1;
# 1780
exit(___);}
#if 0
# 1775
{ 
# 1776
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1777
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1779
return make_float2(w.x, w.y); 
# 1780
} 
#endif
# 1782 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex3D(texture< uchar2, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1783
{int volatile ___ = 1;
# 1788
exit(___);}
#if 0
# 1783
{ 
# 1784
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1785
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1787
return make_float2(w.x, w.y); 
# 1788
} 
#endif
# 1790 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex3D(texture< char4, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1791
{int volatile ___ = 1;
# 1796
exit(___);}
#if 0
# 1791
{ 
# 1792
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1793
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1795
return make_float4(w.x, w.y, w.z, w.w); 
# 1796
} 
#endif
# 1798 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex3D(texture< uchar4, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1799
{int volatile ___ = 1;
# 1804
exit(___);}
#if 0
# 1799
{ 
# 1800
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1801
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1803
return make_float4(w.x, w.y, w.z, w.w); 
# 1804
} 
#endif
# 1812 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< short, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1813
{int volatile ___ = 1;
# 1818
exit(___);}
#if 0
# 1813
{ 
# 1814
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1815
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1817
return w.x; 
# 1818
} 
#endif
# 1820 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float tex3D(texture< unsigned short, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1821
{int volatile ___ = 1;
# 1826
exit(___);}
#if 0
# 1821
{ 
# 1822
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1823
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1825
return w.x; 
# 1826
} 
#endif
# 1828 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex3D(texture< short1, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1829
{int volatile ___ = 1;
# 1834
exit(___);}
#if 0
# 1829
{ 
# 1830
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1831
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1833
return make_float1(w.x); 
# 1834
} 
#endif
# 1836 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float1 tex3D(texture< ushort1, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1837
{int volatile ___ = 1;
# 1842
exit(___);}
#if 0
# 1837
{ 
# 1838
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1839
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1841
return make_float1(w.x); 
# 1842
} 
#endif
# 1844 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex3D(texture< short2, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1845
{int volatile ___ = 1;
# 1850
exit(___);}
#if 0
# 1845
{ 
# 1846
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1847
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1849
return make_float2(w.x, w.y); 
# 1850
} 
#endif
# 1852 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float2 tex3D(texture< ushort2, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1853
{int volatile ___ = 1;
# 1858
exit(___);}
#if 0
# 1853
{ 
# 1854
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1855
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1857
return make_float2(w.x, w.y); 
# 1858
} 
#endif
# 1860 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex3D(texture< short4, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1861
{int volatile ___ = 1;
# 1866
exit(___);}
#if 0
# 1861
{ 
# 1862
int4 v = __itexfetch(t, make_float4(x, y, z, 0)); 
# 1863
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1865
return make_float4(w.x, w.y, w.z, w.w); 
# 1866
} 
#endif
# 1868 "/usr/local/cuda/bin/../include/texture_fetch_functions.h"
static __attribute__((unused)) inline float4 tex3D(texture< ushort4, 3, cudaReadModeNormalizedFloat>  t, float x, float y, float z) 
# 1869
{int volatile ___ = 1;
# 1874
exit(___);}
#if 0
# 1869
{ 
# 1870
uint4 v = __utexfetch(t, make_float4(x, y, z, 0)); 
# 1871
float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w)); 
# 1873
return make_float4(w.x, w.y, w.z, w.w); 
# 1874
} 
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
# 102 "/usr/local/cuda/bin/../include/cuda_runtime.h"
template<class T> inline cudaError_t 
# 103
cudaSetupArgument(T 
# 104
arg, size_t 
# 105
offset) 
# 107
{ 
# 108
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset); 
# 109
} 
# 111
template<class T> inline cudaError_t 
# 112
cudaHostAlloc(T **
# 113
ptr, size_t 
# 114
size, unsigned 
# 115
flags) 
# 117
{ 
# 118
return cudaHostAlloc((void **)((void *)ptr), size, flags); 
# 119
} 
# 121
template<class T> inline cudaError_t 
# 122
cudaHostGetDevicePointer(T **
# 123
pDevice, void *
# 124
pHost, unsigned 
# 125
flags) 
# 127
{ 
# 128
return cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags); 
# 129
} 
# 131
template<class T> inline cudaError_t 
# 132
cudaMalloc(T **
# 133
devPtr, size_t 
# 134
size) 
# 136
{ 
# 137
return cudaMalloc((void **)((void *)devPtr), size); 
# 138
} 
# 140
template<class T> inline cudaError_t 
# 141
cudaMallocHost(T **
# 142
ptr, size_t 
# 143
size) 
# 145
{ 
# 146
return cudaMallocHost((void **)((void *)ptr), size); 
# 147
} 
# 149
template<class T> inline cudaError_t 
# 150
cudaMallocPitch(T **
# 151
devPtr, size_t *
# 152
pitch, size_t 
# 153
width, size_t 
# 154
height) 
# 156
{ 
# 157
return cudaMallocPitch((void **)((void *)devPtr), pitch, width, height); 
# 158
} 
# 173
static inline cudaError_t cudaMemcpyToSymbol(char *
# 174
symbol, const void *
# 175
src, size_t 
# 176
count, size_t 
# 177
offset = (0), cudaMemcpyKind 
# 178
kind = cudaMemcpyHostToDevice) 
# 180
{ 
# 181
return cudaMemcpyToSymbol((const char *)symbol, src, count, offset, kind); 
# 182
} 
# 184
template<class T> inline cudaError_t 
# 185
cudaMemcpyToSymbol(const T &
# 186
symbol, const void *
# 187
src, size_t 
# 188
count, size_t 
# 189
offset = (0), cudaMemcpyKind 
# 190
kind = cudaMemcpyHostToDevice) 
# 192
{ 
# 193
return cudaMemcpyToSymbol((const char *)(&symbol), src, count, offset, kind); 
# 194
} 
# 196
static inline cudaError_t cudaMemcpyToSymbolAsync(char *
# 197
symbol, const void *
# 198
src, size_t 
# 199
count, size_t 
# 200
offset = (0), cudaMemcpyKind 
# 201
kind = cudaMemcpyHostToDevice, cudaStream_t 
# 202
stream = 0) 
# 204
{ 
# 205
return cudaMemcpyToSymbolAsync((const char *)symbol, src, count, offset, kind, stream); 
# 206
} 
# 208
template<class T> inline cudaError_t 
# 209
cudaMemcpyToSymbolAsync(const T &
# 210
symbol, const void *
# 211
src, size_t 
# 212
count, size_t 
# 213
offset = (0), cudaMemcpyKind 
# 214
kind = cudaMemcpyHostToDevice, cudaStream_t 
# 215
stream = 0) 
# 217
{ 
# 218
return cudaMemcpyToSymbolAsync((const char *)(&symbol), src, count, offset, kind, stream); 
# 219
} 
# 227
static inline cudaError_t cudaMemcpyFromSymbol(void *
# 228
dst, char *
# 229
symbol, size_t 
# 230
count, size_t 
# 231
offset = (0), cudaMemcpyKind 
# 232
kind = cudaMemcpyDeviceToHost) 
# 234
{ 
# 235
return cudaMemcpyFromSymbol(dst, (const char *)symbol, count, offset, kind); 
# 236
} 
# 238
template<class T> inline cudaError_t 
# 239
cudaMemcpyFromSymbol(void *
# 240
dst, const T &
# 241
symbol, size_t 
# 242
count, size_t 
# 243
offset = (0), cudaMemcpyKind 
# 244
kind = cudaMemcpyDeviceToHost) 
# 246
{ 
# 247
return cudaMemcpyFromSymbol(dst, (const char *)(&symbol), count, offset, kind); 
# 248
} 
# 250
static inline cudaError_t cudaMemcpyFromSymbolAsync(void *
# 251
dst, char *
# 252
symbol, size_t 
# 253
count, size_t 
# 254
offset = (0), cudaMemcpyKind 
# 255
kind = cudaMemcpyDeviceToHost, cudaStream_t 
# 256
stream = 0) 
# 258
{ 
# 259
return cudaMemcpyFromSymbolAsync(dst, (const char *)symbol, count, offset, kind, stream); 
# 260
} 
# 262
template<class T> inline cudaError_t 
# 263
cudaMemcpyFromSymbolAsync(void *
# 264
dst, const T &
# 265
symbol, size_t 
# 266
count, size_t 
# 267
offset = (0), cudaMemcpyKind 
# 268
kind = cudaMemcpyDeviceToHost, cudaStream_t 
# 269
stream = 0) 
# 271
{ 
# 272
return cudaMemcpyFromSymbolAsync(dst, (const char *)(&symbol), count, offset, kind, stream); 
# 273
} 
# 275
static inline cudaError_t cudaGetSymbolAddress(void **
# 276
devPtr, char *
# 277
symbol) 
# 279
{ 
# 280
return cudaGetSymbolAddress(devPtr, (const char *)symbol); 
# 281
} 
# 308
template<class T> inline cudaError_t 
# 309
cudaGetSymbolAddress(void **
# 310
devPtr, const T &
# 311
symbol) 
# 313
{ 
# 314
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol)); 
# 315
} 
# 323
static inline cudaError_t cudaGetSymbolSize(size_t *
# 324
size, char *
# 325
symbol) 
# 327
{ 
# 328
return cudaGetSymbolSize(size, (const char *)symbol); 
# 329
} 
# 356
template<class T> inline cudaError_t 
# 357
cudaGetSymbolSize(size_t *
# 358
size, const T &
# 359
symbol) 
# 361
{ 
# 362
return cudaGetSymbolSize(size, (const char *)(&symbol)); 
# 363
} 
# 412
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t 
# 413
cudaBindTexture(size_t *
# 414
offset, const texture< T, dim, readMode>  &
# 415
tex, const void *
# 416
devPtr, const cudaChannelFormatDesc &
# 417
desc, size_t 
# 418
size = (((2147483647) * 2U) + 1U)) 
# 420
{ 
# 421
return cudaBindTexture(offset, &tex, devPtr, &desc, size); 
# 422
} 
# 456
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t 
# 457
cudaBindTexture(size_t *
# 458
offset, const texture< T, dim, readMode>  &
# 459
tex, const void *
# 460
devPtr, size_t 
# 461
size = (((2147483647) * 2U) + 1U)) 
# 463
{ 
# 464
return cudaBindTexture(offset, tex, devPtr, (tex.texture< T, dim, readMode> ::channelDesc), size); 
# 465
} 
# 511
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t 
# 512
cudaBindTexture2D(size_t *
# 513
offset, const texture< T, dim, readMode>  &
# 514
tex, const void *
# 515
devPtr, const cudaChannelFormatDesc &
# 516
desc, size_t 
# 517
width, size_t 
# 518
height, size_t 
# 519
pitch) 
# 521
{ 
# 522
return cudaBindTexture2D(offset, &tex, devPtr, &desc, width, height, pitch); 
# 523
} 
# 553
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t 
# 554
cudaBindTextureToArray(const texture< T, dim, readMode>  &
# 555
tex, const cudaArray *
# 556
array, const cudaChannelFormatDesc &
# 557
desc) 
# 559
{ 
# 560
return cudaBindTextureToArray(&tex, array, &desc); 
# 561
} 
# 590
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t 
# 591
cudaBindTextureToArray(const texture< T, dim, readMode>  &
# 592
tex, const cudaArray *
# 593
array) 
# 595
{ 
# 596
cudaChannelFormatDesc desc; 
# 597
cudaError_t err = cudaGetChannelDesc(&desc, array); 
# 599
return (err == (cudaSuccess)) ? cudaBindTextureToArray(tex, array, desc) : err; 
# 600
} 
# 628
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t 
# 629
cudaUnbindTexture(const texture< T, dim, readMode>  &
# 630
tex) 
# 632
{ 
# 633
return cudaUnbindTexture(&tex); 
# 634
} 
# 667
template<class T, int dim, cudaTextureReadMode readMode> inline cudaError_t 
# 668
cudaGetTextureAlignmentOffset(size_t *
# 669
offset, const texture< T, dim, readMode>  &
# 670
tex) 
# 672
{ 
# 673
return cudaGetTextureAlignmentOffset(offset, &tex); 
# 674
} 
# 724
template<class T> inline cudaError_t 
# 725
cudaFuncSetCacheConfig(T *
# 726
func, cudaFuncCache 
# 727
cacheConfig) 
# 729
{ 
# 730
return cudaFuncSetCacheConfig((const char *)func, cacheConfig); 
# 731
} 
# 768
template<class T> inline cudaError_t 
# 769
cudaLaunch(T *
# 770
entry) 
# 772
{ 
# 773
return cudaLaunch((const char *)entry); 
# 774
} 
# 805
template<class T> inline cudaError_t 
# 806
cudaFuncGetAttributes(cudaFuncAttributes *
# 807
attr, T *
# 808
entry) 
# 810
{ 
# 811
return cudaFuncGetAttributes(attr, (const char *)entry); 
# 812
} 
# 835
template<class T, int dim> inline cudaError_t 
# 836
cudaBindSurfaceToArray(const surface< T, dim>  &
# 837
surf, const cudaArray *
# 838
array, const cudaChannelFormatDesc &
# 839
desc) 
# 841
{ 
# 842
return cudaBindSurfaceToArray(&surf, array, &desc); 
# 843
} 
# 865
template<class T, int dim> inline cudaError_t 
# 866
cudaBindSurfaceToArray(const surface< T, dim>  &
# 867
surf, const cudaArray *
# 868
array) 
# 870
{ 
# 871
cudaChannelFormatDesc desc; 
# 872
cudaError_t err = cudaGetChannelDesc(&desc, array); 
# 874
return (err == (cudaSuccess)) ? cudaBindSurfaceToArray(surf, array, desc) : err; 
# 875
} 
# 45 "/usr/include/stdio.h" 3
struct _IO_FILE; 
# 49
extern "C" { typedef _IO_FILE FILE; }
# 65 "/usr/include/stdio.h" 3
extern "C" { typedef _IO_FILE __FILE; }
# 90 "/usr/include/wchar.h" 3
extern "C" { typedef 
# 79
struct { 
# 80
int __count; 
# 82
union { 
# 84
unsigned __wch; 
# 88
char __wchb[4]; 
# 89
} __value; 
# 90
} __mbstate_t; }
# 26 "/usr/include/_G_config.h" 3
extern "C" { typedef 
# 23
struct { 
# 24
__off_t __pos; 
# 25
__mbstate_t __state; 
# 26
} _G_fpos_t; }
# 31
extern "C" { typedef 
# 28
struct { 
# 29
__off64_t __pos; 
# 30
__mbstate_t __state; 
# 31
} _G_fpos64_t; }
# 53 "/usr/include/_G_config.h" 3
extern "C" { typedef short _G_int16_t; }
# 54
extern "C" { typedef int _G_int32_t; }
# 55
extern "C" { typedef unsigned short _G_uint16_t; }
# 56
extern "C" { typedef unsigned _G_uint32_t; }
# 43 "/usr/lib/gcc/x86_64-linux-gnu/4.2.4/include/stdarg.h" 3
extern "C" { typedef __builtin_va_list __gnuc_va_list; }
# 170 "/usr/include/libio.h" 3
struct _IO_jump_t; struct _IO_FILE; 
# 180
extern "C" { typedef void _IO_lock_t; }
# 186
extern "C" { struct _IO_marker { 
# 187
_IO_marker *_next; 
# 188
_IO_FILE *_sbuf; 
# 192
int _pos; 
# 203 "/usr/include/libio.h" 3
}; }
# 206
enum __codecvt_result { 
# 208
__codecvt_ok, 
# 209
__codecvt_partial, 
# 210
__codecvt_error, 
# 211
__codecvt_noconv
# 212
}; 
# 271 "/usr/include/libio.h" 3
extern "C" { struct _IO_FILE { 
# 272
int _flags; 
# 277
char *_IO_read_ptr; 
# 278
char *_IO_read_end; 
# 279
char *_IO_read_base; 
# 280
char *_IO_write_base; 
# 281
char *_IO_write_ptr; 
# 282
char *_IO_write_end; 
# 283
char *_IO_buf_base; 
# 284
char *_IO_buf_end; 
# 286
char *_IO_save_base; 
# 287
char *_IO_backup_base; 
# 288
char *_IO_save_end; 
# 290
_IO_marker *_markers; 
# 292
_IO_FILE *_chain; 
# 294
int _fileno; 
# 298
int _flags2; 
# 300
__off_t _old_offset; 
# 304
unsigned short _cur_column; 
# 305
signed char _vtable_offset; 
# 306
char _shortbuf[1]; 
# 310
_IO_lock_t *_lock; 
# 319 "/usr/include/libio.h" 3
__off64_t _offset; 
# 328 "/usr/include/libio.h" 3
void *__pad1; 
# 329
void *__pad2; 
# 330
void *__pad3; 
# 331
void *__pad4; 
# 332
size_t __pad5; 
# 334
int _mode; 
# 336
char _unused2[((((15) * sizeof(int)) - ((4) * sizeof(void *))) - sizeof(size_t))]; 
# 338
}; }
# 344
struct _IO_FILE_plus; 
# 346
extern "C" { extern _IO_FILE_plus _IO_2_1_stdin_; } 
# 347
extern "C" { extern _IO_FILE_plus _IO_2_1_stdout_; } 
# 348
extern "C" { extern _IO_FILE_plus _IO_2_1_stderr_; } 
# 364 "/usr/include/libio.h" 3
extern "C" { typedef __ssize_t __io_read_fn(void *, char *, size_t); }
# 372
extern "C" { typedef __ssize_t __io_write_fn(void *, const char *, size_t); }
# 381
extern "C" { typedef int __io_seek_fn(void *, __off64_t *, int); }
# 384
extern "C" { typedef int __io_close_fn(void *); }
# 389
extern "C" { typedef __io_read_fn cookie_read_function_t; }
# 390
extern "C" { typedef __io_write_fn cookie_write_function_t; }
# 391
extern "C" { typedef __io_seek_fn cookie_seek_function_t; }
# 392
extern "C" { typedef __io_close_fn cookie_close_function_t; }
# 401
extern "C" { typedef 
# 396
struct { 
# 397
__io_read_fn *read; 
# 398
__io_write_fn *write; 
# 399
__io_seek_fn *seek; 
# 400
__io_close_fn *close; 
# 401
} _IO_cookie_io_functions_t; }
# 402
extern "C" { typedef _IO_cookie_io_functions_t cookie_io_functions_t; }
# 404
struct _IO_cookie_file; 
# 407
extern "C" void _IO_cookie_init(_IO_cookie_file *, int, void *, _IO_cookie_io_functions_t); 
# 416
extern "C" int __underflow(_IO_FILE *); 
# 417
extern "C" int __uflow(_IO_FILE *); 
# 418
extern "C" int __overflow(_IO_FILE *, int); 
# 458 "/usr/include/libio.h" 3
extern "C" int _IO_getc(_IO_FILE *); 
# 459
extern "C" int _IO_putc(int, _IO_FILE *); 
# 460
extern "C" int _IO_feof(_IO_FILE *) throw(); 
# 461
extern "C" int _IO_ferror(_IO_FILE *) throw(); 
# 463
extern "C" int _IO_peekc_locked(_IO_FILE *); 
# 469
extern "C" void _IO_flockfile(_IO_FILE *) throw(); 
# 470
extern "C" void _IO_funlockfile(_IO_FILE *) throw(); 
# 471
extern "C" int _IO_ftrylockfile(_IO_FILE *) throw(); 
# 488 "/usr/include/libio.h" 3
extern "C" int _IO_vfscanf(_IO_FILE *__restrict__, const char *__restrict__, __gnuc_va_list, int *__restrict__); 
# 490
extern "C" int _IO_vfprintf(_IO_FILE *__restrict__, const char *__restrict__, __gnuc_va_list); 
# 492
extern "C" __ssize_t _IO_padn(_IO_FILE *, int, __ssize_t); 
# 493
extern "C" size_t _IO_sgetn(_IO_FILE *, void *, size_t); 
# 495
extern "C" __off64_t _IO_seekoff(_IO_FILE *, __off64_t, int, int); 
# 496
extern "C" __off64_t _IO_seekpos(_IO_FILE *, __off64_t, int); 
# 498
extern "C" void _IO_free_backup_area(_IO_FILE *) throw(); 
# 80 "/usr/include/stdio.h" 3
extern "C" { typedef __gnuc_va_list va_list; }
# 91
extern "C" { typedef _G_fpos_t fpos_t; }
# 97
extern "C" { typedef _G_fpos64_t fpos64_t; }
# 145 "/usr/include/stdio.h" 3
extern "C" { extern _IO_FILE *stdin; } 
# 146
extern "C" { extern _IO_FILE *stdout; } 
# 147
extern "C" { extern _IO_FILE *stderr; } 
# 155
extern "C" int remove(const char *) throw(); 
# 157
extern "C" int rename(const char *, const char *) throw(); 
# 162
extern "C" int renameat(int, const char *, int, const char *) throw(); 
# 172
extern "C" FILE *tmpfile(); 
# 182 "/usr/include/stdio.h" 3
extern "C" FILE *tmpfile64(); 
# 186
extern "C" char *tmpnam(char *) throw(); 
# 192
extern "C" char *tmpnam_r(char *) throw(); 
# 204
extern "C" char *tempnam(const char *, const char *) throw() __attribute__((__malloc__)); 
# 214
extern "C" int fclose(FILE *); 
# 219
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
# 276
extern "C" FILE *freopen64(const char *__restrict__, const char *__restrict__, FILE *__restrict__); 
# 283
extern "C" FILE *fdopen(int, const char *) throw(); 
# 289
extern "C" FILE *fopencookie(void *__restrict__, const char *__restrict__, _IO_cookie_io_functions_t) throw(); 
# 294
extern "C" FILE *fmemopen(void *, size_t, const char *) throw(); 
# 300
extern "C" FILE *open_memstream(char **, size_t *) throw(); 
# 307
extern "C" void setbuf(FILE *__restrict__, char *__restrict__) throw(); 
# 311
extern "C" int setvbuf(FILE *__restrict__, char *__restrict__, int, size_t) throw(); 
# 318
extern "C" void setbuffer(FILE *__restrict__, char *__restrict__, size_t) throw(); 
# 322
extern "C" void setlinebuf(FILE *) throw(); 
# 331
extern "C" int fprintf(FILE *__restrict__, const char *__restrict__, ...); 
# 337
extern "C" int printf(const char *__restrict__, ...); 
# 339
extern "C" int sprintf(char *__restrict__, const char *__restrict__, ...) throw(); 
# 346
extern "C" int vfprintf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list); 
# 352
extern "C" int vprintf(const char *__restrict__, __gnuc_va_list); 
# 354
extern "C" int vsprintf(char *__restrict__, const char *__restrict__, __gnuc_va_list) throw(); 
# 361
extern "C" int snprintf(char *__restrict__, size_t, const char *__restrict__, ...) throw(); 
# 365
extern "C" int vsnprintf(char *__restrict__, size_t, const char *__restrict__, __gnuc_va_list) throw(); 
# 374
extern "C" int vasprintf(char **__restrict__, const char *__restrict__, __gnuc_va_list) throw(); 
# 377
extern "C" int __asprintf(char **__restrict__, const char *__restrict__, ...) throw(); 
# 380
extern "C" int asprintf(char **__restrict__, const char *__restrict__, ...) throw(); 
# 390
extern "C" int vdprintf(int, const char *__restrict__, __gnuc_va_list); 
# 393
extern "C" int dprintf(int, const char *__restrict__, ...); 
# 403
extern "C" int fscanf(FILE *__restrict__, const char *__restrict__, ...); 
# 409
extern "C" int scanf(const char *__restrict__, ...); 
# 411
extern "C" int sscanf(const char *__restrict__, const char *__restrict__, ...) throw(); 
# 449 "/usr/include/stdio.h" 3
extern "C" int vfscanf(FILE *__restrict__, const char *__restrict__, __gnuc_va_list); 
# 457
extern "C" int vscanf(const char *__restrict__, __gnuc_va_list); 
# 461
extern "C" int vsscanf(const char *__restrict__, const char *__restrict__, __gnuc_va_list) throw(); 
# 509 "/usr/include/stdio.h" 3
extern "C" int fgetc(FILE *); 
# 510
extern "C" int getc(FILE *); 
# 516
extern "C" int getchar(); 
# 528
extern "C" int getc_unlocked(FILE *); 
# 529
extern "C" int getchar_unlocked(); 
# 539
extern "C" int fgetc_unlocked(FILE *); 
# 551
extern "C" int fputc(int, FILE *); 
# 552
extern "C" int putc(int, FILE *); 
# 558
extern "C" int putchar(int); 
# 572
extern "C" int fputc_unlocked(int, FILE *); 
# 580
extern "C" int putc_unlocked(int, FILE *); 
# 581
extern "C" int putchar_unlocked(int); 
# 588
extern "C" int getw(FILE *); 
# 591
extern "C" int putw(int, FILE *); 
# 600
extern "C" char *fgets(char *__restrict__, int, FILE *__restrict__); 
# 608
extern "C" char *gets(char *); 
# 618
extern "C" char *fgets_unlocked(char *__restrict__, int, FILE *__restrict__); 
# 634
extern "C" __ssize_t __getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__); 
# 637
extern "C" __ssize_t getdelim(char **__restrict__, size_t *__restrict__, int, FILE *__restrict__); 
# 647
extern "C" __ssize_t getline(char **__restrict__, size_t *__restrict__, FILE *__restrict__); 
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
# 708
extern "C" size_t fwrite_unlocked(const void *__restrict__, size_t, size_t, FILE *__restrict__); 
# 718
extern "C" int fseek(FILE *, long, int); 
# 723
extern "C" long ftell(FILE *); 
# 728
extern "C" void rewind(FILE *); 
# 742
extern "C" int fseeko(FILE *, __off_t, int); 
# 747
extern "C" __off_t ftello(FILE *); 
# 767 "/usr/include/stdio.h" 3
extern "C" int fgetpos(FILE *__restrict__, fpos_t *__restrict__); 
# 772
extern "C" int fsetpos(FILE *, const fpos_t *); 
# 787 "/usr/include/stdio.h" 3
extern "C" int fseeko64(FILE *, __off64_t, int); 
# 788
extern "C" __off64_t ftello64(FILE *); 
# 789
extern "C" int fgetpos64(FILE *__restrict__, fpos64_t *__restrict__); 
# 790
extern "C" int fsetpos64(FILE *, const fpos64_t *); 
# 795
extern "C" void clearerr(FILE *) throw(); 
# 797
extern "C" int feof(FILE *) throw(); 
# 799
extern "C" int ferror(FILE *) throw(); 
# 804
extern "C" void clearerr_unlocked(FILE *) throw(); 
# 805
extern "C" int feof_unlocked(FILE *) throw(); 
# 806
extern "C" int ferror_unlocked(FILE *) throw(); 
# 815
extern "C" void perror(const char *); 
# 27 "/usr/include/bits/sys_errlist.h" 3
extern "C" { extern int sys_nerr; } 
# 28
extern "C" { extern const char *const sys_errlist[]; } 
# 31
extern "C" { extern int _sys_nerr; } 
# 32
extern "C" { extern const char *const _sys_errlist[]; } 
# 827 "/usr/include/stdio.h" 3
extern "C" int fileno(FILE *) throw(); 
# 832
extern "C" int fileno_unlocked(FILE *) throw(); 
# 842
extern "C" FILE *popen(const char *, const char *); 
# 848
extern "C" int pclose(FILE *); 
# 854
extern "C" char *ctermid(char *) throw(); 
# 860
extern "C" char *cuserid(char *); 
# 865
struct obstack; 
# 868
extern "C" int obstack_printf(obstack *__restrict__, const char *__restrict__, ...) throw(); 
# 871
extern "C" int obstack_vprintf(obstack *__restrict__, const char *__restrict__, __gnuc_va_list) throw(); 
# 882
extern "C" void flockfile(FILE *) throw(); 
# 886
extern "C" int ftrylockfile(FILE *) throw(); 
# 889
extern "C" void funlockfile(FILE *) throw(); 
# 38 "src/cuda/cuenergy.h"
void cenergy(int, float, float *); 
# 42
int copyatomstoconstbuf(float *, int, float); 
# 25 "src/cuda/cuenergy_pre8_coalesce.cu"
__loc_sc__(__constant__,,) float4 atominfo[4000]; 
# 30
void cenergy(int numatoms, float gridspacing, float *energygrid) ;
#if 0
# 30
{ 
# 31
unsigned xindex = ((__umul24(blockIdx.x, blockDim.x) * (8)) + (threadIdx.x)); 
# 33
unsigned yindex = (__umul24(blockIdx.y, blockDim.y) + (threadIdx.y)); 
# 34
unsigned outaddr = (((__umul24(gridDim.x, blockDim.x) * (8)) * yindex) + xindex); 
# 37
float coory = (gridspacing * yindex); 
# 38
float coorx = (gridspacing * xindex); 
# 40
float energyvalx1 = (0.0F); 
# 41
float energyvalx2 = (0.0F); 
# 42
float energyvalx3 = (0.0F); 
# 43
float energyvalx4 = (0.0F); 
# 44
float energyvalx5 = (0.0F); 
# 45
float energyvalx6 = (0.0F); 
# 46
float energyvalx7 = (0.0F); 
# 47
float energyvalx8 = (0.0F); 
# 49
float gridspacing_u = (gridspacing * (16)); 
# 51
int atomid; 
# 52
for (atomid = 0; atomid < numatoms; atomid++) { 
# 53
float dy = (coory - (((atominfo)[atomid]).y)); 
# 54
float dyz2 = ((dy * dy) + (((atominfo)[atomid]).z)); 
# 56
float dx1 = (coorx - (((atominfo)[atomid]).x)); 
# 57
float dx2 = (dx1 + gridspacing_u); 
# 58
float dx3 = (dx2 + gridspacing_u); 
# 59
float dx4 = (dx3 + gridspacing_u); 
# 60
float dx5 = (dx4 + gridspacing_u); 
# 61
float dx6 = (dx5 + gridspacing_u); 
# 62
float dx7 = (dx6 + gridspacing_u); 
# 63
float dx8 = (dx7 + gridspacing_u); 
# 65
energyvalx1 += ((((atominfo)[atomid]).w) * ((1.0F) / sqrtf((dx1 * dx1) + dyz2))); 
# 66
energyvalx2 += ((((atominfo)[atomid]).w) * ((1.0F) / sqrtf((dx2 * dx2) + dyz2))); 
# 67
energyvalx3 += ((((atominfo)[atomid]).w) * ((1.0F) / sqrtf((dx3 * dx3) + dyz2))); 
# 68
energyvalx4 += ((((atominfo)[atomid]).w) * ((1.0F) / sqrtf((dx4 * dx4) + dyz2))); 
# 69
energyvalx5 += ((((atominfo)[atomid]).w) * ((1.0F) / sqrtf((dx5 * dx5) + dyz2))); 
# 70
energyvalx6 += ((((atominfo)[atomid]).w) * ((1.0F) / sqrtf((dx6 * dx6) + dyz2))); 
# 71
energyvalx7 += ((((atominfo)[atomid]).w) * ((1.0F) / sqrtf((dx7 * dx7) + dyz2))); 
# 72
energyvalx8 += ((((atominfo)[atomid]).w) * ((1.0F) / sqrtf((dx8 * dx8) + dyz2))); 
# 73
}  
# 75
(energygrid[outaddr]) += energyvalx1; 
# 76
(energygrid[outaddr + (1 * 16)]) += energyvalx2; 
# 77
(energygrid[outaddr + (2 * 16)]) += energyvalx3; 
# 78
(energygrid[outaddr + (3 * 16)]) += energyvalx4; 
# 79
(energygrid[outaddr + (4 * 16)]) += energyvalx5; 
# 80
(energygrid[outaddr + (5 * 16)]) += energyvalx6; 
# 81
(energygrid[outaddr + (6 * 16)]) += energyvalx7; 
# 82
(energygrid[outaddr + (7 * 16)]) += energyvalx8; 
# 83
} 
#endif
# 88 "src/cuda/cuenergy_pre8_coalesce.cu"
int copyatomstoconstbuf(float *atoms, int count, float zplane) { 
# 89
if (count > 4000) { 
# 90
printf("Atom count exceeds constant buffer storage capacity\n"); 
# 91
return -1; 
# 92
}  
# 94
float atompre[(4 * 4000)]; 
# 95
int i; 
# 96
for (i = 0; i < (count * 4); i += 4) { 
# 97
((atompre)[i]) = (atoms[i]); 
# 98
((atompre)[i + 1]) = (atoms[i + 1]); 
# 99
float dz = (zplane - (atoms[i + 2])); 
# 100
((atompre)[i + 2]) = (dz * dz); 
# 101
((atompre)[i + 3]) = (atoms[i + 3]); 
# 102
}  
# 104
cudaMemcpyToSymbol(atominfo, atompre, (count * 4) * sizeof(float), 0); 
# 105
{ cudaError_t err; if ((err = cudaGetLastError()) != (cudaSuccess)) { printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 105); return -1; }  } 
# 107
return 0; 
# 108
} 
# 1 "cuenergy_pre8_coalesce.cudafe1.stub.c"
#include "cuenergy_pre8_coalesce.cudafe1.stub.c"
