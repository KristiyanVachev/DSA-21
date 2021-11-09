#include "catch.hpp"
#include "../DataStructures/Queue.h"

TEST_CASE("Queue_IsEmpty_ShouldReturnTrue_WhenInitialized")
{
	//Act
	Queue<int> queue;

	//Assert
	REQUIRE(queue.IsEmpty() == true);
}
