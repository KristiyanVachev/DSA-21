#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "utils.cpp"

TEST_CASE("Factorials are computed", "[factorial]") {
    REQUIRE(GetAgeInDays(1) == 365);
}