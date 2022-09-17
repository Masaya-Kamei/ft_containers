#ifndef AVL_TREE_NODE_HPP
# define AVL_TREE_NODE_HPP

namespace ft
{

template <class Val>
class	avl_tree_node
{
	public:
		typedef avl_tree_node*	pointer;
		typedef Val				value_type;
		typedef size_t			size_type;

		pointer			parent_;
		pointer			left_;
		pointer			right_;
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
};

}  // namespace ft

#endif  // AVL_TREE_NODE_HPP
