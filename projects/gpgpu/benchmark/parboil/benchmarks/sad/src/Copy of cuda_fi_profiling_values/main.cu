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

#include <stdio.h>

#include <stdlib.h>

#include <sys/time.h>

#include <inttypes.h>

#include "parboil.h"

#include "cuda.h"

#include "sad.h"

#include "sad4.h"

#include "largerBlocks.h"

#include "file.h"

#include "image.h"

#include "largerBlocks.cu"

#include "sad4.cu"

#include "gpufi.h"

static unsigned short * load_sads(char * filename);
static void write_sads(char * filename, int image_size_macroblocks, unsigned short * sads);
static void write_sads_directly(char * filename, int width, int height, unsigned short * sads);
/* FILE I/O */
unsigned short * load_sads(char * filename)
{
    FILE * infile;
    unsigned short * sads;
    int w;
    int h;
    int sads_per_block;
    infile=fopen(filename, "r");
    if (( ! infile))
    {
        fprintf(stderr, "Cannot find file '%s'\n", filename);
        exit(( - 1));
    }
    /* Read image dimensions (measured in macroblocks) */
    w=read16u(infile);
    h=read16u(infile);
    /*
    Read SAD values.  Only interested in the 4x4 SAD values, which are
       * at the end of the file.
    */
    sads_per_block=(1096*(w*h));
    fseek(infile, ((25*sads_per_block)*sizeof (unsigned short)), 1);
    sads=((unsigned short * )malloc(((sads_per_block*16)*sizeof (unsigned short))));
    fread(sads, sizeof (unsigned short), (sads_per_block*16), infile);
    fclose(infile);
    return sads;
}

/*
Compare the reference SADs to the expected SADs.
 
*/
void check_sads(unsigned short * sads_reference, unsigned short * sads_computed, int image_size_macroblocks)
{
    int block;
    /*
    Check the 4x4 SAD values.  These are in sads_reference.
       * Ignore the data at the beginning of sads_computed.
    */
    sads_computed+=((25*1096)*image_size_macroblocks);
    for (block=0; block<image_size_macroblocks; block ++ )
    {
        int subblock;
        for (subblock=0; subblock<16; subblock ++ )
        {
            int sad_index;
            for (sad_index=0; sad_index<1089; sad_index ++ )
            {
                int index = ((((block*16)+subblock)*1096)+sad_index);
                if ((sads_reference[index]!=sads_computed[index]))
                {
                    goto mismatch;
                }
            }
        }
    }
    printf("Success.\n");
    return ;
    {
mismatch:
        printf("Computed SADs do not match expected values.\n");
    }
}

/*
Extract the SAD data for a particular block type for a particular
 * macroblock from the array of SADs of that block type.
*/
static inline void write_subblocks(FILE * outfile, unsigned short * subblock_array, int macroblock, int count)
{
    int block;
    int pos;
    for (block=0; block<count; block ++ )
    {
        unsigned short * vec = (subblock_array+((block+(macroblock*count))*1096));
        /* Write all SADs for this sub-block */
        for (pos=0; pos<1089; pos ++ )
        {
            write16u(outfile, ( * (vec ++ )));
        }
    }
}

void write_sads(char * filename, int image_size_macroblocks, unsigned short * sads)
{
    FILE * outfile = fopen(filename, "w");
    int block;
    if ((outfile==NULL))
    {
        fprintf(stderr, "Cannot open output file\n");
        exit(( - 1));
    }
    /* Write size in macroblocks */
    write32u(outfile, image_size_macroblocks);
    /* Write zeros */
    write32u(outfile, 0);
    /* Each macroblock */
    for (block=0; block<image_size_macroblocks; block ++ )
    {
        int blocktype;
        /* Write SADs for all sub-block types */
        for (blocktype=1; blocktype<=7; blocktype ++ )
        {
            write_subblocks(outfile, (sads+((blocktype==1) ? 0 : ((blocktype==2) ? (image_size_macroblocks*1096) : ((blocktype==3) ? (image_size_macroblocks*(3*1096)) : ((blocktype==4) ? (image_size_macroblocks*(5*1096)) : ((blocktype==5) ? (image_size_macroblocks*(9*1096)) : ((blocktype==6) ? (image_size_macroblocks*(17*1096)) : (image_size_macroblocks*(25*1096))))))))), block, ((blocktype==1) ? 1 : ((blocktype==2) ? 2 : ((blocktype==3) ? 2 : ((blocktype==4) ? 4 : ((blocktype==5) ? 8 : ((blocktype==6) ? 8 : 16)))))));
        }
    }
    fclose(outfile);
}

/* FILE I/O for debugging */
static void write_sads_directly(char * filename, int width, int height, unsigned short * sads)
{
    FILE * f = fopen(filename, "w");
    int n;
    write16u(f, width);
    write16u(f, height);
    for (n=0; n<((41*1096)*(width*height)); n ++ )
    {
        write16u(f, sads[n]);
    }
    fclose(f);
}

static void print_test_sad_vector(unsigned short * base, int macroblock, int count)
{
    int n;
    int searchpos = ((17*33)+17);
    for (n=0; n<count; n ++ )
    {
        printf(" %d", base[((((count*macroblock)+n)*1096)+searchpos)]);
    }
}

static void print_test_sads(unsigned short * sads_computed, int mbs)
{
    int macroblock = 5;
    int blocktype;
    for (blocktype=1; blocktype<=7; blocktype ++ )
    {
        printf("%d:", blocktype);
        print_test_sad_vector((sads_computed+((blocktype==1) ? 0 : ((blocktype==2) ? (mbs*1096) : ((blocktype==3) ? (mbs*(3*1096)) : ((blocktype==4) ? (mbs*(5*1096)) : ((blocktype==5) ? (mbs*(9*1096)) : ((blocktype==6) ? (mbs*(17*1096)) : (mbs*(25*1096))))))))), macroblock, ((blocktype==1) ? 1 : ((blocktype==2) ? 2 : ((blocktype==3) ? 2 : ((blocktype==4) ? 4 : ((blocktype==5) ? 8 : ((blocktype==6) ? 8 : 16)))))));
        puts("\n");
    }
}

/* MAIN */
int stream_data = 0;
int main(int argc, char *  * argv)
{
    struct image_i16 * ref_image;
    struct image_i16 * cur_image;
    unsigned short * sads_computed;
    /* SADs generated by the program */
    GPUFI_INIT(3, 129);


    int image_size_bytes;
    int image_width_macroblocks, image_height_macroblocks;
    int image_size_macroblocks;
    struct pb_TimerSet timers;
    struct pb_Parameters * params;
    pb_InitializeTimerSet(( & timers));
    params=pb_ReadParameters(( & argc), argv);
    if ((pb_Parameters_CountInputs(params)!=2))
    {
        fprintf(stderr, "Expecting two input filenames\n");
        exit(( - 1));
    }
    /* Read input files */
    pb_SwitchToTimer(( & timers), pb_TimerID_IO);
    ref_image=load_image(params->inpFiles[0]);
    cur_image=load_image(params->inpFiles[1]);
    pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
    if (((ref_image->width!=cur_image->width)||(ref_image->height!=cur_image->height)))
    {
        fprintf(stderr, "Input images must be the same size\n");
        exit(( - 1));
    }
    if (((ref_image->width%16)||(ref_image->height%16)))
    {
        fprintf(stderr, "Input image size must be an integral multiple of 16\n");
        exit(( - 1));
    }
    /* Compute parameters, allocate memory */
    image_size_bytes=((ref_image->width*ref_image->height)*sizeof (short));
    image_width_macroblocks=(ref_image->width>>4);
    image_height_macroblocks=(ref_image->height>>4);
    image_size_macroblocks=(image_width_macroblocks*image_height_macroblocks);
    sads_computed=((unsigned short * )malloc((((41*1096)*image_size_macroblocks)*sizeof (short))));
    /* Run the kernel code */
    {
        struct cudaArray * ref_ary;
        /* Reference image on the device */
        short * d_cur_image;
        /* Current image on the device */
        unsigned short * d_sads;
        /* SADs on the device */
        dim3 macroblock_grid( image_width_macroblocks,  image_height_macroblocks);
        pb_SwitchToTimer(( & timers), pb_TimerID_COPY);
        cudaMalloc(((void *  * )( & d_cur_image)), image_size_bytes);
        stream_data+=image_size_bytes;
        {
            cudaError_t err = cudaGetLastError();
            if (err)
            {
                fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
            }
        }
        cudaMallocArray(( & ref_ary), ( & get_ref().channelDesc), ref_image->width, ref_image->height);
        stream_data+=(ref_image->width*ref_image->height);
        {
            cudaError_t err = cudaGetLastError();
            if (err)
            {
                fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
            }
        }
        /* Transfer current image to device */
        cudaMemcpy(d_cur_image, cur_image->data, image_size_bytes, cudaMemcpyHostToDevice);
        {
            cudaError_t err = cudaGetLastError();
            if (err)
            {
                fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
            }
        }
        /* Transfer reference image to device */
        cudaMemcpy2DToArray(ref_ary, 0, 0, ref_image->data, (ref_image->width*sizeof (unsigned short)), (ref_image->width*sizeof (unsigned short)), ref_image->height, cudaMemcpyHostToDevice);
        {
            cudaError_t err = cudaGetLastError();
            if (err)
            {
                fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
            }
        }
        cudaBindTextureToArray(get_ref(), ref_ary);
        {
            cudaError_t err = cudaGetLastError();
            if (err)
            {
                fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
            }
        }
        /* Allocate SAD data on the device */
        cudaMalloc(((void *  * )( & d_sads)), (((41*1096)*image_size_macroblocks)*sizeof (unsigned short)));
        stream_data+=(((41*1096)*image_size_macroblocks)*sizeof (unsigned short));
        printf("stream_data %d\n", stream_data);
        {
            cudaError_t err = cudaGetLastError();
            if (err)
            {
                fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
            }
        }
        cudaMemset(d_sads, 0, (((41*1096)*image_size_macroblocks)*sizeof (unsigned short)));
        {
            cudaError_t err = cudaGetLastError();
            if (err)
            {
                fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
            }
        }
        if (params->synchronizeGpu)
        {
            cudaThreadSynchronize();
        }
        pb_SwitchToTimer(( & timers), pb_TimerID_GPU);
        /* Run the 4x4 kernel */
        /* Fault Injection Instrumentation Begin */
        cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));
        CUDA_ERRCK
        cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);
        CUDA_ERRCK
        /* Fault Injection Instrumentation End */

        mb_sad_calc<<<dim3((((ref_image->width/4)+(1-1))/1), (((ref_image->height/4)+(1-1))/1)), dim3(((((1089+(18-1))/18)*1)*1)), (((1*1)*1096)*sizeof (unsigned short))>>> (d_sads, ((unsigned short * )d_cur_image), image_width_macroblocks, image_height_macroblocks, gpufi_dev);
        /* Fault Injection Instrumentation Begin */
        cudaMemcpy(&gpufi_host, gpufi_dev, sizeof(struct _gpufi_data_), cudaMemcpyDeviceToHost);
        CUDA_ERRCK
        cudaFree(gpufi_dev);
        CUDA_ERRCK
        /* Fault Injection Instrumentation End */

        {
            cudaError_t err = cudaGetLastError();
            if (err)
        {
            fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
            }
        }
        /* Run the larger-blocks kernels */
        /* Fault Injection Instrumentation Begin */
        cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));
        CUDA_ERRCK
        cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);
        CUDA_ERRCK
        /* Fault Injection Instrumentation End */

        larger_sad_calc_8<<<macroblock_grid, dim3(32, 4)>>> (d_sads, image_width_macroblocks, image_height_macroblocks, gpufi_dev);
        /* Fault Injection Instrumentation Begin */
        cudaMemcpy(&gpufi_host, gpufi_dev, sizeof(struct _gpufi_data_), cudaMemcpyDeviceToHost);
        CUDA_ERRCK
        cudaFree(gpufi_dev);
        CUDA_ERRCK
        /* Fault Injection Instrumentation End */

        {
            cudaError_t err = cudaGetLastError();
            if (err)
        {
            fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
            }
        }
        /* Fault Injection Instrumentation Begin */
        cudaMalloc((void**)&gpufi_dev, sizeof(struct _gpufi_data_));
        CUDA_ERRCK
        cudaMemcpy(gpufi_dev, &gpufi_host, sizeof(struct _gpufi_data_), cudaMemcpyHostToDevice);
        CUDA_ERRCK
        /* Fault Injection Instrumentation End */

        larger_sad_calc_16<<<macroblock_grid, dim3(32, 1)>>> (d_sads, image_width_macroblocks, image_height_macroblocks, gpufi_dev);
        /* Fault Injection Instrumentation Begin */
        cudaMemcpy(&gpufi_host, gpufi_dev, sizeof(struct _gpufi_data_), cudaMemcpyDeviceToHost);
        CUDA_ERRCK
        cudaFree(gpufi_dev);
        CUDA_ERRCK
        /* Fault Injection Instrumentation End */

        {
            cudaError_t err = cudaGetLastError();
            if (err)
        {
            fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
            }
        }
        if (params->synchronizeGpu)
        {
            cudaThreadSynchronize();
        }
        pb_SwitchToTimer(( & timers), pb_TimerID_COPY);
        /* Transfer SAD data to the host */
        /* + 25 * MAX_POS_PADDED * image_size_macroblocks,
         */
        /* + 25 * MAX_POS_PADDED * image_size_macroblocks,
         */
        cudaMemcpy(sads_computed, d_sads, (((41*1096)*image_size_macroblocks)*sizeof (unsigned short)), cudaMemcpyDeviceToHost);
        {
            cudaError_t err = cudaGetLastError();
            if (err)
            {
                fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
            }
        }
        /* Free GPU memory */
        cudaFree(d_sads);
        {
            cudaError_t err = cudaGetLastError();
            if (err)
            {
                fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
            }
        }
        cudaUnbindTexture(get_ref());
        {
            cudaError_t err = cudaGetLastError();
            if (err)
            {
                fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
            }
        }
        cudaFreeArray(ref_ary);
        {
            cudaError_t err = cudaGetLastError();
            if (err)
            {
                fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
            }
        }
        cudaFree(d_cur_image);
        {
            cudaError_t err = cudaGetLastError();
            if (err)
            {
                fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err));
            }
        }
        if (params->synchronizeGpu)
        {
            cudaThreadSynchronize();
        }
        pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
    }
    /* Print output */
    if (params->outFile)
    {
        pb_SwitchToTimer(( & timers), pb_TimerID_IO);
        write_sads(params->outFile, image_size_macroblocks, sads_computed);
        pb_SwitchToTimer(( & timers), pb_TimerID_COMPUTE);
    }
    /* Free memory */
    free(sads_computed);
    free_image(ref_image);
    free_image(cur_image);
    pb_SwitchToTimer(( & timers), pb_TimerID_NONE);
    pb_PrintTimerSet(( & timers));
    pb_FreeParameters(params);
    GPUFI_HALT("fi_profile.txt");
    return 0;
    GPUFI_HALT("fi_profile.txt");
}
