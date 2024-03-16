#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <memory>

// Pack together curves when importing skill
#include "randomized_difficultycurve.h"
#include "adjusted_difficultycurve.h"
#include "linear_difficultycurve.h"


/*
    Invariant:
        1.)  Name and description of a skill are const. through lifetime.
        2.)  Uniqueness is defined by name only.
*/
class Skill
{
    
    private:
        std::string name;
        std::string description;
        unsigned int level;
        std::shared_ptr<IDifficultyCurve> difficultyCurve;

    public:
        /*
            Precondition:
                1.) Checks literal equivalence.
        */
        bool operator==(const Skill& otherSkill);

        /*
            Precondition:
                1.) Checks literal equivalence.
        */
        bool operator!=(const Skill& otherSkill);

        std::string getName();
        std::shared_ptr<IDifficultyCurve> getCurve();

        unsigned int getLevel();

        // Allow free-reign to set level for either task or employee now as expressed through rubric.
        void setLevel(const unsigned int& newLevel);

        std::string getDescription();

        Skill(const std::string& name, const std::string& description, const unsigned int& skillLevel = 0, std::shared_ptr<IDifficultyCurve> skillCurve = std::make_shared<LinearDifficultyCurve>());

        Skill(const Skill& toCopy);
        Skill& operator=(const Skill& toCopy);



};

#endif