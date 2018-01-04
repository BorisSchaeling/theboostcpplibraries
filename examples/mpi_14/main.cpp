#include <boost/mpi.hpp>
#include <boost/serialization/string.hpp>
#include <string>
#include <iostream>

std::string min(const std::string &lhs, const std::string &rhs)
{
  return lhs.size() < rhs.size() ? lhs : rhs;
}

int main(int argc, char *argv[])
{
  boost::mpi::environment env{argc, argv};
  boost::mpi::communicator world;
  std::string s;
  if (world.rank() == 0)
    s = "Hello, world!";
  else if (world.rank() == 1)
    s = "Hello, moon!";
  else if (world.rank() == 2)
    s = "Hello, sun!";
  std::string result;
  boost::mpi::all_reduce(world, s, result, min);
  std::cout << world.rank() << ": " << result << '\n';
}