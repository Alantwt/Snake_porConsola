#include"../include/snake.h"
#include"../include/functions.h"

#include<conio.h>
#include<windows.h>
#include<stdio.h>

Snake::Snake(int _x, int _y){
    x = _x;
    y = _y;
    keyPress = 'd';
    SnakeLenght = 1;
    snakeBody = (snakebody*)calloc(1,sizeof(snakebody));
    snakeBody[0].x = _x;
    snakeBody[0].y = _y;
}

void Snake::printSnake(){
    movePointer(x,y);
    printf("%c",219);
}

void Snake::deleteSteps(){
    movePointer(0,0);
    int _x = snakeBody[SnakeLenght-1].x;
    int _y = snakeBody[SnakeLenght-1].y;
    movePointer(_x,_y);
    printf(" ");
}

void Snake::eat(){
    SnakeLenght++;
    snakeBody = (snakebody*)realloc(snakeBody,SnakeLenght*(sizeof(snakebody)));
    movePointer(47,3);
    printf("Points: %d",SnakeLenght-1);
}

void Snake::die(){
    gameOver = true;
}

void Snake::move(){
    Sleep(100);
    deleteSteps();
    iterarSnakeBody();
    if(kbhit() != 0)keyPress = getch();

    if((keyPress == K_RIGTH || keyPress == T_RIGTH) && x < (47+59)){
        x++;
        snakeBody[0].x = x;
        snakeBody[0].y = y;
    }
    else if((keyPress == K_LEFT || keyPress == T_LEFT) && x > 48){
        x--;
        snakeBody[0].x = x;
        snakeBody[0].y = y;
    }
    else if((keyPress == K_DOWN || keyPress == T_DOWN) && y < (4+14)){
        y++;
        snakeBody[0].x = x;
        snakeBody[0].y = y;
    }
    else if((keyPress == K_UP || keyPress == T_UP) && y > 5){
        y--;
        snakeBody[0].x = x;
        snakeBody[0].y = y;
    }
    else if(keyPress == 'D'){
        eat();
        keyPress = 'a';
    }

    else{
        if(keyPress == 'a' || keyPress == 's' || keyPress == 'd' || keyPress == 'w'){
            die();
        }
    }
    for(int i = 0; i <= SnakeLenght-1; i++){
        if(snakeBody[0].x == snakeBody[i+1].x && snakeBody[0].y == snakeBody[i+1].y && SnakeLenght > 0)die();
    }

    printSnake();
}

void Snake::iterarSnakeBody(){
    int i = SnakeLenght-1;

    while(SnakeLenght != 1){
        snakeBody[i].x = snakeBody[i-1].x;
        snakeBody[i].y = snakeBody[i-1].y;
        i--;
        if(i == 0)break;
    }
}

int Snake::X(){
    return x;
}

int Snake::Y(){
    return y;
}

bool Snake::gameover(){
    return gameOver;
}