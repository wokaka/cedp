#ifndef __GPUFI_KERNEL__
#define __GPUFI_KERNEL__

#include <stdio.h>
////////////////////////////////////////////////////
// CPU PART
////////////////////////////////////////////////////

struct _gpufi_data_ gpufi_host = {0, };
__device__ struct _gpufi_data_ *gpufi_dev;

#if GPUFI

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

    fscanf(fp, "%s", &cmd);
    if(!strcmp(cmd, "profile")){
        gpufi_host.fault.mode = GPUFI_PROFILE;
        gpufi_host.current.profile_index = -1;
        printf("profile\n");
    }
    else if(!strcmp(cmd, "fi")){
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

int GPUFI_HALT(char *fname)
{
    FILE    *fp;
    int i, j, k, m;

    if(gpufi_host.fault.mode == GPUFI_PROFILE){
        //char    cmd[32];

        fp = fopen(fname, "wt");
        if(!fp)
            return -1;

        for(i=0; i<MAX_KERNEL; i++){
            if(gpufi_host.profile.kernel[i].state == 1)
                fprintf(fp, "kernel\t%d\t%s\t%d\n",
                        gpufi_host.profile.kernel[i].id,
                        gpufi_host.profile.kernel[i].name,
                        gpufi_host.profile.kernel[i].instance);
            else
                break;

            for(j=0; j<variable_count; j++){
                if(gpufi_host.profile.variable[i][j].call_count != 0)
                    fprintf(fp, "variable\t%d\t%s\t%d\t%d\n",
                            j,
                            gpufi_host.profile.variable[i][j].name,
                            gpufi_host.profile.variable[i][j].call_count,
                            gpufi_host.profile.variable[i][j].loop_id);
            }
            fprintf(fp, "\n");
        }

        fclose(fp);
    }
    else{
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
    }

    return 0;
}

// DEVICE PART

__device__
void GPUFI_KERNEL_DEC(int *count)
{
    if(*count != 0)
        *count--;
    // else
    /* be ready to inject fault when GPUFI_KERNEL_INJECT is called */
}

__device__
void GPUFI_KERNEL_SET(int *count, int value)
{
    *count = value;
}

/*
 * @about   Event generated when a GPU kernel is executed
 */
#define GPUFI_KERNEL_BEGIN 0
#define GPUFI_KERNEL_END 1


__device__
void CudaStrcpy(char *dst, char *src)
{
    int i;

    for(i=0; src[i]!=0; i++)
        dst[i] = src[i];
    dst[i] = 0;
}

__device__
void GPUFI_KERNEL(struct _gpufi_data_ *gpufi_dev, int begin, int type, char *name)
{
    if(blockIdx.x != gpufi_dev->current.blid || threadIdx.x != gpufi_dev->current.thid)
        return;

    if(gpufi_dev->fault.mode == GPUFI_PROFILE){
        if(begin == GPUFI_KERNEL_BEGIN){
            /* 1: update current */
            
            if(gpufi_dev->profile.kernel_bitmap[type] == 0)
                gpufi_dev->profile.kernel_bitmap[type] = 1; /* kernel */
            gpufi_dev->profile.kernel_instance[type]++; /* instance */

            /* update current */
            gpufi_dev->current.kernel = type;
            gpufi_dev->current.instance = gpufi_dev->profile.kernel_instance[type] - 1;
            gpufi_dev->current.loop = -1;

            /* 2: profiling */
            gpufi_dev->current.profile_index++;

            gpufi_dev->profile.kernel[gpufi_dev->current.profile_index].state  = 1;
            gpufi_dev->profile.kernel[gpufi_dev->current.profile_index].id  = gpufi_dev->current.kernel;
            CudaStrcpy(gpufi_dev->profile.kernel[gpufi_dev->current.profile_index].name, name);
            gpufi_dev->profile.kernel[gpufi_dev->current.profile_index].instance  = gpufi_dev->current.instance;
        }
    }
    else{
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

#if 0
        if(gpufi_dev->current.kernel != type)
            gpufi_dev->current.instance = 0;
        else    
        	gpufi_dev->current.instance++;

        gpufi_dev->current.kernel = type;
        gpufi_dev->current.loop = -1;
        gpufi_dev->current.iteration = -1;
        gpufi_dev->current.iteration = -1;

/*
//        if(type == gpufi_dev->fault.kernel_type){
            if(gpufi_dev->fault.kernel != type){
                gpufi_dev->fault.kernel = gpufi_dev->fault.kernel_count;
                GPUFI_KERNEL_SET(&gpufi_dev->fault.instance, gpufi_dev->fault.instance_count);
            }
            else{
                GPUFI_KERNEL_DEC(&gpufi_dev->fault.instance);
            }
            GPUFI_KERNEL_SET(&gpufi_dev->fault.loop, gpufi_dev->fault.loop_count);
            GPUFI_KERNEL_SET(&gpufi_dev->fault.iteration, gpufi_dev->fault.iteration_count);
            
            gpufi_dev->fault.disable = 0;
//        }
//        else{
//            gpufi_dev->fault.disable = 1;
//        }
*/
#endif
        }
    }
}

#define GPUFI_LOOP_BEGIN 0
#define GPUFI_LOOP_END 1

__device__
void GPUFI_KERNEL_LOOP(struct _gpufi_data_ *gpufi_dev, int begin)
{
    if(blockIdx.x != gpufi_dev->current.blid || threadIdx.x != gpufi_dev->current.thid)
        return;

    if(gpufi_dev->fault.mode == GPUFI_PROFILE){
        if(begin == GPUFI_LOOP_BEGIN){
            //gpufi_dev->profile.loop[gpufi_dev->current.kernel][gpufi_dev->current.instance]++;
            gpufi_dev->current.loop = gpufi_dev->current.loop_count;// = gpufi_dev->profile.loop[gpufi_dev->current.kernel][gpufi_dev->current.instance] - 1;
            gpufi_dev->current.iteration = -1;
            gpufi_dev->current.loop_count++;
        }
        else{
            //gpufi_dev->profile.loop[gpufi_dev->current.kernel][gpufi_dev->current.instance]++;
            gpufi_dev->current.loop = -1;
        }
    }
    else{
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
}

__device__
void GPUFI_KERNEL_ITERATION(struct _gpufi_data_ *gpufi_dev)
{
    if(blockIdx.x != gpufi_dev->current.blid || threadIdx.x != gpufi_dev->current.thid)
        return;

    if(gpufi_dev->fault.mode == GPUFI_PROFILE){
//        gpufi_dev->profile.iteration[gpufi_dev->current.kernel][gpufi_dev->current.instance][gpufi_dev->current.loop]++;
        gpufi_dev->current.iteration++;
    }
    else{
/*
        gpufi_dev->current.iteration++;
        if(gpufi_dev->fault.disable)
            return;

        GPUFI_KERNEL_DEC(&gpufi_dev->fault.iteration);
*/
    }
}

__device__
int GPUFI_STRCMP(char *src, char *dst)
{
	int	i;

	for(i=0; src[i] && dst[i]; i++){
		if(src[i] != dst[i])
			return 1;
	}
	
	if(src[i] == dst[i])
		return 0;

	return 1;
}

__device__
void GPUFI_KERNEL_VARIABLE(struct _gpufi_data_ *gpufi_dev, int varid, char *name, int *variable)
{
    if(blockIdx.x != gpufi_dev->current.blid || threadIdx.x != gpufi_dev->current.thid)
        return;

    if(gpufi_dev->fault.mode == GPUFI_PROFILE){
        gpufi_dev->profile.variable[gpufi_dev->current.profile_index][varid].call_count++;
        CudaStrcpy(gpufi_dev->profile.variable[gpufi_dev->current.profile_index][varid].name, name);
        gpufi_dev->profile.variable[gpufi_dev->current.profile_index][varid].loop_id = gpufi_dev->current.loop;
    }
    else{
        if(gpufi_dev->fault.disabled)
            return;

        if(varid == gpufi_dev->fault.varid){
            if(gpufi_dev->profile.kernel[gpufi_dev->current.profile_index].id == gpufi_dev->fault.kernel &&
               gpufi_dev->profile.kernel[gpufi_dev->current.profile_index].instance == gpufi_dev->fault.instance){
                if(gpufi_dev->profile.variable[gpufi_dev->current.profile_index][varid].call_count == gpufi_dev->fault.call){
                    gpufi_dev->fault.injected++;
                    gpufi_dev->fault.disabled = 1;
                    /* injected fault */
                    switch(gpufi_dev->fault.mask_type){
                    case MASK_XOR:
                        *variable ^= gpufi_dev->fault.mask;
                        break;
                    }
                }
            }
        }

#if DEBUG_INJECT_LOC
        gpufi_dev->injected.kernel = gpufi_dev->current.kernel;
        gpufi_dev->injected.instance = gpufi_dev->current.instance;
        gpufi_dev->injected.loop = gpufi_dev->current.loop;
        gpufi_dev->injected.iteration = gpufi_dev->current.iteration;
        gpufi_dev->injected.varid = varid;
#endif

        gpufi_dev->profile.variable[gpufi_dev->current.profile_index][varid].call_count++;
    }
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

__device__
void GPUFI_DEBUG_LOC(struct _gpufi_data_ *gpufi_dev)
{
#if 0
    if(blockIdx.x != gpufi_dev->current.blid || threadIdx.x != gpufi_dev->current.thid)
        return;

	if(!gpufi_dev->debug.injected){
								gpufi_dev->debug.injected = 1;
								gpufi_dev->debug.kernel = gpufi_dev->current.kernel;
								gpufi_dev->debug.instance = gpufi_dev->current.instance;
								gpufi_dev->debug.loop = gpufi_dev->current.loop;
								gpufi_dev->debug.iteration = gpufi_dev->current.iteration;
	}
#endif
}

__device__ 
int GPUFI_EXIT(int errno)
{
	int *addr = 0x0;
	
	*addr = 0x80;
	return 100 / errno;
}

#else

int GPUFI_INIT()
{
    return 0;
}

int GPUFI_HALT(char *)
{
    return 0;
}

// DEVICE PART

__device__
void GPUFI_KERNEL_DEC(int *count)
{
}

__device__
void GPUFI_KERNEL_SET(int *count, int value)
{
}

__device__
void GPUFI_KERNEL(struct _gpufi_data_ *gpufi_dev, int begin, int type)
{
}

__device__
void GPUFI_KERNEL_LOOP(struct _gpufi_data_ *gpufi_dev, int begin)
{
}

__device__
void GPUFI_KERNEL_ITERATION(struct _gpufi_data_ *gpufi_dev)
{
}

__device__
int GPUFI_STRCMP(char *src, char *dst)
{
	return 1;
}

__device__
void GPUFI_KERNEL_VARIABLE(struct _gpufi_data_ *gpufi_dev, char *name, int *variable)
{
}

__device__
void GPUFI_KERNEL_VARIABLE_FORCE(struct _gpufi_data_ *gpufi_dev, int varid, char *name, int *variable)
{
}

__device__
void CudaStrcpy(char *dst, char *src)
{
}

__device__ int GPUFI_EXIT(int errno)
{
return 0;
}


#endif

#endif