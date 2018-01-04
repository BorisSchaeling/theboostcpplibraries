#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/ref.hpp>
#include <string>
#include <iostream>

int main()
{
  std::string s = "cat";
  std::cout.setf(std::ios::boolalpha);
  std::cout << boost::make_tuple(boost::ref(s), 4, true) << '\n';
}