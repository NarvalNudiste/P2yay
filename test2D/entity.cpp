#include "entity.h"

Entity::Entity()
{
 setFlag(QGraphicsItem::ItemIsFocusable,true);  //sinon ça bouge pas et c'est toujours autiste
 Entity::setBasicProps();
}
Entity::Entity(tile* t)
{
    setFlag(QGraphicsItem::ItemIsFocusable,true);  //sinon ça bouge pas et c'est toujours autiste
    Entity::setBasicProps();
    collisionTest = t;
}

void Entity::setBasicProps()    //on cache les trucs sales
{
    x = 10;
    y = 0;
    speed = 2;
    setRect(x,y,10,10);
    setLeftMove(false);
    setRightMove(false);
    setUpMove(false);
    setBotMove(false);
}
void Entity::keyPressEvent(QKeyEvent* event) //si c'est pressé on mets les booléens à 1 (si on fait le mouvement dans le keypressevent ça saccade à mort)
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
void Entity::keyReleaseEvent(QKeyEvent *event) //pour pas que le truc bouge à l'infini
{
    if (event->key() == Qt::Key_Left)
    {
        this->setLeftMove(false);
    }
    else if (event->key() == Qt::Key_Right)
    {
        this->setRightMove(false);
    }
}
void Entity::Update() //boucle principale
{
    Entity::Movement();
    Jump();
}
void Entity::Gravity(){
 /*  QPointF collisionPos = collisionTest->scenePos();
    QPointF thisPos = this->scenePos();
    int thisPosY = thisPos.y();
    //int colPosY = collisionPos.y();
    if (thisPosY > colPosY)
    {
    qDebug() << "position y of entity : " << this->scenePos();
    qDebug() << "position y of collider : " << colPosY;
    qDebug() << "inAir";
    this->setPos(getPosX(), getPosY()-1);
    setPos(getPosX(), getPosY() -1);
    }
    else
    {
        qDebug() << "position y of entity : " << this->scenePos();
        qDebug() << "position y of collider : " << colPosY;
        qDebug() << "grounded";
    }
    */
}
void Entity::Jump(){
    //todo
}
void Entity::Movement() //mouvements
{
    if (isMovingLeft())
    {
        setPos(getPosX()-speed, getPosY());
        setX(getPosX()-speed);
    }
    if (isMovingRight())
    {
        setPos(getPosX()+speed, getPosY());
        setX(getPosX()+speed);
    }
}
