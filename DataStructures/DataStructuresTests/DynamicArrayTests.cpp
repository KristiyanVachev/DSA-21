#include "catch.hpp"
#include "../DataStructures/DynamicArray.h"

TEST_CASE("DynamicArray_Constructor_ShouldHaveLenghtOfZero_WhenInitialized")
{
	//Act
	DynamicArray<int> arr;

	//Assert
	REQUIRE(arr.Lenght() == 0);
}

TEST_CASE("DynamicArray_Add_ShouldAddCorrectly")
{
	//Arrange
	DynamicArray<int> arr;

	//Act
	arr.Add(2);

	//Assert
	REQUIRE(arr.Lenght() == 1);
}