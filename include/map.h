#ifndef _MAP
#define _MAP


class Map{
    int xDimension,yDimension,xLen,yLen;
public:
    Map(int x,int y, int xmax, int ymax):xDimension(x),yDimension(y),xLen(xmax),yLen(ymax){}
    void map_generate();
};

#include "../lib/map.cpp"

#endif