#include <boost/fusion/adapted.hpp>
#include <boost/fusion/sequence.hpp>
#include <boost/mpl/int.hpp>
#include <utility>
#include <iostream>

using namespace boost::fusion;

int main()
{
  auto p = std::make_pair(10, 3.14);
  std::cout << at<boost::mpl::int_<0>>(p) << '\n';
  std::cout << back(p) << '\n';
}