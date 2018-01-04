#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/stream.hpp>
#include <iostream>

using namespace boost::iostreams;

int main()
{
  file_source f{"main.cpp"};
  if (f.is_open())
  {
    stream<file_source> is{f};
    std::cout << is.rdbuf() << '\n';
    f.close();
  }
}