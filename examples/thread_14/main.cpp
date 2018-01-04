#define BOOST_THREAD_PROVIDES_FUTURE
#include <boost/thread.hpp>
#include <boost/thread/future.hpp>
#include <functional>
#include <iostream>

void accumulate(boost::promise<int> &p)
{
  int sum = 0;
  for (int i = 0; i < 5; ++i)
    sum += i;
  p.set_value(sum);
}

int main()
{
  boost::promise<int> p;
  boost::future<int> f = p.get_future();
  boost::thread t{accumulate, std::ref(p)};
  std::cout << f.get() << '\n';
}