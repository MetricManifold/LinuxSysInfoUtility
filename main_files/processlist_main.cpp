/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		ProcessorList contains the list of all the processes, generated
 *					when the application was created
 */

#include <iostream>

#include "../processlist.h"

int main()
{
	std::cout << ProcessList().to_string() << std::endl;

}

