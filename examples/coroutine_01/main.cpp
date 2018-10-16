#include <boost/coroutine2/all.hpp>
#include <iostream>

using namespace boost::coroutines2;

void cooperative(coroutine<void>::push_type &sink)
{
  std::cout << "Hello";
  sink();
  std::cout << "world";
}

int main()
{
  coroutine<void>::pull_type source{cooperative};
  std::cout << ", ";
  source();
  std::cout << "!\n";
}
