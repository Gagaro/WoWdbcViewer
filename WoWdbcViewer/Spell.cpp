#include "Spell.h"

QString spellMechanics[] = {
    "None",
    "Charm",
    "Disoriented",
    "Disarm",
    "Distract",
    "Fear",
    "Fumble",
    "Root",
    "Pacify",
    "Silence",
    "Sleep",
    "Snare",
    "Stun",
    "Freeze",
    "Knockout",
    "Bleed",
    "Bandage",
    "Polymorph",
    "Banish",
    "Shield",
    "Shackle",
    "Mount",
    "Persuade",
    "Turn",
    "Horror",
    "Invulnarability",
    "Interrupt",
    "Daze",
    "Discovery",
    "Immune Shield",
    "Sapped"
};

QString spellDispels[] = {
    "None",
    "Magic",
    "Curse",
    "Disease",
    "Poison",
    "Stealth",
    "Invisibility",
    "All",
    "Spe NPC Only",
    "Enrage",
    "ZG Ticket"
};

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

    // Strings
    _name = spell->SpellName[2];
    _rank = spell->Rank[2];
    _description = spell->Description[2];
    _tooltip = spell->ToolTip[2];

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
    // Dispel
    _dispel = spellDispels[spell->Dispel];
    // Mechanic
    _mechanic = spellMechanics[spell->Mechanic];
}

Spell::~Spell()
{
}

const QString &Spell::getName() const
{
    return _name;
}

const QString &Spell::getRank() const
{
    return _rank;
}

const QString &Spell::getTooltip() const
{
    return _tooltip;
}

const QString &Spell::getDescription() const
{
    return _description;
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

const QString &Spell::getDispel() const
{
    return _dispel;
}

const QString &Spell::getMechanic() const
{
    return _mechanic;
}

unsigned int Spell::getMinRange() const
{
    return _minRange;
}

unsigned int Spell::getMaxRange() const
{
    return _maxRange;
}
