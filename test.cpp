#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "include/catch.hpp"
#include "include/Human.hpp"

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

Human h;

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE( "Fact Human", "[factH]" ) {
	REQUIRE( h.Factorial(1) == 1);
	REQUIRE( h.Factorial(3) == 6);
}

TEST_CASE( "PJ", "[test PJ]") {
	REQUIRE( h.getName() == "Peter Johennecken");
}
