#include <boost/optional.hpp>
#include <string>
#include <vector>
#include <iostream>

struct animal
{
    std::string name;
    int legs;

    animal(std::string n, int l) : name(n), legs(l) {}
};

class animals_container
{
public:
    void add(animal a)
    {
        // TODO: Implement this member function.
    }

    boost::optional<animal> find_by_name(const std::string &name) const
    {
        // TODO: Implement this member function.
        return {};
    }

    std::vector<animal> find_by_legs(int from, int to) const
    {
        // TODO: Implement this member function.
        return {};
    }
};

int main()
{
    animals_container animals;
    animals.add({ "cat", 4 });
    animals.add({ "ant", 6 });
    animals.add({ "spider", 8 });
    animals.add({ "shark", 0 });

    auto shark = animals.find_by_name("shark");
    if (shark)
        std::cout << "shark has " << shark->legs << " legs\n";

    auto animals_with_4_to_6_legs = animals.find_by_legs(4, 7);
    for (auto animal : animals_with_4_to_6_legs)
        std::cout << animal.name << " has " << animal.legs << " legs\n";
}
