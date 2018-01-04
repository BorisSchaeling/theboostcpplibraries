#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/regex.hpp>
#include <string>
#include <iostream>

int main()
{
  std::string s = "The Boost C++ Libraries";
  boost::regex expr{"[\\w+]+"};
  boost::copy(boost::adaptors::tokenize(s, expr, 0,
    boost::regex_constants::match_default),
    std::ostream_iterator<std::string>{std::cout, ","});
}