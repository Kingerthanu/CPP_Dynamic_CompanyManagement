#ifndef RANDOMIZED_DIFFICULTYCURVE_H
#define RANDOMIZED_DIFFICULTYCURVE_H

#include <random>
#include "difficultycurve.h"

/*
    Invariant:
        1.)   Random generator will be constant for lifetime after initialization
*/
class RandomizedDifficultyCurve : public IDifficultyCurve
{

    private:
        std::mt19937 gen; // Random number generator
        std::uniform_int_distribution<int> rangeRNG = std::uniform_int_distribution<int>(2, 15);    // Random number distribution (gives vals)
        
    public:
        RandomizedDifficultyCurve();
        RandomizedDifficultyCurve(const unsigned int& seed);
        float CalculateCost(float baseCost, unsigned int taskDifficulty, unsigned int employeeProficiency) override;
};

#endif
