#include "../include/game.h"
#include "../include/functions.h"
#include "../include/snake.h"

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

bool Game::init(){
    system("cls");
    int position[2],area[2];
    position[0] = 47, position[1] = 4,area[0] = 50, area[1] = 15;
    while (true){    
        init_Welcome();
        movePointer(75,16);
        printf("--Press Enter for Play--");
        if(kbhit() != 0){
            animationSpiral(219,0,position,area);
            if(getch() == ENTER) return true;
            else return false;
        }
        Sleep(50);
    }    
}

void Game::init_Welcome(){
    int x=65,y=10;
    /*
        *****   *****   *****   *****   *****       *****   ***   *  ********   *****   *****    
        **   *  **   *  **      **      **          **      ***   *     **      **      **   *   
        *****   *****   ****    *****   *****       ****    ** *  *     **      ****    *****    
        **      ** **   **         **      **       **      **  * *     **      **      ** **    
        **      **  **  *****   *****   *****       *****   **   **     **      *****   **  **

        *****   ***   *   ******   **   *   *****
        **      ***   *   **   *   **  *    **
        *****   ** *  *   **___*   ****     ****
           **   **  * *   **   *   **  *    **
        *****   **   **   **   *   **   *   *****
    */
   movePointer(x,y);
   printf("                                              ");
   movePointer(x,y+1);  
   printf("                                              ");
   movePointer(x,y+2);
   printf("                                              ");
   movePointer(x,y+3);
   printf("                                               ");
   movePointer(x,y+4);
   printf("                                               ");

   movePointer(x,y);
   printf("*****   ***   *   ******   **   *   *****");
   Sleep(300);
   movePointer(x,y+1);
   printf("**      ***   *   **   *   **  *    **");
   Sleep(300);
   movePointer(x,y+2);
   printf("*****   ** *  *   **___*   ****     ****");
   Sleep(300);
   movePointer(x,y+3);
   printf("   **   **  * *   **   *   **  *    **");
   Sleep(300);
   movePointer(x,y+4);
   printf("*****   **   **   **   *   **   *   *****");
   Sleep(1000);
}

bool Game::game(class Snake* snake){
    snake->move();
    Sleep(70);
    return snake->gameover();
}

bool Game::gameOver(){
    int x=50,y=10;
    system("cls");
    Sleep(100);
    movePointer(x,y);
    printf("********    ********    ***      ***    *******          ******     *         *     *******     *******");
    Sleep(100);
    movePointer(x,y+1);
    printf("**          **    **    ***      ***    **              *      *     *       *      **          **     *");
    Sleep(100);
    movePointer(x,y+2);
    printf("**  ****    **____**    ** *    * **    ******          *      *      *     *       ******      *******");
    Sleep(100);
    movePointer(x,y+3);
    printf("**     *    **    **    **  ****  **    **              *      *       *   *        **          **  ** ");
    Sleep(100);
    movePointer(x,y+4);
    printf("********    **    **    **   **   **    *******          ******         ***         *******     **    **");
    Sleep(100);
    movePointer(x,y+5);
    printf("                                                Play again\n");
    movePointer(x,y+6);
    printf("                                                Exit game\n");

    int option = 14;
    char keypressed = 'w';
    while(true){
        keypressed = getch();
        movePointer(x+60,option);
        printf(" ");
        if(keypressed == T_DOWN){
            option = 16;
        } 
        else if(keypressed == T_UP){
            option = 15;
        }
        else if(keypressed == ENTER){
            if(option == 16){
                return false;
            }
            else{
                return true;
            }
        }
        movePointer(x+60,option);
        printf("%c",17);

    }
}

void Game::gameOver_endGame(){

}

void Game::animationSpiral(char charAnimation, int delay, int position[2], int area[2]){
    system("cls");
    int x = position[0], xtemp = x, xmax = area[0]+x;
    int y = position[1], ytemp = y, ymax = area[1]+y;
    int value = 0;
    bool EndAnimation = false;
    int i=0;
    while (true)
    {
        i++;
        if(value == 0){
            do{
                movePointer(xtemp,ytemp);
                printf("%c",charAnimation);
                Sleep(delay);
                if((y>ymax) ){
                    EndAnimation = true;
                }
                xtemp++;
            }while(xtemp <= xmax-1);
            value = 1;
        }
        if(value == 1){
            do{
                movePointer(xtemp,ytemp);
                printf("%c",charAnimation);
                Sleep(delay);
                if((y>ymax) ){
                    EndAnimation = true;
                }
                ytemp++;
            }while(ytemp <= ymax-1);
            value = 2;
        }
        if(value == 2){
            do{
                movePointer(xtemp,ytemp);
                printf("%c",charAnimation);
                Sleep(delay);
                if((y>ymax) ){
                    EndAnimation = true;
                }
                xtemp--;
            }while(xtemp >= x+1);
            value = 3;
        }
        if(value == 3){
            ytemp = ymax;
            do{
                movePointer(xtemp,ytemp);
                printf("%c",charAnimation);
                Sleep(delay);
                ytemp--;
            }while(ytemp >= y+2);
            value = 0;

            if(y<=ymax+1){
                x++;
                xmax--;
                y++;
                ymax--;
            } 
            if((y>ymax) ){
                    EndAnimation = true;
                }
        }
        
        if(EndAnimation == true ){
            break;
        }
    }
    Sleep(1);
}




