#ifndef OUTPUTTESTSTACK_HPP
# define OUTPUTTESTSTACK_HPP

#ifdef NAMESPACE_STD
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "stack.hpp"
	#include "vector.hpp"
#endif

# include "Fixed.hpp"

class OutputTestStack
{
	public:
		static void	SetUpStatic();

		OutputTestStack();

		void	DefaultConstructor();
		void	CopyConstructor();
		void	OpeAssign();
		void	Empty();
		void	Size();
		void	Top();
		void	Push();
		void	Pop();
		void	OpeEqual();
		void	OpeNotEqual();
		void	OpeLess();
		void	OpeLessEqual();
		void	OpeGreater();
		void	OpeGreaterEqual();

	private:
		static const int	nums_[5];
		static const ft::vector<Fixed>				cv_;
		const ft::stack<Fixed, ft::vector<Fixed> >	cs_;
		ft::stack<Fixed, ft::vector<Fixed> >		s_;
		ft::stack<Fixed, ft::vector<Fixed> >		s0_;
		ft::stack<Fixed, ft::vector<Fixed> >		large_;
		ft::stack<Fixed, ft::vector<Fixed> >		small_;
		ft::stack<Fixed, ft::vector<Fixed> >		more_;
		ft::stack<Fixed, ft::vector<Fixed> >		less_;

		void	PutSizeTop(const ft::stack<Fixed, ft::vector<Fixed> >& s);
		void	SetUpStackForRelationalOpe();
};

#endif  // OUTPUTTESTSTACK_HPP
