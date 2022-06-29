#ifndef _SNAKE
#define _SNAKE

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

struct SnakeBody{
    int x;
    int y;
};

typedef SnakeBody snakebody; 


class Snake{
    int x,y,SnakeLenght;
    char keyPress;
    snakebody* snakeBody;
    bool gameOver = false;
public:
    Snake(int _x, int _y);
    void move();
    void eat();
    void die();
    void autoMove();
    void printSnake();
    void deleteSteps();
    void iterarSnakeBody();
    int X();
    int Y();
    bool gameover();
};

#include"../lib/snake.cpp"

#endif