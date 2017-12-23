#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPaintEvent>
#include "ball.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    QTimer timer;
    Ball *ball;
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void paintEvent(QPaintEvent * e);
    void mousePressEvent(QMouseEvent *event);
protected slots:
    void moveAll();
private:
    Ui::Widget *ui;
    int score = 0;
};

#endif // WIDGET_H
