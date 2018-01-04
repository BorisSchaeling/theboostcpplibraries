#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
  path p{"C:\\"};
  p /= "Windows\\System";
  std::cout << p.string() << '\n';
}