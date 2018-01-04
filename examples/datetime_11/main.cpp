#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

using namespace boost::posix_time;

int main()
{
  ptime pt = second_clock::universal_time();
  std::cout << pt.date() << '\n';
  std::cout << pt.time_of_day() << '\n';

  pt = from_iso_string("20140512T120000");
  std::cout << pt.date() << '\n';
  std::cout << pt.time_of_day() << '\n';
}