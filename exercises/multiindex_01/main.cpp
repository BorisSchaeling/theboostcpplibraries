#include <string>
#include <vector>
#include <iostream>

struct animal
{
    std::string name;
    int legs;
    bool has_tail;
};

class animals_container
{
public:
    void add(animal a)
    {
        // TODO: Implement this member function.
    }

    const animal *find_by_name(const std::string &name) const
    {
        // TODO: Implement this member function.
        return nullptr;
    }

    std::vector<animal> find_by_legs(int from, int to) const
    {
        // TODO: Implement this member function.
        return {};
    }

    std::vector<animal> find_by_tail(bool has_tail) const
    {
        // TODO: Implement this member function.
        return {};
    }
};

int main()
{
    animals_container animals;
    animals.add({ "cat", 4, true });
    animals.add({ "ant", 6, false });
    animals.add({ "spider", 8, false });
    animals.add({ "shark", 0, false });

    const animal *a = animals.find_by_name("cat");
    if (a)
        std::cout << "cat has " << a->legs << " legs\n";

    auto animals_with_6_to_8_legs = animals.find_by_legs(6, 9);
    for (auto a : animals_with_6_to_8_legs)
        std::cout << a.name << " has " << a.legs << " legs\n";

    auto animals_without_tail = animals.find_by_tail(false);
    for (auto a : animals_without_tail)
        std::cout << a.name << " has no tail\n";
}
