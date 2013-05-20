#ifndef SPELL_H
#define SPELL_H

#include <QString>

class Spell
{
public:
    Spell(int id, QString name);

    int getId() const;
    const QString &getName() const;

private:
    int     _id;
    QString _name;
};

#endif // SPELL_H
