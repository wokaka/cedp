#ifndef __GPU_FI_H__
#define __GPU_FI_H__

#include "gpufi_kernel.cu"

#define GPUFI_CHECK(n1,n2) { if(n1 != n2) GPUFI_EXIT(0); }

#endif
