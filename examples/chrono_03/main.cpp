#include <boost/chrono.hpp>
#include <iostream>

using namespace boost::chrono;

int main()
{
  process_real_cpu_clock::time_point p = process_real_cpu_clock::now();
  std::cout << p << '\n';
  std::cout << time_point_cast<minutes>(p) << '\n';
}