#ifndef BENCHMARKTESTVECTOR_HPP
# define BENCHMARKTESTVECTOR_HPP

#ifdef NAMESPACE_STD
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
#endif

class BenchMarkTestVector
{
	public:
		static void	SetUpStatic();

		explicit BenchMarkTestVector(bool setup_flag);

		void	DefaultConstructor();
		void	FillConstructor();
		void	RangeConstructor();
		void	CopyConstructor();
		void	OpeAssign();
		void	Begin();
		void	End();
		void	RBegin();
		void	REnd();
		void	Size();
		void	MaxSize();
		void	Capacity();
		void	Empty();
		void	Resize();
		void	Reserve();
		void	OpeBrackets();
		void	At();
		void	Front();
		void	Back();
		void	Data();
		void	AssignFill();
		void	AssignRange();
		void	PushBack();
		void	PopBack();
		void	InsertSingle();
		void	InsertFill();
		void	InsertRange();
		void	EraseSingle();
		void	EraseRange();
		void	Swap();
		void	Clear();
		void	GetAllocator();
		void	OpeEqual();
		void	OpeNotEqual();
		void	OpeLess();
		void	OpeLessEqual();
		void	OpeGreater();
		void	OpeGreaterEqual();
		void	NonMemberSwap();

	private:
		static ft::vector<int>	cv_;
		static ft::vector<int>	cv1_;

		ft::vector<int>		v_;
};

#endif  // BENCHMARKTESTVECTOR_HPP
