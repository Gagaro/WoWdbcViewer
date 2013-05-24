#include "Spell.h"

Spell::Spell(SpellEntry *spell)
{
    _id = spell->Id;
    //_name = QString(spell->SpellName[0]);

    // Effects
    for (int i = 0 ; i < MAX_EFFECT_INDEX ; i++)
    {
        _effects[i] = SpellEffect(spell, i);
    }

    // Attributes
    _attributes = SpellAttribute::create(spell);
}

Spell::~Spell()
{
}

const QString &Spell::getName() const
{
    return _name;
}

int Spell::getId() const
{
    return _id;
}

const SpellEffect & Spell::getSpellEffect(int i) const
{
    return _effects[i];
}

const QList<SpellAttribute>   &Spell::getAttributes() const
{
    return _attributes;
}
