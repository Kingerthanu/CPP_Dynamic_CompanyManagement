#include "skillset.h"
#include <iostream>

bool SkillSet::add(std::unique_ptr<Skill>& newSkill)
{
    // Check for duplicates
    for (unsigned int i = 0; i < this->skillsSize; i++) {

        if ((this->skills[i]->getName() == newSkill->getName())) {
            // If duplicate (based upon uniqueness identifier of name)
            return false;
        }

    }

    // Create new array with one extra slot
    auto tmp = std::make_unique<std::unique_ptr<Skill>[]>(this->skillsSize + 1);

    // Move existing skills into new array
    for (unsigned int i = 0; i < this->skillsSize; i++) {

        tmp[i] = std::move(this->skills[i]);

    }

    // Move new skill into the last slot
    tmp[this->skillsSize++] = std::move(newSkill);

    // Replace skills array with new array
    this->skills = std::move(tmp);

    return true;
}

void SkillSet::remove(const std::string& nameToFind)
{
    std::unique_ptr<std::unique_ptr<Skill>[]> handler = std::make_unique<std::unique_ptr<Skill>[]>(this->skillsSize - 1);
    
    unsigned int handleI = 0;
    for (unsigned int i = 0; i < this->skillsSize; i++) {

        if (!((this->skills[i]->getName() == nameToFind))) {

            handler[handleI++] = std::move(this->skills[i]);

        }
    }

    this->skillsSize--;
    this->skills = std::move(handler);
}

bool SkillSet::change(const std::string& nameToFind, const unsigned int& newLevel)
{
    for (unsigned int i = 0; i < this->skillsSize; i++) {

        if ((this->skills[i]->getName() == nameToFind)) {

            this->skills[i]->setLevel(newLevel);
            return true;

        }
    }
    return false;
}

bool SkillSet::contains(const std::string& nameToFind)
{

    for (unsigned int i = 0; i < this->skillsSize; i++) {

        if ((this->skills[i]->getName() == nameToFind)) {

            return true;

        }
    }
    return false;

}

unsigned int SkillSet::findLevel(const std::string& nameToFind)
{
    for (unsigned int i = 0; i < this->skillsSize; i++) {

        if ((this->skills[i]->getName() == nameToFind)) {

            return this->skills[i]->getLevel();

        }
    }
    return 0; // Indicate skill not found / if skill is not known, have 0 prof/difficulty in it
}

SkillSet::SkillSet(std::unique_ptr<std::unique_ptr<Skill>[]> givenSkills, const unsigned int skillsAmount)
{

    this->skillsSize = skillsAmount;
    this->skills = std::move(givenSkills);

}

SkillSet::~SkillSet()
{
    // Automatically managed by std::unique_ptr
}

const std::unique_ptr<std::unique_ptr<Skill>[]>& SkillSet::getSkills()
{

    return this->skills;

}

unsigned int SkillSet::getSkillSize()
{
    return this->skillsSize;
}

SkillSet::SkillSet(const SkillSet& toCopy)
{

    this->skillsSize = toCopy.skillsSize;
    this->skills = std::make_unique<std::unique_ptr<Skill>[]>(this->skillsSize);

    for (unsigned int i = 0; i < this->skillsSize; i++) {

        this->skills[i] = std::make_unique<Skill>(*toCopy.skills[i]);

    }

}

SkillSet& SkillSet::operator=(SkillSet&& toCut) noexcept {

    if (this == &toCut) {  // Check for self-assignment
        return *this;
    }

    // Transfer ownership of resources from 'other' to 'this'
    this->skillsSize = toCut.skillsSize;
    this->skills = std::move(toCut.skills);

    // Reset 'other' to a valid state
    toCut.skillsSize = 0;
    toCut.skills.reset();

    return *this;
}

SkillSet& SkillSet::operator=(SkillSet& toCopy) 
{

    if (this == &toCopy) {

        return *this;

    }

    this->skillsSize = toCopy.skillsSize;

    this->skills = std::make_unique<std::unique_ptr<Skill>[]>(this->skillsSize);

    for (unsigned int i = 0; i < this->skillsSize; i++) {

        this->skills[i] = std::make_unique<Skill>(*toCopy.skills[i]);

    }

    return *this;

}

bool SkillSet::operator==(const SkillSet& rightHand)
{

    for (unsigned int i = 0; i < rightHand.skillsSize; i++) {

        // Check if the skill already exists in the newSkillSet
        if (!this->contains(rightHand.skills[i]->getName())) {

            return false;

        }

    }

    return true;

};

bool SkillSet::operator!=(const SkillSet& rightHand)
{

    for (unsigned int i = 0; i < rightHand.skillsSize; i++) {

        // Check if the skill already exists in the newSkillSet
        if (!this->contains(rightHand.skills[i]->getName())) {

            return true;

        }

    }

    return false;

};

SkillSet SkillSet::operator*(const unsigned int& multiple)
{
    SkillSet newSkillSet(*this); // Copy the left-hand side SkillSet

    for (unsigned int i = 0; i < newSkillSet.skillsSize; i++) {

        newSkillSet.change(newSkillSet.skills[i]->getName(),
            newSkillSet.skills[i]->getLevel() * multiple);

    }
    return newSkillSet;
};

void SkillSet::operator*=(const unsigned int& multiple)
{

    for (unsigned int i = 0; i < this->skillsSize; i++) {

        this->change(this->skills[i]->getName(),
            this->skills[i]->getLevel() * multiple);

    }

};

SkillSet SkillSet::operator/(const unsigned int& divisor)
{
    SkillSet newSkillSet(*this); // Copy the left-hand side SkillSet

    for (unsigned int i = 0; i < newSkillSet.skillsSize; i++) {

        newSkillSet.change(newSkillSet.skills[i]->getName(),
            newSkillSet.skills[i]->getLevel() / divisor);

    }
    return newSkillSet;
};

void SkillSet::operator/=(const unsigned int& divisor)
{
    for (unsigned int i = 0; i < this->skillsSize; i++) {

        this->change(this->skills[i]->getName(),
            this->skills[i]->getLevel() / divisor);

    }
};

SkillSet SkillSet::operator+(const SkillSet& rightHand)
{
    SkillSet newSkillSet(*this); // Copy the left-hand side SkillSet

    for (unsigned int i = 0; i < rightHand.skillsSize; i++) {
        // Check if the skill already exists in the newSkillSet
        if (!newSkillSet.contains(rightHand.skills[i]->getName())) {
            // If the skill doesn't exist, add it to the newSkillSet
            std::unique_ptr<Skill> newSkill = std::make_unique<Skill>(
                rightHand.skills[i]->getName(),
                rightHand.skills[i]->getDescription(),
                rightHand.skills[i]->getLevel(),
                rightHand.skills[i]->getCurve());
            newSkillSet.add(newSkill);
        }
        else {
            // If the skill already exists, update its level
            newSkillSet.change(rightHand.skills[i]->getName(),
                newSkillSet.findLevel(rightHand.skills[i]->getName()) + rightHand.skills[i]->getLevel());
        }
    }
    return newSkillSet;
};

void SkillSet::operator+=(const SkillSet& rightHand)
{

    for (unsigned int i = 0; i < rightHand.skillsSize; i++) {
        // Check if the skill already exists in the newSkillSet
        if (!this->contains(rightHand.skills[i]->getName())) {
            // If the skill doesn't exist, add it to the newSkillSet
            std::unique_ptr<Skill> newSkill = std::make_unique<Skill>(
                rightHand.skills[i]->getName(),
                rightHand.skills[i]->getDescription(),
                rightHand.skills[i]->getLevel(),
                rightHand.skills[i]->getCurve());
            this->add(newSkill);
        }
        else {
            // If the skill already exists, update its level
            this->change(rightHand.skills[i]->getName(),
                this->findLevel(rightHand.skills[i]->getName()) + rightHand.skills[i]->getLevel());
        }
    }

};

SkillSet SkillSet::operator-(const SkillSet& rightHand)
{
    SkillSet newSkillSet(*this); // Copy the left-hand side SkillSet

    for (unsigned int i = 0; i < rightHand.skillsSize; i++) {
        // Check if the skill already exists in the newSkillSet
        if (!newSkillSet.contains(rightHand.skills[i]->getName())) {
            // If the skill doesn't exist, add it to the newSkillSet
            std::unique_ptr<Skill> newSkill = std::make_unique<Skill>(
                rightHand.skills[i]->getName(),
                rightHand.skills[i]->getDescription(),
                0,
                rightHand.skills[i]->getCurve());
            newSkillSet.add(newSkill);
        }
        else {
            int result = newSkillSet.findLevel(rightHand.skills[i]->getName()) - rightHand.skills[i]->getLevel();
            // Ensure the skill level doesn't go below 0
            if (result < 0) {
                result = 0;
            }
            newSkillSet.change(rightHand.skills[i]->getName(), result);
        }
    }
    return newSkillSet;
};

void SkillSet::operator-=(const SkillSet& rightHand)
{

    for (unsigned int i = 0; i < rightHand.skillsSize; i++) {
        // Check if the skill already exists in the newSkillSet
        if (!this->contains(rightHand.skills[i]->getName())) {
            // If the skill doesn't exist, add it to the newSkillSet
            std::unique_ptr<Skill> newSkill = std::make_unique<Skill>(
                rightHand.skills[i]->getName(),
                rightHand.skills[i]->getDescription(),
                0,
                rightHand.skills[i]->getCurve());
            this->add(newSkill);
        }
        else {
            int result = this->findLevel(rightHand.skills[i]->getName()) - rightHand.skills[i]->getLevel();
            // Ensure the skill level doesn't go below 0
            if (result < 0) {
                result = 0;
            }
            this->change(rightHand.skills[i]->getName(), result);
        }
    }
};

