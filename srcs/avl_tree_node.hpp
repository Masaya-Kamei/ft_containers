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

		pointer			parent_;
		pointer			left_;
		pointer			right_;
		value_type		value_;

		avl_tree_node()
		{
		}

		explicit avl_tree_node(const value_type& val)
			: parent_(NULL), left_(NULL), right_(NULL), value_(val)
		{
		}
};

}  // namespace ft

#endif  // AVL_TREE_NODE_HPP
