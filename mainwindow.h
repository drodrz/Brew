#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fermentablemodel.h"
#include "hopmodel.h"
#include "yeastmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    FermentableModel fermModel;
    HopModel hopModel;
    YeastModel yeastModel;
};

#endif // MAINWINDOW_H
