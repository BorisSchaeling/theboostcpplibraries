#include <boost/xpressive/xpressive.hpp>
#include <string>
#include <iostream>

using namespace boost::xpressive;

int main()
{
  std::string s = "Boost Libraries";
  sregex expr = +_w >> _s >> +_w;
  std::cout << std::boolalpha << regex_match(s, expr) << '\n';
}