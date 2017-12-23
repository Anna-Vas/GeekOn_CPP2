#include "ball.h"
#include <QtGui>

Ball::Ball(int w, int h)
{
    r = 15 + rand()%15;//radius
    point.setX(r+rand()%(w-r*2));//geo
    point.setY(r+rand()%(h-r*2));//position
    color = QColor::fromRgb(rand()%256, rand()%256, rand()%256);//color
    vx = 2 + rand()%2;
    vy = 2 + rand()%2;
    if(rand()%2==0) vx *= -1;
    if(rand()%2==0) vy *= -1;
}

void Ball::move(int w, int h)
{
    if(point.x()+r>w || point.x()-r<0){
        vx = vx*-1;
    }
    if(point.y()+r>h || point.y()-r<0){
        vy = vy*-1;
    }
    point += QPoint(vx, vy);
}

void Ball::draw(QPainter &painter)
{
    painter.setBrush(QBrush(color, Qt::Dense7Pattern));
    painter.drawEllipse(point, r, r);
}

bool Ball::isCol(Ball *second)
{
    if(dist(point, second->point) <= ((r+second->r)*(r+second->r)))
        return true;
    return false;
}

int Ball::dist(QPoint firstBall, QPoint secondBall)
{
    return ((firstBall.x() - secondBall.x())*(firstBall.x() - secondBall.x())) + ((firstBall.y() - secondBall.y())*(firstBall.y() - secondBall.y()));
}
