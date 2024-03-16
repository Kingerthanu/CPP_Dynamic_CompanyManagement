#ifndef SKILLSET_H
#define SKILLSET_H

#include "skill.h"
#include <memory>

/*
    Invariants:
        1.) SkillSet will always contain uniquely named skills. 
        2.) SkillSet will always contain its this->skills size in this->skillsSize.    
*/
class SkillSet
{

    private:
        std::unique_ptr<std::unique_ptr<Skill>[]> skills; // Unique_ptr array of unique_ptr's to Skills
        unsigned int skillsSize;

    public:
        /*
            Preconditions:
                1.) newSkill unique_ptr's ptr expected to be given to this SkillSet.
            Postconditions:
                1.) newSkill will now be moved to this and become null.
                2.) newSkill pointed to instance is handed over to SkillSet.
                3.) skillsSize increases by + 1.
                4.) Skills container will be resized by + 1
        */
        bool add(std::unique_ptr<Skill>& newSkill);

        /*
           Preconditions:
               1.) SkillSet has a contained skill with name, nameToFind.
           Postconditions:
               1.) unique_ptr of given Skill with nameToFind is freed (loses scope).
               2.) skillsSize decrease by - 1.
               3.) Skills container will be resized by - 1
        */
        void remove(const std::string& nameToFind);

        /*
          Postconditions:
              1.) unique_ptr skill with nameToFind will have its level changed to newLevel.
              2.) Returns true if a skill with nameToFind was found and level change was successful, else false.
        */
        bool change(const std::string& nameToFind, const unsigned int& newLevel);

        /*
          Postconditions:
              1.) Returns true if a skill with nameToFind was found, else false.
        */
        bool contains(const std::string& nameToFind);

        /*
           Postconditions:
               1.) If skill with name, nameToFind, is found in this->skills, return its level.
               2.) If no skill with name, nameToFind, is found in this->skills, return 0 (start at no knowledge of skill).
        */
        unsigned int findLevel(const std::string& nameToFind);

        /*
            Postconditions:
                1.) Will return instances locked reference to its ptr array.
        */
        const std::unique_ptr<std::unique_ptr<Skill>[]>& getSkills();
        unsigned int getSkillSize();

        /*
            Precondition:
                1.) givenSkills' unique_ptr array will be moved out of givenSkills.
            Postconditions:
                1.) If no provided arguments, set to size 0 array.
                2.) If provided arguments, move ownership to this.
        */
        SkillSet(std::unique_ptr<std::unique_ptr<Skill>[]> givenSkills = std::unique_ptr<std::unique_ptr<Skill>[]>(0), const unsigned int skillsAmount = 0);

        /*
            Postcondition:
                1.) Will deep-copy over unique_ptrs.
        */
        SkillSet(const SkillSet& toCopy);

        /*
            Postcondition:
                1.) Will shallow-copy over unique_ptrs.
        */
        SkillSet& operator=(SkillSet&& toCut) noexcept;

        /*
            Postcondition:
                1.) Will deep-copy over unique_ptrs.
        */
        SkillSet& operator=(SkillSet& toCopy);


        /*
            Preconditions:
                1.) Equivalence is defined by this->skills skill names only, not instance.
                2.) Storage order doesn't matter.
                3.) Will check if all rightHands are contained in this; not other way around.
            Postcondition:
                1.) Will return true if rightHand and this are comprised only of shared named skills.
        */
        bool operator==(const SkillSet& rightHand);
        
        /*
            Preconditions:
                1.) Equivalence is defined by this->skills skill names only, not instance.
                2.) Storage order doesn't matter.
                3.) Will check if all rightHands are contained in this; not other way around.
            Postcondition:
                1.) Will return true if at least one skill in rightHand or this are differently named.
        */
        bool operator!=(const SkillSet& rightHand);
    

        /*
           Preconditions:
               1.) Passed multiple is expected not to exceed any skills level by the value range of unsigned int.
               2.) Each skill in local SkillSet handler will be multiplied by multiple and set to this new multiplied level value.
           Postconditions:
               1.) Return a new SkillSet in which contains all this->skills by value with a level multiplied by multiple.
       */
        SkillSet operator*(const unsigned int& multiple);
        
        /*
            Preconditions:
                1.) Passed multiple is expected not to exceed any skills level by the value range of unsigned int.
                2.) Each skill in this will be multiplied by multiple and set to this new multiplied level value.
            Postconditions:
                1.) After execution, this->skills will all have their level multiplied by multiple.
        */
        void operator*=(const unsigned int& multiple);

        /*
            Preconditions:
                1.) Passed divisor is expected not to exceed any skills level by the value range of unsigned int.
                2.) Each skill in local SkillSet handler will be divided by divisor and set to this new divided level value.
            Postconditions:
                1.) Return a new SkillSet in which contains all this->skills by value with a level divided by divisor.
        */
        SkillSet operator/(const unsigned int& divisor);

        /*
            Preconditions:
                1.) Passed divisor is expected not to exceed any skills level by the value range of unsigned int.
                2.) Each skill in this will be divided by divisor and set to this new divided level value.
            Postconditions:
                1.) After execution, this->skills will all have their level divided by divisor.
        */
        void operator/=(const unsigned int& divisor);

        /*
            Preconditions:
                1.) The addition of any equivalently named skill's level in this or rightHand will not exceed value range of unsigned int.
                2.) Any equivalently named skill in which is in this as well as rightHand will have their levels added together.
            Postconditions:
                1.) Return a new SkillSet in which contains all uniquely named skills in both this as well as rightHand.
                2.) New SkillSet will contain all uniquely named skills from both this and rightHand.
                3.) All skills in the new returned SkillSet will either be set to known level if not shared between both this and rightHand; or their shared instances level's added together.
                4.) Any skill not known by this will inherit the member states of rightHand's skill in the returned SkillSet.        
        */
        SkillSet operator+(const SkillSet& rightHand);

        /*
            Preconditions:
                1.) The addition of any equivalently named skill's level in this or rightHand will not exceed value range of unsigned int.
                2.) Any equivalently named skill in which is in this as well as rightHand will have their levels added together.
            Postconditions:
                1.) After execution, this->skills will all have their level's added together with the skills levels of rightHand.
                2.) this->skills will contain all uniquely named skills from both this and rightHand.
                3.) All skills in the new returned SkillSet will either be set to known level if not shared between both this and rightHand; or their shared instances level's added together.
                4.) Any skill not known by this will inherit the member states of rightHand's skill in the returned SkillSet.
        */
        void operator+=(const SkillSet& rightHand);
        
        /*
            Preconditions:
                1.) The subtraction of any equivalently named skill's level in this or rightHand will not exceed value range of unsigned int.
                2.) Any equivalently named skill in which is in this as well as rightHand will have their levels subtracted together.
            Postconditions:
                1.) Return a new SkillSet in which contains all uniquely named skills in both this as well as rightHand. 
                2.) A negative subtraction operation will be clamped to 0 <= _.
                3.) All skills in the new returned SkillSet will either be set to known level if not shared between both this and rightHand; or their shared instances level's subtracted together.
                4.) Any skill not known by this will inherit the member states of rightHand's skill in the returned SkillSet (other than level which will be set to 0 as 0 -(x) will always be neg).        
        */
        SkillSet operator-(const SkillSet& rightHand);

        /*
            Preconditions:
                1.) The subtraction of any equivalently named skill's level in this or rightHand will not exceed value range of unsigned int.
                2.) Any equivalently named skill in which is in this as well as rightHand will have their levels subtracted together.
            Postconditions:
                1.) this->skills contains all uniquely named skills in both this as well as rightHand.
                2.) A negative subtraction operation will be clamped to 0 <= _.
                3.) All skills in the this->skills will either be set to known level if not shared between both this and rightHand; or their shared instances level's subtracted together.
                4.) Any skill not known by this will inherit the member states of rightHand's skill in the returned SkillSet (other than level which will be set to 0 as 0 -(x) will always be neg).                
        */
        void operator-=(const SkillSet& rightHand);
        
        ~SkillSet();

};



#endif