#define BOOST_TEST_MODULE test_bulk

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <iomanip>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_bulk)


BOOST_AUTO_TEST_CASE(test_test)
{
  BOOST_CHECK(true == true);
}
BOOST_AUTO_TEST_CASE(test_valid)
{
  std::cout <<"test_valid" << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()
