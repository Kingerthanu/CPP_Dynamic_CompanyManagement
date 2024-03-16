#ifndef TEAM_H
#define TEAM_H

#include <string>
#include "task.h"
#include "employee.h"

/*
	Invariant:
		1.) Name of team will never change.
		2.) employeeList will have its size given in employees_amount.
*/
class Team
{

	private:
		std::string name;
		unsigned int employees_amount;
		std::unique_ptr<std::shared_ptr<Employees::Employee>[]> employeeList = std::unique_ptr<std::shared_ptr<Employees::Employee>[]>(0);

	public:
		bool containsEmployee(std::shared_ptr<Employees::Employee> toFind);
		unsigned int getAmountEmployees();

		/*
			Preconditions:
				1.) Expects that if employees are given that size is also supplied.
				2.) teamName is non-empty
		*/
		Team(const std::string& teamName, std::unique_ptr<std::shared_ptr<Employees::Employee>[]> teamEmployees = nullptr, const unsigned int& teamSize = 0);
		
		/*
			Postconditions:
				1.)  Employees of toCopy will be shared with this instance.
		*/
		Team(const Team& toCopy);

		/*
			Postconditions:
				1.)  Employees of toCopy will be shared with this instance.
		*/
		Team& operator=(const Team& toCopy);

		~Team();
		std::string getName();

		/*
			Precondition:
				1.) newEmployee name is not already in this->employeeList.
			Postconditions:
				1.) Size of Employee list will increase by one and newEmployee will be at end.
				2.) this->employeeList will point to a new unique ptr of + 1 size.
		*/
		void addEmployee(std::shared_ptr<Employees::Employee> newEmployee);

		/*
			Preconditions:
				1.) Employee name is in the team.
			Postconditions:
				1.) this->employeeList will decrease size by one.
				2.) Named employee will be removed from team.
		*/
		void removeEmployee(const std::string& employeeName);

		/*
			Precondition:
				1.) this->employeeList is not empty.
			Postconditions:
				1.) Estimate will be returned in hours based on average of worktime of each employee on team in team groups of 4.
		*/
		float estimateTask(Tasks::Task& givenTask);

		

};

#endif
