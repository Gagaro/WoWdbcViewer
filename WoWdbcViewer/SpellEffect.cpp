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

QString auraName[] = {
    "NONE",
    "BIND_SIGHT",
    "MOD_POSSESS",
    "PERIODIC_DAMAGE",
    "DUMMY",
    "MOD_CONFUSE",
    "MOD_CHARM",
    "MOD_FEAR",
    "PERIODIC_HEAL",
    "MOD_ATTACKSPEED",
    "MOD_THREAT",
    "MOD_TAUNT",
    "MOD_STUN",
    "MOD_DAMAGE_DONE",
    "MOD_DAMAGE_TAKEN",
    "DAMAGE_SHIELD",
    "MOD_STEALTH",
    "MOD_STEALTH_DETECT",
    "MOD_INVISIBILITY",
    "MOD_INVISIBILITY_DETECTION",
    "OBS_MOD_HEALTH",
    "OBS_MOD_MANA",
    "MOD_RESISTANCE",
    "PERIODIC_TRIGGER_SPELL",
    "PERIODIC_ENERGIZE",
    "MOD_PACIFY",
    "MOD_ROOT",
    "MOD_SILENCE",
    "REFLECT_SPELLS",
    "MOD_STAT",
    "MOD_SKILL",
    "MOD_INCREASE_SPEED",
    "MOD_INCREASE_MOUNTED_SPEED",
    "MOD_DECREASE_SPEED",
    "MOD_INCREASE_HEALTH",
    "MOD_INCREASE_ENERGY",
    "MOD_SHAPESHIFT",
    "EFFECT_IMMUNITY",
    "STATE_IMMUNITY",
    "SCHOOL_IMMUNITY",
    "DAMAGE_IMMUNITY",
    "DISPEL_IMMUNITY",
    "PROC_TRIGGER_SPELL",
    "PROC_TRIGGER_DAMAGE",
    "TRACK_CREATURES",
    "TRACK_RESOURCES",
    "46",
    "MOD_PARRY_PERCENT",
    "48",
    "MOD_DODGE_PERCENT",
    "MOD_BLOCK_SKILL",
    "MOD_BLOCK_PERCENT",
    "MOD_CRIT_PERCENT",
    "PERIODIC_LEECH",
    "MOD_HIT_CHANCE",
    "MOD_SPELL_HIT_CHANCE",
    "TRANSFORM",
    "MOD_SPELL_CRIT_CHANCE",
    "MOD_INCREASE_SWIM_SPEED",
    "MOD_DAMAGE_DONE_CREATURE",
    "MOD_PACIFY_SILENCE",
    "MOD_SCALE",
    "PERIODIC_HEALTH_FUNNEL",
    "PERIODIC_MANA_FUNNEL",
    "PERIODIC_MANA_LEECH",
    "MOD_CASTING_SPEED_NOT_STACK",
    "FEIGN_DEATH",
    "MOD_DISARM",
    "MOD_STALKED",
    "SCHOOL_ABSORB",
    "EXTRA_ATTACKS",
    "MOD_SPELL_CRIT_CHANCE_SCHOOL",
    "MOD_POWER_COST_SCHOOL_PCT",
    "MOD_POWER_COST_SCHOOL",
    "REFLECT_SPELLS_SCHOOL",
    "MOD_LANGUAGE",
    "FAR_SIGHT",
    "MECHANIC_IMMUNITY",
    "MOUNTED",
    "MOD_DAMAGE_PERCENT_DONE",
    "MOD_PERCENT_STAT",
    "SPLIT_DAMAGE_PCT",
    "WATER_BREATHING",
    "MOD_BASE_RESISTANCE",
    "MOD_REGEN",
    "MOD_POWER_REGEN",
    "CHANNEL_DEATH_ITEM",
    "MOD_DAMAGE_PERCENT_TAKEN",
    "MOD_HEALTH_REGEN_PERCENT",
    "PERIODIC_DAMAGE_PERCENT",
    "MOD_RESIST_CHANCE",
    "MOD_DETECT_RANGE",
    "PREVENTS_FLEEING",
    "MOD_UNATTACKABLE",
    "INTERRUPT_REGEN",
    "GHOST",
    "SPELL_MAGNET",
    "MANA_SHIELD",
    "MOD_SKILL_TALENT",
    "MOD_ATTACK_POWER",
    "AURAS_VISIBLE",
    "MOD_RESISTANCE_PCT",
    "MOD_MELEE_ATTACK_POWER_VERSUS",
    "MOD_TOTAL_THREAT",
    "WATER_WALK",
    "FEATHER_FALL",
    "HOVER",
    "ADD_FLAT_MODIFIER",
    "ADD_PCT_MODIFIER",
    "ADD_TARGET_TRIGGER",
    "MOD_POWER_REGEN_PERCENT",
    "ADD_CASTER_HIT_TRIGGER",
    "OVERRIDE_CLASS_SCRIPTS",
    "MOD_RANGED_DAMAGE_TAKEN",
    "MOD_RANGED_DAMAGE_TAKEN_PCT",
    "MOD_HEALING",
    "MOD_REGEN_DURING_COMBAT",
    "MOD_MECHANIC_RESISTANCE",
    "MOD_HEALING_PCT",
    "SHARE_PET_TRACKING",
    "UNTRACKABLE",
    "EMPATHY",
    "MOD_OFFHAND_DAMAGE_PCT",
    "MOD_TARGET_RESISTANCE",
    "MOD_RANGED_ATTACK_POWER",
    "MOD_MELEE_DAMAGE_TAKEN",
    "MOD_MELEE_DAMAGE_TAKEN_PCT",
    "RANGED_ATTACK_POWER_ATTACKER_BONUS",
    "MOD_POSSESS_PET",
    "MOD_SPEED_ALWAYS",
    "MOD_MOUNTED_SPEED_ALWAYS",
    "MOD_RANGED_ATTACK_POWER_VERSUS",
    "MOD_INCREASE_ENERGY_PERCENT",
    "MOD_INCREASE_HEALTH_PERCENT",
    "MOD_MANA_REGEN_INTERRUPT",
    "MOD_HEALING_DONE",
    "MOD_HEALING_DONE_PERCENT",
    "MOD_TOTAL_STAT_PERCENTAGE",
    "MOD_MELEE_HASTE",
    "FORCE_REACTION",
    "MOD_RANGED_HASTE",
    "MOD_RANGED_AMMO_HASTE",
    "MOD_BASE_RESISTANCE_PCT",
    "MOD_RESISTANCE_EXCLUSIVE",
    "SAFE_FALL",
    "CHARISMA",
    "PERSUADED",
    "MECHANIC_IMMUNITY_MASK",
    "RETAIN_COMBO_POINTS",
    "RESIST_PUSHBACK ",
    "MOD_SHIELD_BLOCKVALUE_PCT",
    "TRACK_STEALTHED ",
    "MOD_DETECTED_RANGE",
    "SPLIT_DAMAGE_FLAT",
    "MOD_STEALTH_LEVEL",
    "MOD_WATER_BREATHING",
    "MOD_REPUTATION_GAIN",
    "PET_DAMAGE_MULTI",
    "MOD_SHIELD_BLOCKVALUE",
    "NO_PVP_CREDIT",
    "MOD_AOE_AVOIDANCE",
    "MOD_HEALTH_REGEN_IN_COMBAT",
    "POWER_BURN_MANA",
    "MOD_CRIT_DAMAGE_BONUS",
    "164",
    "MELEE_ATTACK_POWER_ATTACKER_BONUS",
    "MOD_ATTACK_POWER_PCT",
    "MOD_RANGED_ATTACK_POWER_PCT",
    "MOD_DAMAGE_DONE_VERSUS",
    "MOD_CRIT_PERCENT_VERSUS",
    "DETECT_AMORE",
    "MOD_SPEED_NOT_STACK",
    "MOD_MOUNTED_SPEED_NOT_STACK",
    "ALLOW_CHAMPION_SPELLS",
    "MOD_SPELL_DAMAGE_OF_STAT_PERCENT",
    "MOD_SPELL_HEALING_OF_STAT_PERCENT",
    "SPIRIT_OF_REDEMPTION",
    "AOE_CHARM",
    "MOD_DEBUFF_RESISTANCE",
    "MOD_ATTACKER_SPELL_CRIT_CHANCE",
    "MOD_FLAT_SPELL_DAMAGE_VERSUS",
    "MOD_FLAT_SPELL_CRIT_DAMAGE_VERSUS",
    "MOD_RESISTANCE_OF_STAT_PERCENT",
    "MOD_CRITICAL_THREAT",
    "MOD_ATTACKER_MELEE_HIT_CHANCE",
    "MOD_ATTACKER_RANGED_HIT_CHANCE",
    "MOD_ATTACKER_SPELL_HIT_CHANCE",
    "MOD_ATTACKER_MELEE_CRIT_CHANCE",
    "MOD_ATTACKER_RANGED_CRIT_CHANCE",
    "MOD_RATING",
    "MOD_FACTION_REPUTATION_GAIN",
    "USE_NORMAL_MOVEMENT_SPEED",
    "MOD_MELEE_RANGED_HASTE",
    "HASTE_ALL",
    "MOD_DEPRICATED_1 ",
    "MOD_DEPRICATED_2 ",
    "MOD_COOLDOWN",
    "MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE",
    "MOD_ALL_WEAPON_SKILLS",
    "MOD_INCREASES_SPELL_PCT_TO_HIT",
    "MOD_XP_PCT",
    "FLY",
    "IGNORE_COMBAT_RESULT",
    "MOD_ATTACKER_MELEE_CRIT_DAMAGE",
    "MOD_ATTACKER_RANGED_CRIT_DAMAGE",
    "MOD_ATTACKER_SPELL_CRIT_DAMAGE",
    "MOD_FLIGHT_SPEED",
    "MOD_FLIGHT_SPEED_MOUNTED",
    "MOD_FLIGHT_SPEED_STACKING",
    "MOD_FLIGHT_SPEED_MOUNTED_STACKING",
    "MOD_FLIGHT_SPEED_NOT_STACKING",
    "MOD_FLIGHT_SPEED_MOUNTED_NOT_STACKING",
    "MOD_RANGED_ATTACK_POWER_OF_STAT_PERCENT",
    "MOD_RAGE_FROM_DAMAGE_DEALT",
    "214",
    "ARENA_PREPARATION",
    "HASTE_SPELLS",
    "217",
    "HASTE_RANGED",
    "MOD_MANA_REGEN_FROM_STAT",
    "MOD_RATING_FROM_STAT",
    "221",
    "222",
    "223",
    "224",
    "PRAYER_OF_MENDING",
    "PERIODIC_DUMMY",
    "PERIODIC_TRIGGER_SPELL_WITH_VALUE",
    "DETECT_STEALTH",
    "MOD_AOE_DAMAGE_AVOIDANCE",
    "230",
    "PROC_TRIGGER_SPELL_WITH_VALUE",
    "MECHANIC_DURATION_MOD",
    "233",
    "MECHANIC_DURATION_MOD_NOT_STACK",
    "MOD_DISPEL_RESIST",
    "236",
    "MOD_SPELL_DAMAGE_OF_ATTACK_POWER",
    "MOD_SPELL_HEALING_OF_ATTACK_POWER",
    "MOD_SCALE_2",
    "MOD_EXPERTISE",
    "FORCE_MOVE_FORWARD",
    "242",
    "243",
    "COMPREHEND_LANGUAGE",
    "245",
    "246",
    "MIRROR_IMAGE",
    "MOD_COMBAT_RESULT_CHANCE",
    "249",
    "MOD_INCREASE_HEALTH_2",
    "MOD_ENEMY_DODGE",
    "252",
    "253",
    "254",
    "255",
    "256",
    "257",
    "258",
    "259",
    "260",
    "261",
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
   _applyAuraName = auraName[spell->EffectApplyAuraName[i]];
   _amplitude = spell->EffectAmplitude[i];
   _multipleValue = spell->EffectMultipleValue[i];
   _chainTarget = spell->EffectChainTarget[i];
   _itemType = spell->EffectItemType[i];
   _miscValueA = spell->EffectMiscValue[i];
   _miscValueB = spell->EffectMiscValueB[i];
   _triggerSpell = spell->EffectTriggerSpell[i];
   _pointsPerComboPoint = spell->EffectPointsPerComboPoint[i];
   _dmgMultiplier = spell->DmgMultiplier[i];
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

const QString   &SpellEffect::getApplyAuraName() const
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

float SpellEffect::getDmgMultiplier() const
{
    return _dmgMultiplier;
}
