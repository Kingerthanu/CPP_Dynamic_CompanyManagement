#include "linear_difficultycurve.h"

float LinearDifficultyCurve::CalculateCost(float baseCost, unsigned int taskDifficulty, unsigned int employeeProficiency)
{

    float result = baseCost + (int)(taskDifficulty - employeeProficiency);

    // If below 0, clamp.
    if (result < 0.0f)
    {

        return 0.0f;

    }

    return result;
}