#include <boost/mpi.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
  boost::mpi::environment env{argc, argv};
  boost::mpi::communicator world;
  if (world.rank() == 0)
  {
    int i;
    boost::mpi::status s = world.recv(boost::mpi::any_source, 16, i);
    std::cout << s.source() << ": " << i << '\n';
  }
  else
  {
    world.send(0, 16, 99);
  }
}