#include <boost/optional.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using boost::optional;

optional<int> get_even_random_number()
{
  int i = std::rand();
  return (i % 2 == 0) ? i : optional<int>{};
}

int main()
{
  std::srand(static_cast<unsigned int>(std::time(0)));
  optional<int> i = get_even_random_number();
  if (i)
    std::cout << std::sqrt(static_cast<float>(*i)) << '\n';
}