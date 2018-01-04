#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace boost::algorithm;

int main()
{
  std::string s = "Boost C++ Libraries";
  std::cout << erase_first_copy(s, "s") << '\n';
  std::cout << erase_nth_copy(s, "s", 0) << '\n';
  std::cout << erase_last_copy(s, "s") << '\n';
  std::cout << erase_all_copy(s, "s") << '\n';
  std::cout << erase_head_copy(s, 5) << '\n';
  std::cout << erase_tail_copy(s, 9) << '\n';
}