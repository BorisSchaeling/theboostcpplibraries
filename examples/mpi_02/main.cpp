#include <boost/mpi.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
  boost::mpi::environment env{argc, argv};
  boost::mpi::communicator world;
  if (world.rank() == 0)
  {
    int i;
    world.recv(1, 16, i);
    std::cout << i << '\n';
  }
  else if (world.rank() == 1)
  {
    world.send(0, 16, 99);
  }
}