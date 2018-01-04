#include <boost/type_traits.hpp>
#include <iostream>

using namespace boost;

int main()
{
  std::cout.setf(std::ios::boolalpha);
  std::cout << is_integral<int>::value << '\n';
  std::cout << is_floating_point<int>::value << '\n';
  std::cout << is_arithmetic<int>::value << '\n';
  std::cout << is_reference<int>::value << '\n';
}