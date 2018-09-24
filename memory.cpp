/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		Memory class contains the information associated with the
 *					current memory usage and size
 */

#pragma once

#include "memory.h"

/*
 * constructor for the memory object that calls the system function
 * and sets the object attributes
 */
Memory::Memory()
{
	// get the sysinfo structure
	struct sysinfo s_buf;
	if (sysinfo(&s_buf) != 0)
	{
		fprintf(stderr, "sysinfo function did not return correctly\n");
		exit(SYS_FUNC_ERROR);
	}

	// populate the class attributes from sysinfo structure 
	mem_unit = s_buf.mem_unit;
	totalram = s_buf.totalram;
	freeram = s_buf.freeram;
}

/*
 * returns the total maximum amount of RAM owned by the computer
 */
unsigned long Memory::get_totalram() const
{
	return totalram;
}

/*
 * returns the total free amount of RAM owned by the computer
 */
unsigned long Memory::get_freeram() const
{
	return freeram;
}

/*
 * returns the string representation of the memory information
 */
std::string Memory::to_string() const
{
	std::stringstream ss;
	ss << "Memory information for the computer";
	ss << "\n\tTotal amount of memory is " << (totalram / static_cast<double>(mem_unit * 1024e6)) << " GB";
	ss << "\n\tFree amount of memory is " << (freeram / static_cast<double>(mem_unit * 1024e6)) << " GB";
	ss << "\n\t(Free memory excludes memory used by cached operating system data)";

	return ss.str();
}

