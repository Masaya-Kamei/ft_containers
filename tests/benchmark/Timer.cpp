#include "Timer.hpp"

Timer::Timer()
{
	gettimeofday(&start_, NULL);
}

long	Timer::ElapsedMTime() const
{
	struct timeval	end;
	gettimeofday(&end, NULL);

	return ((end.tv_sec - start_.tv_sec) * 1000
		+ (end.tv_usec - start_.tv_usec) / 1000);
}
