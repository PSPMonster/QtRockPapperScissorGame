#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnRock->setStyleSheet("border-image:url(:/new/images/images/rock.jpg);");
}

MainWindow::~MainWindow()
{
    delete ui;
}


