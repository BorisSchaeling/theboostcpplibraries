#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main()
{
  path p1{"..."};
  path p2{"\\"};
  path p3{"@:"};
}