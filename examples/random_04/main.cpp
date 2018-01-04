#include <boost/random.hpp>
#include <iostream>
#include <ctime>
#include <cstdint>

int main()
{
  std::time_t now = std::time(0);
  boost::random::mt19937 gen{static_cast<std::uint32_t>(now)};
  boost::random::uniform_int_distribution<> dist{1, 100};
  std::cout << dist(gen) << '\n';
}