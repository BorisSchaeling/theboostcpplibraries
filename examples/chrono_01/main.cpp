#include <boost/chrono.hpp>
#include <iostream>

using namespace boost::chrono;

int main()
{
  std::cout << system_clock::now() << '\n';
#ifdef BOOST_CHRONO_HAS_CLOCK_STEADY
  std::cout << steady_clock::now() << '\n';
#endif
  std::cout << high_resolution_clock::now() << '\n';

#ifdef BOOST_CHRONO_HAS_PROCESS_CLOCKS
  std::cout << process_real_cpu_clock::now() << '\n';
  std::cout << process_user_cpu_clock::now() << '\n';
  std::cout << process_system_cpu_clock::now() << '\n';
  std::cout << process_cpu_clock::now() << '\n';
#endif

#ifdef BOOST_CHRONO_HAS_THREAD_CLOCK
  std::cout << thread_clock::now() << '\n';
#endif
}