#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "task.h"
#include "skillset.h"

namespace Employees
{

    /*
        Invariants:
            1.)  A Employee will always be initialized with zero hours worked on tasks.
    */
    class Employee
    {

        private:
            std::string name;
            float hoursOfTasks = 0.0f;
            std::shared_ptr<SkillSet> skills;

        public:
            ~Employee();

            /*
                Postconditions:
                    1.)  this.skills will be a deep-copy of toCopies Skills in their SkillSet.
            */
            Employee& operator=(const Employee& toCopy);

            /*
                Postconditions:
                    1.)  this.skills will be a deep-copy of toCopies Skills their SkillSet.
            */
            Employee(Employee& toCopy);

            float getHoursOfTasks();
            std::shared_ptr<SkillSet>& getSkillSet();
            std::string getName();

            /*
                Preconditions:
                    1.)  name is non-empty ("").
                Postconditions:
                    1.)  Name, and skillSet is initialized (SkillSet calls default if not provided).
            */
            Employee(const std::string& name, std::shared_ptr<SkillSet> givenSkill = std::make_shared<SkillSet>());

            /*
                Preconditions:
                    1.)  name is non-empty ("").
                Postconditions:
                    1.)  Name, and skillSet is initialized.
                    2.)  this->skillSet set to copy of givenSkill.
            */
            Employee(const std::string& name, SkillSet& givenSkill);

            /*
                Preconditions:
                    1.)  name is non-empty ("").
                Postconditions:
                    1.)  Name, and skillSet is initialized.
                    2.)  this->skillSet set to givenSkill.
            */
            Employee(const std::string& name, SkillSet&& givenSkill);

            /*
                Preconditions:
                    1.) Task's runtime is measured in minutes.
                Postconditions:
                    1.)  Return task runtime in minutes.
                    2.)  If taskTime falls into negatives (overly proficient), return 0 to show instant finishing of task.
            */
            float estimateTask(Tasks::Task& givenTask);

            /*
                Preconditions:
                    1.)  Skills name(s) is a unique identifier.
                    2.)  taskTime is given in minutes.
                Postconditions:
                    1.)  Won't change anything if already done task.
                    2.)  First time seeing skill, proficiency will start at 0 for that given skill.
                    3.)  Task will set this->done = true if not added already to employee doneTasks.
                    4.)  All task skills will be known to employee after execution.
            */
            void doTask(Tasks::Task& toDo);

    };
};

#endif
