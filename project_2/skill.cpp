#include "skill.h"


std::string Skill::getName()
{

    return this->name;

}

std::shared_ptr<IDifficultyCurve> Skill::getCurve()
{

    return this->difficultyCurve;

}

unsigned int Skill::getLevel()
{

    return this->level;

}

void Skill::setLevel(const unsigned int& newLevel)
{

    this->level = newLevel;

}

std::string Skill::getDescription()
{

    return this->description;

}


Skill::Skill(const std::string& name, const std::string& description, const unsigned int& skillLevel, std::shared_ptr<IDifficultyCurve> skillCurve) :
    name(name), description(description)
{

    this->level = skillLevel;
    this->difficultyCurve = skillCurve;

}


Skill::Skill(const Skill& toCopy) : name(toCopy.name), description(toCopy.description)
{

    this->level = toCopy.level;

    // Don't need to deep-copy over our interface
    this->difficultyCurve = toCopy.difficultyCurve;


}


Skill& Skill::operator=(const Skill& toCopy)
{

    if (this == &toCopy) {

        return *this;

    }

    this->name = toCopy.name;
    this->description = toCopy.description;
    this->level = toCopy.level;

    // Share curve (interface so no need to deep-copy).
    this->difficultyCurve = toCopy.difficultyCurve;

    return *this;

}


bool Skill::operator==(const Skill& otherSkill)
{
    // Check literal equivalence
    return this == &otherSkill;

};

bool Skill::operator!=(const Skill& otherSkill)
{

    // Check literal equivalence
    return this != &otherSkill;

};