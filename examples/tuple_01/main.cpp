#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <string>
#include <iostream>

int main()
{
  typedef boost::tuple<std::string, int> animal;
  animal a{"cat", 4};
  std::cout << a << '\n';
}