#ifndef MOVINGSTUFF_H
#define MOVINGSTUFF_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
class movingStuff : public QGraphicsRectItem
{
    Q_OBJECT
protected:
    void keyPressEvent(QKeyEvent* event);
public:
    movingStuff(int x, int y, int h, int w);

    void setX(int _x){posX = _x;}
    void setY(int _y){posY = _y;}
    int getX(){return posX;}
    int getY(){return posY;}
    int getSpeed(){return moveSpeed;}
    void setSpeed(int _ms){moveSpeed = _ms;}
    void move(int direction);
    void setLeftMove(bool _i){left = _i;}
    void setRightMove(bool _i){right = _i;}
    void setUpMove(bool _i){up = _i;}
    void setBotMove(bool _i){bot = _i;}
    void Movement();
    bool isMovingUp(){return up;}
    bool isMovingLeft(){return left;}
    bool isMovingRight(){return right;}
    bool isMovingBot(){return bot;}
    //bool move
    void keyReleaseEvent(QKeyEvent *event);
public slots:
    void Update();
private:
    int moveSpeed = 10;
    int height;
    int width;
    int posX;
    int posY;
    bool left, right, up, bot;
};

#endif // MOVINGSTUFF_H
