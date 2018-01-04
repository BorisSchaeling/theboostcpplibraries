#include <boost/ptr_container/ptr_vector.hpp>
#include <iostream>

int main()
{
  boost::ptr_vector<int> v;
  v.push_back(new int{1});
  v.push_back(new int{2});
  std::cout << v.back() << '\n';
}