#include <gtest/gtest.h>
#include "vector.hpp"

class ReverseIteratorTest : public ::testing::Test
{
};

TEST_F(ReverseIteratorTest, ConstructorTest)
{
	int 	a[3] = {1, 2, 3};
	std::vector<int>					std_vec(a, a + 3);
	ft::vector<int>						ft_vec(a, a + 3);
	std::vector<int>::reverse_iterator	std_ritr	= std_vec.rbegin();
	ft::vector<int>::reverse_iterator	ft_ritr		= ft_vec.rbegin();
	std::vector<int>::reverse_iterator	std_rbegin;
	std_rbegin = std_vec.rbegin();
	ft::vector<int>::reverse_iterator	ft_rbegin;
	ft_rbegin = ft_vec.rbegin();

	EXPECT_EQ(*std_ritr, *ft_ritr);
	EXPECT_EQ(*std_rbegin, *ft_rbegin);
	EXPECT_EQ(std_ritr, std_rbegin);
	EXPECT_EQ(ft_ritr, ft_rbegin);
}

TEST_F(ReverseIteratorTest, CopyConstructorConstTest)
{
	int 	a[3] = {1, 2, 3};
	ft::vector<int>				vec(a, a + 3);
	ft::vector<const int>		vec_const(a, a + 3);
	const ft::vector<int>		const_vec(a, a + 3);

	ft::vector<int>::reverse_iterator		ritr1(vec.rbegin());

	ft::vector<const int>::reverse_iterator	ritr_const1(vec.rbegin());
	ft::vector<const int>::reverse_iterator	ritr_const2(vec_const.rbegin());
	ft::vector<const int>::reverse_iterator	ritr_const3(const_vec.rbegin());

	ft::vector<int>::const_reverse_iterator	const_ritr1(vec.rbegin());
	ft::vector<int>::const_reverse_iterator	const_ritr2(vec_const.rbegin());
	ft::vector<int>::const_reverse_iterator	const_ritr3(const_vec.rbegin());
}

TEST_F(ReverseIteratorTest, OpeEqualConstTest)
{
	int 	a[3] = {1, 2, 3};
	ft::vector<int>				vec(a, a + 3);
	ft::vector<const int>		vec_const(a, a + 3);
	const ft::vector<int>		const_vec(a, a + 3);

	ft::vector<int>::reverse_iterator		ritr1(vec.rbegin());

	ft::vector<const int>::reverse_iterator	ritr_const1; ritr_const1 = vec.rbegin();
	ft::vector<const int>::reverse_iterator	ritr_const2; ritr_const2 = vec_const.rbegin();
	ft::vector<const int>::reverse_iterator	ritr_const3; ritr_const3 = const_vec.rbegin();

	ft::vector<int>::const_reverse_iterator	const_ritr1; const_ritr1 = vec.rbegin();
	ft::vector<int>::const_reverse_iterator	const_ritr2; const_ritr2 = vec_const.rbegin();
	ft::vector<int>::const_reverse_iterator	const_ritr3; const_ritr3 = const_vec.rbegin();
}

TEST_F(ReverseIteratorTest, OpeBothSidesTest)
{
	int a[3] = {1, 2, 3};
	ft::vector<int>	vec(a, a + 3);
	ft::vector<int>::reverse_iterator				ritr1 = vec.rbegin();
	ft::vector<int>::const_reverse_iterator			ritr2 = vec.rbegin();
	ft::vector<const int>::reverse_iterator			ritr3 = vec.rbegin();
	ft::vector<const int>::const_reverse_iterator	ritr4 = vec.rbegin();
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
	int		a[3] = {1, 2, 3};
	std::vector<int>					std_vec(a, a + 3);
	ft::vector<int>						ft_vec(a, a + 3);
	std::vector<int>::reverse_iterator	std_ritr	= std_vec.rbegin();
	ft::vector<int>::reverse_iterator	ft_ritr = ft_vec.rbegin();
	std::vector<int>::reverse_iterator	std_rbegin = std_vec.rbegin();
	ft::vector<int>::reverse_iterator	ft_rbegin = ft_vec.rbegin();

	EXPECT_EQ(*(std_ritr++), *(ft_ritr++));
	EXPECT_EQ(*(++std_ritr), *(++ft_ritr));
	EXPECT_EQ(*(std_ritr--), *(ft_ritr--));
	EXPECT_EQ(*(--std_ritr), *(--ft_ritr));

	EXPECT_EQ(*(std_ritr += 1), *(ft_ritr += 1));
	EXPECT_EQ(*(std_ritr -= 1), *(ft_ritr -= 1));
	EXPECT_EQ(*(std_ritr + 1), *(ft_ritr + 1));
	EXPECT_EQ(*(std_ritr - 1 + 1), *(ft_ritr - 1 + 1));
	EXPECT_EQ(*(1 + std_ritr), *(1 + ft_ritr));
	EXPECT_EQ((std_ritr + 1) - std_rbegin, (ft_ritr + 1) - ft_rbegin);

	EXPECT_EQ(*std_ritr, *ft_ritr);
	EXPECT_EQ(std_ritr, std_rbegin);
	EXPECT_EQ(ft_ritr, ft_rbegin);
}

TEST_F(ReverseIteratorTest, OpeRelationalTest)
{
	int		a[3] = {1, 2, 3};
	std::vector<int>			std_vec(a, a + 3);
	ft::vector<int>				ft_vec(a, a + 3);
	std::vector<int>::iterator	std_first_ritr = std_vec.begin();
	ft::vector<int>::iterator	ft_first_ritr = ft_vec.begin();
	std::vector<int>::iterator	std_second_ritr = std_first_ritr + 1;
	ft::vector<int>::iterator	ft_second_ritr = ft_first_ritr + 1;

	EXPECT_EQ(std_first_ritr == std_second_ritr,	ft_first_ritr == ft_second_ritr);
	EXPECT_EQ(std_first_ritr != std_second_ritr,	ft_first_ritr != ft_second_ritr);
	EXPECT_EQ(std_first_ritr < std_second_ritr,		ft_first_ritr < ft_second_ritr);
	EXPECT_EQ(std_first_ritr <= std_second_ritr,	ft_first_ritr <= ft_second_ritr);
	EXPECT_EQ(std_first_ritr > std_second_ritr,		ft_first_ritr > ft_second_ritr);
	EXPECT_EQ(std_first_ritr >= std_second_ritr,	ft_first_ritr >= ft_second_ritr);
}

TEST_F(ReverseIteratorTest, OpeOthersTest)
{
	std::string s[3] = {"a", "b", "c"};
	std::vector<std::string>	std_vec(s, s + 3);
	ft::vector<std::string>		ft_vec(s, s + 3);
	std::vector<std::string>::reverse_iterator	std_ritr	= std_vec.rbegin();
	ft::vector<std::string>::reverse_iterator	ft_ritr		= ft_vec.rbegin();

	EXPECT_EQ(*std_ritr, *ft_ritr);
	EXPECT_EQ(std_ritr[1], ft_ritr[1]);
	EXPECT_EQ(std_ritr->length(), ft_ritr->length());
}
