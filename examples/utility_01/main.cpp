#include <boost/checked_delete.hpp>
#include <boost/intrusive/list.hpp>
#include <string>
#include <utility>
#include <iostream>

struct animal : public boost::intrusive::list_base_hook<>
{
  std::string name_;
  int legs_;

  animal(std::string name, int legs) : name_{std::move(name)},
    legs_{legs} {}
};

int main()
{
  animal *a = new animal{"cat", 4};

  typedef boost::intrusive::list<animal> animal_list;
  animal_list al;

  al.push_back(*a);

  al.pop_back_and_dispose(boost::checked_delete<animal>);
  std::cout << al.size() << '\n';
}