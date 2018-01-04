#include <boost/utility/binary.hpp>
#include <iostream>

int main()
{
  int i = BOOST_BINARY(1001 0001);
  std::cout << i << '\n';

  short s = BOOST_BINARY(1000 0000 0000 0000);
  std::cout << s << '\n';
}