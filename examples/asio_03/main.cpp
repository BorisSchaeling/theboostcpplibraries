#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <chrono>
#include <thread>
#include <iostream>

using namespace boost::asio;

int main()
{
  io_service ioservice;

  steady_timer timer1{ioservice, std::chrono::seconds{3}};
  timer1.async_wait([](const boost::system::error_code &ec)
    { std::cout << "3 sec\n"; });

  steady_timer timer2{ioservice, std::chrono::seconds{3}};
  timer2.async_wait([](const boost::system::error_code &ec)
    { std::cout << "3 sec\n"; });

  std::thread thread1{[&ioservice](){ ioservice.run(); }};
  std::thread thread2{[&ioservice](){ ioservice.run(); }};
  thread1.join();
  thread2.join();
}