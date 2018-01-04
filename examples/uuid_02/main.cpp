#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <iostream>

using namespace boost::uuids;

int main()
{
  random_generator gen;
  uuid id = gen();
  std::cout << id.size() << '\n';
  std::cout << std::boolalpha << id.is_nil() << '\n';
  std::cout << id.variant() << '\n';
  std::cout << id.version() << '\n';
}