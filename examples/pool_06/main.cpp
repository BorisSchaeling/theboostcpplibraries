#define BOOST_POOL_NO_MT
#include <boost/pool/pool_alloc.hpp>
#include <list>

int main()
{
  typedef boost::fast_pool_allocator<int,
    boost::default_user_allocator_new_delete,
    boost::details::pool::default_mutex,
    64, 128> allocator;

  std::list<int, allocator> l;
  for (int i = 0; i < 1000; ++i)
    l.push_back(i);

  l.clear();
  boost::singleton_pool<boost::fast_pool_allocator_tag, sizeof(int)>::
    purge_memory();
}