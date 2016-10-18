#ifndef TILE_H
#define TILE_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QDebug>

class Tile : public QGraphicsRectItem
{
public:

    Tile();
    Tile(int width, int height, int posX, int posY);

    void SetWalkable(bool value);
    void SetStartPoint(bool value);
    void SetEndPoint(bool value);
    bool IsEndPoint() {return m_isEndPoint; }
    bool IsStartPoint() {return m_isStartPoint;}
    bool IsWalkable() {return m_isWalkable; }


private:

    bool m_isWalkable;
    bool m_isStartPoint;
    bool m_isEndPoint;

};

#endif // TILE_H
