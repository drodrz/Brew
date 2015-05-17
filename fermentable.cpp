#include "fermentable.h"

// Fermentable Constructor
Fermentable::Fermentable(QString name, QString type, float ppg, int lovibond, float amt) {
    _name = name;
    _type = type;
    _ppg = ppg;
    _lovibond = lovibond;
    _amount = amt;
}
