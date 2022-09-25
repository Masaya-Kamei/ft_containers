#ifndef TIMER_HPP
# define TIMER_HPP

# include <sys/time.h>

class Timer
{
	public:
		Timer() : elapsed_utime_(0) {}

		unsigned long	ElapsedUTime() const { return (elapsed_utime_); }

		void	Start()
		{
			gettimeofday(&start_, NULL);
		}

		void	Stop()
		{
			struct timeval	end;
			gettimeofday(&end, NULL);

			elapsed_utime_ += (end.tv_sec * 1000000 + end.tv_usec) - (start_.tv_sec * 1000000 + start_.tv_usec);
		}

	private:
		struct timeval	start_;
		unsigned long	elapsed_utime_;
};

#endif  // TIMER_HPP
