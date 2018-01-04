#include <boost/tokenizer.hpp>
#include <string>
#include <iostream>

int main()
{
  typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
  std::string s = "Boost C++ Libraries";
  boost::char_separator<char> sep{" ", "+", boost::keep_empty_tokens};
  tokenizer tok{s, sep};
  for (const auto &t : tok)
    std::cout << t << '\n';
}