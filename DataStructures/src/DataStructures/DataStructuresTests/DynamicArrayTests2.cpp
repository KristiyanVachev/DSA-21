//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "../DataStructures/DynamicArray.h"


TEST_CASE("Add_ShouldAddCorrectly2")
{
	//Arrange
	DynamicArray<int> arr;

	//Act
	arr.Add(2);

	//Assert
	REQUIRE(arr.Lenght() == 0);
}