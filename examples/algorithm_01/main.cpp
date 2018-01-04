#include <boost/algorithm/cxx11/one_of.hpp>
#include <array>
#include <iostream>

using namespace boost::algorithm;

int main()
{
  std::array<int, 6> a{{0, 5, 2, 1, 4, 3}};
  auto predicate = [](int i){ return i == 4; };
  std::cout.setf(std::ios::boolalpha);
  std::cout << one_of(a.begin(), a.end(), predicate) << '\n';
  std::cout << one_of_equal(a.begin(), a.end(), 4) << '\n';
}