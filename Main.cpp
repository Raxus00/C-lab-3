#undef new
#include "Tests.hpp"
#include <iostream>
#include "MemoryLeakChecker.hpp"

int main()
{
	{
		bool result = TestShape() && TestPolymorphism() && TestCircle() && TestRectangle()
					&& TestShapeContainerAddRectangle() && TestShapeContainerAddCircle()
					&& TestShapeContainerCopying() && TestShapeContainerIntersection();

		if(!result)
			return -1;
	}
	if(MemoryLeakChecker::LeakExists())
	{
		std::cout << "Memory leaks exists, dumping information" << std::endl;
		MemoryLeakChecker::DumpInformation();
		return -1;
	}


	std::cout << "All tests succeded!";
	return 0;
}