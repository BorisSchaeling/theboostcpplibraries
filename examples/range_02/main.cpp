#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <array>
#include <iterator>
#include <iostream>

int main()
{
  std::array<int, 6> a{{0, 1, 2, 3, 4, 5}};
  boost::random_shuffle(a);
  boost::copy(a, std::ostream_iterator<int>{std::cout, ","});
  std::cout << "\n" << *boost::max_element(a) << '\n';
  std::cout << boost::accumulate(a, 0) << '\n';
}