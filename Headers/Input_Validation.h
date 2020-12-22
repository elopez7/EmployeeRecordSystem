#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include <string>
#include <unordered_map>
#include <functional>
#include "UserInterface.h"

class Database;

namespace records
{
	float validate_money_amount(int low, int high, const std::string_view& greeting, const std::string_view& sorry);
	float check_float(const std::string_view& sorry);
	int validate_employee_number(int low, int high, const std::string_view& greeting, const std::string_view& sorry);
	int check_int(const std::string_view& sorry);
	std::string command_validation(std::unordered_map<std::string, std::function<void(records::Database&)>>& inCommands);
}

#endif // !INPUT_VALIDATION_H
