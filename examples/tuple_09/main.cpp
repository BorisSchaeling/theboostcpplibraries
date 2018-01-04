#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <string>
#include <iostream>

int main()
{
  typedef boost::tuple<std::string&, int&, bool&> animal;
  std::string name = "cat";
  int legs = 4;
  bool tail = true;
  animal a = boost::make_tuple(boost::ref(name), boost::ref(legs),
    boost::ref(tail));
  name = "dog";
  std::cout << std::boolalpha << a << '\n';
}