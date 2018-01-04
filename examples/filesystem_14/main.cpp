#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
  path p{"C:\\Test"};
  try
  {
    if (create_directory(p))
    {
      rename(p, "C:\\Test2");
      boost::filesystem::remove("C:\\Test2");
    }
  }
  catch (filesystem_error &e)
  {
    std::cerr << e.what() << '\n';
  }
}