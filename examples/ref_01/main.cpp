#include <boost/ref.hpp>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

void print(std::ostream &os, int i)
{
  os << i << std::endl;
}

int main()
{
  std::vector<int> v{1, 3, 2};
  std::for_each(v.begin(), v.end(),
    std::bind(print, boost::ref(std::cout), std::placeholders::_1));
}