#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    for (int i=0; i<NUM; i++)
        balls[i] = new Ball(width(), height());
    connect(&timer, SIGNAL(timeout()), this, SLOT(moveAll()));
    timer.start(40);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    for (int i=0; i<NUM; i++)
        balls[i]->draw(painter);
}

bool Widget::is_alive()
{
    if(NUM == 0)
        return false;
    return true;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    int fooor = NUM;
    for(int i=0; i<fooor; i++){
        if(balls[i]->isCol(x, y)){
            delete balls[i];
            NUM--;
        }
    }
}

void Widget::moveAll()
{
    for (int i=0; i<NUM; i++){
        for(int j=i+1; j< NUM; j++){
           if(balls[i]->isCol(balls[j]))
           {
               balls[i]->move(width() * -1, height() * -1);
               balls[j]->move(width() * -1, height() * -1);
           }
        }
        balls[i]->move(width(), height());
    }
    if(!is_alive()){
        delete ui;
    }
    this->repaint();
}
