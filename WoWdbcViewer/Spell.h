#ifndef SPELL_H
#define SPELL_H

#include <QString>
#include <QList>

#include "dbc/DBCStructures.h"
#include "dbc/SharedDefines.h"
#include "SpellEffect.h"
#include "SpellAttribute.h"

class Spell
{
public:
    Spell(SpellEntry *spell, SpellRangeEntry ** rangeIndexTable);
    ~Spell();

    unsigned int                    getId() const;
    const QString &                 getName() const;
    const QString &                 getRank() const;
    const QString &                 getTooltip() const;
    const QString &                 getDescription() const;
    const SpellEffect &             getSpellEffect(int i) const;
    const QList<SpellAttribute> &   getAttributes() const;
    const QString &                 getSchool() const;
    const QString &                 getDispel() const;
    const QString &                 getMechanic() const;
    unsigned int                    getMinRange() const;
    unsigned int                    getMaxRange() const;

private:
    /** @TODO
    unsigned int            _category;
    unsigned int            _stances;
    unsigned int            _stancesNot;
    unsigned int            _targets;
    unsigned int            _targetCreatureType;
    unsigned int            _requiresSpellFocus;
    unsigned int            _facingCasterFlags;
    unsigned int            _casterAuraState;
    unsigned int            _targetAuraState;
    unsigned int            _casterAuraStateNot;
    unsigned int            _targetAuraStateNot;
    unsigned int            _castingTimeIndex;
    unsigned int            _recoveryTime;
    unsigned int            _categoryRecoveryTime;
    unsigned int            _interruptFlags;
    unsigned int            _auraInterruptFlags;
    unsigned int            _channelInterruptFlags;
    unsigned int            _procFlags;
    unsigned int            _procChance;
    unsigned int            _procCharges;
    unsigned int            _maxLevel;
    unsigned int            _baseLevel;
    unsigned int            _spellLevel;
    unsigned int            _durationIndex;
    unsigned int            _powerType;
    unsigned int            _manaCost;
    unsigned int            _manaCostPerLevel;
    unsigned int            _manaPerSecond;
    unsigned int            _manaPerSecondPerLevel;
    float                   _speed;
    unsigned int            _stackAmount;
    unsigned int            _totem[MAX_SPELL_TOTEMS];
    int                     _reagent[MAX_SPELL_REAGENTS];
    unsigned int            _reagentCount[MAX_SPELL_REAGENTS];
    int                     _equippedItemClass;
    int                     _equippedItemSubClassMask;
    int                     _equippedItemInventoryTypeMask;
    unsigned int            _spellVisual;
    unsigned int            _spellIconID;
    unsigned int            _activeIconID;
    unsigned int            _manaCostPercentage;
    unsigned int            _startRecoveryCategory;
    unsigned int            _startRecoveryTime;
    unsigned int            _maxTargetLevel;
    unsigned int            _spellFamilyName;
    ClassFamilyMask         _spellFamilyFlags;
    unsigned int            _maxAffectedTargets;
    unsigned int            _dmgClass;
    unsigned int            _preventionType;
    unsigned int            _totemCategory[MAX_SPELL_TOTEM_CATEGORIES];
    unsigned int            _areaId;
    */

    unsigned int            _id;
    QString                 _name;
    QString                 _rank;
    QString                 _description;
    QString                 _tooltip;
    QString                 _dispel;
    QString                 _mechanic;
    QString                 _school;
    SpellEffect             _effects[MAX_EFFECT_INDEX];
    QList<SpellAttribute>   _attributes;
    unsigned int            _minRange;
    unsigned int            _maxRange;
};

#endif // SPELL_H
