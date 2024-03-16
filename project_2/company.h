#ifndef COMPANY_H
#define COMPANY_H

#include "team.h"

/*
	Invariant:
		1.) Name of company will never change.
		2.) Team and Employee lists will have their size always stated in their respective _size member.
		3.) Team(s) and Employee(s) will be uniquely named.
*/
class Company
{

	private:
		std::string name;

		// Unique_ptr container of shared employee ptrs.
		std::unique_ptr<std::shared_ptr<Employees::Employee>[]> employeesList = std::unique_ptr<std::shared_ptr<Employees::Employee>[]>(0);
		unsigned int employeesList_size;

		// Unique_ptr container of shared team ptrs.
		std::unique_ptr<std::shared_ptr<Team>[]> teamsList = std::unique_ptr<std::shared_ptr<Team>[]>(0);
		unsigned int teamsList_size;

	public:
		/*
			Preconditions:
				1.) employees or team lists are stated, their respective size is also supplied.
				2.) companyName is non-empty ("").
			Postconditions:
				1.) No employee or team inputs are given, every member of that type is set to size 0.
				2.) Employee or team inputs are given, set every member of that type to respective argument.
		*/
		Company(const std::string& companyName, std::unique_ptr<std::shared_ptr<Employees::Employee>[]> companyEmployees = nullptr, const unsigned int& employeesSize = 0, std::unique_ptr<std::shared_ptr<Team>[]> companyTeams = nullptr, const unsigned int& teamsSize = 0);
	
		/*
			Postconditions:
				1.) Deep-copy over members (teams, employees) into new shared_ptrs which are independent of toCopy.
		*/
		Company(const Company& toCopy);

		/*
			Postconditions:
				1.) Deep-copy over members (teams, employees) into new shared_ptrs which are independent of toCopy.
		*/
		Company& operator=(const Company& toCopy);

		~Company();
		unsigned int getAmountTeams();
		unsigned int getAmountEmployees();
		std::string getName();

		/*
			Preconditions:
				1.) newEmployee is not already in company.
			Postconditions:
				1.) newEmployee added to the end of this->employeesList.
				2.) this->employeesList will be a new unique container of + 1 size.
				3.) this->employeesList_size will be incremented 1 after addition of employee.
		*/
		void addEmployee(std::shared_ptr<Employees::Employee> newEmployee);

		/*
			Preconditions:
				1.) existingEmployee to be existing in this->employeesList.
				2.) existingEmployee is the address stored in company.
			Postconditions:
				1.) existingEmployee will be removed from this->employeesList.
				2.) this->employeesList will be a new container of - 1 size.
				3.) this->employeesList_size will be decremented 1 after removal of employee.
		*/
		void removeEmployee(std::shared_ptr<Employees::Employee> existingEmployee);

		/*
			Preconditions:
				1.) Arguments are passed in the Team constructor.
				2.) teamName to be unique for company.
				3.) teamName is non-empty ("").
				4.) teamEmployees already are in company.
			Postconditions:
				1.) New Team(...) shared_ptr added to the end of this->teamsList.
				2.) this->teamsList will be a new container of + 1 size.
				3.) this->teamsList_size will be incremented 1 after addition of team.
		*/
		void createTeam(const std::string& teamName, std::unique_ptr<std::shared_ptr<Employees::Employee>[]> teamEmployees = nullptr, const unsigned int& teamSize = 0);

		/*
			Preconditions:
				1.) existingTeam existing in this->teamsList.
				2.) existingTeam is the same reference as in teamsList.
			Postconditions:
				1.) existingTeam is removed from this->teamsList.
				2.) this->teamsList will be a new container of - 1 size.
				3.) this->teamsList_size will be decremented 1 after removal of team.
		*/
		void deleteTeam(std::shared_ptr<Team> existingTeam);

		/*
			Preconditions:
				1.) teamName is existing name in this->teamsList.
			Postconditions:
				1.) Will return a new shared pointer pointing to the team index where the team with that name lies.
		*/
		std::shared_ptr<Team> getTeam(const std::string& teamName);

		/*
			Preconditions:
				1.) employeeName is existing name in this->teamsList.
				2.) employeeName is unique in this->teamsList.
			Postconditions:
				1.) Will return a new shared pointer pointing to the team index where the team with that name lies.
		*/
		std::shared_ptr<Employees::Employee> getEmployee(const std::string& employeeName);

};

#endif
