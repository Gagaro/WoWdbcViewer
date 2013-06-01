#ifndef SPELLS_H
#define SPELLS_H

#include <QList>
#include <QString>

#include "Spell.h"

struct SpellEntry;

class Spells
{
public:
    Spells();
    ~Spells();

    bool                    importSpells(QString directory);
    void                    loadSpells(unsigned int nCount, SpellEntry ** spellIndexTable,
                                       SpellRangeEntry ** rangeIndexTable);
    const Spell *           getSpell(unsigned int id) const;
    const Spell *           getSpell(QString name) const;
    const QList<Spell> *    getSpells() const;

private:
    QList<Spell>            _spells;
    char *                  _strings;
};

#endif // SPELLS_H
