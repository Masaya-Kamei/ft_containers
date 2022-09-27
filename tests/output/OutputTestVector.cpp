#include <iostream>
#include "OutputTestVector.hpp"
#include "Put.hpp"

const int	OutputTestVector::nums_[5] = {10, 20, 30, 40, 50};

void	OutputTestVector::SetUpStatic()
{
}

void	OutputTestVector::SetUpVectorForRelationalOpe()
{
	large_.assign(nums_, nums_ + 3);
	large_[1] = 200;
	small_.assign(nums_, nums_ + 3);
	small_[1] = 2;
	more_.assign(nums_, nums_ + 4);
	less_.assign(nums_, nums_ + 2);
}

void	OutputTestVector::PutSizeCapElem(const ft::vector<Fixed>& v)
{
	std::cout << "size     : " << v.size()	   << std::endl;
	std::cout << "capacity : " << v.capacity() << std::endl;

	ft::vector<Fixed>::const_iterator	itr = v.begin();
	ft::vector<Fixed>::const_iterator	end = v.end();
	std::cout << "elem     : " << "[";
	for (; itr != end; ++itr)
		std::cout << *itr << ", ";
	std::cout << "]" << std::endl;
}

OutputTestVector::OutputTestVector()
	: cv_(nums_, nums_ + 3), v_(nums_, nums_ + 3)
{
}

void OutputTestVector::DefaultConstructor()
{
	ft::vector<Fixed> v;
	PutSizeCapElem(v);
}

void OutputTestVector::FillConstructor()
{
	ft::vector<Fixed> v1(5, 42);
	PutSizeCapElem(v1);
	ft::vector<Fixed> v2(5);
	PutSizeCapElem(v2);
	ft::vector<Fixed> v3(0);
	PutSizeCapElem(v3);
	try { ft::vector<Fixed>	v4(-1); }
	catch (std::length_error& e) {  Put("catch length_error"); }
}

void OutputTestVector::RangeConstructor()
{
	ft::vector<Fixed> v1(v_.begin(), v_.end());
	PutSizeCapElem(v1);
	ft::vector<Fixed> v2(nums_, nums_ + 3);
	PutSizeCapElem(v2);
	ft::vector<Fixed> v3(nums_, nums_);
	PutSizeCapElem(v3);
}

void OutputTestVector::CopyConstructor()
{
	ft::vector<Fixed> v(v_);
	PutSizeCapElem(v);
	Put(v.begin() != v_.begin());
}

void OutputTestVector::OpeAssign()
{
	ft::vector<Fixed> v;
	v = v_;
	PutSizeCapElem(v);
	Put(v.begin() != v_.begin());
}

void OutputTestVector::Begin()
{
	Put(*(itr_ = v_.begin()));
	Put(*(citr_ = v_.begin()));
	Put(*(citr_ = cv_.begin()));
	// Put(*(itr_ = cv_.begin()));
}

void OutputTestVector::End()
{
	Put(*(itr_ = v_.end() - 1));
	Put(*(citr_ = v_.end() - 1));
	Put(*(citr_ = cv_.end() - 1));
	// Put(*(itr_ = cv_.end() - 1));
}

void OutputTestVector::RBegin()
{
	Put(*(ritr_ = v_.rbegin()));
	Put(*(critr_ = v_.rbegin()));
	Put(*(critr_ = cv_.rbegin()));
	// Put(*(ritr_ = cv_.rbegin()));
}

void OutputTestVector::REnd()
{
	Put(*(ritr_ = v_.rend() - 1));
	Put(*(critr_ = v_.rend() - 1));
	Put(*(critr_ = cv_.rend() - 1));
	// Put(*(ritr_ = cv_.rend() - 1));
}

void OutputTestVector::Size()
{
	Put(v_.size());
	Put(v0_.size());
	v_.push_back(42);
	v_.push_back(42);
	v_.push_back(42);
	Put(v_.size());
}

void OutputTestVector::MaxSize()
{
	Put(v_.max_size());
	Put(v0_.max_size());
}

void OutputTestVector::Capacity()
{
	Put(v_.capacity());
	Put(v0_.capacity());
	v_.push_back(42);
	v_.push_back(42);
	v_.push_back(42);
	Put(v_.capacity());
}

void OutputTestVector::Empty()
{
	Put(v_.empty());
	Put(v0_.empty());
	v_.clear();
	Put(v_.empty());
}

void OutputTestVector::Resize()
{
	v_.resize(1, 42);
	PutSizeCapElem(v_);
	v_.resize(2, 43);
	PutSizeCapElem(v_);
	v_.resize(3, 44);
	PutSizeCapElem(v_);
	v_.resize(5, 45);
	PutSizeCapElem(v_);
	v_.resize(0, 46);
	PutSizeCapElem(v_);
	try { v_.resize(-1, 42); }
	catch (std::length_error& e) { Put("catch length_error"); }
	PutSizeCapElem(v_);
}

void OutputTestVector::Reserve()
{
	v_.reserve(1);
	PutSizeCapElem(v_);
	v_.reserve(3);
	PutSizeCapElem(v_);
	v_.reserve(5);
	try { v_.reserve(-1); }
	catch (std::length_error& e) { Put("catch length_error"); }
	PutSizeCapElem(v_);
}

void OutputTestVector::OpeBrackets()
{
	Put(v_[0]);
	Put(v_[1]);
	Put(v_[2]);
	Put(cv_[0]);
	Put(cv_[1]);
	Put(cv_[2]);
}

void OutputTestVector::At()
{
	Put(v_.at(0));
	Put(v_.at(1));
	Put(v_.at(2));
	Put(cv_.at(0));
	Put(cv_.at(1));
	Put(cv_.at(2));
	try { v_.at(3); }
	catch (std::out_of_range& e) { Put("catch out_of_range"); }
	try { cv_.at(3); }
	catch (std::out_of_range& e) { Put("catch out_of_range"); }
}

void OutputTestVector::Front()
{
	Put(v_.front());
	Put(cv_.front());
	// Put(v0_.front());
}

void OutputTestVector::Back()
{
	Put(v_.back());
	Put(cv_.back());
	// Put(v0_.back());
}

void OutputTestVector::Data()
{
	Put(*(v_.data()));
	Put(*(cv_.data()));
	// Put(*(v0_.data()));
}

void OutputTestVector::AssignFill()
{
	v_.assign(4, 42);
	PutSizeCapElem(v_);
	v_.assign(4, 42);
	PutSizeCapElem(v_);
	v_.assign(4, 42);
	PutSizeCapElem(v_);
	v_.assign(4, 42);
	PutSizeCapElem(v_);
	v_.assign(4, 42);
	PutSizeCapElem(v_);
	try { v_.assign(-1, 42); }
	catch (std::length_error& e) { Put("catch length_error"); }
	PutSizeCapElem(v_);
}

void OutputTestVector::AssignRange()
{
	v_.assign(nums_, nums_ + 4);
	PutSizeCapElem(v_);
	v_.assign(nums_, nums_ + 1);
	PutSizeCapElem(v_);
	v_.assign(nums_, nums_ + 3);
	PutSizeCapElem(v_);
	v_.assign(nums_, nums_);
	PutSizeCapElem(v_);
	try { v_.assign(nums_, nums_ - 1); }
	catch (std::length_error& e) { Put("catch length_error"); }
	PutSizeCapElem(v_);
}

void OutputTestVector::PushBack()
{
	v_.push_back(42);
	PutSizeCapElem(v_);
	v_.push_back(43); v_.push_back(44); v_.push_back(45);
	v_.push_back(46); v_.push_back(47); v_.push_back(48);
	PutSizeCapElem(v_);
}

void OutputTestVector::PopBack()
{
	v_.pop_back();
	PutSizeCapElem(v_);
	v_.pop_back();
	PutSizeCapElem(v_);
	v_.pop_back();
	PutSizeCapElem(v_);
	// v_.pop_back();
	// PutSizeCapElem(v_);
}

void OutputTestVector::InsertSingle()
{
	itr_ = v_.insert(v_.begin(), 42);
	Put(*itr_);
	PutSizeCapElem(v_);
	itr_ = v_.insert(v_.begin() + 1, 43);
	Put(*itr_);
	PutSizeCapElem(v_);
	itr_ = v_.insert(v_.begin() + 2, 44);
	Put(*itr_);
	PutSizeCapElem(v_);
	itr_ = v_.insert(v_.end(), 45);
	Put(*itr_);
	PutSizeCapElem(v_);
}

void OutputTestVector::InsertFill()
{
	v_.insert(v_.begin(), 2, 42);
	PutSizeCapElem(v_);
	v_.insert(v_.begin() + 1, 5, 43);
	PutSizeCapElem(v_);
	v_.insert(v_.begin() + 2, 8, 44);
	PutSizeCapElem(v_);
	v_.insert(v_.end(), 100, 45);
	PutSizeCapElem(v_);
}

void OutputTestVector::InsertRange()
{
	v_.insert(v_.begin(), nums_, nums_ + 3);
	PutSizeCapElem(v_);
	v_.insert(v_.begin() + 1, nums_, nums_ + 1);
	PutSizeCapElem(v_);
	v_.insert(v_.begin() + 2, nums_, nums_);
	PutSizeCapElem(v_);
	v_.insert(v_.end(), nums_, nums_ + 2);
	PutSizeCapElem(v_);
}

void OutputTestVector::EraseSingle()
{
	ft::vector<Fixed>::iterator	begin = v_.begin();

	itr_ = v_.erase(begin + 1);
	Put(*itr_);
	PutSizeCapElem(v_);
	itr_ = v_.erase(begin + 1);
	Put(itr_ == v_.end());
	PutSizeCapElem(v_);
	itr_ = v_.erase(begin);
	Put(itr_ == v_.end());
	PutSizeCapElem(v_);
}

void OutputTestVector::EraseRange()
{
	ft::vector<Fixed>	v1(v_);
	ft::vector<Fixed>	v2(v_);

	itr_ = v_.erase(v_.begin(), v_.begin() + 2);
	Put(*itr_);
	PutSizeCapElem(v_);
	itr_ = v1.erase(v1.begin() + 1, v1.begin() + 3);
	Put(itr_ == v1.end());
	PutSizeCapElem(v1);
	itr_ = v2.erase(v2.begin(), v2.end());
	Put(itr_ == v2.end());
	PutSizeCapElem(v2);
}

void OutputTestVector::Swap()
{
	ft::vector<Fixed>::iterator	begin = v_.begin();
	ft::vector<Fixed>			v1(5, 42);
	v_.swap(v1);
	PutSizeCapElem(v_);
	PutSizeCapElem(v1);
	Put(begin == v1.begin());

	v_.swap(v0_);
	PutSizeCapElem(v_);
	PutSizeCapElem(v0_);
}

void OutputTestVector::Clear()
{
	v_.clear();
	PutSizeCapElem(v_);
	v_.assign(nums_, nums_ + 3);
	PutSizeCapElem(v_);

	v0_.clear();
	PutSizeCapElem(v0_);
}

void OutputTestVector::GetAllocator()
{
	Put(cv_.get_allocator() == std::allocator<Fixed>());
}

void OutputTestVector::OpeEqual()
{
	SetUpVectorForRelationalOpe();
	Put(v_ == v_);
	Put(v_ == large_);
	Put(v_ == small_);
	Put(v_ == more_);
	Put(v_ == less_);
}

void OutputTestVector::OpeNotEqual()
{
	SetUpVectorForRelationalOpe();
	Put(v_ != v_);
	Put(v_ != large_);
	Put(v_ != small_);
	Put(v_ != more_);
	Put(v_ != less_);
}

void OutputTestVector::OpeLess()
{
	SetUpVectorForRelationalOpe();
	Put(v_ < v_);
	Put(v_ < large_);
	Put(v_ < small_);
	Put(v_ < more_);
	Put(v_ < less_);
}

void OutputTestVector::OpeLessEqual()
{
	SetUpVectorForRelationalOpe();
	Put(v_ <= v_);
	Put(v_ <= large_);
	Put(v_ <= small_);
	Put(v_ <= more_);
	Put(v_ <= less_);
}

void OutputTestVector::OpeGreater()
{
	SetUpVectorForRelationalOpe();
	Put(v_ > v_);
	Put(v_ > large_);
	Put(v_ > small_);
	Put(v_ > more_);
	Put(v_ > less_);
}

void OutputTestVector::OpeGreaterEqual()
{
	SetUpVectorForRelationalOpe();
	Put(v_ >= v_);
	Put(v_ >= large_);
	Put(v_ >= small_);
	Put(v_ >= more_);
	Put(v_ >= less_);
}

void OutputTestVector::NonMemberSwap()
{
	ft::vector<Fixed>::iterator	begin = v_.begin();
	ft::vector<Fixed>			v1(5, 42);
	swap(v_, v1);
	PutSizeCapElem(v_);
	PutSizeCapElem(v1);
	Put(begin == v1.begin());

	swap(v_, v0_);
	PutSizeCapElem(v_);
	PutSizeCapElem(v0_);
}
