#include <boost/container/stable_vector.hpp>
#include <iostream>

using namespace boost::container;

int main()
{
  stable_vector<int> v(2, 1);
  int &i = v[1];
  v.erase(v.begin());
  std::cout << i << '\n';
}