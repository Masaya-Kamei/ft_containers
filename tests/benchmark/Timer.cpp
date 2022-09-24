#include "Timer.hpp"

Timer::Timer()
{
	gettimeofday(&start_, NULL);
}

unsigned long	Timer::ElapsedMTime() const
{
	struct timeval	end;
	gettimeofday(&end, NULL);

	return ((end.tv_sec * 1000 + end.tv_usec / 1000) - (start_.tv_sec * 1000 + start_.tv_usec / 1000));
}

unsigned long	Timer::ElapsedUTime() const
{
	struct timeval	end;
	gettimeofday(&end, NULL);

	return ((end.tv_sec * 1000000 + end.tv_usec) - (start_.tv_sec * 1000000 + start_.tv_usec));
}
