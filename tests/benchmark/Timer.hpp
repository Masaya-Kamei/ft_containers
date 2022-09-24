#ifndef TIMER_HPP
# define TIMER_HPP

# include <sys/time.h>

class Timer
{
	public:
		Timer();

		unsigned long	ElapsedMTime() const;
		unsigned long	ElapsedUTime() const;

	private:
		struct timeval	start_;
};

#endif  // TIMER_HPP
