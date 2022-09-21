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

TEST_F(VectorIteratorTest, CopyConstructorConstTest)
{
	ft::vector<int>				vec(nums, nums + 3);
	ft::vector<const int>		vec_const(nums, nums + 3);
	const ft::vector<int>		const_vec(nums, nums + 3);

	ft::vector<int>::iterator		itr1(vec.begin());
	// ft::vector<int>::iterator		itr1(vec_const.begin());
	// ft::vector<int>::iterator		itr1(const_vec.begin());

	ft::vector<const int>::iterator	itr_const1(vec.begin());
	ft::vector<const int>::iterator	itr_const2(vec_const.begin());
	ft::vector<const int>::iterator	itr_const3(const_vec.begin());

	ft::vector<int>::const_iterator	const_itr1(vec.begin());
	ft::vector<int>::const_iterator	const_itr2(vec_const.begin());
	ft::vector<int>::const_iterator	const_itr3(const_vec.begin());
}

TEST_F(VectorIteratorTest, OpeEqualConstTest)
{
	ft::vector<int>				vec(nums, nums + 3);
	ft::vector<const int>		vec_const(nums, nums + 3);
	const ft::vector<int>		const_vec(nums, nums + 3);

	ft::vector<int>::iterator	itr1; itr1 = vec.begin();
	// ft::vector<int>::iterator	itr2; itr2 = vec_const.begin();
	// ft::vector<int>::iterator	itr3; itr3 = const_vec.begin();

	// copy constructor が呼ばれたのち、operator= が呼ばれる。
	ft::vector<const int>::iterator	itr_const1; itr_const1 = vec.begin();
	ft::vector<const int>::iterator	itr_const2; itr_const2 = vec_const.begin();
	ft::vector<const int>::iterator	itr_const3; itr_const3 = const_vec.begin();

	ft::vector<int>::const_iterator	const_itr1; const_itr1 = vec.begin();
	ft::vector<int>::const_iterator	const_itr2; const_itr2 = vec_const.begin();
	ft::vector<int>::const_iterator	const_itr3; const_itr3 = const_vec.begin();
}

TEST_F(VectorIteratorTest, OpeBothSidesTest)
{
	ft::vector<int>::iterator				itr1 = ft_vec_.begin();
	ft::vector<int>::const_iterator			itr2 = ft_vec_.begin();
	ft::vector<const int>::iterator			itr3 = ft_vec_.begin();
	ft::vector<const int>::const_iterator	itr4 = ft_vec_.begin();
	EXPECT_EQ(itr1 == itr2, true);	EXPECT_EQ(itr2 == itr1, true);
	EXPECT_EQ(itr2 == itr3, true);	EXPECT_EQ(itr3 == itr2, true);
	EXPECT_EQ(itr3 == itr4, true);	EXPECT_EQ(itr4 == itr3, true);
	EXPECT_EQ(itr1 + 1, ++itr1);	EXPECT_EQ(1 + itr1, ++itr1);
	EXPECT_EQ(itr2 + 1, ++itr2);	EXPECT_EQ(1 + itr2, ++itr2);
	EXPECT_EQ(itr3 + 1, ++itr3);	EXPECT_EQ(1 + itr3, ++itr3);
	EXPECT_EQ(itr4 + 1, ++itr4);	EXPECT_EQ(1 + itr4, ++itr4);
	EXPECT_EQ(itr1 - 1, --itr1);
	EXPECT_EQ(itr2 - 1, --itr2);
	EXPECT_EQ(itr3 - 1, --itr3);
	EXPECT_EQ(itr4 - 1, --itr4);
	EXPECT_EQ(itr1 - itr2, 0);		EXPECT_EQ(itr2 - itr1, 0);
	EXPECT_EQ(itr2 - itr3, 0);		EXPECT_EQ(itr3 - itr2, 0);
	EXPECT_EQ(itr3 - itr4, 0);		EXPECT_EQ(itr4 - itr3, 0);
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

// TEST_F(VectorIteratorTest, ConstIteratorTest)
// {
// 	std::vector<int>::iterator			st_itr = st_vec_.begin();
// 	ft::vector<int>::iterator			ft_itr = ft_vec_.begin();
// 	*st_itr = 42;
// 	*ft_itr = 42;

// 	std::vector<int>::const_iterator	st_citr = st_vec_.begin();
// 	ft::vector<int>::const_iterator		ft_citr = ft_vec_.begin();
// 	*st_citr = 42;
// 	*ft_citr = 42;
// }
