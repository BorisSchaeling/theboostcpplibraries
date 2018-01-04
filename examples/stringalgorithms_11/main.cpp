#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <iostream>

using namespace boost::algorithm;

int main()
{
  std::string s = "Boost C++ Libraries";
  std::vector<std::string> v;
  split(v, s, is_space());
  std::cout << v.size() << '\n';
}