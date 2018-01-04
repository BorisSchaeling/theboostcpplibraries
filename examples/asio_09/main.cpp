#include <boost/asio/io_service.hpp>
#include <boost/asio/windows/overlapped_ptr.hpp>
#include <boost/system/error_code.hpp>
#include <iostream>
#include <Windows.h>

using namespace boost::asio;
using namespace boost::system;

int main()
{
  io_service ioservice;

  HANDLE file_handle = CreateFileA(".", FILE_LIST_DIRECTORY,
    FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL,
    OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED, NULL);

  error_code ec;
  auto &io_service_impl = use_service<detail::io_service_impl>(ioservice);
  io_service_impl.register_handle(file_handle, ec);

  char buffer[1024];
  auto handler = [&buffer](const error_code &ec, std::size_t) {
    if (!ec)
    {
      auto notification =
        reinterpret_cast<FILE_NOTIFY_INFORMATION*>(buffer);
      std::wcout << notification->Action << '\n';
      std::streamsize size = notification->FileNameLength / sizeof(wchar_t);
      std::wcout.write(notification->FileName, size);
    }
  };
  windows::overlapped_ptr overlapped{ioservice, handler};
  DWORD transferred;
  BOOL ok = ReadDirectoryChangesW(file_handle, buffer, sizeof(buffer),
    FALSE, FILE_NOTIFY_CHANGE_FILE_NAME, &transferred, overlapped.get(),
    NULL);
  int last_error = GetLastError();
  if (!ok && last_error != ERROR_IO_PENDING)
  {
    error_code ec{last_error, error::get_system_category()};
    overlapped.complete(ec, 0);
  }
  else
  {
    overlapped.release();
  }

  ioservice.run();
}