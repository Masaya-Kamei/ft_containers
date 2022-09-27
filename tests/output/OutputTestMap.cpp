#include <iostream>
#include "OutputTestMap.hpp"
#include "Put.hpp"

const ft::pair<Fixed, std::string>	OutputTestMap::pairs_[12]
	= {ft::make_pair(90, "I"), ft::make_pair(20, "B"), ft::make_pair(110, "K")
	 , ft::make_pair(80, "H"), ft::make_pair(50, "E"), ft::make_pair(60, "F")
	 , ft::make_pair(120, "L"), ft::make_pair(40, "D"), ft::make_pair(10, "A")
	 , ft::make_pair(100, "J"), ft::make_pair(30, "C"), ft::make_pair(70, "G")};

void	OutputTestMap::SetUpStatic()
{
}

void	OutputTestMap::SetUpMapForRelationalOpe()
{
	large_.insert(m_.begin(), m_.end());
	large_.erase(20);	large_.insert(ft::make_pair(22, "X"));
	small_.insert(m_.begin(), m_.end());
	small_.erase(20);	small_.insert(ft::make_pair(18, "X"));
	more_.insert(m_.begin(),  m_.end());
	more_.insert(ft::make_pair(130, "X"));
	less_.insert(m_.begin(),  m_.end());
	less_.erase(120);
}

OutputTestMap::OutputTestMap()
	: cm_(pairs_, pairs_ + 12), m_(pairs_, pairs_ + 12)
{
}

void	OutputTestMap::PutSizeElem(const ft::map<Fixed, std::string>& m)
{
	std::cout << "size : " << m.size() << std::endl;

	ft::map<Fixed, std::string>::const_iterator	itr = m.begin();
	ft::map<Fixed, std::string>::const_iterator	end = m.end();
	std::cout << "elem : " << "[";
	for (; itr != end; itr++)
		std::cout << "(" << itr->first << ", " << itr->second << ")" << ", ";
	std::cout << "]" << std::endl;
}

void	OutputTestMap::DefaultConstructor()
{
	ft::map<Fixed, std::string>	m;
	PutSizeElem(m);
};

void	OutputTestMap::RangeConstructor()
{
	ft::map<Fixed, std::string>	m(pairs_, pairs_ + 12);
	PutSizeElem(m);
	ft::map<Fixed, std::string>	m0(pairs_, pairs_);
	PutSizeElem(m0);
}

void	OutputTestMap::CopyConstructor()
{
	ft::map<Fixed, std::string>	m(m_);
	PutSizeElem(m);
	Put(m_.begin() != m.begin());
}

void	OutputTestMap::OpeAssign()
{
	ft::map<Fixed, std::string>	m;
	m = m_;
	PutSizeElem(m);
	Put(m_.begin() != m.begin());
}

void	OutputTestMap::Empty()
{
	Put(m_.empty());
	Put(cm_.empty());
	Put(m0_.empty());

	m_.clear();
	Put(m_.empty());
}

void	OutputTestMap::Size()
{
	Put(m_.size());
	Put(cm_.size());
	Put(m0_.size());
}

void	OutputTestMap::MaxSize()
{
	#ifdef NAMESPACE_STD
	typedef std::__tree_node<std::pair<Fixed, std::string>, void *>	node_type;
	#else
	typedef ft::avl_tree_node<ft::pair<Fixed, std::string> >	node_type;
	#endif

	std::allocator<node_type>	node_alloc;
	size_t	result = std::min<size_t>(node_alloc.max_size(), std::numeric_limits<ptrdiff_t>::max());

	Put(result == m_.max_size());
}

void	OutputTestMap::Begin()
{
	itr_ = m_.begin();
	Put(itr_->first);
	citr_ = m_.begin();
	Put(citr_->first);
	citr_ = cm_.begin();
	Put(citr_->first);
}

void	OutputTestMap::End()
{
	itr_ = --m_.end();
	Put(itr_->first);
	citr_ = --m_.end();
	Put(citr_->first);
	citr_ = --cm_.end();
	Put(citr_->first);
}

void	OutputTestMap::RBegin()
{
	ritr_ = m_.rbegin();
	Put(ritr_->first);
	critr_ = m_.rbegin();
	Put(critr_->first);
	critr_ = cm_.rbegin();
	Put(critr_->first);
}

void	OutputTestMap::REnd()
{
	ritr_ = --m_.rend();
	Put(ritr_->first);
	critr_ = --m_.rend();
	Put(critr_->first);
	critr_ = --cm_.rend();
	Put(critr_->first);
}

void	OutputTestMap::OpeBrackets()
{
	Put(m_[10]);
	Put(m_[-1]);
	PutSizeElem(m_);
	// Put(cm_[10]);
	// Put(cm_[-1]);
}

void	OutputTestMap::InsertSingle()
{
	ft::map<Fixed, std::string>	m;
	ft::pair<ft::map<Fixed, std::string>::iterator, bool>	ret;

	ret = m.insert(ft::make_pair(1, "A"));
	Put((ret.first)->first);
	Put(ret.second);
	ret = m.insert(ft::make_pair(3, "C"));
	Put((ret.first)->first);
	Put(ret.second);
	ret = m.insert(ft::make_pair(4, "D"));
	Put((ret.first)->first);
	Put(ret.second);
	ret = m.insert(ft::make_pair(2, "B"));
	Put((ret.first)->first);
	Put(ret.second);
	ret = m.insert(ft::make_pair(1, "Z"));
	Put((ret.first)->first);
	Put(ret.second);

	PutSizeElem(m);
}

void	OutputTestMap::InsertHint()
{
	ft::map<Fixed, std::string>::iterator	ret;

	ret = m_.insert(m_.find(20), ft::make_pair(22, "X"));
	Put(ret->first);
	ret = m_.insert(m_.find(20), ft::make_pair(18, "X"));
	Put(ret->first);

	ret = m_.insert(++(++(++m_.begin())), ft::make_pair(42, "X"));
	Put(ret->first);
	ret = m_.insert(++(++(++m_.begin())), ft::make_pair(-1, "X"));
	Put(ret->first);
	ret = m_.insert(++(++(++m_.begin())), ft::make_pair(142, "X"));
	Put(ret->first);
	ret = m_.insert(++(++(++m_.begin())), ft::make_pair(50, "X"));
	Put(ret->first);

	ret = m_.insert(m_.begin(), ft::make_pair(43, "X"));
	Put(ret->first);
	ret = m_.insert(m_.begin(), ft::make_pair(-2, "X"));
	Put(ret->first);
	ret = m_.insert(m_.begin(), ft::make_pair(143, "X"));
	Put(ret->first);
	ret = m_.insert(m_.begin(), ft::make_pair(50, "X"));
	Put(ret->first);

	ret = m_.insert(m_.end(), ft::make_pair(44, "X"));
	Put(ret->first);
	ret = m_.insert(m_.end(), ft::make_pair(-3, "X"));
	Put(ret->first);
	ret = m_.insert(m_.end(), ft::make_pair(144, "X"));
	Put(ret->first);
	ret = m_.insert(m_.end(), ft::make_pair(50, "X"));
	Put(ret->first);

	PutSizeElem(m_);
}

void	OutputTestMap::InsertRange()
{
	ft::map<Fixed, std::string>	m;

	m.insert(pairs_, 	  pairs_ + 3);
	PutSizeElem(m_);
	m.insert(pairs_ + 3,  pairs_ + 9);
	PutSizeElem(m_);
	m.insert(pairs_ + 9,  pairs_ + 10);
	PutSizeElem(m_);
	m.insert(pairs_ + 10, pairs_ + 10);
	PutSizeElem(m_);
	m.insert(pairs_ + 12, pairs_ + 12);
	PutSizeElem(m_);
}

void	OutputTestMap::EraseSingleIter()
{
	for (int i = 0; i < 12; ++i)
	{
		ft::map<Fixed, std::string>::iterator	erase_itr = m_.begin();
		int		distance = rand() % m_.size();
		std::advance(erase_itr, distance);
		m_.erase(erase_itr);
		PutSizeElem(m_);
	}
}

void	OutputTestMap::EraseSingleKey()
{
	while (m_.size() != 0)
	{
		int r = ((rand() % 12) + 1) * 10;
		m_.erase(r);
		PutSizeElem(m_);
	};
}

void	OutputTestMap::EraseRange()
{
	m_.erase(m_.begin(), ++(++(++m_.begin())));
	PutSizeElem(m_);
	m_.erase(++(++(++m_.begin())), --m_.end());
	PutSizeElem(m_);
	m_.erase(m_.end(), m_.end());
	PutSizeElem(m_);
	m_.erase(m_.begin(), m_.end());
	PutSizeElem(m_);
}

void	OutputTestMap::Swap()
{
	ft::map<Fixed, std::string>::iterator	begin = m_.begin();
	ft::map<Fixed, std::string>				m1(pairs_, pairs_ + 5);
	m_.swap(m1);
	PutSizeElem(m_);
	PutSizeElem(m1);
	Put(begin == m1.begin());

	m_.swap(m0_);
	PutSizeElem(m_);
	PutSizeElem(m0_);
}

void	OutputTestMap::Clear()
{
	m_.clear();
	PutSizeElem(m_);
	m_.insert(pairs_, pairs_ + 12);
	PutSizeElem(m_);
	m0_.clear();
	PutSizeElem(m0_);
}

void	OutputTestMap::KeyComp()
{
	ft::map<Fixed, std::string>::key_compare	key_comp = m_.key_comp();
	Put(key_comp(1, 1));
	Put(key_comp(1, 2));
	Put(key_comp(2, 1));
}

void	OutputTestMap::ValueComp()
{
	ft::map<Fixed, std::string>::value_compare	value_comp = m_.value_comp();
	Put(value_comp(pairs_[0], pairs_[0]));
	Put(value_comp(pairs_[0], pairs_[1]));
	Put(value_comp(pairs_[1], pairs_[0]));
}

void	OutputTestMap::Find()
{
	Put((m_.find(50))->first);
	Put((m_.find(60))->first);
	Put((m_.find(10))->first);
	Put((m_.find(120))->first);
	Put(m_.find(42) == m_.end());

	Put((cm_.find(50))->first);
	Put((cm_.find(60))->first);
	Put((cm_.find(10))->first);
	Put((cm_.find(120))->first);
	Put(cm_.find(42) == cm_.end());
}

void	OutputTestMap::Count()
{
	Put(m_.count(50));
	Put(m_.count(60));
	Put(m_.count(10));
	Put(m_.count(120));
	Put(m_.count(42));

	Put(cm_.count(50));
	Put(cm_.count(60));
	Put(cm_.count(10));
	Put(cm_.count(120));
	Put(cm_.count(42));
}

void	OutputTestMap::LowerBound()
{
	Put((m_.lower_bound(42))->first);
	Put((m_.lower_bound(60))->first);
	Put((m_.lower_bound(1))->first);
	Put(m_.lower_bound(420) == m_.end());

	Put(cm_.lower_bound(42)->first);
	Put(cm_.lower_bound(60)->first);
	Put(cm_.lower_bound(1)->first);
	Put(cm_.lower_bound(420) == cm_.end());
}

void	OutputTestMap::UpperBound()
{
	Put((m_.upper_bound(42))->first);
	Put((m_.upper_bound(60))->first);
	Put((m_.upper_bound(1))->first);
	Put(m_.upper_bound(420) == m_.end());

	Put(cm_.upper_bound(42)->first);
	Put(cm_.upper_bound(60)->first);
	Put(cm_.upper_bound(1)->first);
	Put(cm_.upper_bound(420) == cm_.end());
}

void	OutputTestMap::EqualRange()
{
	typedef ft::map<Fixed, std::string>::iterator	itr;
	ft::pair<itr, itr>								ret;
	ret = m_.equal_range(30);
	Put(ret.first->first);
	Put(ret.second->first);
	Put((++(ret.first))->first == ret.second->first);
	ret = m_.equal_range(42);
	Put(ret.first->first);
	Put(ret.second->first);
	Put(ret.first->first == ret.second->first);
	ret = m_.equal_range(120);
	Put(ret.first->first);
	Put(ret.second == m_.end());
	ret = m_.equal_range(1);
	Put(ret.first->first);
	Put(ret.second->first);
	Put(ret.first->first == ret.second->first);
	ret = m_.equal_range(122);
	Put(ret.first == m_.end());
	Put(ret.second == m_.end());

	typedef ft::map<Fixed, std::string>::const_iterator	citr;
	ft::pair<citr, citr>	cret;
	cret = cm_.equal_range(30);
	Put(cret.first->first);
	Put(cret.second->first);
	Put((++(cret.first))->first == cret.second->first);
}

void	OutputTestMap::GetAllocator()
{
}

void	OutputTestMap::OpeEqual()
{
	SetUpMapForRelationalOpe();
	Put(m_ == m_);
	Put(m_ == large_);
	Put(m_ == small_);
	Put(m_ == more_);
	Put(m_ == less_);
}

void	OutputTestMap::OpeNotEqual()
{
	SetUpMapForRelationalOpe();
	Put(m_ != m_);
	Put(m_ != large_);
	Put(m_ != small_);
	Put(m_ != more_);
	Put(m_ != less_);
}

void	OutputTestMap::OpeLess()
{
	SetUpMapForRelationalOpe();
	Put(m_ < m_);
	Put(m_ < large_);
	Put(m_ < small_);
	Put(m_ < more_);
	Put(m_ < less_);
}

void	OutputTestMap::OpeLessEqual()
{
	SetUpMapForRelationalOpe();
	Put(m_ <= m_);
	Put(m_ <= large_);
	Put(m_ <= small_);
	Put(m_ <= more_);
	Put(m_ <= less_);
}

void	OutputTestMap::OpeGreater()
{
	SetUpMapForRelationalOpe();
	Put(m_ > m_);
	Put(m_ > large_);
	Put(m_ > small_);
	Put(m_ > more_);
	Put(m_ > less_);
}

void	OutputTestMap::OpeGreaterEqual()
{
	SetUpMapForRelationalOpe();
	Put(m_ >= m_);
	Put(m_ >= large_);
	Put(m_ >= small_);
	Put(m_ >= more_);
	Put(m_ >= less_);
}

void	OutputTestMap::NonMemberSwap()
{
	ft::map<Fixed, std::string>::iterator	begin = m_.begin();
	ft::map<Fixed, std::string>				m1(pairs_, pairs_ + 5);
	swap(m_, m1);
	PutSizeElem(m_);
	PutSizeElem(m1);
	Put(begin == m1.begin());

	swap(m_, m0_);
	PutSizeElem(m_);
	PutSizeElem(m0_);
}
