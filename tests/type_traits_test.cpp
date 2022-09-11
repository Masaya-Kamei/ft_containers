#include <gtest/gtest.h>
#include "type_traits.hpp"

class TypeTraitsTest : public ::testing::Test
{
	protected:
		template <class T>
		bool IsEnable(T t)
		{
			(void)t;
			return (false);
		}
		template <class T>
		bool IsEnable(typename ft::enable_if<!ft::is_integral<T>::value, T>::type t)
		{
			(void)t;
			return (true);
		}
};

TEST_F(TypeTraitsTest, IsIntegralTest)
{
	EXPECT_EQ(std::is_integral<bool>::value,				ft::is_integral<bool>::value);
	EXPECT_EQ(std::is_integral<long>::value,				ft::is_integral<long>::value);
	EXPECT_EQ(std::is_integral<const int>::value,			ft::is_integral<const int>::value);
	EXPECT_EQ(std::is_integral<volatile int>::value,		ft::is_integral<volatile int>::value);
	EXPECT_EQ(std::is_integral<const volatile int>::value,	ft::is_integral<const volatile int>::value);
	EXPECT_EQ(std::is_integral<volatile const int>::value,	ft::is_integral<volatile const int>::value);

	EXPECT_EQ(std::is_integral<void *>::value, ft::is_integral<void *>::value);
	EXPECT_EQ(std::is_integral<char *>::value, ft::is_integral<char *>::value);
}

TEST_F(TypeTraitsTest, EnableIfTest)
{
	EXPECT_EQ(typeid(std::enable_if<true, int>::type), typeid(ft::enable_if<true, int>::type));
	// EXPECT_EQ(typeid(std::enable_if<false, int>::type), typeid(ft::enable_if<false, int>::type));
}

TEST_F(TypeTraitsTest, SFINAETest)
{
	EXPECT_EQ(IsEnable<int>(42), false);
	EXPECT_EQ(IsEnable<const int>(42), false);
	EXPECT_EQ(IsEnable<void *>(NULL), true);
	EXPECT_EQ(IsEnable<char *>(NULL), true);
}
