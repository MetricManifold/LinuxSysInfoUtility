/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		Network contains the information associated with an interface
 */

#include "network.h"

/*
 * constructor for the network object that reads from the interface file
 * and populates the attributes
 * parameter: the name of the interface
 */
Network::Network(const char *name) : name{ name }
{
	// form the name of the file
	char fname[64];
	sprintf(fname, NET_INFO_FILE, name);
	
	/*
	 * files are opened and parsed the c-style way
	 */
	FILE *f;
	if ((f = fopen(fname, "r")) == 0)
	{
		fprintf(stderr, "file %s failed to open\n", fname);
		exit(FILE_OPEN_ERROR);

	}
	
	// create a line buffer and read the first line into it
	size_t constexpr LINE_BUFFER = 256;
	char line[LINE_BUFFER];
	fgets(line, LINE_BUFFER, f);

	// copy the line into mac_address attribute without newline
	mac_address = strtok(line, "\n");

	fclose(f);
}

/*
 * returns the name of this interface
 */
std::string Network::get_name() const
{
	return name;
}

/*
 * returns the physical address associated with this interface
 */
std::string Network::get_mac_address() const
{
	return mac_address;
}

/*
 * returns the string representation of the network interface
 */
std::string Network::to_string() const
{
	std::stringstream ss;
	ss << "Network information for interface " << name;
	ss << "\n\tMac address is " << mac_address;

	return ss.str();
}
	
