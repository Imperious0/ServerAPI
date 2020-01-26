//
// Created by Alp on 12.12.2019.
//

#ifndef SOCKETPROGRAMMING_GAME_H
#define SOCKETPROGRAMMING_GAME_H

#endif //SOCKETPROGRAMMING_GAME_H

#include "Player.h"

using namespace std;

class Game
{
public:
    Game();
    Game(unsigned int);
    ~Game();
    void addNewPlayer(unsigned int uuid, int x = 0, int y = 0, int z = 0, int rotateX = 0, int rotateY = 0, int rotateZ = 0);
    void deletePlayer(unsigned int uuid);
    char * getPlayerCoord(unsigned int uuid);
    char * getPlayerRotate(unsigned int uuid);
    char * getFirstTimeUserInfos();
    Player * findPlayer(unsigned int uuid);
    int getMaxUserCount();
private:
    unsigned int userCount;
    unsigned int activePlayers;
    struct PlayerPrototype
    {
        Player * user;
        PlayerPrototype * nextPlayer;
        PlayerPrototype * beforePlayer;
    };

    PlayerPrototype* basePlayer;

protected:
};