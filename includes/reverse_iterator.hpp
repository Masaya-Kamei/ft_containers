#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iterator>
# include "iterator.hpp"

namespace ft
{

template <class Iter>
class reverse_iterator
{
	public:
		typedef	Iter 													iterator_type;
		typedef	typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef	typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef	typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef	typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef	typename ft::iterator_traits<Iter>::reference			reference;

	private:
		Iter	iter_;

	public:
		reverse_iterator()
			: iter_()
		{
		}
		explicit reverse_iterator(iterator_type iter)
			: iter_(iter)
		{
		}
		template <class Iter2>
		reverse_iterator(const reverse_iterator<Iter2>& rhs)
			: iter_(rhs.base())
		{
		}
		template<class Iter2>
		reverse_iterator<Iter>& operator=(const reverse_iterator<Iter2>& rhs)
		{
			iter_ = rhs.base();
			return (*this);
		}
		virtual ~reverse_iterator()
		{
		}

		iterator_type base() const
		{
			return (iter_);
		}

		reference operator*() const
		{
			Iter	tmp = iter_;
			return (*(--tmp));
		}
		pointer operator->() const
		{
			return (&(operator*()));
		}
		reference operator[] (difference_type n) const
		{
			return (iter_[- n - 1]);
		}

		reverse_iterator<Iter>& operator++()
		{
			--iter_;
			return (*this);
		}
		reverse_iterator<Iter>  operator++(int )
		{
			reverse_iterator<Iter>	tmp(*this);
			--iter_;
			return (tmp);
		}
		reverse_iterator<Iter>& operator--()
		{
			++iter_;
			return (*this);
		}
		reverse_iterator<Iter>  operator--(int )
		{
			reverse_iterator<Iter>	tmp(*this);
			++iter_;
			return (tmp);
		}
		reverse_iterator<Iter>& operator+=(difference_type n)
		{
			iter_ -= n;
			return (*this);
		}
		reverse_iterator<Iter>& operator-=(difference_type n)
		{
			iter_ += n;
			return (*this);
		}
		reverse_iterator<Iter> operator+(difference_type n) const
		{
			return (reverse_iterator<Iter>(iter_ - n));
		}
		reverse_iterator<Iter> operator-(difference_type n) const
		{
			return (reverse_iterator<Iter>(iter_ + n));
		}
};

template <class Iter1, class Iter2>
bool operator==(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <class Iter1, class Iter2>
bool operator!=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
{
	return (lhs.base() != rhs.base());
}

template <class Iter1, class Iter2>
bool operator<(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
{
	return (lhs.base() > rhs.base());
}

template <class Iter1, class Iter2>
bool operator<=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template <class Iter1, class Iter2>
bool operator>(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
{
	return (lhs.base() < rhs.base());
}

template <class Iter1, class Iter2>
bool operator>=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template <class Iter>
reverse_iterator<Iter>	operator+(
	typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& x)
{
	return (reverse_iterator<Iter>(x.base() - n));
}

template <class Iter1, class Iter2>
typename reverse_iterator<Iter1>::difference_type	operator-
	(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
{
	return (rhs.base() - lhs.base());
}

}  // namespace ft

#endif  // REVERSE_ITERATOR_HPP
