#ifndef DUNGEONGENERATOR_H
#define DUNGEONGENERATOR_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <vector>
#include "tile.h"
#include <stdlib.h>
#include <ctime>

class DungeonGenerator
{
public:

    DungeonGenerator(int windowWidth, int windowHeight);
    void Start();

private:

    void GenerateDungeon();

private:

    int m_windowWidth;
    int m_windowHeight;
    int m_tileSize;
    std::vector<int> m_startPoint;
    std::vector<int> m_endPoint;
    std::vector<std::vector<Tile*>> m_field;

    QGraphicsView* m_window;
    QGraphicsScene* m_scene;
};

#endif // DUNGEONGENERATOR_H
