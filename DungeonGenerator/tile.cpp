#include "tile.h"


Tile::Tile()
{

}

Tile::Tile(int width, int height, int posX, int posY)
{
    this->setRect(posX,posY,width, height);
}
