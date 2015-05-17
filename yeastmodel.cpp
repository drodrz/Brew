#include "yeastmodel.h"

// YeastModel Constructor
// Initializes header strings and hardcoded Yeasts
YeastModel::YeastModel(QObject *parent)
    :QAbstractTableModel(parent){
    headerList << "Name" << "Attenuation";

    yeast << new Yeast("WLP001", 78);
}

// rowCount
// Required QAbstractTableModel method.  Indicates how many rows to display.
// Returns number of Yeasts in current recipe
int YeastModel::rowCount(const QModelIndex &) const {
    return yeast.length();
}

// columnCount
// Required QAbstractTableModel method.  Indicates how many cols to display.
// Num cols defined by number of items in the header list
int YeastModel::columnCount(const QModelIndex &) const {
    return headerList.length();
}

// data
// Required QAbstractTableModel method.  Returns the information to be displayed
// at a given row and column
QVariant YeastModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
            case 0: return yeast.at(index.row())->name();
            case 1: return QString("%1%").arg(yeast.at(index.row())->attenuation());
        }
    }
    return QVariant();
}

// data
// Required QAbstractTableModel method.  Populates the table's header
QVariant YeastModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            return headerList.at(section);
        }
    }
    return QVariant();
}
