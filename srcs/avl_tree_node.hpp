#ifndef AVL_TREE_NODE_HPP
# define AVL_TREE_NODE_HPP

namespace ft
{

template <class Val>
class	avl_tree_node
{
	public:
		typedef avl_tree_node*			node_pointer;
		typedef Val						value_type;
		typedef size_t					size_type;
		typedef ptrdiff_t				difference_type;

		node_pointer	parent_;
		node_pointer	left_;
		node_pointer	right_;
		value_type		value_;
		size_type		height_;

		avl_tree_node()
		{
		}

		explicit avl_tree_node(const value_type& val)
			: parent_(NULL), left_(NULL), right_(NULL), value_(val), height_(1)
		{
		}

		avl_tree_node(const avl_tree_node& rhs)
			: parent_(rhs.parent_), left_(rhs.left_), right_(rhs.right_)
			, value_(rhs.value_), height_(rhs.height_)
		{
		}

		difference_type	get_balance() const
		{
			size_type	left_height = left_ ? left_->height_ : 0;
			size_type	right_height = right_ ? right_->height_ : 0;
			return (left_height - right_height);
		}

		void	update_height()
		{
			size_type	left_height = left_ ? left_->height_ : 0;
			size_type	right_height = right_ ? right_->height_ : 0;
			height_ = 1 + std::max(left_height, right_height);
		}

		bool	is_left()  const { return (this == parent_->left_); }
		bool	is_right() const { return (this == parent_->right_); }

		node_pointer	get_max_node()
		{
			node_pointer	node = this;
			while (node->right_)
				node = node->right_;
			return (node);
		}

		node_pointer	get_min_node()
		{
			node_pointer	node = this;
			while (node->left_)
				node = node->left_;
			return (node);
		}

		node_pointer	get_next_node()
		{
			if (right_)
				return (right_->get_min_node());
			else
			{
				node_pointer	node = this;
				while (node->is_right())
					node = node->parent_;
				return (node->parent_);
			}
		}

		node_pointer	get_prev_node()
		{
			if (left_)
				return (left_->get_max_node());
			else
			{
				node_pointer	node = this;
				while (node->is_left())
					node = node->parent_;
				return (node->parent_);
			}
		}
};

}  // namespace ft

#endif  // AVL_TREE_NODE_HPP
