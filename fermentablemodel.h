#ifndef FERMENTABLEMODEL_H
#define FERMENTABLEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include <QString>
#include <fermentable.h>


// FermentableModel
//
// Implements the Table Model for the current recipe's fermentables.  The model keeps
// track of a list of Fermentables which are used to calculate the recipe's percentages,
// estimated sugars, and color.
class FermentableModel : public QAbstractTableModel
{
public:
    FermentableModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;      // Returns number of rows in table
    int columnCount(const QModelIndex &parent = QModelIndex()) const;   // Returns number of cols in table
    QVariant data(const QModelIndex &index, int role) const;            // Returns the data at a particular index
    QVariant headerData(int section, Qt::Orientation orientation,       // Describes how to populate the table's header
                        int role = Qt::DisplayRole) const;

private:
    QStringList headerList;                                             // Specifies table header strings
    QVector <Fermentable*> fermentables;                                // Fermentables in current recipe

};

#endif // FERMENTABLEMODEL_H
