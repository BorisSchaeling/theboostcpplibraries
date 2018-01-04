#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <iostream>

template <typename T>
void print(typename boost::enable_if<std::is_integral<T>, T>::type i)
{
  std::cout << "Integral: " << i << '\n';
}

template <typename T>
void print(typename boost::enable_if<std::is_floating_point<T>, T>::type f)
{
  std::cout << "Floating point: " << f << '\n';
}

int main()
{
  print<short>(1);
  print<long>(2);
  print<double>(3.14);
}