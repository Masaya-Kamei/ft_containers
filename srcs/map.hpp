#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <functional>
#include "pair.hpp"
// #include "reverse_iterator.hpp"
#include "avl_tree.hpp"

namespace ft
{

template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
class map
{
	public:
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef	pair<const key_type, mapped_type>	value_type;
		typedef Compare								key_compare;

		class value_compare
		{
			friend class map;
			protected:
				Compare comp;
				value_compare(Compare c) : comp(c) {}
			public:
				typedef bool		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;
				bool operator()(const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};

		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::reference			pointer;
		typedef typename allocator_type::const_reference	const_pointer;
		// typedef iterator;
		// typedef const_iterator;
		// typedef ft::reverse_iterator<iterator>				reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

		explicit map(const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
			: tree_(value_compare(comp), alloc)
		{
		}

		// template <class InputIterator>
		// map(InputIterator first, InputIterator last,
		// 	const key_compare& comp = key_compare(),
		// 	const allocator_type& alloc = allocator_type());
		// map(const map& x);
		// ~map();
		// map& operator= (const map& x);

		// iterator begin();
		// const_iterator begin() const;
		// iterator end();
		// const_iterator end() const;
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;

		// bool empty() const;
		// size_type size() const;
		// size_type max_size() const;
		// mapped_type& operator[] (const key_type& k);

		// pair<iterator, bool> insert(const value_type& val);
		// iterator insert(iterator position, const value_type& val);
		// template <class InputIterator>
		// void insert(InputIterator first, InputIterator last);
		// void erase(iterator position);
		// size_type erase(const key_type& k);
		// void erase(iterator first, iterator last);
		// void swap(map& x);
		// void clear();
		// key_compare key_comp() const;
		// value_compare value_comp() const;
		// iterator find(const key_type& k);
		// const_iterator find(const key_type& k) const;
		// size_type count(const key_type& k) const;
		// iterator lower_bound(const key_type& k);
		// const_iterator lower_bound(const key_type& k) const;
		// iterator upper_bound(const key_type& k);
		// const_iterator upper_bound(const key_type& k) const;
		// pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
		// pair<iterator, iterator>             equal_range(const key_type& k);
		// allocator_type get_allocator() const;

	private:
		typedef avl_tree<value_type, value_compare, allocator_type>	avl_tree;

		avl_tree	tree_;
};

// template <class Key, class T, class Compare, class Alloc>
// bool	operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs);

// template <class Key, class T, class Compare, class Alloc>
// bool	operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs);

// template <class Key, class T, class Compare, class Alloc>
// bool	operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs);

// template <class Key, class T, class Compare, class Alloc>
// bool	operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs);

// template <class Key, class T, class Compare, class Alloc>
// bool	operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs);

// template <class Key, class T, class Compare, class Alloc>
// bool	operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs);

// template <class Key, class T, class Compare, class Alloc>
// void	swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y);

}  // namespace ft

#endif  // VECTOR_HPP
