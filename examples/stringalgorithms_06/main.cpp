#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>

using namespace boost::algorithm;

int main()
{
  std::string s = "Boost C++ Libraries";
  std::cout << replace_first_copy(s, "+", "-") << '\n';
  std::cout << replace_nth_copy(s, "+", 0, "-") << '\n';
  std::cout << replace_last_copy(s, "+", "-") << '\n';
  std::cout << replace_all_copy(s, "+", "-") << '\n';
  std::cout << replace_head_copy(s, 5, "BOOST") << '\n';
  std::cout << replace_tail_copy(s, 9, "LIBRARIES") << '\n';
}