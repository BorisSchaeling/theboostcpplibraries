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
    boost::mpi::request requests[2];
    std::string s[2];
    requests[0] = world.irecv(1, 16, s[0]);
    requests[1] = world.irecv(2, 16, s[1]);
    boost::mpi::wait_all(requests, requests + 2);
    std::cout << s[0] << "; " << s[1] << '\n';
  }
  else if (world.rank() == 1)
  {
    std::string s = "Hello, world!";
    world.send(0, 16, s);
  }
  else if (world.rank() == 2)
  {
    std::string s = "Hello, moon!";
    world.send(0, 16, s);
  }
}