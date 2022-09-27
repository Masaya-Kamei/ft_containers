#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iterator>
# include "iterator.hpp"

namespace ft
{

template <class Iter>
class vector_iterator
{
	public:
		typedef	Iter 													iterator_type;
		typedef	typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef	typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef	typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef	typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef	typename ft::iterator_traits<Iter>::reference			reference;

	private:
		pointer		ptr_;

	public:
		vector_iterator()
			: ptr_(NULL)
		{
		}
		template <class T2>
		vector_iterator(const vector_iterator<T2>& rhs)
			: ptr_(rhs.base())
		{
		}
		explicit vector_iterator(pointer ptr)
			: ptr_(ptr)
		{
		}
		vector_iterator& operator=(const vector_iterator& rhs)
		{
			if (*this != rhs)
				ptr_ = rhs.ptr_;
			return (*this);
		}
		virtual ~vector_iterator()
		{
		}

		pointer	base() const
		{
			return (ptr_);
		}

		reference operator*() const
		{
			return (*ptr_);
		}
		pointer operator->() const
		{
			return (ptr_);
		}
		reference operator[](difference_type n) const
		{
			return (*(ptr_ + n));
		}

		vector_iterator&	operator++()
		{
			++ptr_;
			return (*this);
		}
		vector_iterator	operator++(int )
		{
			vector_iterator	tmp(*this);
			++ptr_;
			return (tmp);
		}
		vector_iterator& operator--()
		{
			--ptr_;
			return (*this);
		}
		vector_iterator	operator--(int )
		{
			vector_iterator	tmp(*this);
			--ptr_;
			return (tmp);
		}
		vector_iterator&	operator+=(difference_type n)
		{
			ptr_ += n;
			return (*this);
		}
		vector_iterator&	operator-=(difference_type n)
		{
			ptr_ -= n;
			return (*this);
		}
		vector_iterator operator+(difference_type n) const
		{
			return (vector_iterator(ptr_ + n));
		}
		vector_iterator operator-(difference_type n) const
		{
			return (vector_iterator(ptr_ - n));
		}
};

template <class T1, class T2>
bool operator==(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs)
{
	return lhs.base() == rhs.base();
}

template <class T1, class T2>
bool operator!=(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs)
{
	return lhs.base() != rhs.base();
}

template <class T1, class T2>
bool operator<(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs)
{
	return lhs.base() < rhs.base();
}

template <class T1, class T2>
bool operator<=(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs)
{
	return lhs.base() <= rhs.base();
}

template <class T1, class T2>
bool operator>(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs)
{
	return lhs.base() > rhs.base();
}

template <class T1, class T2>
bool operator>=(const vector_iterator<T1>& lhs, const vector_iterator<T2>& rhs)
{
	return lhs.base() >= rhs.base();
}

template <class T>
vector_iterator<T> operator+
	(typename vector_iterator<T>::difference_type n, const vector_iterator<T>& x)
{
	return (vector_iterator<T>(n + x.base()));
}

template <class T1, class T2>
typename vector_iterator<T1>::difference_type operator-
	(const vector_iterator<T1> lhs, const vector_iterator<T2> rhs)
{
	return (lhs.base() - rhs.base());
}

}  // namespace ft

#endif  // VECTOR_ITERATOR_HPP
