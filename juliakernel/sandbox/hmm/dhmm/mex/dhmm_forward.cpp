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
	printf("dhmm_forward: discrete HMM based on C++ implementation\n");
	printf("by Daniel Roggen\n\n");
	printf("Syntax: \n");
	printf("   ll = dhmm_forward(dataset,prior0,transmat0,obsmat0);\n");
	printf("\n");
	printf("   dataset:    1xL matrix with the data sequence\n");
	printf("   prior0:     initial prior probabilies\n");
	printf("   transmat0:  initial transition probabilies\n");
	printf("   obsmat0:    initial observation probabilies\n");
	printf("   iterations: optional number of iterations, by default 3 iterations\n");
	printf(" Returns:\n");
	printf("   ll:         log-likelihood\n");	
}
void Error()
{
   printf("dhmm_forward: Invalid parameters\n");
}


// Input:
//    prhs[0]: 1xN cell array of 1xL observations
//    prhs[1]: Sx1 matrix with priors for S states
//    prhs[2]: SxS matrix with transition probabilities
//    prhs[3]: SxO matrix with observation probabilities
//    S: number of states
//    O: number of observations
// Output:
//    plhs[0]: log likelihood

void mexFunction(int nlhs, mxArray *plhs[],int nrhs, const mxArray *prhs[])
{
	int S,O,Iterations;
	int i,j;
	double v1,v2;
	double r;
	double *t;
	
	
	//printf("nrhs: %d. nlhs: %d\n",nrhs,nlhs);
	// Check in/out args
	if((nrhs!=4) || nlhs!=1 )
	{
		Error();
		Syntax();
		return;
	}
	
	
	
	// Find the number of states and observation and sequences from the PI and B.
	S = mxGetM(prhs[1]);
	O = mxGetN(prhs[3]);
	
	//printf("S: %d O: %d\n",S,O);
	
	
	
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
	
	hmm->Print();
	
	
	// Convert the observations to the HMM format.
	Observation obs;

	t = mxGetPr(prhs[0]);
	int L = mxGetN(prhs[0]);
	obs.resize(L,0);
	for(j=0;j<L;j++)
		obs[j] = (*t++)-1;		// Correct for 1-based of matlab, 0-based of C
	

	
	double p = hmm->GetObservationSequenceProbabilityL(obs);
	
	// Create the return variables
	plhs[0] = mxCreateScalarDouble(p);

	delete hmm;
}



