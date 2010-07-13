#ifndef __GPUFI_KERNEL__
#define __GPUFI_KERNEL__

#include <stdio.h>

#define MAX2(x,y) ((x>y)?x:y)
#define MAX3(x,y,z) ((x>y)?MAX2(x,z):MAX2(y,z))

struct _gpufi_data_ gpufi_host = {0, };
__device__ struct _gpufi_data_ *gpufi_dev;



#if GPUFI_FUNC_INIT
////////////////////////////////////////////////////
// CPU PART
////////////////////////////////////////////////////

int variable_count;
int kernel_count;

/*
 * @about   Fetch a fault injection command (including fault type and time)
 *          from a file, namely fi_cmd.txt
 */
int GPUFI_INIT(int kernel_cnt, int variable_cnt)
{
    FILE    *fp;
    char    cmd[32];
	
    kernel_count = kernel_cnt + 1;
    variable_count = variable_cnt;

    memset(&gpufi_host, 0, sizeof(struct _gpufi_data_));

    fp = fopen("fi_cmd.txt", "rt");

    if(!fp){
        printf("file open error\n");
        system("pwd");
        return -1;
    }

    fscanf(fp, "%s", cmd);
    printf("%s ", cmd);
		if(!strcmp(cmd, "fi")){
        gpufi_host.fault.mode = GPUFI_FI;
        gpufi_host.current.profile_index = -1;

        fscanf(fp, "%d %d %d %d 0x%x\n",
                &gpufi_host.fault.kernel,
                &gpufi_host.fault.instance,
								&gpufi_host.fault.varid,
                &gpufi_host.fault.call,
                &gpufi_host.fault.mask);

        gpufi_host.fault.mask_type = MASK_XOR;
				gpufi_host.fault.injected = 0;

        gpufi_host.current.blid = 0;
        gpufi_host.current.thid = 0;

       	printf("fi_cmd %d %d %d %d 0x%x\n", gpufi_host.fault.kernel, gpufi_host.fault.instance,
    		gpufi_host.fault.varid, gpufi_host.fault.call, gpufi_host.fault.mask);
    }

    fclose(fp);

    return 0;
}
#else 
int GPUFI_INIT(int x, int y)
{
    return 0;
}
#endif

#if GPUFI_FUNC_HALT

int GPUFI_HALT(char *fname)
{
    int i;

    printf("* injected: %d\n", gpufi_host.fault.injected);
    
#if DEBUG_INJECT_LOC
    if(gpufi_host.fault.injected){
			printf("%d %d %d %d %d\n", gpufi_host.injected.kernel,
				gpufi_host.injected.instance,
				gpufi_host.injected.loop,
				gpufi_host.injected.iteration,
				gpufi_host.injected.varid);
		}
#endif

	  printf("fi %d %d %d %d 0x%x\n", gpufi_host.fault.kernel, gpufi_host.fault.instance,
			gpufi_host.fault.varid, gpufi_host.fault.call, gpufi_host.fault.mask);
	
	  if(!gpufi_host.fault.injected)
	    for(i=0; i<MAX_KERNEL; i++){
	        if(gpufi_host.profile.kernel[i].state == 1)
	            printf("kernel\t%d\tinstance\t%d\tcall\t%d\n",
	                    gpufi_host.profile.kernel[i].id,
	                    gpufi_host.profile.kernel[i].instance,
	                    gpufi_host.profile.variable[i][gpufi_host.fault.varid].call_count);
	        else
	            break;
	        printf("\n");
	    }

    /*
    if(gpufi_host.debug.injected){
			printf("debug - %d %d %d %d\n", gpufi_host.debug.kernel,
				gpufi_host.debug.instance,
				gpufi_host.debug.loop,
				gpufi_host.debug.iteration);
		}
    */

    return 0;
}

#else

int GPUFI_HALT(char *x)
{
    return 0;
}


#endif

////////////////////////////////////////////////////
// DEVICE PART
////////////////////////////////////////////////////

#if GPUFI_FUNC_LIB

__device__ 
int GPUFI_EXIT(struct _gpufi_data_ *gpufi_dev, int errno)
{
	gpufi_dev->sdc = 1;
	//int *addr = (int *)0x0;
	//*addr = (int)0x80;
	//return 100 / errno;
	return 0;
}

#else

__device__
int GPUFI_STRCMP(char *src, char *dst)
{
	return 1;
}

__device__
void CudaStrcpy(char *dst, char *src, int max)
{
}

__device__ int GPUFI_EXIT(int errno)
{
	return 0;
}

__device__
void GPUFI_KERNEL_DEC(int *count)
{
}

__device__
void GPUFI_KERNEL_SET(int *count, int value)
{
}

#endif

#if GPUFI_FUNC_KERNEL

__device__
void GPUFI_KERNEL(struct _gpufi_data_ *gpufi_dev, int begin, int type, char *name)
{
    if(blockIdx.x != gpufi_dev->current.blid || threadIdx.x != gpufi_dev->current.thid)
        return;

        if(begin == GPUFI_KERNEL_BEGIN){
            /* 1: update current */
            if(gpufi_dev->profile.kernel_bitmap[type] == 0) /* kernel */
                gpufi_dev->profile.kernel_bitmap[type] = 1;
            gpufi_dev->profile.kernel_instance[type]++; /* instance */

            /* update current */
            gpufi_dev->current.kernel = type;
            gpufi_dev->current.instance = gpufi_dev->profile.kernel_instance[type] - 1;
            gpufi_dev->current.loop = -1;

            /* 2: profiling */
            gpufi_dev->current.profile_index++;

            gpufi_dev->profile.kernel[gpufi_dev->current.profile_index].state  = 1;
            gpufi_dev->profile.kernel[gpufi_dev->current.profile_index].id  = gpufi_dev->current.kernel;
            gpufi_dev->profile.kernel[gpufi_dev->current.profile_index].instance  = gpufi_dev->current.instance;
        }
}

#else

// DEVICE PART

__device__
void GPUFI_KERNEL(struct _gpufi_data_ *gpufi_dev, int begin, int type, char *name)
{
}

#endif


#if GPUFI_FUNC_LOOP

__device__
void GPUFI_KERNEL_LOOP(struct _gpufi_data_ *gpufi_dev, int begin)
{
    if(blockIdx.x != gpufi_dev->current.blid || threadIdx.x != gpufi_dev->current.thid)
        return;

/*
        gpufi_dev->current.loop++;
        gpufi_dev->current.iteration = -1;
        gpufi_dev->current.kernel = type;


//        if(gpufi_dev->fault.disable)
//            return;
            
        GPUFI_KERNEL_DEC(&gpufi_dev->fault.loop);
        GPUFI_KERNEL_SET(&gpufi_dev->fault.iteration, gpufi_dev->fault.iteration_count);
*/
}

__device__
void GPUFI_KERNEL_ITERATION(struct _gpufi_data_ *gpufi_dev)
{
    if(blockIdx.x != gpufi_dev->current.blid || threadIdx.x != gpufi_dev->current.thid)
        return;

/*
        gpufi_dev->current.iteration++;
        if(gpufi_dev->fault.disable)
            return;

        GPUFI_KERNEL_DEC(&gpufi_dev->fault.iteration);
*/
}

#else

__device__
void GPUFI_KERNEL_LOOP(struct _gpufi_data_ *gpufi_dev, int begin)
{
}

__device__
void GPUFI_KERNEL_ITERATION(struct _gpufi_data_ *gpufi_dev)
{
}

#endif

#if GPUFI_FUNC_VARIABLE

__device__
void GPUFI_KERNEL_VARIABLE(struct _gpufi_data_ *gpufi_dev, int varid, char *name, int *variable, int var_type)
{
    if(blockIdx.x != gpufi_dev->current.blid || threadIdx.x != gpufi_dev->current.thid)
        return;

    if(gpufi_dev->fault.disabled)
        return;

    if(varid == gpufi_dev->fault.varid && gpufi_dev->profile.kernel[gpufi_dev->current.profile_index].id == gpufi_dev->fault.kernel && gpufi_dev->profile.kernel[gpufi_dev->current.profile_index].instance == gpufi_dev->fault.instance && gpufi_dev->profile.variable[gpufi_dev->current.profile_index][varid].call_count == gpufi_dev->fault.call){
				    int temp;
            gpufi_dev->fault.disabled = 1;
            gpufi_dev->fault.injected++;
            if(var_type == GPUFI_DATATYPE_INTEGER){
                *variable ^= gpufi_dev->fault.mask;
            }
            else if(var_type == GPUFI_DATATYPE_FLOAT_POINTER ||
              var_type == GPUFI_DATATYPE_INTEGER_POINTER ||
              var_type == GPUFI_DATATYPE_UNKNOWN_POINTER){
					    temp = (int)*variable;
					    temp ^= gpufi_dev->fault.mask;
					    *variable = (int) temp;
            }
            else if(var_type == GPUFI_DATATYPE_FLOAT){
              *variable = __int_as_float(__float_as_int(*variable) ^ gpufi_dev->fault.mask);
            }
            else{
	            gpufi_dev->fault.injected--;
            }

            /* injected fault */
//            switch(gpufi_dev->fault.mask_type){
//            case MASK_XOR:
//                break;
//            }
    }
/*
#if DEBUG_INJECT_LOC
        gpufi_dev->injected.kernel = gpufi_dev->current.kernel;
        gpufi_dev->injected.instance = gpufi_dev->current.instance;
        gpufi_dev->injected.loop = gpufi_dev->current.loop;
        gpufi_dev->injected.iteration = gpufi_dev->current.iteration;
        gpufi_dev->injected.varid = varid;
#endif
*/
//    gpufi_dev->profile.variable[gpufi_dev->current.profile_index][varid].call_count++;
}

__device__
void GPUFI_KERNEL_VARIABLE_FORCE(struct _gpufi_data_ *gpufi_dev, int varid, char *name, int *variable)
{
#if 0
    if(blockIdx.x != gpufi_dev->current.blid || threadIdx.x != gpufi_dev->current.thid)
        return;

    if(gpufi_dev->fault.mode == GPUFI_PROFILE){
    }
    else{
        if(gpufi_dev->fault.kernel == gpufi_dev->current.kernel && 
            gpufi_dev->fault.instance == gpufi_dev->current.instance && 
            gpufi_dev->fault.loop == gpufi_dev->current.loop &&
	          gpufi_dev->fault.varid == varid){

            gpufi_dev->fault.injected++;

            /* injected fault */
            switch(gpufi_dev->fault.mask_type){
            case MASK_XOR:
                *variable ^= gpufi_dev->fault.mask;
                break;
            }
        }
    }
#endif
}

__device__
void GPUFI_KERNEL_VARIABLE_STREAM(struct _gpufi_data_ *gpufi_dev, int varid, char *name, int *variable, int length, int count)
{
#if 0
    int i;

    if(blockIdx.x != gpufi_dev->current.blid || threadIdx.x != gpufi_dev->current.thid)
        return;

    if(gpufi_dev->fault.mode == GPUFI_PROFILE){
//        gpufi_dev->profile.variable[gpufi_dev->current.kernel][gpufi_dev->current.instance][gpufi_dev->current.loop][varid]++;
    }
    else{
//        if(gpufi_dev->fault.disable)
//            return;
		for(i=0; i<count; i++){
//        if(!gpufi_dev->fault.injected){
            if(gpufi_dev->fault.kernel == gpufi_dev->current.kernel &&
               gpufi_dev->fault.instance == gpufi_dev->current.instance &&
               gpufi_dev->fault.loop == gpufi_dev->current.loop &&
               gpufi_dev->fault.iteration == gpufi_dev->current.iteration &&
	           gpufi_dev->fault.varid == varid
            ){
/*            if(0 == gpufi_dev->current.kernel &&
               1 == gpufi_dev->current.instance &&
               1 == gpufi_dev->current.loop &&
               1 == gpufi_dev->current.iteration &&
	           0 == varid){*/
                gpufi_dev->fault.injected++;

                /* injected fault */
                switch(gpufi_dev->fault.mask_type){
                case MASK_XOR:
                    variable[length*i/count] ^= gpufi_dev->fault.mask;
                    break;
                }
            }
//        }
	}
    }
#endif
}

#else

__device__
void GPUFI_KERNEL_VARIABLE(struct _gpufi_data_ *gpufi_dev, int varid, char *name, int *variable, int var_type)
{
}

__device__
void GPUFI_KERNEL_VARIABLE_FORCE(struct _gpufi_data_ *gpufi_dev, int varid, char *name, int *variable)
{
}

#endif

#endif