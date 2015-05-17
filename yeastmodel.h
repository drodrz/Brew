#ifndef YEASTMODEL_H
#define YEASTMODEL_H

#include <QAbstractTableModel>
#include <QString>
#include <yeast.h>

// YeastModel
//
// Implements the Table Model for the current recipe's hops.  The model keeps
// track of a list of Fermentables which are used to calculate the recipe's IBUs
class YeastModel : public QAbstractTableModel
{
public:
    YeastModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;      // Returns number of rows in table
    int columnCount(const QModelIndex &parent = QModelIndex()) const;   // Returns number of cols in table
    QVariant data(const QModelIndex &index, int role) const;            // Returns the data at a particular index
    QVariant headerData(int section, Qt::Orientation orientation,       // Describes how to populate the table's header
                        int role = Qt::DisplayRole) const;

private:
    QStringList headerList;                 // Specifies table header strings
    QVector <Yeast*> yeast;                 // Yeast in current recipe

};

#endif // YEASTMODEL_H
