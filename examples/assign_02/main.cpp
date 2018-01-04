#include <boost/assign.hpp>
#include <vector>
#include <deque>
#include <set>
#include <queue>

int main()
{
  std::vector<int> v;
  boost::assign::push_back(v)(1)(2)(3);

  std::deque<int> d;
  boost::assign::push_front(d)(1)(2)(3);

  std::set<int> s;
  boost::assign::insert(s)(1)(2)(3);

  std::queue<int> q;
  boost::assign::push(q)(1)(2)(3);
}