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

		void SetupMapForRelationalOpe()
		{
			st_large_.insert(st_map_.begin(), st_map_.end());
			st_large_.erase(20);	st_large_.insert(std::make_pair(22, "X"));
			ft_large_.insert(ft_map_.begin(), ft_map_.end());
			ft_large_.erase(20);	ft_large_.insert(ft::make_pair(22, "X"));

			st_small_.insert(st_map_.begin(), st_map_.end());
			st_small_.erase(20);	st_small_.insert(std::make_pair(18, "X"));
			ft_small_.insert(ft_map_.begin(), ft_map_.end());
			ft_small_.erase(20);	ft_small_.insert(ft::make_pair(18, "X"));

			st_more_.insert(st_map_.begin(),  st_map_.end());
			st_more_.insert(std::make_pair(130, "X"));
			ft_more_.insert(ft_map_.begin(),  ft_map_.end());
			ft_more_.insert(ft::make_pair(130, "X"));

			st_less_.insert(st_map_.begin(),  st_map_.end());
			st_less_.erase(120);
			ft_less_.insert(ft_map_.begin(),  ft_map_.end());
			ft_less_.erase(120);
		}

		template <class T1, class T2>
		void CompareSizeCapElem(const std::map<T1, T2>& st_map, const ft::map<T1, T2>& ft_map)
		{
			typename std::map<T1, T2>::const_iterator	st_itr = st_map.begin();
			typename ft::map<T1, T2>::const_iterator	ft_itr = ft_map.begin();
			typename std::map<T1, T2>::const_iterator	st_end = st_map.end();

			EXPECT_EQ(st_map.size(),	ft_map.size());
			EXPECT_EQ(st_map.empty(),	ft_map.empty());
			for (; st_itr != st_end; ++st_itr, ++ft_itr)
			{
				EXPECT_EQ(st_itr->first,	ft_itr->first);
				EXPECT_EQ(st_itr->second,	ft_itr->second);
			}
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
		static const std::map<int, std::string>		st_const_map_;
		static const ft::map<int, std::string>		ft_const_map_;
		std::map<int, std::string>	st_map_;
		ft::map<int, std::string>	ft_map_;
		unsigned int				seed_;

		std::map<int, std::string>	st_large_;
		ft::map<int, std::string>	ft_large_;
		std::map<int, std::string>	st_small_;
		ft::map<int, std::string>	ft_small_;
		std::map<int, std::string>	st_more_;
		ft::map<int, std::string>	ft_more_;
		std::map<int, std::string>	st_less_;
		ft::map<int, std::string>	ft_less_;
};

const std::pair<int, std::string>	MapTest::st_pairs_[12]
	= {std::make_pair(90, "I"), std::make_pair(20, "B"), std::make_pair(110, "K")
		, std::make_pair(80, "H"), std::make_pair(50, "E"), std::make_pair(60, "F")
		, std::make_pair(120, "L"), std::make_pair(40, "D"), std::make_pair(10, "A")
		, std::make_pair(100, "J"), std::make_pair(30, "C"), std::make_pair(70, "G")};
const ft::pair<int, std::string>	MapTest::ft_pairs_[12]
	= {ft::make_pair(90, "I"), ft::make_pair(20, "B"), ft::make_pair(110, "K")
		, ft::make_pair(80, "H"), ft::make_pair(50, "E"), ft::make_pair(60, "F")
		, ft::make_pair(120, "L"), ft::make_pair(40, "D"), ft::make_pair(10, "A")
		, ft::make_pair(100, "J"), ft::make_pair(30, "C"), ft::make_pair(70, "G")};
const std::map<int, std::string>	MapTest::st_const_map_(st_pairs_, &st_pairs_[12]);
const ft::map<int, std::string>		MapTest::ft_const_map_(ft_pairs_, &ft_pairs_[12]);


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

	std::map<int, std::string>	st_zero_map(st_pairs_, st_pairs_);
	ft::map<int, std::string>	ft_zero_map(ft_pairs_, ft_pairs_);
	CompareSizeCapElem(st_zero_map, ft_zero_map);
}

TEST_F(MapTest, CopyConstructorTest)
{
	std::map<int, std::string>	st_map_copy(st_map_);
	ft::map<int, std::string>	ft_map_copy(ft_map_);
	CompareSizeCapElem(st_map_copy, ft_map_copy);
	EXPECT_NE(ft_map_.begin(), ft_map_copy.begin());
}

TEST_F(MapTest, OpeAssignTest)
{
	std::map<int, std::string>	st_map_copy;	st_map_copy = st_map_;
	ft::map<int, std::string>	ft_map_copy;	ft_map_copy = ft_map_;
	CompareSizeCapElem(st_map_copy, ft_map_copy);
	EXPECT_NE(ft_map_.begin(), ft_map_copy.begin());
}

TEST_F(MapTest, OpeBracketsTest)
{
	EXPECT_EQ(st_map_[10], ft_map_[10]);
	EXPECT_EQ(st_map_[-1], ft_map_[-1]);
	// EXPECT_EQ(st_const_map_[10], ft_const_map_[10]);
	// EXPECT_EQ(st_const_map_[-1], ft_const_map_[-1]);
	CompareSizeCapElem(st_map_, ft_map_);
}

TEST_F(MapTest, InsertSingleTest)
{
	std::map<int, std::string>	st_map;
	ft::map<int, std::string>	ft_map;
	std::pair<std::map<int, std::string>::iterator, bool>	st_ret;
	ft::pair<ft::map<int, std::string>::iterator, bool>		ft_ret;

	st_ret = st_map.insert(std::make_pair(1, "A"));
	ft_ret = ft_map.insert(ft::make_pair(1, "A"));
	EXPECT_EQ((st_ret.first)->first, (ft_ret.first)->first);
	EXPECT_EQ(st_ret.second, ft_ret.second);
	st_ret = st_map.insert(std::make_pair(3, "C"));
	ft_ret = ft_map.insert(ft::make_pair(3, "C"));
	EXPECT_EQ((st_ret.first)->first, (ft_ret.first)->first);
	EXPECT_EQ(st_ret.second, ft_ret.second);
	st_ret = st_map.insert(std::make_pair(4, "D"));
	ft_ret = ft_map.insert(ft::make_pair(4, "D"));
	EXPECT_EQ((st_ret.first)->first, (ft_ret.first)->first);
	EXPECT_EQ(st_ret.second, ft_ret.second);
	st_ret = st_map.insert(std::make_pair(2, "B"));
	ft_ret = ft_map.insert(ft::make_pair(2, "B"));
	EXPECT_EQ((st_ret.first)->first, (ft_ret.first)->first);
	EXPECT_EQ(st_ret.second, ft_ret.second);
	st_ret = st_map.insert(std::make_pair(1, "Z"));
	ft_ret = ft_map.insert(ft::make_pair(1, "Z"));
	EXPECT_EQ((st_ret.first)->first, (ft_ret.first)->first);
	EXPECT_EQ(st_ret.second, ft_ret.second);

	CompareSizeCapElem(st_map, ft_map);
}

TEST_F(MapTest, InsertHintTest)
{
	std::map<int, std::string>::iterator	st_ret;
	ft::map<int, std::string>::iterator		ft_ret;

	st_ret = st_map_.insert(++(++(++st_map_.begin())), std::make_pair(42, "X"));
	ft_ret = ft_map_.insert(++(++(++ft_map_.begin())), ft::make_pair(42, "X"));
	EXPECT_EQ(st_ret->first, ft_ret->first);
	st_ret = st_map_.insert(++(++(++st_map_.begin())), std::make_pair(-1, "X"));
	ft_ret = ft_map_.insert(++(++(++ft_map_.begin())), ft::make_pair(-1, "X"));
	EXPECT_EQ(st_ret->first, ft_ret->first);
	st_ret = st_map_.insert(++(++(++st_map_.begin())), std::make_pair(142, "X"));
	ft_ret = ft_map_.insert(++(++(++ft_map_.begin())), ft::make_pair(142, "X"));
	EXPECT_EQ(st_ret->first, ft_ret->first);
	st_ret = st_map_.insert(++(++(++st_map_.begin())), std::make_pair(50, "X"));
	ft_ret = ft_map_.insert(++(++(++ft_map_.begin())), ft::make_pair(50, "X"));
	EXPECT_EQ(st_ret->first, ft_ret->first);

	st_ret = st_map_.insert(st_map_.begin(), std::make_pair(43, "X"));
	ft_ret = ft_map_.insert(ft_map_.begin(), ft::make_pair(43, "X"));
	EXPECT_EQ(st_ret->first, ft_ret->first);
	st_ret = st_map_.insert(st_map_.begin(), std::make_pair(-2, "X"));
	ft_ret = ft_map_.insert(ft_map_.begin(), ft::make_pair(-2, "X"));
	EXPECT_EQ(st_ret->first, ft_ret->first);
	st_ret = st_map_.insert(st_map_.begin(), std::make_pair(143, "X"));
	ft_ret = ft_map_.insert(ft_map_.begin(), ft::make_pair(143, "X"));
	EXPECT_EQ(st_ret->first, ft_ret->first);
	st_ret = st_map_.insert(st_map_.begin(), std::make_pair(50, "X"));
	ft_ret = ft_map_.insert(ft_map_.begin(), ft::make_pair(50, "X"));
	EXPECT_EQ(st_ret->first, ft_ret->first);

	st_ret = st_map_.insert(st_map_.end(), std::make_pair(44, "X"));
	ft_ret = ft_map_.insert(ft_map_.end(), ft::make_pair(44, "X"));
	EXPECT_EQ(st_ret->first, ft_ret->first);
	st_ret = st_map_.insert(st_map_.end(), std::make_pair(-3, "X"));
	ft_ret = ft_map_.insert(ft_map_.end(), ft::make_pair(-3, "X"));
	EXPECT_EQ(st_ret->first, ft_ret->first);
	st_ret = st_map_.insert(st_map_.end(), std::make_pair(144, "X"));
	ft_ret = ft_map_.insert(ft_map_.end(), ft::make_pair(144, "X"));
	EXPECT_EQ(st_ret->first, ft_ret->first);
	st_ret = st_map_.insert(st_map_.end(), std::make_pair(50, "X"));
	ft_ret = ft_map_.insert(ft_map_.end(), ft::make_pair(50, "X"));
	EXPECT_EQ(st_ret->first, ft_ret->first);

	CompareSizeCapElem(st_map_, ft_map_);
}

TEST_F(MapTest, EraseSingleIteratorTest)
{
	// st_map_.erase(st_map_.end());
	// ft_map_.erase(ft_map_.end());

	for (int i = 0; i < 12; ++i)
	{
		std::map<int, std::string>::iterator	st_erase_itr = st_map_.begin();
		ft::map<int, std::string>::iterator		ft_erase_itr = ft_map_.begin();
		int		distance = rand_r(&seed_) % st_map_.size();
		std::advance(st_erase_itr, distance);
		std::advance(ft_erase_itr, distance);
		st_map_.erase(st_erase_itr);
		ft_map_.erase(ft_erase_itr);
		CompareSizeCapElem(st_map_, ft_map_);
	}
}

TEST_F(MapTest, SwapTest)
{
	std::map<int, std::string>::iterator	st_begin = st_map_.begin();
	ft::map<int, std::string>::iterator		ft_begin = ft_map_.begin();
	std::map<int, std::string>				st_map2(st_pairs_, st_pairs_ + 5);
	ft::map<int, std::string>				ft_map2(ft_pairs_, ft_pairs_ + 5);
	st_map_.swap(st_map2);
	ft_map_.swap(ft_map2);
	CompareSizeCapElem(st_map_,	ft_map_);
	CompareSizeCapElem(st_map2,	ft_map2);
	EXPECT_EQ(st_begin == st_map2.begin(), ft_begin == ft_map2.begin());

	std::map<int, std::string>	st_zero_map;
	ft::map<int, std::string>	ft_zero_map;
	st_map_.swap(st_zero_map);
	ft_map_.swap(ft_zero_map);
	CompareSizeCapElem(st_map_,		ft_map_);
	CompareSizeCapElem(st_zero_map,	ft_zero_map);
}

TEST_F(MapTest, ClearTest)
{
	st_map_.clear();
	ft_map_.clear();
	CompareSizeCapElem(st_map_, ft_map_);

	st_map_.insert(st_pairs_, st_pairs_ + 12);
	ft_map_.insert(ft_pairs_, ft_pairs_ + 12);
	CompareSizeCapElem(st_map_, ft_map_);

	std::map<int, std::string>	st_zero_map;
	ft::map<int, std::string>	ft_zero_map;
	st_zero_map.clear();
	ft_zero_map.clear();
	CompareSizeCapElem(st_zero_map, ft_zero_map);
}

TEST_F(MapTest, KeyCompTest)
{
	std::map<int, std::string>::key_compare	st_key_comp = st_map_.key_comp();
	ft::map<int, std::string>::key_compare	ft_key_comp = ft_map_.key_comp();
	EXPECT_EQ(st_key_comp(1, 1), ft_key_comp(1, 1));
	EXPECT_EQ(st_key_comp(1, 2), ft_key_comp(1, 2));
	EXPECT_EQ(st_key_comp(2, 1), ft_key_comp(2, 1));
}

TEST_F(MapTest, ValueCompTest)
{
	std::map<int, std::string>::value_compare	st_value_comp = st_map_.value_comp();
	ft::map<int, std::string>::value_compare	ft_value_comp = ft_map_.value_comp();
	EXPECT_EQ(st_value_comp(st_pairs_[0], st_pairs_[0]), ft_value_comp(ft_pairs_[0], ft_pairs_[0]));
	EXPECT_EQ(st_value_comp(st_pairs_[0], st_pairs_[1]), ft_value_comp(ft_pairs_[0], ft_pairs_[1]));
	EXPECT_EQ(st_value_comp(st_pairs_[1], st_pairs_[0]), ft_value_comp(ft_pairs_[1], ft_pairs_[0]));
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
	EXPECT_EQ((st_map_.find(50))->first,  (ft_map_.find(50))->first);
	EXPECT_EQ((st_map_.find(60))->first,  (ft_map_.find(60))->first);
	EXPECT_EQ((st_map_.find(10))->first,  (ft_map_.find(10))->first);
	EXPECT_EQ((st_map_.find(120))->first, (ft_map_.find(120))->first);
	EXPECT_EQ(st_map_.find(42), st_map_.end());
	EXPECT_EQ(ft_map_.find(42), ft_map_.end());

	EXPECT_EQ((st_const_map_.find(50))->first,  (ft_const_map_.find(50))->first);
	EXPECT_EQ((st_const_map_.find(60))->first,  (ft_const_map_.find(60))->first);
	EXPECT_EQ((st_const_map_.find(10))->first,  (ft_const_map_.find(10))->first);
	EXPECT_EQ((st_const_map_.find(120))->first, (ft_const_map_.find(120))->first);
	EXPECT_EQ(st_const_map_.find(42), st_const_map_.end());
	EXPECT_EQ(ft_const_map_.find(42), ft_const_map_.end());
}

TEST_F(MapTest, CountTest)
{
	EXPECT_EQ(st_map_.count(50),  ft_map_.count(50));
	EXPECT_EQ(st_map_.count(60),  ft_map_.count(60));
	EXPECT_EQ(st_map_.count(10),  ft_map_.count(10));
	EXPECT_EQ(st_map_.count(120), ft_map_.count(120));
	EXPECT_EQ(st_map_.count(42), ft_map_.count(42));

	EXPECT_EQ(st_const_map_.count(50),  ft_const_map_.count(50));
	EXPECT_EQ(st_const_map_.count(60),  ft_const_map_.count(60));
	EXPECT_EQ(st_const_map_.count(10),  ft_const_map_.count(10));
	EXPECT_EQ(st_const_map_.count(120), ft_const_map_.count(120));
	EXPECT_EQ(st_const_map_.count(42), ft_const_map_.count(42));
}

TEST_F(MapTest, LowerBoundTest)
{
	EXPECT_EQ((st_map_.lower_bound(42))->first, (ft_map_.lower_bound(42))->first);
	EXPECT_EQ((st_map_.lower_bound(60))->first, (ft_map_.lower_bound(60))->first);
	EXPECT_EQ((st_map_.lower_bound(1))->first,  (ft_map_.lower_bound(1))->first);
	EXPECT_EQ(st_map_.lower_bound(420), st_map_.end());
	EXPECT_EQ(ft_map_.lower_bound(420), ft_map_.end());

	EXPECT_EQ((st_const_map_.lower_bound(42))->first, (ft_const_map_.lower_bound(42))->first);
	EXPECT_EQ((st_const_map_.lower_bound(60))->first, (ft_const_map_.lower_bound(60))->first);
	EXPECT_EQ((st_const_map_.lower_bound(1))->first,  (ft_const_map_.lower_bound(1))->first);
	EXPECT_EQ(st_const_map_.lower_bound(420), st_const_map_.end());
	EXPECT_EQ(ft_const_map_.lower_bound(420), ft_const_map_.end());
}

TEST_F(MapTest, UpperBoundTest)
{
	EXPECT_EQ((st_map_.upper_bound(42))->first, (ft_map_.upper_bound(42))->first);
	EXPECT_EQ((st_map_.upper_bound(60))->first, (ft_map_.upper_bound(60))->first);
	EXPECT_EQ((st_map_.upper_bound(1))->first,  (ft_map_.upper_bound(1))->first);
	EXPECT_EQ(st_map_.upper_bound(420), st_map_.end());
	EXPECT_EQ(ft_map_.upper_bound(420), ft_map_.end());

	EXPECT_EQ((st_const_map_.upper_bound(42))->first, (ft_const_map_.upper_bound(42))->first);
	EXPECT_EQ((st_const_map_.upper_bound(60))->first, (ft_const_map_.upper_bound(60))->first);
	EXPECT_EQ((st_const_map_.upper_bound(1))->first,  (ft_const_map_.upper_bound(1))->first);
	EXPECT_EQ(st_const_map_.upper_bound(420), st_const_map_.end());
	EXPECT_EQ(ft_const_map_.upper_bound(420), ft_const_map_.end());
}

TEST_F(MapTest, EqualRangeTest)
{
	typedef std::map<int, std::string>::iterator	st_iterator;
	typedef ft::map<int, std::string>::iterator		ft_iterator;
	std::pair<st_iterator, st_iterator>		st_ret;
	ft::pair<ft_iterator, ft_iterator>		ft_ret;

	st_ret = st_map_.equal_range(30);
	ft_ret = ft_map_.equal_range(30);
	EXPECT_EQ(st_ret.first->first, ft_ret.first->first);
	EXPECT_EQ(st_ret.second->first, ft_ret.second->first);
	EXPECT_EQ((++(ft_ret.first))->first, ft_ret.second->first);
	st_ret = st_map_.equal_range(42);
	ft_ret = ft_map_.equal_range(42);
	EXPECT_EQ(st_ret.first->first, ft_ret.first->first);
	EXPECT_EQ(st_ret.second->first, ft_ret.second->first);
	EXPECT_EQ(ft_ret.first->first, ft_ret.second->first);
	st_ret = st_map_.equal_range(120);
	ft_ret = ft_map_.equal_range(120);
	EXPECT_EQ(st_ret.first->first, ft_ret.first->first);
	EXPECT_EQ(st_ret.second, st_map_.end());
	EXPECT_EQ(ft_ret.second, ft_map_.end());
	st_ret = st_map_.equal_range(1);
	ft_ret = ft_map_.equal_range(1);
	EXPECT_EQ(st_ret.first->first, ft_ret.first->first);
	EXPECT_EQ(st_ret.second->first, ft_ret.second->first);
	EXPECT_EQ(ft_ret.first->first, ft_ret.second->first);
	st_ret = st_map_.equal_range(122);
	ft_ret = ft_map_.equal_range(122);
	EXPECT_EQ(st_ret.first, st_map_.end());
	EXPECT_EQ(ft_ret.first, ft_map_.end());
	EXPECT_EQ(st_ret.second, st_map_.end());
	EXPECT_EQ(ft_ret.second, ft_map_.end());

	typedef std::map<int, std::string>::const_iterator	st_const_iterator;
	typedef ft::map<int, std::string>::const_iterator	ft_const_iterator;
	std::pair<st_const_iterator, st_const_iterator>		st_const_ret;
	ft::pair<ft_const_iterator,  ft_const_iterator>		ft_const_ret;
	st_const_ret = st_const_map_.equal_range(30);
	ft_const_ret = ft_const_map_.equal_range(30);
	EXPECT_EQ(st_const_ret.first->first,		ft_const_ret.first->first);
	EXPECT_EQ(st_const_ret.second->first,		ft_const_ret.second->first);
	EXPECT_EQ((++(ft_const_ret.first))->first,	ft_const_ret.second->first);
}

TEST_F(MapTest, GetAllocatorTest)
{
	std::allocator<ft::pair<const int, std::string>	> alloc;
	EXPECT_EQ(alloc, ft_map_.get_allocator());
	EXPECT_EQ(st_map_.get_allocator(), ft_map_.get_allocator());
}

TEST_F(MapTest, OpeEqualTest)
{
	SetupMapForRelationalOpe();
	EXPECT_EQ(st_map_ == st_map_,	ft_map_ == ft_map_);
	EXPECT_EQ(st_map_ == st_large_,	ft_map_ == ft_large_);
	EXPECT_EQ(st_map_ == st_small_,	ft_map_ == ft_small_);
	EXPECT_EQ(st_map_ == st_more_,	ft_map_ == ft_more_);
	EXPECT_EQ(st_map_ == st_less_,	ft_map_ == ft_less_);
}

TEST_F(MapTest, OpeNotEqualTest)
{
	SetupMapForRelationalOpe();
	EXPECT_EQ(st_map_ != st_map_,	ft_map_ != ft_map_);
	EXPECT_EQ(st_map_ != st_large_,	ft_map_ != ft_large_);
	EXPECT_EQ(st_map_ != st_small_,	ft_map_ != ft_small_);
	EXPECT_EQ(st_map_ != st_more_,	ft_map_ != ft_more_);
	EXPECT_EQ(st_map_ != st_less_,	ft_map_ != ft_less_);
}

TEST_F(MapTest, OpeLessTest)
{
	SetupMapForRelationalOpe();
	EXPECT_EQ(st_map_ < st_map_,	ft_map_ < ft_map_);
	EXPECT_EQ(st_map_ < st_large_,	ft_map_ < ft_large_);
	EXPECT_EQ(st_map_ < st_small_,	ft_map_ < ft_small_);
	EXPECT_EQ(st_map_ < st_more_,	ft_map_ < ft_more_);
	EXPECT_EQ(st_map_ < st_less_,	ft_map_ < ft_less_);
}

TEST_F(MapTest, OpeLessEqualTest)
{
	SetupMapForRelationalOpe();
	EXPECT_EQ(st_map_ <= st_map_,	ft_map_ <= ft_map_);
	EXPECT_EQ(st_map_ <= st_large_,	ft_map_ <= ft_large_);
	EXPECT_EQ(st_map_ <= st_small_,	ft_map_ <= ft_small_);
	EXPECT_EQ(st_map_ <= st_more_,	ft_map_ <= ft_more_);
	EXPECT_EQ(st_map_ <= st_less_,	ft_map_ <= ft_less_);
}

TEST_F(MapTest, OpeGreaterTest)
{
	SetupMapForRelationalOpe();
	EXPECT_EQ(st_map_ > st_map_,	ft_map_ > ft_map_);
	EXPECT_EQ(st_map_ > st_large_,	ft_map_ > ft_large_);
	EXPECT_EQ(st_map_ > st_small_,	ft_map_ > ft_small_);
	EXPECT_EQ(st_map_ > st_more_,	ft_map_ > ft_more_);
	EXPECT_EQ(st_map_ > st_less_,	ft_map_ > ft_less_);
}

TEST_F(MapTest, OpeGreaterEqualTest)
{
	SetupMapForRelationalOpe();
	EXPECT_EQ(st_map_ >= st_map_,	ft_map_ >= ft_map_);
	EXPECT_EQ(st_map_ >= st_large_,	ft_map_ >= ft_large_);
	EXPECT_EQ(st_map_ >= st_small_,	ft_map_ >= ft_small_);
	EXPECT_EQ(st_map_ >= st_more_,	ft_map_ >= ft_more_);
	EXPECT_EQ(st_map_ >= st_less_,	ft_map_ >= ft_less_);
}

TEST_F(MapTest, NonMemberSwapTest)
{
	std::map<int, std::string>::iterator	st_begin = st_map_.begin();
	ft::map<int, std::string>::iterator		ft_begin = ft_map_.begin();
	std::map<int, std::string>	st_map2(st_pairs_, st_pairs_ + 5);
	ft::map<int, std::string>	ft_map2(ft_pairs_, ft_pairs_ + 5);
	swap(st_map_, st_map2);
	swap(ft_map_, ft_map2);
	CompareSizeCapElem(st_map_,	ft_map_);
	CompareSizeCapElem(st_map2,	ft_map2);
	EXPECT_EQ(st_begin == st_map2.begin(), ft_begin == ft_map2.begin());

	std::map<int, std::string>	st_zero_map;
	ft::map<int, std::string>	ft_zero_map;
	swap(st_map_, st_zero_map);
	swap(ft_map_, ft_zero_map);
	CompareSizeCapElem(st_map_,		ft_map_);
	CompareSizeCapElem(st_zero_map,	ft_zero_map);

	// const std::map<int, std::string>	st_const_map;
	// const ft::map<int, std::string>		ft_const_map;
	// swap(st_map_, st_const_map);
	// swap(ft_map_, ft_const_map);
}
