//
// Created by alpar on 7.09.2019.
//

#ifndef SOCKETPROGRAMMING_CLIENT_H
#define SOCKETPROGRAMMING_CLIENT_H




#define _WINSOCK_DEPRECATED_NO_WARNINGS

//STD Declerations
#include <sdkddkver.h>
#include <conio.h>
#include <stdio.h>

//Socket Headers
#include <winsock2.h>
#include <windows.h>
#include <iostream>

using namespace std;

class Client
{
private:
    //Socket Version
    unsigned int SCK_VERSION[2] = {0x0101, 0x0202};
    //Win Socket Data
    WSAData WinSockData;
    WORD DLLVersion = MAKEWORD(2,2);
    long SUCCESSFULData = WSAStartup(DLLVersion, &WinSockData);

    //Socket Types
    int TCPType = SOCK_STREAM;
    int UDPType = SOCK_DGRAM;

    //Internet Family
    int Ipv4Family = AF_INET;
    int Ipv6Family = AF_INET6;

    //IP Address
    const char * IP = "192.168.1.113";
    //Port
    unsigned int GlobalPort = 80;
    //Address INFO STRUCTURE
    SOCKADDR_IN AddressData;
    //Address Size Needed
    int AddressSize = sizeof(AddressData);

    SOCKET user;


    //MessageHandlers
    char * Message;
    int MessageSize = 1000;


public:
    Client(const char * CONN_IP, unsigned int CONN_PORT);
    void prepareClient(const char * CONN_IP, unsigned int CONN_PORT);
    void createConnection();
    void sendData(const char *, int);
    long receiveData();
    void closeConnection();
    char * receiveMessage();
};


#endif //SOCKETPROGRAMMING_CLIENT_H