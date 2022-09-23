#ifndef TIMER_HPP
# define TIMER_HPP

# include <sys/time.h>

class Timer
{
	public:
		Timer();

		long	ElapsedMTime() const;

	private:
		struct timeval	start_;
};

#endif  // TIMER_HPP
