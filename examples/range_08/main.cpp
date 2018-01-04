#include <boost/range/algorithm.hpp>
#include <boost/range/istream_range.hpp>
#include <iterator>
#include <iostream>

int main()
{
  boost::iterator_range<std::istream_iterator<int>> ir =
    boost::istream_range<int>(std::cin);
  boost::copy(ir, std::ostream_iterator<int>{std::cout, "\n"});
}