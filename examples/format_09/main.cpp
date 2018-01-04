#include <boost/format.hpp>
#include <string>
#include <iostream>

struct animal
{
  std::string name;
  int legs;
};

std::ostream &operator<<(std::ostream &os, const animal &a)
{
  return os << a.name << ',' << a.legs;
}

int main()
{
  animal a{"cat", 4};
  std::cout << boost::format{"%1%"} % a << '\n';
}