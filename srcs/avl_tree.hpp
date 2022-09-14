#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

namespace ft
{

template <class Val, class Compare, class Alloc>
class	avl_node
{
	private:
		typedef avl_node*	node_pointer;
	public:
		node_pointer	left;
		node_pointer	right;
};

template <class Val, class Compare, class Alloc>
class	avl_tree
{
	public:
		typedef Val												value_type;
		typedef typename value_type::first_type					key_type;
		typedef typename value_type::second_type				mapped_type;
		typedef Compare											value_compare;
		typedef Alloc											allocator_type;
		typedef avl_node<Val, Compare, Alloc>					node;
		typedef node*											node_pointer;
		typedef typename Alloc::template rebind<node>::other	node_allocator_type;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;

		avl_tree(value_compare comp, allocator_type alloc)
			: comp_(comp), node_alloc_(alloc), size_(0), root_(NULL)
		{
		}

		~avl_tree()
		{
			destroy(root_);
		}

	private:
		value_compare		comp_;
		node_allocator_type	node_alloc_;
		size_type			size_;
		node_pointer		root_;

		void	destroy(node_pointer node)
		{
			if (node != NULL)
			{
				destroy(node->left);
				destroy(node->right);
				node_alloc_.destroy(node);
				node_alloc_.deallocate(node, 1);
			}
		}
};

}  // namespace ft

#endif  // AVL_TREE_HPP
