#include <boost/tuple/tuple.hpp>
#include <string>
#include <iostream>

boost::tuple<std::string, int> new_cat()
{
  return boost::make_tuple("cat", 4);
}

int main()
{
  std::string name;
  int legs;
  boost::tie(name, legs) = new_cat();
  std::cout << name << ", " << legs << '\n';
}