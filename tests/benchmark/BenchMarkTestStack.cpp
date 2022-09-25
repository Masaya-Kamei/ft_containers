#include "BenchMarkTest.hpp"

void BenchMarkTest::StackDefaultConstructor()	{ ft::stack<int, ft::vector<int> > s; }
void BenchMarkTest::StackCopyConstructor()		{ ft::stack<int, ft::vector<int> > s(s_); }
void BenchMarkTest::StackOpeAssign()			{ ft::stack<int, ft::vector<int> > s; s = s_; }
void BenchMarkTest::StackEmpty()				{ s_.empty(); }
void BenchMarkTest::StackSize()					{ s_.size(); }
void BenchMarkTest::StackTop()					{ s_.top(); }
void BenchMarkTest::StackPush()					{ s_.push(RandomVal()); }
void BenchMarkTest::StackPop()					{ s_.pop(); }
void BenchMarkTest::StackOpeEqual()				{ (void)(s_ == s1_); }
void BenchMarkTest::StackOpeNotEqual()			{ (void)(s_ != s1_); }
void BenchMarkTest::StackOpeLess()				{ (void)(s_ < s1_); }
void BenchMarkTest::StackOpeLessEqual()			{ (void)(s_ <= s1_); }
void BenchMarkTest::StackOpeGreater()			{ (void)(s_ > s1_); }
void BenchMarkTest::StackOpeGreaterEqual()		{ (void)(s_ >= s1_); }


void	BenchMarkTest::RunStackTest()
{
	int		size;
	size = RandomSize();
	for (int i = 0; i < size; ++i)
		s_.push(RandomVal());
	size = RandomSize();
	for (int i = 0; i < size; ++i)
		s1_.push(RandomVal());

	Timer	timer;

	MeasureMemFunc("stack", "default constructor",	&BenchMarkTest::StackDefaultConstructor);
	MeasureMemFunc("stack", "copy constructor",		&BenchMarkTest::StackCopyConstructor);
	MeasureMemFunc("stack", "=", 					&BenchMarkTest::StackOpeAssign);
	MeasureMemFunc("stack", "empty",				&BenchMarkTest::StackEmpty);
	MeasureMemFunc("stack", "size",					&BenchMarkTest::StackSize);
	MeasureMemFunc("stack", "top",					&BenchMarkTest::StackTop);
	MeasureMemFunc("stack", "push",					&BenchMarkTest::StackPush);
	MeasureMemFunc("stack", "pop",					&BenchMarkTest::StackPop);
	MeasureMemFunc("stack", "==",					&BenchMarkTest::StackOpeEqual);
	MeasureMemFunc("stack", "!=",					&BenchMarkTest::StackOpeNotEqual);
	MeasureMemFunc("stack", "<",					&BenchMarkTest::StackOpeLess);
	MeasureMemFunc("stack", "<=",					&BenchMarkTest::StackOpeLessEqual);
	MeasureMemFunc("stack", ">",					&BenchMarkTest::StackOpeGreater);
	MeasureMemFunc("stack", ">=",					&BenchMarkTest::StackOpeGreaterEqual);

	PutElapsedTimeMsg(timer, "Stack");
}
