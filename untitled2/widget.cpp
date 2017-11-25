#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()), this, SLOT(tick()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(vBoi()));
    timer.start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::tick()
{
    n--;
    ui->lcdNumber->display(n);
    if(n<0){
        close();
    }
}

void Widget::vBoi()
{
    n++;
}


