#include"../include/coin.h"
#include"../include/functions.h"
#include"../include/snake.h"

#include<conio.h>
#include<windows.h>
#include<stdio.h>


void Coin::generate(){
    if(collisionCoin == true){
        x = 48 + rand()%29;
        y = 5 + rand()%14;
        movePointer(x,y);
        printf("%c",184);
        collisionCoin = false;
    }
}

void Coin::collision(class Snake* snake){
    movePointer(0,0);
    if(x == snake->X() && y == snake->Y()){
        snake->eat();
        collisionCoin = true;
    }
}