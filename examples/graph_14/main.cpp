#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/random_spanning_tree.hpp>
#include <boost/graph/named_function_params.hpp>
#include <boost/array.hpp>
#include <array>
#include <utility>
#include <random>
#include <iostream>
#include <ctime>
#include <cstdint>

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
    boost::undirectedS> graph;

  graph g{edges.begin(), edges.end(), 4};

  boost::array<int, 4> predecessors;

  std::mt19937 gen{static_cast<uint32_t>(std::time(0))};
  boost::random_spanning_tree(g, gen,
    boost::predecessor_map(predecessors.begin()).
    root_vertex(bottomLeft));

  int p = topRight;
  while (p != -1)
  {
    std::cout << p << '\n';
    p = predecessors[p];
  }
}