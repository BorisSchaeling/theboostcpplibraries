#include <boost/mpi.hpp>
#include <boost/serialization/string.hpp>
#include <vector>
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
  boost::mpi::environment env{argc, argv};
  boost::mpi::communicator world;
  std::vector<std::string> v{"Hello, world!", "Hello, moon!",
    "Hello, sun!"};
  std::string s;
  boost::mpi::scatter(world, v, s, 0);
  std::cout << world.rank() << ": " << s << '\n';
}