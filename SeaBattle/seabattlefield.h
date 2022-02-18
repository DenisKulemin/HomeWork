#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QGroupBox>
#include <QVector>
#include <QPushButton>
#include <QGridLayout>

#include <iostream>

class SeaBattleField : public QWidget
{
    Q_OBJECT
public:
    SeaBattleField(QWidget *parent = 0, int value = 1);
    ~SeaBattleField();
//    QGridLayout * getLayout();

//protected:
//    void paintEvent(QPaintEvent *);
//    void timerEvent(QTimerEvent *);
//    void keyPressEvent(QKeyEvent *);

private:
    static const int WIDTH = 580;
    static const int HEIGHT = 580;
    int value;
//    void doDrawing();
    QVector<QPushButton*> buttons = QVector<QPushButton*>();
    QGridLayout *layout = new QGridLayout;
};
