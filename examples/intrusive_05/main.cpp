#include <boost/intrusive/set.hpp>
#include <string>
#include <utility>
#include <iostream>

using namespace boost::intrusive;

struct animal
{
  std::string name;
  int legs;
  set_member_hook<> set_hook;
  animal(std::string n, int l) : name{std::move(n)}, legs{l} {}
  bool operator<(const animal &a) const { return legs < a.legs; }
};

int main()
{
  animal a1{"cat", 4};
  animal a2{"shark", 0};
  animal a3{"spider", 8};

  typedef member_hook<animal, set_member_hook<>, &animal::set_hook> hook;
  typedef set<animal, hook> animal_set;
  animal_set animals;

  animals.insert(a1);
  animals.insert(a2);
  animals.insert(a3);

  for (const animal &a : animals)
    std::cout << a.name << '\n';
}