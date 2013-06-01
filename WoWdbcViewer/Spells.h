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

    bool                    importSpells(QString filename);
    void                    loadSpells(SpellEntry ** indexTable, unsigned int nCount);
    const Spell *           getSpell(int id) const;
    const Spell *           getSpell(QString name) const;
    const QList<Spell> *    getSpells() const;

private:
    QList<Spell>            _spells;
    char *                  _strings;
};

#endif // SPELLS_H
