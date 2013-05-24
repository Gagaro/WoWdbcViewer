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
    const QString         &getName() const;
    unsigned int    getEffect() const;
    unsigned int    getDieSides() const;
    unsigned int    getBaseDice() const;
    unsigned int    getDicePerLevel() const;
    unsigned int    getRealPointsPerLevel() const;
    unsigned int    getBasePoint() const;
    unsigned int    getMechanic() const;
    unsigned int    getImplicitTargetA() const;
    unsigned int    getImplicitTargetB() const;
    unsigned int    getRadius() const;
    unsigned int    getApplyAuraName() const;
    unsigned int    getAmplitude() const;
    unsigned int    getMultipleValue() const;
    unsigned int    getChainTarget() const;
    unsigned int    getItemType() const;
    unsigned int    getMiscValueA() const;
    unsigned int    getMiscValueB() const;
    unsigned int    getTriggerSpell() const;
    unsigned int    getPointsPerComboPoint() const;

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
