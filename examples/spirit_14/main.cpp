#include <boost/spirit/include/qi.hpp>
#include <boost/variant.hpp>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace boost::spirit;

struct print : public boost::static_visitor<>
{
  template <typename T>
  void operator()(T t) const
  {
    std::cout << std::boolalpha << t << ';';
  }
};

int main()
{
  std::string s;
  std::getline(std::cin, s);
  auto it = s.begin();
  qi::rule<std::string::iterator, boost::variant<int, bool>(),
    ascii::space_type> value = qi::int_ | qi::bool_;
  qi::rule<std::string::iterator, std::vector<boost::variant<int, bool>>(),
    ascii::space_type> values = value % ',';
  std::vector<boost::variant<int, bool>> v;
  if (qi::phrase_parse(it, s.end(), values, ascii::space, v))
  {
    for (const auto &elem : v)
      boost::apply_visitor(print{}, elem);
  }
}