/* Instrumented by FaultInjector */
#include "gpufi.h"

/*
**************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 **************************************************************************
*/
#include "randomc.h"

#include "gpufi.h"

/*
 
   The following two functions implement the Mersenne Twister random 
   number generator.  The copyright notice/disclaimer, etc are related
   to this code.
 
   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.                          
 
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
 
     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
 
     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
 
     3. The names of its contributors may not be used to endorse or promote 
        products derived from this software without specific prior written 
        permission.
 
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 
*/
void RandomInit(uint32 seed)
{
    int i;
    /* re-seed generator
     */
    if ((threadIdx.x==0))
    {
        mt[0]=(seed&0XFFFFFFFF);
        for (i=1; i<624; i ++ )
        {
            mt[i]=((1812433253*(mt[(i-1)]^(mt[(i-1)]>>30)))+i);
        }
    }
    __syncthreads();
}

void BRandom(  )
{
    /* generate 32 random bits
     */
    uint32 y;
    int thdx;
    /* block size is 256
     */
    /* step 1: 0-226, MERS_N-MERS_M=227
     */
    if ((threadIdx.x<(624-397)))
    {
        y=((mt[threadIdx.x]&(MASK<<31))|(mt[(threadIdx.x+1)]&((1<<31)-1)));
        y=((mt[(threadIdx.x+397)]^(y>>1))^((y&1) ? MERS_A : 0));
    }
    __syncthreads();
    if ((threadIdx.x<(624-397)))
    {
        mt[threadIdx.x]=y;
    }
    __syncthreads();
    /* step 2: 227-453
     */
    thdx=(threadIdx.x+(624-397));
    if ((threadIdx.x<(624-397)))
    {
        y=((mt[thdx]&(MASK<<31))|(mt[(thdx+1)]&((1<<31)-1)));
        y=((mt[threadIdx.x]^(y>>1))^((y&1) ? MERS_A : 0));
    }
    __syncthreads();
    if ((threadIdx.x<(624-397)))
    {
        mt[thdx]=y;
    }
    __syncthreads();
    /* step 3: 454-622
     */
    thdx+=(624-397);
    if ((thdx<(624-1)))
    {
        y=((mt[thdx]&(MASK<<31))|(mt[(thdx+1)]&((1<<31)-1)));
        y=((mt[(threadIdx.x+(624-397))]^(y>>1))^((y&1) ? MERS_A : 0));
    }
    __syncthreads();
    if ((thdx<(624-1)))
    {
        mt[thdx]=y;
    }
    __syncthreads();
    /* step 4: 623
     */
    if ((threadIdx.x==0))
    {
        y=((mt[(624-1)]&(MASK<<31))|(mt[0]&((1<<31)-1)));
        mt[(624-1)]=((mt[(397-1)]^(y>>1))^((y&1) ? MERS_A : 0));
    }
    __syncthreads();
    /* Tempering (May be omitted):
     */
    y^=(y>>11);
    y^=((y<<7)&MERS_B);
    y^=((y<<15)&MERS_C);
    y^=(y>>18);
}
