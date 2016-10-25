#include "movingstuff.h"
#include <QDebug>
movingStuff::movingStuff(int x, int y, int h, int w)
{
    this->setRect(x, y,h,w);
    this->setX(x);
    this->setY(y);

}
void movingStuff::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Left)
    {
        this->setLeftMove(true);
    }
    else if (event->key() == Qt::Key_Right)
    {
        this->setRightMove(true);
    }


}

void movingStuff::keyReleaseEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left)
    {
        this->setLeftMove(false);
    }
    else if (event->key() == Qt::Key_Right)
    {
        this->setRightMove(false);
    }
}

void movingStuff::Movement(){
    if (isMovingLeft())
    {
        this->setX(getX() - moveSpeed);
    }
    if (isMovingRight())
    {
        this->setX(getX() + moveSpeed);
    }

    this->setPos(this->getX(),this->getY());
}

void movingStuff::Update(){
    Movement();
}
