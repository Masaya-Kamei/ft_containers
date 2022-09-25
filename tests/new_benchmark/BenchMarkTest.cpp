#include <iostream>
#include <iomanip>
#include "BenchMarkTest.hpp"
#include "BenchMarkTestVector.hpp"
#include "Random.hpp"

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

void	BenchMarkTest::PutElapsedTimeMsg(
			const unsigned long utime,
			const std::string& container_name,
			const std::string& memfunc_name)
{
	std::cout << container_name;
	if (!memfunc_name.empty())
		std::cout << " " << memfunc_name;

	int	 width = container_name.size() + memfunc_name.size() + !memfunc_name.empty();
	std::cout << std::setw(30 - width) << ": ";

	if (utime >= 10000000)
		std::cout << std::setw(8) << utime / 1000000 << " [ s]" << std::endl;
	else if (utime >= 10000)
		std::cout << std::setw(8) << utime / 1000 << " [ms]" << std::endl;
	else
		std::cout << std::setw(8) << utime << " [us]" << std::endl;
}

unsigned long	BenchMarkTest::RunVectorTest()
{
	BenchMarkTestVector::SetUp();
	unsigned long	utime = 0;

	utime += MeasureMemFunc("vector", "default constructor", &BenchMarkTestVector::DefaultConstructor);
	utime += MeasureMemFunc("vector", "fill constructor",	&BenchMarkTestVector::FillConstructor);
	utime += MeasureMemFunc("vector", "range constructor",	&BenchMarkTestVector::RangeConstructor);
	utime += MeasureMemFunc("vector", "copy constructor",	&BenchMarkTestVector::CopyConstructor);
	utime += MeasureMemFunc("vector", "=", 					&BenchMarkTestVector::OpeAssign);
	utime += MeasureMemFunc("vector", "begin", 				&BenchMarkTestVector::Begin);
	utime += MeasureMemFunc("vector", "end", 				&BenchMarkTestVector::End);
	utime += MeasureMemFunc("vector", "rbegin",				&BenchMarkTestVector::RBegin);
	utime += MeasureMemFunc("vector", "rend", 				&BenchMarkTestVector::REnd);
	utime += MeasureMemFunc("vector", "size",				&BenchMarkTestVector::Size);
	utime += MeasureMemFunc("vector", "max_size",			&BenchMarkTestVector::MaxSize);
	utime += MeasureMemFunc("vector", "capacity",			&BenchMarkTestVector::Capacity);
	utime += MeasureMemFunc("vector", "empty",				&BenchMarkTestVector::Empty);
	utime += MeasureMemFunc("vector", "resize",				&BenchMarkTestVector::Resize);
	utime += MeasureMemFunc("vector", "reserve",			&BenchMarkTestVector::Reserve);
	utime += MeasureMemFunc("vector", "[]",					&BenchMarkTestVector::OpeBrackets);
	utime += MeasureMemFunc("vector", "at",					&BenchMarkTestVector::At);
	utime += MeasureMemFunc("vector", "front",				&BenchMarkTestVector::Front);
	utime += MeasureMemFunc("vector", "back",				&BenchMarkTestVector::Back);
	utime += MeasureMemFunc("vector", "data",				&BenchMarkTestVector::Data);
	utime += MeasureMemFunc("vector", "assign fill",		&BenchMarkTestVector::AssignFill);
	utime += MeasureMemFunc("vector", "assign range",		&BenchMarkTestVector::AssignRange);
	utime += MeasureMemFunc("vector", "push_back",			&BenchMarkTestVector::PushBack);
	utime += MeasureMemFunc("vector", "pop_back",			&BenchMarkTestVector::PopBack);
	utime += MeasureMemFunc("vector", "insert single",		&BenchMarkTestVector::InsertSingle);
	utime += MeasureMemFunc("vector", "insert fill",		&BenchMarkTestVector::InsertFill);
	utime += MeasureMemFunc("vector", "insert range",		&BenchMarkTestVector::InsertRange);
	utime += MeasureMemFunc("vector", "erase single",		&BenchMarkTestVector::EraseSingle);
	utime += MeasureMemFunc("vector", "erase range",		&BenchMarkTestVector::EraseRange);
	utime += MeasureMemFunc("vector", "swap",				&BenchMarkTestVector::Swap);
	utime += MeasureMemFunc("vector", "clear",				&BenchMarkTestVector::Clear);
	utime += MeasureMemFunc("vector", "get_allocator",		&BenchMarkTestVector::GetAllocator);
	utime += MeasureMemFunc("vector", "==",					&BenchMarkTestVector::OpeEqual);
	utime += MeasureMemFunc("vector", "!=",					&BenchMarkTestVector::OpeNotEqual);
	utime += MeasureMemFunc("vector", "<",					&BenchMarkTestVector::OpeLess);
	utime += MeasureMemFunc("vector", "<=",					&BenchMarkTestVector::OpeLessEqual);
	utime += MeasureMemFunc("vector", ">",					&BenchMarkTestVector::OpeGreater);
	utime += MeasureMemFunc("vector", ">=",					&BenchMarkTestVector::OpeGreaterEqual);
	utime += MeasureMemFunc("vector", "non member swap",	&BenchMarkTestVector::NonMemberSwap);

	PutElapsedTimeMsg(utime, "Vector");
	return (utime);
}

void	BenchMarkTest::RunAllTest()
{
	unsigned long	utime = 0;

	utime += RunVectorTest();
	// RunMapTest();
	// RunStackTest();

	PutElapsedTimeMsg(utime, "All");
}
