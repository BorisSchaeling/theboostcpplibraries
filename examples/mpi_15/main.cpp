#include <boost/mpi.hpp>
#include <boost/serialization/string.hpp>
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
  boost::mpi::environment env{argc, argv};
  boost::mpi::communicator world;
  boost::mpi::communicator local = world.split(world.rank() < 2 ? 99 : 100);
  std::string s;
  if (world.rank() == 0)
    s = "Hello, world!";
  boost::mpi::broadcast(local, s, 0);
  std::cout << world.rank() << ": " << s << '\n';
}