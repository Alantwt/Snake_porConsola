#ifndef _GAME
#define _GAME

//Teclas de movimiento
#define K_UP 72
#define T_UP 'w'
#define K_DOWN 80
#define T_DOWN 's'
#define K_RIGTH 77
#define T_RIGTH 'd'
#define K_LEFT 75
#define T_LEFT 'a'
#define ENTER 13
#define ESC 27

class Game{

public:
    bool init();
    bool game(class Snake* snake);
    bool gameOver();
    void init_Welcome();
    void gameOver_endGame();
    void animationSpiral(char charAnimation,int delay,int position[2], int area[2]);
};

#include "../lib/game.cpp"

#endif