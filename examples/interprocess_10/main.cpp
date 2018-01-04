#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <iostream>

using namespace boost::interprocess;

int main()
{
  shared_memory_object::remove("Boost");
  managed_shared_memory managed_shm{open_or_create, "Boost", 1024};
  typedef allocator<char,
    managed_shared_memory::segment_manager> CharAllocator;
  typedef basic_string<char, std::char_traits<char>, CharAllocator> string;
  string *s = managed_shm.find_or_construct<string>("String")("Hello!",
    managed_shm.get_segment_manager());
  s->insert(5, ", world");
  std::cout << *s << '\n';
}