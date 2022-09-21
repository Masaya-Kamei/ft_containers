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
			st_vec_.assign(nums, nums + 3);
			ft_vec_.assign(nums, nums + 3);
		}
		virtual void TearDown()
		{
		}

		static const int	nums[3];
		std::vector<int>	st_vec_;
		ft::vector<int>		ft_vec_;
};

const int ReverseIteratorTest::nums[3] = {1, 2, 3};


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

TEST_F(ReverseIteratorTest, CopyConstructorConstTest)
{
	ft::vector<int>				vec(nums, nums + 3);
	ft::vector<const int>		vec_const(nums, nums + 3);
	const ft::vector<int>		const_vec(nums, nums + 3);

	ft::vector<int>::reverse_iterator		ritr1(vec.rbegin());
	// ft::vector<int>::reverse_iterator		ritr2(vec_const.rbegin());
	// ft::vector<int>::reverse_iterator		ritr3(const_vec.rbegin());

	ft::vector<const int>::reverse_iterator	ritr_const1(vec.rbegin());
	ft::vector<const int>::reverse_iterator	ritr_const2(vec_const.rbegin());
	ft::vector<const int>::reverse_iterator	ritr_const3(const_vec.rbegin());

	ft::vector<int>::const_reverse_iterator	const_ritr1(vec.rbegin());
	ft::vector<int>::const_reverse_iterator	const_ritr2(vec_const.rbegin());
	ft::vector<int>::const_reverse_iterator	const_ritr3(const_vec.rbegin());
}

TEST_F(ReverseIteratorTest, OpeEqualConstTest)
{
	ft::vector<int>				vec(nums, nums + 3);
	ft::vector<const int>		vec_const(nums, nums + 3);
	const ft::vector<int>		const_vec(nums, nums + 3);

	ft::vector<int>::reverse_iterator		ritr1(vec.rbegin());
	// ft::vector<int>::reverse_iterator		ritr2(vec_const.rbegin());
	// ft::vector<int>::reverse_iterator		ritr3(const_vec.rbegin());

	ft::vector<const int>::reverse_iterator	ritr_const1; ritr_const1 = vec.rbegin();
	ft::vector<const int>::reverse_iterator	ritr_const2; ritr_const2 = vec_const.rbegin();
	ft::vector<const int>::reverse_iterator	ritr_const3; ritr_const3 = const_vec.rbegin();

	ft::vector<int>::const_reverse_iterator	const_ritr1; const_ritr1 = vec.rbegin();
	ft::vector<int>::const_reverse_iterator	const_ritr2; const_ritr2 = vec_const.rbegin();
	ft::vector<int>::const_reverse_iterator	const_ritr3; const_ritr3 = const_vec.rbegin();
}

TEST_F(ReverseIteratorTest, OpeBothSidesTest)
{
	ft::vector<int>::reverse_iterator				ritr1 = ft_vec_.rbegin();
	ft::vector<int>::const_reverse_iterator			ritr2 = ft_vec_.rbegin();
	ft::vector<const int>::reverse_iterator			ritr3 = ft_vec_.rbegin();
	ft::vector<const int>::const_reverse_iterator	ritr4 = ft_vec_.rbegin();
	EXPECT_EQ(ritr1 == ritr2, true);	EXPECT_EQ(ritr2 == ritr1, true);
	EXPECT_EQ(ritr2 == ritr3, true);	EXPECT_EQ(ritr3 == ritr2, true);
	EXPECT_EQ(ritr3 == ritr4, true);	EXPECT_EQ(ritr4 == ritr3, true);
	EXPECT_EQ(ritr1 + 1, ++ritr1);		EXPECT_EQ(1 + ritr1, ++ritr1);
	EXPECT_EQ(ritr2 + 1, ++ritr2);		EXPECT_EQ(1 + ritr2, ++ritr2);
	EXPECT_EQ(ritr3 + 1, ++ritr3);		EXPECT_EQ(1 + ritr3, ++ritr3);
	EXPECT_EQ(ritr4 + 1, ++ritr4);		EXPECT_EQ(1 + ritr4, ++ritr4);
	EXPECT_EQ(ritr1 - 1, --ritr1);
	EXPECT_EQ(ritr2 - 1, --ritr2);
	EXPECT_EQ(ritr3 - 1, --ritr3);
	EXPECT_EQ(ritr4 - 1, --ritr4);
	EXPECT_EQ(ritr1 - ritr2, 0);		EXPECT_EQ(ritr2 - ritr1, 0);
	EXPECT_EQ(ritr2 - ritr3, 0);		EXPECT_EQ(ritr3 - ritr2, 0);
	EXPECT_EQ(ritr3 - ritr4, 0);		EXPECT_EQ(ritr4 - ritr3, 0);
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
}

TEST_F(ReverseIteratorTest, OpeRelationalTest)
{
	std::vector<int>::iterator	st_first_ritr = st_vec_.begin();
	ft::vector<int>::iterator	ft_first_ritr = ft_vec_.begin();
	std::vector<int>::iterator	st_second_ritr = st_first_ritr + 1;
	ft::vector<int>::iterator	ft_second_ritr = ft_first_ritr + 1;

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
