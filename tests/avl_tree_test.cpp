#ifndef TESTLIB
# include <gtest/gtest.h>
#else
# include "testlib.hpp"
#endif
#include <string>
#include <iostream>
#include "avl_tree.hpp"

class AvlTreeTest : public ::testing::Test
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

		typedef int									key_type;
		typedef std::string							mapped_type;
		typedef ft::pair<key_type, mapped_type>		value_type;
		class value_compare
		{
			public:
				bool operator()(const value_type& x, const value_type& y) const
				{ return (x.first < y.first); }
		};
		typedef std::allocator<ft::pair<const key_type, mapped_type> >	allocator_type;
		typedef ft::avl_tree<value_type, value_compare, allocator_type>	tree_type;
		typedef tree_type::node_pointer									node_pointer;
		typedef ptrdiff_t												difference_type;
		typedef size_t													size_type;

		difference_type	get_balance(node_pointer node)
		{
			size_type	left_height = node->left_ ? node->left_->height_ : 0;
			size_type	right_height = node->right_ ? node->right_->height_ : 0;
			return (left_height - right_height);
		}
		size_type	get_height(node_pointer node)
		{
			size_type	left_height = node->left_ ? node->left_->height_ : 0;
			size_type	right_height = node->right_ ? node->right_->height_ : 0;
			return (1 + std::max(left_height, right_height));
		}

		void	print_tree(node_pointer node, const int depth = 0)
		{
			if (node)
			{
				print_tree(node->right_, depth + 1);
				for (int i = 0; i < depth; ++i)
					std::cout << "\t\t";
				std::cout	<< node->value_.first << "," << node->height_ << std::endl;
				print_tree(node->left_, depth + 1);
			}
		}

		void	check_tree(node_pointer node)
		{
			if (node == NULL)
				return;
			if (node->left_)
				EXPECT_LT(node->left_->value_.first, node->value_.first);
			if (node->right_)
				EXPECT_LT(node->value_.first, node->right_->value_.first);
			EXPECT_EQ(node->height_, get_height(node));
			EXPECT_LT(abs(get_balance(node)), 2);
			EXPECT_TRUE(node->parent_->left_ == node || node->parent_->right_ == node);
			check_tree(node->left_);
			check_tree(node->right_);
		}
};

TEST_F(AvlTreeTest, Test)
{
	unsigned int	seed = time(NULL);
	srand(seed);

	tree_type 	tree((value_compare()), allocator_type());

	for (int i = 0; i < 100; ++i)
		tree.insert(ft::make_pair(rand_r(&seed) % 1000, "A"));
	// print_tree(tree.get_root());
	check_tree(tree.get_root());
}