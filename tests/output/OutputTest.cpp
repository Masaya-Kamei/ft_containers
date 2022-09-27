#include <iostream>
#include <iomanip>
#include "OutputTest.hpp"
#include "OutputTestVector.hpp"
#include "OutputTestMap.hpp"
#include "OutputTestStack.hpp"

OutputTest::OutputTest(const unsigned int seed)
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

void	OutputTest::RunVectorTest()
{
	OutputTestVector::SetUpStatic();

	RunMemFunc("vector", "default constructor", &OutputTestVector::DefaultConstructor);
	RunMemFunc("vector", "fill constructor",	&OutputTestVector::FillConstructor);
	RunMemFunc("vector", "range constructor",	&OutputTestVector::RangeConstructor);
	RunMemFunc("vector", "copy constructor",	&OutputTestVector::CopyConstructor);
	RunMemFunc("vector", "=", 					&OutputTestVector::OpeAssign);
	RunMemFunc("vector", "begin", 				&OutputTestVector::Begin);
	RunMemFunc("vector", "end", 				&OutputTestVector::End);
	RunMemFunc("vector", "rbegin",				&OutputTestVector::RBegin);
	RunMemFunc("vector", "rend", 				&OutputTestVector::REnd);
	RunMemFunc("vector", "size",				&OutputTestVector::Size);
	RunMemFunc("vector", "max_size",			&OutputTestVector::MaxSize);
	RunMemFunc("vector", "capacity",			&OutputTestVector::Capacity);
	RunMemFunc("vector", "empty",				&OutputTestVector::Empty);
	RunMemFunc("vector", "resize",				&OutputTestVector::Resize);
	RunMemFunc("vector", "reserve",				&OutputTestVector::Reserve);
	RunMemFunc("vector", "[]",					&OutputTestVector::OpeBrackets);
	RunMemFunc("vector", "at",					&OutputTestVector::At);
	RunMemFunc("vector", "front",				&OutputTestVector::Front);
	RunMemFunc("vector", "back",				&OutputTestVector::Back);
	RunMemFunc("vector", "data",				&OutputTestVector::Data);
	RunMemFunc("vector", "assign fill",			&OutputTestVector::AssignFill);
	RunMemFunc("vector", "assign range",		&OutputTestVector::AssignRange);
	RunMemFunc("vector", "push_back",			&OutputTestVector::PushBack);
	RunMemFunc("vector", "pop_back",			&OutputTestVector::PopBack);
	RunMemFunc("vector", "insert single",		&OutputTestVector::InsertSingle);
	RunMemFunc("vector", "insert fill",			&OutputTestVector::InsertFill);
	RunMemFunc("vector", "insert range",		&OutputTestVector::InsertRange);
	RunMemFunc("vector", "erase single",		&OutputTestVector::EraseSingle);
	RunMemFunc("vector", "erase range",			&OutputTestVector::EraseRange);
	RunMemFunc("vector", "swap",				&OutputTestVector::Swap);
	RunMemFunc("vector", "clear",				&OutputTestVector::Clear);
	RunMemFunc("vector", "get_allocator",		&OutputTestVector::GetAllocator);
	RunMemFunc("vector", "==",					&OutputTestVector::OpeEqual);
	RunMemFunc("vector", "!=",					&OutputTestVector::OpeNotEqual);
	RunMemFunc("vector", "<",					&OutputTestVector::OpeLess);
	RunMemFunc("vector", "<=",					&OutputTestVector::OpeLessEqual);
	RunMemFunc("vector", ">",					&OutputTestVector::OpeGreater);
	RunMemFunc("vector", ">=",					&OutputTestVector::OpeGreaterEqual);
	RunMemFunc("vector", "non member swap",		&OutputTestVector::NonMemberSwap);
}

void	OutputTest::RunMapTest()
{
	OutputTestMap::SetUpStatic();

	RunMemFunc("map", "default constructor", &OutputTestMap::DefaultConstructor);
	RunMemFunc("map", "range constructor",	&OutputTestMap::RangeConstructor);
	RunMemFunc("map", "copy constructor",	&OutputTestMap::CopyConstructor);
	RunMemFunc("map", "=", 					&OutputTestMap::OpeAssign);
	RunMemFunc("map", "empty",				&OutputTestMap::Empty);
	RunMemFunc("map", "size",				&OutputTestMap::Size);
	RunMemFunc("map", "max_size",			&OutputTestMap::MaxSize);
	RunMemFunc("map", "begin", 				&OutputTestMap::Begin);
	RunMemFunc("map", "end", 				&OutputTestMap::End);
	RunMemFunc("map", "rbegin",				&OutputTestMap::RBegin);
	RunMemFunc("map", "rend", 				&OutputTestMap::REnd);
	RunMemFunc("map", "[]",					&OutputTestMap::OpeBrackets);
	RunMemFunc("map", "insert single",		&OutputTestMap::InsertSingle);
	RunMemFunc("map", "insert hint",		&OutputTestMap::InsertHint);
	RunMemFunc("map", "insert range",		&OutputTestMap::InsertRange);
	RunMemFunc("map", "erase single iter",	&OutputTestMap::EraseSingleIter);
	RunMemFunc("map", "erase single key",	&OutputTestMap::EraseSingleKey);
	RunMemFunc("map", "erase range",		&OutputTestMap::EraseRange);
	RunMemFunc("map", "swap",				&OutputTestMap::Swap);
	RunMemFunc("map", "clear",				&OutputTestMap::Clear);
	RunMemFunc("map", "key_comp",			&OutputTestMap::KeyComp);
	RunMemFunc("map", "value_comp",			&OutputTestMap::ValueComp);
	RunMemFunc("map", "find",				&OutputTestMap::Find);
	RunMemFunc("map", "count",				&OutputTestMap::Count);
	RunMemFunc("map", "lower_bound",		&OutputTestMap::LowerBound);
	RunMemFunc("map", "upper_bound",		&OutputTestMap::UpperBound);
	RunMemFunc("map", "equal_range",		&OutputTestMap::EqualRange);
	RunMemFunc("map", "get_allocator",		&OutputTestMap::GetAllocator);
	RunMemFunc("map", "==",					&OutputTestMap::OpeEqual);
	RunMemFunc("map", "!=",					&OutputTestMap::OpeNotEqual);
	RunMemFunc("map", "<",					&OutputTestMap::OpeLess);
	RunMemFunc("map", "<=",					&OutputTestMap::OpeLessEqual);
	RunMemFunc("map", ">",					&OutputTestMap::OpeGreater);
	RunMemFunc("map", ">=",					&OutputTestMap::OpeGreaterEqual);
	RunMemFunc("map", "non member swap",	&OutputTestMap::NonMemberSwap);
}

void	OutputTest::RunStackTest()
{
	OutputTestStack::SetUpStatic();

	RunMemFunc("stack", "default constructor",	&OutputTestStack::DefaultConstructor);
	RunMemFunc("stack", "copy constructor",		&OutputTestStack::CopyConstructor);
	RunMemFunc("stack", "=", 					&OutputTestStack::OpeAssign);
	RunMemFunc("stack", "empty",				&OutputTestStack::Empty);
	RunMemFunc("stack", "size",					&OutputTestStack::Size);
	RunMemFunc("stack", "top",					&OutputTestStack::Top);
	RunMemFunc("stack", "push",					&OutputTestStack::Push);
	RunMemFunc("stack", "pop",					&OutputTestStack::Pop);
	RunMemFunc("stack", "==",					&OutputTestStack::OpeEqual);
	RunMemFunc("stack", "!=",					&OutputTestStack::OpeNotEqual);
	RunMemFunc("stack", "<",					&OutputTestStack::OpeLess);
	RunMemFunc("stack", "<=",					&OutputTestStack::OpeLessEqual);
	RunMemFunc("stack", ">",					&OutputTestStack::OpeGreater);
	RunMemFunc("stack", ">=",					&OutputTestStack::OpeGreaterEqual);
}

void	OutputTest::RunAllTest()
{
	RunVectorTest();
	RunMapTest();
	RunStackTest();
}
