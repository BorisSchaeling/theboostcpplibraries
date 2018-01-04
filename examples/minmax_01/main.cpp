#include <boost/algorithm/minmax.hpp>
#include <boost/tuple/tuple.hpp>
#include <iostream>

int main()
{
  int i = 2;
  int j = 1;

  boost::tuples::tuple<const int&, const int&> t = boost::minmax(i, j);

  std::cout << t.get<0>() << '\n';
  std::cout << t.get<1>() << '\n';
}