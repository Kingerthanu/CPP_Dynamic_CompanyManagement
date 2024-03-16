#ifndef ADJUSTED_DIFFICULTYCURVE_H
#define ADJUSTED_DIFFICULTYCURVE_H

#include "linear_difficultycurve.h"

/*
    Invariant:
        1.)  Curve multiple will not change during lifetime
*/
class AdjustedDifficultyCurve : public IDifficultyCurve
{
    private:
        // Contain Linear Curve member.
        LinearDifficultyCurve linearCurve = LinearDifficultyCurve();

        // Hold our constant multiple to curve a linear curve by
        const float multiple;

    public:
        /*
            Preconditions:
                1.)  curveMultiple is positive.
            Postconditions:
                1.)  Multiple of linear curve will be set to argument.
                2.)  No multiple supplied, default to 1.0f
        */
        AdjustedDifficultyCurve(float curveMultiple = 1.0f);

        /*
            Preconditions:
                1.)  Doesn't guarantee handling of overflow or underflow with a excessive multiple
        */
        float CalculateCost(float baseCost, unsigned int taskDifficulty, unsigned int employeeProficiency) override;

};


#endif