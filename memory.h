/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		Memory class contains the information associated with the
 *					current memory usage and size
 */

#pragma once

#include <string>
#include <sys/sysinfo.h>
#include <sstream>

#include "errorcodes.h"

class Memory
{
	unsigned long totalram;
	unsigned long freeram;
	unsigned int mem_unit;

public:
	Memory();

	unsigned long get_totalram() const;
	unsigned long get_freeram() const;

	std::string to_string() const;
};

