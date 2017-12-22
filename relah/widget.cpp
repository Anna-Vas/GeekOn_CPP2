#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()), this, SLOT(tick()));
    timer.start(100);
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
    pinter.setBrush(QBrush(QColor::fromRgb(red, green, blue)));
    pinter.drawRect(0, 0, width, height);
}

void Widget::too_big(int *color, bool *target)
{
    if(*color>255){
        *color = 255;
        *target = !*target;
    }
}

void Widget::too_small(int *color, bool *target)
{
    if(*color<1){
        *color = 1;
        *target = !*target;
    }
}

void Widget::tick()
{
    if(red_target == false){
        red-=1;
    }
    too_small(&red, &red_target);
    if(red_target == true){
        red+=1;
    }
    too_big(&red, &red_target);


    if(blue_target == false){
        blue-=2;
    }
    too_small(&blue, &blue_target);
    if(blue_target == true){
        blue+=2;
    }
    too_big(&blue, &blue_target);


    if(green_target == false){
        green-=3;
    }
    too_small(&green, &green_target);
    if(green_target == true){
        green+=3;
    }
    too_big(&green, &green_target);

    this->repaint();
}
