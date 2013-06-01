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

bool Spells::importSpells(QString directory)
{
    DBCFileLoader dbc;
    uint32 nCount;
    uint32 tmp;
    SpellEntry ** spellIndexTable;
    SpellEntry * spellDataTable;
    SpellRangeEntry ** rangeIndexTable;
    SpellRangeEntry * rangeDataTable;

    MainWindow::getInstance()->statusBar()->showMessage("Loading dbc files.");
    if (!dbc.Load(QString(directory + "/Spell.dbc").toLatin1().data(), SpellEntryfmt))
        return false;
    spellDataTable = (SpellEntry *) dbc.AutoProduceData(SpellEntryfmt, nCount, (char ** &) spellIndexTable);
    if (_strings != 0)
        delete [] _strings;
    _strings = dbc.AutoProduceStrings(SpellEntryfmt, (char *) spellDataTable);
    if (!dbc.Load(QString(directory + "/SpellRange.dbc").toLatin1().data(), SpellRangefmt))
        return false;
    rangeDataTable = (SpellRangeEntry *) dbc.AutoProduceData(SpellRangefmt, tmp, (char ** &) rangeIndexTable);



    loadSpells(nCount, spellIndexTable, rangeIndexTable);
    delete [] spellDataTable;
    delete [] spellIndexTable;
    delete [] rangeDataTable;
    delete [] rangeIndexTable;
    return true;
}

void                    Spells::loadSpells(unsigned int nCount, SpellEntry ** spellIndexTable,
                                           SpellRangeEntry ** rangeIndexTable)
{
    MainWindow::getInstance()->statusBar()->showMessage("Loading spells.");
    while (!_spells.isEmpty())
        _spells.removeFirst();
    unsigned int percent = 0;
    for (unsigned int i = 0 ; i < nCount ; i++)
    {
        if (spellIndexTable[i] != 0)
        {
            _spells.append(Spell(spellIndexTable[i], rangeIndexTable));
        }
        if (i * 100 / nCount > percent)
        {
            percent = i * 100 / nCount;
            MainWindow::getInstance()->statusBar()->showMessage(QString::number(percent) + QString("%"));
        }
    }
}

const Spell *         Spells::getSpell(unsigned int id) const
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
