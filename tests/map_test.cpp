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
			seed_ = time(NULL);
			srand(seed_);
			st_map_.insert(st_pairs_, st_pairs_ + 12);
			ft_map_.insert(ft_pairs_, ft_pairs_ + 12);
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

		static const std::pair<int, std::string>	st_pairs_[12];
		static const ft::pair<int, std::string>		ft_pairs_[12];
		std::map<int, std::string>	st_map_;
		ft::map<int, std::string>	ft_map_;
		unsigned int				seed_;
};

const std::pair<int, std::string>	MapTest::st_pairs_[12]
	= {std::make_pair(9, "I"), std::make_pair(2, "B"), std::make_pair(11, "K")
		, std::make_pair(8, "H"), std::make_pair(5, "E"), std::make_pair(6, "F")
		, std::make_pair(12, "L"), std::make_pair(4, "D"), std::make_pair(1, "A")
		, std::make_pair(10, "J"), std::make_pair(3, "C"), std::make_pair(7, "G")};
const ft::pair<int, std::string>	MapTest::ft_pairs_[12]
	= {ft::make_pair(9, "I"), ft::make_pair(2, "B"), ft::make_pair(11, "K")
		, ft::make_pair(8, "H"), ft::make_pair(5, "E"), ft::make_pair(6, "F")
		, ft::make_pair(12, "L"), ft::make_pair(4, "D"), ft::make_pair(1, "A")
		, ft::make_pair(10, "J"), ft::make_pair(3, "C"), ft::make_pair(7, "G")};


TEST_F(MapTest, DefaultConstructorTest)
{
	std::map<int, std::string>	st_map;
	ft::map<int, std::string>	ft_map;
	CompareSizeCapElem(st_map, ft_map);
}

TEST_F(MapTest, RangeConstructorTest)
{
	std::map<int, std::string>	st_map(st_pairs_, st_pairs_ + 12);
	ft::map<int, std::string>	ft_map(ft_pairs_, ft_pairs_ + 12);
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

TEST_F(MapTest, EraseSingleIteratorTest)
{
	for (int i = 0; i < 12; ++i)
	{
		std::map<int, std::string>::iterator	st_erase_itr = st_map_.begin();
		ft::map<int, std::string>::iterator		ft_erase_itr = ft_map_.begin();
		for (int j = rand_r(&seed_) % (12 - i); j > 0; --j)
		{
			++st_erase_itr;
			++ft_erase_itr;
		}
		st_map_.erase(st_erase_itr);
		ft_map_.erase(ft_erase_itr);
		CompareSizeCapElem(st_map_, ft_map_);
	}
}

TEST_F(MapTest, MaxSizeTest)
{
	typedef ft::avl_tree_node<ft::pair<int, std::string> > node_type;
	ft::map<int, std::string>	ft_map;
	std::allocator<node_type>	alloc;
	EXPECT_EQ(ft_map.max_size(), alloc.max_size());
}

TEST_F(MapTest, FindTest)
{
	EXPECT_EQ((st_map_.find(5))->first, (ft_map_.find(5))->first);
	EXPECT_EQ((st_map_.find(6))->first, (ft_map_.find(6))->first);
	EXPECT_EQ((st_map_.find(1))->first, (ft_map_.find(1))->first);
	EXPECT_EQ((st_map_.find(12))->first, (ft_map_.find(12))->first);
	EXPECT_EQ(st_map_.find(42), st_map_.end());
	EXPECT_EQ(ft_map_.find(42), ft_map_.end());
}

// TEST_F(MapTest, CountTest)
// {
// 	EXPECT_EQ(st_map_.count(5), ft_map_.count(5));
// 	EXPECT_EQ(st_map_.count(6), ft_map_.count(6));
// 	EXPECT_EQ(st_map_.count(1), ft_map_.count(1));
// 	EXPECT_EQ(st_map_.count(12), ft_map_.count(12));
// 	EXPECT_EQ(st_map_.count(42), ft_map_.count(42));
// }

TEST_F(MapTest, LowerBoundTest)
{
	EXPECT_EQ((st_map_.lower_bound(5))->first, (ft_map_.lower_bound(5))->first);
	EXPECT_EQ((st_map_.lower_bound(6))->first, (ft_map_.lower_bound(6))->first);
	EXPECT_EQ((st_map_.lower_bound(1))->first, (ft_map_.lower_bound(1))->first);
	EXPECT_EQ((st_map_.lower_bound(12))->first, (ft_map_.lower_bound(12))->first);
	EXPECT_EQ(st_map_.lower_bound(42), st_map_.end());
	EXPECT_EQ(ft_map_.lower_bound(42), ft_map_.end());
}

TEST_F(MapTest, UpperBoundTest)
{
	EXPECT_EQ((st_map_.lower_bound(5))->first, (ft_map_.lower_bound(5))->first);
	EXPECT_EQ((st_map_.lower_bound(6))->first, (ft_map_.lower_bound(6))->first);
	EXPECT_EQ((st_map_.lower_bound(1))->first, (ft_map_.lower_bound(1))->first);
	EXPECT_EQ((st_map_.lower_bound(12))->first, (ft_map_.lower_bound(12))->first);
	EXPECT_EQ(st_map_.lower_bound(42), st_map_.end());
	EXPECT_EQ(ft_map_.lower_bound(42), ft_map_.end());
}
