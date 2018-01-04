#include <boost/mpi.hpp>
#include <boost/serialization/string.hpp>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>

int main(int argc, char *argv[])
{
  boost::mpi::environment env{argc, argv};
  boost::mpi::communicator world;
  if (world.rank() == 0)
  {
    std::vector<std::string> v;
    boost::mpi::gather<std::string>(world, "", v, 0);
    std::ostream_iterator<std::string> out{std::cout, "\n"};
    std::copy(v.begin(), v.end(), out);
  }
  else if (world.rank() == 1)
  {
    boost::mpi::gather(world, std::string{"Hello, world!"}, 0);
  }
  else if (world.rank() == 2)
  {
    boost::mpi::gather(world, std::string{"Hello, moon!"}, 0);
  }
}