#include <boost/system/error_code.hpp>
#include <string>
#include <iostream>

class application_category :
  public boost::system::error_category
{
public:
  const char *name() const noexcept { return "my app"; }
  std::string message(int ev) const { return "error message"; }
};

application_category cat;

int main()
{
  boost::system::error_code ec{129, cat};
  std::cout << ec.value() << '\n';
  std::cout << ec.category().name() << '\n';
}