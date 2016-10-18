#include "entity.h"

Entity::Entity()
{
 setFlag(QGraphicsItem::ItemIsFocusable,true);  //sinon ça bouge pas et c'est toujours autiste
 Entity::setBasicProps();
}
void Entity::setBasicProps()    //on cache les trucs sales
{
    x = 0;
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
    Gravity();
    Jump();
}
void Entity::Gravity(){
    //todo
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
