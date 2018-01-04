#include <boost/numeric/conversion/cast.hpp>
#include <iostream>

int main()
{
  try
  {
    int i = -0x10000;
    short s = boost::numeric_cast<short>(i);
    std::cout << s << '\n';
  }
  catch (boost::numeric::negative_overflow &e)
  {
    std::cerr << e.what() << '\n';
  }
}