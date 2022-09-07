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
	bool b1 = ft::is_integral<bool>::value;
	EXPECT_EQ(b1, true);
	bool b2 = ft::is_integral<long>::value;
	EXPECT_EQ(b2, true);
	bool b3 = ft::is_integral<const int>::value;
	EXPECT_EQ(b3, true);
	bool b4 = ft::is_integral<volatile int>::value;
	EXPECT_EQ(b4, true);
	bool b5 = ft::is_integral<const volatile int>::value;
	EXPECT_EQ(b5, true);
	bool b6 = ft::is_integral<volatile const int>::value;
	EXPECT_EQ(b6, true);

	bool b7 = ft::is_integral<void *>::value;
	EXPECT_EQ(b7, false);
	bool b8 = ft::is_integral<char *>::value;
	EXPECT_EQ(b8, false);
}

TEST_F(TypeTraitsTest, EnableIfTest)
{
	EXPECT_EQ(typeid(ft::enable_if<true, int>::type), typeid(int));
	// EXPECT_EQ(typeid(ft::enable_if<false, int>::type), typeid(void));
}

TEST_F(TypeTraitsTest, SFINAETest)
{
	EXPECT_EQ(IsEnable<int>(42), false);
	EXPECT_EQ(IsEnable<const int>(42), false);
	EXPECT_EQ(IsEnable<void *>(NULL), true);
	EXPECT_EQ(IsEnable<char *>(NULL), true);
}
