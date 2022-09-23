#ifndef TESTLIB
# include <gtest/gtest.h>
#else
# include "testlib.hpp"
#endif
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

		static const int n_[];
		static const int small_[];
		static const int large_[];
		static const int more_[];
		static const int less_[];
};

const int	AlgorithmTest::n_[]		=	{10, 20,  30, 40, 50};
const int	AlgorithmTest::small_[] =	{10, 2,   30, 40, 50};
const int	AlgorithmTest::large_[] =	{10, 200, 30, 40, 50};
const int	AlgorithmTest::more_[]	=	{10, 20,  30, 40, 50, 60, 70, 80};
const int	AlgorithmTest::less_[]	=	{10, 20,  30};

TEST_F(AlgorithmTest, EqualTest)
{
	EXPECT_EQ(std::equal(n_, n_ + 5, n_),		ft::equal(n_, n_ + 5, n_));
	EXPECT_EQ(std::equal(n_, n_ + 5, small_),	ft::equal(n_, n_ + 5, small_));
	EXPECT_EQ(std::equal(n_, n_ + 5, large_),	ft::equal(n_, n_ + 5, large_));
	EXPECT_EQ(std::equal(n_, n_ + 5, more_),	ft::equal(n_, n_ + 5, more_));
	// EXPECT_EQ(std::equal(n_, n_ + 5, less_),	ft::equal(n_, n_ + 5, less_));
}

TEST_F(AlgorithmTest, EqualFuncTest)
{
	EXPECT_EQ(std::equal(n_, n_ + 5, n_,	 MyNotEqual),	ft::equal(n_, n_ + 5, n_,	  MyNotEqual));
	EXPECT_EQ(std::equal(n_, n_ + 5, small_, MyNotEqual),	ft::equal(n_, n_ + 5, small_, MyNotEqual));
	EXPECT_EQ(std::equal(n_, n_ + 5, large_, MyNotEqual),	ft::equal(n_, n_ + 5, large_, MyNotEqual));
	EXPECT_EQ(std::equal(n_, n_ + 5, more_,  MyNotEqual),	ft::equal(n_, n_ + 5, more_,  MyNotEqual));
	// EXPECT_EQ(std::equal(n_, n_ + 5, less_,  MyNotEqual),	ft::equal(n_, n_ + 5, less_,  MyNotEqual));
}

TEST_F(AlgorithmTest, LexicographicalCompareTest)
{
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 0, n_, n_ + 0),
			   ft::lexicographical_compare(n_, n_ + 0, n_, n_ + 0));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 0, n_, n_ + 1),
			   ft::lexicographical_compare(n_, n_ + 0, n_, n_ + 1));

	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, n_, n_ + 0),
			   ft::lexicographical_compare(n_, n_ + 3, n_, n_ + 0));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, n_, n_ + 1),
			   ft::lexicographical_compare(n_, n_ + 3, n_, n_ + 1));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, n_, n_ + 3),
			   ft::lexicographical_compare(n_, n_ + 3, n_, n_ + 3));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, n_, n_ + 5),
			   ft::lexicographical_compare(n_, n_ + 3, n_, n_ + 5));

	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, small_, small_ + 0),
			   ft::lexicographical_compare(n_, n_ + 3, small_, small_ + 0));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, small_, small_ + 1),
			   ft::lexicographical_compare(n_, n_ + 3, small_, small_ + 1));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, small_, small_ + 3),
			   ft::lexicographical_compare(n_, n_ + 3, small_, small_ + 3));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, small_, small_ + 5),
			   ft::lexicographical_compare(n_, n_ + 3, small_, small_ + 5));

	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, large_, large_ + 0),
			   ft::lexicographical_compare(n_, n_ + 3, large_, large_ + 0));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, large_, large_ + 1),
			   ft::lexicographical_compare(n_, n_ + 3, large_, large_ + 1));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, large_, large_ + 3),
			   ft::lexicographical_compare(n_, n_ + 3, large_, large_ + 3));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, large_, large_ + 5),
			   ft::lexicographical_compare(n_, n_ + 3, large_, large_ + 5));
}

TEST_F(AlgorithmTest, LexicographicalCompareFuncTest)
{
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 0, n_, n_ + 0, MyGreater),
			   ft::lexicographical_compare(n_, n_ + 0, n_, n_ + 0, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 0, n_, n_ + 1, MyGreater),
			   ft::lexicographical_compare(n_, n_ + 0, n_, n_ + 1, MyGreater));

	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, n_, n_ + 0, MyGreater),
			   ft::lexicographical_compare(n_, n_ + 3, n_, n_ + 0, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, n_, n_ + 1, MyGreater),
			   ft::lexicographical_compare(n_, n_ + 3, n_, n_ + 1, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, n_, n_ + 3, MyGreater),
			   ft::lexicographical_compare(n_, n_ + 3, n_, n_ + 3, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, n_, n_ + 5, MyGreater),
			   ft::lexicographical_compare(n_, n_ + 3, n_, n_ + 5, MyGreater));

	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, small_, small_ + 0, MyGreater),
			   ft::lexicographical_compare(n_, n_ + 3, small_, small_ + 0, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, small_, small_ + 1, MyGreater),
			   ft::lexicographical_compare(n_, n_ + 3, small_, small_ + 1, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, small_, small_ + 3, MyGreater),
			   ft::lexicographical_compare(n_, n_ + 3, small_, small_ + 3, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, small_, small_ + 5, MyGreater),
			   ft::lexicographical_compare(n_, n_ + 3, small_, small_ + 5, MyGreater));

	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, large_, large_ + 0, MyGreater),
			   ft::lexicographical_compare(n_, n_ + 3, large_, large_ + 0, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, large_, large_ + 1, MyGreater),
			   ft::lexicographical_compare(n_, n_ + 3, large_, large_ + 1, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, large_, large_ + 3, MyGreater),
			   ft::lexicographical_compare(n_, n_ + 3, large_, large_ + 3, MyGreater));
	EXPECT_EQ(std::lexicographical_compare(n_, n_ + 3, large_, large_ + 5, MyGreater),
			   ft::lexicographical_compare(n_, n_ + 3, large_, large_ + 5, MyGreater));
}
