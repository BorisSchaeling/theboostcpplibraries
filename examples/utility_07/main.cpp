#include <boost/utility/string_ref.hpp>
#include <iostream>

boost::string_ref start_at_boost(boost::string_ref s)
{
  auto idx = s.find("Boost");
  return (idx != boost::string_ref::npos) ? s.substr(idx) : "";
}

int main()
{
  boost::string_ref s = "The Boost C++ Libraries";
  std::cout << start_at_boost(s) << '\n';
}