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
#include "gpufi.h"

/* #include <stdio.h>
 */
#include "cuenergy.h"

/* typedef double float4;
 */
/* Max constant buffer size is 64KB, minus whatever
 */
/* the CUDA runtime and compiler are using that we don't know about.
 */
/* At 16 bytes for atom, for this program 4070 atoms is about the max
 */
/* we can store in the constant buffer.
 */
__constant__ float4 atominfo[4000];
/* This kernel calculates coulombic potential at each grid point and
 */
/* stores the results in the output array.
 */
__global__ void cenergy(int numatoms, float gridspacing, float * energygrid,  struct _gpufi_data_ *gpufi_dev)
{
    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_BEGIN, 0, "cenergy");
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 0, "numatoms", (int*)&numatoms, GPUFI_DATATYPE_INTEGER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 1, "gridspacing", (int*)&gridspacing, GPUFI_DATATYPE_FLOAT);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 2, "energygrid", (int*)&energygrid, GPUFI_DATATYPE_FLOAT_POINTER);


    unsigned int xindex = ((__umul24(blockIdx.x, blockDim.x)*8)+threadIdx.x);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 3, "xindex", (int*)&xindex, GPUFI_DATATYPE_INTEGER);


    unsigned int yindex = (__umul24(blockIdx.y, blockDim.y)+threadIdx.y);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 4, "yindex", (int*)&yindex, GPUFI_DATATYPE_INTEGER);


    unsigned int outaddr = (((__umul24(gridDim.x, blockDim.x)*8)*yindex)+xindex);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 5, "outaddr", (int*)&outaddr, GPUFI_DATATYPE_INTEGER);


    float coory = (gridspacing*yindex);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 6, "coory", (int*)&coory, GPUFI_DATATYPE_FLOAT);


    float coorx = (gridspacing*xindex);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 7, "coorx", (int*)&coorx, GPUFI_DATATYPE_FLOAT);


    float energyvalx1 = 0.0;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 8, "energyvalx1", (int*)&energyvalx1, GPUFI_DATATYPE_FLOAT);


    float energyvalx2 = 0.0;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 9, "energyvalx2", (int*)&energyvalx2, GPUFI_DATATYPE_FLOAT);


    float energyvalx3 = 0.0;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 10, "energyvalx3", (int*)&energyvalx3, GPUFI_DATATYPE_FLOAT);


    float energyvalx4 = 0.0;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 11, "energyvalx4", (int*)&energyvalx4, GPUFI_DATATYPE_FLOAT);


    float energyvalx5 = 0.0;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 12, "energyvalx5", (int*)&energyvalx5, GPUFI_DATATYPE_FLOAT);


    float energyvalx6 = 0.0;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 13, "energyvalx6", (int*)&energyvalx6, GPUFI_DATATYPE_FLOAT);


    float energyvalx7 = 0.0;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 14, "energyvalx7", (int*)&energyvalx7, GPUFI_DATATYPE_FLOAT);


    float energyvalx8 = 0.0;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 15, "energyvalx8", (int*)&energyvalx8, GPUFI_DATATYPE_FLOAT);


    float gridspacing_u = (gridspacing*16);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 16, "gridspacing_u", (int*)&gridspacing_u, GPUFI_DATATYPE_FLOAT);


    int atomid;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 17, "atomid", (int*)&atomid, GPUFI_DATATYPE_INTEGER);


    /* Fault Injector Instrumentation Begin */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_BEGIN);
    /* Fault Injector Instrumentation End */

    for (atomid=0; atomid<numatoms; atomid ++ )
    {
        /* Fault Injector Instrumentation Begin */
        GPUFI_KERNEL_ITERATION(gpufi_dev);
        /* Fault Injector Instrumentation End */

        float dy = (coory-atominfo[atomid].y);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 20, "dy", (int*)&dy, GPUFI_DATATYPE_FLOAT);


        float dyz2 = ((dy*dy)+atominfo[atomid].z);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 21, "dyz2", (int*)&dyz2, GPUFI_DATATYPE_FLOAT);


        float dx1 = (coorx-atominfo[atomid].x);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 22, "dx1", (int*)&dx1, GPUFI_DATATYPE_FLOAT);


        float dx2 = (dx1+gridspacing_u);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 23, "dx2", (int*)&dx2, GPUFI_DATATYPE_FLOAT);


        float dx3 = (dx2+gridspacing_u);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 24, "dx3", (int*)&dx3, GPUFI_DATATYPE_FLOAT);


        float dx4 = (dx3+gridspacing_u);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 25, "dx4", (int*)&dx4, GPUFI_DATATYPE_FLOAT);


        float dx5 = (dx4+gridspacing_u);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 26, "dx5", (int*)&dx5, GPUFI_DATATYPE_FLOAT);


        float dx6 = (dx5+gridspacing_u);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 27, "dx6", (int*)&dx6, GPUFI_DATATYPE_FLOAT);


        float dx7 = (dx6+gridspacing_u);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 28, "dx7", (int*)&dx7, GPUFI_DATATYPE_FLOAT);


        float dx8 = (dx7+gridspacing_u);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 29, "dx8", (int*)&dx8, GPUFI_DATATYPE_FLOAT);


        energyvalx1+=(atominfo[atomid].w*(1.0/sqrtf(((dx1*dx1)+dyz2))));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 30, "energyvalx1", (int*)&energyvalx1, GPUFI_DATATYPE_FLOAT);


        energyvalx2+=(atominfo[atomid].w*(1.0/sqrtf(((dx2*dx2)+dyz2))));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 31, "energyvalx2", (int*)&energyvalx2, GPUFI_DATATYPE_FLOAT);


        energyvalx3+=(atominfo[atomid].w*(1.0/sqrtf(((dx3*dx3)+dyz2))));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 32, "energyvalx3", (int*)&energyvalx3, GPUFI_DATATYPE_FLOAT);


        energyvalx4+=(atominfo[atomid].w*(1.0/sqrtf(((dx4*dx4)+dyz2))));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 33, "energyvalx4", (int*)&energyvalx4, GPUFI_DATATYPE_FLOAT);


        energyvalx5+=(atominfo[atomid].w*(1.0/sqrtf(((dx5*dx5)+dyz2))));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 34, "energyvalx5", (int*)&energyvalx5, GPUFI_DATATYPE_FLOAT);


        energyvalx6+=(atominfo[atomid].w*(1.0/sqrtf(((dx6*dx6)+dyz2))));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 35, "energyvalx6", (int*)&energyvalx6, GPUFI_DATATYPE_FLOAT);


        energyvalx7+=(atominfo[atomid].w*(1.0/sqrtf(((dx7*dx7)+dyz2))));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 36, "energyvalx7", (int*)&energyvalx7, GPUFI_DATATYPE_FLOAT);


        energyvalx8+=(atominfo[atomid].w*(1.0/sqrtf(((dx8*dx8)+dyz2))));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 37, "energyvalx8", (int*)&energyvalx8, GPUFI_DATATYPE_FLOAT);


    }
    /* Automatically inserted by Cetus_Cuda */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_END);
    /* Fault Injector Instrumentation End *//* End of Cetus_Cuda code */

    GPUFI_KERNEL_VARIABLE(gpufi_dev, 19, "atomid", (int*)&atomid, GPUFI_DATATYPE_INTEGER);


    energygrid[outaddr]+=energyvalx1;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 38, "energygrid[outaddr]", (int*)&energygrid[outaddr], GPUFI_DATATYPE_FLOAT);


    energygrid[(outaddr+(1*16))]+=energyvalx2;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 39, "energygrid[(outaddr+(1*16))]", (int*)&energygrid[(outaddr+(1*16))], GPUFI_DATATYPE_FLOAT);


    energygrid[(outaddr+(2*16))]+=energyvalx3;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 40, "energygrid[(outaddr+(2*16))]", (int*)&energygrid[(outaddr+(2*16))], GPUFI_DATATYPE_FLOAT);


    energygrid[(outaddr+(3*16))]+=energyvalx4;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 41, "energygrid[(outaddr+(3*16))]", (int*)&energygrid[(outaddr+(3*16))], GPUFI_DATATYPE_FLOAT);


    energygrid[(outaddr+(4*16))]+=energyvalx5;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 42, "energygrid[(outaddr+(4*16))]", (int*)&energygrid[(outaddr+(4*16))], GPUFI_DATATYPE_FLOAT);


    energygrid[(outaddr+(5*16))]+=energyvalx6;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 43, "energygrid[(outaddr+(5*16))]", (int*)&energygrid[(outaddr+(5*16))], GPUFI_DATATYPE_FLOAT);


    energygrid[(outaddr+(6*16))]+=energyvalx7;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 44, "energygrid[(outaddr+(6*16))]", (int*)&energygrid[(outaddr+(6*16))], GPUFI_DATATYPE_FLOAT);


    energygrid[(outaddr+(7*16))]+=energyvalx8;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 45, "energygrid[(outaddr+(7*16))]", (int*)&energygrid[(outaddr+(7*16))], GPUFI_DATATYPE_FLOAT);


    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_END, 0, "cenergy");
}

/* This function copies atoms from the CPU to the GPU and
 */
/* precalculates (z^2) for each atom.
 */
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
    /* check and clear any existing errors
     */
    return 0;
}
