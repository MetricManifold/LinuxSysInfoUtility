
#include "utility.h"

/*
 * print all the information collected by each class in this program
 * this includes:
 * - memory information
 * - hostname
 * - list of network interfaces and their information
 * - operating system information
 * - list of processes and their information
 * - CPU information
 * parameter: desired output stream
 */
void util::print_all(std::ostream &out)
{
	out
		<< ProcessList().to_string() << "\n"
		<< "-\n"
		<< Processor().to_string() << "\n"
		<< "-\n"
		<< HostName().to_string() << "\n"
		<< "-\n"
		<< Memory().to_string() << "\n"
		<< "-\n"
		<< NetworkList().to_string() << "\n"
		<< "-\n"
		<< OperatingSystem().to_string()
		<< "-" << std::endl;
}

/*
 * print information collected by the hostname class
 * parameter: desired output stream
 */
void util::print_hostname(std::ostream &out)
{
	out	<< HostName().to_string() << std::endl;
}

/*
 * print information collected by the memory class
 * parameter: desired output stream
 */
void util::print_memory(std::ostream &out)
{
	out	<< Memory().to_string() << std::endl;
}

/*
 * print information collected by the networklist class
 * parameter: desired output stream
 */
void util::print_networklist(std::ostream &out)
{
	out	<< NetworkList().to_string() << std::endl;
}

/*
 * print information collected by the operatingystem class
 * parameter: desired output stream
 */
void util::print_os(std::ostream &out)
{
	out	<< OperatingSystem().to_string() << std::endl;
}

/*
 * print information collected by the processlist class
 * parameter: desired output stream
 */
void util::print_processlist(std::ostream &out)
{
	out	<< ProcessList().to_string() << std::endl;
}

/*
 * print information collected by the processor class
 * parameter: desired output stream
 */
void util::print_processor(std::ostream &out)
{
	out	<< Processor().to_string() << std::endl;
}

/*
 * given the input and output streams, prints the possible items whose
 * information can be printed and takes input from the user to print the
 * corresponding one, continues until the user decides to exit
 * parameter: the output stream to print to
 * parameter: the input stream to recieve user input
 */
void util::print_menu(std::ostream &out, std::istream &in)
{
	bool running = true;
	while (running)
	{
		out << "Choose the information to have printed out:\n"
			<< "\t1. List of all processes\n"
			<< "\t2. List of all network interfaces\n"
			<< "\t3. CPU information\n"
			<< "\t4. RAM information\n"
			<< "\t5. Operating system information\n"
			<< "\t6. System hostname\n"
			<< "\t7. Exit" << std::endl;

		out << "Choice: ";
		int ch;
		while (!(in >> ch) && ch < 1 && ch > 6) {
			out << "Bad value!";
			in.clear();
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		// choose the correct output based on the given input
		out << "-\n";
		switch (ch)
		{
		case 1:
			print_processlist(out);
			break;
		case 2:
			print_networklist(out);
			break;
		case 3:
			print_processor(out);
			break;
		case 4:
			print_memory(out);
			break;
		case 5:
			print_os(out);
			break;
		case 6:
			print_hostname(out);
			break;
		case 7:
			out << "Exiting program" << std::endl;
			running = false;
		}
	}
}



