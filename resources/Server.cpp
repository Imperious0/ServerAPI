//
// Created by alpar on 7.09.2019.
//


#include "Server.h"



Server::Server(const char * IP, unsigned int PORT)
{
    prepareServer(IP, PORT);
}
void Server::prepareServer(const char * IP, unsigned int PORT)
{
    this->IP = IP;
    this->GlobalPort = PORT;

    //Address Data Fill
    AddressData.sin_addr.s_addr = inet_addr(this->IP);
    AddressData.sin_family = this->Ipv4Family;
    AddressData.sin_port = htons(this->GlobalPort);

    cout << this->IP << " " << this->GlobalPort << endl;
    this->ConnectionHandler = socket(this->Ipv4Family, this->TCPType, 0);
    this->Listener = socket(this->Ipv4Family, this->TCPType, 0);
    this->OnlineUsers = 0;

    //ClientStack
    ClientStacks = NULL;
}
void Server::startListen()
{
    bind(this->Listener, (SOCKADDR *)& this->AddressData, sizeof(this->AddressData));
    listen(this->Listener, SOMAXCONN);
}

void Server::connectionHandlerEvent()
{
    cout << "Server Started Succesfully\n";
    cout <<"Waiting For Connections..\n";
    while(TRUE)
    {
        if(this->ConnectionHandler = accept(this->Listener, (SOCKADDR *)& this->AddressData, &(this->AddressSize)))
        {
            cout << "Incoming Connection Now Threading..\n";
            this->OnlineUsers++;
            _beginthreadex(0, 0, this->createNewThread, (void*)this, 0, 0);
        }
    }

}

SOCKET* Server::getConnectionHandler()
{
    return &(this->ConnectionHandler);
}

unsigned int __stdcall Server::createNewThread(void *data)
{
    //Type Casting
    Server* farServer = (Server*)data;
    //Server rightServer = *farServer;
    //SOCKET* client = (SOCKET*)data;
    //SOCKET Player = *client;
    SOCKET* tmpNetwork = farServer->getConnectionHandler();
    SOCKET Network = *tmpNetwork;
    cout << "User Connected!\n";


    //unsigned long flags = 1;
    //ioctlsocket make non blocking socket
    //ioctlsocket(Network, FIONBIO, &flags);

    //Game Properties

    unsigned int uuid = GetCurrentThreadId();
    Game* playerGame = farServer->getGame();

    playerGame->addNewPlayer(uuid, 50, 100, 200, 0, 0, 0);

    Player* playerME = playerGame->findPlayer(uuid);

    //GlobeSocketsSets
    farServer->addClientSocket(uuid, &Network);
    if(farServer->OnlineUsers > 1)
    {
        char* globe = (char*)malloc(sizeof(char)*128);
        memset(globe, '\0', 128);
        strcat(globe, "USER,ADD,");
        strcat(globe, playerME->getUUIDText());
        strcat(globe, ",");
        strcat(globe, playerME->getCoord());
        strcat(globe, ",");
        strcat(globe, playerME->getRotate());
        farServer->sendGlobalMessage(globe, 128, uuid);
    }

    //Thread Properties
    long SUCCESS;
    char * Message;
    int MessageLen = 1000;
    Message = farServer->clearString(Message, MessageLen);
    char * sendMessage;
    sendMessage = farServer->clearString(sendMessage, MessageLen);

    int exitCode = 0;
    int isWaited = 0;

    strcat(sendMessage, "Welcome to the Server Feller ..");
    SUCCESS = send(Network, sendMessage, farServer->getExactLen(sendMessage), 0);

    cout << "Total User Number: " << farServer->OnlineUsers << endl;
    int ordersize = 32;
    int paramsize = 15;
    char* order;
    char* parameters = (char *)malloc(sizeof(char)*paramsize);
    int oldOnline = farServer->OnlineUsers;

    while(TRUE)
    {
        SUCCESS = recv(Network, Message, MessageLen, 0);
        if(SUCCESS > 0)
        {
            cout << "Client " << GetCurrentThreadId() << " Said : " << Message << endl;
            order = farServer->clearString(order, ordersize);
            order = strtok(Message, ",");

            if(strcmp(Message, "Count") == 0)
            {
                cout << "Client Said: " << Message << " And Received : " << farServer->OnlineUsers-1 << endl;
                sendMessage = farServer->clearString(sendMessage, MessageLen);
                strcat(sendMessage, farServer->intToChar(farServer->OnlineUsers-1, 2, 10));
                SUCCESS = send(Network, sendMessage, farServer->getExactLen(sendMessage), 0);
            }
            if(strcmp(Message, "MaxCount") == 0)
            {
                cout << "Client Said: " << Message << " And Received : " << playerGame->getMaxUserCount() << endl;
                sendMessage = farServer->clearString(sendMessage, MessageLen);
                strcat(sendMessage, farServer->intToChar(playerGame->getMaxUserCount(), 3, 10));
                SUCCESS = send(Network, sendMessage, farServer->getExactLen(sendMessage), 0);
            }
            if(strcmp(Message, "Hello Server") == 0)
            {
                cout << "Client Said: " << Message << " And Received : Hello Feller" << endl;
                sendMessage = farServer->clearString(sendMessage, MessageLen);
                strcat(sendMessage, "Hello Feller");
                SUCCESS = send(Network, sendMessage, farServer->getExactLen(sendMessage), 0);
            }
            if(strcmp(Message, "123") == 0)
            {
                cout << "Client " << GetCurrentThreadId() <<" Want To Exit" << endl;
                sendMessage = farServer->clearString(sendMessage, MessageLen);
                strcat(sendMessage, "BYE");
                SUCCESS = send(Network, sendMessage, farServer->getExactLen(sendMessage), 0);
                farServer->deleteClientSocket(uuid);
                closesocket(Network);
                break;
            }
            if(order != NULL)
            {
                if(strcmp(order, "USER") == 0)
                {
                    order = strtok(NULL, ",");
                    if(strcmp(order, "FIRSTINFO") == 0)
                    {
                        sendMessage = farServer->clearString(sendMessage, MessageLen);
                        strcat(sendMessage, "USER,FIRSTINFO,");
                        strcat(sendMessage, playerGame->getFirstTimeUserInfos());
                        cout << sendMessage << endl;
                        SUCCESS = send(Network, sendMessage, farServer->getExactLen(sendMessage), 0);
                    }
                }
                if(strcmp(order, "ME") == 0)
                {
                    order = strtok(NULL, ",");
                    if(strcmp(order, "INFO") == 0)
                    {
                        sendMessage = farServer->clearString(sendMessage, MessageLen);
                        strcat(sendMessage, "ME,INFO,");
                        strcat(sendMessage, playerME->getUUIDText());
                        strcat(sendMessage, ",");
                        strcat(sendMessage, playerME->getCoord());
                        strcat(sendMessage, ",");
                        strcat(sendMessage, playerME->getRotate());
                        cout << sendMessage << endl;
                        SUCCESS = send(Network, sendMessage, farServer->getExactLen(sendMessage), 0);
                    }
                    if(strcmp(order, "W") == 0)
                    {
                        playerME->moveForward(1);
                        sendMessage = farServer->clearString(sendMessage, MessageLen);
                        strcat(sendMessage, "USER,MOVE,");
                        strcat(sendMessage, playerME->getUUIDText());
                        strcat(sendMessage, ",");
                        strcat(sendMessage, playerME->getCoord());
                        farServer->sendGlobalMessage(sendMessage, farServer->getExactLen(sendMessage), uuid);
                        sendMessage = farServer->clearString(sendMessage, MessageLen);
                        strcat(sendMessage, "OK");
                        SUCCESS = send(Network, sendMessage, farServer->getExactLen(sendMessage), 0);
                    }
                    if(strcmp(order, "S") == 0)
                    {
                        playerME->moveBack(1);
                        sendMessage = farServer->clearString(sendMessage, MessageLen);
                        strcat(sendMessage, "USER,MOVE,");
                        strcat(sendMessage, playerME->getUUIDText());
                        strcat(sendMessage, ",");
                        strcat(sendMessage, playerME->getCoord());
                        farServer->sendGlobalMessage(sendMessage, farServer->getExactLen(sendMessage), uuid);
                        sendMessage = farServer->clearString(sendMessage, MessageLen);
                        strcat(sendMessage, "OK");
                        SUCCESS = send(Network, sendMessage, farServer->getExactLen(sendMessage), 0);
                    }
                    if(strcmp(order, "D") == 0)
                    {
                        playerME->moveRight(1);
                        sendMessage = farServer->clearString(sendMessage, MessageLen);
                        strcat(sendMessage, "USER,MOVE,");
                        strcat(sendMessage, playerME->getUUIDText());
                        strcat(sendMessage, ",");
                        strcat(sendMessage, playerME->getCoord());
                        farServer->sendGlobalMessage(sendMessage, farServer->getExactLen(sendMessage), uuid);
                        sendMessage = farServer->clearString(sendMessage, MessageLen);
                        strcat(sendMessage, "OK");
                        SUCCESS = send(Network, sendMessage, farServer->getExactLen(sendMessage), 0);
                    }
                    if(strcmp(order, "A") == 0)
                    {
                        playerME->moveLeft(1);
                        sendMessage = farServer->clearString(sendMessage, MessageLen);
                        strcat(sendMessage, "USER,MOVE,");
                        strcat(sendMessage, playerME->getUUIDText());
                        strcat(sendMessage, ",");
                        strcat(sendMessage, playerME->getCoord());
                        farServer->sendGlobalMessage(sendMessage, farServer->getExactLen(sendMessage), uuid);
                        sendMessage = farServer->clearString(sendMessage, MessageLen);
                        strcat(sendMessage, "OK");
                        SUCCESS = send(Network, sendMessage, farServer->getExactLen(sendMessage), 0);
                    }
                }
            }else
                {
                    order = (char *)malloc(sizeof(char)*ordersize);
                }
            Message = farServer->clearString(Message, MessageLen);
        }else
            {
                if(SUCCESS <= 0)
                {
                    if(isWaited < 10)
                    {
                        cout << "Client " << GetCurrentThreadId()  << " Disconnected!" << " Error:" << WSAGetLastError() << " Waiting 10 Seconds for ComeBack \n";
                        isWaited++;
                        Sleep(1000);
                    }else
                    {
                        cout << "Client " << GetCurrentThreadId() << " Disconnected! \n";
                        farServer->OnlineUsers -= 1;
                        playerGame->deletePlayer(uuid);
                        sendMessage = farServer->clearString(sendMessage, MessageLen);
                        strcat(sendMessage, "DELETE,");
                        strcat(sendMessage, playerME->getUUIDText());
                        farServer->sendGlobalMessage(sendMessage, farServer->getExactLen(sendMessage), uuid);
                        farServer->deleteClientSocket(uuid);
                        closesocket(Network);
                        break;
                    }
                }else
                {
                    isWaited = 0;
                }
            }
    }
    return exitCode;
}

//ClientSocketStack Global Functions

void Server::addClientSocket(unsigned int uuid, SOCKET* tmpSocket)
{
    ClientStack* newest = new ClientStack();
    ClientStack* tmp = ClientStacks;
    newest->uuid = uuid;
    newest->client = tmpSocket;
    //Temporary Before is First
    newest->BeforeClient = ClientStacks;
    newest->NextClient = NULL;
    if(ClientStacks == NULL)
    {
        ClientStacks = newest;
        return;
    }else
        {
            while(tmp->NextClient != NULL)
                tmp = tmp->NextClient;
            newest->BeforeClient = tmp;
            tmp->NextClient = newest;
        }
}

void Server::deleteClientSocket(unsigned int uuid)
{
    ClientStack* tmp = ClientStacks;
    if(tmp == NULL)
        return;
    else
        {
            while(tmp->NextClient != NULL)
            {
                if(tmp->uuid != uuid)
                {
                    tmp = tmp->NextClient;
                }else
                    {
                        break;
                    }
             }
            if(tmp->uuid == uuid)
            {
                if(tmp->NextClient == NULL && tmp->BeforeClient == NULL)
                    ClientStacks = NULL;
                else if(tmp->BeforeClient == NULL)
                {
                    ClientStacks = ClientStacks->NextClient;
                    ClientStacks->BeforeClient=NULL;
                }
                else if(tmp->NextClient == NULL)
                {
                    tmp->BeforeClient->NextClient = NULL;
                }
                else
                    {
                        tmp->BeforeClient->NextClient = tmp->NextClient;
                        tmp->NextClient->BeforeClient = tmp->BeforeClient;
                    }
            }
        }
}
//Under Implementation
void Server::findClientSocket(unsigned int uuid)
{
    ClientStack* tmp = ClientStacks;
}
//Under Implementation
void Server::sendGlobalMessage(char *Message, int Size, unsigned int uuid)
{
    ClientStack* tmp = ClientStacks;
    if(tmp == NULL)
    {
        return;
    }
    while(tmp != NULL)
    {
        if(uuid != 0 && tmp->uuid != uuid)
        {
            tmp->sendData(Message, Size);
        }else
            {

            }
        tmp = tmp->NextClient;
    }
}

//Casual Functions
char* Server::intToChar(int number, int charLength, int Base)
{
    char* tmp = (char*)malloc(sizeof(char)*charLength);
    memset(tmp, '\0', charLength);
    itoa(number, tmp, Base);
    return tmp;
}
char* Server::clearString(char *string, int stringLen)
{
    string = (char *)malloc(sizeof(char) * stringLen);
    memset(string, '\0', stringLen);
    return string;
}
int Server::getExactLen(char *Message)
{
    int i = 0;
    while(Message[i] != '\0')
    {
        i++;
    }
    i++;
    return i;
}

//Game Functions
void Server::createGame(unsigned int userCount)
{
    GameTo = new Game(userCount);
}

Game* Server::getGame()
{
    return this->GameTo;
}