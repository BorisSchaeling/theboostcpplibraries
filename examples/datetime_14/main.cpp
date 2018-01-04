#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

using namespace boost::posix_time;
using namespace boost::gregorian;

int main()
{
  ptime pt1{date{2014, 5, 12}, time_duration{12, 0, 0}};
  time_duration td{6, 30, 0};
  ptime pt2 = pt1 + td;
  std::cout << pt2.time_of_day() << '\n';
}