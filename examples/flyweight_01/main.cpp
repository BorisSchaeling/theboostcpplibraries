#include <string>
#include <vector>

struct person
{
  int id_;
  std::string city_;
};

int main()
{
  std::vector<person> persons;
  for (int i = 0; i < 100000; ++i)
    persons.push_back({i, "Berlin"});
}