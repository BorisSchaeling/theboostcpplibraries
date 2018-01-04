#include <boost/next_prior.hpp>
#include <array>
#include <algorithm>
#include <iostream>

int main()
{
  std::array<char, 4> a{{'a', 'c', 'b', 'd'}};

  auto it = std::find(a.begin(), a.end(), 'b');
  auto prior = boost::prior(it, 2);
  auto next = boost::next(it);

  std::cout << *prior << '\n';
  std::cout << *it << '\n';
  std::cout << *next << '\n';
}