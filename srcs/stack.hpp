#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{

template<class T, class Container = ft::vector<T> >
class stack
{
	public:
		typedef T								value_type;
		typedef Container						container_type;
		typedef typename Container::size_type	size_type;

	protected:
		container_type	c_;

	public:
		explicit stack(const container_type& ctnr = container_type()) : c_(ctnr) {}
		~stack() {}
		stack& operator=(const stack& rhs) { c_ = rhs.c_; return (*this); }

		bool 				empty() const				{ return (c_.empty()); }
		size_type 			size()	const				{ return (c_.size()); }
		value_type& 		top()			  			{ return (c_.back()); }
		const value_type&	top() 	const				{ return (c_.back()); }
		void				push(const value_type& val)	{ c_.push_back(val); }
		void 				pop()						{ c_.pop_back(); }

		template<class T1, class Container1>
		friend bool	operator==(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);

		template<class T1, class Container1>
		friend bool	operator<(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);
};

template<class T, class Container>
bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (lhs.c_ == rhs.c_);
}

template<class T, class Container>
bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (lhs.c_ < rhs.c_);
}

template<class T, class Container>
bool	operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (!(lhs == rhs));
}

template<class T, class Container>
bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (!(rhs < lhs));
}

template<class T, class Container>
bool	operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (rhs < lhs);
}

template<class T, class Container>
bool	operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{
	return (!(lhs < rhs));
}

}  // namespace ft

#endif  // STACK_HPP
