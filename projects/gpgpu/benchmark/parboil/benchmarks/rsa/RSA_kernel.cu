#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define MODULI_SET_SIZE 33
#define NUMBER_OF_MESSAGES 6800
#define NUMBER_OF_THREADS 34
#define SIZE_OF_e 17


__constant__ unsigned int d_MiInverse[MODULI_SET_SIZE], d_Mij[MODULI_SET_SIZE+1][MODULI_SET_SIZE];
__constant__ unsigned int d_Mpjr[MODULI_SET_SIZE], d_MpjInverse[MODULI_SET_SIZE], d_Mpji[MODULI_SET_SIZE][MODULI_SET_SIZE], d_MpInvR, d_Mpi[MODULI_SET_SIZE];
__constant__ unsigned int d_Mj[MODULI_SET_SIZE+1];
__constant__ unsigned int d_MInv[MODULI_SET_SIZE+1];
__constant__ unsigned int d_MsqModN[MODULI_SET_SIZE*2+1];
__constant__ unsigned int d_e[SIZE_OF_e];
__constant__ unsigned int d_One[MODULI_SET_SIZE*2+1];


//__device__ unsigned int XPrime[NUMBER_OF_MESSAGES][2*MODULI_SET_SIZE+1], Y[NUMBER_OF_MESSAGES][2*MODULI_SET_SIZE+1];
//__device__ unsigned int TR[NUMBER_OF_MESSAGES][MODULI_SET_SIZE+1], TRR[NUMBER_OF_MESSAGES][MODULI_SET_SIZE+1];




__global__ void dExp(unsigned int (*A)[2*MODULI_SET_SIZE+1], unsigned int *N, unsigned int *modulus, unsigned int (*Result)[2*MODULI_SET_SIZE+1]);

__device__ unsigned int d_MMlast(unsigned int *A, unsigned int *B, unsigned int *N, unsigned int *modulus, unsigned int *Result);
__device__ unsigned int d_FirstStep(unsigned int *A, unsigned int *B, unsigned int *N, unsigned int *modulus, unsigned int *Q);
__device__ unsigned int d_ThirdStep(unsigned int *A, unsigned int *B, unsigned int *N, unsigned int *modulus, unsigned int *Qp, unsigned int *Rp);
__device__ unsigned int d_ExactExt( unsigned int *Rp, unsigned int *R, unsigned int *modulus);
__device__ unsigned int d_ExactExtLast( unsigned int *Q, unsigned int *Qp, unsigned int *modulus);
__device__ unsigned int d_ModularInverse(unsigned int N, unsigned int D);
__device__ unsigned int d_gcd(unsigned int A, unsigned int B, long long *X, long long *Y);




//////// Compute X^e mod N ////////////////////////////////////////
// source: Kawamura's paper page 532
// This function works for both MM and MMlast (commented out with //) inside the cide below. However, tha last Montgomery call must be MMlast.

__global__ void dExp(unsigned int (*A)[2*MODULI_SET_SIZE+1], unsigned int *N, unsigned int *modulus, unsigned int (*Result)[2*MODULI_SET_SIZE+1])
{
	__shared__ unsigned int XPrime[2*MODULI_SET_SIZE+1], Y[2*MODULI_SET_SIZE+1];
	//unsigned int e[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}; // e = 65537
	//unsigned int One[2*MODULI_SET_SIZE+1];
	int i, j;
/*
__shared__ unsigned int Q[MODULI_SET_SIZE]; // Variable for step 1 // Q = 6 as needed for the final Montgomery pass
__shared__ unsigned int Qp[MODULI_SET_SIZE+1]; // Varibale for step 2
__shared__ unsigned int Rp[MODULI_SET_SIZE+1]; // Varibale for step 3
__shared__ unsigned int R[MODULI_SET_SIZE]; // Varibale for step 4
*/
	//unsigned int TR[NUMBER_OF_MESSAGES][MODULI_SET_SIZE+1], TRR[NUMBER_OF_MESSAGES][MODULI_SET_SIZE+1];

	//int tx = threadIdx.x;
	int bx = blockIdx.x;

	//for (i = 0; i <= 2*MODULI_SET_SIZE; i++)
	//{
	//	One[i] = 1;
	//}


	//Step 1:
	//MM(A, MsqModN, N, modulus, Mpi, /*Mj, Mi,*/ MiInverse, Mij, /*Mpj,*/ Mpjr, MpjInverse, Mpji, &*MpInvR, MInv, XPrime);
	d_MMlast(A[bx], d_MsqModN, N, modulus, XPrime);
		/*
		d_FirstStep(A[bx], d_MsqModN, N, modulus, Q);
		d_ExactExtLast(Q, Qp, modulus);
		d_ThirdStep(A[bx], d_MsqModN, N, modulus, Qp, Rp);
		d_ExactExt(Rp, R, modulus);

		for (i = 0; i<= MODULI_SET_SIZE-1; i++)	XPrime[i] = R[i];
		for (i = 0; i<= MODULI_SET_SIZE; i++) XPrime[i+MODULI_SET_SIZE] = Rp[i];
		*/
	//Step 2:
	for (i = 0; i <= 2*MODULI_SET_SIZE; i++)
	{
		Y[i] = XPrime[i];
	}

	//Step 3:
	for (j = SIZE_OF_e - 2; j >= 0; j--)
	{
		d_MMlast(Y, Y, N, modulus, Result[bx]);
		/*
		d_FirstStep(Y, Y, N, modulus, Q);
		d_ExactExtLast(Q, Qp, modulus);
		d_ThirdStep(Y, Y, N, modulus, Qp, Rp);
		d_ExactExt(Rp, R, modulus);

		for (i = 0; i<= MODULI_SET_SIZE-1; i++)	Result[bx][i] = R[i];
		for (i = 0; i<= MODULI_SET_SIZE; i++) Result[bx][i+MODULI_SET_SIZE] = Rp[i];
		*/
		for (i = 0; i <= 2*MODULI_SET_SIZE; i++)
		{
			Y[i] = Result[bx][i];
		}


		//Step 5:
		if (d_e[j] == 1)
		{
			d_MMlast(Result[bx], XPrime, N, modulus, Y);
			/*
			d_FirstStep(Result[bx], XPrime, N, modulus, Q);
			d_ExactExtLast(Q, Qp, modulus);
			d_ThirdStep(Result[bx], XPrime, N, modulus, Qp, Rp);
			d_ExactExt(Rp, R, modulus);

			for (i = 0; i<= MODULI_SET_SIZE-1; i++)	Y[i] = R[i];
			for (i = 0; i<= MODULI_SET_SIZE; i++) Y[i+MODULI_SET_SIZE] = Rp[i];
			*/
		}
	}

	d_MMlast(Y, d_One, N, modulus, Result[bx]);
	/*
	d_FirstStep(Y, One, N, modulus, Q);
	d_ExactExtLast(Q, Qp, modulus);
	d_ThirdStep(Y, One, N, modulus, Qp, Rp);
	d_ExactExt(Rp, R, modulus);

	for (i = 0; i<= MODULI_SET_SIZE-1; i++)	Result[bx][i] = R[i];
	for (i = 0; i<= MODULI_SET_SIZE; i++) Result[bx][i+MODULI_SET_SIZE] = Rp[i];
	*/

}





//////////////////////////Final Montgomery multiplication///////////////////////

__device__ unsigned int d_MMlast(unsigned int *A, unsigned int *B, unsigned int *N, unsigned int *modulus, unsigned int *Result)
{	int i;
	/*
	__shared__ unsigned int Q[MODULI_SET_SIZE]; // Variable for step 1
	__shared__ unsigned int Qp[MODULI_SET_SIZE+1]; // Varibale for step 2
	__shared__ unsigned int Rp[MODULI_SET_SIZE+1]; // Varibale for step 3
	__shared__ unsigned int R[MODULI_SET_SIZE]; // Varibale for step 4
	*/
	__shared__ unsigned int T[MODULI_SET_SIZE+1];
	__shared__ unsigned int TT[MODULI_SET_SIZE+1];

	/////////////////Step 1: Q <- ( -A * B) * N^(-1) /////////////////////////

	d_FirstStep(A, B, N, modulus, T);


	//////////////////Step 2: First base conversion using CRT /////////////////////

	//ApproxExt( Q, Qp, modulus, &*M, Mi, MiInverse, Mij);
	d_ExactExtLast( T, TT, modulus);
	//MRS( Q, Qp, modulus, MI);

	/////////////////Step 3: Rp <- (A * B + Qp * N) * M^(-1) /////////////////////////

	d_ThirdStep(A, B, N, modulus, TT, T);


	//////////////////Step 4: Second base conversion using Shenoy and Kumaresan /////////////////////

	d_ExactExt( T, TT, modulus);



	// Copy results back
	/*
	for (i = 0; i<= MODULI_SET_SIZE-1; i++)
	{
		Result[i] = R[i];
	}

	for (i = 0; i<= MODULI_SET_SIZE; i++)
	{
		Result[i+MODULI_SET_SIZE] = Rp[i];
	}
	*/

	for (i = 0; i<= MODULI_SET_SIZE-1; i++)
		{
			Result[i] = TT[i];
		}

		for (i = 0; i<= MODULI_SET_SIZE; i++)
		{
			Result[i+MODULI_SET_SIZE] = T[i];
	}

return 0;
}




/////////////////Step 1: Q <- ( -A * B) * N^(-1) /////////////////////////

__device__ unsigned int d_FirstStep(unsigned int *A, unsigned int *B, unsigned int *N, unsigned int *modulus, unsigned int *Q)
{
	long long temp;
		//int i;
		int tx = threadIdx.x;

		/*for (i = 0; i <= MODULI_SET_SIZE-1; i++)
		{
			Q[i] = 0; // Initialize Q
		}*/

		//for (i = 0; i <= MODULI_SET_SIZE-1; i++)
		//{
			/*temp = -((long long)A[i] * (long long)B[i]) * (long long)ModularInverse( N[i], modulus[i]);
			Q[i] = (temp % (long long)modulus[i]) + (long long)modulus[i];*/ // Source :http://stackoverflow.com/questions/989943/weird-objective-c-mod-behavior
			if (tx <33)										 // Since temp is always negative here, use the first comment/answer in the source website.
			{
			temp = ((unsigned long long)A[tx] * (unsigned long long)B[tx]) % modulus[tx];
			temp = -((temp * (unsigned long long)d_ModularInverse( N[tx], modulus[tx])) % modulus[tx]);
			Q[tx] = (temp % modulus[tx]) + modulus[tx];
			}
		//}
		__syncthreads();

return 0;

}



/////////////////Step 3: Rp <- (A * B + Qp * N) * M^(-1) /////////////////////////

__device__ unsigned int d_ThirdStep(unsigned int *A, unsigned int *B, unsigned int *N, unsigned int *modulus, unsigned int *Qp, unsigned int *Rp)
{
	//int i;
	unsigned int temp, temp1, temp2;
	int tx = threadIdx.x;

	// Compute Rp
	//for (i = 0; i <= MODULI_SET_SIZE; i++)
	//{
		//Rp[i] = ((A[i+MODULI_SET_SIZE] * B[i+MODULI_SET_SIZE] + Qp[i] * N[i+MODULI_SET_SIZE]) * MInv[i]) % modulus[i+MODULI_SET_SIZE];
		temp = ((unsigned long long)A[tx+MODULI_SET_SIZE] * (unsigned long long)B[tx+MODULI_SET_SIZE]) % modulus[tx+MODULI_SET_SIZE];
		temp1 = ((unsigned long long)Qp[tx] * (unsigned long long)N[tx+MODULI_SET_SIZE]) % modulus[tx+MODULI_SET_SIZE];
		temp2 = ((unsigned long long)temp + (unsigned long long)temp1) % modulus[tx+MODULI_SET_SIZE];
		Rp[tx] = ((unsigned long long)temp2 * (unsigned long long)d_MInv[tx]) % modulus[tx+MODULI_SET_SIZE];

		__syncthreads();

	//}


	return 0;

}



//////////////////Approximate base conversion using CRT /////////////////////

__device__ unsigned int d_ApproxExt( unsigned int *Q, unsigned int *Qp, unsigned int *modulus)
{
	unsigned int sigma[MODULI_SET_SIZE], temp;
	int i, j;


	// Compute sigma
	for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	{
		sigma[i] = ((long long)Q[i]*(long long)d_MiInverse[i]) % modulus[i];
	}


	// Compute Q^

	for (i = 0; i <= MODULI_SET_SIZE; i++)
	{
		Qp[i] = 0; // Initialize Q^
	}

	for (j = 0; j <= MODULI_SET_SIZE; j++)
	{
		for (i = 0; i <= MODULI_SET_SIZE-1; i++)
		{
			//Qp[j] = ((long long)Qp[j] + (long long)Mij[j][i] * (long long)sigma[i]) % (long long)modulus[j+MODULI_SET_SIZE];
			  temp = ((long long)d_Mij[j][i] * (long long)sigma[i]) % (long long)modulus[j+MODULI_SET_SIZE];
			  Qp[j] = ((long long)temp + (long long)Qp[j]) % (long long)modulus[j+MODULI_SET_SIZE];
		}
	}



	return 0;
}




//////////////////Exact base conversion using Shenoy and Kumaresan /////////////////////

__device__ unsigned int d_ExactExt( unsigned int *Rp, unsigned int *R, unsigned int *modulus)
{
	__shared__ unsigned int Xi[MODULI_SET_SIZE];
	__shared__ unsigned int Beta;

	unsigned int temp, temp1, temp2;
	long long  temp3;
	int i, j;

	int tx = threadIdx.x;

	// Compute xi

	//for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	//{
		if(tx < 33)
	{
		Xi[tx] = ((unsigned long long)Rp[tx+1] * (unsigned long long)d_MpjInverse[tx]) % modulus[tx+MODULI_SET_SIZE+1];
	}

	__syncthreads();

	//}


	//Compute Beta
	//if(tx < 1)
	{
		temp = 0;

		for (i = 0; i <= MODULI_SET_SIZE-1; i++)
		{
			//temp = (temp + Mpjr[i] * Xi[i]) % modulus[MODULI_SET_SIZE];
			temp1 = ((unsigned long long)d_Mpjr[i] * (unsigned long long)Xi[i]) % modulus[MODULI_SET_SIZE];
			temp = ((unsigned long long)temp + (unsigned long long)temp1 ) % modulus[MODULI_SET_SIZE];

		}

		//temp = (modulus[MODULI_SET_SIZE] + (temp - Rp[0]) % modulus[MODULI_SET_SIZE]) % modulus[MODULI_SET_SIZE]; // Source :http://stackoverflow.com/questions/989943/weird-objective-c-mod-behavior
		temp3 = ((long long)temp - (long long)Rp[0]);
		//temp = temp % modulus[MODULI_SET_SIZE];
		temp3 = (modulus[MODULI_SET_SIZE] + temp3 % modulus[MODULI_SET_SIZE]) % modulus[MODULI_SET_SIZE];
		Beta = ((unsigned long long)temp3 * (unsigned long long)(d_MpInvR)) % modulus[MODULI_SET_SIZE];							// Since temp will sometimes be positive ans sometimes negative,
	}



	// Compute R
	//for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	//{
	if(tx < 33)
	{
		R[tx] = 0; // Initialize R

	//}

	//for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	//{
		for (j = 0; j <= MODULI_SET_SIZE-1; j++)
		{
			//R[i] = (R[i] + Mpji[i][j] * Xi[j]) % modulus[i];
			temp2 = ((unsigned long long)d_Mpji[tx][j] * (unsigned long long)Xi[j]) % modulus[tx];
			R[tx] = ((unsigned long long)R[tx] + (unsigned long long)temp2)% modulus[tx];
		}
		temp3 = R[tx] - ((long long)Beta * (long long)(d_Mpi[tx])) % modulus[tx];
		R[tx] = (modulus[tx] + (temp3 % modulus[tx])) % modulus[tx]; // Source :http://stackoverflow.com/questions/989943/weird-objective-c-mod-behavior
	}															// Since temp will sometimes be positive ans sometimes negative,
																// use the third comment/answer in the source website.


	__syncthreads();

	return 0;
}


//////////////////Exact base conversion using Kawamura, Harrison and Shenoy and Kumaresan /////////////////////

__device__ unsigned int d_ExactExtLast(unsigned int *Q, unsigned int *Qp, unsigned int *modulus)
{
	__shared__ unsigned int Xi[MODULI_SET_SIZE];
	__shared__ unsigned int Beta;
	unsigned int temp2;

	float temp;
	int i;
	long long temp1;

	int tx = threadIdx.x;


	// Compute xi

	//for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	//{
	if(tx < 33)
	{
		Xi[tx] = ((unsigned long long)Q[tx]*(unsigned long long)d_MiInverse[tx]) % modulus[tx];
	}

	__syncthreads();
	//}


	//Compute Beta.
	//This part is done according to Kawamura et al (2000) page 5 equation 5 and idea from Harrison et al (2009) page 12.
	// Here Beta is essentially k as in Kawamura et al and Harrison et al.
	// This part needs further consideration and observation to see if the accumulation of results of the division below
	// actually works for large numbers of not. If not, alternative ways of doiing it would be (1) follow Bajard's base extension without conversion,
	// (2) Kawamura's approximate truncation method, or (3) Mixed Radix System

	//if(tx < 1)
	{
		temp = 0;

		for (i = 0; i <= MODULI_SET_SIZE-1; i++)
		{
			temp = temp + (float)Xi[i] / (float)modulus[i];
		}
		Beta = temp;
	}





	// Compute Qp
	// After the computation below, the validity of Qp[0] is questionalble; it needs to be seen what happens to this value for large numbers.

		//for (i = 0; i <= MODULI_SET_SIZE; i++)
		//{
			Qp[tx] = 0; // Initialize R
		//}


	//for (j = 0; j <= MODULI_SET_SIZE; j++)
	//{
		for (i = 0; i <= MODULI_SET_SIZE-1; i++)
		{
			//Qp[j] = ((unsigned long long)Qp[j] + (unsigned long long)Mij[j][i] * (unsigned long long)Xi[i]) % (unsigned long long)modulus[j+MODULI_SET_SIZE];
				temp2 = ((unsigned long long)d_Mij[tx][i] * (unsigned long long)Xi[i]) % (unsigned long long)modulus[tx+MODULI_SET_SIZE];
				Qp[tx] = ((unsigned long long)Qp[tx]+(unsigned long long)temp2) % (unsigned long long)modulus[tx+MODULI_SET_SIZE];
		}
		temp1 = (long long)Qp[tx] - (Beta * (long long)(d_Mj[tx])) % (long long)modulus[tx+MODULI_SET_SIZE];
		/*temp1 = (long long)Beta * (long long)(Mj[j]);
		temp1 = temp1 % (long long)modulus[j+MODULI_SET_SIZE];
		temp1 = (long long)Qp[j] - temp1;*/
		Qp[tx] = (modulus[tx+MODULI_SET_SIZE] + (temp1 % modulus[tx+MODULI_SET_SIZE])) % modulus[tx+MODULI_SET_SIZE]; // Source :http://stackoverflow.com/questions/989943/weird-objective-c-mod-behavior
	//}															 // Since temp will sometimes be positive ans sometimes negative,
																 // use the third comment/answer in the source website.


__syncthreads();


	return 0;
}



/*//////////Compute modular inverse///////////////////////////////////////////////
Code from http://en.wikipedia.org/wiki/Modular_multiplicative_inverse
and http://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
*/

__device__ unsigned int d_ModularInverse(unsigned int N, unsigned int D)
{	long long temp_gcd, x, y;

	temp_gcd = d_gcd(N, D, &x, &y);

	if (temp_gcd == 1)
		return ((x+D)%D); // takes care of negative values of x
	else
		return 0;
}


/*//////////Compute gcd///////////////////////////////////////////////
Code from http://en.wikipedia.org/wiki/Modular_multiplicative_inverse
and http://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
*/

__device__ unsigned int d_gcd(unsigned int A, unsigned int B, long long *X, long long *Y)
{
    long long x, y, u, v, m, n, a, b, q, r;

    /* B = A(0) + B(1) */
    x = 0; y = 1;

    /* A = A(1) + B(0) */
    u = 1; v = 0;

    for (a = A, b = B; 0 != a; b = a, a = r, x = u, y = v, u = m, v = n) {
        /* b = aq + r and 0 <= r < a */
        q = b / a;
        r = b % a;

        /* r = Ax + By - aq = Ax + By - (Au + Bv)q = A(x - uq) + B(y - vq) */
        m = x - (u * q);
        n = y - (v * q);
    }

    /* Ax + By = gcd(A, B) */
    *X = x; *Y = y;

    return b;
}



