#include <boost/lexical_cast.hpp>
#include <string>
#include <iostream>

int main()
{
  try
  {
    int i = boost::lexical_cast<int>("abc");
    std::cout << i << '\n';
  }
  catch (const boost::bad_lexical_cast &e)
  {
    std::cerr << e.what() << '\n';
  }
}