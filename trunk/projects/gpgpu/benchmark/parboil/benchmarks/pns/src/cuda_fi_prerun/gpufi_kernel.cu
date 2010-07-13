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
		int i;
	
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
    if(!strcmp(cmd, "profile")){
        gpufi_host.current.blid = 0;
        gpufi_host.current.thid = 0;

        gpufi_host.fault.mode = GPUFI_PROFILE;
        gpufi_host.current.profile_index = -1;
        fscanf(fp, "%s", cmd);
	      printf("%s ", cmd);
        if(!strcmp(cmd, "none")){
	        gpufi_host.current.profile_mode = PROFILE_MODE_NONE;
	      }
        else if(!strcmp(cmd, "value")){
	        fscanf(fp, "%s", cmd);
  	      printf("%s ", cmd);
					if(!strcmp(cmd, "loop"))
		        gpufi_host.current.profile_mode = PROFILE_MODE_VALUE_LOOP;
	        else if(!strcmp(cmd, "kernel"))
		        gpufi_host.current.profile_mode = PROFILE_MODE_VALUE_KERNEL;
	        else if(!strcmp(cmd, "thread")){
		        gpufi_host.current.profile_mode = PROFILE_MODE_VALUE_THREAD;
		        fscanf(fp, "%d", &gpufi_host.current.blid);
	      		printf(" %d ", gpufi_host.current.blid);
	        }
	        else if(!strcmp(cmd, "block")){
		        gpufi_host.current.profile_mode = PROFILE_MODE_VALUE_BLOCK;
		      }
	      }
	      printf(" (%d)\n", gpufi_host.current.profile_mode);
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

char *gpufi_type_name[6] = {"unknown", "int", "fp", "int_pt", "fp_pt", "unknown_pt"};

int GPUFI_HALT(char *fname)
{
    FILE    *fp;
    int i, j, k, m;

    if(gpufi_host.fault.mode == GPUFI_PROFILE){
        //char    cmd[32];

        fp = fopen(fname, "wt");
        if(!fp){
        	  printf("can't write to an output file, %s\n", fname);
            return -1;
        }

        for(i=0; i<MAX_KERNEL; i++){
            if(gpufi_host.profile.kernel[i].state == 1)
                fprintf(fp, "kernel\t%d\t%s\t%d\n",
                        gpufi_host.profile.kernel[i].id,
                        gpufi_host.profile.kernel[i].name,
                        gpufi_host.profile.kernel[i].instance);
            else
                break;

            for(j=0; j<variable_count; j++){
                if(gpufi_host.profile.variable[i][j].call_count != 0){
                  fprintf(fp, "variable\t%d\t%s\t%d\t%d\t%s\t",
                          j,
             							gpufi_host.profile.variable_bitmap[j]?gpufi_host.profile.variable_name[j]:"",
                          gpufi_host.profile.variable[i][j].call_count,
                          gpufi_host.profile.variable[i][j].loop_id,
                          gpufi_type_name[gpufi_host.profile.variable[i][j].type]);

				        		fprintf(fp, "\n");
								}
            }
            fprintf(fp, "\n");
        }

        fclose(fp);
    }

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
__device__
void CudaStrcpy(char *dst, char *src, int max)
{
    int i;
	
    for(i=0; src[i]!=0 && i<max-1; i++)
        dst[i] = src[i];
    dst[i] = 0;
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

						if(gpufi_dev->current.profile_index < MAX_KERNEL){
	            gpufi_dev->profile.kernel[gpufi_dev->current.profile_index].state  = 1;
	            gpufi_dev->profile.kernel[gpufi_dev->current.profile_index].id  = gpufi_dev->current.kernel;
	            CudaStrcpy(gpufi_dev->profile.kernel[gpufi_dev->current.profile_index].name, name, MAX_NAME);
	            gpufi_dev->profile.kernel[gpufi_dev->current.profile_index].instance  = gpufi_dev->current.instance;
					  }
        }
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
    int i;
    if(blockIdx.x != gpufi_dev->current.blid || threadIdx.x != gpufi_dev->current.thid)
        return;

    if(gpufi_dev->fault.mode == GPUFI_PROFILE){
    		if(gpufi_dev->current.profile_index < MAX_KERNEL && varid < MAX_VARIABLE){
	        	atomicAdd(&gpufi_dev->profile.variable[gpufi_dev->current.profile_index][varid].call_count, 1);
	        	if(gpufi_dev->profile.variable_bitmap[varid] == 0){
	        		gpufi_dev->profile.variable_bitmap[varid] = 1;
	        		CudaStrcpy(gpufi_dev->profile.variable_name[varid], name, MAX_NAME);
	        	}
	        	gpufi_dev->profile.variable[gpufi_dev->current.profile_index][varid].loop_id = gpufi_dev->current.loop;
	        	gpufi_dev->profile.variable[gpufi_dev->current.profile_index][varid].type = var_type;
      	}
    }
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