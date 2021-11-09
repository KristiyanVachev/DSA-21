#include "catch.hpp"
#include "../DataStructures/Stack.h"

TEST_CASE("Stack_IsEmpty_ShouldReturnTrue_WhenInitialized")
{
	//Act
	Stack<int> stack;

	//Assert
	REQUIRE(stack.IsEmpty() == true);
}
