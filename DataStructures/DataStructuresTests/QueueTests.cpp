#include "catch.hpp"
#include "../DataStructures/Queue.h"

TEST_CASE("Queue_IsEmpty_ShouldReturnTrue_WhenInitialized")
{
	//Act
	Queue<int> queue;

	//Assert
	REQUIRE(queue.IsEmpty() == true);
}

TEST_CASE("Queue_Dequeue_ShouldSetTheNextElementInLineAsHead_WhenOneExists")
{
	//Arrance
	Queue<int> queue;

	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);

	//Act
	queue.Dequeue();

	//Assert
	int nextElement = queue.Dequeue();

	REQUIRE(nextElement == 2);
}

TEST_CASE("Queue_Size_ShouldReturnTheCountOfElements")
{
	//Arrance
	Queue<int> queue;

	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);

	//Act
	int actualSize = queue.Size();

	//Assert
	REQUIRE(actualSize == 3);
}