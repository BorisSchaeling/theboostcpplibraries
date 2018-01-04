#define BOOST_SP_USE_QUICK_ALLOCATOR
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <ctime>

int main()
{
  boost::shared_ptr<int> p;
  std::time_t then = std::time(nullptr);
  for (int i = 0; i < 1000000; ++i)
    p.reset(new int{i});
  std::time_t now = std::time(nullptr);
  std::cout << now - then << '\n';
}