#include <boost/date_time/local_time/local_time.hpp>
#include <iostream>

using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::gregorian;

int main()
{
  time_zone_ptr tz{new posix_time_zone{"CET+1"}};

  ptime pt{date{2014, 5, 12}, time_duration{12, 0, 0}};
  local_date_time dt{pt, tz};
  std::cout << dt.local_time() << '\n';

  time_zone_ptr tz2{new posix_time_zone{"EET+2"}};
  std::cout << dt.local_time_in(tz2).local_time() << '\n';
}