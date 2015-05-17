#ifndef YEAST_H
#define YEAST_H

#include <QString>

// Yeast
//
// Implements underlying yeast data structure.
class Yeast
{
public:
    Yeast(QString name, int attenuation);

    // Setters
    void setAttenuation(float attentuation)    { _attentuation = attentuation; }

    // Getters
    QString name() const        { return _name; }
    int attenuation() const     { return _attentuation; }

private:
    QString _name;          // Yeast Strain Name
    int _attentuation;      // Estimated attenuation (in %)
};

#endif // YEAST_H
