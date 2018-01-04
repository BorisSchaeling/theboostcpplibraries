#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/named_function_params.hpp>
#include <boost/array.hpp>
#include <array>
#include <utility>
#include <iostream>

int main()
{
  enum { topLeft, topRight, bottomRight, bottomLeft };

  std::array<std::pair<int, int>, 4> edges{{
    std::make_pair(topLeft, topRight),
    std::make_pair(topRight, bottomRight),
    std::make_pair(bottomRight, bottomLeft),
    std::make_pair(bottomLeft, topLeft)
  }};

  struct edge_properties
  {
    int weight;
  };

  typedef boost::adjacency_list<boost::listS, boost::vecS,
    boost::undirectedS, boost::no_property,
    edge_properties> graph;

  boost::array<edge_properties, 4> props{{2, 1, 1, 1}};

  graph g{edges.begin(), edges.end(), props.begin(), 4};

  boost::array<int, 4> directions;
  boost::dijkstra_shortest_paths(g, bottomRight,
    boost::predecessor_map(directions.begin()).
    weight_map(boost::get(&edge_properties::weight, g)));

  int p = topLeft;
  while (p != bottomRight)
  {
    std::cout << p << '\n';
    p = directions[p];
  }
  std::cout << p << '\n';
}