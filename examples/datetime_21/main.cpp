#include <boost/date_time/gregorian/gregorian.hpp>
#include <string>
#include <vector>
#include <locale>
#include <iostream>

using namespace boost::gregorian;

int main()
{
  std::locale::global(std::locale{"German"});
  std::string months[12]{"Januar", "Februar", "M\xe4rz", "April",
    "Mai", "Juni", "Juli", "August", "September", "Oktober",
    "November", "Dezember"};
  std::string weekdays[7]{"Sonntag", "Montag", "Dienstag",
    "Mittwoch", "Donnerstag", "Freitag", "Samstag"};
  date d{2014, 5, 12};
  date_facet *df = new date_facet{"%A, %d. %B %Y"};
  df->long_month_names(std::vector<std::string>{months, months + 12});
  df->long_weekday_names(std::vector<std::string>{weekdays,
    weekdays + 7});
  std::cout.imbue(std::locale{std::cout.getloc(), df});
  std::cout << d << '\n';
}