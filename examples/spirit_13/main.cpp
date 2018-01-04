#include <boost/spirit/include/qi.hpp>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace boost::spirit;

int main()
{
  std::string s;
  std::getline(std::cin, s);
  auto it = s.begin();
  qi::rule<std::string::iterator, std::vector<int>(),
    ascii::space_type> values = qi::int_ % ',';
  std::vector<int> v;
  if (qi::phrase_parse(it, s.end(), values, ascii::space, v))
  {
    std::ostream_iterator<int> out{std::cout, ";"};
    std::copy(v.begin(), v.end(), out);
  }
}