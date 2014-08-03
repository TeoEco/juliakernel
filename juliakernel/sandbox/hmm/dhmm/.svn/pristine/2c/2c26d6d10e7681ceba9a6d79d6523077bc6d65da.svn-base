/*
	MEX wrapper to use C++ DHMM under Matlab
	
	Multithreaded version
	
	(c) Daniel Roggen, 2008-2009
	
*/

#include <mex.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>
#include <process.h>

#include "dhmm.h"

#define printf mexPrintf

struct Data
{
	int M; 						
	int N;						
	int S,O,Iterations;
	const mxArray **prhs;
	mxArray **plhs;
	int m;
	vector<Observation> *obs;
	HANDLE handle;
};

unsigned __stdcall ThreadBW(void *d)
{
	double *t;
	int i,j;
	Data *data=(Data*)d;
	
	// Create the HMM
	DHMM *hmm=new DHMM(data->S,data->O);

	
	// Set the starting probabilities
	t = mxGetPr(mxGetCell(data->prhs[1],data->m));
	for(i=0;i<data->S;i++)
		hmm->StartingStateProbabilities[i]=t[i];
	
	// Set the transition probabilites
	t = mxGetPr(mxGetCell(data->prhs[2],data->m));
	for(j=0;j<data->S;j++)		// to state
	{
		for(i=0;i<data->S;i++)	// from state
		{
			hmm->operator[](i).SetTransitionProbability(j,*t++);
		}
	}
	
	// Set the observation probabilites
	t = mxGetPr(mxGetCell(data->prhs[3],data->m));
	for(j=0;j<data->O;j++)
	{
		for(i=0;i<data->S;i++)
		{
			hmm->operator[](i).SetObservationProbability(j,*t++);
		}
	}
	
	//hmm->Print();
	
	
	
	// Run the Baum-Welch
	vector<double> LL = hmm->BaumWelch(*data->obs,data->Iterations);
	
	//hmm->Print();
	

	// Get the LL
	t = mxGetPr(mxGetCell(data->plhs[0],data->m));
	for(i=0;i<data->Iterations;i++)
		t[i] = LL[i];
			
	// Get the starting probabilities
	t = mxGetPr(mxGetCell(data->plhs[1],data->m));
	for(i=0;i<data->S;i++)
		t[i] = hmm->StartingStateProbabilities[i];
	
	// Get the transition probabilites
	t = mxGetPr(mxGetCell(data->plhs[2],data->m));
	for(j=0;j<data->S;j++)		// to state
	{
		for(i=0;i<data->S;i++)	// from state
		{
			*t++ = hmm->operator[](i).TransitionProbability[j];
		}
	}
	
	// Set the observation probabilites
	t = mxGetPr(mxGetCell(data->plhs[3],data->m));
	for(j=0;j<data->O;j++)
	{
		for(i=0;i<data->S;i++)
		{
			*t++ = hmm->operator[](i).ObservationProbability[j];
		}
	}
	
	delete hmm;	

	return 0;	
}

void Syntax()
{
	printf("dhmm_bw_mt: discrete HMM based on C++ implementation\n");
	printf("            Multithreaded implementation\n");
	printf("by Daniel Roggen\n\n");
	printf("Syntax: \n");
	printf("   [ll,prior,transmat,obsmat] = dhmm_bw(dataset,prior0,transmat0,obsmat0,iterations);\n");
	printf("\n");
	printf("   dataset:    1XM cell of 1xN cell array with training instances.\n");
	printf("               Training instances are 1xL matrix with L symbols (1-based)\n");
	printf("   prior0:     1XM cell of Sx1 matrix of initial prior probabilies\n");
	printf("   transmat0:  1XM cell of SxS matrix of initial transition probabilies\n");
	printf("   obsmat0:    1XM cell of SxO matrix of initial observation probabilies\n");
	printf("   iterations: optional number of iterations, by default 3 iterations\n");
	printf(" Returns:\n");
	printf("   ll:         1XM cell of log-likelihood\n");
	printf("   prior:      1XM cell of re-estimated prior probabilities\n");
	printf("   transmat:   1XM cell of re-estimated transition probabilities\n");
	printf("   obsmat:     1XM cell of re-estimated observation probabilities\n");
	printf("dhmm_bw_mt reestimates the HMM parameters using Baum-Welch from the M specific initial HMMs\n");
	printf("and returns M reestimated parameters\n");
}
void Error()
{
   printf("dhmm_bw: Invalid parameters\n");
}


// Input:
//    prhs[0]: 1xN cell array of 1xL observations
//    prhs[1]: 1xM cell Sx1 matrix with priors for S states
//    prhs[2]: 1xM cell SxS matrix with transition probabilities
//    prhs[3]: 1xM cell SxO matrix with observation probabilities
//    prhs[4]: Scalar with number of iterations
//    S: number of states
//    O: number of observations
// Output:
//    plhs[0]: 1xM cell 1xIteration matrix with log likelihood
//		plhs[1]: 1xM cell 1xS matrix with re-estimated priors
//    plhs[2]: 1xM cell SxS matrix with re-estimated transition probabilities
//    plhs[3]: 1xM cell SxO matrix with re-estimated observation probabilities
void mexFunction( int nlhs, mxArray *plhs[],int nrhs, const mxArray *prhs[] )
{
	int M; 						// Number of initial HMMs for MT implementation
	int N;						// Number of training instances
	int S,O,Iterations;
	int i,j;
	double v1,v2;
	double r;
	double *t;
	
	
	//printf("nrhs: %d. nlhs: %d\n",nrhs,nlhs);
	// Check in/out args
	if((nrhs!=4 && nrhs!=5) || nlhs!=4 )
	{
		Error();
		Syntax();
		return;
	}
	// Checks that the size of the cells
	M = mxGetN(prhs[1]);

	if(M<1 || mxGetN(prhs[2])!=M || mxGetN(prhs[2])!=M)
	{
		Error();
		Syntax();
		return;
	}
	
	if(nrhs==4)
		Iterations=3;
	else
	{
		Iterations = mxGetScalar(prhs[4]);
	}
	
	
	
	// Find the number of states and observation and sequences from the PI and B.
	mxArray *tmp;
	tmp = mxGetCell(prhs[1],0);
	S = mxGetM(tmp);
	tmp = mxGetCell(prhs[3],0);
	O = mxGetN(tmp);
	// Find the number of training instances	
	N = mxGetN(prhs[0]);
	
	//printf("S: %d O: %d N: %d\n",S,O,N);
	
	
	// Convert the observations to the HMM format.
	vector<Observation> obs(N);
	for(i=0;i<N;i++)
	{
		mxArray *sequence = mxGetCell(prhs[0],i);
		int L = mxGetN(sequence);
		t = mxGetPr(sequence);
		obs[i].resize(L,0);
		for(j=0;j<L;j++)
		{
			obs[i][j] = (*t++)-1;		// Correct for 1-based of matlab, 0-based of C
		}
	}	
	
	
	// Create the return variables
	// Create return cells
	plhs[0] = mxCreateCellMatrix(1,M);			// LL
	plhs[1] = mxCreateCellMatrix(1,M);			// Prior
	plhs[2] = mxCreateCellMatrix(1,M);			// Trans
	plhs[3] = mxCreateCellMatrix(1,M);			// Obs
	// Fill return cells with matrices
	for(i=0;i<M;i++)
	{
		mxSetCell(plhs[0],i,mxCreateDoubleMatrix(1,Iterations,mxREAL));
		mxSetCell(plhs[1],i,mxCreateDoubleMatrix(S,1,mxREAL));
		mxSetCell(plhs[2],i,mxCreateDoubleMatrix(S,S,mxREAL));
		mxSetCell(plhs[3],i,mxCreateDoubleMatrix(S,O,mxREAL));
	}
	
	
	vector<Data> data(M);
	// Initialize the thread data
	for(int m=0;m<M;m++)
	{
		data[m].M = M;
		data[m].N = N;
		data[m].S = S;
		data[m].O = O;
		data[m].Iterations = Iterations;
		data[m].prhs = prhs;
		data[m].plhs = plhs;
		data[m].m = m;
		data[m].obs = &obs;
	}

	// Launch the threads	
	for(int m=0;m<M;m++)
	{
		unsigned id;
		data[m].handle = (HANDLE)_beginthreadex( NULL, 0, &ThreadBW, (void*)&data[m], 0, &id );
		//printf("Created thread ID %d handle %d\n",id,data[m].handle);
	}
	// Wait for thread end
	for(int m=0;m<M;m++)
	{
		WaitForSingleObject( data[m].handle, INFINITE );
		//printf("Thread %d done\n",data[m].handle);
	}
		
	
	
	
}



