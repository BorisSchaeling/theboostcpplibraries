#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>

void wait(int seconds)
{
  boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}

boost::timed_mutex mutex;

void thread1()
{
  using boost::this_thread::get_id;
  for (int i = 0; i < 5; ++i)
  {
    wait(1);
    boost::unique_lock<boost::timed_mutex> lock{mutex};
    std::cout << "Thread " << get_id() << ": " << i << std::endl;
    boost::timed_mutex *m = lock.release();
    m->unlock();
  }
}

void thread2()
{
  using boost::this_thread::get_id;
  for (int i = 0; i < 5; ++i)
  {
    wait(1);
    boost::unique_lock<boost::timed_mutex> lock{mutex,
      boost::try_to_lock};
    if (lock.owns_lock() || lock.try_lock_for(boost::chrono::seconds{1}))
    {
      std::cout << "Thread " << get_id() << ": " << i << std::endl;
    }
  }
}

int main()
{
  boost::thread t1{thread1};
  boost::thread t2{thread2};
  t1.join();
  t2.join();
}