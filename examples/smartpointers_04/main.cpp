#include <boost/shared_ptr.hpp>
#include <Windows.h>

int main()
{
  boost::shared_ptr<void> handle(OpenProcess(PROCESS_SET_INFORMATION, FALSE,
    GetCurrentProcessId()), CloseHandle);
}