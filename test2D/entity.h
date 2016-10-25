#ifndef ENTITY_H
#define ENTITY_H
#include <QGraphicsRectItem>
#include <QDebug>
#include <QKeyEvent>
#include <QObject>
#include <QPointF>
#include "tile.h"

class Entity : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
protected:
    void keyReleaseEvent(QKeyEvent *event);
    void keyPressEvent(QKeyEvent* event);
public:
    //ctor
    Entity();
    Entity(tile* t);

    tile* collisionTest;
    //getset
    void setLeftMove(bool _i){left = _i;}
    void setRightMove(bool _i){right = _i;}
    void setUpMove(bool _i){up = _i;}
    void setBotMove(bool _i){bot = _i;}
    bool isMovingUp(){return up;}
    bool isMovingLeft(){return left;}
    bool isMovingRight(){return right;}
    bool isMovingBot(){return bot;}
    int getPosX(){return x;}
    int getPosY() {return y;}
    void setX(int _i){x = _i;}
    void setY(int _i){y = _i;}
    //props
    int speed;

    //funcs
    void Movement();
    void setBasicProps();
    void Gravity();
    void Jump();
private:
    int x, y;
    bool left, right, up, bot;
public slots:
    void Update();
};

#endif // ENTITY_H
