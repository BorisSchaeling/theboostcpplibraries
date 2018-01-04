#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>

using namespace boost::interprocess;

int main()
{
  shared_memory_object shdmem{open_or_create, "Boost", read_write};
  shdmem.truncate(1024);
  mapped_region region{shdmem, read_write};
  std::cout << std::hex << region.get_address() << '\n';
  std::cout << std::dec << region.get_size() << '\n';
  mapped_region region2{shdmem, read_only};
  std::cout << std::hex << region2.get_address() << '\n';
  std::cout << std::dec << region2.get_size() << '\n';
}