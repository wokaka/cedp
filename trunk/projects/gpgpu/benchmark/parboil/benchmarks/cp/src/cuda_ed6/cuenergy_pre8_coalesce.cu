/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

#include "gpufi.h"
#include <stdio.h>

#include "cuenergy.h"

#if UNROLLX != 8
# error "UNROLLX must be 8"
#endif

#if BLOCKSIZEX != 16
# error "BLOCKSIZEX must be 16"
#endif

// Max constant buffer size is 64KB, minus whatever
// the CUDA runtime and compiler are using that we don't know about.
// At 16 bytes for atom, for this program 4070 atoms is about the max
// we can store in the constant buffer.
__constant__ float4 atominfo[MAXATOMS];

// This kernel calculates coulombic potential at each grid point and
// stores the results in the output array.

__global__ void cenergy(int numatoms, float gridspacing, float * energygrid) {

  int numatoms_dup = numatoms; //[ED]
  float gridspacing_dup = gridspacing; //[ED]
  float * energygrid_dup = energygrid; //[ED]
  
  unsigned int xindex  = __umul24(blockIdx.x, blockDim.x) * UNROLLX
                         + threadIdx.x;
  unsigned int xindex_dup  = __umul24(blockIdx.x, blockDim.x) * UNROLLX
                         + threadIdx.x;	//[ED]
                         
  unsigned int yindex  = __umul24(blockIdx.y, blockDim.y) + threadIdx.y;
  unsigned int yindex_dup  = __umul24(blockIdx.y, blockDim.y) + threadIdx.y; //[ED]

GPUFI_CHECK(yindex,yindex_dup);
GPUFI_CHECK(xindex,xindex_dup);
  unsigned int outaddr = (__umul24(gridDim.x, blockDim.x) * UNROLLX) * yindex
                         + xindex;
  unsigned int outaddr_dup = (__umul24(gridDim.x, blockDim.x) * UNROLLX) * yindex
                         + xindex;	//[ED]

GPUFI_CHECK(gridspacing,gridspacing_dup);
GPUFI_CHECK(yindex,yindex_dup);
  float coory = gridspacing * yindex;
  float coory_dup = gridspacing * yindex;	//[ED]

GPUFI_CHECK(gridspacing,gridspacing_dup);
GPUFI_CHECK(xindex,xindex_dup);
  float coorx = gridspacing * xindex;
  float coorx_dup = gridspacing * xindex;	//[ED]

  float energyvalx1=0.0f;
  float energyvalx1_dup=0.0f;
  float energyvalx2=0.0f;
  float energyvalx2_dup=0.0f;
  float energyvalx3=0.0f;
  float energyvalx3_dup=0.0f;
  float energyvalx4=0.0f;
  float energyvalx4_dup=0.0f;
  float energyvalx5=0.0f;
  float energyvalx5_dup=0.0f;
  float energyvalx6=0.0f;
  float energyvalx6_dup=0.0f;
  float energyvalx7=0.0f;
  float energyvalx7_dup=0.0f;
  float energyvalx8=0.0f;
  float energyvalx8_dup=0.0f;


GPUFI_CHECK(gridspacing,gridspacing_dup);
  float gridspacing_u = gridspacing * BLOCKSIZEX;
  float gridspacing_u_dup = gridspacing * BLOCKSIZEX;	//[ED]

  int atomid;
  int atomid_dup;


GPUFI_CHECK(numatoms,numatoms_dup);
  for (atomid=0, atomid_dup=0; atomid<numatoms && atomid == atomid_dup; atomid++, atomid_dup++) {
GPUFI_CHECK(coory,coory_dup);
GPUFI_CHECK(atomid,atomid_dup);
    float dy = coory - atominfo[atomid].y;
    float dy_dup = coory - atominfo[atomid].y;	//[ED]
GPUFI_CHECK(dy,dy_dup);
GPUFI_CHECK(atomid,atomid_dup);
    float dyz2 = (dy * dy) + atominfo[atomid].z;
    float dyz2_dup = (dy * dy) + atominfo[atomid].z;	//[ED]

GPUFI_CHECK(coorx,coorx_dup);
    float dx1 = coorx - atominfo[atomid].x;
    float dx1_dup = coorx - atominfo[atomid].x;
GPUFI_CHECK(dx1,dx1_dup);
GPUFI_CHECK(gridspacing_u,gridspacing_u_dup);
    float dx2 = dx1 + gridspacing_u;
    float dx2_dup = dx1 + gridspacing_u;
GPUFI_CHECK(dx2,dx2_dup);
GPUFI_CHECK(gridspacing_u,gridspacing_u_dup);
    float dx3 = dx2 + gridspacing_u;
    float dx3_dup = dx2 + gridspacing_u;
GPUFI_CHECK(dx3,dx3_dup);
GPUFI_CHECK(gridspacing_u,gridspacing_u_dup);
    float dx4 = dx3 + gridspacing_u;
    float dx4_dup = dx3 + gridspacing_u;
GPUFI_CHECK(dx4,dx4_dup);
GPUFI_CHECK(gridspacing_u,gridspacing_u_dup);
    float dx5 = dx4 + gridspacing_u;
    float dx5_dup = dx4 + gridspacing_u;
GPUFI_CHECK(dx5,dx5_dup);
GPUFI_CHECK(gridspacing_u,gridspacing_u_dup);
    float dx6 = dx5 + gridspacing_u;
    float dx6_dup = dx5 + gridspacing_u;
GPUFI_CHECK(dx6,dx6_dup);
GPUFI_CHECK(gridspacing_u,gridspacing_u_dup);
    float dx7 = dx6 + gridspacing_u;
    float dx7_dup = dx6 + gridspacing_u;
GPUFI_CHECK(dx7,dx7_dup);
GPUFI_CHECK(gridspacing_u,gridspacing_u_dup);
    float dx8 = dx7 + gridspacing_u;
    float dx8_dup = dx7 + gridspacing_u;


GPUFI_CHECK(dx1,dx1_dup);
GPUFI_CHECK(dyz2,dyz2_dup);
GPUFI_CHECK(atomid,atomid_dup);
    energyvalx1 += atominfo[atomid].w * (1.0f / sqrtf(dx1*dx1 + dyz2));
    energyvalx1_dup += atominfo[atomid].w * (1.0f / sqrtf(dx1*dx1 + dyz2));
GPUFI_CHECK(dx2,dx2_dup);
GPUFI_CHECK(dyz2,dyz2_dup);
GPUFI_CHECK(atomid,atomid_dup);
    energyvalx2 += atominfo[atomid].w * (1.0f / sqrtf(dx2*dx2 + dyz2));
    energyvalx2_dup += atominfo[atomid].w * (1.0f / sqrtf(dx2*dx2 + dyz2));
GPUFI_CHECK(dx3,dx3_dup);
GPUFI_CHECK(dyz2,dyz2_dup);
GPUFI_CHECK(atomid,atomid_dup);
    energyvalx3 += atominfo[atomid].w * (1.0f / sqrtf(dx3*dx3 + dyz2));
    energyvalx3_dup += atominfo[atomid].w * (1.0f / sqrtf(dx3*dx3 + dyz2));
GPUFI_CHECK(dx4,dx4_dup);
GPUFI_CHECK(dyz2,dyz2_dup);
GPUFI_CHECK(atomid,atomid_dup);
    energyvalx4 += atominfo[atomid].w * (1.0f / sqrtf(dx4*dx4 + dyz2));
    energyvalx4_dup += atominfo[atomid].w * (1.0f / sqrtf(dx4*dx4 + dyz2));
GPUFI_CHECK(dx5,dx5_dup);
GPUFI_CHECK(dyz2,dyz2_dup);
GPUFI_CHECK(atomid,atomid_dup);
    energyvalx5 += atominfo[atomid].w * (1.0f / sqrtf(dx5*dx5 + dyz2));
    energyvalx5_dup += atominfo[atomid].w * (1.0f / sqrtf(dx5*dx5 + dyz2));
GPUFI_CHECK(dx6,dx6_dup);
GPUFI_CHECK(dyz2,dyz2_dup);
GPUFI_CHECK(atomid,atomid_dup);
    energyvalx6 += atominfo[atomid].w * (1.0f / sqrtf(dx6*dx6 + dyz2));
    energyvalx6_dup += atominfo[atomid].w * (1.0f / sqrtf(dx6*dx6 + dyz2));
GPUFI_CHECK(dx7,dx7_dup);
GPUFI_CHECK(dyz2,dyz2_dup);
GPUFI_CHECK(atomid,atomid_dup);
    energyvalx7 += atominfo[atomid].w * (1.0f / sqrtf(dx7*dx7 + dyz2));
    energyvalx7_dup += atominfo[atomid].w * (1.0f / sqrtf(dx7*dx7 + dyz2));
GPUFI_CHECK(dx8,dx8_dup);
GPUFI_CHECK(dyz2,dyz2_dup);
GPUFI_CHECK(atomid,atomid_dup);
    energyvalx8 += atominfo[atomid].w * (1.0f / sqrtf(dx8*dx8 + dyz2));
    energyvalx8_dup += atominfo[atomid].w * (1.0f / sqrtf(dx8*dx8 + dyz2));
  }	

GPUFI_CHECK(energygrid,energygrid_dup);
GPUFI_CHECK(outaddr,outaddr_dup);
GPUFI_CHECK(energyvalx1,energyvalx1_dup);
float temp = energygrid[outaddr];
  energygrid[outaddr]   += energyvalx1;
  temp += energyvalx1;
GPUFI_CHECK(energygrid[outaddr],temp);

GPUFI_CHECK(energygrid,energygrid_dup);
GPUFI_CHECK(outaddr,outaddr_dup);
GPUFI_CHECK(energyvalx2,energyvalx2_dup);
temp = energygrid[outaddr+1*BLOCKSIZEX];
  energygrid[outaddr+1*BLOCKSIZEX] += energyvalx2;
  temp += energyvalx2;
GPUFI_CHECK(energygrid[outaddr+1*BLOCKSIZEX],temp);

GPUFI_CHECK(energygrid,energygrid_dup);
GPUFI_CHECK(outaddr,outaddr_dup);
GPUFI_CHECK(energyvalx3,energyvalx3_dup);
temp = energygrid[outaddr+2*BLOCKSIZEX];
  energygrid[outaddr+2*BLOCKSIZEX] += energyvalx3;
  temp += energyvalx3;
GPUFI_CHECK(energygrid[outaddr+2*BLOCKSIZEX],temp);

GPUFI_CHECK(energygrid,energygrid_dup);
GPUFI_CHECK(outaddr,outaddr_dup);
GPUFI_CHECK(energyvalx4,energyvalx4_dup);
temp = energygrid[outaddr+3*BLOCKSIZEX];
  energygrid[outaddr+3*BLOCKSIZEX] += energyvalx4;
  temp += energyvalx4;
GPUFI_CHECK(energygrid[outaddr+3*BLOCKSIZEX],temp);

GPUFI_CHECK(energygrid,energygrid_dup);
GPUFI_CHECK(outaddr,outaddr_dup);
GPUFI_CHECK(energyvalx5,energyvalx5_dup);
temp = energygrid[outaddr+4*BLOCKSIZEX];
  energygrid[outaddr+4*BLOCKSIZEX] += energyvalx5;
  temp += energyvalx5;
GPUFI_CHECK(energygrid[outaddr+4*BLOCKSIZEX],temp);

GPUFI_CHECK(energygrid,energygrid_dup);
GPUFI_CHECK(outaddr,outaddr_dup);
GPUFI_CHECK(energyvalx6,energyvalx6_dup);
temp = energygrid[outaddr+5*BLOCKSIZEX];
  energygrid[outaddr+5*BLOCKSIZEX] += energyvalx6;
  temp += energyvalx6;
GPUFI_CHECK(energygrid[outaddr+5*BLOCKSIZEX],temp);

GPUFI_CHECK(energygrid,energygrid_dup);
GPUFI_CHECK(outaddr,outaddr_dup);
GPUFI_CHECK(energyvalx7,energyvalx7_dup);
temp = energygrid[outaddr+6*BLOCKSIZEX];
  energygrid[outaddr+6*BLOCKSIZEX] += energyvalx7;
  temp += energyvalx7;
GPUFI_CHECK(energygrid[outaddr+6*BLOCKSIZEX],temp);

GPUFI_CHECK(energygrid,energygrid_dup);
GPUFI_CHECK(outaddr,outaddr_dup);
GPUFI_CHECK(energyvalx8,energyvalx8_dup);
temp = energygrid[outaddr+7*BLOCKSIZEX];
  energygrid[outaddr+7*BLOCKSIZEX] += energyvalx8;
  temp += energyvalx8;
GPUFI_CHECK(energygrid[outaddr+7*BLOCKSIZEX],temp);
}

// This function copies atoms from the CPU to the GPU and
// precalculates (z^2) for each atom.

int copyatomstoconstbuf(float *atoms, int count, float zplane) {
  if (count > MAXATOMS) {
    printf("Atom count exceeds constant buffer storage capacity\n");
    return -1;
  }

  float atompre[4*MAXATOMS];
  int i;
  for (i=0; i<count*4; i+=4) {
    atompre[i    ] = atoms[i    ];
    atompre[i + 1] = atoms[i + 1];
    float dz = zplane - atoms[i + 2];
    atompre[i + 2]  = dz*dz;
    atompre[i + 3] = atoms[i + 3];
  }

  cudaMemcpyToSymbol(atominfo, atompre, count * 4 * sizeof(float), 0);
  CUERR // check and clear any existing errors

  return 0;
}

