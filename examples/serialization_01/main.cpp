#include <boost/archive/text_oarchive.hpp>
#include <iostream>

using namespace boost::archive;

int main()
{
  text_oarchive oa{std::cout};
  int i = 1;
  oa << i;
}