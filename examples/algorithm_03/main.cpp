#include <boost/algorithm/cxx14/equal.hpp>
#include <boost/algorithm/cxx14/mismatch.hpp>
#include <vector>
#include <iostream>

using namespace boost::algorithm;

int main()
{
  std::vector<int> v{1, 2};
  std::vector<int> w{1, 2, 3};
  std::cout.setf(std::ios::boolalpha);
  std::cout << equal(v.begin(), v.end(), w.begin(), w.end()) << '\n';
  auto pair = mismatch(v.begin(), v.end(), w.begin(), w.end());
  if (pair.first != v.end())
    std::cout << *pair.first << '\n';
  if (pair.second != w.end())
    std::cout << *pair.second << '\n';
}