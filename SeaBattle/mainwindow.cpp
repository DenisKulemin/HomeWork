#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(WIDTH, HEIGHT);
    initGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initGame()
{
    auto widget = new QWidget;
    QGridLayout *mainLayout = new QGridLayout(this);

    player_main = new SeaBattleField(this, 1);
    enemy_main = new SeaBattleField(this, 2);
    player_enemy_view = new SeaBattleField(this, 1);
    enemy_player_view = new SeaBattleField(this, 2);

    mainLayout->addWidget(player_main, 0, 0);
    mainLayout->addWidget(enemy_main, 1, 0);
    mainLayout->addWidget(player_enemy_view, 0, 1);
    mainLayout->addWidget(enemy_player_view, 1, 1);
    widget->setLayout(mainLayout);
    setCentralWidget(widget);
    timerId = startTimer(DELAY);
}

void MainWindow::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);

    doDrawing();
}

void MainWindow::doDrawing()
{
    QPainter qp(this);
//    std::cout << __PRETTY_FUNCTION__ << std::endl;
    qp.setPen(QColor(Qt::black));
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
//    std::cout << __PRETTY_FUNCTION__ << std::endl;
    repaint();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    QWidget::keyPressEvent(e);
}
