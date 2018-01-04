#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

using namespace boost::gregorian;

int main()
{
  date_duration dd{4};
  std::cout << dd.days() << '\n';
  weeks ws{4};
  std::cout << ws.days() << '\n';
  months ms{4};
  std::cout << ms.number_of_months() << '\n';
  years ys{4};
  std::cout << ys.number_of_years() << '\n';
}