#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main()
{
  path p1{"C:\\"};
  path p2{"C:\\Windows"};
  path p3{L"C:\\Boost C++ \u5E93"};
}