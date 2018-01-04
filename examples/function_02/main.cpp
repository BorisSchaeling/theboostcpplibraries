#include <boost/function.hpp>
#include <iostream>

int main()
{
  try
  {
    boost::function<int(const char*)> f;
    f("");
  }
  catch (boost::bad_function_call &ex)
  {
    std::cerr << ex.what() << '\n';
  }
}