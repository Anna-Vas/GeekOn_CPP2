#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPaintEvent>
#include <QMouseEvent>
#include "ball.h"
#include "player.h"

namespace Ui {
class Widget;
}

const int NUM = 5;

class Widget : public QWidget
{
    Q_OBJECT
    QTimer timer;
    Ball * balls[NUM];
    Player *player;
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void paintEvent(QPaintEvent * e);
    void keyPressEvent(QKeyEvent *event);
    bool is_alive();
    void stop();
protected slots:
    void moveAll();
private:
    Ui::Widget *ui;
    int score = 0;
    int lifes = 8;
};

#endif // WIDGET_H
