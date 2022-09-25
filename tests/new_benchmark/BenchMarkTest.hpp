#ifndef BENCHMARKTEST_HPP
# define BENCHMARKTEST_HPP

#include <string>
#include "Timer.hpp"

class BenchMarkTest
{
	public:
		explicit BenchMarkTest(const unsigned int seed);

		void			RunAllTest();
		unsigned long	RunVectorTest();
		unsigned long	RunMapTest();
		unsigned long	RunStackTest();

	private:
		const unsigned int	seed_;

		void	PutElapsedTimeMsg(
					const unsigned long utime,
					const std::string& container_name,
					const std::string& memfunc_name = "");

		template <class TestClass>
		unsigned long	MeasureMemFunc(
			const std::string& container_name,
			const std::string& memfunc_name,
			void (TestClass::*memfunc)());
};

template <class TestClass>
unsigned long	BenchMarkTest::MeasureMemFunc(
	const std::string& container_name,
	const std::string& memfunc_name,
	void (TestClass::*memfunc)())
{
	Timer	timer;

	for (int i = 0; i < 100; ++i)
	{
		TestClass	t;
		timer.Start();
		(t.*memfunc)();
		timer.Stop();
	}

	PutElapsedTimeMsg(timer.ElapsedUTime(), container_name, memfunc_name);
	return (timer.ElapsedUTime());
}

#endif  // BENCHMARKTEST_HPP
