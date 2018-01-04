#include <boost/filesystem.hpp>
#include <iostream>
#include <ctime>

using namespace boost::filesystem;

int main()
{
  path p{"C:\\Windows\\win.ini"};
  try
  {
    std::time_t t = last_write_time(p);
    std::cout << std::ctime(&t) << '\n';
  }
  catch (filesystem_error &e)
  {
    std::cerr << e.what() << '\n';
  }
}