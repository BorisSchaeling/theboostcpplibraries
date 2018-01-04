#include <boost/pool/object_pool.hpp>

int main()
{
  boost::object_pool<int> pool;

  int *i = pool.malloc();
  *i = 1;

  int *j = pool.construct(2);

  pool.destroy(i);
  pool.destroy(j);
}