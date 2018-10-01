/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		NetworkList contains the list of interfaces used by the
 *					computer
 */

#include <iostream>

#include "../networklist.h"

int main()
{
	std::cout << NetworkList().to_string() << std::endl;
	return 0;
}


