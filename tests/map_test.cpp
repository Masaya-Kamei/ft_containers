#include <gtest/gtest.h>
#include <map>
#include <string>
#include "map.hpp"

class MapTest : public ::testing::Test
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

		// template <class T1, class T2>
		// void CompareSizeCapElem(const std::map<T1, T2>& st_map, const ft::map<T1, T2>& ft_map)
		// {
		// 	typename std::map<T>::const_iterator	st_itr = st_map.begin();
		// 	typename ft::map<T>::const_iterator		ft_itr = ft_map.begin();
		// 	typename std::map<T>::const_iterator	st_end = st_map.end();

		// 	EXPECT_EQ(st_map.size(),		ft_map.size());
		// 	EXPECT_EQ(st_map.max_size(),	ft_map.max_size());
		// 	EXPECT_EQ(st_map.empty(),		ft_map.empty());
		// 	for (; st_itr < st_end; st_itr++, ft_itr++)
		// 		EXPECT_EQ(*st_itr, *ft_itr);
		// }

		template <class Map>
		void PrintMap(const Map& map)
		{
			typename Map::const_iterator	itr = map.begin();
			typename Map::const_iterator	end = map.end();

			std::cout << "size:     "	<< map.size() << std::endl;
			std::cout << "max_size: "	<< map.max_size() << std::endl;
			std::cout << "empty:    "	<< map.empty() << std::endl;
			std::cout << "elem:     [";
			for (; itr != end; itr++)
				std::cout << "{" << itr->first << ", " << itr->second << "}" << ", ";
			std::cout << "]" << std::endl;
		}
};

TEST_F(MapTest, DefaultConstructorTest)
{
	std::map<int, std::string>	st_map;
	ft::map<int, std::string>	ft_map;

	// CompareSizeCapElem(st_map, ft_map);
	st_map.insert(std::make_pair(42, "Hello"));
	PrintMap(st_map);
}

