#include "BenchMarkTest.hpp"

void BenchMarkTest::MapDefaultConstructor()	{ ft::map<int, std::string> m; }
void BenchMarkTest::MapRangeConstructor()	{ ft::map<int, std::string> m(m_.begin(), RandomItr(m_)); }
void BenchMarkTest::MapCopyConstructor()	{ ft::map<int, std::string> m(m_); }
void BenchMarkTest::MapOpeAssign()			{ ft::map<int, std::string> m; m = m_; }
void BenchMarkTest::MapEmpty()				{ m_.empty(); }
void BenchMarkTest::MapSize()				{ m_.size(); }
void BenchMarkTest::MapMaxSize()			{ m_.max_size(); }
void BenchMarkTest::MapBegin()				{ m_.begin(); }
void BenchMarkTest::MapEnd()				{ m_.end(); }
void BenchMarkTest::MapRBegin()				{ m_.rbegin(); }
void BenchMarkTest::MapREnd()				{ m_.rend(); }
void BenchMarkTest::MapOpeBrackets()		{ m_[rand() % m_.size()]; }
void BenchMarkTest::MapInsertSingle()		{ m_.insert(ft::make_pair(RandomKey(), "X")); }
void BenchMarkTest::MapInsertHint()			{ m_.insert(RandomItr(m_), ft::make_pair(RandomKey(), "X")); }
void BenchMarkTest::MapInsertRange()		{ m_.insert(m1_.begin(), RandomItr(m1_)); }
void BenchMarkTest::MapEraseSingleIter()	{ m_.erase(RandomItr(m_)); }
void BenchMarkTest::MapEraseSingleKey()		{ m_.erase(RandomKey()); }
void BenchMarkTest::MapEraseRange()			{ m_.erase((m_itr_ = RandomItr(m_)), RandomItr(m_, m_itr_)); }
void BenchMarkTest::MapSwap()				{ m_.swap(m1_); }
void BenchMarkTest::MapClear()				{ ft::map<int, std::string> m(m_.begin(), m_.end()); m.clear(); }
void BenchMarkTest::MapKeyComp()			{ m_.key_comp(); }
void BenchMarkTest::MapValueComp()			{ m_.value_comp(); }
void BenchMarkTest::MapFind()				{ m_.find(RandomKey()); }
void BenchMarkTest::MapCount()				{ m_.count(RandomKey()); }
void BenchMarkTest::MapLowerBound()			{ m_.lower_bound(RandomKey()); }
void BenchMarkTest::MapUpperBound()			{ m_.upper_bound(RandomKey()); }
void BenchMarkTest::MapEqualRange()			{ m_.equal_range(RandomKey()); }
void BenchMarkTest::MapGetAllocator()		{ m_.get_allocator(); }
void BenchMarkTest::MapOpeEqual()			{ (void)(m_ == m1_); }
void BenchMarkTest::MapOpeNotEqual()		{ (void)(m_ != m1_); }
void BenchMarkTest::MapOpeLess()			{ (void)(m_ < m1_); }
void BenchMarkTest::MapOpeLessEqual()		{ (void)(m_ <= m1_); }
void BenchMarkTest::MapOpeGreater()			{ (void)(m_ > m1_); }
void BenchMarkTest::MapOpeGreaterEqual()	{ (void)(m_ >= m1_); }
void BenchMarkTest::MapNonMemberSwap()		{ swap(m_, m1_); }


void	BenchMarkTest::RunMapTest()
{
	int		size;
	size = RandomSize();
	for (int i = 0; i < size; ++i)
		m_.insert(ft::make_pair(RandomKey(), "X"));
	size = RandomSize();
	for (int i = 0; i < size; ++i)
		m1_.insert(ft::make_pair(RandomKey(), "X"));

	Timer	timer;

	MeasureMemFunc("map", "default constructor", &BenchMarkTest::MapDefaultConstructor);
	MeasureMemFunc("map", "range constructor",	&BenchMarkTest::MapRangeConstructor);
	MeasureMemFunc("map", "copy constructor",	&BenchMarkTest::MapCopyConstructor);
	MeasureMemFunc("map", "=", 					&BenchMarkTest::MapOpeAssign);
	MeasureMemFunc("map", "empty",				&BenchMarkTest::MapEmpty);
	MeasureMemFunc("map", "size",				&BenchMarkTest::MapSize);
	MeasureMemFunc("map", "max_size",			&BenchMarkTest::MapMaxSize);
	MeasureMemFunc("map", "begin", 				&BenchMarkTest::MapBegin);
	MeasureMemFunc("map", "end", 				&BenchMarkTest::MapEnd);
	MeasureMemFunc("map", "rbegin",				&BenchMarkTest::MapRBegin);
	MeasureMemFunc("map", "rend", 				&BenchMarkTest::MapREnd);
	MeasureMemFunc("map", "[]",					&BenchMarkTest::MapOpeBrackets);
	MeasureMemFunc("map", "insert single",		&BenchMarkTest::MapInsertSingle);
	MeasureMemFunc("map", "insert hint",		&BenchMarkTest::MapInsertHint);
	MeasureMemFunc("map", "insert range",		&BenchMarkTest::MapInsertRange);
	MeasureMemFunc("map", "erase single iter",	&BenchMarkTest::MapEraseSingleIter);
	MeasureMemFunc("map", "erase single key",	&BenchMarkTest::MapEraseSingleKey);
	MeasureMemFunc("map", "erase range",		&BenchMarkTest::MapEraseRange);
	MeasureMemFunc("map", "swap",				&BenchMarkTest::MapSwap);
	MeasureMemFunc("map", "clear",				&BenchMarkTest::MapClear);
	MeasureMemFunc("map", "key_comp",			&BenchMarkTest::MapKeyComp);
	MeasureMemFunc("map", "value_comp",			&BenchMarkTest::MapValueComp);
	MeasureMemFunc("map", "find",				&BenchMarkTest::MapFind);
	MeasureMemFunc("map", "count",				&BenchMarkTest::MapCount);
	MeasureMemFunc("map", "lower_bound",		&BenchMarkTest::MapLowerBound);
	MeasureMemFunc("map", "upper_bound",		&BenchMarkTest::MapUpperBound);
	MeasureMemFunc("map", "equal_range",		&BenchMarkTest::MapEqualRange);
	MeasureMemFunc("map", "get_allocator",		&BenchMarkTest::MapGetAllocator);
	MeasureMemFunc("map", "==",					&BenchMarkTest::MapOpeEqual);
	MeasureMemFunc("map", "!=",					&BenchMarkTest::MapOpeNotEqual);
	MeasureMemFunc("map", "<",					&BenchMarkTest::MapOpeLess);
	MeasureMemFunc("map", "<=",					&BenchMarkTest::MapOpeLessEqual);
	MeasureMemFunc("map", ">",					&BenchMarkTest::MapOpeGreater);
	MeasureMemFunc("map", ">=",					&BenchMarkTest::MapOpeGreaterEqual);
	MeasureMemFunc("map", "non member swap",	&BenchMarkTest::MapNonMemberSwap);

	PutElapsedTimeMsg(timer, "Map");
}
