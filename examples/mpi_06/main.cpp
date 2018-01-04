#include <boost/mpi.hpp>
#include <boost/serialization/string.hpp>
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
  boost::mpi::environment env{argc, argv};
  boost::mpi::communicator world;
  if (world.rank() == 0)
  {
    std::string s;
    world.recv(boost::mpi::any_source, 16, s);
    std::cout << s << '\n';
  }
  else
  {
    std::string s = "Hello, world!";
    world.send(0, 16, s);
  }
}