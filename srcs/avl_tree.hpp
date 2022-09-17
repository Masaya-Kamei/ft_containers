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

	public:
		typedef node_type*											node_pointer;
		typedef typename Alloc::template rebind<node_type>::other	node_allocator_type;

	private:
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

		size_type	size() const
		{
			return (size_);
		}
		size_type	max_size() const
		{
			return (std::min<size_type>(node_alloc_.max_size(), std::numeric_limits<difference_type>::max()));
		}

		ft::pair<iterator, bool>	insert(const value_type& val)
		{
			node_pointer	parent_node = end_;
			node_pointer	node = end_->left_;

			while (node)
			{
				parent_node = node;
				if (comp_(val, parent_node->value_))
					node = parent_node->left_;
				else if (comp_(parent_node->value_, val))
					node = parent_node->right_;
				else
					return (ft::make_pair(iterator(parent_node), false));
			}

			node_pointer	new_node = create_node_at(val, parent_node);
			rebalance_tree(new_node);
			return (ft::make_pair(iterator(new_node), true));
		}

		void	erase(iterator position)
		{
			node_pointer	node = position.base();
			node = NULL;
			// node_pointer	replace_node;
			// if (get_balance(node) >= 0)
			// 	replace_node = avl_tree_node::get_max_node()
		}

		size_type	erase(const key_type& key)
		{
			iterator position = find(key);
			if (position == end())
				return (0);
			erase(position);
			return (1);
		}

		node_pointer	get_root()	{ return (end_->left_); }

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

		node_pointer	create_node_at(const value_type& val, node_pointer parent_node)
		{
			node_pointer	new_node = node_alloc_.allocate(1);
			node_alloc_.construct(new_node, node_type(val));

			const bool	is_left = (parent_node == end_ || comp_(val, parent_node->value_));
			if (is_left)
				parent_node->left_ = new_node;
			else
				parent_node->right_ = new_node;
			new_node->parent_ = parent_node;

			if (is_left && parent_node == begin_)
				begin_ = new_node;
			++size_;
			return (new_node);
		}

		void	rotate_left(node_pointer node)
		{
			node_pointer	parent_node = node->parent_;
			node_pointer	right_node = node->right_;

			if (parent_node->left_ == node)
				parent_node->left_ = right_node;
			else
				parent_node->right_ = right_node;
			right_node->parent_ = parent_node;

			node->right_ = right_node->left_;
			if (right_node->left_)
				right_node->left_->parent_ = node;
			right_node->left_ = node;
			node->parent_ = right_node;

			node->update_height();
			right_node->update_height();
		}

		void	rotate_right(node_pointer node)
		{
			node_pointer	parent_node = node->parent_;
			node_pointer	left_node = node->left_;

			if (parent_node->left_ == node)
				parent_node->left_ = left_node;
			else
				parent_node->right_ = left_node;
			left_node->parent_ = parent_node;

			node->left_ = left_node->right_;
			if (left_node->right_)
				left_node->right_->parent_ = node;
			left_node->right_ = node;
			node->parent_ = left_node;

			node->update_height();
			left_node->update_height();
		}

		void	rebalance_tree(node_pointer new_node)
		{
			difference_type	balance;
			node_pointer	node = new_node;
			node_pointer	parent_node = node->parent_;

			while (node != end_)
			{
				balance = node->get_balance();
				if (balance == 2)
				{
					if (node->left_->get_balance() == -1)
						rotate_left(node->left_);
					rotate_right(node);
				}
				else if (balance == -2)
				{
					if (node->right_->get_balance() == 1)
						rotate_right(node->right_);
					rotate_left(node);
				}
				else
					node->update_height();
				node = parent_node;
				parent_node = node->parent_;
			}
		}
};

}  // namespace ft

#endif  // AVL_TREE_HPP
