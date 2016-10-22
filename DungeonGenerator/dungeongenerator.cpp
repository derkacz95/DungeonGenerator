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
    StartGenerateDungeon();
}

void DungeonGenerator::GenerateDungeon()
{
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
    int currX = rand() % countX;
    int currY = countY - 1;
    m_field[currY][currX]->SetStartPoint(true);

    // Set the end point
    srand(time(0));
    m_field[0][rand() % countY]->SetEndPoint(true);

    DrawPath(currX, currY, countY);

    /*bool foundEnd = false;
    int nextTile;
    int i = 0;
    srand(time(0));

    /*while(!foundEnd)
    {

        nextTile = rand() % 3;

        if(nextTile == Direction::Forward)
        {
            if(currY - 1 >= 1 && !m_field[currY - 1][currX - 1]->IsWalkable()
               && !m_field[currY - 1][currX + 1]->IsWalkable() && !m_field[currY-1][currX]->IsWalkable())
            {
                if(m_field[currY - 1][currX]->IsEndPoint())
                {
                    foundEnd = true;
                    break;
                }
                else
                {
                    m_field[--currY][currX]->SetWalkable(true);
                }
            }
            else
            {
                currY++;
                continue;
            }

        }
        else if(nextTile == Direction::Left)
        {
            if(currX - 1 >= 1 && (currY < countY - 1 && currY > 0) &&
               !m_field[currY + 1][currX - 1]->IsWalkable() && !m_field[currY - 1][currX - 1]->IsWalkable() && !m_field[currY][currX-1]->IsWalkable())
            {
                if(m_field[currY][currX - 1]->IsEndPoint())
                {
                    foundEnd = true;
                    break;
                }
                else
                {
                    m_field[currY][--currX]->SetWalkable(true);
                }
            }
            else
            {
                currX++;
                continue;
            }
        }
        else if(nextTile == Direction::Right)
        {
            if(currX + 1 <= countY - 2 && (currY < countY - 1 && currY > 0) &&
               !m_field[currY + 1][currX + 1]->IsWalkable() && !m_field[currY - 1][currX + 1]->IsWalkable() && !m_field[currY][currX+1]->IsWalkable())
            {
                if(m_field[currY][currX + 1]->IsEndPoint())
                {
                    foundEnd = true;
                    break;
                }
                else
                {
                    m_field[currY][++currX]->SetWalkable(true);
                }
            }
            else
            {
                currX--;
                continue;
            }
        }

        i++;
        if(i >= 60)
            foundEnd = true;

    }*/



}

void DungeonGenerator::DrawPath(int startX, int startY, int tries)
{
    srand(time(0));
    int x = startX;
    int y = startY;
    int countX = m_field[0].size();
    int countY = m_field.size();

    while(m_generateDungeon && tries > 0)
    {
        --tries;
        qDebug() << "tries: " << tries;

        if(m_field[y - 1 < 0 ? y : y - 1][x]->IsEndPoint() ||
           m_field[y + 1 >= countY ? y : y + 1][x]->IsEndPoint() ||
           m_field[y][x - 1 < 0 ? x : x - 1]->IsEndPoint() ||
           m_field[y][x + 1 >= countX ? x : x + 1 ]->IsEndPoint())
        {
            qDebug() << "Stop generating";
            StopGenerateDungeon();
            continue;
        }

        int nextAction = rand() % 4;
        qDebug() << "nextAction: " << nextAction;

        if(nextAction == Direction::Forward)
        {
            if(y + 1 >= 1 &&
               !m_field[y - 1][x]->IsWalkable() && !m_field[y - 1][x + 1]->IsWalkable() &&
               !m_field[y - 1][x - 1]->IsWalkable())
            {
                m_field[--y][x]->SetWalkable(true);

            }

        }
        else if(nextAction == Direction::Left)
        {
            if(x - 1 >= 1 && y + 1 <= m_field.size() - 2 && y - 1 >= 1 &&
               !m_field[y][x - 1]->IsWalkable() && !m_field[y - 1][x - 1]->IsWalkable() &&
               !m_field[y + 1][x - 1]->IsWalkable())
            {
                 m_field[y][x - 1]->SetWalkable(true);
                 DrawPath(x + 1, y, 10);
            }

        }
        else if(nextAction == Direction::Right)
        {
            if(x + 1 <= m_field[0].size() && y + 1 <= m_field.size() - 2 && y - 1 >= 1 &&
               !m_field[y][x + 1]->IsWalkable() && !m_field[y - 1][x + 1]->IsWalkable() &&
               !m_field[y + 1][x + 1]->IsWalkable())
            {
                 m_field[y][x + 1]->SetWalkable(true);
                 DrawPath(x + 1, y, 10);
            }

        }
        else if(nextAction == Direction::Backwards)
        {

        }


    }
}
