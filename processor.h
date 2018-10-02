/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		Processor class contains attributes with information
 *					about the system processor
 */

#pragma once

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <sys/sysinfo.h>

#include "errorcodes.h"

#define CPU_INFO_FILE "/proc/cpuinfo"

class Processor
{
	std::string vendor;
	std::string model_name;

	/*
	 * processor clock speed in MHz
	 */
	double clock_speed;
	
	/*
	 * load averages for 1, 5 and 15 minutes
	 */
	float loads[3];

public:
	Processor();

	double get_clock_speed() const;
	float get_cpu_load(size_t index) const;
	std::string get_vendor() const;
	std::string get_model_name() const;

	std::string to_string() const;
};
	
