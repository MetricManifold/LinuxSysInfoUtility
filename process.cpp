/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		Processor contains the data associated with a process
 */

#include "process.h"

/*
 * constructor for the process, given the numeric process id, populates
 * the class attributes
 * parameter: the pid of the process
 */
Process::Process(unsigned long pid) : pid{ pid }
{
	char fname[32];
	sprintf(fname, PROC_INFO_FILE, pid);

	/*
	 * files are opened and parsed the c-style way
	 */
	FILE *f;
	if ((f = fopen(fname, "r")) == 0)
	{
		fprintf(stderr, "file %s failed to open\n", fname);
		exit(FILE_OPEN_ERROR);

	}

	/*
	 * list of keys we're searching for
	 */
	char name_key[] = "Name";
	char owner_key[] = "Uid";
	char state_key[] = "State";
	char ppid_key[] = "PPid";

	// create a line buffer to iterate over all lines
	size_t constexpr LINE_BUFFER = 256;
	char line[LINE_BUFFER];
	while (fgets(line, LINE_BUFFER, f))
	{
		char *key = strtok(line, ":");
		/*
		 * chceck to see that the line key corresponds to the
		 * information we're looking for and then exploit copy
		 * assignment operator from std::string to populate data
		 *
		 * strtok must be taken before the data to move cursor
		 * beyond ':' character
		 */
		if (strcmp(key, name_key) == 0)
		{
			char *value = strtok(NULL, "\t\n");
			name = value;
		}
		else if (strcmp(key, owner_key) == 0)
		{
			char *value = strtok(NULL, "\n");
			owner = value;
		}
		else if (strcmp(key, state_key) == 0)
		{
			char *value = strtok(NULL, "\t\n");
			state = value;
		}
		else if (strcmp(key, ppid_key) == 0)
		{
			char *value = strtok(NULL, "\n");
			ppid = atoi(value);
		}
	}

	fclose(f);
}

/*
 * returns the pid of the process
 */
unsigned long Process::get_pid() const
{
	return pid;
}

/*
 * returns the parent pid of the process
 */
unsigned long Process::get_ppid() const
{
	return ppid;
}

/*
 * returns the name of the process
 */
std::string Process::get_name() const
{
	return name;
}

/*
 * returns the owner uid of the process
 */
std::string Process::get_owner() const
{
	return owner;
}

/*
 * returns the state of the process
 */
std::string Process::get_state() const
{
	return state;
}

/*
 * returns the string representation of the process information
 */
std::string Process::to_string() const
{
	std::stringstream ss;
	ss << "Process information for PID " << pid;
	ss << "\n\tName is '" << name << "'";
	ss << "\n\tOwner UID is " << owner;
	ss << "\n\tParent PID is " << ppid;
	ss << "\n\tThe process is in state " << state;

	return ss.str();
}
	
