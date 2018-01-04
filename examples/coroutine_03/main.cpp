#include <boost/coroutine/all.hpp>
#include <tuple>
#include <string>
#include <iostream>

using boost::coroutines::coroutine;

void cooperative(coroutine<std::tuple<int, std::string>>::pull_type &source)
{
  auto args = source.get();
  std::cout << std::get<0>(args) << " " << std::get<1>(args) << '\n';
  source();
  args = source.get();
  std::cout << std::get<0>(args) << " " << std::get<1>(args) << '\n';
}

int main()
{
  coroutine<std::tuple<int, std::string>>::push_type sink{cooperative};
  sink(std::make_tuple(0, "aaa"));
  sink(std::make_tuple(1, "bbb"));
  std::cout << "end\n";
}