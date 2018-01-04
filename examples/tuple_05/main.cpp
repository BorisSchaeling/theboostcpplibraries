#include <boost/tuple/tuple.hpp>
#include <string>
#include <iostream>

int main()
{
  typedef boost::tuple<std::string, int, bool> animal;
  animal a = boost::make_tuple("cat", 4, true);
  std::cout << a.get<0>() << '\n';
  std::cout << boost::get<0>(a) << '\n';
}