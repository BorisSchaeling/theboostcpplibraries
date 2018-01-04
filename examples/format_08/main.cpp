#include <boost/format.hpp>
#include <iostream>

int main()
{
  std::cout << boost::format{"%+s %s %s"} % 1 % 2 % 1 << '\n';
}