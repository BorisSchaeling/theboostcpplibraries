#include <boost/fusion/tuple.hpp>
#include <string>
#include <iostream>

using namespace boost::fusion;

int main()
{
  typedef tuple<int, std::string, bool, double> tuple_type;
  tuple_type t{10, "Boost", true, 3.14};
  std::cout << get<0>(t) << '\n';
  std::cout << get<1>(t) << '\n';
  std::cout << std::boolalpha << get<2>(t) << '\n';
  std::cout << get<3>(t) << '\n';
}