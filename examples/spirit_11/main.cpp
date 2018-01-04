#include <boost/spirit/include/qi.hpp>
#include <string>
#include <iostream>

using namespace boost::spirit;

int main()
{
  std::string s;
  std::getline(std::cin, s);
  auto it = s.begin();
  int i;
  if (qi::phrase_parse(it, s.end(), qi::int_, ascii::space, i))
    std::cout << i << '\n';
}