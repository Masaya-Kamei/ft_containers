#ifndef BENCHMARKTEST_HPP
# define BENCHMARKTEST_HPP

#include <string>
#include "Timer.hpp"
#ifdef NAMESPACE_STD
	#include <vector>
	#include <stack>
	#include <map>
	namespace ft = std;
#else
	#include "vector.hpp"
	#include "stack.hpp"
	#include "map.hpp"
#endif

class BenchMarkTest
{
	public:
		explicit BenchMarkTest(const unsigned int seed);

		void	RunAllTest();
		void	RunVectorTest();
		void	RunMapTest();
		void	RunStackTest();

	private:
		const unsigned int	seed_;

		void	MeasureMemFunc(
					const std::string& container_name,
					const std::string& memfunc_name,
					void (BenchMarkTest::*memfunc)());
		void	PutElapsedTimeMsg(
					const Timer& timer,
					const std::string& container_name,
					const std::string& memfunc_name = "");

		ft::vector<int>				v_;
		ft::vector<int>				v1_;
		ft::vector<int>::iterator	v_itr_;
		void	VectorDefaultConstructor();
		void	VectorFillConstructor();
		void	VectorRangeConstructor();
		void	VectorCopyConstructor();
		void	VectorOpeAssign();
		void	VectorBegin();
		void	VectorEnd();
		void	VectorRBegin();
		void	VectorREnd();
		void	VectorSize();
		void	VectorMaxSize();
		void	VectorCapacity();
		void	VectorEmpty();
		void	VectorResize();
		void	VectorReserve();
		void	VectorOpeBrackets();
		void	VectorAt();
		void	VectorFront();
		void	VectorBack();
		void	VectorData();
		void	VectorAssignFill();
		void	VectorAssignRange();
		void	VectorPushBack();
		void	VectorPopBack();
		void	VectorInsertSingle();
		void	VectorInsertFill();
		void	VectorInsertRange();
		void	VectorEraseSingle();
		void	VectorEraseRange();
		void	VectorSwap();
		void	VectorClear();
		void	VectorGetAllocator();
		void	VectorOpeEqual();
		void	VectorOpeNotEqual();
		void	VectorOpeLess();
		void	VectorOpeLessEqual();
		void	VectorOpeGreater();
		void	VectorOpeGreaterEqual();
		void	VectorNonMemberSwap();

		ft::map<int, std::string>			m_;
		ft::map<int, std::string>			m1_;
		ft::map<int, std::string>::iterator	m_itr_;
		void	MapDefaultConstructor();
		void	MapRangeConstructor();
		void	MapCopyConstructor();
		void	MapOpeAssign();
		void	MapEmpty();
		void	MapSize();
		void	MapMaxSize();
		void	MapBegin();
		void	MapEnd();
		void	MapRBegin();
		void	MapREnd();
		void	MapOpeBrackets();
		void	MapInsertSingle();
		void	MapInsertHint();
		void	MapInsertRange();
		void	MapEraseSingleIter();
		void	MapEraseSingleKey();
		void	MapEraseRange();
		void	MapSwap();
		void	MapClear();
		void	MapKeyComp();
		void	MapValueComp();
		void	MapFind();
		void	MapCount();
		void	MapLowerBound();
		void	MapUpperBound();
		void	MapEqualRange();
		void	MapGetAllocator();
		void	MapOpeEqual();
		void	MapOpeNotEqual();
		void	MapOpeLess();
		void	MapOpeLessEqual();
		void	MapOpeGreater();
		void	MapOpeGreaterEqual();
		void	MapNonMemberSwap();

		ft::stack<int, ft::vector<int> >	s_;
		ft::stack<int, ft::vector<int> >	s1_;
		void	StackDefaultConstructor();
		void	StackCopyConstructor();
		void	StackOpeAssign();
		void	StackEmpty();
		void	StackSize();
		void	StackTop();
		void	StackPush();
		void	StackPop();
		void	StackOpeEqual();
		void	StackOpeNotEqual();
		void	StackOpeLess();
		void	StackOpeLessEqual();
		void	StackOpeGreater();
		void	StackOpeGreaterEqual();

		int		RandomSize();
		int		RandomVal();
		int		RandomKey();

		template <class Container>
		typename Container::iterator	RandomItr(Container& v);
		template <class Container>
		typename Container::iterator	RandomItr(Container& v, typename Container::iterator start);
};

template <class Container>
typename Container::iterator	BenchMarkTest::RandomItr(Container& v)
{
	typename Container::iterator	start = v.begin();
	std::advance(start, rand() % v.size());
	return (start);
}
template <class Container>
typename Container::iterator	BenchMarkTest::RandomItr(Container& v, typename Container::iterator start)
{
	std::advance(start, rand() % std::distance(start, v.end()));
	return (start);
}

#endif  // BENCHMARKTEST_HPP
