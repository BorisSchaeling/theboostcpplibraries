#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
  path p{"C:\\"};
  try
  {
    space_info s = space(p);
    std::cout << s.capacity << '\n';
    std::cout << s.free << '\n';
    std::cout << s.available << '\n';
  }
  catch (filesystem_error &e)
  {
    std::cerr << e.what() << '\n';
  }
}