#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>
#include <array>
#include <iterator>
#include <iostream>

int main()
{
  std::array<int, 6> a{{0, 5, 2, 1, 3, 4}};
  boost::copy(boost::adaptors::filter(a, [](int i){ return i > 2; }),
    std::ostream_iterator<int>{std::cout, ","});
}