// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include <unordered_map>
#include <iostream>
#include "UserInterface.h"
#include "Input_Validation.h"
#include <functional>

int main()
{
	records::Database employee_db;

	while (true)
	{
		records::display_menu();
		std::unordered_map<std::string, std::function<void(records::Database&)>> sampleCommands
		{
			{"hire", records::do_hire },
			{"fire", records::do_fire },
			{"promote", records::do_promote },
			{"demote", records::do_demote },
			{"list all", records::display_all },
			{"list current", records::display_current },
			{"list former", records::display_former },
			{"quit", records::quit },
			{"help", records::help }
		};
		std::string user_input = records::command_validation(sampleCommands);
		
		if (user_input.empty())
		{
			std::cout << "Invalid Command\n";
			continue;
		}
		sampleCommands[user_input](employee_db);
	}
	return 0;
}