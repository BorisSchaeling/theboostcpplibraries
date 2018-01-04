#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
  path p = current_path();
  directory_iterator it{p};
  while (it != directory_iterator{})
    std::cout << *it++ << '\n';
}