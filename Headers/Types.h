#ifndef TYPES_H
#define TYPES_H

/*THIS IS A DEFINITIONS FILE
In here I put all generic and static variables that I can't put in a class or other specific file
Think of this as where my global variables are.
*/

#include <array>
#include <string>
#include <unordered_map>

namespace records
{
	static constexpr int min_dollar_amount = 1;
	static constexpr int max_dollar_amount = 30000;
	static constexpr int first_employee_number = 1;
	static constexpr int last_employee_number = 100;
	static constexpr float default_starting_salary = 30000.0f;

	//When the command help is called, it loops through this dictionary printing each of the options
	static std::unordered_map<std::string, std::string> help_output = 
	{ 
		{"hire", "Adds employee to the database.\n\tIf an employee already exists, rehire them\n"},
		{"fire", "Fire an employee, but keep them in the database\n"},
		{"promote", "Promotes an employee of choice\n"},
		{"demote", "Demotes an employee of choice\n"},
		{"list all", "Displays a list of all current and former employees\n"},
		{"list current", "Displays a list of all current employees\n"},
		{"list former", "Displays a list of former employees\n"},
		{"quit", "Quits the program\n"},
		{"help", "Displays this menu\n"}
	};

	//Use this to print the main menu
	static std::array<std::string, 9> menu_output = 
	{ 
		"Hire a new employee"
		,"Fire employee"
		,"Promote an employee"
		,"Demote an employee"
		,"List all employees"
		,"List current employees"
		,"List former employees"
		,"type \'help\' to access a list of available commands"
		,"Quit" 
	};

}

#endif // TYPES_H
