#include "markovchain.h"
#include <iostream>

markovChain::markovChain(){
    states = {"AAA", "BB", "D"};
    transitionMatrix = {{0.9, 0.08, 0.02}, {0.30,0.6,0.1}, {0.0,0.0,1.0}};
}

void markovChain::setTransitionMatrix(const std::vector<std::vector<double>>& matrix){
    transitionMatrix = matrix;
}

void markovChain::setStates(const std::vector<std::string>& stateNames){
    states = stateNames;
}

std::vector<double> markovChain::estimateProbabilities(int periods, int initialState){
    std::vector<double> stateProbabilities(3, 0.0);
    stateProbabilities[initialState] = 1.0;

    for(int i = 0; i < periods; i++){
        std::vector<double> probabilityOutputVector(3, 0.0);
        for(int c = 0; c < 3; c++){ 
            for(int r =0; r <3; r++){
                probabilityOutputVector[c] += stateProbabilities[r] * transitionMatrix[r][c];
            }
        } 
        stateProbabilities = probabilityOutputVector;
    }

    return stateProbabilities;
}

void markovChain::printProbabilities(const std::vector<double>& probabilities){
    for(int i = 0; i < probabilities.size(); i++){
        std::cout << states[i] << " -> " << probabilities[i] << std::endl;
    }
}
