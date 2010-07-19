#ifndef __GPUFI_KERNEL__
#define __GPUFI_KERNEL__

#include <stdio.h>

#define MAX2(x,y) ((x>y)?x:y)
#define MAX3(x,y,z) ((x>y)?MAX2(x,z):MAX2(y,z))

struct _gpufi_data_ gpufi_host = {0, };
__device__ struct _gpufi_data_ *gpufi_dev;

////////////////////////////////////////////////////
// CPU PART
////////////////////////////////////////////////////

/*
 * @about   Fetch a fault injection command (including fault type and time)
 *          from a file, namely fi_cmd.txt
 */
int GPUFI_INIT(int kernel_cnt, int variable_cnt)
{
    FILE    *fp;
    char    cmd[32];
	
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
        fscanf(fp, "%d %d %d %d 0x%x %d %d\n",
                &gpufi_host.fault.kernel,
                &gpufi_host.fault.instance,
								&gpufi_host.fault.varid,
                &gpufi_host.fault.call,
                &gpufi_host.fault.mask, 
		      		  &gpufi_host.fault.blid,
    			    	&gpufi_host.fault.thid);

				gpufi_host.fault.injected = 0;
 				gpufi_host.fault.disabled = 1;

       	printf("fi_cmd %d %d %d %d 0x%x\n", gpufi_host.fault.kernel, gpufi_host.fault.instance,
    		gpufi_host.fault.varid, gpufi_host.fault.call, gpufi_host.fault.mask);
    }

    fclose(fp);

    return 0;
}

int GPUFI_HALT(char *fname)
{
    printf("* injected: %d\n", gpufi_host.fault.injected);
    fprintf(stderr, "* injected: %d\n", gpufi_host.fault.injected);
    
	  printf("fi %d %d %d %d 0x%x\n", gpufi_host.fault.kernel, gpufi_host.fault.instance,
			gpufi_host.fault.varid, gpufi_host.fault.call, gpufi_host.fault.mask);
	
    return 0;
}

////////////////////////////////////////////////////
// DEVICE PART
////////////////////////////////////////////////////

__device__ 
int GPUFI_EXIT(struct _gpufi_data_ *gpufi_dev, int errno)
{
	gpufi_dev->sdc = 1;
	//int *addr = (int *)0x0;
	//*addr = (int)0x80;
	//return 100 / errno;
	return 0;
}

__device__
void GPUFI_KERNEL(struct _gpufi_data_ *gpufi_dev, int begin, int type, char *name)
{
    if(blockIdx.x != gpufi_dev->fault.blid || threadIdx.x != gpufi_dev->fault.thid)
        return;

		gpufi_dev->fault.disabled = 1;
    if(begin == GPUFI_KERNEL_BEGIN){
    		if(gpufi_dev->fault.kernel == type){
            if(gpufi_dev->fault.instance == gpufi_dev->current.instance++){
    					gpufi_dev->fault.disabled = 0;
    				}
    		}
    }
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
void GPUFI_KERNEL_VARIABLE(struct _gpufi_data_ *gpufi_dev, int varid, char *name, int *variable, int var_type)
{
    if(blockIdx.x != gpufi_dev->fault.blid || threadIdx.x != gpufi_dev->fault.thid)
        return;

    if(gpufi_dev->fault.disabled)
        return;

    if(varid == gpufi_dev->fault.varid){
    	if(gpufi_dev->fault.call == gpufi_dev->current.count++){
            gpufi_dev->fault.disabled = 1;
            gpufi_dev->fault.injected++;

            if(var_type == GPUFI_DATATYPE_INTEGER){
                *variable ^= gpufi_dev->fault.mask;
            }
            else if(var_type == GPUFI_DATATYPE_FLOAT_POINTER ||
              var_type == GPUFI_DATATYPE_INTEGER_POINTER ||
              var_type == GPUFI_DATATYPE_UNKNOWN_POINTER){
					    int temp;
					    temp = (int)*variable;
					    temp ^= gpufi_dev->fault.mask;
					    *variable = (int) temp;
            }
            else if(var_type == GPUFI_DATATYPE_FLOAT){
              *variable = __int_as_float(__float_as_int(*variable) ^ gpufi_dev->fault.mask);
            }
            else{
					    int temp;
					    temp = (int)*variable;
					    temp ^= gpufi_dev->fault.mask;
					    *variable = (int) temp;
            }
		  }
    }
}

#endif