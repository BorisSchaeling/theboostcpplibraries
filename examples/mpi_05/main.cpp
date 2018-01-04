#include <boost/mpi.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
  boost::mpi::environment env{argc, argv};
  boost::mpi::communicator world;
  if (world.rank() == 0)
  {
    char buffer[14];
    world.recv(boost::mpi::any_source, 16, buffer, 13);
    buffer[13] = '\0';
    std::cout << buffer << '\n';
  }
  else
  {
    const char *c = "Hello, world!";
    world.send(0, 16, c, 13);
  }
}