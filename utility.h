#pragma once

#include <iostream>
#include <string>
#include <limits>

#include "hostname.h"
#include "memory.h"
#include "networklist.h"
#include "operatingsystem.h"
#include "processlist.h"
#include "processor.h"

namespace util
{
	void print_all(std::ostream &out);
	void print_hostname(std::ostream &out);
	void print_memory(std::ostream &out);
	void print_networklist(std::ostream &out);
	void print_os(std::ostream &out);
	void print_processlist(std::ostream &out);
	void print_processor(std::ostream &out);
	void print_menu(std::ostream &out, std::istream &in);
}
	
