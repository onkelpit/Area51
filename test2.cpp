#define BOOST_TEST_MODULE test_module1
#include <boost/test/included/unit_test.hpp>
#include "include/Human.hpp"

Human h;

BOOST_AUTO_TEST_CASE(factH) {
	BOOST_TEST( h.Factorial(1) == 1);
	BOOST_TEST( h.Factorial(3) == 6);
}

