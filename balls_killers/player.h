#ifndef PLAYER_H
#define PLAYER_H
#include <ball.h>
#include <QtGui>

class Player : public Ball
{
public:
    Player(int w, int h);
    void draw(QPainter& painter);
    void move(int w, int h, int key);
};

#endif // PLAYER_H
