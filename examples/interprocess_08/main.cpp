#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>

using namespace boost::interprocess;

int main()
{
  try
  {
    shared_memory_object::remove("Boost");
    managed_shared_memory managed_shm{open_or_create, "Boost", 1024};
    int *i = managed_shm.construct<int>("Integer")[4096](99);
  }
  catch (boost::interprocess::bad_alloc &ex)
  {
    std::cerr << ex.what() << '\n';
  }
}