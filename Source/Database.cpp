// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <iostream>
#include <stdexcept>
#include <fmt/format.h>
#include "Types.h"
#include "Database.h"

namespace records
{
	Database::Database() : m_next_employee_number{ first_employee_number }
	{

	}

	records::Employee& Database::add_employee(const std::string& first_name, const std::string& last_name)
	{
		m_employees.push_back(Employee{first_name, last_name, m_next_employee_number++,  default_starting_salary, true} );
		return m_employees[m_employees.size() - 1];
	}

	records::Employee& Database::get_employee(int employee_number)
	{
		for (auto& employee : m_employees)
		{
			if (employee.get_employee_number() == employee_number)
			{
				return employee;
			}
		}
		throw std::runtime_error("No employee found");
	}

	records::Employee& Database::get_employee(const std::string& first_name, const std::string& last_name)
	{
		for (auto& employee : m_employees)
		{
			if (employee.get_first_name() == first_name && employee.get_last_name() == last_name)
			{
				return employee;
			}
			throw std::runtime_error("No employee found");
		};
	}

	void Database::display_all() const
	{
		fmt::print(
			"\n"
			"*{0:*^{2}}*\n"
			"-{1: ^{2}}-\n"
			"*{0:*^{2}}*\n"
			, "", "LIST OF CURRENT AND PAST EMPLOYEES", 60);
		for (const auto& employee : m_employees)
		{
			employee.display();
		}
		fmt::print("-----------------------------------\n");
	}

	void Database::display_current() const
	{
		for (const auto& employee : m_employees)
		{
			if (employee.get_is_hired())
			{
				employee.display();
			}
		}
		fmt::print("-----------------------------------\n");

	}

	void Database::display_former() const
	{
		for (const auto& employee : m_employees)
		{
			if (!employee.get_is_hired())
			{
				employee.display();
			}
		}
		fmt::print("-----------------------------------\n");
	}
}