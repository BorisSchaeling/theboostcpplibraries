#include <boost/date_time/local_time/local_time.hpp>
#include <iostream>

using namespace boost::posix_time;
using namespace boost::gregorian;

int main()
{
  ptime pt{date{2014, 5, 12}, time_duration{12, 0, 0}};
  time_iterator it{pt, time_duration{6, 30, 0}};
  std::cout << *++it << '\n';
  std::cout << *++it << '\n';
}