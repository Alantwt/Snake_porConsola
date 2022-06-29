#include "../include/game.h"
#include "../include/functions.h"
#include "../include/map.h"
#include "../include/snake.h"
#include "../include/coin.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    hidePointer();
    bool gameOver = false, pressEnter = false, reStart;
    Game game;
    pressEnter = game.init();

    Map map(47,4,50,15);

    Snake ss(50,6);
    Snake* snake = &ss;

    Coin coin;

    if(pressEnter == false)exit(EXIT_SUCCESS);

    if(pressEnter != false){
        map.map_generate();
        while (!gameOver)
        {
            coin.generate();
            gameOver = game.game(snake);
            coin.collision(snake);
        }
        reStart = game.gameOver();
        if(reStart == true) main();
    }
    system("cls");
}
