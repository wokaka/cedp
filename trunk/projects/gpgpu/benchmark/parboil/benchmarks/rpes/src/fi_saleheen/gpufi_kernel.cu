#include "gpufi.h"

////////////////////////////////////////////////////
// CPU PART
////////////////////////////////////////////////////


struct _gpufi_data_ gpufi_host = {0, };

__device__
struct _gpufi_data_ *gpufi_dev;


#if GPUFI


/*
 * @about   Fetch a fault injection command (including fault type and time)
 *          from a file, namely fi_cmd.txt
 */
int GPUFI_FETCH_COMMAND()
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

    fscanf(fp, "%s", &cmd);
    if(!strcmp(cmd, "profile")){
	   gpufi_host.fault.mode = GPUFI_PROFILE;
       printf("profile\n");
    }
    else if(!strcmp(cmd, "fi")){
	   gpufi_host.fault.mode = GPUFI_FI;
	    fscanf(fp, "%d %d %d %d %d 0x%x\n", &gpufi_host.fault.kernel, &gpufi_host.fault.instance,
		&gpufi_host.fault.loop, &gpufi_host.fault.iteration,
		&gpufi_host.fault.varid, &gpufi_host.fault.mask);
	    gpufi_host.fault.kernel_count = gpufi_host.fault.kernel;
	    gpufi_host.fault.mask_type = MASK_XOR;
	    gpufi_host.fault.injected = 0;

       printf("fi %d %d %d %d %d 0x%x\n", gpufi_host.fault.kernel, gpufi_host.fault.instance,
    	gpufi_host.fault.loop, gpufi_host.fault.iteration,
		gpufi_host.fault.varid, gpufi_host.fault.mask);

        gpufi_host.current.blid = 0;//1;
        gpufi_host.current.thid = 0;//1;
    }

    fclose(fp);

//    GPUFI_END("fi_org.txt");

    return 0;
}

int GPUFI_END(char *fname)
{
    FILE    *fp;
    int i, j, k, l, m;

    if(gpufi_host.fault.mode == GPUFI_PROFILE){
        //char    cmd[32];

        fp = fopen(fname, "wt");
        if(!fp)
            return -1;

        fprintf(fp, "kernel\t%d\n", gpufi_host.profile.kernels);
        for(i=0; i<gpufi_host.profile.kernels; i++){
            fprintf(fp, "\tkernel#\t%d\n", i);
            fprintf(fp, "\t\tinstance\t%d\n", gpufi_host.profile.instance[i]);

            for(j=0; j<gpufi_host.profile.instance[i]; j++){
                fprintf(fp, "\t\tinstance#\t%d\n", j);
                fprintf(fp, "\t\t\tloop\t%d\n", gpufi_host.profile.loop[i][j]);

                for(k=0; k<gpufi_host.profile.loop[i][j]; k++){
                    fprintf(fp, "\t\t\tloop#\t%d\n", k);
                    fprintf(fp, "\t\t\t\titeration\t%d\n", gpufi_host.profile.iteration[i][j][k]);

//                    for(l=0; l<gpufi_host.profile.iteration[i][j][k]; l++){
                        for(m=0; m<MAX_VARIABLE; m++){
                            fprintf(fp, "\t\t\t\t\tvariable(#%d)\t%d\n", m, gpufi_host.profile.variable[i][j][k][m]);
                        }
//                    }
                }
            }
        }

        fclose(fp);
    }
    else{
        printf("injected: %d\n", gpufi_host.fault.injected);
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
__device__
void GPUFI_KERNEL_KERNEL(struct _gpufi_data_ *gpufi_dev, int type)
{
    if(blockIdx.x != gpufi_dev->current.blid || threadIdx.x != gpufi_dev->current.thid)
        return;

    if(gpufi_dev->fault.mode == GPUFI_PROFILE){
        /* kernel */

        if(gpufi_dev->profile.kernel_bitmap[type] == 0){
            gpufi_dev->profile.kernels++;
            gpufi_dev->profile.kernel_bitmap[type] = 1;
        }

        /* instance */
        gpufi_dev->profile.instance[type]++;

        /* update current */
        gpufi_dev->current.kernel = type;
        gpufi_dev->current.instance = gpufi_dev->profile.instance[type] - 1;
    }
    else{
        if(gpufi_dev->current.kernel != type)
            gpufi_dev->current.instance = 0;
        gpufi_dev->current.instance++;

        gpufi_dev->current.kernel = type;
        gpufi_dev->current.loop = 0;

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
    }

}

__device__
void GPUFI_KERNEL_LOOP(struct _gpufi_data_ *gpufi_dev)
{
    if(blockIdx.x != gpufi_dev->current.blid || threadIdx.x != gpufi_dev->current.thid)
        return;

    if(gpufi_dev->fault.mode == GPUFI_PROFILE){
        gpufi_dev->profile.loop[gpufi_dev->current.kernel][gpufi_dev->current.instance]++;
        gpufi_dev->current.loop = gpufi_dev->profile.loop[gpufi_dev->current.kernel][gpufi_dev->current.instance] - 1;
    }
    else{
        gpufi_dev->current.loop++;
        gpufi_dev->current.iteration = 0;
/*
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
        gpufi_dev->profile.iteration[gpufi_dev->current.kernel][gpufi_dev->current.instance][gpufi_dev->current.loop]++;
        gpufi_dev->current.iteration = gpufi_dev->profile.iteration[gpufi_dev->current.kernel][gpufi_dev->current.instance][gpufi_dev->current.loop] - 1;
    }
    else{
        gpufi_dev->current.iteration++;

/*
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
        gpufi_dev->profile.variable[gpufi_dev->current.kernel][gpufi_dev->current.instance][gpufi_dev->current.loop][varid]++;
    }
    else{
//        if(gpufi_dev->fault.disable)
//            return;

//        if(!gpufi_dev->fault.injected){
            if(gpufi_dev->fault.kernel == gpufi_dev->current.kernel && 
               gpufi_dev->fault.instance == gpufi_dev->current.instance - 1 && 
               gpufi_dev->fault.loop == gpufi_dev->current.loop - 1 &&
               gpufi_dev->fault.iteration == gpufi_dev->current.iteration - 1 &&
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
                    *variable ^= gpufi_dev->fault.mask;
                    break;
                }
            }
//        }
    }
}

#else

int GPUFI_FETCH_COMMAND()
{
    return 0;
}

int GPUFI_END()
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
void GPUFI_KERNEL_KERNEL(struct _gpufi_data_ *gpufi_dev, int type)
{
}

__device__
void GPUFI_KERNEL_LOOP(struct _gpufi_data_ *gpufi_dev)
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

#endif

