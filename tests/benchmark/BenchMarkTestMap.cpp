#include "BenchMarkTestMap.hpp"
#include "Random.hpp"

ft::map<int, std::string>	BenchMarkTestMap::cm_;
ft::map<int, std::string>	BenchMarkTestMap::cm1_;

static int		RandomKey()	{ return (rand() % 10000); }

void	BenchMarkTestMap::SetUpStatic()
{
	for (int i = 0; i < 1000; ++i)
		cm_.insert(ft::make_pair(RandomKey(), "X"));
	for (int i = 0; i < 1000; ++i)
		cm1_.insert(ft::make_pair(RandomKey(), "X"));
}

BenchMarkTestMap::BenchMarkTestMap(bool setup_flag)
{
	if (setup_flag)
		m_ = cm_;
}

void BenchMarkTestMap::DefaultConstructor()	{ ft::map<int, std::string> m; }
void BenchMarkTestMap::RangeConstructor()	{ ft::map<int, std::string> m(cm_.begin(), cm_.end()); }
void BenchMarkTestMap::CopyConstructor()	{ ft::map<int, std::string> m(cm_); }
void BenchMarkTestMap::OpeAssign()			{ ft::map<int, std::string> m; m = cm_; }
void BenchMarkTestMap::Empty()				{ cm_.empty(); }
void BenchMarkTestMap::Size()				{ cm_.size(); }
void BenchMarkTestMap::MaxSize()			{ cm_.max_size(); }
void BenchMarkTestMap::Begin()				{ cm_.begin(); }
void BenchMarkTestMap::End()				{ cm_.end(); }
void BenchMarkTestMap::RBegin()				{ cm_.rbegin(); }
void BenchMarkTestMap::REnd()				{ cm_.rend(); }
void BenchMarkTestMap::OpeBrackets()		{ cm_[rand() % cm_.size()]; }
void BenchMarkTestMap::InsertSingle()		{ m_.insert(ft::make_pair(RandomKey(), "X")); }
void BenchMarkTestMap::InsertHint()			{ m_.insert(RandomItr(m_), ft::make_pair(RandomKey(), "X")); }
void BenchMarkTestMap::InsertRange()		{ m_.insert(cm1_.begin(), RandomItr(cm1_)); }
void BenchMarkTestMap::EraseSingleIter()	{ m_.erase(RandomItr(m_)); }
void BenchMarkTestMap::EraseSingleKey()		{ m_.erase(RandomKey()); }
void BenchMarkTestMap::EraseRange()			{ m_.erase(m_.begin(), m_.end()); }
void BenchMarkTestMap::Swap()				{ cm_.swap(cm1_); }
void BenchMarkTestMap::Clear()				{ m_.clear(); }
void BenchMarkTestMap::KeyComp()			{ cm_.key_comp(); }
void BenchMarkTestMap::ValueComp()			{ cm_.value_comp(); }
void BenchMarkTestMap::Find()				{ cm_.find(RandomKey()); }
void BenchMarkTestMap::Count()				{ cm_.count(RandomKey()); }
void BenchMarkTestMap::LowerBound()			{ cm_.lower_bound(RandomKey()); }
void BenchMarkTestMap::UpperBound()			{ cm_.upper_bound(RandomKey()); }
void BenchMarkTestMap::EqualRange()			{ cm_.equal_range(RandomKey()); }
void BenchMarkTestMap::GetAllocator()		{ cm_.get_allocator(); }
void BenchMarkTestMap::OpeEqual()			{ (void)(cm_ == cm1_); }
void BenchMarkTestMap::OpeNotEqual()		{ (void)(cm_ != cm1_); }
void BenchMarkTestMap::OpeLess()			{ (void)(cm_ < cm1_); }
void BenchMarkTestMap::OpeLessEqual()		{ (void)(cm_ <= cm1_); }
void BenchMarkTestMap::OpeGreater()			{ (void)(cm_ > cm1_); }
void BenchMarkTestMap::OpeGreaterEqual()	{ (void)(cm_ >= cm1_); }
void BenchMarkTestMap::NonMemberSwap()		{ swap(cm_, cm1_); }
