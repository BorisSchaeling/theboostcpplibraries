#include <boost/any.hpp>
#include <iostream>

int main()
{
  boost::any a = 1;
  std::cout << boost::any_cast<int>(a) << '\n';
  a = 3.14;
  std::cout << boost::any_cast<double>(a) << '\n';
  a = true;
  std::cout << std::boolalpha << boost::any_cast<bool>(a) << '\n';
}