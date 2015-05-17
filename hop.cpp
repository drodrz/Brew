#include "hop.h"

// Fermentable Constructor
Hop::Hop(QString name, float amt, float aa, int time) {
    _name = name;
    _time = time;
    _aa = aa;
    _amount = amt;
}
