#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
  path p{"/"};
  std::cout << p.string() << '\n';
  std::cout << p.generic_string() << '\n';
}