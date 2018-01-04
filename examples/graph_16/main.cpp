#include <boost/graph/compressed_sparse_row_graph.hpp>
#include <array>
#include <utility>

int main()
{
  enum { topLeft, topRight, bottomRight, bottomLeft };

  std::array<std::pair<int, int>, 4> edges{{
    std::make_pair(topLeft, topRight),
    std::make_pair(topRight, bottomRight),
    std::make_pair(bottomRight, bottomLeft),
    std::make_pair(bottomLeft, topLeft)
  }};

  typedef boost::compressed_sparse_row_graph<boost::bidirectionalS> graph;
  graph g{boost::edges_are_unsorted_multi_pass, edges.begin(),
    edges.end(), 4};
}