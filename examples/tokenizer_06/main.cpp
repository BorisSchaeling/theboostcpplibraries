#include <boost/tokenizer.hpp>
#include <string>
#include <iostream>

int main()
{
  typedef boost::tokenizer<boost::escaped_list_separator<char>> tokenizer;
  std::string s = "Boost,\"C++ Libraries\"";
  tokenizer tok{s};
  for (const auto &t : tok)
    std::cout << t << '\n';
}