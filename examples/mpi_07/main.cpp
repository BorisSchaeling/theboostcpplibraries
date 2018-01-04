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
    boost::mpi::request r = world.irecv(boost::mpi::any_source, 16, s);
    if (r.test())
      std::cout << s << '\n';
    else
      r.cancel();
  }
  else
  {
    std::string s = "Hello, world!";
    world.send(0, 16, s);
  }
}