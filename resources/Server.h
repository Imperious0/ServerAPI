//
// Created by alpar on 7.09.2019.
//

#ifndef SOCKETPROGRAMMING_SERVER_H
#define SOCKETPROGRAMMING_SERVER_H


#define _WINSOCK_DEPRECATED_NO_WARNINGS

//STD Declerations
#include <sdkddkver.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <string>

//Socket Headers
#include <winsock2.h>
#include <windows.h>
#include <iostream>

//Thread Headers
#include <thread>

//Game Headers
#include "Game.h"

using namespace std;

class Server
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

    //Socket Properties
    SOCKET Listener; SOCKET ConnectionHandler;


    //Casual Functions
    char* intToChar(int number, int charLength, int Base);
    int getExactLen(char* Message);
    char * clearString(char * string, int stringLen);

    //Game Properties
    Game* GameTo;

    SOCKET* getConnectionHandler();
    Game* getGame();

    //ClientSocketStacks Properties
    struct ClientStack
    {
        unsigned int uuid;
        SOCKET* client;
        long returnBytes;
        void sendData(char* Message, int Size)
        {
            returnBytes = send((*client), Message, Size,0);
        };
        ClientStack* NextClient;
        ClientStack* BeforeClient;
    };

    ClientStack* ClientStacks;

public:

    Server(const char * IP, unsigned int PORT);
    void prepareServer(const char * IP, unsigned int PORT);
    void startListen();

    void connectionHandlerEvent();
    unsigned static int __stdcall createNewThread(void *);


    void createGame(unsigned int userCount);

    //ClientSocketGlobal Functions
    void findClientSocket(unsigned int uuid);
    void addClientSocket(unsigned int uuid, SOCKET* tmpSocket);
    void deleteClientSocket(unsigned int uuid);
    void sendGlobalMessage(char* Message, int Size, unsigned int uuid = 0);

    //online Users
    int OnlineUsers;
};
#endif //SOCKETPROGRAMMING_SERVER_H