#include <boost/utility/addressof.hpp>
#include <string>
#include <iostream>

struct animal
{
  std::string name;
  int legs;

  int operator&() const { return legs; }
};

int main()
{
  animal a{"cat", 4};
  std::cout << &a << '\n';
  std::cout << boost::addressof(a) << '\n';
}