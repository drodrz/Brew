#ifndef FERMENTABLE_H
#define FERMENTABLE_H

#include <QObject>

class Fermentable : public QObject
{
    Q_OBJECT
public:
    explicit Fermentable(QObject *parent = 0);

signals:

public slots:

};

#endif // FERMENTABLE_H

//explicit Fermentable(QString name, QString type, QString usage, int ppg, int lovibond);

//private:
//QString name;
//QString type;
//QString usage;
//int ppg;
//int lovibond;
