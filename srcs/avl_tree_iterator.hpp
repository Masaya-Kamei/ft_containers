#ifndef AVL_TREE_ITERATOR_HPP
# define AVL_TREE_ITERATOR_HPP

# include "avl_tree_node.hpp"

namespace ft
{

template <class Val>
class avl_tree_iterator : public std::iterator<std::bidirectional_iterator_tag, Val>
{
	public:
		typedef	typename std::iterator<std::bidirectional_iterator_tag, Val>::iterator_category	iterator_category;
		typedef	typename std::iterator<std::bidirectional_iterator_tag, Val>::value_type		value_type;
		typedef	typename std::iterator<std::bidirectional_iterator_tag, Val>::difference_type	difference_type;
		typedef	typename std::iterator<std::bidirectional_iterator_tag, Val>::pointer			pointer;
		typedef	typename std::iterator<std::bidirectional_iterator_tag, Val>::reference			reference;

	private:
		typedef avl_tree_node<Val>	node_type;
		typedef node_type*			node_pointer;

		node_pointer	node_;

	public:
		avl_tree_iterator()
			: node_(NULL)
		{
		}
		template <class T2>
		avl_tree_iterator(const avl_tree_iterator<T2>& rhs)
			: node_(rhs.base())
		{
		}
		explicit avl_tree_iterator(node_pointer node)
			: node_(node)
		{
		}
		avl_tree_iterator& operator=(const avl_tree_iterator& rhs)
		{
			if (this != &rhs)
				node_ = rhs.node_;
			return (*this);
		}
		virtual ~avl_tree_iterator()
		{
		}

		reference	operator*() const
		{
			return (node_->value_);
		}
		pointer		operator->() const
		{
			return (&(node_->value_));
		}

		avl_tree_iterator&	operator++()
		{
			node_ = get_next_node(node_);
			return (*this);
		}
		avl_tree_iterator	operator++(int )
		{
			avl_tree_iterator	tmp(*this);
			node_ = get_next_node(node_);
			return (tmp);
		}
		avl_tree_iterator&	operator--()
		{
			node_ = get_prev_node(node_);
			return (*this);
		}
		avl_tree_iterator	operator--(int )
		{
			avl_tree_iterator	tmp(*this);
			node_ = get_prev_node(node_);
			return (tmp);
		}

		template <class T1, class T2>
		friend bool operator==(const avl_tree_iterator<T1>& lhs, const avl_tree_iterator<T2>& rhs)
		{
			return (lhs.node_ == rhs.node_);
		}

		template <class T1, class T2>
		friend bool operator!=(const avl_tree_iterator<T1>& lhs, const avl_tree_iterator<T2>& rhs)
		{
			return (!(lhs == rhs));
		}

	private:
		static node_pointer	get_next_node(node_pointer node)
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

		static node_pointer	get_prev_node(node_pointer node)
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

}  // namespace ft

#endif  // AVL_TREE_ITERATOR_HPP
