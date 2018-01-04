#include <boost/range/algorithm.hpp>
#include <array>
#include <iostream>

int main()
{
  std::array<int, 6> a{{0, 1, 0, 1, 0, 1}};
  std::cout << boost::count(a, 0) << '\n';
}