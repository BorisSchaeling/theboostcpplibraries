#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

using namespace boost;

int main()
{
  gregorian::date d{2014, 5, 12};
  gregorian::day_iterator it{d};
  std::cout << *++it << '\n';
  std::cout << date_time::next_weekday(*it,
    gregorian::greg_weekday(date_time::Friday)) << '\n';
}