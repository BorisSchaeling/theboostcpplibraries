#include <boost/fusion/tuple.hpp>
#include <boost/fusion/view.hpp>
#include <boost/fusion/algorithm.hpp>
#include <boost/type_traits.hpp>
#include <boost/mpl/arg.hpp>
#include <string>
#include <iostream>

using namespace boost::fusion;

struct print
{
  template <typename T>
  void operator()(const T &t) const
  {
    std::cout << std::boolalpha << t << '\n';
  }
};

int main()
{
  typedef tuple<int, std::string, bool, double> tuple_type;
  tuple_type t{10, "Boost", true, 3.14};
  filter_view<tuple_type, boost::is_integral<boost::mpl::arg<1>>> v{t};
  for_each(v, print{});
}