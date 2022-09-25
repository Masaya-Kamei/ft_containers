#include "BenchMarkTestVector.hpp"
#include "Random.hpp"

ft::vector<int>	BenchMarkTestVector::base_v_;
ft::vector<int>	BenchMarkTestVector::base_v1_;

void	BenchMarkTestVector::SetUp()
{
	for (int i = 0; i < 10000; ++i)
		base_v_.push_back(RandomVal());
	for (int i = 0; i < 20000; ++i)
		base_v1_.push_back(RandomVal());
}

BenchMarkTestVector::BenchMarkTestVector()
	: v_(base_v_), v1_(base_v1_)
{
}

void BenchMarkTestVector::DefaultConstructor()	{ ft::vector<int> v; }
void BenchMarkTestVector::FillConstructor() 	{ ft::vector<int> v(10000, 42); }
void BenchMarkTestVector::RangeConstructor()	{ ft::vector<int> v(v_.begin(), v_.end()); }
void BenchMarkTestVector::CopyConstructor()		{ ft::vector<int> v(v_); }
void BenchMarkTestVector::OpeAssign()			{ ft::vector<int> v; v = v_; }
void BenchMarkTestVector::Begin()				{ v_.begin(); }
void BenchMarkTestVector::End()					{ v_.end(); }
void BenchMarkTestVector::RBegin()				{ v_.rbegin(); }
void BenchMarkTestVector::REnd()				{ v_.rend(); }
void BenchMarkTestVector::Size()				{ v_.size(); }
void BenchMarkTestVector::MaxSize()				{ v_.max_size(); }
void BenchMarkTestVector::Capacity()			{ v_.capacity(); }
void BenchMarkTestVector::Empty()				{ v_.empty(); }
void BenchMarkTestVector::Resize()				{ v_.resize(rand() % 20000); }
void BenchMarkTestVector::Reserve()				{ v_.reserve(rand() % 20000); }
void BenchMarkTestVector::OpeBrackets()			{ v_[rand() % v_.size()]; }
void BenchMarkTestVector::At()					{ try { v_[rand() % 20000]; } catch(...) {} }
void BenchMarkTestVector::Front()				{ v_.front(); }
void BenchMarkTestVector::Back()				{ v_.back(); }
void BenchMarkTestVector::Data()				{ v_.data(); }
void BenchMarkTestVector::AssignFill()			{ v_.assign(rand() % 20000, 42); }
void BenchMarkTestVector::AssignRange()			{ v_.assign(v1_.begin(), RandomItr(v1_)); }
void BenchMarkTestVector::PushBack()			{ v_.push_back(42); }
void BenchMarkTestVector::PopBack()				{ v_.pop_back(); }
void BenchMarkTestVector::InsertSingle()		{ v_.insert(RandomItr(v_), 42); }
void BenchMarkTestVector::InsertFill()			{ v_.insert(RandomItr(v_), rand() % 1000, 42); }
void BenchMarkTestVector::InsertRange()			{ v_.insert(RandomItr(v_), v1_.begin(), RandomItr(v1_)); }
void BenchMarkTestVector::EraseSingle()			{ v_.erase(RandomItr(v_)); }
void BenchMarkTestVector::EraseRange()			{ v_.erase(v_.begin(), v_.end()); }
void BenchMarkTestVector::Swap()				{ v_.swap(v1_); }
void BenchMarkTestVector::Clear()				{ v_.clear(); }
void BenchMarkTestVector::GetAllocator()		{ v_.get_allocator(); }
void BenchMarkTestVector::OpeEqual()			{ (void)(v_ == v1_); }
void BenchMarkTestVector::OpeNotEqual()			{ (void)(v_ != v1_); }
void BenchMarkTestVector::OpeLess()				{ (void)(v_ < v1_); }
void BenchMarkTestVector::OpeLessEqual()		{ (void)(v_ <= v1_); }
void BenchMarkTestVector::OpeGreater()			{ (void)(v_ > v1_); }
void BenchMarkTestVector::OpeGreaterEqual()		{ (void)(v_ >= v1_); }
void BenchMarkTestVector::NonMemberSwap()		{ swap(v_, v1_); }
