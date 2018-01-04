#include <string>
#include <vector>
#include <memory>

int main()
{
    std::vector<std::shared_ptr<std::string>> countries;
    auto germany = std::make_shared<std::string>("Germany");
    for (int i = 0; i < 500; ++i)
        countries.push_back(germany);
    auto netherlands = std::make_shared<std::string>("Netherlands");
    for (int i = 0; i < 500; ++i)
        countries.push_back(netherlands);
}
