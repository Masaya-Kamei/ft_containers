#ifndef BENCHMARKTESTMAP_HPP
# define BENCHMARKTESTMAP_HPP

#include <string>

#ifdef NAMESPACE_STD
	#include <map>
	namespace ft = std;
#else
	#include "map.hpp"
#endif

class BenchMarkTestMap
{
	public:
		static void	SetUp();

		BenchMarkTestMap();

		void	DefaultConstructor();
		void	RangeConstructor();
		void	CopyConstructor();
		void	OpeAssign();
		void	Empty();
		void	Size();
		void	MaxSize();
		void	Begin();
		void	End();
		void	RBegin();
		void	REnd();
		void	OpeBrackets();
		void	InsertSingle();
		void	InsertHint();
		void	InsertRange();
		void	EraseSingleIter();
		void	EraseSingleKey();
		void	EraseRange();
		void	Swap();
		void	Clear();
		void	KeyComp();
		void	ValueComp();
		void	Find();
		void	Count();
		void	LowerBound();
		void	UpperBound();
		void	EqualRange();
		void	GetAllocator();
		void	OpeEqual();
		void	OpeNotEqual();
		void	OpeLess();
		void	OpeLessEqual();
		void	OpeGreater();
		void	OpeGreaterEqual();
		void	NonMemberSwap();

	private:
		static ft::map<int, std::string>	base_m_;
		static ft::map<int, std::string>	base_m1_;

		ft::map<int, std::string>			m_;
		ft::map<int, std::string>			m1_;
};

#endif  // BENCHMARKTESTMAP_HPP
