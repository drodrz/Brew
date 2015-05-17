#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fermentablemodel.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->fermentablesView->setModel(&fermModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}
