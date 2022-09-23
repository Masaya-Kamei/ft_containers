#include <iostream>
#include <iomanip>
#include "BenchMarkTest.hpp"

BenchMarkTest::BenchMarkTest()
	: seed_(time(NULL))
{
	srand(seed_);
	std::cout << "Seed: " << seed_ << std::endl;
}

void	BenchMarkTest::MeasureLoop(
	const std::string& container_name,
	const std::string& memfunc_name,
	void (*memfunc)(const unsigned int),
	const int count)
{
	Timer	timer;
	for (int i = 0; i < count; ++i)
		memfunc(seed_);

	PutElapsedMTimeMsg(timer, container_name, memfunc_name);
}

void	BenchMarkTest::PutElapsedMTimeMsg(
			const Timer& timer,
			const std::string& container_name,
			const std::string& memfunc_name)
{
	std::cout << container_name;
	if (!memfunc_name.empty())
		std::cout << " " << memfunc_name;

	int	 width = container_name.size() + memfunc_name.size() + !memfunc_name.empty();
	std::cout << std::setw(30 - width) << ": " << timer.ElapsedMTime() << " [ms]" << std::endl;
}

void	BenchMarkTest::RunAllTest()
{
	Timer	timer;

	RunVectorTest();

	PutElapsedMTimeMsg(timer, "All");
}
