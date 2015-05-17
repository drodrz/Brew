#ifndef FERMENTABLEMODEL_H
#define FERMENTABLEMODEL_H

#include <QAbstractTableModel>
#include <QObject>

class FermentableModel : public QAbstractTableModel
{
public:
    FermentableModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;

};

#endif // FERMENTABLEMODEL_H
