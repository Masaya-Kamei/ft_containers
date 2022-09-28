#include <iostream>
#include "OutputTest.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./output_test [seed]" << std::endl;
		std::cerr << "       make test SEED=[seed]" << std::endl;
		return (1);
	}

	OutputTest	output_test(atoi(argv[1]));
	output_test.RunAllTest();

#ifdef NAMESPACE_STD
	system("leaks output_std 1>&2");
#else
	system("leaks output_ft 1>&2");
#endif
	return (0);
}
