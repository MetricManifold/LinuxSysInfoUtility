/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		OperatingSystem class contains information related
 *					to the operating system on the computer
 */

#pragma once

#include <string>
#include <sstream>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

#include "errorcodes.h"

class OperatingSystem
{
	std::string system_name;
	std::string os_release;
	std::string os_version;

	long uptime;

public:
	OperatingSystem();

	std::string get_system_name() const;
	std::string get_os_release() const;
	std::string get_os_version() const;
	long get_uptime() const;

	std::string to_string() const;
};