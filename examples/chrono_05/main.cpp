#include <boost/chrono.hpp>
#include <iostream>

using namespace boost::chrono;

int main()
{
  std::cout << floor<minutes>(minutes{1} + seconds{45}) << '\n';
  std::cout << round<minutes>(minutes{1} + seconds{15}) << '\n';
  std::cout << ceil<minutes>(minutes{1} + seconds{15}) << '\n';
}