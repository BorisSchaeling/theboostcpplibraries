#include <boost/coroutine2/all.hpp>
#include <functional>
#include <iostream>

using boost::coroutines2::coroutine;

void cooperative(coroutine<int>::push_type &sink, int i)
{
  int j = i;
  sink(++j);
  sink(++j);
  std::cout << "end\n";
}

int main()
{
  coroutine<int>::pull_type source{[](auto &x){ cooperative(x, 0); }};
  std::cout << source.get() << '\n';
  source();
  std::cout << source.get() << '\n';
  source();
}
