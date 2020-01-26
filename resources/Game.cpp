//
// Created by Alp on 12.12.2019.
//

#include "Game.h"

Game::Game()
{
    this->userCount = 3;
    this->activePlayers = 0;
    this->basePlayer = NULL;
}
Game::Game(unsigned int userCount)
{
    this->userCount = userCount;
    this->activePlayers = 0;
    this->basePlayer = NULL;
}
Game::~Game()
{

}
void Game::addNewPlayer(unsigned int uuid, int x, int y, int z, int rotateX, int rotateY, int rotateZ)
{
    PlayerPrototype* newest = new PlayerPrototype();
    PlayerPrototype* tmp = basePlayer;
    newest->user = new Player(uuid, x, y, z, rotateX, rotateY, rotateZ);
    //Temporarely Assign to basePlayer
    newest->beforePlayer = basePlayer;
    newest->nextPlayer = NULL;

    if(basePlayer == NULL)
    {
        basePlayer = newest;
        return;
    }else
        {
            while(tmp->nextPlayer != NULL)
                tmp = tmp->nextPlayer;
            newest->beforePlayer = tmp;
            tmp->nextPlayer = newest;
        }
}
void Game::deletePlayer(unsigned int uuid)
{
    PlayerPrototype* tmp = basePlayer;
    if(tmp == NULL)
    {
        return;
    }else
        {
            while (tmp->nextPlayer != NULL)
            {
                if(tmp->user->getUUID() != uuid)
                {
                    tmp = tmp->nextPlayer;
                }else
                    {
                        break;
                    }
            }
            if(tmp->user->getUUID() == uuid)
            {
                if(tmp->nextPlayer == NULL && tmp->beforePlayer == NULL)
                    basePlayer = NULL;
                else if(tmp->beforePlayer == NULL)
                {
                    basePlayer = basePlayer->nextPlayer;
                    basePlayer->beforePlayer = NULL;
                }
                else if(tmp->nextPlayer == NULL)
                {
                    tmp->beforePlayer->nextPlayer = NULL;
                }
                else
                    {
                        tmp->beforePlayer->nextPlayer = tmp->nextPlayer;
                        tmp->nextPlayer->beforePlayer = tmp->beforePlayer;
                    }
            }
        }
}
char* Game::getFirstTimeUserInfos()
{
    int tmp_size = 1000;
    char * tmp = (char*)malloc(sizeof(char)*tmp_size);
    memset(tmp, '\0', tmp_size);

    PlayerPrototype* tmpPlayer = basePlayer;

    if(tmpPlayer == NULL)
    {
        strcat(tmp, "0");
    }else
        {
            strcat(tmp, (tmpPlayer->user->getUUIDText()));
            strcat(tmp, ",");
            strcat(tmp, (tmpPlayer->user->getCoord()));
            strcat(tmp, ",");
            strcat(tmp, (tmpPlayer->user->getRotate()));
            while(tmpPlayer->nextPlayer != NULL)
            {
                strcat(tmp, ",");
                tmpPlayer = tmpPlayer->nextPlayer;
                strcat(tmp, (tmpPlayer->user->getUUIDText()));
                strcat(tmp, ",");
                strcat(tmp, (tmpPlayer->user->getCoord()));
                strcat(tmp, ",");
                strcat(tmp, (tmpPlayer->user->getRotate()));
            }
        }
    return tmp;
}
char* Game::getPlayerCoord(unsigned int uuid)
{
    return this->findPlayer(uuid)->getCoord();
}
char* Game::getPlayerRotate(unsigned int uuid)
{
    return this->findPlayer(uuid)->getRotate();
}
int Game::getMaxUserCount()
{
    return this->userCount;
}
Player* Game::findPlayer(unsigned int uuid)
{
    Player * tmp = NULL;
    PlayerPrototype* tmpPlayer = basePlayer;
    if(tmpPlayer == NULL)
    {

    }else
        {
            while(tmpPlayer->nextPlayer != NULL)
            {
                if(tmpPlayer->user->getUUID() != uuid)
                {
                    tmpPlayer = tmpPlayer->nextPlayer;
                }else
                    {
                        break;
                    }
            }
            if(tmpPlayer->user->getUUID() == uuid)
            {
                tmp = tmpPlayer->user;
            }
        }
    return tmp;
}