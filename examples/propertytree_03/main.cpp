#include <boost/property_tree/ptree.hpp>
#include <boost/optional.hpp>
#include <iostream>
#include <cstdlib>

struct string_to_int_translator
{
  typedef std::string internal_type;
  typedef int external_type;

  boost::optional<int> get_value(const std::string &s)
  {
    char *c;
    long l = std::strtol(s.c_str(), &c, 10);
    return boost::make_optional(c != s.c_str(), static_cast<int>(l));
  }
};

int main()
{
  typedef boost::property_tree::iptree ptree;
  ptree pt;
  pt.put(ptree::path_type{"C:\\Windows\\System", '\\'}, "20 files");
  pt.put(ptree::path_type{"C:\\Windows\\Cursors", '\\'}, "50 files");

  string_to_int_translator tr;
  int files =
    pt.get<int>(ptree::path_type{"c:\\windows\\system", '\\'}, tr) +
    pt.get<int>(ptree::path_type{"c:\\windows\\cursors", '\\'}, tr);
  std::cout << files << '\n';
}