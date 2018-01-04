#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
  path p{"C:\\Windows\\win.ini"};
  boost::system::error_code ec;
  boost::uintmax_t filesize = file_size(p, ec);
  if (!ec)
    std::cout << filesize << '\n';
  else
    std::cout << ec << '\n';
}