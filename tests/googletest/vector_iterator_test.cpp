#ifndef TESTLIB
# include <gtest/gtest.h>
#else
# include "testlib.hpp"
#endif
#include "vector.hpp"

class VectorIteratorTest : public ::testing::Test
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

const int VectorIteratorTest::nums[3] = {10, 20, 30};


TEST_F(VectorIteratorTest, ConstructorTest)
{
	std::vector<int>::iterator	st_itr(st_vec_.begin());
	ft::vector<int>::iterator	ft_itr(ft_vec_.begin());
	std::vector<int>::iterator	st_begin;
	st_begin = st_vec_.begin();
	ft::vector<int>::iterator	ft_begin;
	ft_begin = ft_vec_.begin();

	EXPECT_EQ(*st_itr, *ft_itr);
	EXPECT_EQ(*st_begin, *ft_begin);
	EXPECT_EQ(st_itr, st_begin);
	EXPECT_EQ(ft_itr, ft_begin);
}

TEST_F(VectorIteratorTest, OpeAddSubTest)
{
	std::vector<int>::iterator	st_itr	= st_vec_.begin();
	ft::vector<int>::iterator	ft_itr = ft_vec_.begin();
	std::vector<int>::iterator	st_begin = st_vec_.begin();
	ft::vector<int>::iterator	ft_begin = ft_vec_.begin();

	EXPECT_EQ(*(st_itr++), *(ft_itr++));
	EXPECT_EQ(*(++st_itr), *(++ft_itr));
	EXPECT_EQ(*(st_itr--), *(ft_itr--));
	EXPECT_EQ(*(--st_itr), *(--ft_itr));

	EXPECT_EQ(*(st_itr += 1), *(ft_itr += 1));
	EXPECT_EQ(*(st_itr -= 1), *(ft_itr -= 1));
	EXPECT_EQ(*(st_itr + 1), *(ft_itr + 1));
	EXPECT_EQ(*(st_itr - 1 + 1), *(ft_itr - 1 + 1));
	EXPECT_EQ(*(1 + st_itr), *(1 + ft_itr));
	EXPECT_EQ((st_itr + 1) - st_begin, (ft_itr + 1) - ft_begin);

	EXPECT_EQ(*st_itr, *ft_itr);
	EXPECT_EQ(st_itr, st_begin);
	EXPECT_EQ(ft_itr, ft_begin);

	for (; st_itr != st_vec_.end(); ++st_itr, ++ft_itr)
		EXPECT_EQ(*st_itr, *ft_itr);
	EXPECT_EQ(ft_itr, ft_vec_.end());
}

TEST_F(VectorIteratorTest, OpeRelationalTest)
{
	std::vector<int>::iterator	st_first_itr = st_vec_.begin();
	ft::vector<int>::iterator	ft_first_itr = ft_vec_.begin();
	std::vector<int>::iterator st_second_itr = st_first_itr + 1;
	ft::vector<int>::iterator	ft_second_itr = ft_first_itr + 1;

	EXPECT_EQ(st_first_itr == st_second_itr,	ft_first_itr == ft_second_itr);
	EXPECT_EQ(st_first_itr != st_second_itr,	ft_first_itr != ft_second_itr);
	EXPECT_EQ(st_first_itr <  st_second_itr,	ft_first_itr <  ft_second_itr);
	EXPECT_EQ(st_first_itr <= st_second_itr,	ft_first_itr <= ft_second_itr);
	EXPECT_EQ(st_first_itr >  st_second_itr,	ft_first_itr >  ft_second_itr);
	EXPECT_EQ(st_first_itr >= st_second_itr,	ft_first_itr >= ft_second_itr);
}

TEST_F(VectorIteratorTest, OpeOthersTest)
{
	std::string	s[3] = {"a", "b", "c"};
	std::vector<std::string>	st_str_vec(s, s + 3);
	ft::vector<std::string>		ft_str_vec(s, s + 3);
	std::vector<std::string>::iterator	st_itr = st_str_vec.begin();
	ft::vector<std::string>::iterator	ft_itr = ft_str_vec.begin();

	EXPECT_EQ(*st_itr, *ft_itr);
	EXPECT_EQ(st_itr[1], ft_itr[1]);
	EXPECT_EQ(st_itr->length(), ft_itr->length());
}

TEST_F(VectorIteratorTest, ConstIteratorTest)
{
	std::vector<int>::iterator	st_itr = st_vec_.begin();
	ft::vector<int>::iterator	ft_itr = ft_vec_.begin();
	*st_itr = 42;
	*ft_itr = 42;
	// std::vector<int>::const_iterator	st_citr = st_vec_.begin();
	// ft::vector<int>::const_iterator		ft_citr = ft_vec_.begin();
	// *st_citr = 42;
	// *ft_citr = 42;
}

TEST_F(VectorIteratorTest, CopyConstructorConstTest)
{
	std::vector<int>			st_vec(nums, nums + 3);
	std::vector<const int>		st_vec_const(nums, nums + 3);
	const std::vector<int>		st_const_vec(nums, nums + 3);
	ft::vector<int>				ft_vec(nums, nums + 3);
	ft::vector<const int>		ft_vec_const(nums, nums + 3);
	const ft::vector<int>		ft_const_vec(nums, nums + 3);

	std::vector<int>::iterator		st_itr1(st_vec.begin());
	// std::vector<int>::iterator		st_itr2(st_vec_const.begin());
	// std::vector<int>::iterator		st_itr3(st_const_vec.begin());
	ft::vector<int>::iterator		ft_itr1(ft_vec.begin());
	// ft::vector<int>::iterator		ft_itr2(ft_vec_const.begin());
	// ft::vector<int>::iterator		ft_itr3(ft_const_vec.begin());
	std::vector<const int>::iterator	st_itr_const1(st_vec.begin());
	std::vector<const int>::iterator	st_itr_const2(st_vec_const.begin());
	std::vector<const int>::iterator	st_itr_const3(st_const_vec.begin());
	ft::vector<const int>::iterator		ft_itr_const1(ft_vec.begin());
	ft::vector<const int>::iterator		ft_itr_const2(ft_vec_const.begin());
	ft::vector<const int>::iterator		ft_itr_const3(ft_const_vec.begin());

	std::vector<int>::const_iterator	st_const_itr1(st_vec.begin());
	std::vector<int>::const_iterator	st_const_itr2(st_vec_const.begin());
	std::vector<int>::const_iterator	st_const_itr3(st_const_vec.begin());
	ft::vector<int>::const_iterator		ft_const_itr1(ft_vec.begin());
	ft::vector<int>::const_iterator		ft_const_itr2(ft_vec_const.begin());
	ft::vector<int>::const_iterator		ft_const_itr3(ft_const_vec.begin());

	(void)st_itr1;
	(void)st_itr_const1; (void)st_itr_const2; (void)st_itr_const3;
	(void)st_const_itr1; (void)st_const_itr2; (void)st_const_itr3;
}

TEST_F(VectorIteratorTest, OpeEqualConstTest)
{
	std::vector<int>			st_vec(nums, nums + 3);
	std::vector<const int>		st_vec_const(nums, nums + 3);
	const std::vector<int>		st_const_vec(nums, nums + 3);
	ft::vector<int>				ft_vec(nums, nums + 3);
	ft::vector<const int>		ft_vec_const(nums, nums + 3);
	const ft::vector<int>		ft_const_vec(nums, nums + 3);

	std::vector<int>::iterator		st_itr1; st_itr1 = st_vec.begin();
	// std::vector<int>::iterator		st_itr2; st_itr2 = st_vec_const.begin();
	// std::vector<int>::iterator		st_itr3; st_itr3 = st_const_vec.begin();
	ft::vector<int>::iterator		ft_itr1; ft_itr1 = ft_vec.begin();
	// ft::vector<int>::iterator		ft_itr2; ft_itr2 = ft_vec_const.begin();
	// ft::vector<int>::iterator		ft_itr3; ft_itr3 = ft_const_vec.begin();

	std::vector<const int>::iterator st_itr_const1; st_itr_const1 = st_vec.begin();
	std::vector<const int>::iterator st_itr_const2; st_itr_const2 = st_vec_const.begin();
	std::vector<const int>::iterator st_itr_const3; st_itr_const3 = st_const_vec.begin();
	ft::vector<const int>::iterator	 ft_itr_const1; ft_itr_const1 = ft_vec.begin();
	ft::vector<const int>::iterator	 ft_itr_const2; ft_itr_const2 = ft_vec_const.begin();
	ft::vector<const int>::iterator	 ft_itr_const3; ft_itr_const3 = ft_const_vec.begin();

	std::vector<int>::const_iterator st_const_itr1; st_const_itr1 = st_vec.begin();
	std::vector<int>::const_iterator st_const_itr2; st_const_itr2 = st_vec_const.begin();
	std::vector<int>::const_iterator st_const_itr3; st_const_itr3 = st_const_vec.begin();
	ft::vector<int>::const_iterator	 ft_const_itr1; ft_const_itr1 = ft_vec.begin();
	ft::vector<int>::const_iterator	 ft_const_itr2; ft_const_itr2 = ft_vec_const.begin();
	ft::vector<int>::const_iterator	 ft_const_itr3; ft_const_itr3 = ft_const_vec.begin();
}

TEST_F(VectorIteratorTest, OpeBothSidesConstTest)
{
	std::vector<int>::iterator				st_itr1 = st_vec_.begin();
	std::vector<int>::const_iterator		st_itr2 = st_vec_.begin();
	std::vector<const int>::iterator		st_itr3 = st_vec_.begin();
	ft::vector<int>::iterator				ft_itr1 = ft_vec_.begin();
	ft::vector<int>::const_iterator			ft_itr2 = ft_vec_.begin();
	ft::vector<const int>::iterator			ft_itr3 = ft_vec_.begin();
	EXPECT_EQ(st_itr1 == st_itr2, ft_itr1 == ft_itr2);	EXPECT_EQ(st_itr2 == st_itr1, ft_itr2 == ft_itr1);
	EXPECT_EQ(st_itr1 == st_itr3, ft_itr1 == ft_itr3);	EXPECT_EQ(st_itr3 == st_itr1, ft_itr3 == ft_itr1);
	EXPECT_EQ(st_itr2 == st_itr3, ft_itr2 == ft_itr3);	EXPECT_EQ(st_itr3 == st_itr2, ft_itr3 == ft_itr2);

	EXPECT_EQ(*(st_itr1 + 1), *(ft_itr1 + 1));	EXPECT_EQ(*(1 + st_itr1), *(1 + ft_itr1));
	EXPECT_EQ(*(st_itr2 + 1), *(ft_itr2 + 1));	EXPECT_EQ(*(1 + st_itr2), *(1 + ft_itr2));
	EXPECT_EQ(*(st_itr3 + 1), *(ft_itr3 + 1));	EXPECT_EQ(*(1 + st_itr3), *(1 + ft_itr3));
	EXPECT_EQ(*(++st_itr1 - 1), *(++ft_itr1 - 1));
	EXPECT_EQ(*(++st_itr2 - 1), *(++ft_itr2 - 1));
	EXPECT_EQ(*(++st_itr3 - 1), *(++ft_itr3 - 1));
	EXPECT_EQ(st_itr1 - st_itr2, ft_itr1 - ft_itr2);	EXPECT_EQ(st_itr2 - st_itr1, ft_itr2 - ft_itr1);
	EXPECT_EQ(st_itr1 - st_itr3, ft_itr1 - ft_itr3);	EXPECT_EQ(st_itr3 - st_itr1, ft_itr3 - ft_itr1);
	EXPECT_EQ(st_itr2 - st_itr3, ft_itr2 - ft_itr3);	EXPECT_EQ(st_itr3 - st_itr2, ft_itr3 - ft_itr2);
}
