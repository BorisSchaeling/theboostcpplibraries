#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
  path p{"photo.jpg"};
  std::cout << p.stem() << '\n';
  std::cout << p.extension() << '\n';
}