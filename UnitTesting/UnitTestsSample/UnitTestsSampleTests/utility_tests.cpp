#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "../UnitTestsSample/utility.cpp"

#pragma region BasicTests


TEST_CASE("Age is computed are computed")
{
	REQUIRE(GetAgeInDays(1) == 365);
	REQUIRE(GetAgeInDays(4) == 1459); //The test below will not be executed if this one fails.
	REQUIRE(GetAgeInDays(-15) == -1);
}
#pragma endregion


#pragma region Each test on its own
//Tests are now run independetnly
//Problems - it is hard to understand what the test does


//TEST_CASE("Age is computed 1")
//{
//	REQUIRE(GetAgeInDays(1) == 365);
//}
//
//TEST_CASE("Age is computed 2")
//{
//	REQUIRE(GetAgeInDays(4) == 1459);
//}
//
//TEST_CASE("Age is computed invalid")
//{
//	REQUIRE(GetAgeInDays(-15) == -1);
//}

#pragma endregion



#pragma region Naming
//Names are clear, long, and in format
//Still harder to understand 


//TEST_CASE("GetAgeInDays_ShouldCalculateCorrectly_WhenAgeIsValid")
//{
//	REQUIRE(GetAgeInDays(1) == 365);
//}
//
//TEST_CASE("GetAgeInDays_ShouldCalculateCorrectly_WhenAgeIncludesLeapYears")
//{
//	REQUIRE(GetAgeInDays(4) == 1459);
//}
//
//TEST_CASE("GetAgeInDays_ShouldReturnMinusOne_WhenAgeIsInvalid")
//{
//	REQUIRE(GetAgeInDays(-15) == -1);
//}

#pragma endregion


#pragma region AAA
//Using the AAA pattern - clearly knowing the parts of each test


//TEST_CASE("GetAgeInDays_ShouldCalculateCorrectly_WhenAgeIsValid")
//{
//	//Arrange
//	int age = 1;
//	int expectedResult = 365;
//
//	//Act
//	int result = GetAgeInDays(age);
//
//	//Assert
//	REQUIRE(result == expectedResult);
//}
//
//TEST_CASE("GetAgeInDays_ShouldCalculateCorrectly_WhenAgeIncludesLeapYears")
//{
//	//Arrange
//	int age = 4;
//	int expectedResult = 1459;
//
//	//Act
//	int result = GetAgeInDays(age);
//
//	//Assert
//	REQUIRE(result == expectedResult);
//}
//
//TEST_CASE("GetAgeInDays_ShouldReturnMinusOne_WhenAgeIsInvalid")
//{
//	//Arrange
//	int age = -15;
//	int expectedResult = -1;
//
//	//Act
//	int result = GetAgeInDays(age);
//
//	//Assert
//	REQUIRE(result == expectedResult);
//}

#pragma endregion


#pragma region Sections
//This is okay as well, but to me it seems uglier.


//TEST_CASE("GetAgeInDays")
//{
//	SECTION("_ShouldCalculateCorrectly_WhenAgeIsValid") 
//	{
//		//Arrange
//		int age = 1;
//		int expectedResult = 365;
//
//		//Act
//		int result = GetAgeInDays(age);
//
//		//Assert
//		REQUIRE(result == expectedResult);
//	}
//
//	SECTION("_ShouldCalculateCorrectly_WhenAgeIncludesLeapYears")
//	{
//		//Arrange
//		int age = 4;
//		int expectedResult = 1459;
//
//		//Act
//		int result = GetAgeInDays(age);
//
//		//Assert
//		REQUIRE(result == expectedResult);
//	}
//
//	SECTION("_ShouldReturnMinusOne_WhenAgeIsInvalid")
//	{
//		//Arrange
//		int age = -15;
//		int expectedResult = -1;
//
//		//Act
//		int result = GetAgeInDays(age);
//
//		//Assert
//		REQUIRE(result == expectedResult);
//	}
//}

#pragma endregion
