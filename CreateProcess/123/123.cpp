#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>

int main()
{
	char pathwitharguments[256];
	char path[256];
	char arg[256];
	wchar_t env_var[256];

	int choise = 1;
	int action = 0;

	STARTUPINFOA Sif;
	ZeroMemory(&Sif, sizeof(STARTUPINFOA));
	PROCESS_INFORMATION pi;
	std::cout << "Enter desired action - create or end a process\n  1.CreateProcess\n   2.TerminateProcess\n";
	std::cin >> action;
	for (;;)
	{
		switch (action)
		{
		case 1:
			for (; choise == 1;)
			{
				std::cout << "Enter full file path \n ";
				std::cout << "exaple of path: ""C:\\Folder\\file.exe""\n ";
				std::cin >> path;

				std::cout << "Enter arguments (separate it with a space)";
				std::cout << "example of argument: ""/arg_1"" \n ";
				std::cin >> arg;

				std::cout << "Enter environment variable\n";
				std::wcin >> env_var;

				LPCTSTR MY_ENV_VAR = env_var;

				strcat(pathwitharguments, path);
				strcat(pathwitharguments, arg);

				LPCSTR FILEPATH = (LPCSTR)pathwitharguments;
				std::cout << "You want to start " << path << " with arguments " << arg << " and set MY_ENV_VAR = " << MY_ENV_VAR << " ?\n 1.Yes\n 2.No\n";
				std::cin >> choise;
				if (choise != 0 || choise != 1)
				{
					return 0;
				};

				if (choise == 0)
				{
					if(!CreateProcessA(FILEPATH, NULL,
						NULL, NULL, FALSE, CREATE_NEW_CONSOLE, (LPVOID)MY_ENV_VAR, NULL, &Sif, &pi))
					{
						printf("CreateProcess failed (%d).\n", GetLastError());
						return 0;
					}

				}
			}
			break;
		case 2:
			TerminateProcess(pi.hProcess, NO_ERROR);
		}
	}
}