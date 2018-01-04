#include <boost/unordered_set.hpp>
#include <string>
#include <iostream>

int main()
{
  typedef boost::unordered_set<std::string> unordered_set;
  unordered_set set;

  set.emplace("cat");
  set.emplace("shark");
  set.emplace("spider");

  for (const std::string &s : set)
    std::cout << s << '\n';

  std::cout << set.size() << '\n';
  std::cout << set.max_size() << '\n';

  std::cout << std::boolalpha << (set.find("cat") != set.end()) << '\n';
  std::cout << set.count("shark") << '\n';
}