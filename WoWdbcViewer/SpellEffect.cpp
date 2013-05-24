#include "SpellEffect.h"

QString effectName[] = {
        "None",
        "Instakill",
        "School damage",
        "Dummy",
        "Portal teleport",
        "Teleport Unit",
        "Apply aura",
        "Environmental damage",
        "Power drain",
        "Health leech",
        "Heal",
        "Bind",
        "Portal",
        "Ritual base",
        "Ritual specialize",
        "Ritual activate portal",
        "Quest complete",
        "Weapon damage noschool",
        "Resurrect",
        "Add extra attacks",
        "Dodge",
        "Evade",
        "Parry",
        "Block",
        "Create item",
        "Weapon",
        "Defense",
        "Persistent area aura",
        "Summon",
        "Leap",
        "Energize",
        "Weapon percent damage",
        "Trigger missile",
        "Open lock",
        "Summon change item",
        "Apply area aura party",
        "Learn spell",
        "Spell defense",
        "Dispel",
        "Language",
        "Dual wield",
        "41",
        "42",
        "Teleport units face caster",
        "Skill step",
        "Undefined 45",
        "Spawn",
        "Trade skill",
        "Stealth",
        "Detect",
        "Trans door",
        "Force critical hit",
        "Guarantee hit",
        "Enchant item",
        "Enchant item temporary",
        "Tamecreature",
        "Summon pet",
        "Learn pet spell",
        "Weapon damage",
        "Open lock item",
        "Proficiency",
        "Send event",
        "Power burn",
        "Threat",
        "Trigger spell",
        "Health funnel",
        "Power funnel",
        "Heal max health",
        "Interrupt cast",
        "Distract",
        "Pull",
        "Pickpocket",
        "Add farsight",
        "73",
        "74",
        "Heal mechanical",
        "Summon object wild",
        "Script effect",
        "Attack",
        "Sanctuary",
        "Add combo points",
        "Create house",
        "Bind sight",
        "Duel",
        "Stuck",
        "Summon player",
        "Activate object",
        "87",
        "88",
        "89",
        "90",
        "Threat all",
        "Enchant held item",
        "93",
        "Self resurrect",
        "Skinning",
        "Charge",
        "97",
        "Knock back",
        "Disenchant",
        "Inebriate",
        "Feed pet",
        "Dismiss pet",
        "Reputation",
        "Summon object slot1",
        "Summon object slot2",
        "Summon object slot3",
        "Summon object slot4",
        "Dispel mechanic",
        "Summon dead pet",
        "Destroy all totems",
        "Durability damage",
        "112",
        "Resurrect new",
        "Attack me",
        "Durability damage pct",
        "Skin player corpse",
        "Spirit heal",
        "Skill",
        "Apply area aura pet",
        "Teleport graveyard",
        "Normalized weapon dmg",
        "122",
        "Send taxi",
        "Player pull",
        "Modify threat percent",
        "Steal beneficial buff",
        "Prospecting",
        "Apply area aura friend",
        "Apply area aura enemy",
        "Redirect threat",
        "Play sound",
        "Play music",
        "Unlearn specialization",
        "Kill credit group",
        "Call pet",
        "Heal pct",
        "Energize pct",
        "Leap back",
        "Clear quest",
        "Force cast",
        "141",
        "Trigger spell with value",
        "Apply area aura owner",
        "Knockback from position",
        "145",
        "146",
        "Quest fail",
        "148",
        "Charge2",
        "150",
        "Trigger spell 2",
        "152",
        "153"
    };

SpellEffect::SpellEffect(SpellEntry *spell, int i)
{
    _effect = spell->Effect[i];
    _name = QString(effectName[_effect]);
   _dieSides = spell->EffectDieSides[i];
   _baseDice = spell->EffectBaseDice[i];
   _dicePerLevel = spell->EffectDicePerLevel[i];
   _realPointsPerLevel = spell->EffectRealPointsPerLevel[i];
   _basePoint = spell->EffectBasePoints[i];
   _mechanic = spell->EffectMechanic[i];
   _implicitTargetA = spell->EffectImplicitTargetA[i];
   _implicitTargetB = spell->EffectImplicitTargetB[i];
   _radius = spell->EffectRadiusIndex[i];
   _applyAuraName = spell->EffectApplyAuraName[i];
   _amplitude = spell->EffectAmplitude[i];
   _multipleValue = spell->EffectMultipleValue[i];
   _chainTarget = spell->EffectChainTarget[i];
   _itemType = spell->EffectItemType[i];
   _miscValueA = spell->EffectMiscValue[i];
   _miscValueB = spell->EffectMiscValueB[i];
   _triggerSpell = spell->EffectTriggerSpell[i];
   _pointsPerComboPoint = spell->EffectPointsPerComboPoint[i];
}

const QString         &SpellEffect::getName() const
{
    return _name;
}

unsigned int    SpellEffect::getEffect() const
{
    return _effect;
}

unsigned int    SpellEffect::getDieSides() const
{
    return _dieSides;
}

unsigned int    SpellEffect::getBaseDice() const
{
    return _baseDice;
}

unsigned int    SpellEffect::getDicePerLevel() const
{
    return _dicePerLevel;
}

unsigned int    SpellEffect::getRealPointsPerLevel() const
{
    return _realPointsPerLevel;
}

unsigned int    SpellEffect::getBasePoint() const
{
    return _basePoint;
}

unsigned int    SpellEffect::getMechanic() const
{
    return _mechanic;
}

unsigned int    SpellEffect::getImplicitTargetA() const
{
    return _implicitTargetA;
}

unsigned int    SpellEffect::getImplicitTargetB() const
{
    return _implicitTargetB;
}

unsigned int    SpellEffect::getRadius() const
{
    return _radius;
}

unsigned int    SpellEffect::getApplyAuraName() const
{
    return _applyAuraName;
}

unsigned int    SpellEffect::getAmplitude() const
{
    return _amplitude;
}

unsigned int    SpellEffect::getMultipleValue() const
{
    return _multipleValue;
}

unsigned int    SpellEffect::getChainTarget() const
{
    return _chainTarget;
}

unsigned int    SpellEffect::getItemType() const
{
    return _itemType;
}

unsigned int    SpellEffect::getMiscValueA() const
{
    return _miscValueA;
}

unsigned int    SpellEffect::getMiscValueB() const
{
    return _miscValueB;
}

unsigned int    SpellEffect::getTriggerSpell() const
{
    return _triggerSpell;
}

unsigned int    SpellEffect::getPointsPerComboPoint() const
{
    return _pointsPerComboPoint;
}
