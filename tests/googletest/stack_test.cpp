#ifndef TESTLIB
# include <gtest/gtest.h>
#else
# include "testlib.hpp"
#endif
#include <stack>
#include <vector>
#include "stack.hpp"
#include "vector.hpp"

class StackTest : public ::testing::Test
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
			st_stack_.push(10); st_stack_.push(20); st_stack_.push(30);
			ft_stack_.push(10); ft_stack_.push(20); ft_stack_.push(30);
		}
		virtual void TearDown()
		{
		}

		void	SetupStackForRelationalOpe()
		{
			st_large_.push(10);	st_large_.push(200); st_large_.push(30);
			ft_large_.push(10);	ft_large_.push(200); ft_large_.push(30);
			st_small_.push(10);	st_small_.push(2);	 st_small_.push(30);
			ft_small_.push(10);	ft_small_.push(2);	 ft_small_.push(30);
			st_more_.push(10);	st_more_.push(20);	 st_more_.push(30);	 st_more_.push(40);
			ft_more_.push(10);	ft_more_.push(20);	 ft_more_.push(30);	 ft_more_.push(40);
			st_less_.push(10);	st_less_.push(20);
			ft_less_.push(10);	ft_less_.push(20);
		}

		template <class T, class Container1, class Container2>
		void CompareSizeTop(
			const std::stack<T, Container1>& st_stack
			, const ft::stack<T, Container2>& ft_stack)
		{
			EXPECT_EQ(st_stack.size(),	ft_stack.size());
			if (st_stack.size() > 0)
				EXPECT_EQ(st_stack.top(), 	ft_stack.top());
		}

		template <class Stack>
		void PrintStack(const Stack& stack)
		{
			std::cout << "size:  "	<< stack.size() << std::endl;
			std::cout << "top:   "	<< stack.top() << std::endl;
			std::cout << "empty: "	<< stack.empty() << std::endl;
		}

		static const int								nums[3];
		static const std::vector<int>					st_const_vec_;
		static const ft::vector<int>					ft_const_vec_;
		static const std::stack<int, std::vector<int> >	st_const_stack_;
		static const ft::stack<int, ft::vector<int> >	ft_const_stack_;
		std::stack<int, std::vector<int> >				st_stack_;
		ft::stack<int, ft::vector<int> >				ft_stack_;
		std::stack<int, std::vector<int> >				st_zero_stack_;
		ft::stack<int, ft::vector<int> >				ft_zero_stack_;

		std::stack<int, std::vector<int> >	st_large_;
		ft::stack<int, ft::vector<int> >	ft_large_;
		std::stack<int, std::vector<int> >	st_small_;
		ft::stack<int, ft::vector<int> >	ft_small_;
		std::stack<int, std::vector<int> >	st_more_;
		ft::stack<int, ft::vector<int> >	ft_more_;
		std::stack<int, std::vector<int> >	st_less_;
		ft::stack<int, ft::vector<int> >	ft_less_;
};

const int				StackTest::nums[3] = {10, 20, 30};
const std::vector<int>	StackTest::st_const_vec_(nums, nums + 3);
const ft::vector<int>	StackTest::ft_const_vec_(nums, nums + 3);
const std::stack<int, std::vector<int> >	StackTest::st_const_stack_(st_const_vec_);
const ft::stack<int, ft::vector<int> >		StackTest::ft_const_stack_(ft_const_vec_);

TEST_F(StackTest, DefaultConstructorTest)
{
	std::stack<int, std::vector<int> >	st_stack;
	ft::stack<int, ft::vector<int> >	ft_stack;
	CompareSizeTop(st_stack, ft_stack);
}

TEST_F(StackTest, CopyConstructorTest)
{
	std::stack<int, std::vector<int> >	st_stack(st_stack_);
	ft::stack<int, ft::vector<int> >	ft_stack(ft_stack_);
	CompareSizeTop(st_stack, ft_stack);

	std::stack<int, std::vector<int> >	st_zero_stack(st_zero_stack_);
	ft::stack<int, ft::vector<int> >	ft_zero_stack(ft_zero_stack_);
	CompareSizeTop(st_zero_stack, ft_zero_stack);

	std::stack<int, std::vector<int> >	st_vec_stack(st_const_vec_);
	ft::stack<int, ft::vector<int> >	ft_vec_stack(ft_const_vec_);
	CompareSizeTop(st_vec_stack, ft_vec_stack);
}

TEST_F(StackTest, OpeAssignTest)
{
	std::stack<int, std::vector<int> >	st_stack;	st_stack = st_stack_;
	ft::stack<int, ft::vector<int> >	ft_stack;	ft_stack = ft_stack_;
	CompareSizeTop(st_stack, ft_stack);

	std::stack<int, std::vector<int> >	st_zero_stack;	st_zero_stack = st_zero_stack_;
	ft::stack<int, ft::vector<int> >	ft_zero_stack;	ft_zero_stack = ft_zero_stack_;
	CompareSizeTop(st_zero_stack, ft_zero_stack);

	// std::stack<int, std::vector<int> >	st_vec_stack;	st_vec_stack = st_const_vec_;
	// ft::stack<int, ft::vector<int> >	ft_vec_stack;	ft_vec_stack = ft_const_vec_;
	// CompareSizeTop(st_vec_stack, ft_vec_stack);
}

TEST_F(StackTest, EmptyTest)
{
	EXPECT_EQ(st_stack_.empty(), ft_stack_.empty());
	EXPECT_EQ(st_zero_stack_.empty(), ft_zero_stack_.empty());
	EXPECT_EQ(st_const_stack_.empty(), ft_const_stack_.empty());

	st_stack_.pop(); st_stack_.pop(); st_stack_.pop();
	ft_stack_.pop(); ft_stack_.pop(); ft_stack_.pop();
	EXPECT_EQ(st_stack_.empty(), ft_stack_.empty());
}

TEST_F(StackTest, SizeTest)
{
	EXPECT_EQ(st_stack_.size(), ft_stack_.size());
	EXPECT_EQ(st_zero_stack_.size(), ft_zero_stack_.size());
	EXPECT_EQ(st_const_stack_.size(), ft_const_stack_.size());
}

TEST_F(StackTest, TopTest)
{
	EXPECT_EQ(st_stack_.top(), ft_stack_.top());
	EXPECT_EQ(st_const_stack_.top(), ft_const_stack_.top());
	// EXPECT_EQ(st_zero_stack_.top(), ft_zero_stack_.top());

	st_stack_.push(42);
	ft_stack_.push(42);
	EXPECT_EQ(st_stack_.top(), ft_stack_.top());
	st_stack_.pop();
	ft_stack_.pop();
	EXPECT_EQ(st_stack_.top(), ft_stack_.top());
}

TEST_F(StackTest, PushTest)
{
	st_stack_.push(42);
	ft_stack_.push(42);
	CompareSizeTop(st_stack_, ft_stack_);
	st_zero_stack_.push(42);
	ft_zero_stack_.push(42);
	CompareSizeTop(st_zero_stack_, ft_zero_stack_);
}

TEST_F(StackTest, PopTest)
{
	st_stack_.pop();
	ft_stack_.pop();
	CompareSizeTop(st_stack_, ft_stack_);
	st_stack_.pop();
	ft_stack_.pop();
	CompareSizeTop(st_stack_, ft_stack_);
	st_stack_.pop();
	ft_stack_.pop();
	CompareSizeTop(st_stack_, ft_stack_);
	// st_stack_.pop();
	// ft_stack_.pop();
	// CompareSizeTop(st_stack_, ft_stack_);
}

TEST_F(StackTest, OpeEqualTest)
{
	SetupStackForRelationalOpe();
	EXPECT_EQ(st_stack_ == st_stack_,	ft_stack_ == ft_stack_);
	EXPECT_EQ(st_stack_ == st_large_,	ft_stack_ == ft_large_);
	EXPECT_EQ(st_stack_ == st_small_,	ft_stack_ == ft_small_);
	EXPECT_EQ(st_stack_ == st_more_,	ft_stack_ == ft_more_);
	EXPECT_EQ(st_stack_ == st_less_,	ft_stack_ == ft_less_);
}

TEST_F(StackTest, OpeNotEqualTest)
{
	SetupStackForRelationalOpe();
	EXPECT_EQ(st_stack_ != st_stack_,	ft_stack_ != ft_stack_);
	EXPECT_EQ(st_stack_ != st_large_,	ft_stack_ != ft_large_);
	EXPECT_EQ(st_stack_ != st_small_,	ft_stack_ != ft_small_);
	EXPECT_EQ(st_stack_ != st_more_,	ft_stack_ != ft_more_);
	EXPECT_EQ(st_stack_ != st_less_,	ft_stack_ != ft_less_);
}

TEST_F(StackTest, OpeLessTest)
{
	SetupStackForRelationalOpe();
	EXPECT_EQ(st_stack_ < st_stack_,	ft_stack_ < ft_stack_);
	EXPECT_EQ(st_stack_ < st_large_,	ft_stack_ < ft_large_);
	EXPECT_EQ(st_stack_ < st_small_,	ft_stack_ < ft_small_);
	EXPECT_EQ(st_stack_ < st_more_,		ft_stack_ < ft_more_);
	EXPECT_EQ(st_stack_ < st_less_,		ft_stack_ < ft_less_);
}

TEST_F(StackTest, OpeLessEqualTest)
{
	SetupStackForRelationalOpe();
	EXPECT_EQ(st_stack_ <= st_stack_,	ft_stack_ <= ft_stack_);
	EXPECT_EQ(st_stack_ <= st_large_,	ft_stack_ <= ft_large_);
	EXPECT_EQ(st_stack_ <= st_small_,	ft_stack_ <= ft_small_);
	EXPECT_EQ(st_stack_ <= st_more_,	ft_stack_ <= ft_more_);
	EXPECT_EQ(st_stack_ <= st_less_,	ft_stack_ <= ft_less_);
}

TEST_F(StackTest, OpeGreaterTest)
{
	SetupStackForRelationalOpe();
	EXPECT_EQ(st_stack_ > st_stack_,	ft_stack_ > ft_stack_);
	EXPECT_EQ(st_stack_ > st_large_,	ft_stack_ > ft_large_);
	EXPECT_EQ(st_stack_ > st_small_,	ft_stack_ > ft_small_);
	EXPECT_EQ(st_stack_ > st_more_,		ft_stack_ > ft_more_);
	EXPECT_EQ(st_stack_ > st_less_,		ft_stack_ > ft_less_);
}

TEST_F(StackTest, OpeGreaterEqualTest)
{
	SetupStackForRelationalOpe();
	EXPECT_EQ(st_stack_ >= st_stack_,	ft_stack_ >= ft_stack_);
	EXPECT_EQ(st_stack_ >= st_large_,	ft_stack_ >= ft_large_);
	EXPECT_EQ(st_stack_ >= st_small_,	ft_stack_ >= ft_small_);
	EXPECT_EQ(st_stack_ >= st_more_,	ft_stack_ >= ft_more_);
	EXPECT_EQ(st_stack_ >= st_less_,	ft_stack_ >= ft_less_);
}
