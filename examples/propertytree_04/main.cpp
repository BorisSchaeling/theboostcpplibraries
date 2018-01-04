#include <boost/property_tree/ptree.hpp>
#include <utility>
#include <iostream>

using boost::property_tree::ptree;

int main()
{
  ptree pt;
  pt.put("C:.Windows.System", "20 files");

  boost::optional<std::string> c = pt.get_optional<std::string>("C:");
  std::cout << std::boolalpha << c.is_initialized() << '\n';

  pt.put_child("D:.Program Files", ptree{"50 files"});
  pt.add_child("D:.Program Files", ptree{"60 files"});

  ptree d = pt.get_child("D:");
  for (const std::pair<std::string, ptree> &p : d)
    std::cout << p.second.get_value<std::string>() << '\n';

  boost::optional<ptree&> e = pt.get_child_optional("E:");
  std::cout << e.is_initialized() << '\n';
}