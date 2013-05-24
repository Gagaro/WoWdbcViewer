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
    const unsigned int    getEffect() const;
    const unsigned int    getDieSides() const;
    const unsigned int    getBaseDice() const;
    const unsigned int    getDicePerLevel() const;
    const unsigned int    getRealPointsPerLevel() const;
    const unsigned int    getBasePoint() const;
    const unsigned int    getMechanic() const;
    const unsigned int    getImplicitTargetA() const;
    const unsigned int    getImplicitTargetB() const;
    const unsigned int    getRadius() const;
    const unsigned int    getApplyAuraName() const;
    const unsigned int    getAmplitude() const;
    const unsigned int    getMultipleValue() const;
    const unsigned int    getChainTarget() const;
    const unsigned int    getItemType() const;
    const unsigned int    getMiscValueA() const;
    const unsigned int    getMiscValueB() const;
    const unsigned int    getTriggerSpell() const;
    const unsigned int    getPointsPerComboPoint() const;

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
