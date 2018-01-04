#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>
#include <iostream>

using namespace boost::accumulators;

int main()
{
  accumulator_set<int, features<tag::count>> acc;
  acc(4);
  acc(-6);
  acc(9);
  std::cout << count(acc) << '\n';
}