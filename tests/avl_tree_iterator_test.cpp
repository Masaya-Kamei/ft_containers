#ifndef TESTLIB
# include <gtest/gtest.h>
#else
# include "testlib.hpp"
#endif
#include "map.hpp"

class AvlTreeIteratorTest : public ::testing::Test
{
	protected:
		static void SetUpTestCase()
		{
		}
		static void TearDownTestCase()
		{
		}
		virtual void SetUp()
		{
			seed_ = time(NULL);
			srand(seed_);
			st_map_.insert(st_pairs_, st_pairs_ + 12);
			ft_map_.insert(ft_pairs_, ft_pairs_ + 12);
		}
		virtual void TearDown()
		{
		}

		static const std::pair<int, std::string>	st_pairs_[12];
		static const ft::pair<int, std::string>		ft_pairs_[12];
		static const std::map<int, std::string>		st_const_map_;
		static const ft::map<int, std::string>		ft_const_map_;
		std::map<int, std::string>	st_map_;
		ft::map<int, std::string>	ft_map_;
		unsigned int				seed_;
};

const std::pair<int, std::string>	AvlTreeIteratorTest::st_pairs_[12]
	= {std::make_pair(90, "I"), std::make_pair(20, "B"), std::make_pair(110, "K")
		, std::make_pair(80, "H"), std::make_pair(50, "E"), std::make_pair(60, "F")
		, std::make_pair(120, "L"), std::make_pair(40, "D"), std::make_pair(10, "A")
		, std::make_pair(100, "J"), std::make_pair(30, "C"), std::make_pair(70, "G")};
const ft::pair<int, std::string>	AvlTreeIteratorTest::ft_pairs_[12]
	= {ft::make_pair(90, "I"), ft::make_pair(20, "B"), ft::make_pair(110, "K")
		, ft::make_pair(80, "H"), ft::make_pair(50, "E"), ft::make_pair(60, "F")
		, ft::make_pair(120, "L"), ft::make_pair(40, "D"), ft::make_pair(10, "A")
		, ft::make_pair(100, "J"), ft::make_pair(30, "C"), ft::make_pair(70, "G")};
const std::map<int, std::string>	AvlTreeIteratorTest::st_const_map_(st_pairs_, &st_pairs_[12]);
const ft::map<int, std::string>		AvlTreeIteratorTest::ft_const_map_(ft_pairs_, &ft_pairs_[12]);


TEST_F(AvlTreeIteratorTest, ConstructorTest)
{
	std::map<int, std::string>::iterator	st_itr(st_map_.begin());
	ft::map<int, std::string>::iterator		ft_itr(ft_map_.begin());
	std::map<int, std::string>::iterator	st_begin;
	st_begin = st_map_.begin();
	ft::map<int, std::string>::iterator		ft_begin;
	ft_begin = ft_map_.begin();

	EXPECT_EQ(st_itr->first,   ft_itr->first);
	EXPECT_EQ(st_begin->first, ft_begin->first);
	EXPECT_EQ(st_itr->first,   st_begin->first);
	EXPECT_EQ(ft_itr->first,   ft_begin->first);
}

TEST_F(AvlTreeIteratorTest, OpeIncDecTest)
{
	std::map<int, std::string>::iterator	st_itr	= st_map_.begin();
	ft::map<int, std::string>::iterator		ft_itr = ft_map_.begin();
	std::map<int, std::string>::iterator	st_begin = st_map_.begin();
	ft::map<int, std::string>::iterator		ft_begin = ft_map_.begin();

	EXPECT_EQ((st_itr++)->first, (ft_itr++)->first);
	EXPECT_EQ((++st_itr)->first, (++ft_itr)->first);
	EXPECT_EQ((st_itr--)->first, (ft_itr--)->first);
	EXPECT_EQ((--st_itr)->first, (--ft_itr)->first);

	EXPECT_EQ(st_itr->first, ft_itr->first);
	EXPECT_EQ(st_itr->first, st_begin->first);
	EXPECT_EQ(ft_itr->first, ft_begin->first);

	for (; st_itr != st_map_.end(); ++st_itr, ++ft_itr)
		EXPECT_EQ(st_itr->first, ft_itr->first);
	EXPECT_EQ(ft_itr, ft_map_.end());
}

TEST_F(AvlTreeIteratorTest, OpeRelationalTest)
{
	std::map<int, std::string>::iterator	st_first_itr = st_map_.begin();
	ft::map<int, std::string>::iterator		ft_first_itr = ft_map_.begin();
	std::map<int, std::string>::iterator	st_second_itr = ++st_first_itr;
	ft::map<int, std::string>::iterator		ft_second_itr = ++ft_first_itr;
	--st_first_itr;
	--ft_first_itr;

	EXPECT_EQ(st_first_itr == st_first_itr,		ft_first_itr == ft_first_itr);
	EXPECT_EQ(st_first_itr == st_second_itr,	ft_first_itr == ft_second_itr);
	EXPECT_EQ(st_first_itr != st_second_itr,	ft_first_itr != ft_second_itr);
}

TEST_F(AvlTreeIteratorTest, OpeOthersTest)
{
	std::map<int, std::string>::iterator	st_itr = st_map_.begin();
	ft::map<int, std::string>::iterator		ft_itr = ft_map_.begin();

	EXPECT_EQ((*st_itr).first, (*ft_itr).first);
	EXPECT_EQ(st_itr->first, ft_itr->first);
}

TEST_F(AvlTreeIteratorTest, ConstIteratorTest)
{
	std::map<int, std::string>::iterator	st_itr = st_map_.begin();
	ft::map<int, std::string>::iterator		ft_itr = ft_map_.begin();
	st_itr->second = "X";	ft_itr->second = "X";
	(*st_itr).second = "X";	(*ft_itr).second = "X";

	std::map<int, std::string>::const_iterator	st_citr = st_map_.begin();
	ft::map<int, std::string>::const_iterator	ft_citr = ft_map_.begin();
	// st_citr->second = "X";
	// ft_citr->second = "X";
	// (*st_citr).second = "X";
	// (*ft_citr).second = "X";
	(void)st_citr;

	ft::map<int, std::string>::const_iterator	citr = ft_map_.begin();
	for (int i = 0;  i < 12; ++i)
		++citr;
	EXPECT_EQ(citr, ft_map_.end());
	for (int i = 0; i < 12; ++i)
		--citr;
	EXPECT_EQ(citr, ft_map_.begin());

	citr = ft_map_.end();
	for (int i = 0;  i < 12; ++i)
		--citr;
	EXPECT_EQ(citr, ft_map_.begin());
	for (int i = 0; i < 12; ++i)
		++citr;
	EXPECT_EQ(citr, ft_map_.end());
}

TEST_F(AvlTreeIteratorTest, CopyConstructorConstTest)
{
	std::map<int, std::string>			st_map(st_pairs_, st_pairs_ + 12);
	const std::map<int, std::string>	st_const_map(st_pairs_, st_pairs_ + 12);
	ft::map<int, std::string>			ft_map(ft_pairs_, ft_pairs_ + 12);
	const ft::map<int, std::string>		ft_const_map(ft_pairs_, ft_pairs_ + 12);

	std::map<int, std::string>::iterator	st_itr1(st_map.begin());
	// std::map<int, std::string>::iterator	st_itr2(st_const_map.begin());
	ft::map<int, std::string>::iterator		ft_itr1(ft_map.begin());
	// typedef const_iterator で、node にもconst つけないと、コンパイル通る。
	// ft::map<int, std::string>::iterator		ft_itr2(ft_const_map.begin());

	std::map<int, std::string>::const_iterator	st_const_itr1(st_map.begin());
	std::map<int, std::string>::const_iterator	st_const_itr2(st_const_map.begin());
	ft::map<int, std::string>::const_iterator	ft_const_itr1(ft_map.begin());
	ft::map<int, std::string>::const_iterator	ft_const_itr2(ft_const_map.begin());

	 (void)st_itr1; (void)st_const_itr1; (void)st_const_itr2;
}

TEST_F(AvlTreeIteratorTest, OpeEqualConstTest)
{
	std::map<int, std::string>			st_map(st_pairs_, st_pairs_ + 12);
	const std::map<int, std::string>	st_const_map(st_pairs_, st_pairs_ + 12);
	ft::map<int, std::string>			ft_map(ft_pairs_, ft_pairs_ + 12);
	const ft::map<int, std::string>		ft_const_map(ft_pairs_, ft_pairs_ + 12);

	std::map<int, std::string>::iterator	st_itr1; st_itr1 = st_map.begin();
	// std::map<int, std::string>::iterator	st_itr2; st_itr2 = st_const_map.begin();
	ft::map<int, std::string>::iterator		ft_itr1; ft_itr1 = ft_map.begin();
	// ft::map<int, std::string>::iterator		ft_itr2; ft_itr2 = ft_const_map.begin();

	std::map<int, std::string>::const_iterator st_const_itr1; st_const_itr1 = st_map.begin();
	std::map<int, std::string>::const_iterator st_const_itr2; st_const_itr2 = st_const_map.begin();
	ft::map<int, std::string>::const_iterator  ft_const_itr1; ft_const_itr1 = ft_map.begin();
	ft::map<int, std::string>::const_iterator  ft_const_itr2; ft_const_itr2 = ft_const_map.begin();
}

TEST_F(AvlTreeIteratorTest, OpeRelationalConstTest)
{
	std::map<int, std::string>::iterator			st_itr1 = st_map_.begin();
	std::map<int, std::string>::const_iterator		st_itr2 = st_map_.begin();
	ft::map<int, std::string>::iterator				ft_itr1 = ft_map_.begin();
	ft::map<int, std::string>::const_iterator		ft_itr2 = ft_map_.begin();
	EXPECT_EQ(st_itr1 == st_itr2, ft_itr1 == ft_itr2);
	EXPECT_EQ(st_itr2 == st_itr1, ft_itr2 == ft_itr1);
	EXPECT_EQ(st_itr2 == st_itr2, ft_itr2 == ft_itr2);
}
