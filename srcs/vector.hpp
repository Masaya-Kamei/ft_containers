#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include "type_traits.hpp"
#include "random_access_iterator.hpp"

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
		// typedef reverse_iterator;
		// typedef const_reverse_iterator;

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
			else if (n > max_size())
				throw std::length_error("ft::vector");
			begin_ = alloc_.allocate(n);
			end_ = begin_ + n;
			end_cap_ = end_;
			std::uninitialized_fill(begin_, end_, val);
		}

		template <class InputIterator>
		vector(InputIterator first
			, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last
			, const allocator_type& alloc = allocator_type())
			: alloc_(alloc), begin_(NULL), end_(NULL), end_cap_(NULL)
		{
			size_type	size = last - first;
			if (size == 0)
				return;
			else if (size > max_size())
				throw std::length_error("ft::vector");
			begin_ = alloc_.allocate(size);
			end_ = begin_ + size;
			end_cap_ = end_;
			std::uninitialized_copy(first, last, begin_);
		}

		vector(const vector& rhs)
			: alloc_(rhs.alloc_), begin_(NULL), end_(NULL), end_cap_(NULL)
		{
			size_type size = rhs.size();
			if (size == 0)   // TODO(mkamei)
				return;
			begin_ = alloc_.allocate(size);
			end_ = begin_ + size;
			end_cap_ = end_;
			std::uninitialized_copy(rhs.begin_, rhs.last, begin_);
		}

		~vector()
		{
			for (pointer p = begin_; p < end_; p++)
				alloc_.destroy(p);
			alloc_.deallocate(begin_, capacity());
		}

		vector& operator=(const vector& x);

		iterator begin()
		{
			return (iterator(begin_));
		}
		const_iterator begin() const
		{
			return (const_iterator(begin_));
		}
		iterator end()
		{
			return (iterator(end_));
		}
		const_iterator end() const
		{
			return (const_iterator(end_));
		}
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;
		size_type size() const
		{
			return (end_ - begin_);
		}
		size_type max_size() const
		{
			return (std::min<size_type>(alloc_.max_size(), std::numeric_limits<difference_type>::max()));
		}
		size_type capacity() const
		{
			return (end_cap_ - begin_);
		}
		bool empty() const
		{
			return (begin_ == end_);
		}
		void resize(size_type n, value_type val = value_type());
		void reserve(size_type n);
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;
		reference at(size_type n);
		const_reference at(size_type n) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		value_type* data();
		const value_type* data() const;
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last);
		void assign(size_type n, const value_type& val);
		void push_back(const value_type& val);
		void pop_back();
		iterator insert(iterator position, const value_type& val);
		void insert(iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last);
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);
		void swap(vector& x);
		void clear();
		allocator_type get_allocator() const;

	private:
		allocator_type	alloc_;
		pointer			begin_;
		pointer			end_;
		pointer			end_cap_;
};

}  // namespace ft

#endif  // VECTOR_HPP
