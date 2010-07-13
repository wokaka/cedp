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

#include <assert.h>

#include "model.h"

#include <math.h>

#include "gpufi.h"

float *  * g_scanBlockSums;
unsigned int g_numEltsAllocated = 0;
unsigned int g_numLevelsAllocated = 0;
__constant__ float dev_binb[(20+1)];
unsigned int NUM_SETS;
unsigned int NUM_ELEMENTS;
/* create the bin boundaries
 */
void initBinB(struct pb_TimerSet * timers)
{
    float * binb = ((float * )malloc(((20+1)*sizeof (float))));
    int k;
    for (k=0; k<(20+1); k ++ )
    {
        binb[k]=cos((((pow(10.0, (log10(1.0)+((k*1.0)/5)))/60.0)*3.141592653589793)/180.0));
    }
    pb_SwitchToTimer(timers, pb_TimerID_COPY);
    cudaMemcpyToSymbol(dev_binb, binb, ((20+1)*sizeof (float)));
    pb_SwitchToTimer(timers, pb_TimerID_COMPUTE);
    free(binb);
}

__global__ void gen_hists(hist_t * histograms, float * all_x_data, float * all_y_data, float * all_z_data, int NUM_SETS, int NUM_ELEMENTS,  struct _gpufi_data_ *gpufi_dev)
{
    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_BEGIN, 0, "gen_hists");
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 0, "histograms", (int*)&histograms, GPUFI_DATATYPE_UNKNOWN_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 1, "all_x_data", (int*)&all_x_data, GPUFI_DATATYPE_FLOAT_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 2, "all_y_data", (int*)&all_y_data, GPUFI_DATATYPE_FLOAT_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 3, "all_z_data", (int*)&all_z_data, GPUFI_DATATYPE_FLOAT_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 4, "NUM_SETS", (int*)&NUM_SETS, GPUFI_DATATYPE_INTEGER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 5, "NUM_ELEMENTS", (int*)&NUM_ELEMENTS, GPUFI_DATATYPE_INTEGER);


    unsigned int bx = blockIdx.x;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 6, "bx", (int*)&bx, GPUFI_DATATYPE_INTEGER);


    unsigned int tid = threadIdx.x;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 7, "tid", (int*)&tid, GPUFI_DATATYPE_INTEGER);


    bool do_self = (bx<(NUM_SETS+1));
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 8, "do_self", (int*)&do_self, GPUFI_DATATYPE_UNKNOWN);


    float * data_x;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 9, "data_x", (int*)&data_x, GPUFI_DATATYPE_FLOAT_POINTER);


    float * data_y;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 10, "data_y", (int*)&data_y, GPUFI_DATATYPE_FLOAT_POINTER);


    float * data_z;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 11, "data_z", (int*)&data_z, GPUFI_DATATYPE_FLOAT_POINTER);


    float * random_x;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 12, "random_x", (int*)&random_x, GPUFI_DATATYPE_FLOAT_POINTER);


    float * random_y;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 13, "random_y", (int*)&random_y, GPUFI_DATATYPE_FLOAT_POINTER);


    float * random_z;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 14, "random_z", (int*)&random_z, GPUFI_DATATYPE_FLOAT_POINTER);


    __shared__ float data_x_s[256];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 15, "data_x_s", (int*)&data_x_s, GPUFI_DATATYPE_FLOAT);


    __shared__ float data_y_s[256];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 16, "data_y_s", (int*)&data_y_s, GPUFI_DATATYPE_FLOAT);


    __shared__ float data_z_s[256];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 17, "data_z_s", (int*)&data_z_s, GPUFI_DATATYPE_FLOAT);


    volatile __shared__ unsigned int warp_hists[20][((256/32)*16)];
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 18, "warp_hists", (int*)&warp_hists, GPUFI_DATATYPE_INTEGER);


    /* 640B <1k
     */
    unsigned int w;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 19, "w", (int*)&w, GPUFI_DATATYPE_INTEGER);


    unsigned int i;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 20, "i", (int*)&i, GPUFI_DATATYPE_INTEGER);


    unsigned int warp_index;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 21, "warp_index", (int*)&warp_index, GPUFI_DATATYPE_INTEGER);


    unsigned int bin_index;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 22, "bin_index", (int*)&bin_index, GPUFI_DATATYPE_INTEGER);


    unsigned int offset;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 23, "offset", (int*)&offset, GPUFI_DATATYPE_INTEGER);


    unsigned int bin_base;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 24, "bin_base", (int*)&bin_base, GPUFI_DATATYPE_INTEGER);


    hist_t * hist_base;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 25, "hist_base", (int*)&hist_base, GPUFI_DATATYPE_UNKNOWN_POINTER);


    /* Fault Injector Instrumentation Begin */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_BEGIN);
    /* Fault Injector Instrumentation End */

    for (w=0; w<(20*((256/32)*16)); w+=256)
    {
        /* Fault Injector Instrumentation Begin */
        GPUFI_KERNEL_ITERATION(gpufi_dev);
        /* Fault Injector Instrumentation End */

        if (((w+tid)<(20*((256/32)*16))))
        {
            warp_hists[((w+tid)/((256/32)*16))][((w+tid)%((256/32)*16))]=0;
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 28, "warp_hists[((w+tid)/((256/32)*16))][((w+tid)%((256/32)*16))]", (int*)&warp_hists[((w+tid)/((256/32)*16))][((w+tid)%((256/32)*16))], GPUFI_DATATYPE_INTEGER);


        }
    }
    /* Automatically inserted by Cetus_Cuda */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_END);
    /* Fault Injector Instrumentation End *//* End of Cetus_Cuda code */

    GPUFI_KERNEL_VARIABLE(gpufi_dev, 27, "w", (int*)&w, GPUFI_DATATYPE_INTEGER);


    /* Get stuff into shared memory to kick off the loop.
     */
    if (( ! do_self))
    {
        data_x=all_x_data;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 29, "data_x", (int*)&data_x, GPUFI_DATATYPE_FLOAT_POINTER);


        data_y=all_y_data;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 30, "data_y", (int*)&data_y, GPUFI_DATATYPE_FLOAT_POINTER);


        data_z=all_z_data;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 31, "data_z", (int*)&data_z, GPUFI_DATATYPE_FLOAT_POINTER);


        random_x=(all_x_data+(NUM_ELEMENTS*(bx-NUM_SETS)));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 32, "random_x", (int*)&random_x, GPUFI_DATATYPE_FLOAT_POINTER);


        random_y=(all_y_data+(NUM_ELEMENTS*(bx-NUM_SETS)));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 33, "random_y", (int*)&random_y, GPUFI_DATATYPE_FLOAT_POINTER);


        random_z=(all_z_data+(NUM_ELEMENTS*(bx-NUM_SETS)));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 34, "random_z", (int*)&random_z, GPUFI_DATATYPE_FLOAT_POINTER);


    }
    else
    {
        random_x=(all_x_data+(NUM_ELEMENTS*bx));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 35, "random_x", (int*)&random_x, GPUFI_DATATYPE_FLOAT_POINTER);


        random_y=(all_y_data+(NUM_ELEMENTS*bx));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 36, "random_y", (int*)&random_y, GPUFI_DATATYPE_FLOAT_POINTER);


        random_z=(all_z_data+(NUM_ELEMENTS*bx));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 37, "random_z", (int*)&random_z, GPUFI_DATATYPE_FLOAT_POINTER);


        data_x=random_x;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 38, "data_x", (int*)&data_x, GPUFI_DATATYPE_FLOAT_POINTER);


        data_y=random_y;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 39, "data_y", (int*)&data_y, GPUFI_DATATYPE_FLOAT_POINTER);


        data_z=random_z;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 40, "data_z", (int*)&data_z, GPUFI_DATATYPE_FLOAT_POINTER);


    }
    /* Iterate over all data points
     */
    /* Fault Injector Instrumentation Begin */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_BEGIN);
    /* Fault Injector Instrumentation End */

    for (i=0; i<NUM_ELEMENTS; i+=256)
    {
        /* Fault Injector Instrumentation Begin */
        GPUFI_KERNEL_ITERATION(gpufi_dev);
        /* Fault Injector Instrumentation End */

        /* load current set of data into shared memory
         */
        /* (total of BLOCK_SIZE points loaded)
         */
        unsigned int j;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 43, "j", (int*)&j, GPUFI_DATATYPE_INTEGER);


        if (((tid+i)<NUM_ELEMENTS))
        {
            /* reading outside of bounds is a-okay
             */
            data_x_s[tid]=data_x[(tid+i)];
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 44, "data_x_s[tid]", (int*)&data_x_s[tid], GPUFI_DATATYPE_FLOAT);


            data_y_s[tid]=data_y[(tid+i)];
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 45, "data_y_s[tid]", (int*)&data_y_s[tid], GPUFI_DATATYPE_FLOAT);


            data_z_s[tid]=data_z[(tid+i)];
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 46, "data_z_s[tid]", (int*)&data_z_s[tid], GPUFI_DATATYPE_FLOAT);


        }
        __syncthreads();
        /* Iterate over all random points
         */
        for (j=(do_self ? (i+1) : 0); j<NUM_ELEMENTS; j+=256)
        {
            /* load current random point values
             */
            float random_x_s;
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 49, "random_x_s", (int*)&random_x_s, GPUFI_DATATYPE_FLOAT);


            float random_y_s;
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 50, "random_y_s", (int*)&random_y_s, GPUFI_DATATYPE_FLOAT);


            float random_z_s;
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 51, "random_z_s", (int*)&random_z_s, GPUFI_DATATYPE_FLOAT);


            unsigned int k;
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 52, "k", (int*)&k, GPUFI_DATATYPE_INTEGER);


            if (((tid+j)<NUM_ELEMENTS))
            {
                random_x_s=random_x[(tid+j)];
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 53, "random_x_s", (int*)&random_x_s, GPUFI_DATATYPE_FLOAT);


                random_y_s=random_y[(tid+j)];
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 54, "random_y_s", (int*)&random_y_s, GPUFI_DATATYPE_FLOAT);


                random_z_s=random_z[(tid+j)];
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 55, "random_z_s", (int*)&random_z_s, GPUFI_DATATYPE_FLOAT);


            }
            /* Iterate for all elements of current set of data points
             */
            /* (BLOCK_SIZE iterations per thread)
             */
            /* Each thread calcs against 1 random point within cur set of random
             */
            /* (so BLOCK_SIZE threads covers all random points within cur set)
             */
            for (k=0; (k<256)&&((k+i)<NUM_ELEMENTS); k+=1)
            {
                /* do actual calculations on the values:
                 */
                float distance = (((data_x_s[k]*random_x_s)+(data_y_s[k]*random_y_s))+(data_z_s[k]*random_z_s));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 58, "distance", (int*)&distance, GPUFI_DATATYPE_FLOAT);


                /* run binary search
                 */
                unsigned int bin_index;
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 59, "bin_index", (int*)&bin_index, GPUFI_DATATYPE_INTEGER);


                unsigned int min = 0;
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 60, "min", (int*)&min, GPUFI_DATATYPE_INTEGER);


                unsigned int max = 20;
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 61, "max", (int*)&max, GPUFI_DATATYPE_INTEGER);


                unsigned int k2;
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 62, "k2", (int*)&k2, GPUFI_DATATYPE_INTEGER);


                unsigned int warpnum;
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 63, "warpnum", (int*)&warpnum, GPUFI_DATATYPE_INTEGER);


                while ((max>(min+1)))
                {
                    k2=((min+max)/2);
                    GPUFI_KERNEL_VARIABLE(gpufi_dev, 64, "k2", (int*)&k2, GPUFI_DATATYPE_INTEGER);


                    if ((distance>=dev_binb[k2]))
                    {
                        max=k2;
                        GPUFI_KERNEL_VARIABLE(gpufi_dev, 65, "max", (int*)&max, GPUFI_DATATYPE_INTEGER);


                    }
                    else
                    {
                        min=k2;
                        GPUFI_KERNEL_VARIABLE(gpufi_dev, 66, "min", (int*)&min, GPUFI_DATATYPE_INTEGER);


                    }
                }
                warpnum=(tid/(32/16));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 67, "warpnum", (int*)&warpnum, GPUFI_DATATYPE_INTEGER);


                if (((((distance<dev_binb[min])&&(distance>=dev_binb[max]))&&(( ! do_self)||((tid+j)>(i+k))))&&((tid+j)<NUM_ELEMENTS)))
                {
                    unsigned long myVal;
                    GPUFI_KERNEL_VARIABLE(gpufi_dev, 68, "myVal", (int*)&myVal, GPUFI_DATATYPE_UNKNOWN);


                    bin_index=(max-1);
                    GPUFI_KERNEL_VARIABLE(gpufi_dev, 69, "bin_index", (int*)&bin_index, GPUFI_DATATYPE_INTEGER);


                    /* Write into the mini histogram
                     */
                    /* do this until update is not overwritten:
                     */
                    do
                    {
                        /* read the current bin val
                         */
                        myVal=(warp_hists[bin_index][warpnum]&134217727);
                        GPUFI_KERNEL_VARIABLE(gpufi_dev, 70, "myVal", (int*)&myVal, GPUFI_DATATYPE_UNKNOWN);


                        /* increment and put thread tag in top bits
                         */
                        myVal=(((tid&31)<<27)|(myVal+1));
                        GPUFI_KERNEL_VARIABLE(gpufi_dev, 71, "myVal", (int*)&myVal, GPUFI_DATATYPE_UNKNOWN);


                        /* attempt to write the bin
                         */
                        warp_hists[bin_index][warpnum]=myVal;
                        GPUFI_KERNEL_VARIABLE(gpufi_dev, 72, "warp_hists[bin_index][warpnum]", (int*)&warp_hists[bin_index][warpnum], GPUFI_DATATYPE_INTEGER);


                        /* while updates overwritten, keep retrying
                         */
                    }
                    while((warp_hists[bin_index][warpnum]!=myVal));

                }
                __syncthreads();
            }
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 57, "k", (int*)&k, GPUFI_DATATYPE_INTEGER);


        }
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 48, "j", (int*)&j, GPUFI_DATATYPE_INTEGER);


    }
    /* Automatically inserted by Cetus_Cuda */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_END);
    /* Fault Injector Instrumentation End *//* End of Cetus_Cuda code */

    GPUFI_KERNEL_VARIABLE(gpufi_dev, 42, "i", (int*)&i, GPUFI_DATATYPE_INTEGER);


    /* coalesce the histograms in a block
     */
    warp_index=(tid&((((256/32)*16)>>1)-1));
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 73, "warp_index", (int*)&warp_index, GPUFI_DATATYPE_INTEGER);


    bin_index=(tid/(((256/32)*16)>>1));
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 74, "bin_index", (int*)&bin_index, GPUFI_DATATYPE_INTEGER);


    /* Fault Injector Instrumentation Begin */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_BEGIN);
    /* Fault Injector Instrumentation End */

    for (offset=(((256/32)*16)>>1); offset>0; offset>>=1)
    {
        /* Fault Injector Instrumentation Begin */
        GPUFI_KERNEL_ITERATION(gpufi_dev);
        /* Fault Injector Instrumentation End */

        for (bin_base=0; bin_base<20; bin_base+=(256/(((256/32)*16)>>1)))
        {
            __syncthreads();
            if (((warp_index<offset)&&((bin_base+bin_index)<20)))
            {
                unsigned long sum = (warp_hists[(bin_base+bin_index)][warp_index]+warp_hists[(bin_base+bin_index)][(warp_index+offset)]);
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 79, "sum", (int*)&sum, GPUFI_DATATYPE_UNKNOWN);


                warp_hists[(bin_base+bin_index)][warp_index]=sum;
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 80, "warp_hists[(bin_base+bin_index)][warp_index]", (int*)&warp_hists[(bin_base+bin_index)][warp_index], GPUFI_DATATYPE_INTEGER);


            }
        }
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 78, "bin_base", (int*)&bin_base, GPUFI_DATATYPE_INTEGER);


    }
    /* Automatically inserted by Cetus_Cuda */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_END);
    /* Fault Injector Instrumentation End *//* End of Cetus_Cuda code */

    GPUFI_KERNEL_VARIABLE(gpufi_dev, 76, "offset", (int*)&offset, GPUFI_DATATYPE_INTEGER);


    __syncthreads();
    /* Put the results back in the real histogram
     */
    /* warp_hists[x][0] holds sum of all locations of bin x
     */
    hist_base=(histograms+(20*bx));
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 81, "hist_base", (int*)&hist_base, GPUFI_DATATYPE_UNKNOWN_POINTER);


    if ((tid<20))
    {
        hist_base[tid]=(warp_hists[tid][0]&134217727);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 82, "hist_base[tid]", (int*)&hist_base[tid], GPUFI_DATATYPE_UNKNOWN);


    }
    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_END, 0, "gen_hists");
}

void TPACF(hist_t * histograms, float * d_x_data, float * d_y_data, float * d_z_data)
{
    dim3 dimBlock;
    dim3 dimGrid;
    dimBlock.x=256;
    dimGrid.x=((NUM_SETS*2)+1);
    /* Fault Injection Instrumentation Begin */
    cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));
    CUDA_ERRCK
    cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);
    CUDA_ERRCK
    /* Fault Injection Instrumentation End */

    gen_hists<<<dimGrid, dimBlock>>> (histograms, d_x_data, d_y_data, d_z_data, NUM_SETS, NUM_ELEMENTS, gpufi_dev);
    /* Fault Injection Instrumentation Begin */
    cudaMemcpy(&gpufi_host, gpufi_dev, sizeof(struct _gpufi_data_), cudaMemcpyDeviceToHost);
    CUDA_ERRCK
    cudaFree(gpufi_dev);
    CUDA_ERRCK
    /* Fault Injection Instrumentation End */

}
