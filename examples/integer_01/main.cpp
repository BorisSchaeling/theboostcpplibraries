#include <boost/cstdint.hpp>
#include <iostream>

int main()
{
  boost::int8_t i8 = 1;
  std::cout << sizeof(i8) << '\n';

#ifndef BOOST_NO_INT64_T
  boost::uint64_t ui64 = 1;
  std::cout << sizeof(ui64) << '\n';
#endif

  boost::int_least8_t il8 = 1;
  std::cout << sizeof(il8) << '\n';

  boost::uint_least32_t uil32 = 1;
  std::cout << sizeof(uil32) << '\n';

  boost::int_fast8_t if8 = 1;
  std::cout << sizeof(if8) << '\n';

  boost::uint_fast16_t uif16 = 1;
  std::cout << sizeof(uif16) << '\n';
}