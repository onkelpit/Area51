#define BOOST_TEST_MODULE test_module1
#include <boost/test/included/unit_test.hpp>
#include "include/Human.hpp"

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

BOOST_AUTO_TEST_CASE(factorial) {
    BOOST_TEST( Factorial(1) == 1 );
    BOOST_TEST( Factorial(2) == 2 );
    BOOST_TEST( Factorial(3) == 6 );
    BOOST_TEST( Factorial(10) == 3628800 );
}

