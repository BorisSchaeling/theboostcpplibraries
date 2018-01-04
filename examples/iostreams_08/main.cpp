#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <vector>
#include <string>
#include <iostream>

using namespace boost::iostreams;

int main()
{
  std::vector<char> v;
  back_insert_device<std::vector<char>> snk{v};
  filtering_ostream os;
  os.push(zlib_compressor{});
  os.push(snk);
  os << "Boost" << std::flush;
  os.pop();

  array_source src{v.data(), v.size()};
  filtering_istream is;
  is.push(zlib_decompressor{});
  is.push(src);
  std::string s;
  is >> s;
  std::cout << s << '\n';
}