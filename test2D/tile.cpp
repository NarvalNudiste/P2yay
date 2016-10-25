#include "tile.h"

tile::tile()
{
}

tile::tile(int x, int y)
{
    setRect(x,y,getSize(), getSize());
}

int tile::getTileValue() const
{
    return tileValue;
}

void tile::setTileValue(int value)
{
    tileValue = value;
}
