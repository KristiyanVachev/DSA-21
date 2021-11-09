#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <vector>

#include "../PoisonousPlants/PoisonousPlants.cpp"

TEST_CASE("poisonousPlants_SampeTestCase1")
{
	//Arrange
	vector<int> plants;

	plants.push_back(3);
	plants.push_back(6);
	plants.push_back(2);
	plants.push_back(7);
	plants.push_back(5);

	int expectedDay = 2;

	//Act
	int actualDay = poisonousPlants(plants);

	//Assert
	REQUIRE(actualDay == expectedDay);
}

TEST_CASE("poisonousPlants_SampeTestCase2")
{
	//Arrange
	vector<int> plants;

	plants.push_back(4);
	plants.push_back(3);
	plants.push_back(7);
	plants.push_back(5);
	plants.push_back(6);
	plants.push_back(4);
	plants.push_back(2);

	int expectedDay = 3;

	//Act
	int actualDay = poisonousPlants(plants);

	//Assert
	REQUIRE(actualDay == expectedDay);
}

TEST_CASE("poisonousPlants_SampeTestCase3")
{
	//Arrange
	vector<int> plants;

	plants.push_back(3);
	plants.push_back(2);
	plants.push_back(5);
	plants.push_back(4);

	int expectedDay = 2;

	//Act
	int actualDay = poisonousPlants(plants);

	//Assert
	REQUIRE(actualDay == expectedDay);
}



TEST_CASE("poisonousPlants_ShouldFinishOnDayOne_WhenAllPlantsInAscendingOrder")
{
	//Arrange
	vector<int> plants;

	plants.push_back(1);
	plants.push_back(2);
	plants.push_back(3);
	plants.push_back(4);
	plants.push_back(5);

	int expectedDay = 1;

	//Act
	int actualDay = poisonousPlants(plants);

	//Assert
	REQUIRE(actualDay == expectedDay);
}


