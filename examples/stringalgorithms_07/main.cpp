#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace boost::algorithm;

int main()
{
  std::string s = "\t Boost C++ Libraries \t";
  std::cout << "_" << trim_left_copy(s) << "_\n";
  std::cout << "_" << trim_right_copy(s) << "_\n";
  std::cout << "_" << trim_copy(s) << "_\n";
}