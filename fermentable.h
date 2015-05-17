#ifndef FERMENTABLE_H
#define FERMENTABLE_H

#include <QObject>
#include <QString>

// Fermentable
//
// Implements underlying fermentable data structure.  In the future, may seperate
// the amount of a particular fermentable from this data structure.
class Fermentable
{
public:
    Fermentable(QString name, QString type, float ppg, int lovibond, float amt);

    // Setters
    void setAmount(float amt)   { _amount = amt; }

    // Getters
    QString name() const    { return _name; }
    QString type() const    { return _type; }
    int ppg() const         { return _ppg; }
    int lovibond() const    { return _lovibond; }
    float amount() const    { return _amount; }

private:
    QString _name;      // Fermentable Name
    QString _type;      // Fermentable Type (i.e. Base Malt, Crystal Malt, adjunt, etc)
    int _ppg;           // Fermentable sugars contributed
    int _lovibond;      // Color contributed
    float _amount;      // Weight of fermentable (defaulting to lbs for now).  TODO:  Switch to metric
};

#endif // FERMENTABLETYPE_H
