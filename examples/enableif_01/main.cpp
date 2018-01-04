#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <string>
#include <iostream>

template <typename T>
typename boost::enable_if<std::is_same<T, int>, T>::type create()
{
  return 1;
}

template <typename T>
typename boost::enable_if<std::is_same<T, std::string>, T>::type create()
{
  return "Boost";
}

int main()
{
  std::cout << create<std::string>() << '\n';
}