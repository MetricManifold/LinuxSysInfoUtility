/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		HostName class contains the hostname information for the computer
 */

#include <iostream>

#include "../hostname.h"

int main()
{
	std::cout << HostName().to_string() << std::endl;
	return 0;
}


