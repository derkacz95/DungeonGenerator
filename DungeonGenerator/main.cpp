
#include "dungeongenerator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DungeonGenerator* g = new DungeonGenerator(800,600);
    g->Start();

    return a.exec();
}

