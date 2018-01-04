#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/counter.hpp>
#include <iostream>

using namespace boost::iostreams;

int main()
{
  char buffer[16];
  array_sink sink{buffer};
  filtering_ostream os;
  os.push(counter{});
  os.push(sink);
  os << "Boost" << std::flush;
  os.pop();
  counter *c = os.component<counter>(0);
  std::cout << c->characters() << '\n';
  std::cout << c->lines() << '\n';
}