#include <boost/function.hpp>
#include <functional>
#include <iostream>

struct world
{
  void hello(std::ostream &os)
  {
    os << "Hello, world!\n";
  }
};

int main()
{
  boost::function<void(world*, std::ostream&)> f = &world::hello;
  world w;
  f(&w, std::ref(std::cout));
}