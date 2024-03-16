#include "randomized_difficultycurve.h"

RandomizedDifficultyCurve::RandomizedDifficultyCurve(){

    // Setup generator with random seeding
    this->gen = std::mt19937((std::random_device())());

}

RandomizedDifficultyCurve::RandomizedDifficultyCurve(const unsigned int& seed)
{

    // Setup generator with given seed
    this->gen = std::mt19937(seed);

}

float RandomizedDifficultyCurve::CalculateCost(float baseCost, unsigned int taskDifficulty, unsigned int employeeProficiency)
{

    int randomFactor = this->rangeRNG(this->gen);

    // Random formula where we 150% our proficiency and see difference scaled by a multiple.
    float result = baseCost + ((int)(((taskDifficulty)) - (employeeProficiency * 1.5f)) * randomFactor);

    // If below 0, clamp.
    if (result < 0.0f)
    {

        return 0.0f;

    }

    return result;
}