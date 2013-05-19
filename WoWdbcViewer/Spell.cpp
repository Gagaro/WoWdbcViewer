#include "Spell.h"

Spell::Spell(int id, QString name)
{
    _id = id;
    _name = name;
}

QString Spell::name() const
{
    return _name;
}

int Spell::id() const
{
    return _id;
}

