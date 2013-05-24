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
    Spell(SpellEntry *spell);
    ~Spell();

    int                             getId() const;
    const QString &                 getName() const;
    const SpellEffect &             getSpellEffect(int i) const;
    const QList<SpellAttribute> &   getAttributes() const;

private:
    int                     _id;
    QString                 _name;
    SpellEffect             _effects[MAX_EFFECT_INDEX];
    QList<SpellAttribute>   _attributes;
};

#endif // SPELL_H
