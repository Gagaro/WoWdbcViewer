#ifndef SPELL_H
#define SPELL_H

#include <QString>

#include "dbc/DBCStructures.h"
#include "SpellEffect.h"

class Spell
{
public:
    Spell(SpellEntry *spell);
    ~Spell();

    int getId() const;
    const QString &getName() const;

private:
    int         _id;
    QString     _name;
    SpellEffect _spellEffects[MAX_EFFECT_INDEX];
};

#endif // SPELL_H
