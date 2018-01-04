#include <boost/format.hpp>
#include <iostream>

int main()
{
  std::cout << boost::format{"%2%/%1%/%3%"} % 12 % 5 % 2014 << '\n';
}