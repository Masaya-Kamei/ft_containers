#ifndef OUTPUTTESTVECTOR_HPP
# define OUTPUTTESTVECTOR_HPP

#ifdef NAMESPACE_STD
	#include <vector>
	namespace ft = std;
#else
	#include "vector.hpp"
#endif

# include "Fixed.hpp"

class OutputTestVector
{
	public:
		static void	SetUpStatic();

		OutputTestVector();

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
		void	InputIterator();

	private:
		static const int		nums_[5];

		const ft::vector<Fixed>	cv_;
		ft::vector<Fixed>		v_;
		ft::vector<Fixed>		v0_;
		ft::vector<Fixed>		large_;
		ft::vector<Fixed>		small_;
		ft::vector<Fixed>		more_;
		ft::vector<Fixed>		less_;

		ft::vector<Fixed>::iterator					itr_;
		ft::vector<Fixed>::const_iterator			citr_;
		ft::vector<Fixed>::reverse_iterator			ritr_;
		ft::vector<Fixed>::const_reverse_iterator	critr_;

		void	PutSizeCapElem(const ft::vector<Fixed>& v);
		void	SetUpVectorForRelationalOpe();
};

#endif  // OUTPUTTESTVECTOR_HPP
