#ifndef RANDOM_HPP
# define  RANDOM_HPP

# include <cstdlib>

inline int		RandomSize()	{ return (rand() % 10000); }
inline int		RandomVal()		{ return (rand() % 100000); }
inline int		RandomKey()		{ return (rand() % 100000); }

template <class Container>
inline typename Container::iterator	RandomItr(Container& v)
{
	typename Container::iterator	start = v.begin();
	std::advance(start, rand() % v.size());
	return (start);
}

template <class Container>
inline typename Container::iterator	RandomItr(Container& v, typename Container::iterator start)
{
	std::advance(start, rand() % std::distance(start, v.end()));
	return (start);
}

#endif  // RANDOM_HPP
