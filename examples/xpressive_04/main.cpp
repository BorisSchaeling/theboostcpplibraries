#include <boost/xpressive/xpressive.hpp>
#include <boost/xpressive/regex_actions.hpp>
#include <string>
#include <iterator>
#include <iostream>

using namespace boost::xpressive;

int main()
{
  std::string s = "Boost Libraries";
  std::ostream_iterator<std::string> it{std::cout, "\n"};
  sregex expr = (+_w)[*boost::xpressive::ref(it) = _] >> _s >> +_w;
  std::cout << std::boolalpha << regex_match(s, expr) << '\n';
}