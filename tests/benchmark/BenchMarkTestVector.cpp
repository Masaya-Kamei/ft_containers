#include "BenchMarkTest.hpp"

void BenchMarkTest::VectorDefaultConstructor()	{ ft::vector<int> v; }
void BenchMarkTest::VectorFillConstructor() 	{ ft::vector<int> v(RandomSize(), RandomVal()); }
void BenchMarkTest::VectorRangeConstructor()	{ ft::vector<int> v(v_.begin(), RandomItr(v_)); }
void BenchMarkTest::VectorCopyConstructor()		{ ft::vector<int> v(v_); }
void BenchMarkTest::VectorOpeAssign()			{ ft::vector<int> v; v = v_; }
void BenchMarkTest::VectorBegin()				{ v_.begin(); }
void BenchMarkTest::VectorEnd()					{ v_.end(); }
void BenchMarkTest::VectorRBegin()				{ v_.rbegin(); }
void BenchMarkTest::VectorREnd()				{ v_.rend(); }
void BenchMarkTest::VectorSize()				{ v_.size(); }
void BenchMarkTest::VectorMaxSize()				{ v_.max_size(); }
void BenchMarkTest::VectorCapacity()			{ v_.capacity(); }
void BenchMarkTest::VectorEmpty()				{ v_.empty(); }
void BenchMarkTest::VectorResize()				{ v_.resize(RandomSize()); }
void BenchMarkTest::VectorReserve()				{ v_.reserve(RandomSize()); }
void BenchMarkTest::VectorOpeBrackets()			{ v_[rand() % v_.size()]; }
void BenchMarkTest::VectorAt()					{ try { v_[RandomSize()]; } catch(...) {} }
void BenchMarkTest::VectorFront()				{ v_.front(); }
void BenchMarkTest::VectorBack()				{ v_.back(); }
void BenchMarkTest::VectorData()				{ v_.data(); }
void BenchMarkTest::VectorAssignFill()			{ v_.assign(RandomSize(), RandomVal()); }
void BenchMarkTest::VectorAssignRange()			{ v_.assign(v1_.begin(), RandomItr(v1_)); }
void BenchMarkTest::VectorPushBack()			{ v_.push_back(RandomVal()); }
void BenchMarkTest::VectorPopBack()				{ v_.pop_back(); }
void BenchMarkTest::VectorInsertSingle()		{ v_.insert(RandomItr(v_), RandomVal()); }
void BenchMarkTest::VectorInsertFill()			{ v_.insert(RandomItr(v_), RandomSize() / 10, RandomVal()); }
void BenchMarkTest::VectorInsertRange()			{ v_.insert(RandomItr(v_), v1_.begin(), RandomItr(v1_)); }
void BenchMarkTest::VectorEraseSingle()			{ v_.erase(RandomItr(v_)); }
void BenchMarkTest::VectorEraseRange()			{ v_.erase((v_itr_ = RandomItr(v_)), RandomItr(v_, v_itr_)); }
void BenchMarkTest::VectorSwap()				{ v_.swap(v1_); }
void BenchMarkTest::VectorClear()				{ ft::vector<int> v(RandomSize(), RandomVal()); v.clear(); }
void BenchMarkTest::VectorGetAllocator()		{ v_.get_allocator(); }
void BenchMarkTest::VectorOpeEqual()			{ (void)(v_ == v1_); }
void BenchMarkTest::VectorOpeNotEqual()			{ (void)(v_ != v1_); }
void BenchMarkTest::VectorOpeLess()				{ (void)(v_ < v1_); }
void BenchMarkTest::VectorOpeLessEqual()		{ (void)(v_ <= v1_); }
void BenchMarkTest::VectorOpeGreater()			{ (void)(v_ > v1_); }
void BenchMarkTest::VectorOpeGreaterEqual()		{ (void)(v_ >= v1_); }
void BenchMarkTest::VectorNonMemberSwap()		{ swap(v_, v1_); }


void	BenchMarkTest::RunVectorTest()
{
	v_.assign(RandomSize(), RandomVal());
	v1_.assign(RandomSize(), RandomVal());

	Timer	timer;

	MeasureMemFunc("vector", "default constructor", &BenchMarkTest::VectorDefaultConstructor);
	MeasureMemFunc("vector", "fill constructor",	&BenchMarkTest::VectorFillConstructor);
	MeasureMemFunc("vector", "range constructor",	&BenchMarkTest::VectorRangeConstructor);
	MeasureMemFunc("vector", "copy constructor",	&BenchMarkTest::VectorCopyConstructor);
	MeasureMemFunc("vector", "=", 					&BenchMarkTest::VectorOpeAssign);
	MeasureMemFunc("vector", "begin", 				&BenchMarkTest::VectorBegin);
	MeasureMemFunc("vector", "end", 				&BenchMarkTest::VectorEnd);
	MeasureMemFunc("vector", "rbegin",				&BenchMarkTest::VectorRBegin);
	MeasureMemFunc("vector", "rend", 				&BenchMarkTest::VectorREnd);
	MeasureMemFunc("vector", "size",				&BenchMarkTest::VectorSize);
	MeasureMemFunc("vector", "max_size",			&BenchMarkTest::VectorMaxSize);
	MeasureMemFunc("vector", "capacity",			&BenchMarkTest::VectorCapacity);
	MeasureMemFunc("vector", "empty",				&BenchMarkTest::VectorEmpty);
	MeasureMemFunc("vector", "resize",				&BenchMarkTest::VectorResize);
	MeasureMemFunc("vector", "reserve",				&BenchMarkTest::VectorReserve);
	MeasureMemFunc("vector", "[]",					&BenchMarkTest::VectorOpeBrackets);
	MeasureMemFunc("vector", "at",					&BenchMarkTest::VectorAt);
	MeasureMemFunc("vector", "front",				&BenchMarkTest::VectorFront);
	MeasureMemFunc("vector", "back",				&BenchMarkTest::VectorBack);
	MeasureMemFunc("vector", "data",				&BenchMarkTest::VectorData);
	MeasureMemFunc("vector", "assign fill",			&BenchMarkTest::VectorAssignFill);
	MeasureMemFunc("vector", "assign range",		&BenchMarkTest::VectorAssignRange);
	MeasureMemFunc("vector", "push_back",			&BenchMarkTest::VectorPushBack);
	MeasureMemFunc("vector", "pop_back",			&BenchMarkTest::VectorPopBack);
	MeasureMemFunc("vector", "insert single",		&BenchMarkTest::VectorInsertSingle);
	MeasureMemFunc("vector", "insert fill",			&BenchMarkTest::VectorInsertFill);
	MeasureMemFunc("vector", "insert range",		&BenchMarkTest::VectorInsertRange);
	MeasureMemFunc("vector", "erase single",		&BenchMarkTest::VectorEraseSingle);
	MeasureMemFunc("vector", "erase range",			&BenchMarkTest::VectorEraseRange);
	MeasureMemFunc("vector", "swap",				&BenchMarkTest::VectorSwap);
	MeasureMemFunc("vector", "clear",				&BenchMarkTest::VectorClear);
	MeasureMemFunc("vector", "get_allocator",		&BenchMarkTest::VectorGetAllocator);
	MeasureMemFunc("vector", "==",					&BenchMarkTest::VectorOpeEqual);
	MeasureMemFunc("vector", "!=",					&BenchMarkTest::VectorOpeNotEqual);
	MeasureMemFunc("vector", "<",					&BenchMarkTest::VectorOpeLess);
	MeasureMemFunc("vector", "<=",					&BenchMarkTest::VectorOpeLessEqual);
	MeasureMemFunc("vector", ">",					&BenchMarkTest::VectorOpeGreater);
	MeasureMemFunc("vector", ">=",					&BenchMarkTest::VectorOpeGreaterEqual);
	MeasureMemFunc("vector", "non member swap",		&BenchMarkTest::VectorNonMemberSwap);

	PutElapsedTimeMsg(timer, "Vector");
}
