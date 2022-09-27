#include <iostream>
#include <iomanip>
#include "OutputTest.hpp"
#include "OutputTestVector.hpp"

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
	// RunMemFunc("vector", "==",					&OutputTestVector::OpeEqual);
	// RunMemFunc("vector", "!=",					&OutputTestVector::OpeNotEqual);
	// RunMemFunc("vector", "<",					&OutputTestVector::OpeLess);
	// RunMemFunc("vector", "<=",					&OutputTestVector::OpeLessEqual);
	// RunMemFunc("vector", ">",					&OutputTestVector::OpeGreater);
	// RunMemFunc("vector", ">=",					&OutputTestVector::OpeGreaterEqual);
	// RunMemFunc("vector", "non member swap",		&OutputTestVector::NonMemberSwap);
}

void	OutputTest::RunAllTest()
{
	RunVectorTest();
}
