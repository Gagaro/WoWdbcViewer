#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Spells.h"
#include "Spell.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void setSpellInformation(const Spell &spell);
    void setSpellOverview(const Spell &spell);
    void setSpellAttributes(const Spell &spell);
    void setSpellEffects(const Spell &spell);

    Ui::MainWindow *ui;
    Spells _spells;

private slots:
    void loadDbc();
    void lookupSpell();
};

#endif // MAINWINDOW_H
