#ifndef DATABASE_H
#define DATABASE_H

#include <vector>

#include "Employee.h"

namespace records
{
	class Database
	{
	public :
		Database();
		Employee& add_employee(const std::string& first_name, const std::string& last_name);
		Employee& get_employee(int employee_number);
		Employee& get_employee(const std::string& first_name, const std::string& last_name);

		void display_all() const;
		void display_current() const;
		void display_former() const;
	private:
		std::vector<Employee> m_employees;
		int m_next_employee_number;
	};
}

#endif // !DATABASE_H
