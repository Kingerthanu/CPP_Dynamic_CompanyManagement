#ifndef TASK_H
#define TASK_H

#include <string>
#include "skillset.h"


namespace Tasks
{
   
    /*
        Invariants:
            1.)  Task will always contain a name, description and the runtime of it.
            2.)  Runtime of a Task is measured in minutes.
    */
    class Task
    {

        private:
            std::string name;
            std::string description;
            float runTime;
            bool done = false; // Determines if task is completed
            std::shared_ptr<SkillSet> skills;

        public:
            ~Task();

            /*
                Preconditions:
                    1.)  this.done state will not be copied over (stays false)
                Postconditions:
                    1.)  this->skills will be a deep-copy of toCopies Skills.
            */
            Task& operator=(const Task& toCopy);

            /*
               Preconditions:
                   1.)  this.done state will not be copied over (stays false)
               Postconditions:
                   1.)  this.skills will be a deep-copy of toCopies Skills their SkillSet.
           */
            Task(Task& toCopy);

            std::string getName();
            std::string getDescription();
            void setDescription(std::string newDescription);
            bool isDone();
            float getRuntime();
            std::shared_ptr<SkillSet>& getSkillSet();

            /*
                Preconditions:
                    1.)  taskTime is measured in minutes.
                    2.)  taskTime is non-negative.
                    3.)  taskName is non-empty ("").
                    4.)  If skills, then skillsSize is given as well.
                Postconditions:
                    1.)  this->skillSet will be initialized to either length 0 if no skills supplied, or to argument skills contents.
            */
            Task(std::string taskName, std::string taskDescription, const float& taskTime, std::shared_ptr<SkillSet> givenSkill = std::make_shared<SkillSet>());

            /*
                Preconditions:
                    1.)  taskTime is measured in minutes.
                    2.)  taskTime is non-negative.
                    3.)  taskName is non-empty ("").
                    4.)  If skills, then skillsSize is given as well.
                Postconditions:
                    1.)  this->skillSet will be initialized to either length 0 if no skills supplied, or to argument skills contents.
            */
            Task(std::string taskName, std::string taskDescription, const float& taskTime, SkillSet& givenSkill);

            
            /*
                Preconditions:
                    1.)  taskTime is measured in minutes.
                    2.)  taskTime is non-negative.
                    3.)  taskName is non-empty ("").
                    4.)  If skills, then skillsSize is given as well.
                Postconditions:
                    1.)  this->skillSet will be initialized to either length 0 if no skills supplied, or to argument skills contents.
            */
            Task(std::string taskName, std::string taskDescription, const float& taskTime, SkillSet&& givenSkill);

            /*
                Postcondition:
                    1.) this->done will now be true.
            */
            void markDone();

    };

};



#endif