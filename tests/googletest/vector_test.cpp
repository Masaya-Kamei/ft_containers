#ifndef TESTLIB
# include <gtest/gtest.h>
#else
# include "testlib.hpp"
#endif
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
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
			st_vec_.assign(nums_, nums_ + 3);
			ft_vec_.assign(nums_, nums_ + 3);
		}
		virtual void TearDown()
		{
		}

		void SetupVectorForRelationalOpe()
		{
			st_large_.assign(nums_, nums_ + 3);	st_large_[1] = 200;
			ft_large_.assign(nums_, nums_ + 3);	ft_large_[1] = 200;
			st_small_.assign(nums_, nums_ + 3);	st_small_[1] = 2;
			ft_small_.assign(nums_, nums_ + 3);	ft_small_[1] = 2;
			st_more_.assign(nums_, nums_ + 4);
			ft_more_.assign(nums_, nums_ + 4);
			st_less_.assign(nums_, nums_ + 2);
			ft_less_.assign(nums_, nums_ + 2);
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

		static const int				nums_[5];
		std::vector<int>				st_vec_;
		ft::vector<int>					ft_vec_;
		static const std::vector<int>	st_const_vec_;
		static const ft::vector<int>	ft_const_vec_;
		std::vector<int>				st_zero_vec_;
		ft::vector<int>					ft_zero_vec_;

		std::vector<int>::iterator					st_itr_;
		ft::vector<int>::iterator					ft_itr_;
		std::vector<int>::const_iterator			st_citr_;
		ft::vector<int>::const_iterator				ft_citr_;
		std::vector<int>::reverse_iterator			st_ritr_;
		ft::vector<int>::reverse_iterator			ft_ritr_;
		std::vector<int>::const_reverse_iterator	st_critr_;
		ft::vector<int>::const_reverse_iterator		ft_critr_;

		std::vector<int>	st_large_;
		ft::vector<int>		ft_large_;
		std::vector<int>	st_small_;
		ft::vector<int>		ft_small_;
		std::vector<int>	st_more_;
		ft::vector<int>		ft_more_;
		std::vector<int>	st_less_;
		ft::vector<int>		ft_less_;
};

const int 				VectorTest::nums_[5] = {10, 20, 30, 40, 50};
const std::vector<int>	VectorTest::st_const_vec_(nums_, nums_ + 3);
const ft::vector<int>	VectorTest::ft_const_vec_(nums_, nums_ + 3);

TEST_F(VectorTest, DefaultConstructorTest)
{
	std::vector<int>	st_int_vec;
	ft::vector<int>		ft_int_vec;
	CompareSizeCapElem(st_int_vec, ft_int_vec);

	std::vector<std::string>	st_str_vec;
	ft::vector<std::string>		ft_str_vec;
	CompareSizeCapElem(st_str_vec, ft_str_vec);
}

TEST_F(VectorTest, FillConstructorTest)
{
	std::vector<int>	st_vec(5, 5);
	ft::vector<int>		ft_vec(5, 5);
	CompareSizeCapElem(st_vec, ft_vec);

	std::vector<int>	st_size_vec(5);
	ft::vector<int>		ft_size_vec(5);
	CompareSizeCapElem(st_size_vec, ft_size_vec);

	std::vector<int>	st_zero_vec(0);
	ft::vector<int>		ft_zero_vec(0);
	CompareSizeCapElem(st_zero_vec, ft_zero_vec);

	EXPECT_THROW(std::vector<int>	st_invalid_vec(-1),	std::length_error);
	EXPECT_THROW(ft::vector<int>	ft_invalid_vec(-1),	std::length_error);
}

TEST_F(VectorTest, RangeConstructorTest)
{
	std::vector<int>	st_vec(nums_, nums_ + 3);
	ft::vector<int>		ft_vec(nums_, nums_ + 3);
	CompareSizeCapElem(st_vec, ft_vec);
	EXPECT_NE(&(*nums_), &(*ft_vec.begin()));

	EXPECT_THROW(std::vector<int> st_invalid_vec(nums_, nums_ - 1),	std::length_error);
	EXPECT_THROW(ft::vector<int>  ft_invalid_vec(nums_, nums_ - 1),	std::length_error);

	std::vector<int>	st_zero_vec(nums_, nums_);
	ft::vector<int>		ft_zero_vec(nums_, nums_);
	CompareSizeCapElem(st_zero_vec, ft_zero_vec);
}

TEST_F(VectorTest, CopyConstructorTest)
{
	std::vector<int>	st_vec_copy(st_vec_);
	ft::vector<int>		ft_vec_copy(ft_vec_);
	CompareSizeCapElem(st_vec_copy, ft_vec_copy);
	EXPECT_NE(ft_vec_.begin(), ft_vec_copy.begin());
}

TEST_F(VectorTest, OpeAssignTest)
{
	std::vector<int> st_vec_copy;	st_vec_copy = st_vec_;
	ft::vector<int>	 ft_vec_copy;	ft_vec_copy = ft_vec_;

	CompareSizeCapElem(st_vec_copy, ft_vec_copy);
	EXPECT_NE(ft_vec_.begin(), ft_vec_copy.begin());
}

TEST_F(VectorTest, BeginTest)
{
	st_itr_ = st_vec_.begin();
	ft_itr_ = ft_vec_.begin();
	EXPECT_EQ(*st_itr_, *ft_itr_);
	st_citr_ = st_vec_.begin();
	ft_citr_ = ft_vec_.begin();
	EXPECT_EQ(*st_citr_, *ft_citr_);

	st_citr_ = st_const_vec_.begin();
	ft_citr_ = ft_const_vec_.begin();
	EXPECT_EQ(*st_citr_, *ft_citr_);
}

TEST_F(VectorTest, EndTest)
{
	st_itr_ = st_vec_.end() - 1;
	ft_itr_ = ft_vec_.end() - 1;
	EXPECT_EQ(*st_itr_, *ft_itr_);
	st_citr_ = st_vec_.end() - 1;
	ft_citr_ = ft_vec_.end() - 1;
	EXPECT_EQ(*st_citr_, *ft_citr_);

	st_citr_ = st_const_vec_.end() - 1;
	ft_citr_ = ft_const_vec_.end() - 1;
	EXPECT_EQ(*st_citr_, *ft_citr_);
}

TEST_F(VectorTest, RbeginTest)
{
	st_ritr_ = st_vec_.rbegin();
	ft_ritr_ = ft_vec_.rbegin();
	EXPECT_EQ(*st_ritr_, *ft_ritr_);
	st_critr_ = st_vec_.rbegin();
	ft_critr_ = ft_vec_.rbegin();
	EXPECT_EQ(*st_critr_, *ft_critr_);

	st_critr_ = st_const_vec_.rbegin();
	ft_critr_ = ft_const_vec_.rbegin();
	EXPECT_EQ(*st_critr_, *ft_critr_);
}

TEST_F(VectorTest, RendTest)
{
	st_ritr_ = st_vec_.rend() - 1;
	ft_ritr_ = ft_vec_.rend() - 1;
	EXPECT_EQ(*st_ritr_, *ft_ritr_);
	st_critr_ = st_vec_.rend() - 1;
	ft_critr_ = ft_vec_.rend() - 1;
	EXPECT_EQ(*st_critr_, *ft_critr_);

	st_critr_ = st_const_vec_.rend() - 1;
	ft_critr_ = ft_const_vec_.rend() - 1;
	EXPECT_EQ(*st_critr_, *ft_critr_);
}

TEST_F(VectorTest, SizeTest)
{
	EXPECT_EQ(st_vec_.size(), ft_vec_.size());
	EXPECT_EQ(st_zero_vec_.size(), ft_zero_vec_.size());
}

TEST_F(VectorTest, MaxSizeTest)
{
	EXPECT_EQ(st_vec_.max_size(), ft_vec_.max_size());
	EXPECT_EQ(st_zero_vec_.max_size(), ft_zero_vec_.max_size());
}

TEST_F(VectorTest, CapacityTest)
{
	EXPECT_EQ(st_vec_.capacity(), ft_vec_.capacity());
	st_vec_.push_back(42);
	ft_vec_.push_back(42);
	EXPECT_EQ(st_vec_.capacity(), ft_vec_.capacity());
	EXPECT_EQ(st_zero_vec_.capacity(), ft_zero_vec_.capacity());
}

TEST_F(VectorTest, EmptyTest)
{
	EXPECT_EQ(st_vec_.empty(), ft_vec_.empty());
	EXPECT_EQ(st_zero_vec_.empty(), ft_zero_vec_.empty());
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

TEST_F(VectorTest, OpeBracketsTest)
{
	EXPECT_EQ(st_vec_[0], ft_vec_[0]);
	EXPECT_EQ(st_vec_[1], ft_vec_[1]);
	EXPECT_EQ(st_vec_[2], ft_vec_[2]);

	EXPECT_EQ(st_const_vec_[0], ft_const_vec_[0]);
	EXPECT_EQ(st_const_vec_[1], ft_const_vec_[1]);
	EXPECT_EQ(st_const_vec_[2], ft_const_vec_[2]);
}

TEST_F(VectorTest, AtTest)
{
	EXPECT_EQ(st_vec_.at(0), ft_vec_.at(0));
	EXPECT_EQ(st_vec_.at(1), ft_vec_.at(1));
	EXPECT_EQ(st_vec_.at(2), ft_vec_.at(2));
	EXPECT_THROW(st_vec_.at(3), std::out_of_range);
	EXPECT_THROW(ft_vec_.at(3), std::out_of_range);

	EXPECT_EQ(st_const_vec_.at(0), ft_const_vec_.at(0));
	EXPECT_EQ(st_const_vec_.at(1), ft_const_vec_.at(1));
	EXPECT_EQ(st_const_vec_.at(2), ft_const_vec_.at(2));
	EXPECT_THROW(st_const_vec_.at(3), std::out_of_range);
	EXPECT_THROW(ft_const_vec_.at(3), std::out_of_range);
}

TEST_F(VectorTest, FrontTest)
{
	EXPECT_EQ(st_vec_.front(), ft_vec_.front());
	EXPECT_EQ(st_const_vec_.front(), ft_const_vec_.front());

	// std::cout << st_zero_vec_.front() << std::endl;
	// EXPECT_EQ(st_zero_vec_.front(), ft_zero_vec.front());
}

TEST_F(VectorTest, BackTest)
{
	EXPECT_EQ(st_vec_.back(), ft_vec_.back());
	EXPECT_EQ(st_const_vec_.back(), ft_const_vec_.back());

	// std::cout << st_zero_vec_.back() << std::endl;
	// EXPECT_EQ(st_zero_vec_.back(), ft_zero_vec.back());
}

TEST_F(VectorTest, DataTest)
{
	EXPECT_EQ(*(st_vec_.data()), *(ft_vec_.data()));
	EXPECT_EQ(*(st_const_vec_.data()), *(ft_const_vec_.data()));
	EXPECT_EQ(st_zero_vec_.data(), ft_zero_vec_.data());
}

TEST_F(VectorTest, AssignFillTest)
{
	st_vec_.assign(4, 42);
	ft_vec_.assign(4, 42);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.assign(1, 42);
	ft_vec_.assign(1, 42);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.assign(3, 42);
	ft_vec_.assign(3, 42);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.assign(0, 42);
	ft_vec_.assign(0, 42);
	CompareSizeCapElem(st_vec_, ft_vec_);
	EXPECT_THROW(st_vec_.assign(-1, 42), std::length_error);
	EXPECT_THROW(ft_vec_.assign(-1, 42), std::length_error);
	CompareSizeCapElem(st_vec_, ft_vec_);
}

TEST_F(VectorTest, AssignRangeTest)
{
	st_vec_.assign(nums_, nums_ + 4);
	ft_vec_.assign(nums_, nums_ + 4);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.assign(nums_, nums_ + 1);
	ft_vec_.assign(nums_, nums_ + 1);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.assign(nums_, nums_ + 3);
	ft_vec_.assign(nums_, nums_ + 3);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.assign(nums_, nums_);
	ft_vec_.assign(nums_, nums_);
	CompareSizeCapElem(st_vec_, ft_vec_);
	EXPECT_THROW(st_vec_.assign(nums_, nums_ - 1), std::length_error);
	EXPECT_THROW(ft_vec_.assign(nums_, nums_ - 1), std::length_error);
	CompareSizeCapElem(st_vec_, ft_vec_);
}

TEST_F(VectorTest, PushBackTest)
{
	st_vec_.push_back(42);
	ft_vec_.push_back(42);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.push_back(43); st_vec_.push_back(44); st_vec_.push_back(45);
	st_vec_.push_back(46); st_vec_.push_back(47); st_vec_.push_back(48);
	ft_vec_.push_back(43); ft_vec_.push_back(44); ft_vec_.push_back(45);
	ft_vec_.push_back(46); ft_vec_.push_back(47); ft_vec_.push_back(48);
	CompareSizeCapElem(st_vec_, ft_vec_);
}

TEST_F(VectorTest, PopBackTest)
{
	st_vec_.pop_back();
	ft_vec_.pop_back();
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.pop_back();
	ft_vec_.pop_back();
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.pop_back();
	ft_vec_.pop_back();
	CompareSizeCapElem(st_vec_, ft_vec_);
	// st_vec_.pop_back();
	// ft_vec_.pop_back();
	// CompareSizeCapElem(st_vec_, ft_vec_);
}

TEST_F(VectorTest, InsertSingleTest)
{
	st_itr_ = st_vec_.insert(st_vec_.begin(), 42);
	ft_itr_ = ft_vec_.insert(ft_vec_.begin(), 42);
	EXPECT_EQ(*st_itr_, *ft_itr_);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_itr_ = st_vec_.insert(st_vec_.begin() + 1, 43);
	ft_itr_ = ft_vec_.insert(ft_vec_.begin() + 1, 43);
	EXPECT_EQ(*st_itr_, *ft_itr_);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_itr_ = st_vec_.insert(st_vec_.begin() + 2, 44);
	ft_itr_ = ft_vec_.insert(ft_vec_.begin() + 2, 44);
	EXPECT_EQ(*st_itr_, *ft_itr_);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_itr_ = st_vec_.insert(st_vec_.end(), 45);
	ft_itr_ = ft_vec_.insert(ft_vec_.end(), 45);
	EXPECT_EQ(*st_itr_, *ft_itr_);
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
	st_vec_.insert(st_vec_.begin(), nums_, nums_ + 3);
	ft_vec_.insert(ft_vec_.begin(), nums_, nums_ + 3);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.insert(st_vec_.begin() + 1, nums_, nums_ + 1);
	ft_vec_.insert(ft_vec_.begin() + 1, nums_, nums_ + 1);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.insert(st_vec_.begin() + 2, nums_, nums_);
	ft_vec_.insert(ft_vec_.begin() + 2, nums_, nums_);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_vec_.insert(st_vec_.end(), nums_, nums_ + 2);
	ft_vec_.insert(ft_vec_.end(), nums_, nums_ + 2);
	CompareSizeCapElem(st_vec_, ft_vec_);
	// EXPECT_THROW(st_vec_.insert(st_vec_.begin(), nums_, nums_ - 1), std::length_error);
	// EXPECT_THROW(ft_vec_.insert(ft_vec_.begin(), nums_, nums_ - 1), std::length_error);
	// CompareSizeCapElem(st_vec_, ft_vec_);
}

TEST_F(VectorTest, EraseSingleTest)
{
	std::vector<int>::iterator	st_begin = st_vec_.begin();
	ft::vector<int>::iterator	ft_begin = ft_vec_.begin();

	st_itr_ = st_vec_.erase(st_begin + 1);
	ft_itr_ = ft_vec_.erase(ft_begin + 1);
	EXPECT_EQ(*st_itr_, *ft_itr_);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_itr_ = st_vec_.erase(st_begin + 1);
	ft_itr_ = ft_vec_.erase(ft_begin + 1);
	EXPECT_EQ(st_itr_ == st_vec_.end(), ft_itr_ == ft_vec_.end());
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_itr_ = st_vec_.erase(st_begin);
	ft_itr_ = ft_vec_.erase(ft_begin);
	EXPECT_EQ(st_itr_ == st_vec_.end(), ft_itr_ == ft_vec_.end());
	CompareSizeCapElem(st_vec_, ft_vec_);
}

TEST_F(VectorTest, EraseRangeTest)
{
	std::vector<int>			st_vec2(st_vec_);
	std::vector<int>			st_vec3(st_vec_);
	ft::vector<int>				ft_vec2(ft_vec_);
	ft::vector<int>				ft_vec3(ft_vec_);

	st_itr_ = st_vec_.erase(st_vec_.begin(), st_vec_.begin() + 2);
	ft_itr_ = ft_vec_.erase(ft_vec_.begin(), ft_vec_.begin() + 2);
	EXPECT_EQ(*st_itr_, *ft_itr_);
	CompareSizeCapElem(st_vec_, ft_vec_);
	st_itr_ = st_vec2.erase(st_vec2.begin() + 1, st_vec2.begin() + 3);
	ft_itr_ = ft_vec2.erase(ft_vec2.begin() + 1, ft_vec2.begin() + 3);
	EXPECT_EQ(st_itr_ == st_vec2.end(), ft_itr_ == ft_vec2.end());
	CompareSizeCapElem(st_vec2, ft_vec2);
	st_itr_ = st_vec3.erase(st_vec3.begin(), st_vec3.end());
	ft_itr_ = ft_vec3.erase(ft_vec3.begin(), ft_vec3.end());
	EXPECT_EQ(st_itr_ == st_vec3.end(), ft_itr_ == ft_vec3.end());
	CompareSizeCapElem(st_vec3, ft_vec3);
}

TEST_F(VectorTest, SwapTest)
{
	std::vector<int>::iterator	st_begin = st_vec_.begin();
	ft::vector<int>::iterator	ft_begin = ft_vec_.begin();
	std::vector<int>			st_fill_vec(5, 42);
	ft::vector<int>				ft_fill_vec(5, 42);
	st_vec_.swap(st_fill_vec);
	ft_vec_.swap(ft_fill_vec);
	CompareSizeCapElem(st_vec_,		ft_vec_);
	CompareSizeCapElem(st_fill_vec,	ft_fill_vec);
	EXPECT_EQ(st_begin == st_fill_vec.begin(), ft_begin == ft_fill_vec.begin());

	st_vec_.swap(st_zero_vec_);
	ft_vec_.swap(ft_zero_vec_);
	CompareSizeCapElem(st_vec_,		 ft_vec_);
	CompareSizeCapElem(st_zero_vec_, ft_zero_vec_);
}

TEST_F(VectorTest, ClearTest)
{
	st_vec_.clear();
	ft_vec_.clear();
	CompareSizeCapElem(st_vec_, ft_vec_);

	st_vec_.assign(nums_, nums_ + 3);
	ft_vec_.assign(nums_, nums_ + 3);
	CompareSizeCapElem(st_vec_, ft_vec_);

	st_zero_vec_.clear();
	ft_zero_vec_.clear();
	CompareSizeCapElem(st_zero_vec_, ft_zero_vec_);
}

TEST_F(VectorTest, GetAllocatorTest)
{
	EXPECT_EQ(st_vec_.get_allocator(), ft_vec_.get_allocator());
}

TEST_F(VectorTest, OpeEqualTest)
{
	SetupVectorForRelationalOpe();
	EXPECT_EQ(st_vec_ == st_vec_,	ft_vec_ == ft_vec_);
	EXPECT_EQ(st_vec_ == st_large_,	ft_vec_ == ft_large_);
	EXPECT_EQ(st_vec_ == st_small_,	ft_vec_ == ft_small_);
	EXPECT_EQ(st_vec_ == st_more_,	ft_vec_ == ft_more_);
	EXPECT_EQ(st_vec_ == st_less_,	ft_vec_ == ft_less_);
}

TEST_F(VectorTest, OpeNotEqualTest)
{
	SetupVectorForRelationalOpe();
	EXPECT_EQ(st_vec_ != st_vec_,	ft_vec_ != ft_vec_);
	EXPECT_EQ(st_vec_ != st_large_,	ft_vec_ != ft_large_);
	EXPECT_EQ(st_vec_ != st_small_,	ft_vec_ != ft_small_);
	EXPECT_EQ(st_vec_ != st_more_,	ft_vec_ != ft_more_);
	EXPECT_EQ(st_vec_ != st_less_,	ft_vec_ != ft_less_);
}

TEST_F(VectorTest, OpeLessTest)
{
	SetupVectorForRelationalOpe();
	EXPECT_EQ(st_vec_ < st_vec_,	ft_vec_ < ft_vec_);
	EXPECT_EQ(st_vec_ < st_large_,	ft_vec_ < ft_large_);
	EXPECT_EQ(st_vec_ < st_small_,	ft_vec_ < ft_small_);
	EXPECT_EQ(st_vec_ < st_more_,	ft_vec_ < ft_more_);
	EXPECT_EQ(st_vec_ < st_less_,	ft_vec_ < ft_less_);
}

TEST_F(VectorTest, OpeLessEqualTest)
{
	SetupVectorForRelationalOpe();
	EXPECT_EQ(st_vec_ <= st_vec_,	ft_vec_ <= ft_vec_);
	EXPECT_EQ(st_vec_ <= st_large_,	ft_vec_ <= ft_large_);
	EXPECT_EQ(st_vec_ <= st_small_,	ft_vec_ <= ft_small_);
	EXPECT_EQ(st_vec_ <= st_more_,	ft_vec_ <= ft_more_);
	EXPECT_EQ(st_vec_ <= st_less_,	ft_vec_ <= ft_less_);
}

TEST_F(VectorTest, OpeGreaterTest)
{
	SetupVectorForRelationalOpe();
	EXPECT_EQ(st_vec_ > st_vec_,	ft_vec_ > ft_vec_);
	EXPECT_EQ(st_vec_ > st_large_,	ft_vec_ > ft_large_);
	EXPECT_EQ(st_vec_ > st_small_,	ft_vec_ > ft_small_);
	EXPECT_EQ(st_vec_ > st_more_,	ft_vec_ > ft_more_);
	EXPECT_EQ(st_vec_ > st_less_,	ft_vec_ > ft_less_);
}

TEST_F(VectorTest, OpeGreaterEqualTest)
{
	SetupVectorForRelationalOpe();
	EXPECT_EQ(st_vec_ >= st_vec_,	ft_vec_ >= ft_vec_);
	EXPECT_EQ(st_vec_ >= st_large_,	ft_vec_ >= ft_large_);
	EXPECT_EQ(st_vec_ >= st_small_,	ft_vec_ >= ft_small_);
	EXPECT_EQ(st_vec_ >= st_more_,	ft_vec_ >= ft_more_);
	EXPECT_EQ(st_vec_ >= st_less_,	ft_vec_ >= ft_less_);
}

TEST_F(VectorTest, NonMemberSwapTest)
{
	std::vector<int>::iterator	st_begin = st_vec_.begin();
	ft::vector<int>::iterator	ft_begin = ft_vec_.begin();
	std::vector<int>			st_fill_vec(5, 42);
	ft::vector<int>				ft_fill_vec(5, 42);
	swap(st_vec_, st_fill_vec);
	swap(ft_vec_, ft_fill_vec);
	CompareSizeCapElem(st_vec_,		ft_vec_);
	CompareSizeCapElem(st_fill_vec,	ft_fill_vec);
	EXPECT_EQ(st_begin == st_fill_vec.begin(), ft_begin == ft_fill_vec.begin());

	swap(st_vec_, st_zero_vec_);
	swap(ft_vec_, ft_zero_vec_);
	CompareSizeCapElem(st_vec_,		 ft_vec_);
	CompareSizeCapElem(st_zero_vec_, ft_zero_vec_);

	// swap(st_vec_, st_const_vec_);
	// swap(ft_vec_, ft_const_vec_);
}

TEST_F(VectorTest, InputIteratorTest)
{
	std::istream_iterator<int>	st_first;
	std::istream_iterator<int>	ft_first;
	std::istream_iterator<int>	st_last;
	std::istream_iterator<int>	ft_last;

	std::stringstream st_ss1;	st_ss1 << 1 << std::endl << 2 << std::endl << 3;
	std::stringstream ft_ss1;	ft_ss1 << 1 << std::endl << 2 << std::endl << 3;
	st_first = st_ss1;
	ft_first = ft_ss1;
	std::vector<int>	st_vec(st_first, st_last);
	ft::vector<int>		ft_vec(ft_first, ft_last);
	CompareSizeCapElem(st_vec, ft_vec);

	std::stringstream st_ss2;	st_ss2 << 1 << std::endl << 2 << std::endl << 3 << std::endl << 4;
	std::stringstream ft_ss2;	ft_ss2 << 1 << std::endl << 2 << std::endl << 3 << std::endl << 4;
	st_first = st_ss2;
	ft_first = ft_ss2;
	st_vec_.assign(st_first, st_last);
	ft_vec_.assign(ft_first, ft_last);
	CompareSizeCapElem(st_vec_, ft_vec_);

	std::stringstream st_ss3;	st_ss3 << 1 << std::endl << 2 << std::endl << 3;
	std::stringstream ft_ss3;	ft_ss3 << 1 << std::endl << 2 << std::endl << 3;
	st_first = st_ss3;
	ft_first = ft_ss3;
	st_vec_.insert(st_vec_.begin(), st_first, st_last);
	ft_vec_.insert(ft_vec_.begin(), ft_first, ft_last);
	CompareSizeCapElem(st_vec_, ft_vec_);
}

TEST_F(VectorTest, ConstIntTest)
{
	std::vector<const int>	st_vec1(nums_, nums_ + 3);
	ft::vector<const int>	ft_vec1(nums_, nums_ + 3);
	CompareSizeCapElem(st_vec1, ft_vec1);

	std::vector<const int>	st_vec2(10, 42);
	ft::vector<const int>	ft_vec2(10, 42);
	CompareSizeCapElem(st_vec2, ft_vec2);

	std::vector<const int>	st_vec3(st_vec1);
	ft::vector<const int>	ft_vec3(ft_vec1);
	CompareSizeCapElem(st_vec3, ft_vec3);

	// st_vec1 = st_vec_;
	// ft_vec1 = ft_vec_;
	// st_vec1.assign(100, 42);
	// ft_vec1.assign(100, 42);
}
