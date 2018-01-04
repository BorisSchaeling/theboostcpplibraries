#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>
#include <iostream>

using namespace boost::accumulators;

int main()
{
  accumulator_set<double, features<tag::mean, tag::variance>, int> acc;
  acc(8, weight = 1);
  acc(9, weight = 1);
  acc(10, weight = 4);
  acc(11, weight = 1);
  acc(12, weight = 1);
  std::cout << mean(acc) << '\n';
  std::cout << variance(acc) << '\n';
}