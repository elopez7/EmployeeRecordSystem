// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <fmt/format.h>

#include "Types.h"
#include "Employee.h"

namespace records
{
	Employee::Employee(std::string firstName, std::string lastName, int employeeNumber, float salary, bool hired)
	: m_first_name{ std::move(firstName) } //Using move semantics we ensure the constructor takes each argument by value and moves it into the member
	, m_last_name{ std::move(lastName) }   //I had no idea we could do that
	, m_employee_number{ employeeNumber }
	, m_salary{ salary }
	, m_hired{ hired }
	{

	}

	//Copy Constructor
	Employee::Employee(const Employee& emp) noexcept
	: m_first_name{ std::move(emp.m_first_name) }
	, m_last_name{ std::move(emp.m_last_name) }
	, m_employee_number{ emp.m_employee_number }
	, m_salary{ emp.m_salary }
	, m_hired{ emp.m_hired }
	{

	}

	//Move Constructor
	Employee::Employee(Employee&& emp) noexcept
	: m_first_name{ std::move(emp.m_first_name) }
	, m_last_name{ std::move(emp.m_last_name) }
	, m_employee_number{ emp.m_employee_number }
	, m_salary{ emp.m_salary }
	, m_hired{ emp.m_hired }
	{
		
	}

	//Copy Assignment
	Employee& Employee::operator=(const Employee& emp) noexcept
	{
		m_first_name = emp.m_first_name;
		m_last_name = emp.m_last_name;
		m_employee_number = emp.m_employee_number;
		m_salary = emp.m_salary;
		m_hired = emp.m_hired;
		return *this;
	}

	//Move assignment Operator
	Employee& Employee::operator=(Employee&& emp) noexcept
	{
		//Is this a move assignment to myself?
		if (this != &emp)
		{
			m_first_name = std::move(emp.m_first_name);
			m_last_name = std::move(emp.m_last_name);
			m_employee_number = emp.m_employee_number;
			m_salary = emp.m_salary;
			m_hired = emp.m_hired;
		}
		return *this;
	}

	void Employee::promote(float raise_amount)
	{
		set_salary(get_salary() + raise_amount);
	}

	void Employee::demote(float demerit_amount)
	{
		set_salary(get_salary() - demerit_amount);
	}

	void Employee::hire()
	{
		m_hired = true;
	}

	void Employee::fire()
	{
		m_hired = false;
	}

	void Employee::display() const
	{
		fmt::print
		(
			"Employee: {0}, {1}\n"
			"-----------------------------------\n"
			"{2}\n"
			"Employee Number {3}\n"
			"Salary: ${4}\n"
			,get_last_name(), get_first_name(), (m_hired ? "Current Employee" : "Former Employee"), get_employee_number(), get_salary());
		
		fmt::print("-----------------------------------\n");
	}

	void Employee::set_first_name(const std::string& first_name)
	{
		m_first_name = first_name;
	}

	const std::string& Employee::get_first_name() const
	{
		return m_first_name;
	}

	void Employee::set_last_name(const std::string& last_name)
	{
		m_last_name = last_name;
	}

	const std::string& Employee::get_last_name() const
	{
		return m_last_name;
	}

	void Employee::set_employee_number(int employee_number)
	{
		m_employee_number = employee_number;
	}

	int Employee::get_employee_number() const
	{
		return m_employee_number;
	}

	void Employee::set_salary(float new_salary)
	{
		m_salary = new_salary;
	}

	float Employee::get_salary() const
	{
		return m_salary;
	}

	bool Employee::get_is_hired() const
	{
		return m_hired;
	}

}