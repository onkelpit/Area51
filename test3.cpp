#define BOOST_TEST_MODULE test_module1
#include <boost/test/unit_test.hpp>
#include "include/Human.hpp"

Human h;

BOOST_AUTO_TEST_CASE(test_FB) {
	BOOST_TEST( h.getName() == "foo bar");
}

