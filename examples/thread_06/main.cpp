#include <boost/thread.hpp>
#include <iostream>

int main()
{
  std::cout << boost::this_thread::get_id() << '\n';
  std::cout << boost::thread::hardware_concurrency() << '\n';
}