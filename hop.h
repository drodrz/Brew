#ifndef HOP_H
#define HOP_H

#include <QString>

// Hop
//
// Implements underlying hop data structure.
// TODO: Seperate amount and time from this data structure.
class Hop
{
public:
    Hop(QString name, float amt, float aa, int time);

    // Setters
    void setAmount(float amt)   { _amount = amt; }
    void setTime(float time)    { _time = time; }

    // Getters
    QString name() const    { return _name; }
    int time() const        { return _time; }
    float aa() const        { return _aa; }
    float amount() const    { return _amount; }

private:
    QString _name;      // Hop Name
    int _time;          // Hop addition (in minutes)
    float _aa;          // Alpha acid (in %)
    float _amount;      // Hop amount (in oz) TODO: Use grams internally, user option for display units
};

#endif // HOP_H
