//
// Created by Alp on 12.12.2019.
//

#ifndef SOCKETPROGRAMMING_PLAYER_H
#define SOCKETPROGRAMMING_PLAYER_H

#endif //SOCKETPROGRAMMING_PLAYER_H

using namespace std;

#include <iostream>
#include <stdlib.h>

class Player
{
public:
    Player();
    Player(unsigned int userID, int x=0, int y=0, int z=0, int rotateX=0, int rotateY=0, int rotateZ=0);
    ~Player();
    void moveForward(double power);
    void moveLeft(double power);
    void moveRight(double power);
    void moveBack(double power);
    void setZ(double new_Z);
    char * getCoord();
    char * getRotate();
    unsigned int getUUID();
    char* getUUIDText();
private:
    unsigned int uid;
    int x, y, z;
    int realWorld_x, realWorld_y, realWorld_z;
    int rotateX, rotateY, rotateZ;
    unsigned int health;
    unsigned int stamina;

    void mergeChars(char * To, int toCount, char * From, int fromCount);
protected:
};