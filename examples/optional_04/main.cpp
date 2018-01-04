#include <boost/optional.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace boost;

optional<int> get_even_random_number()
{
  int i = std::rand();
  return make_optional(i % 2 == 0, i);
}

int main()
{
  std::srand(static_cast<unsigned int>(std::time(0)));
  optional<int> i = get_even_random_number();
  double d = get_optional_value_or(i, 0);
  std::cout << std::sqrt(d) << '\n';
}