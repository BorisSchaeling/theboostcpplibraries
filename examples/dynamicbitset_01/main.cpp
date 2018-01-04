#include <boost/dynamic_bitset.hpp>
#include <iostream>

int main()
{
  boost::dynamic_bitset<> db{3, 4};

  db.push_back(true);

  std::cout.setf(std::ios::boolalpha);
  std::cout << db.size() << '\n';
  std::cout << db.count() << '\n';
  std::cout << db.any() << '\n';
  std::cout << db.none() << '\n';

  std::cout << db[0].flip() << '\n';
  std::cout << ~db[3] << '\n';
  std::cout << db << '\n';
}