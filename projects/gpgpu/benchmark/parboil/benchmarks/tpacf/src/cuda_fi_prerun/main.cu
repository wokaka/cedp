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

#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include <math.h>

#include "args.h"

#include "model.h"

#include "scan_largearray_kernel.cu"

#include "gpufi.h"

extern unsigned int NUM_SETS;
extern unsigned int NUM_ELEMENTS;
int main(int argc, char *  * argv)
{
    struct pb_TimerSet timers;
    struct pb_Parameters * params;
    options args;
    int num_elements;
    unsigned mem_size;
    unsigned f_mem_size;
    struct cartesian * h_all_data;
    struct cartesian * working;
    int i, j;
    float * h_x_data;
    float * h_y_data;
    float * h_z_data;
    float * d_x_data;
    float * d_y_data;
    float * d_z_data;
    hist_t * d_hists;
    hist_t * new_hists;
    hist_t * dd_hist;
    hist_t * rr_hist;
    hist_t * dr_hist;
    int rr[20];
    int dr[20];
    int dd_t = 0;
    int dr_t = 0;
    int rr_t = 0;
    FILE * outfile;
    pb_InitializeTimerSet(( & timers));
    GPUFI_INIT(1, 83);


    params=pb_ReadParameters(( & argc), argv);
    parse_args(argc, argv, ( & args));
    pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
    NUM_ELEMENTS=args.npoints;
    NUM_SETS=args.random_count;
    num_elements=NUM_ELEMENTS;
    printf("Min distance: %f arcmin\n", 1.0);
    printf("Max distance: %f arcmin\n", 10000.0);
    printf("Bins per dec: %i\n", 5);
    printf("Total bins  : %i\n", 20);
    /* read in files
     */
    mem_size=(((1+NUM_SETS)*num_elements)*sizeof (struct cartesian));
    f_mem_size=(((1+NUM_SETS)*num_elements)*sizeof (float));
    /* container for all the points read from files
     */
    h_all_data=((struct cartesian * )malloc(mem_size));
    /* Until I can get libs fixed
     */
    /* iterator for data files
     */
    working=h_all_data;
    /* go through and read all data and random points into h_all_data
     */
    pb_SwitchToTimer(( & timers), pb_TimerID_IO);
    readdatafile(params->inpFiles[0], working, num_elements);
    pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
    working+=num_elements;
    for (i=0; i<NUM_SETS; i ++ )
    {
        pb_SwitchToTimer(( & timers), pb_TimerID_IO);
        readdatafile(params->inpFiles[(i+1)], working, num_elements);
        pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
        working+=num_elements;
    }
    /* split into x, y, and z arrays
     */
    h_x_data=((float * )malloc((3*f_mem_size)));
    h_y_data=(h_x_data+(NUM_ELEMENTS*(NUM_SETS+1)));
    h_z_data=(h_y_data+(NUM_ELEMENTS*(NUM_SETS+1)));
    for (i=0; i<(NUM_SETS+1);  ++ i)
    {
        for (j=0; j<NUM_ELEMENTS;  ++ j)
        {
            h_x_data[((i*NUM_ELEMENTS)+j)]=h_all_data[((i*NUM_ELEMENTS)+j)].x;
            h_y_data[((i*NUM_ELEMENTS)+j)]=h_all_data[((i*NUM_ELEMENTS)+j)].y;
            h_z_data[((i*NUM_ELEMENTS)+j)]=h_all_data[((i*NUM_ELEMENTS)+j)].z;
        }
    }
    /* from on use x, y, and z arrays, free h_all_data
     */
    free(h_all_data);
    pb_SwitchToTimer(( & timers), pb_TimerID_COPY);
    /* allocate cuda memory to hold all points
     */
    cudaMalloc(((void *  * )( & d_x_data)), (3*f_mem_size));
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 117);
            GPUFI_HALT("fi_profile.txt");
            return ( - 1);
        }
    }
    d_y_data=(d_x_data+(NUM_ELEMENTS*(NUM_SETS+1)));
    d_z_data=(d_y_data+(NUM_ELEMENTS*(NUM_SETS+1)));
    /* allocate cuda memory to hold final histograms
     */
    /* (1 for dd, and NUM_SETS for dr and rr apiece)
     */
    cudaMalloc(((void *  * )( & d_hists)), ((20*((NUM_SETS*2)+1))*sizeof (hist_t)));
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 125);
            GPUFI_HALT("fi_profile.txt");
            return ( - 1);
        }
    }
    pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
    /* allocate system memory for final histograms
     */
    new_hists=((hist_t * )malloc(((20*((NUM_SETS*2)+1))*sizeof (hist_t))));
    /* Initialize the boundary constants for bin search
     */
    initBinB(( & timers));
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 134);
            GPUFI_HALT("fi_profile.txt");
            return ( - 1);
        }
    }
    /* **===------------------ Kick off TPACF on CUDA------------------===**
     */
    pb_SwitchToTimer(( & timers), pb_TimerID_COPY);
    cudaMemcpy(d_x_data, h_x_data, (3*f_mem_size), cudaMemcpyHostToDevice);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 139);
            GPUFI_HALT("fi_profile.txt");
            return ( - 1);
        }
    }
    if (params->synchronizeGpu)
    {
        cudaThreadSynchronize();
    }
    pb_SwitchToTimer(( & timers), pb_TimerID_GPU);
    TPACF(d_hists, d_x_data, d_y_data, d_z_data);
    if (params->synchronizeGpu)
    {
        cudaThreadSynchronize();
    }
    pb_SwitchToTimer(( & timers), pb_TimerID_COPY);
    cudaMemcpy(new_hists, d_hists, ((20*((NUM_SETS*2)+1))*sizeof (hist_t)), cudaMemcpyDeviceToHost);
    {
        cudaError_t err;
        if (((err=cudaGetLastError())!=cudaSuccess))
        {
            printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), 149);
            GPUFI_HALT("fi_profile.txt");
            return ( - 1);
        }
    }
    pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
    /* **===-----------------------------------------------------------===**
     */
    /* references into output histograms
     */
    dd_hist=new_hists;
    rr_hist=(dd_hist+20);
    dr_hist=(rr_hist+(20*NUM_SETS));
    /* add up values within dr and rr
     */
    for (i=0; i<20; i ++ )
    {
        rr[i]=0;
    }
    for (i=0; i<NUM_SETS; i ++ )
    {
        for (j=0; j<20; j ++ )
        {
            rr[j]+=rr_hist[((i*20)+j)];
        }
    }
    for (i=0; i<20; i ++ )
    {
        dr[i]=0;
    }
    for (i=0; i<NUM_SETS; i ++ )
    {
        for (j=0; j<20; j ++ )
        {
            dr[j]+=dr_hist[((i*20)+j)];
        }
    }
    if (((outfile=fopen(params->outFile, "w"))==NULL))
    {
        fprintf(stderr, "Unable to open output file %s for writing, ""assuming stdout\n", params->outFile);
        outfile=stdout;
    }
    /* print out final histograms + omega (while calculating omega)
     */
    for (i=0; i<20; i ++ )
    {
        float w = ((((100.0*dd_hist[i])-dr[i])/rr[i])+1.0);
        pb_SwitchToTimer(( & timers), pb_TimerID_IO);
        fprintf(outfile, "%f\n", w);
        pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
        dd_t+=dd_hist[i];
        dr_t+=dr[i];
        rr_t+=rr[i];
    }
    if ((outfile!=stdout))
    {
        fclose(outfile);
    }
    /* cleanup memory
     */
    free(new_hists);
    free(h_x_data);
    pb_SwitchToTimer(( & timers), pb_TimerID_COPY);
    cudaFree(d_hists);
    cudaFree(d_x_data);
    pb_SwitchToTimer(( & timers), pb_TimerID_NONE);
    pb_PrintTimerSet(( & timers));
    pb_FreeParameters(params);
    GPUFI_HALT("fi_profile.txt");
}
