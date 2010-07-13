/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/
struct Shell
{
	char Type[2];
	int numPrimitives;
	float Alpha[20];
	float Coeff[20];
	int inList[20];
	int myAtom;
};

struct Atom
{
	char Type[1];
	int numShells;
	Shell AtomShell[10];
	float X;
	float Y;
	float Z;
};
// Thread block size
#define BLOCK_SIZE 16

// Matrix dimensions
// (chosen as multiples of the thread block size for simplicity)
#define WA (3 * BLOCK_SIZE) // Matrix A width
#define HA (5 * BLOCK_SIZE) // Matrix A height
#define WB (8 * BLOCK_SIZE) // Matrix B width
#define HB WA  // Matrix B height
#define WC WB  // Matrix C width 
#define HC HA  // Matrix C height

#define MAX_VARIABLE_NAME 256
#define GPUFI_PROFILE 1
#define GPUFI_FI 0
#define MAX_KERNEL	5
#define MAX_INSTANCE	10
#define MAX_LOOP	10
#define MAX_ITERATION	1000
#define MAX_VARIABLE	10

struct gpufi_fault {
    int kernel;         // invocation index
                        // if it is 0, it means 'ready to inject'
    int instance;
    int loop;
    int iteration;

    int kernel_type;
    int kernel_count;
    int instance_count;
    int loop_count;
    int iteration_count;
    char variable_name[MAX_VARIABLE_NAME];
        
    int mask_type;
#define MASK_XOR    0    
//    int mask_length;    // 4 Bytes
    unsigned int mask;  
    
    int injected;                        
    int disable;
    int mode;
};

struct gpufi_profile {
	int	kernels;
	int	instance[MAX_KERNEL];
	int	loop[MAX_KERNEL][MAX_INSTANCE];
	int	iteration[MAX_KERNEL][MAX_INSTANCE][MAX_LOOP];
	char	*variable[MAX_KERNEL][MAX_INSTANCE][MAX_LOOP][MAX_VARIABLE];
	int     output_size;
	void	*output[MAX_KERNEL][MAX_INSTANCE];
};

struct gpufi_current {
    int mode;    
    int kernel;
    int instance;
    int loop;
};

__device__
void GPUFI_KERNEL_DEC(int *count);
__device__
void GPUFI_KERNEL_SET(int *count, int value);
__device__
void GPUFI_KERNEL_KERNEL(int type, struct gpufi_fault *gpufi_fault, struct gpufi_profile *gpufi_profile, struct gpufi_current *gpufi_current);
__device__
void GPUFI_KERNEL_LOOP(struct gpufi_fault *gpufi_fault, struct gpufi_profile *gpufi_profile, struct gpufi_current *gpufi_current);
__device__
void GPUFI_KERNEL_ITERATION(struct gpufi_fault *gpufi_fault, struct gpufi_profile *gpufi_profile, struct gpufi_current *gpufi_current);
__device__
void GPUFI_KERNEL_VARIABLE(char *name, int *variable, struct gpufi_fault *gpufi_fault, struct gpufi_profile *gpufi_profile, struct gpufi_current *gpufi_current);


