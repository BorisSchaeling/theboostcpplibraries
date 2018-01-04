#include <boost/compressed_pair.hpp>
#include <utility>
#include <iostream>

struct empty {};

int main()
{
  std::pair<int, empty> p;
  std::cout << sizeof(p) << '\n';

  boost::compressed_pair<int, empty> cp;
  std::cout << sizeof(cp) << '\n';
}