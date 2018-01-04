#include <boost/flyweight.hpp>
#include <string>
#include <vector>
#include <utility>

using namespace boost::flyweights;

struct city {};
struct country {};

struct person
{
  int id_;
  flyweight<std::string, tag<city>> city_;
  flyweight<std::string, tag<country>> country_;
  person(int id, std::string city, std::string country)
    : id_{id}, city_{std::move(city)}, country_{std::move(country)} {}
};

int main()
{
  std::vector<person> persons;
  for (int i = 0; i < 100000; ++i)
    persons.push_back({i, "Berlin", "Germany"});
}