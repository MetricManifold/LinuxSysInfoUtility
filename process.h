/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		Processor contains the data associated with a process
 */

#pragma once

#include <sstream>
#include <string>
#include <vector>
#include <cstring>

#include "errorcodes.h"

#define PROC_INFO_DIR "/proc"
#define PROC_INFO_FILE "/proc/%d/status"

class Process
{
	unsigned long pid;
	unsigned long ppid;
	std::string name;
	std::string owner;
	std::string state;

public:
	Process(unsigned long pid);

	unsigned long get_pid() const;
	unsigned long get_ppid() const;
	std::string get_name() const;
	std::string get_owner() const;
	std::string get_state() const;

	std::string to_string() const;
};

