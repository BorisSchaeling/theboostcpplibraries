#include <boost/lockfree/spsc_queue.hpp>
#include <thread>
#include <iostream>

boost::lockfree::spsc_queue<int> q{100};
int sum = 0;

void produce()
{
  for (int i = 1; i <= 100; ++i)
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
  t1.join();
  t2.join();
  consume();
  std::cout << sum << '\n';
}