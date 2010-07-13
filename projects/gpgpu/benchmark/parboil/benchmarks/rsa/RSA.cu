
#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "time.h"
#include <cutil.h>
#include <sys/time.h>
#include <malloc.h>
#include <RSA_kernel.cu>



using namespace std;

unsigned int MM(unsigned int *A, unsigned int *B, unsigned int *N, unsigned int *modulus, unsigned int *Mpi, /*unsigned int *Mj, unsigned int *Mi,*/ unsigned int *MiInverse, unsigned int (*Mij)[MODULI_SET_SIZE], /*unsigned int *Mpj,*/ unsigned int *Mpjr, unsigned int *MpjInverse, unsigned int (*Mpji)[MODULI_SET_SIZE], unsigned int *MpInvR, unsigned int *MInv, unsigned int *Result);
//unsigned int MMlast(unsigned int *A, unsigned int *B, unsigned int *N, unsigned int *modulus, unsigned int *Mpi, unsigned int *Mj, unsigned int *Mi, unsigned int *Mir, unsigned int *MiInverse, unsigned int (*Mij)[MODULI_SET_SIZE], unsigned int *MInvR, unsigned int *Mpj, unsigned int *Mpjr, unsigned int *MpjInverse, unsigned int (*Mpji)[MODULI_SET_SIZE], unsigned int *MpInvR, unsigned int *MInv, unsigned int *Result);
unsigned int MMlast(unsigned int *A, unsigned int *B, unsigned int *N, unsigned int *modulus, unsigned int *Mpi, unsigned int *Mj, /*unsigned int *Mi, unsigned int *Mir,*/ unsigned int *MiInverse, unsigned int (*Mij)[MODULI_SET_SIZE], /*unsigned int *MInvR, unsigned int *Mpj,*/ unsigned int *Mpjr, unsigned int *MpjInverse, unsigned int (*Mpji)[MODULI_SET_SIZE], unsigned int *MpInvR, unsigned int *MInv, /*unsigned int (*MI)[MODULI_SET_SIZE],*/ unsigned int *Result);
unsigned int FirstStep(unsigned int *A, unsigned int *B, unsigned int *N, unsigned int *modulus, unsigned int *Q);
unsigned int ThirdStep(unsigned int *A, unsigned int *B, unsigned int *N, unsigned int *modulus, unsigned int *Qp, unsigned int *Rp, unsigned int *MInv);
unsigned int ApproxExt( unsigned int *Q, unsigned int *Qp, unsigned int *modulus, /*unsigned int *Mi,*/ unsigned int *MiInverse, unsigned int (*Mij)[MODULI_SET_SIZE]);
unsigned int ExactExt( unsigned int *Rp, unsigned int *R, unsigned int *modulus, unsigned int *Mpi, /*unsigned int *Mpj,*/ unsigned int *Mpjr, unsigned int *MpjInverse, unsigned int (*Mpji)[MODULI_SET_SIZE], unsigned int *MpInvR);
unsigned int ExactExtLast( unsigned int *Q, unsigned int *Qp, unsigned int *modulus, unsigned int *Mj, /*unsigned int *Mi, unsigned int *Mir,*/ unsigned int *MiInverse, unsigned int (*Mij)[MODULI_SET_SIZE]/*, unsigned int *MInvR*/);
unsigned int MRS( unsigned int *Q, unsigned int *Qp, unsigned int *modulus, unsigned int (*MI)[MODULI_SET_SIZE]);
unsigned int ModularInverse(unsigned int N, unsigned int D);
//unsigned int Exp(unsigned int *A, unsigned int *B, unsigned int *N, unsigned int *MsqModN, unsigned int *modulus, unsigned int *Mpi, unsigned int *Mj, unsigned int *Mi, unsigned int *Mir, unsigned int *MiInverse, unsigned int (*Mij)[MODULI_SET_SIZE], unsigned int *MInvR, unsigned int *Mpj, unsigned int *Mpjr, unsigned int *MpjInverse, unsigned int (*Mpji)[MODULI_SET_SIZE], unsigned int *MpInvR, unsigned int *MInv, unsigned int *Result);
unsigned int Exp(unsigned int *A, /*unsigned int *B,*/ unsigned int *N, unsigned int *MsqModN, unsigned int *modulus, unsigned int *Mpi, unsigned int *Mj, /*unsigned int *Mi, unsigned int *Mir,*/ unsigned int *MiInverse, unsigned int (*Mij)[MODULI_SET_SIZE], /*unsigned int *MInvR, unsigned int *Mpj,*/ unsigned int *Mpjr, unsigned int *MpjInverse, unsigned int (*Mpji)[MODULI_SET_SIZE], unsigned int *MpInvR, unsigned int *MInv, /*unsigned int (*MI)[MODULI_SET_SIZE],*/ unsigned int *Result);
unsigned int gcd(unsigned int A, unsigned int B, long long *X, long long *Y);


int main()
{
	//unsigned int in_modulus[] = {3, 7, 13, 19, 29, 8, 5, 11, 17, 23, 31}; // Modulii used for conversion to RNS
	//unsigned int M = 150423, MP = 666655; // Constants specific to the above modulus set
	unsigned int in_A[NUMBER_OF_MESSAGES][MODULI_SET_SIZE * 2 + 1], in_B[MODULI_SET_SIZE * 2 + 1], in_N[MODULI_SET_SIZE * 2 + 1];
	unsigned int /*Mi[MODULI_SET_SIZE],*/ MiInverse[MODULI_SET_SIZE], Mij[MODULI_SET_SIZE+1][MODULI_SET_SIZE]; //Variables for precomutation of approximate base conversion
	unsigned int /*Mpj[MODULI_SET_SIZE],*/ Mpjr[MODULI_SET_SIZE], MpjInverse[MODULI_SET_SIZE], Mpji[MODULI_SET_SIZE][MODULI_SET_SIZE], MpInvR, Mpi[MODULI_SET_SIZE]; //Variables for precomutation of exact base conversion
	unsigned int /*Mir[MODULI_SET_SIZE], MInvR,*/ Mj[MODULI_SET_SIZE+1]; // Variables to perform exact base conversion for the first base conversion in the final Montgomery pass
	unsigned int MInv[MODULI_SET_SIZE+1]; //Variables for precomutation of third step
	//unsigned int MsquareN = 12580; // Precomputed result needed for input to final pass of the Montgomery multiplication
	unsigned int MsqModN[MODULI_SET_SIZE*2+1]; // Variable for input to the final pass of the Montgomery multiplication
	//unsigned int MI[MODULI_SET_SIZE][MODULI_SET_SIZE]; // Variable for MRS base conversion

	//unsigned int Result[MODULI_SET_SIZE*2+1]; // Results (on both bases) from a Montgomery pass
	unsigned int Final_Result[NUMBER_OF_MESSAGES][MODULI_SET_SIZE*2+1]; // Results (on both bases) from the final Montgomery pass
	unsigned int Device_Final_Result[NUMBER_OF_MESSAGES][MODULI_SET_SIZE*2+1]; // Results (on both bases) from the final Montgomery pass

	int i, j;
	//Timer
	float cpu_time = 0;
	float gpu_time = 0;
	unsigned int timer;
	CUT_SAFE_CALL(cutCreateTimer(&timer));



	printf("Starting .....");


	/////////Read RNS look-up table from file////////////////////

	unsigned int input[MODULI_SET_SIZE * 2 + 1][256];
			FILE *fp=fopen("RNS.txt", "r");
			if (fp)
			{
				while(feof(fp)== 0)
				{
					for (i=0; i <= (MODULI_SET_SIZE*2); i++ )
					{
						for(j=0; j<=255; j++)
						{
							fscanf(fp,"%u",&input[i][j]);
						}
					}
				}
			printf("\nLook-up table read complete.");
			fclose(fp);
			}
			else
		printf("\nFile Read Error!\n");


	/////////Read modulus set from file////////////////////

	unsigned int input1[MODULI_SET_SIZE * 2 + 1];
		FILE *fp1=fopen("ModFile.txt", "r");
		if (fp1)
		{
			while(feof(fp1)== 0)
			{
				for (i=0; i <= (MODULI_SET_SIZE*2); i++)
				{
					fscanf(fp1,"%u",&input1[i]);
				}
			}
		printf("\nModulus file read complete.");
		fclose(fp1);
		}
		else
			printf("\nFile Read Error!\n");



	/////////////Read 1024-bit input numbers from file/////////////////////////////

	// Read A from file
		FILE *aFile;
		char str[4];
		unsigned int sub_hex;
			unsigned int buffer_A[NUMBER_OF_MESSAGES][256], a_counter[NUMBER_OF_MESSAGES];
		i = 0;
		j = 0;
		aFile = fopen ("AFile.txt","r");
		if (aFile)
		{
			while((feof(aFile)== 0)&&(j<=NUMBER_OF_MESSAGES-1))
			{
				while((str[0] = getc(aFile)) != '\n')
				{
					sscanf(str,"%x", &sub_hex);
					buffer_A[j][i] = sub_hex;
					i++;
				}

				a_counter[j] = i-1;
				i=0;
				j++;
			}
		printf("\nA read complete.");
		fclose(aFile);
		}
		else
		printf("\nFile Read Error!\n");


	// Read B from file
	FILE *bFile;
	unsigned int buffer_B[256], b_counter;
	i = 0;
	bFile = fopen ("BFile.txt","r");
	if (bFile)
	{
		while ((str[0] = getc(bFile)) != EOF)
		{
			sscanf(str,"%x", &sub_hex);
			buffer_B[i] = sub_hex;
			i++;
			}

	}
	else
		printf("\nFile Read Error!\n");

	b_counter = i-1;
	printf("\nB read complete.");
	fclose(bFile);

	// Read N from file
	FILE *nFile;
	unsigned int buffer_N[256], n_counter;
	i = 0;
	nFile = fopen ("NFile.txt","r");
	if (nFile)
	{
		while ((str[0] = getc(nFile)) != EOF)
		{
			sscanf(str,"%x", &sub_hex);
			buffer_N[i] = sub_hex;
			i++;
			}

	}
	else
		printf("\nFile Read Error!\n");

	n_counter = i-1;
	printf("\nN read complete.");
	fclose(nFile);



	///////////Convert inputs to RNS////////////////////////

	// Initialize inputs

for (i = 0; i <= MODULI_SET_SIZE*2; i++)
	{
		//in_A[i] = 0;
		in_B[i] = 0;
		in_N[i] = 0;
	}

	for (i = 0; i < NUMBER_OF_MESSAGES; i++)
	{
		for (j = 0; j <= MODULI_SET_SIZE*2; j++)
		{
			in_A[i][j] = 0;
		}
	}


	// Conversion of A

	long long temp1, temp2, temp3;

		for (int p = 0; p < NUMBER_OF_MESSAGES; p++)
		{
			for (i = 0, j = a_counter[p]; j>=0; i++, j--)
			{
				for (unsigned int k = 0; k <= MODULI_SET_SIZE*2; k++)
				{
					temp1 = (long long) buffer_A[p][j] * (long long)input[k][i];
					temp2 = (long long) in_A[p][k] + temp1;
					temp3 = temp2 % input1[k];
					in_A[p][k] = temp3;
				}
			}
	}


	// Conversion of B

	for (i = 0, j = b_counter; j>=0; i++, j--)
	{
		for (unsigned int k = 0; k <= MODULI_SET_SIZE*2; k++)
		{
			temp1 = (long long) buffer_B[j] * (long long)input[k][i];
			temp2 = (long long) in_B[k] + temp1;
			temp3 = temp2 % input1[k];
			in_B[k] = temp3;
		}
	}



	// Conversion of N

	for (i = 0, j = n_counter; j>=0; i++, j--)
	{
		for (unsigned int k = 0; k <= MODULI_SET_SIZE*2; k++)
		{
			temp1 = (long long) buffer_N[j] * (long long)input[k][i];
			temp2 = (long long) in_N[k] + temp1;
			temp3 = temp2 % input1[k];
			in_N[k] = temp3;
		}
	}

	printf("\nInitial RNS conversion complete.");
	/*printf("\n\nA[] = ");
	for (i = 0; i<= MODULI_SET_SIZE*2; i++)
	{
		printf("%d ", in_A[i]);
	}

	printf("\n\nB[] = ");
	for (i = 0; i<= MODULI_SET_SIZE*2; i++)
	{
		printf("%d ", in_B[i]);
	}

	printf("\n\nN[] = ");
	for (i = 0; i<= MODULI_SET_SIZE*2; i++)
	{
		printf("%d ", in_N[i]);
	}*/

	////////////////////// Perform precomputations /////////////////////////////////////

	/////Precomputations for approximate base conversion/////

	// Precompute Mi and |Mi^(-1)| mi

	/*for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	{
		Mi[i] = M / in_modulus[i]; // Compute Mi
		MiInverse[i] = ModularInverse(Mi[i], in_modulus[i]) % in_modulus[i]; // |Mi^(-1)| mi
	}*/

	FILE *fp2=fopen("MiInverse.txt", "r");
		if (fp2)
		{
			while(feof(fp2)== 0)
			{
				for (i=0; i <= (MODULI_SET_SIZE-1); i++)
				{
					fscanf(fp2,"%u",&MiInverse[i]);
				}
			}
		printf("\nMiInverse file read complete.");
		fclose(fp2);
		}
		else
		printf("\nFile Read Error!\n");





	// Precompute  |Mi| mj
	/*for (j = 0; j <= MODULI_SET_SIZE ; j++) // j = 6 because the redundant modulus also needs to be calculated here
	{
		for (i = 0; i<=MODULI_SET_SIZE-1; i++)
		{
			Mij[j][i] = Mi[i] % in_modulus[j+MODULI_SET_SIZE];
		}
	}*/

	FILE *fp3=fopen("Mij.txt", "r");
			if (fp3)
			{
				while(feof(fp3)== 0)
				{
					for (i=0; i <= (MODULI_SET_SIZE); i++ )
					{
						for(j=0; j<=(MODULI_SET_SIZE - 1); j++)
						{
							fscanf(fp3,"%u",&Mij[i][j]);
						}
					}
				}
			printf("\nMij file read complete.");
			fclose(fp3);
			}
			else
			printf("\nFile Read Error!\n");



	/////Precomputations for exact base conversion/////

	// Precompute Mpj, |Mpj|mr  and |Mpj^(-1)| mj

	/*for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	{
		Mpj[i] = MP / in_modulus[i+MODULI_SET_SIZE+1]; // Compute Mpj
		Mpjr[i] = Mpj[i] % in_modulus[MODULI_SET_SIZE];  // Compute |Mpj|mr
		MpjInverse[i] = ModularInverse(Mpj[i], in_modulus[i+MODULI_SET_SIZE+1]) % in_modulus[i+MODULI_SET_SIZE+1]; // |Mpj^(-1)| mj
	}*/

	FILE *fp4=fopen("Mpjr.txt", "r");
		if (fp4)
		{
			while(feof(fp4)== 0)
			{
				for (i=0; i <= (MODULI_SET_SIZE-1); i++)
				{
					fscanf(fp4,"%u",&Mpjr[i]);
				}
			}
		printf("\nMpjr file read complete.");
		fclose(fp4);
		}
		else
			printf("\nFile Read Error!\n");



		FILE *fp5=fopen("MpjInverse.txt", "r");
		if (fp5)
		{
			while(feof(fp5)== 0)
			{
				for (i=0; i <= (MODULI_SET_SIZE-1); i++)
				{
					fscanf(fp5,"%u",&MpjInverse[i]);
				}
			}
		printf("\nMpjInverse file read complete.");
		fclose(fp5);
		}
		else
			printf("\nFile Read Error!\n");





	//Precompute |Mp(^-1)|mr

	/*MpInvR = ModularInverse(MP, in_modulus[MODULI_SET_SIZE]);*/

	FILE *fp6=fopen("MpInvR.txt", "r");
		if (fp6)
		{
			while(feof(fp6)== 0)
			{
				fscanf(fp6,"%u",&MpInvR);
			}
		printf("\nMpInvR file read complete.");
		fclose(fp6);
		}
		else
			printf("\nFile Read Error!\n");




	// Precompute  |Mpj| mi
	/*for (i = 0; i <= MODULI_SET_SIZE-1 ; i++)
	{
		for (j = 0; j<=MODULI_SET_SIZE-1; j++)
		{
			Mpji[i][j] = Mpj[j] % in_modulus[i];
		}
	} */

	FILE *fp7=fopen("Mpji.txt", "r");
		if (fp7)
		{
			while(feof(fp7)== 0)
			{
				for (i=0; i <= (MODULI_SET_SIZE-1); i++ )
				{
					for(j=0; j<=(MODULI_SET_SIZE - 1); j++)
					{
						fscanf(fp7,"%u",&Mpji[i][j]);
					}
				}
			}
		printf("\nMpji file read complete.");
		fclose(fp7);
		}
		else
			printf("\nFile Read Error!\n");



/*
	///Extra precomputation needed to perform exact base conversion for the first base conversion in the final Montgomery pass
	// Precompute |Mi|mr

	//for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	//{
	//	Mir[i] = Mi[i] % in_modulus[MODULI_SET_SIZE];
	//}

	ifstream indata8; // indata is like cin
    unsigned int num8;

	indata8.open("Mir.txt"); // opens the file
	if(!indata8) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

	indata8 >> num8;
	for (i=0; (i <= (MODULI_SET_SIZE - 1))&&(!indata8.eof()); i++ )
	{
			Mir[i] = num8;
			indata8 >> num8; // sets EOF flag if no value found
	}

	indata8.close();
	printf("\nMir file read complete.");




	//Precompute |M(^-1)|mr

	//MInvR = ModularInverse(M, in_modulus[MODULI_SET_SIZE]);

	ifstream indata9; // indata is like cin
    unsigned int num9;

	indata9.open("MInvR.txt"); // opens the file
	if(!indata9) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

	indata9 >> num9;
	while(!indata9.eof())
	{
			MInvR = num9;
			indata9 >> num9; // sets EOF flag if no value found
	}

	indata9.close();
	printf("\nMInvR file read complete.");

*/


	/////Precomputations for third step/////


	//Precompute M^(-1)

	/*for (i = 0; i <= MODULI_SET_SIZE; i++)
	{
		MInv[i] = ModularInverse(M, in_modulus[i+MODULI_SET_SIZE]);
	}*/

	FILE *fp10=fopen("MInv.txt", "r");
			if (fp10)
			{
				while(feof(fp10)== 0)
				{
					for (i=0; i <= (MODULI_SET_SIZE); i++)
					{
						fscanf(fp10,"%u",&MInv[i]);
					}
				}
			printf("\nMInv file read complete.");
			fclose(fp10);
			}
			else
		printf("\nFile Read Error!\n");



	/*//////////////////////Perform first pass of Montgomery multiplication ///////////////

	MM(in_A, in_B, in_N, in_modulus, &M, &MP, Mi, MiInverse, Mij, Mpj, Mpjr, MpjInverse, Mpji, &MpInvR, MInv, Result);*/




	////////////////////// Precompute M^2 mod N  ////////////////////////////////////////

	/*for (i =0; i <= MODULI_SET_SIZE*2; i++)
	{
		MsqModN[i] = MsquareN % in_modulus[i];
	}*/

	FILE *fp11=fopen("MsqModN.txt", "r");
		if (fp11)
		{
			while(feof(fp11)== 0)
			{
				for (i=0; i <= (MODULI_SET_SIZE*2); i++)
				{
					fscanf(fp11,"%u",&MsqModN[i]);
				}
			}
		printf("\nMsqModN file read complete.");
		fclose(fp11);
		}
		else
		printf("\nFile Read Error!\n");

	////////////////////// Precompute MP mod mi  ////////////////////////////////////////

		FILE *fp12=fopen("Mpi.txt", "r");
				if (fp12)
				{
					while(feof(fp12)== 0)
					{
						for (i=0; i <= (MODULI_SET_SIZE-1); i++)
						{
							fscanf(fp12,"%u",&Mpi[i]);
						}
					}
				printf("\nMpi file read complete.");
				fclose(fp12);
				}
				else
					printf("\nFile Read Error!\n");



	////////////////////// Precompute M mod mj  ////////////////////////////////////////

	FILE *fp13=fopen("Mj.txt", "r");
		if (fp13)
		{
			while(feof(fp13)== 0)
			{
				for (i=0; i <= (MODULI_SET_SIZE); i++)
				{
					fscanf(fp13,"%u",&Mj[i]);
				}
			}
		printf("\nMj file read complete.");
		fclose(fp13);
		}
		else
			printf("\nFile Read Error!\n");


/*
	/////////////////////// Precompute MI /////////////////////////


ifstream indata14; // indata is like cin
    unsigned int num14;

	indata14.open("MI.txt"); // opens the file
	if(!indata14) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

	indata14 >> num14;
	for (i = 0; (i <= (MODULI_SET_SIZE - 1))&&(!indata14.eof()); i++ )
	{
		for(j = 0; (j <= MODULI_SET_SIZE - 1 )&&(!indata14.eof()); j++)
		{
			MI[i][j]=num14;
			indata14 >> num14; // sets EOF flag if no value found
		}
	}

	indata14.close();
	printf("\nMI file read complete.");

*/


	/*//////////////////////Perform final pass of Montgomery multiplication ///////////////

	printf(" \n\n\n\nSecoond pass starting .....");

	MMlast(MsqModN, Result, in_N, in_modulus, &M, &MP, Mi, Mir, MiInverse, Mij, &MInvR, Mpj, Mpjr, MpjInverse, Mpji, &MpInvR, MInv, Final_Result);*/

	//////////////////////Perform Montgomery Exponentiation ///////////////

	printf(" \n\n\n\nCPU starting .....");


	for (i = 0; i < NUMBER_OF_MESSAGES; i++)
		{
			printf("\n\nCipher# %d", i+1);

			//Timer
			cutResetTimer(timer);
			cutStartTimer(timer);


			Exp(&in_A[i][0], /*in_B,*/ in_N, MsqModN, input1, Mpi, Mj, /*Mi, Mir,*/ MiInverse, Mij, /*&MInvR, Mpj,*/ Mpjr, MpjInverse, Mpji, &MpInvR, MInv, /*MI,*/ &Final_Result[i][0]);

			//Timer
			cutStopTimer(timer);
			cpu_time += cutGetTimerValue(timer)/1000;

			printf("\nCPU Processing Time = %f sec", cutGetTimerValue(timer)/1000);
		}

	printf("\n\nCPU completed.");
	printf("\n----------------------------------------");
	printf("\nNumber of Mesages = %d", NUMBER_OF_MESSAGES);
	printf("\nTotal CPU Processing Time = %f sec", cpu_time);
	printf("\n----------------------------------------");


	////////////////////////////////////GPU ////////////////////////////////////

	printf("\n\nGPU phase:");
	// Precomputed variables
	unsigned int e[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}; // e = 65537
	unsigned int One[2*MODULI_SET_SIZE+1];
	for (i = 0; i <= 2*MODULI_SET_SIZE; i++) One[i] = 1;




	// pointers for precomputed variables
	unsigned int (*prt_A)[MODULI_SET_SIZE * 2 + 1], *prt_N, *prt_MsqModN, *prt_input1, *prt_Mpi, *prt_Mj, /*Mi, Mir,*/ *prt_MiInverse;
	unsigned int (*prt_Mij)[MODULI_SET_SIZE], /*&MInvR, Mpj,*/ *prt_Mpjr, *prt_MpjInverse, (*prt_Mpji)[MODULI_SET_SIZE], *prt_MpInvR, *prt_MInv /*MI,*/ ;
	unsigned int (*prt_Device_Final_Result)[MODULI_SET_SIZE * 2 + 1];
	unsigned int *prt_e, *prt_One;

	// assign precomputed variables to pointers
	prt_A = in_A;
	prt_N = in_N;
	prt_MsqModN = MsqModN;
	prt_input1 = input1;
	prt_Mpi = Mpi;
	prt_Mj = Mj;
	prt_MiInverse = MiInverse;
	prt_Mij = Mij;
	prt_Mpjr = Mpjr;
	prt_MpjInverse = MpjInverse;
	prt_Mpji = Mpji;
	prt_MpInvR = &MpInvR;
	prt_MInv = MInv;
	prt_Device_Final_Result = Device_Final_Result;
	prt_e = e;
	prt_One = One;



	//sizes of variables
	unsigned int size1 = sizeof(unsigned int);
	unsigned int size2 = (MODULI_SET_SIZE) * sizeof(unsigned int);
	unsigned int size3 = (MODULI_SET_SIZE+1) * sizeof(unsigned int);
	unsigned int size4 = (MODULI_SET_SIZE * 2 + 1) * sizeof(unsigned int);
	unsigned int size5 = (MODULI_SET_SIZE * MODULI_SET_SIZE) * sizeof(unsigned int);
	unsigned int size6 = ((MODULI_SET_SIZE+1)* MODULI_SET_SIZE) * sizeof(unsigned int);


	// allocate memory in GPU
	unsigned int (*d_A)[MODULI_SET_SIZE * 2 + 1];
	cudaMalloc((void**)&d_A, NUMBER_OF_MESSAGES*size4);
	cudaMemcpy(d_A, prt_A, NUMBER_OF_MESSAGES*size4, cudaMemcpyHostToDevice);
	printf("\nA allocated");
	fflush(NULL);

	unsigned int* d_N;
	cudaMalloc((void**)&d_N, size4);
	cudaMemcpy(d_N, prt_N, size4, cudaMemcpyHostToDevice);
	printf("\nN allocated");
	fflush(NULL);

	//unsigned int* d_MsqModN;
	//cudaMalloc((void**)&d_MsqModN, size4);
	//cudaMemcpy(d_MsqModN, prt_MsqModN, size4, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol(d_MsqModN, prt_MsqModN, size4);
	printf("\nMsqModN allocated");
	fflush(NULL);

	unsigned int* d_input1;
	cudaMalloc((void**)&d_input1, size4);
	cudaMemcpy(d_input1, prt_input1, size4, cudaMemcpyHostToDevice);
	printf("\ninput1 allocated");
	fflush(NULL);

	//unsigned int* d_Mpi;
	//cudaMalloc((void**)&d_Mpi, size2);
	//cudaMemcpy(d_Mpi, prt_Mpi, size2, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol(d_Mpi, prt_Mpi, size2);
	printf("\nMpi allocated");
	fflush(NULL);

	//unsigned int* d_Mj;
	//cudaMalloc((void**)&d_Mj, size3);
	//cudaMemcpy(d_Mj, prt_Mj, size3, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol(d_Mj, prt_Mj, size3);
	printf("\nMj allocated");
	fflush(NULL);

	//unsigned int* d_MiInverse;
	//cudaMalloc((void**)&d_MiInverse, size2);
	//cudaMemcpy(d_MiInverse, prt_MiInverse, size2, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol(d_MiInverse, prt_MiInverse, size2);
	printf("\nMiInverse allocated");
	fflush(NULL);

	//unsigned int (*d_Mij)[MODULI_SET_SIZE];
	//cudaMalloc((void**)&d_Mij, size6);
	//cudaMemcpy(d_Mij, prt_Mij, size6, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol(d_Mij, prt_Mij, size6);
	printf("\nMij allocated");
	fflush(NULL);


	//unsigned int* d_Mpjr;
	//cudaMalloc((void**)&d_Mpjr, size2);
	//cudaMemcpy(d_Mpjr, prt_Mpjr, size2, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol(d_Mpjr, prt_Mpjr, size2);
	printf("\nMpjr allocated");
	fflush(NULL);

	//unsigned int* d_MpjInverse;
	//cudaMalloc((void**)&d_MpjInverse, size2);
	//cudaMemcpy(d_MpjInverse, prt_MpjInverse, size2, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol(d_MpjInverse, prt_MpjInverse, size2);
	printf("\nMpjInverse allocated");
	fflush(NULL);

	//unsigned int (*d_Mpji)[MODULI_SET_SIZE];
	//cudaMalloc((void**)&d_Mpji, size5);
	//cudaMemcpy(d_Mpji, prt_Mpji, size5, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol(d_Mpji, prt_Mpji, size5);
	printf("\nMpji allocated");
	fflush(NULL);

	//unsigned int* d_MpInvR;
	//cudaMalloc((void**)&d_MpInvR, size1);
	//cudaMemcpy(d_MpInvR, prt_MpInvR, size1, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol(d_MpInvR, prt_MpInvR, size1);
	printf("\nMpInvR allocated");
	fflush(NULL);

	//unsigned int* d_MInv;
	//cudaMalloc((void**)&d_MInv, size3);
	//cudaMemcpy(d_MInv, prt_MInv, size3, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol(d_MInv, prt_MInv, size3);
	printf("\nMInv allocated");
	fflush(NULL);

	unsigned int (*d_Device_Final_Result)[MODULI_SET_SIZE * 2 + 1];
	cudaMalloc((void**)&d_Device_Final_Result, NUMBER_OF_MESSAGES*size4);
	cudaMemcpy(d_Device_Final_Result, prt_Device_Final_Result, NUMBER_OF_MESSAGES*size4, cudaMemcpyHostToDevice);
	printf("\nFinal_Result allocated");
	fflush(NULL);

	cudaMemcpyToSymbol(d_e, prt_e, SIZE_OF_e*sizeof(unsigned int));
	printf("\ne allocated");
	fflush(NULL);

	cudaMemcpyToSymbol(d_One, prt_One, size4);
	printf("\nOne allocated");
	fflush(NULL);



	// GPU configuration
	//dim3 DimQBlock(NUMBER_OF_THREADS, 1);
	//dim3 DimQGrid(1, 1);
	dim3 DimQBlock(NUMBER_OF_THREADS, 1);
	dim3 DimQGrid(NUMBER_OF_MESSAGES, 1);


	printf("\n\nGPU started......");

	cutResetTimer(timer);
	cutStartTimer(timer);

//	dExp <<< DimQGrid, DimQBlock >>> (d_A, /*in_B,*/ d_N, d_MsqModN, d_input1, d_Mpi, d_Mj, /*Mi, Mir,*/ d_MiInverse, d_Mij, /*&MInvR, Mpj,*/ d_Mpjr, d_MpjInverse, d_Mpji, d_MpInvR, d_MInv, /*MI,*/ d_Device_Final_Result);
	dExp <<< DimQGrid, DimQBlock >>> (d_A, d_N, d_input1, d_Device_Final_Result);

	//check if kernel invocation generated an error
	CUT_CHECK_ERROR("Kernel execution failed");


    cudaThreadSynchronize();

    cutStopTimer(timer);
    gpu_time = cutGetTimerValue(timer)/1000;


    printf ("\n\nGPU completed.....");

	cudaMemcpy(prt_Device_Final_Result, d_Device_Final_Result, NUMBER_OF_MESSAGES*size4, cudaMemcpyDeviceToHost);



	/*
	for( j = 0; j < NUMBER_OF_MESSAGES; j++)
	{
		printf("\n\nCipher# %d",j);
		printf("\n----------------------------------------------------------------\n");

		for (i = 0; i <= 2*MODULI_SET_SIZE; i++) printf("%u, ", Device_Final_Result[j][i]);

		printf("\n----------------------------------------------------------------");

	}
	*/


	printf("\n----------------------------------------");
	printf("\nTotal GPU Processing Time = %f sec", gpu_time);
	printf("\nSpeedup = %f", cpu_time/gpu_time);
	printf("\n----------------------------------------");


	for (i = 0; i < NUMBER_OF_MESSAGES; i++)
	{
		for(j = 0; j <= 2*MODULI_SET_SIZE; j++)
		{

			if (Final_Result[i][j] != Device_Final_Result[i][j])
			{
				printf("\nERROR !! Results from CPU and GPU don't Match.\n");
				exit(0);
			}
		}

	}

	printf("\n\nResults from CPU and GPU match.\n");


	cudaFree(d_A);
	cudaFree(d_N);
	cudaFree(d_input1);
	cudaFree(d_Device_Final_Result);
	cudaFree(d_MsqModN);
	cudaFree(d_Mpi);
	cudaFree(d_Mj);
	cudaFree(d_MiInverse);
	cudaFree(d_Mij);
	cudaFree(d_Mpjr);
	cudaFree(d_MpjInverse);
	cudaFree(d_Mpji);
	cudaFree(&d_MpInvR);
	cudaFree(d_MInv);


	getchar();
	return 0;
}




//////////////////////////Montgomery multiplication///////////////////////

unsigned int MM(unsigned int *A, unsigned int *B, unsigned int *N, unsigned int *modulus, unsigned int *Mpi, /*unsigned int *Mj, unsigned int *Mi,*/ unsigned int *MiInverse, unsigned int (*Mij)[MODULI_SET_SIZE], /*unsigned int *Mpj,*/ unsigned int *Mpjr, unsigned int *MpjInverse, unsigned int (*Mpji)[MODULI_SET_SIZE], unsigned int *MpInvR, unsigned int *MInv, unsigned int *Result)
{	int i;
	unsigned int Q[MODULI_SET_SIZE]; // Variable for step 1 // Q = 6 as needed for the final Montgomery pass
	unsigned int Qp[MODULI_SET_SIZE+1]; // Varibale for step 2
	unsigned int Rp[MODULI_SET_SIZE+1]; // Varibale for step 3
	unsigned int R[MODULI_SET_SIZE]; // Varibale for step 4


	/////////////////Step 1: Q <- ( -A * B) * N^(-1) /////////////////////////

	FirstStep(A, B, N, modulus, Q);


	//////////////////Step 2: First base conversion using CRT /////////////////////

	ApproxExt( Q, Qp, modulus, /*Mi,*/ MiInverse, Mij);


	/////////////////Step 3: Rp <- (A * B + Qp * N) * M^(-1) /////////////////////////

	ThirdStep(A, B, N, modulus, Qp, Rp, MInv);


	//////////////////Step 4: Second base conversion using Shenoy and Kumaresan /////////////////////

	ExactExt( Rp, R, modulus, Mpi, /*Mpj,*/ Mpjr, MpjInverse, Mpji, &*MpInvR);



	// Copy results back

	for (i = 0; i<= MODULI_SET_SIZE-1; i++)
	{
		Result[i] = R[i];
	}

	for (i = 0; i<= MODULI_SET_SIZE; i++)
	{
		Result[i+MODULI_SET_SIZE] = Rp[i];
	}

	return 0;

}


//////////////////////////Final Montgomery multiplication///////////////////////

unsigned int MMlast(unsigned int *A, unsigned int *B, unsigned int *N, unsigned int *modulus, unsigned int *Mpi, unsigned int *Mj, /*unsigned int *Mi, unsigned int *Mir,*/ unsigned int *MiInverse, unsigned int (*Mij)[MODULI_SET_SIZE], /*unsigned int *MInvR, unsigned int *Mpj,*/ unsigned int *Mpjr, unsigned int *MpjInverse, unsigned int (*Mpji)[MODULI_SET_SIZE], unsigned int *MpInvR, unsigned int *MInv, /*unsigned int (*MI)[MODULI_SET_SIZE],*/ unsigned int *Result)
{	int i;
	unsigned int Q[MODULI_SET_SIZE]; // Variable for step 1
	unsigned int Qp[MODULI_SET_SIZE+1]; // Varibale for step 2
	unsigned int Rp[MODULI_SET_SIZE+1]; // Varibale for step 3
	unsigned int R[MODULI_SET_SIZE]; // Varibale for step 4


	/////////////////Step 1: Q <- ( -A * B) * N^(-1) /////////////////////////

	FirstStep(A, B, N, modulus, Q);


	//////////////////Step 2: First base conversion using CRT /////////////////////

	//ApproxExt( Q, Qp, modulus, &*M, Mi, MiInverse, Mij);
	ExactExtLast( Q, Qp, modulus, Mj, /*Mi, Mir,*/ MiInverse, Mij/*, &*MInvR*/);
	//MRS( Q, Qp, modulus, MI);

	/////////////////Step 3: Rp <- (A * B + Qp * N) * M^(-1) /////////////////////////

	ThirdStep(A, B, N, modulus, Qp, Rp, MInv);


	//////////////////Step 4: Second base conversion using Shenoy and Kumaresan /////////////////////

	ExactExt( Rp, R, modulus, Mpi, /*Mpj,*/ Mpjr, MpjInverse, Mpji, &*MpInvR);



	// Copy results back

	for (i = 0; i<= MODULI_SET_SIZE-1; i++)
	{
		Result[i] = R[i];
	}

	for (i = 0; i<= MODULI_SET_SIZE; i++)
	{
		Result[i+MODULI_SET_SIZE] = Rp[i];
	}

return 0;
}




/////////////////Step 1: Q <- ( -A * B) * N^(-1) /////////////////////////

unsigned int FirstStep(unsigned int *A, unsigned int *B, unsigned int *N, unsigned int *modulus, unsigned int *Q)
{
	long long temp;
	int i;

	for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	{
		Q[i] = 0; // Initialize Q
	}

	for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	{
		/*temp = -((long long)A[i] * (long long)B[i]) * (long long)ModularInverse( N[i], modulus[i]);
		Q[i] = (temp % (long long)modulus[i]) + (long long)modulus[i];*/ // Source :http://stackoverflow.com/questions/989943/weird-objective-c-mod-behavior
												 // Since temp is always negative here, use the first comment/answer in the source website.
		temp = ((unsigned long long)A[i] * (unsigned long long)B[i]) % modulus[i];
		temp = -((temp * (unsigned long long)ModularInverse( N[i], modulus[i])) % modulus[i]);
		Q[i] = (temp % modulus[i]) + modulus[i];
	}
	/*printf("\n\n\nStep1 [Q <- ( -A * B) * N^(-1)] complete.");
	printf("\n\nQ[] = ");
	for (i = 0; i<=MODULI_SET_SIZE-1; i++)
	{
		printf("%u ", Q[i]);
	}*/

	/*ofstream myfile3 ("Temp2.txt");
  	if (myfile3.is_open())
	  {


		for (i = 0; i<=(MODULI_SET_SIZE-1); i++)
		{
			myfile3 << Q[i] << " ";
		}

		 myfile3.close();
	  }
 	 else cout << "Unable to open file";*/


	return 0;
}



/////////////////Step 3: Rp <- (A * B + Qp * N) * M^(-1) /////////////////////////

unsigned int ThirdStep(unsigned int *A, unsigned int *B, unsigned int *N, unsigned int *modulus, unsigned int *Qp, unsigned int *Rp, unsigned int *MInv)
{
	int i;
	unsigned int temp, temp1, temp2;

	// Compute Rp
	for (i = 0; i <= MODULI_SET_SIZE; i++)
	{
		//Rp[i] = ((A[i+MODULI_SET_SIZE] * B[i+MODULI_SET_SIZE] + Qp[i] * N[i+MODULI_SET_SIZE]) * MInv[i]) % modulus[i+MODULI_SET_SIZE];
		temp = ((unsigned long long)A[i+MODULI_SET_SIZE] * (unsigned long long)B[i+MODULI_SET_SIZE]) % modulus[i+MODULI_SET_SIZE];
		temp1 = ((unsigned long long)Qp[i] * (unsigned long long)N[i+MODULI_SET_SIZE]) % modulus[i+MODULI_SET_SIZE];
		temp2 = ((unsigned long long)temp + (unsigned long long)temp1) % modulus[i+MODULI_SET_SIZE];
		Rp[i] = ((unsigned long long)temp2 * (unsigned long long)MInv[i]) % modulus[i+MODULI_SET_SIZE];
	}

	/*printf("\n\n\nStep3 [Rp <- (A * B + Qp * N) * M^(-1)] complete.");
	printf("\n\nRp[] = ");
	for (i = 0; i<=MODULI_SET_SIZE; i++)
	{
		printf("%u ", Rp[i]);
	}*/

	/*ofstream myfile5 ("Temp4.txt");
  	if (myfile5.is_open())
	  {


		for (i = 0; i<=(MODULI_SET_SIZE); i++)
		{
			myfile5 << Rp[i] << " ";
		}

		 myfile5.close();
	  }
 	 else cout << "Unable to open file";*/


	return 0;

}



//////////////////Approximate base conversion using CRT /////////////////////

unsigned int ApproxExt( unsigned int *Q, unsigned int *Qp, unsigned int *modulus, /*unsigned int *Mi,*/ unsigned int *MiInverse, unsigned int (*Mij)[MODULI_SET_SIZE])
{
	unsigned int sigma[MODULI_SET_SIZE], temp;
	int i, j;


	// Compute sigma
	for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	{
		sigma[i] = ((long long)Q[i]*(long long)MiInverse[i]) % modulus[i];
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
			  temp = ((long long)Mij[j][i] * (long long)sigma[i]) % (long long)modulus[j+MODULI_SET_SIZE];
			  Qp[j] = ((long long)temp + (long long)Qp[j]) % (long long)modulus[j+MODULI_SET_SIZE];
		}
	}

	printf("\n\n\nStep2 [first base conversion] complete.");
	printf("\n\nQp[] = ");
	for (i = 0; i<=MODULI_SET_SIZE; i++)
	{
		printf("%u ", Qp[i]);
	}

	return 0;
}

//////////////////Exact base conversion using MRS /////////////////////

unsigned int MRS( unsigned int *Q, unsigned int *Qp, unsigned int *modulus, unsigned int (*MI)[MODULI_SET_SIZE])
{

	unsigned int xp[MODULI_SET_SIZE];
	unsigned long long temp = 1;
	int i, j;


	// compute the MRS coefficients
	xp[0] = Q[0] % modulus[0];

	for (i = 1; i<= MODULI_SET_SIZE-1; i++)
	{
		for(j = 0; j <= i-1; j++)
		{
			if (j <=0)
			{
				//temp1 = (Q[i]-xp[j])*MI[j][i];
				temp = ((modulus[i]+((long long)Q[i]-(long long)xp[j]))% modulus[i])%modulus[i];
				temp = (temp*(long long)MI[j][i])% modulus[i];
			}
			else
			{
				//temp1 = (temp1 - xp[j])*MI[j][i];
				temp = ((modulus[i]+(temp - (long long)xp[j]))% modulus[i])%modulus[i];
				temp = (temp*(long long)MI[j][i])% modulus[i];

			}
		}
		//xp[i] = temp % modulus[i];
		xp[i] = temp;
	}



	unsigned long long tRNS[MODULI_SET_SIZE+1], temp1[MODULI_SET_SIZE+1], temp2[MODULI_SET_SIZE+1];
	for (i = 0; i <= MODULI_SET_SIZE; i++)
	{
		tRNS[i] = xp[0];
		temp1[i] = 1;
	}

	temp = 1;
	for(i = 1; i <= MODULI_SET_SIZE-1; i++)
	{
		for (j = 0; j <= MODULI_SET_SIZE; j++)
		{
			temp1[j] = (temp1[j] * (long long)modulus[i-1])%modulus[MODULI_SET_SIZE+j];
			temp2[j] = ((long long)xp[i] * temp1[j])%modulus[MODULI_SET_SIZE+j];
			tRNS[j] = (tRNS[j]+temp2[j])%modulus[MODULI_SET_SIZE+j];
		}
		//X = X + xp[i] * temp1;
	}

	for (i = 0; i <= MODULI_SET_SIZE; i++)
	{
		Qp[i] = tRNS[i];
	}

	printf("\n\n\nStep2 [first base conversion] complete.");
	printf("\n\nQp[] = ");
	for (i = 0; i<=MODULI_SET_SIZE; i++)
	{
		printf("%u ", Qp[i]);
	}

	/*ofstream myfile4 ("Temp3.txt");
  	if (myfile4.is_open())
	  {


		for (i = 0; i<=(MODULI_SET_SIZE); i++)
		{
			myfile4 << Qp[i] << " ";
		}

		 myfile4.close();
	  }
 	 else cout << "Unable to open file";*/




	return 0;
}





//////////////////Exact base conversion using Shenoy and Kumaresan /////////////////////

unsigned int ExactExt( unsigned int *Rp, unsigned int *R, unsigned int *modulus, unsigned int *Mpi, /*unsigned int *Mpj,*/ unsigned int *Mpjr, unsigned int *MpjInverse, unsigned int (*Mpji)[MODULI_SET_SIZE], unsigned int *MpInvR)
{
	unsigned int Xi[MODULI_SET_SIZE],Beta, temp, temp1, temp2;
	long long  temp3;
	int i, j;


	// Compute xi

	for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	{
		Xi[i] = ((unsigned long long)Rp[i+1] * (unsigned long long)MpjInverse[i]) % modulus[i+MODULI_SET_SIZE+1];
	}


	//Compute Beta

	temp = 0;

	for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	{
		//temp = (temp + Mpjr[i] * Xi[i]) % modulus[MODULI_SET_SIZE];
		temp1 = ((unsigned long long)Mpjr[i] * (unsigned long long)Xi[i]) % modulus[MODULI_SET_SIZE];
		temp = ((unsigned long long)temp + (unsigned long long)temp1 ) % modulus[MODULI_SET_SIZE];

	}

	//temp = (modulus[MODULI_SET_SIZE] + (temp - Rp[0]) % modulus[MODULI_SET_SIZE]) % modulus[MODULI_SET_SIZE]; // Source :http://stackoverflow.com/questions/989943/weird-objective-c-mod-behavior
	temp3 = ((long long)temp - (long long)Rp[0]);
	//temp = temp % modulus[MODULI_SET_SIZE];
	temp3 = (modulus[MODULI_SET_SIZE] + temp3 % modulus[MODULI_SET_SIZE]) % modulus[MODULI_SET_SIZE];
	Beta = ((unsigned long long)temp3 * (unsigned long long)(*MpInvR)) % modulus[MODULI_SET_SIZE];							// Since temp will sometimes be positive ans sometimes negative,


	// Compute R
	for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	{
		R[i] = 0; // Initialize R
	}

	for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	{
		for (j = 0; j <= MODULI_SET_SIZE-1; j++)
		{
			//R[i] = (R[i] + Mpji[i][j] * Xi[j]) % modulus[i];
			temp2 = ((unsigned long long)Mpji[i][j] * (unsigned long long)Xi[j]) % modulus[i];
			R[i] = ((unsigned long long)R[i] + (unsigned long long)temp2)% modulus[i];
		}
		temp3 = R[i] - ((long long)Beta * (long long)(Mpi[i])) % modulus[i];
		R[i] = (modulus[i] + (temp3 % modulus[i])) % modulus[i]; // Source :http://stackoverflow.com/questions/989943/weird-objective-c-mod-behavior
	}															// Since temp will sometimes be positive ans sometimes negative,
																// use the third comment/answer in the source website.


	/*printf("\n\n\nStep4 [second base conversion] complete.");
	printf("\n\nR[] = ");
	for (i = 0; i<=MODULI_SET_SIZE-1; i++)
	{
		printf("%u ", R[i]);
	}*/


	/*ofstream myfile6 ("Temp5.txt");
  	if (myfile6.is_open())
	  {


		for (i = 0; i<=(MODULI_SET_SIZE-1); i++)
		{
			myfile6 << R[i] << " ";
		}

		 myfile6.close();
	  }
 	 else cout << "Unable to open file";*/




	return 0;


}


//////////////////Exact base conversion using Kawamura, Harrison and Shenoy and Kumaresan /////////////////////

unsigned int ExactExtLast( unsigned int *Q, unsigned int *Qp, unsigned int *modulus, unsigned int *Mj, /*unsigned int *Mi, unsigned int *Mir,*/ unsigned int *MiInverse, unsigned int (*Mij)[MODULI_SET_SIZE]/*, unsigned int *MInvR*/)
{
	unsigned int Xi[MODULI_SET_SIZE],Beta, temp2;
	float temp;
	int i, j;
	long long temp1;



	// Compute xi

	for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	{
		Xi[i] = ((unsigned long long)Q[i]*(unsigned long long)MiInverse[i]) % modulus[i];
	}


	//Compute Beta.
	//This part is done according to Kawamura et al (2000) page 5 equation 5 and idea from Harrison et al (2009) page 12.
	// Here Beta is essentially k as in Kawamura et al and Harrison et al.
	// This part needs further consideration and observation to see if the accumulation of results of the division below
	// actually works for large numbers of not. If not, alternative ways of doiing it would be (1) follow Bajard's base extension without conversion,
	// (2) Kawamura's approximate truncation method, or (3) Mixed Radix System

	temp = 0;

	for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	{
		temp = temp + (float)Xi[i] / (float)modulus[i];
	}

	Beta = temp;




	// Compute Qp
	// After the computation below, the validity of Qp[0] is questionalble; it needs to be seen what happens to this value for large numbers.
	for (i = 0; i <= MODULI_SET_SIZE; i++)
	{
		Qp[i] = 0; // Initialize R
	}

	for (j = 0; j <= MODULI_SET_SIZE; j++)
	{
		for (i = 0; i <= MODULI_SET_SIZE-1; i++)
		{
			//Qp[j] = ((unsigned long long)Qp[j] + (unsigned long long)Mij[j][i] * (unsigned long long)Xi[i]) % (unsigned long long)modulus[j+MODULI_SET_SIZE];
				temp2 = ((unsigned long long)Mij[j][i] * (unsigned long long)Xi[i]) % (unsigned long long)modulus[j+MODULI_SET_SIZE];
				Qp[j] = ((unsigned long long)Qp[j]+(unsigned long long)temp2) % (unsigned long long)modulus[j+MODULI_SET_SIZE];
		}
		temp1 = (long long)Qp[j] - (Beta * (long long)(Mj[j])) % (long long)modulus[j+MODULI_SET_SIZE];
		/*temp1 = (long long)Beta * (long long)(Mj[j]);
		temp1 = temp1 % (long long)modulus[j+MODULI_SET_SIZE];
		temp1 = (long long)Qp[j] - temp1;*/
		Qp[j] = (modulus[j+MODULI_SET_SIZE] + (temp1 % modulus[j+MODULI_SET_SIZE])) % modulus[j+MODULI_SET_SIZE]; // Source :http://stackoverflow.com/questions/989943/weird-objective-c-mod-behavior
	}															 // Since temp will sometimes be positive ans sometimes negative,
																 // use the third comment/answer in the source website.


	/*printf("\n\n\nStep2 [first base conversion] complete.");
	printf("\n\nQp[] = ");
	for (i = 0; i<=MODULI_SET_SIZE; i++)
	{
		printf("%u ", Qp[i]);
	}*/

	return 0;
}



/*//////////Compute modular inverse///////////////////////////////////////////////
Code from http://en.wikipedia.org/wiki/Modular_multiplicative_inverse
and http://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
*/

unsigned int ModularInverse(unsigned int N, unsigned int D)
{	long long temp_gcd, x, y;

	temp_gcd = gcd(N, D, &x, &y);

	if (temp_gcd == 1)
		return ((x+D)%D); // takes care of negative values of x
	else
		return 0;
}


/*//////////Compute gcd///////////////////////////////////////////////
Code from http://en.wikipedia.org/wiki/Modular_multiplicative_inverse
and http://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
*/

unsigned int gcd(unsigned int A, unsigned int B, long long *X, long long *Y)
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


//////// Compute X^e mod N ////////////////////////////////////////
// source: Kawamura's paper page 532
// This function works for both MM and MMlast (commented out with //) inside the cide below. However, tha last Montgomery call must be MMlast.

unsigned int Exp(unsigned int *A, /*unsigned int *B,*/ unsigned int *N, unsigned int *MsqModN, unsigned int *modulus, unsigned int *Mpi, unsigned int *Mj, /*unsigned int *Mi, unsigned int *Mir,*/ unsigned int *MiInverse, unsigned int (*Mij)[MODULI_SET_SIZE], /*unsigned int *MInvR, unsigned int *Mpj,*/ unsigned int *Mpjr, unsigned int *MpjInverse, unsigned int (*Mpji)[MODULI_SET_SIZE], unsigned int *MpInvR, unsigned int *MInv, /*unsigned int (*MI)[MODULI_SET_SIZE],*/ unsigned int *Result)
{
	unsigned int XPrime[2*MODULI_SET_SIZE+1], Y[2*MODULI_SET_SIZE+1];
	unsigned int e[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}; // e = 65537
	unsigned int One[2*MODULI_SET_SIZE+1];
	int i, j;

	for (i = 0; i <= 2*MODULI_SET_SIZE; i++)
	{
		One[i] = 1;
	}


	//Step 1:
	//MM(A, MsqModN, N, modulus, Mpi, /*Mj, Mi,*/ MiInverse, Mij, /*Mpj,*/ Mpjr, MpjInverse, Mpji, &*MpInvR, MInv, XPrime);
	MMlast(A, MsqModN, N, modulus, Mpi, Mj, /*Mi, Mir,*/ MiInverse, Mij, /*&*MInvR, Mpj,*/ Mpjr, MpjInverse, Mpji, &*MpInvR, MInv, /*MI,*/ XPrime);

	//Step 2:
	for (i = 0; i <= 2*MODULI_SET_SIZE; i++)
	{
		Y[i] = XPrime[i];
	}



	/*ofstream myfile2 ("Temp.txt");
  	if (myfile2.is_open())
	  {


		for (i = 0; i<=(MODULI_SET_SIZE-1); i++)
		{
			myfile2 << Y[i] << " ";
		}

		 myfile2.close();
	  }
 	 else cout << "Unable to open file";*/



	//Step 3:
	for (j = 15; j >= 0; j--)
	{
		//Step 4:
		//MM(Y, Y, N, modulus, Mpi, /*Mj, Mi,*/ MiInverse, Mij, /*Mpj,*/ Mpjr, MpjInverse, Mpji, &*MpInvR, MInv, Result);
		MMlast(Y, Y, N, modulus, Mpi, Mj, /*Mi, Mir,*/ MiInverse, Mij, /*&*MInvR, Mpj,*/ Mpjr, MpjInverse, Mpji, &*MpInvR, MInv, /*MI,*/ Result);

		for (i = 0; i <= 2*MODULI_SET_SIZE; i++)
		{
			Y[i] = Result[i];
		}

	/*ofstream myfile2 ("Temp1.txt");
  	if (myfile2.is_open())
	  {


		for (i = 0; i<=(MODULI_SET_SIZE-1); i++)
		{
			myfile2 << Y[i] << " ";
		}

		 myfile2.close();
	  }
 	 else cout << "Unable to open file";*/




		//Step 5:
		if (e[j] == 1)
		{
			//MM(Result, XPrime, N, modulus, Mpi, /*Mj, Mi,*/ MiInverse, Mij, /*Mpj,*/ Mpjr, MpjInverse, Mpji, &*MpInvR, MInv, TEMP);
			MMlast(Result, XPrime, N, modulus, Mpi, Mj, /*Mi, Mir,*/ MiInverse, Mij, /*&*MInvR, Mpj,*/ Mpjr, MpjInverse, Mpji, &*MpInvR, MInv, /*MI,*/ Y);


		}


	}

	//Step 7:
	MMlast(Y, One, N, modulus, Mpi, Mj, /*Mi, Mir,*/ MiInverse, Mij, /*&*MInvR, Mpj,*/ Mpjr, MpjInverse, Mpji, &*MpInvR, MInv, /*MI,*/ Result);

	/*
	printf("\n----------------------------------------------------------------\n");
	for (i = 0; i <= 2*MODULI_SET_SIZE; i++) printf("%u, ", Result[i]);
	printf("\n----------------------------------------------------------------");
	*/

	return 0;

}