#ifndef OUTPUTTESTMAP_HPP
# define OUTPUTTESTMAP_HPP

#ifdef NAMESPACE_STD
	#include <map>
	namespace ft = std;
#else
	#include "map.hpp"
#endif

# include <string>
# include "Fixed.hpp"

class OutputTestMap
{
	public:
		static void	SetUpStatic();

		OutputTestMap();

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
		static const ft::pair<Fixed, std::string>	pairs_[12];

		const ft::map<Fixed, std::string>	cm_;
		ft::map<Fixed, std::string>			m_;
		ft::map<Fixed, std::string>			m0_;
		ft::map<Fixed, std::string>			large_;
		ft::map<Fixed, std::string>			small_;
		ft::map<Fixed, std::string>			more_;
		ft::map<Fixed, std::string>			less_;

		ft::map<Fixed, std::string>::iterator				itr_;
		ft::map<Fixed, std::string>::const_iterator			citr_;
		ft::map<Fixed, std::string>::reverse_iterator		ritr_;
		ft::map<Fixed, std::string>::const_reverse_iterator	critr_;

		void	PutSizeElem(const ft::map<Fixed, std::string>& m);
		void	SetUpMapForRelationalOpe();
};

#endif  // OUTPUTTESTMAP_HPP
