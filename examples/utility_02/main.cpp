#include <boost/current_function.hpp>
#include <iostream>

int main()
{
  const char *funcname = BOOST_CURRENT_FUNCTION;
  std::cout << funcname << '\n';
}