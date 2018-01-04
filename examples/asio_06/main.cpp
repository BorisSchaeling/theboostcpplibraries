#include <boost/asio/io_service.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <string>
#include <ctime>

using namespace boost::asio;
using namespace boost::asio::ip;

io_service ioservice;
tcp::endpoint tcp_endpoint{tcp::v4(), 2014};
tcp::acceptor tcp_acceptor{ioservice, tcp_endpoint};
tcp::socket tcp_socket{ioservice};
std::string data;

void write_handler(const boost::system::error_code &ec,
  std::size_t bytes_transferred)
{
  if (!ec)
    tcp_socket.shutdown(tcp::socket::shutdown_send);
}

void accept_handler(const boost::system::error_code &ec)
{
  if (!ec)
  {
    std::time_t now = std::time(nullptr);
    data = std::ctime(&now);
    async_write(tcp_socket, buffer(data), write_handler);
  }
}

int main()
{
  tcp_acceptor.listen();
  tcp_acceptor.async_accept(tcp_socket, accept_handler);
  ioservice.run();
}