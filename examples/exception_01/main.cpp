#include <boost/exception/all.hpp>
#include <exception>
#include <new>
#include <string>
#include <algorithm>
#include <limits>
#include <iostream>

typedef boost::error_info<struct tag_errmsg, std::string> errmsg_info;

struct allocation_failed : public boost::exception, public std::exception
{
  const char *what() const noexcept { return "allocation failed"; }
};

char *allocate_memory(std::size_t size)
{
  char *c = new (std::nothrow) char[size];
  if (!c)
    throw allocation_failed{};
  return c;
}

char *write_lots_of_zeros()
{
  try
  {
    char *c = allocate_memory(std::numeric_limits<std::size_t>::max());
    std::fill_n(c, std::numeric_limits<std::size_t>::max(), 0);
    return c;
  }
  catch (boost::exception &e)
  {
    e << errmsg_info{"writing lots of zeros failed"};
    throw;
  }
}

int main()
{
  try
  {
    char *c = write_lots_of_zeros();
    delete[] c;
  }
  catch (boost::exception &e)
  {
    std::cerr << boost::diagnostic_information(e);
  }
}