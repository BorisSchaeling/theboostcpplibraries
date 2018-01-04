#include <boost/graph/adjacency_list.hpp>
#include <iostream>

int main()
{
  boost::adjacency_list<> g;

  boost::adjacency_list<>::vertex_descriptor v1 = boost::add_vertex(g);
  boost::adjacency_list<>::vertex_descriptor v2 = boost::add_vertex(g);
  boost::adjacency_list<>::vertex_descriptor v3 = boost::add_vertex(g);
  boost::adjacency_list<>::vertex_descriptor v4 = boost::add_vertex(g);

  std::cout << v1 << ", " << v2 << ", " << v3 << ", " << v4 << '\n';
}