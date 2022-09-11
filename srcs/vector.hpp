#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iterator>
#include "type_traits.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{

template <class T, class Allocator = std::allocator<T>>
class	vector
{
	public:
		typedef	T												value_type;
		typedef	Allocator										allocator_type;
		typedef	std::ptrdiff_t									difference_type;
		typedef	std::size_t										size_type;
		typedef value_type&										reference;
		typedef const value_type&								const_reference;
		typedef typename Allocator::pointer						pointer;
		typedef typename Allocator::const_pointer				const_pointer;
		typedef	ft::random_access_iterator<value_type>			iterator;
		typedef ft::random_access_iterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator> 					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

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
			std::uninitialized_fill(begin_, end_, val);
		}

		template <class InputIterator>
		vector(InputIterator first
			, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last
			, const allocator_type& alloc = allocator_type())
			: alloc_(alloc), begin_(NULL), end_(NULL), end_cap_(NULL)
		{
			size_type	size = std::distance(first, last);
			if (size == 0)
				return;
			allocate(size);
			std::uninitialized_copy(first, last, begin_);
		}

		vector(const vector& rhs)
			: alloc_(rhs.alloc_), begin_(NULL), end_(NULL), end_cap_(NULL)
		{
			size_type size = rhs.size();
			if (size == 0)
				return;
			allocate(size);
			std::uninitialized_copy(rhs.begin_, rhs.end_, begin_);
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
		reverse_iterator		rend()			{ return (reverse_iterator(begin_)); }
		const_reverse_iterator	rend() const	{ return (const_reverse_iterator(begin_)); }

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
				erase(begin() + n, end());
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

		reference	operator[] (size_type n);
		const_reference	operator[] (size_type n) const;
		reference	at(size_type n);
		const_reference	at(size_type n) const;
		reference	front();
		const_reference	front() const;
		reference	back();
		const_reference	back() const;
		value_type*	data();
		const value_type*	data() const;

		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
			assign(InputIterator first, InputIterator last)
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

		void	push_back(const value_type& val);
		void	pop_back();

		iterator	insert(iterator position, const value_type& val)
		{
			difference_type	pos_dist = std::distance(begin(), position);
			insert(position, 1, val);
			return (begin() + pos_dist);
		}

		void	insert(iterator position, size_type n, const value_type& val)
		{
			difference_type	pos_dist = std::distance(begin(), position);
			size_type		new_size = size() + n;
			if (capacity() < new_size)
			{
				reserve(recommend_size(new_size));
				position = begin() + pos_dist;
			}
			pointer		new_end = end_ + n;
			construct_range(end_, new_end);
			std::copy_backward(position, end(), new_end);
			std::fill(position, position + n, val);
			end_ = new_end;
		}

		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
			insert(iterator position, InputIterator first, InputIterator last)
		{
			size_type		n = std::distance(first, last);
			difference_type	pos_dist = std::distance(begin(), position);
			size_type		new_size = size() + n;
			if (capacity() < new_size)
			{
				reserve(recommend_size(new_size));
				position = begin() + pos_dist;
			}
			pointer		new_end = end_ + n;
			construct_range(end_, new_end);
			std::copy_backward(position, end(), new_end);
			std::copy(first, last, position);
			end_ = new_end;
		}

		iterator	erase(iterator position)
		{
			return (erase(position, position + 1));
		}

		iterator	erase(iterator first, iterator last)
		{
			size_type	erase_size = std::distance(first, last);
			pointer		new_end = end_ - erase_size;
			std::copy(last, end(), first);
			destroy_range(new_end, end_);
			end_ = new_end;
			return (first);
		}

		void	swap(vector& x);

		void	clear()
		{
			destroy_range(begin_, end_);
			end_ = begin_;
		}

		allocator_type	get_allocator() const;

	private:
		allocator_type	alloc_;
		pointer			begin_;
		pointer			end_;
		pointer			end_cap_;

		 void	construct_range(pointer first, pointer last)
		 {
			for (pointer p = first; p < last; p++)
				alloc_.construct(p);
		 }

		 void	destroy_range(pointer first, pointer last)
		 {
			for (pointer p = first; p < last; p++)
				alloc_.destroy(p);
		 }

		void	allocate(size_type size)
		{
			if (size > max_size())
				throw std::length_error("ft::vector");
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
				throw std::length_error("ft::vector");
			size_type	cap = capacity();
			if (maxsize / 2 <= cap)
				return (maxsize);
			return (std::max<size_type>(new_size, cap * 2));
		}
};

}  // namespace ft

#endif  // VECTOR_HPP
