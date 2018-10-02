/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		ProcessorList contains the list of all the processes, generated
 *					when the application was created
 */

#include "processlist.h"

/*
 * constructor for processlist that opens the process directory
 * and populates process object list based on the contents
 */
ProcessList::ProcessList()
{
	DIR *d;
	dirent *ent;
	if ((d = opendir(PROC_INFO_DIR)) == 0)
	{
		fprintf(stderr, "the %s directory failed to open\n", PROC_INFO_DIR);
		exit(DIR_OPEN_ERROR);
	}

	while ((ent = readdir(d)) != 0)
	{
		/*
		 * iterate over every character in the name of the directory entry
		 * and check if they are numbers
		 */
		bool b = true;
		for (const char *c = ent->d_name; *c != 0 && (b = isdigit(*c)); ++c);

		if (b)
		{
			// create a new process entry with the registered PID
			// (converted from the directory name)
			process_list.emplace_back(atoi(ent->d_name));
		}

	}
}

/*
 * returns the vector of all processes
 */
std::vector<Process> ProcessList::get_process_list() const
{
	return process_list;
}

/*
 * returns the string representation of all the interfaces
 */
std::string ProcessList::to_string() const
{
	std::stringstream ss;
	ss << "Full process list description:\n"
		<< "****************************************************************************************\n";
	for (auto const& process : process_list)
	{
		ss << process.to_string() << "\n";
	}
	ss << "****************************************************************************************";

	return ss.str();

}
	
