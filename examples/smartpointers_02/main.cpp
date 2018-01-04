#include <boost/scoped_array.hpp>

int main()
{
  boost::scoped_array<int> p{new int[2]};
  *p.get() = 1;
  p[1] = 2;
  p.reset(new int[3]);
}