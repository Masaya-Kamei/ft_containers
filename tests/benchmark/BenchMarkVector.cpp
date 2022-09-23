#include <iostream>
#include "BenchMarkTest.hpp"
#include "vector.hpp"

#define COUNT 1000000

static void	DefaultConstructor(const unsigned int seed)
{
	(void)seed;
	ft::vector<int>	vec;
}

void	BenchMarkTest::RunVectorTest()
{
	Timer	timer;

	MeasureMemFunc("Vector", "Default Constructor", DefaultConstructor, COUNT);

	PutElapsedTimeMsg(timer, "Vector");
}
