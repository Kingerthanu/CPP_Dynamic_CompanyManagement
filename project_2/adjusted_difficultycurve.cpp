#include "adjusted_difficultycurve.h"

AdjustedDifficultyCurve::AdjustedDifficultyCurve(float curveMultiple) : multiple(curveMultiple)
{
    // ...
}

float AdjustedDifficultyCurve::CalculateCost(float baseCost, unsigned int taskDifficulty, unsigned int employeeProficiency)
{

    // Use LinearDifficultyCurve's CalculateCost and adjust the cost (relying on linear supplying positive calculation)
    float adjustedCost = linearCurve.CalculateCost(baseCost, taskDifficulty, employeeProficiency) * this->multiple;
    return adjustedCost;

}