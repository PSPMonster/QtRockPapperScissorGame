#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    ui->btnRock->setStyleSheet("border-image:url(:/new/images/images/rock.jpg);");
    ui->btnPaper->setStyleSheet("border-image:url(:/new/images/images/paper.jpg);");
    ui->btnScissors->setStyleSheet("border-image:url(:/new/images/images/scissors.jpg);");
    player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/new/sounds/sounds/COMBAT01.MP3"));
    player->setVolume(10);
    player->play();
    qDebug() << player->errorString();
}

MainWindow::~MainWindow()
{
    delete ui;
}



// przycisk od wybrania kamienia

void MainWindow::on_btnRock_clicked()
{
    playerChoice = 0; //0
    qDebug() << "Player choosed: " << playerChoice;
    Losuj();
    klik = new QMediaPlayer;
    klik->setMedia(QUrl("qrc:/new/sounds/sounds/snd1.wav"));
    klik->setVolume(20);
    klik->play();
}



// przycisk od wybrania papieru

void MainWindow::on_btnPaper_clicked()
{
    playerChoice = 1; //1
    qDebug() << "Player choosed: " << playerChoice;
    Losuj();
    klik = new QMediaPlayer;
    klik->setMedia(QUrl("qrc:/new/sounds/sounds/snd1.wav"));
    klik->setVolume(20);
    klik->play();
}



// przycisk od wybrania nozyc

void MainWindow::on_btnScissors_clicked()
{
    playerChoice = 2; //2
    qDebug() << "Player choosed: " << playerChoice;
    Losuj();
    klik = new QMediaPlayer;
    klik->setMedia(QUrl("qrc:/new/sounds/sounds/snd1.wav"));
    klik->setVolume(20);
    klik->play();
}



// jak nazwa mowi, ta funkcja losuje wybor dla komputera zeby gra byla uczciwa

void MainWindow::Losuj()
{
    computerChoice = QRandomGenerator::global()->bounded(0, 3);
    qDebug() << "Computer choosed: " << computerChoice;
    WhoWon();
}



// funkcja odpowiedzialna z okreslanie kto wygral oraz za wyświetlanie punktow i komunikatu stosownie do wygranej, przegrqanej, lub remisu

void MainWindow::WhoWon()
{

    if ((playerChoice == 0 && computerChoice == 2) || (playerChoice == 1 && computerChoice == 0) || (playerChoice == 2 && computerChoice == 1))
    {
        ui->lblPlayerScore->setText(QString::number(playerPoints++));
        qDebug() << "wygral gracz";
        ui->lblDraw->setText("Player won!");
    }
    else if ((computerChoice == 0 && playerChoice == 2) || (computerChoice == 1 && playerChoice == 0) || (computerChoice == 2 && playerChoice == 1))
    {
        ui->lblCompScore->setText(QString::number(computerPoints++));
        qDebug() << "wygral komputer";
        ui->lblDraw->setText("Computer won!");
    }
    else {
        qDebug() << "remis";
        ui->lblDraw->setText("Draw!!!");
    }
}



// przycisk do resetowania wyniku

void MainWindow::on_btnRestart_clicked()
{
    playerPoints = 0;
    computerPoints = 0;
    ui->lblPlayerScore->setText(QString::number(playerPoints));
    ui->lblCompScore->setText(QString::number(computerPoints));
    playerPoints = 1;
    computerPoints = 1;
    ui->lblDraw->setText("Scores have been reset!");
    klik = new QMediaPlayer;
    klik->setMedia(QUrl("qrc:/new/sounds/sounds/snd1.wav"));
    klik->setVolume(20);
    klik->play();
}



//slider do glosnosci muzyki

void MainWindow::on_SliVolume_sliderMoved(int position)
{
        player->setVolume(position);
}



// przycisk od pauzy dla muzyki

void MainWindow::on_btnPause_clicked()
{
    klik = new QMediaPlayer;
    klik->setMedia(QUrl("qrc:/new/sounds/sounds/snd1.wav"));
    klik->setVolume(20);
    klik->play();
    player->pause();
}



// przycisk od stopowania muzyki

void MainWindow::on_btnStop_clicked()
{
    klik = new QMediaPlayer;
    klik->setMedia(QUrl("qrc:/new/sounds/sounds/snd1.wav"));
    klik->setVolume(20);
    klik->play();
    player->stop();
}



// przycisk od puszczania/odpauzowywania muzyki

void MainWindow::on_btnPlay_clicked()
{
    klik = new QMediaPlayer;
    klik->setMedia(QUrl("qrc:/new/sounds/sounds/snd1.wav"));
    klik->setVolume(20);
    klik->play();
    player->play();
}
