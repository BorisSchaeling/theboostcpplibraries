#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/named_function_params.hpp>
#include <boost/graph/visitors.hpp>
#include <boost/array.hpp>
#include <array>
#include <utility>
#include <iterator>
#include <algorithm>
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

  typedef boost::adjacency_list<boost::setS, boost::vecS,
    boost::undirectedS> graph;
  graph g{edges.begin(), edges.end(), 4};

  boost::array<int, 4> distances{{0}};

  boost::breadth_first_search(g, topLeft,
    boost::visitor(
      boost::make_bfs_visitor(
        boost::record_distances(distances.begin(),
          boost::on_tree_edge{}))));

  std::copy(distances.begin(), distances.end(),
    std::ostream_iterator<int>{std::cout, "\n"});
}