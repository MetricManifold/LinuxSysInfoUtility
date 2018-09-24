/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		Network contains the information associated with an interface
 */

#pragma once

#include <sstream>
#include <string>
#include <cstring>

#include "errorcodes.h"

#define NET_INFO_DIR "/sys/class/net"
#define NET_INFO_FILE "/sys/class/net/%s/address"

class Network
{
	std::string name;
	std::string mac_address;

public:
	Network(const char *name);

	std::string get_name() const;
	std::string get_mac_address() const;

	std::string to_string() const;
};