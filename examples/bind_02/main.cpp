#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

class print : public std::binary_function<std::ostream*, int, void>
{
public:
  void operator()(std::ostream *os, int i) const
  {
    *os << i << '\n';
  }
};

int main()
{
  std::vector<int> v{1, 3, 2};
  std::for_each(v.begin(), v.end(), std::bind1st(print{}, &std::cout));
}