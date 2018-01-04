#include <boost/random/random_device.hpp>
#include <iostream>

int main()
{
  boost::random::random_device gen;
  std::cout << gen() << '\n';
}