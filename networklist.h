/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		NetworkList contains the list of interfaces used by the
 *					computer
 */

#pragma once

#include <sys/types.h>
#include <cctype>
#include <dirent.h>
#include <string>
#include <sstream>
#include <vector>

#include "errorcodes.h"
#include "network.h"

class NetworkList
{
	std::vector<Network> network_list;

public:
	NetworkList();

	std::vector<Network> get_network_list() const;

	std::string to_string() const;
};
	
