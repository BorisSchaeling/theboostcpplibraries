#include <boost/swap.hpp>
#include <boost/array.hpp>
#include <iostream>

int main()
{
  char c1 = 'a';
  char c2 = 'b';

  boost::swap(c1, c2);

  std::cout << c1 << c2 << '\n';

  boost::array<int, 1> a1{{1}};
  boost::array<int, 1> a2{{2}};

  boost::swap(a1, a2);

  std::cout << a1[0] << a2[0] << '\n';
}