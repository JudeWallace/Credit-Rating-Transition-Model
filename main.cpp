#include "markovchain.h"

int main(){
    markovChain MC;
    
    int initialState = 1;
    int periods = 5;

    std::vector<double> probabilitiesVector = MC.estimateProbabilities(periods, initialState);
    MC.printProbabilities(probabilitiesVector);
}