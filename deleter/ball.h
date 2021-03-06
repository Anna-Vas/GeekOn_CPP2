#ifndef BALL_H
#define BALL_H
#include <QtGui>


class Ball
{
protected:
    int vx, vy;
    int r;
    QColor color;
    QPoint point;
public:
    Ball(int w, int h);
    void move(int w, int h);
    void draw(QPainter& painter);
    bool isCol(Ball * second);
    bool isCol(int ixs, int igrek);
    int dist(QPoint firstBall, QPoint secondBall);
};

#endif // BALL_H
