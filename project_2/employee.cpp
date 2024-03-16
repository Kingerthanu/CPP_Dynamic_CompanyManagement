#include "employee.h"


Employees::Employee::Employee(Employees::Employee& toCopy)
{

    this->name = toCopy.name;
    this->hoursOfTasks = toCopy.hoursOfTasks;

    // Implicitly call our deep-copy assignment operation.
    this->skills = std::make_shared<SkillSet>(*toCopy.skills);

};


Employees::Employee::~Employee()
{

    // Stack frees...

};


Employees::Employee& Employees::Employee::operator=(const Employees::Employee& toCopy)
{

    if (this == &toCopy) {

        return *this;

    }

    this->name = toCopy.name;
    this->hoursOfTasks = toCopy.hoursOfTasks;

    // Set-up and do deep-copy of skills (non-const shifting so need extra declaration step).
    std::shared_ptr<SkillSet> newSet = std::make_shared<SkillSet>(*toCopy.skills);
    this->skills = newSet;

    return *this;

};


float Employees::Employee::getHoursOfTasks()
{

    return this->hoursOfTasks;

};


std::shared_ptr<SkillSet>& Employees::Employee::getSkillSet()
{

    // Return reference as shouldn't seperate our unique ptrs with a new instance.
    return this->skills;

};


std::string Employees::Employee::getName()
{

    return this->name;

};




Employees::Employee::Employee(const std::string& name, std::shared_ptr<SkillSet> givenSkill)
{

    this->name = name;

    // Default SkillSet if not provided
    this->skills = givenSkill;

};


Employees::Employee::Employee(const std::string& name, SkillSet& givenSkill)
{

    this->name = name;

    // Should deep-copy over.
    this->skills = std::make_shared<SkillSet>(std::ref(givenSkill));

};


Employees::Employee::Employee(const std::string& name, SkillSet&& givenSkill)
{

    this->name = name;

    // Paste over the provided SkillSet
    this->skills = std::make_shared<SkillSet>(givenSkill);

};


float Employees::Employee::estimateTask(Tasks::Task& givenTask) {

    float taskTime = givenTask.getRuntime();

    // for each skill in a given task, calculate time it'll take to do given skill of task based on proficiency
    for (unsigned int index = 0; index < givenTask.getSkillSet()->getSkillSize(); index++) {

        // overall task time is based upon the given difficulty of the skill minus our proficiency in the given skill.
        //    - if more proficient than difficult, remove time from the tasks completion.
        //    - if more difficult than proficiency, add time from the tasks completion.
        taskTime = givenTask.getSkillSet()->getSkills()[index]->getCurve()->CalculateCost(taskTime, givenTask.getSkillSet()->getSkills()[index]->getLevel(), this->skills->findLevel(givenTask.getSkillSet()->getSkills()[index]->getName()));

    }
    // if negative, return instantanous finishing of task (0.0f)
    if (taskTime < 0.0f) {
        return 0.0f;
    }

    return taskTime;

};


void Employees::Employee::doTask(Tasks::Task& toDo)
{
    // If task is already been done, don't do it again.
    if (toDo.isDone()) {

        return;

    }

    float taskTime = this->estimateTask(toDo);
    this->hoursOfTasks += (taskTime / 60.0f);

    bool flag = false;

    for (unsigned int indexN = 0; indexN < toDo.getSkillSet()->getSkillSize(); indexN++, flag = false) {

        for (unsigned int indexO = 0; indexO < this->skills->getSkillSize(); indexO++) {

            // If we have a skill of a task in our skillset already, add proficiency for redoing it.
            if (toDo.getSkillSet()->getSkills()[indexN]->getName() == this->skills->getSkills()[indexO]->getName()) {

                // Proficiency += minimum 1 increase for redoing + ( (difference between difficulty and proficiency in skill) / 3 )
                //     If diff is less than 3, then go slowly by increments of one as to scale.
                this->skills->getSkills()[indexO]->setLevel(this->skills->getSkills()[indexO]->getLevel() + (unsigned int)(1 + (std::abs((int)((toDo.getSkillSet()->getSkills()[indexN]->getLevel()) - (this->skills->getSkills()[indexO]->getLevel()))) / 3)));
                flag = true;
                break;

            }


        }

        // If not known skill, add it with a new proficiency of 0 for first time learning concept.
        if (flag == false) {
            
            std::unique_ptr<Skill> handler = std::make_unique<Skill>(Skill(toDo.getSkillSet()->getSkills()[indexN]->getName(), toDo.getSkillSet()->getSkills()[indexN]->getDescription(), false));
            this->skills->add( handler );
        }

    }

    // After doing / adding task skills; mark task as done.
    toDo.markDone();
};
