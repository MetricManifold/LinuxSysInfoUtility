/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		OperatingSystem class contains information related
 *					to the operating system on the computer
 */

#pragma once

#include "operatingsystem.h"

/*
 * constructor for the operating system object that calls the system function
 * and extracts the operating system information
 */
OperatingSystem::OperatingSystem()
{
	// get the utsname structure
	struct utsname u_buf;
	if (uname(&u_buf) != 0)
	{
		fprintf(stderr, "uname function did not return correctly\n");
		exit(SYS_FUNC_ERROR);
	}

	// populate the class attributes using the utsname structure
	system_name = u_buf.sysname;
	os_release = u_buf.release;
	os_version = u_buf.version;

	// get the sys info structure
	struct sysinfo s_buf;
	if (sysinfo(&s_buf) != 0)
	{
		fprintf(stderr, "sysinfo function did not return correctly\n");
		exit(SYS_FUNC_ERROR);
	}

	// retrieve the uptime attribute
	uptime = s_buf.uptime;
}

/*
 * return the system name identified by the operating system
 */
std::string OperatingSystem::get_system_name() const
{
	return system_name;
}

/*
 * return the operating system release name
 */
std::string OperatingSystem::get_os_release() const
{
	return os_release;
}

/* 
 * return the operating system version
 */
std::string OperatingSystem::get_os_version()  const
{
	return os_version;
}

/*
 * return the total time the operating system has been active
 */
long OperatingSystem::get_uptime() const
{
	return uptime;
}

/*
 * returns the string representation of the operating system information
 */
std::string OperatingSystem::to_string() const
{
	std::stringstream ss;
	ss << "Operating system information ";
	ss << "\n\tSystem name is " << system_name;
	ss << "\n\tOperating system release name is " << os_release;
	ss << "\n\tOperating system release version is " << os_version;
	ss << "\n\tThe system has been operating for " << uptime << " seconds";

	return ss.str();
}

