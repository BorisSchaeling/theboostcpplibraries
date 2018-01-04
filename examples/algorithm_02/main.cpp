#include <boost/algorithm/cxx11/iota.hpp>
#include <boost/algorithm/cxx11/is_sorted.hpp>
#include <boost/algorithm/cxx11/copy_if.hpp>
#include <vector>
#include <iterator>
#include <iostream>

using namespace boost::algorithm;

int main()
{
  std::vector<int> v;
  iota_n(std::back_inserter(v), 10, 5);
  std::cout.setf(std::ios::boolalpha);
  std::cout << is_increasing(v) << '\n';
  std::ostream_iterator<int> out{std::cout, ","};
  copy_until(v, out, [](int i){ return i > 12; });
}