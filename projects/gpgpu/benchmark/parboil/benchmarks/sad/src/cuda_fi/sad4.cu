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

#include "sad.h"

#include "sad4.h"

/* Macros to access temporary frame storage in shared memory */
/* Macros to access temporary SAD storage in shared memory */
/*
When reading from this array, we use an "index" rather than a
   search position.  Also, the number of array elements is divided by
   four relative to SAD_LOC_GET() since this is an array of 8byte
   data, while SAD_LOC_GET() sees an array of 2byte data.
*/
/*
The size of one row of sad_loc_8b.  This is the group of elements
 * holding SADs for all search positions for one 4x4 block.
*/
/*
The presence of this preprocessor variable controls which
 * of two means of computing the current search position is used.
*/
/* A local copy of the current 4x4 block */
__shared__ unsigned short frame_loc[((1*1)*16)];
/* The part of the reference image that is in the search range */
texture<unsigned short, 2, cudaReadModeElementType> ref;
/*
The local SAD array on the device.  This is an array of short ints.  It is
 * interpreted as an array of 8-byte data for global data transfers.
*/
extern __shared__ unsigned short sad_loc[];
extern __shared__ struct vec8b sad_loc_8b[];
/* The compute kernel. */
/*
The macros THREADS_W and THREADS_H specify the width and height of the
 * area to be processed by one thread, measured in 4-by-4 pixel blocks.
 * Larger numbers mean more computation per thread block.
 *
 * The macro POS_PER_THREAD specifies the number of search positions for which
 * an SAD is computed.  A larger value indicates more computation per thread,
 * and fewer threads per thread block.  It must be a multiple of 3 and also
 * must be at most 33 because the loop to copy from shared memory uses
 * 32 threads per 4-by-4 pixel block.
 *
 
*/
__global__ void mb_sad_calc(unsigned short * blk_sad, unsigned short * frame, int mb_width, int mb_height,  struct _gpufi_data_ *gpufi_dev)
{
    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_BEGIN, 0, "mb_sad_calc");
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 0, "blk_sad", (int*)&blk_sad, GPUFI_DATATYPE_UNKNOWN_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 1, "frame", (int*)&frame, GPUFI_DATATYPE_UNKNOWN_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 2, "mb_width", (int*)&mb_width, GPUFI_DATATYPE_INTEGER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 3, "mb_height", (int*)&mb_height, GPUFI_DATATYPE_INTEGER);


    int txy_tmp = (threadIdx.x/((1089+(18-1))/18));
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 4, "txy_tmp", (int*)&txy_tmp, GPUFI_DATATYPE_INTEGER);


    int ty = (txy_tmp/1);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 5, "ty", (int*)&ty, GPUFI_DATATYPE_INTEGER);


    int tx = (txy_tmp-__umul24(ty, 1));
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 6, "tx", (int*)&tx, GPUFI_DATATYPE_INTEGER);


    int bx = blockIdx.x;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 7, "bx", (int*)&bx, GPUFI_DATATYPE_INTEGER);


    int by = blockIdx.y;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 8, "by", (int*)&by, GPUFI_DATATYPE_INTEGER);


    /* Macroblock and sub-block coordinates */
    int mb_x = ((tx+__umul24(bx, 1))>>2);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 9, "mb_x", (int*)&mb_x, GPUFI_DATATYPE_INTEGER);


    int mb_y = ((ty+__umul24(by, 1))>>2);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 10, "mb_y", (int*)&mb_y, GPUFI_DATATYPE_INTEGER);


    int block_x = ((tx+__umul24(bx, 1))&3);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 11, "block_x", (int*)&block_x, GPUFI_DATATYPE_INTEGER);


    int block_y = ((ty+__umul24(by, 1))&3);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 12, "block_y", (int*)&block_y, GPUFI_DATATYPE_INTEGER);


    /*
    Block-copy data into shared memory.
       * Threads are grouped into sets of 16, leaving some threads idle.
    */
    if (((threadIdx.x>>4)<(1*1)))
    {
        int ty = ((threadIdx.x>>4)/1);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 13, "ty", (int*)&ty, GPUFI_DATATYPE_INTEGER);


        int tx = ((threadIdx.x>>4)-__umul24(ty, 1));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 14, "tx", (int*)&tx, GPUFI_DATATYPE_INTEGER);


        int tgroup = (threadIdx.x&15);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 15, "tgroup", (int*)&tgroup, GPUFI_DATATYPE_INTEGER);


        /* Width of the image in pixels */
        int img_width = (mb_width*16);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 16, "img_width", (int*)&img_width, GPUFI_DATATYPE_INTEGER);


        /* Pixel offset of the origin of the current 4x4 block */
        int frame_x = ((tx+__umul24(bx, 1))<<2);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 17, "frame_x", (int*)&frame_x, GPUFI_DATATYPE_INTEGER);


        int frame_y = ((ty+__umul24(by, 1))<<2);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 18, "frame_y", (int*)&frame_y, GPUFI_DATATYPE_INTEGER);


        /* Origin in the current frame for this 4x4 block */
        int cur_o = ((frame_y*img_width)+frame_x);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 19, "cur_o", (int*)&cur_o, GPUFI_DATATYPE_INTEGER);


        /* If this is an invalid 4x4 block, do nothing */
        if ((((frame_x>>4)<mb_width)&&((frame_y>>4)<mb_height)))
        {
            /* Copy one pixel into 'frame' */
            frame_loc[(((__umul24(ty, 1)+tx)<<4)+tgroup)]=frame[((cur_o+((tgroup>>2)*img_width))+(tgroup&3))];
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 20, "frame_loc[(((__umul24(ty, 1)+tx)<<4)+tgroup)]", (int*)&frame_loc[(((__umul24(ty, 1)+tx)<<4)+tgroup)], GPUFI_DATATYPE_UNKNOWN);


        }
    }
    __syncthreads();
    /* If this thread is assigned to an invalid 4x4 block, do nothing */
    if (((mb_x<mb_width)&&(mb_y<mb_height)))
    {
        /* Pixel offset of the origin of the current 4x4 block */
        int frame_x = (((mb_x<<2)+block_x)<<2);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 21, "frame_x", (int*)&frame_x, GPUFI_DATATYPE_INTEGER);


        int frame_y = (((mb_y<<2)+block_y)<<2);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 22, "frame_y", (int*)&frame_y, GPUFI_DATATYPE_INTEGER);


        /* Origin of the search area for this 4x4 block */
        int ref_x = (frame_x-16);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 23, "ref_x", (int*)&ref_x, GPUFI_DATATYPE_INTEGER);


        int ref_y = (frame_y-16);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 24, "ref_y", (int*)&ref_y, GPUFI_DATATYPE_INTEGER);


        /* Origin in the current frame for this 4x4 block */
        int cur_o = ((ty*1)+tx);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 25, "cur_o", (int*)&cur_o, GPUFI_DATATYPE_INTEGER);


        int search_pos;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 26, "search_pos", (int*)&search_pos, GPUFI_DATATYPE_INTEGER);


        int search_pos_base = ((threadIdx.x%((1089+(18-1))/18))*18);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 27, "search_pos_base", (int*)&search_pos_base, GPUFI_DATATYPE_INTEGER);


        int search_pos_end = (search_pos_base+18);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 28, "search_pos_end", (int*)&search_pos_end, GPUFI_DATATYPE_INTEGER);


        int sotmp = (search_pos_base/((2*16)+1));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 29, "sotmp", (int*)&sotmp, GPUFI_DATATYPE_INTEGER);


        int local_search_off_x = (search_pos_base-((sotmp<<5)+sotmp));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 30, "local_search_off_x", (int*)&local_search_off_x, GPUFI_DATATYPE_INTEGER);


        int search_off_y = (ref_y+sotmp);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 31, "search_off_y", (int*)&search_off_y, GPUFI_DATATYPE_INTEGER);


        /* Don't go past bounds */
        if ((search_pos_end>1089))
        {
            search_pos_end=1089;
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 32, "search_pos_end", (int*)&search_pos_end, GPUFI_DATATYPE_INTEGER);


        }
        /* For each search position, within the range allocated to this thread */
        /* Fault Injector Instrumentation Begin */
        GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_BEGIN);
        /* Fault Injector Instrumentation End */

        for (search_pos=search_pos_base; search_pos<search_pos_end; search_pos+=3)
        {
            /*
            It is also beneficial to fuse (jam) the enclosed loops if this loop
            	 * is unrolled.
            */
            /* Fault Injector Instrumentation Begin */
            GPUFI_KERNEL_ITERATION(gpufi_dev);
            /* Fault Injector Instrumentation End */

            unsigned short sad1 = 0, sad2 = 0, sad3 = 0;
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 35, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


            int search_off_x = (ref_x+local_search_off_x);
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 36, "search_off_x", (int*)&search_off_x, GPUFI_DATATYPE_INTEGER);


            /* 4x4 SAD computation */
            int y;
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 37, "y", (int*)&y, GPUFI_DATATYPE_INTEGER);


            /*
             
            	for(y=0; y<4; y++) {
            	  int t;
            	  t = tex2D(ref, search_off_x, search_off_y + y);
            	  sad1 += abs(t - FRAME_GET(cur_o, 0, y));
             
            	  t = tex2D(ref, search_off_x + 1, search_off_y + y);
            	  sad1 += abs(t - FRAME_GET(cur_o, 1, y));
            	  sad2 += abs(t - FRAME_GET(cur_o, 0, y));
             
            	  t = tex2D(ref, search_off_x + 2, search_off_y + y);
            	  sad1 += abs(t - FRAME_GET(cur_o, 2, y));
            	  sad2 += abs(t - FRAME_GET(cur_o, 1, y));
            	  sad3 += abs(t - FRAME_GET(cur_o, 0, y));
             
            	  t = tex2D(ref, search_off_x + 3, search_off_y + y);
            	  sad1 += abs(t - FRAME_GET(cur_o, 3, y));
            	  sad2 += abs(t - FRAME_GET(cur_o, 2, y));
            	  sad3 += abs(t - FRAME_GET(cur_o, 1, y));
             
            	  t = tex2D(ref, search_off_x + 4, search_off_y + y);
            	  sad2 += abs(t - FRAME_GET(cur_o, 3, y));
            	  sad3 += abs(t - FRAME_GET(cur_o, 2, y));
             
            	  t = tex2D(ref, search_off_x + 5, search_off_y + y);
            	  sad3 += abs(t - FRAME_GET(cur_o, 3, y));
            	}
            	
            */
            {
                /* y = 0 */
                int t;
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 38, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                y=0;
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 39, "y", (int*)&y, GPUFI_DATATYPE_INTEGER);


                t=tex2D(ref, search_off_x, (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 40, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad1+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+0)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 41, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+1), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 42, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad1+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+1)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 43, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


                sad2+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+0)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 44, "sad2", (int*)&sad2, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+2), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 45, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad1+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+2)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 46, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


                sad2+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+1)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 47, "sad2", (int*)&sad2, GPUFI_DATATYPE_UNKNOWN);


                sad3+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+0)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 48, "sad3", (int*)&sad3, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+3), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 49, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad1+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+3)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 50, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


                sad2+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+2)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 51, "sad2", (int*)&sad2, GPUFI_DATATYPE_UNKNOWN);


                sad3+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+1)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 52, "sad3", (int*)&sad3, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+4), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 53, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad2+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+3)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 54, "sad2", (int*)&sad2, GPUFI_DATATYPE_UNKNOWN);


                sad3+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+2)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 55, "sad3", (int*)&sad3, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+5), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 56, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad3+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+3)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 57, "sad3", (int*)&sad3, GPUFI_DATATYPE_UNKNOWN);


                /* y = 1 */
                y=1;
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 58, "y", (int*)&y, GPUFI_DATATYPE_INTEGER);


                t=tex2D(ref, search_off_x, (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 59, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad1+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+0)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 60, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+1), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 61, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad1+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+1)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 62, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


                sad2+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+0)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 63, "sad2", (int*)&sad2, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+2), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 64, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad1+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+2)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 65, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


                sad2+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+1)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 66, "sad2", (int*)&sad2, GPUFI_DATATYPE_UNKNOWN);


                sad3+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+0)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 67, "sad3", (int*)&sad3, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+3), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 68, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad1+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+3)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 69, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


                sad2+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+2)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 70, "sad2", (int*)&sad2, GPUFI_DATATYPE_UNKNOWN);


                sad3+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+1)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 71, "sad3", (int*)&sad3, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+4), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 72, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad2+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+3)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 73, "sad2", (int*)&sad2, GPUFI_DATATYPE_UNKNOWN);


                sad3+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+2)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 74, "sad3", (int*)&sad3, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+5), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 75, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad3+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+3)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 76, "sad3", (int*)&sad3, GPUFI_DATATYPE_UNKNOWN);


                /* y = 2 */
                y=2;
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 77, "y", (int*)&y, GPUFI_DATATYPE_INTEGER);


                t=tex2D(ref, search_off_x, (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 78, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad1+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+0)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 79, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+1), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 80, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad1+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+1)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 81, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


                sad2+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+0)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 82, "sad2", (int*)&sad2, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+2), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 83, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad1+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+2)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 84, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


                sad2+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+1)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 85, "sad2", (int*)&sad2, GPUFI_DATATYPE_UNKNOWN);


                sad3+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+0)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 86, "sad3", (int*)&sad3, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+3), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 87, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad1+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+3)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 88, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


                sad2+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+2)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 89, "sad2", (int*)&sad2, GPUFI_DATATYPE_UNKNOWN);


                sad3+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+1)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 90, "sad3", (int*)&sad3, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+4), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 91, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad2+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+3)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 92, "sad2", (int*)&sad2, GPUFI_DATATYPE_UNKNOWN);


                sad3+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+2)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 93, "sad3", (int*)&sad3, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+5), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 94, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad3+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+3)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 95, "sad3", (int*)&sad3, GPUFI_DATATYPE_UNKNOWN);


                /* y = 3 */
                y=3;
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 96, "y", (int*)&y, GPUFI_DATATYPE_INTEGER);


                t=tex2D(ref, search_off_x, (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 97, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad1+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+0)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 98, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+1), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 99, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad1+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+1)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 100, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


                sad2+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+0)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 101, "sad2", (int*)&sad2, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+2), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 102, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad1+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+2)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 103, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


                sad2+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+1)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 104, "sad2", (int*)&sad2, GPUFI_DATATYPE_UNKNOWN);


                sad3+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+0)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 105, "sad3", (int*)&sad3, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+3), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 106, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad1+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+3)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 107, "sad1", (int*)&sad1, GPUFI_DATATYPE_UNKNOWN);


                sad2+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+2)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 108, "sad2", (int*)&sad2, GPUFI_DATATYPE_UNKNOWN);


                sad3+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+1)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 109, "sad3", (int*)&sad3, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+4), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 110, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad2+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+3)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 111, "sad2", (int*)&sad2, GPUFI_DATATYPE_UNKNOWN);


                sad3+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+2)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 112, "sad3", (int*)&sad3, GPUFI_DATATYPE_UNKNOWN);


                t=tex2D(ref, (search_off_x+5), (search_off_y+y));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 113, "t", (int*)&t, GPUFI_DATATYPE_INTEGER);


                sad3+=abs((t-frame_loc[(((cur_o<<4)+(y<<2))+3)]));
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 114, "sad3", (int*)&sad3, GPUFI_DATATYPE_UNKNOWN);


            }
            /* Save this value into the local SAD array */
            sad_loc[(((__umul24(ty, 1)+tx)*1096)+search_pos)]=sad1;
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 115, "sad_loc[(((__umul24(ty, 1)+tx)*1096)+search_pos)]", (int*)&sad_loc[(((__umul24(ty, 1)+tx)*1096)+search_pos)], GPUFI_DATATYPE_UNKNOWN);


            sad_loc[(((__umul24(ty, 1)+tx)*1096)+(search_pos+1))]=sad2;
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 116, "sad_loc[(((__umul24(ty, 1)+tx)*1096)+(search_pos+1))]", (int*)&sad_loc[(((__umul24(ty, 1)+tx)*1096)+(search_pos+1))], GPUFI_DATATYPE_UNKNOWN);


            sad_loc[(((__umul24(ty, 1)+tx)*1096)+(search_pos+2))]=sad3;
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 117, "sad_loc[(((__umul24(ty, 1)+tx)*1096)+(search_pos+2))]", (int*)&sad_loc[(((__umul24(ty, 1)+tx)*1096)+(search_pos+2))], GPUFI_DATATYPE_UNKNOWN);


            local_search_off_x+=3;
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 118, "local_search_off_x", (int*)&local_search_off_x, GPUFI_DATATYPE_INTEGER);


            if ((local_search_off_x>=((2*16)+1)))
            {
                local_search_off_x-=((2*16)+1);
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 119, "local_search_off_x", (int*)&local_search_off_x, GPUFI_DATATYPE_INTEGER);


                search_off_y ++ ;
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 120, "search_off_y", (int*)&search_off_y, GPUFI_DATATYPE_INTEGER);


            }
        }
        /* Automatically inserted by Cetus_Cuda */
        GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_END);
        /* Fault Injector Instrumentation End *//* End of Cetus_Cuda code */

        GPUFI_KERNEL_VARIABLE(gpufi_dev, 34, "search_pos", (int*)&search_pos, GPUFI_DATATYPE_INTEGER);


    }
    __syncthreads();
    /*
    Block-copy data into global memory.
       * Threads are grouped into sets of 32, leaving some threads idle.
    */
    if (((threadIdx.x>>5)<(1*1)))
    {
        int tgroup = (threadIdx.x&31);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 121, "tgroup", (int*)&tgroup, GPUFI_DATATYPE_INTEGER);


        int ty = ((threadIdx.x>>5)/1);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 122, "ty", (int*)&ty, GPUFI_DATATYPE_INTEGER);


        int tx = ((threadIdx.x>>5)-__umul24(ty, 1));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 123, "tx", (int*)&tx, GPUFI_DATATYPE_INTEGER);


        int index;
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 124, "index", (int*)&index, GPUFI_DATATYPE_INTEGER);


        /* Macroblock and sub-block coordinates */
        int mb_x = ((tx+__umul24(bx, 1))>>2);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 125, "mb_x", (int*)&mb_x, GPUFI_DATATYPE_INTEGER);


        int mb_y = ((ty+__umul24(by, 1))>>2);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 126, "mb_y", (int*)&mb_y, GPUFI_DATATYPE_INTEGER);


        int block_x = ((tx+__umul24(bx, 1))&3);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 127, "block_x", (int*)&block_x, GPUFI_DATATYPE_INTEGER);


        int block_y = ((ty+__umul24(by, 1))&3);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 128, "block_y", (int*)&block_y, GPUFI_DATATYPE_INTEGER);


        if (((mb_x<mb_width)&&(mb_y<mb_height)))
        {
            /*
            All SADs from this thread are stored in a contiguous chunk
            	 * of memory starting at this offset
            */
            blk_sad+=(((__umul24(__umul24(mb_width, mb_height), 25)+((__umul24(mb_y, mb_width)+mb_x)*16))+((4*block_y)+block_x))*1096);
            GPUFI_KERNEL_VARIABLE(gpufi_dev, 129, "blk_sad", (int*)&blk_sad, GPUFI_DATATYPE_UNKNOWN_POINTER);


            /* Block copy, 32 threads at a time */
            /* Fault Injector Instrumentation Begin */
            GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_BEGIN);
            /* Fault Injector Instrumentation End */

            for (index=tgroup; index<(1096/4); index+=32)
            {
                /* Fault Injector Instrumentation Begin */
                GPUFI_KERNEL_ITERATION(gpufi_dev);
                /* Fault Injector Instrumentation End */

                ((struct vec8b * )blk_sad)[index]=sad_loc_8b[(((__umul24(ty, 1)+tx)*(1096/4))+index)];
                GPUFI_KERNEL_VARIABLE(gpufi_dev, 132, "((struct vec8b * )blk_sad)[index]", (int*)&((struct vec8b * )blk_sad)[index], GPUFI_DATATYPE_UNKNOWN);


            }
            /* Automatically inserted by Cetus_Cuda */
            GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_END);
            /* Fault Injector Instrumentation End *//* End of Cetus_Cuda code */

            GPUFI_KERNEL_VARIABLE(gpufi_dev, 131, "index", (int*)&index, GPUFI_DATATYPE_INTEGER);


        }
    }
    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_END, 0, "mb_sad_calc");
}

texture<unsigned short, 2, cudaReadModeElementType> &
get_ref(void )
{
    return ref;
}
