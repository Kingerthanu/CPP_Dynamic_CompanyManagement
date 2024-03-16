#ifndef IDIFFICULTYCURVE_H
#define IDIFFICULTYCURVE_H

/*
    Invariant:
        1.)   Calculated cost will be clamped to 0.0f if negative.
*/
class IDifficultyCurve
{

    public:
        /*
            Preconditions:
                1.)  baseCost is expected to be a positive number.
        */
        virtual float CalculateCost(float baseCost, unsigned int taskDifficulty = 0, unsigned int employeeProficiency = 0) = 0;

};

#endif