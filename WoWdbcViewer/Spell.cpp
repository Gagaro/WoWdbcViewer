#include "Spell.h"

Spell::Spell(int id, QString name)
{
    _id = id;
    _name = name;
}

const QString &Spell::getName() const
{
    return _name;
}

int Spell::getId() const
{
    return _id;
}

