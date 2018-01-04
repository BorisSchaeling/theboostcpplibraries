#include <boost/fusion/container.hpp>
#include <boost/fusion/sequence.hpp>
#include <boost/fusion/algorithm.hpp>
#include <string>
#include <iostream>

using namespace boost::fusion;

int main()
{
  auto m = make_map<int, std::string, bool, double>("Boost", 10, 3.14, true);
  if (has_key<std::string>(m))
    std::cout << at_key<std::string>(m) << '\n';
  auto m2 = erase_key<std::string>(m);
  auto m3 = push_back(m2, make_pair<float>('X'));
  std::cout << std::boolalpha << has_key<std::string>(m3) << '\n';
}