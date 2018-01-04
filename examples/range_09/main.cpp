#include <boost/range/algorithm.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/range/sub_range.hpp>
#include <array>
#include <iterator>
#include <iostream>

int main()
{
  std::array<int, 6> a{{0, 1, 2, 3, 4, 5}};
  boost::iterator_range<std::array<int, 6>::iterator> r1 =
    boost::random_shuffle(a);
  boost::sub_range<std::array<int, 6>> r2 =
    boost::random_shuffle(r1);
  boost::copy(r2, std::ostream_iterator<int>{std::cout, ","});
}