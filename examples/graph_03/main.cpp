#include <boost/graph/adjacency_list.hpp>
#include <utility>
#include <algorithm>
#include <iterator>
#include <iostream>

int main()
{
  boost::adjacency_list<> g;

  boost::adjacency_list<>::vertex_descriptor v1 = boost::add_vertex(g);
  boost::adjacency_list<>::vertex_descriptor v2 = boost::add_vertex(g);
  boost::add_vertex(g);
  boost::add_vertex(g);

  std::pair<boost::adjacency_list<>::edge_descriptor, bool> p =
    boost::add_edge(v1, v2, g);
  std::cout.setf(std::ios::boolalpha);
  std::cout << p.second << '\n';

  p = boost::add_edge(v1, v2, g);
  std::cout << p.second << '\n';

  p = boost::add_edge(v2, v1, g);
  std::cout << p.second << '\n';

  std::pair<boost::adjacency_list<>::edge_iterator,
    boost::adjacency_list<>::edge_iterator> es = boost::edges(g);

  std::copy(es.first, es.second,
    std::ostream_iterator<boost::adjacency_list<>::edge_descriptor>{
      std::cout, "\n"});
}