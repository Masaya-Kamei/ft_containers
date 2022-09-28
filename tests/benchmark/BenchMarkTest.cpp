#include <iostream>
#include <iomanip>
#include "BenchMarkTest.hpp"
#include "BenchMarkTestVector.hpp"
#include "BenchMarkTestMap.hpp"
#include "BenchMarkTestStack.hpp"

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

	// if (utime >= 10000000)
	// 	std::cout << std::setw(8) << utime / 1000000 << " [ s]" << std::endl;
	// else if (utime >= 10000)
	// 	std::cout << std::setw(8) << utime / 1000 << " [ms]" << std::endl;
	// else
	std::cout << std::setw(8) << utime << " [us]" << std::endl;
}

unsigned long	BenchMarkTest::RunVectorTest()
{
	BenchMarkTestVector::SetUpStatic();
	unsigned long	utime = 0;

	utime += RunMemFunc("vector", "default constructor", &BenchMarkTestVector::DefaultConstructor,	false);
	utime += RunMemFunc("vector", "fill constructor",	&BenchMarkTestVector::FillConstructor,		false);
	utime += RunMemFunc("vector", "range constructor",	&BenchMarkTestVector::RangeConstructor,		false);
	utime += RunMemFunc("vector", "copy constructor",	&BenchMarkTestVector::CopyConstructor,		false);
	utime += RunMemFunc("vector", "=", 					&BenchMarkTestVector::OpeAssign,			false);
	utime += RunMemFunc("vector", "begin", 				&BenchMarkTestVector::Begin,				false);
	utime += RunMemFunc("vector", "end", 				&BenchMarkTestVector::End,					false);
	utime += RunMemFunc("vector", "rbegin",				&BenchMarkTestVector::RBegin,				false);
	utime += RunMemFunc("vector", "rend", 				&BenchMarkTestVector::REnd,					false);
	utime += RunMemFunc("vector", "size",				&BenchMarkTestVector::Size,					false);
	utime += RunMemFunc("vector", "max_size",			&BenchMarkTestVector::MaxSize,				false);
	utime += RunMemFunc("vector", "capacity",			&BenchMarkTestVector::Capacity,				false);
	utime += RunMemFunc("vector", "empty",				&BenchMarkTestVector::Empty,				false);
	utime += RunMemFunc("vector", "resize",				&BenchMarkTestVector::Resize,				true);
	utime += RunMemFunc("vector", "reserve",			&BenchMarkTestVector::Reserve,				true);
	utime += RunMemFunc("vector", "[]",					&BenchMarkTestVector::OpeBrackets,			false);
	utime += RunMemFunc("vector", "at",					&BenchMarkTestVector::At,					false);
	utime += RunMemFunc("vector", "front",				&BenchMarkTestVector::Front,				false);
	utime += RunMemFunc("vector", "back",				&BenchMarkTestVector::Back,					false);
	utime += RunMemFunc("vector", "data",				&BenchMarkTestVector::Data,					false);
	utime += RunMemFunc("vector", "assign fill",		&BenchMarkTestVector::AssignFill,			true);
	utime += RunMemFunc("vector", "assign range",		&BenchMarkTestVector::AssignRange,			true);
	utime += RunMemFunc("vector", "push_back",			&BenchMarkTestVector::PushBack,				true);
	utime += RunMemFunc("vector", "pop_back",			&BenchMarkTestVector::PopBack,				true);
	utime += RunMemFunc("vector", "insert single",		&BenchMarkTestVector::InsertSingle,			true);
	utime += RunMemFunc("vector", "insert fill",		&BenchMarkTestVector::InsertFill,			true);
	utime += RunMemFunc("vector", "insert range",		&BenchMarkTestVector::InsertRange,			true);
	utime += RunMemFunc("vector", "erase single",		&BenchMarkTestVector::EraseSingle,			true);
	utime += RunMemFunc("vector", "erase range",		&BenchMarkTestVector::EraseRange,			true);
	utime += RunMemFunc("vector", "swap",				&BenchMarkTestVector::Swap,					false);
	utime += RunMemFunc("vector", "clear",				&BenchMarkTestVector::Clear,				true);
	utime += RunMemFunc("vector", "get_allocator",		&BenchMarkTestVector::GetAllocator,			false);
	utime += RunMemFunc("vector", "==",					&BenchMarkTestVector::OpeEqual,				false);
	utime += RunMemFunc("vector", "!=",					&BenchMarkTestVector::OpeNotEqual,			false);
	utime += RunMemFunc("vector", "<",					&BenchMarkTestVector::OpeLess,				false);
	utime += RunMemFunc("vector", "<=",					&BenchMarkTestVector::OpeLessEqual,			false);
	utime += RunMemFunc("vector", ">",					&BenchMarkTestVector::OpeGreater,			false);
	utime += RunMemFunc("vector", ">=",					&BenchMarkTestVector::OpeGreaterEqual,		false);
	utime += RunMemFunc("vector", "non member swap",	&BenchMarkTestVector::NonMemberSwap,		false);

	PutElapsedTimeMsg(utime, "Vector");
	return (utime);
}

unsigned long	BenchMarkTest::RunMapTest()
{
	BenchMarkTestMap::SetUpStatic();
	unsigned long	utime = 0;

	utime += RunMemFunc("map", "default constructor", &BenchMarkTestMap::DefaultConstructor, false);
	utime += RunMemFunc("map", "range constructor",	&BenchMarkTestMap::RangeConstructor,	false);
	utime += RunMemFunc("map", "copy constructor",	&BenchMarkTestMap::CopyConstructor,		false);
	utime += RunMemFunc("map", "=", 				&BenchMarkTestMap::OpeAssign,			false);
	utime += RunMemFunc("map", "empty",				&BenchMarkTestMap::Empty,				false);
	utime += RunMemFunc("map", "size",				&BenchMarkTestMap::Size,				false);
	utime += RunMemFunc("map", "max_size",			&BenchMarkTestMap::MaxSize,				false);
	utime += RunMemFunc("map", "begin", 			&BenchMarkTestMap::Begin,				false);
	utime += RunMemFunc("map", "end", 				&BenchMarkTestMap::End,					false);
	utime += RunMemFunc("map", "rbegin",			&BenchMarkTestMap::RBegin,				false);
	utime += RunMemFunc("map", "rend", 				&BenchMarkTestMap::REnd,				false);
	utime += RunMemFunc("map", "[]",				&BenchMarkTestMap::OpeBrackets,			false);
	utime += RunMemFunc("map", "insert single",		&BenchMarkTestMap::InsertSingle,		true);
	utime += RunMemFunc("map", "insert hint",		&BenchMarkTestMap::InsertHint,			true);
	utime += RunMemFunc("map", "insert range",		&BenchMarkTestMap::InsertRange,			true);
	utime += RunMemFunc("map", "erase single iter",	&BenchMarkTestMap::EraseSingleIter,		true);
	utime += RunMemFunc("map", "erase single key",	&BenchMarkTestMap::EraseSingleKey,		true);
	utime += RunMemFunc("map", "erase range",		&BenchMarkTestMap::EraseRange,			true);
	utime += RunMemFunc("map", "swap",				&BenchMarkTestMap::Swap,				false);
	utime += RunMemFunc("map", "clear",				&BenchMarkTestMap::Clear,				true);
	utime += RunMemFunc("map", "key_comp",			&BenchMarkTestMap::KeyComp,				false);
	utime += RunMemFunc("map", "value_comp",		&BenchMarkTestMap::ValueComp,			false);
	utime += RunMemFunc("map", "find",				&BenchMarkTestMap::Find,				false);
	utime += RunMemFunc("map", "count",				&BenchMarkTestMap::Count,				false);
	utime += RunMemFunc("map", "lower_bound",		&BenchMarkTestMap::LowerBound,			false);
	utime += RunMemFunc("map", "upper_bound",		&BenchMarkTestMap::UpperBound,			false);
	utime += RunMemFunc("map", "equal_range",		&BenchMarkTestMap::EqualRange,			false);
	utime += RunMemFunc("map", "get_allocator",		&BenchMarkTestMap::GetAllocator,		false);
	utime += RunMemFunc("map", "==",				&BenchMarkTestMap::OpeEqual,			false);
	utime += RunMemFunc("map", "!=",				&BenchMarkTestMap::OpeNotEqual,			false);
	utime += RunMemFunc("map", "<",					&BenchMarkTestMap::OpeLess,				false);
	utime += RunMemFunc("map", "<=",				&BenchMarkTestMap::OpeLessEqual,		false);
	utime += RunMemFunc("map", ">",					&BenchMarkTestMap::OpeGreater,			false);
	utime += RunMemFunc("map", ">=",				&BenchMarkTestMap::OpeGreaterEqual,		false);
	utime += RunMemFunc("map", "non member swap",	&BenchMarkTestMap::NonMemberSwap,		false);

	PutElapsedTimeMsg(utime, "Map");
	return (utime);
}

unsigned long	BenchMarkTest::RunStackTest()
{
	BenchMarkTestStack::SetUpStatic();
	unsigned long	utime = 0;

	utime += RunMemFunc("stack", "default constructor",	&BenchMarkTestStack::DefaultConstructor, false);
	utime += RunMemFunc("stack", "copy constructor",	&BenchMarkTestStack::CopyConstructor,	false);
	utime += RunMemFunc("stack", "=", 					&BenchMarkTestStack::OpeAssign,			false);
	utime += RunMemFunc("stack", "empty",				&BenchMarkTestStack::Empty,				false);
	utime += RunMemFunc("stack", "size",				&BenchMarkTestStack::Size,				false);
	utime += RunMemFunc("stack", "top",					&BenchMarkTestStack::Top,				false);
	utime += RunMemFunc("stack", "push",				&BenchMarkTestStack::Push,				true);
	utime += RunMemFunc("stack", "pop",					&BenchMarkTestStack::Pop,				true);
	utime += RunMemFunc("stack", "==",					&BenchMarkTestStack::OpeEqual,			false);
	utime += RunMemFunc("stack", "!=",					&BenchMarkTestStack::OpeNotEqual,		false);
	utime += RunMemFunc("stack", "<",					&BenchMarkTestStack::OpeLess,			false);
	utime += RunMemFunc("stack", "<=",					&BenchMarkTestStack::OpeLessEqual,		false);
	utime += RunMemFunc("stack", ">",					&BenchMarkTestStack::OpeGreater,		false);
	utime += RunMemFunc("stack", ">=",					&BenchMarkTestStack::OpeGreaterEqual,	false);

	PutElapsedTimeMsg(utime, "Stack");
	return (utime);
}

void	BenchMarkTest::RunAllTest()
{
	unsigned long	utime = 0;

	utime += RunVectorTest();
	utime += RunMapTest();
	utime += RunStackTest();

	PutElapsedTimeMsg(utime, "All");
}
