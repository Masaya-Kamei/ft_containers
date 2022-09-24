#include <iostream>
#include <iomanip>
#include "BenchMarkTest.hpp"

BenchMarkTest::BenchMarkTest(const unsigned int seed)
	: seed_(seed)
{
	#ifdef NAMESPACE_STD
		std::cout << "NameSpace : std" << std::endl;
	#else
		std::cout << "NameSpace : ft" << std::endl;
	#endif
	srand(seed_);
	std::cout << "Seed      : " << seed_ << std::endl;
}

void	BenchMarkTest::MeasureMemFunc(
	const std::string& container_name,
	const std::string& memfunc_name,
	void (BenchMarkTest::*memfunc)())
{
	Timer	timer;
	for (int i = 0; i < 1000; ++i)
		(this->*memfunc)();

	PutElapsedTimeMsg(timer, container_name, memfunc_name);
}

void	BenchMarkTest::PutElapsedTimeMsg(
			const Timer& timer,
			const std::string& container_name,
			const std::string& memfunc_name)
{
	std::cout << container_name;
	if (!memfunc_name.empty())
		std::cout << " " << memfunc_name;

	int	 width = container_name.size() + memfunc_name.size() + !memfunc_name.empty();
	std::cout << std::setw(30 - width) << ": ";
	// std::cout << std::setw(10) << timer.ElapsedMTime() << " [ms]" << std::endl;
	std::cout << std::setw(10) << timer.ElapsedUTime() << " [us]" << std::endl;
}

void	BenchMarkTest::RunAllTest()
{
	Timer	timer;

	RunVectorTest();

	PutElapsedTimeMsg(timer, "All");
}
