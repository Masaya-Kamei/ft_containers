#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iterator>
#include <algorithm>
#include "type_traits.hpp"
#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"
#include "algorithm.hpp"
#include "iterator.hpp"

namespace ft
{

template <class T, class Allocator = std::allocator<T> >
class	vector
{
	public:
		typedef	T										value_type;
		typedef	Allocator								allocator_type;
		typedef	std::ptrdiff_t							difference_type;
		typedef	std::size_t								size_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		typedef	ft::vector_iterator<pointer>			iterator;
		typedef ft::vector_iterator<const_pointer>		const_iterator;
		typedef ft::reverse_iterator<iterator> 			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	private:
		allocator_type	alloc_;
		pointer			begin_;
		pointer			end_;
		pointer			end_cap_;

	public:
		explicit vector(const allocator_type& alloc = allocator_type())
			: alloc_(alloc), begin_(NULL), end_(NULL), end_cap_(NULL)
		{
		}

		explicit vector(size_type n
			, const value_type& val = value_type()
			, const allocator_type& alloc = allocator_type())
			: alloc_(alloc), begin_(NULL), end_(NULL), end_cap_(NULL)
		{
			if (n == 0)
				return;
			allocate(n);
			construct_range(begin_, end_, val);
		}

	private:
		template <class InputIterator>
		void	range_constructor_impl(InputIterator first, InputIterator last, std::input_iterator_tag)
		{
			for(; first != last; ++first)
				push_back(*first);
		}

		template <class ForwardIterator>
		void	range_constructor_impl(ForwardIterator first, ForwardIterator last, std::forward_iterator_tag)
		{
			size_type	size = std::distance(first, last);
			if (size == 0)
				return;
			allocate(size);
			construct_range(begin_, end_, first);
		}

	public:
		template <class InputIterator>
		vector(InputIterator first
			, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last
			, const allocator_type& alloc = allocator_type())
			: alloc_(alloc), begin_(NULL), end_(NULL), end_cap_(NULL)
		{
			range_constructor_impl(first, last, typename ft::iterator_traits<InputIterator>::iterator_category());
		}

		vector(const vector& rhs)
			: alloc_(rhs.alloc_), begin_(NULL), end_(NULL), end_cap_(NULL)
		{
			size_type size = rhs.size();
			if (size == 0)
				return;
			allocate(size);
			construct_range(begin_, end_, rhs.begin_);
		}

		~vector()
		{
			clear();
			deallocate();
		}

		vector&	operator=(const vector& rhs)
		{
			if (this != &rhs)
			{
				if (alloc_ != rhs.alloc_)
				{
					clear();
					deallocate();
				}
				alloc_ = rhs.alloc_;
				assign(rhs.begin_, rhs.end_);
			}
			return (*this);
		}

		iterator				begin()			{ return (iterator(begin_)); }
		const_iterator			begin() const	{ return (const_iterator(begin_)); }
		iterator				end()			{ return (iterator(end_)); }
		const_iterator			end() const		{ return (const_iterator(end_)); }
		reverse_iterator		rbegin()		{ return (reverse_iterator(iterator(end_))); }
		const_reverse_iterator	rbegin() const	{ return (const_reverse_iterator(const_iterator(end_))); }
		reverse_iterator		rend()			{ return (reverse_iterator(iterator(begin_))); }
		const_reverse_iterator	rend() const	{ return (const_reverse_iterator(const_iterator(begin_))); }

		size_type	size() const
		{
			return (end_ - begin_);
		}

		size_type	max_size() const
		{
			return (std::min<size_type>(alloc_.max_size(), std::numeric_limits<difference_type>::max()));
		}

		size_type	capacity() const
		{
			return (end_cap_ - begin_);
		}

		bool	empty() const
		{
			return (begin_ == end_);
		}

		void	resize(size_type n, value_type val = value_type())
		{
			if (n < size())
				erase(iterator(begin_ + n), end());
			else
				insert(end(), n - size(), val);
		}

		void	reserve(size_type n)
		{
			if (n <= capacity())
				return;
			pointer 	old_begin = begin_;
			pointer		old_end = end_;
			size_type	old_size = size();
			size_type	old_capacity = capacity();
			allocate(n);
			end_ = begin_ + old_size;
			std::uninitialized_copy(old_begin, old_end, begin_);
			destroy_range(old_begin, old_end);
			alloc_.deallocate(old_begin, old_capacity);
		}

		reference		operator[] (size_type n)		{ return (begin_[n]); }
		const_reference	operator[] (size_type n) const	{ return (begin_[n]); }

		reference	at(size_type n)
		{
			if (size() <= n)
				throw std::out_of_range("vector");
			return (begin_[n]);
		}

		const_reference	at(size_type n) const
		{
			if (size() <= n)
				throw std::out_of_range("vector");
			return (begin_[n]);
		}

		reference			front()			{ return (*begin_); }
		const_reference		front() const	{ return (*begin_); }
		reference			back()			{ return (*(end_ - 1)); }
		const_reference		back() const	{ return (*(end_ - 1)); }
		value_type*			data()			{ return (begin_); }
		const value_type*	data() const	{ return (begin_); }

	private:
		template <class InputIterator>
		void	assign_impl(InputIterator first, InputIterator last, std::input_iterator_tag)
		{
			clear();
			for(; first != last; ++first)
				push_back(*first);
		}

		template <class ForwardIterator>
		void	assign_impl(ForwardIterator first, ForwardIterator last, std::forward_iterator_tag)
		{
			size_type	new_size = std::distance(first, last);
			if (new_size <= capacity())
			{
				pointer	new_end = begin_ + new_size;
				if (end_ < new_end)
					construct_range(end_, new_end);
				std::copy(first, last, begin_);
				if (new_end < end_)
					destroy_range(new_end, end_);
				end_ = new_end;
			}
			else
			{
				clear();
				deallocate();
				allocate(new_size);
				std::uninitialized_copy(first, last, begin_);
			}
		}

	public:
		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
			assign(InputIterator first, InputIterator last)
		{
			assign_impl(first, last, typename ft::iterator_traits<InputIterator>::iterator_category());
		}

		void	assign(size_type n, const value_type& val)
		{
			if (n <= capacity())
			{
				pointer new_end = begin_ + n;
				if (end_ < new_end)
					construct_range(end_, new_end);
				std::fill(begin_, new_end, val);
				if (new_end < end_)
					destroy_range(new_end, end_);
				end_ = new_end;
			}
			else
			{
				clear();
				deallocate();
				allocate(n);
				std::uninitialized_fill(begin_, end_, val);
			}
		}

		void	push_back(const value_type& val)
		{
			if (end_ == end_cap_)
				reserve(recommend_size(size() + 1));
			alloc_.construct(end_, val);
			end_ += 1;
		}

		void	pop_back()
		{
			alloc_.destroy(end_ - 1);
			end_ -= 1;
		}

		iterator	insert(iterator position, const value_type& val)
		{
			difference_type	pos_dist = std::distance(begin_, position.base());
			insert(position, 1, val);
			return (iterator(begin_ + pos_dist));
		}

		void	insert(iterator position, size_type n, const value_type& val)
		{
			difference_type	pos_dist = std::distance(begin_, position.base());
			size_type		new_size = size() + n;
			if (capacity() < new_size)
			{
				reserve(recommend_size(new_size));
				position = begin() + pos_dist;
			}
			pointer		new_end = end_ + n;
			construct_range(end_, new_end);
			std::copy_backward(position.base(), end_, new_end);
			std::fill(position.base(), position.base() + n, val);
			end_ = new_end;
		}

	private:
		template <class InputIterator>
		void	insert_impl(iterator position,
			InputIterator first, InputIterator last, std::input_iterator_tag)
		{
			for(; first != last; ++first, ++position)
				position = insert(position, *first);
		}

		template <class ForwardIterator>
		void	insert_impl(iterator position,
			ForwardIterator first, ForwardIterator last, std::forward_iterator_tag)
		{
			size_type		n = std::distance(first, last);
			difference_type	pos_dist = std::distance(begin_, position.base());
			size_type		new_size = size() + n;
			if (capacity() < new_size)
			{
				reserve(recommend_size(new_size));
				position = begin() + pos_dist;
			}
			pointer		new_end = end_ + n;
			construct_range(end_, new_end);
			std::copy_backward(position.base(), end_, new_end);
			std::copy(first, last, position.base());
			end_ = new_end;
		}

	public:
		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
			insert(iterator position, InputIterator first, InputIterator last)
		{
			insert_impl(position, first, last, typename ft::iterator_traits<InputIterator>::iterator_category());
		}

		iterator	erase(iterator position)
		{
			std::copy(position.base() + 1, end_, position.base());
			pop_back();
			return (position);
		}

		iterator	erase(iterator first, iterator last)
		{
			size_type	erase_size = std::distance(first.base(), last.base());
			pointer		new_end = end_ - erase_size;
			std::copy(last.base(), end_, first.base());
			destroy_range(new_end, end_);
			end_ = new_end;
			return (first);
		}

		void	swap(vector& x)
		{
			std::swap(alloc_, x.alloc_);
			std::swap(begin_, x.begin_);
			std::swap(end_, x.end_);
			std::swap(end_cap_, x.end_cap_);
		}

		void	clear()
		{
			destroy_range(begin_, end_);
			end_ = begin_;
		}

		allocator_type	get_allocator() const
		{
			return (alloc_);
		}

	private:
		 void	construct_range(pointer first, pointer last)
		 {
			for (pointer p = first; p < last; ++p)
				alloc_.construct(p, value_type());
		 }

		 void	construct_range(pointer first, pointer last, const value_type& val)
		 {
			for (pointer p = first; p < last; ++p)
				alloc_.construct(p, val);
		 }

		template <class ForwardIterator>
		typename ft::enable_if<!ft::is_integral<ForwardIterator>::value, void>::type
			construct_range(pointer first, pointer last, ForwardIterator val_itr)
		 {
			for (pointer p = first; p < last; ++p, ++val_itr)
				alloc_.construct(p, *val_itr);
		 }

		 void	destroy_range(pointer first, pointer last)
		 {
			for (pointer p = first; p < last; p++)
				alloc_.destroy(p);
		 }

		void	allocate(size_type size)
		{
			if (size > max_size())
				throw std::length_error("vector");
			begin_ = alloc_.allocate(size);
			end_ = begin_ + size;
			end_cap_ = end_;
		}

		void	deallocate()
		{
			if (begin_ == NULL)
				return;
			alloc_.deallocate(begin_, capacity());
			begin_ = NULL;
			end_ = NULL;
			end_cap_ = NULL;
		}

		size_type	recommend_size(size_type new_size) const
		{
			size_type	maxsize = max_size();
			 if (maxsize < new_size)
				throw std::length_error("vector");
			size_type	cap = capacity();
			if (maxsize / 2 <= cap)
				return (maxsize);
			return (std::max<size_type>(new_size, cap * 2));
		}
};

template <class T, class Alloc>
bool	operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool	operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Alloc>
bool	operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class T, class Alloc>
bool	operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return (!(rhs < lhs));
}

template <class T, class Alloc>
bool	operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return (rhs < lhs);
}

template <class T, class Alloc>
bool	operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return (!(lhs < rhs));
}

template <class T, class Alloc>
void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
{
	x.swap(y);
}

}  // namespace ft

#endif  // VECTOR_HPP
