#include "Spell.h"

QString spellSchoolName[] = {
    "Normal",
    "Holy",
    "Fire",
    "Nature",
    "Frost",
    "Shadow",
    "Arcane"
};

Spell::Spell(SpellEntry *spell)
{
    _id = spell->Id;
    _name = QString(spell->SpellName[2]);

    // Effects
    for (int i = 0 ; i < MAX_EFFECT_INDEX ; i++)
    {
        _effects[i] = SpellEffect(spell, i);
    }
    // Attributes
    _attributes = SpellAttribute::create(spell);
    // School
    _school = "None";
    for (unsigned int i = 0 ; i < MAX_SPELL_SCHOOL ; i++)
        if ((spell->SchoolMask & (1 << i)) == (1 << i))
        {
            _school = spellSchoolName[i];
            break ;
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
    return _effects[i];
}

const QList<SpellAttribute>   &Spell::getAttributes() const
{
    return _attributes;
}

const QString   &Spell::getSchool() const
{
    return _school;
}
