#include <boost/fusion/tuple.hpp>
#include <boost/fusion/iterator.hpp>
#include <boost/mpl/int.hpp>
#include <string>
#include <iostream>

using namespace boost::fusion;

int main()
{
  typedef tuple<int, std::string, bool, double> tuple_type;
  tuple_type t{10, "Boost", true, 3.14};
  auto it = begin(t);
  std::cout << *it << '\n';
  auto it2 = advance<boost::mpl::int_<2>>(it);
  std::cout << std::boolalpha << *it2 << '\n';
}