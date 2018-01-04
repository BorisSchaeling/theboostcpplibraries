#include <boost/asio/io_service.hpp>
#include <boost/asio/windows/object_handle.hpp>
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

  char buffer[1024];
  DWORD transferred;
  OVERLAPPED overlapped;
  ZeroMemory(&overlapped, sizeof(overlapped));
  overlapped.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
  ReadDirectoryChangesW(file_handle, buffer, sizeof(buffer), FALSE,
    FILE_NOTIFY_CHANGE_FILE_NAME, &transferred, &overlapped, NULL);

  windows::object_handle obj_handle{ioservice, overlapped.hEvent};
  obj_handle.async_wait([&buffer, &overlapped](const error_code &ec) {
    if (!ec)
    {
      DWORD transferred;
      GetOverlappedResult(overlapped.hEvent, &overlapped, &transferred,
        FALSE);
      auto notification = reinterpret_cast<FILE_NOTIFY_INFORMATION*>(buffer);
      std::wcout << notification->Action << '\n';
      std::streamsize size = notification->FileNameLength / sizeof(wchar_t);
      std::wcout.write(notification->FileName, size);
    }
  });

  ioservice.run();
}