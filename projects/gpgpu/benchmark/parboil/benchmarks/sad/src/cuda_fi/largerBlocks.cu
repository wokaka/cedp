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
#include "sad.h"

#include "largerBlocks.h"

/* typedef */
struct uhvec
{
    unsigned short x;
    unsigned short y;
};

/* __align__(4) */
typedef unsigned int uint;
__global__ void larger_sad_calc_8(unsigned short * blk_sad, int mb_width, int mb_height,  struct _gpufi_data_ *gpufi_dev)
{
    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_BEGIN, 0, "larger_sad_calc_8");
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 0, "blk_sad", (int*)&blk_sad, GPUFI_DATATYPE_UNKNOWN_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 1, "mb_width", (int*)&mb_width, GPUFI_DATATYPE_INTEGER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 2, "mb_height", (int*)&mb_height, GPUFI_DATATYPE_INTEGER);


    int tx = (threadIdx.y&1);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 6, "tx", (int*)&tx, GPUFI_DATATYPE_INTEGER);


    int ty = (threadIdx.y>>1);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 7, "ty", (int*)&ty, GPUFI_DATATYPE_INTEGER);


    /* Macroblock and sub-block coordinates */
    int mb_x = blockIdx.x;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 8, "mb_x", (int*)&mb_x, GPUFI_DATATYPE_INTEGER);


    int mb_y = blockIdx.y;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 9, "mb_y", (int*)&mb_y, GPUFI_DATATYPE_INTEGER);


    /* Number of macroblocks in a frame */
    int macroblocks = __mul24(mb_width, mb_height);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 10, "macroblocks", (int*)&macroblocks, GPUFI_DATATYPE_INTEGER);


    int macroblock_index = ((__mul24(mb_y, mb_width)+mb_x)*1096);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 11, "macroblock_index", (int*)&macroblock_index, GPUFI_DATATYPE_INTEGER);


    int search_pos;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 12, "search_pos", (int*)&search_pos, GPUFI_DATATYPE_INTEGER);


    unsigned short * bi;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 13, "bi", (int*)&bi, GPUFI_DATATYPE_UNKNOWN_POINTER);


    unsigned short * bo_6, * bo_5, * bo_4;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 14, "bo_6", (int*)&bo_6, GPUFI_DATATYPE_UNKNOWN_POINTER);


    bi=((blk_sad+((__mul24(macroblocks, 25)+((ty*8)+(tx*2)))*1096))+(macroblock_index*16));
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 15, "bi", (int*)&bi, GPUFI_DATATYPE_UNKNOWN_POINTER);


    /* Block type 6: 4x8
     */
    bo_6=((blk_sad+((((macroblocks<<4)+macroblocks)+((ty*4)+(tx*2)))*1096))+(macroblock_index*8));
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 16, "bo_6", (int*)&bo_6, GPUFI_DATATYPE_UNKNOWN_POINTER);


    /* always true, but improves register allocation
     */
    if ((ty<100))
    {
        /* Block type 5: 8x4
         */
        bo_5=((blk_sad+((((macroblocks<<3)+macroblocks)+((ty*4)+tx))*1096))+(macroblock_index*8));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 17, "bo_5", (int*)&bo_5, GPUFI_DATATYPE_UNKNOWN_POINTER);


        /* Block type 4: 8x8
         */
        bo_4=((blk_sad+((((macroblocks<<2)+macroblocks)+((ty*2)+tx))*1096))+(macroblock_index*4));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 18, "bo_4", (int*)&bo_4, GPUFI_DATATYPE_UNKNOWN_POINTER);


    }
    /* Fault Injector Instrumentation Begin */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_BEGIN);
    /* Fault Injector Instrumentation End */

    for (search_pos=threadIdx.x; search_pos<((1089+1)/2); search_pos+=32)
    {
        /*
        Each uint is actually two 2-byte integers packed together.
               * Only addition is used and there is no chance of integer overflow
               * so this can be done to reduce computation time.
        */
        /* Fault Injector Instrumentation Begin */
        GPUFI_KERNEL_ITERATION(gpufi_dev);
        /* Fault Injector Instrumentation End */

        uint i00 = ((uint * )bi)[search_pos];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 21, "i00", (int*)&i00, GPUFI_DATATYPE_UNKNOWN);


        uint i01 = ((uint * )bi)[(search_pos+(1096/2))];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 22, "i01", (int*)&i01, GPUFI_DATATYPE_UNKNOWN);


        uint i10 = ((uint * )bi)[(search_pos+((4*1096)/2))];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 23, "i10", (int*)&i10, GPUFI_DATATYPE_UNKNOWN);


        uint i11 = ((uint * )bi)[(search_pos+((5*1096)/2))];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 24, "i11", (int*)&i11, GPUFI_DATATYPE_UNKNOWN);


        ((uint * )bo_6)[search_pos]=(i00+i10);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 25, "((uint * )bo_6)[search_pos]", (int*)&((uint * )bo_6)[search_pos], GPUFI_DATATYPE_UNKNOWN);


        ((uint * )bo_6)[(search_pos+(1096/2))]=(i01+i11);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 26, "((uint * )bo_6)[(search_pos+(1096/2))]", (int*)&((uint * )bo_6)[(search_pos+(1096/2))], GPUFI_DATATYPE_UNKNOWN);


        ((uint * )bo_5)[search_pos]=(i00+i01);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 27, "((uint * )bo_5)[search_pos]", (int*)&((uint * )bo_5)[search_pos], GPUFI_DATATYPE_UNKNOWN);


        ((uint * )bo_5)[(search_pos+((2*1096)/2))]=(i10+i11);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 28, "((uint * )bo_5)[(search_pos+((2*1096)/2))]", (int*)&((uint * )bo_5)[(search_pos+((2*1096)/2))], GPUFI_DATATYPE_UNKNOWN);


        ((uint * )bo_4)[search_pos]=((i00+i01)+(i10+i11));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 29, "((uint * )bo_4)[search_pos]", (int*)&((uint * )bo_4)[search_pos], GPUFI_DATATYPE_UNKNOWN);


    }
    /* Automatically inserted by Cetus_Cuda */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_END);
    /* Fault Injector Instrumentation End *//* End of Cetus_Cuda code */

    GPUFI_KERNEL_VARIABLE(gpufi_dev, 20, "search_pos", (int*)&search_pos, GPUFI_DATATYPE_INTEGER);


    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_END, 0, "larger_sad_calc_8");
}

__global__ void larger_sad_calc_16(unsigned short * blk_sad, int mb_width, int mb_height,  struct _gpufi_data_ *gpufi_dev)
{
    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_BEGIN, 1, "larger_sad_calc_16");
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 3, "blk_sad", (int*)&blk_sad, GPUFI_DATATYPE_UNKNOWN_POINTER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 4, "mb_width", (int*)&mb_width, GPUFI_DATATYPE_INTEGER);


    GPUFI_KERNEL_VARIABLE(gpufi_dev, 5, "mb_height", (int*)&mb_height, GPUFI_DATATYPE_INTEGER);


    /* Macroblock coordinates */
    int mb_x = blockIdx.x;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 30, "mb_x", (int*)&mb_x, GPUFI_DATATYPE_INTEGER);


    int mb_y = blockIdx.y;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 31, "mb_y", (int*)&mb_y, GPUFI_DATATYPE_INTEGER);


    /* Number of macroblocks in a frame */
    int macroblocks = (__mul24(mb_width, mb_height)*1096);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 32, "macroblocks", (int*)&macroblocks, GPUFI_DATATYPE_INTEGER);


    int macroblock_index = ((__mul24(mb_y, mb_width)+mb_x)*1096);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 33, "macroblock_index", (int*)&macroblock_index, GPUFI_DATATYPE_INTEGER);


    int search_pos;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 34, "search_pos", (int*)&search_pos, GPUFI_DATATYPE_INTEGER);


    unsigned short * bi;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 35, "bi", (int*)&bi, GPUFI_DATATYPE_UNKNOWN_POINTER);


    unsigned short * bo_3, * bo_2, * bo_1;
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 36, "bo_3", (int*)&bo_3, GPUFI_DATATYPE_UNKNOWN_POINTER);


    /* bi = blk_sad + macroblocks * 5 + macroblock_index * 4;
     */
    bi=((blk_sad+((macroblocks+macroblock_index)<<2))+macroblocks);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 37, "bi", (int*)&bi, GPUFI_DATATYPE_UNKNOWN_POINTER);


    /* Block type 3: 8x16
     */
    /* bo_3 = blk_sad + macroblocks * 3 + macroblock_index * 2;
     */
    bo_3=((blk_sad+((macroblocks+macroblock_index)<<1))+macroblocks);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 38, "bo_3", (int*)&bo_3, GPUFI_DATATYPE_UNKNOWN_POINTER);


    /* Block type 5: 8x4
     */
    bo_2=((blk_sad+macroblocks)+(macroblock_index*2));
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 39, "bo_2", (int*)&bo_2, GPUFI_DATATYPE_UNKNOWN_POINTER);


    /* Block type 4: 8x8
     */
    bo_1=(blk_sad+macroblock_index);
    GPUFI_KERNEL_VARIABLE(gpufi_dev, 40, "bo_1", (int*)&bo_1, GPUFI_DATATYPE_UNKNOWN_POINTER);


    /* Fault Injector Instrumentation Begin */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_BEGIN);
    /* Fault Injector Instrumentation End */

    for (search_pos=threadIdx.x; search_pos<((1089+1)/2); search_pos+=32)
    {
        /*
        Each uint is actually two 2-byte integers packed together.
               * Only addition is used and there is no chance of integer overflow
               * so this can be done to reduce computation time.
        */
        /* Fault Injector Instrumentation Begin */
        GPUFI_KERNEL_ITERATION(gpufi_dev);
        /* Fault Injector Instrumentation End */

        uint i00 = ((uint * )bi)[search_pos];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 43, "i00", (int*)&i00, GPUFI_DATATYPE_UNKNOWN);


        uint i01 = ((uint * )bi)[(search_pos+(1096/2))];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 44, "i01", (int*)&i01, GPUFI_DATATYPE_UNKNOWN);


        uint i10 = ((uint * )bi)[(search_pos+((2*1096)/2))];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 45, "i10", (int*)&i10, GPUFI_DATATYPE_UNKNOWN);


        uint i11 = ((uint * )bi)[(search_pos+((3*1096)/2))];
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 46, "i11", (int*)&i11, GPUFI_DATATYPE_UNKNOWN);


        ((uint * )bo_3)[search_pos]=(i00+i10);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 47, "((uint * )bo_3)[search_pos]", (int*)&((uint * )bo_3)[search_pos], GPUFI_DATATYPE_UNKNOWN);


        ((uint * )bo_3)[(search_pos+(1096/2))]=(i01+i11);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 48, "((uint * )bo_3)[(search_pos+(1096/2))]", (int*)&((uint * )bo_3)[(search_pos+(1096/2))], GPUFI_DATATYPE_UNKNOWN);


        ((uint * )bo_2)[search_pos]=(i00+i01);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 49, "((uint * )bo_2)[search_pos]", (int*)&((uint * )bo_2)[search_pos], GPUFI_DATATYPE_UNKNOWN);


        ((uint * )bo_2)[(search_pos+(1096/2))]=(i10+i11);
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 50, "((uint * )bo_2)[(search_pos+(1096/2))]", (int*)&((uint * )bo_2)[(search_pos+(1096/2))], GPUFI_DATATYPE_UNKNOWN);


        ((uint * )bo_1)[search_pos]=((i00+i01)+(i10+i11));
        GPUFI_KERNEL_VARIABLE(gpufi_dev, 51, "((uint * )bo_1)[search_pos]", (int*)&((uint * )bo_1)[search_pos], GPUFI_DATATYPE_UNKNOWN);


    }
    /* Automatically inserted by Cetus_Cuda */
    GPUFI_KERNEL_LOOP(gpufi_dev, GPUFI_LOOP_END);
    /* Fault Injector Instrumentation End *//* End of Cetus_Cuda code */

    GPUFI_KERNEL_VARIABLE(gpufi_dev, 42, "search_pos", (int*)&search_pos, GPUFI_DATATYPE_INTEGER);


    GPUFI_KERNEL(gpufi_dev, GPUFI_KERNEL_END, 1, "larger_sad_calc_16");
}
