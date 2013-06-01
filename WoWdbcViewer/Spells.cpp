#include <QDebug>
#include <QStatusBar>

#include "mainwindow.h"
#include "Spells.h"
#include "dbc/DBCFileLoader.h"
#include "dbc/DBCfmt.h"
#include "dbc/DBCStructures.h"

Spells::Spells()
{
    _strings = 0;
}

Spells::~Spells()
{
    if (_strings != 0)
        delete [] _strings;
}

bool Spells::importSpells(QString filename)
{
    DBCFileLoader dbc;
    uint32 nCount;
    SpellEntry ** indexTable;
    SpellEntry * m_dataTable;

    MainWindow::getInstance()->statusBar()->showMessage("Loading dbc file.");
    if (!dbc.Load(filename.toLatin1().data(), SpellEntryfmt))
        return false;
    m_dataTable = (SpellEntry *) dbc.AutoProduceData(SpellEntryfmt, nCount, (char ** &) indexTable);
    if (_strings != 0)
        delete [] _strings;
    _strings = dbc.AutoProduceStrings(SpellEntryfmt, (char *) m_dataTable);
    loadSpells(indexTable, nCount);
    delete [] m_dataTable;
    delete [] indexTable;
    return true;
}

void                    Spells::loadSpells(SpellEntry ** indexTable, unsigned int nCount)
{
    MainWindow::getInstance()->statusBar()->showMessage("Loading spells.");
    while (!_spells.isEmpty())
        _spells.removeFirst();
    unsigned int percent = 0;
    for (unsigned int i = 0 ; i < nCount ; i++)
    {
        if (indexTable[i] != 0)
        {
            _spells.append(Spell(indexTable[i]));
        }
        if (i * 100 / nCount > percent)
        {
            percent = i * 100 / nCount;
            MainWindow::getInstance()->statusBar()->showMessage(QString::number(percent) + QString("%"));
        }
    }
}

const Spell *         Spells::getSpell(int id) const
{
    QList<Spell>::const_iterator i;

    for (i = _spells.constBegin() ; i != _spells.constEnd() ; i++)
    {
        if (i->getId() == id)
            return &(*i);
    }
    return (Spell *) 0;
}

const Spell *         Spells::getSpell(QString name) const
{
    QList<Spell>::const_iterator i;

    for (i = _spells.constBegin() ; i != _spells.constEnd() ; i++)
    {
        if (i->getName() == name)
            return &(*i);
    }
    return (Spell *) 0;
}

const QList<Spell> * Spells::getSpells() const
{
    return &_spells;
}
