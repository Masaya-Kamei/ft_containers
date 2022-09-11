#include <gtest/gtest.h>
#include <algorithm>
#include "algorithm.hpp"

class AlgorithmTest : public ::testing::Test
{
	protected:
		static bool	MyNotEqual(int i, int j)
		{
			return (i != j);
		}

		static bool	MyGreater(int i, int j)
		{
			return (i > j);
		}
};

TEST_F(AlgorithmTest, EqualTest)
{
	int		n[]		=	{10, 20,  30, 40, 50};
	int		small[] =	{10, 2,   30, 40, 50};
	int		large[] =	{10, 200, 30, 40, 50};
	int		more[]	=	{10, 20,  30, 40, 50, 60, 70, 80};
	// int		less[]	=	{10, 20,  30};

	EXPECT_EQ(std::equal(n, n + 5, n),		ft::equal(n, n + 5, n));
	EXPECT_EQ(std::equal(n, n + 5, small),	ft::equal(n, n + 5, small));
	EXPECT_EQ(std::equal(n, n + 5, large),	ft::equal(n, n + 5, large));
	EXPECT_EQ(std::equal(n, n + 5, more),	ft::equal(n, n + 5, more));
	// EXPECT_EQ(std::equal(n, n + 5, less),	ft::equal(n, n + 5, less));
}

TEST_F(AlgorithmTest, EqualFuncTest)
{
	int		n[]		=	{10, 20,  30, 40, 50};
	int		small[] =	{10, 2,   30, 40, 50};
	int		large[] =	{10, 200, 30, 40, 50};
	int		more[]	=	{10, 20,  30, 40, 50, 60, 70, 80};
	// int		less[]	=	{10, 20,  30};

	EXPECT_EQ(std::equal(n, n + 5, n, MyNotEqual),		ft::equal(n, n + 5, n, MyNotEqual));
	EXPECT_EQ(std::equal(n, n + 5, small, MyNotEqual),	ft::equal(n, n + 5, small, MyNotEqual));
	EXPECT_EQ(std::equal(n, n + 5, large, MyNotEqual),	ft::equal(n, n + 5, large, MyNotEqual));
	EXPECT_EQ(std::equal(n, n + 5, more, MyNotEqual),	ft::equal(n, n + 5, more, MyNotEqual));
	// EXPECT_EQ(std::equal(n, n + 5, less, MyNotEqual),	ft::equal(n, n + 5, less, MyNotEqual));
}

TEST_F(AlgorithmTest, LexicographicalCompareTest)
{
	int		n[]	=	{10, 20,  30, 40, 50};
	int		s[] =	{10, 2,   30, 40, 50};
	int		l[] =	{10, 200, 30, 40, 50};

	EXPECT_EQ(std::lexicographical_compare(n, n + 0, n, n + 0),
			   ft::lexicographical_compare(n, n + 0, n, n + 0));
	EXPECT_EQ(std::lexicographical_compare(n, n + 0, n, n + 1),
			   ft::lexicographical_compare(n, n + 0, n, n + 1));

	EXPECT_EQ(std::lexicographical_compare(n, n + 3, n, n + 0),
			   ft::lexicographical_compare(n, n + 3, n, n + 0));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, n, n + 1),
			   ft::lexicographical_compare(n, n + 3, n, n + 1));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, n, n + 3),
			   ft::lexicographical_compare(n, n + 3, n, n + 3));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, n, n + 5),
			   ft::lexicographical_compare(n, n + 3, n, n + 5));

	EXPECT_EQ(std::lexicographical_compare(n, n + 3, s, s + 0),
			   ft::lexicographical_compare(n, n + 3, s, s + 0));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, s, s + 1),
			   ft::lexicographical_compare(n, n + 3, s, s + 1));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, s, s + 3),
			   ft::lexicographical_compare(n, n + 3, s, s + 3));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, s, s + 5),
			   ft::lexicographical_compare(n, n + 3, s, s + 5));

	EXPECT_EQ(std::lexicographical_compare(n, n + 3, l, l + 0),
			   ft::lexicographical_compare(n, n + 3, l, l + 0));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, l, l + 1),
			   ft::lexicographical_compare(n, n + 3, l, l + 1));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, l, l + 3),
			   ft::lexicographical_compare(n, n + 3, l, l + 3));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, l, l + 5),
			   ft::lexicographical_compare(n, n + 3, l, l + 5));
}

TEST_F(AlgorithmTest, LexicographicalCompareFuncTest)
{
	int		n[]	=	{10, 20,  30, 40, 50};
	int		s[] =	{10, 2,   30, 40, 50};
	int		l[] =	{10, 200, 30, 40, 50};

	EXPECT_EQ(std::lexicographical_compare(n, n + 0, n, n + 0, MyGreater),
			   ft::lexicographical_compare(n, n + 0, n, n + 0, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n, n + 0, n, n + 1, MyGreater),
			   ft::lexicographical_compare(n, n + 0, n, n + 1, MyGreater));

	EXPECT_EQ(std::lexicographical_compare(n, n + 3, n, n + 0, MyGreater),
			   ft::lexicographical_compare(n, n + 3, n, n + 0, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, n, n + 1, MyGreater),
			   ft::lexicographical_compare(n, n + 3, n, n + 1, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, n, n + 3, MyGreater),
			   ft::lexicographical_compare(n, n + 3, n, n + 3, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, n, n + 5, MyGreater),
			   ft::lexicographical_compare(n, n + 3, n, n + 5, MyGreater));

	EXPECT_EQ(std::lexicographical_compare(n, n + 3, s, s + 0, MyGreater),
			   ft::lexicographical_compare(n, n + 3, s, s + 0, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, s, s + 1, MyGreater),
			   ft::lexicographical_compare(n, n + 3, s, s + 1, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, s, s + 3, MyGreater),
			   ft::lexicographical_compare(n, n + 3, s, s + 3, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, s, s + 5, MyGreater),
			   ft::lexicographical_compare(n, n + 3, s, s + 5, MyGreater));

	EXPECT_EQ(std::lexicographical_compare(n, n + 3, l, l + 0, MyGreater),
			   ft::lexicographical_compare(n, n + 3, l, l + 0, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, l, l + 1, MyGreater),
			   ft::lexicographical_compare(n, n + 3, l, l + 1, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, l, l + 3, MyGreater),
			   ft::lexicographical_compare(n, n + 3, l, l + 3, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n, n + 3, l, l + 5, MyGreater),
			   ft::lexicographical_compare(n, n + 3, l, l + 5, MyGreater));
}
