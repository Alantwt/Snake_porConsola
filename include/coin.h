#ifndef _COIN
#define _COIN

class Coin{
    int x,y;
    bool collisionCoin = true;
public:
    void generate();
    void collision(class Snake* snake);
};

#include "../lib/coin.cpp"

#endif