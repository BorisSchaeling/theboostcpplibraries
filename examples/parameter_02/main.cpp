#include <boost/parameter.hpp>
#include <string>
#include <iostream>
#include <ios>

BOOST_PARAMETER_NAME(a)
BOOST_PARAMETER_NAME(b)
BOOST_PARAMETER_NAME(c)
BOOST_PARAMETER_NAME(d)
BOOST_PARAMETER_NAME(e)

BOOST_PARAMETER_FUNCTION(
  (void),
  complicated,
  tag,
  (required
    (a, (int))
    (b, (char)))
  (optional
    (c, (double), 3.14)
    (d, (std::string), "Boost")
    (e, *, true))
)
{
  std::cout.setf(std::ios::boolalpha);
  std::cout << a << '\n';
  std::cout << b << '\n';
  std::cout << c << '\n';
  std::cout << d << '\n';
  std::cout << e << '\n';
}

int main()
{
  complicated(_b = 'B', _a = 1);
}