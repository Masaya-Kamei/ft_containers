#ifndef TESTLIB
# include <gtest/gtest.h>
#else
# include "testlib.hpp"
#endif
#include "vector.hpp"

class VectorIteratorTest : public ::testing::Test
{
};

TEST_F(VectorIteratorTest, ConstructorTest)
{
	int 	a[3] = {1, 2, 3};
	std::vector<int>			std_vec(a, a + 3);
	ft::vector<int>				ft_vec(a, a + 3);
	std::vector<int>::iterator	std_itr	= std_vec.begin();
	ft::vector<int>::iterator	ft_itr = ft_vec.begin();
	std::vector<int>::iterator	std_begin;
	std_begin = std_vec.begin();
	ft::vector<int>::iterator	ft_begin;
	ft_begin = ft_vec.begin();

	EXPECT_EQ(*std_itr, *ft_itr);
	EXPECT_EQ(*std_begin, *ft_begin);
	EXPECT_EQ(std_itr, std_begin);
	EXPECT_EQ(ft_itr, ft_begin);
}

TEST_F(VectorIteratorTest, CopyConstructorConstTest)
{
	int 	a[3] = {1, 2, 3};
	ft::vector<int>				vec(a, a + 3);
	ft::vector<const int>		vec_const(a, a + 3);
	const ft::vector<int>		const_vec(a, a + 3);

	ft::vector<int>::iterator		itr1(vec.begin());

	ft::vector<const int>::iterator	itr_const1(vec.begin());
	ft::vector<const int>::iterator	itr_const2(vec_const.begin());
	ft::vector<const int>::iterator	itr_const3(const_vec.begin());

	ft::vector<int>::const_iterator	const_itr1(vec.begin());
	ft::vector<int>::const_iterator	const_itr2(vec_const.begin());
	ft::vector<int>::const_iterator	const_itr3(const_vec.begin());
}

TEST_F(VectorIteratorTest, OpeEqualConstTest)
{
	int 	a[3] = {1, 2, 3};
	ft::vector<int>				vec(a, a + 3);
	ft::vector<const int>		vec_const(a, a + 3);
	const ft::vector<int>		const_vec(a, a + 3);

	ft::vector<int>::iterator		itr1(vec.begin());

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
	int a[3] = {1, 2, 3};
	ft::vector<int>	vec(a, a + 3);
	ft::vector<int>::iterator				itr1 = vec.begin();
	ft::vector<int>::const_iterator			itr2 = vec.begin();
	ft::vector<const int>::iterator			itr3 = vec.begin();
	ft::vector<const int>::const_iterator	itr4 = vec.begin();
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
	int		a[3] = {1, 2, 3};
	std::vector<int>			std_vec(a, a + 3);
	ft::vector<int>				ft_vec(a, a + 3);
	std::vector<int>::iterator	std_itr	= std_vec.begin();
	ft::vector<int>::iterator	ft_itr = ft_vec.begin();
	std::vector<int>::iterator	std_begin = std_vec.begin();
	ft::vector<int>::iterator	ft_begin = ft_vec.begin();

	EXPECT_EQ(*(std_itr++), *(ft_itr++));
	EXPECT_EQ(*(++std_itr), *(++ft_itr));
	EXPECT_EQ(*(std_itr--), *(ft_itr--));
	EXPECT_EQ(*(--std_itr), *(--ft_itr));

	EXPECT_EQ(*(std_itr += 1), *(ft_itr += 1));
	EXPECT_EQ(*(std_itr -= 1), *(ft_itr -= 1));
	EXPECT_EQ(*(std_itr + 1), *(ft_itr + 1));
	EXPECT_EQ(*(std_itr - 1 + 1), *(ft_itr - 1 + 1));
	EXPECT_EQ(*(1 + std_itr), *(1 + ft_itr));
	EXPECT_EQ((std_itr + 1) - std_begin, (ft_itr + 1) - ft_begin);

	EXPECT_EQ(*std_itr, *ft_itr);
	EXPECT_EQ(std_itr, std_begin);
	EXPECT_EQ(ft_itr, ft_begin);
}

TEST_F(VectorIteratorTest, OpeRelationalTest)
{
	int		a[3] = {1, 2, 3};
	std::vector<int>			std_vec(a, a + 3);
	ft::vector<int>				ft_vec(a, a + 3);
	std::vector<int>::iterator	std_first_itr = std_vec.begin();
	ft::vector<int>::iterator	ft_first_itr = ft_vec.begin();
	std::vector<int>::iterator	std_second_itr = std_first_itr + 1;
	ft::vector<int>::iterator	ft_second_itr = ft_first_itr + 1;

	EXPECT_EQ(std_first_itr == std_second_itr,	ft_first_itr == ft_second_itr);
	EXPECT_EQ(std_first_itr != std_second_itr,	ft_first_itr != ft_second_itr);
	EXPECT_EQ(std_first_itr < std_second_itr,	ft_first_itr < ft_second_itr);
	EXPECT_EQ(std_first_itr <= std_second_itr,	ft_first_itr <= ft_second_itr);
	EXPECT_EQ(std_first_itr > std_second_itr,	ft_first_itr > ft_second_itr);
	EXPECT_EQ(std_first_itr >= std_second_itr,	ft_first_itr >= ft_second_itr);
}

TEST_F(VectorIteratorTest, OpeOthersTest)
{
	std::string s[3] = {"a", "b", "c"};
	std::vector<std::string>	std_vec(s, s + 3);
	ft::vector<std::string>		ft_vec(s, s + 3);
	std::vector<std::string>::iterator	std_itr	= std_vec.begin();
	ft::vector<std::string>::iterator	ft_itr = ft_vec.begin();

	EXPECT_EQ(*std_itr, *ft_itr);
	EXPECT_EQ(std_itr[1], ft_itr[1]);
	EXPECT_EQ(std_itr->length(), ft_itr->length());
}
