#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/stream.hpp>
#include <iostream>

using namespace boost::iostreams;

int main()
{
  char buffer[16];
  array_sink sink{buffer};
  stream<array_sink> os{sink};
  os << "Boost" << std::flush;
  std::cout.write(buffer, 5);
}