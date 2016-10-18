#include "dungeongenerator.h"

DungeonGenerator::DungeonGenerator(int windowWidth, int windowHeight)
{
    m_windowWidth = windowWidth;
    m_windowHeight = windowHeight;
    m_tileSize = 20;

    // Create a scene and a window
    m_scene = new QGraphicsScene();
    m_scene->setSceneRect(0,0,m_windowWidth, m_windowHeight);

    m_window = new QGraphicsView();
    m_window->setFixedSize(m_windowWidth,m_windowHeight);
    m_window->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_window->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_window->setScene(m_scene);

    m_window->show();
}

void DungeonGenerator::Start()
{
    GenerateDungeon();
}

void DungeonGenerator::GenerateDungeon()
{
    // Create non walkable tiles
    /*for(int i = 0; i < 20; ++i)
    {
        Tile* tile = new Tile(m_tileSize,m_tileSize, i * m_tileSize, m_tileSize);
        tile->setBrush(QBrush(QColor(0,0,255)));
        m_scene->addItem(tile);
    }

    for(int i = 0; i < 30; ++i)
    {
        WalkableTile* tile = new WalkableTile(m_tileSize, m_tileSize, i * m_tileSize, i * m_tileSize);
        tile->setBrush(QBrush(QColor(255,0,0)));
        m_scene->addItem(tile);
    }*/

    // Generate the grid with non walkable tiles
    int countX = m_windowWidth / m_tileSize;
    int countY = m_windowHeight / m_tileSize;

    m_field.resize(countY);

    for(int y = 0; y < countY; ++y)
    {
        m_field[y].resize(countX);
        for(int x = 0; x < countX; ++x)
        {
            Tile* tile = new Tile(m_tileSize, m_tileSize, x * m_tileSize, y * m_tileSize);
            m_field[y][x] = tile;
            m_scene->addItem(tile);
        }
    }

    // Set the start point
    srand(time(0));
    m_field[countY - 1][rand() % countX]->SetStartPoint(true);

    // Set the end point
    srand(time(0));
    m_field[0][rand() % countY]->SetEndPoint(true);

}
