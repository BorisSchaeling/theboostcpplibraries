#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

int get_even_random_number()
{
  int i = std::rand();
  return (i % 2 == 0) ? i : -1;
}

int main()
{
  std::srand(static_cast<unsigned int>(std::time(0)));
  int i = get_even_random_number();
  if (i != -1)
    std::cout << std::sqrt(static_cast<float>(i)) << '\n';
}