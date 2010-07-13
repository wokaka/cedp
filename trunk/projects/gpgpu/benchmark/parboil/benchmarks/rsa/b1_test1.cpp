
#include <stdio.h>
#include "string.h"
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <cstdlib> // for exit function

#define MODULI_SET_SIZE 33

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
	unsigned int in_A[MODULI_SET_SIZE * 2 + 1], in_B[MODULI_SET_SIZE * 2 + 1], in_N[MODULI_SET_SIZE * 2 + 1];
	unsigned int /*Mi[MODULI_SET_SIZE],*/ MiInverse[MODULI_SET_SIZE], Mij[MODULI_SET_SIZE+1][MODULI_SET_SIZE]; //Variables for precomutation of approximate base conversion
	unsigned int /*Mpj[MODULI_SET_SIZE],*/ Mpjr[MODULI_SET_SIZE], MpjInverse[MODULI_SET_SIZE], Mpji[MODULI_SET_SIZE][MODULI_SET_SIZE], MpInvR, Mpi[MODULI_SET_SIZE]; //Variables for precomutation of exact base conversion
	unsigned int Mir[MODULI_SET_SIZE], MInvR, Mj[MODULI_SET_SIZE+1]; // Variables to perform exact base conversion for the first base conversion in the final Montgomery pass
	unsigned int MInv[MODULI_SET_SIZE+1]; //Variables for precomutation of third step
	//unsigned int MsquareN = 12580; // Precomputed result needed for input to final pass of the Montgomery multiplication
	unsigned int MsqModN[MODULI_SET_SIZE*2+1]; // Variable for input to the final pass of the Montgomery multiplication
	unsigned int MI[MODULI_SET_SIZE][MODULI_SET_SIZE]; // Variable for MRS base conversion

	//unsigned int Result[MODULI_SET_SIZE*2+1]; // Results (on both bases) from a Montgomery pass
	unsigned int Final_Result[MODULI_SET_SIZE*2+1]; // Results (on both bases) from the final Montgomery pass
	int i, j;
	printf("Starting .....");



	/////////////Read 1024-bit input numbers from file/////////////////////////////

		// Read A from file
		FILE *aFile;
		char str[4];
		unsigned int sub_hex;
		unsigned int buffer_A[256], a_counter;
		i = 0;
		aFile = fopen ("AFile.txt","r+");
		if (aFile)
		{
			while ((str[0] = getc(aFile)) != EOF)
			{
				sscanf(str,"%x", &sub_hex);
				buffer_A[i] = sub_hex;
				i++;
				}

		}
		else
			printf("\nAA File Read Error!\n");

		a_counter = i-1;
		printf("\nA read complete.");
		fclose(aFile);

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



	/////////Read RNS look-up table from file////////////////////

	ifstream indata0; // indata is like cin
   unsigned int num, input[MODULI_SET_SIZE * 2 + 1][256];

	indata0.open("RNS.txt"); // opens the file
	if(!indata0) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

	indata0 >> num;
	for (i=0; (i <= (MODULI_SET_SIZE*2))&&(!indata0.eof()); i++ )
	{
		for(j=0; (j<=255)&&(!indata0.eof()); j++)
		{
			//cout << "The next number is " << num << endl;
			input[i][j]=num;
			indata0 >> num; // sets EOF flag if no value found

		}
	}

	indata0.close();
	printf("\nLook-up table read complete.");


	/////////Read modulus set from file////////////////////

	ifstream indata1; // indata is like cin
    unsigned int num1, input1[MODULI_SET_SIZE * 2 + 1];

	indata1.open("ModFile.txt"); // opens the file
	if(!indata1) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

	indata1 >> num1;
	for (i=0; (i <= (MODULI_SET_SIZE*2))&&(!indata1.eof()); i++ )
	{
			input1[i] = num1;
			indata1 >> num1; // sets EOF flag if no value found
	}

	indata1.close();
	printf("\nModulus file read complete.");
	/*printf("\n\nModulus set = ");
	for (i = 0; i<=(MODULI_SET_SIZE*2); i++)
	{
		printf("%u ", input1[i]);
	}*/


	/*/////////////Read 1024-bit input numbers from file/////////////////////////////

	// Read A from file
	FILE *aFile;
	char str[4];
	unsigned int sub_hex;
	unsigned int buffer_A[256], a_counter;
	i = 0;
	aFile = fopen ("AFile.txt","r");
	if (aFile)
	{
		while ((str[0] = getc(aFile)) != EOF)
		{
			sscanf(str,"%x", &sub_hex);
			buffer_A[i] = sub_hex;
			i++;
			}

	}
	else
		printf("\nFile Read Error!\n");

	a_counter = i-1;
	printf("\nA read complete.");
	fclose(aFile);

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
	fclose(nFile); */



	///////////Convert inputs to RNS////////////////////////

	// Initialize inputs

	for (i = 0; i <= MODULI_SET_SIZE*2; i++)
	{
		in_A[i] = 0;
		in_B[i] = 0;
		in_N[i] = 0;
	}


	// Conversion of A

	long long temp1, temp2, temp3;

	for (i = 0, j = a_counter; j>=0; i++, j--)
	{
		for (unsigned int k = 0; k <= MODULI_SET_SIZE*2; k++)
		{
			temp1 = (long long) buffer_A[j] * (long long)input[k][i];
			temp2 = (long long) in_A[k] + temp1;
			temp3 = temp2 % input1[k];
			in_A[k] = temp3;
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

	ifstream indata2; // indata is like cin
    unsigned int num2;

	indata2.open("MiInverse.txt"); // opens the file
	if(!indata2) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

	indata2 >> num2;
	for (i=0; (i <= (MODULI_SET_SIZE - 1))&&(!indata2.eof()); i++ )
	{
			MiInverse[i] = num2;
			indata2 >> num2; // sets EOF flag if no value found
	}

	indata2.close();
	printf("\nMiInverse file read complete.");






	// Precompute  |Mi| mj
	/*for (j = 0; j <= MODULI_SET_SIZE ; j++) // j = 6 because the redundant modulus also needs to be calculated here
	{
		for (i = 0; i<=MODULI_SET_SIZE-1; i++)
		{
			Mij[j][i] = Mi[i] % in_modulus[j+MODULI_SET_SIZE];
		}
	}*/

		ifstream indata3; // indata is like cin
    unsigned int num3;

	indata3.open("Mij.txt"); // opens the file
	if(!indata3) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

	indata3 >> num3;
	for (i = 0; (i <= (MODULI_SET_SIZE))&&(!indata3.eof()); i++ )
	{
		for(j = 0; (j <= MODULI_SET_SIZE - 1 )&&(!indata3.eof()); j++)
		{
			Mij[i][j]=num3;
			indata3 >> num3; // sets EOF flag if no value found
		}
	}

	indata3.close();
	printf("\nMij file read complete.");



	/////Precomputations for exact base conversion/////

	// Precompute Mpj, |Mpj|mr  and |Mpj^(-1)| mj

	/*for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	{
		Mpj[i] = MP / in_modulus[i+MODULI_SET_SIZE+1]; // Compute Mpj
		Mpjr[i] = Mpj[i] % in_modulus[MODULI_SET_SIZE];  // Compute |Mpj|mr
		MpjInverse[i] = ModularInverse(Mpj[i], in_modulus[i+MODULI_SET_SIZE+1]) % in_modulus[i+MODULI_SET_SIZE+1]; // |Mpj^(-1)| mj
	}*/

	ifstream indata4; // indata is like cin
    unsigned int num4;

	indata4.open("Mpjr.txt"); // opens the file
	if(!indata4) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

	indata4 >> num4;
	for (i=0; (i <= (MODULI_SET_SIZE - 1))&&(!indata4.eof()); i++ )
	{
			Mpjr[i] = num4;
			indata4 >> num4; // sets EOF flag if no value found
	}

	indata4.close();
	printf("\nMpjr file read complete.");

	ifstream indata5; // indata is like cin
    unsigned int num5;

	indata5.open("MpjInverse.txt"); // opens the file
	if(!indata5) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

	indata5 >> num5;
	for (i=0; (i <= (MODULI_SET_SIZE - 1))&&(!indata5.eof()); i++ )
	{
			MpjInverse[i] = num5;
			indata5 >> num5; // sets EOF flag if no value found
	}

	indata5.close();
	printf("\nMpjInverse file read complete.");



	//Precompute |Mp(^-1)|mr

	/*MpInvR = ModularInverse(MP, in_modulus[MODULI_SET_SIZE]);*/

	ifstream indata6; // indata is like cin
    unsigned int num6;

	indata6.open("MpInvR.txt"); // opens the file
	if(!indata6) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

	indata6 >> num6;
	while(!indata6.eof())
	{
			MpInvR = num6;
			indata6 >> num6; // sets EOF flag if no value found
	}

	indata6.close();
	printf("\nMpInvR file read complete.");


	// Precompute  |Mpj| mi
	/*for (i = 0; i <= MODULI_SET_SIZE-1 ; i++)
	{
		for (j = 0; j<=MODULI_SET_SIZE-1; j++)
		{
			Mpji[i][j] = Mpj[j] % in_modulus[i];
		}
	} */

	ifstream indata7; // indata is like cin
    unsigned int num7;

	indata7.open("Mpji.txt"); // opens the file
	if(!indata7) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

	indata7 >> num7;
	for (i = 0; (i <= (MODULI_SET_SIZE - 1))&&(!indata7.eof()); i++ )
	{
		for(j = 0; (j <= MODULI_SET_SIZE - 1 )&&(!indata7.eof()); j++)
		{
			Mpji[i][j]=num7;
			indata7 >> num7; // sets EOF flag if no value found
		}
	}

	indata7.close();
	printf("\nMpji file read complete.");




	///Extra precomputation needed to perform exact base conversion for the first base conversion in the final Montgomery pass
	// Precompute |Mi|mr

	/*for (i = 0; i <= MODULI_SET_SIZE-1; i++)
	{
		Mir[i] = Mi[i] % in_modulus[MODULI_SET_SIZE];
	}*/

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

	/*MInvR = ModularInverse(M, in_modulus[MODULI_SET_SIZE]);*/

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




	/////Precomputations for third step/////


	//Precompute M^(-1)

	/*for (i = 0; i <= MODULI_SET_SIZE; i++)
	{
		MInv[i] = ModularInverse(M, in_modulus[i+MODULI_SET_SIZE]);
	}*/

	ifstream indata10; // indata is like cin
    unsigned int num10;

	indata10.open("MInv.txt"); // opens the file
	if(!indata10) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

	indata10 >> num10;
	for (i=0; (i <= (MODULI_SET_SIZE))&&(!indata10.eof()); i++ )
	{
			MInv[i] = num10;
			indata10 >> num10; // sets EOF flag if no value found
	}

	indata10.close();
	printf("\nMInv file read complete.");




	/*//////////////////////Perform first pass of Montgomery multiplication ///////////////

	MM(in_A, in_B, in_N, in_modulus, &M, &MP, Mi, MiInverse, Mij, Mpj, Mpjr, MpjInverse, Mpji, &MpInvR, MInv, Result);*/




	////////////////////// Precompute M^2 mod N  ////////////////////////////////////////

	/*for (i =0; i <= MODULI_SET_SIZE*2; i++)
	{
		MsqModN[i] = MsquareN % in_modulus[i];
	}*/

	ifstream indata11; // indata is like cin
    unsigned int num11;

	indata11.open("MsqModN.txt"); // opens the file
	if(!indata11) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

	indata11 >> num11;
	for (i=0; (i <= (MODULI_SET_SIZE * 2))&&(!indata11.eof()); i++ )
	{
			MsqModN[i] = num11;
			indata11 >> num11; // sets EOF flag if no value found
	}

	indata11.close();
	printf("\nMsqModN file read complete.");

	////////////////////// Precompute MP mod mi  ////////////////////////////////////////

		ifstream indata12; // indata is like cin
    unsigned int num12;

	indata12.open("Mpi.txt"); // opens the file
	if(!indata12) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

	indata12 >> num12;
	for (i=0; (i <= (MODULI_SET_SIZE - 1))&&(!indata12.eof()); i++ )
	{
			Mpi[i] = num12;
			indata12 >> num12; // sets EOF flag if no value found
	}

	indata12.close();
	printf("\nMpi file read complete.");


	////////////////////// Precompute M mod mj  ////////////////////////////////////////

		ifstream indata13; // indata is like cin
    unsigned int num13;

	indata13.open("Mj.txt"); // opens the file
	if(!indata13) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

	indata13 >> num13;
	for (i=0; (i <= (MODULI_SET_SIZE))&&(!indata13.eof()); i++ )
	{
			Mj[i] = num13;
			indata13 >> num13; // sets EOF flag if no value found
	}

	indata13.close();
	printf("\nMj file read complete.");


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




	/*//////////////////////Perform final pass of Montgomery multiplication ///////////////

	printf(" \n\n\n\nSecoond pass starting .....");

	MMlast(MsqModN, Result, in_N, in_modulus, &M, &MP, Mi, Mir, MiInverse, Mij, &MInvR, Mpj, Mpjr, MpjInverse, Mpji, &MpInvR, MInv, Final_Result);*/

	//////////////////////Perform Montgomery Exponentiation ///////////////

	printf(" \n\n\n\nExponentiation starting .....");

	Exp(in_A, /*in_B,*/ in_N, MsqModN, input1, Mpi, Mj, /*Mi, Mir,*/ MiInverse, Mij, /*&MInvR, Mpj,*/ Mpjr, MpjInverse, Mpji, &MpInvR, MInv, /*MI,*/ Final_Result);


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
	printf("\n\n\nStep1 [Q <- ( -A * B) * N^(-1)] complete.");
	printf("\n\nQ[] = ");
	for (i = 0; i<=MODULI_SET_SIZE-1; i++)
	{
		printf("%u ", Q[i]);
	}

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

	printf("\n\n\nStep3 [Rp <- (A * B + Qp * N) * M^(-1)] complete.");
	printf("\n\nRp[] = ");
	for (i = 0; i<=MODULI_SET_SIZE; i++)
	{
		printf("%u ", Rp[i]);
	}

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


	printf("\n\n\nStep4 [second base conversion] complete.");
	printf("\n\nR[] = ");
	for (i = 0; i<=MODULI_SET_SIZE-1; i++)
	{
		printf("%u ", R[i]);
	}


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


	printf("\n\n\nStep2 [first base conversion] complete.");
	printf("\n\nQp[] = ");
	for (i = 0; i<=MODULI_SET_SIZE; i++)
	{
		printf("%u ", Qp[i]);
	}

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

	printf("\n\n\n----------------------------------------------------------------");
	printf("\n\nFinal exponentiation result: ");
	for (i = 0; i <= 2*MODULI_SET_SIZE; i++) printf("%u, ", Result[i]);
	printf("\n\n----------------------------------------------------------------");


	return 0;

}