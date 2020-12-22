#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "Database.h"

namespace records
{
	void display_menu();
	void display_help();
	void do_hire(Database& db);
	void do_fire(Database& db);
	void do_promote(Database& db);
	void do_demote(Database& db);
	void display_all(const Database& db);
	void display_current(const Database& db);
	void display_former(const Database& db);
	void quit(const Database& db);
	void help(const Database& db);
}

#endif // !USER_INTERFACE_H