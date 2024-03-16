#include "team.h"


bool Team::containsEmployee(std::shared_ptr<Employees::Employee> toFind)
{

	// Go through each employee in team.
	for (unsigned int i = 0; i < this->employees_amount; i++) {

		if (this->employeeList[i] == toFind) {	// If same address, return found.

			return true;

		}

	}

	// If this far, not in team.
	return false;

};


unsigned int Team::getAmountEmployees()
{

	return this->employees_amount;

};


Team::Team(const std::string& teamName, std::unique_ptr<std::shared_ptr<Employees::Employee>[]> teamEmployees, const unsigned int& teamSize)
{

	this->name = teamName;
	this->employees_amount = teamSize;

	// If we have non-zero employees to add to team.
	if (teamEmployees) {

		this->employeeList = std::move(teamEmployees);
	}


};



Team::Team(const Team& toCopy)
{

	this->name = toCopy.name;
	this->employees_amount = toCopy.employees_amount;

	this->employeeList = std::make_unique<std::shared_ptr<Employees::Employee>[]>(this->employees_amount);

	// Deep-copy a new set of shared_ptrs to Employees.
	for (unsigned int i = 0; i < this->employees_amount; i++) {

		this->employeeList[i] = std::make_shared<Employees::Employee>(*toCopy.employeeList[i]);

	}

};


Team::~Team()
{

	// Stack Frees (including shared_ptr, unique_ptr)...

};


Team& Team::operator=(const Team& toCopy)
{

	if (this == &toCopy) {

		return *this;

	}

	this->name = toCopy.name;
	this->employees_amount = toCopy.employees_amount;

	this->employeeList = std::make_unique<std::shared_ptr<Employees::Employee>[]>(this->employees_amount);

	// Deep-copy a new set of shared_ptrs to Employees.
	for (unsigned int i = 0; i < this->employees_amount; i++) {

		this->employeeList[i] = std::make_shared<Employees::Employee>(*toCopy.employeeList[i]);

	}

	return *this;

};


std::string Team::getName()
{

	return this->name;

};


void Team::addEmployee(std::shared_ptr<Employees::Employee> newEmployee)
{

	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> handler = std::make_unique<std::shared_ptr<Employees::Employee>[]>(this->employees_amount + 1);

	// Go through each employee and copy over to size + 1
	for (unsigned int i = 0; i < this->employees_amount; i++) {

		handler[i] = this->employeeList[i];

	}

	// At end, add newest employee shared_pointer and increment size up.
	handler[this->employees_amount++] = newEmployee;

	this->employeeList = std::move(handler);

};



void Team::removeEmployee(const std::string& employeeName)
{

	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> handler = std::make_unique<std::shared_ptr<Employees::Employee>[]>(this->employees_amount - 1);

	// Go through each employee and copy over all but employeeName.
	for (unsigned int i = 0, handleI = 0; i < this->employees_amount; i++) {

		// Leak if is employee name as not liable...

		// If not employeeName add to new size - 1
		if (this->employeeList[i]->getName() != employeeName) {
			handler[handleI++] = this->employeeList[i];
		}

	}

	this->employees_amount--;
	this->employeeList = std::move(handler);

};


float Team::estimateTask(Tasks::Task& givenTask)
{

	// Holds sum of all employee estimations.
	float average = 0.0f;

	// For each employee, estimate time to take. Time is proportional to individual worktime + group team size which is statically 4.
	for (unsigned int i = 0; i < this->employees_amount; i++) {

		average += (this->employeeList[i]->estimateTask(givenTask) / (1 + (this->employees_amount / 4))); // Do task estimate by first summing all terms (infer team adds in groups of four)

	}

	// Return these individual estimates divided by amount of employees.
	return (average / this->employees_amount);

};

