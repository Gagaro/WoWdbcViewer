#ifndef SPELLEFFECT_H
#define SPELLEFFECT_H

#include <QString>

#include "dbc/SharedDefines.h"
#include "dbc/DBCStructures.h"


class SpellEffect
{
public:
    SpellEffect() {}
    SpellEffect(SpellEntry * spell, int i);

private:
    QString         _name;
    unsigned int    _effect;
    unsigned int    _dieSides;
    unsigned int    _baseDice;
    unsigned int    _dicePerLevel;
    unsigned int    _realPointsPerLevel;
    unsigned int    _basePoint;
    unsigned int    _mechanic;
    unsigned int    _implicitTargetA;
    unsigned int    _implicitTargetB;
    unsigned int    _radius;
    unsigned int    _applyAuraName;
    unsigned int    _amplitude;
    unsigned int    _multipleValue;
    unsigned int    _chainTarget;
    unsigned int    _itemType;
    unsigned int    _miscValueA;
    unsigned int    _miscValueB;
    unsigned int    _triggerSpell;
    unsigned int    _pointsPerComboPoint;
};

#endif // SPELLEFFECT_H
