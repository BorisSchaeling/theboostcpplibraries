#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace boost::algorithm;

int main()
{
  std::string s = "--Boost C++ Libraries--";
  std::cout << trim_left_copy_if(s, is_any_of("-")) << '\n';
  std::cout << trim_right_copy_if(s, is_any_of("-")) << '\n';
  std::cout << trim_copy_if(s, is_any_of("-")) << '\n';
}