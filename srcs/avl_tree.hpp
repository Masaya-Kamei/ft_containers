#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

# include "pair.hpp"

namespace ft
{

template <class Val>
class	tree_node
{
	public:
		typedef tree_node*	pointer;
		typedef Val			value_type;

		pointer			parent_;
		pointer			left_;
		pointer			right_;
		value_type		value_;

		tree_node()
		{
		}

		explicit tree_node(const value_type& val)
			: parent_(NULL), left_(NULL), right_(NULL), value_(val)
		{
		}
};

template <class Val>
class tree_iterator : public std::iterator<std::bidirectional_iterator_tag, Val>
{
	public:
		typedef	typename std::iterator<std::bidirectional_iterator_tag, Val>::iterator_category	iterator_category;
		typedef	typename std::iterator<std::bidirectional_iterator_tag, Val>::value_type		value_type;
		typedef	typename std::iterator<std::bidirectional_iterator_tag, Val>::difference_type	difference_type;
		typedef	typename std::iterator<std::bidirectional_iterator_tag, Val>::pointer			pointer;
		typedef	typename std::iterator<std::bidirectional_iterator_tag, Val>::reference			reference;

	private:
		typedef tree_node<Val>	node_type;
		typedef node_type*		node_pointer;

		node_pointer	node_;

	public:
		tree_iterator()
			: node_(NULL)
		{
		}
		template <class T2>
		tree_iterator(const tree_iterator<T2>& rhs)
			: node_(rhs.base())
		{
		}
		explicit tree_iterator(node_pointer node)
			: node_(node)
		{
		}
		tree_iterator& operator=(const tree_iterator& rhs)
		{
			if (this != &rhs)
				node_ = rhs.node_;
			return (*this);
		}
		virtual ~tree_iterator()
		{
		}

		node_pointer	base() const { return (node_); }

		reference	operator*() const
		{
			return (node_->value_);
		}
		pointer		operator->() const
		{
			return (&(node_->value_));
		}

		tree_iterator&	operator++()
		{
			node_ = get_next_node(node_);
			return (*this);
		}
		tree_iterator	operator++(int )
		{
			tree_iterator	tmp(*this);
			node_ = get_next_node(node_);
			return (tmp);
		}
		tree_iterator&	operator--()
		{
			node_ = get_prev_node(node_);
			return (*this);
		}
		tree_iterator	operator--(int )
		{
			tree_iterator	tmp(*this);
			node_ = get_prev_node(node_);
			return (tmp);
		}

	private:
		node_pointer	get_next_node(node_pointer node)
		{
			if (node->right_)
			{
				node = node->right_;
				while (node->left_)
					node = node->left_;
			}
			else
			{
				while (node != node->parent_->left_)
					node = node->parent_;
				node = node->parent_;
			}
			return (node);
		}

		node_pointer	get_prev_node(node_pointer node)
		{
			if (node->left_)
			{
				node = node->left_;
				while (node->right_)
					node = node->left_;
			}
			else
			{
				while (node != node->parent_->right_)
					node = node->parent_;
				node = node->parent_;
			}
			return (node);
		}
};

template <class T1, class T2>
bool operator==(const tree_iterator<T1>& lhs, const tree_iterator<T2>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <class T1, class T2>
bool operator!=(const tree_iterator<T1>& lhs, const tree_iterator<T2>& rhs)
{
	return (lhs.base() != rhs.base());
}

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

		typedef tree_iterator<value_type>						iterator;
		// typedef tree_const_iterator<value_type>					const_iterator;

	private:
		typedef tree_node<Val>										node_type;
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
