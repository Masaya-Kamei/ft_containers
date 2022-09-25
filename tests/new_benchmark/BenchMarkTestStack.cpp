#include "BenchMarkTestStack.hpp"
#include "Random.hpp"

ft::stack<int, ft::vector<int> >	BenchMarkTestStack::base_s_;
ft::stack<int, ft::vector<int> >	BenchMarkTestStack::base_s1_;

void	BenchMarkTestStack::SetUp()
{
	for (int i = 0; i < 10000; ++i)
		base_s_.push(42);
	for (int i = 0; i < 20000; ++i)
		base_s1_.push(42);
}

BenchMarkTestStack::BenchMarkTestStack()
	: s_(base_s_), s1_(base_s1_)
{
}

void BenchMarkTestStack::DefaultConstructor()	{ ft::stack<int, ft::vector<int> > s; }
void BenchMarkTestStack::CopyConstructor()		{ ft::stack<int, ft::vector<int> > s(s_); }
void BenchMarkTestStack::OpeAssign()			{ ft::stack<int, ft::vector<int> > s; s = s_; }
void BenchMarkTestStack::Empty()				{ s_.empty(); }
void BenchMarkTestStack::Size()					{ s_.size(); }
void BenchMarkTestStack::Top()					{ s_.top(); }
void BenchMarkTestStack::Push()					{ s_.push(42); }
void BenchMarkTestStack::Pop()					{ s_.pop(); }
void BenchMarkTestStack::OpeEqual()				{ (void)(s_ == s1_); }
void BenchMarkTestStack::OpeNotEqual()			{ (void)(s_ != s1_); }
void BenchMarkTestStack::OpeLess()				{ (void)(s_ < s1_); }
void BenchMarkTestStack::OpeLessEqual()			{ (void)(s_ <= s1_); }
void BenchMarkTestStack::OpeGreater()			{ (void)(s_ > s1_); }
void BenchMarkTestStack::OpeGreaterEqual()		{ (void)(s_ >= s1_); }
