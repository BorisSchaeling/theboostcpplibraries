#define BOOST_CHRONO_VERSION 2
#include <boost/chrono.hpp>
#include <boost/chrono/chrono_io.hpp>
#include <iostream>

using namespace boost::chrono;

int main()
{
  std::cout << symbol_format << minutes{10} << '\n';

  std::cout << time_fmt(boost::chrono::timezone::local, "%H:%M:%S") <<
    system_clock::now() << '\n';
}