#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QDebug>
#include <QTest>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    ui->btnRock->setStyleSheet("border-image:url(:/new/images/images/rock.jpg);");
    ui->btnPaper->setStyleSheet("border-image:url(:/new/images/images/paper.jpg);");
    ui->btnScissors->setStyleSheet("border-image:url(:/new/images/images/scissors.jpg);");
    ui->lblDraw->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnRock_clicked()
{
    playerChoice = 0; //0
    qDebug() << "Player choosed: " << playerChoice;
    Losuj();
}

void MainWindow::on_btnPaper_clicked()
{
    playerChoice = 1; //1
    qDebug() << "Player choosed: " << playerChoice;
    Losuj();
}

void MainWindow::on_btnScissors_clicked()
{
    playerChoice = 2; //2
    qDebug() << "Player choosed: " << playerChoice;
    Losuj();
}

void MainWindow::Losuj()
{
    computerChoice = QRandomGenerator::global()->bounded(0, 3);
    qDebug() << "Computer choosed: " << computerChoice;
    ui->lblDraw->setVisible(false);
    WhoWon();
}

void MainWindow::WhoWon()
{

    ///****POJEBANE WEZ TO NAPRAW*****////


//    if ((playerChoice == 0 && computerChoice == 2) || (playerChoice == 1 && computerChoice == 0) || (playerChoice == 2 && computerChoice == 1))
//    {
//        ui->lblPlayerScore->setText(QString::number(playerPoints++));
//        qDebug() << "wygral gracz";
//    }
//    else if ((computerChoice == 0 && playerChoice == 2) || (computerChoice == 1 && playerChoice == 0) || (computerChoice == 2 && playerChoice == 1))
//    {
//        ui->lblCompScore->setText(QString::number(computerPoints++));
//        qDebug() << "wygral komputer";
//    }
//    else {
//        qDebug() << "remis";
//        ui->lblDraw->setVisible(true);
//        QTest::qWait(2000);
//        ui->lblDraw->setVisible(false);
//    }
}
