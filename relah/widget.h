#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    int blue = 1;
    int green = 1;
    int red = 1;
    bool red_target = true;
    bool blue_target = true;
    bool green_target = true;
    QTimer timer;
protected:
    void paintEvent(QPaintEvent *event);
    void too_big(int *color, bool *target);
    void too_small(int *color, bool *target);
protected slots:
    void tick();
};

#endif // WIDGET_H
