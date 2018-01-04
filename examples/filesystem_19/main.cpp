#include <boost/filesystem/fstream.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
  path p{"test.txt"};
  ofstream ofs{p};
  ofs << "Hello, world!\n";
}