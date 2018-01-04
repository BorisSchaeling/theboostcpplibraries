#include <boost/xpressive/xpressive.hpp>
#include <iostream>

using namespace boost::xpressive;

int main()
{
  const char *c = "Boost Libraries";
  cregex expr = cregex::compile("\\w+\\s\\w+");
  std::cout << std::boolalpha << regex_match(c, expr) << '\n';
}