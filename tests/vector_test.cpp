#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "vector.hpp"

class VectorTest : public ::testing::Test
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
		}
		virtual void TearDown()
		{
		}

		template <class T>
		void CompareSizeCapElem(const std::vector<T>& std_vec, const ft::vector<T>& ft_vec)
		{
			typename std::vector<T>::const_iterator	std_itr = std_vec.begin();
			typename ft::vector<T>::const_iterator	ft_itr = ft_vec.begin();
			typename std::vector<T>::const_iterator	std_end = std_vec.end();

			EXPECT_EQ(std_vec.size(), ft_vec.size());
			EXPECT_EQ(std_vec.max_size(), ft_vec.max_size());
			EXPECT_EQ(std_vec.capacity(), ft_vec.capacity());
			for (; std_itr < std_end; std_itr++, ft_itr++)
				EXPECT_EQ(*std_itr, *ft_itr);
		}
};

TEST_F(VectorTest, DefaultConstructorIntTest)
{
	std::vector<int>	std_vec;
	ft::vector<int>		ft_vec;
	CompareSizeCapElem(std_vec, ft_vec);
}

TEST_F(VectorTest, DefaultConstructorStringTest)
{
	std::vector<std::string>	std_vec;
	ft::vector<std::string>		ft_vec;
	CompareSizeCapElem(std_vec, ft_vec);
}

TEST_F(VectorTest, FillConstructorTest)
{
	std::vector<int> std_vec(5, 5);
	ft::vector<int> ft_vec(5, 5);
	CompareSizeCapElem(std_vec, ft_vec);
}

TEST_F(VectorTest, FillConstructorOnlySizeTest)
{
	std::vector<int> std_vec(5);
	ft::vector<int> ft_vec(5);
	CompareSizeCapElem(std_vec, ft_vec);
}

TEST_F(VectorTest, FillConstructorZeroSizeTest)
{
	std::vector<int> std_vec(0);
	ft::vector<int> ft_vec(0);
	CompareSizeCapElem(std_vec, ft_vec);
}

TEST_F(VectorTest, FillConstructorInvalidSizeTest)
{
	EXPECT_THROW(std::vector<int> std_vec(-1), std::length_error);
	EXPECT_THROW(ft::vector<int> ft_vec(-1), std::length_error);
}

TEST_F(VectorTest, RangeConstructorTest)
{
	int a[3] = {1, 2, 3};
	std::vector<int> std_vec(a, a + 3);
	ft::vector<int> ft_vec(a, a + 3);
	CompareSizeCapElem(std_vec, ft_vec);
}

TEST_F(VectorTest, RangeConstructorInvalidTest)
{
	int a[3] = {1, 2, 3};
	EXPECT_THROW(std::vector<int> std_vec(a, a - 1), std::length_error);
	EXPECT_THROW(ft::vector<int> ft_vec(a, a - 1), std::length_error);
}

TEST_F(VectorTest, RangeConstructorZeroTest)
{
	int a[3] = {1, 2, 3};
	std::vector<int> std_vec(a, a);
	ft::vector<int> ft_vec(a, a);
	CompareSizeCapElem(std_vec, ft_vec);
}
