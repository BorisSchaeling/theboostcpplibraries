#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

using namespace boost::gregorian;

int main()
{
  date d{2014, 1, 30};
  months ms{1};
  date d2 = d + ms;
  std::cout << d2 << '\n';
  date d3 = d2 - ms;
  std::cout << d3 << '\n';
}