#include <boost/mpi.hpp>
#include <boost/serialization/string.hpp>
#include <boost/range/irange.hpp>
#include <boost/optional.hpp>
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
  boost::mpi::environment env{argc, argv};
  boost::mpi::communicator world;
  boost::mpi::group local = world.group();
  boost::integer_range<int> r = boost::irange(0, 1);
  boost::mpi::group subgroup = local.exclude(r.begin(), r.end());
  boost::mpi::communicator others{world, subgroup};
  std::string s;
  boost::optional<int> rank = subgroup.rank();
  if (rank)
  {
    if (rank == 0)
      s = "Hello, world!";
    boost::mpi::broadcast(others, s, 0);
  }
  std::cout << world.rank() << ": " << s << '\n';
}