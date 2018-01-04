#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <iostream>

int main()
{
  std::cout.setf(std::ios::boolalpha);
  std::cout << boost::make_tuple("cat", 4, true) << '\n';
}