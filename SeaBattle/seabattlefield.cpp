#include "seabattlefield.h"
#include <QPainter>
#include <QTime>

SeaBattleField::SeaBattleField(QWidget *parent, int value) : QWidget(parent)
{
    resize(WIDTH, HEIGHT);
    int dimensions = 10;
    QString styleSheet =
        "QPushButton {"
        "  background-color: blue;"
        "  border: 1px solid black;"
        "}"
        "QPushButton:hover {"
          "background-color: lightblue;"
        "}"
        "QPushButton:pressed {"
          "background-color: red;"
        "}";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (value == 1) {
                QPushButton *radio = new QPushButton(tr("1"));
                radio->setFixedSize(40, 40);
                radio->setStyleSheet(styleSheet);
                buttons.push_back(radio);
                layout->addWidget(radio, i + 1, j + 1);
            }
            else {
                QPushButton *radio = new QPushButton(tr("2"));
                radio->setFixedSize(40, 40);
                radio->setStyleSheet(styleSheet);
                buttons.push_back(radio);
                layout->addWidget(radio, i + 1, j + 1);
            }
        }
    }
    layout->setSpacing(0);
    // Vertical spacers
    layout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding), 0, 0, 1, dimensions + 2);
    layout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding), dimensions + 1, 0, 1, dimensions + 2);

    // Horizontal spacers
    layout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum), 1, 0, dimensions, 1);
    layout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum), 1, dimensions + 1, dimensions, 1);
    setLayout(layout);
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

SeaBattleField::~SeaBattleField()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

//void SeaBattleField::paintEvent(QPaintEvent *e) {

//    Q_UNUSED(e);
//    std::cout << __PRETTY_FUNCTION__ << std::endl;
//    doDrawing();
//}

//void SeaBattleField::doDrawing()
//{
//    QPainter qp(this);
//    std::cout << __PRETTY_FUNCTION__ << std::endl;
//    qp.setPen(QColor(Qt::black));
//    qp.drawRect(200, 200, WIDTH + 100, HEIGHT + 100);
//    qp.drawText(600, 600, "SeaBattleField");
//}

//void SeaBattleField::timerEvent(QTimerEvent *e)
//{
//    Q_UNUSED(e);
//    repaint();
//}

//void SeaBattleField::keyPressEvent(QKeyEvent *e)
//{
//    QWidget::keyPressEvent(e);
//}

//QGridLayout* SeaBattleField::getLayout()
//{
//    return layout;
//}
