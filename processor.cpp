/*
 * Author:			Steven Silber (250714687)
 * Date:			September, 2018
 * Description:		Processor class contains attributes with information
 *					about the system processor
 */

#include "processor.h"

 /*
  * constructor for the processor class, initializes the attributes from the
  * system file by parsing it
  */
Processor::Processor()
{
	/*
	 * files are opened and parsed using the c-style way
	 */
	FILE *f;
	f = fopen(CPU_INFO_FILE, "r");

	/*
	 * list of keys we're searching for
	 */
	char vendor_key[] = "vendor_id";
	char model_name_key[] = "model name";
	char clock_speed_key[] = "cpu MHz";

	/*
	 * create a buffer to store the lines in
	 */
	size_t constexpr LINE_BUFFER = 256;
	char line[LINE_BUFFER];
	while (fgets(line, LINE_BUFFER, f))
	{
		char *key = strtok(line, "\t");

		/*
		 * check to see that the line key corresponds to the
		 * information we're looking for and then exploit copy
		 * assignment operator from std::string to populate data
		 *
		 * string is tokenized on tabs, newlines and ':' character
		 * to retrieve the configuration value, then returned value
		 * incremented by 1 to ignore first space
		 */
		if (strcmp(key, vendor_key) == 0)
		{
			char *value = strtok(NULL, ":\t\n") + 1;
			vendor = value;
		}
		else if (strcmp(key, model_name_key) == 0)
		{
			char *value = strtok(NULL, ":\t\n") + 1;
			model_name = value;
		}
		else if (strcmp(key, clock_speed_key) == 0)
		{
			char *value = strtok(NULL, ":\t\n") + 1;
			clock_speed = atof(value);
		}
	}

	fclose(f);

	struct sysinfo s_buf;
	if (sysinfo(&s_buf) != 0)
	{
		fprintf(stderr, "sysinfo function did not return correctly\n");
		exit(SYS_FUNC_ERROR);
	}
	std::transform(
		s_buf.loads, s_buf.loads + 3, loads, 
		[](auto e) { return e / (static_cast<float>(1 << SI_LOAD_SHIFT)); }
	);
}

/*
 * return the clock speed at the current time
 */
double Processor::get_clock_speed() const
{
	return clock_speed;
}

/*
 * return the cpu load, index corresponds to the time average
 * parameter: index in the range [0, 2]
 */
float Processor::get_cpu_load(size_t index) const
{
	if (index > 2 || index < 0)
	{
		fprintf(stderr, "incorrect index provided for cpu load\n");
		exit(INDEX_OUT_OF_BOUNDS);
	}
	else
	{
		return loads[index];
	}
}

/*
 * returns the name of the vendor associated with the processor
 */
std::string Processor::get_vendor() const
{
	return vendor;
}

/*
 * returns the processor model name
 */
std::string Processor::get_model_name() const
{
	return model_name;
}

/*
 * returns the string representation of the processor information
 */
std::string Processor::to_string() const
{
	std::stringstream ss;
	ss << "CPU information for the computer";
	ss << "\n\tModel name is " << model_name;
	ss << "\n\tVendor name is " << vendor;
	ss << "\n\tThe processor clock speed is " << clock_speed << " MHz";
	ss << "\n\tThe average CPU loads are " << loads[0] << "% (1 min) "
		<< loads[1] << "% (5 min) " << loads[2] << "% (15 min)";

	return ss.str();
}


