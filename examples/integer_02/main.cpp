#include <boost/cstdint.hpp>
#include <iostream>

int main()
{
  boost::intmax_t imax = 1;
  std::cout << sizeof(imax) << '\n';

  std::cout << sizeof(UINT8_C(1)) << '\n';

#ifndef BOOST_NO_INT64_T
  std::cout << sizeof(INT64_C(1)) << '\n';
#endif
}