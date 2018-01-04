#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace boost::algorithm;

int main()
{
  std::string s = "123456789Boost C++ Libraries123456789";
  std::cout << trim_left_copy_if(s, is_digit()) << '\n';
  std::cout << trim_right_copy_if(s, is_digit()) << '\n';
  std::cout << trim_copy_if(s, is_digit()) << '\n';
}