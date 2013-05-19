#include "mainwindow.h"
#include <QApplication>

#include "Spells.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Spells spells("/opt/mangos-server/data/dbc/Spell.dbc");

    w.show();
    
    return a.exec();
}
