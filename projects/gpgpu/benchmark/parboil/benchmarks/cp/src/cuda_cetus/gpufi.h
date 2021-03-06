//#ifndef __GPUFI_H__
//#define __GPUFI_H__

#include <vector_types.h>

#ifndef GPU_CETUS
#define GPU_CETUS
#endif

/* CUDA Built-in Types */
/*
typedef struct {char x;} char1;
typedef struct {unsigned char x;} uchar1;
typedef struct {char x, y;} char2;
typedef struct {unsigned char x, y;} uchar2;
typedef struct {char x, y, z;} char3;
typedef struct {unsigned char x, y, z;} uchar3;
typedef struct {char x, y, z, w;} char4;
typedef struct {unsigned char x, y, z, w;} uchar4;

typedef struct {short x;} short1;
typedef struct {unsigned short x;} ushort1;
typedef struct {short x, y;} short2;
typedef struct {unsigned short x, y;} ushort2;
typedef struct {short x, y, z;} short3;
typedef struct {unsigned short x, y, z;} ushort3;
typedef struct {short x, y, z, w;} short4;
typedef struct {unsigned short x, y, z, w;} ushort4;

typedef struct {int x;} int1;
typedef struct {unsigned int x;} uint1;
typedef struct {int x, y;} int2;
typedef struct {unsigned int x, y;} uint2;
typedef struct {int x, y, z;} int3;
typedef struct {unsigned int x, y, z;} uint3;
typedef struct {int x, y, z, w;} int4;
typedef struct {unsigned int x, y, z, w;} uint4;

typedef struct {long x;} long1;
typedef struct {unsigned long x;} ulong1;
typedef struct {long x, y;} long2;
typedef struct {unsigned long x, y;} ulong2;
typedef struct {long x, y, z;} long3;
typedef struct {unsigned long x, y, z;} ulong3;
typedef struct {long x, y, z, w;} long4;
typedef struct {unsigned long x, y, z, w;} ulong4;

typedef struct {float x;} float1;
typedef struct {unsigned float x;} ufloat1;
typedef struct {float x, y;} float2;
typedef struct {unsigned float x, y;} ufloat2;
typedef struct {float x, y, z;} float3;
typedef struct {unsigned float x, y, z;} ufloat3;
typedef struct {float x, y, z, w;} float4;
typedef struct {unsigned float x, y, z, w;} ufloat4;

typedef struct {double x;} double1;
typedef struct {unsigned double x;} udouble1;
typedef struct {double x, y;} double2;
typedef struct {unsigned double x, y;} udouble2;
typedef struct {double x, y, z;} double3;
typedef struct {unsigned double x, y, z;} udouble3;
typedef struct {double x, y, z, w;} double4;
typedef struct {unsigned double x, y, z, w;} udouble4;
*/
#undef NULL
typedef uint3 dim3;
typedef struct kValues kValues;
typedef struct cudaError_t cudaError_t;

/* PNS */
typedef unsigned long uint32;
#undef MERS_A
#undef MERS_B
#undef MERS_C
//#undef MASK

//typedef struct Atom Atom;

#ifdef __device__
#undef __device__
#endif
//#endif