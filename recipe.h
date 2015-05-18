#ifndef RECIPE_H
#define RECIPE_H

#include <QVector>
#include "hop.h"
#include "fermentable.h"
#include "yeast.h"

class Recipe : public QObject {
Q_OBJECT
public:
    Recipe(QObject *parent = 0);

public slots:
    void addFermentable(Fermentable fermentable);   // Add Fermentable to the recipe
    void addHop(Hop hop);                           // Add Hop to the recipe
    void addYeast(Yeast yeast);                     // Add Yeast to the recipe

    // TODO: Ability to remove ingredients

    // Getters
    QString name()              { return _name; }
    QString style()             { return _style; }
    float volume()              { return _volume; }
    float boil_time()           { return _boil_time; }
    float evaporation_rate()    { return _evaporation_rate; }
    float og()                  { return _og; }
    float fg()                  { return _fg; }
    float srm()                 { return _srm; }
    float ibu()                 { return _ibu; }
    float abv()                 { return _abv; }

private:
    QVector <Fermentable*> _fermentables;           // Fermentables in current recipe
    QVector <Hop*> _hops;                           // Fermentables in current recipe
    QVector <Yeast*> _yeast;                        // Fermentables in current recipe
    QString _name;                                  // Recipe Name
    QString _style;                                 // Recipe Style.  TODO: Make this a type with associated ranges and guidelines
    float _volume;                                  // Target volume (in gal)
    float _boil_time;                               // Boil time (in min)   TODO: Incorporate boil time + evaporation rate
    float _evaporation_rate;                        // Evaporation rate (in %/hr)
    float _og;                                      // Estimated Original Gravity
    float _fg;                                      // Estimated Final Gravity
    float _srm;                                     // Estimated SRM
    float _ibu;                                     // Estimated IBU
    float _abv;                                     // Estimated Alcohol by Volume

    void calc_gravity();                            // Calculate gravity
    void calc_srm();                                // Calculate srm
    void calc_ibu();                                // Calculate ibu
    void calc_abv();                                // Calculate abv
    void updateEstimates();                         // Called when ingrediates are modified to update estimates
};

#endif // RECIPE_H
