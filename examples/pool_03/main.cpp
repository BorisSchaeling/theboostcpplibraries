#include <boost/pool/object_pool.hpp>
#include <iostream>

int main()
{
  boost::object_pool<int> pool{32, 0};
  pool.construct();
  std::cout << pool.get_next_size() << '\n';
  pool.set_next_size(8);
}