#ifndef SPELLS_H
#define SPELLS_H

#include <QList>
#include <QString>

#include "Spell.h"

class Spells
{
public:
    Spells();

    bool                    importSpells(QString filename);
    const Spell *           getSpell(int id) const;
    const Spell *           getSpell(QString name) const;
    const QList<Spell> *    getSpells() const;

private:
    QList<Spell> _spells;
};

#endif // SPELLS_H
