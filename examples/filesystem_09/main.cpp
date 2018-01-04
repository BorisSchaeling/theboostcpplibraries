#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
  path p{"C:/Windows/System"};
  std::cout << p.make_preferred() << '\n';
}