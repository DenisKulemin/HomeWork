#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QGridLayout>
#include <seabattlefield.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initGame();

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);

private:
    Ui::MainWindow *ui;
    static const int WIDTH = 1200;
    static const int HEIGHT = 900;
    static const int DELAY = 140;

    SeaBattleField *player_main;
    SeaBattleField *player_enemy_view;
    SeaBattleField *enemy_main;
    SeaBattleField *enemy_player_view;
    int timerId;
    void doDrawing();
};
