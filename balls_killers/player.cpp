#include "player.h"
#include <QtGui>

Player::Player(int w, int h):Ball(w,h)
{
    r = 10;
    vx = 0;
    vy = 0;
}

void Player::draw(QPainter &painter)
{
    painter.setBrush(QBrush(color));
    painter.drawEllipse(point, r, r);
}

void Player::move(int w, int h, int key)
{
    if(key == Qt::Key_W){
        if(point.y()-r>0){
            point += QPoint(vx, -10);
        }
    }
    if(key == Qt::Key_A){
        if(point.x()-r>0){
            point += QPoint(-10, vy);
        }
    }
    if(key == Qt::Key_S){
        if(point.y()+r<h){
            point += QPoint(vx, 10);
        }
    }
    if(key == Qt::Key_D){
        if(point.x()+r<w){
            point += QPoint(10, vy);
        }
    }
}
