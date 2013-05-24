#ifndef SPELLATTRIBUTE_H
#define SPELLATTRIBUTE_H

#include <QString>
#include <QList>

#include "dbc/DBCStructures.h"

class SpellAttribute
{
public:
    SpellAttribute(QString &name, QString &description);
    const QString         &getName() const;
    const QString         &getDescription() const;

    static QList<SpellAttribute>    create(SpellEntry *spell);

private:
    QString         _name;
    QString         _description;
};

#endif // SPELLATTRIBUTE_H
