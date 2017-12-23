#include "ball.h"
#include <QtGui>

Ball::Ball(int w, int h)
{
    r = 15 + rand()%15;//radius
    point.setX(r+rand()%(w-r*2));//geo
    point.setY(r+rand()%(h-r*2));//position
    color = QColor::fromRgb(rand()%256, rand()%256, rand()%256);//color
    x = 10 + rand()%50;
    y = 10 + rand()%50;
}

void Ball::move(int w, int h)
{
    x = rand()%w;
    y = rand()%h;

    point = QPoint(x, y);
}

void Ball::draw(QPainter &painter)
{
    painter.setBrush(QBrush(color, Qt::Dense1Pattern));
    painter.drawEllipse(point, r, r);
}

bool Ball::isCol(int ixs, int igrek)
{
    if(ixs>point.x()-r && ixs<point.x()+r){
        if(igrek>point.y()-r && igrek<point.y()+r){
            return true;
        }
    }
    return false;
}

int Ball::dist(QPoint firstBall, QPoint secondBall)
{
    return ((firstBall.x() - secondBall.x())*(firstBall.x() - secondBall.x())) + ((firstBall.y() - secondBall.y())*(firstBall.y() - secondBall.y()));
}
