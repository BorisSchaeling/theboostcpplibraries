#include <boost/chrono.hpp>
#include <iostream>

using namespace boost::chrono;

int main()
{
  minutes m{1};
  seconds s{35};

  std::cout << m + s << '\n';
  std::cout << duration_cast<minutes>(m + s) << '\n';
}