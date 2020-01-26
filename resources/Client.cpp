//
// Created by alpar on 7.09.2019.
//

#include "Client.h"

Client::Client(const char * CONN_IP, unsigned int CONN_PORT)
{
    this->prepareClient(CONN_IP, CONN_PORT);
}
void Client::prepareClient(const char * CONN_IP, unsigned int CONN_PORT)
{
    this->IP = CONN_IP;
    this->GlobalPort = CONN_PORT;
    //Address Data Fill
    AddressData.sin_addr.s_addr = inet_addr(this->IP);
    AddressData.sin_family = this->Ipv4Family;
    AddressData.sin_port = htons(this->GlobalPort);
    //cout << this->IP << " " << this->GlobalPort << endl;
    this->user = socket(this->Ipv4Family, TCPType, 0);

    //MessageHandlers
    this->Message = (char*)malloc(sizeof(char) * this->MessageSize);
    memset(this->Message, '\0', this->MessageSize);

}
void Client::createConnection()
{
    connect(this->user, (SOCKADDR *)& this->AddressData, this->AddressSize);
}
void Client::sendData(const char * Message, int MessageSize)
{
    this->SUCCESSFULData = send(this->user, Message, MessageSize, 0);
}
long Client::receiveData()
{
    char * tmp_Message = (char*)malloc(sizeof(char) * this->MessageSize);
    memset(tmp_Message, '\0', this->MessageSize);
    this->SUCCESSFULData = recv(this->user, tmp_Message, this->MessageSize, 0);
    if(this->SUCCESSFULData > 0)
    {
        this->Message = (char*)malloc(sizeof(char) * this->MessageSize);
        memset(this->Message, '\0', this->MessageSize);
        strcat(this->Message, tmp_Message);
    }
    return this->SUCCESSFULData;
}
char * Client::receiveMessage()
{
    return this->Message;
}
void Client::closeConnection()
{
    closesocket(this->user);
}