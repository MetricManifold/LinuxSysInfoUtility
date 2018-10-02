/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		ProcessorList contains the list of all the processes, generated
 *					when the application was created
 */

#pragma once

#include <sys/types.h>
#include <cctype>
#include <dirent.h>
#include <vector>
#include <sstream>

#include "errorcodes.h"
#include "process.h"

class ProcessList
{
	std::vector<Process> process_list;

public:
	ProcessList();

	std::vector<Process> get_process_list() const;

	std::string to_string() const;
};
	
