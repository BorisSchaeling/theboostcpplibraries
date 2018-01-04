#include <boost/tokenizer.hpp>
#include <string>
#include <iostream>

int main()
{
  typedef boost::tokenizer<boost::char_separator<wchar_t>,
    std::wstring::const_iterator, std::wstring> tokenizer;
  std::wstring s = L"Boost C++ Libraries";
  boost::char_separator<wchar_t> sep{L" "};
  tokenizer tok{s, sep};
  for (const auto &t : tok)
    std::wcout << t << '\n';
}