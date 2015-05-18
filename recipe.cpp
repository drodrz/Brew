#include <QtMath>

#include "recipe.h"

Recipe::Recipe(QObject *parent) : QObject(parent)
{
    _volume = 5.0;
    _boil_time = 60;
    _evaporation_rate = .15;
}

// Add Fermentable to the recipe
void Recipe::addFermentable(Fermentable fermentable) {
    _fermentables.append(&fermentable);
    updateEstimates();
}

// Add Hop to the recipe
void Recipe::addHop(Hop hop){
    _hops.append(&hop);
    updateEstimates();
}

// Add Yeast to the recipe
void Recipe::addYeast(Yeast yeast) {
    _yeast.append(&yeast);
    updateEstimates();
}

// Call after modifying ingredients to calculate estimated gravity
void Recipe::calc_gravity() {
    // TODO: Calculate gravity
    _og = 1.075;
    _fg = 1.016;
}

// Call after modifying ingredients to calculate estimated SRM (color)
void Recipe::calc_srm() {
    float mcu = 0;
    foreach(const Fermentable *f, _fermentables) {
        mcu += f->amount() * f->lovibond() / _volume;
    }

    // Equation courtesy of Beersmith
    // http://beersmith.com/blog/2008/04/29/beer-color-understanding-srm-lovibond-and-ebc/
    _srm = 1.4922 * qPow(mcu, .6859);
}

void Recipe::calc_ibu() {
    _ibu = 0;
    float U = .148; // TODO: Need to calculate utilization
    foreach(const Hop *h, _hops) {
        float aau = h->amount() * h->aa();
        _ibu += aau * U * 75 / _volume;
    }

    // Equation courtesy of How to Brew
    // http://www.howtobrew.com/section1/chapter5-5.html
}

void Recipe::calc_abv() {
    _abv = (_og - _fg)*131;

    // Homebrew Stack Exchange
    // http://homebrew.stackexchange.com/questions/2924/calculating-alcohol-by-volume
}

// Called when fermentables or yeast are modified to update estimates
void Recipe::updateEstimates() {
    calc_gravity();
    calc_srm();
    calc_ibu();
    calc_abv();
}
