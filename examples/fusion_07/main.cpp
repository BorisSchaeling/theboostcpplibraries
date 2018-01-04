#include <boost/fusion/adapted.hpp>
#include <boost/fusion/sequence.hpp>
#include <boost/mpl/int.hpp>
#include <iostream>

struct strct
{
  int i;
  double d;
};

BOOST_FUSION_ADAPT_STRUCT(strct,
  (int, i)
  (double, d)
)

using namespace boost::fusion;

int main()
{
  strct s = {10, 3.14};
  std::cout << at<boost::mpl::int_<0>>(s) << '\n';
  std::cout << back(s) << '\n';
}