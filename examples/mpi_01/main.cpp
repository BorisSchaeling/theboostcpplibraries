#include <boost/mpi.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
  boost::mpi::environment env{argc, argv};
  boost::mpi::communicator world;
  std::cout << world.rank() << ", " << world.size() << '\n';
}