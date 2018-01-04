#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace boost::algorithm;

int main()
{
  std::string s = "Boost C++ Libraries";
  boost::iterator_range<std::string::iterator> r = find_first(s, "C++");
  std::cout << r << '\n';
  r = find_first(s, "xyz");
  std::cout << r << '\n';
}