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
			std_vec_.assign(nums, nums + 3);
			ft_vec_.assign(nums, nums + 3);
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

		static const int	nums[3];
		std::vector<int>	std_vec_;
		ft::vector<int>		ft_vec_;
};

const int VectorTest::nums[3] = {1, 2, 3};

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
	std::vector<int>	std_vec(5, 5);
	ft::vector<int>		ft_vec(5, 5);
	CompareSizeCapElem(std_vec, ft_vec);
}

TEST_F(VectorTest, FillConstructorOnlySizeTest)
{
	std::vector<int>	std_vec(5);
	ft::vector<int>		ft_vec(5);
	CompareSizeCapElem(std_vec, ft_vec);
}

TEST_F(VectorTest, FillConstructorZeroSizeTest)
{
	std::vector<int>	std_vec(0);
	ft::vector<int>		ft_vec(0);
	CompareSizeCapElem(std_vec, ft_vec);
}

TEST_F(VectorTest, FillConstructorInvalidSizeTest)
{
	EXPECT_THROW(std::vector<int> std_vec(-1), std::length_error);
	EXPECT_THROW(ft::vector<int> ft_vec(-1), std::length_error);
}

TEST_F(VectorTest, RangeConstructorTest)
{
	std::vector<int>	std_vec(nums, nums + 3);
	ft::vector<int>		ft_vec(nums, nums + 3);
	CompareSizeCapElem(std_vec, ft_vec);
	EXPECT_NE(&(*nums), &(*ft_vec.begin()));
}

TEST_F(VectorTest, RangeConstructorInvalidTest)
{
	EXPECT_THROW(std::vector<int> std_vec(nums, nums - 1), std::length_error);
	EXPECT_THROW(ft::vector<int> ft_vec(nums, nums - 1), std::length_error);
}

TEST_F(VectorTest, RangeConstructorZeroTest)
{
	std::vector<int>	std_vec(nums, nums);
	ft::vector<int>		ft_vec(nums, nums);
	CompareSizeCapElem(std_vec, ft_vec);
}

TEST_F(VectorTest, CopyConstructorTest)
{
	std::vector<int>	std_vec(nums, nums + 3);
	ft::vector<int>		ft_vec(nums, nums + 3);
	std::vector<int>	std_vec_copy(std_vec);
	ft::vector<int>		ft_vec_copy(ft_vec);
	CompareSizeCapElem(std_vec_copy, ft_vec_copy);
	EXPECT_NE(ft_vec.begin(), ft_vec_copy.begin());
}

TEST_F(VectorTest, AssignFillTest)
{
	std::vector<int>	std_vec(nums, nums + 2);
	ft::vector<int>		ft_vec(nums, nums + 2);

	std_vec.assign(3, 42);
	ft_vec.assign(3, 42);
	CompareSizeCapElem(std_vec, ft_vec);
	std_vec.assign(1, 42);
	ft_vec.assign(1, 42);
	CompareSizeCapElem(std_vec, ft_vec);
	std_vec.assign(2, 42);
	ft_vec.assign(2, 42);
	CompareSizeCapElem(std_vec, ft_vec);
	std_vec.assign(0, 42);
	ft_vec.assign(0, 42);
	CompareSizeCapElem(std_vec, ft_vec);
	EXPECT_THROW(std_vec.assign(-1, 42), std::length_error);
	EXPECT_THROW(ft_vec.assign(-1, 42), std::length_error);
}

TEST_F(VectorTest, AssignRangeTest)
{
	std::vector<int>	std_vec(nums, nums + 2);
	ft::vector<int>		ft_vec(nums, nums + 2);

	std_vec.assign(nums, nums + 3);
	ft_vec.assign(nums, nums + 3);
	CompareSizeCapElem(std_vec, ft_vec);
	std_vec.assign(nums, nums + 1);
	ft_vec.assign(nums, nums + 1);
	CompareSizeCapElem(std_vec, ft_vec);
	std_vec.assign(nums, nums + 2);
	ft_vec.assign(nums, nums + 2);
	CompareSizeCapElem(std_vec, ft_vec);
	std_vec.assign(nums, nums);
	ft_vec.assign(nums, nums);
	CompareSizeCapElem(std_vec, ft_vec);
	EXPECT_THROW(std_vec.assign(nums, nums - 1), std::length_error);
	EXPECT_THROW(ft_vec.assign(nums, nums - 1), std::length_error);
}

TEST_F(VectorTest, OpeEqualTest)
{
	std::vector<int>	std_vec_copy;
	std_vec_copy = std_vec_;
	ft::vector<int>	ft_vec_copy;
	ft_vec_copy = ft_vec_;

	CompareSizeCapElem(std_vec_copy, ft_vec_copy);
	EXPECT_NE(ft_vec_.begin(), ft_vec_copy.begin());
}

TEST_F(VectorTest, ClearTest)
{
	std_vec_.clear();
	ft_vec_.clear();
	CompareSizeCapElem(std_vec_, ft_vec_);
}
