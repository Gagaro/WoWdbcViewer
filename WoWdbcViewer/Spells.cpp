#include <QDebug>

#include "Spells.h"
#include "dbc/DBCFileLoader.h"
#include "dbc/DBCfmt.h"
#include "dbc/DBCStructures.h"

Spells::Spells()
{
}

bool Spells::importSpells(QString filename)
{
    DBCFileLoader dbc;
    uint32 nCount;
    SpellEntry ** indexTable;
    SpellEntry * m_dataTable;

    if (!dbc.Load(filename.toLatin1().data(), SpellEntryfmt))
        return false;

    m_dataTable = (SpellEntry *) dbc.AutoProduceData(SpellEntryfmt, nCount, (char ** &) indexTable);
    dbc.AutoProduceStrings(SpellEntryfmt, (char *) m_dataTable);

    while (!_spells.isEmpty())
        _spells.removeFirst();
    for (unsigned int i = 0 ; i < nCount ; i++)
    {
        if (indexTable[i] != 0)
        {
            _spells.append(Spell(indexTable[i]->Id, (char *) indexTable[i]->SpellName));
        }
    }
    return true;
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

const QList <Spell> * Spells::getSpells() const
{
    return &_spells;
}
