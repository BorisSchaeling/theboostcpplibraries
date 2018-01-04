#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace boost::algorithm;

int main()
{
  std::string s = "Boost C++ Libraries";
  std::cout.setf(std::ios::boolalpha);
  std::cout << starts_with(s, "Boost") << '\n';
  std::cout << ends_with(s, "Libraries") << '\n';
  std::cout << contains(s, "C++") << '\n';
  std::cout << lexicographical_compare(s, "Boost") << '\n';
}