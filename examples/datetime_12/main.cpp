#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

using namespace boost::posix_time;

int main()
{
  time_duration td{16, 30, 0};
  std::cout << td.hours() << '\n';
  std::cout << td.minutes() << '\n';
  std::cout << td.seconds() << '\n';
  std::cout << td.total_seconds() << '\n';
}