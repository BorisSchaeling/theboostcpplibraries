#include <boost/bimap.hpp>
#include <string>
#include <iostream>

int main()
{
  typedef boost::bimap<boost::bimaps::set_of<std::string>,
    boost::bimaps::set_of<int>> bimap;
  bimap animals;

  animals.insert({"cat", 4});
  animals.insert({"shark", 0});
  animals.insert({"spider", 8});

  std::cout << animals.left.count("spider") << '\n';
  std::cout << animals.right.count(8) << '\n';
}