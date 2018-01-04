#include <boost/atomic.hpp>
#include <thread>
#include <iostream>

boost::atomic<int> a{0};

void thread()
{
  a.fetch_add(1, boost::memory_order_relaxed);
}

int main()
{
  std::thread t1{thread};
  std::thread t2{thread};
  t1.join();
  t2.join();
  std::cout << a << '\n';
}