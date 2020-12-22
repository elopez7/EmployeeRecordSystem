#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

namespace records
{
	class Employee
	{
	public:
		//Constructors
		//Default Constructor
		Employee(std::string firstName, std::string lastName, int employeeNumber, float salary, bool hired);
		
		//Copy Constructor
		Employee(const Employee& emp) noexcept;

		//Move Constructor
		Employee(Employee&& emp) noexcept;

		//Copy Assignment
		Employee& operator= (const Employee& emp) noexcept;

		//Move Assignment
		Employee& operator= (Employee&& emp) noexcept;
		
		//Functions
		void promote(float raise_amount = 1000);
		void demote(float demerit_amount = 1000);
		void hire();
		void fire();
		void display() const;

		//Getters and setters
		void set_first_name(const std::string& first_name);
		const std::string& get_first_name() const;

		void set_last_name(const std::string& last_name);
		const std::string& get_last_name() const;

		void set_employee_number(int employee_number);
		int get_employee_number() const;

		void set_salary(float new_salary);
		float get_salary() const;

		bool get_is_hired() const;
	private:
		std::string m_first_name;
		std::string m_last_name;
		int m_employee_number;
		float m_salary;
		bool m_hired;
	};
}
#endif // !EMPLOYEE_H