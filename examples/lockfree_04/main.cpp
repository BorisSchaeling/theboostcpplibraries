#include <boost/lockfree/queue.hpp>
#include <thread>
#include <atomic>
#include <iostream>

using namespace boost::lockfree;

queue<int, fixed_sized<true>> q{10000};
std::atomic<int> sum{0};

void produce()
{
  for (int i = 1; i <= 10000; ++i)
    q.push(i);
}

void consume()
{
  int i;
  while (q.pop(i))
    sum += i;
}

int main()
{
  std::thread t1{produce};
  std::thread t2{consume};
  std::thread t3{consume};
  t1.join();
  t2.join();
  t3.join();
  consume();
  std::cout << sum << '\n';
}