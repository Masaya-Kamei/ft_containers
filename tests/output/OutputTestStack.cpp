#include "OutputTestStack.hpp"
#include "Put.hpp"

const int	OutputTestStack::nums_[5] = {10, 20, 30, 40, 50};
const ft::vector<Fixed>	OutputTestStack::cv_(nums_, nums_ + 3);

void	OutputTestStack::SetUpStatic()
{
}

void	OutputTestStack::SetUpStackForRelationalOpe()
{
	large_.push(10); large_.push(200); large_.push(30);
	small_.push(10); small_.push(2);   small_.push(30);
	more_.push(10);	 more_.push(20);   more_.push(30);  more_.push(40);
	less_.push(10);	 less_.push(20);
}

void	OutputTestStack::PutSizeTop(const ft::stack<Fixed, ft::vector<Fixed> >& s)
{
	std::cout << "size : "	<< s.size() << std::endl;
	if (s.size() > 0)
		std::cout << "top  : "	<< s.top() << std::endl;
}

OutputTestStack::OutputTestStack()
	: cs_(cv_), s_(cv_)
{
}

void	OutputTestStack::DefaultConstructor()
{
	ft::stack<Fixed, ft::vector<Fixed> >	s;
	PutSizeTop(s);
}

void	OutputTestStack::CopyConstructor()
{
	ft::stack<Fixed, ft::vector<Fixed> >	s1(s_);
	PutSizeTop(s1);
	ft::stack<Fixed, ft::vector<Fixed> >	s2(s0_);
	PutSizeTop(s2);
	ft::stack<Fixed, ft::vector<Fixed> >	s3(cv_);
	PutSizeTop(s3);
}

void	OutputTestStack::OpeAssign()
{
	ft::stack<Fixed, ft::vector<Fixed> >	s1;
	s1 = s_;
	PutSizeTop(s1);
	ft::stack<Fixed, ft::vector<Fixed> >	s2;
	s2 = s0_;
	PutSizeTop(s2);
	// ft::stack<Fixed, ft::vector<Fixed> >	s3;
	// s3 = cv_;
	// PutSizeTop(s3);
}

void	OutputTestStack::Empty()
{
	Put(s_.empty());
	Put(s0_.empty());
	Put(cs_.empty());

	s_.pop(); s_.pop(); s_.pop();
	Put(s_.empty());
}

void	OutputTestStack::Size()
{
	Put(s_.size());
	Put(cs_.size());
	Put(s0_.size());
}

void	OutputTestStack::Top()
{
	Put(s_.top());
	Put(cs_.top());
	// Put(s0_.top());

	s_.push(42);
	Put(s_.top());
	s_.pop();
	Put(s_.top());
}

void	OutputTestStack::Push()
{
	s_.push(42);
	PutSizeTop(s_);
	s0_.push(42);
	PutSizeTop(s0_);
}

void	OutputTestStack::Pop()
{
	s_.pop();
	PutSizeTop(s_);
	s_.pop();
	PutSizeTop(s_);
	s_.pop();
	PutSizeTop(s_);
	// s_.pop();
	// PutSizeTop(s_);
}

void	OutputTestStack::OpeEqual()
{
	SetUpStackForRelationalOpe();
	Put(s_ == s_);
	Put(s_ == large_);
	Put(s_ == small_);
	Put(s_ == more_);
	Put(s_ == less_);
}

void	OutputTestStack::OpeNotEqual()
{
	SetUpStackForRelationalOpe();
	Put(s_ != s_);
	Put(s_ != large_);
	Put(s_ != small_);
	Put(s_ != more_);
	Put(s_ != less_);
}

void	OutputTestStack::OpeLess()
{
	SetUpStackForRelationalOpe();
	Put(s_ < s_);
	Put(s_ < large_);
	Put(s_ < small_);
	Put(s_ < more_);
	Put(s_ < less_);
}

void	OutputTestStack::OpeLessEqual()
{
	SetUpStackForRelationalOpe();
	Put(s_ <= s_);
	Put(s_ <= large_);
	Put(s_ <= small_);
	Put(s_ <= more_);
	Put(s_ <= less_);
}

void	OutputTestStack::OpeGreater()
{
	SetUpStackForRelationalOpe();
	Put(s_ > s_);
	Put(s_ > large_);
	Put(s_ > small_);
	Put(s_ > more_);
	Put(s_ > less_);
}

void	OutputTestStack::OpeGreaterEqual()
{
	SetUpStackForRelationalOpe();
	Put(s_ >= s_);
	Put(s_ >= large_);
	Put(s_ >= small_);
	Put(s_ >= more_);
	Put(s_ >= less_);
}
