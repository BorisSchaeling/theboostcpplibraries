#include <boost/phoenix/phoenix.hpp>
#include <iostream>

int main()
{
  using namespace boost::phoenix::placeholders;
  std::cout << arg1(1, 2, 3, 4, 5) << '\n';

  auto v = boost::phoenix::val(2);
  std::cout << v() << '\n';
}