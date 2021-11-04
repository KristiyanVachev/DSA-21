
# Unit testing guidelines

## Multiple conditions in the same test case

    TEST_CASE("Age is computed are computed")
    {
    	REQUIRE(GetAgeInDays(1) == 365);
    	REQUIRE(GetAgeInDays(4) == 1459);
    	REQUIRE(GetAgeInDays(-15) == -1);
    }
### Problems
If REQUIRE #2 fails, then the REQUIRE #3 will not be executed.
<img alt="bad-test" src="https://i.gyazo.com/c98fae222fa599cd76ebb79e01bb95e9.png">

## Each test on its own

 Each test case is run independently.

    TEST_CASE("Age is computed 1")
    {
    	REQUIRE(GetAgeInDays(1) == 365);
    }
    
    TEST_CASE("Age is computed 2")
    {
    	REQUIRE(GetAgeInDays(4) == 1459);
    }
    
    TEST_CASE("Age is computed invalid")
    {
    	REQUIRE(GetAgeInDays(-15) == -1);
    }

### Problems
It is hard to understand what the test does just by the input and output.
<img alt="bad-test" src="https://i.gyazo.com/87d63bf266b9a92fd63c3a7fa4f158d8.png">

## Naming
 Names of unit tests should be longer and more descriptive.


    TEST_CASE("GetAgeInDays_ShouldCalculateCorrectly_WhenAgeIsValid")
    {
    	REQUIRE(GetAgeInDays(1) == 365);
    }
    
    TEST_CASE("GetAgeInDays_ShouldCalculateCorrectly_WhenAgeIncludesLeapYears")
    {
    	REQUIRE(GetAgeInDays(4) == 1459);
    }
    
    TEST_CASE("GetAgeInDays_ShouldReturnMinusOne_WhenAgeIsInvalid")
    {
    	REQUIRE(GetAgeInDays(-15) == -1);
    }

<img alt="bad-test" src="https://i.gyazo.com/c8b289c75d04a5f73a22b90b8cf9553d.png">

 Follow the following pattern *functionName_ShouldDoSomething_WhenSomeCondition*

## Separating parts 
Clearly separating each part of the unit test. Into 
* Arrange 
* Act 
* Assert 

Using comments to separate the parts add to the readability. 


    TEST_CASE("GetAgeInDays_ShouldCalculateCorrectly_WhenAgeIsValid")
    {
    	//Arrange
    	int age = 1;
    	int expectedResult = 365;
    
    	//Act
    	int result = GetAgeInDays(age);
    
    	//Assert
    	REQUIRE(result == expectedResult);
    }
    
    TEST_CASE("GetAgeInDays_ShouldCalculateCorrectly_WhenAgeIncludesLeapYears")
    {
    	//Arrange
    	int age = 4;
    	int expectedResult = 1459;
    
    	//Act
    	int result = GetAgeInDays(age);
    
    	//Assert
    	REQUIRE(result == expectedResult);
    }
    
    TEST_CASE("GetAgeInDays_ShouldReturnMinusOne_WhenAgeIsInvalid")
    {
    	//Arrange
    	int age = -15;
    	int expectedResult = -1;
    
    	//Act
    	int result = GetAgeInDays(age);
    
    	//Assert
    	REQUIRE(result == expectedResult);
    }

## Sections

Sections are used to add some repetative lines that are executed before each test. This could be more useful when tests require a complex setup, but it makes the tests harder to read.

    TEST_CASE("GetAgeInDays")
    {
		//Code here will be executed once for every Section.
    
    	SECTION("_ShouldCalculateCorrectly_WhenAgeIsValid") 
    	{
    		//Arrange
    		int age = 1;
    		int expectedResult = 365;
    
    		//Act
    		int result = GetAgeInDays(age);
    
    		//Assert
    		REQUIRE(result == expectedResult);
    	}
    
    	SECTION("_ShouldCalculateCorrectly_WhenAgeIncludesLeapYears")
    	{
    		//Arrange
    		int age = 4;
    		int expectedResult = 1459;
    
    		//Act
    		int result = GetAgeInDays(age);
    
    		//Assert
    		REQUIRE(result == expectedResult);
    	}
    
    	SECTION("_ShouldReturnMinusOne_WhenAgeIsInvalid")
    	{
    		//Arrange
    		int age = -15;
    		int expectedResult = -1;
    
    		//Act
    		int result = GetAgeInDays(age);
    
    		//Assert
    		REQUIRE(result == expectedResult);
    	}
    }

