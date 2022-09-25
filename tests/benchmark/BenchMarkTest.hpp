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
		// RunStackTest();
		// RunMapTest();

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
		ft::vector<int>				cv_;
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

		template <class Container>
		typename Container::iterator	RandomItr(Container& v);
		template <class Container>
		typename Container::iterator	RandomItr(Container& v, typename Container::iterator start);
};

template <class Container>
typename Container::iterator	BenchMarkTest::RandomItr(Container& v)
{
	return (v.begin() + rand() % v.size());
}
template <class Container>
typename Container::iterator	BenchMarkTest::RandomItr(Container& v, typename Container::iterator start)
{
	return (start + rand() % (v.end() - start));
}

#endif  // BENCHMARKTEST_HPP
