#include <boost/math/constants/constants.hpp>
#include <iostream>

struct animal
{
    std::string name;
    int legs;
    bool has_tail;
};

struct important_numbers
{
    const float pi = boost::math::constants::pi<float>();
    const double e = boost::math::constants::e<double>();
};

template <class T>
void debug(const T &t)
{
    // TODO: Write member variables of t to standard output.
}

int main()
{
    animal a{ "cat", 4, true };
    debug(a);

    important_numbers in;
    debug(in);
}
