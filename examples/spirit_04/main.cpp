#include <boost/spirit/include/qi.hpp>
#include <string>
#include <iostream>

using namespace boost::spirit;

int main()
{
  std::wstring s;
  std::getline(std::wcin, s);
  auto it = s.begin();
  bool match = qi::phrase_parse(it, s.end(), ascii::digit, ascii::space,
    qi::skip_flag::dont_postskip);
  std::wcout << std::boolalpha << match << '\n';
  if (it != s.end())
    std::wcout << std::wstring{it, s.end()} << '\n';
}