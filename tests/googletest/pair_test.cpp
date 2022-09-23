#ifndef TESTLIB
# include <gtest/gtest.h>
#else
# include "testlib.hpp"
#endif
#include "pair.hpp"
#include "vector.hpp"

class PairTest : public ::testing::Test
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
			st_pair_.first = 42;
			st_pair_.second = "Forty Two";
			ft_pair_.first = 42;
			ft_pair_.second = "Forty Two";
		}
		virtual void TearDown()
		{
		}

		void	SetupPairForRelationalOpe()
		{
			st_first_small_ = st_pair_;		st_first_small_.first = 1;
			ft_first_small_ = ft_pair_;		ft_first_small_.first = 1;
			st_first_large_ = st_pair_;		st_first_large_.first = 100;
			ft_first_large_ = ft_pair_;		ft_first_large_.first = 100;
			st_second_small_ = st_pair_;	st_second_small_.second = "AAAAA";
			ft_second_small_ = ft_pair_;	ft_second_small_.second = "AAAAA";
			st_second_large_ = st_pair_;	st_second_large_.second = "zzzzz";
			ft_second_large_ = ft_pair_;	ft_second_large_.second = "zzzzz";
		}

		template <class T1, class T2>
		void CompareFirstSecond(const std::pair<T1, T2>& st_pair, const ft::pair<T1, T2>& ft_pair)
		{
			EXPECT_EQ(st_pair.first,	ft_pair.first);
			EXPECT_EQ(st_pair.second,	ft_pair.second);
		}

		std::pair<int, std::string>	st_pair_;
		ft::pair<int, std::string>	ft_pair_;

		std::pair<int, std::string>	st_first_small_;
		ft::pair<int, std::string>	ft_first_small_;
		std::pair<int, std::string>	st_first_large_;
		ft::pair<int, std::string>	ft_first_large_;
		std::pair<int, std::string>	st_second_small_;
		ft::pair<int, std::string>	ft_second_small_;
		std::pair<int, std::string>	st_second_large_;
		ft::pair<int, std::string>	ft_second_large_;
};

TEST_F(PairTest, DefaultConstructorTest)
{
	std::pair<int, std::string>	st_pair;
	ft::pair<int, std::string>	ft_pair;
	CompareFirstSecond(st_pair, ft_pair);

	std::pair<ft::vector<int>, ft::vector<std::string> >	st_vec_pair;
	ft::pair<ft::vector<int>, ft::vector<std::string> >	ft_vec_pair;
	CompareFirstSecond(st_pair, ft_pair);
}

TEST_F(PairTest, CopyConstructorTest)
{
	std::pair<int, std::string>	st_pair_copy(st_pair_);
	ft::pair<int, std::string>	ft_pair_copy(ft_pair_);
	CompareFirstSecond(st_pair_copy, ft_pair_copy);

	std::pair<char, std::string>	st_char_pair_copy(st_pair_);
	ft::pair<char, std::string>		ft_char_pair_copy(ft_pair_);
	CompareFirstSecond(st_char_pair_copy, ft_char_pair_copy);

	// std::pair<std::string, std::string>	st_str_pair_copy(st_pair_);
	// ft::pair<std::string, std::string>	ft_str_pair_copy(ft_pair_);
	// CompareFirstSecond(st_str_pair_copy, ft_str_pair_copy);
}

TEST_F(PairTest, InitialConstructorTest)
{
	std::pair<int, std::string>	st_pair(42, "Forty Two");
	ft::pair<int, std::string>	ft_pair(42, "Forty Two");
	CompareFirstSecond(st_pair, ft_pair);

	// std::pair<std::string, std::string>	st_str_pair(42, "Forty Two");
	// ft::pair<std::string, std::string>	ft_str_pair(42, "Forty Two");
	// CompareFirstSecond(st_str_pair, ft_str_pair);
}

TEST_F(PairTest, OpeAssignTest)
{
	std::pair<int, std::string>	st_pair_copy;
	ft::pair<int, std::string>	ft_pair_copy;
	CompareFirstSecond((st_pair_copy = st_pair_), (ft_pair_copy = ft_pair_));
}

TEST_F(PairTest, OpeEqualTest)
{
	SetupPairForRelationalOpe();
	EXPECT_EQ(st_pair_ == st_pair_, 		ft_pair_ == ft_pair_);
	EXPECT_EQ(st_pair_ == st_first_small_, 	ft_pair_ == ft_first_small_);
	EXPECT_EQ(st_pair_ == st_first_large_, 	ft_pair_ == ft_first_large_);
	EXPECT_EQ(st_pair_ == st_second_small_,	ft_pair_ == ft_second_small_);
	EXPECT_EQ(st_pair_ == st_second_large_,	ft_pair_ == ft_second_large_);
}

TEST_F(PairTest, OpeNotEqualTest)
{
	SetupPairForRelationalOpe();
	EXPECT_EQ(st_pair_ != st_pair_, 		ft_pair_ != ft_pair_);
	EXPECT_EQ(st_pair_ != st_first_small_, 	ft_pair_ != ft_first_small_);
	EXPECT_EQ(st_pair_ != st_first_large_, 	ft_pair_ != ft_first_large_);
	EXPECT_EQ(st_pair_ != st_second_small_,	ft_pair_ != ft_second_small_);
	EXPECT_EQ(st_pair_ != st_second_large_,	ft_pair_ != ft_second_large_);
}

TEST_F(PairTest, OpeLessTest)
{
	SetupPairForRelationalOpe();
	EXPECT_EQ(st_pair_ < st_pair_, 			ft_pair_ < ft_pair_);
	EXPECT_EQ(st_pair_ < st_first_small_, 	ft_pair_ < ft_first_small_);
	EXPECT_EQ(st_pair_ < st_first_large_, 	ft_pair_ < ft_first_large_);
	EXPECT_EQ(st_pair_ < st_second_small_,	ft_pair_ < ft_second_small_);
	EXPECT_EQ(st_pair_ < st_second_large_,	ft_pair_ < ft_second_large_);
}

TEST_F(PairTest, OpeLessEqualTest)
{
	SetupPairForRelationalOpe();
	EXPECT_EQ(st_pair_ <= st_pair_, 		ft_pair_ <= ft_pair_);
	EXPECT_EQ(st_pair_ <= st_first_small_, 	ft_pair_ <= ft_first_small_);
	EXPECT_EQ(st_pair_ <= st_first_large_, 	ft_pair_ <= ft_first_large_);
	EXPECT_EQ(st_pair_ <= st_second_small_,	ft_pair_ <= ft_second_small_);
	EXPECT_EQ(st_pair_ <= st_second_large_,	ft_pair_ <= ft_second_large_);
}

TEST_F(PairTest, OpeMoreTest)
{
	SetupPairForRelationalOpe();
	EXPECT_EQ(st_pair_ > st_pair_, 			ft_pair_ > ft_pair_);
	EXPECT_EQ(st_pair_ > st_first_small_, 	ft_pair_ > ft_first_small_);
	EXPECT_EQ(st_pair_ > st_first_large_, 	ft_pair_ > ft_first_large_);
	EXPECT_EQ(st_pair_ > st_second_small_,	ft_pair_ > ft_second_small_);
	EXPECT_EQ(st_pair_ > st_second_large_,	ft_pair_ > ft_second_large_);
}

TEST_F(PairTest, OpeMoreEqualTest)
{
	SetupPairForRelationalOpe();
	EXPECT_EQ(st_pair_ >= st_pair_, 		ft_pair_ >= ft_pair_);
	EXPECT_EQ(st_pair_ >= st_first_small_, 	ft_pair_ >= ft_first_small_);
	EXPECT_EQ(st_pair_ >= st_first_large_, 	ft_pair_ >= ft_first_large_);
	EXPECT_EQ(st_pair_ >= st_second_small_,	ft_pair_ >= ft_second_small_);
	EXPECT_EQ(st_pair_ >= st_second_large_,	ft_pair_ >= ft_second_large_);
}

TEST_F(PairTest, MakePairTest)
{
	ft::pair<int, std::string>	ft_pair = ft::make_pair(42, "Forty Two");
	EXPECT_EQ(ft_pair.first, 42);
	EXPECT_EQ(ft_pair.second, "Forty Two");
}
