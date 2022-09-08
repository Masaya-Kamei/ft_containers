#include <gtest/gtest.h>
#include "vector.hpp"

class RandomAccessIteratorTest : public ::testing::Test
{
};

TEST_F(RandomAccessIteratorTest, ConstructorTest)
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

TEST_F(RandomAccessIteratorTest, BothSidesOpeTest1)
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

TEST_F(RandomAccessIteratorTest, BothSidesOpeTest2)
{
	int a[3] = {1, 2, 3};
	ft::vector<const int>	vec(a, a + 3);
	// ft::vector<int>::iterator				itr1 = vec.begin();
	ft::vector<int>::const_iterator			itr2 = vec.begin();
	ft::vector<const int>::iterator			itr3 = vec.begin();
	ft::vector<const int>::const_iterator	itr4 = vec.begin();
	// EXPECT_EQ(itr1 == itr2, true);	EXPECT_EQ(itr2 == itr1, true);
	EXPECT_EQ(itr2 == itr3, true);	EXPECT_EQ(itr3 == itr2, true);
	EXPECT_EQ(itr3 == itr4, true);	EXPECT_EQ(itr4 == itr3, true);
	// EXPECT_EQ(itr1 + 1, ++itr1);	EXPECT_EQ(1 + itr1, ++itr1);
	EXPECT_EQ(itr2 + 1, ++itr2);	EXPECT_EQ(1 + itr2, ++itr2);
	EXPECT_EQ(itr3 + 1, ++itr3);	EXPECT_EQ(1 + itr3, ++itr3);
	EXPECT_EQ(itr4 + 1, ++itr4);	EXPECT_EQ(1 + itr4, ++itr4);
	// EXPECT_EQ(itr1 - 1, --itr1);
	EXPECT_EQ(itr2 - 1, --itr2);
	EXPECT_EQ(itr3 - 1, --itr3);
	EXPECT_EQ(itr4 - 1, --itr4);
	// EXPECT_EQ(itr1 - itr2, 0);		EXPECT_EQ(itr2 - itr1, 0);
	EXPECT_EQ(itr2 - itr3, 0);		EXPECT_EQ(itr3 - itr2, 0);
	EXPECT_EQ(itr3 - itr4, 0);		EXPECT_EQ(itr4 - itr3, 0);
}

TEST_F(RandomAccessIteratorTest, BothSidesOpeTest3)
{
	int a[3] = {1, 2, 3};
	const ft::vector<int>	vec(a, a + 3);
	// ft::vector<int>::iterator				itr1 = vec.begin();
	ft::vector<int>::const_iterator			itr2 = vec.begin();
	ft::vector<const int>::iterator			itr3 = vec.begin();
	ft::vector<const int>::const_iterator	itr4 = vec.begin();
	// EXPECT_EQ(itr1 == itr2, true);	EXPECT_EQ(itr2 == itr1, true);
	EXPECT_EQ(itr2 == itr3, true);	EXPECT_EQ(itr3 == itr2, true);
	EXPECT_EQ(itr3 == itr4, true);	EXPECT_EQ(itr4 == itr3, true);
	// EXPECT_EQ(itr1 + 1, ++itr1);	EXPECT_EQ(1 + itr1, ++itr1);
	EXPECT_EQ(itr2 + 1, ++itr2);	EXPECT_EQ(1 + itr2, ++itr2);
	EXPECT_EQ(itr3 + 1, ++itr3);	EXPECT_EQ(1 + itr3, ++itr3);
	EXPECT_EQ(itr4 + 1, ++itr4);	EXPECT_EQ(1 + itr4, ++itr4);
	// EXPECT_EQ(itr1 - 1, --itr1);
	EXPECT_EQ(itr2 - 1, --itr2);
	EXPECT_EQ(itr3 - 1, --itr3);
	EXPECT_EQ(itr4 - 1, --itr4);
	// EXPECT_EQ(itr1 - itr2, 0);		EXPECT_EQ(itr2 - itr1, 0);
	EXPECT_EQ(itr2 - itr3, 0);		EXPECT_EQ(itr3 - itr2, 0);
	EXPECT_EQ(itr3 - itr4, 0);		EXPECT_EQ(itr4 - itr3, 0);
}

// TEST_F(RandomAccessIteratorTest, CompareIterRevIterTest)
// {
	// int a[3] = {1, 2, 3};
	// std::vector<int>	vec(a, a + 3);s
	// std::vector<int>::iterator			itr1 = vec.begin();
	// std::vector<int>::reverse_iterator	itr2 = vec.rbegin();
	// EXPECT_EQ(itr1 == itr2, false);
// }

TEST_F(RandomAccessIteratorTest, AddSubOpeTest)
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
	EXPECT_EQ(std_itr - std_begin, ft_itr - ft_begin);

	EXPECT_EQ(*std_itr, *ft_itr);
	EXPECT_EQ(std_itr, std_begin);
	EXPECT_EQ(ft_itr, ft_begin);
}

TEST_F(RandomAccessIteratorTest, RelationalOpeTest)
{
	int		a[3] = {1, 2, 3};
	ft::vector<int>				vec(a, a + 3);
	ft::vector<int>::iterator	first_itr = vec.begin();
	ft::vector<int>::iterator	second_itr = first_itr + 1;

	EXPECT_EQ(first_itr == second_itr, false);
	EXPECT_EQ(first_itr != second_itr, true);
	EXPECT_EQ(first_itr < second_itr, true);
	EXPECT_EQ(first_itr <= second_itr, true);
	EXPECT_EQ(first_itr > second_itr, false);
	EXPECT_EQ(first_itr >= second_itr, false);
}

TEST_F(RandomAccessIteratorTest, OthersOpeTest)
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
