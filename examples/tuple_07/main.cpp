#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <string>
#include <iostream>

int main()
{
  typedef boost::tuple<std::string, int, bool> animal;
  animal a1 = boost::make_tuple("cat", 4, true);
  animal a2 = boost::make_tuple("shark", 0, true);
  std::cout << std::boolalpha << (a1 != a2) << '\n';
}