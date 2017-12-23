#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ball = new Ball(width(), height());
    connect(&timer, SIGNAL(timeout()), this, SLOT(moveAll()));
    timer.start(800);
}

Widget::~Widget()
{
    delete ball;
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    ball->draw(painter);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    if(ball->isCol(x, y)){
        score++;
        ui->lcdNumber->display(score);
    }
}

void Widget::moveAll()
{
    ball->move(width(), height());
    this->repaint();
}

