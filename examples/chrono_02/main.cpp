#include <boost/chrono.hpp>
#include <iostream>

using namespace boost::chrono;

int main()
{
  process_real_cpu_clock::time_point p = process_real_cpu_clock::now();
  std::cout << p << '\n';
  std::cout << p - nanoseconds{1} << '\n';
  std::cout << p + milliseconds{1} << '\n';
  std::cout << p + seconds{1} << '\n';
  std::cout << p + minutes{1} << '\n';
  std::cout << p + hours{1} << '\n';
}