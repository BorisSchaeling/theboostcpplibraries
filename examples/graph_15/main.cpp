#include <boost/graph/adjacency_matrix.hpp>
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

  typedef boost::adjacency_matrix<boost::undirectedS> graph;
  graph g{edges.begin(), edges.end(), 4};
}