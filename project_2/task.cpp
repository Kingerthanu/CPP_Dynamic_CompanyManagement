#include "task.h"


Tasks::Task::Task(Tasks::Task& toCopy)
{

    this->name = toCopy.name;
    this->description = toCopy.description;
    this->runTime = toCopy.runTime;

    // Do not copy over completion 
    
    // Deep-copy over SkillSet and its skills.
    std::shared_ptr<SkillSet> newSet = std::make_shared<SkillSet>(*toCopy.skills);
    this->skills = newSet;

};


Tasks::Task::~Task()
{

    // Stack frees...

};


Tasks::Task& Tasks::Task::operator=(const Tasks::Task& toCopy)
{

    if (this == &toCopy) {

        return *this;

    }

    // Deep-copy over SkillSet and its skills.
    std::shared_ptr<SkillSet> newSet = std::make_shared<SkillSet>(*toCopy.skills);
    this->skills = newSet;


    this->name = toCopy.name;
    this->description = toCopy.description;
    this->runTime = toCopy.runTime;

    // Do not copy over completion 
    
    return *this;

};


std::string Tasks::Task::getName()
{

    return this->name;

};


std::string Tasks::Task::getDescription()
{

    return this->description;

};


void Tasks::Task::setDescription(std::string newDescription)
{

    this->description = newDescription;

};


bool Tasks::Task::isDone()
{

    return this->done;

};


float Tasks::Task::getRuntime()
{

    return this->runTime;

};


std::shared_ptr<SkillSet>& Tasks::Task::getSkillSet()
{

    return this->skills;

};


Tasks::Task::Task(std::string taskName, std::string taskDescription, const float& taskTime, std::shared_ptr<SkillSet> givenSkill)
{

    this->name = taskName;
    this->description = taskDescription;
    this->runTime = taskTime;

    this->skills = givenSkill;

};


Tasks::Task::Task(std::string taskName, std::string taskDescription, const float& taskTime, SkillSet& givenSkill)
{

    this->name = taskName;
    this->description = taskDescription;
    this->runTime = taskTime;

    this->skills = std::make_shared<SkillSet>(std::ref(givenSkill));

};


Tasks::Task::Task(std::string taskName, std::string taskDescription, const float& taskTime, SkillSet&& givenSkill)
{

    this->name = taskName;
    this->description = taskDescription;
    this->runTime = taskTime;

    this->skills = std::make_shared<SkillSet>(givenSkill);

};


void Tasks::Task::markDone()
{

    this->done = true;

};
