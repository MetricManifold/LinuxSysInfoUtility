/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		NetworkList contains the list of interfaces used by the
 *					computer
 */

#include "networklist.h"

/*
 * accesses directory of all interfaces and creates a list of interfaces
 */
NetworkList::NetworkList()
{
	// read the directory structure to get the interfaces
	DIR *d;
	dirent *ent;
	if ((d = opendir(NET_INFO_DIR)) == 0)
	{
		fprintf(stderr, "the %s directory failed to open\n", NET_INFO_DIR);
		exit(DIR_OPEN_ERROR);
	}
	
	// read the first entry because this is always the link the prev dir
	readdir(d), readdir(d);

	// read all remaining entries and create a new process entry 
	// with the registered interface name
	while ((ent = readdir(d)) != 0)
	{
		network_list.emplace_back(ent->d_name);
	}
}

/*
 * return the vector of the network list
 */
std::vector<Network> NetworkList::get_network_list() const
{
	return network_list;
}

/*
 * returns the string representation of all the interfaces
 */
std::string NetworkList::to_string() const
{
	std::stringstream ss;
	ss << "Full network interface description:\n"
		<< "****************************************************************************************\n";
	for (auto const& network : network_list)
	{
		ss << network.to_string() << "\n";
	}
	ss << "****************************************************************************************";

	return ss.str();

}
