#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fermentablemodel.h"
#include "hopmodel.h"
#include "yeastmodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->fermentablesView->setModel(&fermModel);
    ui->hopsView->setModel(&hopModel);
    ui->yeastView->setModel(&yeastModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}
