/*
 * Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:   
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and 
 * international Copyright laws.  Users and possessors of this source code 
 * are hereby granted a nonexclusive, royalty-free license to use this code 
 * in individual and commercial software.
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE 
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR 
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH 
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF 
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL, 
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS 
 * OF USE, DATA OR PROFITS,  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE 
 * OR OTHER TORTIOUS ACTION,  ARISING OUT OF OR IN CONNECTION WITH THE USE 
 * OR PERFORMANCE OF THIS SOURCE CODE.  
 *
 * U.S. Government End Users.   This source code is a "commercial item" as 
 * that term is defined at  48 C.F.R. 2.101 (OCT 1995), consisting  of 
 * "commercial computer  software"  and "commercial computer software 
 * documentation" as such terms are  used in 48 C.F.R. 12.212 (SEPT 1995) 
 * and is provided to the U.S. Government only as a commercial end item.  
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through 
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the 
 * source code with only those rights set forth herein. 
 *
 * Any use of this source code in individual and commercial software must 
 * include, in the user documentation and internal comments to the code,
 * the above Disclaimer and U.S. Government End Users Notice.
 */

#ifndef CUDAGL_H
#define CUDAGL_H

#ifdef __cplusplus
extern "C" {
#endif

//
// Flags to map or unmap a resource
//
typedef enum CUGLmap_flags_enum {
    CU_GL_MAP_RESOURCE_FLAGS_NONE          = 0x00,
    CU_GL_MAP_RESOURCE_FLAGS_READ_ONLY     = 0x01,
    CU_GL_MAP_RESOURCE_FLAGS_WRITE_DISCARD = 0x02,    
} CUGLmap_flags;

CUresult CUDAAPI cuGLInit(void);
CUresult CUDAAPI cuGLCtxCreate( CUcontext *pCtx, unsigned int Flags, CUdevice device );
CUresult CUDAAPI cuGLRegisterBufferObject( GLuint bufferobj );
CUresult CUDAAPI cuGLMapBufferObject( CUdeviceptr *dptr, unsigned int *size,  GLuint bufferobj ); 
CUresult CUDAAPI cuGLUnmapBufferObject( GLuint bufferobj );
CUresult CUDAAPI cuGLUnregisterBufferObject( GLuint bufferobj );

CUresult CUDAAPI cuGLSetBufferObjectMapFlags( GLuint bufferobj, unsigned int Flags );
CUresult CUDAAPI cuGLMapBufferObjectAsync( CUdeviceptr *dptr, unsigned int *size,  GLuint bufferobj, CUstream hStream );
CUresult CUDAAPI cuGLUnmapBufferObjectAsync( GLuint bufferobj, CUstream hStream );

#if defined(_WIN32)
#if !defined(WGL_NV_gpu_affinity)
typedef void* HGPUNV;
#endif
CUresult CUDAAPI cuWGLGetDevice( CUdevice *pDevice, HGPUNV hGpu );
#endif

#ifdef __cplusplus
};
#endif

#endif
