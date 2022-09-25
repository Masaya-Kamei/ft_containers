#include "BenchMarkTestStack.hpp"
#include "Random.hpp"

ft::stack<int, ft::vector<int> >	BenchMarkTestStack::cs_;
ft::stack<int, ft::vector<int> >	BenchMarkTestStack::cs1_;

void	BenchMarkTestStack::SetUpStatic()
{
	for (int i = 0; i < 10000; ++i)
		cs_.push(42);
	for (int i = 0; i < 20000; ++i)
		cs1_.push(42);
}

BenchMarkTestStack::BenchMarkTestStack(bool setup_flag)
{
	if (setup_flag)
		s_ = cs_;
}

void BenchMarkTestStack::DefaultConstructor()	{ ft::stack<int, ft::vector<int> > s; }
void BenchMarkTestStack::CopyConstructor()		{ ft::stack<int, ft::vector<int> > s(cs_); }
void BenchMarkTestStack::OpeAssign()			{ ft::stack<int, ft::vector<int> > s; s = cs_; }
void BenchMarkTestStack::Empty()				{ cs_.empty(); }
void BenchMarkTestStack::Size()					{ cs_.size(); }
void BenchMarkTestStack::Top()					{ cs_.top(); }
void BenchMarkTestStack::Push()					{ s_.push(42); }
void BenchMarkTestStack::Pop()					{ s_.pop(); }
void BenchMarkTestStack::OpeEqual()				{ (void)(cs_ == cs1_); }
void BenchMarkTestStack::OpeNotEqual()			{ (void)(cs_ != cs1_); }
void BenchMarkTestStack::OpeLess()				{ (void)(cs_ <  cs1_); }
void BenchMarkTestStack::OpeLessEqual()			{ (void)(cs_ <= cs1_); }
void BenchMarkTestStack::OpeGreater()			{ (void)(cs_ >  cs1_); }
void BenchMarkTestStack::OpeGreaterEqual()		{ (void)(cs_ >= cs1_); }
