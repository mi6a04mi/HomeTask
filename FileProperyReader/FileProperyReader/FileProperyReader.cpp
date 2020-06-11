#include "windows.h"
#include <iostream>
#include <exception>

int main()
{
        TCHAR filepath[256];
        std::wcin >> filepath;
        LPCWSTR FILEPATH = filepath;
    BY_HANDLE_FILE_INFORMATION lpFileInformation;
	SYSTEMTIME lpSystemCreationTime, lpSystemWriteTime,lpSystemAccessTime;
   HANDLE hFile = CreateFile(FILEPATH,
        GENERIC_READ, 
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);
   GetFileInformationByHandle(
      hFile,
      &lpFileInformation
   );
   FileTimeToSystemTime(
       &lpFileInformation.ftCreationTime,
       &lpSystemCreationTime
   ); 
   FileTimeToSystemTime(
       &lpFileInformation.ftLastWriteTime,
       &lpSystemWriteTime
   );
   FileTimeToSystemTime(
       &lpFileInformation.ftLastAccessTime,
       &lpSystemAccessTime
   );
   std::wcout<<"Creation time:" << " YEAR:" << lpSystemCreationTime.wYear << " MONTH:" << lpSystemCreationTime.wMonth << " DAY:" << lpSystemCreationTime.wDay + 1<< " HOUR:" << lpSystemCreationTime.wHour << " MINUTES:" << lpSystemCreationTime.wMinute << "\n";
   std::wcout<< "Write time:" << " YEAR:" << lpSystemWriteTime.wYear << " MONTH:" << lpSystemWriteTime.wMonth << " DAY:" << lpSystemWriteTime.wDay + 1 << " HOUR:" << lpSystemWriteTime.wHour << " MINUTES:" << lpSystemWriteTime.wMinute << "\n";
   std::wcout<< "Access time:" << " YEAR:" << lpSystemAccessTime.wYear << " MONTH:" << lpSystemAccessTime.wMonth << " DAY:" << lpSystemAccessTime.wDay + 1 << " HOUR:" << lpSystemAccessTime.wHour << " MINUTES:" << lpSystemAccessTime.wMinute << "\n";
   std::wcout<< "Full path to file: " << filepath << "\n";
   if ((FILE_ATTRIBUTE_DIRECTORY & GetFileAttributes(filepath)) == FILE_ATTRIBUTE_DIRECTORY)
   {
       std::wcout<<"Its folder\n";
   }
   else
   {
       std::wcout << "Its file\n";
   }
}
