#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter pinter(this);
    int width = this->width();
    int height = this->height();
    QColor orange("orange");
    QColor purple("pink");
    //QString colors = {"Qt::red", "Qt::orange", "Qt::yellow", "Qt::green", "Qt::blue", "Qt::blue", "Qt::purple"};
    pinter.setBrush(QBrush(Qt::red));
    pinter.drawEllipse(QPoint(this->width()/2, this->height()), width/2, height);
    pinter.setBrush(QBrush(orange));
    pinter.drawEllipse(QPoint(this->width()/2, this->height()), width/2-(width/2/7), height-(height/7));
    pinter.setBrush(QBrush(Qt::yellow));
    pinter.drawEllipse(QPoint(this->width()/2, this->height()), width/2-(width/7), height-(height/7*2));
    pinter.setBrush(QBrush(Qt::green));
    pinter.drawEllipse(QPoint(this->width()/2, this->height()), width/2-(width/2/7*3), height-(height/7*3));
    pinter.setBrush(QBrush(Qt::cyan));
    pinter.drawEllipse(QPoint(this->width()/2, this->height()), width/2-(width/2/7*4), height-(height/7*4));
    pinter.setBrush(QBrush(Qt::blue));
    pinter.drawEllipse(QPoint(this->width()/2, this->height()), width/2-(width/2/7*5), height-(height/7*5));
    pinter.setBrush(QBrush(purple));
    pinter.drawEllipse(QPoint(this->width()/2, this->height()), width/2-(width/2/7*6), height-(height/7*6));
}
