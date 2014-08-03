/*
	MEX wrapper to use C++ DHMM under Matlab
	
	(c) Daniel Roggen, 2008
	
	
*/

#include <mex.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "dhmm.h"

#define printf mexPrintf


void Syntax()
{
	printf("dhmm_bw: discrete HMM based on C++ implementation\n");
	printf("by Daniel Roggen\n\n");
	printf("Syntax: \n");
	printf("   [ll,prior,transmat,obsmat] = dhmm_bw(dataset,prior0,transmat0,obsmat0 [,iterations]);\n");
	printf("\n");
	printf("   dataset:    1xN cell array with training instances.\n");
	printf("               Training instances are 1xL matrix with L symbols (1-based)\n");
	printf("   prior0:     initial prior probabilies\n");
	printf("   transmat0:  initial transition probabilies\n");
	printf("   obsmat0:    initial observation probabilies\n");
	printf("   iterations: optional number of iterations, by default 3 iterations\n");
	printf(" Returns:\n");
	printf("   ll:         log-likelihood\n");
	printf("   prior:      re-estimated prior probabilities\n");
	printf("   transmat:   re-estimated transition probabilities\n");
	printf("   obsmat:     re-estimated observation probabilities\n");
	
}
void Error()
{
   printf("dhmm_bw: Invalid parameters\n");
}


// Input:
//    prhs[0]: 1xN cell array of 1xL observations
//    prhs[1]: Sx1 matrix with priors for S states
//    prhs[2]: SxS matrix with transition probabilities
//    prhs[3]: SxO matrix with observation probabilities
//    prhs[4]: Scalar with number of iterations
//    S: number of states
//    O: number of observations
// Output:
//    plhs[0]: 1xIteration matrix with log likelihood
//		plhs[1]: 1xS matrix with re-estimated priors
//    plhs[2]: SxS matrix with re-estimated transition probabilities
//    plhs[3]: SxO matrix with re-estimated observation probabilities
void mexFunction( int nlhs, mxArray *plhs[],int nrhs, const mxArray *prhs[] )
{
	int S,O,N,Iterations;
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
	if(nrhs==4)
		Iterations=3;
	else
	{
		Iterations = mxGetScalar(prhs[4]);
	}
	
	// Find the number of states and observation and sequences from the PI and B.
	S = mxGetM(prhs[1]);
	O = mxGetN(prhs[3]);
	N = mxGetN(prhs[0]);
	
	//printf("N: %d\n",N);
	
	// Create the HMM
	DHMM *hmm=new DHMM(S,O);

	
	// Set the starting probabilities
	t = mxGetPr(prhs[1]);
	for(i=0;i<S;i++)
		hmm->StartingStateProbabilities[i]=t[i];
	
	// Set the transition probabilites
	t = mxGetPr(prhs[2]);
	for(j=0;j<S;j++)		// to state
	{
		for(i=0;i<S;i++)	// from state
		{
			hmm->operator[](i).SetTransitionProbability(j,*t++);
		}
	}
	
	// Set the observation probabilites
	t = mxGetPr(prhs[3]);
	for(j=0;j<O;j++)
	{
		for(i=0;i<S;i++)
		{
			hmm->operator[](i).SetObservationProbability(j,*t++);
		}
	}
	
	//hmm->Print();
	
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
	
	// Run the Baum-Welch
	vector<double> LL = hmm->BaumWelch(obs,Iterations);
	
	//hmm->Print();
	
	// Create the return variables
	plhs[0] = mxCreateDoubleMatrix(1,Iterations,mxREAL);
	plhs[1] = mxCreateDoubleMatrix(S,1,mxREAL);
	plhs[2] = mxCreateDoubleMatrix(S,S,mxREAL);
	plhs[3] = mxCreateDoubleMatrix(S,O,mxREAL);
	
	// Get the LL
	t = mxGetPr(plhs[0]);
	for(i=0;i<Iterations;i++)
		t[i] = LL[i];
		
			
	// Get the starting probabilities
	t = mxGetPr(plhs[1]);
	for(i=0;i<S;i++)
		t[i] = hmm->StartingStateProbabilities[i];
	
	// Get the transition probabilites
	t = mxGetPr(plhs[2]);
	for(j=0;j<S;j++)		// to state
	{
		for(i=0;i<S;i++)	// from state
		{
			*t++ = hmm->operator[](i).TransitionProbability[j];
		}
	}
	
	// Set the observation probabilites
	t = mxGetPr(plhs[3]);
	for(j=0;j<O;j++)
	{
		for(i=0;i<S;i++)
		{
			*t++ = hmm->operator[](i).ObservationProbability[j];
		}
	}
		
	
	
	delete hmm;
}



