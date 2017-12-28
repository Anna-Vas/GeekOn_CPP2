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
    QMessageBox::warning(this, tr("Game start"),
                         tr("You'll win!11!"));
    for(int i=0; i<NUM; i++)
        balls.push_back(new Ball(width(), height()));
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
    for (int i=0; i!=balls.size(); i++)
        balls[i]->draw(painter);
}

bool Widget::is_alive()
{
    if(balls.size() == 0)
        return false;
    return true;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();    
    QList<Ball*>::iterator iter = balls.begin();
    while(iter!=balls.end()){
        if((*iter)->isCol(x, y))
            iter = balls.erase(iter);
        else
            iter++;
    }
}

void Widget::stop()
{
    timer.stop();
    QMessageBox::warning(this, tr("Game over"),
                         tr("You won!11!"));
}

void Widget::start()
{

}

void Widget::moveAll()
{
    if(rand()%50 == 1)
        balls.push_back(new Ball(width(), height()));
    for (int i=0; i<balls.size(); i++){
        for(int j=i+1; j< balls.size(); j++){
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
        stop();
    }
    this->repaint();
}
