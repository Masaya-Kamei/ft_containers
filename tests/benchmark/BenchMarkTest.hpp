#ifndef BENCHMARKTEST_HPP
# define BENCHMARKTEST_HPP

#include <string>
#include "Timer.hpp"

class BenchMarkTest
{
	public:
		BenchMarkTest();

		void	RunAllTest();
		void	RunVectorTest();
		// RunStackTest();
		// RunMapTest();

	private:
		const unsigned int	seed_;

		void	MeasureLoop(
					const std::string& container_name,
					const std::string& memfunc_name,
					void (*memfunc)(unsigned int),
					const int count);
		void	PutElapsedMTimeMsg(
					const Timer& timer,
					const std::string& container_name,
					const std::string& memfunc_name = "");
};

#endif  // BENCHMARKTEST_HPP
