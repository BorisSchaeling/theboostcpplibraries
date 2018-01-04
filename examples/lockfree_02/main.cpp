#include <boost/lockfree/spsc_queue.hpp>
#include <boost/lockfree/policies.hpp>
#include <thread>
#include <iostream>

using namespace boost::lockfree;

spsc_queue<int, capacity<100>> q;
int sum = 0;

void produce()
{
  for (int i = 1; i <= 100; ++i)
    q.push(i);
}

void consume()
{
  while (q.consume_one([](int i){ sum += i; }))
    ;
}

int main()
{
  std::thread t1{produce};
  std::thread t2{consume};
  t1.join();
  t2.join();
  q.consume_all([](int i){ sum += i; });
  std::cout << sum << '\n';
}