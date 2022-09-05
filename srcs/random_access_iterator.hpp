#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iterator>
# include "iterator_traits.hpp"

namespace ft
{

template <class T>
class random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
{
	public:
		typedef	typename std::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
		typedef	typename std::iterator<std::random_access_iterator_tag, T>::value_type			value_type;
		typedef	typename std::iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
		typedef	typename std::iterator<std::random_access_iterator_tag, T>::pointer				pointer;
		typedef	typename std::iterator<std::random_access_iterator_tag, T>::reference			reference;

		random_access_iterator()
			: ptr_(NULL)
		{
		}
		random_access_iterator(const random_access_iterator& rhs)
			: ptr_(rhs.ptr_)
		{
		}
		explicit random_access_iterator(pointer ptr)
			: ptr_(ptr)
		{
		}
		random_access_iterator& operator=(const random_access_iterator& rhs)
		{
			if (*this != rhs)
				ptr_ = rhs.ptr_;
			return (*this);
		}
		~random_access_iterator()
		{
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
		random_access_iterator&	operator++()
		{
			++ptr_;
			return (*this);
		}
		random_access_iterator	operator++(int )
		{
			random_access_iterator	tmp(*this);
			++ptr_;
			return (tmp);
		}
		random_access_iterator& operator--()
		{
			--ptr_;
			return (*this);
		}
		random_access_iterator	operator--(int )
		{
			random_access_iterator	tmp(*this);
			--ptr_;
			return (tmp);
		}
		random_access_iterator&	operator+=(difference_type n)
		{
			ptr_ += n;
			return (*this);
		}
		random_access_iterator&	operator-=(difference_type n)
		{
			ptr_ -= n;
			return (*this);
		}
		random_access_iterator<T> operator+(difference_type n)
		{
			random_access_iterator<T> tmp(*this);
			tmp += n;
			return (tmp);
		}
		random_access_iterator<T> operator-(difference_type n)
		{
			random_access_iterator<T> tmp(*this);
			tmp -= n;
			return (tmp);
		}
		difference_type operator-(const random_access_iterator& rhs)
		{
			return (ptr_ - rhs.ptr_);
		}
		bool	operator==(const random_access_iterator& rhs)
		{
			return (ptr_ == rhs.ptr_);
		}
		bool	operator!=(const random_access_iterator& rhs)
		{
			return (ptr_ != rhs.ptr_);
		}
		bool	operator<(const random_access_iterator& rhs)
		{
			return (ptr_ < rhs.ptr_);
		}
		bool	operator<=(const random_access_iterator& rhs)
		{
			return (ptr_ <= rhs.ptr_);
		}
		bool	operator>(const random_access_iterator& rhs)
		{
			return (ptr_ > rhs.ptr_);
		}
		bool	operator>=(const random_access_iterator& rhs)
		{
			return (ptr_ >= rhs.ptr_);
		}

	private:
		pointer		ptr_;
};

template <class T>
random_access_iterator<T> operator+
	(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> x)
{
	x += n;
	return (x);
}

// template <class T>	// TODO
// bool operator==(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
// {
// 	return lhs.base() == rhs.base();
// }
// template <class T1, class T2>
// bool operator==(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
// {
// 	return lhs.base() == rhs.base();
// }

// template <class T>
// typename random_access_iterator<T>::difference_type operator-
// 	(const random_access_iterator<T> lhs, const random_access_iterator<T> rhs)
// {
// 	return (lhs.base() - rhs.base());
// }

}  // namespace ft

#endif  // RANDOM_ACCESS_ITERATOR_HPP
