/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		Memory class contains the information associated with the
 *					current memory usage and size
 */

#include <iostream>

#include "../memory.h"

int main()
{
	std::cout << Memory().to_string() << std::endl;
	return 0;

}

