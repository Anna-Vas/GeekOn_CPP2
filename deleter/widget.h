#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QList>
#include "ball.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    QTimer timer;
    //Ball * balls[5];
    QList<Ball*> balls;
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void paintEvent(QPaintEvent * e);
    bool is_alive();
    void mousePressEvent(QMouseEvent *event);
    void stop();
    void start();
protected slots:
    void moveAll();
private:
    Ui::Widget *ui;
    int NUM = 5;
};

#endif // WIDGET_H
