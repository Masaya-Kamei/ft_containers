#ifndef BENCHMARKTESTSTACK_HPP
# define BENCHMARKTESTSTACK_HPP

#ifdef NAMESPACE_STD
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "stack.hpp"
	#include "vector.hpp"
#endif

class BenchMarkTestStack
{
	public:
		static void	SetUpStatic();

		explicit BenchMarkTestStack(bool setup_flag);

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
		static ft::stack<int, ft::vector<int> >	cs_;
		static ft::stack<int, ft::vector<int> >	cs1_;

		ft::stack<int, ft::vector<int> >	s_;
};

#endif  // BENCHMARKTESTSTACK_HPP
