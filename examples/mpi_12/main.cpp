#include <boost/mpi.hpp>
#include <boost/serialization/string.hpp>
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
  boost::mpi::environment env{argc, argv};
  boost::mpi::communicator world;
  std::string s;
  if (world.rank() == 0)
    s = "Hello, world!";
  boost::mpi::broadcast(world, s, 0);
  std::cout << s << '\n';
}