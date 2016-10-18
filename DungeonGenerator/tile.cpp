#include "tile.h"


Tile::Tile()
{
    this->SetWalkable(false);
}

Tile::Tile(int width, int height, int posX, int posY)
{

    this->setRect(posX,posY,width, height);
    this->SetWalkable(false);
}

void Tile::SetWalkable(bool value)
{

    if(value)
    {
        this->setBrush(QBrush(QColor(255,0,0)));
    }
    else
    {
        this->setBrush(QBrush(QColor(0,0,255)));
    }
}

void Tile::SetStartPoint(bool value)
{
    m_isStartPoint = true;
    m_isEndPoint = false;
    this->SetWalkable(true);
}

void Tile::SetEndPoint(bool value)
{
    m_isEndPoint = true;
    m_isStartPoint = false;
    this->SetWalkable(true);
}
