#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>

using namespace boost::interprocess;

int main()
{
  shared_memory_object::remove("Boost");
  managed_shared_memory managed_shm{open_or_create, "Boost", 1024};
  int *i = managed_shm.construct<int>("Integer")(99);
  std::cout << *i << '\n';
  std::pair<int*, std::size_t> p = managed_shm.find<int>("Integer");
  if (p.first)
    std::cout << *p.first << '\n';
}