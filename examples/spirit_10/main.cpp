#define BOOST_SPIRIT_USE_PHOENIX_V3
#include <boost/spirit/include/qi.hpp>
#include <boost/phoenix/phoenix.hpp>
#include <string>
#include <iostream>

using namespace boost::spirit;
using boost::phoenix::ref;

int main()
{
  std::string s;
  std::getline(std::cin, s);
  auto it = s.begin();
  int i;
  bool match = qi::phrase_parse(it, s.end(), qi::int_[ref(i) = qi::_1],
    ascii::space);
  std::cout << std::boolalpha << match << '\n';
  if (match)
    std::cout << i << '\n';
  if (it != s.end())
    std::cout << std::string{it, s.end()} << '\n';
}