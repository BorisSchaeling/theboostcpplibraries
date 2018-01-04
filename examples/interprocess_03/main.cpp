#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>

using namespace boost::interprocess;

int main()
{
  shared_memory_object shdmem{open_or_create, "Boost", read_write};
  shdmem.truncate(1024);
  mapped_region region{shdmem, read_write};
  int *i1 = static_cast<int*>(region.get_address());
  *i1 = 99;
  mapped_region region2{shdmem, read_only};
  int *i2 = static_cast<int*>(region2.get_address());
  std::cout << *i2 << '\n';
}