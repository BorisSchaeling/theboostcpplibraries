#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <iostream>

using namespace boost::interprocess;

int main()
{
  managed_shared_memory managed_shm{open_or_create, "shm", 1024};
  int *i = managed_shm.find_or_construct<int>("Integer")();
  interprocess_mutex *mtx =
    managed_shm.find_or_construct<interprocess_mutex>("mtx")();
  mtx->lock();
  ++(*i);
  std::cout << *i << '\n';
  mtx->unlock();
}