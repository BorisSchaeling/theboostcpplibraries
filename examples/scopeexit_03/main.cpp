#include <boost/scope_exit.hpp>
#include <iostream>

struct x
{
  int i;

  void foo()
  {
    i = 10;
    BOOST_SCOPE_EXIT(void)
    {
      std::cout << "last\n";
    } BOOST_SCOPE_EXIT_END
    BOOST_SCOPE_EXIT(this_)
    {
      this_->i = 20;
      std::cout << "first\n";
    } BOOST_SCOPE_EXIT_END
  }
};

int main()
{
  x obj;
  obj.foo();
  std::cout << obj.i << '\n';
}