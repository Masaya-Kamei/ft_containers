#include <iostream>
#include "BenchMarkTest.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./bench_test [seed]" << std::endl;
		std::cerr << "       make test SEED=[seed]" << std::endl;
		return (1);
	}

	BenchMarkTest	benchmark_test(atoi(argv[1]));
	benchmark_test.RunAllTest();

	return (0);
}
