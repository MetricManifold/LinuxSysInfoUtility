/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		HostName class contains the hostname information for the computer
 */

#pragma once

#include <string>
#include <sstream>
#include <unistd.h>

#include "errorcodes.h"

class HostName
{
	std::string hostname;

public:
	HostName();

	std::string get_hostname() const;

	std::string to_string() const;
};
	
