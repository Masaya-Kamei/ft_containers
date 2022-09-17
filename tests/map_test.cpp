#ifndef TESTLIB
# include <gtest/gtest.h>
#else
# include "testlib.hpp"
#endif
#include <map>
#include <string>
#include <iostream>
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
			// st_map_.insert(st_pairs_, st_pairs_ + 3);
			// ft_map_.insert(ft_pairs_, ft_pairs_ + 3);
		}
		virtual void TearDown()
		{
		}

		template <class T1, class T2>
		void CompareSizeCapElem(std::map<T1, T2>& st_map, ft::map<T1, T2>& ft_map)
		{
			typename std::map<T1, T2>::iterator	st_itr = st_map.begin();
			typename ft::map<T1, T2>::iterator	ft_itr = ft_map.begin();
			typename std::map<T1, T2>::iterator	st_end = st_map.end();

			EXPECT_EQ(st_map.size(),	ft_map.size());
			EXPECT_EQ(st_map.empty(),	ft_map.empty());
			for (; st_itr != st_end; ++st_itr, ++ft_itr)
			{
				EXPECT_EQ(st_itr->first,	ft_itr->first);
				EXPECT_EQ(st_itr->second,	ft_itr->second);
			}
		}

		template <class Iter1, class Iter2>
		void	CompareInsertReturn(std::pair<Iter1, bool> st_ret, ft::pair<Iter2, bool> ft_ret)
		{
			EXPECT_EQ((st_ret.first)->first, (ft_ret.first)->first);
			EXPECT_EQ((st_ret.first)->second, (ft_ret.first)->second);
			EXPECT_EQ(st_ret.second, ft_ret.second);
		}

		template <class Map>
		void PrintMap(const Map& map)
		{
			typename Map::const_iterator	itr = map.begin();
			typename Map::const_iterator	end = map.end();

			std::cout << "size:     "	<< map.size() << std::endl;
			std::cout << "empty:    "	<< map.empty() << std::endl;
			std::cout << "elem:     [";
			for (; itr != end; itr++)
				std::cout << "{" << itr->first << ", " << itr->second << "}" << ", ";
			std::cout << "]" << std::endl;
		}

		static const std::pair<int, std::string>	st_pairs_[3];
		static const ft::pair<int, std::string>		ft_pairs_[3];
		// std::map<int, std::string>	st_map_;
		// ft::map<int, std::string>	ft_map_;
};

const std::pair<int, std::string>	MapTest::st_pairs_[3]
	= {std::make_pair(1, "A"), std::make_pair(2, "B"), std::make_pair(3, "C")};
const ft::pair<int, std::string>	MapTest::ft_pairs_[3]
	= {ft::make_pair(1, "A"), ft::make_pair(2, "B"), ft::make_pair(3, "C")};


TEST_F(MapTest, DefaultConstructorTest)
{
	std::map<int, std::string>	st_map;
	ft::map<int, std::string>	ft_map;
	CompareSizeCapElem(st_map, ft_map);
}

TEST_F(MapTest, RangeConstructorTest)
{
	std::map<int, std::string>	st_map(st_pairs_, st_pairs_ + 3);
	ft::map<int, std::string>	ft_map(ft_pairs_, ft_pairs_ + 3);
	CompareSizeCapElem(st_map, ft_map);
}

TEST_F(MapTest, InsertSingleTest)
{
	std::map<int, std::string>	st_map;
	ft::map<int, std::string>	ft_map;
	std::pair<std::map<int, std::string>::iterator, bool>	st_ret;
	ft::pair<ft::map<int, std::string>::iterator, bool>		ft_ret;

	st_ret = st_map.insert(std::make_pair(1, "A"));
	ft_ret = ft_map.insert(ft::make_pair(1, "A"));
	CompareInsertReturn(st_ret, ft_ret);

	st_ret = st_map.insert(std::make_pair(3, "C"));
	ft_ret = ft_map.insert(ft::make_pair(3, "C"));
	CompareInsertReturn(st_ret, ft_ret);

	st_ret = st_map.insert(std::make_pair(4, "D"));
	ft_ret = ft_map.insert(ft::make_pair(4, "D"));
	CompareInsertReturn(st_ret, ft_ret);

	st_ret = st_map.insert(std::make_pair(2, "B"));
	ft_ret = ft_map.insert(ft::make_pair(2, "B"));
	CompareInsertReturn(st_ret, ft_ret);

	st_ret = st_map.insert(std::make_pair(1, "Z"));
	ft_ret = ft_map.insert(ft::make_pair(1, "Z"));
	CompareInsertReturn(st_ret, ft_ret);

	CompareSizeCapElem(st_map, ft_map);
}

TEST_F(MapTest, MaxSizeTest)
{
	typedef ft::avl_tree_node<ft::pair<int, std::string> > node_type;
	ft::map<int, std::string>	ft_map;
	std::allocator<node_type>	alloc;
	EXPECT_EQ(ft_map.max_size(), alloc.max_size());
}
