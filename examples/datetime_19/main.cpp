#include <boost/date_time/local_time/local_time.hpp>
#include <iostream>

using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::gregorian;

int main()
{
  time_zone_ptr tz{new posix_time_zone{"CET+0"}};

  ptime pt1{date{2014, 12, 5}, time_duration{12, 0, 0}};
  local_date_time dt1{pt1, tz};

  ptime pt2{date{2014, 12, 5}, time_duration{18, 0, 0}};
  local_date_time dt2{pt2, tz};

  local_time_period tp{dt1, dt2};

  std::cout.setf(std::ios::boolalpha);
  std::cout << tp.contains(dt1) << '\n';
  std::cout << tp.contains(dt2) << '\n';
}