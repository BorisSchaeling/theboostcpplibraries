#include <iostream>
#include <utility>

template <typename T>
struct scope_exit
{
  scope_exit(T &&t) : t_{std::move(t)} {}
  ~scope_exit() { t_(); }
  T t_;
};

template <typename T>
scope_exit<T> make_scope_exit(T &&t) { return scope_exit<T>{
  std::move(t)}; }

int *foo()
{
  int *i = new int{10};
  auto cleanup = make_scope_exit([&i]() mutable { delete i; i = 0; });
  std::cout << *i << '\n';
  return i;
}

int main()
{
  int *j = foo();
  std::cout << j << '\n';
}