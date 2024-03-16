#ifndef LINEAR_DIFFICULTYCURVE_H
#define LINEAR_DIFFICULTYCURVE_H

#include "difficultycurve.h"

class LinearDifficultyCurve : public IDifficultyCurve
{
    public:
        float CalculateCost(float baseCost, unsigned int taskDifficulty, unsigned int employeeProficiency)  override;
};

#endif