#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>
#include <iostream>

using namespace boost::system;

void fail()
{
  throw system_error{errc::make_error_code(errc::not_supported)};
}

int main()
{
  try
  {
    fail();
  }
  catch (system_error &e)
  {
    error_code ec = e.code();
    std::cerr << ec.value() << '\n';
    std::cerr << ec.category().name() << '\n';
  }
}