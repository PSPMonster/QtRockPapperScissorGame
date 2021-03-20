#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnRock_clicked();

    void on_btnPaper_clicked();

    void on_btnScissors_clicked();

    void Losuj();

    void WhoWon();

private:
    Ui::MainWindow *ui;

private:
    int computerChoice;
    int computerPoints = 0;
    int playerChoice;
    int playerPoints = 0;
};
#endif // MAINWINDOW_H
