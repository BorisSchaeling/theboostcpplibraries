#include <boost/property_tree/ptree.hpp>
#include <utility>
#include <iostream>

int main()
{
  typedef boost::property_tree::basic_ptree<std::string, int> ptree;
  ptree pt;
  pt.put(ptree::path_type{"C:\\Windows\\System", '\\'}, 20);
  pt.put(ptree::path_type{"C:\\Windows\\Cursors", '\\'}, 50);

  ptree &windows = pt.get_child(ptree::path_type{"C:\\Windows", '\\'});
  int files = 0;
  for (const std::pair<std::string, ptree> &p : windows)
    files += p.second.get_value<int>();
  std::cout << files << '\n';
}