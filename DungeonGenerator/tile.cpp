#include "tile.h"


Tile::Tile()
{
    this->SetWalkable(false);
}

Tile::Tile(int width, int height, int posX, int posY)
{

    this->setRect(posX,posY,width, height);
    this->SetWalkable(false);
    m_isEndPoint = false;
    m_isStartPoint = false;
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
    m_isStartPoint = value;
    m_isEndPoint = false;
    if(value)
    {
        this->SetWalkable(true);
        this->setBrush(QBrush(QColor(50,50,50)));
    }
}

void Tile::SetEndPoint(bool value)
{
    m_isEndPoint = value;
    m_isStartPoint = false;
    if(value)
    {
        this->SetWalkable(true);
        this->setBrush(QBrush(QColor(50,50,50)));
    }
}
