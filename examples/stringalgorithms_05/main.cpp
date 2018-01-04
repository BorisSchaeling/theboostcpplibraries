#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <iostream>

using namespace boost::algorithm;

int main()
{
  std::vector<std::string> v{"Boost", "C++", "Libraries"};
  std::cout << join(v, " ") << '\n';
}