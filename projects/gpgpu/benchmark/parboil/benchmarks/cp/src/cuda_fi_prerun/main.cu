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
/*
 
 * CUDA accelerated coulombic potential grid test code
 *   John E. Stone <johns@ks.uiuc.edu>
 *   http:www.ks.uiuc.edu/~johns/
 *
 * Coulombic potential grid calculation microbenchmark based on the time
 * consuming portions of the 'cionize' ion placement tool.
 
*/
#include "gpufi.h"

#include "parboil.h"

#include <stdio.h>

#include <stdlib.h>

#include "cuenergy.h"

#include "cuenergy_pre8_coalesce.cu"

#include "gpufi.h"

/*
initatoms()
 * Store a pseudorandom arrangement of point charges in *atombuf.
 
*/
static int initatoms(float *  * atombuf, int count, dim3 volsize, float gridspacing)
{
    dim3 size;
    int i;
    float * atoms;
    srand(54321);
    /* Ensure that atom placement is repeatable
     */
    atoms=((float * )malloc(((count*4)*sizeof (float))));
    ( * atombuf)=atoms;
    /* compute grid dimensions in angstroms
     */
    size.x=(gridspacing*volsize.x);
    size.y=(gridspacing*volsize.y);
    size.z=(gridspacing*volsize.z);
    for (i=0; i<count; i ++ )
    {
        int addr = (i*4);
        atoms[addr]=((rand()/((float)2147483647))*size.x);
        atoms[(addr+1)]=((rand()/((float)2147483647))*size.y);
        atoms[(addr+2)]=((rand()/((float)2147483647))*size.z);
        atoms[(addr+3)]=(((rand()/((float)2147483647))*2.0)-1.0);
        /* charge
         */
    }
    return 0;
}

/*
writeenergy()
 * Write part of the energy array to an output file for verification.
 
*/
static int writeenergy(char * filename, float * energy, dim3 volsize)
{
    FILE * outfile;
    int x, y;
    outfile=fopen(filename, "w");
    if ((outfile==NULL))
    {
        fputs("Cannot open output file\n", stderr);
        return ( - 1);
    }
    /* Print the execution parameters */
    fprintf(outfile, "%d %d %d %d\n", volsize.x, volsize.y, volsize.z, 40000);
    /* Print a checksum */
    {
        double sum = 0.0;
        for (y=0; y<volsize.y; y ++ )
        {
            for (x=0; x<volsize.x; x ++ )
            {
                double t = energy[((y*volsize.x)+x)];
                t=fmax(( - 20.0), fmin(20.0, t));
                sum+=t;
            }
        }
        fprintf(outfile, "%.4g\n", sum);
    }
    /* Print several rows of the computed data */
    for (y=0; y<17; y ++ )
    {
        for (x=0; x<volsize.x; x ++ )
        {
            int addr = ((y*volsize.x)+x);
            fprintf(outfile, "%.4g ", energy[addr]);
        }
        fprintf(outfile, "\n");
    }
    fclose(outfile);
    return 0;
}

int main(int argc, char *  * argv)
{
    struct pb_TimerSet timers;
    struct pb_Parameters * parameters;
    float * energy = NULL;
    /* Output of device calculation
     */
    GPUFI_INIT(1, 46);


    float * atoms = NULL;
    dim3 volsize, Gsz, Bsz;
    /* int final_iteration_count;
     */
    /* number of atoms to simulate
     */
    int atomcount = 40000;
    /* voxel spacing
     */
    const float gridspacing = 0.1;
    /* Size of buffer on GPU
     */
    int volmemsz;
    printf("CUDA accelerated coulombic potential microbenchmark\n");
    printf("Original version by John E. Stone <johns@ks.uiuc.edu>\n");
    printf("This version maintained by Chris Rodrigues\n");
    parameters=pb_ReadParameters(( & argc), argv);
    if (( ! parameters))
    {
        GPUFI_HALT("fi_profile.txt");
        return ( - 1);
    }
    if (parameters->inpFiles[0])
    {
        fputs("No input files expected\n", stderr);
        GPUFI_HALT("fi_profile.txt");
        return ( - 1);
    }
    pb_InitializeTimerSet(( & timers));
    pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
    /* setup energy grid size
     */
    volsize.x=512;
    volsize.y=512;
    volsize.z=1;
    /* setup CUDA grid and block sizes
     */
    Bsz.x=16;
    /* each thread does multiple Xs
     */
    Bsz.y=8;
    Bsz.z=1;
    Gsz.x=(volsize.x/(Bsz.x*8));
    /* each thread does multiple Xs
     */
    Gsz.y=(volsize.y/Bsz.y);
    Gsz.z=(volsize.z/Bsz.z);
    /* allocate and initialize atom coordinates and charges
     */
    if (initatoms(( & atoms), atomcount, volsize, gridspacing))
    {
        GPUFI_HALT("fi_profile.txt");
        return ( - 1);
    }
    /* allocate and initialize the GPU output array
     */
    volmemsz=(((sizeof (float)*volsize.x)*volsize.y)*volsize.z);
    /* Main computation
     */
    {
        float * d_output = NULL;
        /* Output on device
         */
        int iterations = 0;
        int atomstart;
        pb_SwitchToTimer(( & timers), pb_TimerID_COPY);
        cudaMalloc(((void *  * )( & d_output)), volmemsz);
        if (1)
        {
            ;
        }
        /* check and clear any existing errors
         */
        cudaMemset(d_output, 0, volmemsz);
        if (1)
        {
            ;
        }
        /* check and clear any existing errors
         */
        pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
        for (atomstart=0; atomstart<atomcount; atomstart+=4000)
        {
            int atomsremaining = (atomcount-atomstart);
            int runatoms = ((atomsremaining>4000) ? 4000 : atomsremaining);
            iterations ++ ;
            /* copy the atoms to the GPU
             */
            pb_SwitchToTimer(( & timers), pb_TimerID_COPY);
            if (copyatomstoconstbuf((atoms+(4*atomstart)), runatoms, (0*gridspacing)))
            {
                GPUFI_HALT("fi_profile.txt");
                return ( - 1);
            }
            if (parameters->synchronizeGpu)
            {
                cudaThreadSynchronize();
            }
            pb_SwitchToTimer(( & timers), pb_TimerID_GPU);
            /* RUN the kernel...
             */
            /* Fault Injection Instrumentation Begin */
            cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));
            CUDA_ERRCK
            cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);
            CUDA_ERRCK
            /* Fault Injection Instrumentation End */

            cenergy<<<Gsz, Bsz, 0>>> (runatoms, 0.1, d_output, gpufi_dev);
            /* Fault Injection Instrumentation Begin */
            cudaMemcpy(&gpufi_host, gpufi_dev, sizeof(struct _gpufi_data_), cudaMemcpyDeviceToHost);
            CUDA_ERRCK
            cudaFree(gpufi_dev);
            CUDA_ERRCK
            /* Fault Injection Instrumentation End */

            if (1)
            {
                ;
            }
            /* check and clear any existing errors
             */
            if (parameters->synchronizeGpu)
            {
                cudaThreadSynchronize();
            }
            pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
            /* final_iteration_count = iterations;
             */
        }
        /* Copy the GPU output data back to the host and use/store it..
         */
        energy=((float * )malloc(volmemsz));
        pb_SwitchToTimer(( & timers), pb_TimerID_COPY);
        cudaMemcpy(energy, d_output, volmemsz, cudaMemcpyDeviceToHost);
        if (1)
        {
            ;
        }
        /* check and clear any existing errors
         */
        cudaFree(d_output);
        pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
    }
    /* Print a subset of the results to a file */
    if (parameters->outFile)
    {
        pb_SwitchToTimer(( & timers), pb_TimerID_IO);
        if ((writeenergy(parameters->outFile, energy, volsize)==( - 1)))
        {
            GPUFI_HALT("fi_profile.txt");
            return ( - 1);
        }
        pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
    }
    free(atoms);
    free(energy);
    pb_SwitchToTimer(( & timers), pb_TimerID_NONE);
    pb_PrintTimerSet(( & timers));
    pb_FreeParameters(parameters);
    GPUFI_HALT("fi_profile.txt");
    return 0;
    GPUFI_HALT("fi_profile.txt");
}
