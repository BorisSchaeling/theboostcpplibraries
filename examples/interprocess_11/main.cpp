#include <boost/interprocess/managed_shared_memory.hpp>
#include <functional>
#include <iostream>

using namespace boost::interprocess;

void construct_objects(managed_shared_memory &managed_shm)
{
  managed_shm.construct<int>("Integer")(99);
  managed_shm.construct<float>("Float")(3.14);
}

int main()
{
  shared_memory_object::remove("Boost");
  managed_shared_memory managed_shm{open_or_create, "Boost", 1024};
  auto atomic_construct = std::bind(construct_objects,
    std::ref(managed_shm));
  managed_shm.atomic_func(atomic_construct);
  std::cout << *managed_shm.find<int>("Integer").first << '\n';
  std::cout << *managed_shm.find<float>("Float").first << '\n';
}