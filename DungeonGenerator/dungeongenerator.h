#ifndef DUNGEONGENERATOR_H
#define DUNGEONGENERATOR_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <vector>
#include "tile.h"
#include <stdlib.h>
#include <ctime>

enum Direction
{
    Forward = 0,
    Left = 1,
    Right = 2,
    Backwards = 3
};

class DungeonGenerator
{
public:

    DungeonGenerator(int windowWidth, int windowHeight);
    void Start();

private:

    void StartGenerateDungeon() {m_generateDungeon = true; GenerateDungeon();}
    void StopGenerateDungeon(){m_generateDungeon = false;}
    void GenerateDungeon();
    void DrawPath(int startX, int startY, int tries);


private:

    int m_windowWidth;
    int m_windowHeight;
    int m_tileSize;
    bool m_generateDungeon;
    std::vector<int> m_startPoint;
    std::vector<int> m_endPoint;
    std::vector<std::vector<Tile*>> m_field;

    QGraphicsView* m_window;
    QGraphicsScene* m_scene;
};

#endif // DUNGEONGENERATOR_H
