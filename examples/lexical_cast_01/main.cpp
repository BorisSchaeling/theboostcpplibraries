#include <boost/lexical_cast.hpp>
#include <string>
#include <iostream>

int main()
{
  std::string s = boost::lexical_cast<std::string>(123);
  std::cout << s << '\n';
  double d = boost::lexical_cast<double>(s);
  std::cout << d << '\n';
}