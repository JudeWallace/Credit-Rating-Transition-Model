#ifndef MARKOVCHAIN_H
#define MARKOVCHAIN_H

#include <vector>
#include <string>

class markovChain {
    private:
        std::vector<std::vector<double>> transitionMatrix;
        std::vector<std::string> states;
    public:
        markovChain();
        void setTransitionMatrix(const std::vector<std::vector<double>>& matrix);
        void setStates(const std::vector<std::string>& stateNames);
        std::vector<double> estimateProbabilities(int periods, int initialState);
        void printProbabilities(const std::vector<double>& probabilities);
};
#endif