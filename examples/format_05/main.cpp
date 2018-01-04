#include <boost/format.hpp>
#include <iostream>

int main()
{
  try
  {
    std::cout << boost::format{"%|+| %2% %1%"} % 1 % 2 << '\n';
  }
  catch (boost::io::format_error &ex)
  {
    std::cout << ex.what() << '\n';
  }
}