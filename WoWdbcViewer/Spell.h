#ifndef SPELL_H
#define SPELL_H

#include <QString>

class Spell
{
public:
    Spell(int id, QString name);

    int id() const;
    QString name() const;

private:
    int     _id;
    QString _name;
};

#endif // SPELL_H
