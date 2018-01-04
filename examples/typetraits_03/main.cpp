#include <boost/type_traits.hpp>
#include <iostream>

using namespace boost;

int main()
{
  std::cout.setf(std::ios::boolalpha);
  std::cout << has_plus<int>::value << '\n';
  std::cout << has_pre_increment<int>::value << '\n';
  std::cout << has_trivial_copy<int>::value << '\n';
  std::cout << has_virtual_destructor<int>::value << '\n';
}