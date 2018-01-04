#include <boost/graph/adjacency_list.hpp>
#include <tuple>
#include <algorithm>
#include <iterator>
#include <iostream>

int main()
{
  typedef boost::adjacency_list<boost::setS, boost::vecS,
    boost::undirectedS> graph;
  graph g;

  enum { topLeft, topRight, bottomRight, bottomLeft };

  boost::add_edge(topLeft, topRight, g);
  boost::add_edge(topRight, bottomRight, g);
  boost::add_edge(bottomRight, bottomLeft, g);
  boost::add_edge(bottomLeft, topLeft, g);

  graph::edge_iterator it, end;
  std::tie(it, end) = boost::edges(g);
  std::copy(it, end,
    std::ostream_iterator<graph::edge_descriptor>{std::cout, "\n"});
}