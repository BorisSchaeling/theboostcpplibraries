#include <boost/algorithm/hex.hpp>
#include <vector>
#include <string>
#include <iterator>
#include <iostream>

using namespace boost::algorithm;

int main()
{
  std::vector<char> v{'C', '+', '+'};
  hex(v, std::ostream_iterator<char>{std::cout, ""});
  std::cout << '\n';

  std::string s = "C++";
  std::cout << hex(s) << '\n';

  std::vector<char> w{'4', '3', '2', 'b', '2', 'b'};
  unhex(w, std::ostream_iterator<char>{std::cout, ""});
  std::cout << '\n';

  std::string t = "432b2b";
  std::cout << unhex(t) << '\n';
}