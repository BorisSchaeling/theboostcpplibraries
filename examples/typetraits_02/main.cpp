#include <boost/type_traits.hpp>
#include <iostream>

using namespace boost;

int main()
{
  std::cout.setf(std::ios::boolalpha);
  std::cout << is_same<is_integral<int>::type, true_type>::value << '\n';
  std::cout << is_same<is_floating_point<int>::type, false_type>::value <<
    '\n';
  std::cout << is_same<is_arithmetic<int>::type, true_type>::value << '\n';
  std::cout << is_same<is_reference<int>::type, false_type>::value << '\n';
}