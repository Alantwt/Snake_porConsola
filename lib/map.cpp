#include"../include/map.h"
#include"../include/functions.h"

#include<stdio.h>
#include<stdlib.h>

void Map::map_generate(){
    system("cls");
    int x = xDimension, xtemp = x, xmax = xLen+x;
    int y = yDimension, ytemp = y, ymax = yLen+y;
    int value = 0;
    bool EndAnimation = false;
    char charBordes = 219;
    int i=0;
    while (i != 1)
    {
        
        if(value == 0){
            do{
                movePointer(xtemp,ytemp);
                printf("%c",charBordes);
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
                printf("%c",charBordes);
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
                printf("%c",charBordes);
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
                printf("%c",charBordes);
                ytemp--;
            }while(ytemp >= y+1);
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
        i++;
    }
}

