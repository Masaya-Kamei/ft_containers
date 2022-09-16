#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

# include "pair.hpp"
# include "avl_tree_node.hpp"
# include "avl_tree_iterator.hpp"

namespace ft
{

template <class Val, class Compare, class Alloc>
class	avl_tree
{
	public:
		typedef Val												value_type;
		typedef typename value_type::first_type					key_type;
		typedef typename value_type::second_type				mapped_type;
		typedef Compare											value_compare;
		typedef Alloc											allocator_type;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;

		typedef avl_tree_iterator<value_type>						iterator;
		// typedef avl_tree_const_iterator<value_type>					const_iterator;

	private:
		typedef avl_tree_node<Val>									node_type;
		typedef node_type*											node_pointer;
		typedef typename Alloc::template rebind<node_type>::other	node_allocator_type;

		value_compare		comp_;
		node_allocator_type	node_alloc_;
		size_type			size_;
		node_pointer		begin_;
		node_pointer		end_;

	public:
		avl_tree(value_compare comp, allocator_type alloc)
			: comp_(comp), node_alloc_(alloc), size_(0)
		{
			end_ = node_alloc_.allocate(1);
			node_alloc_.construct(end_);  // TODO(mkamei)
			end_->left_ = NULL;
			begin_ = end_;
		}

		~avl_tree()
		{
			delete_tree(end_->left_);
			node_alloc_.destroy(end_);
			node_alloc_.deallocate(end_, 1);
		}

		iterator	begin()	{ return (iterator(begin_)); }
		iterator	end()	{ return (iterator(end_)); }

		ft::pair<iterator, bool>	insert(const value_type& val)
		{
			node_pointer	new_node = create_node(val);
			node_pointer	parent = end_;
			node_pointer	node = end_->left_;
			while (node)
			{
				parent = node;
				if (comp_(node->value_, new_node->value_))
					node = node->right_;
				else
					node = node->left_;
			}
			new_node->parent_ = parent;
			if (parent == end_ || !comp_(parent->value_, new_node->value_))
			{
				parent->left_ = new_node;
				if (parent == begin_)
					begin_ = new_node;
			}
			else
				parent->right_ = new_node;
			return (ft::make_pair((new_node), true));
		}

	private:
		void	delete_tree(node_pointer node)
		{
			if (node != NULL)
			{
				delete_tree(node->left_);
				delete_tree(node->right_);
				node_alloc_.destroy(node);
				node_alloc_.deallocate(node, 1);
			}
		}

		node_pointer	create_node(const value_type &value)
		{
			node_pointer	new_node = node_alloc_.allocate(1);
			node_alloc_.construct(new_node, value);
			return (new_node);
		}
};

}  // namespace ft

#endif  // AVL_TREE_HPP
