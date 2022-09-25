#include "BenchMarkTestVector.hpp"
#include "Random.hpp"

ft::vector<int>	BenchMarkTestVector::cv_;
ft::vector<int>	BenchMarkTestVector::cv1_;

static int		RandomSize()	{ return (rand() % 20000); }

void	BenchMarkTestVector::SetUpStatic()
{
	for (int i = 0; i < 10000; ++i)
		cv_.push_back(42);
	for (int i = 0; i < 20000; ++i)
		cv1_.push_back(42);
}

BenchMarkTestVector::BenchMarkTestVector(bool setup_flag)
{
	if (setup_flag)
		v_ = cv_;
}

void BenchMarkTestVector::DefaultConstructor()	{ ft::vector<int> v; }
void BenchMarkTestVector::FillConstructor() 	{ ft::vector<int> v(10000, 42); }
void BenchMarkTestVector::RangeConstructor()	{ ft::vector<int> v(cv_.begin(), cv_.end()); }
void BenchMarkTestVector::CopyConstructor()		{ ft::vector<int> v(cv_); }
void BenchMarkTestVector::OpeAssign()			{ ft::vector<int> v; v = cv_; }
void BenchMarkTestVector::Begin()				{ cv_.begin(); }
void BenchMarkTestVector::End()					{ cv_.end(); }
void BenchMarkTestVector::RBegin()				{ cv_.rbegin(); }
void BenchMarkTestVector::REnd()				{ cv_.rend(); }
void BenchMarkTestVector::Size()				{ cv_.size(); }
void BenchMarkTestVector::MaxSize()				{ cv_.max_size(); }
void BenchMarkTestVector::Capacity()			{ cv_.capacity(); }
void BenchMarkTestVector::Empty()				{ cv_.empty(); }
void BenchMarkTestVector::Resize()				{ v_.resize(RandomSize()); }
void BenchMarkTestVector::Reserve()				{ v_.reserve(RandomSize()); }
void BenchMarkTestVector::OpeBrackets()			{ cv_[rand() % cv_.size()]; }
void BenchMarkTestVector::At()					{ try { cv_[RandomSize()]; } catch(...) {} }
void BenchMarkTestVector::Front()				{ cv_.front(); }
void BenchMarkTestVector::Back()				{ cv_.back(); }
void BenchMarkTestVector::Data()				{ cv_.data(); }
void BenchMarkTestVector::AssignFill()			{ v_.assign(RandomSize(), 42); }
void BenchMarkTestVector::AssignRange()			{ v_.assign(cv1_.begin(), RandomItr(cv1_)); }
void BenchMarkTestVector::PushBack()			{ v_.push_back(42); }
void BenchMarkTestVector::PopBack()				{ v_.pop_back(); }
void BenchMarkTestVector::InsertSingle()		{ v_.insert(RandomItr(v_), 42); }
void BenchMarkTestVector::InsertFill()			{ v_.insert(RandomItr(v_), rand() % 1000, 42); }
void BenchMarkTestVector::InsertRange()			{ v_.insert(RandomItr(v_), cv1_.begin(), RandomItr(cv1_)); }
void BenchMarkTestVector::EraseSingle()			{ v_.erase(RandomItr(v_)); }
void BenchMarkTestVector::EraseRange()			{ v_.erase(v_.begin(), v_.end()); }
void BenchMarkTestVector::Swap()				{ cv_.swap(cv1_); }
void BenchMarkTestVector::Clear()				{ v_.clear(); }
void BenchMarkTestVector::GetAllocator()		{ cv_.get_allocator(); }
void BenchMarkTestVector::OpeEqual()			{ (void)(cv_ == cv1_); }
void BenchMarkTestVector::OpeNotEqual()			{ (void)(cv_ != cv1_); }
void BenchMarkTestVector::OpeLess()				{ (void)(cv_ < cv1_); }
void BenchMarkTestVector::OpeLessEqual()		{ (void)(cv_ <= cv1_); }
void BenchMarkTestVector::OpeGreater()			{ (void)(cv_ > cv1_); }
void BenchMarkTestVector::OpeGreaterEqual()		{ (void)(cv_ >= cv1_); }
void BenchMarkTestVector::NonMemberSwap()		{ swap(cv_, cv1_); }
