#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

using namespace boost::posix_time;
using namespace boost::gregorian;

int main()
{
  ptime pt1{date{2014, 5, 12}, time_duration{12, 0, 0}};
  ptime pt2{date{2014, 5, 12}, time_duration{18, 30, 0}};
  time_duration td = pt2 - pt1;
  std::cout << td.hours() << '\n';
  std::cout << td.minutes() << '\n';
  std::cout << td.seconds() << '\n';
}