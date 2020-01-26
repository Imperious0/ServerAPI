//
// Created by Alp on 12.12.2019.
//

#include "Player.h"

Player::Player()
{

}

Player::Player(unsigned int userID, int x, int y, int z, int rotateX, int rotateY, int rotateZ)
{
    this->uid = userID;
    this->x = x;
    this->y = y;
    this->z = z;
    this->realWorld_x = x;
    this->realWorld_y = y;
    this->realWorld_z = z;
    this->rotateX = rotateX;
    this->rotateY = rotateY;
    this->rotateZ = rotateZ;
    this->health = 100;
    this->stamina = 100;
}
Player::~Player()
{

}

void Player::moveForward(double power)
{
    this->x += 1*power;
    this->realWorld_x += 1*power;
}

void Player::moveBack(double power)
{
    this->x += -1*power;
    this->realWorld_x += -1*power;
}

void Player::moveRight(double power)
{
    this->y += 1*power;
    this->realWorld_y += 1*power;
}

void Player::moveLeft(double power)
{
    this->y += -1*power;
    this->realWorld_y += -1*power;
}

void Player::setZ(double new_Z)
{
    this->z = new_Z;
    this->realWorld_z = new_Z;
}

char* Player::getCoord()
{
    char * tmp = new char[50];
    memset(tmp, '\0', 50);
    char * tmp2 = new char[15];
    memset(tmp2, '\0', 15);

    //X Coord
    memset(tmp2, '\0', 15);

    itoa(this->x, tmp2, 10);

    strcat(tmp, tmp2);
    strcat(tmp, ",");

    //Y Coord
    memset(tmp2, '\0', 15);

    itoa(this->y, tmp2, 10);

    strcat(tmp, tmp2);
    strcat(tmp, ",");

    //Z Coord
    memset(tmp2, '\0', 15);

    itoa(this->z, tmp2, 10);

    strcat(tmp, tmp2);

    return tmp;
}
char* Player::getRotate()
{
    char * tmp = new char[50];
    memset(tmp, '\0', 50);
    char * tmp2 = new char[15];
    memset(tmp2, '\0', 15);

    //X Coord
    memset(tmp2, '\0', 15);

    itoa(this->rotateX, tmp2, 10);

    strcat(tmp, tmp2);
    strcat(tmp, ",");

    //Y Coord
    memset(tmp2, '\0', 15);

    itoa(this->rotateY, tmp2, 10);

    strcat(tmp, tmp2);
    strcat(tmp, ",");

    //Z Coord
    memset(tmp2, '\0', 15);

    itoa(this->rotateZ, tmp2, 10);

    strcat(tmp, tmp2);

    return tmp;
}
unsigned int Player::getUUID()
{
    return this->uid;
}
char* Player::getUUIDText()
{
    char * tmp = (char *)malloc(sizeof(char)*32);
    memset(tmp, '\0', 32);
    itoa(this->uid, tmp, 10);
    return tmp;
}