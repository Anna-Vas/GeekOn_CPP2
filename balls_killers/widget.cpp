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
    player = new Player(width(), height());
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
    player->draw(painter);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    player->move(width(), height(), event->key());
    for(int j=0; j< NUM; j++){
       if(player->isCol(balls[j]))
       {
           balls[j]->move(width() * -1, height() * -1);
           player->move(width()* -1, height()* -1, event->key());
           lifes--;
       }
    }
    this->repaint();
}

bool Widget::is_alive()
{
    if(lifes == 0)
        return false;
    return true;
}

void Widget::stop()
{
    timer.stop();
    ui->lcdNumber->hide();
    for (int i=0; i<NUM; i++)
        delete balls[i];
    delete player;
    QMessageBox::warning(this, "You are kek", "Вы проиграли. Ваш счёт:"+QString::number(score));
    delete ui;
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
    for(int j=0; j< NUM; j++){
       if(balls[j]->isCol(player))
       {
           balls[j]->move(width() * -1, height() * -1);
           lifes--;
       }
    }
    if(!is_alive()){
        stop();
    }
    this->repaint();
    ui->lcdNumber->display(lifes);
    score++;
}
