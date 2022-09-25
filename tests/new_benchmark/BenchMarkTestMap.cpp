#include "BenchMarkTestMap.hpp"
#include "Random.hpp"

ft::map<int, std::string>	BenchMarkTestMap::base_m_;
ft::map<int, std::string>	BenchMarkTestMap::base_m1_;

static int		RandomKey()	{ return (rand() % 10000); }

void	BenchMarkTestMap::SetUp()
{
	for (int i = 0; i < 1000; ++i)
		base_m_.insert(ft::make_pair(RandomKey(), "X"));
	for (int i = 0; i < 1000; ++i)
		base_m1_.insert(ft::make_pair(RandomKey(), "X"));
}

BenchMarkTestMap::BenchMarkTestMap()
	: m_(base_m_), m1_(base_m1_)
{
}

void BenchMarkTestMap::DefaultConstructor()	{ ft::map<int, std::string> m; }
void BenchMarkTestMap::RangeConstructor()	{ ft::map<int, std::string> m(m_.begin(), m_.end()); }
void BenchMarkTestMap::CopyConstructor()	{ ft::map<int, std::string> m(m_); }
void BenchMarkTestMap::OpeAssign()			{ ft::map<int, std::string> m; m = m_; }
void BenchMarkTestMap::Empty()				{ m_.empty(); }
void BenchMarkTestMap::Size()				{ m_.size(); }
void BenchMarkTestMap::MaxSize()			{ m_.max_size(); }
void BenchMarkTestMap::Begin()				{ m_.begin(); }
void BenchMarkTestMap::End()				{ m_.end(); }
void BenchMarkTestMap::RBegin()				{ m_.rbegin(); }
void BenchMarkTestMap::REnd()				{ m_.rend(); }
void BenchMarkTestMap::OpeBrackets()		{ m_[rand() % m_.size()]; }
void BenchMarkTestMap::InsertSingle()		{ m_.insert(ft::make_pair(RandomKey(), "X")); }
void BenchMarkTestMap::InsertHint()			{ m_.insert(RandomItr(m_), ft::make_pair(RandomKey(), "X")); }
void BenchMarkTestMap::InsertRange()		{ m_.insert(m1_.begin(), RandomItr(m1_)); }
void BenchMarkTestMap::EraseSingleIter()	{ m_.erase(RandomItr(m_)); }
void BenchMarkTestMap::EraseSingleKey()		{ m_.erase(RandomKey()); }
void BenchMarkTestMap::EraseRange()			{ m_.erase(m_.begin(), m_.end()); }
void BenchMarkTestMap::Swap()				{ m_.swap(m1_); }
void BenchMarkTestMap::Clear()				{ m_.clear(); }
void BenchMarkTestMap::KeyComp()			{ m_.key_comp(); }
void BenchMarkTestMap::ValueComp()			{ m_.value_comp(); }
void BenchMarkTestMap::Find()				{ m_.find(RandomKey()); }
void BenchMarkTestMap::Count()				{ m_.count(RandomKey()); }
void BenchMarkTestMap::LowerBound()			{ m_.lower_bound(RandomKey()); }
void BenchMarkTestMap::UpperBound()			{ m_.upper_bound(RandomKey()); }
void BenchMarkTestMap::EqualRange()			{ m_.equal_range(RandomKey()); }
void BenchMarkTestMap::GetAllocator()		{ m_.get_allocator(); }
void BenchMarkTestMap::OpeEqual()			{ (void)(m_ == m1_); }
void BenchMarkTestMap::OpeNotEqual()		{ (void)(m_ != m1_); }
void BenchMarkTestMap::OpeLess()			{ (void)(m_ < m1_); }
void BenchMarkTestMap::OpeLessEqual()		{ (void)(m_ <= m1_); }
void BenchMarkTestMap::OpeGreater()			{ (void)(m_ > m1_); }
void BenchMarkTestMap::OpeGreaterEqual()	{ (void)(m_ >= m1_); }
void BenchMarkTestMap::NonMemberSwap()		{ swap(m_, m1_); }
