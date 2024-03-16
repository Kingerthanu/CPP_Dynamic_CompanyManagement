#include "company.h"

Company::Company(const std::string& companyName, std::unique_ptr<std::shared_ptr<Employees::Employee>[]> companyEmployees, const unsigned int& employeesSize, std::unique_ptr<std::shared_ptr<Team>[]> companyTeams, const unsigned int& teamsSize)
{

	this->name = companyName;
	this->employeesList_size = employeesSize;
	this->teamsList_size = teamsSize;

	// If we have a non-zero amount of employees, move over from provided pointer array
	if (companyEmployees) {

		this->employeesList = std::move(companyEmployees);

	}

	// If we have a non-zero amount of teams, move over from provided pointer array
	if (companyTeams) {

		this->teamsList = std::move(companyTeams);

	}



};


std::string Company::getName()
{

	return this->name;

};


Company::Company(const Company& toCopy)
{

	this->name = toCopy.name;

	this->employeesList_size = toCopy.employeesList_size;
	this->teamsList_size = toCopy.teamsList_size;

	this->employeesList = std::make_unique<std::shared_ptr<Employees::Employee>[]>(this->employeesList_size);
	this->teamsList = std::make_unique<std::shared_ptr<Team>[]>(this->teamsList_size);

	// Deep-Copy over employees from other.
	for (unsigned int i = 0; i < this->employeesList_size; i++) {

		// Make new shared using data of employee
		this->employeesList[i] = std::make_shared<Employees::Employee>(*toCopy.employeesList[i]);

	}

	// Deep-Copy over teams from other.
	for (unsigned int i = 0; i < this->teamsList_size; i++) {

		// Make new shared using data of team
		this->teamsList[i] = std::make_shared<Team>(*toCopy.teamsList[i]);

	}

};


Company& Company::operator=(const Company& toCopy)
{

	if (this == &toCopy) {

		return *this;

	}


	this->name = toCopy.name;

	this->employeesList_size = toCopy.employeesList_size;
	this->teamsList_size = toCopy.teamsList_size;

	this->employeesList = std::make_unique<std::shared_ptr<Employees::Employee>[]>(this->employeesList_size);
	this->teamsList = std::make_unique<std::shared_ptr<Team>[]>(this->teamsList_size);

	// Deep-Copy over employees from other.
	for (unsigned int i = 0; i < this->employeesList_size; i++) {

		// Make new shared using data of employee
		this->employeesList[i] = std::make_shared<Employees::Employee>(*toCopy.employeesList[i]);

	}

	// Deep-Copy over teams from other.
	for (unsigned int i = 0; i < this->teamsList_size; i++) {

		// Make new shared using data of team
		this->teamsList[i] = std::make_shared<Team>(*toCopy.teamsList[i]);

	}

	return *this;

};


Company::~Company()
{

	// Stack frees...

};


void Company::addEmployee(std::shared_ptr<Employees::Employee> newEmployee)
{

	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> handler = std::make_unique<std::shared_ptr<Employees::Employee>[]>(this->employeesList_size + 1);

	// Copy over pointers of previous.
	for (unsigned int i = 0; i < this->employeesList_size; i++) {

		handler[i] = this->employeesList[i];

	}

	// Now finally point to this (then increment our size up one).
	handler[this->employeesList_size++] = newEmployee;
	this->employeesList = std::move(handler);

};


void Company::removeEmployee(std::shared_ptr<Employees::Employee> existingEmployee)
{

	// Remove employees from teams they are on.
	for (unsigned int i = 0; i < this->teamsList_size; i++) {

		if (this->teamsList[i]->containsEmployee(existingEmployee)) {
			
			this->teamsList[i]->removeEmployee(existingEmployee->getName());

		}

	}

	std::unique_ptr<std::shared_ptr<Employees::Employee>[]> handler = std::make_unique<std::shared_ptr<Employees::Employee>[]>(this->employeesList_size - 1);

	for (unsigned int i = 0, handleI = 0; i < this->employeesList_size; i++) {

		// If employee to remove, deallocate, as we are liable for lifetime.
		if (existingEmployee == this->employeesList[i]) {
			
			// Let it leak (is stack)

		}
		else {
			// Add and increment in new container of size - 1.
			handler[handleI++] = this->employeesList[i];
		}

	}

	this->employeesList_size--;
	this->employeesList = std::move(handler);

};


void Company::createTeam(const std::string& teamName, std::unique_ptr<std::shared_ptr<Employees::Employee>[]> teamEmployees, const unsigned int& teamSize)
{

	std::unique_ptr<std::shared_ptr<Team>[]> handler = std::make_unique<std::shared_ptr<Team>[]>(this->teamsList_size + 1);

	// Copy over other teams.
	for (unsigned int i = 0; i < this->teamsList_size; i++) {

		handler[i] = this->teamsList[i];

	}

	// Now finally point to this (then increment our size up one).
	handler[this->teamsList_size++] = std::make_shared<Team>(teamName, std::move(teamEmployees), teamSize);

	this->teamsList = std::move(handler);

};


void Company::deleteTeam(std::shared_ptr<Team> existingTeam)
{

	std::unique_ptr<std::shared_ptr<Team>[]> handler = std::make_unique<std::shared_ptr<Team>[]>(this->teamsList_size - 1);

	for (unsigned int i = 0, handleI = 0; i < this->teamsList_size; i++) {

		// If team to remove, deallocate, as we are liable for lifetime.
		if (existingTeam == this->teamsList[i]) {

			// Let it leak (Stack free)

		}
		else {
			// Add and increment in new container of size - 1.
			handler[handleI++] = this->teamsList[i];
		}

	}


	this->teamsList_size--;
	this->teamsList = std::move(handler);

};


std::shared_ptr<Team> Company::getTeam(const std::string& teamName)
{

	unsigned int index = 0;

	while (index < this->teamsList_size) {

		if (this->teamsList[index]->getName() == teamName) {

			break; // Jump out prematurely if we found it midway.

		}

		index++;

	}

	return this->teamsList[index];

};


std::shared_ptr<Employees::Employee> Company::getEmployee(const std::string& employeeName)
{

	unsigned int index = 0;

	while (index < this->employeesList_size) {

		if (this->employeesList[index]->getName() == employeeName) {

			break; // Jump out prematurey if we found it midway.

		}

		index++;

	}

	return this->employeesList[index];

};


unsigned int Company::getAmountTeams()
{

	return this->teamsList_size;

};


unsigned int Company::getAmountEmployees()
{

	return this->employeesList_size;

};