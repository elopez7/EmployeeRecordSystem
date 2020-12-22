// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <iostream>
#include <limits>
#include <string_view>
#include <fmt/format.h>

#include "Types.h"
#include "UserInterface.h"
#include "Input_Validation.h"

namespace records
{
	void display_menu()
	{
		//Print Title
		fmt::print(
			"\n"
			"-{0:-^{2}}-\n"
			"#{1: ^{2}}#\n"
			"-{0:-^{2}}-\n"
			, "", "EMPLOYEE DATABASE MAIN MENU", menu_output[7].size() + 2);
		for (auto& menu_item : menu_output)
		{
			fmt::print(
				"# {0:<{1}}#\n"
				, std::string_view{ menu_item }
				, menu_output[7].size()+1
			);
		}
		fmt::print("-{0:-^{2}}-\n", "", "", menu_output[7].size() + 2);
		fmt::print("Enter your selection: ");
	}

	void display_help()
	{
		fmt::print(
			"\n"
			"={0:=^{2}}=\n"
			"+{1: ^{2}}+\n"
			"={0:=^{2}}=\n"
			, "", "AVAILABLE COMMANDS", menu_output[6].size() + 2);

		//Iterate through menu items array and print it to the screen
		for (auto it = help_output.begin(); it != help_output.end(); ++it)
		{
			fmt::print(
				"\t*{0}: {1}"
				, std::string_view{ it->first }
				, std::string_view{ it->second }
			);
		}
		fmt::print("-{0:-^{2}}-\n", "", "", menu_output[6].size() + 2);
	}

	void do_hire(Database& db)
	{		
		std::string first_name{ "" };
		std::string last_name{ "" };


		fmt::print(std::string_view{ "First Name: " });

		std::cin >> first_name;
		std::cin.ignore();
		

		fmt::print(std::string_view{ "Last Name: " });

		std::cin >> last_name;
		std::cin.ignore();
		try
		{
			db.add_employee(std::move(first_name), std::move(last_name));
		}
		catch (const std::exception& exception)
		{

			std::cerr << std::string_view{ "Unable to add new employee: " } << exception.what() << '\n';

		}
	}

	void do_fire(Database& db)
	{
		int employee_number = validate_employee_number(first_employee_number, last_employee_number, "Employee Number: ", "Invalid choice");
		try
		{
			Employee& emp = db.get_employee(employee_number);
			emp.fire();
			fmt::print("Employee {0} has been terminated\n", employee_number);
		}
		catch (const std::exception& exception)
		{
			std::cerr << std::string_view{ "Unable to terminate employee: " } << exception.what() << '\n';
		}

	}
	void do_promote(Database& db)
	{
		int employee_number = validate_employee_number(first_employee_number, last_employee_number, "Employee Number: ", "Invalid choice");	
		float raise_amount = validate_money_amount(min_dollar_amount, max_dollar_amount, "Raise Amount: ", "Amount out of allowed range");
		try
		{
			Employee& emp = db.get_employee(employee_number);
			emp.promote(raise_amount);
		}
		catch (const std::exception& exception)
		{
			std::cerr << std::string_view{ "Unable to promote employee: " } << exception.what() << '\n';
		}
	}

	void do_demote(Database& db)
	{
		float employee_number = validate_money_amount(min_dollar_amount, max_dollar_amount, "Employee Number: ", "Invalid choice");
		float demerit_amount = validate_employee_number(first_employee_number, last_employee_number, "Demerit Amount: ", "Amount out of valid range");
		try
		{
			Employee& emp = db.get_employee(employee_number);
			emp.demote(demerit_amount);
		}
		catch (const std::exception& exception)
		{
			std::cerr << std::string_view{ "Unable to demote employee: " } << exception.what() << '\n';
		}
	}

	void display_all(const Database& db)
	{
		db.display_all();
	}

	void display_current(const Database& db)
	{
		db.display_current();
	}

	void display_former(const Database& db)
	{
		db.display_former();
	}

	void quit(const Database& db)
	{
		exit(0);
	}

	void help(const Database& db)
	{
		records::display_help();
	}
}