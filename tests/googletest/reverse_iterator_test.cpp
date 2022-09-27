#ifndef TESTLIB
# include <gtest/gtest.h>
#else
# include "testlib.hpp"
#endif
#include "vector.hpp"

class ReverseIteratorTest : public ::testing::Test
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
			st_vec_.assign(nums_, nums_ + 3);
			ft_vec_.assign(nums_, nums_ + 3);
		}
		virtual void TearDown()
		{
		}

		static const int	nums_[5];
		std::vector<int>	st_vec_;
		ft::vector<int>		ft_vec_;
};

const int ReverseIteratorTest::nums_[5] = {10, 20, 30, 40, 50};


TEST_F(ReverseIteratorTest, ConstructorTest)
{
	std::vector<int>::reverse_iterator	st_ritr(st_vec_.rbegin());
	ft::vector<int>::reverse_iterator	ft_ritr(ft_vec_.rbegin());
	std::vector<int>::reverse_iterator	st_rbegin;
	st_rbegin = st_vec_.rbegin();
	ft::vector<int>::reverse_iterator	ft_rbegin;
	ft_rbegin = ft_vec_.rbegin();

	EXPECT_EQ(*st_ritr, *ft_ritr);
	EXPECT_EQ(*st_rbegin, *ft_rbegin);
	EXPECT_EQ(st_ritr, st_rbegin);
	EXPECT_EQ(ft_ritr, ft_rbegin);
}

TEST_F(ReverseIteratorTest, OpeAddSubTest)
{
	std::vector<int>::reverse_iterator	st_ritr	= st_vec_.rbegin();
	ft::vector<int>::reverse_iterator	ft_ritr = ft_vec_.rbegin();
	std::vector<int>::reverse_iterator	st_rbegin = st_vec_.rbegin();
	ft::vector<int>::reverse_iterator	ft_rbegin = ft_vec_.rbegin();

	EXPECT_EQ(*(st_ritr++), *(ft_ritr++));
	EXPECT_EQ(*(++st_ritr), *(++ft_ritr));
	EXPECT_EQ(*(st_ritr--), *(ft_ritr--));
	EXPECT_EQ(*(--st_ritr), *(--ft_ritr));

	EXPECT_EQ(*(st_ritr += 1), *(ft_ritr += 1));
	EXPECT_EQ(*(st_ritr -= 1), *(ft_ritr -= 1));
	EXPECT_EQ(*(st_ritr + 1), *(ft_ritr + 1));
	EXPECT_EQ(*(st_ritr - 1 + 1), *(ft_ritr - 1 + 1));
	EXPECT_EQ(*(1 + st_ritr), *(1 + ft_ritr));
	EXPECT_EQ((st_ritr + 1) - st_rbegin, (ft_ritr + 1) - ft_rbegin);

	EXPECT_EQ(*st_ritr, *ft_ritr);
	EXPECT_EQ(st_ritr, st_rbegin);
	EXPECT_EQ(ft_ritr, ft_rbegin);

	for (; st_ritr != st_vec_.rend(); ++st_ritr, ++ft_ritr)
		EXPECT_EQ(*st_ritr, *ft_ritr);
	EXPECT_EQ(ft_ritr, ft_vec_.rend());
}

TEST_F(ReverseIteratorTest, OpeRelationalTest)
{
	std::vector<int>::reverse_iterator	st_first_ritr = st_vec_.rbegin();
	ft::vector<int>::reverse_iterator	ft_first_ritr = ft_vec_.rbegin();
	std::vector<int>::reverse_iterator	st_second_ritr = st_first_ritr + 1;
	ft::vector<int>::reverse_iterator	ft_second_ritr = ft_first_ritr + 1;

	EXPECT_EQ(st_first_ritr == st_second_ritr,	ft_first_ritr == ft_second_ritr);
	EXPECT_EQ(st_first_ritr != st_second_ritr,	ft_first_ritr != ft_second_ritr);
	EXPECT_EQ(st_first_ritr <  st_second_ritr,	ft_first_ritr <  ft_second_ritr);
	EXPECT_EQ(st_first_ritr <= st_second_ritr,	ft_first_ritr <= ft_second_ritr);
	EXPECT_EQ(st_first_ritr >  st_second_ritr,	ft_first_ritr >  ft_second_ritr);
	EXPECT_EQ(st_first_ritr >= st_second_ritr,	ft_first_ritr >= ft_second_ritr);
}

TEST_F(ReverseIteratorTest, OpeOthersTest)
{
	std::string s[3] = {"a", "b", "c"};
	std::vector<std::string>	st_str_vec(s, s + 3);
	ft::vector<std::string>		ft_str_vec(s, s + 3);
	std::vector<std::string>::reverse_iterator	st_ritr	= st_str_vec.rbegin();
	ft::vector<std::string>::reverse_iterator	ft_ritr	= ft_str_vec.rbegin();

	EXPECT_EQ(*st_ritr, *ft_ritr);
	EXPECT_EQ(st_ritr[1], ft_ritr[1]);
	EXPECT_EQ(st_ritr->length(), ft_ritr->length());
}

TEST_F(ReverseIteratorTest, ConstIteratorTest)
{
	std::vector<int>::reverse_iterator	st_ritr = st_vec_.rbegin();
	ft::vector<int>::reverse_iterator	ft_ritr = ft_vec_.rbegin();
	*st_ritr = 42;
	*ft_ritr = 42;
	// std::vector<int>::const_reverse_iterator	st_citr = st_vec_.rbegin();
	// ft::vector<int>::const_reverse_iterator		ft_citr = ft_vec_.rbegin();
	// *st_citr = 42;
	// *ft_citr = 42;
}

TEST_F(ReverseIteratorTest, CopyConstructorConstTest)
{
	std::vector<int>			st_vec(nums_, nums_ + 3);
	std::vector<const int>		st_vec_const(nums_, nums_ + 3);
	const std::vector<int>		st_const_vec(nums_, nums_ + 3);
	ft::vector<int>				ft_vec(nums_, nums_ + 3);
	ft::vector<const int>		ft_vec_const(nums_, nums_ + 3);
	const ft::vector<int>		ft_const_vec(nums_, nums_ + 3);

	std::vector<int>::reverse_iterator		st_ritr1(st_vec.rbegin());
	// std::vector<int>::reverse_iterator		st_ritr2(st_vec_const.rbegin());
	// std::vector<int>::reverse_iterator		st_ritr3(st_const_vec.rbegin());
	ft::vector<int>::reverse_iterator		ft_ritr1(ft_vec.rbegin());
	// ft::vector<int>::reverse_iterator		ft_ritr2(ft_vec_const.rbegin());
	// ft::vector<int>::reverse_iterator		ft_ritr3(ft_const_vec.rbegin());

	std::vector<const int>::reverse_iterator	st_ritr_const1(st_vec.rbegin());
	std::vector<const int>::reverse_iterator	st_ritr_const2(st_vec_const.rbegin());
	std::vector<const int>::reverse_iterator	st_ritr_const3(st_const_vec.rbegin());
	ft::vector<const int>::reverse_iterator		ft_ritr_const1(ft_vec.rbegin());
	ft::vector<const int>::reverse_iterator		ft_ritr_const2(ft_vec_const.rbegin());
	ft::vector<const int>::reverse_iterator		ft_ritr_const3(ft_const_vec.rbegin());

	std::vector<int>::const_reverse_iterator	st_const_ritr1(st_vec.rbegin());
	std::vector<int>::const_reverse_iterator	st_const_ritr2(st_vec_const.rbegin());
	std::vector<int>::const_reverse_iterator	st_const_ritr3(st_const_vec.rbegin());
	ft::vector<int>::const_reverse_iterator		ft_const_ritr1(ft_vec.rbegin());
	ft::vector<int>::const_reverse_iterator		ft_const_ritr2(ft_vec_const.rbegin());
	ft::vector<int>::const_reverse_iterator		ft_const_ritr3(ft_const_vec.rbegin());

	(void)st_ritr1;
	(void)st_ritr_const1; (void)st_ritr_const2; (void)st_ritr_const3;
	(void)st_const_ritr1; (void)st_const_ritr2; (void)st_const_ritr3;
}

TEST_F(ReverseIteratorTest, OpeEqualConstTest)
{
	std::vector<int>			st_vec(nums_, nums_ + 3);
	std::vector<const int>		st_vec_const(nums_, nums_ + 3);
	const std::vector<int>		st_const_vec(nums_, nums_ + 3);
	ft::vector<int>				ft_vec(nums_, nums_ + 3);
	ft::vector<const int>		ft_vec_const(nums_, nums_ + 3);
	const ft::vector<int>		ft_const_vec(nums_, nums_ + 3);

	std::vector<int>::reverse_iterator		st_ritr1; st_ritr1 = st_vec.rbegin();
	// std::vector<int>::reverse_iterator		st_ritr2; st_ritr2 = st_vec_const.rbegin();
	// std::vector<int>::reverse_iterator		st_ritr3; st_ritr3 = st_const_vec.rbegin();
	ft::vector<int>::reverse_iterator		ft_ritr1; ft_ritr1 = ft_vec.rbegin();
	// ft::vector<int>::reverse_iterator		ft_ritr2; ft_ritr2 = ft_vec_const.rbegin();
	// ft::vector<int>::reverse_iterator		ft_ritr3; ft_ritr3 = ft_const_vec.rbegin();

	std::vector<const int>::reverse_iterator st_ritr_const1; st_ritr_const1 = st_vec.rbegin();
	std::vector<const int>::reverse_iterator st_ritr_const2; st_ritr_const2 = st_vec_const.rbegin();
	std::vector<const int>::reverse_iterator st_ritr_const3; st_ritr_const3 = st_const_vec.rbegin();
	ft::vector<const int>::reverse_iterator	 ft_ritr_const1; ft_ritr_const1 = ft_vec.rbegin();
	ft::vector<const int>::reverse_iterator	 ft_ritr_const2; ft_ritr_const2 = ft_vec_const.rbegin();
	ft::vector<const int>::reverse_iterator	 ft_ritr_const3; ft_ritr_const3 = ft_const_vec.rbegin();

	std::vector<int>::const_reverse_iterator st_const_ritr1; st_const_ritr1 = st_vec.rbegin();
	std::vector<int>::const_reverse_iterator st_const_ritr2; st_const_ritr2 = st_vec_const.rbegin();
	std::vector<int>::const_reverse_iterator st_const_ritr3; st_const_ritr3 = st_const_vec.rbegin();
	ft::vector<int>::const_reverse_iterator	 ft_const_ritr1; ft_const_ritr1 = ft_vec.rbegin();
	ft::vector<int>::const_reverse_iterator	 ft_const_ritr2; ft_const_ritr2 = ft_vec_const.rbegin();
	ft::vector<int>::const_reverse_iterator	 ft_const_ritr3; ft_const_ritr3 = ft_const_vec.rbegin();
}

TEST_F(ReverseIteratorTest, OpeBothSidesConstTest)
{
	std::vector<int>::reverse_iterator				st_ritr1 = st_vec_.rbegin();
	std::vector<int>::const_reverse_iterator		st_ritr2 = st_vec_.rbegin();
	std::vector<const int>::reverse_iterator		st_ritr3 = st_vec_.rbegin();
	ft::vector<int>::reverse_iterator				ft_ritr1 = ft_vec_.rbegin();
	ft::vector<int>::const_reverse_iterator			ft_ritr2 = ft_vec_.rbegin();
	ft::vector<const int>::reverse_iterator			ft_ritr3 = ft_vec_.rbegin();
	EXPECT_EQ(st_ritr1 == st_ritr2, ft_ritr1 == ft_ritr2);	EXPECT_EQ(st_ritr2 == st_ritr1, ft_ritr2 == ft_ritr1);
	EXPECT_EQ(st_ritr1 == st_ritr3, ft_ritr1 == ft_ritr3);	EXPECT_EQ(st_ritr3 == st_ritr1, ft_ritr3 == ft_ritr1);
	EXPECT_EQ(st_ritr2 == st_ritr3, ft_ritr2 == ft_ritr3);	EXPECT_EQ(st_ritr3 == st_ritr2, ft_ritr3 == ft_ritr2);

	EXPECT_EQ(*(st_ritr1 + 1), *(ft_ritr1 + 1));	EXPECT_EQ(*(1 + st_ritr1), *(1 + ft_ritr1));
	EXPECT_EQ(*(st_ritr2 + 1), *(ft_ritr2 + 1));	EXPECT_EQ(*(1 + st_ritr2), *(1 + ft_ritr2));
	EXPECT_EQ(*(st_ritr3 + 1), *(ft_ritr3 + 1));	EXPECT_EQ(*(1 + st_ritr3), *(1 + ft_ritr3));
	EXPECT_EQ(*(++st_ritr1 - 1), *(++ft_ritr1 - 1));
	EXPECT_EQ(*(++st_ritr2 - 1), *(++ft_ritr2 - 1));
	EXPECT_EQ(*(++st_ritr3 - 1), *(++ft_ritr3 - 1));
	EXPECT_EQ(st_ritr1 - st_ritr2, ft_ritr1 - ft_ritr2);	EXPECT_EQ(st_ritr2 - st_ritr1, ft_ritr2 - ft_ritr1);
	EXPECT_EQ(st_ritr1 - st_ritr3, ft_ritr1 - ft_ritr3);	EXPECT_EQ(st_ritr3 - st_ritr1, ft_ritr3 - ft_ritr1);
	EXPECT_EQ(st_ritr2 - st_ritr3, ft_ritr2 - ft_ritr3);	EXPECT_EQ(st_ritr3 - st_ritr2, ft_ritr3 - ft_ritr2);
}
