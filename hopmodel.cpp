#include "hopmodel.h"

// HopModel Constructor
// Initializes header strings and hardcoded hops
HopModel::HopModel(QObject *parent)
    :QAbstractTableModel(parent){
    headerList << "Name" << "Amount" << "Unit" << "AA %" << "Addition";

    hops << new Hop("Cascade", 1.0, 13.5, 60) \
         << new Hop("Amarillo", 2.0, 12.7, 15) \
         << new Hop("Amarillo", 1.0, 12.7, 5);
}

// rowCount
// Required QAbstractTableModel method.  Indicates how many rows to display.
// Returns number of hops in current recipe
int HopModel::rowCount(const QModelIndex &) const {
    return hops.length();
}

// columnCount
// Required QAbstractTableModel method.  Indicates how many cols to display.
// Num cols defined by number of items in the header list
int HopModel::columnCount(const QModelIndex &) const {
    return headerList.length();
}

// data
// Required QAbstractTableModel method.  Returns the information to be displayed
// at a given row and column
QVariant HopModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
            case 0: return hops.at(index.row())->name();
            case 1: return hops.at(index.row())->amount();
            case 2: return QString("oz");                                           // TODO: Return QComboBox to select unit of measure
            case 3: return QString("%1%").arg(hops.at(index.row())->aa());
            case 4: return QString("%1 (min)").arg(hops.at(index.row())->time());
        }
    }
    return QVariant();
}

// data
// Required QAbstractTableModel method.  Populates the table's header
QVariant HopModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            return headerList.at(section);
        }
    }
    return QVariant();
}
