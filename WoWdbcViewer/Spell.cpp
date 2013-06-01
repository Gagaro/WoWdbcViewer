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

Spell::Spell(SpellEntry *spell, SpellRangeEntry **rangeIndexTable)
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
        if ((spell->SchoolMask & (1 << i)) == (unsigned int) (1 << i))
        {
            _school = spellSchoolName[i];
            break ;
        }
    // Range
    _minRange = rangeIndexTable[spell->rangeIndex]->minRange;
    _maxRange = rangeIndexTable[spell->rangeIndex]->maxRange;
}

Spell::~Spell()
{
}

const QString &Spell::getName() const
{
    return _name;
}

unsigned int Spell::getId() const
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

unsigned int Spell::getMinRange() const
{
    return _minRange;
}

unsigned int Spell::getMaxRange() const
{
    return _maxRange;
}
