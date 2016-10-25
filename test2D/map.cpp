#include "map.h"

map::map(int w, int h){
    setHeight(h);
    setWidth(w);
    ary = new tile*[getHeight()];
    for(int i = 0; i < w; ++i)
        ary[i] = new tile[getWidth()];
}
void map::generate(){

}

int map::getHeight() const
{
    return height;
}

void map::setHeight(int value)
{
    height = value;
}

int map::getWidth() const
{
    return width;
}

void map::setWidth(int value)
{
    width = value;
}
