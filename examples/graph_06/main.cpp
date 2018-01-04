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

  graph::adjacency_iterator vit, vend;
  std::tie(vit, vend) = boost::adjacent_vertices(topLeft, g);
  std::copy(vit, vend,
    std::ostream_iterator<graph::vertex_descriptor>{std::cout, "\n"});

  graph::out_edge_iterator eit, eend;
  std::tie(eit, eend) = boost::out_edges(topLeft, g);
  std::for_each(eit, eend,
    [&g](graph::edge_descriptor it)
      { std::cout << boost::target(it, g) << '\n'; });
}