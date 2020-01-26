//
// Created by alpar on 7.09.2019.
//

#include "resources/Server.h"
#include "resources/Client.h"

bool isServer = true;

int main() {

    if(isServer)
    {
        Server *trying = new Server("192.168.2.231", 8080);
        trying->startListen();
        trying->createGame(100);
        trying->connectionHandlerEvent();
    }else
        {
            Client *trying = new Client("192.168.2.231", 8080);
            trying->createConnection();
            long ptr = trying->receiveData();
            trying->sendData("USER,FIRSTINFO", 14);
            trying->receiveData();
            cout << trying->receiveMessage() << endl;

            trying->sendData("ME,INFO", 7);
            trying->receiveData();
            cout << trying->receiveMessage() << endl;
            /*
            trying->sendData("ME", 2);
            if (trying->receiveData() > 0)
            {

                cout << trying->receiveMessage();
            }
            else
            {
            }

            int i = 0;

            while(i < 10)
            {
                cout << "Sending Message to Server : Hello Server \n";
                trying->sendData("Hello Server", 13);
                ptr = trying->receiveData();
                if(ptr < 0)
                {
                    cout << "There is no Data/Packet Received";
                    cout << "Server :" << trying->receiveMessage() << endl;
                }else
                    {
                        cout << "Server :" << trying->receiveMessage() << endl;
                    }
                i++;
                trying->sendData("Count", 6);
                ptr = trying->receiveData();
                cout << "Server :" << trying->receiveMessage() << endl;
                Sleep(1000);
            }
            cout << "Sending Message Successful Now Closing Connection \n";
            trying->sendData("123", 5);
            trying->closeConnection();
             */
        }

    getch();
    return 0;
}