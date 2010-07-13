/*
**************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 **************************************************************************
*/
#include <stdio.h> 
#include "cuenergy.h" 
/* Max constant buffer size is 64KB, minus whatever */
/* the CUDA runtime and compiler are using that we don't know about. */
/* At 16 bytes for atom, for this program 4070 atoms is about the max */
/* we can store in the constant buffer. */
__constant__ float4 atominfo[4000];
/* This kernel calculates coulombic potential at each grid point and */
/* stores the results in the output array. */
__global__ void cenergy(int numatoms, float gridspacing, float * energygrid)
{
unsigned int xindex = ((__umul24(blockIdx.x, blockDim.x)*8)+threadIdx.x);
unsigned int yindex = (__umul24(blockIdx.y, blockDim.y)+threadIdx.y);
unsigned int outaddr = (((__umul24(gridDim.x, blockDim.x)*8)*yindex)+xindex);
float coory = (gridspacing*yindex);
float coorx = (gridspacing*xindex);
float energyvalx1 = 0.0;
float energyvalx2 = 0.0;
float energyvalx3 = 0.0;
float energyvalx4 = 0.0;
float energyvalx5 = 0.0;
float energyvalx6 = 0.0;
float energyvalx7 = 0.0;
float energyvalx8 = 0.0;
float gridspacing_u = (gridspacing*16);
int atomid;
for (atomid=0; atomid<numatoms; atomid ++ )
{
float dy = (coory-atominfo[atomid].y);
float dyz2 = ((dy*dy)+atominfo[atomid].z);
float dx1 = (coorx-atominfo[atomid].x);
float dx2 = (dx1+gridspacing_u);
float dx3 = (dx2+gridspacing_u);
float dx4 = (dx3+gridspacing_u);
float dx5 = (dx4+gridspacing_u);
float dx6 = (dx5+gridspacing_u);
float dx7 = (dx6+gridspacing_u);
float dx8 = (dx7+gridspacing_u);
energyvalx1+=(atominfo[atomid].w*(1.0/sqrtf(((dx1*dx1)+dyz2))));
energyvalx2+=(atominfo[atomid].w*(1.0/sqrtf(((dx2*dx2)+dyz2))));
energyvalx3+=(atominfo[atomid].w*(1.0/sqrtf(((dx3*dx3)+dyz2))));
energyvalx4+=(atominfo[atomid].w*(1.0/sqrtf(((dx4*dx4)+dyz2))));
energyvalx5+=(atominfo[atomid].w*(1.0/sqrtf(((dx5*dx5)+dyz2))));
energyvalx6+=(atominfo[atomid].w*(1.0/sqrtf(((dx6*dx6)+dyz2))));
energyvalx7+=(atominfo[atomid].w*(1.0/sqrtf(((dx7*dx7)+dyz2))));
energyvalx8+=(atominfo[atomid].w*(1.0/sqrtf(((dx8*dx8)+dyz2))));
}
energygrid[outaddr]+=energyvalx1;
energygrid[(outaddr+(1*16))]+=energyvalx2;
energygrid[(outaddr+(2*16))]+=energyvalx3;
energygrid[(outaddr+(3*16))]+=energyvalx4;
energygrid[(outaddr+(4*16))]+=energyvalx5;
energygrid[(outaddr+(5*16))]+=energyvalx6;
energygrid[(outaddr+(6*16))]+=energyvalx7;
energygrid[(outaddr+(7*16))]+=energyvalx8;
}

/* This function copies atoms from the CPU to the GPU and */
/* precalculates (z^2) for each atom. */
int copyatomstoconstbuf(float * atoms, int count, float zplane)
{
float atompre[(4*4000)];
int i;
if ((count>4000))
{
printf("Atom count exceeds constant buffer storage capacity\n");
return ( - 1);
}
for (i=0; i<(count*4); i+=4)
{
float dz;
atompre[i]=atoms[i];
atompre[(i+1)]=atoms[(i+1)];
dz=(zplane-atoms[(i+2)]);
atompre[(i+2)]=(dz*dz);
atompre[(i+3)]=atoms[(i+3)];
}
cudaMemcpyToSymbol(atominfo, atompre, ((count*4)*sizeof (float)), 0);
if (1)
{
;
}
/* check and clear any existing errors */
return 0;
}

