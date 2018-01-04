#include <boost/fusion/container.hpp>
#include <boost/fusion/sequence.hpp>
#include <boost/mpl/int.hpp>
#include <string>
#include <iostream>

using namespace boost::fusion;

int main()
{
  typedef vector<int, std::string, bool, double> vector_type;
  vector_type v{10, "Boost", true, 3.14};
  std::cout << at<boost::mpl::int_<0>>(v) << '\n';

  auto v2 = push_back(v, 'X');
  std::cout << size(v) << '\n';
  std::cout << size(v2) << '\n';
  std::cout << back(v2) << '\n';
}