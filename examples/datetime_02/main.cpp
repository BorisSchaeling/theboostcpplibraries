#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

using namespace boost::gregorian;

int main()
{
  date d = day_clock::universal_day();
  std::cout << d.year() << '\n';
  std::cout << d.month() << '\n';
  std::cout << d.day() << '\n';

  d = date_from_iso_string("20140131");
  std::cout << d.year() << '\n';
  std::cout << d.month() << '\n';
  std::cout << d.day() << '\n';
}