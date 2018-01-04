#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/iostreams/stream.hpp>
#include <iostream>
#include <Windows.h>

using namespace boost::iostreams;

int main()
{
  HANDLE handles[2];
  if (CreatePipe(&handles[0], &handles[1], nullptr, 0))
  {
    file_descriptor_source src{handles[0], close_handle};
    stream<file_descriptor_source> is{src};

    file_descriptor_sink snk{handles[1], close_handle};
    stream<file_descriptor_sink> os{snk};

    os << "Boost" << std::endl;
    std::string s;
    std::getline(is, s);
    std::cout << s;
  }
}