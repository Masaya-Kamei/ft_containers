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
			st_vec_.assign(nums, nums + 3);
			ft_vec_.assign(nums, nums + 3);
		}
		virtual void TearDown()
		{
		}

		template <class T>
		void CompareSizeCapElem(const std::vector<T>& st_vec, const ft::vector<T>& ft_vec)
		{
			typename std::vector<T>::const_iterator	st_itr = st_vec.begin();
			typename ft::vector<T>::const_iterator	ft_itr = ft_vec.begin();
			typename std::vector<T>::const_iterator	st_end = st_vec.end();

			EXPECT_EQ(st_vec.size(),		ft_vec.size());
			EXPECT_EQ(st_vec.max_size(),	ft_vec.max_size());
			EXPECT_EQ(st_vec.capacity(),	ft_vec.capacity());
			EXPECT_EQ(st_vec.empty(),		ft_vec.empty());
			for (; st_itr < st_end; st_itr++, ft_itr++)
				EXPECT_EQ(*st_itr, *ft_itr);
		}

		template <class Vector>
		void PrintVector(const Vector& vec)
		{
			typename Vector::const_iterator	itr = vec.begin();
			typename Vector::const_iterator	end = vec.end();

			std::cout << "size:     "	<< vec.size() << std::endl;
			std::cout << "max_size: "	<< vec.max_size() << std::endl;
			std::cout << "capacity: "	<< vec.capacity() << std::endl;
			std::cout << "empty:    "	<< vec.empty() << std::endl;
			std::cout << "elem:     [";
			for (; itr < end; itr++)
				std::cout << *itr << ", ";
			std::cout << "]" << std::endl;
		}

		static const int	nums[3];
		std::vector<int>	st_vec_;
		ft::vector<int>		ft_vec_;
};

const int VectorTest::nums[3] = {1, 2, 3};

TEST_F(VectorTest, DefaultConstructorIntTest)
{
	std::vector<int>	st_vec;
	ft::vector<int>		ft_vec;
	CompareSizeCapElem(st_vec, ft_vec);
}

TEST_F(VectorTest, DefaultConstructorStringTest)
{
	std::vector<std::string>	st_vec;
	ft::vector<std::string>		ft_vec;
	CompareSizeCapElem(st_vec, ft_vec);
}

TEST_F(VectorTest, FillConstructorTest)
{
	std::vector<int>	st_vec(5, 5);
	ft::vector<int>		ft_vec(5, 5);
	CompareSizeCapElem(st_vec, ft_vec);
}

TEST_F(VectorTest, FillConstructorOnlySizeTest)
{
	std::vector<int>	st_vec(5);
	ft::vector<int>		ft_vec(5);
	CompareSizeCapElem(st_vec, ft_vec);
}

TEST_F(VectorTest, FillConstructorZeroSizeTest)
{
	std::vector<int>	st_vec(0);
	ft::vector<int>		ft_vec(0);
	CompareSizeCapElem(st_vec, ft_vec);
}

TEST_F(VectorTest, FillConstructorInvalidSizeTest)
{
	EXPECT_THROW(std::vector<int> st_vec(-1),	std::length_error);
	EXPECT_THROW(ft::vector<int> ft_vec(-1),	std::length_error);
}

TEST_F(VectorTest, RangeConstructorTest)
{
	std::vector<int>	st_vec(nums, nums + 3);
	ft::vector<int>		ft_vec(nums, nums + 3);
	CompareSizeCapElem(st_vec, ft_vec);
	EXPECT_NE(&(*nums), &(*ft_vec.begin()));
}

TEST_F(VectorTest, RangeConstructorInvalidTest)
{
	EXPECT_THROW(std::vector<int> st_vec(nums, nums - 1),	std::length_error);
	EXPECT_THROW(ft::vector<int> ft_vec(nums, nums - 1),	std::length_error);
}

TEST_F(VectorTest, RangeConstructorZeroTest)
{
	std::vector<int>	st_vec(nums, nums);
	ft::vector<int>		ft_vec(nums, nums);
	CompareSizeCapElem(st_vec, ft_vec);
}

TEST_F(VectorTest, CopyConstructorTest)
{
	std::vector<int>	st_vec(nums, nums + 3);
	ft::vector<int>		ft_vec(nums, nums + 3);
	std::vector<int>	st_vec_copy(st_vec);
	ft::vector<int>		ft_vec_copy(ft_vec);
	CompareSizeCapElem(st_vec_copy, ft_vec_copy);
	EXPECT_NE(ft_vec.begin(), ft_vec_copy.begin());
}

TEST_F(VectorTest, AssignFillTest)
{
	std::vector<int>	st_vec(nums, nums + 2);
	ft::vector<int>		ft_vec(nums, nums + 2);

	st_vec.assign(3, 42);
	ft_vec.assign(3, 42);
	CompareSizeCapElem(st_vec, ft_vec);
	st_vec.assign(1, 42);
	ft_vec.assign(1, 42);
	CompareSizeCapElem(st_vec, ft_vec);
	st_vec.assign(2, 42);
	ft_vec.assign(2, 42);
	CompareSizeCapElem(st_vec, ft_vec);
	st_vec.assign(0, 42);
	ft_vec.assign(0, 42);
	CompareSizeCapElem(st_vec, ft_vec);
	EXPECT_THROW(st_vec.assign(-1, 42), std::length_error);
	EXPECT_THROW(ft_vec.assign(-1, 42), std::length_error);
	CompareSizeCapElem(st_vec, ft_vec);
}

TEST_F(VectorTest, AssignRangeTest)
{
	std::vector<int>	st_vec(nums, nums + 2);
	ft::vector<int>		ft_vec(nums, nums + 2);

	st_vec.assign(nums, nums + 3);
	ft_vec.assign(nums, nums + 3);
	CompareSizeCapElem(st_vec, ft_vec);
	st_vec.assign(nums, nums + 1);
	ft_vec.assign(nums, nums + 1);
	CompareSizeCapElem(st_vec, ft_vec);
	st_vec.assign(nums, nums + 2);
	ft_vec.assign(nums, nums + 2);
	CompareSizeCapElem(st_vec, ft_vec);
	st_vec.assign(nums, nums);
	ft_vec.assign(nums, nums);
	CompareSizeCapElem(st_vec, ft_vec);
	EXPECT_THROW(st_vec.assign(nums, nums - 1), std::length_error);
	EXPECT_THROW(ft_vec.assign(nums, nums - 1), std::length_error);
	CompareSizeCapElem(st_vec, ft_vec);
}

TEST_F(VectorTest, OpeEqualTest)
{
	std::vector<int>	st_vec_copy;
	st_vec_copy = st_vec_;
	ft::vector<int>	ft_vec_copy;
	ft_vec_copy = ft_vec_;

	CompareSizeCapElem(st_vec_copy, ft_vec_copy);
	EXPECT_NE(ft_vec_.begin(), ft_vec_copy.begin());
}

TEST_F(VectorTest, OpeBracketsTest)
{
	EXPECT_EQ(st_vec_[0], ft_vec_[0]);
	EXPECT_EQ(st_vec_[1], ft_vec_[1]);
	EXPECT_EQ(st_vec_[2], ft_vec_[2]);

	const std::vector<int>	st_const_vec(st_vec_);
	const ft::vector<int>	ft_const_vec(ft_vec_);
	EXPECT_EQ(st_const_vec[0], ft_const_vec[0]);
	EXPECT_EQ(st_const_vec[1], ft_const_vec[1]);
	EXPECT_EQ(st_const_vec[2], ft_const_vec[2]);
}

TEST_F(VectorTest, AtTest)
{
	EXPECT_EQ(st_vec_.at(0), ft_vec_.at(0));
	EXPECT_EQ(st_vec_.at(1), ft_vec_.at(1));
	EXPECT_EQ(st_vec_.at(2), ft_vec_.at(2));
	EXPECT_THROW(st_vec_.at(3), std::out_of_range);
	EXPECT_THROW(ft_vec_.at(3), std::out_of_range);

	const std::vector<int>	st_const_vec(st_vec_);
	const ft::vector<int>	ft_const_vec(ft_vec_);
	EXPECT_EQ(st_const_vec.at(0), ft_const_vec.at(0));
	EXPECT_EQ(st_const_vec.at(1), ft_const_vec.at(1));
	EXPECT_EQ(st_const_vec.at(2), ft_const_vec.at(2));
	EXPECT_THROW(st_const_vec.at(3), std::out_of_range);
	EXPECT_THROW(ft_const_vec.at(3), std::out_of_range);
}

TEST_F(VectorTest, FrontTest)
{
	EXPECT_EQ(st_vec_.front(), ft_vec_.front());

	const std::vector<int>	st_const_vec(st_vec_);
	const ft::vector<int>	ft_const_vec(ft_vec_);
	EXPECT_EQ(st_const_vec.front(), ft_const_vec.front());

	// std::vector<int>	st_zero_vec;
	// ft::vector<int>		ft_zero_vec;
	// std::cout << st_zero_vec.front() << std::endl;
	// EXPECT_EQ(st_zero_vec.front(), ft_zero_vec.front());
}

TEST_F(VectorTest, BackTest)
{
	EXPECT_EQ(st_vec_.back(), ft_vec_.back());

	const std::vector<int>	st_const_vec(st_vec_);
	const ft::vector<int>	ft_const_vec(ft_vec_);
	EXPECT_EQ(st_const_vec.back(), ft_const_vec.back());

	// std::vector<int>	st_zero_vec;
	// ft::vector<int>		ft_zero_vec;
	// std::cout << st_zero_vec.back() << std::endl;
	// EXPECT_EQ(st_zero_vec.back(), ft_zero_vec.back());
}

TEST_F(VectorTest, DataTest)
{
	EXPECT_EQ(*(st_vec_.data()), *(ft_vec_.data()));

	const std::vector<int>	st_const_vec(st_vec_);
	const ft::vector<int>	ft_const_vec(ft_vec_);
	EXPECT_EQ(*(st_const_vec.data()), *(ft_const_vec.data()));

	std::vector<int>	st_zero_vec;
	ft::vector<int>		ft_zero_vec;
	EXPECT_EQ(st_zero_vec.data(), ft_zero_vec.data());
}

TEST_F(VectorTest, ReserveTest)
{
	st_vec_.reserve(1);
	ft_vec_.reserve(1);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.reserve(3);
	ft_vec_.reserve(3);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.reserve(5);
	ft_vec_.reserve(5);
	CompareSizeCapElem(st_vec_, ft_vec_);
	EXPECT_THROW(st_vec_.reserve(-1), std::length_error);
	EXPECT_THROW(ft_vec_.reserve(-1), std::length_error);
	CompareSizeCapElem(st_vec_, ft_vec_);
}

TEST_F(VectorTest, InsertSingleTest)
{
	std::vector<int>::iterator	st_itr;
	ft::vector<int>::iterator	ft_itr;

	st_itr = st_vec_.insert(st_vec_.begin(), 42);
	ft_itr = ft_vec_.insert(ft_vec_.begin(), 42);
	EXPECT_EQ(*st_itr, *ft_itr);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_itr = st_vec_.insert(st_vec_.begin() + 1, 43);
	ft_itr = ft_vec_.insert(ft_vec_.begin() + 1, 43);
	EXPECT_EQ(*st_itr, *ft_itr);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_itr = st_vec_.insert(st_vec_.begin() + 2, 44);
	ft_itr = ft_vec_.insert(ft_vec_.begin() + 2, 44);
	EXPECT_EQ(*st_itr, *ft_itr);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_itr = st_vec_.insert(st_vec_.end(), 45);
	ft_itr = ft_vec_.insert(ft_vec_.end(), 45);
	EXPECT_EQ(*st_itr, *ft_itr);
	CompareSizeCapElem(st_vec_, ft_vec_);
}

TEST_F(VectorTest, InsertFillTest)
{
	st_vec_.insert(st_vec_.begin(), 2, 42);
	ft_vec_.insert(ft_vec_.begin(), 2, 42);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.insert(st_vec_.begin() + 1, 5, 43);
	ft_vec_.insert(ft_vec_.begin() + 1, 5, 43);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.insert(st_vec_.begin() + 2, 8, 44);
	ft_vec_.insert(ft_vec_.begin() + 2, 8, 44);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.insert(st_vec_.end(), 100, 45);
	ft_vec_.insert(ft_vec_.end(), 100, 45);
	CompareSizeCapElem(st_vec_, ft_vec_);
	// EXPECT_THROW(st_vec_.insert(st_vec_.begin(), -1, 42), std::length_error);
	// EXPECT_THROW(ft_vec_.insert(ft_vec_.begin(), -1, 42), std::length_error);
	// CompareSizeCapElem(st_vec_, ft_vec_);
}

TEST_F(VectorTest, InsertRangeTest)
{
	st_vec_.insert(st_vec_.begin(), nums, nums + 3);
	ft_vec_.insert(ft_vec_.begin(), nums, nums + 3);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.insert(st_vec_.begin() + 1, nums, nums + 1);
	ft_vec_.insert(ft_vec_.begin() + 1, nums, nums + 1);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.insert(st_vec_.begin() + 2, nums, nums);
	ft_vec_.insert(ft_vec_.begin() + 2, nums, nums);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.insert(st_vec_.end(), nums, nums + 2);
	ft_vec_.insert(ft_vec_.end(), nums, nums + 2);
	CompareSizeCapElem(st_vec_, ft_vec_);
	// EXPECT_THROW(st_vec_.insert(st_vec_.begin(), nums, nums - 1), std::length_error);
	// EXPECT_THROW(ft_vec_.insert(ft_vec_.begin(), nums, nums - 1), std::length_error);
	// CompareSizeCapElem(st_vec_, ft_vec_);
}

TEST_F(VectorTest, ResizeTest)
{
	st_vec_.resize(1, 42);
	ft_vec_.resize(1, 42);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.resize(2, 43);
	ft_vec_.resize(2, 43);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.resize(3, 44);
	ft_vec_.resize(3, 44);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.resize(5, 45);
	ft_vec_.resize(5, 45);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.resize(0, 46);
	ft_vec_.resize(0, 46);
	CompareSizeCapElem(st_vec_, ft_vec_);
	EXPECT_THROW(st_vec_.resize(-1, 42), std::length_error);
	EXPECT_THROW(ft_vec_.resize(-1, 42), std::length_error);
	CompareSizeCapElem(st_vec_, ft_vec_);
}

TEST_F(VectorTest, EraseSingleTest)
{
	std::vector<int>::iterator	st_begin = st_vec_.begin();
	ft::vector<int>::iterator	ft_begin = ft_vec_.begin();
	std::vector<int>::iterator	st_itr;
	ft::vector<int>::iterator	ft_itr;

	st_itr = st_vec_.erase(st_begin + 1);
	ft_itr = ft_vec_.erase(ft_begin + 1);
	EXPECT_EQ(*st_itr, *ft_itr);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_itr = st_vec_.erase(st_begin + 1);
	ft_itr = ft_vec_.erase(ft_begin + 1);
	EXPECT_EQ(st_itr == st_vec_.end(), ft_itr == ft_vec_.end());
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_itr = st_vec_.erase(st_begin);
	ft_itr = ft_vec_.erase(ft_begin);
	EXPECT_EQ(st_itr == st_vec_.end(), ft_itr == ft_vec_.end());
	CompareSizeCapElem(st_vec_, ft_vec_);
}

TEST_F(VectorTest, EraseRangeTest)
{
	std::vector<int>			st_vec2(st_vec_);
	std::vector<int>			st_vec3(st_vec_);
	ft::vector<int>				ft_vec2(ft_vec_);
	ft::vector<int>				ft_vec3(ft_vec_);
	std::vector<int>::iterator	st_itr;
	ft::vector<int>::iterator	ft_itr;

	st_itr = st_vec_.erase(st_vec_.begin(), st_vec_.begin() + 2);
	ft_itr = ft_vec_.erase(ft_vec_.begin(), ft_vec_.begin() + 2);
	EXPECT_EQ(*st_itr, *ft_itr);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_itr = st_vec2.erase(st_vec2.begin() + 1, st_vec2.begin() + 3);
	ft_itr = ft_vec2.erase(ft_vec2.begin() + 1, ft_vec2.begin() + 3);
	EXPECT_EQ(st_itr == st_vec2.end(), ft_itr == ft_vec2.end());
	CompareSizeCapElem(st_vec2, ft_vec2);
	st_itr = st_vec3.erase(st_vec3.begin(), st_vec3.end());
	ft_itr = ft_vec3.erase(ft_vec3.begin(), ft_vec3.end());
	EXPECT_EQ(st_itr == st_vec3.end(), ft_itr == ft_vec3.end());
	CompareSizeCapElem(st_vec3, ft_vec3);
}

TEST_F(VectorTest, SwapTest)
{
	std::vector<int>::iterator	st_begin = st_vec_.begin();
	ft::vector<int>::iterator	ft_begin = ft_vec_.begin();
	std::vector<int>			st_vec2(5, 42);
	ft::vector<int>				ft_vec2(5, 42);
	st_vec_.swap(st_vec2);
	ft_vec_.swap(ft_vec2);
	CompareSizeCapElem(st_vec_, ft_vec_);
	CompareSizeCapElem(st_vec2, ft_vec2);
	EXPECT_EQ(st_begin == st_vec2.begin(), ft_begin == ft_vec2.begin());

	std::vector<int>			st_vec3;
	ft::vector<int>				ft_vec3;
	st_vec_.swap(st_vec3);
	ft_vec_.swap(ft_vec3);
	CompareSizeCapElem(st_vec_, ft_vec_);
	CompareSizeCapElem(st_vec3, ft_vec3);
}

TEST_F(VectorTest, ClearTest)
{
	st_vec_.clear();
	ft_vec_.clear();
	CompareSizeCapElem(st_vec_, ft_vec_);
}
