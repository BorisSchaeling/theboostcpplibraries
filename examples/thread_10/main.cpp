#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void wait(int seconds)
{
  boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}

boost::shared_mutex mutex;
std::vector<int> random_numbers;

void fill()
{
  std::srand(static_cast<unsigned int>(std::time(0)));
  for (int i = 0; i < 3; ++i)
  {
    boost::unique_lock<boost::shared_mutex> lock{mutex};
    random_numbers.push_back(std::rand());
    lock.unlock();
    wait(1);
  }
}

void print()
{
  for (int i = 0; i < 3; ++i)
  {
    wait(1);
    boost::shared_lock<boost::shared_mutex> lock{mutex};
    std::cout << random_numbers.back() << '\n';
  }
}

int sum = 0;

void count()
{
  for (int i = 0; i < 3; ++i)
  {
    wait(1);
    boost::shared_lock<boost::shared_mutex> lock{mutex};
    sum += random_numbers.back();
  }
}

int main()
{
  boost::thread t1{fill}, t2{print}, t3{count};
  t1.join();
  t2.join();
  t3.join();
  std::cout << "Sum: " << sum << '\n';
}