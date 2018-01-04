#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
  path p{"C:\\"};
  try
  {
    file_status s = status(p);
    std::cout << std::boolalpha << is_directory(s) << '\n';
  }
  catch (filesystem_error &e)
  {
    std::cerr << e.what() << '\n';
  }
}