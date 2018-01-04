#include <boost/operators.hpp>
#include <string>
#include <utility>
#include <iostream>

struct animal : public boost::less_than_comparable<animal>
{
  std::string name;
  int legs;

  animal(std::string n, int l) : name{std::move(n)}, legs{l} {}

  bool operator<(const animal &a) const { return legs < a.legs; }
};

int main()
{
  animal a1{"cat", 4};
  animal a2{"spider", 8};

  std::cout << std::boolalpha << (a2 > a1) << '\n';
}