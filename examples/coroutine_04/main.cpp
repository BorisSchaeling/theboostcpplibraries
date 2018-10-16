#include <boost/coroutine2/all.hpp>
#include <stdexcept>
#include <iostream>

using boost::coroutines2::coroutine;

void cooperative(coroutine<void>::push_type &sink)
{
  sink();
  throw std::runtime_error("error");
}

int main()
{
  coroutine<void>::pull_type source{cooperative};
  try
  {
    source();
  }
  catch (const std::runtime_error &e)
  {
    std::cerr << e.what() << '\n';
  }
}
