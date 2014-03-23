#ifndef MONEYSTREAM_H
#define MONEYSTREAM_H
#include "Player.h"

class MoneyStream
{
public:
    MoneyStream(int* arr,
        int size,
        Player* players);



private:
    Player players[2];
    int* moneyStream;
    int size;
};

#endif
