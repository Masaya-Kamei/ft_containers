#ifndef OUTPUTTEST_HPP
# define OUTPUTTEST_HPP

#include <string>

class OutputTest
{
	public:
		explicit OutputTest(const unsigned int seed);

		void	RunAllTest();
		void	RunVectorTest();
		void	RunMapTest();
		void	RunStackTest();

	private:
		const unsigned int	seed_;

		template <class TestClass>
		void	RunMemFunc(
			const std::string& container_name,
			const std::string& memfunc_name,
			void (TestClass::*memfunc)());
};

template <class TestClass>
void	OutputTest::RunMemFunc(
	const std::string& container_name,
	const std::string& memfunc_name,
	void (TestClass::*memfunc)())
{
	std::cout	<< "\n[" << container_name
				<< " " << memfunc_name
				<< "]" << std::endl;
	TestClass	t;
	(t.*memfunc)();
}

#endif  // OUTPUTTEST_HPP
