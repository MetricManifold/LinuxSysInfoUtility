/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		HostName class contains the hostname information for the computer
 */

#include "hostname.h"

/*
 * construtor for the hostname object which finds the hostname of
 * the system and saves it in the attribute
 */
HostName::HostName()
{
	// create a char buffer and read hostname into it
	size_t constexpr NAME_BUFFER = 64;
	char tempname[NAME_BUFFER];
	gethostname(tempname, NAME_BUFFER);

	// use string copying to copy the hostname
	hostname = tempname;
}

/*
 * return the hostname of the system
 */
std::string HostName::get_hostname() const
{
	return hostname;
}

/*
 * returns the string representation of the hostname
 */
std::string HostName::to_string() const
{
	std::stringstream ss;
	ss << "The hostname of the system is " << hostname;

	return ss.str();
}

