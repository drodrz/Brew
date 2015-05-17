#include "fermentablemodel.h"

// FermentableModel Constructor
// Initializes header strings and hardcoded fermentables
FermentableModel::FermentableModel(QObject *parent)
    :QAbstractTableModel(parent){
    headerList << "Name" << "Amount" << "Unit" << "%";

    fermentables << new Fermentable("2-Row", "Base Malt", 1.039, 2, 10.0) \
                 << new Fermentable("Crystal 20L", "Crystal Malt", 1.036, 20, 1.0);
}

// rowCount
// Required QAbstractTableModel method.  Indicates how many rows to display.
// Returns number of rermentables in current recipe
int FermentableModel::rowCount(const QModelIndex &) const {
    return fermentables.length();
}

// columnCount
// Required QAbstractTableModel method.  Indicates how many cols to display.
// Num cols defined by number of items in the header list
int FermentableModel::columnCount(const QModelIndex &) const {
    return headerList.length();
}

// data
// Required QAbstractTableModel method.  Returns the information to be displayed
// at a given row and column
QVariant FermentableModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
            case 0: return fermentables.at(index.row())->name();
            case 1: return fermentables.at(index.row())->amount();
            case 2: return QString("lbs");                          // TODO: Return QComboBox to select unit of measure
            case 3: return 100;                                     // TODO: Calculate percentage of grist
        }
    }
    return QVariant();
}

// data
// Required QAbstractTableModel method.  Populates the table's header
QVariant FermentableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            return headerList.at(section);
        }
    }
    return QVariant();
}
