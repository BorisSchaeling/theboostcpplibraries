#define BOOST_THREAD_PROVIDES_FUTURE
#include <boost/thread.hpp>
#include <boost/thread/future.hpp>
#include <utility>
#include <iostream>

int accumulate()
{
  int sum = 0;
  for (int i = 0; i < 5; ++i)
    sum += i;
  return sum;
}

int main()
{
  boost::packaged_task<int> task{accumulate};
  boost::future<int> f = task.get_future();
  boost::thread t{std::move(task)};
  std::cout << f.get() << '\n';
}