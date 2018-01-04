#include <boost/atomic.hpp>
#include <iostream>

int main()
{
  std::cout.setf(std::ios::boolalpha);

  boost::atomic<short> s;
  std::cout << s.is_lock_free() << '\n';

  boost::atomic<int> i;
  std::cout << i.is_lock_free() << '\n';

  boost::atomic<long> l;
  std::cout << l.is_lock_free() << '\n';
}