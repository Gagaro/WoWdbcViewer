#include "Spell.h"

Spell::Spell(SpellEntry *spell)
{
    _id = spell->Id;
    //_name = QString(spell->SpellName[0]);

    for (int i = 0 ; i < MAX_EFFECT_INDEX ; i++)
    {
        _spellEffects[i] = SpellEffect(spell, i);
    }
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
    return _spellEffects[i];
}
