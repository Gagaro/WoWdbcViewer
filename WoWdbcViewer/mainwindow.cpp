#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionLoad_dbc, SIGNAL(triggered()), this, SLOT(loadDbc()));
    connect(ui->buttonId, SIGNAL(clicked()), this, SLOT(lookupSpell()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadDbc()
{
    QString directory = QFileDialog::getExistingDirectory(this, "dbc directory");

    if (_spells.importSpells(directory + "/Spell.dbc"))
    {
        statusBar()->showMessage("dbc loaded.", 10000);
        ui->inputId->setEnabled(true);
        ui->buttonId->setEnabled(true);
    }
    else
    {
        statusBar()->showMessage("Error while loading dbc.", 10000);
        ui->inputId->setEnabled(false);
        ui->buttonId->setEnabled(false);
    }
}

void MainWindow::lookupSpell()
{
    int id = ui->inputId->text().toInt();

    if (id <= 0)
    {
        statusBar()->showMessage("Invalid id.", 10000);
        return ;
    }

    const Spell * spell = (Spell *) 0;
    if ((spell = _spells.getSpell(id)) == 0)
    {
        statusBar()->showMessage("Unkown spell.", 10000);
        return ;
    }
    setSpellInformation(*spell);
}

void MainWindow::setSpellInformation(const Spell &spell)
{
    ui->spellOverviewId->setText("Id: " + QString::number(spell.getId()));
}
