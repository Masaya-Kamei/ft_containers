#ifndef AVL_TREE_ITERATOR_HPP
# define AVL_TREE_ITERATOR_HPP

# include "avl_tree_node.hpp"

namespace ft
{

template <class Val, class Node>
class avl_tree_iterator : public std::iterator<std::bidirectional_iterator_tag, Val>
{
	public:
		typedef	typename std::iterator<std::bidirectional_iterator_tag, Val>::iterator_category	iterator_category;
		typedef	typename std::iterator<std::bidirectional_iterator_tag, Val>::value_type		value_type;
		typedef	typename std::iterator<std::bidirectional_iterator_tag, Val>::difference_type	difference_type;
		typedef	typename std::iterator<std::bidirectional_iterator_tag, Val>::pointer			pointer;
		typedef	typename std::iterator<std::bidirectional_iterator_tag, Val>::reference			reference;

	private:
		// typedef avl_tree_node<Val>	node_type;
		typedef Node				node_type;
		typedef node_type*			node_pointer;

		node_pointer	node_;

	public:
		avl_tree_iterator()
			: node_(NULL)
		{
		}
		template <class T2>
		avl_tree_iterator(const avl_tree_iterator<T2, node_type>& rhs)
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
			node_ = node_->next_node();
			return (*this);
		}
		avl_tree_iterator	operator++(int )
		{
			avl_tree_iterator	tmp(*this);
			node_ = node_->next_node();
			return (tmp);
		}
		avl_tree_iterator&	operator--()
		{
			node_ = node_->prev_node();
			return (*this);
		}
		avl_tree_iterator	operator--(int )
		{
			avl_tree_iterator	tmp(*this);
			node_ = node_->prev_node();
			return (tmp);
		}

		node_pointer	base() const
		{
			return (node_);
		}

		// template <class T1, class T2>	// TODO(mkamei)
		// friend bool operator==(const avl_tree_iterator<T1, node_type>& lhs, const avl_tree_iterator<T2, node_type>& rhs)
		friend bool operator==(const avl_tree_iterator& lhs, const avl_tree_iterator& rhs)
		{
			return (lhs.node_ == rhs.node_);
		}

		// template <class T1, class T2>
		// friend bool operator!=(const avl_tree_iterator<T1, node_type>& lhs, const avl_tree_iterator<T2, node_type>& rhs)
		friend bool operator!=(const avl_tree_iterator& lhs, const avl_tree_iterator& rhs)
		{
			return (!(lhs == rhs));
		}
};

// template <class T1, class T2>
// bool operator==(const avl_tree_iterator<T1>& lhs, const avl_tree_iterator<T2>& rhs)
// {
// 	return (lhs.base() == rhs.base());
// }

// template <class T1, class T2>
// bool operator!=(const avl_tree_iterator<T1>& lhs, const avl_tree_iterator<T2>& rhs)
// {
// 	return (!(lhs == rhs));
// }

}  // namespace ft

#endif  // AVL_TREE_ITERATOR_HPP
