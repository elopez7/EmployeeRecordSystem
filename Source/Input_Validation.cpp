// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <iostream>
#include <regex>
#include <limits>
#include <fmt/format.h>

#include "Input_Validation.h"
#include "Types.h"

namespace records
{
	float validate_money_amount(int low, int high, const std::string_view& greeting, const std::string_view& sorry)
	{
		fmt::print("{0} :[{1}:{2}]\n", greeting, low, high);
		
		for (;;)
		{
			float new_salary{ check_float("That was not a number, please try again") };

			if (low <= new_salary && new_salary <= high)
			{
				return new_salary;
			}
			fmt::print("{0} {1}\n", new_salary, sorry);
		}
	}

	float check_float(const std::string_view& sorry)
	{
		std::regex salary_pattern(R"(\d+(\.\d{1,2})?)");

		for (std::string salary_input; std::getline(std::cin, salary_input);)
		{
			if (std::regex_match(salary_input, salary_pattern))
			{
				return std::stof(salary_input);
			}
		}
		fmt::print("{0}\n", sorry);
		return 0.0f;
	}

	int validate_employee_number(int low, int high, const std::string_view& greeting, const std::string_view& sorry)
	{
		fmt::print("{0} :[{1}:{2}]\n", greeting, low, high);

		for (;;)
		{
			int employee_number{ check_int("That was not a number, please try again") };
			if (low <= employee_number && employee_number <= high)
			{
				return employee_number;
			}
			fmt::print("{0} {1}", employee_number, sorry);
		}
	}

	int check_int(const std::string_view& sorry)
	{
		std::regex salary_pattern(R"(\d+(\.\d{1,2})?)");

		for (std::string employee_number; std::getline(std::cin, employee_number);)
		{
			if (std::regex_match(employee_number, salary_pattern))
			{
				return std::stof(employee_number);
			}
		}
		std::cout << sorry;
		return 0.0f;
	}

	std::string command_validation(std::unordered_map<std::string, std::function<void(records::Database&)>>& inCommands)
	{
		std::string user_input{ 0 };
		std::getline(std::cin, user_input);
		auto it = inCommands.find(std::move(user_input));

		if (it == inCommands.end())
		{
			return "Invalid command\n";
		}
		return it->first;
	}
}
