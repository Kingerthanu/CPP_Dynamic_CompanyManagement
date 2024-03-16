#include "company.h"
#include <iostream>

#include "company.h"
#include <stdexcept>

/*
	Purpose:
		- Thorough testing of employees' constructors, destructor and assignment operators to make sure deep-copying is working properly and no leaks are possible
		within the class.
*/
void testEmployeeThreeAndFree()
{

	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> employeeBin = std::make_unique<std::shared_ptr<Employees::Employee>[]>(300);

	// For all 300 employees, either make unique employee with default construction, copy construction, or assignment.
	for (unsigned int i = 0; i < 300; i++) {

		switch (i % 3) {

		case 0: // Default
		{
			std::unique_ptr<std::unique_ptr<Skill>[]> newSkills = std::make_unique<std::unique_ptr<Skill>[]>(2);
			newSkills[0] = std::make_unique<Skill>("Apple", "Salmonella", 5);
			newSkills[1] = std::make_unique<Skill>("Sauce", "Grape Juice", 5);

			Tasks::Task handler("Bingus", "Tingus", 50.0f, SkillSet(std::move(newSkills), 2));
			employeeBin[i] = std::make_shared<Employees::Employee>(std::to_string(i));
			employeeBin[i]->doTask(handler);
			break;
		}
		case 1: // Copy
			employeeBin[i] = std::make_shared<Employees::Employee>(*employeeBin[i - 1]);
			break;
		case 2: // Assignment
			employeeBin[i] = std::make_shared<Employees::Employee>(*employeeBin[i - 1]);
			*employeeBin[i] = *(employeeBin[i - 1]);
			break;


		}

	}

};


/*
	Purpose:
		- Thorough testing of tasks' constructors, destructor and assignment operators to make sure deep-copying is working properly and no leaks are possible
		within the class.
*/
void testTaskThreeAndFree()
{

	std::unique_ptr<std::unique_ptr<Tasks::Task>[]> taskBin = std::make_unique<std::unique_ptr<Tasks::Task>[]>(300);

	// For all 300 Tasks, either make unique task with default construction, copy construction, or assignment.
	for (unsigned int i = 0; i < 300; i++) {

		switch (i % 3) {

			case 0:
				{
					std::unique_ptr<std::unique_ptr<Skill>[]> newSkills = std::make_unique<std::unique_ptr<Skill>[]>(2);
					newSkills[0] = std::make_unique<Skill>("Apple", "Salmonella", 5);
					newSkills[1] = std::make_unique<Skill>("Sauce", "Grape Juice", 5);

					taskBin[i] = std::make_unique<Tasks::Task>("Bingus", "Tingus", 50.0f, SkillSet(std::move(newSkills), 2));
					break;
				}
			case 1:
				{
					taskBin[i] = std::make_unique<Tasks::Task>(*taskBin[i - 1]);
					break;
				}
			case 2:
				{
					taskBin[i] = std::make_unique<Tasks::Task>(*taskBin[i - 1]);
					*taskBin[i] = *(taskBin[i - 1]);
					break;
				}


		}

	}


};


/*
	Purpose:
		- Thorough testing of teams' constructors, destructor and assignment operators to make sure deep-copying is working properly and no leaks are possible
		within the class.
*/
void testTeamThreeAndFree()
{

	std::unique_ptr<std::unique_ptr<Team>[]> teamBin = std::make_unique<std::unique_ptr<Team>[]>(300);

	// For all 300 teams, either make unique team with default construction, copy construction, or assignment.
	for (unsigned int i = 0; i < 300; i++) {

		switch (i % 3) {

		case 0:
		{

			teamBin[i] = std::make_unique<Team>("Team 10");
			break;
		}
		case 1:
			teamBin[i] = std::make_unique<Team>(*teamBin[i - 1]);
			break;
		case 2:
			teamBin[i] = std::make_unique<Team>(*teamBin[i - 1]);
			*teamBin[i] = *(teamBin[i - 1]);
			break;


		}

	}

};


/*
	Purpose:
		- Thorough testing of companies' constructors, destructor and assignment operators to make sure deep-copying is working properly and no leaks are possible
		within the class. Will manage teams which are made using their copy constructors as well as employees using their copy constructors to make sure management of data
		is seen for leaks through deep copies.
*/
void testCompanyThreeAndFree()
{

	std::unique_ptr<std::unique_ptr<Company>[]> companyBin = std::make_unique<std::unique_ptr<Company>[]>(300);

	// For all 300 companies, either make unique company with employees in teams with default construction, copy construction, or assignment.
	for (unsigned int i = 0; i < 300; i++) {

		switch (i % 3) {

		case 0:
		{

			std::unique_ptr<std::shared_ptr<Employees::Employee>[]> employeeBin = std::make_unique<std::shared_ptr<Employees::Employee>[]>(300);

			// For all 300 employees, either make unique employee with default construction, copy construction, or assignment.
			for (unsigned int i = 0; i < 300; i++) {

				switch (i % 3) {

				case 0: // Default
				{
					std::unique_ptr<std::unique_ptr<Skill>[]> newSkills = std::make_unique<std::unique_ptr<Skill>[]>(2);
					newSkills[0] = std::make_unique<Skill>("Apple", "Salmonella", 5);
					newSkills[1] = std::make_unique<Skill>("Sauce", "Grape Juice", 5);

					Tasks::Task handler("Bingus", "Tingus", 50.0f, SkillSet(std::move(newSkills), 2));
					employeeBin[i] = std::make_shared<Employees::Employee>(std::to_string(i));
					employeeBin[i]->doTask(handler);
					break;
				}
				case 1: // Copy
					employeeBin[i] = std::make_shared<Employees::Employee>(*employeeBin[i - 1]);
					break;
				case 2: // Assignment
					employeeBin[i] = std::make_shared<Employees::Employee>(*employeeBin[i - 1]);
					*employeeBin[i] = *(employeeBin[i - 1]);
					break;


				}

			}

			std::unique_ptr<std::shared_ptr<Team>[]> teamBin = std::make_unique<std::shared_ptr<Team>[]>(300);

			// For all 300 teams, either make unique team with default construction, copy construction, or assignment.
			for (unsigned int i = 0; i < 300; i++) {

				switch (i % 3) {

				case 0:
				{

					teamBin[i] = std::make_shared<Team>("Team 10");
					break;
				}
				case 1:
					teamBin[i] = std::make_shared<Team>(*teamBin[i - 1]);
					break;
				case 2:
					teamBin[i] = std::make_shared<Team>(*teamBin[i - 1]);
					*teamBin[i] = *(teamBin[i - 1]);
					break;


				}

			}

			companyBin[i] = std::make_unique<Company>("Jimmothies", std::move(employeeBin), 300, std::move(teamBin), 300);

			break;

		}
		case 1:
			companyBin[i] = std::make_unique<Company>(*companyBin[i - 1]);
			break;
		case 2:
			companyBin[i] = std::make_unique<Company>(*companyBin[i - 1]);
			*companyBin[i] = *(companyBin[i - 1]);
			break;

		}

	}

	// Clean-up.
	for (unsigned int i = 0; i < 300; i++) {

		if (companyBin[i]->getName() != "Jimmothies") {

			throw std::runtime_error("Not properly copying name of companies..");

		}


	}

};

bool demoSkillSetFunctionality()
{

    // Create some skills
    std::unique_ptr<Skill> skill1 = std::make_unique<Skill>("Skill1", "Description1", 10);
    std::unique_ptr<Skill> skill2 = std::make_unique<Skill>("Skill2", "Description2", 20);
    std::unique_ptr<Skill> skill3 = std::make_unique<Skill>("Skill3", "Description3", 30);


    // Create an array of unique pointers to skills
    std::unique_ptr<std::unique_ptr<Skill>[]> skillArray = std::make_unique<std::unique_ptr<Skill>[]>(3);
    skillArray[0] = std::move(skill1);
    skillArray[1] = std::move(skill2);
    skillArray[2] = std::move(skill3);

    // Create a SkillSet using the array of skills
    SkillSet skillSet(std::move(skillArray), 3);


    // Test adding a new skill
    std::unique_ptr<Skill> newSkill = std::make_unique<Skill>("Skill1", "NewDescription", 0);
    if (skillSet.add(newSkill)) {
        return false;
    }

    // Test removing a skill
    skillSet.remove("Skill1");

    // Test changing skill level
    if (skillSet.change("Skill1", 10)) {
        return false;
    }


    // Test finding skill level
    std::unique_ptr<Skill> skillToReAdd = std::make_unique<Skill>("Skill1", "Description1", 10);
    skillSet.add(skillToReAdd);

    unsigned int level = skillSet.findLevel("Skill1");

    if (level != 10) {
    
        return false;

    }

    return true;

};

bool demoSkillSetCopy()
{

    // Create some skills
    std::unique_ptr<Skill> skill1 = std::make_unique<Skill>("Skill1", "Description1", 10);
    std::unique_ptr<Skill> skill2 = std::make_unique<Skill>("Skill2", "Description2", 20);
    std::unique_ptr<Skill> skill3 = std::make_unique<Skill>("Skill3", "Description3", 30);


    // Create an array of unique pointers to skills
    std::unique_ptr<std::unique_ptr<Skill>[]> skillArray = std::make_unique<std::unique_ptr<Skill>[]>(3);
    skillArray[0] = std::move(skill1);
    skillArray[1] = std::move(skill2);
    skillArray[2] = std::move(skill3);

    // Create a SkillSet using the array of skills
    SkillSet skillSet(std::move(skillArray), 3);

    SkillSet secondSkillSet(skillSet);

    for (unsigned int i = 0; i < 3; i++) {

        // Check to make sure not same unique_ptrs
        if (*skillSet.getSkills()[i] == *secondSkillSet.getSkills()[i]) {

            return false;

        }

    }
    
    skillSet.remove("Skill2");

    if (skillSet.getSkillSize() != 2) {

        return false;

    }
    else if (secondSkillSet.getSkillSize() != 3 || secondSkillSet.getSkills()[0]->getName() != "Skill1" || secondSkillSet.getSkills()[0]->getLevel() != 10) {

        return false;

    }


    skillSet = secondSkillSet;

    for (unsigned int i = 0; i < 3; i++) {

        // Check to make sure not same unique_ptrs
        if (*skillSet.getSkills()[i] == *secondSkillSet.getSkills()[i]) {

            return false;

        }

    }


    secondSkillSet.remove("Skill2");

    if (secondSkillSet.getSkillSize() != 2) {

        return false;

    }
    else if (skillSet.getSkillSize() != 3 || skillSet.getSkills()[0]->getName() != "Skill1" || skillSet.getSkills()[0]->getLevel() != 10) {

        return false;

    }

	return true;

};

/*
	Purpose:
		- Test will look to make sure employees are not being cleaned up by Teams when removed, added or copied then removed.
		We want to make sure clean-up of Employees is independent of our teams.
*/
bool testTeamAddingAndRemoving()
{

	// Get team members
	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> teamEmployees = std::make_unique<std::shared_ptr<Employees::Employee>[]>(100);
	for (unsigned int i = 0; i < 100; i++) {
		teamEmployees[i] = std::make_shared<Employees::Employee>("Employee " + std::to_string('0' + i));
	}

	// Teams are not liable.
	std::unique_ptr<Team> teamHandler = std::make_unique<Team>("Team 10", std::move(teamEmployees), 100);
	std::unique_ptr<Team> secondTeamHandler = std::make_unique<Team>(*teamHandler);

	// Free all our employees
	for (unsigned int i = 0; i < 100; i++) {
		teamHandler->removeEmployee("Employee " + std::to_string('0' + i));
	}

	if (teamHandler->getAmountEmployees() != 0) {
		return false;
	}

	// Re-add all employees.
	teamEmployees = std::make_unique<std::shared_ptr<Employees::Employee>[]>(100);

	for (unsigned int i = 0; i < 100; i++) {
		teamEmployees[i] = std::make_shared<Employees::Employee>("Employee " + std::to_string('0' + i));
		teamHandler->addEmployee(teamEmployees[i]);
	}

	// Override employees with secondTeam's
	*teamHandler = *secondTeamHandler;

	if (teamHandler->getAmountEmployees() != 100) {
		return false;
	}

	// Make sure all employees are still here.
	for (unsigned int i = 0; i < 100; i++) {
		if (teamEmployees[i]->getName() != ("Employee " + std::to_string('0' + i))) {
			return false;
		}
	}

	return true;

};

/*
	Purpose:
		- Test will make sure that the time estimates for a given task when done by a team where theres no skills is lower with more teammates
		compared to doing it with a single employee (try showing divide-and-conquering of tasks within a team.
*/
bool testTeamEstimatesNoSkill()
{

	// Get team members
	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> teamEmployeesMultiple = std::make_unique<std::shared_ptr<Employees::Employee>[]>(100);
	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> teamEmployeesSingle = std::make_unique<std::shared_ptr<Employees::Employee>[]>(1);
	teamEmployeesSingle[0] = std::make_shared<Employees::Employee>("Employee " + std::to_string('0'));
	for (unsigned int i = 0; i < 100; i++) {

		teamEmployeesMultiple[i] = std::make_shared<Employees::Employee>("Employee " + std::to_string('0' + i));

	}

	// Set teams with employees.
	std::unique_ptr<Team> teamHandlerMultiple = std::make_unique<Team>("Team 10", std::move(teamEmployeesMultiple), 100);
	std::unique_ptr<Team> teamHandlerSingle = std::make_unique<Team>("Team 10", std::move(teamEmployeesSingle), 1);

	std::unique_ptr<Tasks::Task>  baseTimeTask = std::make_unique<Tasks::Task>("Base Time Task", "Seasoned Beef", 60.0f);

	// Get estimates with multiple vs with single teammate.
	float multipleEstimate = teamHandlerMultiple->estimateTask(*baseTimeTask);
	float singleEstimate = teamHandlerSingle->estimateTask(*baseTimeTask);

	if (singleEstimate != 60.0f) {

		return false;

	}
	else if (multipleEstimate >= 60.0f) {

		return false;

	}

	return true;

};

/*
	Purpose:
		- Test will make sure that the time estimates for a given task when done by a team where theres skills vs no skills upholds the invariant
		that a skilled employee(s) will complete a task faster than a team of non-skilled employee(s).
*/
bool testTeamEstimatesSkill()
{

	// Get team members without skills
	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> teamEmployeesNoSkillMultiple = std::make_unique<std::shared_ptr<Employees::Employee>[]>(100);
	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> teamEmployeesNoSkillSingle = std::make_unique<std::shared_ptr<Employees::Employee>[]>(1);
	teamEmployeesNoSkillSingle[0] = std::make_shared<Employees::Employee>("Employee " + std::to_string('0'));
	for (unsigned int i = 0; i < 100; i++) {

		teamEmployeesNoSkillMultiple[i] = std::make_shared<Employees::Employee>("Employee " + std::to_string('0' + i));

	}


	// Get team members with skills
	std::unique_ptr<std::shared_ptr<Employees::Employee>[]>teamEmployeesMultipleSkill = std::make_unique<std::shared_ptr<Employees::Employee>[]>(100);
	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> teamEmployeesSingleSkill = std::make_unique<std::shared_ptr<Employees::Employee>[]>(1);

	std::unique_ptr<std::unique_ptr<Skill>[]> handler = std::make_unique<std::unique_ptr<Skill>[]>(2);
	handler[0] = std::make_unique<Skill>("Skill One", "Theodore", 2);
	handler[1] = std::make_unique<Skill>("Skill Two", "Trent", 5);

	teamEmployeesSingleSkill[0] = std::make_shared<Employees::Employee>("Employee " + std::to_string('0'), SkillSet(std::move(handler), 2));
;
	for (unsigned int i = 0; i < 100; i++) {

		handler = std::make_unique<std::unique_ptr<Skill>[]>(2);
		handler[0] = std::make_unique<Skill>("Skill One", "Theodore", 2);
		handler[1] = std::make_unique<Skill>("Skill Two", "Trent", 5);

		teamEmployeesMultipleSkill[i] = std::make_unique<Employees::Employee>("Employee " + std::to_string('0' + i), SkillSet(std::move(handler), 2));

	}


	// Teams with employees of no skill
	std::unique_ptr<Team> teamHandlerMultipleNoSkill = std::make_unique<Team>("Team 10", std::move(teamEmployeesNoSkillMultiple), 100);
	std::unique_ptr<Team> teamHandlerSingleNoSkill = std::make_unique<Team>("Team 10", std::move(teamEmployeesNoSkillSingle), 1);

	// Teams with employees of skill
	std::unique_ptr<Team> teamHandlerMultipleSkill = std::make_unique<Team>("Team 10", std::move(teamEmployeesMultipleSkill), 100);
	std::unique_ptr<Team> teamHandlerSingleSkill = std::make_unique<Team>("Team 10", std::move(teamEmployeesSingleSkill), 1);

	// Task both teams will do with skills
	std::unique_ptr<std::unique_ptr<Skill>[]>handlerTask = std::make_unique<std::unique_ptr<Skill>[]>(2);
	handlerTask[0] = std::make_unique<Skill>("Skill One", "Theodore", 2);
	handlerTask[1] = std::make_unique<Skill>("Skill Two", "Trent", 3);
	std::unique_ptr<Tasks::Task> baseTimeTask = std::make_unique<Tasks::Task>("Base Time Task", "Seasoned Beef", 60.0f, SkillSet(std::move(handlerTask), 2));

	// Get estimates without skills
	float multipleEstimateNoSkill = teamHandlerMultipleNoSkill->estimateTask(*baseTimeTask);
	float singleEstimateNoSkill = teamHandlerSingleNoSkill->estimateTask(*baseTimeTask);

	// Get estimates with skills
	float multipleEstimateSkill = teamHandlerMultipleSkill->estimateTask(*baseTimeTask);
	float singleEstimateSkill = teamHandlerSingleSkill->estimateTask(*baseTimeTask);



	if (singleEstimateNoSkill < 60.0f) {
		return false;
	}
	else if (multipleEstimateNoSkill > 60.0f) {

		return false;

	}

	if (singleEstimateSkill > singleEstimateNoSkill) {

		return false;

	}
	else if (multipleEstimateSkill > multipleEstimateNoSkill) {

		return false;

	}

	return true;

};

/*
	Purpose:
		- Test will try addition and removal of employees from the company as well as their respective team. First trying reoccuring employees on many teams,
		and secondly many unique employees on many teams. We check for proper leak cleanup as well.
*/
bool testCompanyHireAndFire()
{

	// Start empty, fill with employees
	std::unique_ptr<Company> companyHandler = std::make_unique<Company>("MANNCO");

	// Only allocate for 5 employees.
	for (unsigned int i = 0; i < 5; i++) {
		std::shared_ptr<Employees::Employee> employeeHandler = std::make_shared<Employees::Employee>("Employee " + std::to_string('0' + i));
		companyHandler->addEmployee(employeeHandler);

	}

	// Make 1000 teams in which use 0-4 employees.
	for (unsigned int i = 0; i < 1000;) {

		std::unique_ptr<std::shared_ptr<Employees::Employee>[]> employeeHandle = std::make_unique<std::shared_ptr<Employees::Employee>[]>(5);

		employeeHandle[0] = companyHandler->getEmployee("Employee " + std::to_string('0' + 0));
		employeeHandle[1] = companyHandler->getEmployee("Employee " + std::to_string('0' + 1));
		employeeHandle[2] = companyHandler->getEmployee("Employee " + std::to_string('0' + 2));
		employeeHandle[3] = companyHandler->getEmployee("Employee " + std::to_string('0' + 3));
		employeeHandle[4] = companyHandler->getEmployee("Employee " + std::to_string('0' + 4));

		companyHandler->createTeam("Team " + std::to_string('0' + i++), std::move(employeeHandle), 5);


	}

	// Backward removal
	for (int i = 4; i != -1; i--) {

		companyHandler->removeEmployee(companyHandler->getEmployee("Employee " + std::to_string('0' + i)));

		for (unsigned int j = 0; j < 1000; j++) {

			// Should decrease by one per outer-loop increment.
			if (companyHandler->getTeam("Team " + std::to_string('0' + j))->getAmountEmployees() != (4 - (4 - i))) {

				return false;

			}

		}
	}


	// Make 1000 employees for teams.
	for (unsigned int i = 0; i < 1000; i++) {
		std::shared_ptr<Employees::Employee> employeeHandler = std::make_shared<Employees::Employee>("Employee " + std::to_string('0' + i));
		companyHandler->addEmployee(employeeHandler);

	}

	// Make 200 teams of 5 unique employees.
	for (unsigned int i = 0, teamIndex = 0; i < 1000;) {

		std::unique_ptr<std::shared_ptr<Employees::Employee>[]> employeeHandler = std::make_unique<std::shared_ptr<Employees::Employee>[]>(5);

		employeeHandler[0] = companyHandler->getEmployee("Employee " + std::to_string('0' + i++));
		employeeHandler[1] = companyHandler->getEmployee("Employee " + std::to_string('0' + i++));
		employeeHandler[2] = companyHandler->getEmployee("Employee " + std::to_string('0' + i++));
		employeeHandler[3] = companyHandler->getEmployee("Employee " + std::to_string('0' + i++));
		employeeHandler[4] = companyHandler->getEmployee("Employee " + std::to_string('0' + i++));

		companyHandler->createTeam("Team " + std::to_string('0' + teamIndex++), std::move(employeeHandler), 5);


	}

	// Remove everyone from team and check if all removed.
	for (unsigned int i = 0; i < 1000;) {

		// Forward removal
		companyHandler->removeEmployee(companyHandler->getEmployee("Employee " + std::to_string('0' + i++)));
		companyHandler->removeEmployee(companyHandler->getEmployee("Employee " + std::to_string('0' + i++)));
		companyHandler->removeEmployee(companyHandler->getEmployee("Employee " + std::to_string('0' + i++)));
		companyHandler->removeEmployee(companyHandler->getEmployee("Employee " + std::to_string('0' + i++)));
		companyHandler->removeEmployee(companyHandler->getEmployee("Employee " + std::to_string('0' + i++)));

		for (unsigned int j = 0; j < 200; j++) {

			if (companyHandler->getTeam("Team " + std::to_string('0' + j))->getAmountEmployees() != 0) {

				return false;

			}

		}
	}

	return true;

};

/*
	Purpose:
		- Test will check proper handling of empty teams with removal and retrieval.
*/
bool testCompanyFindAndRemoveEmptyTeams()
{

	std::unique_ptr<Company> companyHandler = std::make_unique<Company>("MANNCO");


	// Make 1000 teams in which use 0 employees.
	for (unsigned int i = 0; i < 1000; i++) {

		if (i != companyHandler->getAmountTeams()) {

			return false;

		}

		companyHandler->createTeam("Team " + std::to_string('0' + i));

	}

	// Remove all 1000 teams.
	for (unsigned int i = 0; i < 1000; i++) {

		companyHandler->deleteTeam(companyHandler->getTeam("Team " + std::to_string('0' + i)));

		if ((999 - i) != companyHandler->getAmountTeams()) {

			return false;

		}

	}

	return true;

}

/*
	Purpose:
		- Test tries checking to make sure that rehiring a employee will still keep the same estimate as before hiring without skills.
*/
bool testCompanyEstimateWithRehires()
{

	// Allocate 5 non-skills employees to give to new company
	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> currentEmployees = std::make_unique<std::shared_ptr<Employees::Employee>[]>(5);

	currentEmployees[0] = std::make_unique<Employees::Employee>("Employee 1");
	currentEmployees[1] = std::make_unique<Employees::Employee>("Employee 2");
	currentEmployees[2] = std::make_unique<Employees::Employee>("Employee 3");
	currentEmployees[3] = std::make_unique<Employees::Employee>("Employee 4");
	currentEmployees[4] = std::make_unique<Employees::Employee>("Employee 5");

	// Create a new unique_ptr to hold the shared_ptrs
	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> copyEmployees =
		std::make_unique<std::shared_ptr<Employees::Employee>[]>(5);

	// Move the shared_ptrs from currentEmployees to newEmployees
	for (size_t i = 0; i < 5; ++i) {
		copyEmployees[i] = currentEmployees[i];
	}

	// Create company with employees
	std::unique_ptr<Company> companyHandler = std::make_unique<Company>("MANNCO", std::move(copyEmployees), 5);


	copyEmployees =
		std::make_unique<std::shared_ptr<Employees::Employee>[]>(5);

	// Move the shared_ptrs from currentEmployees to newEmployees
	for (size_t i = 0; i < 5; ++i) {
		copyEmployees[i] = currentEmployees[i];
	}


	// Create non-skilled task todo (basically neutral skill-level so can infer same invariants with skills).
	std::unique_ptr < Tasks::Task > taskHandler = std::make_unique < Tasks::Task >("Task One", "Wet Towel", 60.0f);

	// Create team with all current company employees
	companyHandler->createTeam("Team 10", std::move(copyEmployees), 5);

	// Grab estimate of our task with team before removing employee
	float estimateBeforeFired = companyHandler->getTeam("Team 10")->estimateTask(*taskHandler);

	// Copy over to-be-removed employee for readding when dealllocated by company with removal
	std::shared_ptr<Employees::Employee> employeeOneCopy = currentEmployees[2];
	companyHandler->removeEmployee(currentEmployees[2]);

	// Re-add employee after removal
	companyHandler->addEmployee(employeeOneCopy);
	companyHandler->getTeam("Team 10")->addEmployee(employeeOneCopy);

	// Grab estimate of our task with team after removing employee but re-adding
	float estimateAfterFired = companyHandler->getTeam("Team 10")->estimateTask(*taskHandler);

	if (estimateAfterFired != estimateBeforeFired) {

		return false;

	}

	return true;

};

/*
	Purpose:
		- Test will create teams and randomly assign a employee to a given random team.
		We want to make sure that teams are being cleaned up properly under random assignment of unique employees. The removal of employees
		during checks in teams is to see if reallocation and reordering of non-deleted elements is corrupt.
*/
bool testCompanyRetrievals()
{

	std::unique_ptr<Company> companyHandler = std::make_unique<Company>("MANNCO");
	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> employeeBin = std::make_unique<std::shared_ptr<Employees::Employee>[]>(100);
	std::unique_ptr<Tasks::Task> taskHandler = std::make_unique<Tasks::Task>("Task one", "Salmonella", 60.0f);

	// Make 1000 teams in which use 0 employees.
	for (unsigned int i = 0; i < 100; i++) {

		companyHandler->createTeam("Team " + std::to_string('0' + i));

	}


	// Seed the random number generator
	std::random_device rd;
	std::mt19937 seed(rd());

	// Define a uniform distribution
	std::uniform_int_distribution<int> employeeIndex(0, 99);


	// Add 1000 employees randomly to a team.
	for (unsigned int i = 0; i < 100; i++) {

		employeeBin[i] = std::make_shared<Employees::Employee>(std::to_string('0' + i));
		companyHandler->addEmployee(employeeBin[i]);

		companyHandler->getTeam("Team " + std::to_string('0' + employeeIndex(seed)))->addEmployee(employeeBin[i]);

	}

	bool foundFlag = false;
	float prevRuntime = 0.0f;

	for (unsigned int i = 0; i < 100; i++, foundFlag = false) { // For each employee...

		for (unsigned int j = 0; j < 100; j++) { // For each team...

			// If team contains employee, remove from team and set found flag as true
			if (companyHandler->getTeam("Team " + std::to_string('0' + j))->containsEmployee(employeeBin[i])) {

				prevRuntime = companyHandler->getTeam("Team " + std::to_string('0' + j))->estimateTask(*taskHandler);

				companyHandler->getTeam("Team " + std::to_string('0' + j))->removeEmployee(companyHandler->getEmployee(employeeBin[i]->getName())->getName());

				if ((companyHandler->getTeam("Team " + std::to_string('0' + j))->getAmountEmployees() != 0) && (prevRuntime > companyHandler->getTeam("Team " + std::to_string('0' + j))->estimateTask(*taskHandler))) {

					return false;

				}

				foundFlag = true;
				break;

			}

		}

		if (!foundFlag) {

			return false;

		}

	}

	return true;

};

/*
	Purpose:
		- Test will make sure that even when teams are dissolved and have associated employees that the employees are still in the company and aren't
		tampered with through team clean-up.
*/
bool testCompanyTeamDestruction()
{

	std::unique_ptr<Company> companyHandler = std::make_unique<Company>("MANNCO");
	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> employeeBin = std::make_unique<std::shared_ptr<Employees::Employee>[]>(100);


	// Make 1000 teams in which use 0 employees.
	for (unsigned int i = 0; i < 100; i++) {

		companyHandler->createTeam("Team " + std::to_string('0' + i));

	}


	// Seed the random number generator
	std::random_device rd;
	std::mt19937 seed(rd());

	// Define a uniform distribution
	std::uniform_int_distribution<> employeeIndex(0, 99);

	// Add 1000 employees randomly to a team.
	for (unsigned int i = 0; i < 100; i++) {

		employeeBin[i] = std::make_shared<Employees::Employee>(std::to_string('0' + i));
		companyHandler->addEmployee(employeeBin[i]);

		companyHandler->getTeam("Team " + std::to_string('0' + employeeIndex(seed)))->addEmployee(employeeBin[i]);

	}


	// Delete all teams..
	for (unsigned int i = 0; i < 100; i++) {

		companyHandler->deleteTeam(companyHandler->getTeam("Team " + std::to_string('0' + i)));

	}

	// Make sure employees are still in our company even throughout team dissolvement.
	for (unsigned int i = 0; i < 100; i++) {

		companyHandler->getEmployee(std::to_string('0' + i));

	}

	return true;


};

bool testDefaultInterface()
{

	// Should set interface to linear as default.
	Skill skillDefaultInterface = Skill("Skill One", "Apple Bees", 0);

	// Equal amount should return base time.
	if (skillDefaultInterface.getCurve()->CalculateCost(60.0f, 0, 0) != 60.0f) {
		return false;
	}

	// Add 3-minutes as is difficulty of 3 and 0 skill
	else if (skillDefaultInterface.getCurve()->CalculateCost(60.0f, 3, 0) != 63.0f) {
		return false;
	}

	// Remove 3-minutes as is difficulty of 0 and 3 skill
	else if (skillDefaultInterface.getCurve()->CalculateCost(60.0f, 0, 3) != 57.0f) {
		return false;
	}

	// If goes negative, should return 0.0f for instant finishing
	else if (skillDefaultInterface.getCurve()->CalculateCost(60.0f, 0, 120) != 0.0f) {
		return false;
	}

}

bool testUnseededRandomizedInterface()
{

	// Create a Skill object with default arguments
	Skill skillRandomInterface("Skill One", "Apple Bees", 0, std::make_shared<LinearDifficultyCurve>());

	// Equal amount should return base time.
	if (skillRandomInterface.getCurve()->CalculateCost(60.0f, 0, 0) != 60.0f)
	{

		return false;

	}

	// Should be always at least double so check from adding one up to see if properly randomizing
	else if (!(skillRandomInterface.getCurve()->CalculateCost(60.0f, 3, 0) <= 63.0f))
	{

		return false;

	}

	// Should be always at least double so check from removing one up to see if properly randomizing
	else if (!(skillRandomInterface.getCurve()->CalculateCost(60.0f, 0, 3) >= 57.0f))
	{

		return false;

	}

	// If goes negative, should return 0.0f for instant finishing
	else if (skillRandomInterface.getCurve()->CalculateCost(60.0f, 0, 120) != 0.0f)
	{

		return false;

	}

	return true; // Return the success flag



}

bool testSeededRandomInterface()
{

	std::random_device seed;

	// Should set interface to linear as default.
	Skill skillRandomInterface("Skill One", "Apple Bees", 0, std::make_shared<RandomizedDifficultyCurve>(seed()));

	// Equal amount should return base time.
	if (skillRandomInterface.getCurve()->CalculateCost(60.0f, 0, 0) != 60.0f) {
		return false;
	}

	// Should be always at least double so check from adding one up to see if properly randomizing
	else if (!(skillRandomInterface.getCurve()->CalculateCost(60.0f, 3, 0) > 63.0f)) {
		return false;
	}

	// Should be always at least double so check from removing one up to see if properly randomizing
	else if (!(skillRandomInterface.getCurve()->CalculateCost(60.0f, 0, 3) < 57.0f)) {
		return false;
	}

	// If goes negative, should return 0.0f for instant finishing
	else if (skillRandomInterface.getCurve()->CalculateCost(60.0f, 0, 120) != 0.0f) {
		return false;
	}

	return true;

}

bool testRandomInterface()
{
	// Pass same seed top both skills to compare
	std::random_device seedGen;

	const unsigned int seed = seedGen();

	// Should set interface to linear as default.
	Skill skillRandomInterface = Skill("Skill One", "Apple Bees", 0, std::make_shared<RandomizedDifficultyCurve>(seed));
	Skill skillRandomInterfaceSecond = Skill("Skill One", "Apple Bees", 0, std::make_shared<RandomizedDifficultyCurve>(seed));

	// Need float to hold one of the most recent as want to check value twice and calling function again will give new val.
	float newestCost = skillRandomInterface.getCurve()->CalculateCost(60.0f, 0, 0);

	// Equal amount should return base time.
	if (newestCost != 60.0f) {
		return false;
	}
	else if (newestCost != skillRandomInterfaceSecond.getCurve()->CalculateCost(60.0f, 0, 0)) {
		return false;
	}

	newestCost = skillRandomInterface.getCurve()->CalculateCost(60.0f, 3, 0);

	// Should be always at least double so check from adding one up to see if properly randomizing
	if(!(newestCost > 63.0f)) {
		return false;
	}
	else if (newestCost != skillRandomInterfaceSecond.getCurve()->CalculateCost(60.0f, 3, 0)) {
		return false;
	}

	newestCost = skillRandomInterface.getCurve()->CalculateCost(60.0f, 0, 3);

	// Should be always at least double so check from removing one up to see if properly randomizing
	if (!(newestCost < 57.0f)) {
		return false;
	}
	else if (newestCost != skillRandomInterfaceSecond.getCurve()->CalculateCost(60.0f, 0, 3)) {
		return false;
	}

	newestCost = skillRandomInterface.getCurve()->CalculateCost(60.0f, 0, 120);

	// If goes negative, should return 0.0f for instant finishing
	if (newestCost != 0.0f) {
		return false;
	}
	else if (newestCost != skillRandomInterfaceSecond.getCurve()->CalculateCost(60.0f, 0, 120)) {
		return false;
	}

	return true;

}

bool testAdjustedInterface()
{


	Skill skillAdjustedInterface = Skill("Skill One", "Apple Bees", 0, std::make_shared <AdjustedDifficultyCurve>(1.5f));
	LinearDifficultyCurve handler = LinearDifficultyCurve();

	// Equal amount should return base time (should be 60.0f * 1.5f as that's multiple)
	if (skillAdjustedInterface.getCurve()->CalculateCost(60.0f, 0, 0) != (handler.CalculateCost(60.0f, 0, 0) * 1.5f)) {
		return false;
	}

	// Should be linear, but with higher multiple so check with known multiple to see if properly did calculation
	else if (skillAdjustedInterface.getCurve()->CalculateCost(60.0f, 3, 0) != (handler.CalculateCost(60.0f, 3, 0)) * 1.5f) {
		return false;
	}

	// Should be linear, but with higher multiple so check with known multiple to see if properly did calculation
	else if (skillAdjustedInterface.getCurve()->CalculateCost(60.0f, 0, 3) != (handler.CalculateCost(60.0f, 0, 3)) * 1.5f) {
		return false;
	}

	// If goes negative, should return 0.0f for instant finishing
	else if (skillAdjustedInterface.getCurve()->CalculateCost(60.0f, 0, 120) != handler.CalculateCost(60.0f, 0, 120) * 1.5f) {
		return false;
	}

	return true;

}

bool testCopyInterface()
{


	// Should set interface to linear as default.
	Skill skillAdjustedInterface = Skill("Skill One", "Apple Bees", 0, std::make_shared < AdjustedDifficultyCurve>(1.5f));

	Skill skillAdjustedInterfaceCopy = Skill(skillAdjustedInterface);

	// We intend on the Curve being shared amongst Skills as no real need to copy over a interface or its general struct other than whats needed.
	if (skillAdjustedInterface.getCurve() != (skillAdjustedInterfaceCopy.getCurve())) {
		return false;
	}

	// Equal amount should return base time (should be 60.0f * 1.5f as that's multiple)
	else if (skillAdjustedInterface.getCurve()->CalculateCost(60.0f, 0, 0) != (60.0f * 1.5f)) {
		return false;
	}
	else if (skillAdjustedInterface.getCurve()->CalculateCost(60.0f, 0, 0) != skillAdjustedInterfaceCopy.getCurve()->CalculateCost(60.0f, 0, 0)) {
		return false;
	}


	// Should be linear, but with higher multiple so check with known multiple to see if properly did calculation
	else if (skillAdjustedInterface.getCurve()->CalculateCost(60.0f, 3, 0) != ((60.0f * 1.5f) + (1.5f * 3))) {
		return false;
	}
	else if (skillAdjustedInterface.getCurve()->CalculateCost(60.0f, 3, 0) != skillAdjustedInterfaceCopy.getCurve()->CalculateCost(60.0f, 3, 0)) {
		return false;
	}

	// Should be linear, but with higher multiple so check with known multiple to see if properly did calculation
	else if (skillAdjustedInterface.getCurve()->CalculateCost(60.0f, 0, 3) != ((60.0f * 1.5f) - (1.5f * 3))) {
		return false;
	}
	else if (skillAdjustedInterface.getCurve()->CalculateCost(60.0f, 0, 3) != skillAdjustedInterfaceCopy.getCurve()->CalculateCost(60.0f, 0, 3)) {
		return false;
	}

	// If goes negative, should return 0.0f for instant finishing
	else if (skillAdjustedInterface.getCurve()->CalculateCost(60.0f, 0, 120) != 0.0f) {
		return false;
	}
	else if (skillAdjustedInterface.getCurve()->CalculateCost(60.0f, 0, 120) != skillAdjustedInterfaceCopy.getCurve()->CalculateCost(60.0f, 0, 120)) {
		return false;
	}

	return true;

}

bool testCopyRandomInterface()
{


	// Should set interface to linear as default.
	Skill skillRandomInterface = Skill("Skill One", "Apple Bees", 0, std::make_shared <RandomizedDifficultyCurve>());

	Skill skillRandomInterfaceSecond = Skill(skillRandomInterface);

	if (skillRandomInterface.getCurve() != (skillRandomInterfaceSecond.getCurve())) {
		return false;
	}

	return true;

}

bool testCopyLinearInterface()
{


	// Should set interface to linear as default.
	Skill skillLinearInterface = Skill("Skill One", "Apple Bees", 0, std::make_shared < LinearDifficultyCurve>());

	Skill skillLineaInterfaceSecond = Skill(skillLinearInterface);

	if (skillLinearInterface.getCurve() != (skillLineaInterfaceSecond.getCurve())) {
		return false;
	}

	return true;

}

bool testDemo()
{
	// Founding owners
	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> companyOwners = std::make_unique<std::shared_ptr<Employees::Employee>[]>(3);
	companyOwners[0] = std::make_shared<Employees::Employee>("Jimmy");
	companyOwners[1] = std::make_shared<Employees::Employee>("John");
	companyOwners[2] = std::make_shared<Employees::Employee>("Grimpo");

	// Owners start in company initially
	std::unique_ptr<Company> theCompany = std::make_unique<Company>("MANNCO", std::move(companyOwners), 3);

	if (theCompany->getAmountEmployees() != 3) {
		return false;
	}

	
	std::unique_ptr<std::unique_ptr<Skill>[]> skillHandler = std::make_unique<std::unique_ptr<Skill>[]>(1);

	skillHandler[0] = std::make_unique<Skill>("Skill Linear", "Spicy Hazlenut", 10);

	SkillSet team2SkillSet(std::move(skillHandler), 1);

	// Get new hires in container before adding to company so can do checks on company
	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> companyEmployees = std::make_unique<std::shared_ptr<Employees::Employee>[]>(9);
	companyEmployees[0] = std::make_shared<Employees::Employee>("Tim");
	companyEmployees[1] = std::make_shared<Employees::Employee>("Lrim");
	companyEmployees[2] = std::make_shared<Employees::Employee>("Plirm");

	companyEmployees[3] = std::make_shared<Employees::Employee>("Dlurm", team2SkillSet);
	companyEmployees[4] = std::make_shared<Employees::Employee>("Urm", team2SkillSet);
	companyEmployees[5] = std::make_shared<Employees::Employee>("Mur", team2SkillSet);

	companyEmployees[6] = std::make_shared<Employees::Employee>("Glirm");
	companyEmployees[7] = std::make_shared<Employees::Employee>("Rurm");
	companyEmployees[8] = std::make_shared<Employees::Employee>("Germ");

	// Add them all on first team
	for (unsigned int i = 0; i < 9; i++) {

		theCompany->addEmployee(companyEmployees[i]);

	}

	

	// Add them to a team
	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> teamEmployees1 = std::make_unique<std::shared_ptr<Employees::Employee>[]>(3);
	teamEmployees1[0] = companyEmployees[0];
	teamEmployees1[1] = companyEmployees[1];
	teamEmployees1[2] = companyEmployees[2];
	theCompany->createTeam("Team 10", std::move(teamEmployees1), 3);

	// Check if employees are properly added to the team
	if (theCompany->getTeam("Team 10")->getAmountEmployees() != 3) {
		return false;
	}

	// Add them all on second team
	theCompany->addEmployee(companyEmployees[3]);
	theCompany->addEmployee(companyEmployees[4]);
	theCompany->addEmployee(companyEmployees[5]);

	// Add them to a team
	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> teamEmployees2 = std::make_unique<std::shared_ptr<Employees::Employee>[]>(3);
	teamEmployees2[0] = companyEmployees[3];
	teamEmployees2[1] = companyEmployees[4];
	teamEmployees2[2] = companyEmployees[5];

	theCompany->createTeam("Team 11", std::move(teamEmployees2), 3);

	// Check if employees are properly added to the team
	if (theCompany->getTeam("Team 11")->getAmountEmployees() != 3) {
		return false;
	}

	// Add them all on third team
	theCompany->addEmployee(companyEmployees[6]);
	theCompany->addEmployee(companyEmployees[7]);
	theCompany->addEmployee(companyEmployees[8]);


	// Add them to a team
	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> teamEmployees3 = std::make_unique<std::shared_ptr<Employees::Employee>[]>(3);
	teamEmployees3[0] = companyEmployees[6];
	teamEmployees3[1] = companyEmployees[7];
	teamEmployees3[2] = companyEmployees[8];
	theCompany->createTeam("Team 12", std::move(teamEmployees3), 3);

	// Check if employees are properly added to the team
	if (theCompany->getTeam("Team 12")->getAmountEmployees() != 3) {
		return false;
	}

	// Default passed interface override of curve is linear.
	std::unique_ptr<std::unique_ptr<Skill>[]> linearsSkill = std::make_unique<std::unique_ptr<Skill>[]>(1);
	linearsSkill[0] = std::make_unique<Skill>("Skill Linear", "Spicy Hazlenut", 10);

	std::unique_ptr<Tasks::Task> linearTask = std::make_unique<Tasks::Task>("Task Linear", "Wet Fish", 60.0f, SkillSet(std::move(linearsSkill), 1));

	// Augment linear curve to half its original value.
	std::unique_ptr<std::unique_ptr<Skill>[]> augmentedSkill = std::make_unique<std::unique_ptr<Skill>[]>(1);
	augmentedSkill[0] = std::make_unique<Skill>("Skill Augmented", "Spicy Hazlenut", 10, std::make_unique<AdjustedDifficultyCurve>(0.5f));
	std::unique_ptr<Tasks::Task> augmentedTask = std::make_unique<Tasks::Task>("Task Augmented", "Wet Fish", 60.0f, SkillSet(std::move(augmentedSkill), 1));

	// Create randomly seeded curve.
	std::unique_ptr<std::unique_ptr<Skill>[]> randomSkill = std::make_unique<std::unique_ptr<Skill>[]>(1);
	randomSkill[0] = std::make_unique<Skill>("Skill Augmented", "Spicy Hazlenut", 10, std::make_unique<RandomizedDifficultyCurve>(33));
	std::unique_ptr<Tasks::Task> randomTask = std::make_unique<Tasks::Task>("Task Augmented", "Wet Fish", 60.0f, SkillSet(std::move(randomSkill), 1));

	// Give a linear difficulty task to two teams; one with people of proficiency, and people of none. People with prof. should have a lower estimate.

	if (!(theCompany->getTeam("Team 10")->estimateTask(*linearTask) > theCompany->getTeam("Team 11")->estimateTask(*linearTask))) {
		return false;
	}

	// Give task to two differing teams of differing employees but same proficiencies so should be equal estimate.
	else if ((theCompany->getTeam("Team 10")->estimateTask(*augmentedTask) != theCompany->getTeam("Team 12")->estimateTask(*augmentedTask))) {
		return false;
	}
	// Adjusted Curve will have 0.5f multiple and random is 2 -> 10 so should always be true if random is pulling correctly.
	else if (!(theCompany->getTeam("Team 10")->estimateTask(*randomTask) > theCompany->getTeam("Team 10")->estimateTask(*augmentedTask))) {
		return false;
	}

	// Adjusted Curve will have 0.5f multiple so should half estimate given it should give same estimate as linear but lower.
	else if (!(theCompany->getTeam("Team 10")->estimateTask(*linearTask) > theCompany->getTeam("Team 10")->estimateTask(*augmentedTask))) {
		return false;
	}


	// Disband employees
	for (int i = 0; i < 9; i++)
	{

		theCompany->removeEmployee(companyEmployees[i]);

	}

	// Make sure are removed from their associated teams as well.
	if (theCompany->getTeam("Team 10")->getAmountEmployees() != 0) {
		return false;
	}
	if (theCompany->getTeam("Team 11")->getAmountEmployees() != 0) {
		return false;
	}
	if (theCompany->getTeam("Team 12")->getAmountEmployees() != 0) {
		return false;
	}

	// Disband teams.
	theCompany->deleteTeam(theCompany->getTeam("Team 10"));
	theCompany->deleteTeam(theCompany->getTeam("Team 11"));
	theCompany->deleteTeam(theCompany->getTeam("Team 12"));

	if (theCompany->getAmountTeams() != 0) {
		return false;
	}


	return true;

};

bool testRealDemo()
{


	std::unique_ptr<std::unique_ptr<Skill>[]> handlersSkills = std::make_unique<std::unique_ptr<Skill>[]>(1);
	handlersSkills[0] = std::make_unique<Skill>("Skillenheimer 1", "Typenheimer", 2);


	std::unique_ptr<std::unique_ptr<Skill>[]> dandlersSkills = std::make_unique<std::unique_ptr<Skill>[]>(2);
	dandlersSkills[0] = std::make_unique<Skill>("Skillenheimer 1", "Typenheimer", 3);
	dandlersSkills[1] = std::make_unique<Skill>("Skillenheimer 2", "Typen", 100);

	SkillSet handler = SkillSet(std::move(handlersSkills), 1);
	SkillSet dandler = SkillSet(std::move(dandlersSkills), 2);


	SkillSet additionSetForward = handler + dandler;
	SkillSet additionSetBackward = dandler + handler;

	if (additionSetForward.getSkillSize() != 2) {
		return false;
	}
	else if (additionSetForward.getSkills()[0]->getName() != "Skillenheimer 1" || additionSetForward.getSkills()[0]->getLevel() != 5) {
		return false;
	}
	else if (additionSetForward.getSkills()[1]->getName() != "Skillenheimer 2" || additionSetForward.getSkills()[1]->getLevel() != 100) {
		return false;
	}
	else if (additionSetForward.getSkills()[0]->getLevel() != additionSetBackward.getSkills()[0]->getLevel() || additionSetForward.getSkills()[1]->getLevel() != additionSetBackward.getSkills()[1]->getLevel()) {
		return false;
	}
	
	additionSetForward -= dandler;

	if (additionSetForward.getSkillSize() != 2) {
		return false;
	}
	else if (additionSetForward.getSkills()[0]->getName() != "Skillenheimer 1" || additionSetForward.getSkills()[0]->getLevel() != 2) {
		return false;
	}
	else if (additionSetForward.getSkills()[1]->getName() != "Skillenheimer 2" || additionSetForward.getSkills()[1]->getLevel() != 0) {
		return false;
	}

	SkillSet subtractionSetForward = handler - dandler;
	SkillSet subtractionSetBackward = dandler - handler;

	if (subtractionSetForward.getSkillSize() != 2) {
		return false;
	}
	else if (subtractionSetForward.getSkills()[0]->getName() != "Skillenheimer 1" || subtractionSetForward.getSkills()[0]->getLevel() != 0) {
		return false;
	}
	else if (subtractionSetForward.getSkills()[1]->getName() != "Skillenheimer 2" || subtractionSetForward.getSkills()[1]->getLevel() != 0) {
		return false;
	}
	else if (subtractionSetBackward.getSkills()[0]->getName() != "Skillenheimer 1" || subtractionSetBackward.getSkills()[0]->getLevel() != 1) {
		return false;
	}
	else if (subtractionSetBackward.getSkills()[1]->getName() != "Skillenheimer 2" || subtractionSetBackward.getSkills()[1]->getLevel() != 100) {
		return false;
	}

	subtractionSetForward += dandler;

	if (subtractionSetForward.getSkillSize() != 2) {
		return false;
	}
	else if (subtractionSetForward.getSkills()[0]->getName() != "Skillenheimer 1" || subtractionSetForward.getSkills()[0]->getLevel() != 3) {
		return false;
	}
	else if (subtractionSetForward.getSkills()[1]->getName() != "Skillenheimer 2" || subtractionSetForward.getSkills()[1]->getLevel() != 100) {
		return false;
	}


	SkillSet multiplicationSet = dandler * 2;

	if (multiplicationSet.getSkillSize() != 2) {
		return false;
	}
	else if (multiplicationSet.getSkills()[0]->getName() != "Skillenheimer 1" || multiplicationSet.getSkills()[0]->getLevel() != 6) {
		return false;
	}
	else if (multiplicationSet.getSkills()[1]->getName() != "Skillenheimer 2" || multiplicationSet.getSkills()[1]->getLevel() != 200) {
		return false;
	}

	multiplicationSet /= 2;

	if (multiplicationSet.getSkillSize() != 2) {
		return false;
	}
	else if (multiplicationSet.getSkills()[0]->getName() != "Skillenheimer 1" || multiplicationSet.getSkills()[0]->getLevel() != 3) {
		return false;
	}
	else if (multiplicationSet.getSkills()[1]->getName() != "Skillenheimer 2" || multiplicationSet.getSkills()[1]->getLevel() != 100) {
		return false;
	}

	
	SkillSet divisionSet = dandler / 2;

	if (divisionSet.getSkillSize() != 2) {
		return false;
	}
	else if (divisionSet.getSkills()[0]->getName() != "Skillenheimer 1" || divisionSet.getSkills()[0]->getLevel() != 1) {
		return false;
	}
	else if (divisionSet.getSkills()[1]->getName() != "Skillenheimer 2" || divisionSet.getSkills()[1]->getLevel() != 50) {
		return false;
	}

	divisionSet *= 2;

	if (divisionSet.getSkillSize() != 2) {
		return false;
	}
	else if (divisionSet.getSkills()[0]->getName() != "Skillenheimer 1" || divisionSet.getSkills()[0]->getLevel() != 2) {
		return false;
	}
	else if (divisionSet.getSkills()[1]->getName() != "Skillenheimer 2" || divisionSet.getSkills()[1]->getLevel() != 100) {
		return false;
	}

	SkillSet duplicatesSet = dandler;

	if (duplicatesSet != dandler) {
		return false;
	}
	
	duplicatesSet = handler;

	if (duplicatesSet == dandler) {
		return false;
	}

	return true;

}




void callUnitTests()
{

	if (!demoSkillSetFunctionality()) {
		throw errno;
	}
	else if (!demoSkillSetCopy()) {
		throw errno;
	}
	else if (!testTeamAddingAndRemoving()) {
		throw errno;
	}
	else if (!testTeamEstimatesSkill()) {
		throw errno;
	}
	else if (!testTeamEstimatesNoSkill()) {
		throw errno;
	}
	else if (!testCompanyHireAndFire()) {
		throw errno;
	}
	else if (!testCompanyFindAndRemoveEmptyTeams()) {
		throw errno;
	}
	else if (!testCompanyEstimateWithRehires()) {
		throw errno;
	}
	else if (!testCompanyRetrievals()) {
		throw errno;
	}
	else if (!testCompanyTeamDestruction()) {
		throw errno;
	}
	else if (!testDefaultInterface()) {
		throw errno;
	}
	else if (!testUnseededRandomizedInterface()) {
		throw errno;
	}
	else if (!testSeededRandomInterface()) {
		throw errno;
	}
	else if (!testRandomInterface()) {
		throw errno;
	}
	else if (!testAdjustedInterface()) {
		throw errno;
	}
	else if (!testCopyInterface()) {
		throw errno;
	}
	else if (!testCopyRandomInterface()) {
		throw errno;
	}
	else if (!testCopyLinearInterface()) {
		throw errno;
	}
	else if (!testDemo()) {
		throw errno;
	}
	else if (!testRealDemo()) {
		throw errno;
	}
	
	// Call leak tests / corruption
	testEmployeeThreeAndFree();
	testTaskThreeAndFree();
	testTeamThreeAndFree();
	testCompanyThreeAndFree();

}


int main()
{

	// If want to check checks all previous projects capatiability.
	//callUnitTests();

	Company MANNCO("MANNCO");

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


	std::cout << "Demo p1: Linear Task With Skill and Without\n";

	std::cout << "  Creating Linear SkillSet of size 3, each with level 10 (proficiency) for 3 Employees..\n";

	std::unique_ptr<std::unique_ptr<Skill>[]> linearSkills = std::make_unique<std::unique_ptr<Skill>[]>(3);
	linearSkills[0] = std::make_unique<Skill>("Skillenheimer 1", "Cranberry", 10);
	linearSkills[1] = std::make_unique<Skill>("Skillenheimer 2", "Saw Dust", 10);
	linearSkills[2] = std::make_unique<Skill>("Skillenheimer 3", "Brown Substance", 10);
	SkillSet linearSkillSet(std::move(linearSkills), 3);

	MANNCO.addEmployee(std::make_shared<Employees::Employee>("John", linearSkillSet));
	MANNCO.addEmployee(std::make_shared<Employees::Employee>("Jimmy", linearSkillSet));
	MANNCO.addEmployee(std::make_shared<Employees::Employee>("Jonah", linearSkillSet));

	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> linearSkilledEmployeesCopy = std::make_unique<std::shared_ptr<Employees::Employee>[]>(3);
	linearSkilledEmployeesCopy[0] = MANNCO.getEmployee("John");
	linearSkilledEmployeesCopy[1] = MANNCO.getEmployee("Jimmy");
	linearSkilledEmployeesCopy[2] = MANNCO.getEmployee("Jonah");

	MANNCO.createTeam("Team Linear", std::move(linearSkilledEmployeesCopy), 3);


	std::cout << "  Creating No Skilled SkillSet of size 0 for 3 Employees..\n";

	MANNCO.addEmployee(std::make_shared<Employees::Employee>("Brittany"));
	MANNCO.addEmployee(std::make_shared<Employees::Employee>("Brock"));
	MANNCO.addEmployee(std::make_shared<Employees::Employee>("Brutus"));

	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> notSkilledEmployeesCopy = std::make_unique<std::shared_ptr<Employees::Employee>[]>(3);
	notSkilledEmployeesCopy[0] = MANNCO.getEmployee("Brittany");
	notSkilledEmployeesCopy[1] = MANNCO.getEmployee("Brock");
	notSkilledEmployeesCopy[2] = MANNCO.getEmployee("Brutus");

	MANNCO.createTeam("Team No Skill :/", std::move(notSkilledEmployeesCopy), 3);

	std::unique_ptr<Tasks::Task> linearTask = std::make_unique<Tasks::Task>("Linear Task Difficulty 10", "Mold", 60.0f, linearSkillSet);

	std::cout << "  Skill Level 10 Employees team of 3 task estimate: " << MANNCO.getTeam("Team Linear")->estimateTask(*linearTask) << '\n';
	std::cout << "  No Skill Level Employees team of 3 task estimate (should be higher than skilled team): " << MANNCO.getTeam("Team No Skill :/")->estimateTask(*linearTask) << '\n';

	MANNCO.deleteTeam(MANNCO.getTeam("Team No Skill :/"));

	MANNCO.getTeam("Team Linear")->addEmployee(std::make_shared<Employees::Employee>("Brittany"));
	MANNCO.getTeam("Team Linear")->addEmployee(std::make_shared<Employees::Employee>("Brock"));
	MANNCO.getTeam("Team Linear")->addEmployee(std::make_shared<Employees::Employee>("Brutus"));

	std::cout << "  Skill Level 10 Employees team of 6 task estimate should be lower than linear with 3 teammates: " << MANNCO.getTeam("Team Linear")->estimateTask(*linearTask) << '\n';

	MANNCO.deleteTeam(MANNCO.getTeam("Team Linear"));

	MANNCO.removeEmployee(MANNCO.getEmployee("John"));
	MANNCO.removeEmployee(MANNCO.getEmployee("Jonah"));
	MANNCO.removeEmployee(MANNCO.getEmployee("Brutus"));

	MANNCO.removeEmployee(MANNCO.getEmployee("Jimmy"));
	MANNCO.removeEmployee(MANNCO.getEmployee("Brock"));
	MANNCO.removeEmployee(MANNCO.getEmployee("Brittany"));


	std::cout << "  Company should now have no Employees, or Teams.. All Dissolved.\n";
	std::cout << "    Team Count " << MANNCO.getAmountTeams() << " Employees Count " << MANNCO.getAmountEmployees() << "\n\n\n";

	if (MANNCO.getAmountTeams() != 0 || MANNCO.getAmountEmployees() != 0) {
		return false;
	}

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


	std::cout << "Demo p2: SkillSet Addition Subtraction, Multiplication, and Division\n";

	std::cout << "  Making two Skills, one with a linear difficulty curve of level 2 and another with a adjusted difficulty curve of 0.005f\n";
	std::unique_ptr<std::unique_ptr<Skill>[]> linearDifficultySkill = std::make_unique<std::unique_ptr<Skill>[]>(1);
	linearDifficultySkill[0] = std::make_unique<Skill>("Skillenheimer 1", "Typenheimer", 10);

	std::unique_ptr<std::unique_ptr<Skill>[]> randomDifficultySkill = std::make_unique<std::unique_ptr<Skill>[]>(1);
	randomDifficultySkill[0] = std::make_unique<Skill>("Skillenheimer 2", "Typenheimer", 10, std::make_shared<RandomizedDifficultyCurve>());

	std::unique_ptr<std::unique_ptr<Skill>[]> adjustedDifficultySkill = std::make_unique<std::unique_ptr<Skill>[]>(1);
	adjustedDifficultySkill[0] = std::make_unique<Skill>("Skillenheimer 3", "Typenheimer", 10, std::make_shared<AdjustedDifficultyCurve>(0.5f));

	std::cout << "  Adding together linearDifficultySkill + adjustedDifficultySkill\n";
	SkillSet handler = SkillSet(std::move(linearDifficultySkill), 1);
	SkillSet dandler = SkillSet(std::move(adjustedDifficultySkill), 1);

	SkillSet linearAndAdjusted = handler + dandler;

	std::unique_ptr<Tasks::Task> linearAndAdjustedTask = std::make_unique<Tasks::Task>("Linear Task Difficulty 10", "Mold", 60.0f, linearAndAdjusted);

	MANNCO.addEmployee(std::make_shared<Employees::Employee>("Jeremy", linearAndAdjusted));
	MANNCO.addEmployee(std::make_shared<Employees::Employee>("Jerma", linearAndAdjusted));
	MANNCO.addEmployee(std::make_shared<Employees::Employee>("Joeseph", linearAndAdjusted));

	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> noSkillsEmployeesCopy = std::make_unique<std::shared_ptr<Employees::Employee>[]>(3);
	noSkillsEmployeesCopy[0] = MANNCO.getEmployee("Jeremy");
	noSkillsEmployeesCopy[1] = MANNCO.getEmployee("Jerma");
	noSkillsEmployeesCopy[2] = MANNCO.getEmployee("Joeseph");

	MANNCO.createTeam("Team No Skill :/", std::move(noSkillsEmployeesCopy), 3);

	std::cout << "  Should be lower than 80, as that is longest expected with no skilled employees on two level 10 skills: " << MANNCO.getTeam("Team No Skill :/")->estimateTask(*linearAndAdjustedTask) << '\n';


	std::cout << "  Adding new skill with random difficulty curve Into Skilllset\n";

	SkillSet pandler = SkillSet(std::move(randomDifficultySkill), 1);
	linearAndAdjusted += pandler;

	std::unique_ptr<Tasks::Task> linearAndAdjustedAndRandomizedTask = std::make_unique<Tasks::Task>("Linear Task Difficulty 10", "Mold", 60.0f, linearAndAdjusted);

	std::cout << "  Should be higher than previous at 30, as now we have new skill of difficulty 10 which has a randomized increase in runtime by at least 2: " << MANNCO.getTeam("Team No Skill :/")->estimateTask(*linearAndAdjustedAndRandomizedTask) << '\n';

	std::unique_ptr<Tasks::Task> linearAndAdjustedAndRandomizedMultiple10Task = std::make_unique<Tasks::Task>("Linear Task Difficulty 10", "Mold", 60.0f, linearAndAdjusted * 10);

	std::cout << "  Multiplying each level in the skillset by 10; should dramatically increase runtime " << MANNCO.getTeam("Team No Skill :/")->estimateTask(*linearAndAdjustedAndRandomizedMultiple10Task) << '\n';

	std::unique_ptr<Tasks::Task> linearAndAdjustedAndRandomizedDivisor2Task = std::make_unique<Tasks::Task>("Linear Task Difficulty 10", "Mold", 60.0f, *linearAndAdjustedAndRandomizedMultiple10Task->getSkillSet() / 10);

	std::cout << "  Dividing each level in the skillset of the multiple 10 skillset by 10; should dramatically decrease runtime " << MANNCO.getTeam("Team No Skill :/")->estimateTask(*linearAndAdjustedAndRandomizedDivisor2Task) << '\n';

	SkillSet newSkillSet = linearAndAdjusted - (linearAndAdjusted * 10);

	std::cout << "  Subtracting Levels By Current Levels * 10; should return 0 for all skill levels: " << newSkillSet.getSkills()[0]->getLevel() << " == " << newSkillSet.getSkills()[1]->getLevel() << " == " << newSkillSet.getSkills()[2]->getLevel() << " == 0\n";

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	std::cout << "Demo p3: SkillSet Assignment arithmetic operations\n";

	std::cout << "  Making two skills, same name ( Skillenheimer 1 ), different levels\n";
	std::unique_ptr<std::unique_ptr<Skill>[]> linearDifficultySkillInitial10 = std::make_unique<std::unique_ptr<Skill>[]>(1);
	linearDifficultySkillInitial10[0] = std::make_unique<Skill>("Skillenheimer 1", "Typerheimer", 10);

	std::unique_ptr<std::unique_ptr<Skill>[]> linearDifficultySkillInitial2 = std::make_unique<std::unique_ptr<Skill>[]>(1);
	linearDifficultySkillInitial2[0] = std::make_unique<Skill>("Skillenheimer 1", "Typenheimer", 2);

	handler = SkillSet(std::move(linearDifficultySkillInitial10), 1);
	dandler = SkillSet(std::move(linearDifficultySkillInitial2), 1);

	handler -= dandler;

	std::cout << "  Subtracting 2 levels from level 10 (should print 8): " << handler.getSkills()[0]->getLevel() << '\n'; \

		handler += dandler;

	std::cout << "  Adding 2 levels from level 8 (should print 10): " << handler.getSkills()[0]->getLevel() << '\n';

	handler *= 2;

	std::cout << "  Multiplying by 2 from level 10 (should print 20): " << handler.getSkills()[0]->getLevel() << '\n';

	handler /= 2;

	std::cout << "  Dividing by 2 from level 20 (should print 10): " << handler.getSkills()[0]->getLevel() << '\n';

	dandler -= handler;

	std::cout << "  Subtracting 10 levels from level 2 (should print 0 [should clamp]): " << dandler.getSkills()[0]->getLevel() << '\n'; \


		// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		std::cout << "Demo p4: SkillSet operator= definitions\n";

	// Create two sets of skills with different levels
	linearDifficultySkill = std::make_unique<std::unique_ptr<Skill>[]>(1);
	linearDifficultySkill[0] = std::make_unique<Skill>("Skillenheimer 1", "Typerheimer", 10);

	std::unique_ptr<std::unique_ptr<Skill>[]> linearDifficultySkill2 = std::make_unique<std::unique_ptr<Skill>[]>(1);
	linearDifficultySkill2[0] = std::make_unique<Skill>("Skillenheimer 1", "Typenheimer", 2);

	std::unique_ptr<std::unique_ptr<Skill>[]> linearDifficultySkill3 = std::make_unique<std::unique_ptr<Skill>[]>(1);
	linearDifficultySkill3[0] = std::make_unique<Skill>("Skillenheimer 2", "Typepheimer", 2);

	// Create SkillSets from the skills
	handler = SkillSet(std::move(linearDifficultySkill), 1);
	dandler = SkillSet(std::move(linearDifficultySkill2), 1);
	pandler = SkillSet(std::move(linearDifficultySkill3), 1);

	// Test assignment operator=
	std::cout << "  Testing assignment operator=:\n";
	handler = dandler;
	std::cout << "  After assignment, handler's skill level (should be 2): " << handler.getSkills()[0]->getLevel() << '\n';

	// Test move assignment operator=
	std::cout << "  Testing move assignment operator=:\n";
	SkillSet cutOperatorEqual = std::move(handler);
	std::cout << "  After move assignment, cutOperatorEqual's skill level (should be 2): " << cutOperatorEqual.getSkills()[0]->getLevel() << '\n';

	std::cout << "  Check if cutOperatorEqual has same skills as handler (operator==) [should be true]: " << (cutOperatorEqual == handler) << '\n';


	std::cout << "  Check if ( cutOperatorEqual + new skill not in handler ) has same skills as handler (operator!=) [should be true]: " << (handler != (cutOperatorEqual + pandler)) << '\n';

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	return 0;

}