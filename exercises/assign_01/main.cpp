#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout));
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout));
}
