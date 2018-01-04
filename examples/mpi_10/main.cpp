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
  std::string s;
  if (world.rank() == 1)
    s = "Hello, world!";
  else if (world.rank() == 2)
    s = "Hello, moon!";
  std::vector<std::string> v;
  boost::mpi::gather(world, s, v, 0);
  std::ostream_iterator<std::string> out{std::cout, "\n"};
  std::copy(v.begin(), v.end(), out);
}