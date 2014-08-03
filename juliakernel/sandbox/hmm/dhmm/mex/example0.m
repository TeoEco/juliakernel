%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Test the functionality of the mex implementation
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



% Compile the mex files...

mex -I.. dhmm_bw.cpp ../dhmm.cpp
mex -I.. dhmm_forward.cpp ../dhmm.cpp
mex -I.. dhmm_bw_mt.cpp ../dhmm.cpp


% Test the mex files


% Load a test dataset
load dataset


% Initialize the HMM parameters - starting values
% Starting probabilities, 2 states
prior0=[.5;
        .5 ];
% Transition probabilities
transmat0=[  0.5 0.5;
            0.7 0.3 ];
% Observation probabilities
obsmat0=[.33 .33 .33;
        .33 .33 .33];
    
    
fprintf(1,'Parameters before training\n');
prior0
transmat0
obsmat0

fprintf(1,'Train the HMM model\n');
    
[ll,prior,transmat,obsmat] = dhmm_bw(dataset{2}, prior0,transmat0,obsmat0);

fprintf(1,'Parameters after training\n');
prior
transmat
obsmat



fprintf(1,'Try the forward\n');
for i=1:4
    v = dataset{2}{i};
    ll = dhmm_forward(v, prior, transmat, obsmat);
    
    fprintf(1,'Instance %d  log likelihood: %f\n',i,ll,ll);
end
fprintf(1,'\n');




