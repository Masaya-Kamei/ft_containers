#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

# include "pair.hpp"
# include "avl_tree_node.hpp"
# include "avl_tree_iterator.hpp"

# define PUT(X) std::cout << X << std::endl;

namespace ft
{

template <class Key, class Val, class Compare, class Alloc>
class	avl_tree
{
	public:
		typedef Key												key_type;
		typedef Val												value_type;
		typedef Compare											map_value_compare;
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
		map_value_compare	comp_;
		node_allocator_type	node_alloc_;
		size_type			size_;
		node_pointer		begin_;
		node_pointer		end_;

	public:
		avl_tree(map_value_compare comp, allocator_type alloc)
			: comp_(comp), node_alloc_(alloc), size_(0)
		{
			end_ = node_alloc_.allocate(1);
			node_alloc_.construct(end_);  // TODO(mkamei)
			end_->left_ = NULL;
			begin_ = end_;
		}

		~avl_tree()
		{
			delete_tree(get_root());
			delete_node(end_);
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
			node_pointer	node = get_root();

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
			node_pointer	erase_node = position.base();

			if (erase_node == begin_)
				begin_ = erase_node->get_next_node();  // TODO(mkamei)

			node_pointer	alt_node;
			if (erase_node->left_ == NULL && erase_node->right_ == NULL)
				alt_node = NULL;
			else if (erase_node->get_balance() >= 0)
				alt_node = erase_node->left_->get_max_node();
			else
				alt_node = erase_node->right_->get_min_node();

			node_pointer	bottom_node;
			if (alt_node == NULL)
				bottom_node = erase_node->parent_;
			else if (alt_node->parent_ == erase_node)
				bottom_node = alt_node;
			else
				bottom_node = alt_node->parent_;

			replace_node(erase_node, alt_node);
			delete_node(erase_node);
			--size_;
			rebalance_tree(bottom_node);
		}

		iterator	find(const key_type& k)
		{
			node_pointer	node = get_root();
			while (node)
			{
				if (comp_(k, node->value_))
					node = node->left_;
				else if (comp_(node->value_, k))
					node = node->right_;
				else
					return (iterator(node));
			}
			return (end());
		}

		iterator	lower_bound(const key_type& k)
		{
			node_pointer	node = get_root();
			node_pointer	result = end_;
			while (node)
			{
				if (!comp_(node->value_, k))
				{
					result = node;
					node = node->left_;
				}
				else
					node = node->right_;
			}
			return (iterator(result));
		}

		iterator	upper_bound(const key_type& k)
		{
			node_pointer	node = get_root();
			node_pointer	result = end_;
			while (node)
			{
				if (!comp_(k, node->value_))
				{
					result = node;
					node = node->right_;
				}
				else
					node = node->left_;
			}
			return (iterator(result));
		}

		node_pointer	get_root() const { return (end_->left_); }

	private:
		void	delete_node(node_pointer node)
		{
			node_alloc_.destroy(node);
			node_alloc_.deallocate(node, 1);
		}

		void	delete_tree(node_pointer node)
		{
			if (node != NULL)
			{
				delete_tree(node->left_);
				delete_tree(node->right_);
				delete_node(node);
				--size_;
			}
		}

		node_pointer	create_node(const value_type& val)
		{
			node_pointer	new_node = node_alloc_.allocate(1);
			node_alloc_.construct(new_node, node_type(val));
			return (new_node);
		}

		node_pointer	create_node_at(const value_type& val, node_pointer parent_node)
		{
			node_pointer	new_node = create_node(val);

			bool	is_left = (parent_node == end_ || comp_(val, parent_node->value_));
			new_node->connect_parent(parent_node, is_left);

			if (is_left && parent_node == begin_)
				begin_ = new_node;

			++size_;
			return (new_node);
		}

		void	replace_node(node_pointer erase_node, node_pointer alt_node)
		{
			if (alt_node == NULL)
				erase_node->disconnect_parent();
			else
			{
				if (alt_node->left_ == NULL && alt_node->right_ == NULL)
					alt_node->disconnect_parent();
				else if (alt_node->left_)
					alt_node->left_->connect_parent(alt_node->parent_, alt_node->is_left());
				else
					alt_node->right_->connect_parent(alt_node->parent_, alt_node->is_left());
				alt_node->connect_parent(erase_node->parent_, erase_node->is_left());
				alt_node->connect_left(erase_node->left_);
				alt_node->connect_right(erase_node->right_);
			}
		}

		void	rotate_left(node_pointer node)
		{
			node_pointer	right_node = node->right_;

			right_node->connect_parent(node->parent_, node->is_left());
			node->connect_right(right_node->left_);
			right_node->connect_left(node);

			node->update_height();
			right_node->update_height();
		}

		void	rotate_right(node_pointer node)
		{
			node_pointer	left_node = node->left_;

			left_node->connect_parent(node->parent_, node->is_left());
			node->connect_left(left_node->right_);
			left_node->connect_right(node);

			node->update_height();
			left_node->update_height();
		}

		void	rebalance_tree(node_pointer bottom_node)
		{
			node_pointer	node = bottom_node;
			node_pointer	parent_node;

			while (node != end_)
			{
				parent_node = node->parent_;
				difference_type	balance = node->get_balance();
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
			}
		}
};

}  // namespace ft

#endif  // AVL_TREE_HPP
