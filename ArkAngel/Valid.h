#pragma once
//#include <winsock2.h>
//#include <windows.h>
//#include <iostream>
//#pragma warning(disable: 4996)
//#pragma comment(lib,"ws2_32.lib")
//
//bool ValidateHWID(std::string hwid)
//{
//    WSADATA wsaData;
//    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
//        cout << "WSAStartup failed.\n";
//        system("pause");
//        return false;
//    }
//    SOCKET Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//    struct hostent* host;
//    host = gethostbyname("www.arkangel-dl.neocities.org");
//    if (!host)
//        return false;
//    SOCKADDR_IN SockAddr;
//    SockAddr.sin_port = htons(80);
//    SockAddr.sin_family = AF_INET;
//    SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);
//    cout << "Connecting...\n";
//    if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0) {
//        cout << "Could not connect";
//        system("pause");
//        return false;
//    }
//    cout << "Connected.\n";
//    std::string b = "";
//    send(Socket, "GET / HTTP/1.1\r\nHost: www.arkangel-dl.neocities.org\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: www.arkangel-dl.neocities.org\r\nConnection: close\r\n\r\n"), 0);
//    char buffer[10000];
//    int nDataLength;
//    while ((nDataLength = recv(Socket, buffer, 10000, 0)) > 0) {
//        int i = 0;
//        while (buffer[i] >= 32 || buffer[i] == '\n' || buffer[i] == '\r') {
//            b += buffer[i];
//            cout << buffer[i];
//            i += 1;
//        }
//    }
//    closesocket(Socket);
//    WSACleanup();
//    system("pause");
//}