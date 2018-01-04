#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>
#include <iostream>

using namespace boost::accumulators;

int main()
{
  accumulator_set<double, features<tag::mean, tag::variance>> acc;
  acc(8);
  acc(9);
  acc(10);
  acc(11);
  acc(12);
  std::cout << mean(acc) << '\n';
  std::cout << variance(acc) << '\n';
}